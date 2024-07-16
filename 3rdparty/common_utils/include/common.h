#ifndef COMMON_UTILS_INCLUDE_COMMON_H
#define COMMON_UTILS_INCLUDE_COMMON_H
//#pragma once
#include <string>

#ifndef ARRAY_SIZE
#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#endif

typedef void* (*thread_callback)(void*);


/**
 * x: Real handler(support function class)
 * y: If the 'x' is function of class, the value is 'this'
 */
#define DEF_TO_STRING(S) #S
#define ACTIVATE_THREAD(x, y)                      \
  do {                                             \
    char const *threadX = DEF_TO_STRING(x);        \
    char threadName[16] = {0};                     \
    thread_callback callback = (thread_callback)x; \
    pthread_t pid;                                 \
    pthread_create(&pid, NULL, callback, y);       \
		memcpy(threadName, threadX + 6, strlen(threadX) - 6 > 15 ? 15 : strlen(threadX) - 6);                              \
		pthread_setname_np(pid, threadName);           \
    pthread_detach(pid);                           \
  } while (0)

/**
 * @beif Get mac address(order: 'eth*', 'en*', 'wlan*')
 *
 * retval: if it's not NULL, need free it.
 */
int get_mac_addr(char *out_data, int out_size);

long generate_random_num(void);

char* generate_random_string(int length);

std::string generate_serial_code(void);

std::string md5_sum_text(std::string input);

int call_cmd(const char *cmd, char *out_buffer, int out_buflen);

#endif //COMMON_UTILS_INCLUDE_COMMON_H