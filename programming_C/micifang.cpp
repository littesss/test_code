/*************************************************************************
	> File Name: 1.cpp
	> Created Time: Tue 10 Oct 2017 07:38:50 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int fun(int a, int n) // 2^3 = 8
{
    if(n == 0)
        return 1;
    if(a == 0)
        return 0;
    int sum = 1;
    for(int i=1; i<=n; i++)
    {
        sum *= a;
    }
    return sum;
}

void fun1(int * a, int n)
{
    *a <<= n-1;
}
int main()
{
    int a=3;
    cout << fun(a,2) << endl;    
    fun1(&a, 2);
    cout << a << endl;
    return 0;
}
