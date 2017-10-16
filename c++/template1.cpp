/*************************************************************************
	> File Name: template1.cpp
	> Created Time: Mon 16 Oct 2017 10:51:06 AM CST
 ************************************************************************/
#include <iostream>
using namespace std;

template <typename T>
class A
{
    friend ostream& operator<<(ostream& out, A& a)
    {
        out << a.m_i;
    }
    public:
        A(T i)
        {
            m_i = i;
        }
        void print();
        //{
        //    cout << ++this->m_i << endl;
        //}
    private:
        T m_i;

};

//模板类的成员函数属于模板函数
template <typename T>
void A<T>::print()
{
    cout << ++m_i << endl;
}
int main()
{
    A<char> a('a');
    a.print();
    cout << a << endl;
    char b = 66;
    cout << b << endl;
    return 0;
}
