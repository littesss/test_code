/*************************************************************************
	> File Name: getopt.cpp
	> Created Time: Sun 20 Aug 2017 13:10:30 PDT
 ************************************************************************/
#include <iostream>
using namespace std;

#include <unistd.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
//    opterr = 0;
    int res;
    int year;
    while((res = getopt(argc, argv,":lsh:")) != -1)
    {
        switch(res)
        {
            case 'l':
                cout << "i am liushao" << endl;
                break;
            case 's':
                cout << "i am from China" << endl;
                break;
            case 'h':
                year = atoi(optarg) ;
                cout << "i am " << year << " old" << endl;
                break;
            case '?':
                cout <<(char) optopt << "无效参数！" << endl;
                break;
            case':':
                cout << "缺少参数 ！！" << endl;
                break;
            default:
               cout << "error" << endl; 
               break;
        }

    }
    return 0;
}
