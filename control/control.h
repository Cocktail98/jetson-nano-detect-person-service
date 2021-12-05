#ifndef YOLOV5_CONTROL_CONTROL_H_
#define YOLOV5_CONTROL_CONTROL_H_

#include <time.h>

// TODO: 整合控制函数
/**
 * @brief 控制基类
 * @details IsSleepTime->bool 检查是否是开馆时间
 */
class Control {
 public:
  static bool IsSleepTime();
};

#endif //YOLOV5_CONTROL_CONTROL_H_
