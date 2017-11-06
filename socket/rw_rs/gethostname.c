/*************************************************************************
  > File Name: gethostname.c
  > Created Time: Mon 06 Nov 2017 11:41:47 PM CST
 ************************************************************************/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int getlocalip(char* ip)
{ 
    char host[100] = {0};
    if(gethostname(host,sizeof(host)) <0)
    {
        return -1;
    }

    struct  hostent * hp;
    if((hp = gethostbyname(host)) == NULL)
        return -1;

    strcpy(ip, inet_ntoa(*(struct in_addr*)hp->h_addr));
}

int main()
{
    char host[100] = "lens333";
    if(gethostname(host,sizeof(host)) <0)
    {
        return -1;
    }

    struct  hostent * hp;
    if((hp = gethostbyname(host)) == NULL)
        return -1;

    int i = 0;
    while (hp->h_addr_list[i] != NULL)
    {
        printf("%s\n", inet_ntoa(*(struct in_addr*)hp->h_addr_list[i]));
        i++;
    }

    printf("=======getlocalIp===========\n");
    char ip[16] = {0};
    getlocalip(ip);
    printf("localIp = %s\n", ip);
    return 0;

    return 0;
}
