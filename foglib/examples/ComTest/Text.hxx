#ifndef TEXT_HXX
#define TEXT_HXX

#include <new>

#ifndef PRIM_HXX
#include <Prim.hxx>
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
#line 807 "../../src/Com/Text.fog"
    inline String Capitalize(const String& s);
#line 966
    String CharToUTF8(Lang::uint16 chr);
#line 956
    String EscapeCharacter(String s);
#line 947
    String EscapeString(String s);
#line 862
    inline void FromString(const String& s, Lang::byte& o);
#line 861
    inline void FromString(const String& s, Lang::int64& o);
#line 860
    inline void FromString(const String& s, Lang::uint32& o);
#line 866
    inline void FromString(const String& s, String& o);
#line 857
    template < class _1 >
    inline void FromString(const String& s, _1& o);
#line 858
    inline void FromString(const String& s, bool& o);
#line 863
    inline void FromString(const String& s, char& o);
#line 865
    inline void FromString(const String& s, double& o);
#line 864
    inline void FromString(const String& s, float& o);
#line 859
    inline void FromString(const String& s, int& o);
#line 11
    inline int GetBinDigit(char c);
    inline int GetHexDigit(char c);
#line 878
    inline int HexDigit(int c);
    inline int HexDigitLower(int c);
    inline String HexStr(Lang::uint64 p);
#line 896
    inline String HexStr(void *p);
#line 10
    inline bool IsAlpha(char c);
#line 5
    inline bool IsBinDigit(char c);
#line 8
    inline bool IsDigit(char c);
#line 7
    inline bool IsHexDigit(char c);
#line 6
    inline bool IsOctDigit(char c);
#line 9
    inline bool IsSpace(char c);
#line 868
    template < class _1 >
    inline Lang::int64 ToInt(const _1& o);
#line 872
    template <>
    inline Lang::int64 ToInt < Lang::byte > (const Lang::byte& o);
#line 871
    template <>
    inline Lang::int64 ToInt < Lang::int64 > (const Lang::int64& o);
#line 876
    template <>
    inline Lang::int64 ToInt < String > (const String& o);
#line 869
    template <>
    inline Lang::int64 ToInt < bool > (const bool& o);
#line 873
    template <>
    inline Lang::int64 ToInt < char > (const char& o);
    template <>
    inline Lang::int64 ToInt < double > (const double& o);
#line 874
    template <>
    inline Lang::int64 ToInt < float > (const float& o);
#line 870
    template <>
    inline Lang::int64 ToInt < int > (const int& o);
#line 793
    String ToLower(const String& s);
#line 773
    int ToLowerChar(int chr);
#line 842
    template < class _1 >
    inline String ToString(const _1& o);
#line 847
    template <>
    inline String ToString < Lang::byte > (const Lang::byte& o);
#line 846
    template <>
    inline String ToString < Lang::int64 > (const Lang::int64& o);
#line 845
    template <>
    inline String ToString < Lang::uint32 > (const Lang::uint32& o);
#line 851
    template <>
    inline String ToString < String > (const String& o);
};

namespace Text {
class WString;
}

namespace Text
{
#line 854
    template <>
    inline String ToString < WString > (const WString& o);
#line 843
    template <>
    inline String ToString < bool > (const bool& o);
#line 848
    template <>
    inline String ToString < char > (const char& o);
    template <>
    inline String ToString < double > (const double& o);
#line 849
    template <>
    inline String ToString < float > (const float& o);
#line 844
    template <>
    inline String ToString < int > (const int& o);
#line 779
    String ToUpper(const String& s);
#line 767
    int ToUpperChar(int chr);
#line 853
    template < class _1 >
    inline WString ToWString(const _1& o);
    template <>
    inline WString ToWString < String > (const String& o);
#line 825
    String TrimBoth(String s);
#line 899
    void UnescapeNumbers(String& s);
#line 938
    String UnescapeString(String s);
    
    class String
    {
#line 30
        typedef char Char;
        typedef const char ConstChar;
        
#line 91
        bool is_ref;
        int count;
        
    public:
#line 100
        String();
#line 103
        String(const String& s);
#line 101
        String(const Char *c);
        String(const Char *c, int len);
#line 104
        ~String();
#line 459
        inline bool operator!= (const String& s) const;
#line 467
        String operator+ (const String& s);
#line 187
        String operator+ (const String& l) const;
#line 464
        inline String& operator+= (const String& s);
        inline String& operator<< (const String& s);
        inline String& operator<< (int i);
#line 169
        String& operator= (const String& str);
#line 168
        inline String& operator= (const Char *c);
#line 454
        bool operator== (const String& s) const;
#line 461
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 451
        const Char *Begin() const;
#line 107
        inline String& Cat();
#line 199
        String& Cat(Char i);
#line 193
        String& Cat(Char c, int count);
#line 244
        String& Cat(const String& str);
#line 494
        inline String CharoString() const;
#line 109
        void Clear();
#line 452
        inline const Char *End() const;
#line 328
        int Find(const String& str, int pos = 0) const;
#line 355
        int FindFirstNotOf(const Char *str) const;
#line 326
        inline int GetCount() const;
#line 496
        Lang::uint32 GetHashValue() const;
#line 433
        bool Insert(int begin, const Char *str, int n);
#line 327
        inline bool IsEmpty() const;
#line 410
        inline String Left(int i) const;
#line 403
        String Mid(int i) const;
        String Mid(int i, int size) const;
#line 413
        void Remove(int begin, int count);
#line 287
        void Replace(const String& s, const String& value);
#line 296
        void Replace(int i, int len, const String& value);
#line 342
        inline int ReverseFind(const String& str) const;
        int ReverseFind(const String& str, int pos) const;
#line 379
        int ReverseFindFirstNotOf(const Char *str) const;
#line 411
        inline String Right(int i) const;
#line 115
        void Serialize(Abstract::StreamBase& s);
#line 149
        String& Set(const Char *c, int len, bool find_end = true);
        
#line 95
        void Zero();
        
    public:
#line 469
        inline static int BinInt(const String& s);
#line 518
        static int CharBinInt(const Char *s);
#line 587
        static double CharDbl(const Char *s);
#line 533
        static int CharHexInt(const Char *s);
#line 548
        static int CharInt(const Char *s);
#line 561
        static Lang::int64 CharInt64(const Char *s);
#line 574
        static Lang::uint64 CharIntU64(const Char *s);
#line 504
        static int CharOctInt(const Char *s);
#line 713
        static int Compare(const Char *a, const Char *b);
#line 724
        static int Compare(const Char *a, const Char *b, int len);
#line 736
        static void Copy(Char *dst, const Char *src);
#line 488
        static String DblStr(double d);
#line 744
        inline static ConstChar *Empty();
#line 471
        inline static int HexInt(const String& s);
#line 637
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 655
        static const Char *IntChar64(Char *p, int bufsize, Lang::int64 x);
#line 673
        static const Char *IntCharU64(Char *p, int bufsize, Lang::uint64 x);
#line 476
        static String IntStr(int i);
#line 482
        static String IntStr64(Lang::int64 i);
#line 692
        static int Length(const Char *c, int max_len = - 1);
#line 470
        inline static int OctInt(const String& s);
#line 474
        inline static double StrDbl(const String& s);
#line 472
        inline static int StrInt(const String& s);
        inline static Lang::int64 StrInt64(const String& s);
        
        class RefData
        {
#line 34
            Char *data;
            int reserved;
#line 122 "../../src/Com/Meta.fog"
            Lang::AtomicInt refs;
            
        public:
#line 38 "../../src/Com/Text.fog"
            RefData();
            RefData(Char *str, int reserved);
            ~RefData();
#line 77
            operator ConstChar * () const;
#line 76
            Char *Begin();
#line 42
            void Clear();
#line 125 "../../src/Com/Meta.fog"
            void Dec();
#line 75 "../../src/Com/Text.fog"
            ConstChar *Get() const;
#line 123 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 79 "../../src/Com/Text.fog"
            int GetReserved() const;
#line 124 "../../src/Com/Meta.fog"
            void Inc();
#line 44 "../../src/Com/Text.fog"
            void IncreaseReserved();
#line 53
            void IncreaseReserved(int min_reserved);
#line 62
            void Reserve(int new_reserved);
        };
        
        union
        {
        public:
#line 88
            Char buf[8];
            RefData *ref[0];
        };
    };
    
    struct Exc : public Text::String
    {
#line 192 "../../src/Com/Meta.fog"
        inline Exc();
        inline Exc(const Text::String& s);
    };
    
    class WString
    {
#line 30 "../../src/Com/Text.fog"
        typedef short Char;
        typedef const short ConstChar;
        
#line 91
        bool is_ref;
        int count;
        
    public:
#line 100
        WString();
#line 103
        WString(const WString& s);
#line 101
        WString(const Char *c);
        WString(const Char *c, int len);
#line 104
        ~WString();
#line 459
        inline bool operator!= (const WString& s) const;
#line 467
        WString operator+ (const WString& s);
#line 187
        WString operator+ (const WString& l) const;
#line 464
        inline WString& operator+= (const WString& s);
        inline WString& operator<< (const WString& s);
        inline WString& operator<< (int i);
#line 169
        WString& operator= (const WString& str);
#line 168
        inline WString& operator= (const Char *c);
#line 454
        bool operator== (const WString& s) const;
#line 461
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 451
        const Char *Begin() const;
#line 107
        inline WString& Cat();
#line 199
        WString& Cat(Char i);
#line 193
        WString& Cat(Char c, int count);
#line 244
        WString& Cat(const WString& str);
#line 494
        inline WString CharoString() const;
#line 109
        void Clear();
#line 452
        inline const Char *End() const;
#line 328
        int Find(const WString& str, int pos = 0) const;
#line 355
        int FindFirstNotOf(const Char *str) const;
#line 326
        inline int GetCount() const;
#line 496
        Lang::uint32 GetHashValue() const;
#line 433
        bool Insert(int begin, const Char *str, int n);
#line 327
        inline bool IsEmpty() const;
#line 410
        inline WString Left(int i) const;
#line 403
        WString Mid(int i) const;
        WString Mid(int i, int size) const;
#line 413
        void Remove(int begin, int count);
#line 287
        void Replace(const WString& s, const WString& value);
#line 296
        void Replace(int i, int len, const WString& value);
#line 342
        inline int ReverseFind(const WString& str) const;
        int ReverseFind(const WString& str, int pos) const;
#line 379
        int ReverseFindFirstNotOf(const Char *str) const;
#line 411
        inline WString Right(int i) const;
#line 115
        void Serialize(Abstract::StreamBase& s);
#line 149
        WString& Set(const Char *c, int len, bool find_end = true);
        
#line 95
        void Zero();
        
    public:
#line 469
        inline static int BinInt(const WString& s);
#line 518
        static int CharBinInt(const Char *s);
#line 587
        static double CharDbl(const Char *s);
#line 533
        static int CharHexInt(const Char *s);
#line 548
        static int CharInt(const Char *s);
#line 561
        static Lang::int64 CharInt64(const Char *s);
#line 574
        static Lang::uint64 CharIntU64(const Char *s);
#line 504
        static int CharOctInt(const Char *s);
#line 713
        static int Compare(const Char *a, const Char *b);
#line 724
        static int Compare(const Char *a, const Char *b, int len);
#line 736
        static void Copy(Char *dst, const Char *src);
#line 488
        static WString DblStr(double d);
#line 744
        inline static ConstChar *Empty();
#line 471
        inline static int HexInt(const WString& s);
#line 637
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 655
        static const Char *IntChar64(Char *p, int bufsize, Lang::int64 x);
#line 673
        static const Char *IntCharU64(Char *p, int bufsize, Lang::uint64 x);
#line 476
        static WString IntStr(int i);
#line 482
        static WString IntStr64(Lang::int64 i);
#line 692
        static int Length(const Char *c, int max_len = - 1);
#line 470
        inline static int OctInt(const WString& s);
#line 474
        inline static double StrDbl(const WString& s);
#line 472
        inline static int StrInt(const WString& s);
        inline static Lang::int64 StrInt64(const WString& s);
        
        class RefData
        {
#line 34
            Char *data;
            int reserved;
#line 122 "../../src/Com/Meta.fog"
            Lang::AtomicInt refs;
            
        public:
#line 38 "../../src/Com/Text.fog"
            RefData();
            RefData(Char *str, int reserved);
            ~RefData();
#line 77
            operator ConstChar * () const;
#line 76
            Char *Begin();
#line 42
            void Clear();
#line 125 "../../src/Com/Meta.fog"
            void Dec();
#line 75 "../../src/Com/Text.fog"
            ConstChar *Get() const;
#line 123 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 79 "../../src/Com/Text.fog"
            int GetReserved() const;
#line 124 "../../src/Com/Meta.fog"
            void Inc();
#line 44 "../../src/Com/Text.fog"
            void IncreaseReserved();
#line 53
            void IncreaseReserved(int min_reserved);
#line 62
            void Reserve(int new_reserved);
        };
        
        union
        {
        public:
#line 88
            Char buf[8];
            RefData *ref[0];
        };
    };
};

namespace Text
{
#line 807
    inline String Capitalize(const String& s)
    {
#line 808
        return ToUpper(s.Left(1)) + s.Mid(1);
    };
    
#line 862
    inline void FromString(const String& s, Lang::byte& o)
    {
#line 862
        o = Text::String::StrInt(s);
    };
    
#line 861
    inline void FromString(const String& s, Lang::int64& o)
    {
#line 861
        o = Text::String::StrInt64(s);
    };
    
#line 860
    inline void FromString(const String& s, Lang::uint32& o)
    {
#line 860
        o = Text::String::StrInt64(s);
    };
    
#line 866
    inline void FromString(const String& s, String& o)
    {
#line 866
        o = s;
    };
    
#line 857
    template < class _1 >
    inline void FromString(const String& s, _1& o)
    {
#line 857
        o.FromString(s);
    };
    
#line 858
    inline void FromString(const String& s, bool& o)
    {
#line 858
        o = (ToLower(s) != "false" && s != "0" && s.GetCount());
    };
    
#line 863
    inline void FromString(const String& s, char& o)
    {
#line 863
        o = Text::String::StrInt(s);
    };
    
#line 865
    inline void FromString(const String& s, double& o)
    {
#line 865
        o = Text::String::StrDbl(s);
    };
    
#line 864
    inline void FromString(const String& s, float& o)
    {
#line 864
        o = Text::String::StrDbl(s);
    };
    
#line 859
    inline void FromString(const String& s, int& o)
    {
#line 859
        o = Text::String::StrInt(s);
    };
    
#line 11
    inline int GetBinDigit(char c)
    {
#line 11
        return c - '0';
    };
    
#line 12
    inline int GetHexDigit(char c)
    {
#line 13
        if (c >= '0' && c <= '9')
            return c - '0';
        if (c >= 'a' && c <= 'f')
            return 10 + c - 'a';
        if (c >= 'A' && c <= 'F')
            return 10 + c - 'A';
        return 0;
    };
    
#line 878
    inline int HexDigit(int c)
    {
#line 878
        return "0123456789ABCDEF"[c & 15];
    };
    
#line 879
    inline int HexDigitLower(int c)
    {
#line 879
        return "0123456789abcdef"[c & 15];
    };
    
#line 880
    inline String HexStr(Lang::uint64 p)
    {
#line 881
        String o("0x");
        bool zero = true;
        Lang::uint64 i = 64;
        do
            {
#line 885
                i -= 4;
                Lang::byte b = (p >> i) & 15ULL;
                if (b || !zero)
                {
#line 888
                    zero = false;
                    o.Cat(HexDigit(b));
                }
            }while (i);
#line 893
        if (zero)
#line 893
            o.Cat('0');
        return o;
    };
    
#line 896
    inline String HexStr(void *p)
    {
#line 896
        return HexStr((Lang::uint64) p);
    };
    
#line 10
    inline bool IsAlpha(char c)
    {
#line 10
        return(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    };
    
#line 5
    inline bool IsBinDigit(char c)
    {
#line 5
        return c >= '0' && c <= '1';
    };
    
    inline bool IsDigit(char c)
    {
#line 8
        return c >= '0' && c <= '9';
    };
    
#line 7
    inline bool IsHexDigit(char c)
    {
#line 7
        return(c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
    };
    
#line 6
    inline bool IsOctDigit(char c)
    {
#line 6
        return c >= '0' && c <= '7';
    };
    
    inline bool IsSpace(char c)
    {
#line 9
        return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    };
    
#line 868
    template < class _1 >
    inline Lang::int64 ToInt(const _1& o)
    {
#line 868
        return o.AsInt();
    };
    
#line 872
    template <>
    inline Lang::int64 ToInt < Lang::byte > (const Lang::byte& o)
    {
#line 872
        return(Lang::int64) o;
    };
    
#line 871
    template <>
    inline Lang::int64 ToInt < Lang::int64 > (const Lang::int64& o)
    {
#line 871
        return(Lang::int64) o;
    };
    
#line 876
    template <>
    inline Lang::int64 ToInt < String > (const String& o)
    {
#line 876
        return Text::String::StrInt(o);
    };
    
#line 869
    template <>
    inline Lang::int64 ToInt < bool > (const bool& o)
    {
#line 869
        return(Lang::int64) o;
    };
    
#line 873
    template <>
    inline Lang::int64 ToInt < char > (const char& o)
    {
#line 873
        return(Lang::int64) o;
    };
    
#line 875
    template <>
    inline Lang::int64 ToInt < double > (const double& o)
    {
#line 875
        return(Lang::int64) o;
    };
    
#line 874
    template <>
    inline Lang::int64 ToInt < float > (const float& o)
    {
#line 874
        return(Lang::int64) o;
    };
    
#line 870
    template <>
    inline Lang::int64 ToInt < int > (const int& o)
    {
#line 870
        return(Lang::int64) o;
    };
    
#line 842
    template < class _1 >
    inline String ToString(const _1& o)
    {
#line 842
        return o.AsString();
    };
    
#line 847
    template <>
    inline String ToString < Lang::byte > (const Lang::byte& o)
    {
#line 847
        return Text::String::IntStr(o);
    };
    
#line 846
    template <>
    inline String ToString < Lang::int64 > (const Lang::int64& o)
    {
#line 846
        return Text::String::IntStr64(o);
    };
    
#line 845
    template <>
    inline String ToString < Lang::uint32 > (const Lang::uint32& o)
    {
#line 845
        return Text::String::IntStr64(o);
    };
    
#line 851
    template <>
    inline String ToString < String > (const String& o)
    {
#line 851
        return o;
    };
    
    template <>
    inline String ToString < WString > (const WString& o)
    {
#line 854
        return Native::Utf16To8(o.Begin());
    };
    
#line 843
    template <>
    inline String ToString < bool > (const bool& o)
    {
#line 843
        if (o)
#line 843
            return "true";
        else
#line 843
            return "false";
    };
    
#line 848
    template <>
    inline String ToString < char > (const char& o)
    {
#line 848
        String s;
#line 848
        s.Cat(o);
#line 848
        return s;
    };
    
#line 850
    template <>
    inline String ToString < double > (const double& o)
    {
#line 850
        return Text::String::DblStr(o);
    };
    
#line 849
    template <>
    inline String ToString < float > (const float& o)
    {
#line 849
        return Text::String::DblStr(o);
    };
    
#line 844
    template <>
    inline String ToString < int > (const int& o)
    {
#line 844
        return Text::String::IntStr(o);
    };
    
#line 853
    template < class _1 >
    inline WString ToWString(const _1& o)
    {
#line 853
        return o.ToWString();
    };
    
#line 855
    template <>
    inline WString ToWString < String > (const String& o)
    {
#line 855
        return Native::Utf8To16(o.Begin());
    };
    
#line 192 "../../src/Com/Meta.fog"
    inline Exc::Exc() {};
    
#line 193
    inline Exc::Exc(const Text::String& s)
    :
        String(s)
    {};
    
#line 459 "../../src/Com/Text.fog"
    inline bool String::operator!= (const String& s) const
    {
#line 459
        return !(*this == s);
    };
    
#line 464
    inline String& String::operator+= (const String& s)
    {
#line 464
        Cat(s);
#line 464
        return *this;
    };
    
#line 465
    inline String& String::operator<< (const String& s)
    {
#line 465
        Cat(s);
#line 465
        return *this;
    };
    
#line 466
    inline String& String::operator<< (int i)
    {
#line 466
        Cat(IntStr(i));
#line 466
        return *this;
    };
    
#line 168
    inline String& String::operator= (const Char *c)
    {
#line 168
        return Set(c, Lang::StringLength(c));
    };
    
#line 461
    inline String::Char String::operator[](int i) const
    {
#line 461
        return At(i);
    };
    
#line 469
    inline int String::BinInt(const String& s)
    {
#line 469
        return CharBinInt(s.Begin());
    };
    
#line 107
    inline String& String::Cat()
    {
#line 107
        return *this;
    };
    
#line 494
    inline String String::CharoString() const
    {
#line 494
        return *this;
    };
    
#line 744
    inline String::ConstChar *String::Empty()
    {
#line 745
        static Char buf[1] = 
        {
            0
        };
#line 746
        return buf;
    };
    
#line 452
    inline const String::Char *String::End() const
    {
#line 452
        return Begin() + GetCount();
    };
    
#line 326
    inline int String::GetCount() const
    {
#line 326
        return count;
    };
    
#line 471
    inline int String::HexInt(const String& s)
    {
#line 471
        return CharHexInt(s.Begin());
    };
    
#line 327
    inline bool String::IsEmpty() const
    {
#line 327
        return count == 0;
    };
    
#line 410
    inline String String::Left(int i) const
    {
#line 410
        return Mid(0, i);
    };
    
#line 470
    inline int String::OctInt(const String& s)
    {
#line 470
        return CharOctInt(s.Begin());
    };
    
#line 342
    inline int String::ReverseFind(const String& str) const
    {
#line 342
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 411
    inline String String::Right(int i) const
    {
#line 411
        return Mid(GetCount() - i, i);
    };
    
#line 474
    inline double String::StrDbl(const String& s)
    {
#line 474
        return CharDbl(s.Begin());
    };
    
#line 472
    inline int String::StrInt(const String& s)
    {
#line 472
        return CharInt(s.Begin());
    };
    
#line 473
    inline Lang::int64 String::StrInt64(const String& s)
    {
#line 473
        return CharInt64(s.Begin());
    };
    
#line 459
    inline bool WString::operator!= (const WString& s) const
    {
#line 459
        return !(*this == s);
    };
    
#line 464
    inline WString& WString::operator+= (const WString& s)
    {
#line 464
        Cat(s);
#line 464
        return *this;
    };
    
#line 465
    inline WString& WString::operator<< (const WString& s)
    {
#line 465
        Cat(s);
#line 465
        return *this;
    };
    
#line 466
    inline WString& WString::operator<< (int i)
    {
#line 466
        Cat(IntStr(i));
#line 466
        return *this;
    };
    
#line 168
    inline WString& WString::operator= (const Char *c)
    {
#line 168
        return Set(c, Lang::StringLength(c));
    };
    
#line 461
    inline WString::Char WString::operator[](int i) const
    {
#line 461
        return At(i);
    };
    
#line 469
    inline int WString::BinInt(const WString& s)
    {
#line 469
        return CharBinInt(s.Begin());
    };
    
#line 107
    inline WString& WString::Cat()
    {
#line 107
        return *this;
    };
    
#line 494
    inline WString WString::CharoString() const
    {
#line 494
        return *this;
    };
    
#line 744
    inline WString::ConstChar *WString::Empty()
    {
#line 745
        static Char buf[1] = 
        {
            0
        };
#line 746
        return buf;
    };
    
#line 452
    inline const WString::Char *WString::End() const
    {
#line 452
        return Begin() + GetCount();
    };
    
#line 326
    inline int WString::GetCount() const
    {
#line 326
        return count;
    };
    
#line 471
    inline int WString::HexInt(const WString& s)
    {
#line 471
        return CharHexInt(s.Begin());
    };
    
#line 327
    inline bool WString::IsEmpty() const
    {
#line 327
        return count == 0;
    };
    
#line 410
    inline WString WString::Left(int i) const
    {
#line 410
        return Mid(0, i);
    };
    
#line 470
    inline int WString::OctInt(const WString& s)
    {
#line 470
        return CharOctInt(s.Begin());
    };
    
#line 342
    inline int WString::ReverseFind(const WString& str) const
    {
#line 342
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 411
    inline WString WString::Right(int i) const
    {
#line 411
        return Mid(GetCount() - i, i);
    };
    
#line 474
    inline double WString::StrDbl(const WString& s)
    {
#line 474
        return CharDbl(s.Begin());
    };
    
#line 472
    inline int WString::StrInt(const WString& s)
    {
#line 472
        return CharInt(s.Begin());
    };
    
#line 473
    inline Lang::int64 WString::StrInt64(const WString& s)
    {
#line 473
        return CharInt64(s.Begin());
    };
    
};

#endif
