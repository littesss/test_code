#pthread_create() //创建一个新线程
tid , NULL, 函数指针（线程入口函数）， 入口函数的参数
成功 返回0 ， 失败返回错误码，而不是保存在errno

#pthread_join() //等待线程结束
tid , void** vuale

#pthread_exit() //退出线程
在线程的任何时候调用退出函数，保存在value中
