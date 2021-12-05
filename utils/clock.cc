#include "clock.h"

//Clock::Clock() = default;

//Clock::~Clock() = default;

time_t Clock::GetTime() {
  time_t timep;
  time(&timep); // 获取time_t类型的当前时间
  return timep;
}

std::string Clock::GetTimeString() {
  time_t timep;
  time(&timep); // 获取time_t类型的当前时间
  char t_str[64];
  strftime(t_str, sizeof(t_str), "%Y-%m-%d %H:%M:%S", localtime(&timep));
  return std::string(t_str);
}

std::string Clock::GetTimeString(std::string _format_str) {
  // TODO: 加正则判断 _format_str 是否合法
  time_t timep;
  time(&timep); // 获取time_t类型的当前时间
  char t_str[64];
  strftime(t_str, sizeof(t_str), _format_str.c_str(), localtime(&timep));
  return std::string(t_str);
}