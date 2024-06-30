## fork()函数
https://blog.csdn.net/cckluv/article/details/109169941

 在语句fpid=fork()之前，只有一个进程在执行这段代码，但在这条语句之后，就变成两个进程在执行了，这两个进程的几乎完全相同，将要执行的下一条语句都是if(fpid<0)……
    为什么两个进程的fpid不同呢，这与fork函数的特性有关。fork调用的一个奇妙之处就是它仅仅被调用一次，却能够返回两次，它可能有三种不同的返回值：
    1）在父进程中，fork返回新创建子进程的进程ID；
    2）在子进程中，fork返回0；
    3）如果出现错误，fork返回一个负值；
## execl函数

exec族实际包含有 6 个不同的 exec 函数，它们功能一样，主要是传参的形式不同， 函数原型分别如下：

    int execl(const char *path, const char *arg, ...)
    int execlp(const char *file, const char *arg, ...)
    int execle(const char *path, const char *arg, ..., char *const envp[])
    int execv(const char *path, char *const argv[])
    int execvp(const char *file, char *const argv[])
    int execve(const char *path, char *const argv[], char *const envp[])

这些函数可以分为两大类，execl、execlp和execle传递给子程序的参数个数是可变的， 如“ls -la”示例中，“-la”为子程序“ls”的参数。 execv、execvp和execve通过数组去装载子程序的参数，无论那种形式，参数都以一个空指针NULL结束，

总结来说，可以通过它们的后缀来区分他们的作用：

    名称包含 l 字母的函数（execl、execlp和execle）接收参数列表“list”作为调用程序的参数。

    名称包含 p 字母的函数（execvp 和 execlp）可接受一个程序名作为参数， 它会在当前的执行路径和环境变量“PATH”中搜索并执行这个程序（即可使用相对路径）； 名字不包含p字母的函数在调用时必须指定程序的完整路径（即要求绝对路径）。

    名称包含 v 字母的函数（execv、execvp 和 execve）的子程序参数通过一个数组“vector”装载。

    名称包含 e 字母的函数（execve 和 execle）比其它函数多接收一个指明环境变量列表的参数， 并且可以通过参数envp传递字符串数组作为新程序的环境变量， 这个envp参数的格式应为一个以 NULL 指针作为结束标记的字符串数组， 每个字符串应该表示为“environment = virables”的形式。

 
————————————————

                            版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。
                        
原文链接：https://blog.csdn.net/weixin_64685646/article/details/138044220
