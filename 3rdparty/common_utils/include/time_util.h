#ifndef COMMON_UTILS_INCLUDE_TIME_UTIL_H
#define COMMON_UTILS_INCLUDE_TIME_UTIL_H
#include <string>

// microseconds(0.000001 second)
long long get_now_time_mms(void);

// milliseconds(0.001 second)
long long get_now_time_ms(void);

// seconds
double get_now_time_seconds(void);

std::string timestamp_to_human_readable(double timeStamp);

#endif //COMMON_UTILS_INCLUDE_TIME_UTIL_H
