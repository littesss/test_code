/*************************************************************************
	> File Name: testReference.cpp
	> Created Time: Sun 24 Sep 2017 12:34:26 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string>

void fun(int& a)
{
   a = 100;

}
void fun(int *a)
{
   *a = 1000;
}
/*
void fun(int a)
{
    a = 1000;
}
*/
void fun1(string &s)
{
    s = "linuxxxxxxxxxxxxxxxxx";
}


int main()
{
    int a = 10;
    cout << a << endl;
    fun(a);
    cout << a << endl;
    fun(&a);
    cout << a << endl;
    
    cout << "=========" << endl;
    string s("hello");
    cout << s << endl;
    fun1(s);
    cout << s << endl;
    return 0;
}
