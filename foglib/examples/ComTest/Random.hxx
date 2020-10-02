#ifndef RANDOM_HXX
#define RANDOM_HXX

#include <new>

#ifndef HASH_HXX
#include <Hash.hxx>
#endif

namespace Random
{
#line 67 "../../src/Com/Random.fog"
    inline double Double();
#line 66
    inline float Float();
#line 62
    inline Lang::dword Int();
    inline Lang::uint64 Int64();
    inline Lang::dword Range(Lang::dword n);
    inline Lang::uint64 Range64(Lang::uint64 n);
#line 68
    inline void Seed();
    
    class Generator
    {
#line 9
        Lang::uint64 state[4];
        
    public:
#line 44
        inline Generator();
#line 49
        inline operator Lang::uint64();
#line 48
        inline Lang::uint64 Get();
#line 47
        inline Lang::uint64 Random(Lang::uint64 max);
#line 46
        double Randomd();
#line 45
        float Randomf();
#line 50
        inline void Seed();
        void Seed(Lang::dword seed);
        
#line 15
        Lang::uint64 sNext(Lang::uint64 *s);
#line 31
        void sSeed(Lang::uint64 *s);
#line 11
        Lang::uint64 s_rotl(const Lang::uint64 x, int k);
        
    public:
#line 56
        inline static Generator& Local();
    };
};

namespace Random
{
#line 67
    inline double Double()
    {
#line 67
        return Generator::Local().Randomd();
    };
    
#line 66
    inline float Float()
    {
#line 66
        return Generator::Local().Randomf();
    };
    
#line 62
    inline Lang::dword Int()
    {
#line 62
        return Generator::Local().Random(4294967295U);
    };
    
#line 63
    inline Lang::uint64 Int64()
    {
#line 63
        return Generator::Local().Get();
    };
    
#line 64
    inline Lang::dword Range(Lang::dword n)
    {
#line 64
        return Generator::Local().Random(n);
    };
    
#line 65
    inline Lang::uint64 Range64(Lang::uint64 n)
    {
#line 65
        return Generator::Local().Random(n);
    };
    
    inline void Seed()
    {
#line 68
        return Generator::Local().Seed();
    };
    
#line 44
    inline Generator::Generator()
    {
#line 44
        Seed();
    };
    
#line 49
    inline Generator::operator Lang::uint64()
    {
#line 49
        return Get();
    };
    
#line 48
    inline Lang::uint64 Generator::Get()
    {
#line 48
        return sNext(state);
    };
    
#line 56
    inline Generator& Generator::Local()
    {
#line 56
        static thread_local Generator r;
#line 56
        return r;
    };
    
#line 47
    inline Lang::uint64 Generator::Random(Lang::uint64 max)
    {
#line 47
        return Get() % max;
    };
    
    inline void Generator::Seed()
    {
#line 50
        sSeed(state);
    };
    
};

#endif
