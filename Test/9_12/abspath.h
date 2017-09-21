/*************************************************************************
	> File Name: abspath.h
	> Created Time: Tue 12 Sep 2017 17:28:27 PDT
 ************************************************************************/
#ifndef _ABSPATH_H
#define _ABSPATH_H

#include <string>
#include <iostream>
using namespace std;

#include <limits.h>
#include <stdlib.h>

class Abspath
{
    public:
        static void abspath(const string input,char* output);
};
void  Abspath::abspath(const string input, char* output)
{
   
    char *ret = realpath(input.c_str(), output);
    if(!ret)
    {
        cout << "realpath error" << endl;
        return;
    }
    cout << "realpath():return = "  << ret << endl;
}
#endif
