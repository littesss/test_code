/*************************************************************************
> File Name: singleton.cpp
> Author: Littesss 
> Mail: liushaohua_2017@163.com 
> Created Time: 2017-10-31T01:24:27 PDT
************************************************************************/

#include<iostream>
using namespace std;

//懒汉式：不初始化，需要的时候才创建对象
class singleton
{
    public:
    static  void fun()
    {
        cout << "here" << endl;
    }
    static singleton* create()
    {
        if(instance == NULL)
        {
            instance = new singleton;
          //instance = new singleton(); //理解为构造singleton类的一个无惨构造
        }
        return instance;
    }
    ~singleton()
    {
        if(instance != NULL)
        {
            delete instance;
            instance = NULL;
        }
    }
   
    private:
    singleton(){}               //construction func is private 
    static singleton* instance; //指向父类的的一个静态全局实例

};

//静态数据成员必须在类外初始化
singleton* singleton::instance = NULL;

int main()
{
    singleton* p0 = singleton::create();
    singleton* p1 = singleton::create();
    singleton* p2 = singleton::create();
    singleton* p3 = singleton::create();

    cout << "p0:" << p0 << endl;
    cout << "p1:" << p1 << endl;
    cout << "p2:" << p2 << endl;
    cout << "p3:" << p3 << endl;

    singleton::fun();

    cout << "hello" << endl;
    return 0;
}
