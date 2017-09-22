/*************************************************************************
	> File Name: strcmp.cpp
	> Created Time: Thu 21 Sep 2017 06:06:22 PM PDT
 ************************************************************************/
#include <iostream>
using namespace std;

#include <assert.h>

int my_strcmp(const char *str1, const char* str2)
{
    assert(str1 && str2);
    const char * temp1 = str1;
    const char * temp2 = str2;
    
    while(*temp1++ == *temp2++ && *temp1 && *temp2)
    {
//        temp1++;
//        temp2++;
    }
    if(*temp1 == * temp2)
        return 0;
    else if(*temp1 > *temp2)
        return 1;
    else
        return -1;

    /*
    assert(str1 != NULL && str2 != NULL);  
    while( (*str1) == (*str2) &&  *str1 && *str2 )  
    {  
        str1++;  
        str2++;  
    }  
    if(*str1 == '\0'&& *str2 == '\0')  
        return 0;  
    else if (*str1 >*str2)  
        return 1;  
    else  
        return -1; 
        */
}
int main()
{
    const char * str1 = "hello1";
    const char * str2 = "hello";
    int ret = my_strcmp(str1,str2);
    cout << ret << endl;

    return 0;
}
