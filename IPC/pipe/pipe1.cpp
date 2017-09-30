/*************************************************************************
  > File Name: pipe1.cpp
  > Created Time: Fri 29 Sep 2017 08:11:19 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    int pipe_fd[2];
    pid_t pid;
    char r_buf[10];
    char w_buf[4];
    int r_num;

    memset(r_buf,0,sizeof(r_buf));
    memset(w_buf,0,sizeof(w_buf));
    if(pipe(pipe_fd)<0)
    {
        printf("pipe create error\n");
        return -1;

    }

    if((pid=fork())==0)
    {
        printf("\n");
        close(pipe_fd[1]);
        sleep(3);//确保父进程关闭写端
        r_num=read(pipe_fd[0],r_buf,10);
        printf(    "read num is %d the data read from the pipe is %d\n",r_num,atoi(r_buf) );

        close(pipe_fd[0]);
        exit(1);

    }
    else if(pid>0)
    {
        close(pipe_fd[0]);//close read 
        strcpy(w_buf,"111");
        if(write(pipe_fd[1],w_buf,4)!=-1)
            printf("parent write over\n");
        printf("parent close fd[1] over\n");
        close(pipe_fd[1]);//write
        sleep(10);

    }
    return 0;

}
