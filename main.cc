#include <pthread.h>
#include <signal.h>

#include <thread>
#include <mutex>
#include <csignal>

#include <opencv4/opencv2/opencv.hpp>

#include "model/yolo_v_5.h"
#include "model/gen_color.h"
#include "detect_service/detect_service_server.h"
#include "config/config.h"
#include "utils/clock.h"
#include "control/control.h"

bool is_running = true;

const int kWidth = 640;
const int kHeight = 480;

// 框颜色
std::vector<cv::Scalar> kColorsList = GetColors(YoloV5::CLASS_NUM);
std::vector<std::string> kIdName = {
    "person"
};
bool kDownFlags[20] = {false};

// cv::Mat 2 std::string，也可以通过 stringstream 将 cv::Mat 流转换为字符流
// 但是以下方法，直接操作内存，快
inline std::string Mat2String(const cv::Mat &img) {
  std::string imag_str;
  std::vector<unsigned char> buff;
  cv::imencode(".jpg", img, buff);
  imag_str.resize(buff.size());
  memcpy(&imag_str[0], buff.data(), buff.size());
  return imag_str;
}

void OnSignal(int) {
  is_running = false;
}

/**
 * @brief 相机的线程
 * @details 用于开启摄像头
 */
int CameraThread(bool &_sem,
                 std::mutex &_mtx,
                 Info &_info,
                 int _camera_id = 0) {
  // open the camera
  cv::VideoCapture capture(_camera_id);
  if (!capture.isOpened()) {
    std::cout << "Failed to open camera." << std::endl;
    kDownFlags[_camera_id] = true;
    return EXIT_FAILURE;
  }
  capture.set(cv::CAP_PROP_FRAME_WIDTH, kWidth);
  capture.set(cv::CAP_PROP_FRAME_HEIGHT, kHeight);
//  capture.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));

//  // create a window to show the detected frame
//  cv::namedWindow("dst", cv::WINDOW_AUTOSIZE);

  // Prepare buffer
  float data[BATCH_SIZE * 3 * YoloV5::INPUT_H * YoloV5::INPUT_W];
  float prob[BATCH_SIZE * YoloV5::OUTPUT_SIZE];

  cv::Mat img;

  while (true) {
    if (_sem) {
      // 加锁，使用信号量控制单个摄像头
      std::lock_guard<std::mutex> guard(_mtx);  // 利用lock_guard管理mutex
      _sem = false;

      capture >> img;
      if (img.empty()) {
        continue;
      }

      // 转换
      img = YoloV5::BGR2RGB(data, img);

      // 向前推导
      auto boxes = YoloV5::Get()->Inference(kColorsList, kIdName, data, prob, img);

      // 处理结果
      if (!boxes->empty()) {
        // 格式化成 json 字符串，输出
        std::cout << "[" << Clock::GetTimeString() << "]:\t";
        for (const auto box: *boxes) {
          std::cout << box.ToJson().dump() << " ";
        }
        std::cout << std::endl;

        _info.set_image(Mat2String(img));
        _info.set_rects(boxes);

        // status 的设置一定在 image 和 rect 之前，否则 rpc 会读到无用数据
        _info.set_status(true);
      } else {
        _info.set_status(false);
      }

//    // 显示图片，检测退出
//    cv::imshow("dst", img);
//    if (cv::waitKey(1) == 'q') {
//      cv::destroyAllWindows();
//      break;
//    }
//
//    // cv::Mat 转换成 char 数组，传入 ffmpeg 的子进程中
//    fwrite(img.data, sizeof(char), img.total() * img.elemSize(), fp);
    }
    if (!is_running) {
      break;
    }
  }
  capture.release();  // 释放摄像头
  kDownFlags[_camera_id] = true;
  return EXIT_SUCCESS;
}

int main(int argc, char **argv) {

  // 触发下面的信号就退出
  signal(SIGINT, OnSignal);
  signal(SIGQUIT, OnSignal);
  signal(SIGTERM, OnSignal);

  // 处理 Parse、Gen engine、Load engine 的 Exception
  try {
    YoloV5::Get()->ParseArgs(argc, argv); // 检查输入参数是否合格
    YoloV5::Get()->GenEngine(); // 生成引擎
    YoloV5::Get()->LoadEngine();  // 加载引擎
  } catch (YoloQuit &_d) {
    std::cout << _d.what();
    return EXIT_SUCCESS;
  } catch (YoloException &_e) {
    std::cerr << _e.what();
    return EXIT_FAILURE;
  }

  // 准备神经网络和 gpu buffer
  YoloV5::Get()->PrepareInput();

  // 信号量和锁
  bool sem = true; // Semaphore 信号量
  std::mutex mtx;

  // 暂存: 检测状态、检测信息、图片的对象
  Info info;

  // 监听地址
  auto local_address =
      Config::Get()->BasicSetting()->local_rpc_address() + ":" + Config::Get()->BasicSetting()->local_rpc_port();

  // rpc 服务对象
  DetectServiceServer server(local_address, info);

  server.Start(); // 启动 rpc 服务

  // TODO: 更换成线程池进行处理
  // 开启相机线程
  std::thread camera01(CameraThread, std::ref(sem), std::ref(mtx), std::ref(info), 0);
  camera01.detach();

  // 主线程，用来计算时间的
  while ([]() -> bool {
    for (auto f: kDownFlags) {
      if (f)
        return false;
      return true;
    }
  }) {
    mtx.lock();
    // 关门时间不检测
    if (Control::IsSleepTime()) {
      sem = true;
    }
    mtx.unlock();
    // TODO: 控制帧率
    sleep(4);
    if (!is_running) {
      break;
    }
  }

  server.Stop();  // 停止 rpc 服务
  return EXIT_SUCCESS;
}

