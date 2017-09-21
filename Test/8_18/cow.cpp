/*************************************************************************
	> File Name: cow.cpp
	> Created Time: Fri 18 Aug 2017 21:07:18 PDT
 ************************************************************************/
#include<iostream>
#include <string>
using namespace std;

int main()
{
    string a("hello");
    string b(a);
    cout << &a << a.c_str() << endl;
    cout << &b << b.c_str() << endl;
    
    b = "hello"; 
    cout << &a << a.c_str() << endl;
    cout << &b << b.c_str() << endl;
    return 0;
}
