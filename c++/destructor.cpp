/*************************************************************************
	> File Name: destructor.cpp
	> Created Time: Thu 12 Oct 2017 11:13:18 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;

//virtual destructor

class A
{
    public:
        A(){ cout << "A construction:" << this << endl;}
        virtual ~A(){cout << "A destructor:" << this << endl;}
};
class D: public A
{
    public:
        D(){ cout << "D construction:" << this << endl;}
        ~D(){cout << "D destructor:" << this << endl;}
};

int main()
{
    new D ;
    new D();
    D a;
    A & b = a;
    // D d;
    // A * a = new D;
    //D d;
    //A & b = d;
    cout << "=====" << endl;
    // delete a;
    return 0;
}
