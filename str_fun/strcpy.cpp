/*************************************************************************
	> File Name: strcpy.cpp
	> Created Time: Thu 21 Sep 2017 06:48:21 PM PDT
 ************************************************************************/
#include <iostream>
using namespace std;

#include <assert.h>

void my_strcpy(char * dest, const char * src)
{
    assert(dest && src);
    char * temp1 = dest;
    const char * temp2 = src;
    while (*temp2 != '\0')
    {
        *temp1++ = *temp2++;
    }
    *temp1 = '\0';
   // return dest;
}
int main()
{
    char dest[20] = "hello";
    const char * src = "linux";
    
    cout << "before dest:" << dest << endl;
    my_strcpy(dest, src);
    cout << "after dest:" << dest << endl;
    return 0;
}
