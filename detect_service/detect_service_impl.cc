#include "detect_service_impl.h"

::grpc::Status DetectServiceImpl::DetectedRect(::grpc::ServerContext *_context,
                                               const ::Detect::DetectRequest *_request,
                                               ::Detect::DetectResponse *_response) {
  // 写入检测状态，如果图片中检测到对象即为 true
  _response->set_status(info_.status());

  if (_request->status()) {
    // 如果检测到，继续写入 rect 和 image
    if (info_.status()) {
      // 写入检测结果
      for (const auto &c_r: *(info_.camera_rect())) {
        auto camera_rect = _response->add_camera_rect();
        camera_rect->set_camera_id(c_r.camera_id());
        for (const auto &b_r: *c_r.camera_rect()) {
          auto box_rect = camera_rect->add_box_rect();
          box_rect->set_x(b_r.x());
          box_rect->set_y(b_r.y());
          box_rect->set_width(b_r.width());
          box_rect->set_height(b_r.height());
          box_rect->set_class_id(b_r.class_id());
        }
      }
    }
  }
  return ::grpc::Status::OK;
}