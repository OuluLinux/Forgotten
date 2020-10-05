#ifndef TEXT_HXX
#define TEXT_HXX

#include <new>

#ifndef PRIM_HXX
#include <Prim.hxx>
#endif

#ifndef LANG_HXX
#include <Lang.hxx>
#endif

#ifndef ABSTRACT_HXX
#include <Abstract.hxx>
#endif

namespace Text
{
};

namespace Text {
class String;
}

namespace Text
{
#line 797 "../../src/Com/Text.fog"
    inline String Capitalize(const String& s);
#line 811
    String EscapeCharacter(String s);
#line 810
    String EscapeString(String s);
#line 850
    inline void FromString(const String& s, Lang::byte& o);
#line 849
    inline void FromString(const String& s, Lang::int64& o);
#line 848
    inline void FromString(const String& s, Lang::uint32& o);
#line 854
    inline void FromString(const String& s, String& o);
#line 845
    template < class _1 >
    inline void FromString(const String& s, _1& o);
#line 846
    inline void FromString(const String& s, bool& o);
#line 851
    inline void FromString(const String& s, char& o);
#line 853
    inline void FromString(const String& s, double& o);
#line 852
    inline void FromString(const String& s, float& o);
#line 847
    inline void FromString(const String& s, int& o);
#line 10
    inline int GetHexDigit(char c);
#line 866
    inline int HexDigit(int c);
    inline int HexDigitLower(int c);
    inline String HexStr(Lang::uint64 p);
#line 884
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
#line 856
    template < class _1 >
    inline Lang::int64 ToInt(const _1& o);
#line 860
    template <>
    inline Lang::int64 ToInt < Lang::byte > (const Lang::byte& o);
#line 859
    template <>
    inline Lang::int64 ToInt < Lang::int64 > (const Lang::int64& o);
#line 864
    template <>
    inline Lang::int64 ToInt < String > (const String& o);
#line 857
    template <>
    inline Lang::int64 ToInt < bool > (const bool& o);
#line 861
    template <>
    inline Lang::int64 ToInt < char > (const char& o);
    template <>
    inline Lang::int64 ToInt < double > (const double& o);
#line 862
    template <>
    inline Lang::int64 ToInt < float > (const float& o);
#line 858
    template <>
    inline Lang::int64 ToInt < int > (const int& o);
#line 783
    String ToLower(const String& s);
#line 763
    int ToLowerChar(int chr);
#line 830
    template < class _1 >
    inline String ToString(const _1& o);
#line 835
    template <>
    inline String ToString < Lang::byte > (const Lang::byte& o);
#line 834
    template <>
    inline String ToString < Lang::int64 > (const Lang::int64& o);
#line 833
    template <>
    inline String ToString < Lang::uint32 > (const Lang::uint32& o);
#line 839
    template <>
    inline String ToString < String > (const String& o);
};

namespace Text {
class WString;
}

namespace Text
{
#line 842
    template <>
    inline String ToString < WString > (const WString& o);
#line 831
    template <>
    inline String ToString < bool > (const bool& o);
#line 836
    template <>
    inline String ToString < char > (const char& o);
    template <>
    inline String ToString < double > (const double& o);
#line 837
    template <>
    inline String ToString < float > (const float& o);
#line 832
    template <>
    inline String ToString < int > (const int& o);
#line 769
    String ToUpper(const String& s);
#line 757
    int ToUpperChar(int chr);
#line 841
    template < class _1 >
    inline WString ToWString(const _1& o);
    template <>
    inline WString ToWString < String > (const String& o);
#line 813
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
#line 455
        inline bool operator!= (const String& s) const;
#line 463
        String operator+ (const String& s);
#line 183
        String operator+ (const String& l) const;
#line 460
        inline String& operator+= (const String& s);
        inline String& operator<< (const String& s);
        inline String& operator<< (int i);
#line 165
        String& operator= (const String& str);
#line 164
        inline String& operator= (const Char *c);
#line 450
        bool operator== (const String& s) const;
#line 457
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 447
        const Char *Begin() const;
#line 195
        String& Cat(Char i);
#line 189
        String& Cat(Char c, int count);
#line 240
        String& Cat(const String& str);
#line 489
        inline String CharoString() const;
#line 105
        void Clear();
#line 448
        inline const Char *End() const;
#line 324
        int Find(const String& str, int pos = 0) const;
#line 351
        int FindFirstNotOf(const Char *str) const;
#line 322
        inline int GetCount() const;
#line 491
        Lang::uint32 GetHashValue() const;
#line 429
        bool Insert(int begin, const Char *str, int n);
#line 323
        inline bool IsEmpty() const;
#line 406
        inline String Left(int i) const;
#line 399
        String Mid(int i) const;
        String Mid(int i, int size) const;
#line 409
        void Remove(int begin, int count);
#line 283
        void Replace(const String& s, const String& value);
#line 292
        void Replace(int i, int len, const String& value);
#line 338
        inline int ReverseFind(const String& str) const;
        int ReverseFind(const String& str, int pos) const;
#line 375
        int ReverseFindFirstNotOf(const Char *str) const;
#line 407
        inline String Right(int i) const;
#line 111
        void Serialize(Abstract::StreamBase& s);
#line 145
        String& Set(const Char *c, int len, bool find_end = true);
        
#line 93
        void Zero();
        
    public:
#line 567
        static double CharDbl(const Char *s);
#line 513
        static int CharHexInt(const Char *s);
#line 528
        static int CharInt(const Char *s);
#line 541
        static Lang::int64 CharInt64(const Char *s);
#line 554
        static Lang::uint64 CharIntU64(const Char *s);
#line 499
        static int CharOctInt(const Char *s);
#line 693
        static int Compare(const Char *a, const Char *b);
#line 704
        static int Compare(const Char *a, const Char *b, int len);
#line 716
        static void Copy(Char *dst, const Char *src);
#line 483
        static String DblStr(double d);
#line 724
        inline static ConstChar *Empty();
#line 466
        inline static int HexInt(const String& s);
#line 617
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 635
        static const Char *IntChar64(Char *p, int bufsize, Lang::int64 x);
#line 653
        static const Char *IntCharU64(Char *p, int bufsize, Lang::uint64 x);
#line 471
        static String IntStr(int i);
#line 477
        static String IntStr64(Lang::int64 i);
#line 672
        static int Length(const Char *c, int max_len = - 1);
#line 465
        inline static int OctInt(const String& s);
#line 469
        inline static double StrDbl(const String& s);
#line 467
        inline static int StrInt(const String& s);
        inline static Lang::int64 StrInt64(const String& s);
        
        class RefData
        {
#line 32
            Char *data;
            int reserved;
#line 94 "../../src/Com/Meta.fog"
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
#line 97 "../../src/Com/Meta.fog"
            void Dec();
#line 73 "../../src/Com/Text.fog"
            ConstChar *Get() const;
#line 95 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 77 "../../src/Com/Text.fog"
            int GetReserved() const;
#line 96 "../../src/Com/Meta.fog"
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
#line 744
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
#line 455
        inline bool operator!= (const WString& s) const;
#line 463
        WString operator+ (const WString& s);
#line 183
        WString operator+ (const WString& l) const;
#line 460
        inline WString& operator+= (const WString& s);
        inline WString& operator<< (const WString& s);
        inline WString& operator<< (int i);
#line 165
        WString& operator= (const WString& str);
#line 164
        inline WString& operator= (const Char *c);
#line 450
        bool operator== (const WString& s) const;
#line 457
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 447
        const Char *Begin() const;
#line 195
        WString& Cat(Char i);
#line 189
        WString& Cat(Char c, int count);
#line 240
        WString& Cat(const WString& str);
#line 489
        inline WString CharoString() const;
#line 105
        void Clear();
#line 448
        inline const Char *End() const;
#line 324
        int Find(const WString& str, int pos = 0) const;
#line 351
        int FindFirstNotOf(const Char *str) const;
#line 322
        inline int GetCount() const;
#line 491
        Lang::uint32 GetHashValue() const;
#line 429
        bool Insert(int begin, const Char *str, int n);
#line 323
        inline bool IsEmpty() const;
#line 406
        inline WString Left(int i) const;
#line 399
        WString Mid(int i) const;
        WString Mid(int i, int size) const;
#line 409
        void Remove(int begin, int count);
#line 283
        void Replace(const WString& s, const WString& value);
#line 292
        void Replace(int i, int len, const WString& value);
#line 338
        inline int ReverseFind(const WString& str) const;
        int ReverseFind(const WString& str, int pos) const;
#line 375
        int ReverseFindFirstNotOf(const Char *str) const;
#line 407
        inline WString Right(int i) const;
#line 111
        void Serialize(Abstract::StreamBase& s);
#line 145
        WString& Set(const Char *c, int len, bool find_end = true);
        
#line 93
        void Zero();
        
    public:
#line 567
        static double CharDbl(const Char *s);
#line 513
        static int CharHexInt(const Char *s);
#line 528
        static int CharInt(const Char *s);
#line 541
        static Lang::int64 CharInt64(const Char *s);
#line 554
        static Lang::uint64 CharIntU64(const Char *s);
#line 499
        static int CharOctInt(const Char *s);
#line 693
        static int Compare(const Char *a, const Char *b);
#line 704
        static int Compare(const Char *a, const Char *b, int len);
#line 716
        static void Copy(Char *dst, const Char *src);
#line 483
        static WString DblStr(double d);
#line 724
        inline static ConstChar *Empty();
#line 466
        inline static int HexInt(const WString& s);
#line 617
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 635
        static const Char *IntChar64(Char *p, int bufsize, Lang::int64 x);
#line 653
        static const Char *IntCharU64(Char *p, int bufsize, Lang::uint64 x);
#line 471
        static WString IntStr(int i);
#line 477
        static WString IntStr64(Lang::int64 i);
#line 672
        static int Length(const Char *c, int max_len = - 1);
#line 465
        inline static int OctInt(const WString& s);
#line 469
        inline static double StrDbl(const WString& s);
#line 467
        inline static int StrInt(const WString& s);
        inline static Lang::int64 StrInt64(const WString& s);
        
        class RefData
        {
#line 32
            Char *data;
            int reserved;
#line 94 "../../src/Com/Meta.fog"
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
#line 97 "../../src/Com/Meta.fog"
            void Dec();
#line 73 "../../src/Com/Text.fog"
            ConstChar *Get() const;
#line 95 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 77 "../../src/Com/Text.fog"
            int GetReserved() const;
#line 96 "../../src/Com/Meta.fog"
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
#line 797
    inline String Capitalize(const String& s)
    {
#line 798
        return ToUpper(s.Left(1)) + s.Mid(1);
    };
    
#line 850
    inline void FromString(const String& s, Lang::byte& o)
    {
#line 850
        o = Text::String::StrInt(s);
    };
    
#line 849
    inline void FromString(const String& s, Lang::int64& o)
    {
#line 849
        o = Text::String::StrInt64(s);
    };
    
#line 848
    inline void FromString(const String& s, Lang::uint32& o)
    {
#line 848
        o = Text::String::StrInt64(s);
    };
    
#line 854
    inline void FromString(const String& s, String& o)
    {
#line 854
        o = s;
    };
    
#line 845
    template < class _1 >
    inline void FromString(const String& s, _1& o)
    {
#line 845
        o.FromString(s);
    };
    
#line 846
    inline void FromString(const String& s, bool& o)
    {
#line 846
        o = (ToLower(s) != "false" && s != "0" && s.GetCount());
    };
    
#line 851
    inline void FromString(const String& s, char& o)
    {
#line 851
        o = Text::String::StrInt(s);
    };
    
#line 853
    inline void FromString(const String& s, double& o)
    {
#line 853
        o = Text::String::StrDbl(s);
    };
    
#line 852
    inline void FromString(const String& s, float& o)
    {
#line 852
        o = Text::String::StrDbl(s);
    };
    
#line 847
    inline void FromString(const String& s, int& o)
    {
#line 847
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
    
#line 866
    inline int HexDigit(int c)
    {
#line 866
        return "0123456789ABCDEF"[c & 15];
    };
    
#line 867
    inline int HexDigitLower(int c)
    {
#line 867
        return "0123456789abcdef"[c & 15];
    };
    
#line 868
    inline String HexStr(Lang::uint64 p)
    {
#line 869
        String o("0x");
        bool zero = true;
        Lang::uint64 i = 64;
        do
            {
#line 873
                i -= 4;
                Lang::byte b = (p >> i) & 15ULL;
                if (b || !zero)
                {
#line 876
                    zero = false;
                    o.Cat(HexDigit(b));
                }
            }while (i);
#line 881
        if (zero)
#line 881
            o.Cat('0');
        return o;
    };
    
#line 884
    inline String HexStr(void *p)
    {
#line 884
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
    
#line 856
    template < class _1 >
    inline Lang::int64 ToInt(const _1& o)
    {
#line 856
        return o.AsInt();
    };
    
#line 860
    template <>
    inline Lang::int64 ToInt < Lang::byte > (const Lang::byte& o)
    {
#line 860
        return(Lang::int64) o;
    };
    
#line 859
    template <>
    inline Lang::int64 ToInt < Lang::int64 > (const Lang::int64& o)
    {
#line 859
        return(Lang::int64) o;
    };
    
#line 864
    template <>
    inline Lang::int64 ToInt < String > (const String& o)
    {
#line 864
        return Text::String::StrInt(o);
    };
    
#line 857
    template <>
    inline Lang::int64 ToInt < bool > (const bool& o)
    {
#line 857
        return(Lang::int64) o;
    };
    
#line 861
    template <>
    inline Lang::int64 ToInt < char > (const char& o)
    {
#line 861
        return(Lang::int64) o;
    };
    
#line 863
    template <>
    inline Lang::int64 ToInt < double > (const double& o)
    {
#line 863
        return(Lang::int64) o;
    };
    
#line 862
    template <>
    inline Lang::int64 ToInt < float > (const float& o)
    {
#line 862
        return(Lang::int64) o;
    };
    
#line 858
    template <>
    inline Lang::int64 ToInt < int > (const int& o)
    {
#line 858
        return(Lang::int64) o;
    };
    
#line 830
    template < class _1 >
    inline String ToString(const _1& o)
    {
#line 830
        return o.AsString();
    };
    
#line 835
    template <>
    inline String ToString < Lang::byte > (const Lang::byte& o)
    {
#line 835
        return Text::String::IntStr(o);
    };
    
#line 834
    template <>
    inline String ToString < Lang::int64 > (const Lang::int64& o)
    {
#line 834
        return Text::String::IntStr64(o);
    };
    
#line 833
    template <>
    inline String ToString < Lang::uint32 > (const Lang::uint32& o)
    {
#line 833
        return Text::String::IntStr64(o);
    };
    
#line 839
    template <>
    inline String ToString < String > (const String& o)
    {
#line 839
        return o;
    };
    
    template <>
    inline String ToString < WString > (const WString& o)
    {
#line 842
        return Native::Utf16To8(o.Begin());
    };
    
#line 831
    template <>
    inline String ToString < bool > (const bool& o)
    {
#line 831
        if (o)
#line 831
            return "true";
        else
#line 831
            return "false";
    };
    
#line 836
    template <>
    inline String ToString < char > (const char& o)
    {
#line 836
        String s;
#line 836
        s.Cat(o);
#line 836
        return s;
    };
    
#line 838
    template <>
    inline String ToString < double > (const double& o)
    {
#line 838
        return Text::String::DblStr(o);
    };
    
#line 837
    template <>
    inline String ToString < float > (const float& o)
    {
#line 837
        return Text::String::DblStr(o);
    };
    
#line 832
    template <>
    inline String ToString < int > (const int& o)
    {
#line 832
        return Text::String::IntStr(o);
    };
    
#line 841
    template < class _1 >
    inline WString ToWString(const _1& o)
    {
#line 841
        return o.ToWString();
    };
    
#line 843
    template <>
    inline WString ToWString < String > (const String& o)
    {
#line 843
        return Native::Utf8To16(o.Begin());
    };
    
#line 744
    inline Exc::Exc() {};
    
#line 745
    inline Exc::Exc(const String& s)
    :
        String(s)
    {};
    
#line 455
    inline bool String::operator!= (const String& s) const
    {
#line 455
        return !(*this == s);
    };
    
#line 460
    inline String& String::operator+= (const String& s)
    {
#line 460
        Cat(s);
#line 460
        return *this;
    };
    
#line 461
    inline String& String::operator<< (const String& s)
    {
#line 461
        Cat(s);
#line 461
        return *this;
    };
    
#line 462
    inline String& String::operator<< (int i)
    {
#line 462
        Cat(IntStr(i));
#line 462
        return *this;
    };
    
#line 164
    inline String& String::operator= (const Char *c)
    {
#line 164
        return Set(c, Lang::StringLength(c));
    };
    
#line 457
    inline String::Char String::operator[](int i) const
    {
#line 457
        return At(i);
    };
    
#line 489
    inline String String::CharoString() const
    {
#line 489
        return *this;
    };
    
#line 724
    inline String::ConstChar *String::Empty()
    {
#line 725
        static Char buf[1] = 
        {
            0
        };
#line 726
        return buf;
    };
    
#line 448
    inline const String::Char *String::End() const
    {
#line 448
        return Begin() + GetCount();
    };
    
#line 322
    inline int String::GetCount() const
    {
#line 322
        return count;
    };
    
#line 466
    inline int String::HexInt(const String& s)
    {
#line 466
        return CharHexInt(s.Begin());
    };
    
#line 323
    inline bool String::IsEmpty() const
    {
#line 323
        return count == 0;
    };
    
#line 406
    inline String String::Left(int i) const
    {
#line 406
        return Mid(0, i);
    };
    
#line 465
    inline int String::OctInt(const String& s)
    {
#line 465
        return CharOctInt(s.Begin());
    };
    
#line 338
    inline int String::ReverseFind(const String& str) const
    {
#line 338
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 407
    inline String String::Right(int i) const
    {
#line 407
        return Mid(GetCount() - i, i);
    };
    
#line 469
    inline double String::StrDbl(const String& s)
    {
#line 469
        return CharDbl(s.Begin());
    };
    
#line 467
    inline int String::StrInt(const String& s)
    {
#line 467
        return CharInt(s.Begin());
    };
    
#line 468
    inline Lang::int64 String::StrInt64(const String& s)
    {
#line 468
        return CharInt64(s.Begin());
    };
    
#line 455
    inline bool WString::operator!= (const WString& s) const
    {
#line 455
        return !(*this == s);
    };
    
#line 460
    inline WString& WString::operator+= (const WString& s)
    {
#line 460
        Cat(s);
#line 460
        return *this;
    };
    
#line 461
    inline WString& WString::operator<< (const WString& s)
    {
#line 461
        Cat(s);
#line 461
        return *this;
    };
    
#line 462
    inline WString& WString::operator<< (int i)
    {
#line 462
        Cat(IntStr(i));
#line 462
        return *this;
    };
    
#line 164
    inline WString& WString::operator= (const Char *c)
    {
#line 164
        return Set(c, Lang::StringLength(c));
    };
    
#line 457
    inline WString::Char WString::operator[](int i) const
    {
#line 457
        return At(i);
    };
    
#line 489
    inline WString WString::CharoString() const
    {
#line 489
        return *this;
    };
    
#line 724
    inline WString::ConstChar *WString::Empty()
    {
#line 725
        static Char buf[1] = 
        {
            0
        };
#line 726
        return buf;
    };
    
#line 448
    inline const WString::Char *WString::End() const
    {
#line 448
        return Begin() + GetCount();
    };
    
#line 322
    inline int WString::GetCount() const
    {
#line 322
        return count;
    };
    
#line 466
    inline int WString::HexInt(const WString& s)
    {
#line 466
        return CharHexInt(s.Begin());
    };
    
#line 323
    inline bool WString::IsEmpty() const
    {
#line 323
        return count == 0;
    };
    
#line 406
    inline WString WString::Left(int i) const
    {
#line 406
        return Mid(0, i);
    };
    
#line 465
    inline int WString::OctInt(const WString& s)
    {
#line 465
        return CharOctInt(s.Begin());
    };
    
#line 338
    inline int WString::ReverseFind(const WString& str) const
    {
#line 338
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 407
    inline WString WString::Right(int i) const
    {
#line 407
        return Mid(GetCount() - i, i);
    };
    
#line 469
    inline double WString::StrDbl(const WString& s)
    {
#line 469
        return CharDbl(s.Begin());
    };
    
#line 467
    inline int WString::StrInt(const WString& s)
    {
#line 467
        return CharInt(s.Begin());
    };
    
#line 468
    inline Lang::int64 WString::StrInt64(const WString& s)
    {
#line 468
        return CharInt64(s.Begin());
    };
    
};

#endif
