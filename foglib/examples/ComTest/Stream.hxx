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

#ifndef STREAM_HXX
#define STREAM_HXX

#include <new>

#ifndef ABSTRACT_HXX
#include <Abstract.hxx>
#endif
#ifndef CONTAINER_HXX
#include <Container.hxx>
#endif

namespace Stream
{
#line 120 "../../src/Com/Stream.fog"
    Text::String LoadFile(Text::String path);
#line 265
    template < class _1 >
    bool LoadFromFile(_1& o, Text::String path);
#line 274
    template < class _1 >
    bool StoreToFile(_1& o, Text::String path);
    
    class AudioFrame
    {
    public:
#line 291
        virtual ~AudioFrame();
    };
    
    struct CharStream : public Abstract::Stream
    {
#line 19
        CharStream& operator<< (Text::String s);
        inline CharStream& operator<< (const char *s);
        CharStream& operator<< (int i);
#line 28
        Text::String GetLine(int max = 65535);
#line 22
        Text::String GetString(int size);
    };
    
    class FileIn : public Stream::CharStream
    {
#line 43
        typedef Native::FILE FILE;
        
#line 44
        FILE *s;
        
    public:
        inline FileIn();
        inline FileIn(FILE *s);
        inline FileIn(Text::String path);
        inline ~FileIn();
#line 62
        void Close();
#line 66
        virtual Text::String Get(int size);
#line 97
        virtual int Get(void *mem, int size);
#line 104
        virtual Lang::int64 GetCursor();
#line 106
        virtual Lang::int64 GetSize() const;
#line 88
        Text::String GetText(int size);
#line 54
        virtual bool IsEof();
#line 52
        virtual bool IsLoading();
        virtual bool IsOpen() const;
#line 56
        bool Open(Text::String path);
#line 115
        virtual void Seek(Lang::int64 i);
    };
    
#line 180
    extern FileIn cin;
    
    struct FileOut : public Stream::CharStream
    {
#line 124
        typedef Native::FILE FILE;
        
#line 125
        FILE *s;
        
#line 128
        inline FileOut();
        inline FileOut(FILE *s);
        inline FileOut(Text::String path);
        inline ~FileOut();
#line 143
        void Close();
#line 165
        virtual void Flush();
#line 167
        virtual Lang::int64 GetCursor();
#line 169
        virtual Lang::int64 GetSize() const;
#line 136
        virtual bool IsEof();
#line 135
        virtual bool IsOpen() const;
#line 133
        virtual bool IsStoring();
#line 138
        bool Open(Text::String path);
#line 163
        virtual int Put(char c);
#line 157
        virtual int Put(const void *mem, int size);
    };
    
#line 181
    extern FileOut cerr;
#line 181
    extern FileOut cout;
};

namespace Stream {
class VideoFrame;
}

namespace Stream
{
    class MediaStream
    {
    public:
#line 309
        virtual Text::String GetLastError() const;
#line 308
        /*pure*/virtual bool Initialize(AudioFrame& a, VideoFrame& v) = 0;
    };
    
    class MemReadStream : public Stream::CharStream
    {
#line 239
        const char *buf;
        Lang::int64 size;
        Lang::int64 cursor;
        
    public:
        MemReadStream(const char *buf, Lang::int64 size);
#line 250
        virtual int Get(void *mem, int size);
#line 259
        virtual Lang::int64 GetCursor();
#line 261
        virtual Lang::int64 GetSize() const;
#line 248
        virtual bool IsEof();
#line 246
        virtual bool IsLoading();
        virtual bool IsStoring();
#line 260
        virtual void Seek(Lang::int64 i);
    };
    
    class StringStream : public Stream::CharStream
    {
#line 186
        Container::Vector < char > s;
        Lang::int64 cursor;
        bool is_storing;
        
    public:
        StringStream();
#line 200
        virtual Abstract::Stream& operator<< (Text::String str);
#line 204
        virtual Abstract::Stream& operator<< (int i);
#line 221
        virtual int Get(void *mem, int size);
#line 230
        virtual Lang::int64 GetCursor();
#line 234
        Text::String GetResult();
#line 231
        virtual Lang::int64 GetSize() const;
#line 195
        virtual bool IsEof();
#line 193
        virtual bool IsLoading();
        virtual bool IsStoring();
#line 220
        virtual int Put(char c);
#line 209
        virtual int Put(const void *mem, int size);
#line 233
        virtual void Seek(Lang::int64 i);
#line 198
        inline void SetLoading();
#line 197
        inline void SetStoring();
    };
    
    class VideoFrame
    {
    public:
#line 299
        virtual ~VideoFrame();
    };
};

namespace Stream
{
#line 20
    inline CharStream& CharStream::operator<< (const char *s)
    {
#line 20
        Serialize(s, *this);
#line 20
        return *this;
    };
    
#line 47
    inline FileIn::FileIn()
    :
        s(0)
    {};
    
#line 48
    inline FileIn::FileIn(FILE *s)
    :
        s(s)
    {};
    
#line 49
    inline FileIn::FileIn(Text::String path)
    :
        s(0)
    {
#line 49
        Open(path);
    };
    
#line 50
    inline FileIn::~FileIn()
    {
#line 50
        Close();
    };
    
#line 128
    inline FileOut::FileOut()
    :
        s(0)
    {};
    
#line 129
    inline FileOut::FileOut(FILE *s)
    :
        s(s)
    {};
    
#line 130
    inline FileOut::FileOut(Text::String path)
    :
        s(0)
    {
#line 130
        Open(path);
    };
    
#line 131
    inline FileOut::~FileOut()
    {
#line 131
        Close();
    };
    
#line 198
    inline void StringStream::SetLoading()
    {
#line 198
        is_storing = false;
    };
    
#line 197
    inline void StringStream::SetStoring()
    {
#line 197
        is_storing = true;
    };
    
};

#endif
