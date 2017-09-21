#include<iostream>
using namespace std;
#include<malloc.h>

class A
{
public:
    A(int a = 0){cout << "A construction" << endl;}
private:
    int m_a;
};

void *operator new(size_t n)// return must be void*
{
    void *p = malloc(n);

    cout<<"operator new"<<endl;
    return p;
}
int main()
{
    A* ptr = new A;
    //int * p = new int;
    //new(p)  int(10);
    //cout << *p << endl;
    
    int * arr = new int[10];
    new(arr+4) int(10);
    for(int i=0; i<10 ;++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
