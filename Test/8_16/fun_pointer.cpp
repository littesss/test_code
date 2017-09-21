#include<iostream>
using namespace std;

int add(int a,int b)
{
    return a+b;
}

void test()
{
    cout << "test" <<endl;
}

int (* fun(int n)(int,int))_
{
    return add;
}
int main()
{
    cout << fun(test)(4,6) << endl;
    return 0;
s}
