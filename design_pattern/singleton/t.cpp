/*************************************************************************
	> File Name: t.cpp
	> Author: Littesss 
	> Mail: liushaohua_2017@163.com 
	> Created Time: 2017-10-31T23:25:30 PDT
 ************************************************************************/

#include<iostream>
using namespace std;

//嵌套类去析构单例类对象
class A
{
    public:
    ~A()
    {
        cout << "deconstructor A" << endl;
    }
    private:
    class B
    {
        public:
        ~B()      //嵌套类成员的析构函数去析构单例函数的对象
        {
            cout << "调用嵌套 deconstructor B" << endl; 
        }
    };

    private:
    static  B b;
    static int a;
};
int  A::a = 10;
A::B A::b;        //嵌套静态类成语,必须类外声明

int main()
{
    return 0;
}
