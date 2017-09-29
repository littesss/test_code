/*************************************************************************
	> File Name: abc+cba.cpp
	> Created Time: Thu 28 Sep 2017 10:45:32 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    //abc+cba = 1333;
    int a, b, c;
    for(a=1; a<=9; a++)
    {
        for(b=0; b<=9; b++)
        {
            for(c=1; c<=9; c++)
            {
                if((a*100+b*10+c + c*100+b*10+a) == 1333)
                    cout << "abc = " << a << b << c << endl;
            }
        }
    }
    return  0;
}
