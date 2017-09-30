/*************************************************************************
  > File Name: pipe.cpp
  > Created Time: Fri 29 Sep 2017 10:56:19 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include<stdio.h>
#include<unistd.h>

int main()
{
    int fd[2];  // 两个文件描述符
    pid_t pid;
    char buff[20];

    if(pipe(fd) < 0)  // 创建管道
        printf("Create Pipe Error!\n");

    if((pid = fork()) < 0)  // 创建子进程
        printf("Fork Error!\n");
    else if(pid > 0)  // 父进程
    {
        close(fd[0]); // 关闭读端
        write(fd[1], "hello world\n", 12);
        cout << "pid > 0" << endl; 

    }
    else
    {
        close(fd[1]); // 关闭写端
        cout << "pid  == 0"  << endl;
        read(fd[0], buff, 20);
        printf("%s", buff);

    }

    return 0;

}
