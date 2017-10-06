/*************************************************************************
	> File Name: fork1.cpp
	> Created Time: Fri 06 Oct 2017 11:47:17 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int count = 0;
    pid_t pid = fork();
    int status = 0;
    if(pid)
    {
        //sleep(1);
        cout << "i am parent,my PID is:" << getpid() << endl;
        cout << "++count:" << ++count << endl;
    }
    else if(!pid)
    {
        cout << "i am child,my PID is:" << getpid() << endl;
        cout << "++count:" << ++count << endl;
    }
    int ret = wait(&status);
    cout << "ret = wait() = " << ret << endl;
    return 0;
}
