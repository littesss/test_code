/*************************************************************************
  > File Name: lseek.cpp
  > Created Time: Sat 30 Sep 2017 07:06:40 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd = open("./4.md",O_RDWR);
    int ret = lseek(fd, 2, SEEK_SET);

    char buff[100];
    const char * str = "2222";
    write(fd, str, 4);
    close(fd);

    cout << "===============" << endl;
    fd = open("./4.md",O_RDWR);
    read(fd, buff, 100);
    cout << "buff:" << buff << endl;
    close(fd);
    return 0;
}
