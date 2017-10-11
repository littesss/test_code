/*************************************************************************
  > File Name: fork.cpp
  > Created Time: Fri 06 Oct 2017 11:40:38 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <unistd.h>
#include <stdio.h> 
int main () 
{ 
    pid_t fpid; //fpid表示fork函数返回的值
    int count=0;
    fpid=fork(); 
    if (fpid < 0) 
        printf("error in fork!"); 
    else if (fpid == 0)
    {
        printf("i am the child process, my process id is %d\n",getpid()); 
        printf("我是爹的儿子\n");//对某些人来说中文看着更直白。
        count++;

    }
    else
    {
        printf("i am the parent process, my process id is %d\n",getpid()); 
        printf("我是孩子他爹\n");
        count++;

    }
    printf("统计结果是: %d\n",count);
    return 0;
}