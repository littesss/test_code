/*************************************************************************
	> File Name: reverse.cpp
	> Created Time: Thu 28 Sep 2017 10:26:19 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <string.h>
int main()
{
    const char * str = "hello";
    char arr[6];
    strcpy(arr, str);
    int high = 4;
    int low = 0;
    while(low <= high)
    {
        char temp = arr[low];
        arr[low++] = arr[high];
        arr[high--] = temp;
    } 


    /*for(int i=4; i>0; --i)
    {
        char temp = arr[i];
        arr[i] = arr[i-1];
        arr[i-1] = temp;
    }*/
    cout << "arr reserve:" << arr << endl;
    return 0;
}
