/*************************************************************************
	> File Name: deleteStr.cpp
	> Created Time: Wed 11 Oct 2017 06:06:38 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

void  deleteStr(char * str, const char * sub)
{
    int src=0, dest, arr[256]={0};

    if((str == NULL) || (sub == NULL))
    {
        return;
    }

    while(sub[src] != 0)
    {
        arr[(unsigned char)sub[src]] = 1;
        src++;
    }

    src=0;
    dest=0;

    for(;str[src]!=0; src++)
    {
        if(arr[(unsigned char)str[src]] == 0)
        {
            str[dest]=str[src];
            dest++;
        }
    }
    str[dest] = 0;
}
int main()
{
    char str[] = "hello hreeehedlofllllllllllllllfooo";
    const char * sub = "he";
    cout << str << endl;
    deleteStr(str, sub);
    cout << str << endl;
    return 0;
}
