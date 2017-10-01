/*************************************************************************
  > File Name: test.cpp
  > Created Time: Fri 29 Sep 2017 11:47:03 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char * argv[])
{
    int flags, opt;
    int nsecs, tfnd;

    nsecs = 0;
    tfnd = 0;
    flags = 0;

    char buff[512];
    int fd;
    int number;
    
    while ((opt = getopt(argc, argv, "d:s:")) != -1)
    {
        switch (opt) 
        {
            case 'd'://dest file write;
                fd = creat("./test1.txt",O_RDWR);
                fd = open("./test1.txt",O_RDWR);
                write(fd, buff, strlen(buff+1));

                close(fd);
                flags = 1;
                break;
            case 's'://src file read
                fd = open("./test.txt",O_RDWR);

                lseek(fd, 1, SEEK_SET);
                number = read(fd, buff, 512);//vim 会自动在结尾处＋'\n'换行符，
                buff[number-1] = '\0';
                close(fd);
                break;

            default: /* '?' */
                fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
                        argv[0]);
                exit(EXIT_FAILURE);
        }
    }
//   cout << "buff:" << buff << endl;
   return 0;
}
/*
#define LENGTH 100
int main()
{
    int fd, len;
    char str[LENGTH]; 
    fd = open("hello.txt", O_CREAT | O_RDWR); 
    if (fd) 
    {
        write(fd, "Hello, Software Weekly", strlen("Hello, software weekly")); 
        close(fd);
    }
    fd = open("hello.txt", O_RDWR);
    len = read(fd, str, LENGTH); 
    str[len] = '\0';
    printf("%s\n", str);
    close(fd);
    return 0;
}*/
