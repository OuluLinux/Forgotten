#ifndef RANDOM_CXX
#define RANDOM_CXX

#include <new>

#ifndef RANDOM_HXX
#include <Random.hxx>
#endif

namespace Random
{
#line 46 "../../src/Com/Random.fog"
    double Generator::Randomd()
    {
#line 46
        return(sNext(state) >> 11) * (1. / (((Lang::uint64)1) << 53));
    };
    
#line 45
    float Generator::Randomf()
    {
#line 45
        return(sNext(state) >> 11) * (1.f / (((Lang::uint64)1) << 53));
    };
    
#line 51
    void Generator::Seed(Lang::dword seed)
    {
#line 52
        for (int i = 0; i < 4; i ++ )
            state[i] = 12345678 + seed + i;
    };
    
#line 15
    Lang::uint64 Generator::sNext(Lang::uint64 *s)
    {
#line 16
        const Lang::uint64 result_starstar = s_rotl(s[1] * 5, 7) * 9;
        const Lang::uint64 t = s[1] << 17;
#line 19
        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];
#line 24
        s[2] ^= t;
#line 26
        s[3] = s_rotl(s[3], 45);
#line 28
        return result_starstar;
    };
    
    void Generator::sSeed(Lang::uint64 *s)
    {
#line 32
        for (int pass = 0; pass < 4; pass ++ )
            {
#line 33
                for (int i = 0; i < 4; i ++ )
                    {
#line 34
                        Hash::Combine h;
                        h.Put64(Native::CurrentTime());
                        h.Put64(Native::NanoSeconds());
                        h.Put64(Native::MilliSeconds());
                        s[i] ^= h;
                    }
            }
    };
    
#line 11
    Lang::uint64 Generator::s_rotl(const Lang::uint64 x, int k)
    {
#line 12
        return(x << k) | (x >> (64 - k));
    };
    
};

#endif
