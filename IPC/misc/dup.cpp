/*************************************************************************
  > File Name: dup.cpp
  > Created Time: Tue 03 Oct 2017 01:40:53 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd = open("./test.txt", O_RDWR);
    if(fd == -1)
    {
        cout << "error open" << endl;
        return -1;
    }
    cout << "fd = " << fd << endl;

    int fd1 = dup(fd);
    //cout << "fd1 = " << fd1 << endl;
    close(fd);
    if(fd1 == -1)
    {
        cout << "error dup" << endl;
        return -1;
    }
    cout << "fd1 = dup(fd) = " << fd1 << endl;
    
   off_t ret = lseek(fd1, 0, SEEK_END);
   if(ret == -1)
   {
       cout << "lseek failed" << endl;
       return -1;
   }
   const char * str = "hello,c++"; 
   int nbyte = write(fd1, str, strlen(str));
   if(nbyte == -1)
   {
       cout << "write failed" << endl;
       return -1;
   }
cout << "here" << endl; 
   int fd2 = dup2(fd1, 0);
cout << "here" << endl; 
   if(fd2 == -1)
   {
       cout << "dup2 failed.." << endl;
       return -1;
   }
   char buff[10];
   read(1,buff, 10);
   cout << "stdout:" << buff << endl;
   close(fd1);
    return 0;
}
