/*************************************************************************
	> File Name: 1.h
	> Created Time: Tue 05 Sep 2017 18:10:53 PDT
 ************************************************************************/
#ifndef _1_H
#define _1_H
#include <iostream>
using namespace std;

class A
{
    public:
        A(int aa=11, int bb=22);
    private:
        int a;
};
A::A(int aa, int bb)
{
    this->a = aa;

    cout << "aa" << aa << endl;
    cout << "bb" << bb << endl;
    cout << "construction" << endl;
}

#endif
