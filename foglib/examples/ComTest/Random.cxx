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

#ifndef RANDOM_CXX
#define RANDOM_CXX

#include <new>

#ifndef RANDOM_HXX
#include <Random.hxx>
#endif

namespace Random
{
#line 49 "../../src/Com/Random.fog"
    double Generator::Randomd()
    {
#line 49
        return(sNext(state) >> 11) * (1. / (((Lang::uint64)1) << 53));
    };
    
#line 48
    float Generator::Randomf()
    {
#line 48
        return(sNext(state) >> 11) * (1.f / (((Lang::uint64)1) << 53));
    };
    
#line 54
    void Generator::Seed(Lang::dword seed)
    {
#line 55
        for (int i = 0; i < 4; i ++ )
            state[i] = 12345678 + seed + i;
    };
    
#line 18
    Lang::uint64 Generator::sNext(Lang::uint64 *s)
    {
#line 19
        const Lang::uint64 result_starstar = s_rotl(s[1] * 5, 7) * 9;
        const Lang::uint64 t = s[1] << 17;
#line 22
        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];
#line 27
        s[2] ^= t;
#line 29
        s[3] = s_rotl(s[3], 45);
#line 31
        return result_starstar;
    };
    
    void Generator::sSeed(Lang::uint64 *s)
    {
#line 35
        for (int pass = 0; pass < 4; pass ++ )
            {
#line 36
                for (int i = 0; i < 4; i ++ )
                    {
#line 37
                        Hash::Combine h;
                        h.Put64(Native::CurrentTime());
                        h.Put64(Native::NanoSeconds());
                        h.Put64(Native::MilliSeconds());
                        s[i] ^= h;
                    }
            }
    };
    
#line 14
    Lang::uint64 Generator::s_rotl(const Lang::uint64 x, int k)
    {
#line 15
        return(x << k) | (x >> (64 - k));
    };
    
};

#endif
