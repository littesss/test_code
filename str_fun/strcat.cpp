/*************************************************************************
	> File Name: strcat.cpp
	> Created Time: Thu 21 Sep 2017 06:34:16 PM PDT
 ************************************************************************/
#include <iostream>
using namespace std;

#include <assert.h>


char * my_strcat(char * dest, const char * src)
{
    assert(dest && src);
    char * temp1 = dest;
    const char *temp2 = src;
    while(*temp1 != '\0')
    {
        temp1++;
    }
    while(*temp2 != '\0')
    {
        *temp1++ = *temp2++;
    }
    *temp1 = '\0';
    return dest;
}
int main()
{
    char  dest[20] = "hello ";
    char  src[] = "linux";
    char * ret =  my_strcat(dest, src);
    cout << ret  << endl;
    return 0;
}
