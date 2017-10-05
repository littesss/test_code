/*************************************************************************


  > File Name: fd.cpp
  > Created Time: Thu 05 Oct 2017 05:03:09 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <sys/types.h>          /* See NOTES */
#include <sys/socket.h>

#include <stdlib.h>
#include <unistd.h>
int main()
{
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    cout << "fd:" << fd << endl;

    int fd1 = socket(AF_INET, SOCK_STREAM, 0);
    cout << "fd1:" << fd1 << endl;

    int fd2 = socket(AF_INET, SOCK_STREAM, 0);
    cout << "fd2:" << fd2 << endl;
    sleep(2);
    exit(0);
    return 0;

}
