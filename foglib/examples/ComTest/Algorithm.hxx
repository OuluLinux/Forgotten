/*!$@FOG@$!
 *	Generated at Wed Sep 30 12:25:17 2020
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
 *		../../src/Com/Stream.fog
 *		../../src/Com/Text.fog
 *		ComTest.mfog
 */

#ifndef ALGORITHM_HXX
#define ALGORITHM_HXX

#include <new>

namespace Algorithm
{
#line 11 "../../src/Com/Algorithm.fog"
    template < class _1 >
    inline const _1& Maximum(const _1& a, const _1& b);
#line 4
    template < class _1 >
    inline const _1& Minimum(const _1& a, const _1& b);
};

namespace Algorithm
{
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
