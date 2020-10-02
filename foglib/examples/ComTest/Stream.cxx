#ifndef STREAM_CXX
#define STREAM_CXX

#include <new>

#ifndef STREAM_HXX
#include <Stream.hxx>
#endif

namespace Stream
{
#line 263 "../../src/Com/Stream.fog"
    template < class _1 >
    bool LoadFromFile(_1& o, Text::String path)
    {
#line 265
        FileIn fin(path);
        if (!fin.IsOpen())
            return false;
        fin % o;
        return !fin.IsCorrupted();
    };
    
    template < class _1 >
    bool StoreToFile(_1& o, Text::String path)
    {
#line 274
        FileOut fout(path);
        if (!fout.IsOpen())
            return false;
        fout % o;
        return !fout.IsCorrupted();
    };
    
#line 289
    AudioFrame::~AudioFrame() {};
    
#line 17
    CharStream& CharStream::operator<< (Text::String s)
    {
#line 17
        s.Serialize(*this);
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
    
#line 141
    void FileOut::Close()
    {
#line 142
        if (s)
        {
#line 142
            Native::FileFlush(s);
#line 142
            Native::FileClose(s);
#line 142
            s = 0;
        }
    };
    
#line 163
    void FileOut::Flush()
    {
#line 163
        if (s)
#line 163
            Native::FileFlush(s);
    };
    
#line 165
    Lang::int64 FileOut::GetCursor()
    {
#line 165
        if (!s)
#line 165
            return 0;
#line 165
        return Native::FileTell(s);
    };
    
#line 167
    Lang::int64 FileOut::GetSize() const
    {
#line 168
        if (!s)
#line 168
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
    bool FileOut::Open(Text::String path)
    {
#line 137
        if (s)
#line 137
            Native::FileClose(s);
        return s != 0;
    };
    
#line 161
    int FileOut::Put(char c)
    {
#line 161
        return Put(&c, 1);
    };
    
#line 155
    int FileOut::Put(const void *mem, int size)
    {
#line 156
        if (!s)
#line 156
            return 0;
        Lang::int64 ret = Native::FileWrite(mem, size, 1, s) * size;
        {
#line 158
            if (!(ret < 2147483647))
            {
#line 158
                Lang::SysBreak("Assertion failed: ret < INT_MAX");
            }
        }
#line 159
        ;
#line 159
        return(int) ret;
    };
    
#line 307
    Text::String MediaStream::GetLastError() const
    {
#line 307
        return "unknown";
    };
    
#line 242
    MemReadStream::MemReadStream(const char *buf, Lang::int64 size)
    :
        buf(buf),
        size(size),
        cursor(0)
    {};
    
#line 248
    int MemReadStream::Get(void *mem, int size)
    {
#line 249
        Lang::int64 sz = Algorithm::Minimum < Lang::int64 > (size, size - cursor);
        if (sz <= 0)
#line 250
            return 0;
        {
#line 251
            if (!(sz < 2147483647))
            {
#line 251
                Lang::SysBreak("Assertion failed: sz < INT_MAX");
            }
        }
#line 252
        ;
#line 252
        char * b = (char * ) mem;
        Lang::Memory::Copy(b, buf + cursor, (int) sz);
        cursor += sz;
        return(int) sz;
    };
    
#line 257
    Lang::int64 MemReadStream::GetCursor()
    {
#line 257
        return cursor;
    };
    
#line 259
    Lang::int64 MemReadStream::GetSize() const
    {
#line 259
        return size;
    };
    
#line 246
    bool MemReadStream::IsEof()
    {
#line 246
        return cursor >= size;
    };
    
#line 244
    bool MemReadStream::IsLoading()
    {
#line 244
        return true;
    };
    
#line 245
    bool MemReadStream::IsStoring()
    {
#line 245
        return false;
    };
    
#line 258
    void MemReadStream::Seek(Lang::int64 i)
    {
#line 258
        cursor = i;
    };
    
#line 189
    StringStream::StringStream()
    :
        cursor(0),
        is_storing(true)
    {};
    
#line 198
    Abstract::StreamBase& StringStream::operator<< (Text::String str)
    {
#line 199
        Put(str.Begin(), str.GetCount());
        return *this;
    };
    
#line 202
    Abstract::StreamBase& StringStream::operator<< (int i)
    {
#line 203
        Text::String str = Text::String::IntStr(i);
        Put(str.Begin(), str.GetCount());
        return *this;
    };
    
#line 219
    int StringStream::Get(void *mem, int size)
    {
#line 220
        Lang::int64 sz = Algorithm::Minimum((Lang::int64) size, (Lang::int64) s.GetCount() - cursor);
        if (sz <= 0)
#line 221
            return 0;
        {
#line 222
            if (!(sz < 2147483647))
            {
#line 222
                Lang::SysBreak("Assertion failed: sz < INT_MAX");
            }
        }
#line 223
        ;
#line 223
        char * b = (char * ) mem;
        Lang::Memory::Copy(b, s.Begin() + cursor, (int) sz);
        cursor += sz;
        return(int) sz;
    };
    
#line 228
    Lang::int64 StringStream::GetCursor()
    {
#line 228
        return cursor;
    };
    
#line 232
    Text::String StringStream::GetResult()
    {
#line 232
        return Text::String(s.Begin(), s.GetCount());
    };
    
#line 229
    Lang::int64 StringStream::GetSize() const
    {
#line 229
        return s.GetCount();
    };
    
#line 193
    bool StringStream::IsEof()
    {
#line 193
        return cursor >= s.GetCount();
    };
    
#line 191
    bool StringStream::IsLoading()
    {
#line 191
        return !is_storing;
    };
    
#line 192
    bool StringStream::IsStoring()
    {
#line 192
        return is_storing;
    };
    
#line 218
    int StringStream::Put(char c)
    {
#line 218
        return Put(&c, 1);
    };
    
#line 207
    int StringStream::Put(const void *mem, int size)
    {
#line 208
        Lang::int64 end = cursor + size;
        {
#line 209
            if (!(end < 2147483647))
            {
#line 209
                Lang::SysBreak("Assertion failed: end < INT_MAX");
            }
        }
#line 210
        ;
#line 210
        if (end > s.GetCount())
            s.SetCount((int) end);
        char * dst = s.Begin() + cursor;
        const char * src = (const char * ) mem;
        Lang::Memory::Copy(dst, src, size);
        cursor += size;
        return size;
    };
    
#line 231
    void StringStream::Seek(Lang::int64 i)
    {
#line 231
        cursor = i;
    };
    
#line 297
    VideoFrame::~VideoFrame() {};
    
};

#endif
