/*************************************************************************
	> File Name: int_to_a.cpp
	> Created Time: Mon 09 Oct 2017 10:53:18 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    char temp[20];
    char arr[20];
    int i = 0;
    int j = 0;

    int num = 123456;
    do
    {
        temp[i++] = '0' + num%10;
        num /= 10;
    }while(num);
    temp[i] = '\0';

    while(i>0)
    {
        i--;
        arr[j++] = temp[i];
    }
    arr[j] = 0;

    int k = 0;
    while(arr[k])
    {
        cout << arr[k++] << endl;
    }
    cout << arr << endl;
    return 0;
}
