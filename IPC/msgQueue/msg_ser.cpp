/*************************************************************************
  > File Name: msg_ser.cpp
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

#define MAX_BUFF 512
struct mymsgbuf 
{
    long mtype;       /* message type, must be > 0 */
    char mtext[MAX_BUFF];    /* message data */
};

int main()
{
     mymsgbuf sndbuf;
    int msgid = msgget((key_t)4321,IPC_CREAT);
    if(msgid == -1)
    {
        perror("msgget");
        exit(1);
    }
    int running = 1;
    sndbuf.mtype = 1; // mtype must be > 0
    char buff[BUFSIZ];

    while(running)
    {
        cout << "Enter your msg:";
        fgets(buff, BUFSIZ, stdin);
        strcpy(sndbuf.mtext, buff);

        //send msg
        int ret =  msgsnd(msgid, (void*)&sndbuf, MAX_BUFF, 0); //send message
        if(ret == -1)
        {
            perror("msgsnd");
            exit(1);
        }

        //cout << "sndbuf.mtext:" << sndbuf.mtext;
        //cout << "sndbuf.mtype:" << sndbuf.mtype << endl;
        ret = strncmp(buff, "end", 3);
        if(!ret)
        {
            running = 0;
        }

    }
    return 0;
}

