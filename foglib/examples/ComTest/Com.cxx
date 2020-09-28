/*!$@FOG@$!
 *	Generated at Mon Sep 28 10:34:35 2020
 *
 *	by fog 0.1.a of 08:56:34 Sep 28 2020
 *
 *	from
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Defs.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Lang.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Meta.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/String.fog
 *		../../src/Com/Vector.fog
 *		ComTest.mfog
 */

#ifndef COM_CXX
#define COM_CXX

#include <new>

#ifndef COM_HXX
#include <Com.hxx>
#endif

namespace Com
{
#line 17 "../../src/Com/Defs.fog"
    void Break(const char *msg)
    {
#line 17
        C::SysBreak(msg);
    };
    
#line 11
    void *MemoryAlloc(int sz)
    {
#line 11
        return C::Memory::Alloc(sz);
    };
    
#line 13
    int MemoryCompare(const void *m1, const void *m2, int sz)
    {
#line 13
        return C::Memory::Compare(m1, m2, sz);
    };
    
#line 14
    void *MemoryCopy(void *dest, const void *src, int sz)
    {
#line 14
        return C::Memory::Copy(dest, src, sz);
    };
    
#line 12
    void MemoryFree(void *ptr)
    {
#line 12
        C::Memory::Free(ptr);
    };
    
    void *MemoryMove(void *dest, const void *src, int sz)
    {
#line 15
        return C::Memory::Move(dest, src, sz);
    };
    
#line 16
    void MemorySet(void *dest, int byte_value, int sz)
    {
#line 16
        C::Memory::Set(dest, byte_value, sz);
    };
    
#line 28 "../../src/Com/Vector.fog"
    template < class _1 >
    void Swap(_1& a, _1& b)
    {
#line 30
        uint8 tmp[sizeof (_1)];
        MemoryCopy(tmp, &a, sizeof (_1));
        MemoryCopy(&a, &b, sizeof (_1));
        MemoryCopy(&b, tmp, sizeof (_1));
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
    
#line 64 "../../src/Com/Vector.fog"
    template < class _1 >
    _1 *One < _1 >::operator-> ()
    {
        {
#line 64
            if (!(obj))
            {
#line 64
                Break("Assertion failed: obj");
            }
        }
#line 64
        ;
#line 64
        return obj;
    };
    
#line 65
    template < class _1 >
    const _1 *One < _1 >::operator-> () const
    {
        {
#line 65
            if (!(obj))
            {
#line 65
                Break("Assertion failed: obj");
            }
        }
#line 65
        ;
#line 65
        return obj;
    };
    
#line 75
    template < class _1 >
    One < _1 >::operator ConstT & () const
    {
        {
#line 75
            if (!(obj))
            {
#line 75
                Break("Assertion failed: obj");
            }
        }
#line 75
        ;
#line 75
        return *obj;
    };
    
#line 74
    template < class _1 >
    One < _1 >::operator _1 & ()
    {
        {
#line 74
            if (!(obj))
            {
#line 74
                Break("Assertion failed: obj");
            }
        }
#line 74
        ;
#line 74
        return *obj;
    };
    
#line 71
    template < class _1 >
    _1 *One < _1 >::Detach()
    {
        {
#line 71
            if (!(obj))
            {
#line 71
                Break("Assertion failed: obj");
            }
        }
#line 71
        ;
#line 71
        _1 * tmp = obj;
#line 71
        obj = 0;
#line 71
        return tmp;
    };
    
#line 124
    template < class _1 >
    Optional < _1 >::Optional(const Optional& opt)
    :
        obj(0)
    {
#line 124
        if (opt.obj)
#line 124
            this -> obj = new _1(*opt.obj);
    };
    
#line 128
    template < class _1 >
    Optional < _1 >::Optional(const PickT& n)
    :
        obj(0)
    {
#line 128
        *this = n;
    };
    
#line 125
    template < class _1 >
    Optional < _1 >::Optional(const _1& obj)
    :
        obj(0)
    {
#line 125
        this -> obj = new _1(obj);
    };
    
#line 141
    template < class _1 >
    _1 *Optional < _1 >::operator-> ()
    {
        {
#line 141
            if (!(obj))
            {
#line 141
                Break("Assertion failed: obj");
            }
        }
#line 141
        ;
#line 141
        return obj;
    };
    
#line 136
    template < class _1 >
    void Optional < _1 >::operator= (const Optional& o)
    {
#line 136
        Clear();
#line 136
        if (!o.IsEmpty())
        {
#line 136
            this -> obj = new _1(*o.obj);
        }
    };
    
#line 137
    template < class _1 >
    void Optional < _1 >::operator= (const PickOpt& n)
    {
#line 137
        Clear();
#line 137
        if (!n.Get().IsEmpty())
        {
#line 137
            Pick(n.Get());
        }
    };
    
#line 138
    template < class _1 >
    void Optional < _1 >::Pick(Optional& o)
    {
#line 138
        obj = o.obj;
#line 138
        o.obj = 0;
    };
    
#line 58 "../../src/Com/Algorithm.fog"
    double RNG::Randomf()
    {
#line 58
        return(sNext(state) >> 11) * (1. / (((uint64)1) << 53));
    };
    
#line 63
    void RNG::Seed(dword seed)
    {
#line 64
        for (int i = 0; i < 4; i ++ )
            state[i] = 12345678 + seed + i;
    };
    
#line 28
    uint64 RNG::sNext(uint64 *s)
    {
#line 29
        const uint64 result_starstar = s_rotl(s[1] * 5, 7) * 9;
        const uint64 t = s[1] << 17;
#line 32
        s[2] ^= s[0];
        s[3] ^= s[1];
        s[1] ^= s[2];
        s[0] ^= s[3];
#line 37
        s[2] ^= t;
#line 39
        s[3] = s_rotl(s[3], 45);
#line 41
        return result_starstar;
    };
    
    void RNG::sSeed(uint64 *s)
    {
#line 45
        for (int pass = 0; pass < 4; pass ++ )
            {
#line 46
                for (int i = 0; i < 4; i ++ )
                    {
#line 47
                        CombineHash h;
                        h.Put64(NativeCurrentTime());
                        h.Put64(NativeNanoSeconds());
                        h.Put64(NativeMilliSeconds());
                        s[i] ^= h;
                    }
            }
    };
    
#line 24
    uint64 RNG::s_rotl(const uint64 x, int k)
    {
#line 25
        return(x << k) | (x >> (64 - k));
    };
    
#line 99 "../../src/Com/String.fog"
    String::String()
    :
        is_ref(false),
        count(0)
    {
#line 99
        Zero();
    };
    
    String::String(const String& s)
    :
        is_ref(false),
        count(0)
    {
#line 102
        Zero();
#line 102
        *this = s;
    };
    
#line 100
    String::String(const Char *c)
    :
        is_ref(false),
        count(0)
    {
#line 100
        Zero();
#line 100
        *this = c;
    };
    
#line 101
    String::String(const Char *c, int len)
    :
        is_ref(false),
        count(0)
    {
#line 101
        Zero();
#line 101
        Set(c, len);
    };
    
#line 103
    String::~String()
    {
#line 103
        Clear();
    };
    
#line 425
    String String::operator+ (const String& s)
    {
#line 425
        String out(*this);
#line 425
        out.Cat(s);
#line 425
        return out;
    };
    
#line 150
    String String::operator+ (const String& l) const
    {
#line 151
        String s(*this);
        s.Cat(l);
        return s;
    };
    
#line 132
    String& String::operator= (const String& str)
    {
#line 133
        if (!str.is_ref)
        {
#line 134
            Clear();
            MemoryCopy(buf, str.buf, sizeof (buf));
            is_ref = false;
        }
        else
        {
#line 139
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
    
#line 412
    bool String::operator== (const String& s) const
    {
#line 413
        if (s.GetCount() != GetCount())
#line 413
            return false;
        if (s.IsEmpty())
#line 414
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 420
    String::Char String::At(int i) const
    {
        {
#line 420
            if (!(i >= 0 && i < count))
            {
#line 420
                Break("Assertion failed: i >= 0 && i < count");
            }
        }
#line 420
        ;
#line 420
        return *(Begin() + i);
    };
    
#line 409
    const String::Char *String::Begin() const
    {
#line 409
        if (is_ref)
#line 409
            return ref[0] -> Get();
        else
#line 409
            return buf;
    };
    
#line 162
    String& String::Cat(Char i)
    {
#line 163
        if (!is_ref)
        {
#line 164
            is_ref = count + 1 >= 8;
            if (!is_ref)
            {
#line 166
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
            }
            else
            {
#line 171
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
#line 181
            if (ref[0] -> GetRefs() == 1)
            {
#line 182
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
#line 191
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
    
#line 156
    String& String::Cat(Char c, int count)
    {
        for (int i = 0; i < count; i ++ )
#line 158
            Cat(c);
        return *this;
    };
    
#line 205
    String& String::Cat(const String& str)
    {
#line 206
        if (!is_ref)
        {
#line 207
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 209
                MemoryCopy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 213
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
#line 223
            if (ref[0] -> GetRefs() == 1)
            {
#line 224
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
#line 233
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
    
#line 529
    double String::CharDbl(const Char *s)
    {
#line 530
        double a = 0.0;
        int e = 0;
        int c;
#line 534
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 535
                a = a * 10.0 + (c - '0');
            }
#line 538
        if (c == '.')
        {
#line 539
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 540
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 545
        if (c == 'e' || c == 'E')
        {
#line 546
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 550
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 554
                c = *s ++ ;
                sign = - 1;
            }
#line 558
            while (IsDigit(c))
                {
#line 559
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 563
            e += i * sign;
        }
#line 566
        while (e > 0)
            {
#line 567
                a *= 10.0;
                e -- ;
            }
#line 571
        while (e < 0)
            {
#line 572
                a *= 0.1;
                e ++ ;
            }
#line 576
        return a;
    };
    
#line 475
    int String::CharHexInt(const Char *s)
    {
#line 476
        if (!s)
#line 476
            return 0;
        while (IsSpace(*s))
#line 477
            s ++ ;
        int n = 0;
#line 478
        int neg = 0;
        switch (*s)
        {
#line 480
            case '-':
#line 480
                neg = 1;
            case '+':
#line 481
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 487
            return n;
        else
#line 487
            return - n;
    };
    
    int String::CharInt(const Char *s)
    {
        int n = 0;
#line 492
        int neg = 0;
        while (IsSpace(*s))
#line 493
            s ++ ;
        switch (*s)
        {
#line 495
            case '-':
#line 495
                neg = 1;
            case '+':
#line 496
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 500
            return n;
        else
#line 500
            return - n;
    };
    
    int64 String::CharInt64(const Char *s)
    {
        int64 n = 0;
#line 505
        int64 neg = 0;
        while (IsSpace(*s))
#line 506
            s ++ ;
        switch (*s)
        {
#line 508
            case '-':
#line 508
                neg = 1;
            case '+':
#line 509
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 513
            return n;
        else
#line 513
            return - n;
    };
    
    uint64 String::CharIntU64(const Char *s)
    {
        uint64 n = 0;
        while (IsSpace(*s))
#line 519
            s ++ ;
        switch (*s)
        {
#line 521
            case '-':
#line 521
                return 0;
            case '+':
#line 522
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 461
    int String::CharOctInt(const Char *s)
    {
#line 462
        if (!s)
#line 462
            return 0;
        while (IsSpace(*s))
#line 463
            s ++ ;
        int n = 0;
#line 464
        int neg = 0;
        switch (*s)
        {
#line 466
            case '-':
#line 466
                neg = 1;
            case '+':
#line 467
                s ++ ;
        }
        while (*s == '0')
#line 469
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 472
            return n;
        else
#line 472
            return - n;
    };
    
#line 106
    void String::Clear()
    {
#line 107
        if (is_ref)
        {
#line 107
            ref[0] -> Dec();
#line 107
            ref[0] = 0;
#line 107
            is_ref = false;
        }
        else
        {
#line 108
            ref[0] = 0;
        }
#line 109
        count = 0;
    };
    
#line 655
    int String::Compare(const Char *a, const Char *b)
    {
#line 656
        while (*a || *b)
            {
#line 657
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
#line 667
        while ((*a || *b) && len > 0)
            {
#line 668
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
#line 679
            if (!(dst && src))
            {
#line 679
                Break("Assertion failed: dst && src");
            }
        }
#line 680
        ;
#line 680
        if (!dst || !src)
#line 680
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 445
    String String::DblStr(double d)
    {
#line 446
        Char output[50];
        NativeDblStr(d, output, 50);
        return String(output);
    };
    
#line 286
    int String::Find(const String& str, int pos) const
    {
#line 287
        if (GetCount() == 0)
#line 287
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 290
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 290
                Break("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 291
        ;
#line 291
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 295
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 313
    int String::FindFirstNotOf(const Char *str) const
    {
#line 314
        if (GetCount() <= 0 || !str)
#line 314
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 319
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 323
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 326
                        if (chr == cmp_chr)
                        {
#line 327
                            match = true;
                            break;
                        
                        }
                    }
#line 331
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 453
    uint32 String::GetHashValue() const
    {
#line 454
        CombineHash ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 391
    bool String::Insert(int begin, const Char *str, int n)
    {
#line 392
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 394
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 394
                Break("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 395
        ;
#line 395
        begin = max(0, min(begin, GetCount()));
        String part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 401
        if (l)
            *this = Left(l) + part;
        else 
#line 403
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 579
    const String::Char *String::IntChar(Char *p, int bufsize, int x)
    {
#line 580
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 583
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 588
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 592
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const String::Char *String::IntChar64(Char *p, int bufsize, int64 x)
    {
#line 598
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 601
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 606
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 610
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const String::Char *String::IntCharU64(Char *p, int bufsize, uint64 x)
    {
#line 616
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 619
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 624
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 628
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
#line 433
    String String::IntStr(int i)
    {
#line 434
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return String(value);
    };
    
    String String::IntStr64(int64 i)
    {
#line 440
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return String(value);
    };
    
#line 634
    int String::Length(const Char *c, int max_len)
    {
        {
#line 635
            if (!(c))
            {
#line 635
                Break("Assertion failed: c");
            }
        }
#line 636
        ;
#line 636
        if (!c)
#line 636
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 639
            while (*c)
                {
#line 640
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 646
            while (max_len > 0 && *c)
                {
#line 647
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 361
    String String::Mid(int i) const
    {
#line 361
        if (i >= GetCount())
#line 361
            return Empty();
#line 361
        if (i < 0)
#line 361
            i = 0;
#line 361
        return Mid(i, GetCount() - i);
    };
    
#line 362
    String String::Mid(int i, int size) const
    {
#line 363
        size = min(size, count - i);
        if (size <= 0)
#line 364
            return String();
        {
#line 365
            if (!(i >= 0 && i + size <= count))
            {
#line 365
                Break("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 366
        ;
#line 366
        return String(Begin() + i, size);
    };
    
#line 371
    void String::Remove(int begin, int count)
    {
        {
#line 372
            if (!(begin >= 0 && count >= 0))
            {
#line 372
                Break("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 373
        ;
#line 373
        begin = max(0, begin);
        count = max(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 377
            if (!(begin <= c && end <= c))
            {
#line 377
                Break("Assertion failed: begin <= c && end <= c");
            }
        }
#line 378
        ;
#line 378
        end = min(c, end);
        begin = min(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 384
        if (l)
            *this = Left(l);
        else 
#line 386
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 246
    void String::Replace(const String& s, const String& value)
    {
#line 247
        if (s == value)
#line 247
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 250
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void String::Replace(int i, int len, const String& value)
    {
#line 256
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 262
            MemoryCopy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 266
            MemoryCopy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 272
            MemoryCopy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 277
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        {
#line 281
            if (!(cursor == new_len + 1))
            {
#line 281
                Break("Assertion failed: cursor == new_len+1");
            }
        }
#line 282
        ;
    };
    
#line 301
    int String::ReverseFind(const String& str, int pos) const
    {
#line 302
        if (GetCount() == 0)
#line 302
            return - 1;
        {
#line 303
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 303
                Break("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 304
        ;
#line 304
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 308
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 337
    int String::ReverseFindFirstNotOf(const Char *str) const
    {
#line 338
        if (GetCount() <= 0 || !str)
#line 338
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 343
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 347
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 350
                        if (chr == cmp_chr)
                        {
#line 351
                            match = true;
                            break;
                        
                        }
                    }
#line 355
                i -- ;
                if (!match)
                    return i;
            }
        return - 1;
    };
    
#line 113
    String& String::Set(const Char *c, int len)
    {
#line 114
        Clear();
        if (!c)
#line 115
            return *this;
        count = min(C::StringLength(c, len), len);
        if (count < 8)
        {
#line 118
            MemoryCopy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
        }
        else
        {
#line 122
            Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (count + 1));
            MemoryCopy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
            ref[0] = new RefData(buf, count + 1);
            ref[0] -> Inc();
            is_ref = true;
        }
        return *this;
    };
    
#line 94
    void String::Zero()
    {
#line 54 "../../src/Com/Meta.fog"
        MemorySet(this, 0, sizeof (String));
    };
    
#line 38 "../../src/Com/String.fog"
    String::RefData::RefData(Char *str, int reserved)
    :
        data(str),
        reserved(reserved)
    {};
    
#line 39
    String::RefData::~RefData()
    {
#line 39
        Clear();
    };
    
#line 76
    String::RefData::operator ConstChar * () const
    {
#line 76
        return data;
    };
    
#line 75
    String::Char *String::RefData::Begin()
    {
#line 75
        return data;
    };
    
#line 41
    void String::RefData::Clear()
    {
#line 41
        if (data)
        {
#line 41
            MemoryFree(data);
#line 41
            data = 0;
#line 41
            refs = 0;
#line 41
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
    
#line 74 "../../src/Com/String.fog"
    String::ConstChar *String::RefData::Get() const
    {
#line 74
        return data;
    };
    
#line 47 "../../src/Com/Meta.fog"
    int String::RefData::GetRefs() const
    {
#line 47
        return refs;
    };
    
#line 78 "../../src/Com/String.fog"
    int String::RefData::GetReserved() const
    {
#line 78
        return reserved;
    };
    
#line 48 "../../src/Com/Meta.fog"
    void String::RefData::Inc()
    {
#line 48
        refs ++ ;
    };
    
#line 43 "../../src/Com/String.fog"
    void String::RefData::IncreaseReserved()
    {
#line 44
        uint64 new_reserved = 1;
        while (new_reserved <= reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void String::RefData::IncreaseReserved(int min_reserved)
    {
#line 53
        uint64 new_reserved = 1;
        while (new_reserved <= min_reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void String::RefData::Reserve(int new_reserved)
    {
#line 62
        if (new_reserved <= reserved)
            return;
        Char * new_data = (Char * ) MemoryAlloc(new_reserved * sizeof (Char));
        if (data)
        {
#line 66
            if (reserved > 0)
                MemoryCopy(new_data, data, sizeof (Char) * reserved);
            MemoryFree(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
    namespace Tester
    {
#line 28 "../../src/Com/Meta.fog"
        App::SomeRefTuple2::SomeRefTuple2(int& a, double& b)
        :
            a(a),
            b(b)
        {};
        
#line 29
        String App::SomeRefTuple2::ToString() const
        {
#line 29
            return Com::ToString(a) + ", " + Com::ToString(b);
        };
        
#line 9
        String App::SomeTuple2::ToString() const
        {
#line 9
            return Com::ToString(a) + ", " + Com::ToString(b);
        };
        
#line 13 "ComTest.mfog"
        App::VirtualBase::~VirtualBase() {};
        
    };
#line 99 "../../src/Com/String.fog"
    WString::WString()
    :
        is_ref(false),
        count(0)
    {
#line 99
        Zero();
    };
    
    WString::WString(const WString& s)
    :
        is_ref(false),
        count(0)
    {
#line 102
        Zero();
#line 102
        *this = s;
    };
    
#line 100
    WString::WString(const Char *c)
    :
        is_ref(false),
        count(0)
    {
#line 100
        Zero();
#line 100
        *this = c;
    };
    
#line 101
    WString::WString(const Char *c, int len)
    :
        is_ref(false),
        count(0)
    {
#line 101
        Zero();
#line 101
        Set(c, len);
    };
    
#line 103
    WString::~WString()
    {
#line 103
        Clear();
    };
    
#line 425
    WString WString::operator+ (const WString& s)
    {
#line 425
        WString out(*this);
#line 425
        out.Cat(s);
#line 425
        return out;
    };
    
#line 150
    WString WString::operator+ (const WString& l) const
    {
#line 151
        WString s(*this);
        s.Cat(l);
        return s;
    };
    
#line 132
    WString& WString::operator= (const WString& str)
    {
#line 133
        if (!str.is_ref)
        {
#line 134
            Clear();
            MemoryCopy(buf, str.buf, sizeof (buf));
            is_ref = false;
        }
        else
        {
#line 139
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
    
#line 412
    bool WString::operator== (const WString& s) const
    {
#line 413
        if (s.GetCount() != GetCount())
#line 413
            return false;
        if (s.IsEmpty())
#line 414
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 420
    WString::Char WString::At(int i) const
    {
        {
#line 420
            if (!(i >= 0 && i < count))
            {
#line 420
                Break("Assertion failed: i >= 0 && i < count");
            }
        }
#line 420
        ;
#line 420
        return *(Begin() + i);
    };
    
#line 409
    const WString::Char *WString::Begin() const
    {
#line 409
        if (is_ref)
#line 409
            return ref[0] -> Get();
        else
#line 409
            return buf;
    };
    
#line 162
    WString& WString::Cat(Char i)
    {
#line 163
        if (!is_ref)
        {
#line 164
            is_ref = count + 1 >= 8;
            if (!is_ref)
            {
#line 166
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
            }
            else
            {
#line 171
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
#line 181
            if (ref[0] -> GetRefs() == 1)
            {
#line 182
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
#line 191
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
    
#line 156
    WString& WString::Cat(Char c, int count)
    {
        for (int i = 0; i < count; i ++ )
#line 158
            Cat(c);
        return *this;
    };
    
#line 205
    WString& WString::Cat(const WString& str)
    {
#line 206
        if (!is_ref)
        {
#line 207
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 209
                MemoryCopy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 213
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
#line 223
            if (ref[0] -> GetRefs() == 1)
            {
#line 224
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
#line 233
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
    
#line 529
    double WString::CharDbl(const Char *s)
    {
#line 530
        double a = 0.0;
        int e = 0;
        int c;
#line 534
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 535
                a = a * 10.0 + (c - '0');
            }
#line 538
        if (c == '.')
        {
#line 539
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 540
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 545
        if (c == 'e' || c == 'E')
        {
#line 546
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 550
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 554
                c = *s ++ ;
                sign = - 1;
            }
#line 558
            while (IsDigit(c))
                {
#line 559
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 563
            e += i * sign;
        }
#line 566
        while (e > 0)
            {
#line 567
                a *= 10.0;
                e -- ;
            }
#line 571
        while (e < 0)
            {
#line 572
                a *= 0.1;
                e ++ ;
            }
#line 576
        return a;
    };
    
#line 475
    int WString::CharHexInt(const Char *s)
    {
#line 476
        if (!s)
#line 476
            return 0;
        while (IsSpace(*s))
#line 477
            s ++ ;
        int n = 0;
#line 478
        int neg = 0;
        switch (*s)
        {
#line 480
            case '-':
#line 480
                neg = 1;
            case '+':
#line 481
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 487
            return n;
        else
#line 487
            return - n;
    };
    
    int WString::CharInt(const Char *s)
    {
        int n = 0;
#line 492
        int neg = 0;
        while (IsSpace(*s))
#line 493
            s ++ ;
        switch (*s)
        {
#line 495
            case '-':
#line 495
                neg = 1;
            case '+':
#line 496
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 500
            return n;
        else
#line 500
            return - n;
    };
    
    int64 WString::CharInt64(const Char *s)
    {
        int64 n = 0;
#line 505
        int64 neg = 0;
        while (IsSpace(*s))
#line 506
            s ++ ;
        switch (*s)
        {
#line 508
            case '-':
#line 508
                neg = 1;
            case '+':
#line 509
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 513
            return n;
        else
#line 513
            return - n;
    };
    
    uint64 WString::CharIntU64(const Char *s)
    {
        uint64 n = 0;
        while (IsSpace(*s))
#line 519
            s ++ ;
        switch (*s)
        {
#line 521
            case '-':
#line 521
                return 0;
            case '+':
#line 522
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 461
    int WString::CharOctInt(const Char *s)
    {
#line 462
        if (!s)
#line 462
            return 0;
        while (IsSpace(*s))
#line 463
            s ++ ;
        int n = 0;
#line 464
        int neg = 0;
        switch (*s)
        {
#line 466
            case '-':
#line 466
                neg = 1;
            case '+':
#line 467
                s ++ ;
        }
        while (*s == '0')
#line 469
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 472
            return n;
        else
#line 472
            return - n;
    };
    
#line 106
    void WString::Clear()
    {
#line 107
        if (is_ref)
        {
#line 107
            ref[0] -> Dec();
#line 107
            ref[0] = 0;
#line 107
            is_ref = false;
        }
        else
        {
#line 108
            ref[0] = 0;
        }
#line 109
        count = 0;
    };
    
#line 655
    int WString::Compare(const Char *a, const Char *b)
    {
#line 656
        while (*a || *b)
            {
#line 657
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
#line 667
        while ((*a || *b) && len > 0)
            {
#line 668
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
#line 679
            if (!(dst && src))
            {
#line 679
                Break("Assertion failed: dst && src");
            }
        }
#line 680
        ;
#line 680
        if (!dst || !src)
#line 680
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 445
    WString WString::DblStr(double d)
    {
#line 446
        Char output[50];
        NativeDblStr(d, output, 50);
        return WString(output);
    };
    
#line 286
    int WString::Find(const WString& str, int pos) const
    {
#line 287
        if (GetCount() == 0)
#line 287
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 290
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 290
                Break("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 291
        ;
#line 291
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 295
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 313
    int WString::FindFirstNotOf(const Char *str) const
    {
#line 314
        if (GetCount() <= 0 || !str)
#line 314
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 319
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 323
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 326
                        if (chr == cmp_chr)
                        {
#line 327
                            match = true;
                            break;
                        
                        }
                    }
#line 331
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 453
    uint32 WString::GetHashValue() const
    {
#line 454
        CombineHash ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 391
    bool WString::Insert(int begin, const Char *str, int n)
    {
#line 392
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 394
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 394
                Break("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 395
        ;
#line 395
        begin = max(0, min(begin, GetCount()));
        WString part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 401
        if (l)
            *this = Left(l) + part;
        else 
#line 403
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 579
    const WString::Char *WString::IntChar(Char *p, int bufsize, int x)
    {
#line 580
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 583
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 588
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 592
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const WString::Char *WString::IntChar64(Char *p, int bufsize, int64 x)
    {
#line 598
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 601
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 606
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 610
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const WString::Char *WString::IntCharU64(Char *p, int bufsize, uint64 x)
    {
#line 616
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 619
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 624
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 628
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
#line 433
    WString WString::IntStr(int i)
    {
#line 434
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return WString(value);
    };
    
    WString WString::IntStr64(int64 i)
    {
#line 440
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return WString(value);
    };
    
#line 634
    int WString::Length(const Char *c, int max_len)
    {
        {
#line 635
            if (!(c))
            {
#line 635
                Break("Assertion failed: c");
            }
        }
#line 636
        ;
#line 636
        if (!c)
#line 636
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 639
            while (*c)
                {
#line 640
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 646
            while (max_len > 0 && *c)
                {
#line 647
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 361
    WString WString::Mid(int i) const
    {
#line 361
        if (i >= GetCount())
#line 361
            return Empty();
#line 361
        if (i < 0)
#line 361
            i = 0;
#line 361
        return Mid(i, GetCount() - i);
    };
    
#line 362
    WString WString::Mid(int i, int size) const
    {
#line 363
        size = min(size, count - i);
        if (size <= 0)
#line 364
            return WString();
        {
#line 365
            if (!(i >= 0 && i + size <= count))
            {
#line 365
                Break("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 366
        ;
#line 366
        return WString(Begin() + i, size);
    };
    
#line 371
    void WString::Remove(int begin, int count)
    {
        {
#line 372
            if (!(begin >= 0 && count >= 0))
            {
#line 372
                Break("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 373
        ;
#line 373
        begin = max(0, begin);
        count = max(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 377
            if (!(begin <= c && end <= c))
            {
#line 377
                Break("Assertion failed: begin <= c && end <= c");
            }
        }
#line 378
        ;
#line 378
        end = min(c, end);
        begin = min(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 384
        if (l)
            *this = Left(l);
        else 
#line 386
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 246
    void WString::Replace(const WString& s, const WString& value)
    {
#line 247
        if (s == value)
#line 247
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 250
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void WString::Replace(int i, int len, const WString& value)
    {
#line 256
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 262
            MemoryCopy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 266
            MemoryCopy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 272
            MemoryCopy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 277
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        {
#line 281
            if (!(cursor == new_len + 1))
            {
#line 281
                Break("Assertion failed: cursor == new_len+1");
            }
        }
#line 282
        ;
    };
    
#line 301
    int WString::ReverseFind(const WString& str, int pos) const
    {
#line 302
        if (GetCount() == 0)
#line 302
            return - 1;
        {
#line 303
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 303
                Break("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 304
        ;
#line 304
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 308
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 337
    int WString::ReverseFindFirstNotOf(const Char *str) const
    {
#line 338
        if (GetCount() <= 0 || !str)
#line 338
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 343
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 347
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 350
                        if (chr == cmp_chr)
                        {
#line 351
                            match = true;
                            break;
                        
                        }
                    }
#line 355
                i -- ;
                if (!match)
                    return i;
            }
        return - 1;
    };
    
#line 113
    WString& WString::Set(const Char *c, int len)
    {
#line 114
        Clear();
        if (!c)
#line 115
            return *this;
        count = min(C::StringLength(c, len), len);
        if (count < 8)
        {
#line 118
            MemoryCopy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
        }
        else
        {
#line 122
            Char * buf = (Char * ) MemoryAlloc(sizeof (Char) * (count + 1));
            MemoryCopy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
            ref[0] = new RefData(buf, count + 1);
            ref[0] -> Inc();
            is_ref = true;
        }
        return *this;
    };
    
#line 94
    void WString::Zero()
    {
#line 54 "../../src/Com/Meta.fog"
        MemorySet(this, 0, sizeof (WString));
    };
    
#line 38 "../../src/Com/String.fog"
    WString::RefData::RefData(Char *str, int reserved)
    :
        data(str),
        reserved(reserved)
    {};
    
#line 39
    WString::RefData::~RefData()
    {
#line 39
        Clear();
    };
    
#line 76
    WString::RefData::operator ConstChar * () const
    {
#line 76
        return data;
    };
    
#line 75
    WString::Char *WString::RefData::Begin()
    {
#line 75
        return data;
    };
    
#line 41
    void WString::RefData::Clear()
    {
#line 41
        if (data)
        {
#line 41
            MemoryFree(data);
#line 41
            data = 0;
#line 41
            refs = 0;
#line 41
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
    
#line 74 "../../src/Com/String.fog"
    WString::ConstChar *WString::RefData::Get() const
    {
#line 74
        return data;
    };
    
#line 47 "../../src/Com/Meta.fog"
    int WString::RefData::GetRefs() const
    {
#line 47
        return refs;
    };
    
#line 78 "../../src/Com/String.fog"
    int WString::RefData::GetReserved() const
    {
#line 78
        return reserved;
    };
    
#line 48 "../../src/Com/Meta.fog"
    void WString::RefData::Inc()
    {
#line 48
        refs ++ ;
    };
    
#line 43 "../../src/Com/String.fog"
    void WString::RefData::IncreaseReserved()
    {
#line 44
        uint64 new_reserved = 1;
        while (new_reserved <= reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void WString::RefData::IncreaseReserved(int min_reserved)
    {
#line 53
        uint64 new_reserved = 1;
        while (new_reserved <= min_reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void WString::RefData::Reserve(int new_reserved)
    {
#line 62
        if (new_reserved <= reserved)
            return;
        Char * new_data = (Char * ) MemoryAlloc(new_reserved * sizeof (Char));
        if (data)
        {
#line 66
            if (reserved > 0)
                MemoryCopy(new_data, data, sizeof (Char) * reserved);
            MemoryFree(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
    namespace
    {
#line 752
        String ToLower(const String& s)
        {
#line 753
            int count = s.GetCount();
            if (!count)
#line 754
                return String();
            char * v = (char * ) MemoryAlloc(count + 1);
            char * it = v;
            for (int i = 0; i < s.GetCount(); i ++ )
                *it ++ = ToLowerChar(s[i]);
            *it = 0;
            String o;
            o.Set(v, count);
            MemoryFree(v);
            return o;
        };
        
#line 732
        int ToLowerChar(int chr)
        {
#line 733
            if (chr >= 'A' && chr <= 'Z')
                return 'a' + (chr - 'A');
            return chr;
        };
        
        String ToUpper(const String& s)
        {
#line 739
            int count = s.GetCount();
            if (!count)
#line 740
                return String();
            char * v = (char * ) MemoryAlloc(count + 1);
            char * it = v;
            for (int i = 0; i < s.GetCount(); i ++ )
                *it ++ = ToUpperChar(s[i]);
            *it = 0;
            String o;
            o.Set(v, count);
            MemoryFree(v);
            return o;
        };
        
#line 726
        int ToUpperChar(int chr)
        {
#line 727
            if (chr >= 'a' && chr <= 'z')
                return 'A' + (chr - 'a');
            return chr;
        };
        
    };
};

#endif
