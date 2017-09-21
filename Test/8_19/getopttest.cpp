/*************************************************************************
	> File Name: getopttest.cpp
	> Created Time: Sat 19 Aug 2017 16:07:47 PDT
 ************************************************************************/
#include <iostream>
using namespace std;

#include <unistd.h>

#include <stdlib.h>
int main(int argc,char * argv[])
{
   // opterr = 0;//don't use default error 
    int ret;
    char * year;
    char  error;
     while((ret = getopt(argc,argv,":lsh:")) != -1)//""first :
     {
        switch(ret)
        {
            case 'l':
                cout << "I am liushaohu" << endl;
                break;
            case 's':
                cout << "I am from china" << endl;
                break;
            case 'h':
                year = optarg ;
                cout << "i am " << year << endl;
                break;
            case '?':
                error = optopt;
                cout << "无效参数"<< error << endl;
                break;
            case ':':
                cout << "缺少命令行！" << endl;
                break;
            default:
                cout << "error !!!" << endl;
                break;
        }
     }
    return 0;
}
