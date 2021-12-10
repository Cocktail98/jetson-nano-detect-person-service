#include "camera_task.h"

CameraTask::~CameraTask() {
  if (video_capture_.isOpened()) {
    video_capture_.release();
  }
}

bool CameraTask::Init(const int &_camera_id, const int &_width, const int &_height) {
  camera_id_ = _camera_id;
  video_capture_.open(camera_id_);
  if (!video_capture_.isOpened()) {
    return false;
  }
  video_capture_.set(cv::CAP_PROP_FRAME_WIDTH, _width);
  video_capture_.set(cv::CAP_PROP_FRAME_HEIGHT, _height);
  return true;
}

void CameraTask::Main() {
  while (is_running()) {
    // 独占锁，防止抢占
    std::unique_lock<std::shared_mutex> lock(mutex_);

    // 阻塞
    cv_.wait(lock);

    if (video_capture_.isOpened()) {
      video_capture_ >> image_;
    }
  }

  set_return(true);
}
