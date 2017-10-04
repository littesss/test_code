/*************************************************************************
  > File Name: process.cpp
  > Created Time: Tue 03 Oct 2017 10:35:38 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <sys/types.h>
#include <unistd.h>

int main()
{
    pid_t pid = getpid();
    pid_t ppid = getppid();
    pid_t uid = getuid();
    pid_t euid = geteuid();

    cout << "pid = " << pid << endl;
    cout << "ppid = " << ppid << endl;
    cout << "uid = " << uid << endl;
    cout << "euid = " << euid << endl;
    while(1);
    return 0;
} 
