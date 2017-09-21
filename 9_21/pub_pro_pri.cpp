/*************************************************************************
	> File Name: pub_pro_pri.cpp
	> Created Time: Wed 20 Sep 2017 06:58:57 PM PDT
 ************************************************************************/
#include <iostream>
using namespace std;

class test
{
    public:
        test(){}
        ~test(){}
        void getvalue(int aa)//aa = 10
        {
            ++a = aa;
            cout << "a = " << a << endl;// a = 10
            getvalue1(a);
        }
        void get_private_value()
        {
            cout << "this->d = " << this->d  << ";"<< endl;
        }
        static void getvalue2(test t)
        {
            t.a = 10;
            cout << "t.a = " << t.a << endl;
        }

        static int b; // 静态数据成员不能在类里面定义，只能声明，类外实现
    protected://类里面保护和继承一样，类外保护不能被访问，保护继承原public属性变为protected
        void getvalue1(int aa)
        {
            cout << "protected: this->c = " << c << ";" << endl;
            a = aa;
            cout << a << endl;
        }
    private:
        int a = 10;
        static char c;
        static int d; // 静态数据成员不能在类里面定义，只能声明，类外实现
};

int  test::b; // 默认为0
char test::c; //默认为空
int  test::d = 100;

int main()
{
    test t;
    t.getvalue(10);//类的共有成员可以被外部访问
//  t.getvalue1(10);//类的保护成员不能被外部访问
    t.get_private_value();
    test::getvalue2(t);//静态的共有方法才能被外部访问

    cout << "test::b =" << test::b << endl;
    return 0;
}
