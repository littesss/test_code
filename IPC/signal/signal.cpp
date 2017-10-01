/*************************************************************************
  > File Name: signal.cpp
  > Created Time: Sun 01 Oct 2017 02:11:10 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <unistd.h>
#include <signal.h>

//typedef void (*sighandler_t)(int);
//sighandler_t signal(int signum, sighandler_t handler);


void handle(int sig)
{
    cout << "i get " << sig << endl;
}
int main()
{
    signal(2, handle); //ctrl+z  SIGINT终端进程
    signal(1, handle); // SIGHUP  挂起进程
    signal(SIGQUIT, handle); //ctr+\  3号信号 退出
    signal(SIGTSTP, handle); // ctrl+z  20 号信号 终止
    
    int ret = pause();//返回值只有-1
    cout << "ret = pause() = -1 ????" << ret << endl;
    
    alarm(5); // 5秒发送SIGALRM  

    while(1)
    {
        cout << "hello linux." << endl;
        sleep(1);
    }
    return 0;
}
