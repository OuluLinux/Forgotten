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
