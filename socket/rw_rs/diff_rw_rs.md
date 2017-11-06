1.read/write :套接口，文件IO的读写,任何文件的IO
2.recv/send :只用于套接口IO
3.recvfrom/sendto:套接口IO,用于UDP

1. \n 与 \r 的区别
 \n 换取到下一行，并且至行首
 \r 回车，光标回到行数
 不同操作系统由不同的区别，
 Windows Enter其实是回车加换行

2. getsockname() //获取本机IP，端口
  getpeername()  //获取对端IP，端口（前提必须是已连接套接字）
