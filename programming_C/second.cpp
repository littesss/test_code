/*************************************************************************
	> File Name: second.cpp
	> Created Time: Fri 06 Oct 2017 05:54:49 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <string.h>

#define SECOND_OF_YEAR (60*60*24*365)
#define SQR(x) (x*x)
#define MIN(x,y)  ((x)<=(y)? (x) :(y))

void fun(char arr[6]) //数组名字自动降级成指针
{
    cout << "sizeof(arr) = " << sizeof(arr) << endl;
}
int main()
{
    cout << "one year has " << SECOND_OF_YEAR << " second" << endl;
    cout << SQR(3+2+1) << endl;
    cout << "Min(3,2) = " << MIN(3,2) << endl;

    //char arr[]; 必须给出大小
    char arr[6] = "hello"; //sizeof 6
    char arr3[] = {'a','b','c','d','e'};//sizeof 5 strlen 5!
    char arr4[10] = {};

    cout << __LINE__ << endl;
    int arr1[2] = {1,2};
    int arr5[] = {1};
    //int arr1[] = {}
    cout << "sizeof int arr" << sizeof(arr1) << endl;
    cout << "sizeof char arr" << sizeof(arr3) << endl;
    cout << "strlen char arr" << strlen(arr3) << endl;
    cout << (int)arr4[9] << endl;
    cout << sizeof(arr5) << endl;
    cout << "-------------------" << endl;
    cout << sizeof(arr3)/sizeof(arr3[0]) << endl;
    fun(arr);
    int ***** arr7[3][4];
    cout << sizeof(arr7) << endl;//12*8 = 96

    int a;
    /*
    ++10;
    10++;
    a++ =  10;//先把a地址取出来 10 给a, 在++相当于给10++ ，常量能++吗？？？
    */ 
    ++a = 10; //前++ 可以赋值，后++不能赋值

    //  &&逻辑与  &按位与  ||逻辑或 |按位或
    // 0 && 1 = 0    3&4 = 4   && & 与置0
    // 1 || 0 = 1    3|4 = 7   || | 或值1
    

    /* switch（op） 语句  op只有三种形式 整形，字符，或者 枚举*/


    cout << __FILE__ << endl;
    return 0;
}
