#ifndef STREAM_CXX
#define STREAM_CXX

#include <new>

#ifndef STREAM_HXX
#include <Stream.hxx>
#endif

namespace Stream
{
#line 264 "../../src/Com/Stream.fog"
    template < class _1 >
    bool LoadFromFile(_1& o, Text::String path)
    {
#line 266
        FileIn fin(path);
        if (!fin.IsOpen())
            return false;
        fin % o;
        return !fin.IsCorrupted();
    };
    
    template < class _1 >
    bool StoreToFile(_1& o, Text::String path)
    {
#line 275
        FileOut fout(path);
        if (!fout.IsOpen())
            return false;
        fout % o;
        return !fout.IsCorrupted();
    };
    
#line 290
    AudioFrame::~AudioFrame() {};
    
#line 17
    CharStream& CharStream::operator<< (Text::String s)
    {
#line 17
        Put(s.Begin(), s.GetCount());
#line 17
        return *this;
    };
    
#line 19
    CharStream& CharStream::operator<< (int i)
    {
#line 19
        Text::String::IntStr(i).Serialize(*this);
#line 19
        return *this;
    };
    
#line 26
    Text::String CharStream::GetLine(int max)
    {
#line 27
        Text::String out;
        while (!IsEof() && out.GetCount() < max)
            {
#line 29
                char chr;
                Get(&chr, 1);
                if (chr == '\n')
                    break;
                
#line 33
                out.Cat(chr);
            }
        return out;
    };
    
#line 20
    Text::String CharStream::GetString(int size)
    {
#line 21
        Container::Vector < char > v;
        v.SetCount(size, 0);
        Get(v.Begin(), size);
        return Text::String(v.Begin());
    };
    
#line 60
    void FileIn::Close()
    {
#line 61
        if (s)
#line 61
            Native::FileClose(s);
#line 61
        s = 0;
    };
    
    Text::String FileIn::Get(int size)
    {
#line 65
        if (!s || !size)
#line 65
            return Text::String();
        {
#line 66
            if (!(size > 0))
            {
#line 66
                Lang::SysBreak("Assertion failed: size > 0");
            }
        }
#line 67
        ;
#line 67
        int pos = Native::FileTell(s);
        Container::Vector < char > v;
        v.SetCount(size + 1, 0);
        char * it = v.Begin();
        int left = size;
        int total_read = 0;
        while (left > 0)
            {
#line 74
                int read_size = Native::FileRead(it, 1, left, s);
                left -= read_size;
                it += read_size;
                total_read += read_size;
                if (!read_size)
                    break;
            
            }
#line 81
        Text::String out;
        out.Set(v.Begin(), total_read + 1, false);
        return out;
    };
    
#line 95
    int FileIn::Get(void *mem, int size)
    {
#line 96
        if (!s)
#line 96
            return 0;
        Lang::int64 ret = Native::FileRead(mem, size, 1, s) * size;
        {
#line 98
            if (!(ret < 2147483647))
            {
#line 98
                Lang::SysBreak("Assertion failed: ret < INT_MAX");
            }
        }
#line 99
        ;
#line 99
        return(int) ret;
    };
    
    Lang::int64 FileIn::GetCursor()
    {
#line 102
        if (!s)
#line 102
            return 0;
#line 102
        return Native::FileTell(s);
    };
    
#line 104
    Lang::int64 FileIn::GetSize() const
    {
#line 105
        if (!s)
#line 105
            return 0;
        long pos = Native::FileTell(s);
        FileSeekEnd(s, 0);
        int size = Native::FileTell(s);
        FileSeekSet(s, pos);
        return size;
    };
    
#line 86
    Text::String FileIn::GetText(int size)
    {
#line 87
        if (!s)
#line 87
            return "";
        Container::Vector < char > v;
        v.SetCount(size + 1);
        v[size] = 0;
        size_t read_size = Native::FileRead(v.Begin(), 1, size, s);
        return v.Get();
    };
    
#line 52
    bool FileIn::IsEof()
    {
#line 52
        if (!s)
#line 52
            return true;
#line 52
        return IsFileEnd(s);
    };
    
#line 50
    bool FileIn::IsLoading()
    {
#line 50
        return true;
    };
    
#line 51
    bool FileIn::IsOpen() const
    {
#line 51
        return s != 0;
    };
    
    bool FileIn::Open(Text::String path)
    {
#line 55
        if (s)
#line 55
            Native::FileClose(s);
        Native::FileOpen(&s, path.Begin(), false, false);
        return s != 0;
    };
    
#line 113
    void FileIn::Seek(Lang::int64 i)
    {
#line 113
        Native::FileSeekSet(s, (long) i);
    };
    
#line 142
    void FileOut::Close()
    {
#line 143
        if (s)
        {
#line 143
            Native::FileFlush(s);
#line 143
            Native::FileClose(s);
#line 143
            s = 0;
        }
    };
    
#line 164
    void FileOut::Flush()
    {
#line 164
        if (s)
#line 164
            Native::FileFlush(s);
    };
    
#line 166
    Lang::int64 FileOut::GetCursor()
    {
#line 166
        if (!s)
#line 166
            return 0;
#line 166
        return Native::FileTell(s);
    };
    
#line 168
    Lang::int64 FileOut::GetSize() const
    {
#line 169
        if (!s)
#line 169
            return 0;
        long pos = Native::FileTell(s);
        Native::FileSeekSet(s, 0);
        int size = Native::FileTell(s);
        Native::FileSeekSet(s, pos);
        return size;
    };
    
#line 134
    bool FileOut::IsEof()
    {
#line 134
        if (!s)
#line 134
            return true;
#line 134
        return Native::IsFileEnd(s);
    };
    
#line 133
    bool FileOut::IsOpen() const
    {
#line 133
        return s != 0;
    };
    
#line 131
    bool FileOut::IsStoring()
    {
#line 131
        return true;
    };
    
#line 136
    bool FileOut::Open(Text::String path, bool append)
    {
#line 137
        if (s)
#line 137
            Native::FileClose(s);
        Native::FileOpen(&s, path.Begin(), true, append);
        return s != 0;
    };
    
#line 162
    int FileOut::Put(char c)
    {
#line 162
        return Put(&c, 1);
    };
    
#line 156
    int FileOut::Put(const void *mem, int size)
    {
#line 157
        if (!s)
#line 157
            return 0;
        Lang::int64 ret = Native::FileWrite(mem, size, 1, s) * size;
        {
#line 159
            if (!(ret < 2147483647))
            {
#line 159
                Lang::SysBreak("Assertion failed: ret < INT_MAX");
            }
        }
#line 160
        ;
#line 160
        return(int) ret;
    };
    
#line 308
    Text::String MediaStream::GetLastError() const
    {
#line 308
        return "unknown";
    };
    
#line 243
    MemReadStream::MemReadStream(const char *buf, Lang::int64 size)
    :
        buf(buf),
        size(size),
        cursor(0)
    {};
    
#line 249
    int MemReadStream::Get(void *mem, int size)
    {
#line 250
        Lang::int64 sz = Algorithm::Minimum < Lang::int64 > (size, size - cursor);
        if (sz <= 0)
#line 251
            return 0;
        {
#line 252
            if (!(sz < 2147483647))
            {
#line 252
                Lang::SysBreak("Assertion failed: sz < INT_MAX");
            }
        }
#line 253
        ;
#line 253
        char * b = (char * ) mem;
        Lang::Memory::Copy(b, buf + cursor, (int) sz);
        cursor += sz;
        return(int) sz;
    };
    
#line 258
    Lang::int64 MemReadStream::GetCursor()
    {
#line 258
        return cursor;
    };
    
#line 260
    Lang::int64 MemReadStream::GetSize() const
    {
#line 260
        return size;
    };
    
#line 247
    bool MemReadStream::IsEof()
    {
#line 247
        return cursor >= size;
    };
    
#line 245
    bool MemReadStream::IsLoading()
    {
#line 245
        return true;
    };
    
#line 246
    bool MemReadStream::IsStoring()
    {
#line 246
        return false;
    };
    
#line 259
    void MemReadStream::Seek(Lang::int64 i)
    {
#line 259
        cursor = i;
    };
    
#line 190
    StringStream::StringStream()
    :
        cursor(0),
        is_storing(true)
    {};
    
#line 199
    Abstract::StreamBase& StringStream::operator<< (Text::String str)
    {
#line 200
        Put(str.Begin(), str.GetCount());
        return *this;
    };
    
#line 203
    Abstract::StreamBase& StringStream::operator<< (int i)
    {
#line 204
        Text::String str = Text::String::IntStr(i);
        Put(str.Begin(), str.GetCount());
        return *this;
    };
    
#line 220
    int StringStream::Get(void *mem, int size)
    {
#line 221
        Lang::int64 sz = Algorithm::Minimum((Lang::int64) size, (Lang::int64) s.GetCount() - cursor);
        if (sz <= 0)
#line 222
            return 0;
        {
#line 223
            if (!(sz < 2147483647))
            {
#line 223
                Lang::SysBreak("Assertion failed: sz < INT_MAX");
            }
        }
#line 224
        ;
#line 224
        char * b = (char * ) mem;
        Lang::Memory::Copy(b, s.Begin() + cursor, (int) sz);
        cursor += sz;
        return(int) sz;
    };
    
#line 229
    Lang::int64 StringStream::GetCursor()
    {
#line 229
        return cursor;
    };
    
#line 233
    Text::String StringStream::GetResult()
    {
#line 233
        return Text::String(s.Begin(), s.GetCount());
    };
    
#line 230
    Lang::int64 StringStream::GetSize() const
    {
#line 230
        return s.GetCount();
    };
    
#line 194
    bool StringStream::IsEof()
    {
#line 194
        return cursor >= s.GetCount();
    };
    
#line 192
    bool StringStream::IsLoading()
    {
#line 192
        return !is_storing;
    };
    
#line 193
    bool StringStream::IsStoring()
    {
#line 193
        return is_storing;
    };
    
#line 219
    int StringStream::Put(char c)
    {
#line 219
        return Put(&c, 1);
    };
    
#line 208
    int StringStream::Put(const void *mem, int size)
    {
#line 209
        Lang::int64 end = cursor + size;
        {
#line 210
            if (!(end < 2147483647))
            {
#line 210
                Lang::SysBreak("Assertion failed: end < INT_MAX");
            }
        }
#line 211
        ;
#line 211
        if (end > s.GetCount())
            s.SetCount((int) end);
        char * dst = s.Begin() + cursor;
        const char * src = (const char * ) mem;
        Lang::Memory::Copy(dst, src, size);
        cursor += size;
        return size;
    };
    
#line 232
    void StringStream::Seek(Lang::int64 i)
    {
#line 232
        cursor = i;
    };
    
#line 298
    VideoFrame::~VideoFrame() {};
    
};

#endif
