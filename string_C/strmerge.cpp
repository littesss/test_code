/*************************************************************************
	> File Name: strmerge.cpp
	> Created Time: Wed 11 Oct 2017 02:44:53 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string.h>

//"ab*c**d*e"   "*****abcde" return 5
int merge(char* str)
{
    if(!str)
        return 0;
    int i, j;
    int count = 0;
    char temp;
    i = j = strlen(str) - 1;

    while(i >= 0)
    {
        if(str[i] != '*')
        {
            temp = str[i];
            str[i] = str[j];
            str[j] = temp;
            i--;
            j--;
        }
        else
        {
            i--;
            count++;
        }
    }
    return count;
}
int main()
{
    char arr[20] = "ab*c****d*e";
    cout << merge(arr) << endl;
    cout << arr << endl; 
    
    return 0;
}
