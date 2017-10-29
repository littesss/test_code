/*************************************************************************
	> File Name: change.cpp
	> Created Time: Tue 17 Oct 2017 04:05:07 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

void fun(int* a, int*b)
{
    *a = *a^*b;
    *b = *a^*b;
    *a  = *a^*b;
}
int main()
{
    int a=10, b=20;
    cout << "a:" << a << " ,b:" << b << endl;
    fun(&a,&b);
    cout << "a:" << a << " ,b:" << b << endl;
    return 0;
}
