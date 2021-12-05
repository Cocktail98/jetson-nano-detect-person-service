//
// Created by Homin Su on 2021/12/5.
//

#ifndef YOLOV5_CAMERA_TASK_CAMERA_TASK_H_
#define YOLOV5_CAMERA_TASK_CAMERA_TASK_H_

#include "../utils/x_thread_pool/x_task.h"

#include <opencv4/opencv2/opencv.hpp>

#include <condition_variable>
#include <shared_mutex>
#include <atomic>

class CameraTask : public XTask<bool> {
 private:
  int camera_id{};
  cv::VideoCapture video_capture_{};
  mutable std::shared_mutex mutex_;

 public:
  std::condition_variable_any cv_;
  cv::Mat image_;

 public:
  ~CameraTask();

  /**
   * @brief 初始化读取任务，获取文件大小
   * @param _file_name 文件名
   * @return 是否初始化成功
   */
  bool Init(const int &_camera_id, const int &_width, const int &_height);

 private:
  /**
   * 线程入口函数
   */
  void Main() override;
};

#endif //YOLOV5_CAMERA_TASK_CAMERA_TASK_H_
