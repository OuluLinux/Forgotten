#ifndef CONTAINER_CXX
#define CONTAINER_CXX

#include <new>

#ifndef CONTAINER_HXX
#include <Container.hxx>
#endif

namespace Container
{
#line 124 "../../src/Com/Container.fog"
    template < class _1 >
    Optional < _1 >::Optional(const Optional& opt)
    :
        obj(0)
    {
#line 124
        if (opt.obj)
#line 124
            this -> obj = new _1(*opt.obj);
    };
    
    template < class _1 >
    Optional < _1 >::Optional(const PickT& n)
    :
        obj(0)
    {
#line 127
        *this = n;
    };
    
#line 125
    template < class _1 >
    Optional < _1 >::Optional(const _1& obj)
    :
        obj(0)
    {
#line 125
        this -> obj = new _1(obj);
    };
    
#line 139
    template < class _1 >
    _1 *Optional < _1 >::operator-> ()
    {
        {
#line 139
            if (!(obj))
            {
#line 139
                Lang::SysBreak("Assertion failed: obj");
            }
        }
#line 139
        ;
#line 139
        return obj;
    };
    
#line 134
    template < class _1 >
    void Optional < _1 >::operator= (const Optional& o)
    {
#line 134
        Clear();
#line 134
        if (!o.IsEmpty())
        {
#line 134
            this -> obj = new _1(*o.obj);
        }
    };
    
#line 135
    template < class _1 >
    void Optional < _1 >::operator= (const PickOpt& n)
    {
#line 135
        Clear();
#line 135
        if (!n.Get().IsEmpty())
        {
#line 135
            Pick(n.Get());
        }
    };
    
#line 136
    template < class _1 >
    void Optional < _1 >::Pick(Optional& o)
    {
#line 136
        obj = o.obj;
#line 136
        o.obj = 0;
    };
    
};

#endif
