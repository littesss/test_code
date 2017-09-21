/*************************************************************************
	> File Name: getopt.cpp
	> Created Time: Tue 12 Sep 2017 20:15:13 PDT
 ************************************************************************/
#include <iostream>
using namespace std;
#include <unistd.h>


int main(int argc, char **argv)
{
    int ret;
    while(-1 != (ret = getopt(argc, argv,"A:")))
    {
        cout << ret << endl;
        switch(ret)
        {
            case 'A':
                cout << "f is set" << endl;
                break;
            default:
                cout << "error" << endl;
                break;
        }
    }
    return  0;
}

