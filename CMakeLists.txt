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
file(MAKE_DIRECTORY ./builder)
include(CMakeLists.native)
