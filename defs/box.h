#ifndef YOLOV5_DEFS_BOX_H_
#define YOLOV5_DEFS_BOX_H_

#include <nlohmann/json.hpp>
#include <opencv4/opencv2/opencv.hpp>

namespace Box {
struct Rect {
 private:
  int x_;       // x 坐标
  int y_;       // y 坐标
  int width_;   // 宽度
  int height_;  // 高度
  int class_id_;   // 检测种类

 public:
  explicit Rect(const nlohmann::json &_j)
      : x_(_j.at("x")),
        y_(_j.at("y")),
        width_(_j.at("width")),
        height_(_j.at("height")),
        class_id_(_j.at("class_id")) {}

  explicit Rect(const cv::Rect &_rect, int _class_id)
      : x_(_rect.x),
        y_(_rect.y),
        width_(_rect.width),
        height_(_rect.height),
        class_id_(_class_id) {}

  static void from_json(const nlohmann::json& j, Rect& _rect) {
    j.at("x").get_to(_rect.x_);
    j.at("y").get_to(_rect.y_);
    j.at("width").get_to(_rect.width_);
    j.at("height").get_to(_rect.height_);
    j.at("class_id").get_to(_rect.class_id_);
  }

  [[nodiscard]] inline nlohmann::json ToJson() const {
    return nlohmann::json{{"x", x_}, {"y", y_}, {"width", width_}, {"height", height_},
                          {"class_id", class_id_}};
  }

  [[nodiscard]] inline cv::Point getMPoint() const {
    return {x_ + width_ / 2, y_ + height_ / 2};
  }

  [[nodiscard]] int x() const {
    return x_;
  }
  [[nodiscard]] int y() const {
    return y_;
  }
  [[nodiscard]] int width() const {
    return width_;
  }
  [[nodiscard]] int height() const {
    return height_;
  }
  [[nodiscard]] int class_id() const {
    return class_id_;
  }
};

struct Camera {
 private:
  int camera_id_;
  std::shared_ptr<std::vector<Rect>> camera_rect_;

 public:
  explicit Camera(const nlohmann::json &_j)
      : camera_id_(_j.at("camera_id")),
        camera_rect_(_j.at("camera_rect")) {}

  explicit Camera(const int &_camera_id, std::shared_ptr<std::vector<Rect>> &_camera_rect)
      : camera_id_(_camera_id),
        camera_rect_(_camera_rect) {}

//  [[nodiscard]] inline nlohmann::json ToJson() const {
//    return nlohmann::json{{"camera_id", camera_id_}, {"camera_rect", *camera_rect_}};
//  }

  [[nodiscard]] int camera_id() const {
    return camera_id_;
  }

  [[nodiscard]] std::shared_ptr<std::vector<Rect>> camera_rect() const {
    return camera_rect_;
  }
};
}

#endif //YOLOV5_DEFS_BOX_H_
