/*************************************************************************
	> File Name: change.cpp
	> Created Time: Sat 16 Sep 2017 11:48:32 PDT
 ************************************************************************/
#include <iostream>
using namespace std;
#include <fstream>
#include <stdio.h>


int main()
{
    string file1("1");
    string file2("2");
//    char buff[256];

    string buff;
   // char* buff;
    fstream fin("1");
    while(!fin.eof())
    {
        getline(fin,buff);
        cout << buff << endl;
    }
fin.close();
    return 0;
}

