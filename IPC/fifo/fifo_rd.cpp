/*************************************************************************
	> File Name: fifo_rd.cpp
	> Created Time: Sat 30 Sep 2017 12:08:43 PM CST
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

//#define  MAX_BUFF_SIZE  512
#define  MAX_BUFF_SIZE 512
int main()// read 
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
    int fd = open("myfifo", O_RDONLY); // open 也是一个阻塞函数,只读打开的话必须先write东西
    if(fd == -1) 
    {
        perror("open");
        exit(1);
    }
    char buff[MAX_BUFF_SIZE];
    int nbyte;
    while((read(fd, buff ,MAX_BUFF_SIZE)))
    {
        cout << "Msg from myfifo :" << buff;       
    }
}
