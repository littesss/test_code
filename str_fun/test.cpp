/*************************************************************************
	> File Name: test.cpp
	> Created Time: Thu 21 Sep 2017 06:56:37 PM PDT
 ************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    const char * str = "hello";
    const char * str1 = "linux";
    
    while(*str++ !=  *str1++); //
    {
//        str++;
    }
    cout << str << endl; //由于连续开辟空间，所以str 输出linux
    cout << str1 << endl;//乱码
    return 0;
}
