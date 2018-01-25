/*************************************************************************
	> File Name: t.c
	> Created Time: Fri 26 Jan 2018 12:16:54 AM CST
 ************************************************************************/
#include <stdio.h>

typedef struct NUM
{
    int a;
    int b;
}num;

int add(int a, int b)
{
    return a + b;
}

int add1(num *n)
{
    (*n).a = 100;
    (*n).b = 200;
    return (*n).a+(*n).b;
}
/* 全局变量，结构体num */
    num n = {10, 20};

   // n.a = 10;
   // n.b = 20;
/* main函数 */    
int main()
{
    /* 全局变量，必须初始化 */
    
    int sum = 0;
    sum = add(n.a, n.b);
    int sum1 = add1(&n);
    printf("sum = %d\n", sum);
    
    
    printf("n.a = %d, n.b = %d\n", n.a, n.b);
    printf("sum1 = %d\n", sum1);
    printf("n.a = %d, n.b = %d\n", n.a, n.b);

    return 0;
}
