/*************************************************************************
	> File Name: orphan.cpp
	> Created Time: Fri 06 Oct 2017 04:11:23 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    pid_t pid;
    pid = fork();
    switch(pid)
    {
        case 0:
            //sleep(1);
            while(1)
            {
                printf("Child pid:%d\n,PPID:%d\n",getpid(), getppid());
                //cout << "Chlid PID:" << getpid() << " , PPID:" << getppid() << endl;
                sleep(3);
            }
        case -1 :
            exit(-1);
        default:  
            printf("Parent pid:%d\n,PPID:%d\n",getpid(), getppid());
            //cout << "Parent PID:" << getpid() << " , PPID:" << getppid() << endl;
            exit(0);
    }
    return 0;
}
