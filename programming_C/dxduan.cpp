/*************************************************************************
  > File Name: dxduan.cpp
  > Created Time: Sun 08 Oct 2017 04:22:33 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

int BitCount1(unsigned int n)
{
    unsigned int c =0 ; // 计数器
    for (c =0; n; n >>=1) // 循环移位
        c += n &1 ; // 如果当前位是1，则计数器加1
    return c ;

}
int main()
{
    //判断大小端
    /*
       int a = 1;
       char * p;
       p = (char* ) &a;
       if(p == NULL)
       {
       cout << "大端" << endl;
       }
       else
       {
       cout << "小端" << endl;
       }
       */

//统计二进制数中的1

/*    int count = 0;
    int number = 7;
    while(number)
    {
        number = number & (number-1); // 清除最低位的1
        count++;
    }
    int number1 = 3;
    int count1 = 0;
    while(number1 + 1)
    {
        count1++;
        number1 |= (number1+1);
    }
    cout << count << endl;
    cout << count1 << endl;
    cout << BitCount1(7) << endl;
*/

//八进制
/*
    cout<< (12& 012) << endl; //1100 & 01010
*/

//2的n次方 2^16 =  65536

/*
    cout << (1<<16) << endl;
    return 0;
*/
//判断奇偶
/*
    cout << ((2&1) == 1 )<< endl;
*/
//m位置0 ，第3位置0
/*
    int m = 15;
    cout <<( m & (~(1<<3))) << endl;
*/

    cout << (1<<2)-1 << endl;

}
