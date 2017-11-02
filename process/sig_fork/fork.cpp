/*************************************************************************
> File Name: fork.cpp
> Author: Littesss 
> Mail: liushaohua_2017@163.com 
> Created Time: 2017-11-01T19:52:18 PDT
************************************************************************/

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

#include<iostream>
using namespace std;

#include <stdlib.h>
#include <unistd.h>

void sig_handler(int sig)
{
    cout << "catch a signal is :" << sig << endl;
   // exit(0);
}

int main()
{
    int status = 0;
    pid_t pid;
    pid = fork();
    //子进程
    if(pid == 0)
    {
        signal(SIGUSR1, sig_handler);
        int i = 0;
        while(i != 3)
        {
            sleep(1);
            cout << "child:" << i++ << endl;
        }
        
    }
    //父进程
    else if(pid > 0)
    {
        int i = 0;
        while(i != 3)
        {
            sleep(1);
            cout << "parent:" << i++ << endl;
        }
        
        kill(pid, SIGUSR1);
      
    }
    wait(&status);
    cout << "end" << endl; 
    return 0;
}
