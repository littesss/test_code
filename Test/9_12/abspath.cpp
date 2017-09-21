/*************************************************************************
	> File Name: abspath.cpp
	> Created Time: Tue 12 Sep 2017 17:31:14 PDT
 ************************************************************************/
#include <iostream>
using namespace std;

#include <limits.h>
#include <stdlib.h>

#include <abspath.h>

void  Abspath::abspath(char* input, char* output)
{
    if(!input)
    {
        cout << "NULL path" << endl;
        return;
    }
    char *ret = realpath(input, output);
    if(!ret)
    {
        cout << "realpath error" << endl;
        return;
    }
    cout << "realpath():return = "  << ret << endl;
}
