#ifndef ABSTRACT_HXX
#define ABSTRACT_HXX

#include <new>

#ifndef RANDOM_HXX
#include <Random.hxx>
#endif

namespace Abstract
{
};

namespace Abstract {
class StreamBase;
}

namespace Abstract
{
#line 15 "../../src/Com/Abstract.fog"
    template < class _1 >
    inline void Serialize(_1& o, StreamBase& s);
#line 8
    inline void Serialize(bool& o, StreamBase& s);
#line 8
    inline void Serialize(char& o, StreamBase& s);
#line 27
    inline void Serialize(const char *o, StreamBase& s);
#line 8
    inline void Serialize(double& o, StreamBase& s);
#line 8
    inline void Serialize(float& o, StreamBase& s);
#line 8
    inline void Serialize(int& o, StreamBase& s);
#line 8
    inline void Serialize(long long& o, StreamBase& s);
#line 8
    inline void Serialize(short& o, StreamBase& s);
#line 8
    inline void Serialize(unsigned char& o, StreamBase& s);
#line 8
    inline void Serialize(unsigned int& o, StreamBase& s);
#line 8
    inline void Serialize(unsigned long long& o, StreamBase& s);
#line 8
    inline void Serialize(unsigned short& o, StreamBase& s);
    
    class StreamBase
    {
    public:
#line 40
        typedef Native::FILE FILE;
        
#line 38
        bool corrupted;
        
    public:
        inline StreamBase();
#line 61
        template < class _1 >
        inline StreamBase& operator% (_1& o);
#line 59
        virtual void Flush();
#line 54
        virtual int Get(void *mem, int size);
        virtual Lang::int64 GetCursor();
#line 57
        virtual Lang::int64 GetSize() const;
#line 43
        inline bool IsCorrupted() const;
#line 50
        virtual bool IsEof();
#line 48
        virtual bool IsLoading();
#line 46
        virtual bool IsOpen() const;
#line 49
        virtual bool IsStoring();
#line 53
        virtual int Put(char c);
#line 52
        virtual int Put(const void *mem, int size);
#line 56
        virtual void Seek(Lang::int64 i);
#line 44
        inline void SetCorrupted(bool b = true);
    };
};

namespace Abstract
{
#line 15
    template < class _1 >
    inline void Serialize(_1& o, StreamBase& s)
    {
#line 15
        o.Serialize(s);
    };
    
#line 8
    inline void Serialize(bool& o, StreamBase& s)
    {
#line 9
        if (s.IsLoading())
            s.Get(&o, sizeof (bool));
        else 
#line 11
        if (s.IsStoring())
            s.Put(&o, sizeof (bool));
    };
    
#line 8
    inline void Serialize(char& o, StreamBase& s)
    {
#line 9
        if (s.IsLoading())
            s.Get(&o, sizeof (char));
        else 
#line 11
        if (s.IsStoring())
            s.Put(&o, sizeof (char));
    };
    
#line 27
    inline void Serialize(const char *o, StreamBase& s)
    {
        {
#line 28
            if (!(s.IsStoring()))
            {
#line 28
                Lang::SysBreak("Assertion failed: s.IsStoring()");
            }
        }
#line 29
        ;
#line 29
        if (s.IsStoring())
        {
#line 30
            int len = Lang::StringLength(o);
            s.Put(&len, sizeof (len));
            if (len > 0)
                s.Put(o, len);
        }
    };
    
#line 8
    inline void Serialize(double& o, StreamBase& s)
    {
#line 9
        if (s.IsLoading())
            s.Get(&o, sizeof (double));
        else 
#line 11
        if (s.IsStoring())
            s.Put(&o, sizeof (double));
    };
    
#line 8
    inline void Serialize(float& o, StreamBase& s)
    {
#line 9
        if (s.IsLoading())
            s.Get(&o, sizeof (float));
        else 
#line 11
        if (s.IsStoring())
            s.Put(&o, sizeof (float));
    };
    
#line 8
    inline void Serialize(int& o, StreamBase& s)
    {
#line 9
        if (s.IsLoading())
            s.Get(&o, sizeof (int));
        else 
#line 11
        if (s.IsStoring())
            s.Put(&o, sizeof (int));
    };
    
#line 8
    inline void Serialize(long long& o, StreamBase& s)
    {
#line 9
        if (s.IsLoading())
            s.Get(&o, sizeof (long long));
        else 
#line 11
        if (s.IsStoring())
            s.Put(&o, sizeof (long long));
    };
    
#line 8
    inline void Serialize(short& o, StreamBase& s)
    {
#line 9
        if (s.IsLoading())
            s.Get(&o, sizeof (short));
        else 
#line 11
        if (s.IsStoring())
            s.Put(&o, sizeof (short));
    };
    
#line 8
    inline void Serialize(unsigned char& o, StreamBase& s)
    {
#line 9
        if (s.IsLoading())
            s.Get(&o, sizeof (unsigned char));
        else 
#line 11
        if (s.IsStoring())
            s.Put(&o, sizeof (unsigned char));
    };
    
#line 8
    inline void Serialize(unsigned int& o, StreamBase& s)
    {
#line 9
        if (s.IsLoading())
            s.Get(&o, sizeof (unsigned int));
        else 
#line 11
        if (s.IsStoring())
            s.Put(&o, sizeof (unsigned int));
    };
    
#line 8
    inline void Serialize(unsigned long long& o, StreamBase& s)
    {
#line 9
        if (s.IsLoading())
            s.Get(&o, sizeof (unsigned long long));
        else 
#line 11
        if (s.IsStoring())
            s.Put(&o, sizeof (unsigned long long));
    };
    
#line 8
    inline void Serialize(unsigned short& o, StreamBase& s)
    {
#line 9
        if (s.IsLoading())
            s.Get(&o, sizeof (unsigned short));
        else 
#line 11
        if (s.IsStoring())
            s.Put(&o, sizeof (unsigned short));
    };
    
#line 41
    inline StreamBase::StreamBase()
    :
        corrupted(false)
    {};
    
#line 61
    template < class _1 >
    inline StreamBase& StreamBase::operator% (_1& o)
    {
#line 62
        Serialize(o, *this);
#line 62
        return *this;
    };
    
#line 43
    inline bool StreamBase::IsCorrupted() const
    {
#line 43
        return corrupted;
    };
    
#line 44
    inline void StreamBase::SetCorrupted(bool b)
    {
#line 44
        corrupted = b;
    };
    
};

#endif
