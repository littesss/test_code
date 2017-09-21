/*************************************************************************
	> File Name: inherit.cpp
	> Created Time: Thu 21 Sep 2017 12:58:55 AM PDT
 ************************************************************************/
#include <iostream>
using namespace std;

class base
{
    public:
        static void getvalue(int aa)
        {
            cout << "base public static this->a = " << aa << endl;
            //a = aa;
            //cout << "base public this->a = " << a << endl;
        }
    protected:
        void getvalue1(int bb)
        {
            A = bb;
            cout << "base protect this->a = " << A << endl;
        }
    private:
        int A;
};
class derive :public base
{
    public:
        void getvalue3(int aa)
        {
           //a = A; 子类方法不能访问父类私有数据，如要访问通过父类共有方法间接访问 
            a = aa;
            cout << "derive public this->a = " << a << endl;
        }
    protected:
        void getvalue4(int bb)
        {
            a = bb;
            cout << "derive protect this->a = " << a << endl;
        }
    private:
        int a;
};

int main()
{
    derive d;
//    d.getvalue(10);//public 全盘接受，除了构造析构，
//    d.getvalue3(10);//protected  base public--->protected
    derive::getvalue(10);//可以通过子类访问父类静态函数
    base::getvalue(10);
    return 0;
}
