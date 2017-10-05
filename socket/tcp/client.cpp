/*************************************************************************
	> File Name: ser.cpp
	> Created Time: Wed 04 Oct 2017 09:13:43 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5

int main()
{
     //socket
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1)
    {
        perror("socket");
        exit(1);
    }

    sockaddr_in addr_ser;
    addr_ser.sin_family = AF_INET;
    addr_ser.sin_port = htons(8888);
    addr_ser.sin_addr.s_addr = inet_addr("127.0.0.1");

    //connect  int connect(int sockfd, const struct sockaddr *addr,
    //                   socklen_t addrlen);

    int ret = connect(fd, (struct sockaddr*) &addr_ser, sizeof(addr_ser));
    if(ret == -1)
    {
        perror("connect");
        exit(1);
    }

    cout << "connect ret:" << ret << endl;
    cout << "fd:" << fd << endl;

    cout << "addr_ser.sin_port:" << ntohs(addr_ser.sin_port) << endl;
    cout << "addr_ser.sin_addr.s_addr:" << addr_ser.sin_addr.s_addr << endl;

    struct in_addr addr;
    addr.s_addr = addr_ser.sin_addr.s_addr;
    cout << "addr_ser.sin_addr.s_addr(inet_ntoa):" << inet_ntoa(addr) << endl;
    cout << "connect fd = " << fd << endl;
    int running = 1;
    char recvbuf[1024];
    char sendbuf[1024];

    while(running)
    {
        cout << "Cli:>";
        cin >> sendbuf;
        //ssize_t send(int sockfd, const void *buf, size_t len, int flags);
       // int nbyte = send(fd, sendbuf, 1024, 0);
        int nbyte = write(fd, sendbuf,1024);
        if(nbyte < 0)
        {
            perror("send");
            exit(1);
        }
        if(!strncmp(sendbuf, "quit", 4))
        {
            cout << "running  = 0???" << endl;
            running = 0;
        }
        else
        {
            cout << "Ser:>";
            // ssize_t recv(int sockfd, void *buf, size_t len, int flags);
            //nbyte = recv(fd, recvbuf, 1024, 0);
            nbyte = read(fd, recvbuf, 1024);
            if(nbyte < 0)
            {
                perror("read");
                exit(1);
            }
            cout << recvbuf << endl;
        }
    }

    close(fd);
    return 0;
}
