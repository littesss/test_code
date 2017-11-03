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

ssize_t readn(int fd, void* buf, size_t count)
{
    size_t nleft = count;
    ssize_t nread;
    char* bufp = (char*)buf;

    while(nleft > 0)
    {
        if((nread = read(fd, bufp, nleft))<0)
        {
            if(errno == EINTR)
                continue;
            return -1;
        }
        else if(nread == 0)
        {
            return count-nleft;
        }
        bufp += nread;
        nleft -= nread;
    }
    return count;
}
ssize_t writen(int fd, const void* buf, size_t count)
{
    size_t nleft = count;
    ssize_t nwritten;
    char* bufp = (char*)buf;

    while(nleft > 0)
    {
        if((nwritten = write(fd, bufp, nleft)) < 0)
        {
            if(errno == EINTR)
                continue;
            return -1;
        }
        else if(nwritten == 0)
        {
            return count-nleft;
        }
        bufp += nwritten;
        nleft -= nwritten;
    }
    return count;
}
/////////////////////////////////////

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
    while(fgets(sendbuf, sizeof(sendbuf), stdin) != NULL)
    {
        writen(sock, sendbuf, strlen(sendbuf));
        readn(sock, recvbuf, sizeof(recvbuf));
        fputs(recvbuf,stdout);
        memset(recvbuf, 0, sizeof(recvbuf));
    }
    
    close(sock);
    
    return 0;
}
