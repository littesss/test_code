五种IO模型
1. 阻塞IO

2. 非阻塞IO 
   fcntl(fd, F_SETFL, flag|O_NONBLOOK)
   循环接受数据，又要占CPU，故称为忙等待

3. IO复用：阻塞 管理着
   select：管理多个IO
   一旦其中一个IO或者多个IO检测到我们感兴趣的事件
   select函数返回，返回值为检测到的事件数
   并且返回那些IO发生了事件
   遍历这些事件，进而处理事件
#select
int select(int nfds, fd_set *readfds, fd_set *writefds,
           fd_set *exceptfds, struct timeval *timeout);
成功返回检测到的事件个数，失败返回-1

第一个参数：存放到集合中的描述符最大值+1
第二个参数：读操作集合
第三个参数：写操作集合
第四个参数：异常事件集合
第五个参数：超时时间

void FD_CLR(int fd, fd_set *set);
讲文件描述符从集合中移除
int  FD_ISSET(int fd, fd_set *set);
判定fd是否在集合中  //返回事件个数
void FD_SET(int fd, fd_set *set);
讲fd添加到集合中
void FD_ZERO(fd_set *set);
清空fd

4. 信号驱动IO
    SIGIO ：以信号的方式来通知应用进程

5. 异步IO：效率最高,内核推送给应用程序
    aio_read

