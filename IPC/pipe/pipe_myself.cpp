/*************************************************************************
	> File Name: pipe_myself.cpp
	> Created Time: Fri 29 Sep 2017 08:24:00 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


#include <stdlib.h>
#include <stdio.h>

int main()
{
    int fd[2];
    char buff_r[100];
    char buff_w[100];
    pid_t pid;

    int ret = pipe(fd);
    if(ret == -1)
    {
        perror("pipe");
        exit(1);
    }
    
    pid = fork();
    if(pid < 0)
    {
        perror("pipe");
        exit(1);
    }
    else if(pid == 0) //子进程write
    {
        close(fd[0]);
        const char * str = "i am child, i am write";
        strcpy(buff_w, str);
        write(fd[1], buff_w, strlen(str));
        cout << "Write over !!!!" << endl;
        close(fd[1]);
    }
    else //父进程  read
    {
        close(fd[1]);
//        sleep(2);
        read(fd[0], buff_r, 100);
        cout << "i am parent, i am read ,Msg from:" << buff_r<< endl;
        cout << "Read over !!!!" << endl;
        close(fd[0]);
    }

    int  status;
    waitpid(pid, &status, 0);
    return 0;
}
