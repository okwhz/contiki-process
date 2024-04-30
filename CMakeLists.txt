#2024-02-26 做了一个将git信息写入到主程序的示例
#主程序需要#include "CHECK_PRINT.h" #include <config.h>
## Make sure the compiler can find include files from our Hello library.
#include_directories (${HELLO_SOURCE_DIR}/Hello)
#
## Make sure the linker can find the Hello library once it is built.
#link_directories (${HELLO_BINARY_DIR}/Hello)
#
## Add executable called "helloDemo" that is built from the source files
## "demo.cxx" and "demo_b.cxx".  The extensions are automatically found.
#add_executable (helloDemo demo.cxx demo_b.cxx)
#
## Link the executable to the Hello library.
#target_link_libraries (helloDemo Hello)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
set (CMAKE_C_STANDARD 11)
project (contiki-process)
#{ 下面的语句是为了生成Git及编译信息
find_package(Git)
set(COMMIT_HASH "")
set(BRANCH_NAME "")
find_package(Git QUIET)
if(GIT_FOUND)
execute_process(
    COMMAND ${GIT_EXECUTABLE} log -1 --pretty=format:%H
    OUTPUT_VARIABLE COMMIT_HASH
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
execute_process(
    COMMAND ${GIT_EXECUTABLE} symbolic-ref --short -q HEAD
    OUTPUT_VARIABLE BRANCH_NAME
    OUTPUT_STRIP_TRAILING_WHITESPACE
    ERROR_QUIET
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
endif()
message(STATUS "Git version is ${BRANCH_NAME}:${COMMIT_HASH}")

# 原文链接：https://blog.csdn.net/guo_lei_lamant/article/details/89138827
# 执行git命令，并把结果重定向到自定义变量（此处是我的变量<GIT_VERSION>）。
execute_process(
    COMMAND git log -1 --format=%H
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_VERSION
)
execute_process(
    COMMAND git remote -v
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
    OUTPUT_VARIABLE GIT_REMOTE_PATH
)

# 对得到的结果进行处理，尤其注意 \n,\t,\r之类的特殊字符，在cmake时没问题，但是生成的.cmake文件有问题，导致make出错。
string (REGEX REPLACE ".*\t| .*" "" GIT_PATH ${GIT_REMOTE_PATH})
string (REGEX REPLACE "[\n\t\r]" "" GIT_VERSION ${GIT_VERSION})

# 增加编译选项，把宏导入源码
# add_definitions( -DGIT_VERSION=\"${GIT_VERSION}\")
# add_definitions( -DGIT_PATH=\"${GIT_PATH}\")

execute_process(COMMAND
        "${GIT_EXECUTABLE}" describe --always --abbrev=10 --dirty --tags
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE GIT_COMMIT_SHA1
        ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(COMMAND
        "${GIT_EXECUTABLE}" log -1 --format=%ad --date=local
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE GIT_COMMIT_DATE
        ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(COMMAND
        "${GIT_EXECUTABLE}" log -1 --format=%s
        WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
        OUTPUT_VARIABLE GIT_COMMIT_SUBJECT
        ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE
)

execute_process(COMMAND
    "${GIT_EXECUTABLE}" rev-parse --abbrev-ref HEAD
    WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
    OUTPUT_VARIABLE GIT_BRANCH_NAME
    ERROR_QUIET OUTPUT_STRIP_TRAILING_WHITESPACE
)

message(STATUS "")
message(STATUS "============================== GIT COMMIT LOG ==============================")
message(STATUS "=== update git commit SHA1     :    ${GIT_COMMIT_SHA1}")
message(STATUS "=== update git branch name     :    ${GIT_BRANCH_NAME}")
message(STATUS "=== update git commit date     :    ${GIT_COMMIT_DATE}")
message(STATUS "=== update git commit subject  :    ${GIT_COMMIT_SUBJECT}")
message(STATUS "============================================================================")
message(STATUS "")
# get git hash
macro(get_git_hash _git_hash)   # 宏的开始
    find_package(Git QUIET)     # 查找Git，QUIET静默方式不报错
    if(GIT_FOUND)
      execute_process(          # 执行一个子进程
        COMMAND ${GIT_EXECUTABLE} log -1 --pretty=format:%h # 命令
        OUTPUT_VARIABLE ${_git_hash}        # 输出字符串存入变量
        OUTPUT_STRIP_TRAILING_WHITESPACE    # 删除字符串尾的换行符
        ERROR_QUIET                         # 对执行错误静默
        WORKING_DIRECTORY                   # 执行路径
          ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endif()
endmacro()                      # 宏的结束

# get git branch
macro(get_git_branch _git_branch)   # 宏的开始
    find_package(Git QUIET)     # 查找Git，QUIET静默方式不报错
    if(GIT_FOUND)
      execute_process(          # 执行一个子进程
        COMMAND ${GIT_EXECUTABLE} symbolic-ref --short -q HEAD # 命令
        OUTPUT_VARIABLE ${_git_branch}        # 输出字符串存入变量
        OUTPUT_STRIP_TRAILING_WHITESPACE    # 删除字符串尾的换行符
        ERROR_QUIET                         # 对执行错误静默
        WORKING_DIRECTORY                   # 执行路径
          ${CMAKE_CURRENT_SOURCE_DIR}
        )
    endif()
endmacro()                      # 宏的结束
# include(../cmakes/getGitInfo.cmake)
# GIT_HASH
#set(GIT_HASH "")
get_git_hash(GIT_HASH)
message(STATUS "Git hash is ${GIT_HASH}")
#
## git_BRANCh
set(GIT_BRANCH "")
get_git_branch(GIT_BRANCH)
message(STATUS "Git branch is ${GIT_BRANCH}")

# Add the variables we need
set (VERSION_MAJOR 2)
set (VERSION_MINOR 30)
set (SOFT_VERSION \"V${VERSION_MAJOR}.${VERSION_MINOR}\")


execute_process(COMMAND git rev-parse --short HEAD  OUTPUT_VARIABLE GIT_COMMAND_ID)
execute_process(COMMAND date +"%Y%m%d %H:%M" OUTPUT_VARIABLE COMPILE_TIME)

string (REGEX REPLACE "[\n\t\r]" "" GIT_COMMAND_ID \"${GIT_COMMAND_ID}\")
string (REGEX REPLACE "[\n\t\r]" "" COMPILE_TIME ${COMPILE_TIME})

# Specify the configuration file from which the header file will be generated
# configure_file (config.h.in config.h @ONLY)
configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/config.h.ini
  ${CMAKE_CURRENT_SOURCE_DIR}/config.h
  @ONLY
  )
# add a directory with header files to see the generated file
# include_directories (${CMAKE_CURRENT_BINARY_DIR})
message("GIT_CID:${GIT_COMMAND_ID}")
message("COMPILE_TIME:${COMPILE_TIME}")
#}

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)
 ## 生成各种目标(target)文件: 可执行文件、动态库、静态库
# 指定可执行文件的输出目录，输出到bin下面
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})
# add_definitions( "-Wall -Os")
FIND_PACKAGE(wxWidgets)
#FIND_PACKAGE( wxWidgets REQUIRED base core gl adv xml xrc html qa )
IF( wxWidgets_FOUND )
    INCLUDE( ${wxWidgets_USE_FILE} )
    # 加入头文件路径
    INCLUDE_DIRECTORIES( ${wxWidgets_INCLUDE_DIRS} )
    # 加入库文件路径
    LINK_DIRECTORIES( ${wxWidgets_LIB_DIR} )
    #　要加入的库名
    message ( ${wxWidgets_LIBRARIES} )
#TARGET_LINK_LIBRARIES(main ${wxWidgets_LIBRARIES} )
ENDIF( wxWidgets_FOUND)

# Generic compiler flags
add_definitions(
    -Os
    -DUNIX_HOST
    -Wcomment
    -Wno-unused-parameter
    -Wall
    -DDEBUG_LEXER
    # C_P A_P是否显示彩色
    # -DMU_NOCOLOR
    # 是否使用A_P
    # -DASSERT__PRINT
)

add_compile_options(-march=native -O3 -fexceptions -pthread -fPIC)

#FIND AND ADD ALL HEADERS & SOURCES & ASM TO TARGET
MACRO(HEADER_DIRECTORIES RETURN_LIST)
    FILE(GLOB_RECURSE NEW_LIST *.h /b/program/c/*.h)
    SET(DIR_LIST "")
    FOREACH(FILE_PATH ${NEW_LIST})
        GET_FILENAME_COMPONENT(DIR_PATH ${FILE_PATH} PATH)
        SET(DIR_LIST ${DIR_LIST} ${DIR_PATH})
    ENDFOREACH()
    LIST(REMOVE_DUPLICATES DIR_LIST)
    SET(${RETURN_LIST} ${DIR_LIST})
ENDMACRO()

#HEADERS
HEADER_DIRECTORIES(INC)
INCLUDE_DIRECTORIES(. os os/services ${INC})
# INCLUDE_DIRECTORIES(/b/program/c/debug/ /b/program/c/minicsv_c/)

# 绝对引入
# link_libraries("D:\ProgramFiles\Qt\qt5_7_lib_shared_64\lib")

# 预定义变量引入
# PROJECT_SOURCE_DIR 是cmake的预定义变量，表示顶层CmakeList文件所在路径
# link_libraries(${PROJECT_SOURCE_DIR}/sqlite3/libsqlite3.a)

# 环境变量引入
# 环境变量 QT_LIB = D:\\ProgramFiles\\Qt\\qt5_7_lib_shared_64
# link_libraries($ENV{QT_LIB}/lib)
# AUX_SOURCE_DIRECTORY(/b/program/c/mini SRCS)
# AUX_SOURCE_DIRECTORY(/b/program/c/minicsv_c SRCS1)
# SET(SRCS ${SRCS} ${SRCS1})
# 加入调试程序
FILE(GLOB_RECURSE SRCS /b/program/c/*.c)
FILE(GLOB_RECURSE PENDING  /b/program/*/test.c)
FILE(GLOB_RECURSE PENDING1  /b/program/c/mini/builder/*.c)
FILE(GLOB_RECURSE PENDING2  /b/program/c/minicsv_c/builder/*.c)
FILE(GLOB_RECURSE PENDING3  builder/*.c)
SET(PENDING ${PENDING} ${PENDING1} ${PENDING2} ${PENDING3})
# MESSAGE("PENDING:" ${PENDING})
MESSAGE("SRCS:" ${SRCS})

# AUX_SOURCE_DIRECTORY(cstdlib SRCS1)
# SET(SRCS ${SRCS} ${SRCS1})

FILE(GLOB_RECURSE SRC1 ./os/sys/*.c)
AUX_SOURCE_DIRECTORY(native SRC2)

# STRING(REGEX REPLACE "[^;]*CMAKEFILES/[^;]+;?" "" SRC "${SRC}")
# file(GLOB_RECURSE sources CONFIGURE_DEPENDS *.cpp *.h)
# MESSAGE("sources:"${sources})
# LIST(REMOVE_ITEM SRC ${PENDING}) #新生成的SRCS就不包括pending目录的源文件了
SET(SRCS ${SRCS} ${SRC1} ${SRC2} os/lib/list.c os/net/linkaddr.c)
LIST(REMOVE_ITEM SRCS ${PENDING}) #SRCS就不包括pending目录的源文件
LIST(REMOVE_DUPLICATES SRCS)

MESSAGE("SRCS:" ${SRCS})

MESSAGE(STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})
ADD_EXECUTABLE(ks ${SRCS})
# TARGET_LINK_LIBRARIES(ks mysqlclient wxsqlite3 cryptopp dl)
TARGET_LINK_LIBRARIES(ks m readline sqlite3 pcap)
IF( wxWidgets_FOUND )
    TARGET_LINK_LIBRARIES(ks ${wxWidgets_LIBRARIES} )
ENDIF( wxWidgets_FOUND)
