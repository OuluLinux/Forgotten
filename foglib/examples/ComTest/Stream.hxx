#ifndef STREAM_HXX
#define STREAM_HXX

#include <new>

#ifndef ABSTRACT_HXX
#include <Abstract.hxx>
#endif
#ifndef SHARED_HXX
#include <Shared.hxx>
#endif

namespace Stream
{
#line 118 "../../src/Com/Stream.fog"
    Text::String LoadFile(Text::String path);
#line 263
    template < class _1 >
    bool LoadFromFile(_1& o, Text::String path);
#line 272
    template < class _1 >
    bool StoreToFile(_1& o, Text::String path);
    
    class AudioFrame
    {
    public:
#line 289
        virtual ~AudioFrame();
    };
    
    struct CharStream : public Abstract::StreamBase
    {
#line 17
        CharStream& operator<< (Text::String s);
        inline CharStream& operator<< (const char *s);
        CharStream& operator<< (int i);
#line 26
        Text::String GetLine(int max = 65535);
#line 20
        Text::String GetString(int size);
    };
    
    class FileIn : public Stream::CharStream
    {
#line 41
        typedef Native::FILE FILE;
        
#line 42
        FILE *s;
        
    public:
        inline FileIn();
        inline FileIn(FILE *s);
        inline FileIn(Text::String path);
        inline ~FileIn();
#line 60
        void Close();
#line 64
        virtual Text::String Get(int size);
#line 95
        virtual int Get(void *mem, int size);
#line 102
        virtual Lang::int64 GetCursor();
#line 104
        virtual Lang::int64 GetSize() const;
#line 86
        Text::String GetText(int size);
#line 52
        virtual bool IsEof();
#line 50
        virtual bool IsLoading();
        virtual bool IsOpen() const;
#line 54
        bool Open(Text::String path);
#line 113
        virtual void Seek(Lang::int64 i);
    };
    
#line 178
    extern FileIn cin;
    
    struct FileOut : public Stream::CharStream
    {
#line 122
        typedef Native::FILE FILE;
        
#line 123
        FILE *s;
        
#line 126
        inline FileOut();
        inline FileOut(FILE *s);
        inline FileOut(Text::String path);
        inline ~FileOut();
#line 141
        void Close();
#line 163
        virtual void Flush();
#line 165
        virtual Lang::int64 GetCursor();
#line 167
        virtual Lang::int64 GetSize() const;
#line 134
        virtual bool IsEof();
#line 133
        virtual bool IsOpen() const;
#line 131
        virtual bool IsStoring();
#line 136
        bool Open(Text::String path);
#line 161
        virtual int Put(char c);
#line 155
        virtual int Put(const void *mem, int size);
    };
    
#line 179
    extern FileOut cerr;
#line 179
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
#line 307
        virtual Text::String GetLastError() const;
#line 306
        /*pure*/virtual bool Initialize(AudioFrame& a, VideoFrame& v) = 0;
    };
    
    class MemReadStream : public Stream::CharStream
    {
#line 237
        const char *buf;
        Lang::int64 size;
        Lang::int64 cursor;
        
    public:
        MemReadStream(const char *buf, Lang::int64 size);
#line 248
        virtual int Get(void *mem, int size);
#line 257
        virtual Lang::int64 GetCursor();
#line 259
        virtual Lang::int64 GetSize() const;
#line 246
        virtual bool IsEof();
#line 244
        virtual bool IsLoading();
        virtual bool IsStoring();
#line 258
        virtual void Seek(Lang::int64 i);
    };
    
    class StringStream : public Stream::CharStream
    {
#line 184
        Container::Vector < char > s;
        Lang::int64 cursor;
        bool is_storing;
        
    public:
        StringStream();
#line 198
        virtual Abstract::StreamBase& operator<< (Text::String str);
#line 202
        virtual Abstract::StreamBase& operator<< (int i);
#line 219
        virtual int Get(void *mem, int size);
#line 228
        virtual Lang::int64 GetCursor();
#line 232
        Text::String GetResult();
#line 229
        virtual Lang::int64 GetSize() const;
#line 193
        virtual bool IsEof();
#line 191
        virtual bool IsLoading();
        virtual bool IsStoring();
#line 218
        virtual int Put(char c);
#line 207
        virtual int Put(const void *mem, int size);
#line 231
        virtual void Seek(Lang::int64 i);
#line 196
        inline void SetLoading();
#line 195
        inline void SetStoring();
    };
    
    class VideoFrame
    {
    public:
#line 297
        virtual ~VideoFrame();
    };
};

namespace Stream
{
#line 18
    inline CharStream& CharStream::operator<< (const char *s)
    {
#line 18
        Serialize(s, *this);
#line 18
        return *this;
    };
    
#line 45
    inline FileIn::FileIn()
    :
        s(0)
    {};
    
#line 46
    inline FileIn::FileIn(FILE *s)
    :
        s(s)
    {};
    
#line 47
    inline FileIn::FileIn(Text::String path)
    :
        s(0)
    {
#line 47
        Open(path);
    };
    
#line 48
    inline FileIn::~FileIn()
    {
#line 48
        Close();
    };
    
#line 126
    inline FileOut::FileOut()
    :
        s(0)
    {};
    
#line 127
    inline FileOut::FileOut(FILE *s)
    :
        s(s)
    {};
    
#line 128
    inline FileOut::FileOut(Text::String path)
    :
        s(0)
    {
#line 128
        Open(path);
    };
    
#line 129
    inline FileOut::~FileOut()
    {
#line 129
        Close();
    };
    
#line 196
    inline void StringStream::SetLoading()
    {
#line 196
        is_storing = false;
    };
    
#line 195
    inline void StringStream::SetStoring()
    {
#line 195
        is_storing = true;
    };
    
};

#endif
