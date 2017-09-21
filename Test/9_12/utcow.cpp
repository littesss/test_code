/*************************************************************************
	> File Name: utcow.cpp
	> Created Time: Tue 12 Sep 2017 21:28:55 PDT
 ************************************************************************/
#include <iostream>
using namespace std;

#include <stdio.h>

int main()
{
    string a("aaaa");
    string b("aaaa");
    cout << &a << endl;
    cout << &b << endl;
    cout << "===="  << endl;
    a = b;

    cout << &a << endl;
    cout << &b << endl;
    return 0;
}
