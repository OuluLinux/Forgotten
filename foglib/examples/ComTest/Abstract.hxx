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

#ifndef ABSTRACT_HXX
#define ABSTRACT_HXX

#include <new>

#ifndef RANDOM_HXX
#include <Random.hxx>
#endif
#ifndef ALGORITHM_HXX
#include <Algorithm.hxx>
#endif

namespace Abstract
{
};

namespace Abstract {
struct Stream;
}

namespace Abstract
{
#line 21 "../../src/Com/Abstract.fog"
    template < class _1 >
    inline void Serialize(_1& o, Stream& s);
#line 14
    inline void Serialize(bool& o, Stream& s);
#line 14
    inline void Serialize(char& o, Stream& s);
#line 14
    inline void Serialize(double& o, Stream& s);
#line 14
    inline void Serialize(float& o, Stream& s);
#line 14
    inline void Serialize(int& o, Stream& s);
#line 14
    inline void Serialize(long long& o, Stream& s);
#line 14
    inline void Serialize(short& o, Stream& s);
#line 14
    inline void Serialize(unsigned char& o, Stream& s);
#line 14
    inline void Serialize(unsigned int& o, Stream& s);
#line 14
    inline void Serialize(unsigned long long& o, Stream& s);
#line 14
    inline void Serialize(unsigned short& o, Stream& s);
    
    struct Stream
    {
#line 50
        template < class _1 >
        inline Stream& operator% (_1& o);
#line 48
        virtual void Flush();
#line 43
        virtual int Get(void *mem, int size);
        virtual Lang::int64 GetCursor();
#line 46
        virtual Lang::int64 GetSize() const;
#line 39
        virtual bool IsEof();
#line 37
        virtual bool IsLoading();
#line 35
        virtual bool IsOpen() const;
#line 38
        virtual bool IsStoring();
#line 42
        virtual int Put(char c);
#line 41
        virtual int Put(const void *mem, int size);
#line 45
        virtual void Seek(Lang::int64 pos);
    };
};

namespace Abstract
{
#line 21
    template < class _1 >
    inline void Serialize(_1& o, Stream& s)
    {
#line 21
        o.Serialize(s);
    };
    
#line 14
    inline void Serialize(bool& o, Stream& s)
    {
#line 15
        if (s.IsLoading())
            s.Get(&o, sizeof (bool));
        else 
#line 17
        if (s.IsStoring())
            s.Put(&o, sizeof (bool));
    };
    
#line 14
    inline void Serialize(char& o, Stream& s)
    {
#line 15
        if (s.IsLoading())
            s.Get(&o, sizeof (char));
        else 
#line 17
        if (s.IsStoring())
            s.Put(&o, sizeof (char));
    };
    
#line 14
    inline void Serialize(double& o, Stream& s)
    {
#line 15
        if (s.IsLoading())
            s.Get(&o, sizeof (double));
        else 
#line 17
        if (s.IsStoring())
            s.Put(&o, sizeof (double));
    };
    
#line 14
    inline void Serialize(float& o, Stream& s)
    {
#line 15
        if (s.IsLoading())
            s.Get(&o, sizeof (float));
        else 
#line 17
        if (s.IsStoring())
            s.Put(&o, sizeof (float));
    };
    
#line 14
    inline void Serialize(int& o, Stream& s)
    {
#line 15
        if (s.IsLoading())
            s.Get(&o, sizeof (int));
        else 
#line 17
        if (s.IsStoring())
            s.Put(&o, sizeof (int));
    };
    
#line 14
    inline void Serialize(long long& o, Stream& s)
    {
#line 15
        if (s.IsLoading())
            s.Get(&o, sizeof (long long));
        else 
#line 17
        if (s.IsStoring())
            s.Put(&o, sizeof (long long));
    };
    
#line 14
    inline void Serialize(short& o, Stream& s)
    {
#line 15
        if (s.IsLoading())
            s.Get(&o, sizeof (short));
        else 
#line 17
        if (s.IsStoring())
            s.Put(&o, sizeof (short));
    };
    
#line 14
    inline void Serialize(unsigned char& o, Stream& s)
    {
#line 15
        if (s.IsLoading())
            s.Get(&o, sizeof (unsigned char));
        else 
#line 17
        if (s.IsStoring())
            s.Put(&o, sizeof (unsigned char));
    };
    
#line 14
    inline void Serialize(unsigned int& o, Stream& s)
    {
#line 15
        if (s.IsLoading())
            s.Get(&o, sizeof (unsigned int));
        else 
#line 17
        if (s.IsStoring())
            s.Put(&o, sizeof (unsigned int));
    };
    
#line 14
    inline void Serialize(unsigned long long& o, Stream& s)
    {
#line 15
        if (s.IsLoading())
            s.Get(&o, sizeof (unsigned long long));
        else 
#line 17
        if (s.IsStoring())
            s.Put(&o, sizeof (unsigned long long));
    };
    
#line 14
    inline void Serialize(unsigned short& o, Stream& s)
    {
#line 15
        if (s.IsLoading())
            s.Get(&o, sizeof (unsigned short));
        else 
#line 17
        if (s.IsStoring())
            s.Put(&o, sizeof (unsigned short));
    };
    
#line 50
    template < class _1 >
    inline Stream& Stream::operator% (_1& o)
    {
#line 51
        Serialize(o, *this);
#line 51
        return *this;
    };
    
};

#endif
