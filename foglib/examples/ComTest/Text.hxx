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

#ifndef TEXT_HXX
#define TEXT_HXX

#include <new>

#ifndef ABSTRACT_HXX
#include <Abstract.hxx>
#endif

namespace Lang
{
#line 9 "../../src/Com/Lang.fog"
    typedef Prim::CPtr < const char > CString;
#line 9
    typedef Prim::CPtr < const void > ConstVoidPtr;
#line 9
    typedef Prim::CPtr < void > VoidPtr;
#line 142 "../../src/Com/Meta.fog"
    typedef unsigned char byte;
#line 142
    typedef short int16;
#line 142
    typedef int int32;
#line 142
    typedef long long int64;
#line 142
    typedef char int8;
#line 142
    typedef unsigned short uint16;
#line 142
    typedef unsigned int uint32;
#line 142
    typedef uint32 dword;
#line 142
    typedef unsigned long long uint64;
#line 142
    typedef uint64 qword;
#line 142
    typedef unsigned char uint8;
#line 142
    typedef uint16 word;
};

namespace Text
{
};

namespace Text {
class String;
}

namespace Text
{
#line 757 "../../src/Com/Text.fog"
    inline String Capitalize(const String& s);
#line 771
    String EscapeCharacter(String s);
#line 770
    String EscapeString(String s);
#line 795
    inline void FromString(const String& s, Lang::byte& o);
#line 794
    inline void FromString(const String& s, Lang::int64& o);
#line 793
    inline void FromString(const String& s, Lang::uint32& o);
#line 799
    inline void FromString(const String& s, String& o);
#line 790
    template < class _1 >
    inline void FromString(const String& s, _1& o);
#line 791
    inline void FromString(const String& s, bool& o);
#line 796
    inline void FromString(const String& s, char& o);
#line 798
    inline void FromString(const String& s, double& o);
#line 797
    inline void FromString(const String& s, float& o);
#line 792
    inline void FromString(const String& s, int& o);
#line 10
    inline int GetHexDigit(char c);
#line 811
    inline int HexDigit(int c);
    inline int HexDigitLower(int c);
    inline String HexStr(Lang::uint64 p);
#line 829
    inline String HexStr(void *p);
#line 9
    inline bool IsAlpha(char c);
#line 7
    inline bool IsDigit(char c);
#line 6
    inline bool IsHexDigit(char c);
#line 5
    inline bool IsOctDigit(char c);
#line 8
    inline bool IsSpace(char c);
#line 801
    template < class _1 >
    inline Lang::int64 ToInt(const _1& o);
#line 805
    template <>
    inline Lang::int64 ToInt < Lang::byte > (const Lang::byte& o);
#line 804
    template <>
    inline Lang::int64 ToInt < Lang::int64 > (const Lang::int64& o);
#line 809
    template <>
    inline Lang::int64 ToInt < String > (const String& o);
#line 802
    template <>
    inline Lang::int64 ToInt < bool > (const bool& o);
#line 806
    template <>
    inline Lang::int64 ToInt < char > (const char& o);
    template <>
    inline Lang::int64 ToInt < double > (const double& o);
#line 807
    template <>
    inline Lang::int64 ToInt < float > (const float& o);
#line 803
    template <>
    inline Lang::int64 ToInt < int > (const int& o);
#line 743
    String ToLower(const String& s);
#line 723
    int ToLowerChar(int chr);
#line 775
    template < class _1 >
    inline String ToString(const _1& o);
#line 780
    template <>
    inline String ToString < Lang::byte > (const Lang::byte& o);
#line 779
    template <>
    inline String ToString < Lang::int64 > (const Lang::int64& o);
#line 778
    template <>
    inline String ToString < Lang::uint32 > (const Lang::uint32& o);
#line 784
    template <>
    inline String ToString < String > (const String& o);
};

namespace Text {
class WString;
}

namespace Text
{
#line 787
    template <>
    inline String ToString < WString > (const WString& o);
#line 776
    template <>
    inline String ToString < bool > (const bool& o);
#line 781
    template <>
    inline String ToString < char > (const char& o);
    template <>
    inline String ToString < double > (const double& o);
#line 782
    template <>
    inline String ToString < float > (const float& o);
#line 777
    template <>
    inline String ToString < int > (const int& o);
#line 729
    String ToUpper(const String& s);
#line 717
    int ToUpperChar(int chr);
#line 786
    template < class _1 >
    inline WString ToWString(const _1& o);
    template <>
    inline WString ToWString < String > (const String& o);
#line 772
    String TrimBoth(String s);
    
    class String
    {
#line 28
        typedef char Char;
        typedef const char ConstChar;
        
#line 88
        bool is_ref;
        int count;
        
    public:
#line 97
        String();
#line 100
        String(const String& s);
#line 98
        String(const Char *c);
        String(const Char *c, int len);
#line 101
        ~String();
#line 415
        inline bool operator!= (const String& s) const;
#line 423
        String operator+ (const String& s);
#line 148
        String operator+ (const String& l) const;
#line 420
        inline String& operator+= (const String& s);
        inline String& operator<< (const String& s);
        inline String& operator<< (int i);
#line 130
        String& operator= (const String& str);
#line 129
        inline String& operator= (const Char *c);
#line 410
        bool operator== (const String& s) const;
#line 417
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 407
        const Char *Begin() const;
#line 160
        String& Cat(Char i);
#line 154
        String& Cat(Char c, int count);
#line 203
        String& Cat(const String& str);
#line 449
        inline String CharoString() const;
#line 104
        void Clear();
#line 408
        inline const Char *End() const;
#line 284
        int Find(const String& str, int pos = 0) const;
#line 311
        int FindFirstNotOf(const Char *str) const;
#line 282
        inline int GetCount() const;
#line 451
        Lang::uint32 GetHashValue() const;
#line 389
        bool Insert(int begin, const Char *str, int n);
#line 283
        inline bool IsEmpty() const;
#line 366
        inline String Left(int i) const;
#line 359
        String Mid(int i) const;
        String Mid(int i, int size) const;
#line 369
        void Remove(int begin, int count);
#line 244
        void Replace(const String& s, const String& value);
#line 253
        void Replace(int i, int len, const String& value);
#line 298
        inline int ReverseFind(const String& str) const;
        int ReverseFind(const String& str, int pos) const;
#line 335
        int ReverseFindFirstNotOf(const Char *str) const;
#line 367
        inline String Right(int i) const;
#line 110
        void Serialize(Abstract::Stream& s);
        String& Set(const Char *c, int len);
        
#line 92
        void Zero();
        
    public:
#line 527
        static double CharDbl(const Char *s);
#line 473
        static int CharHexInt(const Char *s);
#line 488
        static int CharInt(const Char *s);
#line 501
        static Lang::int64 CharInt64(const Char *s);
#line 514
        static Lang::uint64 CharIntU64(const Char *s);
#line 459
        static int CharOctInt(const Char *s);
#line 653
        static int Compare(const Char *a, const Char *b);
#line 664
        static int Compare(const Char *a, const Char *b, int len);
#line 676
        static void Copy(Char *dst, const Char *src);
#line 443
        static String DblStr(double d);
#line 684
        inline static ConstChar *Empty();
#line 426
        inline static int HexInt(const String& s);
#line 577
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 595
        static const Char *IntChar64(Char *p, int bufsize, Lang::int64 x);
#line 613
        static const Char *IntCharU64(Char *p, int bufsize, Lang::uint64 x);
#line 431
        static String IntStr(int i);
#line 437
        static String IntStr64(Lang::int64 i);
#line 632
        static int Length(const Char *c, int max_len = - 1);
#line 425
        inline static int OctInt(const String& s);
#line 429
        inline static double StrDbl(const String& s);
#line 427
        inline static int StrInt(const String& s);
        inline static Lang::int64 StrInt64(const String& s);
        
        class RefData
        {
#line 32
            Char *data;
            int reserved;
#line 91 "../../src/Com/Meta.fog"
            Lang::AtomicInt refs;
            
        public:
#line 36 "../../src/Com/Text.fog"
            RefData(Char *str, int reserved);
            ~RefData();
#line 74
            operator ConstChar * () const;
#line 73
            Char *Begin();
#line 39
            void Clear();
#line 94 "../../src/Com/Meta.fog"
            void Dec();
#line 72 "../../src/Com/Text.fog"
            ConstChar *Get() const;
#line 92 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 76 "../../src/Com/Text.fog"
            int GetReserved() const;
#line 93 "../../src/Com/Meta.fog"
            void Inc();
#line 41 "../../src/Com/Text.fog"
            void IncreaseReserved();
#line 50
            void IncreaseReserved(int min_reserved);
#line 59
            void Reserve(int new_reserved);
        };
        
        union
        {
        public:
#line 85
            Char buf[8];
            RefData *ref[0];
        };
    };
    
    struct Exc : public Text::String
    {
#line 704
        inline Exc();
        inline Exc(const String& s);
    };
    
    class WString
    {
#line 28
        typedef short Char;
        typedef const short ConstChar;
        
#line 88
        bool is_ref;
        int count;
        
    public:
#line 97
        WString();
#line 100
        WString(const WString& s);
#line 98
        WString(const Char *c);
        WString(const Char *c, int len);
#line 101
        ~WString();
#line 415
        inline bool operator!= (const WString& s) const;
#line 423
        WString operator+ (const WString& s);
#line 148
        WString operator+ (const WString& l) const;
#line 420
        inline WString& operator+= (const WString& s);
        inline WString& operator<< (const WString& s);
        inline WString& operator<< (int i);
#line 130
        WString& operator= (const WString& str);
#line 129
        inline WString& operator= (const Char *c);
#line 410
        bool operator== (const WString& s) const;
#line 417
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 407
        const Char *Begin() const;
#line 160
        WString& Cat(Char i);
#line 154
        WString& Cat(Char c, int count);
#line 203
        WString& Cat(const WString& str);
#line 449
        inline WString CharoString() const;
#line 104
        void Clear();
#line 408
        inline const Char *End() const;
#line 284
        int Find(const WString& str, int pos = 0) const;
#line 311
        int FindFirstNotOf(const Char *str) const;
#line 282
        inline int GetCount() const;
#line 451
        Lang::uint32 GetHashValue() const;
#line 389
        bool Insert(int begin, const Char *str, int n);
#line 283
        inline bool IsEmpty() const;
#line 366
        inline WString Left(int i) const;
#line 359
        WString Mid(int i) const;
        WString Mid(int i, int size) const;
#line 369
        void Remove(int begin, int count);
#line 244
        void Replace(const WString& s, const WString& value);
#line 253
        void Replace(int i, int len, const WString& value);
#line 298
        inline int ReverseFind(const WString& str) const;
        int ReverseFind(const WString& str, int pos) const;
#line 335
        int ReverseFindFirstNotOf(const Char *str) const;
#line 367
        inline WString Right(int i) const;
#line 110
        void Serialize(Abstract::Stream& s);
        WString& Set(const Char *c, int len);
        
#line 92
        void Zero();
        
    public:
#line 527
        static double CharDbl(const Char *s);
#line 473
        static int CharHexInt(const Char *s);
#line 488
        static int CharInt(const Char *s);
#line 501
        static Lang::int64 CharInt64(const Char *s);
#line 514
        static Lang::uint64 CharIntU64(const Char *s);
#line 459
        static int CharOctInt(const Char *s);
#line 653
        static int Compare(const Char *a, const Char *b);
#line 664
        static int Compare(const Char *a, const Char *b, int len);
#line 676
        static void Copy(Char *dst, const Char *src);
#line 443
        static WString DblStr(double d);
#line 684
        inline static ConstChar *Empty();
#line 426
        inline static int HexInt(const WString& s);
#line 577
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 595
        static const Char *IntChar64(Char *p, int bufsize, Lang::int64 x);
#line 613
        static const Char *IntCharU64(Char *p, int bufsize, Lang::uint64 x);
#line 431
        static WString IntStr(int i);
#line 437
        static WString IntStr64(Lang::int64 i);
#line 632
        static int Length(const Char *c, int max_len = - 1);
#line 425
        inline static int OctInt(const WString& s);
#line 429
        inline static double StrDbl(const WString& s);
#line 427
        inline static int StrInt(const WString& s);
        inline static Lang::int64 StrInt64(const WString& s);
        
        class RefData
        {
#line 32
            Char *data;
            int reserved;
#line 91 "../../src/Com/Meta.fog"
            Lang::AtomicInt refs;
            
        public:
#line 36 "../../src/Com/Text.fog"
            RefData(Char *str, int reserved);
            ~RefData();
#line 74
            operator ConstChar * () const;
#line 73
            Char *Begin();
#line 39
            void Clear();
#line 94 "../../src/Com/Meta.fog"
            void Dec();
#line 72 "../../src/Com/Text.fog"
            ConstChar *Get() const;
#line 92 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 76 "../../src/Com/Text.fog"
            int GetReserved() const;
#line 93 "../../src/Com/Meta.fog"
            void Inc();
#line 41 "../../src/Com/Text.fog"
            void IncreaseReserved();
#line 50
            void IncreaseReserved(int min_reserved);
#line 59
            void Reserve(int new_reserved);
        };
        
        union
        {
        public:
#line 85
            Char buf[8];
            RefData *ref[0];
        };
    };
};

namespace Text
{
#line 757
    inline String Capitalize(const String& s)
    {
#line 758
        return ToUpper(s.Left(1)) + s.Mid(1);
    };
    
#line 795
    inline void FromString(const String& s, Lang::byte& o)
    {
#line 795
        o = Text::String::StrInt(s);
    };
    
#line 794
    inline void FromString(const String& s, Lang::int64& o)
    {
#line 794
        o = Text::String::StrInt64(s);
    };
    
#line 793
    inline void FromString(const String& s, Lang::uint32& o)
    {
#line 793
        o = Text::String::StrInt64(s);
    };
    
#line 799
    inline void FromString(const String& s, String& o)
    {
#line 799
        o = s;
    };
    
#line 790
    template < class _1 >
    inline void FromString(const String& s, _1& o)
    {
#line 790
        o.FromString(s);
    };
    
#line 791
    inline void FromString(const String& s, bool& o)
    {
#line 791
        o = (ToLower(s) != "false" && s != "0" && s.GetCount());
    };
    
#line 796
    inline void FromString(const String& s, char& o)
    {
#line 796
        o = Text::String::StrInt(s);
    };
    
#line 798
    inline void FromString(const String& s, double& o)
    {
#line 798
        o = Text::String::StrDbl(s);
    };
    
#line 797
    inline void FromString(const String& s, float& o)
    {
#line 797
        o = Text::String::StrDbl(s);
    };
    
#line 792
    inline void FromString(const String& s, int& o)
    {
#line 792
        o = Text::String::StrInt(s);
    };
    
#line 10
    inline int GetHexDigit(char c)
    {
#line 11
        if (c >= '0' && c <= '9')
            return c - '0';
        if (c >= 'a' && c <= 'f')
            return 10 + c - 'a';
        if (c >= 'A' && c <= 'F')
            return 10 + c - 'A';
        return 0;
    };
    
#line 811
    inline int HexDigit(int c)
    {
#line 811
        return "0123456789ABCDEF"[c & 15];
    };
    
#line 812
    inline int HexDigitLower(int c)
    {
#line 812
        return "0123456789abcdef"[c & 15];
    };
    
#line 813
    inline String HexStr(Lang::uint64 p)
    {
#line 814
        String o("0x");
        bool zero = true;
        Lang::uint64 i = 64;
        do
            {
#line 818
                i -= 4;
                Lang::byte b = (p >> i) & 15ULL;
                if (b || !zero)
                {
#line 821
                    zero = false;
                    o.Cat(HexDigit(b));
                }
            }while (i);
#line 826
        if (zero)
#line 826
            o.Cat('0');
        return o;
    };
    
#line 829
    inline String HexStr(void *p)
    {
#line 829
        return HexStr((Lang::uint64) p);
    };
    
#line 9
    inline bool IsAlpha(char c)
    {
#line 9
        return(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    };
    
#line 7
    inline bool IsDigit(char c)
    {
#line 7
        return c >= '0' && c <= '9';
    };
    
#line 6
    inline bool IsHexDigit(char c)
    {
#line 6
        return(c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
    };
    
#line 5
    inline bool IsOctDigit(char c)
    {
#line 5
        return c >= '0' && c <= '7';
    };
    
    inline bool IsSpace(char c)
    {
#line 8
        return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    };
    
#line 801
    template < class _1 >
    inline Lang::int64 ToInt(const _1& o)
    {
#line 801
        return o.ToInt();
    };
    
#line 805
    template <>
    inline Lang::int64 ToInt < Lang::byte > (const Lang::byte& o)
    {
#line 805
        return(Lang::int64) o;
    };
    
#line 804
    template <>
    inline Lang::int64 ToInt < Lang::int64 > (const Lang::int64& o)
    {
#line 804
        return(Lang::int64) o;
    };
    
#line 809
    template <>
    inline Lang::int64 ToInt < String > (const String& o)
    {
#line 809
        return Text::String::StrInt(o);
    };
    
#line 802
    template <>
    inline Lang::int64 ToInt < bool > (const bool& o)
    {
#line 802
        return(Lang::int64) o;
    };
    
#line 806
    template <>
    inline Lang::int64 ToInt < char > (const char& o)
    {
#line 806
        return(Lang::int64) o;
    };
    
#line 808
    template <>
    inline Lang::int64 ToInt < double > (const double& o)
    {
#line 808
        return(Lang::int64) o;
    };
    
#line 807
    template <>
    inline Lang::int64 ToInt < float > (const float& o)
    {
#line 807
        return(Lang::int64) o;
    };
    
#line 803
    template <>
    inline Lang::int64 ToInt < int > (const int& o)
    {
#line 803
        return(Lang::int64) o;
    };
    
#line 775
    template < class _1 >
    inline String ToString(const _1& o)
    {
#line 775
        return o.ToString();
    };
    
#line 780
    template <>
    inline String ToString < Lang::byte > (const Lang::byte& o)
    {
#line 780
        return Text::String::IntStr(o);
    };
    
#line 779
    template <>
    inline String ToString < Lang::int64 > (const Lang::int64& o)
    {
#line 779
        return Text::String::IntStr64(o);
    };
    
#line 778
    template <>
    inline String ToString < Lang::uint32 > (const Lang::uint32& o)
    {
#line 778
        return Text::String::IntStr64(o);
    };
    
#line 784
    template <>
    inline String ToString < String > (const String& o)
    {
#line 784
        return o;
    };
    
    template <>
    inline String ToString < WString > (const WString& o)
    {
#line 787
        return Native::Utf16To8(o.Begin());
    };
    
#line 776
    template <>
    inline String ToString < bool > (const bool& o)
    {
#line 776
        if (o)
#line 776
            return "true";
        else
#line 776
            return "false";
    };
    
#line 781
    template <>
    inline String ToString < char > (const char& o)
    {
#line 781
        String s;
#line 781
        s.Cat(o);
#line 781
        return s;
    };
    
#line 783
    template <>
    inline String ToString < double > (const double& o)
    {
#line 783
        return Text::String::DblStr(o);
    };
    
#line 782
    template <>
    inline String ToString < float > (const float& o)
    {
#line 782
        return Text::String::DblStr(o);
    };
    
#line 777
    template <>
    inline String ToString < int > (const int& o)
    {
#line 777
        return Text::String::IntStr(o);
    };
    
#line 786
    template < class _1 >
    inline WString ToWString(const _1& o)
    {
#line 786
        return o.ToWString();
    };
    
#line 788
    template <>
    inline WString ToWString < String > (const String& o)
    {
#line 788
        return Native::Utf8To16(o.Begin());
    };
    
#line 704
    inline Exc::Exc() {};
    
#line 705
    inline Exc::Exc(const String& s)
    :
        String(s)
    {};
    
#line 415
    inline bool String::operator!= (const String& s) const
    {
#line 415
        return !(*this == s);
    };
    
#line 420
    inline String& String::operator+= (const String& s)
    {
#line 420
        Cat(s);
#line 420
        return *this;
    };
    
#line 421
    inline String& String::operator<< (const String& s)
    {
#line 421
        Cat(s);
#line 421
        return *this;
    };
    
#line 422
    inline String& String::operator<< (int i)
    {
#line 422
        Cat(IntStr(i));
#line 422
        return *this;
    };
    
#line 129
    inline String& String::operator= (const Char *c)
    {
#line 129
        return Set(c, Lang::StringLength(c));
    };
    
#line 417
    inline String::Char String::operator[](int i) const
    {
#line 417
        return At(i);
    };
    
#line 449
    inline String String::CharoString() const
    {
#line 449
        return *this;
    };
    
#line 684
    inline String::ConstChar *String::Empty()
    {
#line 685
        static Char buf[1] = 
        {
            0
        };
#line 686
        return buf;
    };
    
#line 408
    inline const String::Char *String::End() const
    {
#line 408
        return Begin() + GetCount();
    };
    
#line 282
    inline int String::GetCount() const
    {
#line 282
        return count;
    };
    
#line 426
    inline int String::HexInt(const String& s)
    {
#line 426
        return CharHexInt(s.Begin());
    };
    
#line 283
    inline bool String::IsEmpty() const
    {
#line 283
        return count == 0;
    };
    
#line 366
    inline String String::Left(int i) const
    {
#line 366
        return Mid(0, i);
    };
    
#line 425
    inline int String::OctInt(const String& s)
    {
#line 425
        return CharOctInt(s.Begin());
    };
    
#line 298
    inline int String::ReverseFind(const String& str) const
    {
#line 298
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 367
    inline String String::Right(int i) const
    {
#line 367
        return Mid(GetCount() - i, i);
    };
    
#line 429
    inline double String::StrDbl(const String& s)
    {
#line 429
        return CharDbl(s.Begin());
    };
    
#line 427
    inline int String::StrInt(const String& s)
    {
#line 427
        return CharInt(s.Begin());
    };
    
#line 428
    inline Lang::int64 String::StrInt64(const String& s)
    {
#line 428
        return CharInt64(s.Begin());
    };
    
#line 415
    inline bool WString::operator!= (const WString& s) const
    {
#line 415
        return !(*this == s);
    };
    
#line 420
    inline WString& WString::operator+= (const WString& s)
    {
#line 420
        Cat(s);
#line 420
        return *this;
    };
    
#line 421
    inline WString& WString::operator<< (const WString& s)
    {
#line 421
        Cat(s);
#line 421
        return *this;
    };
    
#line 422
    inline WString& WString::operator<< (int i)
    {
#line 422
        Cat(IntStr(i));
#line 422
        return *this;
    };
    
#line 129
    inline WString& WString::operator= (const Char *c)
    {
#line 129
        return Set(c, Lang::StringLength(c));
    };
    
#line 417
    inline WString::Char WString::operator[](int i) const
    {
#line 417
        return At(i);
    };
    
#line 449
    inline WString WString::CharoString() const
    {
#line 449
        return *this;
    };
    
#line 684
    inline WString::ConstChar *WString::Empty()
    {
#line 685
        static Char buf[1] = 
        {
            0
        };
#line 686
        return buf;
    };
    
#line 408
    inline const WString::Char *WString::End() const
    {
#line 408
        return Begin() + GetCount();
    };
    
#line 282
    inline int WString::GetCount() const
    {
#line 282
        return count;
    };
    
#line 426
    inline int WString::HexInt(const WString& s)
    {
#line 426
        return CharHexInt(s.Begin());
    };
    
#line 283
    inline bool WString::IsEmpty() const
    {
#line 283
        return count == 0;
    };
    
#line 366
    inline WString WString::Left(int i) const
    {
#line 366
        return Mid(0, i);
    };
    
#line 425
    inline int WString::OctInt(const WString& s)
    {
#line 425
        return CharOctInt(s.Begin());
    };
    
#line 298
    inline int WString::ReverseFind(const WString& str) const
    {
#line 298
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 367
    inline WString WString::Right(int i) const
    {
#line 367
        return Mid(GetCount() - i, i);
    };
    
#line 429
    inline double WString::StrDbl(const WString& s)
    {
#line 429
        return CharDbl(s.Begin());
    };
    
#line 427
    inline int WString::StrInt(const WString& s)
    {
#line 427
        return CharInt(s.Begin());
    };
    
#line 428
    inline Lang::int64 WString::StrInt64(const WString& s)
    {
#line 428
        return CharInt64(s.Begin());
    };
    
};

#endif
