#ifndef TEXT_CXX
#define TEXT_CXX

#include <new>

#ifndef TEXT_HXX
#include <Text.hxx>
#endif

namespace Text
{
#line 898 "../../src/Com/Text.fog"
    String CharToUTF8(Lang::uint16 chr)
    {
#line 899
        WString ws;
        ws.Cat((int) chr);
        return ToString(ws);
    };
    
#line 888
    String EscapeCharacter(String s)
    {
#line 889
        s.Replace("\n", "\\n");
        s.Replace("\t", "\\t");
        s.Replace("\r", "\\r");
        s.Replace("\"", "\\\"");
        s.Replace("'", "\\'");
#line 895
        return s;
    };
    
#line 879
    String EscapeString(String s)
    {
#line 880
        s.Replace("\n", "\\n");
        s.Replace("\t", "\\t");
        s.Replace("\r", "\\r");
        s.Replace("\"", "\\\"");
#line 885
        return s;
    };
    
#line 775
    String ToLower(const String& s)
    {
#line 776
        int count = s.GetCount();
        if (!count)
#line 777
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
    
#line 755
    int ToLowerChar(int chr)
    {
#line 756
        if (chr >= 'A' && chr <= 'Z')
            return 'a' + (chr - 'A');
        return chr;
    };
    
    String ToUpper(const String& s)
    {
#line 762
        int count = s.GetCount();
        if (!count)
#line 763
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
    
#line 749
    int ToUpperChar(int chr)
    {
#line 750
        if (chr >= 'a' && chr <= 'z')
            return 'A' + (chr - 'a');
        return chr;
    };
    
#line 805
    String TrimBoth(String s)
    {
#line 806
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
    
#line 465
    String String::operator+ (const String& s)
    {
#line 465
        String out(*this);
#line 465
        out.Cat(s);
#line 465
        return out;
    };
    
#line 185
    String String::operator+ (const String& l) const
    {
#line 186
        String s(*this);
        s.Cat(l);
        return s;
    };
    
#line 167
    String& String::operator= (const String& str)
    {
#line 168
        if (!str.is_ref)
        {
#line 169
            Clear();
            Lang::Memory::Copy(buf, str.buf, sizeof (buf));
            is_ref = false;
        }
        else
        {
#line 174
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
    
#line 452
    bool String::operator== (const String& s) const
    {
#line 453
        if (s.GetCount() != GetCount())
#line 453
            return false;
        if (s.IsEmpty())
#line 454
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 460
    String::Char String::At(int i) const
    {
        {
#line 460
            if (!(i >= 0 && i < count))
            {
#line 460
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 460
        ;
#line 460
        return *(Begin() + i);
    };
    
#line 449
    const String::Char *String::Begin() const
    {
#line 449
        if (is_ref)
        {
            {
#line 449
                if (!(ref[0] && ref[0] -> Get()))
                {
#line 449
                    Lang::SysBreak("Assertion failed: REF && REF->Get()");
                }
            }
#line 449
            ;
#line 449
            return ref[0] -> Get();
        }
        else
#line 449
            return buf;
    };
    
#line 197
    String& String::Cat(Char i)
    {
#line 198
        if (!is_ref)
        {
#line 199
            is_ref = count + 1 >= 8;
            if (!is_ref)
            {
#line 201
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
            }
            else
            {
#line 206
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
#line 217
            if (ref[0] -> GetRefs() == 1)
            {
#line 218
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
#line 227
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
    
#line 191
    String& String::Cat(Char c, int count)
    {
        for (int i = 0; i < count; i ++ )
#line 193
            Cat(c);
        return *this;
    };
    
#line 242
    String& String::Cat(const String& str)
    {
#line 243
        if (!is_ref)
        {
#line 244
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 246
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 250
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
#line 261
            if (ref[0] -> GetRefs() == 1)
            {
#line 262
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
#line 271
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
    
#line 569
    double String::CharDbl(const Char *s)
    {
#line 570
        double a = 0.0;
        int e = 0;
        int c;
#line 574
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 575
                a = a * 10.0 + (c - '0');
            }
#line 578
        if (c == '.')
        {
#line 579
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 580
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 585
        if (c == 'e' || c == 'E')
        {
#line 586
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 590
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 594
                c = *s ++ ;
                sign = - 1;
            }
#line 598
            while (IsDigit(c))
                {
#line 599
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 603
            e += i * sign;
        }
#line 606
        while (e > 0)
            {
#line 607
                a *= 10.0;
                e -- ;
            }
#line 611
        while (e < 0)
            {
#line 612
                a *= 0.1;
                e ++ ;
            }
#line 616
        return a;
    };
    
#line 515
    int String::CharHexInt(const Char *s)
    {
#line 516
        if (!s)
#line 516
            return 0;
        while (IsSpace(*s))
#line 517
            s ++ ;
        int n = 0;
#line 518
        int neg = 0;
        switch (*s)
        {
#line 520
            case '-':
#line 520
                neg = 1;
            case '+':
#line 521
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 527
            return n;
        else
#line 527
            return - n;
    };
    
    int String::CharInt(const Char *s)
    {
        int n = 0;
#line 532
        int neg = 0;
        while (IsSpace(*s))
#line 533
            s ++ ;
        switch (*s)
        {
#line 535
            case '-':
#line 535
                neg = 1;
            case '+':
#line 536
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 540
            return n;
        else
#line 540
            return - n;
    };
    
    Lang::int64 String::CharInt64(const Char *s)
    {
        Lang::int64 n = 0;
#line 545
        Lang::int64 neg = 0;
        while (IsSpace(*s))
#line 546
            s ++ ;
        switch (*s)
        {
#line 548
            case '-':
#line 548
                neg = 1;
            case '+':
#line 549
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 553
            return n;
        else
#line 553
            return - n;
    };
    
    Lang::uint64 String::CharIntU64(const Char *s)
    {
        Lang::uint64 n = 0;
        while (IsSpace(*s))
#line 559
            s ++ ;
        switch (*s)
        {
#line 561
            case '-':
#line 561
                return 0;
            case '+':
#line 562
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 501
    int String::CharOctInt(const Char *s)
    {
#line 502
        if (!s)
#line 502
            return 0;
        while (IsSpace(*s))
#line 503
            s ++ ;
        int n = 0;
#line 504
        int neg = 0;
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
        while (*s == '0')
#line 509
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 512
            return n;
        else
#line 512
            return - n;
    };
    
#line 107
    void String::Clear()
    {
#line 108
        if (is_ref)
        {
#line 108
            ref[0] -> Dec();
#line 108
            ref[0] = 0;
#line 108
            is_ref = false;
        }
        else
        {
#line 109
            ref[0] = 0;
        }
#line 110
        count = 0;
    };
    
#line 695
    int String::Compare(const Char *a, const Char *b)
    {
#line 696
        while (*a || *b)
            {
#line 697
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
#line 707
        while ((*a || *b) && len > 0)
            {
#line 708
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
#line 719
            if (!(dst && src))
            {
#line 719
                Lang::SysBreak("Assertion failed: dst && src");
            }
        }
#line 720
        ;
#line 720
        if (!dst || !src)
#line 720
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 485
    String String::DblStr(double d)
    {
#line 486
        Char output[50];
        Native::DblStr(d, output, 50);
        return String(output);
    };
    
#line 326
    int String::Find(const String& str, int pos) const
    {
#line 327
        if (GetCount() == 0)
#line 327
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 330
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 330
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 331
        ;
#line 331
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 335
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 353
    int String::FindFirstNotOf(const Char *str) const
    {
#line 354
        if (GetCount() <= 0 || !str)
#line 354
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 359
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 363
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 366
                        if (chr == cmp_chr)
                        {
#line 367
                            match = true;
                            break;
                        
                        }
                    }
#line 371
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 493
    Lang::uint32 String::GetHashValue() const
    {
#line 494
        Hash::Combine ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 431
    bool String::Insert(int begin, const Char *str, int n)
    {
#line 432
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 434
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 434
                Lang::SysBreak("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 435
        ;
#line 435
        begin = Algorithm::Maximum(0, Algorithm::Minimum(begin, GetCount()));
        String part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 441
        if (l)
            *this = Left(l) + part;
        else 
#line 443
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 619
    const String::Char *String::IntChar(Char *p, int bufsize, int x)
    {
#line 620
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 623
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 628
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 632
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const String::Char *String::IntChar64(Char *p, int bufsize, Lang::int64 x)
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
    
    const String::Char *String::IntCharU64(Char *p, int bufsize, Lang::uint64 x)
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
    
#line 473
    String String::IntStr(int i)
    {
#line 474
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return String(value);
    };
    
    String String::IntStr64(Lang::int64 i)
    {
#line 480
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return String(value);
    };
    
#line 674
    int String::Length(const Char *c, int max_len)
    {
        {
#line 675
            if (!(c))
            {
#line 675
                Lang::SysBreak("Assertion failed: c");
            }
        }
#line 676
        ;
#line 676
        if (!c)
#line 676
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 679
            while (*c)
                {
#line 680
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 686
            while (max_len > 0 && *c)
                {
#line 687
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 401
    String String::Mid(int i) const
    {
#line 401
        if (i >= GetCount())
#line 401
            return Empty();
#line 401
        if (i < 0)
#line 401
            i = 0;
#line 401
        return Mid(i, GetCount() - i);
    };
    
#line 402
    String String::Mid(int i, int size) const
    {
#line 403
        size = Algorithm::Minimum(size, count - i);
        if (size <= 0)
#line 404
            return String();
        {
#line 405
            if (!(i >= 0 && i + size <= count))
            {
#line 405
                Lang::SysBreak("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 406
        ;
#line 406
        return String(Begin() + i, size);
    };
    
#line 411
    void String::Remove(int begin, int count)
    {
        {
#line 412
            if (!(begin >= 0 && count >= 0))
            {
#line 412
                Lang::SysBreak("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 413
        ;
#line 413
        begin = Algorithm::Maximum(0, begin);
        count = Algorithm::Maximum(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 417
            if (!(begin <= c && end <= c))
            {
#line 417
                Lang::SysBreak("Assertion failed: begin <= c && end <= c");
            }
        }
#line 418
        ;
#line 418
        end = Algorithm::Minimum(c, end);
        begin = Algorithm::Minimum(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 424
        if (l)
            *this = Left(l);
        else 
#line 426
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 285
    void String::Replace(const String& s, const String& value)
    {
#line 286
        if (s == value)
#line 286
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 289
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void String::Replace(int i, int len, const String& value)
    {
#line 295
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 301
            Lang::Memory::Copy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 305
            Lang::Memory::Copy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 311
            Lang::Memory::Copy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 316
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        ref[0] -> Inc();
        {
#line 321
            if (!(cursor == new_len + 1))
            {
#line 321
                Lang::SysBreak("Assertion failed: cursor == new_len+1");
            }
        }
#line 322
        ;
    };
    
#line 341
    int String::ReverseFind(const String& str, int pos) const
    {
#line 342
        if (GetCount() == 0)
#line 342
            return - 1;
        {
#line 343
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 343
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 344
        ;
#line 344
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 348
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 377
    int String::ReverseFindFirstNotOf(const Char *str) const
    {
#line 378
        if (GetCount() <= 0 || !str)
#line 378
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 383
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 387
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 390
                        if (chr == cmp_chr)
                        {
#line 391
                            match = true;
                            break;
                        
                        }
                    }
#line 395
                i -- ;
                if (!match)
                    return i;
            }
        return - 1;
    };
    
#line 113
    void String::Serialize(Abstract::StreamBase& s)
    {
#line 114
        if (s.IsStoring())
        {
#line 115
            s.Put(&count, sizeof (count));
            if (count)
            {
#line 117
                if (!is_ref)
                    s.Put(buf, count);
                else
                    s.Put(ref[0] -> Get(), count);
            }
        }
        else 
#line 123
        if (s.IsLoading())
        {
#line 124
            Clear();
            s.Get(&count, sizeof (count));
            {
#line 126
                if (!(count >= 0))
                {
#line 126
                    Lang::SysBreak("Assertion failed: count >= 0");
                }
            }
#line 127
            ;
#line 127
            if (count < 0)
#line 127
                count = 0;
            if (count > 0)
            {
#line 129
                if (count < 8)
                {
#line 130
                    s.Get(buf, sizeof (Char) * count);
                    buf[count] = 0;
                }
                else
                {
#line 134
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
#line 148
        Clear();
        if (!c)
#line 149
            return *this;
        if (find_end)
#line 150
            count = Algorithm::Minimum(Lang::StringLength(c, len), len);
        else
#line 151
            count = len;
        if (count < 8)
        {
#line 153
            Lang::Memory::Copy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
        }
        else
        {
#line 157
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
    
#line 465
    WString WString::operator+ (const WString& s)
    {
#line 465
        WString out(*this);
#line 465
        out.Cat(s);
#line 465
        return out;
    };
    
#line 185
    WString WString::operator+ (const WString& l) const
    {
#line 186
        WString s(*this);
        s.Cat(l);
        return s;
    };
    
#line 167
    WString& WString::operator= (const WString& str)
    {
#line 168
        if (!str.is_ref)
        {
#line 169
            Clear();
            Lang::Memory::Copy(buf, str.buf, sizeof (buf));
            is_ref = false;
        }
        else
        {
#line 174
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
    
#line 452
    bool WString::operator== (const WString& s) const
    {
#line 453
        if (s.GetCount() != GetCount())
#line 453
            return false;
        if (s.IsEmpty())
#line 454
            return true;
        return Compare(s.Begin(), Begin()) == 0;
    };
    
#line 460
    WString::Char WString::At(int i) const
    {
        {
#line 460
            if (!(i >= 0 && i < count))
            {
#line 460
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 460
        ;
#line 460
        return *(Begin() + i);
    };
    
#line 449
    const WString::Char *WString::Begin() const
    {
#line 449
        if (is_ref)
        {
            {
#line 449
                if (!(ref[0] && ref[0] -> Get()))
                {
#line 449
                    Lang::SysBreak("Assertion failed: REF && REF->Get()");
                }
            }
#line 449
            ;
#line 449
            return ref[0] -> Get();
        }
        else
#line 449
            return buf;
    };
    
#line 197
    WString& WString::Cat(Char i)
    {
#line 198
        if (!is_ref)
        {
#line 199
            is_ref = count + 1 >= 8;
            if (!is_ref)
            {
#line 201
                buf[count] = i;
                count ++ ;
                buf[count] = 0;
            }
            else
            {
#line 206
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
#line 217
            if (ref[0] -> GetRefs() == 1)
            {
#line 218
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
#line 227
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
    
#line 191
    WString& WString::Cat(Char c, int count)
    {
        for (int i = 0; i < count; i ++ )
#line 193
            Cat(c);
        return *this;
    };
    
#line 242
    WString& WString::Cat(const WString& str)
    {
#line 243
        if (!is_ref)
        {
#line 244
            is_ref = count + str.GetCount() >= 8;
            if (!is_ref)
            {
#line 246
                Lang::Memory::Copy(&buf[count], str.Begin(), sizeof (Char) * (str.GetCount() + 1));
                count += str.GetCount();
            }
            else
            {
#line 250
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
#line 261
            if (ref[0] -> GetRefs() == 1)
            {
#line 262
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
#line 271
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
    
#line 569
    double WString::CharDbl(const Char *s)
    {
#line 570
        double a = 0.0;
        int e = 0;
        int c;
#line 574
        while ((c = *s ++ ) != '\000' && IsDigit(c))
            {
#line 575
                a = a * 10.0 + (c - '0');
            }
#line 578
        if (c == '.')
        {
#line 579
            while ((c = *s ++ ) != '\000' && IsDigit(c))
                {
#line 580
                    a = a * 10.0 + (c - '0');
                    e = e - 1;
                }
        }
#line 585
        if (c == 'e' || c == 'E')
        {
#line 586
            int sign = 1;
            int i = 0;
            c = *s ++ ;
#line 590
            if (c == '+')
                c = *s ++ ;
            else 
            if (c == '-')
            {
#line 594
                c = *s ++ ;
                sign = - 1;
            }
#line 598
            while (IsDigit(c))
                {
#line 599
                    i = i * 10 + (c - '0');
                    c = *s ++ ;
                }
#line 603
            e += i * sign;
        }
#line 606
        while (e > 0)
            {
#line 607
                a *= 10.0;
                e -- ;
            }
#line 611
        while (e < 0)
            {
#line 612
                a *= 0.1;
                e ++ ;
            }
#line 616
        return a;
    };
    
#line 515
    int WString::CharHexInt(const Char *s)
    {
#line 516
        if (!s)
#line 516
            return 0;
        while (IsSpace(*s))
#line 517
            s ++ ;
        int n = 0;
#line 518
        int neg = 0;
        switch (*s)
        {
#line 520
            case '-':
#line 520
                neg = 1;
            case '+':
#line 521
                s ++ ;
        }
        if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
            s += 2;
        while (IsHexDigit(*s))
            n = 16 * n - GetHexDigit(*s ++ );
        if (neg)
#line 527
            return n;
        else
#line 527
            return - n;
    };
    
    int WString::CharInt(const Char *s)
    {
        int n = 0;
#line 532
        int neg = 0;
        while (IsSpace(*s))
#line 533
            s ++ ;
        switch (*s)
        {
#line 535
            case '-':
#line 535
                neg = 1;
            case '+':
#line 536
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 540
            return n;
        else
#line 540
            return - n;
    };
    
    Lang::int64 WString::CharInt64(const Char *s)
    {
        Lang::int64 n = 0;
#line 545
        Lang::int64 neg = 0;
        while (IsSpace(*s))
#line 546
            s ++ ;
        switch (*s)
        {
#line 548
            case '-':
#line 548
                neg = 1;
            case '+':
#line 549
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        if (neg)
#line 553
            return n;
        else
#line 553
            return - n;
    };
    
    Lang::uint64 WString::CharIntU64(const Char *s)
    {
        Lang::uint64 n = 0;
        while (IsSpace(*s))
#line 559
            s ++ ;
        switch (*s)
        {
#line 561
            case '-':
#line 561
                return 0;
            case '+':
#line 562
                s ++ ;
        }
        while (IsDigit(*s))
            n = 10 * n - (*s ++ - '0');
        return n;
    };
    
#line 501
    int WString::CharOctInt(const Char *s)
    {
#line 502
        if (!s)
#line 502
            return 0;
        while (IsSpace(*s))
#line 503
            s ++ ;
        int n = 0;
#line 504
        int neg = 0;
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
        while (*s == '0')
#line 509
            s ++ ;
        while (IsOctDigit(*s))
            n = 8 * n - (*s ++ - '0');
        if (neg)
#line 512
            return n;
        else
#line 512
            return - n;
    };
    
#line 107
    void WString::Clear()
    {
#line 108
        if (is_ref)
        {
#line 108
            ref[0] -> Dec();
#line 108
            ref[0] = 0;
#line 108
            is_ref = false;
        }
        else
        {
#line 109
            ref[0] = 0;
        }
#line 110
        count = 0;
    };
    
#line 695
    int WString::Compare(const Char *a, const Char *b)
    {
#line 696
        while (*a || *b)
            {
#line 697
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
#line 707
        while ((*a || *b) && len > 0)
            {
#line 708
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
#line 719
            if (!(dst && src))
            {
#line 719
                Lang::SysBreak("Assertion failed: dst && src");
            }
        }
#line 720
        ;
#line 720
        if (!dst || !src)
#line 720
            return;
        while (*src)
            *dst ++ = *src ++ ;
        *dst = 0;
    };
    
#line 485
    WString WString::DblStr(double d)
    {
#line 486
        Char output[50];
        Native::DblStr(d, output, 50);
        return WString(output);
    };
    
#line 326
    int WString::Find(const WString& str, int pos) const
    {
#line 327
        if (GetCount() == 0)
#line 327
            return - 1;
        if (pos == count)
            return - 1;
        {
#line 330
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 330
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 331
        ;
#line 331
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i < count; i ++ )
            {
#line 335
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 353
    int WString::FindFirstNotOf(const Char *str) const
    {
#line 354
        if (GetCount() <= 0 || !str)
#line 354
            return - 1;
        const Char * it = Begin();
        const Char * end = End();
        int i = 0;
        while (it != end)
            {
#line 359
                Char chr = *it ++ ;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 363
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 366
                        if (chr == cmp_chr)
                        {
#line 367
                            match = true;
                            break;
                        
                        }
                    }
#line 371
                if (!match)
                    return i;
                i ++ ;
            }
        return - 1;
    };
    
#line 493
    Lang::uint32 WString::GetHashValue() const
    {
#line 494
        Hash::Combine ch;
        const Char * buf = Begin();
        for (int i = 0; i < count; i ++ )
            ch.Put(*buf ++ );
        return ch;
    };
    
#line 431
    bool WString::Insert(int begin, const Char *str, int n)
    {
#line 432
        if (begin < 0 || begin > GetCount() || !str || n <= 0)
            return false;
        {
#line 434
            if (!(begin >= 0 && begin <= GetCount()))
            {
#line 434
                Lang::SysBreak("Assertion failed: begin >= 0 && begin <= GetCount()");
            }
        }
#line 435
        ;
#line 435
        begin = Algorithm::Maximum(0, Algorithm::Minimum(begin, GetCount()));
        WString part(str, n);
        int l = begin;
        int r = GetCount() - begin;
        if (l && r)
            *this = Left(l) + part + Right(r);
        else 
#line 441
        if (l)
            *this = Left(l) + part;
        else 
#line 443
        if (r)
            *this = part + Right(r);
        else
            *this = part;
        return true;
    };
    
#line 619
    const WString::Char *WString::IntChar(Char *p, int bufsize, int x)
    {
#line 620
        p += bufsize;
        bool is_neg = false;
        if (x < 0)
        {
#line 623
            is_neg = true;
            x *= - 1;
        }
        *-- p = 0;
        do
            {
#line 628
                *-- p = '0' + x % 10;
                x /= 10;
            }while (x);
#line 632
        if (is_neg)
            *-- p = '-';
        return p;
    };
    
    const WString::Char *WString::IntChar64(Char *p, int bufsize, Lang::int64 x)
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
    
    const WString::Char *WString::IntCharU64(Char *p, int bufsize, Lang::uint64 x)
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
    
#line 473
    WString WString::IntStr(int i)
    {
#line 474
        Char buf[10];
        const Char * value = IntChar(buf, 10, i);
        return WString(value);
    };
    
    WString WString::IntStr64(Lang::int64 i)
    {
#line 480
        Char buf[30];
        const Char * value = IntChar64(buf, 30, i);
        return WString(value);
    };
    
#line 674
    int WString::Length(const Char *c, int max_len)
    {
        {
#line 675
            if (!(c))
            {
#line 675
                Lang::SysBreak("Assertion failed: c");
            }
        }
#line 676
        ;
#line 676
        if (!c)
#line 676
            return 0;
        int count = 0;
        if (max_len < 0)
        {
#line 679
            while (*c)
                {
#line 680
                    count ++ ;
                    c ++ ;
                }
            return count;
        }
        else
        {
#line 686
            while (max_len > 0 && *c)
                {
#line 687
                    count ++ ;
                    c ++ ;
                    max_len -- ;
                }
            return count;
        }
    };
    
#line 401
    WString WString::Mid(int i) const
    {
#line 401
        if (i >= GetCount())
#line 401
            return Empty();
#line 401
        if (i < 0)
#line 401
            i = 0;
#line 401
        return Mid(i, GetCount() - i);
    };
    
#line 402
    WString WString::Mid(int i, int size) const
    {
#line 403
        size = Algorithm::Minimum(size, count - i);
        if (size <= 0)
#line 404
            return WString();
        {
#line 405
            if (!(i >= 0 && i + size <= count))
            {
#line 405
                Lang::SysBreak("Assertion failed: i >= 0 && i + size <= count");
            }
        }
#line 406
        ;
#line 406
        return WString(Begin() + i, size);
    };
    
#line 411
    void WString::Remove(int begin, int count)
    {
        {
#line 412
            if (!(begin >= 0 && count >= 0))
            {
#line 412
                Lang::SysBreak("Assertion failed: begin >= 0 && count >= 0");
            }
        }
#line 413
        ;
#line 413
        begin = Algorithm::Maximum(0, begin);
        count = Algorithm::Maximum(0, count);
        int end = begin + count;
        int c = GetCount();
        {
#line 417
            if (!(begin <= c && end <= c))
            {
#line 417
                Lang::SysBreak("Assertion failed: begin <= c && end <= c");
            }
        }
#line 418
        ;
#line 418
        end = Algorithm::Minimum(c, end);
        begin = Algorithm::Minimum(c, begin);
        int l = begin;
        int r = c - end;
        if (l && r)
            *this = Left(l) + Right(r);
        else 
#line 424
        if (l)
            *this = Left(l);
        else 
#line 426
        if (r)
            *this = Right(r);
        else
            Clear();
    };
    
#line 285
    void WString::Replace(const WString& s, const WString& value)
    {
#line 286
        if (s == value)
#line 286
            return;
        int i = Find(s);
        while (i >= 0)
            {
#line 289
                Replace(i, s.GetCount(), value);
                i = Find(s, i + value.GetCount());
            }
    };
    
    void WString::Replace(int i, int len, const WString& value)
    {
#line 295
        int new_len = this -> count - len + value.GetCount();
        const Char * begin = Begin();
        int reserved = new_len + 1;
        Char * buf = (Char * ) Lang::Memory::Alloc(sizeof (Char) * (reserved));
        int cursor = 0;
        if (i > 0)
        {
#line 301
            Lang::Memory::Copy(buf, begin, sizeof (Char) * i);
            cursor += i;
        }
        if (value.GetCount() > 0)
        {
#line 305
            Lang::Memory::Copy(buf + cursor, value.Begin(), sizeof (Char) * value.GetCount());
            cursor += value.GetCount();
        }
        int c = i + len;
        int end_len = this -> count - c;
        if (end_len > 0)
        {
#line 311
            Lang::Memory::Copy(buf + cursor, begin + c, sizeof (Char) * end_len);
            cursor += end_len;
        }
        buf[cursor ++ ] = 0;
#line 316
        Clear();
        this -> is_ref = true;
        this -> count = new_len;
        ref[0] = new RefData(buf, reserved);
        ref[0] -> Inc();
        {
#line 321
            if (!(cursor == new_len + 1))
            {
#line 321
                Lang::SysBreak("Assertion failed: cursor == new_len+1");
            }
        }
#line 322
        ;
    };
    
#line 341
    int WString::ReverseFind(const WString& str, int pos) const
    {
#line 342
        if (GetCount() == 0)
#line 342
            return - 1;
        {
#line 343
            if (!(pos >= 0 && pos < GetCount()))
            {
#line 343
                Lang::SysBreak("Assertion failed: pos >= 0 && pos < GetCount()");
            }
        }
#line 344
        ;
#line 344
        const Char * cur = Begin();
        const Char * cmp = str.Begin();
        int len = str.GetCount();
        for (int i = pos; i >= 0; i -- )
            {
#line 348
                if (Compare(cur + i, cmp, len) == 0)
                    return i;
            }
        return - 1;
    };
    
#line 377
    int WString::ReverseFindFirstNotOf(const Char *str) const
    {
#line 378
        if (GetCount() <= 0 || !str)
#line 378
            return - 1;
        const Char * begin = Begin();
        const Char * it = End();
        int i = GetCount();
        while (it != begin)
            {
#line 383
                Char chr = *-- it;
                const Char * cmp_it = str;
                bool match = false;
                while (1)
                    {
#line 387
                        Char cmp_chr = *cmp_it ++ ;
                        if (!cmp_chr)
                            break;
                        
#line 390
                        if (chr == cmp_chr)
                        {
#line 391
                            match = true;
                            break;
                        
                        }
                    }
#line 395
                i -- ;
                if (!match)
                    return i;
            }
        return - 1;
    };
    
#line 113
    void WString::Serialize(Abstract::StreamBase& s)
    {
#line 114
        if (s.IsStoring())
        {
#line 115
            s.Put(&count, sizeof (count));
            if (count)
            {
#line 117
                if (!is_ref)
                    s.Put(buf, count);
                else
                    s.Put(ref[0] -> Get(), count);
            }
        }
        else 
#line 123
        if (s.IsLoading())
        {
#line 124
            Clear();
            s.Get(&count, sizeof (count));
            {
#line 126
                if (!(count >= 0))
                {
#line 126
                    Lang::SysBreak("Assertion failed: count >= 0");
                }
            }
#line 127
            ;
#line 127
            if (count < 0)
#line 127
                count = 0;
            if (count > 0)
            {
#line 129
                if (count < 8)
                {
#line 130
                    s.Get(buf, sizeof (Char) * count);
                    buf[count] = 0;
                }
                else
                {
#line 134
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
#line 148
        Clear();
        if (!c)
#line 149
            return *this;
        if (find_end)
#line 150
            count = Algorithm::Minimum(Lang::StringLength(c, len), len);
        else
#line 151
            count = len;
        if (count < 8)
        {
#line 153
            Lang::Memory::Copy(buf, c, sizeof (Char) * count);
            buf[count] = 0;
        }
        else
        {
#line 157
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
