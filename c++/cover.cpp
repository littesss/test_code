/*************************************************************************
	> File Name: cover.cpp
	> Created Time: Sat 14 Oct 2017 03:31:41 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

class A
{
    public:
        void fun()
        {
            cout << "A fun" << endl;
        }
};

class B:public A
{
    public:
        int fun()
        {
            cout << "B fun()" << endl;
            return 0;
        }
};

int main()
{
    B b;
   cout <<  b.fun() ;
}
