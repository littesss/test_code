/*************************************************************************
	> File Name: ser.cpp
	> Created Time: Sun 29 Oct 2017 09:00:58 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//处理粘包问题
//封装read函数

struct packet
{
    int  len;        //包头
    char buf[1024];  //包体，实际长度
};
ssize_t readn(int fd, void* buf, size_t count)
{
    size_t nleft = count;//剩余的字节数
    ssize_t nread;       //已经接受的字节数
    char* bufp = (char*)buf;

    while(nleft > 0)
    {
        if((nread = read(fd, bufp, nleft))<0)
        {
            cout << " < 0" << endl;
            if(errno == EINTR) //信号打断
                continue;
            return -1;
        }
        else if(nread == 0)
        {
            cout << " = 0" << endl;
            //break;
            return count-nleft;
        }
        cout << " > 0" << endl;
        bufp += nread;//偏移到屁股
        nleft -= nread;
    }
    return count;
}
//封装write方法
ssize_t writen(int fd, const void* buf, size_t count)
{
    size_t nleft = count;
    ssize_t nwritten;
    char* bufp = (char*)buf;

    while(nleft > 0)
    {
        if((nwritten = write(fd, bufp, nleft)) < 0)
        {
            if(errno == EINTR) //信号中断
                continue;
            return -1;
        }
        else if(nwritten == 0)
        {
            continue;
           //return count-nleft;
        }
        bufp += nwritten;
        nleft -= nwritten;
    }
    return count;
}
/////////////////////////////////////
void do_server(int conn)
{
    struct packet recvbuf;
    while(1)
    {
        memset(recvbuf.buf, 0, sizeof(recvbuf.buf));
        int ret = readn(conn, &recvbuf.len, 4);
        if(ret == -1)
        {
            perror("read");
            exit(1);
        }
        if(ret < 4)
        {
            cout << "clien close\n";
            break;
        }
       
        int n = ntohl(recvbuf.len);
        readn(conn, &recvbuf.buf, n);
        if(ret == -1)
        {
            perror("read");
            exit(1);
        }
        if(ret < n)
        {
            cout << "clien close\n";
            break;
        }
        fputs(recvbuf.buf, stdout);
        writen(conn, &recvbuf, 4+n);

    }
    close(conn);
}


int main()
{
    int listenfd;
    //初始化监听套接字(默认是主动套接字，发起连接)
    if((listenfd = socket(AF_INET, SOCK_STREAM, 0))<0)
    {
        perror("socket created failed");
        exit(1);
    }
    //bind函数，bind一个本地地址到套接字
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family =  AF_INET;
    servaddr.sin_port = htons(8881);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    /*servaddr.sin_addr.s_addr = inet_addr("127.0.0.1")*/

////////////////////////////getsockopt///////////    
    int on = 1;//开启地址重复利用
    if(setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)
    {
        perror("setsockopt");
    }
//////////////////////////////////////////////////
    if(bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind a local addr to listenfd failed...");
        exit(1);
    }

    //listen 讲套接字用于监听进入的连接，讲套接字从close状态转换成监听状态
    //也就是说调用listen函数就将套接字由主动变为被动套接字（接受连接）
    if(listen(listenfd, SOMAXCONN) < 0)//SOMAXCONN 默认最大队列
    {
        perror("listenfd to listen client connect failed..");
        exit(1);
    }
    
    //accept 从已经连接的队列中返回是第一个连接，队列为空就阻塞
    //成功返回一个新的套接字，也就是连接套接字，并且这个新套接字是主动套接字
    struct sockaddr_in peeraddr;
    socklen_t peerlen = sizeof(peeraddr);//必须初始值
    int conn;

///多进程处理多客户端连接
    pid_t pid;
    while(1)
    {
        if((conn = accept(listenfd, (struct sockaddr*)&peeraddr, &peerlen)) < 0)
        {
            perror("accept client connect failed...");
            exit(1);
        }
        cout << "Ip:" << inet_ntoa(peeraddr.sin_addr) << " port:" << ntohs(peeraddr.sin_port) << endl;
        
        pid = fork();
        if(pid < 0)
        {
            perror("fork");
            exit(1);
        }
        if(pid == 0) // 子进程处理客户端连接
        {
            close(listenfd);
            do_server(conn);
        }
    }
    return 0;
}
