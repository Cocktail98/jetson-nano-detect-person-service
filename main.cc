#include "model/yolo_v_5.h"
#include "model/gen_color.h"
#include "detect_service/detect_service_server.h"
#include "config/config.h"
#include "camera_task/camera_task.h"
#include "utils/x_thread_pool/x_thread_pool.h"

#include <opencv4/opencv2/opencv.hpp>

#include <thread>
#include <mutex>
#include <csignal>

bool is_running = true;

const int kWidth = 640;
const int kHeight = 480;

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

  // open the camera
//  cv::VideoCapture capture(0);
//  if (!capture.isOpened()) {
//    std::cout << "Failed to open camera." << std::endl;
//    return EXIT_FAILURE;
//  }
//  capture.set(cv::CAP_PROP_FRAME_WIDTH, kWidth);
//  capture.set(cv::CAP_PROP_FRAME_HEIGHT, kHeight);
//  capture.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));

  // create a window to show the detected frame
//  cv::namedWindow("dst", cv::WINDOW_AUTOSIZE);

  // 框颜色
  std::vector<cv::Scalar> colors_list = GetColors(YoloV5::CLASS_NUM);
  std::vector<std::string> id_name = {
      "person"
  };

  // Prepare buffer
  float data[BATCH_SIZE * 3 * YoloV5::INPUT_H * YoloV5::INPUT_W];
  float prob[BATCH_SIZE * YoloV5::OUTPUT_SIZE];


  // 暂存: 检测状态、检测信息、图片的对象
  Info info;

  // 监听地址
  auto local_address =
      Config::Get()->BasicSetting()->local_rpc_address() + ":" + Config::Get()->BasicSetting()->local_rpc_port();

  // rpc 服务对象
  DetectServiceServer server(local_address, info);

  server.Start(); // 启动 rpc 服务

  int camera_num = 2;

  // 初始化线程池
  XThreadPool::Get()->Init(camera_num);

  // 摄像机任务列表
  std::vector<std::shared_ptr<CameraTask>> camera_tasks;

  // 初始化全部摄像机
  for (int i = 0; i < camera_num; ++i) {
    // 创建相机任务
    auto camera_task = std::make_shared<CameraTask>();
    if (!camera_task->Init(i, kWidth, kHeight)) {
      std::cout << "failed!!" << std::endl;
      throw std::runtime_error("camera " + std::to_string(i) + " open failed");
    }

    // 任务加入线程池
    XThreadPool::Get()->AddTask(camera_task);
    camera_tasks.push_back(camera_task);
  }
  std::cout << "[INFO] Camera initialization ... " << std::endl;

  std::this_thread::sleep_for(std::chrono::seconds(15 * camera_num));

  std::cout << "[INFO] Start Detect ... " << std::endl;
  std::cout << "[INFO] Thread Count: " << XThreadPool::Get()->task_run_count() << std::endl;

//  FILE *fp = nullptr;
  while (true) {
    std::vector<cv::Mat> images;

    // 通知摄像机线程解除阻塞，拍摄照片
    for (auto &camera_task: camera_tasks) {
      camera_task->cv_.notify_one();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // 读取相机线程的照片
    for (auto &camera_task: camera_tasks) {
      if (!camera_task->image_.empty())
        images.push_back(camera_task->image_);
    }

    // 处理照片
    auto camera_rect = std::make_shared<std::vector<Box::Camera>>();
    int id = 0;
    if (!images.empty()) {
      for (auto &img: images) {
        // 转换
        img = YoloV5::BGR2RGB(data, img);

        // 向前推导
        auto boxes = YoloV5::Get()->Inference(colors_list, id_name, data, prob, img);

        // 处理结果
        if (!boxes->empty()) {
          camera_rect->emplace_back(id++, boxes);
        }

        if (!is_running) {
          break;
        }
      }
    }
    // 处理结果
    if (!camera_rect->empty()) {
//        // 格式化成 json 字符串，输出
//        for (const auto box: *boxes) {
//          std::cout << box.ToJson().dump() << std::endl;
//        }
//        std::cout << std::endl;

      info.set_camera_rect(camera_rect);

      // status 的设置一定在 image 和 rect 之前，否则 rpc 会读到无用数据
      info.set_status(true);
    } else {
      info.set_status(false);
    }

    if (!is_running) {
      break;
    }
  }

  server.Stop();  // 停止 rpc 服务
  for (auto &camera_task: camera_tasks) {
    camera_task->cv_.notify_one();
  }
  XThreadPool::Get()->Stop();
  return EXIT_SUCCESS;
}
