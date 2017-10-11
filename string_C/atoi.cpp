/*************************************************************************
	> File Name: atoi.cpp
	> Created Time: Mon 09 Oct 2017 11:10:16 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    const char *str = "123456";
    int sum = 0;
    int i = 0;

    while(str[i])
    {
        sum = sum*10 + (str[i++]-'0');
    }
    cout << sum << endl;
    return 0;
}
