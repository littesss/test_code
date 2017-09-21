/*************************************************************************
	> File Name: gethostname.cpp
	> Created Time: Tue 12 Sep 2017 21:13:54 PDT
 ************************************************************************/
#include <iostream>
using namespace std;
#include <unistd.h>

#include <stdio.h>

int main()
{
    char buff[256];
    int ret = gethostname(buff, 20);
    cout << "hostname:" << buff << endl;

    ret = sethostname("lsh", 20);
   cout << ret << endl; 
    if(ret)
    {
        perror("sethostname");
    }
    ret = gethostname(buff, 20);
    cout << "hostname:" << buff << endl;

    return 0;
}
