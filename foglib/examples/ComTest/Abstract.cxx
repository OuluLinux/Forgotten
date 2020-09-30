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

#ifndef ABSTRACT_CXX
#define ABSTRACT_CXX

#include <new>

#ifndef ABSTRACT_HXX
#include <Abstract.hxx>
#endif

namespace Abstract
{
#line 48 "../../src/Com/Abstract.fog"
    void Stream::Flush() {};
    
#line 43
    int Stream::Get(void *mem, int size)
    {
#line 43
        return 0;
    };
    
#line 44
    Lang::int64 Stream::GetCursor()
    {
#line 44
        return 0;
    };
    
#line 46
    Lang::int64 Stream::GetSize() const
    {
#line 46
        return 0;
    };
    
#line 39
    bool Stream::IsEof()
    {
#line 39
        return false;
    };
    
#line 37
    bool Stream::IsLoading()
    {
#line 37
        return false;
    };
    
#line 35
    bool Stream::IsOpen() const
    {
#line 35
        return false;
    };
    
    bool Stream::IsStoring()
    {
#line 38
        return false;
    };
    
#line 42
    int Stream::Put(char c)
    {
#line 42
        return Put(&c, 1);
    };
    
#line 41
    int Stream::Put(const void *mem, int size)
    {
#line 41
        return 0;
    };
    
#line 45
    void Stream::Seek(Lang::int64 pos) {};
    
};

#endif
