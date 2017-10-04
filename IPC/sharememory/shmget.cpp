/*************************************************************************
  > File Name: shmget.cpp
  > Created Time: Wed 04 Oct 2017 02:28:25 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/wait.h>

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <stdlib.h>
#include <string.h>
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout << "argc < 2, error" << endl;
        exit(1);
    }
    int shmid = shmget(IPC_PRIVATE, 1024, 0666);
    if(shmid == 1) 
    {
        cout << "share memory get failed." << endl;
        exit(1);
    }

    char * s_addr;
    char * c_addr;
    pid_t pid = fork();
    if(pid)
    {
        cout << "this is parent process." << endl;
        s_addr = (char*)shmat(shmid, 0, 0);
        if(s_addr == (char*) -1);
        {
            cout << "shmat set failed." << endl;
            exit(1);
        }
        
        memset(s_addr, '\0', 1024);
        strcpy(s_addr, argv[1]);
        wait(NULL);
        exit(0);

    }
    
    if(pid == 0)
    {
//        sleep(1);
        cout << "this is child process." << endl;
        c_addr = (char*)shmat(shmid, 0, 0);
        cout << "share memory message:" << c_addr << endl;
        exit(0);

    }

    return 0;
}
