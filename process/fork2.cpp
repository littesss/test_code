/*************************************************************************
	> File Name: fork2.cpp
	> Created Time: Fri 06 Oct 2017 03:52:15 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid = fork();
    switch(pid)
    {
        case 0:
            cout << "Chlid process.pid is:" << getpid() << endl;
            break;
        case -1:
            cout << "Create fork failed..." << endl;
            break;
        default:
            cout << "Parent process.pid is:" << getpid() << endl;
            break;
    }
    exit(0);
    return 0;
}
