/*************************************************************************
	> File Name: static.cpp
	> Created Time: Fri 06 Oct 2017 03:29:10 PM CST
 ************************************************************************/
#include "static.h"
#include <iostream>
using namespace std;

static int a1;
int globle_b;
void fun()
{
    static int b = 1;
    a1++;
    static char c;
    static int d;

    cout << "jubu static c = " <<(int) c << endl;
    cout << "jubu static d = " << d << endl;
}
int main()
{
    //cout << "++b = " << ++b << endl;
    cout << "++a1 = " << ++a1 << endl;
    fun();
    cout << "static a1 = " << a1 << endl;
    cout << "globle int a = " << a << endl;
    cout << "A = " << (int)'A' << endl;
    cout << "A = " << (char)65 << endl;
    return 0;
}
