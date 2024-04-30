#ifndef CONFIG_H_IN
#define CONFIG_H_IN

/**
 * define 会直接根据规则来替换
 */
#define VERSION_MAJOR 2
#define VERSION_MINOR 30
#define SOFT_VERSION "V2.30"
#define GIT_PATH "git@github.com:okwhz/contiki-process.git"
#define GIT_VERSION "1a2069712b687729323bdd1a62297f5485459a7b"
#define GIT_COMMAND_ID "1a20697"
#define BRANCH_NAME "develop"
#define COMPILE_TIME "20240430 11:14"
#define COMMIT_DATE    "Tue Apr 30 11:04:49 2024"
#define COMMIT_SUBJECT "2024-04-30 10:59 增加了一个native，把所有修改的文件移动到此。改CmakeFile.txt文件 INCLUDE_DIRECTORIES(. os os/services ${INC}),删除test.h文件"

#endif
