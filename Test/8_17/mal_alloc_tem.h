#if 0
#include <new>
#define __THROW_BAD_ALLOC throw bad_alloc
#elif !define(__THROW_BAD_ALLOC)
#include <iostream.h>
#define __THROW_BAD_ALLOC cerr << "Out of memory!" << endl; exit(1)
#endif

//一级空间配置器 malloc realloc free
template <int inst>
class __malloc_alloc_template
{
private:
    static void *oom_malloc(size_t);
    static void *oom_realloc(void * ,size_t);
    static void ( * malloc_alloc_template)();
public:
    static void * allocate(size_t n) // malloc
    {
        void * result = malloc(n);
        if(0 == result)
        {
            result = oom_malloc(n);
        }
        return result;
    }

    static void deallocate(void *p, size_t )
    {
        free(p);
    }

    static void * reallocate(void *p,size_t , size_t new_sz)
    {
        void * result = realloc(p,new_sz);
        if(0 == result)
        {
            result = oom_realloc(p,new_sz);
        }
        return result;
    }
    
    //set_new_handler()
    static void( *set_malloc_handler(void (*f)()))()
    {
        void (* old)() = __malloc_alloc_oom_handler;
        __malloc_alloc_oom_handler = f;
        return (old);
    }
};
//mallco_alloc out_of_memory handler
template <int inst>
void (* __malloc_alloc_templa<inst> :: __malloc_alloc_oom_hannler)() = 0;

template <int inst>
void * __malloc_alloc_template<inst>::oom_malloc(size_t n)
{
    void (* my_malloc_handler)();
    void * result;
    for (;;)
    {
        my_malloc_handler = __malloc_alloc_oom_handler;
        if( 0 == my_malloc_handler)
        {
            __THROW_BAD_ALLOC;
        }
        (*my_malloc_handler)();

        result = malloc(n);
        if(result)
            return(result);
    }
}
template <int inst>
void * __malloc_alloc_template<inst>::oom_realloc(void *p,size_t n)
{
    void (* my_malloc_handler)();
    void *result;

    for(;;)
    {
        my_malloc_handler = __malloc_alloc_oom_handler;
        if(0  == my_malloc_handler)
        {
            __THROW_BAD_ALLOC;
        }
        (*my_malloc_handler)();
        result = realloc(p,n);
        if(result)
            return(result);
    }
}



