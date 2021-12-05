#ifndef YOLOV5_DEFS_INFO_H_
#define YOLOV5_DEFS_INFO_H_

#include <shared_mutex>

#include "box.h"

class Info {
 private:
  bool status_ = false;
  std::shared_ptr<std::vector<Box::Camera>> camera_rect_;
  mutable std::shared_mutex mutex_;

 public:
  Info() = default;
  Info(bool _status, std::shared_ptr<std::vector<Box::Camera>> _camera_rect)
      : status_(_status), camera_rect_(std::move(_camera_rect)) {}

  bool status() const {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    return status_;
  }
  void set_status(bool status) {
    std::unique_lock<std::shared_mutex> lock(mutex_);
    status_ = status;
  }
  const std::shared_ptr<std::vector<Box::Camera>> &camera_rect() const {
    std::shared_lock<std::shared_mutex> lock(mutex_);
    return camera_rect_;
  }
  void set_camera_rect(const std::shared_ptr<std::vector<Box::Camera>> &_camera_rect) {
    std::unique_lock<std::shared_mutex> lock(mutex_);
    camera_rect_ = _camera_rect;
  }
};

#endif //YOLOV5_DEFS_INFO_H_
