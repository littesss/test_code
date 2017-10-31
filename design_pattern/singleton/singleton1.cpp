/*************************************************************************
	> File Name: singleton1.cpp
	> Created Time: Tue 31 Oct 2017 08:07:48 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

class singleton
{
    public:
        singleton(int a=10)
        {
            cout << this << endl;
        }
    private:
        int a;
};

int main()
{
    //带默认值构造函数
    singleton* p  = new singleton;
    singleton* p1 = new singleton();
    singleton* p2 = new singleton(1);

    return 0;
}
