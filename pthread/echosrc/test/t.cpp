/*************************************************************************
	> File Name: t.cpp
	> Created Time: Wed 01 Nov 2017 10:37:01 PM CST
 ************************************************************************/
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    int i = 0;
    while(1)
    {
        if(i == 3)
        {
            exit(1);
        }
        cout << "i = " << i << endl;
        i++;
    }
    return 0;
}
