/*************************************************************************
	> File Name: test.cpp
	> Created Time: Mon 09 Oct 2017 10:42:08 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;

typedef void(*fun)(void);

void fun(void a)
{
    cout<< "hello" << endl;
}
int main()
{
    ((fun)0x10000)();
    return 0;
}
