/*************************************************************************
  > File Name: fifo_wr.cpp
  > Created Time: Sat 30 Sep 2017 11:41:01 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h>

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

#include <unistd.h>

#define MAX_BUFF_SIZE 512
int main()
{
    int ret;
    ret = mkfifo("./myfifo", 0666);
    if(ret < 0)
    {
        if(errno == EEXIST)
        {
            cout << "pathname already exist" << endl;
        }
        else
        {
            cout << "fifo create failed!!!" << endl;
            exit(1);
        }
    }
    else
    {
        cout << "fifo create by this process." << endl;
    }
    int fd = open("myfifo", O_WRONLY); 
    if(fd == -1) 
    {
        perror("open");
        exit(1);
    }

    cout << "Please enter something:" << endl;
    char buff[MAX_BUFF_SIZE];
    int nbyte;
    while((nbyte = read(0, buff, MAX_BUFF_SIZE)))
    {
        write(fd, buff, nbyte);
        cout << "please enter something:" << endl;
    }

    close(fd);
    return 0;
}
