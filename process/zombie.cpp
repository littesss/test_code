/*************************************************************************
	> File Name: zombie.cpp
	> Created Time: Tue 17 Oct 2017 11:22:24 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <sys/types.h>
       #include <sys/wait.h>

#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pid;
    pid = fork();
    if(pid == 0)
        exit(0);

    else if(pid > 0)
    {
        sleep(60);//挂起父进程的时候，还没等到给子进程收尸，子进程已经退出了
    }

    wait(NULL);
    return 0;
}
