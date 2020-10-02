#ifndef PRIM_HXX
#define PRIM_HXX

#include <new>

namespace Prim
{
#line 23 "../../src/Com/Prim.fog"
    template < class _1 >
    inline _1 InlineIf(bool cond, _1 a, _1 b);
    
    template < class _1 >
    struct CPtr
    {
#line 6
        _1 *value;
        
#line 9
        inline CPtr();
        inline CPtr(_1 *p);
        inline void operator= (_1 *p);
#line 13
        inline bool operator== (const CPtr& p) const;
        inline bool operator== (void *p) const;
#line 12
        inline operator _1 * () const;
#line 17
        inline unsigned long long Int() const;
    };
};

namespace Prim
{
    template < class _1 >
    inline _1 InlineIf(bool cond, _1 a, _1 b)
    {
#line 24
        if (cond)
            return a;
        else
            return b;
    };
    
#line 9
    template < class _1 >
    inline CPtr < _1 >::CPtr()
    :
        value(0)
    {};
    
#line 10
    template < class _1 >
    inline CPtr < _1 >::CPtr(_1 *p)
    :
        value(p)
    {};
    
#line 11
    template < class _1 >
    inline void CPtr < _1 >::operator= (_1 *p)
    {
#line 11
        value = p;
    };
    
#line 13
    template < class _1 >
    inline bool CPtr < _1 >::operator== (const CPtr& p) const
    {
#line 13
        return value == p.value;
    };
    
#line 14
    template < class _1 >
    inline bool CPtr < _1 >::operator== (void *p) const
    {
#line 14
        return(void * ) value == p;
    };
    
#line 12
    template < class _1 >
    inline CPtr < _1 >::operator _1 * () const
    {
#line 12
        return value;
    };
    
#line 17
    template < class _1 >
    inline unsigned long long CPtr < _1 >::Int() const
    {
#line 17
        return(unsigned long long) value;
    };
    
};

#endif
