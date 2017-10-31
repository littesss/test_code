/*************************************************************************
  > File Name: question.cpp
  > Created Time: Tue 31 Oct 2017 11:48:34 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

class A
{
    private:
        static A *m_p;

    public:
        static A *getSingleTon()
        {
            if(NULL == m_p)
            {
                m_p = new A();

            }

            return m_p;

        }


/*        ~A()
        {
            if(NULL != m_p)
            {
                cout << "xxx" << endl;

                delete m_p; // 递归调用析构
                m_p = NULL;

                cout << "yyy" << endl; // 永远也不会执行

            }

        }
*/
};

A* A::m_p = NULL;


int main()
{
    A *p = A::getSingleTon();
    delete p;

    return 0;

}

