/*************************************************************************
	> File Name: constructor.cpp
	> Created Time: Sun 24 Sep 2017 11:24:36 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;

class base
{
    public:
        base(int a = 0)//要写构造函数，就应该写默认值
        {
            cout << "defalut constructor function" << endl;
        }
        base(const base& b)//拷贝构造必须引用传递，否则死递归
        {
            cout << "copy constructor" << endl;
        }
        base& operator=(base &a) // 引用返回提高效率，不然会调动拷贝构造
        {
            cout << "assignment base" << endl;
        }
        base& operator=(int  a)
        {
            cout << "assignment int"  << endl;
        }  
        ~base()
        {
            cout << "deconstructor" << endl;
        }
    private:
        int a;
        char c;
};

int main()
{
    base b(5);//用整形去构造对象
    base b1 = 10;//等价于b对象的构造
    base b2 = b;//拷贝构造
    base b3;// 默认构造函数 构造出b3对象
    b3 = b2; //赋值语句,对象给对象赋值
    cout << "1111111111111111" << endl;
    b3 = 1111; //1.1111先去调动默认构造函数，构造一个无名临时对象， 2无名临时对象在给b3对象赋值3,使命完成，先析构无名临时对象
    cout << "1111111111111111" << endl;
  
    return 0;
}
