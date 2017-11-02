/*************************************************************************
  > File Name: ser.cpp
  > Created Time: Sun 29 Oct 2017 09:00:58 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <sys/types.h>
#include <signal.h>
#include <arpa/inet.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void handler(int sig)
{
    printf("recv a sig=%d\n",sig);
    exit(0);
}
int main()
{
    int sock;
    //初始化监听套接字(默认是主动套接字，发起连接)
    if((sock = socket(AF_INET, SOCK_STREAM, 0))<0)
    {
        perror("socket created failed");
        exit(1);
    }
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family =  AF_INET;
    servaddr.sin_port = htons(8881);
    //servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    //connect ,发起连接
    if(connect(sock, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) 
    {
        perror("connect ser is failed\n");
        exit(1);
    }

    char sendbuf[1024] = {0};
    char recvbuf[1024] = {0};
    pid_t pid;
    pid  = fork();
    if(pid < 0)
    {
        perror("fork");
        exit(1);
    }
    if(pid == 0)
    {
        while(1)
        {
            memset(recvbuf, 0, sizeof(recvbuf));
            int  ret = read(sock, recvbuf, sizeof(recvbuf));
            if(ret == -1)
            {
                perror("read");
            }
            else if(ret == 0)
            {
                printf("peer close\n");
                break;
            }
            fputs(recvbuf, stdout);
            memset(recvbuf, 0, strlen(recvbuf));
        }
        //当父进程结束的时候，向子进程发送信号，去退出子进程
        cout << "child close" << endl;
        kill(getppid(), SIGUSR1);
        close(sock);
        exit(0); 
    }
    else
    {
        signal(SIGUSR1, handler);
        while(fgets(sendbuf, sizeof(sendbuf), stdin) != NULL)
        {
            write(sock, sendbuf, strlen(sendbuf));
            memset(sendbuf, 0, strlen(sendbuf));
        }
        cout << "这里永远不会执行" << endl;
        exit(0);
    }


    return 0;
}
