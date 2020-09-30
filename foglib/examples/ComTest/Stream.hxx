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

#ifndef STREAM_HXX
#define STREAM_HXX

#include <new>

#ifndef ABSTRACT_HXX
#include <Abstract.hxx>
#endif
#ifndef CONTAINER_HXX
#include <Container.hxx>
#endif

namespace {
struct FILE;
}

namespace Stream
{
#line 119 "../../src/Com/Stream.fog"
    Text::String LoadFile(Text::String path);
    
    struct CharStream : public Abstract::Stream
    {
#line 20
        CharStream& operator<< (Text::String s);
        CharStream& operator<< (int i);
        Text::String Get(int size);
#line 28
        Text::String GetLine(int max = 65535);
    };
    
    class FileIn : public Abstract::Stream
    {
#line 43
        FILE *s;
        
    public:
        inline FileIn();
        inline FileIn(FILE *s);
        inline FileIn(Text::String path);
        inline ~FileIn();
#line 61
        void Close();
#line 65
        virtual Text::String Get(int size);
#line 96
        virtual int Get(void *mem, int size);
#line 103
        virtual Lang::int64 GetCursor();
#line 105
        virtual Lang::int64 GetSize() const;
#line 87
        Text::String GetText(int size);
#line 53
        virtual bool IsEof();
#line 51
        virtual bool IsLoading();
        virtual bool IsOpen() const;
#line 55
        bool Open(Text::String path);
#line 114
        virtual void Seek(Lang::int64 pos);
    };
    
    struct FileOut : public Abstract::Stream
    {
#line 125
        inline FileOut();
    };
};

namespace Stream
{
#line 46
    inline FileIn::FileIn()
    :
        s(0)
    {};
    
#line 47
    inline FileIn::FileIn(FILE *s)
    :
        s(s)
    {};
    
#line 48
    inline FileIn::FileIn(Text::String path)
    :
        s(0)
    {
#line 48
        Open(path);
    };
    
#line 49
    inline FileIn::~FileIn()
    {
#line 49
        Close();
    };
    
#line 125
    inline FileOut::FileOut()
    {
        {
#line 126
            if (!(false))
            {
#line 126
                Lang::SysBreak("Assertion failed: test");
            }
        }
#line 127
        ;
    };
    
};

#endif
