/*************************************************************************
	> File Name: strlen.cpp
	> Created Time: Thu 21 Sep 2017 05:53:46 PM PDT
 ************************************************************************/
#include <iostream>
using namespace std;

#include <assert.h>

int my_strlen(const char * str)
{

    assert(NULL != str);
    const char * temp = str;
    static int count = 0;
    while(*temp++ != '\0')
    {
        count++;
    }
    return count;
}
int main()
{
    const char *str = "hello";
    int ret = my_strlen(str);
    cout << ret << endl;
    return 0;
}
