/*************************************************************************
	> File Name: area.cpp
	> Created Time: Thu 28 Sep 2017 10:52:54 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <math.h>

int main()
{
    float a, b, c, s, area;
    cin >> a >> b >> c;
    bool t = 4;
    cout << t<< endl;
    if(a+b <= c)
    {
        cout << "a+b <= c" << endl;
    }
    if(a+b<=c || b+c<=a || a+c<=b)//有一个不满足就是error 
    {
        cout << "error" << endl;
    }
    else
    {
        s = (a+b+c)/2;
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        cout << "a = " << a << ",b = " << b << ",c = " << c << endl;
        cout << "area = " << area << endl;
    }
}
