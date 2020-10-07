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
#line 789 "../../src/Com/Text.fog"
    inline String Capitalize(const String& s);
#line 898
    String CharToUTF8(Lang::uint16 chr);
#line 888
    String EscapeCharacter(String s);
#line 879
    String EscapeString(String s);
#line 842
    inline void FromString(const String& s, Lang::byte& o);
#line 841
    inline void FromString(const String& s, Lang::int64& o);
#line 840
    inline void FromString(const String& s, Lang::uint32& o);
#line 846
    inline void FromString(const String& s, String& o);
#line 837
    template < class _1 >
    inline void FromString(const String& s, _1& o);
#line 838
    inline void FromString(const String& s, bool& o);
#line 843
    inline void FromString(const String& s, char& o);
#line 845
    inline void FromString(const String& s, double& o);
#line 844
    inline void FromString(const String& s, float& o);
#line 839
    inline void FromString(const String& s, int& o);
#line 10
    inline int GetHexDigit(char c);
#line 858
    inline int HexDigit(int c);
    inline int HexDigitLower(int c);
    inline String HexStr(Lang::uint64 p);
#line 876
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
#line 848
    template < class _1 >
    inline Lang::int64 ToInt(const _1& o);
#line 852
    template <>
    inline Lang::int64 ToInt < Lang::byte > (const Lang::byte& o);
#line 851
    template <>
    inline Lang::int64 ToInt < Lang::int64 > (const Lang::int64& o);
#line 856
    template <>
    inline Lang::int64 ToInt < String > (const String& o);
#line 849
    template <>
    inline Lang::int64 ToInt < bool > (const bool& o);
#line 853
    template <>
    inline Lang::int64 ToInt < char > (const char& o);
    template <>
    inline Lang::int64 ToInt < double > (const double& o);
#line 854
    template <>
    inline Lang::int64 ToInt < float > (const float& o);
#line 850
    template <>
    inline Lang::int64 ToInt < int > (const int& o);
#line 775
    String ToLower(const String& s);
#line 755
    int ToLowerChar(int chr);
#line 822
    template < class _1 >
    inline String ToString(const _1& o);
#line 827
    template <>
    inline String ToString < Lang::byte > (const Lang::byte& o);
#line 826
    template <>
    inline String ToString < Lang::int64 > (const Lang::int64& o);
#line 825
    template <>
    inline String ToString < Lang::uint32 > (const Lang::uint32& o);
#line 831
    template <>
    inline String ToString < String > (const String& o);
};

namespace Text {
class WString;
}

namespace Text
{
#line 834
    template <>
    inline String ToString < WString > (const WString& o);
#line 823
    template <>
    inline String ToString < bool > (const bool& o);
#line 828
    template <>
    inline String ToString < char > (const char& o);
    template <>
    inline String ToString < double > (const double& o);
#line 829
    template <>
    inline String ToString < float > (const float& o);
#line 824
    template <>
    inline String ToString < int > (const int& o);
#line 761
    String ToUpper(const String& s);
#line 749
    int ToUpperChar(int chr);
#line 833
    template < class _1 >
    inline WString ToWString(const _1& o);
    template <>
    inline WString ToWString < String > (const String& o);
#line 805
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
#line 457
        inline bool operator!= (const String& s) const;
#line 465
        String operator+ (const String& s);
#line 185
        String operator+ (const String& l) const;
#line 462
        inline String& operator+= (const String& s);
        inline String& operator<< (const String& s);
        inline String& operator<< (int i);
#line 167
        String& operator= (const String& str);
#line 166
        inline String& operator= (const Char *c);
#line 452
        bool operator== (const String& s) const;
#line 459
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 449
        const Char *Begin() const;
#line 105
        inline String& Cat();
#line 197
        String& Cat(Char i);
#line 191
        String& Cat(Char c, int count);
#line 242
        String& Cat(const String& str);
#line 491
        inline String CharoString() const;
#line 107
        void Clear();
#line 450
        inline const Char *End() const;
#line 326
        int Find(const String& str, int pos = 0) const;
#line 353
        int FindFirstNotOf(const Char *str) const;
#line 324
        inline int GetCount() const;
#line 493
        Lang::uint32 GetHashValue() const;
#line 431
        bool Insert(int begin, const Char *str, int n);
#line 325
        inline bool IsEmpty() const;
#line 408
        inline String Left(int i) const;
#line 401
        String Mid(int i) const;
        String Mid(int i, int size) const;
#line 411
        void Remove(int begin, int count);
#line 285
        void Replace(const String& s, const String& value);
#line 294
        void Replace(int i, int len, const String& value);
#line 340
        inline int ReverseFind(const String& str) const;
        int ReverseFind(const String& str, int pos) const;
#line 377
        int ReverseFindFirstNotOf(const Char *str) const;
#line 409
        inline String Right(int i) const;
#line 113
        void Serialize(Abstract::StreamBase& s);
#line 147
        String& Set(const Char *c, int len, bool find_end = true);
        
#line 93
        void Zero();
        
    public:
#line 569
        static double CharDbl(const Char *s);
#line 515
        static int CharHexInt(const Char *s);
#line 530
        static int CharInt(const Char *s);
#line 543
        static Lang::int64 CharInt64(const Char *s);
#line 556
        static Lang::uint64 CharIntU64(const Char *s);
#line 501
        static int CharOctInt(const Char *s);
#line 695
        static int Compare(const Char *a, const Char *b);
#line 706
        static int Compare(const Char *a, const Char *b, int len);
#line 718
        static void Copy(Char *dst, const Char *src);
#line 485
        static String DblStr(double d);
#line 726
        inline static ConstChar *Empty();
#line 468
        inline static int HexInt(const String& s);
#line 619
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 637
        static const Char *IntChar64(Char *p, int bufsize, Lang::int64 x);
#line 655
        static const Char *IntCharU64(Char *p, int bufsize, Lang::uint64 x);
#line 473
        static String IntStr(int i);
#line 479
        static String IntStr64(Lang::int64 i);
#line 674
        static int Length(const Char *c, int max_len = - 1);
#line 467
        inline static int OctInt(const String& s);
#line 471
        inline static double StrDbl(const String& s);
#line 469
        inline static int StrInt(const String& s);
        inline static Lang::int64 StrInt64(const String& s);
        
        class RefData
        {
#line 32
            Char *data;
            int reserved;
#line 122 "../../src/Com/Meta.fog"
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
#line 125 "../../src/Com/Meta.fog"
            void Dec();
#line 73 "../../src/Com/Text.fog"
            ConstChar *Get() const;
#line 123 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 77 "../../src/Com/Text.fog"
            int GetReserved() const;
#line 124 "../../src/Com/Meta.fog"
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
#line 192 "../../src/Com/Meta.fog"
        inline Exc();
        inline Exc(const Text::String& s);
    };
    
    class WString
    {
#line 28 "../../src/Com/Text.fog"
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
#line 457
        inline bool operator!= (const WString& s) const;
#line 465
        WString operator+ (const WString& s);
#line 185
        WString operator+ (const WString& l) const;
#line 462
        inline WString& operator+= (const WString& s);
        inline WString& operator<< (const WString& s);
        inline WString& operator<< (int i);
#line 167
        WString& operator= (const WString& str);
#line 166
        inline WString& operator= (const Char *c);
#line 452
        bool operator== (const WString& s) const;
#line 459
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 449
        const Char *Begin() const;
#line 105
        inline WString& Cat();
#line 197
        WString& Cat(Char i);
#line 191
        WString& Cat(Char c, int count);
#line 242
        WString& Cat(const WString& str);
#line 491
        inline WString CharoString() const;
#line 107
        void Clear();
#line 450
        inline const Char *End() const;
#line 326
        int Find(const WString& str, int pos = 0) const;
#line 353
        int FindFirstNotOf(const Char *str) const;
#line 324
        inline int GetCount() const;
#line 493
        Lang::uint32 GetHashValue() const;
#line 431
        bool Insert(int begin, const Char *str, int n);
#line 325
        inline bool IsEmpty() const;
#line 408
        inline WString Left(int i) const;
#line 401
        WString Mid(int i) const;
        WString Mid(int i, int size) const;
#line 411
        void Remove(int begin, int count);
#line 285
        void Replace(const WString& s, const WString& value);
#line 294
        void Replace(int i, int len, const WString& value);
#line 340
        inline int ReverseFind(const WString& str) const;
        int ReverseFind(const WString& str, int pos) const;
#line 377
        int ReverseFindFirstNotOf(const Char *str) const;
#line 409
        inline WString Right(int i) const;
#line 113
        void Serialize(Abstract::StreamBase& s);
#line 147
        WString& Set(const Char *c, int len, bool find_end = true);
        
#line 93
        void Zero();
        
    public:
#line 569
        static double CharDbl(const Char *s);
#line 515
        static int CharHexInt(const Char *s);
#line 530
        static int CharInt(const Char *s);
#line 543
        static Lang::int64 CharInt64(const Char *s);
#line 556
        static Lang::uint64 CharIntU64(const Char *s);
#line 501
        static int CharOctInt(const Char *s);
#line 695
        static int Compare(const Char *a, const Char *b);
#line 706
        static int Compare(const Char *a, const Char *b, int len);
#line 718
        static void Copy(Char *dst, const Char *src);
#line 485
        static WString DblStr(double d);
#line 726
        inline static ConstChar *Empty();
#line 468
        inline static int HexInt(const WString& s);
#line 619
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 637
        static const Char *IntChar64(Char *p, int bufsize, Lang::int64 x);
#line 655
        static const Char *IntCharU64(Char *p, int bufsize, Lang::uint64 x);
#line 473
        static WString IntStr(int i);
#line 479
        static WString IntStr64(Lang::int64 i);
#line 674
        static int Length(const Char *c, int max_len = - 1);
#line 467
        inline static int OctInt(const WString& s);
#line 471
        inline static double StrDbl(const WString& s);
#line 469
        inline static int StrInt(const WString& s);
        inline static Lang::int64 StrInt64(const WString& s);
        
        class RefData
        {
#line 32
            Char *data;
            int reserved;
#line 122 "../../src/Com/Meta.fog"
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
#line 125 "../../src/Com/Meta.fog"
            void Dec();
#line 73 "../../src/Com/Text.fog"
            ConstChar *Get() const;
#line 123 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 77 "../../src/Com/Text.fog"
            int GetReserved() const;
#line 124 "../../src/Com/Meta.fog"
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
#line 789
    inline String Capitalize(const String& s)
    {
#line 790
        return ToUpper(s.Left(1)) + s.Mid(1);
    };
    
#line 842
    inline void FromString(const String& s, Lang::byte& o)
    {
#line 842
        o = Text::String::StrInt(s);
    };
    
#line 841
    inline void FromString(const String& s, Lang::int64& o)
    {
#line 841
        o = Text::String::StrInt64(s);
    };
    
#line 840
    inline void FromString(const String& s, Lang::uint32& o)
    {
#line 840
        o = Text::String::StrInt64(s);
    };
    
#line 846
    inline void FromString(const String& s, String& o)
    {
#line 846
        o = s;
    };
    
#line 837
    template < class _1 >
    inline void FromString(const String& s, _1& o)
    {
#line 837
        o.FromString(s);
    };
    
#line 838
    inline void FromString(const String& s, bool& o)
    {
#line 838
        o = (ToLower(s) != "false" && s != "0" && s.GetCount());
    };
    
#line 843
    inline void FromString(const String& s, char& o)
    {
#line 843
        o = Text::String::StrInt(s);
    };
    
#line 845
    inline void FromString(const String& s, double& o)
    {
#line 845
        o = Text::String::StrDbl(s);
    };
    
#line 844
    inline void FromString(const String& s, float& o)
    {
#line 844
        o = Text::String::StrDbl(s);
    };
    
#line 839
    inline void FromString(const String& s, int& o)
    {
#line 839
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
    
#line 858
    inline int HexDigit(int c)
    {
#line 858
        return "0123456789ABCDEF"[c & 15];
    };
    
#line 859
    inline int HexDigitLower(int c)
    {
#line 859
        return "0123456789abcdef"[c & 15];
    };
    
#line 860
    inline String HexStr(Lang::uint64 p)
    {
#line 861
        String o("0x");
        bool zero = true;
        Lang::uint64 i = 64;
        do
            {
#line 865
                i -= 4;
                Lang::byte b = (p >> i) & 15ULL;
                if (b || !zero)
                {
#line 868
                    zero = false;
                    o.Cat(HexDigit(b));
                }
            }while (i);
#line 873
        if (zero)
#line 873
            o.Cat('0');
        return o;
    };
    
#line 876
    inline String HexStr(void *p)
    {
#line 876
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
    
#line 848
    template < class _1 >
    inline Lang::int64 ToInt(const _1& o)
    {
#line 848
        return o.AsInt();
    };
    
#line 852
    template <>
    inline Lang::int64 ToInt < Lang::byte > (const Lang::byte& o)
    {
#line 852
        return(Lang::int64) o;
    };
    
#line 851
    template <>
    inline Lang::int64 ToInt < Lang::int64 > (const Lang::int64& o)
    {
#line 851
        return(Lang::int64) o;
    };
    
#line 856
    template <>
    inline Lang::int64 ToInt < String > (const String& o)
    {
#line 856
        return Text::String::StrInt(o);
    };
    
#line 849
    template <>
    inline Lang::int64 ToInt < bool > (const bool& o)
    {
#line 849
        return(Lang::int64) o;
    };
    
#line 853
    template <>
    inline Lang::int64 ToInt < char > (const char& o)
    {
#line 853
        return(Lang::int64) o;
    };
    
#line 855
    template <>
    inline Lang::int64 ToInt < double > (const double& o)
    {
#line 855
        return(Lang::int64) o;
    };
    
#line 854
    template <>
    inline Lang::int64 ToInt < float > (const float& o)
    {
#line 854
        return(Lang::int64) o;
    };
    
#line 850
    template <>
    inline Lang::int64 ToInt < int > (const int& o)
    {
#line 850
        return(Lang::int64) o;
    };
    
#line 822
    template < class _1 >
    inline String ToString(const _1& o)
    {
#line 822
        return o.AsString();
    };
    
#line 827
    template <>
    inline String ToString < Lang::byte > (const Lang::byte& o)
    {
#line 827
        return Text::String::IntStr(o);
    };
    
#line 826
    template <>
    inline String ToString < Lang::int64 > (const Lang::int64& o)
    {
#line 826
        return Text::String::IntStr64(o);
    };
    
#line 825
    template <>
    inline String ToString < Lang::uint32 > (const Lang::uint32& o)
    {
#line 825
        return Text::String::IntStr64(o);
    };
    
#line 831
    template <>
    inline String ToString < String > (const String& o)
    {
#line 831
        return o;
    };
    
    template <>
    inline String ToString < WString > (const WString& o)
    {
#line 834
        return Native::Utf16To8(o.Begin());
    };
    
#line 823
    template <>
    inline String ToString < bool > (const bool& o)
    {
#line 823
        if (o)
#line 823
            return "true";
        else
#line 823
            return "false";
    };
    
#line 828
    template <>
    inline String ToString < char > (const char& o)
    {
#line 828
        String s;
#line 828
        s.Cat(o);
#line 828
        return s;
    };
    
#line 830
    template <>
    inline String ToString < double > (const double& o)
    {
#line 830
        return Text::String::DblStr(o);
    };
    
#line 829
    template <>
    inline String ToString < float > (const float& o)
    {
#line 829
        return Text::String::DblStr(o);
    };
    
#line 824
    template <>
    inline String ToString < int > (const int& o)
    {
#line 824
        return Text::String::IntStr(o);
    };
    
#line 833
    template < class _1 >
    inline WString ToWString(const _1& o)
    {
#line 833
        return o.ToWString();
    };
    
#line 835
    template <>
    inline WString ToWString < String > (const String& o)
    {
#line 835
        return Native::Utf8To16(o.Begin());
    };
    
#line 192 "../../src/Com/Meta.fog"
    inline Exc::Exc() {};
    
#line 193
    inline Exc::Exc(const Text::String& s)
    :
        String(s)
    {};
    
#line 457 "../../src/Com/Text.fog"
    inline bool String::operator!= (const String& s) const
    {
#line 457
        return !(*this == s);
    };
    
#line 462
    inline String& String::operator+= (const String& s)
    {
#line 462
        Cat(s);
#line 462
        return *this;
    };
    
#line 463
    inline String& String::operator<< (const String& s)
    {
#line 463
        Cat(s);
#line 463
        return *this;
    };
    
#line 464
    inline String& String::operator<< (int i)
    {
#line 464
        Cat(IntStr(i));
#line 464
        return *this;
    };
    
#line 166
    inline String& String::operator= (const Char *c)
    {
#line 166
        return Set(c, Lang::StringLength(c));
    };
    
#line 459
    inline String::Char String::operator[](int i) const
    {
#line 459
        return At(i);
    };
    
#line 105
    inline String& String::Cat()
    {
#line 105
        return *this;
    };
    
#line 491
    inline String String::CharoString() const
    {
#line 491
        return *this;
    };
    
#line 726
    inline String::ConstChar *String::Empty()
    {
#line 727
        static Char buf[1] = 
        {
            0
        };
#line 728
        return buf;
    };
    
#line 450
    inline const String::Char *String::End() const
    {
#line 450
        return Begin() + GetCount();
    };
    
#line 324
    inline int String::GetCount() const
    {
#line 324
        return count;
    };
    
#line 468
    inline int String::HexInt(const String& s)
    {
#line 468
        return CharHexInt(s.Begin());
    };
    
#line 325
    inline bool String::IsEmpty() const
    {
#line 325
        return count == 0;
    };
    
#line 408
    inline String String::Left(int i) const
    {
#line 408
        return Mid(0, i);
    };
    
#line 467
    inline int String::OctInt(const String& s)
    {
#line 467
        return CharOctInt(s.Begin());
    };
    
#line 340
    inline int String::ReverseFind(const String& str) const
    {
#line 340
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 409
    inline String String::Right(int i) const
    {
#line 409
        return Mid(GetCount() - i, i);
    };
    
#line 471
    inline double String::StrDbl(const String& s)
    {
#line 471
        return CharDbl(s.Begin());
    };
    
#line 469
    inline int String::StrInt(const String& s)
    {
#line 469
        return CharInt(s.Begin());
    };
    
#line 470
    inline Lang::int64 String::StrInt64(const String& s)
    {
#line 470
        return CharInt64(s.Begin());
    };
    
#line 457
    inline bool WString::operator!= (const WString& s) const
    {
#line 457
        return !(*this == s);
    };
    
#line 462
    inline WString& WString::operator+= (const WString& s)
    {
#line 462
        Cat(s);
#line 462
        return *this;
    };
    
#line 463
    inline WString& WString::operator<< (const WString& s)
    {
#line 463
        Cat(s);
#line 463
        return *this;
    };
    
#line 464
    inline WString& WString::operator<< (int i)
    {
#line 464
        Cat(IntStr(i));
#line 464
        return *this;
    };
    
#line 166
    inline WString& WString::operator= (const Char *c)
    {
#line 166
        return Set(c, Lang::StringLength(c));
    };
    
#line 459
    inline WString::Char WString::operator[](int i) const
    {
#line 459
        return At(i);
    };
    
#line 105
    inline WString& WString::Cat()
    {
#line 105
        return *this;
    };
    
#line 491
    inline WString WString::CharoString() const
    {
#line 491
        return *this;
    };
    
#line 726
    inline WString::ConstChar *WString::Empty()
    {
#line 727
        static Char buf[1] = 
        {
            0
        };
#line 728
        return buf;
    };
    
#line 450
    inline const WString::Char *WString::End() const
    {
#line 450
        return Begin() + GetCount();
    };
    
#line 324
    inline int WString::GetCount() const
    {
#line 324
        return count;
    };
    
#line 468
    inline int WString::HexInt(const WString& s)
    {
#line 468
        return CharHexInt(s.Begin());
    };
    
#line 325
    inline bool WString::IsEmpty() const
    {
#line 325
        return count == 0;
    };
    
#line 408
    inline WString WString::Left(int i) const
    {
#line 408
        return Mid(0, i);
    };
    
#line 467
    inline int WString::OctInt(const WString& s)
    {
#line 467
        return CharOctInt(s.Begin());
    };
    
#line 340
    inline int WString::ReverseFind(const WString& str) const
    {
#line 340
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 409
    inline WString WString::Right(int i) const
    {
#line 409
        return Mid(GetCount() - i, i);
    };
    
#line 471
    inline double WString::StrDbl(const WString& s)
    {
#line 471
        return CharDbl(s.Begin());
    };
    
#line 469
    inline int WString::StrInt(const WString& s)
    {
#line 469
        return CharInt(s.Begin());
    };
    
#line 470
    inline Lang::int64 WString::StrInt64(const WString& s)
    {
#line 470
        return CharInt64(s.Begin());
    };
    
};

#endif
