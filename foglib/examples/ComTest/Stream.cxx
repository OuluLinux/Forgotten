#ifndef STREAM_CXX
#define STREAM_CXX

#include <new>

#ifndef STREAM_HXX
#include <Stream.hxx>
#endif

namespace Stream
{
#line 310 "../../src/Com/Stream.fog"
    template < class _1 >
    bool LoadFromFile(_1& o, Text::String path)
    {
#line 312
        FileIn fin(path);
        if (!fin.IsOpen())
            return false;
        fin % o;
        return !fin.IsCorrupted();
    };
    
    template < class _1 >
    bool StoreToFile(_1& o, Text::String path)
    {
#line 321
        FileOut fout(path);
        if (!fout.IsOpen())
            return false;
        fout % o;
        return !fout.IsCorrupted();
    };
    
#line 336
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
    
#line 354
    Text::String MediaStream::GetLastError() const
    {
#line 354
        return "unknown";
    };
    
#line 289
    MemReadStream::MemReadStream(const char *buf, Lang::int64 size)
    :
        buf(buf),
        size(size),
        cursor(0)
    {};
    
#line 295
    int MemReadStream::Get(void *mem, int size)
    {
#line 296
        Lang::int64 sz = Algorithm::Minimum < Lang::int64 > (size, size - cursor);
        if (sz <= 0)
#line 297
            return 0;
        {
#line 298
            if (!(sz < 2147483647))
            {
#line 298
                Lang::SysBreak("Assertion failed: sz < INT_MAX");
            }
        }
#line 299
        ;
#line 299
        char * b = (char * ) mem;
        Lang::Memory::Copy(b, buf + cursor, (int) sz);
        cursor += sz;
        return(int) sz;
    };
    
#line 304
    Lang::int64 MemReadStream::GetCursor()
    {
#line 304
        return cursor;
    };
    
#line 306
    Lang::int64 MemReadStream::GetSize() const
    {
#line 306
        return size;
    };
    
#line 293
    bool MemReadStream::IsEof()
    {
#line 293
        return cursor >= size;
    };
    
#line 291
    bool MemReadStream::IsLoading()
    {
#line 291
        return true;
    };
    
#line 292
    bool MemReadStream::IsStoring()
    {
#line 292
        return false;
    };
    
#line 305
    void MemReadStream::Seek(Lang::int64 i)
    {
#line 305
        cursor = i;
    };
    
#line 190
    StringStream::StringStream()
    :
        cursor(0),
        is_storing(true)
    {};
    
#line 212
    int StringStream::Get(void *mem, int size)
    {
#line 213
        Lang::int64 sz = Algorithm::Minimum((Lang::int64) size, (Lang::int64) s.GetCount() - cursor);
        if (sz <= 0)
#line 214
            return 0;
        {
#line 215
            if (!(sz < 2147483647))
            {
#line 215
                Lang::SysBreak("Assertion failed: sz < INT_MAX");
            }
        }
#line 216
        ;
#line 216
        char * b = (char * ) mem;
        Lang::Memory::Copy(b, s.Begin() + cursor, (int) sz);
        cursor += sz;
        return(int) sz;
    };
    
#line 221
    Lang::int64 StringStream::GetCursor()
    {
#line 221
        return cursor;
    };
    
#line 226
    Text::String StringStream::GetResult() const
    {
#line 226
        return Text::String(s.Begin(), s.GetCount());
    };
    
#line 222
    Lang::int64 StringStream::GetSize() const
    {
#line 222
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
    
#line 211
    int StringStream::Put(char c)
    {
#line 211
        return Put(&c, 1);
    };
    
#line 200
    int StringStream::Put(const void *mem, int size)
    {
#line 201
        Lang::int64 end = cursor + size;
        {
#line 202
            if (!(end < 2147483647))
            {
#line 202
                Lang::SysBreak("Assertion failed: end < INT_MAX");
            }
        }
#line 203
        ;
#line 203
        if (end > s.GetCount())
            s.SetCount((int) end);
        char * dst = s.Begin() + cursor;
        const char * src = (const char * ) mem;
        Lang::Memory::Copy(dst, src, size);
        cursor += size;
        return size;
    };
    
#line 225
    void StringStream::Seek(Lang::int64 i)
    {
#line 225
        cursor = i;
    };
    
#line 344
    VideoFrame::~VideoFrame() {};
    
#line 238
    WStringStream::WStringStream()
    :
        cursor(0),
        is_storing(true)
    {};
    
#line 263
    int WStringStream::Cat(short c)
    {
#line 263
        return Put(&c, 2);
    };
    
#line 264
    int WStringStream::Get(void *mem, int size)
    {
#line 265
        Lang::int64 sz = Algorithm::Minimum((Lang::int64) size, ((Lang::int64) s.GetCount() - cursor) * 2);
        if (sz <= 1)
#line 266
            return 0;
        {
#line 267
            if (!(sz < 2147483647))
            {
#line 267
                Lang::SysBreak("Assertion failed: sz < INT_MAX");
            }
        }
#line 268
        ;
#line 268
        char * b = (char * ) mem;
        Lang::Memory::Copy(b, s.Begin() + cursor, (int) sz);
        cursor += sz / 2;
        return(int) sz;
    };
    
#line 273
    Lang::int64 WStringStream::GetCursor()
    {
#line 273
        return cursor;
    };
    
#line 278
    Text::WString WStringStream::GetResult() const
    {
#line 278
        return Text::WString(s.Get(), s.GetCount());
    };
    
#line 274
    Lang::int64 WStringStream::GetSize() const
    {
#line 274
        return s.GetCount();
    };
    
#line 242
    bool WStringStream::IsEof()
    {
#line 242
        return cursor >= s.GetCount();
    };
    
#line 240
    bool WStringStream::IsLoading()
    {
#line 240
        return !is_storing;
    };
    
#line 241
    bool WStringStream::IsStoring()
    {
#line 241
        return is_storing;
    };
    
#line 262
    int WStringStream::Put(char c)
    {
        {
#line 262
            if (!(false))
            {
#line 262
                Lang::SysBreak("Assertion failed: Not supported");
            }
        }
#line 262
        ;
#line 262
        return Put(&c, 1);
    };
    
#line 247
    int WStringStream::Put(const void *mem, int size)
    {
        {
#line 248
            if (!(size % 2 == 0))
            {
#line 248
                Lang::SysBreak("Assertion failed: size % 2 == 0");
            }
        }
#line 249
        ;
#line 249
        if (size / 2 == 0 || size % 2 != 0)
            return 0;
        int chars = size / 2;
        Lang::int64 end = cursor + chars;
        {
#line 253
            if (!(end < 2147483647))
            {
#line 253
                Lang::SysBreak("Assertion failed: end < INT_MAX");
            }
        }
#line 254
        ;
#line 254
        if (end > s.GetCount())
            s.SetCount((int) end);
        short * dst = s.Begin() + cursor;
        const short * src = (const short * ) mem;
        Lang::Memory::Copy(dst, src, size);
        cursor += chars;
        return size;
    };
    
#line 277
    void WStringStream::Seek(Lang::int64 i)
    {
#line 277
        cursor = i;
    };
    
};

#endif
