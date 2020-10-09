#ifndef TEXT_CXX
#define TEXT_CXX

#include <new>

#ifndef TEXT_HXX
#include <Text.hxx>
#endif

namespace Text
{
#line 968 "../../src/Com/Text.fog"
    String CharToUTF8(Lang::uint16 chr)
    {
#line 969
        WString ws;
        ws.Cat((int) chr);
        return ToString(ws);
    };
    
#line 958
    String EscapeCharacter(String s)
    {
#line 959
        s.Replace("\n", "\\n");
        s.Replace("\t", "\\t");
        s.Replace("\r", "\\r");
        s.Replace("\"", "\\\"");
        s.Replace("'", "\\'");
#line 965
        return s;
    };
    
#line 949
    String EscapeString(String s)
    {
#line 950
        s.Replace("\n", "\\n");
        s.Replace("\t", "\\t");
        s.Replace("\r", "\\r");
        s.Replace("\"", "\\\"");
#line 955
        return s;
    };
    
#line 795
    String ToLower(const String& s)
    {
#line 796
        int count = s.GetCount();
        if (!count)
#line 797
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
    
#line 775
    int ToLowerChar(int chr)
    {
#line 776
        if (chr >= 'A' && chr <= 'Z')
            return 'a' + (chr - 'A');
        return chr;
    };
    
    String ToUpper(const String& s)
    {
#line 782
        int count = s.GetCount();
        if (!count)
#line 783
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
    
#line 769
    int ToUpperChar(int chr)
    {
#line 770
        if (chr >= 'a' && chr <= 'z')
            return 'A' + (chr - 'a');
        return chr;
    };
    
#line 827
    String TrimBoth(String s)
    {
#line 828
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
    
#line 901
    void UnescapeNumbers(String& s)
    {
#line 902
        String tmp;
        int prev_offset = 0;
        const char * begin = s.Begin();
        const char * it = begin;
        const char * end = s.End();
        for (; it != end; ++ it)
            {
#line 908
                if (*it == '\\')
                {
#line 909
                    int offset = it - begin;
                    if (++ it == end)
                        break;
                    
#line 912
                    char c = *it;
                    if (c == '0')
                    {
#line 914
                        if (++ it == end)
                            break;
                        
#line 916
                        int num = 0;
                        int mul = 1;
                        for (int i = 0; i < 3 && it != end; i ++ , it ++ )
                            {
#line 919
                                char c = *it;
                                if (c >= '0' && c <= '9')
                                {
#line 921
                                    int n = c - '0';
                                    int new_num = num + n * mul;
                                    if (new_num >= 0x100)
                                        break;
                                    
#line 925
                                    num = new_num;
                                    mul *= 10;
                                }
                                else
#line 928
                                    break;
                            
                            }
#line 930
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
#line 941
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
    
#line 469
    String String::operator+ (const String& s)
    {
#line 469
        String out(*this);
#line 469
        out.Cat(s);
#line 469
        return out;
    };
    
#line 189
    String String::operator+ (const String& l) const
    {
#line 190
        String s(*this);
        s.Cat(l);
        return s;
    };
    
#line 171
    String& String::operator= (const String& str)
    {
#line 172
        if (!str.is_ref)
        {
#line 173
            Clear();
            Lang::Memory::Copy(buf, str.buf, sizeof (buf));
            is_ref = false;
        }
        else
        {
#line 178
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
    
#line 456
    bool String::operator== (const String& s) const
    {
#line 457
        if (s.GetCount() != GetCount())
#line 457
            return false;
        if (s.IsEmpty())
#line 458
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 464
    String::Char String::At(int i) const
    {
        {
#line 464
            if (!(i >= 0 && i < count))
            {
#line 464
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 464
        ;
#line 464
        return *(Begin() + i);
    };
    
#line 453
    const String::Char *String::Begin() const
    {
#line 453
        if (is_ref)
        {
            {
#line 453
                if (!(ref[0] && ref[0] -> Get()))
                {
#line 453
                    Lang::SysBreak("Assertion failed: REF && REF->Get()");
                }
            }
#line 453
            ;
#line 453
            return ref[0] -> Get();
        }
        else
#line 453
            return buf;
    };
    
#line 201
    String& String::Cat(Char i)
    {
#line 202
        if (!is_ref)
        {
#line 203
            is_ref = count + 1 >= 8;
            if (!is_ref)
            {
#line 205
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
            }
            else
            {
#line 210
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
#line 221
            if (ref[0] -> GetRefs() == 1)
            {
#line 222
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
#line 231
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
    
#line 195
    String& String::Cat(Char c, int count)
    {
        for (int i = 0; i < count; i ++ )
#line 197
            Cat(c);
        return *this;
    };
    
#line 246
    String& String::Cat(const String& str)
    {
#line 247
        if (!is_ref)
        {
#line 248
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 250
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 254
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
#line 265
            if (ref[0] -> GetRefs() == 1)
            {
#line 266
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
#line 275
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
    
#line 520
    int String::CharBinInt(const Char *s)
    {
#line 521
        if (!s)
#line 521
            return 0;
        while (IsSpace(*s))
#line 522
            s ++ ;
        int n = 0;
#line 523
        int neg = 0;
        switch (*s)
        {
#line 525
            case '-':
#line 525
                neg = 1;
            case '+':
#line 526
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'b' || s[1] == 'B'))
            s += 2;
        while (IsBinDigit(*s))
            n = 16 * n - GetBinDigit(*s ++ );
        if (neg)
#line 532
            return n;
        else
#line 532
            return - n;
    };
    
#line 589
    double String::CharDbl(const Char *s)
    {
#line 590
        double a = 0.0;
        int e = 0;
        int c;
#line 594
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 595
                a = a * 10.0 + (c - '0');
            }
#line 598
        if (c == '.')
        {
#line 599
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 600
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 605
        if (c == 'e' || c == 'E')
        {
#line 606
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 610
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 614
                c = *s ++ ;
                sign = - 1;
            }
#line 618
            while (IsDigit(c))
                {
#line 619
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 623
            e += i * sign;
        }
#line 626
        while (e > 0)
            {
#line 627
                a *= 10.0;
                e -- ;
            }
#line 631
        while (e < 0)
            {
#line 632
                a *= 0.1;
                e ++ ;
            }
#line 636
        return a;
    };
    
#line 535
    int String::CharHexInt(const Char *s)
    {
#line 536
        if (!s)
#line 536
            return 0;
        while (IsSpace(*s))
#line 537
            s ++ ;
        int n = 0;
#line 538
        int neg = 0;
        switch (*s)
        {
#line 540
            case '-':
#line 540
                neg = 1;
            case '+':
#line 541
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 547
            return n;
        else
#line 547
            return - n;
    };
    
    int String::CharInt(const Char *s)
    {
        int n = 0;
#line 552
        int neg = 0;
        while (IsSpace(*s))
#line 553
            s ++ ;
        switch (*s)
        {
#line 555
            case '-':
#line 555
                neg = 1;
            case '+':
#line 556
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 560
            return n;
        else
#line 560
            return - n;
    };
    
    Lang::int64 String::CharInt64(const Char *s)
    {
        Lang::int64 n = 0;
#line 565
        Lang::int64 neg = 0;
        while (IsSpace(*s))
#line 566
            s ++ ;
        switch (*s)
        {
#line 568
            case '-':
#line 568
                neg = 1;
            case '+':
#line 569
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 573
            return n;
        else
#line 573
            return - n;
    };
    
    Lang::uint64 String::CharIntU64(const Char *s)
    {
        Lang::uint64 n = 0;
        while (IsSpace(*s))
#line 579
            s ++ ;
        switch (*s)
        {
#line 581
            case '-':
#line 581
                return 0;
            case '+':
#line 582
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 506
    int String::CharOctInt(const Char *s)
    {
#line 507
        if (!s)
#line 507
            return 0;
        while (IsSpace(*s))
#line 508
            s ++ ;
        int n = 0;
#line 509
        int neg = 0;
        switch (*s)
        {
#line 511
            case '-':
#line 511
                neg = 1;
            case '+':
#line 512
                s ++ ;
        }
        while (*s == '0')
#line 514
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 517
            return n;
        else
#line 517
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
    
#line 715
    int String::Compare(const Char *a, const Char *b)
    {
#line 716
        while (*a || *b)
            {
#line 717
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
#line 727
        while ((*a || *b) && len > 0)
            {
#line 728
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
#line 739
            if (!(dst && src))
            {
#line 739
                Lang::SysBreak("Assertion failed: dst && src");
            }
        }
#line 740
        ;
#line 740
        if (!dst || !src)
#line 740
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 490
    String String::DblStr(double d)
    {
#line 491
        Char output[50];
        Native::DblStr(d, output, 50);
        return String(output);
    };
    
#line 330
    int String::Find(const String& str, int pos) const
    {
#line 331
        if (GetCount() == 0)
#line 331
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 334
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 334
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 335
        ;
#line 335
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 339
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 357
    int String::FindFirstNotOf(const Char *str) const
    {
#line 358
        if (GetCount() <= 0 || !str)
#line 358
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 363
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 367
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 370
                        if (chr == cmp_chr)
                        {
#line 371
                            match = true;
                            break;
                        
                        }
                    }
#line 375
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 498
    Lang::uint32 String::GetHashValue() const
    {
#line 499
        Hash::Combine ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 435
    bool String::Insert(int begin, const Char *str, int n)
    {
#line 436
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 438
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 438
                Lang::SysBreak("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 439
        ;
#line 439
        begin = Algorithm::Maximum(0, Algorithm::Minimum(begin, GetCount()));
        String part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 445
        if (l)
            *this = Left(l) + part;
        else 
#line 447
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 639
    const String::Char *String::IntChar(Char *p, int bufsize, int x)
    {
#line 640
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 643
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 648
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 652
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const String::Char *String::IntChar64(Char *p, int bufsize, Lang::int64 x)
    {
#line 658
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 661
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 666
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 670
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const String::Char *String::IntCharU64(Char *p, int bufsize, Lang::uint64 x)
    {
#line 676
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 679
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 684
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 688
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
#line 478
    String String::IntStr(int i)
    {
#line 479
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return String(value);
    };
    
    String String::IntStr64(Lang::int64 i)
    {
#line 485
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return String(value);
    };
    
#line 694
    int String::Length(const Char *c, int max_len)
    {
        {
#line 695
            if (!(c))
            {
#line 695
                Lang::SysBreak("Assertion failed: c");
            }
        }
#line 696
        ;
#line 696
        if (!c)
#line 696
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 699
            while (*c)
                {
#line 700
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 706
            while (max_len > 0 && *c)
                {
#line 707
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 405
    String String::Mid(int i) const
    {
#line 405
        if (i >= GetCount())
#line 405
            return Empty();
#line 405
        if (i < 0)
#line 405
            i = 0;
#line 405
        return Mid(i, GetCount() - i);
    };
    
#line 406
    String String::Mid(int i, int size) const
    {
#line 407
        size = Algorithm::Minimum(size, count - i);
        if (size <= 0)
#line 408
            return String();
        {
#line 409
            if (!(i >= 0 && i + size <= count))
            {
#line 409
                Lang::SysBreak("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 410
        ;
#line 410
        return String(Begin() + i, size);
    };
    
#line 415
    void String::Remove(int begin, int count)
    {
        {
#line 416
            if (!(begin >= 0 && count >= 0))
            {
#line 416
                Lang::SysBreak("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 417
        ;
#line 417
        begin = Algorithm::Maximum(0, begin);
        count = Algorithm::Maximum(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 421
            if (!(begin <= c && end <= c))
            {
#line 421
                Lang::SysBreak("Assertion failed: begin <= c && end <= c");
            }
        }
#line 422
        ;
#line 422
        end = Algorithm::Minimum(c, end);
        begin = Algorithm::Minimum(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 428
        if (l)
            *this = Left(l);
        else 
#line 430
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 289
    void String::Replace(const String& s, const String& value)
    {
#line 290
        if (s == value)
#line 290
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 293
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void String::Replace(int i, int len, const String& value)
    {
#line 299
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 305
            Lang::Memory::Copy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 309
            Lang::Memory::Copy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 315
            Lang::Memory::Copy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 320
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        ref[0] -> Inc();
        {
#line 325
            if (!(cursor == new_len + 1))
            {
#line 325
                Lang::SysBreak("Assertion failed: cursor == new_len+1");
            }
        }
#line 326
        ;
    };
    
#line 345
    int String::ReverseFind(const String& str, int pos) const
    {
#line 346
        if (GetCount() == 0)
#line 346
            return - 1;
        {
#line 347
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 347
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 348
        ;
#line 348
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 352
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 381
    int String::ReverseFindFirstNotOf(const Char *str) const
    {
#line 382
        if (GetCount() <= 0 || !str)
#line 382
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 387
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 391
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 394
                        if (chr == cmp_chr)
                        {
#line 395
                            match = true;
                            break;
                        
                        }
                    }
#line 399
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
    
#line 151
    String& String::Set(const Char *c, int len, bool find_end)
    {
#line 152
        Clear();
        if (!c)
#line 153
            return *this;
        if (find_end)
#line 154
            count = Algorithm::Minimum(Lang::StringLength(c, len), len);
        else
#line 155
            count = len;
        if (count < 8)
        {
#line 157
            Lang::Memory::Copy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
        }
        else
        {
#line 161
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
    
#line 469
    WString WString::operator+ (const WString& s)
    {
#line 469
        WString out(*this);
#line 469
        out.Cat(s);
#line 469
        return out;
    };
    
#line 189
    WString WString::operator+ (const WString& l) const
    {
#line 190
        WString s(*this);
        s.Cat(l);
        return s;
    };
    
#line 171
    WString& WString::operator= (const WString& str)
    {
#line 172
        if (!str.is_ref)
        {
#line 173
            Clear();
            Lang::Memory::Copy(buf, str.buf, sizeof (buf));
            is_ref = false;
        }
        else
        {
#line 178
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
    
#line 456
    bool WString::operator== (const WString& s) const
    {
#line 457
        if (s.GetCount() != GetCount())
#line 457
            return false;
        if (s.IsEmpty())
#line 458
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 464
    WString::Char WString::At(int i) const
    {
        {
#line 464
            if (!(i >= 0 && i < count))
            {
#line 464
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 464
        ;
#line 464
        return *(Begin() + i);
    };
    
#line 453
    const WString::Char *WString::Begin() const
    {
#line 453
        if (is_ref)
        {
            {
#line 453
                if (!(ref[0] && ref[0] -> Get()))
                {
#line 453
                    Lang::SysBreak("Assertion failed: REF && REF->Get()");
                }
            }
#line 453
            ;
#line 453
            return ref[0] -> Get();
        }
        else
#line 453
            return buf;
    };
    
#line 201
    WString& WString::Cat(Char i)
    {
#line 202
        if (!is_ref)
        {
#line 203
            is_ref = count + 1 >= 8;
            if (!is_ref)
            {
#line 205
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
            }
            else
            {
#line 210
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
#line 221
            if (ref[0] -> GetRefs() == 1)
            {
#line 222
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
#line 231
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
    
#line 195
    WString& WString::Cat(Char c, int count)
    {
        for (int i = 0; i < count; i ++ )
#line 197
            Cat(c);
        return *this;
    };
    
#line 246
    WString& WString::Cat(const WString& str)
    {
#line 247
        if (!is_ref)
        {
#line 248
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 250
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 254
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
#line 265
            if (ref[0] -> GetRefs() == 1)
            {
#line 266
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
#line 275
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
    
#line 520
    int WString::CharBinInt(const Char *s)
    {
#line 521
        if (!s)
#line 521
            return 0;
        while (IsSpace(*s))
#line 522
            s ++ ;
        int n = 0;
#line 523
        int neg = 0;
        switch (*s)
        {
#line 525
            case '-':
#line 525
                neg = 1;
            case '+':
#line 526
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'b' || s[1] == 'B'))
            s += 2;
        while (IsBinDigit(*s))
            n = 16 * n - GetBinDigit(*s ++ );
        if (neg)
#line 532
            return n;
        else
#line 532
            return - n;
    };
    
#line 589
    double WString::CharDbl(const Char *s)
    {
#line 590
        double a = 0.0;
        int e = 0;
        int c;
#line 594
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 595
                a = a * 10.0 + (c - '0');
            }
#line 598
        if (c == '.')
        {
#line 599
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 600
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 605
        if (c == 'e' || c == 'E')
        {
#line 606
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 610
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 614
                c = *s ++ ;
                sign = - 1;
            }
#line 618
            while (IsDigit(c))
                {
#line 619
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 623
            e += i * sign;
        }
#line 626
        while (e > 0)
            {
#line 627
                a *= 10.0;
                e -- ;
            }
#line 631
        while (e < 0)
            {
#line 632
                a *= 0.1;
                e ++ ;
            }
#line 636
        return a;
    };
    
#line 535
    int WString::CharHexInt(const Char *s)
    {
#line 536
        if (!s)
#line 536
            return 0;
        while (IsSpace(*s))
#line 537
            s ++ ;
        int n = 0;
#line 538
        int neg = 0;
        switch (*s)
        {
#line 540
            case '-':
#line 540
                neg = 1;
            case '+':
#line 541
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 547
            return n;
        else
#line 547
            return - n;
    };
    
    int WString::CharInt(const Char *s)
    {
        int n = 0;
#line 552
        int neg = 0;
        while (IsSpace(*s))
#line 553
            s ++ ;
        switch (*s)
        {
#line 555
            case '-':
#line 555
                neg = 1;
            case '+':
#line 556
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 560
            return n;
        else
#line 560
            return - n;
    };
    
    Lang::int64 WString::CharInt64(const Char *s)
    {
        Lang::int64 n = 0;
#line 565
        Lang::int64 neg = 0;
        while (IsSpace(*s))
#line 566
            s ++ ;
        switch (*s)
        {
#line 568
            case '-':
#line 568
                neg = 1;
            case '+':
#line 569
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 573
            return n;
        else
#line 573
            return - n;
    };
    
    Lang::uint64 WString::CharIntU64(const Char *s)
    {
        Lang::uint64 n = 0;
        while (IsSpace(*s))
#line 579
            s ++ ;
        switch (*s)
        {
#line 581
            case '-':
#line 581
                return 0;
            case '+':
#line 582
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 506
    int WString::CharOctInt(const Char *s)
    {
#line 507
        if (!s)
#line 507
            return 0;
        while (IsSpace(*s))
#line 508
            s ++ ;
        int n = 0;
#line 509
        int neg = 0;
        switch (*s)
        {
#line 511
            case '-':
#line 511
                neg = 1;
            case '+':
#line 512
                s ++ ;
        }
        while (*s == '0')
#line 514
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 517
            return n;
        else
#line 517
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
    
#line 715
    int WString::Compare(const Char *a, const Char *b)
    {
#line 716
        while (*a || *b)
            {
#line 717
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
#line 727
        while ((*a || *b) && len > 0)
            {
#line 728
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
#line 739
            if (!(dst && src))
            {
#line 739
                Lang::SysBreak("Assertion failed: dst && src");
            }
        }
#line 740
        ;
#line 740
        if (!dst || !src)
#line 740
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 490
    WString WString::DblStr(double d)
    {
#line 491
        Char output[50];
        Native::DblStr(d, output, 50);
        return WString(output);
    };
    
#line 330
    int WString::Find(const WString& str, int pos) const
    {
#line 331
        if (GetCount() == 0)
#line 331
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 334
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 334
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 335
        ;
#line 335
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 339
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 357
    int WString::FindFirstNotOf(const Char *str) const
    {
#line 358
        if (GetCount() <= 0 || !str)
#line 358
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 363
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 367
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 370
                        if (chr == cmp_chr)
                        {
#line 371
                            match = true;
                            break;
                        
                        }
                    }
#line 375
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 498
    Lang::uint32 WString::GetHashValue() const
    {
#line 499
        Hash::Combine ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 435
    bool WString::Insert(int begin, const Char *str, int n)
    {
#line 436
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 438
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 438
                Lang::SysBreak("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 439
        ;
#line 439
        begin = Algorithm::Maximum(0, Algorithm::Minimum(begin, GetCount()));
        WString part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 445
        if (l)
            *this = Left(l) + part;
        else 
#line 447
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 639
    const WString::Char *WString::IntChar(Char *p, int bufsize, int x)
    {
#line 640
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 643
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 648
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 652
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const WString::Char *WString::IntChar64(Char *p, int bufsize, Lang::int64 x)
    {
#line 658
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 661
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 666
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 670
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const WString::Char *WString::IntCharU64(Char *p, int bufsize, Lang::uint64 x)
    {
#line 676
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 679
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 684
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 688
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
#line 478
    WString WString::IntStr(int i)
    {
#line 479
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return WString(value);
    };
    
    WString WString::IntStr64(Lang::int64 i)
    {
#line 485
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return WString(value);
    };
    
#line 694
    int WString::Length(const Char *c, int max_len)
    {
        {
#line 695
            if (!(c))
            {
#line 695
                Lang::SysBreak("Assertion failed: c");
            }
        }
#line 696
        ;
#line 696
        if (!c)
#line 696
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 699
            while (*c)
                {
#line 700
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 706
            while (max_len > 0 && *c)
                {
#line 707
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 405
    WString WString::Mid(int i) const
    {
#line 405
        if (i >= GetCount())
#line 405
            return Empty();
#line 405
        if (i < 0)
#line 405
            i = 0;
#line 405
        return Mid(i, GetCount() - i);
    };
    
#line 406
    WString WString::Mid(int i, int size) const
    {
#line 407
        size = Algorithm::Minimum(size, count - i);
        if (size <= 0)
#line 408
            return WString();
        {
#line 409
            if (!(i >= 0 && i + size <= count))
            {
#line 409
                Lang::SysBreak("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 410
        ;
#line 410
        return WString(Begin() + i, size);
    };
    
#line 415
    void WString::Remove(int begin, int count)
    {
        {
#line 416
            if (!(begin >= 0 && count >= 0))
            {
#line 416
                Lang::SysBreak("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 417
        ;
#line 417
        begin = Algorithm::Maximum(0, begin);
        count = Algorithm::Maximum(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 421
            if (!(begin <= c && end <= c))
            {
#line 421
                Lang::SysBreak("Assertion failed: begin <= c && end <= c");
            }
        }
#line 422
        ;
#line 422
        end = Algorithm::Minimum(c, end);
        begin = Algorithm::Minimum(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 428
        if (l)
            *this = Left(l);
        else 
#line 430
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 289
    void WString::Replace(const WString& s, const WString& value)
    {
#line 290
        if (s == value)
#line 290
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 293
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void WString::Replace(int i, int len, const WString& value)
    {
#line 299
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 305
            Lang::Memory::Copy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 309
            Lang::Memory::Copy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 315
            Lang::Memory::Copy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 320
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        ref[0] -> Inc();
        {
#line 325
            if (!(cursor == new_len + 1))
            {
#line 325
                Lang::SysBreak("Assertion failed: cursor == new_len+1");
            }
        }
#line 326
        ;
    };
    
#line 345
    int WString::ReverseFind(const WString& str, int pos) const
    {
#line 346
        if (GetCount() == 0)
#line 346
            return - 1;
        {
#line 347
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 347
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 348
        ;
#line 348
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 352
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 381
    int WString::ReverseFindFirstNotOf(const Char *str) const
    {
#line 382
        if (GetCount() <= 0 || !str)
#line 382
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 387
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 391
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 394
                        if (chr == cmp_chr)
                        {
#line 395
                            match = true;
                            break;
                        
                        }
                    }
#line 399
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
    
#line 151
    WString& WString::Set(const Char *c, int len, bool find_end)
    {
#line 152
        Clear();
        if (!c)
#line 153
            return *this;
        if (find_end)
#line 154
            count = Algorithm::Minimum(Lang::StringLength(c, len), len);
        else
#line 155
            count = len;
        if (count < 8)
        {
#line 157
            Lang::Memory::Copy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
        }
        else
        {
#line 161
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
