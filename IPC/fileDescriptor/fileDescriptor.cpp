/*************************************************************************
  > File Name: fileDescriptor.cpp
  > Created Time: Sat 30 Sep 2017 04:44:19 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <stdio.h>
#include <string.h>

int main()
{
   
    int fd = open("./fd.md",O_RDWR| O_CREAT, 0666);//O_EXCL|
    if(fd < 0)
    {
        cout << "open file failed!" << endl;
        perror("open");
        return 1;
    }
    cout << "fd.md fd :" << fd << endl;// 3
    fd = open("1.md",O_CREAT|O_RDWR,0666);
    cout << "1.md fd :" << fd << endl; //4

    fd = open("2.md",O_CREAT|O_RDWR,0666);//5
    cout << "2.md fd :" << fd << endl;


    fd = open("3.md",0666);   // -1  第二个参数是flags
    cout << "3.md fd :" << fd << endl;
   
    cout << "==================" << endl; 
    fd = creat("4.md", 0666);//6
    cout << "4.md fd :" << fd << endl;
    fd = open("4.md",O_RDWR);//7
    cout << "4.md fd :" << fd << endl;

    const char * str = "hello linux!!";
    int nbyte = write(fd, str, strlen(str));
    cout << "write return :" <<nbyte << endl;
    close(fd);
    
    fd = open("4.md",O_RDWR);//7
    char buff[256];
    memset(buff, 0 ,256);
    cout << "4.md fd :" << fd << endl;
    nbyte = read(fd, buff, 13);

    cout << "read buff :" << buff << endl;
    cout << "read return :" << nbyte << endl;
   
    
    cout << "==================" << endl; 
    fd = open("5.md",O_RDWR | O_CREAT, 0666);//8
    cout << "5.md fd :" << fd << endl;
    
    return 0;
}
