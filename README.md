
这个是一个学习Contiki内核的过程，学习使用Wiki文档

![](picture/img/logo/c.svg)
# 获得一个最简版的内核

|[ProtoThread-Core](https://github.com/smartmx/ProtoThread-Core)|
在这个网址上已经把最简版的协程做了出来。但作者已经不再维护这个程序了，这个程序只存活了几个月。它可以使用，但我想要的是最新版的、可升级的一个内核。

## os/sys
这个文件夹下的所有内容我将其全部保留，它就是Contiki的内核，但它调用了许多os下dev、lib、net、services、storage、sys的.h文件。

- 进入os文件夹，删除所有的.c文件，执行:
rm *
find . -iname "*.c" |xargs rm
g c sys
g c lib/list.c
g c net/linkaddr.c
- 按需要修改native下的文件，即可在Linux下运行了

# 开发环境
### uname -a
Linux puppypc12898 4.9.163-lxpup-32-pae #1 SMP Thu Mar 14 15:41:19 GMT 2019 i686 i686 i686 GNU/Linux
### gcc --version
gcc (Ubuntu 7.4.0-1ubuntu1~18.04.1) 7.4.0
Copyright (C) 2017 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
### cmake --version
cmake version 3.10.2
# Contiki操作系统
# Contiki-ng
8f637885a  (HEAD -> develop) Merge branch 'master' of https://github.com/contiki-ng/contiki-ng into develop 2024-04-26 16:52:01 +0800
[中文文档1](https://docs.contiki-ng.org/en/master/doc/programming/Porting-Contiki-NG-to-new-platforms.html#create-some-examples]])
[中文文档](https://github.com/fengjikui/contiki-ng/wiki/Contiki%E2%80%90NG%E7%9A%84%E9%85%8D%E7%BD%AE%E7%B3%BB%E7%BB%9F)
[中文维基](https://docs.contiki-ng.org/en/develop/|develop)
[中文维基1](https://github.com/fengjikui/contiki-ng/wiki)
[sx128X](https://github.com/tperale/sx128x)
[教程](https://www.cnblogs.com/lijianGX/p/15414013.html)


### 入门知识

基本功很重要

- 编码风格：使用如下指令修改格式
    - astyle -r -n -F -A8 -c -s4 -xV -S -N -xt4 -xW -w -xw -Y -p -U -xe -k3 -W3 -e -j -xg -xf *.c *.h *.cpp

- 如何科学上网 - 懂得都懂
    - 略

- Markdown 语法 - 学会记笔记也很重要
    - 略

---

### 基础开发知识

- 字符编码 - 没啥好说的,基本功
    - 略

- git 及 github 的使用 - 多参与开源项目可以快速提高开发水平
    - [Git学习笔记](./1earn/Develop/版本控制/Git学习笔记.md)

- 数据类型的处理
    - xml
    - json

- 正则 - 了解正则语法
    - [regex](./1earn/Develop/正则/regex.md)

- python - 掌握语法,能够编写POC,能够按需求修改exp
    - 略

---


Find out more:

* GitHub repository: https://github.com/contiki-ng/contiki-ng
* Documentation: https://docs.contiki-ng.org/
* List of releases and changes: https://github.com/contiki-ng/contiki-ng/releases
* Web site: http://contiki-ng.org

Engage with the community:

* Discussions on GitHub: https://github.com/contiki-ng/contiki-ng/discussions
* Contiki-NG tag on Stack Overflow: https://stackoverflow.com/questions/tagged/contiki-ng
* Gitter: https://gitter.im/contiki-ng
* Twitter: https://twitter.com/contiki_ng

---

#### 更改
2024-04-28 11:00 我准备学习它并精简它，只跟踪并保留os/sys/下的所有文件，其它不必要的文件全部删除，用来在Cmake的环境下学习Contiki内核。
2024-04-29 11:38 增加了一个空的文件 os/services/test.h,否则编译时头文件路径不对
2024-04-29 17:09 增加了一个stack.c，里面定义了两个变量， int _stack_origin; int _stack;当前这个版本在Bionic Puppy中能正确编译Hello_Word.c程序了，但还不能连续输出HelloWorld，只输出一个字符串。
2024-04-30 10:01 修改main.c连续调用 etimer_request_poll();etimer工作正常了。
2024-04-30 10:59 增加了一个native，把所有修改的文件移动到此。改CmakeFile.txt文件 INCLUDE_DIRECTORIES(. os os/services ${INC}),删除test.h文件
2024-04-30 11:16 现在工程下只保留了os、native两个文件夹，在Linux运行成功了。精简完成。ks文件大小为46k
2024-04-30 15:25 把native文件夹下的文件数量精简到了12个。准备在建立一个stm32的框架。
2024-04-30 15:41 增加了一个CMakeLists.native的文件，CMakeLists.txt中包含它就能编译native了。
2024-05-01 11:00 将对clock_time_t的长度定义宏放入了contiki-confi.h,更改了rtimer.c包含Contiki.h,否则timer.h没有引用contiki.h
2024-06-30 15:20 增加了contiki/core/ctk,准备开发Cfiles，当前的版本增加执行C脚本的功能。删除了图像预览的功能，编译时不再显示警告。
2024-07-01 07:44 修改chdir、pipe没有返回值判断产生警告。
