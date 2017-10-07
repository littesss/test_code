/*************************************************************************
	> File Name: sizeofClass.cpp
	> Created Time: Fri 06 Oct 2017 08:11:08 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

class A
{
   char a;
};

class A2
{

};

class B :public virtual A //虚继承加一个指针+在最后，在这个继承里面A是虚继承
{
};

class C :public virtual A2 ,virtual A
{};

class D :public A, public A2
{};
//class E :public B, public  A   // 二义性的继承必须虚继承
class E :public B, public  virtual A //
{};
struct AA
{
    int a  ;
    static int  b ;
    static double c;
};
int main()
{
    cout << sizeof(A) << endl;// 1
    cout << sizeof(B) << endl;// 16
    cout << sizeof(C) << endl;// 16
    cout << sizeof(D) << endl;// 不是3 是2 //空类给1个char 继承多个空类还是给1个char
    cout << sizeof(E) << endl;// 16

    cout << sizeof(AA) << endl;// 4 
    int a;



}
