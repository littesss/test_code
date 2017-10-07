/*************************************************************************
	> File Name: quanju.cpp
	> Created Time: Sat 07 Oct 2017 02:29:54 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#define call(a,b) a##b
#define A(a)  #a
#define p(x) (x*x)
int aaa=3;
static int b;

union 
{
    int i;
    char x[2];
}a;
int main()
{
//# 字符串  ## 连接字符
/*
    int m = 3, n = 2 ,mn=9;
    cout << (m+n+call(m,n)) << endl;//连接成一个整体
    cout << A(10) << endl; // 字符串处理
*/

// union联合体是共用一个空间，以最大的作为空间，小段 小小
/* 
    a.x[0] = 10;
    a.x[1] = 1;
    cout << a.i << endl; // 256+10 = 266
*/

    /*
    int a = 10;
    int b;
    ::a++;
    cout << ::a << endl;
    cout << a << endl;
    b++;
    cout << b << endl;
    cout << ::b<< endl;
    */

//c语言唯一一个三目运算符   表达式0？表达式1“：表达式2
    //表达式0是1 输出表达式1，否则输出 表达式2
    /*int i=3,j=4;
    i?i++:++j;
    cout << i << endl;
    cout << j << endl;
    */
//unsigned int + int ---->转换成unsigned int
   /* unsigned int a =6;
    int b = -20;
    cout << a+b << endl;
    */

//短路操作
/*
    int a = 3 ,b =10;
    ++a && !b;
    cout << "a:" << a << endl;// 4
    cout << "b:" << b << endl;// 10
*/

//i++的时机
/*
    int i=3, j, k;
    cout << i++ << " | " << i << " | " << i << endl;//当i++先用完之后就会自+了
    cout << i++ * i++ << endl;
   // cout << p(3) << endl;
    cout << i << endl;
    j = p(i++); // p(i++*i++)
    cout << i << endl;
    //k = p(++i);
    cout << j << endl;
    cout << k << endl;
*/

//不使用变量交换两数
/*
    int a=-1, b=2;
    a = a^b; //  001 ^ 010 = 011  a=3
    b = a^b; //  011 ^ 010 = 001  b=1
    a = a^b; //  011 ^ 001 = 010  a=2
    cout << a << endl;
    cout << b << endl;
*/


//float 不能精确存储 
    float a = 0;
    if((a<0.000001) && (a>-0.000001))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }
   /* float aa = 0.0001; 
    if(aa == 0)
    {
       cout << "yes" << endl; 
    }
    else
        cout << "no" << endl;
    */
    return 0;
}
