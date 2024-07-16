#ifndef COMMON_UTILS_INCLUDE_LOG_H
#define COMMON_UTILS_INCLUDE_LOG_H
// Original Author: Albert Zhang<xhzzhang@yeah.net>
// Last Changed: 2019-03-22 14:08:29

#ifdef __cplusplus

#include <glog/logging.h>
#include <glog/raw_logging.h>

// 一些不频繁但有关键的信息，比如说服务器地址和端口（调试信息除外）
#ifndef AINFO
#define AINFO LOG_IF(INFO, FLAGS_v >= google::GLOG_INFO)
#endif // AINFO

// 调试信息
#ifndef ADEBUG
#define ADEBUG AINFO << "[DEBUG] "
#endif // ADEBUG

// 异常信息，但是系统能运行
#ifndef AWARN
#define AWARN LOG_IF(WARNING, FLAGS_v >= google::GLOG_WARNING)
#endif // AWARN

// 直接影响系统的错误出现
#ifndef AERROR
#define AERROR LOG_IF(ERROR, FLAGS_v >= google::GLOG_ERROR)
#endif // AERROR

// 程序运行不下去的信息（调用该接口会立即将堆栈信息打印并挂掉）
#ifndef AFATAL
#define AFATAL LOG(FATAL)
#endif // AFATAL

#endif // __cplusplus

#define LOG_RESET   "\033[0m"
#define LOG_BLACK   "\033[30m"      /* Black */
#define LOG_RED     "\033[31m"      /* Red */
#define LOG_GREEN   "\033[32m"      /* Green */
#define LOG_YELLOW  "\033[33m"      /* Yellow */
#define LOG_BLUE    "\033[34m"      /* Blue */
#define LOG_MAGENTA "\033[35m"      /* Magenta */
#define LOG_CYAN    "\033[36m"      /* Cyan */
#define LOG_WHITE   "\033[37m"      /* White */
#define LOG_BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define LOG_BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define LOG_BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define LOG_BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define LOG_BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define LOG_BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define LOG_BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define LOG_BOLDWHITE   "\033[1m\033[37m"      /* Bold White */


#include <time.h>
#include <sys/time.h>
#define cidi_log(m, x, y, z, a, b) do { \
  long long_tmp_value = y * 1e3; \
  long ms_value = long_tmp_value % (long)1e3; \
  time_t time_secs = (time_t)y; \
  struct tm * p_tm = localtime(&time_secs); \
  printf(LOG_RED "%d-%02d-%02d %02d:%02d:%02d.%03ld %s:%d %d [%s] %s\n" LOG_RESET,\
      p_tm->tm_year + 1900, p_tm->tm_mon + 1, p_tm->tm_mday, p_tm->tm_hour, \
      p_tm->tm_min, p_tm->tm_sec, ms_value, a, b, x, m, z); \
} while (0)

// Params:
//  x: frame_id
//  y: time(double value, in seconds)
//  z: string
// 
// Sample:
//  vision_error(10, 1577245843.343, "vision test log");
//
// Result:
//  2019-12-25 11:50:43.343 math_test.cpp:274 000010 [vision_error] vision test log
// The detail of result:
//  '2019-12-25 11:50:43.343' is timestamps, and '343' is ms.
//  'math_test.cpp' is the current filename.
//  '274' is the line in filename.
//  '000010' is frame id.
//  '[vision_error]' is the module name.
//  'vision test log' is the message.
#define vision_error(x, y, z) cidi_log("vision_error", x, y, z, __FILE__, __LINE__)

#define lidar_error(x, y, z) cidi_log("lidar_error", x, y, z, __FILE__, __LINE__)

#define radar_error(x, y, z) cidi_log("radar_error", x, y, z, __FILE__, __LINE__)

#define fusion_error(x, y, z) cidi_log("fusion_error", x, y, z, __FILE__, __LINE__)

#define common_error(x, y, z) cidi_log("common_error", x, y, z, __FILE__, __LINE__)


/*
 * @param
 *    module_name   The tag name of log filename
 *    save_days     Allow max days to log save
 *    is_listen     If true then will listen /tmp/glog_info, if it exist, then
 *                  use INFO mode, otherwise use ERROR mode.
 *
 */
void init_log(int argc, char *argv[], char *log_path, int save_days,
    int is_listen);

std::string GenerateLogDatePath(std::string path);

void set_allow_info_log(int value);

#endif //COMMON_UTILS_INCLUDE_LOG_H
