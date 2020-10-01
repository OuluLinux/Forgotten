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

#ifndef STREAM_CXX
#define STREAM_CXX

#include <new>

#ifndef STREAM_HXX
#include <Stream.hxx>
#endif

namespace Stream
{
#line 265 "../../src/Com/Stream.fog"
    template < class _1 >
    bool LoadFromFile(_1& o, Text::String path)
    {
#line 267
        FileIn fin(path);
        if (!fin.IsOpen())
            return false;
        fin % o;
        return !fin.IsCorrupted();
    };
    
    template < class _1 >
    bool StoreToFile(_1& o, Text::String path)
    {
#line 276
        FileOut fout(path);
        if (!fout.IsOpen())
            return false;
        fout % o;
        return !fout.IsCorrupted();
    };
    
#line 291
    AudioFrame::~AudioFrame() {};
    
#line 19
    CharStream& CharStream::operator<< (Text::String s)
    {
#line 19
        s.Serialize(*this);
#line 19
        return *this;
    };
    
#line 21
    CharStream& CharStream::operator<< (int i)
    {
#line 21
        Text::String::IntStr(i).Serialize(*this);
#line 21
        return *this;
    };
    
#line 28
    Text::String CharStream::GetLine(int max)
    {
#line 29
        Text::String out;
        while (!IsEof() && out.GetCount() < max)
            {
#line 31
                char chr;
                Get(&chr, 1);
                if (chr == '\n')
                    break;
                
#line 35
                out.Cat(chr);
            }
        return out;
    };
    
#line 22
    Text::String CharStream::GetString(int size)
    {
#line 23
        Container::Vector < char > v;
        v.SetCount(size, 0);
        Get(v.Begin(), size);
        return Text::String(v.Begin());
    };
    
#line 62
    void FileIn::Close()
    {
#line 63
        if (s)
#line 63
            Native::FileClose(s);
#line 63
        s = 0;
    };
    
    Text::String FileIn::Get(int size)
    {
#line 67
        if (!s || !size)
#line 67
            return Text::String();
        {
#line 68
            if (!(size > 0))
            {
#line 68
                Lang::SysBreak("Assertion failed: size > 0");
            }
        }
#line 69
        ;
#line 69
        int pos = Native::FileTell(s);
        Container::Vector < char > v;
        v.SetCount(size + 1, 0);
        char * it = v.Begin();
        int left = size;
        int total_read = 0;
        while (left > 0)
            {
#line 76
                int read_size = Native::FileRead(it, 1, left, s);
                left -= read_size;
                it += read_size;
                total_read += read_size;
                if (!read_size)
                    break;
            
            }
#line 83
        Text::String out;
        out.Set(v.Begin(), total_read + 1, false);
        return out;
    };
    
#line 97
    int FileIn::Get(void *mem, int size)
    {
#line 98
        if (!s)
#line 98
            return 0;
        Lang::int64 ret = Native::FileRead(mem, size, 1, s) * size;
        {
#line 100
            if (!(ret < 2147483647))
            {
#line 100
                Lang::SysBreak("Assertion failed: ret < INT_MAX");
            }
        }
#line 101
        ;
#line 101
        return(int) ret;
    };
    
    Lang::int64 FileIn::GetCursor()
    {
#line 104
        if (!s)
#line 104
            return 0;
#line 104
        return Native::FileTell(s);
    };
    
#line 106
    Lang::int64 FileIn::GetSize() const
    {
#line 107
        if (!s)
#line 107
            return 0;
        long pos = Native::FileTell(s);
        FileSeekEnd(s, 0);
        int size = Native::FileTell(s);
        FileSeekSet(s, pos);
        return size;
    };
    
#line 88
    Text::String FileIn::GetText(int size)
    {
#line 89
        if (!s)
#line 89
            return "";
        Container::Vector < char > v;
        v.SetCount(size + 1);
        v[size] = 0;
        size_t read_size = Native::FileRead(v.Begin(), 1, size, s);
        return v.Get();
    };
    
#line 54
    bool FileIn::IsEof()
    {
#line 54
        if (!s)
#line 54
            return true;
#line 54
        return IsFileEnd(s);
    };
    
#line 52
    bool FileIn::IsLoading()
    {
#line 52
        return true;
    };
    
#line 53
    bool FileIn::IsOpen() const
    {
#line 53
        return s != 0;
    };
    
    bool FileIn::Open(Text::String path)
    {
#line 57
        if (s)
#line 57
            Native::FileClose(s);
        Native::FileOpen(&s, path.Begin(), false, false);
        return s != 0;
    };
    
#line 115
    void FileIn::Seek(Lang::int64 i)
    {
#line 115
        Native::FileSeekSet(s, (long) i);
    };
    
#line 143
    void FileOut::Close()
    {
#line 144
        if (s)
        {
#line 144
            Native::FileFlush(s);
#line 144
            Native::FileClose(s);
#line 144
            s = 0;
        }
    };
    
#line 165
    void FileOut::Flush()
    {
#line 165
        if (s)
#line 165
            Native::FileFlush(s);
    };
    
#line 167
    Lang::int64 FileOut::GetCursor()
    {
#line 167
        if (!s)
#line 167
            return 0;
#line 167
        return Native::FileTell(s);
    };
    
#line 169
    Lang::int64 FileOut::GetSize() const
    {
#line 170
        if (!s)
#line 170
            return 0;
        long pos = Native::FileTell(s);
        Native::FileSeekSet(s, 0);
        int size = Native::FileTell(s);
        Native::FileSeekSet(s, pos);
        return size;
    };
    
#line 136
    bool FileOut::IsEof()
    {
#line 136
        if (!s)
#line 136
            return true;
#line 136
        return Native::IsFileEnd(s);
    };
    
#line 135
    bool FileOut::IsOpen() const
    {
#line 135
        return s != 0;
    };
    
#line 133
    bool FileOut::IsStoring()
    {
#line 133
        return true;
    };
    
#line 138
    bool FileOut::Open(Text::String path)
    {
#line 139
        if (s)
#line 139
            Native::FileClose(s);
        return s != 0;
    };
    
#line 163
    int FileOut::Put(char c)
    {
#line 163
        return Put(&c, 1);
    };
    
#line 157
    int FileOut::Put(const void *mem, int size)
    {
#line 158
        if (!s)
#line 158
            return 0;
        Lang::int64 ret = Native::FileWrite(mem, size, 1, s) * size;
        {
#line 160
            if (!(ret < 2147483647))
            {
#line 160
                Lang::SysBreak("Assertion failed: ret < INT_MAX");
            }
        }
#line 161
        ;
#line 161
        return(int) ret;
    };
    
#line 309
    Text::String MediaStream::GetLastError() const
    {
#line 309
        return "unknown";
    };
    
#line 244
    MemReadStream::MemReadStream(const char *buf, Lang::int64 size)
    :
        buf(buf),
        size(size),
        cursor(0)
    {};
    
#line 250
    int MemReadStream::Get(void *mem, int size)
    {
#line 251
        Lang::int64 sz = Algorithm::Minimum < Lang::int64 > (size, size - cursor);
        if (sz <= 0)
#line 252
            return 0;
        {
#line 253
            if (!(sz < 2147483647))
            {
#line 253
                Lang::SysBreak("Assertion failed: sz < INT_MAX");
            }
        }
#line 254
        ;
#line 254
        char * b = (char * ) mem;
        Lang::Memory::Copy(b, buf + cursor, (int) sz);
        cursor += sz;
        return(int) sz;
    };
    
#line 259
    Lang::int64 MemReadStream::GetCursor()
    {
#line 259
        return cursor;
    };
    
#line 261
    Lang::int64 MemReadStream::GetSize() const
    {
#line 261
        return size;
    };
    
#line 248
    bool MemReadStream::IsEof()
    {
#line 248
        return cursor >= size;
    };
    
#line 246
    bool MemReadStream::IsLoading()
    {
#line 246
        return true;
    };
    
#line 247
    bool MemReadStream::IsStoring()
    {
#line 247
        return false;
    };
    
#line 260
    void MemReadStream::Seek(Lang::int64 i)
    {
#line 260
        cursor = i;
    };
    
#line 191
    StringStream::StringStream()
    :
        cursor(0),
        is_storing(true)
    {};
    
#line 200
    Abstract::Stream& StringStream::operator<< (Text::String str)
    {
#line 201
        Put(str.Begin(), str.GetCount());
        return *this;
    };
    
#line 204
    Abstract::Stream& StringStream::operator<< (int i)
    {
#line 205
        Text::String str = Text::String::IntStr(i);
        Put(str.Begin(), str.GetCount());
        return *this;
    };
    
#line 221
    int StringStream::Get(void *mem, int size)
    {
#line 222
        Lang::int64 sz = Algorithm::Minimum((Lang::int64) size, (Lang::int64) s.GetCount() - cursor);
        if (sz <= 0)
#line 223
            return 0;
        {
#line 224
            if (!(sz < 2147483647))
            {
#line 224
                Lang::SysBreak("Assertion failed: sz < INT_MAX");
            }
        }
#line 225
        ;
#line 225
        char * b = (char * ) mem;
        Lang::Memory::Copy(b, s.Begin() + cursor, (int) sz);
        cursor += sz;
        return(int) sz;
    };
    
#line 230
    Lang::int64 StringStream::GetCursor()
    {
#line 230
        return cursor;
    };
    
#line 234
    Text::String StringStream::GetResult()
    {
#line 234
        return Text::String(s.Begin(), s.GetCount());
    };
    
#line 231
    Lang::int64 StringStream::GetSize() const
    {
#line 231
        return s.GetCount();
    };
    
#line 195
    bool StringStream::IsEof()
    {
#line 195
        return cursor >= s.GetCount();
    };
    
#line 193
    bool StringStream::IsLoading()
    {
#line 193
        return !is_storing;
    };
    
#line 194
    bool StringStream::IsStoring()
    {
#line 194
        return is_storing;
    };
    
#line 220
    int StringStream::Put(char c)
    {
#line 220
        return Put(&c, 1);
    };
    
#line 209
    int StringStream::Put(const void *mem, int size)
    {
#line 210
        Lang::int64 end = cursor + size;
        {
#line 211
            if (!(end < 2147483647))
            {
#line 211
                Lang::SysBreak("Assertion failed: end < INT_MAX");
            }
        }
#line 212
        ;
#line 212
        if (end > s.GetCount())
            s.SetCount((int) end);
        char * dst = s.Begin() + cursor;
        const char * src = (const char * ) mem;
        Lang::Memory::Copy(dst, src, size);
        cursor += size;
        return size;
    };
    
#line 233
    void StringStream::Seek(Lang::int64 i)
    {
#line 233
        cursor = i;
    };
    
#line 299
    VideoFrame::~VideoFrame() {};
    
};

#endif
