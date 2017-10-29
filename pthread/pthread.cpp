/*************************************************************************
	> File Name: pthread.cpp
	> Created Time: Mon 23 Oct 2017 09:29:51 PM CST
 ************************************************************************/
#include <iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <pthread.h>

void* thread(void*)
{
    for(int i=0; i<20; ++i)
    {
        cout << "B";
        fflush(stdout);
        usleep(20);
        if(i == 3)
        {
            const char *arr = "hello";
            int arr1 =3;
            //cout << "char*:" << arr << endl;
           // pthread_exit(&arr);
        }
    } 
    sleep(1);
    
    
    return (int*)3;
}
int main()
{
    pthread_t tid;

    int ret = pthread_create(&tid, NULL, thread, NULL);
    if(ret != 0)
    {
        fprintf(stderr, "pthread_create:%d\n", ret);
        exit(EXIT_FAILURE);
    }
 
    //sleep(1); 
    void *value; 
    for(int i=0; i<20; ++i)
    {
        cout << "A";
        fflush(stdout);
        usleep(20);
    }

    cout << endl;
    
    ret = pthread_join(tid, &value); 
    if(ret != 0)
    {
        fprintf(stdout, "pthread_join:%d\n", ret);
        exit(1);
    } 
    cout << "value :" << (int*)value << endl;
    printf("return value:%d\n", (int* )value);
    return 0;
}
