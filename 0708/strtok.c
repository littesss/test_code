/*************************************************************************
	> File Name: strtok.c
	> Created Time: Sun 08 Jul 2018 11:44:30 AM CST
 ************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
//	char *arr = "12/0.2/12.22/13/"; //core dump 字符串在常量区，而strtok会破坏源字符串
	char arr[] = "12/0.2/12.22/13/";
	char *save = NULL;
	char *token = NULL;

	token = strtok(arr, "/");
	printf("strtok():[%s]\n", token);
    return 0;
}


