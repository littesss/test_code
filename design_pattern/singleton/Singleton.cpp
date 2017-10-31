/*************************************************************************
	> File Name: Singleton.cpp
	> Created Time: Tue 31 Oct 2017 10:20:58 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;
#include <pthread.h>

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
        /*~singleton_L()
        {
            /*
            if(instance != NULL)
            {
                delete instance;
                instance = NULL;
            }
        
            cout << "~singleton_L()" << endl;
        }*/
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
    private:
        singleton_L(){}
        static singleton_L*  instance;
        static Garbo garbo;
};

singleton_L*  singleton_L::instance = NULL;
singleton_L::Garbo singleton_L::garbo;

//饿汉式（在定义实例的时候就去new对象）以空间换时间
class singleton_E
{
    public:
        static singleton_E* getinstance()
        {
            return instance;
        }

        ~singleton_E(){}
    private:
        singleton_E(){}
        static singleton_E* instance;
};

singleton_E* singleton_E::instance = new singleton_E();

//懒汉式 线程安全式（双检锁）
/*
  所谓双重检查加锁机制，指的是：并不是每次进入getInstance方法都需要同步，而是先不
同步，进入方法过后，先检查实例是否存在，如果不存在才进入下面的同步块，这是第一重
检查。进入同步块过后，再次检查实例是否存在，如果不存在，就在同步的情况下创建一个
实例，这是第二重检查。这样一来，就只需要同步一次了，从而减少了多次在同步情况下进
行判断所浪费的时间。
*/
class singleton_L_Lock
{
    public:
        static singleton_L_Lock* getinstance()
        {
            if(instance == NULL)
            {
                pthread_mutex_lock(&mutex);
                if(instance == NULL)
                    instance = new singleton_L_Lock();
                pthread_mutex_unlock(&mutex);
            }
            return instance;
        }
        ~singleton_L_Lock()
        {
           /*
            if(instance != NULL)
            {
                delete instance;
                instance = NULL;
            }
            */
        }
    public:
        static pthread_mutex_t mutex;
    private:
        singleton_L_Lock()
        {
            pthread_mutex_init(&mutex, NULL);
        }
    private:
        static singleton_L_Lock*  instance;
};

singleton_L_Lock* singleton_L_Lock::instance = NULL;
pthread_mutex_t   singleton_L_Lock::mutex;  

int main()
{
    singleton_L* p  = singleton_L::getinstance();
    singleton_L* p1 = singleton_L::getinstance();
    singleton_L* p2 = singleton_L::getinstance();

    cout << p  << endl;
    cout << p1 << endl;
    cout << p2 << endl;
    delete p2;
    cout << "=================" << endl;
    singleton_E* E  = singleton_E::getinstance();
    singleton_E* E1 = singleton_E::getinstance();
    singleton_E* E2 = singleton_E::getinstance();

    cout << E  << endl;
    cout << E1 << endl;
    cout << E2 << endl;

    cout << "=================" << endl;
    singleton_L_Lock* L  = singleton_L_Lock::getinstance();
    singleton_L_Lock* L1 = singleton_L_Lock::getinstance();
    singleton_L_Lock* L2 = singleton_L_Lock::getinstance();

    cout << L  << endl;
    cout << L1 << endl;
    cout << L2 << endl;
    
    return 0;
}
