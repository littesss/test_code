/*************************************************************************
	> File Name: strinsert.cpp
	> Created Time: Wed 11 Oct 2017 01:35:13 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string.h>

/*在字符串dest 中的pos位置，插入字符串src*/
//还有一种思想就是memcpy(dest, src ,len)  dest[last] = '\0';
void strinsert(char* dest, char*src, int pos)
{
    if(!dest || !src)
        return;
    if(pos>strlen(dest) || pos<=0 )
    {
        cout << "enter pos illegal!" << endl;
        return; 
    }
    cout << "here" << endl;
    char arr_temp[20];
    char *temp;
    temp = &dest[pos-1];
    strcpy(arr_temp, temp);
    strcpy(temp, src);
    int len = strlen(dest);
    char * temp_1 = &dest[len];
    strcpy(temp_1, arr_temp);
}
int main()
{
    char dest[20] = "hello";
    char src[10] = "linux";

    strinsert(dest, src, 2);
    cout << dest << endl;

}
