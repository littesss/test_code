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
#include <signal.h>
#include <sys/wait.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void do_server(int conn)
{
    char recvbuf[512];
    while(1)
    {
        memset(recvbuf, 0, sizeof(recvbuf));
        int ret = read(conn, recvbuf, sizeof(recvbuf));
        if(ret == 0)
        {
            printf("client close\n");
            break;
        }
        else if(ret == -1)//避免死循环
        {
            perror("read");
            break;
        }
        fputs(recvbuf, stdout);//会得到\n
        write(conn, recvbuf, ret);
    }
    close(conn);
}

void handler(int sig)
{
    cout << "recv sig=" << sig << endl;
   // close(conn);
   // close(listenfd);
    exit(0);
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
    conn = accept(listenfd, (struct sockaddr*)&peeraddr, &peerlen);
    if(conn < 0)
    {
        perror("conn");
        exit(1);
    }
//多进程处理多客户端连接
    pid_t pid;
    int status = 0;
    pid = fork();
    if(pid == -1)
    {
        perror("fork");
    }
    if(pid == 0)
    {
        char sendbuf[1024] = {0};
        signal(SIGUSR1, handler);
        while(fgets(sendbuf, sizeof(sendbuf), stdin) != NULL)
        {
            write(conn, sendbuf, strlen(sendbuf));
            memset(sendbuf, 0, sizeof(sendbuf));
        }
        cout << "以下代码不会执行到的" << endl;
        close(conn);
        exit(0);
    }
    else
    {
        char recvbuf[1024];
        while(1)
        {
            memset(recvbuf, 0, 1024);
            int ret = read(conn, recvbuf, sizeof(recvbuf));
            if(ret == -1)
            {
                perror("read");
                exit(1);
            }
            else if(ret == 0) 
            {
                printf("peer close\n");
                break;
            }
            fputs(recvbuf, stdout);
        }
        close(conn);
        close(listenfd);
        cout << "parent close" << endl; 
        kill(pid, SIGUSR1);

        wait(&status);  // 等待子进程结束
    }
    close(listenfd);
    close(conn);
    cout << "last code will be executed????" << endl;
      return 0;
}
