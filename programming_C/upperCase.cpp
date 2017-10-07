/*************************************************************************
	> File Name: upperCase.cpp
	> Created Time: Fri 06 Oct 2017 07:54:29 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string.h>

void upperCase(char * arr)
{
   int i=0;
   for(i; i<= strlen(arr); ++i)
   {
       if(arr[i]>='a' && arr[i]<='z')
       {
           //arr[i]-= 'a' - 'A';
           arr[i] -= 32;
       }
   } 
}
int main()
{
    char arr[] = "AbcDe";
    upperCase(arr);
    cout<< "arr[] = " << arr << endl;

    return 0;
}
