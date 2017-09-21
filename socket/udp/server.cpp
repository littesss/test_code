/*************************************************************************
	> File Name: a.cpp
	> Created Time: Sun 17 Sep 2017 04:34:24 AM PDT
 ************************************************************************/
#include <iostream>
using namespace std;

#include <unistd.h>
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 9999
#define Seraddr "192.168.0.72"

int main(int argc, char ** argv)
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd == -1)
    {
        perror("socket");
        exit(1);
    }
    struct sockaddr_in addrSer, addrPeer;//
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(PORT);
    addrSer.sin_addr.s_addr = inet_addr(Seraddr);

    socklen_t len = sizeof(struct sockaddr_in);
    int ret = bind(sockfd, (struct sockaddr*)&addrSer, len);//服务端必须填充自己的sockaddr_in,以便对客户端来用
    if(ret == -1)
    {
        perror("bind");
        exit(1);
    }

    char recvbuff[1024];
    char sendbuff[1024];
    struct in_addr addr;
    while(1)
    {
        recvfrom(sockfd, recvbuff, 1024, 0, (struct sockaddr*)&addrPeer, &len);
        addr.s_addr = addrPeer.sin_addr.s_addr; //获取对端地址,前提对端必须绑定地址
        cout << "Cli.addr:" << inet_ntoa(addr) << endl;
        //cout << addr.s_addr << endl;  网络地址
        cout << "Cli:>" << recvbuff << endl;

        cout << "Ser:>";
        cin >> sendbuff;
        sendto(sockfd, sendbuff, 1024, 0, (struct sockaddr*)&addrPeer, len);
    }


    return 0;
}
