/*************************************************************************
  > File Name: cli.c
  > Created Time: Mon 06 Nov 2017 11:25:38 PM CST
 ************************************************************************/
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<stdio.h>
#include<errno.h>
#include<string.h>
#define ERR_EXIT(m) do{perror(m);exit(EXIT_FAILURE);}while(1)
struct packet
{
    int len;
    char buf[1024];

};
ssize_t readn(int fd, void *buf, size_t count)
{
    size_t nleft = count;
    ssize_t nread;
    char *bufp = (char*)buf;
    while (nleft > 0)
    {
        if ((nread = read(fd, bufp, nleft)) < 0)
        {
            if (errno == EINTR)
            {
                continue;
                return -1;

            }
            else if (nread == 0)return count - nleft;

        }
        bufp = bufp + nread;
        nleft = nleft - nread;

    }
    return count;

}
ssize_t writen(int fd, void *buf, size_t count)
{
    size_t nleft = count;
    ssize_t nwrite;
    char *bufp = (char*)buf;
    while (nleft > 0)
    {
        if ((nwrite = write(fd, bufp, nleft)) < 0)
        {
            if (errno == EINTR)
            {
                continue;
                return -1;

            }
            else if (nwrite == 0)continue;

        }
        bufp = bufp + nwrite;
        nleft = nleft - nwrite;

    }
    return count;

}
ssize_t recv_peek(int sockfd, void *buf, size_t len)
{
    while (1)
    {
        int ret = recv(sockfd, buf, len, MSG_PEEK);
        if (ret == -1 && errno == EINTR)continue;
        return ret;

    }

}
ssize_t readline(int sockfd, void *buf, size_t maxline)
{
    int ret;
    int nread;
    char *bufp = (char*)buf;
    int nleft = maxline;
    while (1)
    {
        ret = recv_peek(sockfd, bufp, nleft);
        if (ret < 0)return ret;
        else if (ret == 0)return ret;//对方关闭了套接口
        nread = ret;
        for (int i = 0; i < nread; i++)
        {
            if (bufp[i] == '\n')
            {
                ret = readn(sockfd, bufp, i + 1);//将缓冲区数据移除
                if (ret != i + 1)exit(EXIT_FAILURE);
                return ret;

            }

        }
        if (nread>nleft)exit(EXIT_FAILURE);//读到的数据不能超过缓冲区
        nleft -= nread;
        ret = readn(sockfd, bufp, nread);
        if (ret != nread)exit(EXIT_FAILURE);
        bufp += nread;

    }
    return -1;

}

int main(void)
{
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)ERR_EXIT("socket");
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5188);
    servaddr.sin_addr.s_addr = inet_addr("127.0.1");
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)ERR_EXIT("bind");

    //获取本地端口
    struct sockaddr_in localaddr;
    socklen_t addrlen = sizeof(localaddr);
    if(getsockname(sockfd, (struct sockaddr*)&localaddr, &addrlen) < 0)
    {
        exit(-1);
    }
    printf("ip=%s port=%d\n", inet_ntoa(localaddr.sin_addr), ntohs(localaddr.sin_port));


    char sendbuf[1024];
    char recvbuf[1024];
    memset(sendbuf, 0, sizeof(sendbuf));
    memset(recvbuf, 0, sizeof(recvbuf));
    while (fgets(sendbuf, sizeof(sendbuf), stdin) != NULL)
    {
        writen(sockfd, sendbuf, strlen(sendbuf));
        int ret = readline(sockfd, recvbuf, sizeof(recvbuf));
        if (ret == -1)ERR_EXIT("read");
        if (ret == 0)
        {
            printf("server close\n");
            break;

        }
        fputs(recvbuf, stdout);
        memset(sendbuf, 0, sizeof(sendbuf));
        memset(recvbuf, 0, sizeof(recvbuf));

    }
    close(sockfd);

}

