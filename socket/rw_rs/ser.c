/*************************************************************************
  > File Name: ser.c
  > Created Time: Mon 06 Nov 2017 11:24:30 PM CST
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
void do_service(int connfd)
{
    char recvbuf[1024];
    int n;
    while (1)
    {
        memset(&recvbuf, 0, sizeof(recvbuf));
        int ret = readline(connfd, recvbuf, 1204);
        if (ret == -1)
        {
            ERR_EXIT("read");

        }
        else if (ret ==0 )
        {
            printf("client close\n");
            break;

        }
        fputs(recvbuf, stdout);
        writen(connfd, recvbuf, strlen(recvbuf));

    }

}
int main(void)
{
    int listenfd;
    if ((listenfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)ERR_EXIT("socket");
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5188);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    int on = 1;
    if (setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0)ERR_EXIT("setsockopt");
    if (bind(listenfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)ERR_EXIT("bind");
    if (listen(listenfd, SOMAXCONN) < 0)ERR_EXIT("listten");
    while (1)
    {
        int connfd;
        struct sockaddr_in peeraddr;
        socklen_t peerlen = sizeof(peeraddr);
        if ((connfd = accept(listenfd, (struct sockaddr*)&peeraddr, &peerlen)) < 0)ERR_EXIT("accept");
        printf("ip=%s port=%d\n", inet_ntoa(peeraddr.sin_addr), ntohs(peeraddr.sin_port));
        pid_t pid = fork();
        if (pid == -1)ERR_EXIT("fork");
        if (pid == 0)
        {
            close(listenfd);
            do_service(connfd);
            exit(EXIT_SUCCESS);

        }
        if (pid > 0)
        {
            close(connfd);

        }

    }
    close(listenfd);

}

