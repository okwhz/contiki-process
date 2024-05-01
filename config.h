#ifndef CONFIG_H_IN
#define CONFIG_H_IN

/**
 * define 会直接根据规则来替换
 */
#define VERSION_MAJOR 1
#define VERSION_MINOR 01
#define SOFT_VERSION "V1.01"
#define GIT_PATH "git@github.com:okwhz/contiki-process.git"
#define GIT_VERSION "06727b49c2aedd4e949d62be022e1925ecd252aa"
#define GIT_COMMAND_ID "06727b4"
#define BRANCH_NAME "develop"
#define COMPILE_TIME "20240501 12:14"
#define COMMIT_DATE    "Wed May 1 11:04:46 2024"
#define COMMIT_SUBJECT "2024-05-01 11:00 将对clock_time_t的长度定义宏放入了contiki-confi.h,更改了rtimer.c包含Contiki.h,否则timer.h没有引用contiki.h"

#endif
