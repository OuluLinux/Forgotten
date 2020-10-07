#ifndef HASH_HXX
#define HASH_HXX

#include <new>

#ifndef NATIVE_HXX
#include <Native.hxx>
#endif
#ifndef PRIM_HXX
#include <Prim.hxx>
#endif

namespace Hash
{
#line 26 "../../src/Com/Hash.fog"
    inline Lang::uint32 GetValue(const Lang::int32& k);
    inline Lang::uint32 GetValue(const Lang::int64& k);
#line 33
    inline Lang::uint32 GetValue(const Lang::uint32& k);
    inline Lang::uint32 GetValue(const Lang::uint64& k);
#line 24
    template < class _1 >
    inline Lang::uint32 GetValue(const _1& k);
#line 25
    inline Lang::uint32 GetValue(const char& k);
#line 41
    inline Lang::uint32 GetValue(const double& k);
#line 40
    inline Lang::uint32 GetValue(const float& k);
#line 42
    inline Lang::uint32 GetValue(void *const& k);
    
    class Combine
    {
#line 7
        Lang::uint32 hash;
        
    public:
        inline Combine();
        inline Combine(int v0);
        Combine(int v0, int v1);
#line 20
        inline Combine& operator<< (int value);
#line 14
        inline operator Lang::uint32() const;
        inline Lang::uint32 Get() const;
#line 17
        Combine& Put(int value);
        Combine& Put64(Lang::int64 value);
    };
};

namespace Hash
{
#line 26
    inline Lang::uint32 GetValue(const Lang::int32& k)
    {
#line 26
        return k;
    };
    
#line 27
    inline Lang::uint32 GetValue(const Lang::int64& k)
    {
#line 28
        Lang::uint32 a = k & 0xFFFFFFFFULL;
        Lang::uint32 b = k >> 32ULL;
        Lang::uint32 hash = a ^ b;
        return hash;
    };
    
#line 33
    inline Lang::uint32 GetValue(const Lang::uint32& k)
    {
#line 33
        return k;
    };
    
#line 34
    inline Lang::uint32 GetValue(const Lang::uint64& k)
    {
#line 35
        Lang::uint32 a = k & 0xFFFFFFFFULL;
        Lang::uint32 b = k >> 32ULL;
        Lang::uint32 hash = a ^ b;
        return hash;
    };
    
#line 24
    template < class _1 >
    inline Lang::uint32 GetValue(const _1& k)
    {
#line 24
        return k.GetHashValue();
    };
    
#line 25
    inline Lang::uint32 GetValue(const char& k)
    {
#line 25
        return k;
    };
    
#line 41
    inline Lang::uint32 GetValue(const double& k)
    {
#line 41
        return GetValue(*(Lang::uint64 * ) & k);
    };
    
#line 40
    inline Lang::uint32 GetValue(const float& k)
    {
#line 40
        return static_cast< Lang::uint32 >(k);
    };
    
#line 42
    inline Lang::uint32 GetValue(void *const& k)
    {
        return GetValue(k);
    };
    
#line 10
    inline Combine::Combine()
    :
        hash(123456789)
    {};
    
#line 11
    inline Combine::Combine(int v0)
    :
        hash(123456789)
    {
#line 11
        Put(v0);
    };
    
#line 20
    inline Combine& Combine::operator<< (int value)
    {
#line 20
        Put(value);
#line 20
        return *this;
    };
    
#line 14
    inline Combine::operator Lang::uint32() const
    {
#line 14
        return hash;
    };
    
#line 15
    inline Lang::uint32 Combine::Get() const
    {
#line 15
        return hash;
    };
    
};

#endif
