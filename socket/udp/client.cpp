/*************************************************************************
	> File Name: c.cpp
	> Created Time: Sun 17 Sep 2017 09:05:18 AM PDT
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
#define Src "192.168.0.65"

int main()
{
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd == -1)
    {
        perror("socket");
        exit(1);
    }
    
    struct sockaddr_in addrDest;//填充addrDest,为了sendto发到服务器
    addrDest.sin_family = AF_INET;
    addrDest.sin_port = htons(PORT);
    addrDest.sin_addr.s_addr = inet_addr(Seraddr);
    
    struct sockaddr_in addrSrc;//填充addrSrc,为了绑定
    addrSrc.sin_family = AF_INET;
    addrSrc.sin_port = htons(PORT);
    addrSrc.sin_addr.s_addr = inet_addr(Src);//网络地址,指定谁连接，INADDR_ANY任何人都能连接

    socklen_t len = sizeof(struct sockaddr_in);
    int res = bind(sockfd, (struct sockaddr *) &addrSrc, len);
    if(res == -1)
    {
        perror("bind");
    } 
    /*int retval = setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST ,
            &addrSrc, sizeof(addrSrc));//optlen 现选项的长度
    if(retval)
    {
        perror("setsockopt");
    }
*/
    char sendbuf[1024];
    char recvbuf[1024];
    struct in_addr addr;
    addr.s_addr = addrSrc.sin_addr.s_addr;
    
    while(1)
    {
        cout << "addr:" << inet_ntoa(addr) << endl;
        cout << "Cli:>";
        cin >> sendbuf;
        ssize_t ret =  sendto(sockfd, sendbuf, 1024, 0,
            (const struct sockaddr*) &addrDest, len);

        recvfrom(sockfd,recvbuf, 1024, 0, (struct sockaddr*)
                &addrDest, &len);
        cout << "Ser:>" << recvbuf << endl;
    }
    close(sockfd);
    return 0;
}
