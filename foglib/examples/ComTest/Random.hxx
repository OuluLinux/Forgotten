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

#ifndef RANDOM_HXX
#define RANDOM_HXX

#include <new>

#ifndef NATIVE_HXX
#include <Native.hxx>
#endif
#ifndef HASH_HXX
#include <Hash.hxx>
#endif

namespace Random
{
#line 70 "../../src/Com/Random.fog"
    inline double Double();
#line 69
    inline float Float();
#line 65
    inline Lang::dword Int();
    inline Lang::uint64 Int64();
    inline Lang::dword Range(Lang::dword n);
    inline Lang::uint64 Range64(Lang::uint64 n);
#line 71
    inline void Seed();
    
    class Generator
    {
#line 12
        Lang::uint64 state[4];
        
    public:
#line 47
        inline Generator();
#line 52
        inline operator Lang::uint64();
#line 51
        inline Lang::uint64 Get();
#line 50
        inline Lang::uint64 Random(Lang::uint64 max);
#line 49
        double Randomd();
#line 48
        float Randomf();
#line 53
        inline void Seed();
        void Seed(Lang::dword seed);
        
#line 18
        Lang::uint64 sNext(Lang::uint64 *s);
#line 34
        void sSeed(Lang::uint64 *s);
#line 14
        Lang::uint64 s_rotl(const Lang::uint64 x, int k);
        
    public:
#line 59
        inline static Generator& Local();
    };
};

namespace Random
{
#line 70
    inline double Double()
    {
#line 70
        return Generator::Local().Randomd();
    };
    
#line 69
    inline float Float()
    {
#line 69
        return Generator::Local().Randomf();
    };
    
#line 65
    inline Lang::dword Int()
    {
#line 65
        return Generator::Local().Random(4294967295U);
    };
    
#line 66
    inline Lang::uint64 Int64()
    {
#line 66
        return Generator::Local().Get();
    };
    
#line 67
    inline Lang::dword Range(Lang::dword n)
    {
#line 67
        return Generator::Local().Random(n);
    };
    
#line 68
    inline Lang::uint64 Range64(Lang::uint64 n)
    {
#line 68
        return Generator::Local().Random(n);
    };
    
    inline void Seed()
    {
#line 71
        return Generator::Local().Seed();
    };
    
#line 47
    inline Generator::Generator()
    {
#line 47
        Seed();
    };
    
#line 52
    inline Generator::operator Lang::uint64()
    {
#line 52
        return Get();
    };
    
#line 51
    inline Lang::uint64 Generator::Get()
    {
#line 51
        return sNext(state);
    };
    
#line 59
    inline Generator& Generator::Local()
    {
#line 59
        static thread_local Generator r;
#line 59
        return r;
    };
    
#line 50
    inline Lang::uint64 Generator::Random(Lang::uint64 max)
    {
#line 50
        return Get() % max;
    };
    
    inline void Generator::Seed()
    {
#line 53
        sSeed(state);
    };
    
};

#endif
