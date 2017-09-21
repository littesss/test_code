/*************************************************************************
	> File Name: main.cpp
	> Created Time: Mon 21 Aug 2017 03:14:57 PDT
 ************************************************************************/
#include <string>
#include <iostream>
using namespace std;

#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <arpa/inet.h>

#include "netutils.h"

#define SERVER_IP  "127.0.0.1"
#define SERVER_PORT 9999

#define LISTEN_QUEUE_SIZE 5
#define MAX_BUFFER_SIZE   255

//柔性数组，存放变长command
struct Message
{
    int cmd;
    char tag[0];
};

int main(int argc,char *argv[])
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
                exit(EXIT_FAILURE);
        }
    }
    cout << "cmd :" << cmd << endl;
    
    //柔性数组把数据打包好使用UDP发到对端
    int bufflen = sizeof(Message) + machines.length();
    char * pbuff = (char *)malloc(bufflen+1);

    memset(pbuff, 0, bufflen);
    pbuff[bufflen] = '\0';

    Message * pmsg = (Message*) pbuff;
    pmsg->cmd = cmd;
    memcpy(pmsg->tag, machines.c_str(),machines.length());
    
    cout << "==============Message============" << endl;
    cout << "buffer cmd :" << pmsg->cmd << endl;
    cout << "buffer machines:" << pmsg->tag << endl;

    //UDP  创建客户端套接字
    int sockCli = socket(AF_INET, SOCK_DGRAM, 0);
    if(sockCli == -1)
    {
        perror("socket");
    }

    //获取广播地址
    string ifname("ens33");
    string brdaddr;
    netutils::getnicbrdaddr(ifname, brdaddr);
 
    //填充套接字sockaddr_in 用广播地址
    struct sockaddr_in addrSer;
    addrSer.sin_family = AF_INET;
    addrSer.sin_port = htons(SERVER_PORT);
    addrSer.sin_addr.s_addr = inet_addr(brdaddr.c_str());
    
    cout << "broadcast :" << brdaddr << endl;
    socklen_t len = sizeof(struct sockaddr);
    
    //setsockopt(),设置套接字选项，允许UDP向广播地址发数据
    int broadcast = 1;//指向包含新选项值的缓冲 0被禁止，非零启动
    int retval = setsockopt(sockCli, SOL_SOCKET, SO_BROADCAST ,
            &broadcast, sizeof(broadcast));//optlen 现选项的长度
    if(retval)
    {
        perror("setsockopt");
    }

    //sendto() 向服务器发送数据
    int ret =  sendto(sockCli, pbuff, bufflen + 1, 0, (struct sockaddr*)&addrSer, len);
    if (ret < 0) //失败返回负数
    {
        perror("sendto");
    }

    close(sockCli);



    exit(EXIT_SUCCESS);
    return 0;
}
