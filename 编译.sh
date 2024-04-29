#! /bin/sh
PATH="/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/bin:/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/bin_cache:${PATH}"
export PATH
menurunpath=$(cd `dirname $0`; pwd) #获得了当前正在执行的脚本（链接）的存放路径
export menurunpath
if [ -f /b/bin/shellmenu.sh ] ; then
    source "/b/bin/shellmenu.sh"
else
    source "../shellmenu.sh"
fi

function AllComplie(){
    #! /bin/sh
    # PATH="/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/bin:/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/bin_cache:${PATH}"
    # export PATH
    menurunpath=$(cd `dirname $0`; pwd) #获得了当前正在执行的脚本（链接）的存放路径
    # cd $menurunpath
    # pwd
    # read  -n1 -p "Press any key to continue." var
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
    head HELLO.list | tail -n2
    # read -n1 -p "Press any key to continue." var
    exit 0
    :!./%
    :!chmod 777 ./%
}
function Complie(){
    #! /bin/sh
    # PATH="/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/bin:/CodeSourcery/Sourcery_CodeBench_Lite_for_ARM_EABI/bin_cache:${PATH}"
    # export PATH
    pwd
    rm builder/HELLO.elf
    # 删除下面的三个文件可解决CUBE生成工程文件出错的问题
    rm .project  .mxproject  .cproject
    # cp system/ram/* .
    cp .gdbinit ~
    menurunpath=$(cd `dirname $0`; pwd) #获得了当前正在执行的脚本（链接）的存放路径
    # pwd
    # cd $menurunpath
    # pwd
    # read  -n1 -p "Press any key to continue." var
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
    # read  -n1 -p "Press any key to continue." var
    #st-flash --reset write ROM.bin 0x8000000
    #st-util -p 6688
}
function Download(){
    #! /bin/sh
    pwd
    cd $menurunpath
    pwd
    read -n1 -p "Press any key to continue." v
    stm32flash -w builder/HELLO.hex -g0x0 /dev/ttyUSB0 -b115200
    stm32flash -w builder/HELLO.hex -g0x0 /dev/ttyUSB1 -b115200
    stm32flash -w builder/HELLO.hex -g0x0 /dev/ttyUSB2 -b115200
    stm32flash -w builder/HELLO.hex -g0x0 /dev/ttyUSB3 -b115200
    stm32flash -w builder/HELLO.hex -g0x0 /dev/ttyUSB4 -b115200
    # exit 0
    :!./%
    :!chmod 777 ./%
}
function Reset(){
    #! /bin/sh
    pwd
    cd $menurunpath
    pwd
    stm32flash  -g0x0 /dev/ttyUSB0 -b115200
    stm32flash  -g0x0 /dev/ttyUSB1 -b115200
    # exit 0
    :!./%
    :!chmod 777 ./%
}
submenuHead "编译选项"
    menuItem a "全部编译" AllComplie
    menuItem c "编译" Complie
submenuHead "调试"
    menuItem r "运行" "time $menurunpath/ks"
startMenu
#st-flash --reset write ROM.bin 0x8000000
#st-util -p 6688
