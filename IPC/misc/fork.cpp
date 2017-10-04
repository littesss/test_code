/*************************************************************************
  > File Name: fork.cpp
  > Created Time: Tue 03 Oct 2017 10:59:59 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <sys/types.h>
#include <unistd.h>

int main()
{
    while(1)
    {
        pid_t pid = fork();
        if(pid == 0)
        {
            cout << "this is child process."<< endl;
            cout << "gitpid = " << getpid() << endl;
            cout << "gitppid = " << getppid() << endl;
        }

        else if(pid > 0)
        {
            cout << "this is parent process.................."<< endl;
            cout << "gitpid = " << getpid() << endl;
            cout << "gitppid = " << getppid() << endl;;
        }

        else
        {
            cout << "error fork()" << endl;
            return -1;
        }
        sleep(1);
    }
    /*cout << "gitpid :" << getppid() << endl;
      fork();
      cout << "gitpid :" << getppid() << endl;
      fork();
      cout << "gitpid :" << getppid() << endl;
      fork();
      cout << "gitpid :" << getppid() << endl;
      */
    while(1);
    return 0;
}
