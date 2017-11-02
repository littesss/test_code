/*************************************************************************
  > File Name: t.cpp
  > Created Time: Thu 02 Nov 2017 12:45:22 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <stdio.h>
#include<unistd.h> 
pid_t f1,s1,s2;
int main()
{
    f1=getpid();//父
    s1=fork();//子1
//    s2=fork();//子2
    printf("%d,%d\n",f1,s1);
    return 0;

}
