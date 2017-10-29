/*************************************************************************
  > File Name: htonl.cpp
  > Created Time: Wed 25 Oct 2017 10:43:11 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <arpa/inet.h>
#include <stdio.h>
int main()
{
    int x = 0x12345678;
    int y = htonl(x);
    unsigned char* a =(unsigned char*) &y;//网络字节序是大端模式
    printf("%0x\n" ,a[0]);
    return 0;
}
