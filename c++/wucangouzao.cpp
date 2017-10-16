/*************************************************************************
	> File Name: wucangouzao.cpp
	> Created Time: Wed 11 Oct 2017 10:33:35 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

//析构函数可以设置成inline函数
class A
{
public:
    A(char c = 'a')//构造函数
    {
        cout << "A()" << endl;
    };
    A(char c , int b = 10 )//构造函数
    {}
    A(float c, int b = 10) //构造函数
    {}
   // A(double a = 0, float b){} // 带默认值的构造函数
    //A(){}//无惨构造函数
    void fun()
    {
        cout << "this" << endl;
    }
};

void fun(void)
{
    cout << "quanju" << endl;
}
int main()
{
    A g('a',10);
    //A f('a', 11);
    //A b = 'c';
    //b.fun();
    //fun();
    A c; // 调动无惨构造函数
    return 0;
}
