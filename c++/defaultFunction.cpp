/*************************************************************************
	> File Name: defaultFunction.cpp
	> Created Time: Wed 11 Oct 2017 10:08:24 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

class A
{
    public:
        const void fun()const//常成员函数
        {
            cout << "hello" << endl;
        }
};

int main()
{
    A a; // 构造函数
    A b = a; //拷贝构造
    //A b(a); //同上
    A c; //构造函数
    c = b; //赋值运算符的重载

    A d; // 取地址运算符的重载，普通方法
    //const A d;
    A const e;//取地址运算符的重载常方法
    cout << &e << endl; //
    cout << &a << endl; //
   // cout << a << endl;
   e.fun();//常对象，只能调动常方法
    return 0;
}
