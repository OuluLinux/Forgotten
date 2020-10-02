#ifndef ABSTRACT_CXX
#define ABSTRACT_CXX

#include <new>

#ifndef ABSTRACT_HXX
#include <Abstract.hxx>
#endif

namespace Abstract
{
#line 59 "../../src/Com/Abstract.fog"
    void StreamBase::Flush() {};
    
#line 54
    int StreamBase::Get(void *mem, int size)
    {
#line 54
        return 0;
    };
    
#line 55
    Lang::int64 StreamBase::GetCursor()
    {
#line 55
        return 0;
    };
    
#line 57
    Lang::int64 StreamBase::GetSize() const
    {
#line 57
        return 0;
    };
    
#line 50
    bool StreamBase::IsEof()
    {
#line 50
        return false;
    };
    
#line 48
    bool StreamBase::IsLoading()
    {
#line 48
        return false;
    };
    
#line 46
    bool StreamBase::IsOpen() const
    {
#line 46
        return false;
    };
    
    bool StreamBase::IsStoring()
    {
#line 49
        return false;
    };
    
#line 53
    int StreamBase::Put(char c)
    {
#line 53
        return Put(&c, 1);
    };
    
#line 52
    int StreamBase::Put(const void *mem, int size)
    {
#line 52
        return 0;
    };
    
#line 56
    void StreamBase::Seek(Lang::int64 i) {};
    
};

#endif
