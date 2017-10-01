/*************************************************************************
  > File Name: msg_cli.cpp
  > Created Time: Sun 01 Oct 2017 06:06:33 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct mymsgbuf 
{
    long mtype;       /* message type, must be > 0 */
    char mtext[BUFSIZ];    /* message data */
};

int main()
{
    //cout << "BUFSIZ:" << BUFSIZ << endl; 8K
    mymsgbuf rcvbuf;
    int msgid = msgget((key_t)4321,  IPC_CREAT);
    if(msgid == -1)
    {
        perror("msgget");
        exit(1);
    }
    int running = 1;
    rcvbuf.mtype = 1;
    char buff[1024];
    while(running)
    {
        cout << "receive msg:"<< endl;

        //receive msg
        int ret =  msgrcv(msgid, (void*)&rcvbuf, BUFSIZ, 0,  0); //receive message
        if(ret == -1)
        {
            perror("msgrcv");
            exit(1);
        }
        cout << rcvbuf.mtext; 

        ret = strncmp(rcvbuf.mtext, "end", 3);
        if(!ret)
        {
            running = 0;
        }

    }

    int ret = msgctl(msgid, IPC_RMID, 0);//从内核移走消息队列

    cout << "here" << endl;
    if(ret == -1)
    {
        perror("msgctl");
        exit(1);
    }

    return 0;
}

