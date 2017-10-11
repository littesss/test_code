/*************************************************************************
	> File Name: frequency.cpp
	> Created Time: Wed 11 Oct 2017 04:26:10 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string.h>
// "hello"   ch = 'l' size = '2'
void frequency(char* str, char &ch, int &size)
{
    int n[256];
    size = 0;
    ch = '\0';
    if(!str)
        return;
    int  i;

    memset(n, 0, sizeof(n));
    for(i=0; str[i] != '\0'; ++i)
    {
        n[(unsigned char)str[i]] += 1;
        if(n[(unsigned char)str[i]] > size)
        {
            size = n[(unsigned char)str[i]];
            ch = str[i];
        }
    }

}
void fun(char* & p)
{}
int main()
{
    char str[] = "hello";
    char ch;
    int size;
    frequency(str, ch, size);
    cout << "ch :" << ch << endl;
    cout << "size :" << size << endl;
    
    return 0;
}
