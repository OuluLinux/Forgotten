/*!$@FOG@$!
 *	Generated at Sun Sep 27 07:48:06 2020
 *
 *	by fog 0.1.a of 08:09:34 Sep 23 2020
 *
 *	from
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Concurrency.fog
 *		../../src/Com/Defs.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Math.fog
 *		../../src/Com/Meta.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/Stream.fog
 *		../../src/Com/String.fog
 *		/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog
 */

#ifndef COM_CXX
#define COM_CXX

#ifndef COM_HXX
#include <Com.hxx>
#endif

namespace Com
{
#line 79 "../../src/Com/Algorithm.fog"
    template < class _1, class _2 >
    _1 FindIf(_1 begin, _1 end, bool(*fn)(_2& , void *), void *arg)
    {
#line 81
        while (begin != end)
            {
#line 82
                if (fn(*begin, arg))
                    return begin;
                begin ++ ;
            }
        return end;
    };
    
#line 13 "../../src/Com/Hash.fog"
    CombineHash::CombineHash(int v0, int v1)
    :
        hash(123456789)
    {
#line 13
        Put(v0);
#line 13
        Put(v1);
    };
    
#line 18
    CombineHash& CombineHash::Put(int value)
    {
#line 18
        hash = ((hash << 5) + hash) + value;
#line 18
        return *this;
    };
    
#line 19
    CombineHash& CombineHash::Put64(int64 value)
    {
#line 19
        Put((int)(value >> 32));
#line 19
        Put((int)(value & 0xFFFFFFFFULL));
#line 19
        return *this;
    };
    
#line 12 "../../src/Com/Environment.fog"
    void Env::Init(int argc, const char **argv)
    {
#line 13
        SetExeFilePath(argv[0]);
        ParseCommandLine(argc, argv);
        ReadComCmdlineArgs();
        RunInitBlocks();
    };
    
#line 56 "../../src/Com/Algorithm.fog"
    double RNG::Randomf()
    {
#line 56
        return(sNext(state) >> 11) * (1. / (((uint64)1) << 53));
    };
    
#line 61
    void RNG::Seed(dword seed)
    {
#line 62
        for (int i = 0; i < 4; i ++ )
            state[i] = 12345678 + seed + i;
    };
    
#line 26
    uint64 RNG::sNext(uint64 *s)
    {
#line 27
        const uint64 result_starstar = s_rotl(s[1] * 5, 7) * 9;
        const uint64 t = s[1] << 17;
#line 30
        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];
#line 35
        s[2] ^= t;
#line 37
        s[3] = s_rotl(s[3], 45);
#line 39
        return result_starstar;
    };
    
    void RNG::sSeed(uint64 *s)
    {
#line 43
        for (int pass = 0; pass < 4; pass ++ )
            {
#line 44
                for (int i = 0; i < 4; i ++ )
                    {
#line 45
                        CombineHash h;
                        h.Put64(NativeCurrentTime());
                        h.Put64(NativeNanoSeconds());
                        h.Put64(NativeMilliSeconds());
                        s[i] ^= h;
                    }
            }
    };
    
#line 22
    uint64 RNG::s_rotl(const uint64 x, int k)
    {
#line 23
        return(x << k) | (x >> (64 - k));
    };
    
#line 97 "../../src/Com/String.fog"
    String::String()
    :
        is_ref(false),
        count(0)
    {
#line 97
        Zero();
    };
    
    String::String(const String& s)
    :
        is_ref(false),
        count(0)
    {
#line 100
        Zero();
#line 100
        *this = s;
    };
    
#line 98
    String::String(const Char *c)
    :
        is_ref(false),
        count(0)
    {
#line 98
        Zero();
#line 98
        *this = c;
    };
    
#line 99
    String::String(const Char *c, int len)
    :
        is_ref(false),
        count(0)
    {
#line 99
        Zero();
#line 99
        Set(c, len);
    };
    
#line 101
    String::~String()
    {
#line 101
        Clear();
    };
    
#line 423
    String String::operator+ (const String& s)
    {
#line 423
        String out(*this);
#line 423
        out.Cat(s);
#line 423
        return out;
    };
    
#line 148
    String String::operator+ (const String& l) const
    {
#line 149
        String s(*this);
        s.Cat(l);
        return s;
    };
    
#line 130
    String& String::operator= (const String& str)
    {
#line 131
        if (!str.is_ref)
        {
#line 132
            Clear();
            MemoryCopy(buf, str.buf, sizeof (buf));
            is_ref = false;
        }
        else
        {
#line 137
            if (is_ref && ref[0] == str.ref[0])
                return *this;
            Clear();
            is_ref = true;
            str.ref[0] -> Inc();
            ref[0] = str.ref[0];
        }
        count = str.count;
        return *this;
    };
    
#line 410
    bool String::operator== (const String& s) const
    {
#line 411
        if (s.GetCount() != GetCount())
#line 411
            return false;
        if (s.IsEmpty())
#line 412
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 418
    String::Char String::At(int i) const
    {
        {
#line 418
            if (!(i >= 0 && i < count))
            {
#line 418
                Break("Assertion failed: i >= 0 && i < count");
            }
        }
#line 418
        ;
#line 418
        return *(Begin() + i);
    };
    
#line 407
    const String::Char *String::Begin() const
    {
#line 407
        if (is_ref)
#line 407
            return ref[0] -> Get();
        else
#line 407
            return buf;
    };
    
#line 160
    String& String::Cat(Char i)
    {
#line 161
        if (!is_ref)
        {
#line 162
            is_ref = count + 1 >= 8;
            if (!is_ref)
            {
#line 164
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
            }
            else
            {
#line 169
                Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (count + 1 + 1));
                MemoryCopy(buf, this -> buf, sizeof (Char) * count);
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
                ref[0] = new RefData(buf, count + 1);
                is_ref = true;
            }
        }
        else
        {
#line 179
            if (ref[0] -> GetRefs() == 1)
            {
#line 180
                int new_count = count + 1 + 1;
                if (new_count > ref[0] -> GetReserved())
                    ref[0] -> IncreaseReserved();
                Char * c = ref[0] -> Begin();
                c[count] = i;
                count ++ ;
                c[count] = 0;
            }
            else
            {
#line 189
                Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (count + 1 + 1));
                MemoryCopy(buf, ref[0] -> Get(), sizeof (Char) * count);
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
                ref[0] -> Dec();
                ref[0] = new RefData(buf, count + 1);
            }
        }
        return *this;
    };
    
#line 154
    String& String::Cat(Char c, int count)
    {
        for (int i = 0; i < count; i ++ )
#line 156
            Cat(c);
        return *this;
    };
    
#line 203
    String& String::Cat(const String& str)
    {
#line 204
        if (!is_ref)
        {
#line 205
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 207
                MemoryCopy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 211
                int reserved = count + str.GetCount() + 1;
                Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (reserved));
                MemoryCopy(buf, this -> buf, sizeof (Char) * count);
                MemoryCopy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
                ref[0] = new RefData(buf, reserved);
                is_ref = true;
            }
        }
        else
        {
#line 221
            if (ref[0] -> GetRefs() == 1)
            {
#line 222
                int new_count = count + str.GetCount() + 1;
                if (new_count > ref[0] -> GetReserved())
                    ref[0] -> IncreaseReserved(new_count);
                Char * c = ref[0] -> Begin();
                MemoryCopy(c + count, str.Begin(), sizeof (Char) * str.GetCount());
                count += str.GetCount();
                c[count] = 0;
            }
            else
            {
#line 231
                int reserved = count + str.GetCount() + 1;
                Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (reserved));
                MemoryCopy(buf, ref[0] -> Get(), sizeof (Char) * count);
                MemoryCopy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
                buf[count] = 0;
                ref[0] -> Dec();
                ref[0] = new RefData(buf, reserved);
            }
        }
        return *this;
    };
    
#line 527
    double String::CharDbl(const Char *s)
    {
#line 528
        double a = 0.0;
        int e = 0;
        int c;
#line 532
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 533
                a = a * 10.0 + (c - '0');
            }
#line 536
        if (c == '.')
        {
#line 537
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 538
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 543
        if (c == 'e' || c == 'E')
        {
#line 544
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 548
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 552
                c = *s ++ ;
                sign = - 1;
            }
#line 556
            while (IsDigit(c))
                {
#line 557
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 561
            e += i * sign;
        }
#line 564
        while (e > 0)
            {
#line 565
                a *= 10.0;
                e -- ;
            }
#line 569
        while (e < 0)
            {
#line 570
                a *= 0.1;
                e ++ ;
            }
#line 574
        return a;
    };
    
#line 473
    int String::CharHexInt(const Char *s)
    {
#line 474
        if (!s)
#line 474
            return 0;
        while (IsSpace(*s))
#line 475
            s ++ ;
        int n = 0;
#line 476
        int neg = 0;
        switch (*s)
        {
#line 478
            case '-':
#line 478
                neg = 1;
            case '+':
#line 479
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 485
            return n;
        else
#line 485
            return - n;
    };
    
    int String::CharInt(const Char *s)
    {
        int n = 0;
#line 490
        int neg = 0;
        while (IsSpace(*s))
#line 491
            s ++ ;
        switch (*s)
        {
#line 493
            case '-':
#line 493
                neg = 1;
            case '+':
#line 494
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 498
            return n;
        else
#line 498
            return - n;
    };
    
    int64 String::CharInt64(const Char *s)
    {
        int64 n = 0;
#line 503
        int64 neg = 0;
        while (IsSpace(*s))
#line 504
            s ++ ;
        switch (*s)
        {
#line 506
            case '-':
#line 506
                neg = 1;
            case '+':
#line 507
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 511
            return n;
        else
#line 511
            return - n;
    };
    
    uint64 String::CharIntU64(const Char *s)
    {
        uint64 n = 0;
        while (IsSpace(*s))
#line 517
            s ++ ;
        switch (*s)
        {
#line 519
            case '-':
#line 519
                return 0;
            case '+':
#line 520
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 459
    int String::CharOctInt(const Char *s)
    {
#line 460
        if (!s)
#line 460
            return 0;
        while (IsSpace(*s))
#line 461
            s ++ ;
        int n = 0;
#line 462
        int neg = 0;
        switch (*s)
        {
#line 464
            case '-':
#line 464
                neg = 1;
            case '+':
#line 465
                s ++ ;
        }
        while (*s == '0')
#line 467
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 470
            return n;
        else
#line 470
            return - n;
    };
    
#line 104
    void String::Clear()
    {
#line 105
        if (is_ref)
        {
#line 105
            ref[0] -> Dec();
#line 105
            ref[0] = 0;
#line 105
            is_ref = false;
        }
        else
        {
#line 106
            ref[0] = 0;
        }
#line 107
        count = 0;
    };
    
#line 653
    int String::Compare(const Char *a, const Char *b)
    {
#line 654
        while (*a || *b)
            {
#line 655
                Char ac = *a ++ ;
                Char bc = *b ++ ;
                int diff = ac - bc;
                if (diff)
                    return diff;
            }
        return 0;
    };
    
    int String::Compare(const Char *a, const Char *b, int len)
    {
#line 665
        while ((*a || *b) && len > 0)
            {
#line 666
                Char ac = *a ++ ;
                Char bc = *b ++ ;
                int diff = ac - bc;
                if (diff)
                    return diff;
                len -- ;
            }
        return 0;
    };
    
    void String::Copy(Char *dst, const Char *src)
    {
        {
#line 677
            if (!(dst && src))
            {
#line 677
                Break("Assertion failed: dst && src");
            }
        }
#line 678
        ;
#line 678
        if (!dst || !src)
#line 678
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 443
    String String::DblStr(double d)
    {
#line 444
        Char output[50];
        NativeDblStr(d, output, 50);
        return String(output);
    };
    
#line 284
    int String::Find(const String& str, int pos) const
    {
#line 285
        if (GetCount() == 0)
#line 285
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 288
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 288
                Break("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 289
        ;
#line 289
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 293
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 311
    int String::FindFirstNotOf(const Char *str) const
    {
#line 312
        if (GetCount() <= 0 || !str)
#line 312
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 317
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 321
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 324
                        if (chr == cmp_chr)
                        {
#line 325
                            match = true;
                            break;
                        
                        }
                    }
#line 329
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 451
    uint32 String::GetHashValue() const
    {
#line 452
        CombineHash ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 389
    bool String::Insert(int begin, const Char *str, int n)
    {
#line 390
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 392
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 392
                Break("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 393
        ;
#line 393
        begin = max(0, min(begin, GetCount()));
        String part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 399
        if (l)
            *this = Left(l) + part;
        else 
#line 401
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 577
    const String::Char *String::IntChar(Char *p, int bufsize, int x)
    {
#line 578
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 581
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 586
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 590
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const String::Char *String::IntChar64(Char *p, int bufsize, int64 x)
    {
#line 596
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 599
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 604
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 608
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const String::Char *String::IntCharU64(Char *p, int bufsize, uint64 x)
    {
#line 614
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 617
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 622
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 626
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
#line 431
    String String::IntStr(int i)
    {
#line 432
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return String(value);
    };
    
    String String::IntStr64(int64 i)
    {
#line 438
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return String(value);
    };
    
#line 632
    int String::Length(const Char *c, int max_len)
    {
        {
#line 633
            if (!(c))
            {
#line 633
                Break("Assertion failed: c");
            }
        }
#line 634
        ;
#line 634
        if (!c)
#line 634
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 637
            while (*c)
                {
#line 638
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 644
            while (max_len > 0 && *c)
                {
#line 645
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 359
    String String::Mid(int i) const
    {
#line 359
        if (i >= GetCount())
#line 359
            return Empty();
#line 359
        if (i < 0)
#line 359
            i = 0;
#line 359
        return Mid(i, GetCount() - i);
    };
    
#line 360
    String String::Mid(int i, int size) const
    {
#line 361
        size = min(size, count - i);
        if (size <= 0)
#line 362
            return String();
        {
#line 363
            if (!(i >= 0 && i + size <= count))
            {
#line 363
                Break("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 364
        ;
#line 364
        return String(Begin() + i, size);
    };
    
#line 369
    void String::Remove(int begin, int count)
    {
        {
#line 370
            if (!(begin >= 0 && count >= 0))
            {
#line 370
                Break("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 371
        ;
#line 371
        begin = max(0, begin);
        count = max(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 375
            if (!(begin <= c && end <= c))
            {
#line 375
                Break("Assertion failed: begin <= c && end <= c");
            }
        }
#line 376
        ;
#line 376
        end = min(c, end);
        begin = min(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 382
        if (l)
            *this = Left(l);
        else 
#line 384
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 244
    void String::Replace(const String& s, const String& value)
    {
#line 245
        if (s == value)
#line 245
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 248
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void String::Replace(int i, int len, const String& value)
    {
#line 254
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 260
            MemoryCopy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 264
            MemoryCopy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 270
            MemoryCopy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 275
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        {
#line 279
            if (!(cursor == new_len + 1))
            {
#line 279
                Break("Assertion failed: cursor == new_len+1");
            }
        }
#line 280
        ;
    };
    
#line 299
    int String::ReverseFind(const String& str, int pos) const
    {
#line 300
        if (GetCount() == 0)
#line 300
            return - 1;
        {
#line 301
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 301
                Break("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 302
        ;
#line 302
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 306
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 335
    int String::ReverseFindFirstNotOf(const Char *str) const
    {
#line 336
        if (GetCount() <= 0 || !str)
#line 336
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 341
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 345
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 348
                        if (chr == cmp_chr)
                        {
#line 349
                            match = true;
                            break;
                        
                        }
                    }
#line 353
                i -- ;
                if (!match)
                    return i;
            }
        return - 1;
    };
    
#line 111
    String& String::Set(const Char *c, int len)
    {
#line 112
        Clear();
        if (!c)
#line 113
            return *this;
        count = min(StringLength(c, len), len);
        if (count < 8)
        {
#line 116
            MemoryCopy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
        }
        else
        {
#line 120
            Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (count + 1));
            MemoryCopy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
            ref[0] = new RefData(buf, count + 1);
            ref[0] -> Inc();
            is_ref = true;
        }
        return *this;
    };
    
#line 92
    void String::Zero()
    {
#line 54 "../../src/Com/Meta.fog"
        MemorySet(this, 0, sizeof (String));
    };
    
#line 36 "../../src/Com/String.fog"
    String::RefData::RefData(Char *str, int reserved)
    :
        data(str),
        reserved(reserved)
    {};
    
#line 37
    String::RefData::~RefData()
    {
#line 37
        Clear();
    };
    
#line 74
    String::RefData::operator ConstChar * () const
    {
#line 74
        return data;
    };
    
#line 73
    String::Char *String::RefData::Begin()
    {
#line 73
        return data;
    };
    
#line 39
    void String::RefData::Clear()
    {
#line 39
        if (data)
        {
#line 39
            MemoryFree(data);
#line 39
            data = 0;
#line 39
            refs = 0;
#line 39
            reserved = 0;
        }
    };
    
#line 49 "../../src/Com/Meta.fog"
    void String::RefData::Dec()
    {
#line 49
        refs -- ;
#line 49
        if (refs <= 0)
#line 49
            delete this;
    };
    
#line 72 "../../src/Com/String.fog"
    String::ConstChar *String::RefData::Get() const
    {
#line 72
        return data;
    };
    
#line 47 "../../src/Com/Meta.fog"
    int String::RefData::GetRefs() const
    {
#line 47
        return refs;
    };
    
#line 76 "../../src/Com/String.fog"
    int String::RefData::GetReserved() const
    {
#line 76
        return reserved;
    };
    
#line 48 "../../src/Com/Meta.fog"
    void String::RefData::Inc()
    {
#line 48
        refs ++ ;
    };
    
#line 41 "../../src/Com/String.fog"
    void String::RefData::IncreaseReserved()
    {
#line 42
        uint64 new_reserved = 1;
        while (new_reserved <= reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void String::RefData::IncreaseReserved(int min_reserved)
    {
#line 51
        uint64 new_reserved = 1;
        while (new_reserved <= min_reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void String::RefData::Reserve(int new_reserved)
    {
#line 60
        if (new_reserved <= reserved)
            return;
        Char * new_data = (Char * ) MemoryAlloc(new_reserved * sizeof (Char));
        if (data)
        {
#line 64
            if (reserved > 0)
                MemoryCopy(new_data, data, sizeof (Char) * reserved);
            MemoryFree(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
#line 17 "/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog"
    void Tester::Run()
    {
#line 18
        uint64 v = 4294967295U;
        {
#line 19
            if (!(sizeof (v) == 8))
            {
#line 19
                Break("Assertion failed: sizeof(v) == 8");
            }
        }
#line 20
        ;
        VoidPtr p;
        {
#line 22
            if (!(p == Null))
            {
#line 22
                Break("Assertion failed: p == Null");
            }
        }
#line 23
        ;
        {
#line 24
            if (!(SignificantBits(0x8000) == 16))
            {
#line 24
                Break("Assertion failed: SignificantBits(0x8000) == 16");
            }
        }
#line 25
        ;
        {
#line 25
            if (!(SignificantBits64(0x8000) == 16))
            {
#line 25
                Break("Assertion failed: SignificantBits64(0x8000) == 16");
            }
        }
#line 26
        ;
        CombineHash ch;
        ch.Put(777999777).Put(123).Put64(0xF0F0F0F0F0F0F0F0);
        dword hash = ch;
        {
#line 30
            if (!(hash == 1894504625))
            {
#line 30
                Break("Assertion failed: hash == 1894504625");
            }
        }
#line 31
        ;
#line 31
        int a = 0;
        int b = 1;
        {
#line 33
            if (!(min(a, b) < max(a, b)))
            {
#line 33
                Break("Assertion failed: min(a, b) < max(a, b)");
            }
        }
#line 34
        ;
        int r = Random();
        double d = Randomf();
        int j = d;
#line 39
        const char * test_str = "abcdef";
        int test_strlen = StringLength(test_str);
        {
#line 41
            if (!(FindIf(test_str, test_str + test_strlen, &TestCmp)))
            {
#line 41
                Break("Assertion failed: FindIf(test_str, test_str + test_strlen, &TestCmp)");
            }
        }
#line 42
        ;
        {
            if (!(String("test") == "test"))
            {
#line 44
                Break("Assertion failed: String(\"test\") == \"test\"");
            }
        }
#line 45
        ;
        {
#line 45
            if (!(String::DblStr(1.2) == "1.2"))
            {
#line 45
                Break("Assertion failed: String::DblStr(1.2) == \"1.2\"");
            }
        }
#line 46
        ;
        {
#line 46
            if (!("abc" + String("def") == "abcdef"))
            {
#line 46
                Break("Assertion failed: \"abc\" + String(\"def\") == \"abcdef\"");
            }
        }
#line 47
        ;
        {
#line 47
            if (!(String("abc") + "def" == "abcdef"))
            {
#line 47
                Break("Assertion failed: String(\"abc\") + \"def\" == \"abcdef\"");
            }
        }
#line 48
        ;
        {
#line 48
            if (!(ToString(ToWString < String > ("abc")) == "abc"))
            {
#line 48
                Break("Assertion failed: ToString(ToWString<String>(\"abc\")) == \"abc\"");
            }
        }
#line 49
        ;
        {
#line 49
            if (!(ToInt < String > ("123") == 123))
            {
#line 49
                Break("Assertion failed: ToInt<String>(\"123\") == 123");
            }
        }
#line 50
        ;
        {
#line 50
            if (!(ToString(123) == "123"))
            {
#line 50
                Break("Assertion failed: ToString(123) == \"123\"");
            }
        }
#line 51
        ;
        {
#line 51
            if (!(HexStr((void * )0x123f) == "0x123F"))
            {
#line 51
                Break("Assertion failed: HexStr((void*)0x123f) == \"0x123F\"");
            }
        }
#line 52
        ;
#line 54
        SomeTuple2 ttt = 
        {
            1,
            1.2
        };
        {
#line 55
            if (!(ToString(ttt) == "1, 1.2"))
            {
#line 55
                Break("Assertion failed: ToString(ttt) == \"1, 1.2\"");
            }
        }
#line 56
        ;
        SomeRefTuple2 tttref(ttt.a, ttt.b);
        {
#line 58
            if (!(ToString(tttref) == "1, 1.2"))
            {
#line 58
                Break("Assertion failed: ToString(tttref) == \"1, 1.2\"");
            }
        }
#line 59
        ;
    };
    
#line 28 "../../src/Com/Meta.fog"
    Tester::SomeRefTuple2::SomeRefTuple2(int& a, double& b)
    :
        a(a),
        b(b)
    {};
    
#line 29
    String Tester::SomeRefTuple2::ToString() const
    {
#line 29
        return Com::ToString(a) + ", " + Com::ToString(b);
    };
    
#line 9
    String Tester::SomeTuple2::ToString() const
    {
#line 9
        return Com::ToString(a) + ", " + Com::ToString(b);
    };
    
#line 97 "../../src/Com/String.fog"
    WString::WString()
    :
        is_ref(false),
        count(0)
    {
#line 97
        Zero();
    };
    
    WString::WString(const WString& s)
    :
        is_ref(false),
        count(0)
    {
#line 100
        Zero();
#line 100
        *this = s;
    };
    
#line 98
    WString::WString(const Char *c)
    :
        is_ref(false),
        count(0)
    {
#line 98
        Zero();
#line 98
        *this = c;
    };
    
#line 99
    WString::WString(const Char *c, int len)
    :
        is_ref(false),
        count(0)
    {
#line 99
        Zero();
#line 99
        Set(c, len);
    };
    
#line 101
    WString::~WString()
    {
#line 101
        Clear();
    };
    
#line 423
    WString WString::operator+ (const WString& s)
    {
#line 423
        WString out(*this);
#line 423
        out.Cat(s);
#line 423
        return out;
    };
    
#line 148
    WString WString::operator+ (const WString& l) const
    {
#line 149
        WString s(*this);
        s.Cat(l);
        return s;
    };
    
#line 130
    WString& WString::operator= (const WString& str)
    {
#line 131
        if (!str.is_ref)
        {
#line 132
            Clear();
            MemoryCopy(buf, str.buf, sizeof (buf));
            is_ref = false;
        }
        else
        {
#line 137
            if (is_ref && ref[0] == str.ref[0])
                return *this;
            Clear();
            is_ref = true;
            str.ref[0] -> Inc();
            ref[0] = str.ref[0];
        }
        count = str.count;
        return *this;
    };
    
#line 410
    bool WString::operator== (const WString& s) const
    {
#line 411
        if (s.GetCount() != GetCount())
#line 411
            return false;
        if (s.IsEmpty())
#line 412
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 418
    WString::Char WString::At(int i) const
    {
        {
#line 418
            if (!(i >= 0 && i < count))
            {
#line 418
                Break("Assertion failed: i >= 0 && i < count");
            }
        }
#line 418
        ;
#line 418
        return *(Begin() + i);
    };
    
#line 407
    const WString::Char *WString::Begin() const
    {
#line 407
        if (is_ref)
#line 407
            return ref[0] -> Get();
        else
#line 407
            return buf;
    };
    
#line 160
    WString& WString::Cat(Char i)
    {
#line 161
        if (!is_ref)
        {
#line 162
            is_ref = count + 1 >= 8;
            if (!is_ref)
            {
#line 164
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
            }
            else
            {
#line 169
                Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (count + 1 + 1));
                MemoryCopy(buf, this -> buf, sizeof (Char) * count);
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
                ref[0] = new RefData(buf, count + 1);
                is_ref = true;
            }
        }
        else
        {
#line 179
            if (ref[0] -> GetRefs() == 1)
            {
#line 180
                int new_count = count + 1 + 1;
                if (new_count > ref[0] -> GetReserved())
                    ref[0] -> IncreaseReserved();
                Char * c = ref[0] -> Begin();
                c[count] = i;
                count ++ ;
                c[count] = 0;
            }
            else
            {
#line 189
                Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (count + 1 + 1));
                MemoryCopy(buf, ref[0] -> Get(), sizeof (Char) * count);
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
                ref[0] -> Dec();
                ref[0] = new RefData(buf, count + 1);
            }
        }
        return *this;
    };
    
#line 154
    WString& WString::Cat(Char c, int count)
    {
        for (int i = 0; i < count; i ++ )
#line 156
            Cat(c);
        return *this;
    };
    
#line 203
    WString& WString::Cat(const WString& str)
    {
#line 204
        if (!is_ref)
        {
#line 205
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 207
                MemoryCopy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 211
                int reserved = count + str.GetCount() + 1;
                Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (reserved));
                MemoryCopy(buf, this -> buf, sizeof (Char) * count);
                MemoryCopy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
                ref[0] = new RefData(buf, reserved);
                is_ref = true;
            }
        }
        else
        {
#line 221
            if (ref[0] -> GetRefs() == 1)
            {
#line 222
                int new_count = count + str.GetCount() + 1;
                if (new_count > ref[0] -> GetReserved())
                    ref[0] -> IncreaseReserved(new_count);
                Char * c = ref[0] -> Begin();
                MemoryCopy(c + count, str.Begin(), sizeof (Char) * str.GetCount());
                count += str.GetCount();
                c[count] = 0;
            }
            else
            {
#line 231
                int reserved = count + str.GetCount() + 1;
                Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (reserved));
                MemoryCopy(buf, ref[0] -> Get(), sizeof (Char) * count);
                MemoryCopy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
                buf[count] = 0;
                ref[0] -> Dec();
                ref[0] = new RefData(buf, reserved);
            }
        }
        return *this;
    };
    
#line 527
    double WString::CharDbl(const Char *s)
    {
#line 528
        double a = 0.0;
        int e = 0;
        int c;
#line 532
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 533
                a = a * 10.0 + (c - '0');
            }
#line 536
        if (c == '.')
        {
#line 537
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 538
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 543
        if (c == 'e' || c == 'E')
        {
#line 544
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 548
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 552
                c = *s ++ ;
                sign = - 1;
            }
#line 556
            while (IsDigit(c))
                {
#line 557
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 561
            e += i * sign;
        }
#line 564
        while (e > 0)
            {
#line 565
                a *= 10.0;
                e -- ;
            }
#line 569
        while (e < 0)
            {
#line 570
                a *= 0.1;
                e ++ ;
            }
#line 574
        return a;
    };
    
#line 473
    int WString::CharHexInt(const Char *s)
    {
#line 474
        if (!s)
#line 474
            return 0;
        while (IsSpace(*s))
#line 475
            s ++ ;
        int n = 0;
#line 476
        int neg = 0;
        switch (*s)
        {
#line 478
            case '-':
#line 478
                neg = 1;
            case '+':
#line 479
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 485
            return n;
        else
#line 485
            return - n;
    };
    
    int WString::CharInt(const Char *s)
    {
        int n = 0;
#line 490
        int neg = 0;
        while (IsSpace(*s))
#line 491
            s ++ ;
        switch (*s)
        {
#line 493
            case '-':
#line 493
                neg = 1;
            case '+':
#line 494
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 498
            return n;
        else
#line 498
            return - n;
    };
    
    int64 WString::CharInt64(const Char *s)
    {
        int64 n = 0;
#line 503
        int64 neg = 0;
        while (IsSpace(*s))
#line 504
            s ++ ;
        switch (*s)
        {
#line 506
            case '-':
#line 506
                neg = 1;
            case '+':
#line 507
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 511
            return n;
        else
#line 511
            return - n;
    };
    
    uint64 WString::CharIntU64(const Char *s)
    {
        uint64 n = 0;
        while (IsSpace(*s))
#line 517
            s ++ ;
        switch (*s)
        {
#line 519
            case '-':
#line 519
                return 0;
            case '+':
#line 520
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 459
    int WString::CharOctInt(const Char *s)
    {
#line 460
        if (!s)
#line 460
            return 0;
        while (IsSpace(*s))
#line 461
            s ++ ;
        int n = 0;
#line 462
        int neg = 0;
        switch (*s)
        {
#line 464
            case '-':
#line 464
                neg = 1;
            case '+':
#line 465
                s ++ ;
        }
        while (*s == '0')
#line 467
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 470
            return n;
        else
#line 470
            return - n;
    };
    
#line 104
    void WString::Clear()
    {
#line 105
        if (is_ref)
        {
#line 105
            ref[0] -> Dec();
#line 105
            ref[0] = 0;
#line 105
            is_ref = false;
        }
        else
        {
#line 106
            ref[0] = 0;
        }
#line 107
        count = 0;
    };
    
#line 653
    int WString::Compare(const Char *a, const Char *b)
    {
#line 654
        while (*a || *b)
            {
#line 655
                Char ac = *a ++ ;
                Char bc = *b ++ ;
                int diff = ac - bc;
                if (diff)
                    return diff;
            }
        return 0;
    };
    
    int WString::Compare(const Char *a, const Char *b, int len)
    {
#line 665
        while ((*a || *b) && len > 0)
            {
#line 666
                Char ac = *a ++ ;
                Char bc = *b ++ ;
                int diff = ac - bc;
                if (diff)
                    return diff;
                len -- ;
            }
        return 0;
    };
    
    void WString::Copy(Char *dst, const Char *src)
    {
        {
#line 677
            if (!(dst && src))
            {
#line 677
                Break("Assertion failed: dst && src");
            }
        }
#line 678
        ;
#line 678
        if (!dst || !src)
#line 678
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 443
    WString WString::DblStr(double d)
    {
#line 444
        Char output[50];
        NativeDblStr(d, output, 50);
        return WString(output);
    };
    
#line 284
    int WString::Find(const WString& str, int pos) const
    {
#line 285
        if (GetCount() == 0)
#line 285
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 288
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 288
                Break("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 289
        ;
#line 289
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 293
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 311
    int WString::FindFirstNotOf(const Char *str) const
    {
#line 312
        if (GetCount() <= 0 || !str)
#line 312
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 317
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 321
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 324
                        if (chr == cmp_chr)
                        {
#line 325
                            match = true;
                            break;
                        
                        }
                    }
#line 329
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 451
    uint32 WString::GetHashValue() const
    {
#line 452
        CombineHash ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 389
    bool WString::Insert(int begin, const Char *str, int n)
    {
#line 390
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 392
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 392
                Break("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 393
        ;
#line 393
        begin = max(0, min(begin, GetCount()));
        WString part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 399
        if (l)
            *this = Left(l) + part;
        else 
#line 401
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 577
    const WString::Char *WString::IntChar(Char *p, int bufsize, int x)
    {
#line 578
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 581
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 586
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 590
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const WString::Char *WString::IntChar64(Char *p, int bufsize, int64 x)
    {
#line 596
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 599
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 604
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 608
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const WString::Char *WString::IntCharU64(Char *p, int bufsize, uint64 x)
    {
#line 614
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 617
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 622
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 626
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
#line 431
    WString WString::IntStr(int i)
    {
#line 432
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return WString(value);
    };
    
    WString WString::IntStr64(int64 i)
    {
#line 438
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return WString(value);
    };
    
#line 632
    int WString::Length(const Char *c, int max_len)
    {
        {
#line 633
            if (!(c))
            {
#line 633
                Break("Assertion failed: c");
            }
        }
#line 634
        ;
#line 634
        if (!c)
#line 634
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 637
            while (*c)
                {
#line 638
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 644
            while (max_len > 0 && *c)
                {
#line 645
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 359
    WString WString::Mid(int i) const
    {
#line 359
        if (i >= GetCount())
#line 359
            return Empty();
#line 359
        if (i < 0)
#line 359
            i = 0;
#line 359
        return Mid(i, GetCount() - i);
    };
    
#line 360
    WString WString::Mid(int i, int size) const
    {
#line 361
        size = min(size, count - i);
        if (size <= 0)
#line 362
            return WString();
        {
#line 363
            if (!(i >= 0 && i + size <= count))
            {
#line 363
                Break("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 364
        ;
#line 364
        return WString(Begin() + i, size);
    };
    
#line 369
    void WString::Remove(int begin, int count)
    {
        {
#line 370
            if (!(begin >= 0 && count >= 0))
            {
#line 370
                Break("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 371
        ;
#line 371
        begin = max(0, begin);
        count = max(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 375
            if (!(begin <= c && end <= c))
            {
#line 375
                Break("Assertion failed: begin <= c && end <= c");
            }
        }
#line 376
        ;
#line 376
        end = min(c, end);
        begin = min(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 382
        if (l)
            *this = Left(l);
        else 
#line 384
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 244
    void WString::Replace(const WString& s, const WString& value)
    {
#line 245
        if (s == value)
#line 245
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 248
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void WString::Replace(int i, int len, const WString& value)
    {
#line 254
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 260
            MemoryCopy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 264
            MemoryCopy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 270
            MemoryCopy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 275
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        {
#line 279
            if (!(cursor == new_len + 1))
            {
#line 279
                Break("Assertion failed: cursor == new_len+1");
            }
        }
#line 280
        ;
    };
    
#line 299
    int WString::ReverseFind(const WString& str, int pos) const
    {
#line 300
        if (GetCount() == 0)
#line 300
            return - 1;
        {
#line 301
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 301
                Break("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 302
        ;
#line 302
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 306
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 335
    int WString::ReverseFindFirstNotOf(const Char *str) const
    {
#line 336
        if (GetCount() <= 0 || !str)
#line 336
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 341
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 345
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 348
                        if (chr == cmp_chr)
                        {
#line 349
                            match = true;
                            break;
                        
                        }
                    }
#line 353
                i -- ;
                if (!match)
                    return i;
            }
        return - 1;
    };
    
#line 111
    WString& WString::Set(const Char *c, int len)
    {
#line 112
        Clear();
        if (!c)
#line 113
            return *this;
        count = min(StringLength(c, len), len);
        if (count < 8)
        {
#line 116
            MemoryCopy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
        }
        else
        {
#line 120
            Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (count + 1));
            MemoryCopy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
            ref[0] = new RefData(buf, count + 1);
            ref[0] -> Inc();
            is_ref = true;
        }
        return *this;
    };
    
#line 92
    void WString::Zero()
    {
#line 54 "../../src/Com/Meta.fog"
        MemorySet(this, 0, sizeof (WString));
    };
    
#line 36 "../../src/Com/String.fog"
    WString::RefData::RefData(Char *str, int reserved)
    :
        data(str),
        reserved(reserved)
    {};
    
#line 37
    WString::RefData::~RefData()
    {
#line 37
        Clear();
    };
    
#line 74
    WString::RefData::operator ConstChar * () const
    {
#line 74
        return data;
    };
    
#line 73
    WString::Char *WString::RefData::Begin()
    {
#line 73
        return data;
    };
    
#line 39
    void WString::RefData::Clear()
    {
#line 39
        if (data)
        {
#line 39
            MemoryFree(data);
#line 39
            data = 0;
#line 39
            refs = 0;
#line 39
            reserved = 0;
        }
    };
    
#line 49 "../../src/Com/Meta.fog"
    void WString::RefData::Dec()
    {
#line 49
        refs -- ;
#line 49
        if (refs <= 0)
#line 49
            delete this;
    };
    
#line 72 "../../src/Com/String.fog"
    WString::ConstChar *WString::RefData::Get() const
    {
#line 72
        return data;
    };
    
#line 47 "../../src/Com/Meta.fog"
    int WString::RefData::GetRefs() const
    {
#line 47
        return refs;
    };
    
#line 76 "../../src/Com/String.fog"
    int WString::RefData::GetReserved() const
    {
#line 76
        return reserved;
    };
    
#line 48 "../../src/Com/Meta.fog"
    void WString::RefData::Inc()
    {
#line 48
        refs ++ ;
    };
    
#line 41 "../../src/Com/String.fog"
    void WString::RefData::IncreaseReserved()
    {
#line 42
        uint64 new_reserved = 1;
        while (new_reserved <= reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void WString::RefData::IncreaseReserved(int min_reserved)
    {
#line 51
        uint64 new_reserved = 1;
        while (new_reserved <= min_reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void WString::RefData::Reserve(int new_reserved)
    {
#line 60
        if (new_reserved <= reserved)
            return;
        Char * new_data = (Char * ) MemoryAlloc(new_reserved * sizeof (Char));
        if (data)
        {
#line 64
            if (reserved > 0)
                MemoryCopy(new_data, data, sizeof (Char) * reserved);
            MemoryFree(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
    namespace
    {
#line 715
        String operator+ (const char *c, const String& l)
        {
#line 716
            String s(c);
            s.Cat(l);
            return s;
        };
        
    };
};

#endif
