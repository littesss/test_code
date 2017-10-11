/*************************************************************************
	> File Name: deleteInt.cpp
	> Created Time: Wed 11 Oct 2017 04:51:39 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

// "abc4d51e"  "abcde"

void delete_int(char* str)
{
    char *i = str;
    char *j = str;
    if(NULL == str)
    {
        return;
    }

    while(*i != '\0')
    {
        if(*i<'0' || *i>'9') //!0 ~ 9
        {
            *j = *i;
            j++;
        }
        i++;
    }
    *j = '\0';
    return;
}

void delete_char(char* str)
{
    char* i = str;
    char* j = str;
    if(NULL == str)
        return;

    while(*i)
    {
        if(*i>='0' && *i<='9')
        {
            *j = *i;
            j++;
        }
        i++;
    }
    *j = '\0';
    return;
}
int main()
{
    char str[] = "abc4d513333e222v";
    cout << "str:" << str << endl;
    delete_int(str);
    cout << str << endl;

    char str1[] = "abc4d513333e222v";
    delete_char(str1);
    cout << str1 << endl;
    return 0;
}
