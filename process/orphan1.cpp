/*************************************************************************
  > File Name: orphan1.cpp
  > Created Time: Tue 17 Oct 2017 12:03:35 PM CST
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
//ubuntu使用upstart程序来代替init，我电脑上upstart的pid就是2283，最后子进程就由upstart接管，所以起父进程pid就一直是2283
    if(pid == 0)
    {
        sleep(2);
        cout << "child process:my pid:" << getpid()<<endl;
        cout << "chile proces: my ppid:" << getppid() << endl;
        exit(0);
    }
    else if(pid > 0)
    {
        cout << "parent process,i will exit" << endl;
        exit(0);
    }
    //wait(NULL);
    return 0;
}
