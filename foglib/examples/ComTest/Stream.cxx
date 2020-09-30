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

#ifndef STREAM_CXX
#define STREAM_CXX

#include <new>

#ifndef STREAM_HXX
#include <Stream.hxx>
#endif

namespace Stream
{
#line 20 "../../src/Com/Stream.fog"
    CharStream& CharStream::operator<< (Text::String s)
    {
#line 20
        s.Serialize(*this);
#line 20
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
    
#line 22
    Text::String CharStream::Get(int size)
    {
#line 23
        Container::Vector < char > v;
        v.SetCount(size, 0);
        Get(v.Begin(), size);
        return Text::String(v.Begin());
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
    
#line 61
    void FileIn::Close()
    {
#line 62
        if (s)
#line 62
            fclose(s);
#line 62
        s = 0;
    };
    
    Text::String FileIn::Get(int size)
    {
#line 66
        if (!s || !size)
#line 66
            return Text::String();
        {
#line 67
            if (!(size > 0))
            {
#line 67
                Lang::SysBreak("Assertion failed: size > 0");
            }
        }
#line 68
        ;
#line 68
        int pos = ftell(s);
        Container::Vector < char > v;
        v.SetCount(size + 1, 0);
        char * it = v.Begin();
        int left = size;
        int total_read = 0;
        while (left > 0)
            {
#line 75
                int read_size = (int) fread(it, 1, left, s);
                left -= read_size;
                it += read_size;
                total_read += read_size;
                if (!read_size)
                    break;
            
            }
#line 82
        Text::String out;
        out.SetData(v.Begin(), total_read + 1);
        return out;
    };
    
#line 96
    int FileIn::Get(void *mem, int size)
    {
#line 97
        if (!s)
#line 97
            return 0;
        Lang::int64 ret = fread(mem, size, 1, s) * size;
        {
#line 99
            if (!(ret < 2147483647))
            {
#line 99
                Lang::SysBreak("Assertion failed: ret < INT_MAX");
            }
        }
#line 100
        ;
#line 100
        return(int) ret;
    };
    
    Lang::int64 FileIn::GetCursor()
    {
#line 103
        if (!s)
#line 103
            return 0;
#line 103
        return ftell(s);
    };
    
#line 105
    Lang::int64 FileIn::GetSize() const
    {
#line 106
        if (!s)
#line 106
            return 0;
        long pos = ftell(s);
        fseek(s, 0, SEEK_END);
        int size = ftell(s);
        fseek(s, pos, SEEK_SET);
        return size;
    };
    
#line 87
    Text::String FileIn::GetText(int size)
    {
#line 88
        if (!s)
#line 88
            return "";
        Container::Vector < char > v;
        v.SetCount(size + 1);
        v[size] = 0;
        size_t read_size = fread(v.Begin(), 1, size, s);
        return v.Get();
    };
    
#line 53
    bool FileIn::IsEof()
    {
#line 53
        if (!s)
#line 53
            return true;
#line 53
        return feof(s);
    };
    
#line 51
    bool FileIn::IsLoading()
    {
#line 51
        return true;
    };
    
#line 52
    bool FileIn::IsOpen() const
    {
#line 52
        return s != 0;
    };
    
    bool FileIn::Open(Text::String path)
    {
#line 56
        if (s)
#line 56
            fclose(s);
        fopen_s(&s, path.Begin(), "rb");
        return s != 0;
    };
    
#line 114
    void FileIn::Seek(Lang::int64 pos)
    {
#line 114
        fseek(s, (long) pos, SEEK_SET);
    };
    
};

#endif
