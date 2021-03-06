/*************************************************************************
	> File Name: main.cpp
	> Created Time: Mon 21 Aug 2017 03:14:57 PDT
 ************************************************************************/
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <sys/types.h>
#include <arpa/inet.h>

#include "netutils.h"


int main(int argc,char *argv[])
{   //含有goto语句的不能在goto语句中定义变量
    int sendtoret; 
    int bufflen;
    int sockfd ;
    char * msg;
    Message *pmsg;

    msg = netutils::buildmsg(argc, argv, bufflen);
    if(!msg)
    {
        cerr << "can not build message" << endl;
        goto ERROR;
    }
    pmsg = (Message *)msg;
    cout << "==============Message============" << endl;
    cout << "buffer cmd :" << pmsg->cmd << endl;
    cout << "buffer machines:" << pmsg->tag << endl;

    //init socket fd send data
    sockfd = netutils::initsocket();
    
    //init dest for sockfd
    struct sockaddr_in dest;
    netutils::initdest(dest);
    
    //sendto() 向服务器发送数据
    sendtoret =  sendto(sockfd, msg, bufflen+1, 0,
            (struct sockaddr*)&dest, sizeof(sockaddr_in));
    if (sendtoret < 0) //失败返回负数
    {
        perror("sendto");
        goto ERROR;
    }

    //close fd and exit
    close(sockfd);
    free(msg);
    msg = NULL;
    exit(EXIT_SUCCESS);

ERROR:
    close(sockfd);
    free(msg);
    msg = NULL;
    exit(1);

    return 0;
}
