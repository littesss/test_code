/*************************************************************************
  > File Name: shm_send.cpp
  > Created Time: Wed 04 Oct 2017 03:03:22 PM CST
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

    char *s_addr = (char*)shmat(shmid, 0, 0);
    memset(s_addr, 0 ,1024);

    int running = 1;
    while(running)
    {
        char buff [1024];
        fgets(buff, 1024, stdin);//从标准输入流里面读数据
        cout << "buff" << buff << endl;
        if(strncmp(buff,"end",3) == 0)
        {
            cout << "here" << endl;
            running = 0;
        }

        strcpy(s_addr, buff);

    }

}
