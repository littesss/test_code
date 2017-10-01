/*************************************************************************
	> File Name: callself.cpp
	> Created Time: Sun 01 Oct 2017 03:17:29 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

void test(int n)
{
    if(n == 2)
    {
        cout << " i get 2" << endl;
    }
}
void fun(int, void(*test)(int))
{
    test(2);
}
int main()
{
    fun(2,test);
    return 0;
}
