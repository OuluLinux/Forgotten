#ifndef ALGORITHM_HXX
#define ALGORITHM_HXX

#include <new>

#ifndef PRIM_HXX
#include <Prim.hxx>
#endif

namespace Algorithm
{
#line 18 "../../src/Com/Algorithm.fog"
    template < class _1 >
    inline _1 Absolute(const _1& a);
#line 11
    template < class _1 >
    inline const _1& Maximum(const _1& a, const _1& b);
#line 4
    template < class _1 >
    inline const _1& Minimum(const _1& a, const _1& b);
};

namespace Algorithm
{
#line 18
    template < class _1 >
    inline _1 Absolute(const _1& a)
    {
#line 19
        if (a < 0)
            return a * - 1;
        else
            return a;
    };
    
#line 11
    template < class _1 >
    inline const _1& Maximum(const _1& a, const _1& b)
    {
#line 12
        if (a >= b)
            return a;
        else
            return b;
    };
    
#line 4
    template < class _1 >
    inline const _1& Minimum(const _1& a, const _1& b)
    {
#line 5
        if (a < b)
            return a;
        else
            return b;
    };
    
};

#endif
