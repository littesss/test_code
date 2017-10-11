/*************************************************************************
	> File Name: upperFirst.cpp
	> Created Time: Wed 11 Oct 2017 03:06:13 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string.h>
// aAbcDe  abceAD

void move_char(char* str)
{
    if(!str)
        return ;
    int i=0;
    int j = strlen(str) - 1;
    char temp;
    
    while(i<j)
    {
        while(str[i]!='\0' && str[i]>='a' && str[i]<= 'z')
        {
            i++;
        }
        if(str[i] == '\0')
        {
            break;
        }
        while(&str[j] != &str[0] && str[j]>='A' && str[j]<='Z')
        {
            j--;
        }
        if(i<j)
        {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i++;
            j--;
        }
    }
}

int main()
{
    char arr[] = "aAbcDe";
    move_char(arr);
    cout << arr << endl;
}
