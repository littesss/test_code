/*************************************************************************
	> File Name: signalregist.cpp
	> Created Time: Sun 01 Oct 2017 02:51:24 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <unistd.h>
#include <signal.h>

void signalhandle(int signum)
{
    if(signum == 2)
    {
        cout << "i get " << signum << endl;
    }
    if(signum == 3)
    {
        cout << "i get " << signum << endl;
    }
}


int main()
{
    //注册信号处理函数
    signal(2, signalhandle);
    signal(3, signalhandle);
    //int ret = alarm(10);
    //cout << ret << endl;

    //sleep(10);
    alarm(5);//定时器
    while(1)
    {
        cout << "i am waiting singnal...." << endl;
        sleep(2);
    }

    return 0;
}
