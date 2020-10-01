/*!$@FOG@$!
 *	Generated at Thu Oct  1 09:26:12 2020
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
 *		../../src/Com/Util.fog
 *		ComTest.mfog
 */

#ifndef HASH_CXX
#define HASH_CXX

#include <new>

#ifndef HASH_HXX
#include <Hash.hxx>
#endif

namespace Hash
{
#line 12 "../../src/Com/Hash.fog"
    Combine::Combine(int v0, int v1)
    :
        hash(123456789)
    {
#line 12
        Put(v0);
#line 12
        Put(v1);
    };
    
#line 17
    Combine& Combine::Put(int value)
    {
#line 17
        hash = ((hash << 5) + hash) + value;
#line 17
        return *this;
    };
    
#line 18
    Combine& Combine::Put64(Lang::int64 value)
    {
#line 18
        Put((int)(value >> 32));
#line 18
        Put((int)(value & 0xFFFFFFFFULL));
#line 18
        return *this;
    };
    
};

#endif
