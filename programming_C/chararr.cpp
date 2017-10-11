/*************************************************************************
	> File Name: chararr.cpp
	> Created Time: Fri 06 Oct 2017 07:43:46 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

void fun(char str[3])//有警告，说会返回char*
{
    char * str1 = "abc";
    cout << sizeof(str1) << endl;
    cout << sizeof(str) << endl;
}

void fun1(char* str) // 数组是连续的只需传首地址就行了
{
    cout << str[3] << endl;
}
int main()
{
    char str[] = "hello";
    
    cout << sizeof(str) << endl; //6
    fun(str);

    int * p = NULL;
    cout << sizeof(p) << endl; // 64位 8字节
    fun1(str);


    return 0;
}
