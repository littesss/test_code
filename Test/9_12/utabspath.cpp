/*************************************************************************
	> File Name: utabspath.cpp
	> Created Time: Tue 12 Sep 2017 17:40:32 PDT
 ************************************************************************/
#include <iostream>
using namespace std;

#include "abspath.h"

int main()
{
    char buff[256];
    string input("./abspath.h");
    //Abspath::abspath("./111", buff);
    Abspath::abspath(input.c_str(), buff);
    cout << "output = " << buff << endl;
    return 0;
}
