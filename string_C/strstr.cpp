/*************************************************************************
	> File Name: strstr.cpp
	> Created Time: Mon 09 Oct 2017 03:30:58 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string.h>

//strstr("abcde","bc") ,返回"bcde"  
const char * Strstr(const char* str, const char* sub)
{
    const char *pstr = str;
    const char *psub = sub;
    int i=0,j;
    for(i=0; pstr[i]!=0; ++i)
    {
        for(j=0; psub[j]!=0; ++j)
        {
            if(str[i+j] != sub[j])
            {
                break;
            }
        }
        if(psub[j] == 0)
        {
            return &str[i];
        }
    }
    return NULL;
}
//编写一个高效率的函数，实现返回字符串中第一个不重复出现的字符
char findNonRepeated(const char* str)
{
    if(str == NULL)
        return 0;
    int i;
    int count[256] = {0};
    for(i=0; str[i]!='\0'; ++i)
    {
        count[(unsigned char)str[i]]++;
    }
    for(i=0; str[i]!=0; ++i)
    {
        if(count[(unsigned char)str[i]] == 1)
        {
            return str[i];
        }
    }
    return '\0';
}

int main()
{
    const char * str = "hello";
    const char * sub = "el";
    cout << strstr(str,sub) << endl;
    cout << Strstr(str,sub) << endl;
    cout << findNonRepeated("hhhhssswccc") << endl;
    return 0;
}
