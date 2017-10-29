/*************************************************************************
	> File Name: da.cpp
	> Created Time: Wed 25 Oct 2017 10:27:44 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <stdio.h>

int main()
{
    unsigned int a = 0x12345678;
    unsigned char *p =(unsigned char*) &a;
    printf("%0x", p[0]);
    cout << p[0] << endl;
    cout << p[1] << endl;
    cout << p[2] << endl;
    cout << p[3] << endl;
    return 0;
}
