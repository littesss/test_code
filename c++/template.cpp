/*************************************************************************
  > File Name: template.cpp
  > Created Time: Sat 14 Oct 2017 04:29:25 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

template<class T>
class Array
{
    private:
        T* elems;
        int size;
    public:
        Array(int s);
        ~Array();
        T& operator[](int);
        void operator=(T);
};

template <class T>
Array<T>::Array(int s)
{
    size = s;
    elems = new T[size];
    if(elems != NULL)
    {
        for(int i=0; i<size; i++)
        {
            elems[i] = 0;
        }
    }
}

template <class T>
Array<T>::~Array()
{
    if(elems != NULL)
    {
        delete []elems;
    }
}

template<class T>
T& Array<T>::operator[](int index)
{
    return elems[index];
}

template<class T>
void Array<T>::operator=(T temp)
{
    for(int i=0; i<size; i++)
    {
        elems[i] = temp;
    }
}

int main()
{
    int i,n=10;
    Array<int> arr1(n);
    Array<int> arr2(n);
    for(i=0; i<n; i++)
    {
        arr1[i]=10+i;
        arr2[i]='a'+i;
    }
    for(i=0; i<n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    arr1 = 20;
    for(i=0; i<n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    arr2 = 'C';
    for(i=0; i<n; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}
