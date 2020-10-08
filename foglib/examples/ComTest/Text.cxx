#ifndef TEXT_CXX
#define TEXT_CXX

#include <new>

#ifndef TEXT_HXX
#include <Text.hxx>
#endif

namespace Text
{
#line 966 "../../src/Com/Text.fog"
    String CharToUTF8(Lang::uint16 chr)
    {
#line 967
        WString ws;
        ws.Cat((int) chr);
        return ToString(ws);
    };
    
#line 956
    String EscapeCharacter(String s)
    {
#line 957
        s.Replace("\n", "\\n");
        s.Replace("\t", "\\t");
        s.Replace("\r", "\\r");
        s.Replace("\"", "\\\"");
        s.Replace("'", "\\'");
#line 963
        return s;
    };
    
#line 947
    String EscapeString(String s)
    {
#line 948
        s.Replace("\n", "\\n");
        s.Replace("\t", "\\t");
        s.Replace("\r", "\\r");
        s.Replace("\"", "\\\"");
#line 953
        return s;
    };
    
#line 793
    String ToLower(const String& s)
    {
#line 794
        int count = s.GetCount();
        if (!count)
#line 795
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
    
#line 773
    int ToLowerChar(int chr)
    {
#line 774
        if (chr >= 'A' && chr <= 'Z')
            return 'a' + (chr - 'A');
        return chr;
    };
    
    String ToUpper(const String& s)
    {
#line 780
        int count = s.GetCount();
        if (!count)
#line 781
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
    
#line 767
    int ToUpperChar(int chr)
    {
#line 768
        if (chr >= 'a' && chr <= 'z')
            return 'A' + (chr - 'a');
        return chr;
    };
    
#line 825
    String TrimBoth(String s)
    {
#line 826
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
    
#line 899
    void UnescapeNumbers(String& s)
    {
#line 900
        String tmp;
        int prev_offset = 0;
        const char * begin = s.Begin();
        const char * it = begin;
        const char * end = s.End();
        for (; it != end; ++ it)
            {
#line 906
                if (*it == '\\')
                {
#line 907
                    int offset = it - begin;
                    if (++ it == end)
                        break;
                    
#line 910
                    char c = *it;
                    if (c == '0')
                    {
#line 912
                        if (++ it == end)
                            break;
                        
#line 914
                        int num = 0;
                        int mul = 1;
                        for (int i = 0; i < 3 && it != end; i ++ , it ++ )
                            {
#line 917
                                char c = *it;
                                if (c >= '0' && c <= '9')
                                {
#line 919
                                    int n = c - '0';
                                    int new_num = num + n * mul;
                                    if (new_num >= 0x100)
                                        break;
                                    
#line 923
                                    num = new_num;
                                    mul *= 10;
                                }
                                else
#line 926
                                    break;
                            
                            }
#line 928
                        tmp << s.Mid(prev_offset, offset - prev_offset);
                        tmp.Cat(num);
                        prev_offset = it - begin;
                    }
                }
            }
        if (tmp.GetCount())
            s = tmp;
    };
    
    String UnescapeString(String s)
    {
#line 939
        s.Replace("\\n", "\n");
        s.Replace("\\t", "\t");
        s.Replace("\\r", "\r");
        s.Replace("\\\"", "\"");
        UnescapeNumbers(s);
        return s;
    };
    
#line 100
    String::String()
    :
        is_ref(false),
        count(0)
    {
#line 100
        Zero();
    };
    
    String::String(const String& s)
    :
        is_ref(false),
        count(0)
    {
#line 103
        Zero();
#line 103
        *this = s;
    };
    
#line 101
    String::String(const Char *c)
    :
        is_ref(false),
        count(0)
    {
#line 101
        Zero();
#line 101
        *this = c;
    };
    
#line 102
    String::String(const Char *c, int len)
    :
        is_ref(false),
        count(0)
    {
#line 102
        Zero();
#line 102
        Set(c, len);
    };
    
#line 104
    String::~String()
    {
#line 104
        Clear();
    };
    
#line 467
    String String::operator+ (const String& s)
    {
#line 467
        String out(*this);
#line 467
        out.Cat(s);
#line 467
        return out;
    };
    
#line 187
    String String::operator+ (const String& l) const
    {
#line 188
        String s(*this);
        s.Cat(l);
        return s;
    };
    
#line 169
    String& String::operator= (const String& str)
    {
#line 170
        if (!str.is_ref)
        {
#line 171
            Clear();
            Lang::Memory::Copy(buf, str.buf, sizeof (buf));
            is_ref = false;
        }
        else
        {
#line 176
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
    
#line 454
    bool String::operator== (const String& s) const
    {
#line 455
        if (s.GetCount() != GetCount())
#line 455
            return false;
        if (s.IsEmpty())
#line 456
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 462
    String::Char String::At(int i) const
    {
        {
#line 462
            if (!(i >= 0 && i < count))
            {
#line 462
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 462
        ;
#line 462
        return *(Begin() + i);
    };
    
#line 451
    const String::Char *String::Begin() const
    {
#line 451
        if (is_ref)
        {
            {
#line 451
                if (!(ref[0] && ref[0] -> Get()))
                {
#line 451
                    Lang::SysBreak("Assertion failed: REF && REF->Get()");
                }
            }
#line 451
            ;
#line 451
            return ref[0] -> Get();
        }
        else
#line 451
            return buf;
    };
    
#line 199
    String& String::Cat(Char i)
    {
#line 200
        if (!is_ref)
        {
#line 201
            is_ref = count + 1 >= 8;
            if (!is_ref)
            {
#line 203
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
            }
            else
            {
#line 208
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
#line 219
            if (ref[0] -> GetRefs() == 1)
            {
#line 220
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
#line 229
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
    
#line 193
    String& String::Cat(Char c, int count)
    {
        for (int i = 0; i < count; i ++ )
#line 195
            Cat(c);
        return *this;
    };
    
#line 244
    String& String::Cat(const String& str)
    {
#line 245
        if (!is_ref)
        {
#line 246
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 248
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 252
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
#line 263
            if (ref[0] -> GetRefs() == 1)
            {
#line 264
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
#line 273
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
    
#line 518
    int String::CharBinInt(const Char *s)
    {
#line 519
        if (!s)
#line 519
            return 0;
        while (IsSpace(*s))
#line 520
            s ++ ;
        int n = 0;
#line 521
        int neg = 0;
        switch (*s)
        {
#line 523
            case '-':
#line 523
                neg = 1;
            case '+':
#line 524
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'b' || s[1] == 'B'))
            s += 2;
        while (IsBinDigit(*s))
            n = 16 * n - GetBinDigit(*s ++ );
        if (neg)
#line 530
            return n;
        else
#line 530
            return - n;
    };
    
#line 587
    double String::CharDbl(const Char *s)
    {
#line 588
        double a = 0.0;
        int e = 0;
        int c;
#line 592
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 593
                a = a * 10.0 + (c - '0');
            }
#line 596
        if (c == '.')
        {
#line 597
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 598
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 603
        if (c == 'e' || c == 'E')
        {
#line 604
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 608
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 612
                c = *s ++ ;
                sign = - 1;
            }
#line 616
            while (IsDigit(c))
                {
#line 617
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 621
            e += i * sign;
        }
#line 624
        while (e > 0)
            {
#line 625
                a *= 10.0;
                e -- ;
            }
#line 629
        while (e < 0)
            {
#line 630
                a *= 0.1;
                e ++ ;
            }
#line 634
        return a;
    };
    
#line 533
    int String::CharHexInt(const Char *s)
    {
#line 534
        if (!s)
#line 534
            return 0;
        while (IsSpace(*s))
#line 535
            s ++ ;
        int n = 0;
#line 536
        int neg = 0;
        switch (*s)
        {
#line 538
            case '-':
#line 538
                neg = 1;
            case '+':
#line 539
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 545
            return n;
        else
#line 545
            return - n;
    };
    
    int String::CharInt(const Char *s)
    {
        int n = 0;
#line 550
        int neg = 0;
        while (IsSpace(*s))
#line 551
            s ++ ;
        switch (*s)
        {
#line 553
            case '-':
#line 553
                neg = 1;
            case '+':
#line 554
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 558
            return n;
        else
#line 558
            return - n;
    };
    
    Lang::int64 String::CharInt64(const Char *s)
    {
        Lang::int64 n = 0;
#line 563
        Lang::int64 neg = 0;
        while (IsSpace(*s))
#line 564
            s ++ ;
        switch (*s)
        {
#line 566
            case '-':
#line 566
                neg = 1;
            case '+':
#line 567
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 571
            return n;
        else
#line 571
            return - n;
    };
    
    Lang::uint64 String::CharIntU64(const Char *s)
    {
        Lang::uint64 n = 0;
        while (IsSpace(*s))
#line 577
            s ++ ;
        switch (*s)
        {
#line 579
            case '-':
#line 579
                return 0;
            case '+':
#line 580
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 504
    int String::CharOctInt(const Char *s)
    {
#line 505
        if (!s)
#line 505
            return 0;
        while (IsSpace(*s))
#line 506
            s ++ ;
        int n = 0;
#line 507
        int neg = 0;
        switch (*s)
        {
#line 509
            case '-':
#line 509
                neg = 1;
            case '+':
#line 510
                s ++ ;
        }
        while (*s == '0')
#line 512
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 515
            return n;
        else
#line 515
            return - n;
    };
    
#line 109
    void String::Clear()
    {
#line 110
        if (is_ref)
        {
#line 110
            ref[0] -> Dec();
#line 110
            ref[0] = 0;
#line 110
            is_ref = false;
        }
        else
        {
#line 111
            ref[0] = 0;
        }
#line 112
        count = 0;
    };
    
#line 713
    int String::Compare(const Char *a, const Char *b)
    {
#line 714
        while (*a || *b)
            {
#line 715
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
#line 725
        while ((*a || *b) && len > 0)
            {
#line 726
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
#line 737
            if (!(dst && src))
            {
#line 737
                Lang::SysBreak("Assertion failed: dst && src");
            }
        }
#line 738
        ;
#line 738
        if (!dst || !src)
#line 738
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 488
    String String::DblStr(double d)
    {
#line 489
        Char output[50];
        Native::DblStr(d, output, 50);
        return String(output);
    };
    
#line 328
    int String::Find(const String& str, int pos) const
    {
#line 329
        if (GetCount() == 0)
#line 329
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 332
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 332
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 333
        ;
#line 333
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 337
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 355
    int String::FindFirstNotOf(const Char *str) const
    {
#line 356
        if (GetCount() <= 0 || !str)
#line 356
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 361
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 365
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 368
                        if (chr == cmp_chr)
                        {
#line 369
                            match = true;
                            break;
                        
                        }
                    }
#line 373
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 496
    Lang::uint32 String::GetHashValue() const
    {
#line 497
        Hash::Combine ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 433
    bool String::Insert(int begin, const Char *str, int n)
    {
#line 434
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 436
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 436
                Lang::SysBreak("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 437
        ;
#line 437
        begin = Algorithm::Maximum(0, Algorithm::Minimum(begin, GetCount()));
        String part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 443
        if (l)
            *this = Left(l) + part;
        else 
#line 445
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 637
    const String::Char *String::IntChar(Char *p, int bufsize, int x)
    {
#line 638
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 641
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 646
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 650
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const String::Char *String::IntChar64(Char *p, int bufsize, Lang::int64 x)
    {
#line 656
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 659
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 664
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 668
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const String::Char *String::IntCharU64(Char *p, int bufsize, Lang::uint64 x)
    {
#line 674
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 677
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 682
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 686
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
#line 476
    String String::IntStr(int i)
    {
#line 477
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return String(value);
    };
    
    String String::IntStr64(Lang::int64 i)
    {
#line 483
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return String(value);
    };
    
#line 692
    int String::Length(const Char *c, int max_len)
    {
        {
#line 693
            if (!(c))
            {
#line 693
                Lang::SysBreak("Assertion failed: c");
            }
        }
#line 694
        ;
#line 694
        if (!c)
#line 694
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 697
            while (*c)
                {
#line 698
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 704
            while (max_len > 0 && *c)
                {
#line 705
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 403
    String String::Mid(int i) const
    {
#line 403
        if (i >= GetCount())
#line 403
            return Empty();
#line 403
        if (i < 0)
#line 403
            i = 0;
#line 403
        return Mid(i, GetCount() - i);
    };
    
#line 404
    String String::Mid(int i, int size) const
    {
#line 405
        size = Algorithm::Minimum(size, count - i);
        if (size <= 0)
#line 406
            return String();
        {
#line 407
            if (!(i >= 0 && i + size <= count))
            {
#line 407
                Lang::SysBreak("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 408
        ;
#line 408
        return String(Begin() + i, size);
    };
    
#line 413
    void String::Remove(int begin, int count)
    {
        {
#line 414
            if (!(begin >= 0 && count >= 0))
            {
#line 414
                Lang::SysBreak("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 415
        ;
#line 415
        begin = Algorithm::Maximum(0, begin);
        count = Algorithm::Maximum(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 419
            if (!(begin <= c && end <= c))
            {
#line 419
                Lang::SysBreak("Assertion failed: begin <= c && end <= c");
            }
        }
#line 420
        ;
#line 420
        end = Algorithm::Minimum(c, end);
        begin = Algorithm::Minimum(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 426
        if (l)
            *this = Left(l);
        else 
#line 428
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 287
    void String::Replace(const String& s, const String& value)
    {
#line 288
        if (s == value)
#line 288
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 291
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void String::Replace(int i, int len, const String& value)
    {
#line 297
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 303
            Lang::Memory::Copy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 307
            Lang::Memory::Copy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 313
            Lang::Memory::Copy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 318
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        ref[0] -> Inc();
        {
#line 323
            if (!(cursor == new_len + 1))
            {
#line 323
                Lang::SysBreak("Assertion failed: cursor == new_len+1");
            }
        }
#line 324
        ;
    };
    
#line 343
    int String::ReverseFind(const String& str, int pos) const
    {
#line 344
        if (GetCount() == 0)
#line 344
            return - 1;
        {
#line 345
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 345
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 346
        ;
#line 346
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 350
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 379
    int String::ReverseFindFirstNotOf(const Char *str) const
    {
#line 380
        if (GetCount() <= 0 || !str)
#line 380
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 385
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 389
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 392
                        if (chr == cmp_chr)
                        {
#line 393
                            match = true;
                            break;
                        
                        }
                    }
#line 397
                i -- ;
                if (!match)
                    return i;
            }
        return - 1;
    };
    
#line 115
    void String::Serialize(Abstract::StreamBase& s)
    {
#line 116
        if (s.IsStoring())
        {
#line 117
            s.Put(&count, sizeof (count));
            if (count)
            {
#line 119
                if (!is_ref)
                    s.Put(buf, count);
                else
                    s.Put(ref[0] -> Get(), count);
            }
        }
        else 
#line 125
        if (s.IsLoading())
        {
#line 126
            Clear();
            s.Get(&count, sizeof (count));
            {
#line 128
                if (!(count >= 0))
                {
#line 128
                    Lang::SysBreak("Assertion failed: count >= 0");
                }
            }
#line 129
            ;
#line 129
            if (count < 0)
#line 129
                count = 0;
            if (count > 0)
            {
#line 131
                if (count < 8)
                {
#line 132
                    s.Get(buf, sizeof (Char) * count);
                    buf[count] = 0;
                }
                else
                {
#line 136
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
#line 150
        Clear();
        if (!c)
#line 151
            return *this;
        if (find_end)
#line 152
            count = Algorithm::Minimum(Lang::StringLength(c, len), len);
        else
#line 153
            count = len;
        if (count < 8)
        {
#line 155
            Lang::Memory::Copy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
        }
        else
        {
#line 159
            Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (count + 1));
            Lang::Memory::Copy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
            ref[0] = new RefData(buf, count + 1);
            ref[0] -> Inc();
            is_ref = true;
        }
        return *this;
    };
    
#line 95
    void String::Zero()
    {
#line 130 "../../src/Com/Meta.fog"
        Lang::Memory::Set(this, 0, sizeof (String));
    };
    
#line 38 "../../src/Com/Text.fog"
    String::RefData::RefData()
    :
        data(0),
        reserved(0)
    {};
    
#line 39
    String::RefData::RefData(Char *str, int reserved)
    :
        data(str),
        reserved(reserved)
    {};
    
#line 40
    String::RefData::~RefData()
    {
#line 40
        Clear();
    };
    
#line 77
    String::RefData::operator ConstChar * () const
    {
#line 77
        return data;
    };
    
#line 76
    String::Char *String::RefData::Begin()
    {
#line 76
        return data;
    };
    
#line 42
    void String::RefData::Clear()
    {
#line 42
        if (data)
        {
#line 42
            Lang::Memory::Free(data);
#line 42
            data = 0;
#line 42
            refs = 0;
#line 42
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
    
#line 75 "../../src/Com/Text.fog"
    String::ConstChar *String::RefData::Get() const
    {
#line 75
        return data;
    };
    
#line 123 "../../src/Com/Meta.fog"
    int String::RefData::GetRefs() const
    {
#line 123
        return refs;
    };
    
#line 79 "../../src/Com/Text.fog"
    int String::RefData::GetReserved() const
    {
#line 79
        return reserved;
    };
    
#line 124 "../../src/Com/Meta.fog"
    void String::RefData::Inc()
    {
#line 124
        refs ++ ;
    };
    
#line 44 "../../src/Com/Text.fog"
    void String::RefData::IncreaseReserved()
    {
#line 45
        Lang::uint64 new_reserved = 1;
        while (new_reserved <= reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void String::RefData::IncreaseReserved(int min_reserved)
    {
#line 54
        Lang::uint64 new_reserved = 1;
        while (new_reserved <= min_reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void String::RefData::Reserve(int new_reserved)
    {
#line 63
        if (new_reserved <= reserved)
            return;
        Char * new_data = (Char * ) Lang::Memory::Alloc(new_reserved * sizeof (Char));
        if (data)
        {
#line 67
            if (reserved > 0)
                Lang::Memory::Copy(new_data, data, sizeof (Char) * reserved);
            Lang::Memory::Free(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
#line 100
    WString::WString()
    :
        is_ref(false),
        count(0)
    {
#line 100
        Zero();
    };
    
    WString::WString(const WString& s)
    :
        is_ref(false),
        count(0)
    {
#line 103
        Zero();
#line 103
        *this = s;
    };
    
#line 101
    WString::WString(const Char *c)
    :
        is_ref(false),
        count(0)
    {
#line 101
        Zero();
#line 101
        *this = c;
    };
    
#line 102
    WString::WString(const Char *c, int len)
    :
        is_ref(false),
        count(0)
    {
#line 102
        Zero();
#line 102
        Set(c, len);
    };
    
#line 104
    WString::~WString()
    {
#line 104
        Clear();
    };
    
#line 467
    WString WString::operator+ (const WString& s)
    {
#line 467
        WString out(*this);
#line 467
        out.Cat(s);
#line 467
        return out;
    };
    
#line 187
    WString WString::operator+ (const WString& l) const
    {
#line 188
        WString s(*this);
        s.Cat(l);
        return s;
    };
    
#line 169
    WString& WString::operator= (const WString& str)
    {
#line 170
        if (!str.is_ref)
        {
#line 171
            Clear();
            Lang::Memory::Copy(buf, str.buf, sizeof (buf));
            is_ref = false;
        }
        else
        {
#line 176
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
    
#line 454
    bool WString::operator== (const WString& s) const
    {
#line 455
        if (s.GetCount() != GetCount())
#line 455
            return false;
        if (s.IsEmpty())
#line 456
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 462
    WString::Char WString::At(int i) const
    {
        {
#line 462
            if (!(i >= 0 && i < count))
            {
#line 462
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 462
        ;
#line 462
        return *(Begin() + i);
    };
    
#line 451
    const WString::Char *WString::Begin() const
    {
#line 451
        if (is_ref)
        {
            {
#line 451
                if (!(ref[0] && ref[0] -> Get()))
                {
#line 451
                    Lang::SysBreak("Assertion failed: REF && REF->Get()");
                }
            }
#line 451
            ;
#line 451
            return ref[0] -> Get();
        }
        else
#line 451
            return buf;
    };
    
#line 199
    WString& WString::Cat(Char i)
    {
#line 200
        if (!is_ref)
        {
#line 201
            is_ref = count + 1 >= 8;
            if (!is_ref)
            {
#line 203
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
            }
            else
            {
#line 208
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
#line 219
            if (ref[0] -> GetRefs() == 1)
            {
#line 220
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
#line 229
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
    
#line 193
    WString& WString::Cat(Char c, int count)
    {
        for (int i = 0; i < count; i ++ )
#line 195
            Cat(c);
        return *this;
    };
    
#line 244
    WString& WString::Cat(const WString& str)
    {
#line 245
        if (!is_ref)
        {
#line 246
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 248
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 252
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
#line 263
            if (ref[0] -> GetRefs() == 1)
            {
#line 264
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
#line 273
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
    
#line 518
    int WString::CharBinInt(const Char *s)
    {
#line 519
        if (!s)
#line 519
            return 0;
        while (IsSpace(*s))
#line 520
            s ++ ;
        int n = 0;
#line 521
        int neg = 0;
        switch (*s)
        {
#line 523
            case '-':
#line 523
                neg = 1;
            case '+':
#line 524
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'b' || s[1] == 'B'))
            s += 2;
        while (IsBinDigit(*s))
            n = 16 * n - GetBinDigit(*s ++ );
        if (neg)
#line 530
            return n;
        else
#line 530
            return - n;
    };
    
#line 587
    double WString::CharDbl(const Char *s)
    {
#line 588
        double a = 0.0;
        int e = 0;
        int c;
#line 592
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 593
                a = a * 10.0 + (c - '0');
            }
#line 596
        if (c == '.')
        {
#line 597
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 598
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 603
        if (c == 'e' || c == 'E')
        {
#line 604
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 608
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 612
                c = *s ++ ;
                sign = - 1;
            }
#line 616
            while (IsDigit(c))
                {
#line 617
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 621
            e += i * sign;
        }
#line 624
        while (e > 0)
            {
#line 625
                a *= 10.0;
                e -- ;
            }
#line 629
        while (e < 0)
            {
#line 630
                a *= 0.1;
                e ++ ;
            }
#line 634
        return a;
    };
    
#line 533
    int WString::CharHexInt(const Char *s)
    {
#line 534
        if (!s)
#line 534
            return 0;
        while (IsSpace(*s))
#line 535
            s ++ ;
        int n = 0;
#line 536
        int neg = 0;
        switch (*s)
        {
#line 538
            case '-':
#line 538
                neg = 1;
            case '+':
#line 539
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 545
            return n;
        else
#line 545
            return - n;
    };
    
    int WString::CharInt(const Char *s)
    {
        int n = 0;
#line 550
        int neg = 0;
        while (IsSpace(*s))
#line 551
            s ++ ;
        switch (*s)
        {
#line 553
            case '-':
#line 553
                neg = 1;
            case '+':
#line 554
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 558
            return n;
        else
#line 558
            return - n;
    };
    
    Lang::int64 WString::CharInt64(const Char *s)
    {
        Lang::int64 n = 0;
#line 563
        Lang::int64 neg = 0;
        while (IsSpace(*s))
#line 564
            s ++ ;
        switch (*s)
        {
#line 566
            case '-':
#line 566
                neg = 1;
            case '+':
#line 567
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 571
            return n;
        else
#line 571
            return - n;
    };
    
    Lang::uint64 WString::CharIntU64(const Char *s)
    {
        Lang::uint64 n = 0;
        while (IsSpace(*s))
#line 577
            s ++ ;
        switch (*s)
        {
#line 579
            case '-':
#line 579
                return 0;
            case '+':
#line 580
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 504
    int WString::CharOctInt(const Char *s)
    {
#line 505
        if (!s)
#line 505
            return 0;
        while (IsSpace(*s))
#line 506
            s ++ ;
        int n = 0;
#line 507
        int neg = 0;
        switch (*s)
        {
#line 509
            case '-':
#line 509
                neg = 1;
            case '+':
#line 510
                s ++ ;
        }
        while (*s == '0')
#line 512
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 515
            return n;
        else
#line 515
            return - n;
    };
    
#line 109
    void WString::Clear()
    {
#line 110
        if (is_ref)
        {
#line 110
            ref[0] -> Dec();
#line 110
            ref[0] = 0;
#line 110
            is_ref = false;
        }
        else
        {
#line 111
            ref[0] = 0;
        }
#line 112
        count = 0;
    };
    
#line 713
    int WString::Compare(const Char *a, const Char *b)
    {
#line 714
        while (*a || *b)
            {
#line 715
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
#line 725
        while ((*a || *b) && len > 0)
            {
#line 726
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
#line 737
            if (!(dst && src))
            {
#line 737
                Lang::SysBreak("Assertion failed: dst && src");
            }
        }
#line 738
        ;
#line 738
        if (!dst || !src)
#line 738
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 488
    WString WString::DblStr(double d)
    {
#line 489
        Char output[50];
        Native::DblStr(d, output, 50);
        return WString(output);
    };
    
#line 328
    int WString::Find(const WString& str, int pos) const
    {
#line 329
        if (GetCount() == 0)
#line 329
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 332
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 332
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 333
        ;
#line 333
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 337
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 355
    int WString::FindFirstNotOf(const Char *str) const
    {
#line 356
        if (GetCount() <= 0 || !str)
#line 356
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 361
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 365
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 368
                        if (chr == cmp_chr)
                        {
#line 369
                            match = true;
                            break;
                        
                        }
                    }
#line 373
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 496
    Lang::uint32 WString::GetHashValue() const
    {
#line 497
        Hash::Combine ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 433
    bool WString::Insert(int begin, const Char *str, int n)
    {
#line 434
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 436
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 436
                Lang::SysBreak("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 437
        ;
#line 437
        begin = Algorithm::Maximum(0, Algorithm::Minimum(begin, GetCount()));
        WString part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 443
        if (l)
            *this = Left(l) + part;
        else 
#line 445
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 637
    const WString::Char *WString::IntChar(Char *p, int bufsize, int x)
    {
#line 638
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 641
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 646
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 650
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const WString::Char *WString::IntChar64(Char *p, int bufsize, Lang::int64 x)
    {
#line 656
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 659
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 664
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 668
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const WString::Char *WString::IntCharU64(Char *p, int bufsize, Lang::uint64 x)
    {
#line 674
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 677
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 682
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 686
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
#line 476
    WString WString::IntStr(int i)
    {
#line 477
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return WString(value);
    };
    
    WString WString::IntStr64(Lang::int64 i)
    {
#line 483
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return WString(value);
    };
    
#line 692
    int WString::Length(const Char *c, int max_len)
    {
        {
#line 693
            if (!(c))
            {
#line 693
                Lang::SysBreak("Assertion failed: c");
            }
        }
#line 694
        ;
#line 694
        if (!c)
#line 694
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 697
            while (*c)
                {
#line 698
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 704
            while (max_len > 0 && *c)
                {
#line 705
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 403
    WString WString::Mid(int i) const
    {
#line 403
        if (i >= GetCount())
#line 403
            return Empty();
#line 403
        if (i < 0)
#line 403
            i = 0;
#line 403
        return Mid(i, GetCount() - i);
    };
    
#line 404
    WString WString::Mid(int i, int size) const
    {
#line 405
        size = Algorithm::Minimum(size, count - i);
        if (size <= 0)
#line 406
            return WString();
        {
#line 407
            if (!(i >= 0 && i + size <= count))
            {
#line 407
                Lang::SysBreak("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 408
        ;
#line 408
        return WString(Begin() + i, size);
    };
    
#line 413
    void WString::Remove(int begin, int count)
    {
        {
#line 414
            if (!(begin >= 0 && count >= 0))
            {
#line 414
                Lang::SysBreak("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 415
        ;
#line 415
        begin = Algorithm::Maximum(0, begin);
        count = Algorithm::Maximum(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 419
            if (!(begin <= c && end <= c))
            {
#line 419
                Lang::SysBreak("Assertion failed: begin <= c && end <= c");
            }
        }
#line 420
        ;
#line 420
        end = Algorithm::Minimum(c, end);
        begin = Algorithm::Minimum(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 426
        if (l)
            *this = Left(l);
        else 
#line 428
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 287
    void WString::Replace(const WString& s, const WString& value)
    {
#line 288
        if (s == value)
#line 288
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 291
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void WString::Replace(int i, int len, const WString& value)
    {
#line 297
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 303
            Lang::Memory::Copy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 307
            Lang::Memory::Copy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 313
            Lang::Memory::Copy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 318
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        ref[0] -> Inc();
        {
#line 323
            if (!(cursor == new_len + 1))
            {
#line 323
                Lang::SysBreak("Assertion failed: cursor == new_len+1");
            }
        }
#line 324
        ;
    };
    
#line 343
    int WString::ReverseFind(const WString& str, int pos) const
    {
#line 344
        if (GetCount() == 0)
#line 344
            return - 1;
        {
#line 345
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 345
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 346
        ;
#line 346
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 350
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 379
    int WString::ReverseFindFirstNotOf(const Char *str) const
    {
#line 380
        if (GetCount() <= 0 || !str)
#line 380
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 385
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 389
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 392
                        if (chr == cmp_chr)
                        {
#line 393
                            match = true;
                            break;
                        
                        }
                    }
#line 397
                i -- ;
                if (!match)
                    return i;
            }
        return - 1;
    };
    
#line 115
    void WString::Serialize(Abstract::StreamBase& s)
    {
#line 116
        if (s.IsStoring())
        {
#line 117
            s.Put(&count, sizeof (count));
            if (count)
            {
#line 119
                if (!is_ref)
                    s.Put(buf, count);
                else
                    s.Put(ref[0] -> Get(), count);
            }
        }
        else 
#line 125
        if (s.IsLoading())
        {
#line 126
            Clear();
            s.Get(&count, sizeof (count));
            {
#line 128
                if (!(count >= 0))
                {
#line 128
                    Lang::SysBreak("Assertion failed: count >= 0");
                }
            }
#line 129
            ;
#line 129
            if (count < 0)
#line 129
                count = 0;
            if (count > 0)
            {
#line 131
                if (count < 8)
                {
#line 132
                    s.Get(buf, sizeof (Char) * count);
                    buf[count] = 0;
                }
                else
                {
#line 136
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
#line 150
        Clear();
        if (!c)
#line 151
            return *this;
        if (find_end)
#line 152
            count = Algorithm::Minimum(Lang::StringLength(c, len), len);
        else
#line 153
            count = len;
        if (count < 8)
        {
#line 155
            Lang::Memory::Copy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
        }
        else
        {
#line 159
            Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (count + 1));
            Lang::Memory::Copy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
            ref[0] = new RefData(buf, count + 1);
            ref[0] -> Inc();
            is_ref = true;
        }
        return *this;
    };
    
#line 95
    void WString::Zero()
    {
#line 130 "../../src/Com/Meta.fog"
        Lang::Memory::Set(this, 0, sizeof (WString));
    };
    
#line 38 "../../src/Com/Text.fog"
    WString::RefData::RefData()
    :
        data(0),
        reserved(0)
    {};
    
#line 39
    WString::RefData::RefData(Char *str, int reserved)
    :
        data(str),
        reserved(reserved)
    {};
    
#line 40
    WString::RefData::~RefData()
    {
#line 40
        Clear();
    };
    
#line 77
    WString::RefData::operator ConstChar * () const
    {
#line 77
        return data;
    };
    
#line 76
    WString::Char *WString::RefData::Begin()
    {
#line 76
        return data;
    };
    
#line 42
    void WString::RefData::Clear()
    {
#line 42
        if (data)
        {
#line 42
            Lang::Memory::Free(data);
#line 42
            data = 0;
#line 42
            refs = 0;
#line 42
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
    
#line 75 "../../src/Com/Text.fog"
    WString::ConstChar *WString::RefData::Get() const
    {
#line 75
        return data;
    };
    
#line 123 "../../src/Com/Meta.fog"
    int WString::RefData::GetRefs() const
    {
#line 123
        return refs;
    };
    
#line 79 "../../src/Com/Text.fog"
    int WString::RefData::GetReserved() const
    {
#line 79
        return reserved;
    };
    
#line 124 "../../src/Com/Meta.fog"
    void WString::RefData::Inc()
    {
#line 124
        refs ++ ;
    };
    
#line 44 "../../src/Com/Text.fog"
    void WString::RefData::IncreaseReserved()
    {
#line 45
        Lang::uint64 new_reserved = 1;
        while (new_reserved <= reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void WString::RefData::IncreaseReserved(int min_reserved)
    {
#line 54
        Lang::uint64 new_reserved = 1;
        while (new_reserved <= min_reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2147483647)
            new_reserved = 2147483647;
        Reserve((int) new_reserved);
    };
    
    void WString::RefData::Reserve(int new_reserved)
    {
#line 63
        if (new_reserved <= reserved)
            return;
        Char * new_data = (Char * ) Lang::Memory::Alloc(new_reserved * sizeof (Char));
        if (data)
        {
#line 67
            if (reserved > 0)
                Lang::Memory::Copy(new_data, data, sizeof (Char) * reserved);
            Lang::Memory::Free(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
};

#endif
