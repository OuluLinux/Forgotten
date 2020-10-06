#ifndef TEXT_CXX
#define TEXT_CXX

#include <new>

#ifndef TEXT_HXX
#include <Text.hxx>
#endif

namespace Text
{
#line 896 "../../src/Com/Text.fog"
    String EscapeCharacter(String s)
    {
#line 897
        s.Replace("\n", "\\n");
        s.Replace("\t", "\\t");
        s.Replace("\r", "\\r");
        s.Replace("\"", "\\\"");
        s.Replace("'", "\\'");
#line 903
        return s;
    };
    
#line 887
    String EscapeString(String s)
    {
#line 888
        s.Replace("\n", "\\n");
        s.Replace("\t", "\\t");
        s.Replace("\r", "\\r");
        s.Replace("\"", "\\\"");
#line 893
        return s;
    };
    
#line 783
    String ToLower(const String& s)
    {
#line 784
        int count = s.GetCount();
        if (!count)
#line 785
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
    
#line 763
    int ToLowerChar(int chr)
    {
#line 764
        if (chr >= 'A' && chr <= 'Z')
            return 'a' + (chr - 'A');
        return chr;
    };
    
    String ToUpper(const String& s)
    {
#line 770
        int count = s.GetCount();
        if (!count)
#line 771
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
    
#line 757
    int ToUpperChar(int chr)
    {
#line 758
        if (chr >= 'a' && chr <= 'z')
            return 'A' + (chr - 'a');
        return chr;
    };
    
#line 813
    String TrimBoth(String s)
    {
#line 814
        if (s.IsEmpty())
            return s;
        String out;
        int begin = s.FindFirstNotOf(" \t\n\r");
        if (begin < 0)
            return "";
        int end = s.ReverseFindFirstNotOf(" \t\n\r");
        if (end < 0)
            return "";
        end ++ ;
        if (end <= begin)
            return "";
        return s.Mid(begin, end - begin);
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
    
#line 463
    String String::operator+ (const String& s)
    {
#line 463
        String out(*this);
#line 463
        out.Cat(s);
#line 463
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
    
#line 450
    bool String::operator== (const String& s) const
    {
#line 451
        if (s.GetCount() != GetCount())
#line 451
            return false;
        if (s.IsEmpty())
#line 452
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 458
    String::Char String::At(int i) const
    {
        {
#line 458
            if (!(i >= 0 && i < count))
            {
#line 458
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 458
        ;
#line 458
        return *(Begin() + i);
    };
    
#line 447
    const String::Char *String::Begin() const
    {
#line 447
        if (is_ref)
        {
            {
#line 447
                if (!(ref[0] && ref[0] -> Get()))
                {
#line 447
                    Lang::SysBreak("Assertion failed: REF && REF->Get()");
                }
            }
#line 447
            ;
#line 447
            return ref[0] -> Get();
        }
        else
#line 447
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
                ref[0] -> Inc();
                is_ref = true;
            }
        }
        else
        {
#line 215
            if (ref[0] -> GetRefs() == 1)
            {
#line 216
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
#line 225
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (count + 1 + 1));
                Lang::Memory::Copy(buf, ref[0] -> Get(), sizeof (Char) * count);
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
                ref[0] -> Dec();
                ref[0] = new RefData(buf, count + 1);
                ref[0] -> Inc();
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
    
#line 240
    String& String::Cat(const String& str)
    {
#line 241
        if (!is_ref)
        {
#line 242
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 244
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 248
                int reserved = count + str.GetCount() + 1;
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
                Lang::Memory::Copy(buf, this -> buf, sizeof (Char) * count);
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
                ref[0] = new RefData(buf, reserved);
                ref[0] -> Inc();
                is_ref = true;
            }
        }
        else
        {
#line 259
            if (ref[0] -> GetRefs() == 1)
            {
#line 260
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
#line 269
                int reserved = count + str.GetCount() + 1;
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
                Lang::Memory::Copy(buf, ref[0] -> Get(), sizeof (Char) * count);
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
                buf[count] = 0;
                ref[0] -> Dec();
                ref[0] = new RefData(buf, reserved);
                ref[0] -> Inc();
            }
        }
        return *this;
    };
    
#line 567
    double String::CharDbl(const Char *s)
    {
#line 568
        double a = 0.0;
        int e = 0;
        int c;
#line 572
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 573
                a = a * 10.0 + (c - '0');
            }
#line 576
        if (c == '.')
        {
#line 577
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 578
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 583
        if (c == 'e' || c == 'E')
        {
#line 584
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 588
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 592
                c = *s ++ ;
                sign = - 1;
            }
#line 596
            while (IsDigit(c))
                {
#line 597
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 601
            e += i * sign;
        }
#line 604
        while (e > 0)
            {
#line 605
                a *= 10.0;
                e -- ;
            }
#line 609
        while (e < 0)
            {
#line 610
                a *= 0.1;
                e ++ ;
            }
#line 614
        return a;
    };
    
#line 513
    int String::CharHexInt(const Char *s)
    {
#line 514
        if (!s)
#line 514
            return 0;
        while (IsSpace(*s))
#line 515
            s ++ ;
        int n = 0;
#line 516
        int neg = 0;
        switch (*s)
        {
#line 518
            case '-':
#line 518
                neg = 1;
            case '+':
#line 519
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 525
            return n;
        else
#line 525
            return - n;
    };
    
    int String::CharInt(const Char *s)
    {
        int n = 0;
#line 530
        int neg = 0;
        while (IsSpace(*s))
#line 531
            s ++ ;
        switch (*s)
        {
#line 533
            case '-':
#line 533
                neg = 1;
            case '+':
#line 534
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 538
            return n;
        else
#line 538
            return - n;
    };
    
    Lang::int64 String::CharInt64(const Char *s)
    {
        Lang::int64 n = 0;
#line 543
        Lang::int64 neg = 0;
        while (IsSpace(*s))
#line 544
            s ++ ;
        switch (*s)
        {
#line 546
            case '-':
#line 546
                neg = 1;
            case '+':
#line 547
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 551
            return n;
        else
#line 551
            return - n;
    };
    
    Lang::uint64 String::CharIntU64(const Char *s)
    {
        Lang::uint64 n = 0;
        while (IsSpace(*s))
#line 557
            s ++ ;
        switch (*s)
        {
#line 559
            case '-':
#line 559
                return 0;
            case '+':
#line 560
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 499
    int String::CharOctInt(const Char *s)
    {
#line 500
        if (!s)
#line 500
            return 0;
        while (IsSpace(*s))
#line 501
            s ++ ;
        int n = 0;
#line 502
        int neg = 0;
        switch (*s)
        {
#line 504
            case '-':
#line 504
                neg = 1;
            case '+':
#line 505
                s ++ ;
        }
        while (*s == '0')
#line 507
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 510
            return n;
        else
#line 510
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
    
#line 693
    int String::Compare(const Char *a, const Char *b)
    {
#line 694
        while (*a || *b)
            {
#line 695
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
#line 705
        while ((*a || *b) && len > 0)
            {
#line 706
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
#line 717
            if (!(dst && src))
            {
#line 717
                Lang::SysBreak("Assertion failed: dst && src");
            }
        }
#line 718
        ;
#line 718
        if (!dst || !src)
#line 718
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 483
    String String::DblStr(double d)
    {
#line 484
        Char output[50];
        Native::DblStr(d, output, 50);
        return String(output);
    };
    
#line 324
    int String::Find(const String& str, int pos) const
    {
#line 325
        if (GetCount() == 0)
#line 325
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 328
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 328
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 329
        ;
#line 329
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 333
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 351
    int String::FindFirstNotOf(const Char *str) const
    {
#line 352
        if (GetCount() <= 0 || !str)
#line 352
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 357
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 361
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 364
                        if (chr == cmp_chr)
                        {
#line 365
                            match = true;
                            break;
                        
                        }
                    }
#line 369
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 491
    Lang::uint32 String::GetHashValue() const
    {
#line 492
        Hash::Combine ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 429
    bool String::Insert(int begin, const Char *str, int n)
    {
#line 430
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 432
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 432
                Lang::SysBreak("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 433
        ;
#line 433
        begin = Algorithm::Maximum(0, Algorithm::Minimum(begin, GetCount()));
        String part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 439
        if (l)
            *this = Left(l) + part;
        else 
#line 441
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 617
    const String::Char *String::IntChar(Char *p, int bufsize, int x)
    {
#line 618
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 621
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 626
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 630
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const String::Char *String::IntChar64(Char *p, int bufsize, Lang::int64 x)
    {
#line 636
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 639
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 644
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 648
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const String::Char *String::IntCharU64(Char *p, int bufsize, Lang::uint64 x)
    {
#line 654
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 657
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 662
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 666
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
#line 471
    String String::IntStr(int i)
    {
#line 472
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return String(value);
    };
    
    String String::IntStr64(Lang::int64 i)
    {
#line 478
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return String(value);
    };
    
#line 672
    int String::Length(const Char *c, int max_len)
    {
        {
#line 673
            if (!(c))
            {
#line 673
                Lang::SysBreak("Assertion failed: c");
            }
        }
#line 674
        ;
#line 674
        if (!c)
#line 674
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 677
            while (*c)
                {
#line 678
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 684
            while (max_len > 0 && *c)
                {
#line 685
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 399
    String String::Mid(int i) const
    {
#line 399
        if (i >= GetCount())
#line 399
            return Empty();
#line 399
        if (i < 0)
#line 399
            i = 0;
#line 399
        return Mid(i, GetCount() - i);
    };
    
#line 400
    String String::Mid(int i, int size) const
    {
#line 401
        size = Algorithm::Minimum(size, count - i);
        if (size <= 0)
#line 402
            return String();
        {
#line 403
            if (!(i >= 0 && i + size <= count))
            {
#line 403
                Lang::SysBreak("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 404
        ;
#line 404
        return String(Begin() + i, size);
    };
    
#line 409
    void String::Remove(int begin, int count)
    {
        {
#line 410
            if (!(begin >= 0 && count >= 0))
            {
#line 410
                Lang::SysBreak("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 411
        ;
#line 411
        begin = Algorithm::Maximum(0, begin);
        count = Algorithm::Maximum(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 415
            if (!(begin <= c && end <= c))
            {
#line 415
                Lang::SysBreak("Assertion failed: begin <= c && end <= c");
            }
        }
#line 416
        ;
#line 416
        end = Algorithm::Minimum(c, end);
        begin = Algorithm::Minimum(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 422
        if (l)
            *this = Left(l);
        else 
#line 424
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 283
    void String::Replace(const String& s, const String& value)
    {
#line 284
        if (s == value)
#line 284
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 287
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void String::Replace(int i, int len, const String& value)
    {
#line 293
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 299
            Lang::Memory::Copy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 303
            Lang::Memory::Copy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 309
            Lang::Memory::Copy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 314
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        ref[0] -> Inc();
        {
#line 319
            if (!(cursor == new_len + 1))
            {
#line 319
                Lang::SysBreak("Assertion failed: cursor == new_len+1");
            }
        }
#line 320
        ;
    };
    
#line 339
    int String::ReverseFind(const String& str, int pos) const
    {
#line 340
        if (GetCount() == 0)
#line 340
            return - 1;
        {
#line 341
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 341
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 342
        ;
#line 342
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 346
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 375
    int String::ReverseFindFirstNotOf(const Char *str) const
    {
#line 376
        if (GetCount() <= 0 || !str)
#line 376
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 381
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 385
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 388
                        if (chr == cmp_chr)
                        {
#line 389
                            match = true;
                            break;
                        
                        }
                    }
#line 393
                i -- ;
                if (!match)
                    return i;
            }
        return - 1;
    };
    
#line 111
    void String::Serialize(Abstract::StreamBase& s)
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
#line 130 "../../src/Com/Meta.fog"
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
    
#line 125 "../../src/Com/Meta.fog"
    void String::RefData::Dec()
    {
#line 125
        refs -- ;
#line 125
        if (refs <= 0)
#line 125
            delete this;
    };
    
#line 73 "../../src/Com/Text.fog"
    String::ConstChar *String::RefData::Get() const
    {
#line 73
        return data;
    };
    
#line 123 "../../src/Com/Meta.fog"
    int String::RefData::GetRefs() const
    {
#line 123
        return refs;
    };
    
#line 77 "../../src/Com/Text.fog"
    int String::RefData::GetReserved() const
    {
#line 77
        return reserved;
    };
    
#line 124 "../../src/Com/Meta.fog"
    void String::RefData::Inc()
    {
#line 124
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
    
#line 463
    WString WString::operator+ (const WString& s)
    {
#line 463
        WString out(*this);
#line 463
        out.Cat(s);
#line 463
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
    
#line 450
    bool WString::operator== (const WString& s) const
    {
#line 451
        if (s.GetCount() != GetCount())
#line 451
            return false;
        if (s.IsEmpty())
#line 452
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 458
    WString::Char WString::At(int i) const
    {
        {
#line 458
            if (!(i >= 0 && i < count))
            {
#line 458
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 458
        ;
#line 458
        return *(Begin() + i);
    };
    
#line 447
    const WString::Char *WString::Begin() const
    {
#line 447
        if (is_ref)
        {
            {
#line 447
                if (!(ref[0] && ref[0] -> Get()))
                {
#line 447
                    Lang::SysBreak("Assertion failed: REF && REF->Get()");
                }
            }
#line 447
            ;
#line 447
            return ref[0] -> Get();
        }
        else
#line 447
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
                ref[0] -> Inc();
                is_ref = true;
            }
        }
        else
        {
#line 215
            if (ref[0] -> GetRefs() == 1)
            {
#line 216
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
#line 225
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (count + 1 + 1));
                Lang::Memory::Copy(buf, ref[0] -> Get(), sizeof (Char) * count);
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
                ref[0] -> Dec();
                ref[0] = new RefData(buf, count + 1);
                ref[0] -> Inc();
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
    
#line 240
    WString& WString::Cat(const WString& str)
    {
#line 241
        if (!is_ref)
        {
#line 242
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 244
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 248
                int reserved = count + str.GetCount() + 1;
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
                Lang::Memory::Copy(buf, this -> buf, sizeof (Char) * count);
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
                ref[0] = new RefData(buf, reserved);
                ref[0] -> Inc();
                is_ref = true;
            }
        }
        else
        {
#line 259
            if (ref[0] -> GetRefs() == 1)
            {
#line 260
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
#line 269
                int reserved = count + str.GetCount() + 1;
                Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
                Lang::Memory::Copy(buf, ref[0] -> Get(), sizeof (Char) * count);
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
                buf[count] = 0;
                ref[0] -> Dec();
                ref[0] = new RefData(buf, reserved);
                ref[0] -> Inc();
            }
        }
        return *this;
    };
    
#line 567
    double WString::CharDbl(const Char *s)
    {
#line 568
        double a = 0.0;
        int e = 0;
        int c;
#line 572
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 573
                a = a * 10.0 + (c - '0');
            }
#line 576
        if (c == '.')
        {
#line 577
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 578
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 583
        if (c == 'e' || c == 'E')
        {
#line 584
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 588
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 592
                c = *s ++ ;
                sign = - 1;
            }
#line 596
            while (IsDigit(c))
                {
#line 597
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 601
            e += i * sign;
        }
#line 604
        while (e > 0)
            {
#line 605
                a *= 10.0;
                e -- ;
            }
#line 609
        while (e < 0)
            {
#line 610
                a *= 0.1;
                e ++ ;
            }
#line 614
        return a;
    };
    
#line 513
    int WString::CharHexInt(const Char *s)
    {
#line 514
        if (!s)
#line 514
            return 0;
        while (IsSpace(*s))
#line 515
            s ++ ;
        int n = 0;
#line 516
        int neg = 0;
        switch (*s)
        {
#line 518
            case '-':
#line 518
                neg = 1;
            case '+':
#line 519
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 525
            return n;
        else
#line 525
            return - n;
    };
    
    int WString::CharInt(const Char *s)
    {
        int n = 0;
#line 530
        int neg = 0;
        while (IsSpace(*s))
#line 531
            s ++ ;
        switch (*s)
        {
#line 533
            case '-':
#line 533
                neg = 1;
            case '+':
#line 534
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 538
            return n;
        else
#line 538
            return - n;
    };
    
    Lang::int64 WString::CharInt64(const Char *s)
    {
        Lang::int64 n = 0;
#line 543
        Lang::int64 neg = 0;
        while (IsSpace(*s))
#line 544
            s ++ ;
        switch (*s)
        {
#line 546
            case '-':
#line 546
                neg = 1;
            case '+':
#line 547
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 551
            return n;
        else
#line 551
            return - n;
    };
    
    Lang::uint64 WString::CharIntU64(const Char *s)
    {
        Lang::uint64 n = 0;
        while (IsSpace(*s))
#line 557
            s ++ ;
        switch (*s)
        {
#line 559
            case '-':
#line 559
                return 0;
            case '+':
#line 560
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 499
    int WString::CharOctInt(const Char *s)
    {
#line 500
        if (!s)
#line 500
            return 0;
        while (IsSpace(*s))
#line 501
            s ++ ;
        int n = 0;
#line 502
        int neg = 0;
        switch (*s)
        {
#line 504
            case '-':
#line 504
                neg = 1;
            case '+':
#line 505
                s ++ ;
        }
        while (*s == '0')
#line 507
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 510
            return n;
        else
#line 510
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
    
#line 693
    int WString::Compare(const Char *a, const Char *b)
    {
#line 694
        while (*a || *b)
            {
#line 695
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
#line 705
        while ((*a || *b) && len > 0)
            {
#line 706
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
#line 717
            if (!(dst && src))
            {
#line 717
                Lang::SysBreak("Assertion failed: dst && src");
            }
        }
#line 718
        ;
#line 718
        if (!dst || !src)
#line 718
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 483
    WString WString::DblStr(double d)
    {
#line 484
        Char output[50];
        Native::DblStr(d, output, 50);
        return WString(output);
    };
    
#line 324
    int WString::Find(const WString& str, int pos) const
    {
#line 325
        if (GetCount() == 0)
#line 325
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 328
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 328
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 329
        ;
#line 329
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 333
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 351
    int WString::FindFirstNotOf(const Char *str) const
    {
#line 352
        if (GetCount() <= 0 || !str)
#line 352
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 357
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 361
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 364
                        if (chr == cmp_chr)
                        {
#line 365
                            match = true;
                            break;
                        
                        }
                    }
#line 369
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 491
    Lang::uint32 WString::GetHashValue() const
    {
#line 492
        Hash::Combine ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 429
    bool WString::Insert(int begin, const Char *str, int n)
    {
#line 430
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 432
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 432
                Lang::SysBreak("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 433
        ;
#line 433
        begin = Algorithm::Maximum(0, Algorithm::Minimum(begin, GetCount()));
        WString part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 439
        if (l)
            *this = Left(l) + part;
        else 
#line 441
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 617
    const WString::Char *WString::IntChar(Char *p, int bufsize, int x)
    {
#line 618
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 621
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 626
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 630
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const WString::Char *WString::IntChar64(Char *p, int bufsize, Lang::int64 x)
    {
#line 636
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 639
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 644
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 648
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const WString::Char *WString::IntCharU64(Char *p, int bufsize, Lang::uint64 x)
    {
#line 654
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 657
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 662
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 666
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
#line 471
    WString WString::IntStr(int i)
    {
#line 472
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return WString(value);
    };
    
    WString WString::IntStr64(Lang::int64 i)
    {
#line 478
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return WString(value);
    };
    
#line 672
    int WString::Length(const Char *c, int max_len)
    {
        {
#line 673
            if (!(c))
            {
#line 673
                Lang::SysBreak("Assertion failed: c");
            }
        }
#line 674
        ;
#line 674
        if (!c)
#line 674
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 677
            while (*c)
                {
#line 678
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 684
            while (max_len > 0 && *c)
                {
#line 685
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 399
    WString WString::Mid(int i) const
    {
#line 399
        if (i >= GetCount())
#line 399
            return Empty();
#line 399
        if (i < 0)
#line 399
            i = 0;
#line 399
        return Mid(i, GetCount() - i);
    };
    
#line 400
    WString WString::Mid(int i, int size) const
    {
#line 401
        size = Algorithm::Minimum(size, count - i);
        if (size <= 0)
#line 402
            return WString();
        {
#line 403
            if (!(i >= 0 && i + size <= count))
            {
#line 403
                Lang::SysBreak("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 404
        ;
#line 404
        return WString(Begin() + i, size);
    };
    
#line 409
    void WString::Remove(int begin, int count)
    {
        {
#line 410
            if (!(begin >= 0 && count >= 0))
            {
#line 410
                Lang::SysBreak("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 411
        ;
#line 411
        begin = Algorithm::Maximum(0, begin);
        count = Algorithm::Maximum(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 415
            if (!(begin <= c && end <= c))
            {
#line 415
                Lang::SysBreak("Assertion failed: begin <= c && end <= c");
            }
        }
#line 416
        ;
#line 416
        end = Algorithm::Minimum(c, end);
        begin = Algorithm::Minimum(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 422
        if (l)
            *this = Left(l);
        else 
#line 424
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 283
    void WString::Replace(const WString& s, const WString& value)
    {
#line 284
        if (s == value)
#line 284
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 287
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void WString::Replace(int i, int len, const WString& value)
    {
#line 293
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 299
            Lang::Memory::Copy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 303
            Lang::Memory::Copy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 309
            Lang::Memory::Copy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 314
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        ref[0] -> Inc();
        {
#line 319
            if (!(cursor == new_len + 1))
            {
#line 319
                Lang::SysBreak("Assertion failed: cursor == new_len+1");
            }
        }
#line 320
        ;
    };
    
#line 339
    int WString::ReverseFind(const WString& str, int pos) const
    {
#line 340
        if (GetCount() == 0)
#line 340
            return - 1;
        {
#line 341
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 341
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 342
        ;
#line 342
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 346
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 375
    int WString::ReverseFindFirstNotOf(const Char *str) const
    {
#line 376
        if (GetCount() <= 0 || !str)
#line 376
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 381
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 385
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 388
                        if (chr == cmp_chr)
                        {
#line 389
                            match = true;
                            break;
                        
                        }
                    }
#line 393
                i -- ;
                if (!match)
                    return i;
            }
        return - 1;
    };
    
#line 111
    void WString::Serialize(Abstract::StreamBase& s)
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
#line 130 "../../src/Com/Meta.fog"
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
    
#line 125 "../../src/Com/Meta.fog"
    void WString::RefData::Dec()
    {
#line 125
        refs -- ;
#line 125
        if (refs <= 0)
#line 125
            delete this;
    };
    
#line 73 "../../src/Com/Text.fog"
    WString::ConstChar *WString::RefData::Get() const
    {
#line 73
        return data;
    };
    
#line 123 "../../src/Com/Meta.fog"
    int WString::RefData::GetRefs() const
    {
#line 123
        return refs;
    };
    
#line 77 "../../src/Com/Text.fog"
    int WString::RefData::GetReserved() const
    {
#line 77
        return reserved;
    };
    
#line 124 "../../src/Com/Meta.fog"
    void WString::RefData::Inc()
    {
#line 124
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
