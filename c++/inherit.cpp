/*************************************************************************
	> File Name: inherit.cpp
	> Created Time: Thu 12 Oct 2017 02:45:28 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

class A
{
    public:
        void virtual f()
        {
            cout << "A" << endl;
        }
};

class B: public A
{
    public:
        void virtual f()
        {
            cout << "B" << endl;
        }
};
int main()
{
    B bb;
    A aa;
    aa = bb;
    //bb = aa;         // 错误
    A& aaa = bb;
    //B& bbb = aa;     // 错误
    A* aaaa = &bb;
    //B* bbbb = &aa;   // 错误
    A* pa = new A();
    pa->f();

    B* pb = (B* )pa;
    pb->f();
    delete pa;
    cout << "==========" << endl;
    pa = new B();
    pa->f();
    pb = (B* )pa;
    pb->f();
    delete pb;
    return 0;
}
