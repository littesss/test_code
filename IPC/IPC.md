进程间通讯：IPC inter process communication
第一类：传统的unix通信机制：
# 管道( pipe  )：管道是一种半双工的通信方式，数据只能单向流动，而且只能在具有亲缘
  关系的进程间使用。进程的亲缘关系通常是指父子进程关系。
# 有名管道 (named pipe) ： 有名管道也是半双工的通信方式，但是它允许无亲缘关系进程
  间的通信。
# 信号 ( sinal  ) ： 信号是一种比较复杂的通信方式，用于通知接收进程某个事件已经发
  生。

第二类：System V IPC： 
# 信号量( semophore  ) ： 信号量是一个计数器，可以用来控制多个进程对共享资源的访
  问。它常作为一种锁机制，防止某进程正在访问共享资源时，其他进程也访问该资源。因 
  此，主要作为进程间以及同一进程内不同线程之间的同步手段。
# 消息队列( message queue  ) ： 消息队列是由消息的链表，存放在内核中并由消息队列
  标识符标识。消息队列克服了信号传递信息少、管道只能承载无格式字节流以及缓冲区大
  小受限等缺点。
# 共享内存( shared memory  ) ：共享内存就是映射一段能被其他进程所访问的内存，这段
  共享内存由一个进程创建，但多个进程都可以访问。共享内存是最快的 IPC 方式，它是针
  对其他进程间通信方式运行效率低而专门设计的。它往往与其他通信机制，如信号两，配
  合使用，来实现进程间的同步和通信。

第三类：BSD 套接字：
# 套接字( socket  ) ： 套解字也是一种进程间通信机制，与其他通信机制不同的是，它可
  用于不同及其间的进程通信。

===================================================================================

一. unix
                         pipe: 无名管道，匿名管道
1. int pipe(int fd[2]);
  a. 成功返回0，失败返回-1；  
     fd[0] 读read，fd[1] 写write   // 不能反了，会出错
  b. 必须是有血缘关系的进程
  c. fork(),一端读时候必须先把另外一端关闭，注意要read时候先wait()write端写完,
  d. 记得close掉fd

用到函数： pipe  fork read write close waitpid
#waitpid(fd, status, 0)
===============================================================================
                          FIFO: 命名管道

2. int mkfifo("pathname",0666);//创建一个管道文件
  a. 成功返回0，失败返回-1；
  b. 非血缘关系的进程之间的通信
  c. 也是半双工通信;
  d. 一个进程读，另外一个进程写;

用到的函数： mkfifo  open read write lseek close
#lseek(fd,2,SEEK_SET);
===============================================================================
                        signal:信号
3. typedef void (*sighandler_t)(int);
   sighandler_t signal(int signum, sighandler_t handler);
  
   void signalhandle(int signum);
   void  (*signal(int signum,void(*gsignalregist)(int))  (int)
   
   注册信号处理函数
   signal(2, signalhandle );  //调用信号处理函数signalhandle, 其中该函数自己定义
   signal(3, SIG_IGN);        // 信号忽略
   signal(20, SIG_DFL);       // 信号默认处理

查看所有信号：kill -l         //64种信号
SIGHUP    1   挂起信号
SIGINT    2   中断信号ctrl+c
SIGQUIT   3  退出信号ctrl+\
SIGKILL   9  杀死进程
SIGALRM   14 闹钟信号
SIGTERM   15 终端信号
SIGSTOP   20 停止信号ctrl+z
 
用到函数：signal  alarm sleep 
#alarm(second); 定时多少秒后给进程发送SIGALAM（14），成功返回0
#sleep(second); 让进程休眠多少秒后在执行
#pause(); 挂起进程，直到有信号被中断，返回值只有-1；
================================================================================
                    message queue:消息队列
4. int msgget(key_t key, int msgflg);
   key_t 是消息队列的标示，
   msgflg, 是创建消息队列的flag   包括IPC_CREAT and IPC_EXCL
   成功返回：消息队列的标示符msgid  失败返回：-1

   struct msgbuf 
   {
       long mtype;       /* message type, must be > 0 */
       char mtext[BUFSIZ];    /* message data *///BUFSIZ 是宏定义的8k大小
   };

  int msgsnd(int msqid, const void *msgp, size_t msgsz, int msgflg);
  向消息队列发送消息，失败返回-1.成功返回0
  第二个参数是（void*）类型的msgbuf的结构体
  第三个参数是 BUFSIZ
  第四个参数是 一般为0，这个参数依然是是控制函数行为的标志，取值可以是：0,表示忽略；
  IPC_NOWAIT，如果消息队列为空，则返回一个ENOMSG，并将控制权交回调用函 数的进程。如
  果不指定这个参数，那么进程将被阻塞直到函数可以从队列中得到符合条件的消息为止。如
  果一个client 正在等待消息的时候队列被删除，EIDRM 就会被返回。如果进程在阻塞等待
  过程中收到了系统的中断信号，EINTR 就会被返回。MSG_NOERROR，如果函数取得的消息长
  度大于msgsz，将只返回msgsz 长度的信息，剩下的部分被丢弃了。如果不指定这个参数，
  E2BIG 将被返回，而消息则留在队列中不被取出。当消息从队列内取出后，相应的消息就
  从队列中删除了。
 
  ssize_t msgrcv(int msqid, void *msgp, size_t msgsz, long msgtyp, int msgflg);
  从消息队列里获取消息，失败返回-1.成功返回0
  msgtyp：消息类型
  msgtyp等于0 则返回队列的最早的一个消息。
  msgtyp大于0，则返回其类型为mtype的第一个消息。
  msgtyp小于0,则返回其类型小于或等于mtype参数的绝对值的最小的一个消息。

  int msgctl(int msqid, int cmd, struct msqid_ds *buf);
  msgctl系统调用对msqid标识的消息队列执行cmd操作列。 
  IPC_STAT
  读取消息队列的数据结构msqid_ds，并将其存储在b u f指定的地址中。
  IPC_SET
  设置消息队列的数据结构msqid_ds中的ipc_perm元素的值。这个值取自buf参数。
  IPC_RMID
  从系统内核中移走消息队列。

消息队列和管道的区别：
    消息队列：数据结构，存放在内存中，读取速度快
    管道： 文件,存放在磁盘中，读取要经过缓冲区
    都只能一端读，一端写，半双工通信 
#用到的函数 msgget msgsnd msgrcv msgctl strcpy strncmp fgts
#fgets(buff, 512, stdin) // 从标准输入里获取512自己大小的数据存放到buff里
===============================================================================
                    share memory :共享内存
5. int shmget(key_t key, size_t size, int shmflg);
  int shmid = ((key_t)1234, 1024, 0666|IPC_CREAT);
  创建一个消息队列，成功返回共享内存ID号，失败返回-1；
  key:类似消息队列的标识，这个是共享内存的标识
  size：大小
  shmflg: 共享内存的标识0666|IPC_CREAT

  void *shmat(int shmid, const void *shmaddr, int shmflg);
  char * addr shmat(shmid, 0, 0)
  把物理内存映射到进程空间中，成功返回共享内存地址，失败返回（void*）-1;
  shmaaddr : 0 系统自动帮我们找到所需地址
  shmflg: 一般情况为0，和消息队列mode 一样，前面已经设置过了
#用到的函数 shmget shmat shmdt移除消息队列 shmctl类似与消息队列的msgctl
#if(!strncmp(buff,"end",3)) // 判断buff是否和end 相同
#fgets(buff,1024, stdin) // 从标准输入流中输入数据
=============================================================================


