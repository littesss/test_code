TCP: transform communication protocol 传输控制层协议
服务端：
    a. socket      ：建立套接字
    b. bind        ：绑定套接字，必须！
    c. listen      ：监听套接字
    d. accept      ：接受对端套接字
    e. recv/read   ：接受/读消息
    f. send/write  ：发送/写消息
    g. close       ：关闭套接字

客服端：
    a. socket      ：建立套接字
   ~b. bind        ：非必须绑定(客户端一般不建议bind)，绑定为了给客户端一个确切的port，不绑定内核分配，并且地址也会一并发送给服务端
    c. connect     ：连接服务器
    d. send/write  ：发送/写消息
    e. recv/read   ：接受/读消息
    f. close       ：关闭套接字

==================================================================
#socket
int socket(int domain, int type, int protocol);
int fd = socket(AF_INET, SOCK_STREAM, 0);
创建套接字：成功返回套接字，失败返回-1
domain:通信协议族，TCP/IP就是 AF_INET
type： 所要创建套接字的类型 流式套接字 SOCK_STREAM  数据报 SOCK_DGRAM
protocol: 应用程序所使用的通信协议。此参数可以指定单个协议系列中的不同传输协议。
 在Internet通讯域中，此参数一般取值为0，系统会根据套接字的类型决定应使用的传输层协议。
#struct sockaddr /struct sockaddr_in
 他两大小都是14字节，只不过前者系统已经帮我们填充好，后者需要自己填充
 struct sockaddr_in addr_Ser, addr_Cli;
 addr.Ser.sin_family = AF_INET;
 addr.Ser.sin_port = htons(8888); //主机PORT转换成网络短整形
 addr.Ser.sin_addr.s_addr = inet_addr("127.0.0.1"); //把点分字符串地址，转换成网地址
//查看结构体在 /usr/include    命令：grep 'sockaddr\_in' -inr 

#bind
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
int ret = bind(fd, (struct sockadd*) &addr_Ser , sizeof(addr_Ser));
绑定套接字： 成功放回0， 失败返回-1
fd : 文件描述符号
addr: sockaddr 结构体类型的指针，需要强转，记录服务器通信协议，端口，IP
addrlen: 结构体大小

#listen
int listen(int sockfd, int backlog);
int ret = listen(fd, MAX_LISTEN_QUEUE);
监听套接字：成功返回0 ，失败返回-1
fd: 文件描述符
backlog:监听消息队列，这个参数适用于client与server建立连接的过程，当一个client与
  服务器连接的时候，都知道tcp会经过三次握手，这需要一个过程，这期间又来了一个请求也
  想与服务器建立连接，但是上一个还没有处理完，没办法，排队去吧，当上一个处理完了
  ，再处理下一个，这个参数就是指定了这个队伍的最大长度
  这个过程完成之后就属于原来主动套接字，就变成被动套接字，也就属于监听套接字了

#accept
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
int fdConn = (fd, (struct sockaddr*) &addr_Cli, &len);
接受客户端请求函数：成功返回客户端文件描述符，失败返回-1,他的返回值是与请求连接的
    套接字成功对接之后，系统内核返回一个新的套接字，用于数据传输。

fd: 是由主动套接字通过listen之后变为被监听套接字，也就是被动套接字
add_Cli:用来存放客户端的IP PORT 信息
addrlen: 结构体大小的指针

#recv read
ssize_t recv(int sockfd, void *buf, size_t len, int flags);
接收消息
ssize_t read(int fd, void *buf, size_t count);
读取消息

#send write
ssize_t send(int sockfd, const void *buf, size_t len, int flags);
发送消息
ssize_t write(int fd, const void *buf, size_t count);
写消息

#close
int close(int fd);
关闭文件描述符

======================================================================================
#socket
#bind
#connect
int connect(int sockfd, const struct sockaddr *addr,  socklen_t addrlen);
int ret = connect(fd, (struct sockaddr*) &addr_Ser, sizeof(addr_Ser ));
将未建立连接的套接字（主动连接套接字）与服务器端进行连接：成功返回0， 失败返回-1
#send write
#recv write

总结：
1. socket bind listen accept recv/read  send/write close connect 均为系统调用函数
2. accept 是阻塞函数，原因TCP是可靠的连接,返回值返回一个新的文件描述符
3. 要解析对端IP地址inet_ntoa();
   struct addr_in
  {
    unit32_t s_addr;
  }
  struct addr_in addr_peer;
  addr_peer.s_addr = addr_Cli.sin_addr.s_addr;
  char * IP = inet_ntoa(addr_peer);
  解析对端port :ntohs();
  int port_peer = ntohs(addr_Cli.sin_port);
4. 要实现通信就是只要知道服务端这边的IP，port就可以实现通信，所以服务端这边必须要bind
   自己的IP和port，而客户端这边一般不需要bind,当然内核会分配一个随机端口，非要bind有可能
   会导致程序出错，你bind 的是一个其他服务

5. 服务器这边会直接把客户端的地址一并发过来，虽然客户端没有bind，同意系统也会一并发送过来

6. INADDR_ANY 是一个宏0x00000000，标示接受任何地址<netinet/in.h>头文件中；

7. TCP 一般情况是recv / send 但是read / write也可以发送与接受，UDP recvfrom /sendto 

8. 最后记得close关闭套接字，释放占有的系统资源


