#ifndef CONFIG_H_IN
#define CONFIG_H_IN

/**
 * define 会直接根据规则来替换
 */
#define VERSION_MAJOR 1
#define VERSION_MINOR 01
#define SOFT_VERSION "V1.01"
#define GIT_PATH "git@github.com:okwhz/contiki-process.git"
#define GIT_VERSION "cf1795ebc32ead8d4acbfa8f67543f5c4431bf67"
#define GIT_COMMAND_ID "cf1795e"
#define BRANCH_NAME "develop"
#define COMPILE_TIME "20240701 16:32"
#define COMMIT_DATE    "Mon Jul 1 07:45:36 2024"
#define COMMIT_SUBJECT "2024-07-01 07:44 修改chdir、pipe没有返回值判断产生警告。"

#endif
