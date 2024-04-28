<img src="https://github.com/contiki-ng/contiki-ng.github.io/blob/master/images/logo/Contiki_logo_2RGB.png" alt="Logo" width="256">

这个是一个学习Contiki内核的过程，学习使用Wiki文档

![](./assets/img/logo/c.svg)

## 入门知识

基本功很重要

- 虚拟机使用 - 学会安装、使用虚拟机,明白VMware几种网络连接的区别
    - 略

- 如何科学上网 - 懂得都懂
    - 略

- Markdown 语法 - 学会记笔记也很重要
    - 略

---

## 基础开发知识

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

## WEB开发

- dotnet
    - 暂时还没学完 : )

- java
    - 暂时还没学完 : )

- php
    - 暂时还没学完 : )

---

## 基础运维知识

### Linux运维

- Linux 是啥
    - [发行版](./1earn/Integrated/Linux/笔记/发行版.md)
    - [进程](./1earn/Integrated/Linux/笔记/进程.md)

- Linux 基础命令
    - [Speed-Linux](./1earn/Integrated/Linux/Speed-Linux.md)

- Linux 服务搭建 - 起码要学会怎么搭建 httpd、nginx
    - [Power-Linux](./1earn/Integrated/Linux/Power-Linux.md)

- Docker 使用 - 必须要掌握的,可以节约你大量时间
    - [Speed-Docker](./1earn/Integrated/虚拟化/Docker/Speed-Docker.md)

### 网络知识

- TCP/IP 模型 - 需要明白什么是IP、MAC，各层的常见协议有哪些分别什么作用
    - 略

### Windows服务器

- Windows 下常用命令
    - [Speed-Win](./1earn/Integrated/Windows/Speed-Win.md)

- Windows 服务器能干啥
    - [Windows基础服务搭建](./1earn/Integrated/Windows/实验/Windows基础服务搭建.md)

---

## web基础

- HTTP 协议
    - 略

- html+js
    - 略

- web 基础漏洞
    - [Web_Generic](./1earn/Security/RedTeam/Web安全/Web_Generic/Web_Generic.md)

- web 逻辑漏洞
    - [IDOR](./1earn/Security/RedTeam/Web安全/IDOR.md)

- 靶场 - 如果有空闲时间可以打打靶场练习
    - [靶场](https://github.com/No-Github/1earn/tree/master/1earn/Security/RedTeam/Web%E5%AE%89%E5%85%A8/%E9%9D%B6%E5%9C%BA)

## web进阶

- 各类通用漏洞利用
    - [BS-Exploits](./1earn/Security/RedTeam/Web安全/BS-Exploits.md)

- OOB
    - [OOB](./1earn/Security/RedTeam/Web安全/Web_Tricks/OOB.md)

- JWT
    - [JWT安全](./1earn/Security/RedTeam/Web安全/Web_Tricks/JWT安全.md)

## 代码审计

- 暂时还没学完 : )

---

## 主机安全

### linux

- linux 权限、文件
    - [认证](./1earn/Integrated/Linux/笔记/认证.md)
    - [文件](./1earn/Integrated/Linux/笔记/文件.md)

- linux 提权、漏洞利用
    - [OS-Exploits](./1earn/Security/RedTeam/OS安全/OS-Exploits.md#linux)

- linux lol
    - [Linux安全](./1earn/Security/RedTeam/OS安全/Linux安全.md#lol)

### windows

- windows 认证体系
    - [认证](./1earn/Integrated/Windows/笔记/认证.md)

- windows 提权、漏洞利用
    - [OS-Exploits](./1earn/Security/RedTeam/OS安全/OS-Exploits.md#windows)

- windows lol
    - [Windows-LOL](./1earn/Security/RedTeam/OS安全/实验/Windows-LOL.md)

- windows rdp 利用
    - [Windows安全](./1earn/Security/RedTeam/OS安全/Windows安全.md#rdp)

- windows 凭证抓取
    - [Windows安全](./1earn/Security/RedTeam/OS安全/Windows安全.md#认证)

---

## 后渗透

### 权限提升

- linux 提权
    - [OS-Exploits](./1earn/Security/RedTeam/OS安全/OS-Exploits.md#linux)

- windows 提权
    - [OS-Exploits](./1earn/Security/RedTeam/OS安全/OS-Exploits.md#windows)

- 第三方软件提权
    - [权限提升](./1earn/Security/RedTeam/后渗透/权限提升.md)

### 权限维持

- 各种 webshell
    - [权限维持](./1earn/Security/RedTeam/后渗透/权限维持.md#web)

- windows 权限维持
    - [权限维持](./1earn/Security/RedTeam/后渗透/权限维持.md#win)

- linux 权限维持
    - [权限维持](./1earn/Security/RedTeam/后渗透/权限维持.md#linux)

- 各类 C2、免杀
    - [权限维持](./1earn/Security/RedTeam/后渗透/权限维持.md#c2-rat)

### windows 域

- 工作组、域是什么、如何搭建域环境
    - [工作组](./1earn/Integrated/Windows/笔记/工作组.md)
    - [域](./1earn/Integrated/Windows/笔记/域.md)
    - [Windows 域搭建](./1earn/Integrated/Windows/实验/Windows域搭建.md)

- Kerberos
    - [认证](./1earn/Integrated/Windows/笔记/认证.md#域认证)

- 域凭证抓取
    - [Windows安全](./1earn/Security/RedTeam/OS安全/Windows安全.md#域)

- 域控提权
    - [OS-Exploits](./1earn/Security/RedTeam/OS安全/OS-Exploits.md#域)

- pth/k/t
    - [PTH](./1earn/Security/RedTeam/OS安全/Windows安全.md#pth)
    - [PTT](./1earn/Security/RedTeam/OS安全/Windows安全.md#ptt)

- Exchange
    - [Exchange 搭建](./1earn/Integrated/Windows/实验/Exchange搭建.md)
    - [Exchange](./1earn/Security/RedTeam/后渗透/实验/Exchange.md)

---

## 蓝队技能

### 蓝队服务搭建

### 分析技术

- linux 日志、信息
    - [日志](./1earn/Integrated/Linux/笔记/日志.md)
    - [信息](./1earn/Integrated/Linux/笔记/信息.md)

- windows 日志、信息
    - [日志](./1earn/Integrated/Windows/笔记/日志.md)
    - [信息](./1earn/Integrated/Windows/笔记/信息.md)

- 恶意文件分析
    - [分析](./1earn/Security/BlueTeam/分析.md)

### 取证技术

- 文件取证
    - [取证](./1earn/Security/BlueTeam/取证.md#文件取证)

- 内存取证
    - [内存取证](./1earn/Security/BlueTeam/笔记/内存取证.md)

- 流量分析
    - [流量分析](./1earn/Security/BlueTeam/实验/流量分析.md)

- 应用程序、WEB、数据库取证
    - [取证](./1earn/Security/BlueTeam/取证.md#应用程序取证)

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

2024-04-28 11:00 我准备学习它并精简它，只跟踪并保留os/sys/下的所有文件，其它不必要的文件全部删除，用来在Cmake的环境下学习Contiki内核。

