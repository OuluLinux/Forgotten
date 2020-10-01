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

#ifndef TEXT_CXX
#define TEXT_CXX

#include <new>

#ifndef TEXT_HXX
#include <Text.hxx>
#endif

namespace Text
{
#line 778 "../../src/Com/Text.fog"
    String ToLower(const String& s)
    {
#line 779
        int count = s.GetCount();
        if (!count)
#line 780
            return String();
        char * v = (char * ) Lang::Memory::Alloc(count + 1);
        char * it = v;
        for (int i = 0; i < s.GetCount(); i ++ )
            *it ++ = ToLowerChar(s[i]);
        *it = 0;
        String o;
        o.Set(v, count);
        Lang::Memory::Free(v);
        return o;
    };
    
#line 758
    int ToLowerChar(int chr)
    {
#line 759
        if (chr >= 'A' && chr <= 'Z')
            return 'a' + (chr - 'A');
        return chr;
    };
    
    String ToUpper(const String& s)
    {
#line 765
        int count = s.GetCount();
        if (!count)
#line 766
            return String();
        char * v = (char * ) Lang::Memory::Alloc(count + 1);
        char * it = v;
        for (int i = 0; i < s.GetCount(); i ++ )
            *it ++ = ToUpperChar(s[i]);
        *it = 0;
        String o;
        o.Set(v, count);
        Lang::Memory::Free(v);
        return o;
    };
    
#line 752
    int ToUpperChar(int chr)
    {
#line 753
        if (chr >= 'a' && chr <= 'z')
            return 'A' + (chr - 'a');
        return chr;
    };
    
#line 98
    String::String()
    :
        is_ref(false),
        count(0)
    {
#line 98
        Zero();
    };
    
    String::String(const String& s)
    :
        is_ref(false),
        count(0)
    {
#line 101
        Zero();
#line 101
        *this = s;
    };
    
#line 99
    String::String(const Char *c)
    :
        is_ref(false),
        count(0)
    {
#line 99
        Zero();
#line 99
        *this = c;
    };
    
#line 100
    String::String(const Char *c, int len)
    :
        is_ref(false),
        count(0)
    {
#line 100
        Zero();
#line 100
        Set(c, len);
    };
    
#line 102
    String::~String()
    {
#line 102
        Clear();
    };
    
#line 458
    String String::operator+ (const String& s)
    {
#line 458
        String out(*this);
#line 458
        out.Cat(s);
#line 458
        return out;
    };
    
#line 183
    String String::operator+ (const String& l) const
    {
#line 184
        String s(*this);
        s.Cat(l);
        return s;
    };
    
#line 165
    String& String::operator= (const String& str)
    {
#line 166
        if (!str.is_ref)
        {
#line 167
            Clear();
            Lang::Memory::Copy(buf, str.buf, sizeof (buf));
            is_ref = false;
        }
        else
        {
#line 172
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
    
#line 445
    bool String::operator== (const String& s) const
    {
#line 446
        if (s.GetCount() != GetCount())
#line 446
            return false;
        if (s.IsEmpty())
#line 447
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 453
    String::Char String::At(int i) const
    {
        {
#line 453
            if (!(i >= 0 && i < count))
            {
#line 453
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 453
        ;
#line 453
        return *(Begin() + i);
    };
    
#line 442
    const String::Char *String::Begin() const
    {
#line 442
        if (is_ref)
#line 442
            return ref[0] -> Get();
        else
#line 442
            return buf;
    };
    
#line 195
    String& String::Cat(Char i)
    {
#line 196
        if (!is_ref)
        {
#line 197
            is_ref = count + 1 >= 8;
            if (!is_ref)
            {
#line 199
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
            }
            else
            {
#line 204
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (count + 1 + 1));
                Lang::Memory::Copy(buf, this -> buf, sizeof (Char) * count);
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
                ref[0] = new RefData(buf, count + 1);
                is_ref = true;
            }
        }
        else
        {
#line 214
            if (ref[0] -> GetRefs() == 1)
            {
#line 215
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
#line 224
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (count + 1 + 1));
                Lang::Memory::Copy(buf, ref[0] -> Get(), sizeof (Char) * count);
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
                ref[0] -> Dec();
                ref[0] = new RefData(buf, count + 1);
            }
        }
        return *this;
    };
    
#line 189
    String& String::Cat(Char c, int count)
    {
        for (int i = 0; i < count; i ++ )
#line 191
            Cat(c);
        return *this;
    };
    
#line 238
    String& String::Cat(const String& str)
    {
#line 239
        if (!is_ref)
        {
#line 240
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 242
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 246
                int reserved = count + str.GetCount() + 1;
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
                Lang::Memory::Copy(buf, this -> buf, sizeof (Char) * count);
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
                ref[0] = new RefData(buf, reserved);
                is_ref = true;
            }
        }
        else
        {
#line 256
            if (ref[0] -> GetRefs() == 1)
            {
#line 257
                int new_count = count + str.GetCount() + 1;
                if (new_count > ref[0] -> GetReserved())
                    ref[0] -> IncreaseReserved(new_count);
                Char * c = ref[0] -> Begin();
                Lang::Memory::Copy(c + count, str.Begin(), sizeof (Char) * str.GetCount());
                count += str.GetCount();
                c[count] = 0;
            }
            else
            {
#line 266
                int reserved = count + str.GetCount() + 1;
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
                Lang::Memory::Copy(buf, ref[0] -> Get(), sizeof (Char) * count);
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
                buf[count] = 0;
                ref[0] -> Dec();
                ref[0] = new RefData(buf, reserved);
            }
        }
        return *this;
    };
    
#line 562
    double String::CharDbl(const Char *s)
    {
#line 563
        double a = 0.0;
        int e = 0;
        int c;
#line 567
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 568
                a = a * 10.0 + (c - '0');
            }
#line 571
        if (c == '.')
        {
#line 572
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 573
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 578
        if (c == 'e' || c == 'E')
        {
#line 579
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 583
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 587
                c = *s ++ ;
                sign = - 1;
            }
#line 591
            while (IsDigit(c))
                {
#line 592
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 596
            e += i * sign;
        }
#line 599
        while (e > 0)
            {
#line 600
                a *= 10.0;
                e -- ;
            }
#line 604
        while (e < 0)
            {
#line 605
                a *= 0.1;
                e ++ ;
            }
#line 609
        return a;
    };
    
#line 508
    int String::CharHexInt(const Char *s)
    {
#line 509
        if (!s)
#line 509
            return 0;
        while (IsSpace(*s))
#line 510
            s ++ ;
        int n = 0;
#line 511
        int neg = 0;
        switch (*s)
        {
#line 513
            case '-':
#line 513
                neg = 1;
            case '+':
#line 514
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 520
            return n;
        else
#line 520
            return - n;
    };
    
    int String::CharInt(const Char *s)
    {
        int n = 0;
#line 525
        int neg = 0;
        while (IsSpace(*s))
#line 526
            s ++ ;
        switch (*s)
        {
#line 528
            case '-':
#line 528
                neg = 1;
            case '+':
#line 529
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 533
            return n;
        else
#line 533
            return - n;
    };
    
    Lang::int64 String::CharInt64(const Char *s)
    {
        Lang::int64 n = 0;
#line 538
        Lang::int64 neg = 0;
        while (IsSpace(*s))
#line 539
            s ++ ;
        switch (*s)
        {
#line 541
            case '-':
#line 541
                neg = 1;
            case '+':
#line 542
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 546
            return n;
        else
#line 546
            return - n;
    };
    
    Lang::uint64 String::CharIntU64(const Char *s)
    {
        Lang::uint64 n = 0;
        while (IsSpace(*s))
#line 552
            s ++ ;
        switch (*s)
        {
#line 554
            case '-':
#line 554
                return 0;
            case '+':
#line 555
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 494
    int String::CharOctInt(const Char *s)
    {
#line 495
        if (!s)
#line 495
            return 0;
        while (IsSpace(*s))
#line 496
            s ++ ;
        int n = 0;
#line 497
        int neg = 0;
        switch (*s)
        {
#line 499
            case '-':
#line 499
                neg = 1;
            case '+':
#line 500
                s ++ ;
        }
        while (*s == '0')
#line 502
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 505
            return n;
        else
#line 505
            return - n;
    };
    
#line 105
    void String::Clear()
    {
#line 106
        if (is_ref)
        {
#line 106
            ref[0] -> Dec();
#line 106
            ref[0] = 0;
#line 106
            is_ref = false;
        }
        else
        {
#line 107
            ref[0] = 0;
        }
#line 108
        count = 0;
    };
    
#line 688
    int String::Compare(const Char *a, const Char *b)
    {
#line 689
        while (*a || *b)
            {
#line 690
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
#line 700
        while ((*a || *b) && len > 0)
            {
#line 701
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
#line 712
            if (!(dst && src))
            {
#line 712
                Lang::SysBreak("Assertion failed: dst && src");
            }
        }
#line 713
        ;
#line 713
        if (!dst || !src)
#line 713
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 478
    String String::DblStr(double d)
    {
#line 479
        Char output[50];
        Native::DblStr(d, output, 50);
        return String(output);
    };
    
#line 319
    int String::Find(const String& str, int pos) const
    {
#line 320
        if (GetCount() == 0)
#line 320
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 323
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 323
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 324
        ;
#line 324
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 328
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 346
    int String::FindFirstNotOf(const Char *str) const
    {
#line 347
        if (GetCount() <= 0 || !str)
#line 347
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 352
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 356
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 359
                        if (chr == cmp_chr)
                        {
#line 360
                            match = true;
                            break;
                        
                        }
                    }
#line 364
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 486
    Lang::uint32 String::GetHashValue() const
    {
#line 487
        Hash::Combine ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 424
    bool String::Insert(int begin, const Char *str, int n)
    {
#line 425
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 427
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 427
                Lang::SysBreak("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 428
        ;
#line 428
        begin = Algorithm::Maximum(0, Algorithm::Minimum(begin, GetCount()));
        String part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 434
        if (l)
            *this = Left(l) + part;
        else 
#line 436
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 612
    const String::Char *String::IntChar(Char *p, int bufsize, int x)
    {
#line 613
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 616
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 621
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 625
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const String::Char *String::IntChar64(Char *p, int bufsize, Lang::int64 x)
    {
#line 631
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 634
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 639
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 643
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const String::Char *String::IntCharU64(Char *p, int bufsize, Lang::uint64 x)
    {
#line 649
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 652
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 657
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 661
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
#line 466
    String String::IntStr(int i)
    {
#line 467
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return String(value);
    };
    
    String String::IntStr64(Lang::int64 i)
    {
#line 473
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return String(value);
    };
    
#line 667
    int String::Length(const Char *c, int max_len)
    {
        {
#line 668
            if (!(c))
            {
#line 668
                Lang::SysBreak("Assertion failed: c");
            }
        }
#line 669
        ;
#line 669
        if (!c)
#line 669
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 672
            while (*c)
                {
#line 673
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 679
            while (max_len > 0 && *c)
                {
#line 680
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 394
    String String::Mid(int i) const
    {
#line 394
        if (i >= GetCount())
#line 394
            return Empty();
#line 394
        if (i < 0)
#line 394
            i = 0;
#line 394
        return Mid(i, GetCount() - i);
    };
    
#line 395
    String String::Mid(int i, int size) const
    {
#line 396
        size = Algorithm::Minimum(size, count - i);
        if (size <= 0)
#line 397
            return String();
        {
#line 398
            if (!(i >= 0 && i + size <= count))
            {
#line 398
                Lang::SysBreak("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 399
        ;
#line 399
        return String(Begin() + i, size);
    };
    
#line 404
    void String::Remove(int begin, int count)
    {
        {
#line 405
            if (!(begin >= 0 && count >= 0))
            {
#line 405
                Lang::SysBreak("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 406
        ;
#line 406
        begin = Algorithm::Maximum(0, begin);
        count = Algorithm::Maximum(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 410
            if (!(begin <= c && end <= c))
            {
#line 410
                Lang::SysBreak("Assertion failed: begin <= c && end <= c");
            }
        }
#line 411
        ;
#line 411
        end = Algorithm::Minimum(c, end);
        begin = Algorithm::Minimum(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 417
        if (l)
            *this = Left(l);
        else 
#line 419
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 279
    void String::Replace(const String& s, const String& value)
    {
#line 280
        if (s == value)
#line 280
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 283
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void String::Replace(int i, int len, const String& value)
    {
#line 289
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 295
            Lang::Memory::Copy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 299
            Lang::Memory::Copy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 305
            Lang::Memory::Copy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 310
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        {
#line 314
            if (!(cursor == new_len + 1))
            {
#line 314
                Lang::SysBreak("Assertion failed: cursor == new_len+1");
            }
        }
#line 315
        ;
    };
    
#line 334
    int String::ReverseFind(const String& str, int pos) const
    {
#line 335
        if (GetCount() == 0)
#line 335
            return - 1;
        {
#line 336
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 336
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 337
        ;
#line 337
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 341
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 370
    int String::ReverseFindFirstNotOf(const Char *str) const
    {
#line 371
        if (GetCount() <= 0 || !str)
#line 371
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 376
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 380
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 383
                        if (chr == cmp_chr)
                        {
#line 384
                            match = true;
                            break;
                        
                        }
                    }
#line 388
                i -- ;
                if (!match)
                    return i;
            }
        return - 1;
    };
    
#line 111
    void String::Serialize(Abstract::Stream& s)
    {
#line 112
        if (s.IsStoring())
        {
#line 113
            s.Put(&count, sizeof (count));
            if (count)
            {
#line 115
                if (!is_ref)
                    s.Put(buf, count);
                else
                    s.Put(ref[0] -> Get(), count);
            }
        }
        else 
#line 121
        if (s.IsLoading())
        {
#line 122
            Clear();
            s.Get(&count, sizeof (count));
            {
#line 124
                if (!(count >= 0))
                {
#line 124
                    Lang::SysBreak("Assertion failed: count >= 0");
                }
            }
#line 125
            ;
#line 125
            if (count < 0)
#line 125
                count = 0;
            if (count > 0)
            {
#line 127
                if (count < 8)
                {
#line 128
                    s.Get(buf, sizeof (Char) * count);
                    buf[count] = 0;
                }
                else
                {
#line 132
                    ref[0] = new RefData;
                    ref[0] -> Inc();
                    ref[0] -> Reserve(count + 1);
                    Char * buf = ref[0] -> Begin();
                    s.Get(buf, sizeof (Char) * count);
                    int c = count;
                    buf[c] = 0;
                    is_ref = true;
                }
            }
        }
    };
    
    String& String::Set(const Char *c, int len, bool find_end)
    {
#line 146
        Clear();
        if (!c)
#line 147
            return *this;
        if (find_end)
#line 148
            count = Algorithm::Minimum(Lang::StringLength(c, len), len);
        else
#line 149
            count = len;
        if (count < 8)
        {
#line 151
            Lang::Memory::Copy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
        }
        else
        {
#line 155
            Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (count + 1));
            Lang::Memory::Copy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
            ref[0] = new RefData(buf, count + 1);
            ref[0] -> Inc();
            is_ref = true;
        }
        return *this;
    };
    
#line 93
    void String::Zero()
    {
#line 99 "../../src/Com/Meta.fog"
        Lang::Memory::Set(this, 0, sizeof (String));
    };
    
#line 36 "../../src/Com/Text.fog"
    String::RefData::RefData()
    :
        data(0),
        reserved(0)
    {};
    
#line 37
    String::RefData::RefData(Char *str, int reserved)
    :
        data(str),
        reserved(reserved)
    {};
    
#line 38
    String::RefData::~RefData()
    {
#line 38
        Clear();
    };
    
#line 75
    String::RefData::operator ConstChar * () const
    {
#line 75
        return data;
    };
    
#line 74
    String::Char *String::RefData::Begin()
    {
#line 74
        return data;
    };
    
#line 40
    void String::RefData::Clear()
    {
#line 40
        if (data)
        {
#line 40
            Lang::Memory::Free(data);
#line 40
            data = 0;
#line 40
            refs = 0;
#line 40
            reserved = 0;
        }
    };
    
#line 94 "../../src/Com/Meta.fog"
    void String::RefData::Dec()
    {
#line 94
        refs -- ;
#line 94
        if (refs <= 0)
#line 94
            delete this;
    };
    
#line 73 "../../src/Com/Text.fog"
    String::ConstChar *String::RefData::Get() const
    {
#line 73
        return data;
    };
    
#line 92 "../../src/Com/Meta.fog"
    int String::RefData::GetRefs() const
    {
#line 92
        return refs;
    };
    
#line 77 "../../src/Com/Text.fog"
    int String::RefData::GetReserved() const
    {
#line 77
        return reserved;
    };
    
#line 93 "../../src/Com/Meta.fog"
    void String::RefData::Inc()
    {
#line 93
        refs ++ ;
    };
    
#line 42 "../../src/Com/Text.fog"
    void String::RefData::IncreaseReserved()
    {
#line 43
        Lang::uint64 new_reserved = 1;
        while (new_reserved <= reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void String::RefData::IncreaseReserved(int min_reserved)
    {
#line 52
        Lang::uint64 new_reserved = 1;
        while (new_reserved <= min_reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void String::RefData::Reserve(int new_reserved)
    {
#line 61
        if (new_reserved <= reserved)
            return;
        Char * new_data = (Char * ) Lang::Memory::Alloc(new_reserved * sizeof (Char));
        if (data)
        {
#line 65
            if (reserved > 0)
                Lang::Memory::Copy(new_data, data, sizeof (Char) * reserved);
            Lang::Memory::Free(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
#line 98
    WString::WString()
    :
        is_ref(false),
        count(0)
    {
#line 98
        Zero();
    };
    
    WString::WString(const WString& s)
    :
        is_ref(false),
        count(0)
    {
#line 101
        Zero();
#line 101
        *this = s;
    };
    
#line 99
    WString::WString(const Char *c)
    :
        is_ref(false),
        count(0)
    {
#line 99
        Zero();
#line 99
        *this = c;
    };
    
#line 100
    WString::WString(const Char *c, int len)
    :
        is_ref(false),
        count(0)
    {
#line 100
        Zero();
#line 100
        Set(c, len);
    };
    
#line 102
    WString::~WString()
    {
#line 102
        Clear();
    };
    
#line 458
    WString WString::operator+ (const WString& s)
    {
#line 458
        WString out(*this);
#line 458
        out.Cat(s);
#line 458
        return out;
    };
    
#line 183
    WString WString::operator+ (const WString& l) const
    {
#line 184
        WString s(*this);
        s.Cat(l);
        return s;
    };
    
#line 165
    WString& WString::operator= (const WString& str)
    {
#line 166
        if (!str.is_ref)
        {
#line 167
            Clear();
            Lang::Memory::Copy(buf, str.buf, sizeof (buf));
            is_ref = false;
        }
        else
        {
#line 172
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
    
#line 445
    bool WString::operator== (const WString& s) const
    {
#line 446
        if (s.GetCount() != GetCount())
#line 446
            return false;
        if (s.IsEmpty())
#line 447
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 453
    WString::Char WString::At(int i) const
    {
        {
#line 453
            if (!(i >= 0 && i < count))
            {
#line 453
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 453
        ;
#line 453
        return *(Begin() + i);
    };
    
#line 442
    const WString::Char *WString::Begin() const
    {
#line 442
        if (is_ref)
#line 442
            return ref[0] -> Get();
        else
#line 442
            return buf;
    };
    
#line 195
    WString& WString::Cat(Char i)
    {
#line 196
        if (!is_ref)
        {
#line 197
            is_ref = count + 1 >= 8;
            if (!is_ref)
            {
#line 199
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
            }
            else
            {
#line 204
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (count + 1 + 1));
                Lang::Memory::Copy(buf, this -> buf, sizeof (Char) * count);
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
                ref[0] = new RefData(buf, count + 1);
                is_ref = true;
            }
        }
        else
        {
#line 214
            if (ref[0] -> GetRefs() == 1)
            {
#line 215
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
#line 224
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (count + 1 + 1));
                Lang::Memory::Copy(buf, ref[0] -> Get(), sizeof (Char) * count);
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
                ref[0] -> Dec();
                ref[0] = new RefData(buf, count + 1);
            }
        }
        return *this;
    };
    
#line 189
    WString& WString::Cat(Char c, int count)
    {
        for (int i = 0; i < count; i ++ )
#line 191
            Cat(c);
        return *this;
    };
    
#line 238
    WString& WString::Cat(const WString& str)
    {
#line 239
        if (!is_ref)
        {
#line 240
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 242
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 246
                int reserved = count + str.GetCount() + 1;
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
                Lang::Memory::Copy(buf, this -> buf, sizeof (Char) * count);
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
                ref[0] = new RefData(buf, reserved);
                is_ref = true;
            }
        }
        else
        {
#line 256
            if (ref[0] -> GetRefs() == 1)
            {
#line 257
                int new_count = count + str.GetCount() + 1;
                if (new_count > ref[0] -> GetReserved())
                    ref[0] -> IncreaseReserved(new_count);
                Char * c = ref[0] -> Begin();
                Lang::Memory::Copy(c + count, str.Begin(), sizeof (Char) * str.GetCount());
                count += str.GetCount();
                c[count] = 0;
            }
            else
            {
#line 266
                int reserved = count + str.GetCount() + 1;
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
                Lang::Memory::Copy(buf, ref[0] -> Get(), sizeof (Char) * count);
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
                buf[count] = 0;
                ref[0] -> Dec();
                ref[0] = new RefData(buf, reserved);
            }
        }
        return *this;
    };
    
#line 562
    double WString::CharDbl(const Char *s)
    {
#line 563
        double a = 0.0;
        int e = 0;
        int c;
#line 567
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 568
                a = a * 10.0 + (c - '0');
            }
#line 571
        if (c == '.')
        {
#line 572
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 573
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 578
        if (c == 'e' || c == 'E')
        {
#line 579
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 583
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 587
                c = *s ++ ;
                sign = - 1;
            }
#line 591
            while (IsDigit(c))
                {
#line 592
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 596
            e += i * sign;
        }
#line 599
        while (e > 0)
            {
#line 600
                a *= 10.0;
                e -- ;
            }
#line 604
        while (e < 0)
            {
#line 605
                a *= 0.1;
                e ++ ;
            }
#line 609
        return a;
    };
    
#line 508
    int WString::CharHexInt(const Char *s)
    {
#line 509
        if (!s)
#line 509
            return 0;
        while (IsSpace(*s))
#line 510
            s ++ ;
        int n = 0;
#line 511
        int neg = 0;
        switch (*s)
        {
#line 513
            case '-':
#line 513
                neg = 1;
            case '+':
#line 514
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 520
            return n;
        else
#line 520
            return - n;
    };
    
    int WString::CharInt(const Char *s)
    {
        int n = 0;
#line 525
        int neg = 0;
        while (IsSpace(*s))
#line 526
            s ++ ;
        switch (*s)
        {
#line 528
            case '-':
#line 528
                neg = 1;
            case '+':
#line 529
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 533
            return n;
        else
#line 533
            return - n;
    };
    
    Lang::int64 WString::CharInt64(const Char *s)
    {
        Lang::int64 n = 0;
#line 538
        Lang::int64 neg = 0;
        while (IsSpace(*s))
#line 539
            s ++ ;
        switch (*s)
        {
#line 541
            case '-':
#line 541
                neg = 1;
            case '+':
#line 542
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 546
            return n;
        else
#line 546
            return - n;
    };
    
    Lang::uint64 WString::CharIntU64(const Char *s)
    {
        Lang::uint64 n = 0;
        while (IsSpace(*s))
#line 552
            s ++ ;
        switch (*s)
        {
#line 554
            case '-':
#line 554
                return 0;
            case '+':
#line 555
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 494
    int WString::CharOctInt(const Char *s)
    {
#line 495
        if (!s)
#line 495
            return 0;
        while (IsSpace(*s))
#line 496
            s ++ ;
        int n = 0;
#line 497
        int neg = 0;
        switch (*s)
        {
#line 499
            case '-':
#line 499
                neg = 1;
            case '+':
#line 500
                s ++ ;
        }
        while (*s == '0')
#line 502
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 505
            return n;
        else
#line 505
            return - n;
    };
    
#line 105
    void WString::Clear()
    {
#line 106
        if (is_ref)
        {
#line 106
            ref[0] -> Dec();
#line 106
            ref[0] = 0;
#line 106
            is_ref = false;
        }
        else
        {
#line 107
            ref[0] = 0;
        }
#line 108
        count = 0;
    };
    
#line 688
    int WString::Compare(const Char *a, const Char *b)
    {
#line 689
        while (*a || *b)
            {
#line 690
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
#line 700
        while ((*a || *b) && len > 0)
            {
#line 701
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
#line 712
            if (!(dst && src))
            {
#line 712
                Lang::SysBreak("Assertion failed: dst && src");
            }
        }
#line 713
        ;
#line 713
        if (!dst || !src)
#line 713
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 478
    WString WString::DblStr(double d)
    {
#line 479
        Char output[50];
        Native::DblStr(d, output, 50);
        return WString(output);
    };
    
#line 319
    int WString::Find(const WString& str, int pos) const
    {
#line 320
        if (GetCount() == 0)
#line 320
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 323
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 323
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 324
        ;
#line 324
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 328
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 346
    int WString::FindFirstNotOf(const Char *str) const
    {
#line 347
        if (GetCount() <= 0 || !str)
#line 347
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 352
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 356
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 359
                        if (chr == cmp_chr)
                        {
#line 360
                            match = true;
                            break;
                        
                        }
                    }
#line 364
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 486
    Lang::uint32 WString::GetHashValue() const
    {
#line 487
        Hash::Combine ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 424
    bool WString::Insert(int begin, const Char *str, int n)
    {
#line 425
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 427
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 427
                Lang::SysBreak("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 428
        ;
#line 428
        begin = Algorithm::Maximum(0, Algorithm::Minimum(begin, GetCount()));
        WString part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 434
        if (l)
            *this = Left(l) + part;
        else 
#line 436
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 612
    const WString::Char *WString::IntChar(Char *p, int bufsize, int x)
    {
#line 613
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 616
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 621
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 625
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const WString::Char *WString::IntChar64(Char *p, int bufsize, Lang::int64 x)
    {
#line 631
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 634
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 639
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 643
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const WString::Char *WString::IntCharU64(Char *p, int bufsize, Lang::uint64 x)
    {
#line 649
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 652
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 657
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 661
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
#line 466
    WString WString::IntStr(int i)
    {
#line 467
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return WString(value);
    };
    
    WString WString::IntStr64(Lang::int64 i)
    {
#line 473
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return WString(value);
    };
    
#line 667
    int WString::Length(const Char *c, int max_len)
    {
        {
#line 668
            if (!(c))
            {
#line 668
                Lang::SysBreak("Assertion failed: c");
            }
        }
#line 669
        ;
#line 669
        if (!c)
#line 669
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 672
            while (*c)
                {
#line 673
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 679
            while (max_len > 0 && *c)
                {
#line 680
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 394
    WString WString::Mid(int i) const
    {
#line 394
        if (i >= GetCount())
#line 394
            return Empty();
#line 394
        if (i < 0)
#line 394
            i = 0;
#line 394
        return Mid(i, GetCount() - i);
    };
    
#line 395
    WString WString::Mid(int i, int size) const
    {
#line 396
        size = Algorithm::Minimum(size, count - i);
        if (size <= 0)
#line 397
            return WString();
        {
#line 398
            if (!(i >= 0 && i + size <= count))
            {
#line 398
                Lang::SysBreak("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 399
        ;
#line 399
        return WString(Begin() + i, size);
    };
    
#line 404
    void WString::Remove(int begin, int count)
    {
        {
#line 405
            if (!(begin >= 0 && count >= 0))
            {
#line 405
                Lang::SysBreak("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 406
        ;
#line 406
        begin = Algorithm::Maximum(0, begin);
        count = Algorithm::Maximum(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 410
            if (!(begin <= c && end <= c))
            {
#line 410
                Lang::SysBreak("Assertion failed: begin <= c && end <= c");
            }
        }
#line 411
        ;
#line 411
        end = Algorithm::Minimum(c, end);
        begin = Algorithm::Minimum(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 417
        if (l)
            *this = Left(l);
        else 
#line 419
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 279
    void WString::Replace(const WString& s, const WString& value)
    {
#line 280
        if (s == value)
#line 280
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 283
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void WString::Replace(int i, int len, const WString& value)
    {
#line 289
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 295
            Lang::Memory::Copy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 299
            Lang::Memory::Copy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 305
            Lang::Memory::Copy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 310
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        {
#line 314
            if (!(cursor == new_len + 1))
            {
#line 314
                Lang::SysBreak("Assertion failed: cursor == new_len+1");
            }
        }
#line 315
        ;
    };
    
#line 334
    int WString::ReverseFind(const WString& str, int pos) const
    {
#line 335
        if (GetCount() == 0)
#line 335
            return - 1;
        {
#line 336
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 336
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 337
        ;
#line 337
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 341
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 370
    int WString::ReverseFindFirstNotOf(const Char *str) const
    {
#line 371
        if (GetCount() <= 0 || !str)
#line 371
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 376
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 380
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 383
                        if (chr == cmp_chr)
                        {
#line 384
                            match = true;
                            break;
                        
                        }
                    }
#line 388
                i -- ;
                if (!match)
                    return i;
            }
        return - 1;
    };
    
#line 111
    void WString::Serialize(Abstract::Stream& s)
    {
#line 112
        if (s.IsStoring())
        {
#line 113
            s.Put(&count, sizeof (count));
            if (count)
            {
#line 115
                if (!is_ref)
                    s.Put(buf, count);
                else
                    s.Put(ref[0] -> Get(), count);
            }
        }
        else 
#line 121
        if (s.IsLoading())
        {
#line 122
            Clear();
            s.Get(&count, sizeof (count));
            {
#line 124
                if (!(count >= 0))
                {
#line 124
                    Lang::SysBreak("Assertion failed: count >= 0");
                }
            }
#line 125
            ;
#line 125
            if (count < 0)
#line 125
                count = 0;
            if (count > 0)
            {
#line 127
                if (count < 8)
                {
#line 128
                    s.Get(buf, sizeof (Char) * count);
                    buf[count] = 0;
                }
                else
                {
#line 132
                    ref[0] = new RefData;
                    ref[0] -> Inc();
                    ref[0] -> Reserve(count + 1);
                    Char * buf = ref[0] -> Begin();
                    s.Get(buf, sizeof (Char) * count);
                    int c = count;
                    buf[c] = 0;
                    is_ref = true;
                }
            }
        }
    };
    
    WString& WString::Set(const Char *c, int len, bool find_end)
    {
#line 146
        Clear();
        if (!c)
#line 147
            return *this;
        if (find_end)
#line 148
            count = Algorithm::Minimum(Lang::StringLength(c, len), len);
        else
#line 149
            count = len;
        if (count < 8)
        {
#line 151
            Lang::Memory::Copy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
        }
        else
        {
#line 155
            Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (count + 1));
            Lang::Memory::Copy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
            ref[0] = new RefData(buf, count + 1);
            ref[0] -> Inc();
            is_ref = true;
        }
        return *this;
    };
    
#line 93
    void WString::Zero()
    {
#line 99 "../../src/Com/Meta.fog"
        Lang::Memory::Set(this, 0, sizeof (WString));
    };
    
#line 36 "../../src/Com/Text.fog"
    WString::RefData::RefData()
    :
        data(0),
        reserved(0)
    {};
    
#line 37
    WString::RefData::RefData(Char *str, int reserved)
    :
        data(str),
        reserved(reserved)
    {};
    
#line 38
    WString::RefData::~RefData()
    {
#line 38
        Clear();
    };
    
#line 75
    WString::RefData::operator ConstChar * () const
    {
#line 75
        return data;
    };
    
#line 74
    WString::Char *WString::RefData::Begin()
    {
#line 74
        return data;
    };
    
#line 40
    void WString::RefData::Clear()
    {
#line 40
        if (data)
        {
#line 40
            Lang::Memory::Free(data);
#line 40
            data = 0;
#line 40
            refs = 0;
#line 40
            reserved = 0;
        }
    };
    
#line 94 "../../src/Com/Meta.fog"
    void WString::RefData::Dec()
    {
#line 94
        refs -- ;
#line 94
        if (refs <= 0)
#line 94
            delete this;
    };
    
#line 73 "../../src/Com/Text.fog"
    WString::ConstChar *WString::RefData::Get() const
    {
#line 73
        return data;
    };
    
#line 92 "../../src/Com/Meta.fog"
    int WString::RefData::GetRefs() const
    {
#line 92
        return refs;
    };
    
#line 77 "../../src/Com/Text.fog"
    int WString::RefData::GetReserved() const
    {
#line 77
        return reserved;
    };
    
#line 93 "../../src/Com/Meta.fog"
    void WString::RefData::Inc()
    {
#line 93
        refs ++ ;
    };
    
#line 42 "../../src/Com/Text.fog"
    void WString::RefData::IncreaseReserved()
    {
#line 43
        Lang::uint64 new_reserved = 1;
        while (new_reserved <= reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void WString::RefData::IncreaseReserved(int min_reserved)
    {
#line 52
        Lang::uint64 new_reserved = 1;
        while (new_reserved <= min_reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void WString::RefData::Reserve(int new_reserved)
    {
#line 61
        if (new_reserved <= reserved)
            return;
        Char * new_data = (Char * ) Lang::Memory::Alloc(new_reserved * sizeof (Char));
        if (data)
        {
#line 65
            if (reserved > 0)
                Lang::Memory::Copy(new_data, data, sizeof (Char) * reserved);
            Lang::Memory::Free(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
};

#endif
