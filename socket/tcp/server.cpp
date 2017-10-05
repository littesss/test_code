/*************************************************************************
  > File Name: cli.cpp
  > Created Time: Wed 04 Oct 2017 09:13:53 PM CST
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
    
    //bind
    //int bind(int sockfd, const struct sockaddr *addr,
    //                socklen_t addrlen);
    sockaddr_in addr_ser, addr_cli;
    addr_ser.sin_family = AF_INET;
    addr_ser.sin_port = htons(8888);

    addr_ser.sin_addr.s_addr = htonl(INADDR_ANY);
    int len = sizeof(addr_ser);

    int ret = bind(fd, (struct sockaddr*)&addr_ser, len);
    if(ret == -1)
    {
        perror("bind");
        close(fd);
        exit(1);
    }
cout << "listen before " << endl;
    //listen
    // int listen(int sockfd, int backlog);
    ret = listen(fd, MAX_QUEUE_SIZE);
    if(fd == -1)
    {
        perror("listen");
        exit(1);
    }
cout << "listen after " << endl; 
    cout  << "before accept fd = " << fd << endl;
    //accept
    //int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    socklen_t lencli = sizeof(addr_cli);
    int fd1= accept(fd, (struct sockaddr*) &addr_cli, &lencli);
    if(ret == -1)
    {
        perror("accept");
        exit(1);
    }

    cout << "addr_cli.sin_port :" << ntohs(addr_cli.sin_port) << endl;
    struct in_addr addr;
    addr.s_addr = addr_cli.sin_addr.s_addr;
    cout << "addr_cli.sin_addr.s_addr(inet_ntoa):" << inet_ntoa(addr) << endl;

    cout << "fd1 = accept() = " << fd1 << endl;
    int running = 1;
    char recvbuf[1024];
    char sendbuf[1024];
    while(running)
    {
        cout << "Cli:>" << endl; // 下面有阻塞函数必须endl;换行
        //ssize_t read(int fd, void *buf, size_t count);
        //int nbyte = recv(fd1, recvbuf, 1024, 0);
        int nbyte = read(fd1, recvbuf, 1024);
        if(nbyte < 0)
        {
            perror("recv");
            exit(1);
        }
        cout << recvbuf << endl;
        cout << "Ser:>";
        cin >> sendbuf;
        if(!(strncmp(sendbuf, "quit", 4)))
        {
            running = 0;
        }    
        else
        {
            //nbyte = send(fd1, sendbuf, 1024, 0);
            nbyte = write(fd1, sendbuf, 1024);
        }
    }

    close(fd);
    return 0;
}
