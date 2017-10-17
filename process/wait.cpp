/*************************************************************************
  > File Name: wait.cpp
  > Created Time: Tue 17 Oct 2017 12:45:16 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    int value = 0;
    int pid = fork();
    if(pid > 0)
    {
        sleep(2);
        pid = wait(&value);
        cout << "wait() = " << pid << endl;
    }
    else if(pid == 0)
    {
        cout << "i am child ,exit(3)" << endl;
        cout << "child pid :" << getpid() << endl;
        exit(3);
    }
    cout << "value = " << value << endl;
    value >>= 8 ;
    cout << "value = " << value << endl;
    return 0;
}
