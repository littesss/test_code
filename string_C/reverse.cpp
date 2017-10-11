/*************************************************************************
	> File Name: reverse.cpp
	> Created Time: Wed 11 Oct 2017 02:14:05 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

//不额外开辟空间的情况下，完成字符串逆序
void reverse(char* str)
{
    if(!str)
        return;
    char *p = str;
    while(*p)
    {
        p++;
    }
    p--; 
    char temp;
    while(str < p)
    {
        temp = *str;
        *str++ = *p;
        *p-- = temp;
    }
}
int main()
{
    char arr[20] = "hello";
    reverse(arr);
    cout << arr << endl;
    return 0;
}
