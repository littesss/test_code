/*************************************************************************
	> File Name: ttt.cpp
	> Author: Littesss 
	> Mail: liushaohua_2017@163.com 
	> Created Time: 2017-10-31T23:29:42 PDT
 ************************************************************************/

#include<iostream>
using namespace std;
//懒汉式 （创建的时候采取new实例）以时间换取空间，线程不安全
class singleton_L
{
    public:
        static singleton_L* getinstance()
        {
            if(instance == NULL)
            {
                instance = new singleton_L();
            }
            return instance;
        }
        
        //实际上在析构函数中析构对象是一种错误的做法,会调用,切是一个死递归,正确做法是创建一个嵌套的析构类
        /*~singleton_L()
        {
            if(instance != NULL)
            {
                delete instance;
                instance = NULL;
            }
        
            cout << "~singleton_L()" << endl;
        }*/
    public:
        class Garbo
        {
            public:
                ~Garbo()
                {
                    if(singleton_L::instance != NULL)
                    {
                        cout << "delete singleton" << endl;
                        delete singleton_L::instance;
                        singleton_L::instance = NULL;
                    }
                }
        };
        static Garbo garbo;
    
    private:
        singleton_L(){}
        static singleton_L*  instance;
};

singleton_L*       singleton_L::instance = NULL;
singleton_L::Garbo singleton_L::garbo;

//饿汉式（在定义实例的时候就去new对象）以空间换时间
class singleton_E
{
    public:
        static singleton_E* getinstance()
        {
            return instance;
        }

       // ~singleton_E(){}
/*        class Garbo
        {
            public:
                ~Garbo()
                {
                    if(singleton_E::instance != NULL)
                    {
                        cout << "delete singleton_E" << endl;
                        delete singleton_E::instance;
                        singleton_E::instance = NULL;
                    }
                }
        };
    */
    private:
        singleton_E(){}
        static singleton_E* instance;
      //  static Garbo ggarbo;
};

singleton_E*       singleton_E::instance = new singleton_E();
//singleton_E::Garbo singleton_E::ggarbo;


int main()
{
    singleton_L *ppp = singleton_L::getinstance();
    singleton_L *p   = singleton_L::getinstance();

    cout << "hello" << endl;
    //delete ppp;
  //  delete p;

    return 0;
}
