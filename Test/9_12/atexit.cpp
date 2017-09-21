/*************************************************************************
	> File Name: atexit.cpp
	> Created Time: Tue 12 Sep 2017 20:40:34 PDT
 ************************************************************************/
#include <iostream>
using namespace std;

#include <stdlib.h>

void fun1(void)
{
    cout << "i am fun1" << endl;
}

void fun2(void)
{
    cout << "i am fun2" << endl;
}

int main()
{
    exit(1);
    cout << "front" << endl;
    atexit(fun1);
    atexit(fun2);
    cout << "back" << endl;

//    return 0;
}
