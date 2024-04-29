#! /bin/sh
# PATH="/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/bin:/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/bin_cache:${PATH}"
# export PATH
rm -rf builder/*
if [ -f CMakeLists.txt ]; then
    echo "file CMakeLists.txt is ok"
else
    ln -sf /bin/CMakeLists.txt CMakeLists.txt
fi
mkdir -p builder
cd builder
cmake ..
read -n1 -p "Press any key to continue." var
make
exit 0
:!./%
:!chmod 777 ./%
