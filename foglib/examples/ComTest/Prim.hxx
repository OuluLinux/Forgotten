/*!$@FOG@$!
 *	Generated at Wed Sep 30 06:41:10 2020
 *
 *	by fog 0.1.a of 12:17:36 Sep 29 2020
 *
 *	from
 *		../../src/Com/Abstract.fog
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Container.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Lang.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Meta.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/Prim.fog
 *		../../src/Com/Random.fog
 *		../../src/Com/Shared.fog
 *		../../src/Com/Text.fog
 *		ComTest.mfog
 */

#ifndef PRIM_HXX
#define PRIM_HXX

#include <new>

namespace Prim
{
    template < class _1 >
    struct CPtr
    {
#line 6 "../../src/Com/Prim.fog"
        _1 *value;
        
        inline CPtr();
        inline CPtr(_1 *p);
        inline void operator= (_1 *p);
#line 12
        inline bool operator== (const CPtr& p) const;
        inline bool operator== (void *p) const;
#line 11
        inline operator _1 * () const;
#line 16
        inline unsigned long long Int() const;
    };
};

namespace Prim
{
#line 8
    template < class _1 >
    inline CPtr < _1 >::CPtr()
    :
        value(0)
    {};
    
#line 9
    template < class _1 >
    inline CPtr < _1 >::CPtr(_1 *p)
    :
        value(p)
    {};
    
#line 10
    template < class _1 >
    inline void CPtr < _1 >::operator= (_1 *p)
    {
#line 10
        value = p;
    };
    
#line 12
    template < class _1 >
    inline bool CPtr < _1 >::operator== (const CPtr& p) const
    {
#line 12
        return value == p.value;
    };
    
#line 13
    template < class _1 >
    inline bool CPtr < _1 >::operator== (void *p) const
    {
#line 13
        return(void * ) value == p;
    };
    
#line 11
    template < class _1 >
    inline CPtr < _1 >::operator _1 * () const
    {
#line 11
        return value;
    };
    
#line 16
    template < class _1 >
    inline unsigned long long CPtr < _1 >::Int() const
    {
#line 16
        return(unsigned long long) value;
    };
    
};

#endif
