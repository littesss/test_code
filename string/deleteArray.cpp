/*************************************************************************
	> File Name: deleteArray.cpp
	> Created Time: Mon 25 Sep 2017 01:38:06 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string.h>
class A
{
    public:
        A(const char * s = "")
        {
            if(s == NULL)
            {
                str = new char[1];
                str[0] = '\0';
            }
            else
            {
                str = new char[sizeof(s)];
                strcpy(str,s);
            }
        }
        ~A()
        {
            cout << "destructor :" << str << endl;
            delete str;
            str = NULL;
        }
    private:
        char * str;
};


int main()
{
    A * a = new A[10];
    delete []a;
    //delete a;
    //仅释放了a指针指向的全部内存空间 但是只调用了a[0]对象的析构函
    //数 剩下的从a[1]到a[9]这9个用户自行分配的m_cBuffer对应内存空
    //间将不能释放 从而造成内存泄漏
    /*a[0] = "n";
    a[1] = "nn";
    a[2] = "nnn";
*/


/*
    int * p = new int[10];
    p[1] = 10;
    cout << p[1] << endl;
 //   delete p;//不会造成内存泄露
    delete []p;
*/
    //此种情况中的释放效果相同，原因在于：分配简单类型内存时，内存
    //大小已经确定，系统可以记忆并且进行管理，在析构时，系统并不
    //会调用析构函数
    return  0;
}
