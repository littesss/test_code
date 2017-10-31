/*************************************************************************
	> File Name: singleton2.cpp
	> Created Time: Tue 31 Oct 2017 08:17:51 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

//默认构造函数只能有一个， 构造函数可以有多个
class A
{
    public:
        A(int a)
        {

        }
        A(char* a)
        {}
        A(char a='q')
        {}
    private:
        int a ;
};

int main()
{
    A a(19);
    A b(a);
    A c('b');
    return 0;
}
