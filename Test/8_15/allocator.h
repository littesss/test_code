#ifndef __ALLOCATOR_H
#define __ALLOCATOR_H

#include <new> // placement new
#include <iostream> //cerr
#include <stdlib.h> // exit
#include <stdio.h>
#include <cstddef>
#include <climits>
namespace JJ
{
    template <typename _Ty>
    _Ty* _allocate(size_t size,_Ty*)
    {
         printf("opertor new\n"); 
        _Ty * temp = NULL;
        if(size < 0)
            size = 0; 
        temp = (_Ty*)(operator new(size*sizeof(_Ty)));       
        if(temp == 0)
        {
            perror("Out of Memory");

            //cerr << "Out of Mermory !!!" << endl;
            exit(1);
        }
        return temp;
    }

    template <typename _Ty1,typename _Ty2>
    void _construct(_Ty1 *p ,const _Ty2 & value )
    {
        new(p) _Ty1(value);  // placement new
    }

    template <typename _Ty>
    void _deallocate(_Ty * p)
    {
        operator delete(p);
    }

    template <typename _Ty>
    void _destroy(_Ty * p)
    {
        p->~_Ty();
    }


    template <typename _Ty>
    class allocator
    {
    public:
        typedef _Ty         value_type;
        typedef _Ty*        pointer;
        typedef const _Ty*  const_pointer;
        typedef _Ty&        reference;
        typedef const _Ty&  const_reference;
        typedef size_t      size_type;
        typedef ptrdiff_t   difference_type;
        // template <class U>
    public:
        pointer allocate(size_type n,const void* hint=0)
        {
         printf("allocate (n, void*)\n"); 
            return _allocate((difference_type)n,(pointer)0);
        }

        void deallocate(pointer p, size_t  n)
        {
            _deallocate(p);
        }

        void construct(pointer p, const _Ty& value)
        {
            _construct(p, value);
        }

        void destroy(pointer p)
        {
            _destroy(p);
        }

    };

}

#endif
