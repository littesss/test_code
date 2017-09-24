/*************************************************************************
  > File Name: string_char.cpp
  > Created Time: Sun 24 Sep 2017 03:43:55 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string>

void fun(const char * pchar)
{}
int main()
{
//    char* Pchar = new char[100];
    //string* Pstr = new string;
    const char * Pchar = "hello"; // "hello"常量 ，const接受
    fun(Pchar);
    return 0;
}
