/*************************************************************************
	> File Name: t.cpp
	> Created Time: Thu 12 Oct 2017 03:23:19 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

class A
{
    public:
         void  fun()
        {
            cout << "A" << endl;
        }
};
class B :public A
{
    public:
         void fun()
        {
            cout << "B" << endl;
        }
};

int main()
{
    //B* pb = new B();
    B* pbb =(B*) new A();
    pbb->fun();

   // A* pa = new B();
    //``pa->fun();
    
    return 0;
}
