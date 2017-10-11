/*************************************************************************
	> File Name: test.cpp
	> Created Time: Mon 09 Oct 2017 11:17:57 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string.h>
#define MAX 255

int main()
{
   /*
    unsigned char a[MAX],i;
    for(i=0; i<=MAX; i++)
    {
        cout << "si xun huan" << endl;
        a[i] = i;
    }
    */

    /*
    char arr[10];
    char str[10] = {0};
    for(int i=0; i<=9; ++i)
    {
        str[i] = 'a';
    }
    strcpy(arr, str);
    cout << arr << endl;
    return 0;
    */

//回文数  转化成字符形式，然后在数组中判断首未是否相等
//数组转字符 切记'0'
/*
    int num;
    char temp[20] = {0};
    cout << "please enter a number:" ;
    cin >> num;
    
    int i = 0;
    int j = 0;
    int flag = 1;
    while(num)
    {
        temp[i++] = num%10 + '0';
        num /= 10;
    }
    cout << temp << endl;
    i--;
    int t = i;
    cout << "i = " << i << endl;
    for(j; j<=(t/2); ++j,--i)
    {
        if(temp[j] != temp[i])
        {
            flag = 0;
            break;
        }
    }
    
    if(flag == 1)
    {
        cout << "是回文数" << endl;
    }
    else
    {
        cout << "不是回文数" << endl;
    }
*/






}
