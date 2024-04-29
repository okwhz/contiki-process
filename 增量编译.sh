#! /bin/sh
PATH="/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/bin:/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/bin_cache:${PATH}"
export PATH
rm builder/HELLO.elf
# 删除下面的三个文件可解决CUBE生成工程文件出错的问题
rm .project  .mxproject  .cproject
# cp system/ram/* .
cp .gdbinit ~
if [ -f CMakeLists.txt ]; then
    echo "file CMakeLists.txt is ok"
else
    ln -sf /bin/CMakeLists.txt CMakeLists.txt
fi
if [ -d builder ]; then
    cd builder
else
    mkdir builder
    cd builder
    cmake ..
fi
make
head HELLO.list | tail -n2
read  -n1 -p "Press any key to continue." var
#st-flash --reset write ROM.bin 0x8000000
#st-util -p 6688
