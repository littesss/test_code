/*************************************************************************
> File Name: test.cpp
> Author: Littesss 
> Mail: liushaohua_2017@163.com 
> Created Time: 2017-10-31T02:11:49 PDT
************************************************************************/

#include<iostream>
using namespace std;

class A
{
    public:
    A(int a=10,const char* str="hello")
    {
        a = a;
        b = str;
        cout << "constructor" << endl;
    }

    private:
    int a;
    const char* b;
    /*
    public:
    void * fun1()
    {
        cout << "hello"  << endl;
    }
    void fun()
    {
        //void * p = new void* fun1();
    }
    private:
    A(){}
    */
};
int main()
{
    A aa;//A aa();  系统会认为是函数声明
    A bbb(); //函数声明
    //A* bb = new A();
    //A* cc = new A;
    //cout << aa << endl;
   /* cout << aa->a << endl;
    cout << aa.b << endl;
*/
    return 0;
}
