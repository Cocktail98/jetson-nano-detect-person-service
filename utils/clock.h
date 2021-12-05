#ifndef YOLOV5_UTILS_CLOCK_H_
#define YOLOV5_UTILS_CLOCK_H_

#include <time.h>

#include <string>

/**
 * @brief 钟基类
 * @details 用于获取当前时间, GetTime->time_t, GetTimeString->std::string,
 */
class Clock {
 private:
//  Clock();
 public:
//  ~Clock();
  static time_t GetTime();
  static std::string GetTimeString();
  static std::string GetTimeString(std::string _format_str);
};

#endif //YOLOV5_UTILS_CLOCK_H_
