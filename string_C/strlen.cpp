/*************************************************************************
	> File Name: strlen.cpp
	> Created Time: Tue 10 Oct 2017 08:40:28 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string.h>

int main()
{
    int i = strlen("%%\"abcdef\"\\");
    cout << i << endl;    
    return 0;
}

