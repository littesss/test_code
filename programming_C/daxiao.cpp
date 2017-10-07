/*************************************************************************
	> File Name: daxiao.cpp
	> Created Time: Fri 06 Oct 2017 11:03:11 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    int a = 30;
    int b = 20;
    const char* str[2] = {"a 大","b 大"};
    int c = a - b;
    c = ((unsigned int)c) >> 31;
    cout << c << endl;
    c = c >> 31;
    cout << str[c] << endl;
}
