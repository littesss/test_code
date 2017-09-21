/*************************************************************************
	> File Name: ../lib/netutils.cpp
	> Created Time: Wed 30 Aug 2017 15:27:14 PDT
 ************************************************************************/
#include <string>
#include <iostream>
using namespace std;

#include <sys/ioctl.h>
#include <net/if.h>
#include <sys/types.h>      
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/in.h> // ifreq 结构体
#include <arpa/inet.h>

#include <stdio.h>
#include <string.h>

#include "netutils.h"

int netutils::getnicbrdaddr(string& ifname, string& brdaddr)
{
    ifreq req;//结构体ifreq
    strcpy(req.ifr_name, ifname.c_str());

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd == -1)
    {
        perror("socket :");
    } 

    //ioctl(fd, request, 放到req里面去)
    int ret = ioctl(sockfd, SIOCGIFBRDADDR, &req);
    if(ret)
    {
        return ret; // 失败直接返回
    }
    //先取req.ifr_broadaddr 结构体地址  强转成sockaddr_in类型    
    sockaddr_in baddr =  * ((sockaddr_in *) (&req.ifr_broadaddr));
    //化成点分IP地址inet_ntoa()
    char* broadcast = inet_ntoa(baddr.sin_addr);
    brdaddr= broadcast;

    return 0;
}

