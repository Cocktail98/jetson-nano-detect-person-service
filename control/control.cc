#include "control.h"

bool Control::IsSleepTime() {
  // TODO: 引入参数，使其可以更新
  time_t timep;
  time(&timep); // 获取time_t类型的当前时间
  tm *ltm = localtime(&timep);

  // 判断闭馆时间
  if (ltm->tm_hour < 7 || ltm->tm_hour > 23)
    return false;

  return true;
}