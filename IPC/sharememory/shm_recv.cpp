/*************************************************************************
  > File Name: shm_write.cpp
  > Created Time: Wed 04 Oct 2017 03:03:39 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/wait.h>

#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int shmid = shmget((key_t)1234, 1024, 0666|IPC_CREAT);

    char *r_addr = (char*)shmat(shmid, 0, 0);

    cout << "r_addr share memory : " << r_addr << endl;
    return 0;
}
