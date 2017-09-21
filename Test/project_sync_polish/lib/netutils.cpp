/*************************************************************************
	> File Name: ../lib/netutils.cpp
	> Created Time: Wed 30 Aug 2017 15:27:14 PDT
 ************************************************************************/
#include <string>
#include <iostream>
using namespace std;

#include <unistd.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <sys/types.h>      
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netinet/in.h> // ifreq 结构体
#include <arpa/inet.h>


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "netutils.h"
#define SERVER_PORT 9999

char*  netutils::buildmsg(int argc, char** argv, int& bufflen)
{
   string machines;
    int opt;
    int cmd = 0;
    int setbit = 1;
    //getopt() 解析命令行
    while((opt = getopt(argc, argv, "fupm:")) != -1)
    {
        //cout << opt <<endl;  返回值是int类型
        switch(opt)
        {
            case 'f':
                cout << "f is set" << endl;
                setbit = 1;
                cmd = cmd | setbit; // f被设置 cmd 末位置1

                break;
            case 'u':
                cout << "u is set" << endl;
                setbit = 1;
                cmd = cmd | setbit<<1;

                break;
            case 'p':
                cout << "p is set" << endl;
                setbit = 1;
                cmd = cmd | setbit<<2;
                break;
            case 'm':
                machines = optarg;
                // cout << machines << endl;
                break;
            default: /* '?' */
                cout << "Error!!!" << endl;
                return NULL;
        }
    }
    cout << "cmd :" << cmd << endl;
    
    //柔性数组把数据打包好使用UDP发到对端
    bufflen = sizeof(Message) + machines.length();
    char * pbuff = (char *)malloc(bufflen+1); //柔性数组最后一位是char tag[0],所以开辟char *
    if(pbuff == NULL)
    {
        cerr << "cannot alloc memory" << endl;
        return NULL;
    }
    memset(pbuff, 0, bufflen);
    pbuff[bufflen] = '\0';

    Message * pmsg = (Message*) pbuff;
    pmsg->cmd = cmd;
    memcpy(pmsg->tag, machines.c_str(),machines.length());

    return pbuff;
}

void netutils::initdest(sockaddr_in & dest)
{
    //获取广播地址
    string ifname("ens33");
    string brdaddr;
    netutils::getnicbrdaddr(ifname, brdaddr);
    cout << "broadcast :" << brdaddr << endl;
    
    //填充套接字sockaddr_in 用广播地址
    dest.sin_family = AF_INET;
    dest.sin_port = htons(SERVER_PORT);
    netutils::getnicbrdaddr(ifname,brdaddr);
    dest.sin_addr.s_addr = inet_addr(brdaddr.c_str());
}

int netutils::initsocket()
{
    //UDP  创建客户端套接字
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockfd == -1)
    {
        perror("socket");
    }
    
    //setsockopt(),设置套接字选项，允许UDP向广播地址发数据
    int broadcast = 1;//指向包含新选项值的缓冲 0被禁止，非零启动
    int retval = setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST ,
            &broadcast, sizeof(broadcast));//optlen 现选项的长度
    if(retval)
    {
        perror("setsockopt");
    }
    
    return sockfd;

}

int netutils::getnicbrdaddr(string& ifname, string& brdaddr)
{
    ifreq req;//结构体ifreq  在<net/if.h>中
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

