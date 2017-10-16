/*************************************************************************
	> File Name: pure_virtual.cpp
	> Created Time: Sat 14 Oct 2017 03:47:47 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

class A
{
    public:
        virtual void fun() = 0;
};

class B
{
    public:
        void fun()
        {
            cout << "B fun()" << endl;
        }
};

int main()
{
    B b;
    b.fun();
    return 0;
}
