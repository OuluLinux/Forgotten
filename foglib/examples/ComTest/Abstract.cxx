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

#ifndef ABSTRACT_CXX
#define ABSTRACT_CXX

#include <new>

#ifndef ABSTRACT_HXX
#include <Abstract.hxx>
#endif

namespace Abstract
{
#line 65 "../../src/Com/Abstract.fog"
    void Stream::Flush() {};
    
#line 60
    int Stream::Get(void *mem, int size)
    {
#line 60
        return 0;
    };
    
#line 61
    Lang::int64 Stream::GetCursor()
    {
#line 61
        return 0;
    };
    
#line 63
    Lang::int64 Stream::GetSize() const
    {
#line 63
        return 0;
    };
    
#line 56
    bool Stream::IsEof()
    {
#line 56
        return false;
    };
    
#line 54
    bool Stream::IsLoading()
    {
#line 54
        return false;
    };
    
#line 52
    bool Stream::IsOpen() const
    {
#line 52
        return false;
    };
    
    bool Stream::IsStoring()
    {
#line 55
        return false;
    };
    
#line 59
    int Stream::Put(char c)
    {
#line 59
        return Put(&c, 1);
    };
    
#line 58
    int Stream::Put(const void *mem, int size)
    {
#line 58
        return 0;
    };
    
#line 62
    void Stream::Seek(Lang::int64 i) {};
    
};

#endif
