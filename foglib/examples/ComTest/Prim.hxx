#ifndef PRIM_HXX
#define PRIM_HXX

#include <new>

namespace Prim
{
#line 35 "../../src/Com/Prim.fog"
    template < class _1 >
    inline _1 InlineIf(bool cond, _1 a, _1 b);
    
    template < class _1 >
    struct CPtr
    {
#line 18
        _1 *value;
        
#line 21
        inline CPtr();
        inline CPtr(_1 *p);
        inline void operator= (_1 *p);
#line 25
        inline bool operator== (const CPtr& p) const;
        inline bool operator== (void *p) const;
#line 24
        inline operator _1 * () const;
#line 29
        inline unsigned long long Int() const;
    };
    
    template < class _1 >
    struct CRef
    {
#line 6
        _1& value;
        
#line 9
        inline CRef();
        inline CRef(_1& r);
        inline CRef(const CRef& r);
#line 14
        inline bool operator== (const CRef& p) const;
#line 12
        inline operator _1 & () const;
        inline _1& Get() const;
    };
};

namespace Prim
{
#line 35
    template < class _1 >
    inline _1 InlineIf(bool cond, _1 a, _1 b)
    {
#line 36
        if (cond)
            return a;
        else
            return b;
    };
    
#line 21
    template < class _1 >
    inline CPtr < _1 >::CPtr()
    :
        value(0)
    {};
    
#line 22
    template < class _1 >
    inline CPtr < _1 >::CPtr(_1 *p)
    :
        value(p)
    {};
    
#line 23
    template < class _1 >
    inline void CPtr < _1 >::operator= (_1 *p)
    {
#line 23
        value = p;
    };
    
#line 25
    template < class _1 >
    inline bool CPtr < _1 >::operator== (const CPtr& p) const
    {
#line 25
        return value == p.value;
    };
    
#line 26
    template < class _1 >
    inline bool CPtr < _1 >::operator== (void *p) const
    {
#line 26
        return(void * ) value == p;
    };
    
#line 24
    template < class _1 >
    inline CPtr < _1 >::operator _1 * () const
    {
#line 24
        return value;
    };
    
#line 29
    template < class _1 >
    inline unsigned long long CPtr < _1 >::Int() const
    {
#line 29
        return(unsigned long long) value;
    };
    
#line 9
    template < class _1 >
    inline CRef < _1 >::CRef()
    :
        value(0)
    {};
    
#line 10
    template < class _1 >
    inline CRef < _1 >::CRef(_1& r)
    :
        value(r)
    {};
    
#line 11
    template < class _1 >
    inline CRef < _1 >::CRef(const CRef& r)
    :
        value(r.value)
    {};
    
#line 14
    template < class _1 >
    inline bool CRef < _1 >::operator== (const CRef& p) const
    {
#line 14
        return&value == &p.value;
    };
    
#line 12
    template < class _1 >
    inline CRef < _1 >::operator _1 & () const
    {
#line 12
        return value;
    };
    
#line 13
    template < class _1 >
    inline _1& CRef < _1 >::Get() const
    {
#line 13
        return value;
    };
    
};

#endif
