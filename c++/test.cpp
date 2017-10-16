/*************************************************************************
	> File Name: test.cpp
	> Created Time: Thu 12 Oct 2017 11:24:38 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;

class A 
{
    public:
        A(){cout << "A construction" << endl;}
        A(const A&a){cout << "reference" << endl;}
        ~A(){cout << "deconstructor" << endl;}
};
int main()
{
   // A();//无名对象
   // A a;
    //A b(); //函数声明，不调默认构造函数
    //A c = A();
    A b;
    //A e = A();//不调拷贝构造，只调构造函数,估计是系统优化
    return 0;
}
