/*************************************************************************
	> File Name: fork3.cpp
	> Created Time: Fri 06 Oct 2017 04:00:47 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <stdio.h>
#include <unistd.h>

int main()
{
    int pid;
    int k;
    const char * msg;
    pid = fork();
    switch(pid)
    {
        case 0:
            msg = "Child running.";
            k = 3;
            break;
        case -1:
            msg = "fork error.";
            break;
        default:
            msg = "Parent running.";
            k = 5;
            break;
    }

    while(k > 0)
    {
        puts(msg);
        sleep(1);
        k--;
    }
    return 0;
}
