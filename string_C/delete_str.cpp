/*************************************************************************
	> File Name: delete_str.cpp
	> Created Time: Mon 09 Oct 2017 01:40:09 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string.h>

int main()
{
    const char* str = "hehheello";
    const char* sub = "he";
    
    const char* pstr, * psub;
    char out[20];
    int i=0,j;
    pstr = str;
    psub = sub;
    while(*pstr != '\0')
    {
        for(j=0; j<strlen(sub); j++)
        {
            if(pstr[j] != psub[j])
            {
                break;
            }
        }
        if(j == strlen(sub))
        {
            pstr += strlen(sub);
        }
        else
        {
            out[i++] = *pstr++;
        }
    }
    cout << out << endl;
    return 0;
}
