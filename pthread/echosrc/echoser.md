1. netstat -an|grep TIME_OUT 
   服务器在关闭进程之后可能还会保留一段时间bind，此时就需要REUSEADDR，在bind之前尽可能调用
   getsockopt()函数来设置它。

2. 处理多个客户端的连接,fork，也就是说一个连接，一个进程来处理并发
   三次握手发生在listen过程

3. 客户端关闭，服务器捕捉coon  == 0 , break; exit子进程
