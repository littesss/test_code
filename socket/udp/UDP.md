UDP:  用户数据报协议(User Datagram Protocol)
一般会分为：服务端/客户端
服务端：
    a.首先用来接受客户端的消息，然后就可以给客户端发消息
    b.所以服务端必须bind，自己的IP，port（sockaddr_in), 用来和客户端建立连接，客户端知道知道
      服务端的IP,

客户端：
    a.先给服务端发送消息，socket建立连接后就可接受服务端消息了
    b.客户端不必bind，如果一定想要bind的话也行，服务器那边就可以获取客户端IP地址

步骤：
server：
1.socket（） ：建立套接字
2.bind（）   ：绑定套接字，bind a name to a socket
3.recvfrom() ：从客户端获取信息

client：
1.socket()   :建立套接字
2.sendto()   :给服务器发送消息
    

