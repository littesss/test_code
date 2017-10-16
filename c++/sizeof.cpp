/*************************************************************************
	> File Name: sizeof.cpp
	> Created Time: Thu 12 Oct 2017 09:42:35 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

class A
{
    char k[3];
    //public:
    virtual void aa(){}
};

class B:public virtual A
{
   // char j[3];
   // public:
    virtual void bb(){}
};


class C:public virtual B
{
    char i[3];
    public:
    virtual void cc(){}
};

int main()
{
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    cout << sizeof(C) << endl;

    return 0;
}
