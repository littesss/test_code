/*************************************************************************
	> File Name: template2.cpp
	> Created Time: Mon 16 Oct 2017 11:02:47 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;

template <class T>
T fun(T a, T b)
{
    return a>b ? a:b;
}

int main()
{
    cout << fun(1,2) << endl;
    cout << fun('a', 'b') << endl;
    return 0;
}
