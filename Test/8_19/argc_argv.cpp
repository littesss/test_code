/*************************************************************************
	> File Name: argc_argv.cpp
	> Created Time: Sat 19 Aug 2017 08:17:18 PDT
 ************************************************************************/
#include<iostream>
using namespace std;

int main(int argc, char *argv[])
{
    for(int i=0; i<10; ++i)
    {
        cout << argv[i] << endl;
    }
    cout << "why ?" << endl;
    cout << "argc :" <<argc << endl;
    return 0;
}
