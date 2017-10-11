/*************************************************************************
	> File Name: 10_8.cpp
	> Created Time: Sun 08 Oct 2017 03:17:40 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int fun10_8(int a)
{
    int b = ((a/100)%10)*8*8 + ((a/10)%10*8) + (a%10);
    return b; 
}

int fun8_10(int a)
{
    int b =((a/100)%10)*8*8 +((a/10)%10)*8 + (a%10);
    return b;
}

int main()
{
    int a = 377;
    cout << fun8_10(a) << endl;
    cout << (a/100) % 10 << endl;
    cout << (a/10) % 10 << endl;
    cout << a%10 << endl;
    cout << fun10_8(a) << endl;;

    return 0;
}
