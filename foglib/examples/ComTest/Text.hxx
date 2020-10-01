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
#line 792 "../../src/Com/Text.fog"
    inline String Capitalize(const String& s);
#line 806
    String EscapeCharacter(String s);
#line 805
    String EscapeString(String s);
#line 830
    inline void FromString(const String& s, Lang::byte& o);
#line 829
    inline void FromString(const String& s, Lang::int64& o);
#line 828
    inline void FromString(const String& s, Lang::uint32& o);
#line 834
    inline void FromString(const String& s, String& o);
#line 825
    template < class _1 >
    inline void FromString(const String& s, _1& o);
#line 826
    inline void FromString(const String& s, bool& o);
#line 831
    inline void FromString(const String& s, char& o);
#line 833
    inline void FromString(const String& s, double& o);
#line 832
    inline void FromString(const String& s, float& o);
#line 827
    inline void FromString(const String& s, int& o);
#line 10
    inline int GetHexDigit(char c);
#line 846
    inline int HexDigit(int c);
    inline int HexDigitLower(int c);
    inline String HexStr(Lang::uint64 p);
#line 864
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
#line 836
    template < class _1 >
    inline Lang::int64 ToInt(const _1& o);
#line 840
    template <>
    inline Lang::int64 ToInt < Lang::byte > (const Lang::byte& o);
#line 839
    template <>
    inline Lang::int64 ToInt < Lang::int64 > (const Lang::int64& o);
#line 844
    template <>
    inline Lang::int64 ToInt < String > (const String& o);
#line 837
    template <>
    inline Lang::int64 ToInt < bool > (const bool& o);
#line 841
    template <>
    inline Lang::int64 ToInt < char > (const char& o);
    template <>
    inline Lang::int64 ToInt < double > (const double& o);
#line 842
    template <>
    inline Lang::int64 ToInt < float > (const float& o);
#line 838
    template <>
    inline Lang::int64 ToInt < int > (const int& o);
#line 778
    String ToLower(const String& s);
#line 758
    int ToLowerChar(int chr);
#line 810
    template < class _1 >
    inline String ToString(const _1& o);
#line 815
    template <>
    inline String ToString < Lang::byte > (const Lang::byte& o);
#line 814
    template <>
    inline String ToString < Lang::int64 > (const Lang::int64& o);
#line 813
    template <>
    inline String ToString < Lang::uint32 > (const Lang::uint32& o);
#line 819
    template <>
    inline String ToString < String > (const String& o);
};

namespace Text {
class WString;
}

namespace Text
{
#line 822
    template <>
    inline String ToString < WString > (const WString& o);
#line 811
    template <>
    inline String ToString < bool > (const bool& o);
#line 816
    template <>
    inline String ToString < char > (const char& o);
    template <>
    inline String ToString < double > (const double& o);
#line 817
    template <>
    inline String ToString < float > (const float& o);
#line 812
    template <>
    inline String ToString < int > (const int& o);
#line 764
    String ToUpper(const String& s);
#line 752
    int ToUpperChar(int chr);
#line 821
    template < class _1 >
    inline WString ToWString(const _1& o);
    template <>
    inline WString ToWString < String > (const String& o);
#line 807
    String TrimBoth(String s);
    
    class String
    {
#line 28
        typedef char Char;
        typedef const char ConstChar;
        
#line 89
        bool is_ref;
        int count;
        
    public:
#line 98
        String();
#line 101
        String(const String& s);
#line 99
        String(const Char *c);
        String(const Char *c, int len);
#line 102
        ~String();
#line 450
        inline bool operator!= (const String& s) const;
#line 458
        String operator+ (const String& s);
#line 183
        String operator+ (const String& l) const;
#line 455
        inline String& operator+= (const String& s);
        inline String& operator<< (const String& s);
        inline String& operator<< (int i);
#line 165
        String& operator= (const String& str);
#line 164
        inline String& operator= (const Char *c);
#line 445
        bool operator== (const String& s) const;
#line 452
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 442
        const Char *Begin() const;
#line 195
        String& Cat(Char i);
#line 189
        String& Cat(Char c, int count);
#line 238
        String& Cat(const String& str);
#line 484
        inline String CharoString() const;
#line 105
        void Clear();
#line 443
        inline const Char *End() const;
#line 319
        int Find(const String& str, int pos = 0) const;
#line 346
        int FindFirstNotOf(const Char *str) const;
#line 317
        inline int GetCount() const;
#line 486
        Lang::uint32 GetHashValue() const;
#line 424
        bool Insert(int begin, const Char *str, int n);
#line 318
        inline bool IsEmpty() const;
#line 401
        inline String Left(int i) const;
#line 394
        String Mid(int i) const;
        String Mid(int i, int size) const;
#line 404
        void Remove(int begin, int count);
#line 279
        void Replace(const String& s, const String& value);
#line 288
        void Replace(int i, int len, const String& value);
#line 333
        inline int ReverseFind(const String& str) const;
        int ReverseFind(const String& str, int pos) const;
#line 370
        int ReverseFindFirstNotOf(const Char *str) const;
#line 402
        inline String Right(int i) const;
#line 111
        void Serialize(Abstract::Stream& s);
#line 145
        String& Set(const Char *c, int len, bool find_end = true);
        
#line 93
        void Zero();
        
    public:
#line 562
        static double CharDbl(const Char *s);
#line 508
        static int CharHexInt(const Char *s);
#line 523
        static int CharInt(const Char *s);
#line 536
        static Lang::int64 CharInt64(const Char *s);
#line 549
        static Lang::uint64 CharIntU64(const Char *s);
#line 494
        static int CharOctInt(const Char *s);
#line 688
        static int Compare(const Char *a, const Char *b);
#line 699
        static int Compare(const Char *a, const Char *b, int len);
#line 711
        static void Copy(Char *dst, const Char *src);
#line 478
        static String DblStr(double d);
#line 719
        inline static ConstChar *Empty();
#line 461
        inline static int HexInt(const String& s);
#line 612
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 630
        static const Char *IntChar64(Char *p, int bufsize, Lang::int64 x);
#line 648
        static const Char *IntCharU64(Char *p, int bufsize, Lang::uint64 x);
#line 466
        static String IntStr(int i);
#line 472
        static String IntStr64(Lang::int64 i);
#line 667
        static int Length(const Char *c, int max_len = - 1);
#line 460
        inline static int OctInt(const String& s);
#line 464
        inline static double StrDbl(const String& s);
#line 462
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
            RefData();
            RefData(Char *str, int reserved);
            ~RefData();
#line 75
            operator ConstChar * () const;
#line 74
            Char *Begin();
#line 40
            void Clear();
#line 94 "../../src/Com/Meta.fog"
            void Dec();
#line 73 "../../src/Com/Text.fog"
            ConstChar *Get() const;
#line 92 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 77 "../../src/Com/Text.fog"
            int GetReserved() const;
#line 93 "../../src/Com/Meta.fog"
            void Inc();
#line 42 "../../src/Com/Text.fog"
            void IncreaseReserved();
#line 51
            void IncreaseReserved(int min_reserved);
#line 60
            void Reserve(int new_reserved);
        };
        
        union
        {
        public:
#line 86
            Char buf[8];
            RefData *ref[0];
        };
    };
    
    struct Exc : public Text::String
    {
#line 739
        inline Exc();
        inline Exc(const String& s);
    };
    
    class WString
    {
#line 28
        typedef short Char;
        typedef const short ConstChar;
        
#line 89
        bool is_ref;
        int count;
        
    public:
#line 98
        WString();
#line 101
        WString(const WString& s);
#line 99
        WString(const Char *c);
        WString(const Char *c, int len);
#line 102
        ~WString();
#line 450
        inline bool operator!= (const WString& s) const;
#line 458
        WString operator+ (const WString& s);
#line 183
        WString operator+ (const WString& l) const;
#line 455
        inline WString& operator+= (const WString& s);
        inline WString& operator<< (const WString& s);
        inline WString& operator<< (int i);
#line 165
        WString& operator= (const WString& str);
#line 164
        inline WString& operator= (const Char *c);
#line 445
        bool operator== (const WString& s) const;
#line 452
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 442
        const Char *Begin() const;
#line 195
        WString& Cat(Char i);
#line 189
        WString& Cat(Char c, int count);
#line 238
        WString& Cat(const WString& str);
#line 484
        inline WString CharoString() const;
#line 105
        void Clear();
#line 443
        inline const Char *End() const;
#line 319
        int Find(const WString& str, int pos = 0) const;
#line 346
        int FindFirstNotOf(const Char *str) const;
#line 317
        inline int GetCount() const;
#line 486
        Lang::uint32 GetHashValue() const;
#line 424
        bool Insert(int begin, const Char *str, int n);
#line 318
        inline bool IsEmpty() const;
#line 401
        inline WString Left(int i) const;
#line 394
        WString Mid(int i) const;
        WString Mid(int i, int size) const;
#line 404
        void Remove(int begin, int count);
#line 279
        void Replace(const WString& s, const WString& value);
#line 288
        void Replace(int i, int len, const WString& value);
#line 333
        inline int ReverseFind(const WString& str) const;
        int ReverseFind(const WString& str, int pos) const;
#line 370
        int ReverseFindFirstNotOf(const Char *str) const;
#line 402
        inline WString Right(int i) const;
#line 111
        void Serialize(Abstract::Stream& s);
#line 145
        WString& Set(const Char *c, int len, bool find_end = true);
        
#line 93
        void Zero();
        
    public:
#line 562
        static double CharDbl(const Char *s);
#line 508
        static int CharHexInt(const Char *s);
#line 523
        static int CharInt(const Char *s);
#line 536
        static Lang::int64 CharInt64(const Char *s);
#line 549
        static Lang::uint64 CharIntU64(const Char *s);
#line 494
        static int CharOctInt(const Char *s);
#line 688
        static int Compare(const Char *a, const Char *b);
#line 699
        static int Compare(const Char *a, const Char *b, int len);
#line 711
        static void Copy(Char *dst, const Char *src);
#line 478
        static WString DblStr(double d);
#line 719
        inline static ConstChar *Empty();
#line 461
        inline static int HexInt(const WString& s);
#line 612
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 630
        static const Char *IntChar64(Char *p, int bufsize, Lang::int64 x);
#line 648
        static const Char *IntCharU64(Char *p, int bufsize, Lang::uint64 x);
#line 466
        static WString IntStr(int i);
#line 472
        static WString IntStr64(Lang::int64 i);
#line 667
        static int Length(const Char *c, int max_len = - 1);
#line 460
        inline static int OctInt(const WString& s);
#line 464
        inline static double StrDbl(const WString& s);
#line 462
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
            RefData();
            RefData(Char *str, int reserved);
            ~RefData();
#line 75
            operator ConstChar * () const;
#line 74
            Char *Begin();
#line 40
            void Clear();
#line 94 "../../src/Com/Meta.fog"
            void Dec();
#line 73 "../../src/Com/Text.fog"
            ConstChar *Get() const;
#line 92 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 77 "../../src/Com/Text.fog"
            int GetReserved() const;
#line 93 "../../src/Com/Meta.fog"
            void Inc();
#line 42 "../../src/Com/Text.fog"
            void IncreaseReserved();
#line 51
            void IncreaseReserved(int min_reserved);
#line 60
            void Reserve(int new_reserved);
        };
        
        union
        {
        public:
#line 86
            Char buf[8];
            RefData *ref[0];
        };
    };
};

namespace Text
{
#line 792
    inline String Capitalize(const String& s)
    {
#line 793
        return ToUpper(s.Left(1)) + s.Mid(1);
    };
    
#line 830
    inline void FromString(const String& s, Lang::byte& o)
    {
#line 830
        o = Text::String::StrInt(s);
    };
    
#line 829
    inline void FromString(const String& s, Lang::int64& o)
    {
#line 829
        o = Text::String::StrInt64(s);
    };
    
#line 828
    inline void FromString(const String& s, Lang::uint32& o)
    {
#line 828
        o = Text::String::StrInt64(s);
    };
    
#line 834
    inline void FromString(const String& s, String& o)
    {
#line 834
        o = s;
    };
    
#line 825
    template < class _1 >
    inline void FromString(const String& s, _1& o)
    {
#line 825
        o.FromString(s);
    };
    
#line 826
    inline void FromString(const String& s, bool& o)
    {
#line 826
        o = (ToLower(s) != "false" && s != "0" && s.GetCount());
    };
    
#line 831
    inline void FromString(const String& s, char& o)
    {
#line 831
        o = Text::String::StrInt(s);
    };
    
#line 833
    inline void FromString(const String& s, double& o)
    {
#line 833
        o = Text::String::StrDbl(s);
    };
    
#line 832
    inline void FromString(const String& s, float& o)
    {
#line 832
        o = Text::String::StrDbl(s);
    };
    
#line 827
    inline void FromString(const String& s, int& o)
    {
#line 827
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
    
#line 846
    inline int HexDigit(int c)
    {
#line 846
        return "0123456789ABCDEF"[c & 15];
    };
    
#line 847
    inline int HexDigitLower(int c)
    {
#line 847
        return "0123456789abcdef"[c & 15];
    };
    
#line 848
    inline String HexStr(Lang::uint64 p)
    {
#line 849
        String o("0x");
        bool zero = true;
        Lang::uint64 i = 64;
        do
            {
#line 853
                i -= 4;
                Lang::byte b = (p >> i) & 15ULL;
                if (b || !zero)
                {
#line 856
                    zero = false;
                    o.Cat(HexDigit(b));
                }
            }while (i);
#line 861
        if (zero)
#line 861
            o.Cat('0');
        return o;
    };
    
#line 864
    inline String HexStr(void *p)
    {
#line 864
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
    
#line 836
    template < class _1 >
    inline Lang::int64 ToInt(const _1& o)
    {
#line 836
        return o.ToInt();
    };
    
#line 840
    template <>
    inline Lang::int64 ToInt < Lang::byte > (const Lang::byte& o)
    {
#line 840
        return(Lang::int64) o;
    };
    
#line 839
    template <>
    inline Lang::int64 ToInt < Lang::int64 > (const Lang::int64& o)
    {
#line 839
        return(Lang::int64) o;
    };
    
#line 844
    template <>
    inline Lang::int64 ToInt < String > (const String& o)
    {
#line 844
        return Text::String::StrInt(o);
    };
    
#line 837
    template <>
    inline Lang::int64 ToInt < bool > (const bool& o)
    {
#line 837
        return(Lang::int64) o;
    };
    
#line 841
    template <>
    inline Lang::int64 ToInt < char > (const char& o)
    {
#line 841
        return(Lang::int64) o;
    };
    
#line 843
    template <>
    inline Lang::int64 ToInt < double > (const double& o)
    {
#line 843
        return(Lang::int64) o;
    };
    
#line 842
    template <>
    inline Lang::int64 ToInt < float > (const float& o)
    {
#line 842
        return(Lang::int64) o;
    };
    
#line 838
    template <>
    inline Lang::int64 ToInt < int > (const int& o)
    {
#line 838
        return(Lang::int64) o;
    };
    
#line 810
    template < class _1 >
    inline String ToString(const _1& o)
    {
#line 810
        return o.ToString();
    };
    
#line 815
    template <>
    inline String ToString < Lang::byte > (const Lang::byte& o)
    {
#line 815
        return Text::String::IntStr(o);
    };
    
#line 814
    template <>
    inline String ToString < Lang::int64 > (const Lang::int64& o)
    {
#line 814
        return Text::String::IntStr64(o);
    };
    
#line 813
    template <>
    inline String ToString < Lang::uint32 > (const Lang::uint32& o)
    {
#line 813
        return Text::String::IntStr64(o);
    };
    
#line 819
    template <>
    inline String ToString < String > (const String& o)
    {
#line 819
        return o;
    };
    
    template <>
    inline String ToString < WString > (const WString& o)
    {
#line 822
        return Native::Utf16To8(o.Begin());
    };
    
#line 811
    template <>
    inline String ToString < bool > (const bool& o)
    {
#line 811
        if (o)
#line 811
            return "true";
        else
#line 811
            return "false";
    };
    
#line 816
    template <>
    inline String ToString < char > (const char& o)
    {
#line 816
        String s;
#line 816
        s.Cat(o);
#line 816
        return s;
    };
    
#line 818
    template <>
    inline String ToString < double > (const double& o)
    {
#line 818
        return Text::String::DblStr(o);
    };
    
#line 817
    template <>
    inline String ToString < float > (const float& o)
    {
#line 817
        return Text::String::DblStr(o);
    };
    
#line 812
    template <>
    inline String ToString < int > (const int& o)
    {
#line 812
        return Text::String::IntStr(o);
    };
    
#line 821
    template < class _1 >
    inline WString ToWString(const _1& o)
    {
#line 821
        return o.ToWString();
    };
    
#line 823
    template <>
    inline WString ToWString < String > (const String& o)
    {
#line 823
        return Native::Utf8To16(o.Begin());
    };
    
#line 739
    inline Exc::Exc() {};
    
#line 740
    inline Exc::Exc(const String& s)
    :
        String(s)
    {};
    
#line 450
    inline bool String::operator!= (const String& s) const
    {
#line 450
        return !(*this == s);
    };
    
#line 455
    inline String& String::operator+= (const String& s)
    {
#line 455
        Cat(s);
#line 455
        return *this;
    };
    
#line 456
    inline String& String::operator<< (const String& s)
    {
#line 456
        Cat(s);
#line 456
        return *this;
    };
    
#line 457
    inline String& String::operator<< (int i)
    {
#line 457
        Cat(IntStr(i));
#line 457
        return *this;
    };
    
#line 164
    inline String& String::operator= (const Char *c)
    {
#line 164
        return Set(c, Lang::StringLength(c));
    };
    
#line 452
    inline String::Char String::operator[](int i) const
    {
#line 452
        return At(i);
    };
    
#line 484
    inline String String::CharoString() const
    {
#line 484
        return *this;
    };
    
#line 719
    inline String::ConstChar *String::Empty()
    {
#line 720
        static Char buf[1] = 
        {
            0
        };
#line 721
        return buf;
    };
    
#line 443
    inline const String::Char *String::End() const
    {
#line 443
        return Begin() + GetCount();
    };
    
#line 317
    inline int String::GetCount() const
    {
#line 317
        return count;
    };
    
#line 461
    inline int String::HexInt(const String& s)
    {
#line 461
        return CharHexInt(s.Begin());
    };
    
#line 318
    inline bool String::IsEmpty() const
    {
#line 318
        return count == 0;
    };
    
#line 401
    inline String String::Left(int i) const
    {
#line 401
        return Mid(0, i);
    };
    
#line 460
    inline int String::OctInt(const String& s)
    {
#line 460
        return CharOctInt(s.Begin());
    };
    
#line 333
    inline int String::ReverseFind(const String& str) const
    {
#line 333
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 402
    inline String String::Right(int i) const
    {
#line 402
        return Mid(GetCount() - i, i);
    };
    
#line 464
    inline double String::StrDbl(const String& s)
    {
#line 464
        return CharDbl(s.Begin());
    };
    
#line 462
    inline int String::StrInt(const String& s)
    {
#line 462
        return CharInt(s.Begin());
    };
    
#line 463
    inline Lang::int64 String::StrInt64(const String& s)
    {
#line 463
        return CharInt64(s.Begin());
    };
    
#line 450
    inline bool WString::operator!= (const WString& s) const
    {
#line 450
        return !(*this == s);
    };
    
#line 455
    inline WString& WString::operator+= (const WString& s)
    {
#line 455
        Cat(s);
#line 455
        return *this;
    };
    
#line 456
    inline WString& WString::operator<< (const WString& s)
    {
#line 456
        Cat(s);
#line 456
        return *this;
    };
    
#line 457
    inline WString& WString::operator<< (int i)
    {
#line 457
        Cat(IntStr(i));
#line 457
        return *this;
    };
    
#line 164
    inline WString& WString::operator= (const Char *c)
    {
#line 164
        return Set(c, Lang::StringLength(c));
    };
    
#line 452
    inline WString::Char WString::operator[](int i) const
    {
#line 452
        return At(i);
    };
    
#line 484
    inline WString WString::CharoString() const
    {
#line 484
        return *this;
    };
    
#line 719
    inline WString::ConstChar *WString::Empty()
    {
#line 720
        static Char buf[1] = 
        {
            0
        };
#line 721
        return buf;
    };
    
#line 443
    inline const WString::Char *WString::End() const
    {
#line 443
        return Begin() + GetCount();
    };
    
#line 317
    inline int WString::GetCount() const
    {
#line 317
        return count;
    };
    
#line 461
    inline int WString::HexInt(const WString& s)
    {
#line 461
        return CharHexInt(s.Begin());
    };
    
#line 318
    inline bool WString::IsEmpty() const
    {
#line 318
        return count == 0;
    };
    
#line 401
    inline WString WString::Left(int i) const
    {
#line 401
        return Mid(0, i);
    };
    
#line 460
    inline int WString::OctInt(const WString& s)
    {
#line 460
        return CharOctInt(s.Begin());
    };
    
#line 333
    inline int WString::ReverseFind(const WString& str) const
    {
#line 333
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 402
    inline WString WString::Right(int i) const
    {
#line 402
        return Mid(GetCount() - i, i);
    };
    
#line 464
    inline double WString::StrDbl(const WString& s)
    {
#line 464
        return CharDbl(s.Begin());
    };
    
#line 462
    inline int WString::StrInt(const WString& s)
    {
#line 462
        return CharInt(s.Begin());
    };
    
#line 463
    inline Lang::int64 WString::StrInt64(const WString& s)
    {
#line 463
        return CharInt64(s.Begin());
    };
    
};

#endif
