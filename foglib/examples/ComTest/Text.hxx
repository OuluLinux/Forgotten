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
#line 809 "../../src/Com/Text.fog"
    inline String Capitalize(const String& s);
#line 968
    String CharToUTF8(Lang::uint16 chr);
#line 958
    String EscapeCharacter(String s);
#line 949
    String EscapeString(String s);
#line 864
    inline void FromString(const String& s, Lang::byte& o);
#line 863
    inline void FromString(const String& s, Lang::int64& o);
#line 862
    inline void FromString(const String& s, Lang::uint32& o);
#line 868
    inline void FromString(const String& s, String& o);
#line 859
    template < class _1 >
    inline void FromString(const String& s, _1& o);
#line 860
    inline void FromString(const String& s, bool& o);
#line 865
    inline void FromString(const String& s, char& o);
#line 867
    inline void FromString(const String& s, double& o);
#line 866
    inline void FromString(const String& s, float& o);
#line 861
    inline void FromString(const String& s, int& o);
#line 11
    inline int GetBinDigit(char c);
    inline int GetHexDigit(char c);
#line 880
    inline int HexDigit(int c);
    inline int HexDigitLower(int c);
    inline String HexStr(Lang::uint64 p);
#line 898
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
#line 870
    template < class _1 >
    inline Lang::int64 ToInt(const _1& o);
#line 874
    template <>
    inline Lang::int64 ToInt < Lang::byte > (const Lang::byte& o);
#line 873
    template <>
    inline Lang::int64 ToInt < Lang::int64 > (const Lang::int64& o);
#line 878
    template <>
    inline Lang::int64 ToInt < String > (const String& o);
#line 871
    template <>
    inline Lang::int64 ToInt < bool > (const bool& o);
#line 875
    template <>
    inline Lang::int64 ToInt < char > (const char& o);
    template <>
    inline Lang::int64 ToInt < double > (const double& o);
#line 876
    template <>
    inline Lang::int64 ToInt < float > (const float& o);
#line 872
    template <>
    inline Lang::int64 ToInt < int > (const int& o);
#line 795
    String ToLower(const String& s);
#line 775
    int ToLowerChar(int chr);
#line 844
    template < class _1 >
    inline String ToString(const _1& o);
#line 849
    template <>
    inline String ToString < Lang::byte > (const Lang::byte& o);
#line 848
    template <>
    inline String ToString < Lang::int64 > (const Lang::int64& o);
#line 847
    template <>
    inline String ToString < Lang::uint32 > (const Lang::uint32& o);
#line 853
    template <>
    inline String ToString < String > (const String& o);
};

namespace Text {
class WString;
}

namespace Text
{
#line 856
    template <>
    inline String ToString < WString > (const WString& o);
#line 845
    template <>
    inline String ToString < bool > (const bool& o);
#line 850
    template <>
    inline String ToString < char > (const char& o);
    template <>
    inline String ToString < double > (const double& o);
#line 851
    template <>
    inline String ToString < float > (const float& o);
#line 846
    template <>
    inline String ToString < int > (const int& o);
#line 781
    String ToUpper(const String& s);
#line 769
    int ToUpperChar(int chr);
#line 855
    template < class _1 >
    inline WString ToWString(const _1& o);
    template <>
    inline WString ToWString < String > (const String& o);
#line 827
    String TrimBoth(String s);
#line 901
    void UnescapeNumbers(String& s);
#line 940
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
#line 461
        inline bool operator!= (const String& s) const;
#line 469
        String operator+ (const String& s);
#line 189
        String operator+ (const String& l) const;
#line 466
        inline String& operator+= (const String& s);
        inline String& operator<< (const String& s);
        inline String& operator<< (int i);
#line 171
        String& operator= (const String& str);
#line 170
        inline String& operator= (const Char *c);
#line 456
        bool operator== (const String& s) const;
#line 463
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 453
        const Char *Begin() const;
#line 107
        inline String& Cat();
#line 201
        String& Cat(Char i);
#line 195
        String& Cat(Char c, int count);
#line 246
        String& Cat(const String& str);
#line 496
        inline String CharoString() const;
#line 109
        void Clear();
#line 454
        inline const Char *End() const;
#line 330
        int Find(const String& str, int pos = 0) const;
#line 357
        int FindFirstNotOf(const Char *str) const;
#line 328
        inline int GetCount() const;
#line 498
        Lang::uint32 GetHashValue() const;
#line 435
        bool Insert(int begin, const Char *str, int n);
#line 329
        inline bool IsEmpty() const;
#line 149
        inline bool IsThisNull() const;
#line 412
        inline String Left(int i) const;
#line 405
        String Mid(int i) const;
        String Mid(int i, int size) const;
#line 415
        void Remove(int begin, int count);
#line 289
        void Replace(const String& s, const String& value);
#line 298
        void Replace(int i, int len, const String& value);
#line 344
        inline int ReverseFind(const String& str) const;
        int ReverseFind(const String& str, int pos) const;
#line 381
        int ReverseFindFirstNotOf(const Char *str) const;
#line 413
        inline String Right(int i) const;
#line 115
        void Serialize(Abstract::StreamBase& s);
#line 151
        String& Set(const Char *c, int len, bool find_end = true);
        
#line 95
        void Zero();
        
    public:
#line 471
        inline static int BinInt(const String& s);
#line 520
        static int CharBinInt(const Char *s);
#line 589
        static double CharDbl(const Char *s);
#line 535
        static int CharHexInt(const Char *s);
#line 550
        static int CharInt(const Char *s);
#line 563
        static Lang::int64 CharInt64(const Char *s);
#line 576
        static Lang::uint64 CharIntU64(const Char *s);
#line 506
        static int CharOctInt(const Char *s);
#line 715
        static int Compare(const Char *a, const Char *b);
#line 726
        static int Compare(const Char *a, const Char *b, int len);
#line 738
        static void Copy(Char *dst, const Char *src);
#line 490
        static String DblStr(double d);
#line 746
        inline static ConstChar *Empty();
#line 473
        inline static int HexInt(const String& s);
#line 639
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 657
        static const Char *IntChar64(Char *p, int bufsize, Lang::int64 x);
#line 675
        static const Char *IntCharU64(Char *p, int bufsize, Lang::uint64 x);
#line 478
        static String IntStr(int i);
#line 484
        static String IntStr64(Lang::int64 i);
#line 694
        static int Length(const Char *c, int max_len = - 1);
#line 472
        inline static int OctInt(const String& s);
#line 476
        inline static double StrDbl(const String& s);
#line 474
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
#line 461
        inline bool operator!= (const WString& s) const;
#line 469
        WString operator+ (const WString& s);
#line 189
        WString operator+ (const WString& l) const;
#line 466
        inline WString& operator+= (const WString& s);
        inline WString& operator<< (const WString& s);
        inline WString& operator<< (int i);
#line 171
        WString& operator= (const WString& str);
#line 170
        inline WString& operator= (const Char *c);
#line 456
        bool operator== (const WString& s) const;
#line 463
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 453
        const Char *Begin() const;
#line 107
        inline WString& Cat();
#line 201
        WString& Cat(Char i);
#line 195
        WString& Cat(Char c, int count);
#line 246
        WString& Cat(const WString& str);
#line 496
        inline WString CharoString() const;
#line 109
        void Clear();
#line 454
        inline const Char *End() const;
#line 330
        int Find(const WString& str, int pos = 0) const;
#line 357
        int FindFirstNotOf(const Char *str) const;
#line 328
        inline int GetCount() const;
#line 498
        Lang::uint32 GetHashValue() const;
#line 435
        bool Insert(int begin, const Char *str, int n);
#line 329
        inline bool IsEmpty() const;
#line 149
        inline bool IsThisNull() const;
#line 412
        inline WString Left(int i) const;
#line 405
        WString Mid(int i) const;
        WString Mid(int i, int size) const;
#line 415
        void Remove(int begin, int count);
#line 289
        void Replace(const WString& s, const WString& value);
#line 298
        void Replace(int i, int len, const WString& value);
#line 344
        inline int ReverseFind(const WString& str) const;
        int ReverseFind(const WString& str, int pos) const;
#line 381
        int ReverseFindFirstNotOf(const Char *str) const;
#line 413
        inline WString Right(int i) const;
#line 115
        void Serialize(Abstract::StreamBase& s);
#line 151
        WString& Set(const Char *c, int len, bool find_end = true);
        
#line 95
        void Zero();
        
    public:
#line 471
        inline static int BinInt(const WString& s);
#line 520
        static int CharBinInt(const Char *s);
#line 589
        static double CharDbl(const Char *s);
#line 535
        static int CharHexInt(const Char *s);
#line 550
        static int CharInt(const Char *s);
#line 563
        static Lang::int64 CharInt64(const Char *s);
#line 576
        static Lang::uint64 CharIntU64(const Char *s);
#line 506
        static int CharOctInt(const Char *s);
#line 715
        static int Compare(const Char *a, const Char *b);
#line 726
        static int Compare(const Char *a, const Char *b, int len);
#line 738
        static void Copy(Char *dst, const Char *src);
#line 490
        static WString DblStr(double d);
#line 746
        inline static ConstChar *Empty();
#line 473
        inline static int HexInt(const WString& s);
#line 639
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 657
        static const Char *IntChar64(Char *p, int bufsize, Lang::int64 x);
#line 675
        static const Char *IntCharU64(Char *p, int bufsize, Lang::uint64 x);
#line 478
        static WString IntStr(int i);
#line 484
        static WString IntStr64(Lang::int64 i);
#line 694
        static int Length(const Char *c, int max_len = - 1);
#line 472
        inline static int OctInt(const WString& s);
#line 476
        inline static double StrDbl(const WString& s);
#line 474
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
#line 809
    inline String Capitalize(const String& s)
    {
#line 810
        return ToUpper(s.Left(1)) + s.Mid(1);
    };
    
#line 864
    inline void FromString(const String& s, Lang::byte& o)
    {
#line 864
        o = Text::String::StrInt(s);
    };
    
#line 863
    inline void FromString(const String& s, Lang::int64& o)
    {
#line 863
        o = Text::String::StrInt64(s);
    };
    
#line 862
    inline void FromString(const String& s, Lang::uint32& o)
    {
#line 862
        o = Text::String::StrInt64(s);
    };
    
#line 868
    inline void FromString(const String& s, String& o)
    {
#line 868
        o = s;
    };
    
#line 859
    template < class _1 >
    inline void FromString(const String& s, _1& o)
    {
#line 859
        o.FromString(s);
    };
    
#line 860
    inline void FromString(const String& s, bool& o)
    {
#line 860
        o = (ToLower(s) != "false" && s != "0" && s.GetCount());
    };
    
#line 865
    inline void FromString(const String& s, char& o)
    {
#line 865
        o = Text::String::StrInt(s);
    };
    
#line 867
    inline void FromString(const String& s, double& o)
    {
#line 867
        o = Text::String::StrDbl(s);
    };
    
#line 866
    inline void FromString(const String& s, float& o)
    {
#line 866
        o = Text::String::StrDbl(s);
    };
    
#line 861
    inline void FromString(const String& s, int& o)
    {
#line 861
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
    
#line 880
    inline int HexDigit(int c)
    {
#line 880
        return "0123456789ABCDEF"[c & 15];
    };
    
#line 881
    inline int HexDigitLower(int c)
    {
#line 881
        return "0123456789abcdef"[c & 15];
    };
    
#line 882
    inline String HexStr(Lang::uint64 p)
    {
#line 883
        String o("0x");
        bool zero = true;
        Lang::uint64 i = 64;
        do
            {
#line 887
                i -= 4;
                Lang::byte b = (p >> i) & 15ULL;
                if (b || !zero)
                {
#line 890
                    zero = false;
                    o.Cat(HexDigit(b));
                }
            }while (i);
#line 895
        if (zero)
#line 895
            o.Cat('0');
        return o;
    };
    
#line 898
    inline String HexStr(void *p)
    {
#line 898
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
    
#line 870
    template < class _1 >
    inline Lang::int64 ToInt(const _1& o)
    {
#line 870
        return o.AsInt();
    };
    
#line 874
    template <>
    inline Lang::int64 ToInt < Lang::byte > (const Lang::byte& o)
    {
#line 874
        return(Lang::int64) o;
    };
    
#line 873
    template <>
    inline Lang::int64 ToInt < Lang::int64 > (const Lang::int64& o)
    {
#line 873
        return(Lang::int64) o;
    };
    
#line 878
    template <>
    inline Lang::int64 ToInt < String > (const String& o)
    {
#line 878
        return Text::String::StrInt(o);
    };
    
#line 871
    template <>
    inline Lang::int64 ToInt < bool > (const bool& o)
    {
#line 871
        return(Lang::int64) o;
    };
    
#line 875
    template <>
    inline Lang::int64 ToInt < char > (const char& o)
    {
#line 875
        return(Lang::int64) o;
    };
    
#line 877
    template <>
    inline Lang::int64 ToInt < double > (const double& o)
    {
#line 877
        return(Lang::int64) o;
    };
    
#line 876
    template <>
    inline Lang::int64 ToInt < float > (const float& o)
    {
#line 876
        return(Lang::int64) o;
    };
    
#line 872
    template <>
    inline Lang::int64 ToInt < int > (const int& o)
    {
#line 872
        return(Lang::int64) o;
    };
    
#line 844
    template < class _1 >
    inline String ToString(const _1& o)
    {
#line 844
        return o.AsString();
    };
    
#line 849
    template <>
    inline String ToString < Lang::byte > (const Lang::byte& o)
    {
#line 849
        return Text::String::IntStr(o);
    };
    
#line 848
    template <>
    inline String ToString < Lang::int64 > (const Lang::int64& o)
    {
#line 848
        return Text::String::IntStr64(o);
    };
    
#line 847
    template <>
    inline String ToString < Lang::uint32 > (const Lang::uint32& o)
    {
#line 847
        return Text::String::IntStr64(o);
    };
    
#line 853
    template <>
    inline String ToString < String > (const String& o)
    {
#line 853
        return o;
    };
    
    template <>
    inline String ToString < WString > (const WString& o)
    {
#line 856
        return Native::Utf16To8(o.Begin());
    };
    
#line 845
    template <>
    inline String ToString < bool > (const bool& o)
    {
#line 845
        if (o)
#line 845
            return "true";
        else
#line 845
            return "false";
    };
    
#line 850
    template <>
    inline String ToString < char > (const char& o)
    {
#line 850
        String s;
#line 850
        s.Cat(o);
#line 850
        return s;
    };
    
#line 852
    template <>
    inline String ToString < double > (const double& o)
    {
#line 852
        return Text::String::DblStr(o);
    };
    
#line 851
    template <>
    inline String ToString < float > (const float& o)
    {
#line 851
        return Text::String::DblStr(o);
    };
    
#line 846
    template <>
    inline String ToString < int > (const int& o)
    {
#line 846
        return Text::String::IntStr(o);
    };
    
#line 855
    template < class _1 >
    inline WString ToWString(const _1& o)
    {
#line 855
        return o.ToWString();
    };
    
#line 857
    template <>
    inline WString ToWString < String > (const String& o)
    {
#line 857
        return Native::Utf8To16(o.Begin());
    };
    
#line 192 "../../src/Com/Meta.fog"
    inline Exc::Exc() {};
    
#line 193
    inline Exc::Exc(const Text::String& s)
    :
        String(s)
    {};
    
#line 461 "../../src/Com/Text.fog"
    inline bool String::operator!= (const String& s) const
    {
#line 461
        return !(*this == s);
    };
    
#line 466
    inline String& String::operator+= (const String& s)
    {
#line 466
        Cat(s);
#line 466
        return *this;
    };
    
#line 467
    inline String& String::operator<< (const String& s)
    {
#line 467
        Cat(s);
#line 467
        return *this;
    };
    
#line 468
    inline String& String::operator<< (int i)
    {
#line 468
        Cat(IntStr(i));
#line 468
        return *this;
    };
    
#line 170
    inline String& String::operator= (const Char *c)
    {
#line 170
        return Set(c, Lang::StringLength(c));
    };
    
#line 463
    inline String::Char String::operator[](int i) const
    {
#line 463
        return At(i);
    };
    
#line 471
    inline int String::BinInt(const String& s)
    {
#line 471
        return CharBinInt(s.Begin());
    };
    
#line 107
    inline String& String::Cat()
    {
#line 107
        return *this;
    };
    
#line 496
    inline String String::CharoString() const
    {
#line 496
        return *this;
    };
    
#line 746
    inline String::ConstChar *String::Empty()
    {
#line 747
        static Char buf[1] = 
        {
            0
        };
#line 748
        return buf;
    };
    
#line 454
    inline const String::Char *String::End() const
    {
#line 454
        return Begin() + GetCount();
    };
    
#line 328
    inline int String::GetCount() const
    {
#line 328
        return count;
    };
    
#line 473
    inline int String::HexInt(const String& s)
    {
#line 473
        return CharHexInt(s.Begin());
    };
    
#line 329
    inline bool String::IsEmpty() const
    {
#line 329
        return count == 0;
    };
    
#line 149
    inline bool String::IsThisNull() const
    {
#line 149
        return count == 0;
    };
    
#line 412
    inline String String::Left(int i) const
    {
#line 412
        return Mid(0, i);
    };
    
#line 472
    inline int String::OctInt(const String& s)
    {
#line 472
        return CharOctInt(s.Begin());
    };
    
#line 344
    inline int String::ReverseFind(const String& str) const
    {
#line 344
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 413
    inline String String::Right(int i) const
    {
#line 413
        return Mid(GetCount() - i, i);
    };
    
#line 476
    inline double String::StrDbl(const String& s)
    {
#line 476
        return CharDbl(s.Begin());
    };
    
#line 474
    inline int String::StrInt(const String& s)
    {
#line 474
        return CharInt(s.Begin());
    };
    
#line 475
    inline Lang::int64 String::StrInt64(const String& s)
    {
#line 475
        return CharInt64(s.Begin());
    };
    
#line 461
    inline bool WString::operator!= (const WString& s) const
    {
#line 461
        return !(*this == s);
    };
    
#line 466
    inline WString& WString::operator+= (const WString& s)
    {
#line 466
        Cat(s);
#line 466
        return *this;
    };
    
#line 467
    inline WString& WString::operator<< (const WString& s)
    {
#line 467
        Cat(s);
#line 467
        return *this;
    };
    
#line 468
    inline WString& WString::operator<< (int i)
    {
#line 468
        Cat(IntStr(i));
#line 468
        return *this;
    };
    
#line 170
    inline WString& WString::operator= (const Char *c)
    {
#line 170
        return Set(c, Lang::StringLength(c));
    };
    
#line 463
    inline WString::Char WString::operator[](int i) const
    {
#line 463
        return At(i);
    };
    
#line 471
    inline int WString::BinInt(const WString& s)
    {
#line 471
        return CharBinInt(s.Begin());
    };
    
#line 107
    inline WString& WString::Cat()
    {
#line 107
        return *this;
    };
    
#line 496
    inline WString WString::CharoString() const
    {
#line 496
        return *this;
    };
    
#line 746
    inline WString::ConstChar *WString::Empty()
    {
#line 747
        static Char buf[1] = 
        {
            0
        };
#line 748
        return buf;
    };
    
#line 454
    inline const WString::Char *WString::End() const
    {
#line 454
        return Begin() + GetCount();
    };
    
#line 328
    inline int WString::GetCount() const
    {
#line 328
        return count;
    };
    
#line 473
    inline int WString::HexInt(const WString& s)
    {
#line 473
        return CharHexInt(s.Begin());
    };
    
#line 329
    inline bool WString::IsEmpty() const
    {
#line 329
        return count == 0;
    };
    
#line 149
    inline bool WString::IsThisNull() const
    {
#line 149
        return count == 0;
    };
    
#line 412
    inline WString WString::Left(int i) const
    {
#line 412
        return Mid(0, i);
    };
    
#line 472
    inline int WString::OctInt(const WString& s)
    {
#line 472
        return CharOctInt(s.Begin());
    };
    
#line 344
    inline int WString::ReverseFind(const WString& str) const
    {
#line 344
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 413
    inline WString WString::Right(int i) const
    {
#line 413
        return Mid(GetCount() - i, i);
    };
    
#line 476
    inline double WString::StrDbl(const WString& s)
    {
#line 476
        return CharDbl(s.Begin());
    };
    
#line 474
    inline int WString::StrInt(const WString& s)
    {
#line 474
        return CharInt(s.Begin());
    };
    
#line 475
    inline Lang::int64 WString::StrInt64(const WString& s)
    {
#line 475
        return CharInt64(s.Begin());
    };
    
};

#endif
