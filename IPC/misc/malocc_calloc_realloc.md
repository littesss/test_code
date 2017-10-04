malloc  realloc calloc
1. malloc
    void *malloc(size_t size);
    void free(void *ptr);
    开辟多大的空间，成功返回连续空间的指针，失败返回NULL
    malloc 开辟的必须free 释放，否则内存泄露，要预防野指针

2. realloc
    void *realloc(void *ptr, size_t size);
    动态内存调整，成功返回连续空间指针，失败返回NULL

3. calloc
    void *calloc(size_t nmemb, size_t size);
    开辟n个大小为size的连续空间，并且初始化为0
    calloc 开辟 free 释放

new 操作符 malloc realloc calloc 是C语言的运行时库
new delete /  delete [] p   p = NULL;
(void* )malloc(n)   free(ptr)  ptr = NULL;
