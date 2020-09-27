/*!$@FOG@$!
 *	Generated at Sun Sep 27 07:48:06 2020
 *
 *	by fog 0.1.a of 08:09:34 Sep 23 2020
 *
 *	from
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Concurrency.fog
 *		../../src/Com/Defs.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Math.fog
 *		../../src/Com/Meta.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/Stream.fog
 *		../../src/Com/String.fog
 *		/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog
 */

#ifndef COM_HXX
#define COM_HXX

#ifndef C_HXX
#include <C.hxx>
#endif

struct ComInterfaceLinker
{
};

struct Console
{
#line 7 "../../src/Com/Stream.fog"
    static int Get(char *buf, int size);
    static void Put(const char *msg);
};

namespace Com
{
#line 47 "../../src/Com/Defs.fog"
    extern C::Nuller Null;
};

namespace Com
{
#line 61
    typedef unsigned char Byte;
    
#line 62
    extern Byte ____unused_Byte;
};

namespace Com
{
#line 66
    typedef C::Ptr < const char > CString;
    
#line 67
    extern CString ____unused_CString;
};

namespace Com
{
#line 66
    typedef C::Ptr < const void > ConstVoidPtr;
    
#line 67
    extern ConstVoidPtr ____unused_ConstVoidPtr;
};

namespace Com
{
#line 61
    typedef unsigned long DWORD;
    
#line 62
    extern DWORD ____unused_DWORD;
};

namespace Com
{
#line 66
    typedef C::Ptr < void > VoidPtr;
    
#line 67
    extern VoidPtr ____unused_VoidPtr;
};

namespace Com
{
#line 61
    typedef unsigned char byte;
    
#line 62
    extern byte ____unused_byte;
};

namespace Com
{
#line 61
    typedef unsigned int uint32;
#line 61
    typedef uint32 dword;
    
#line 62
    extern dword ____unused_dword;
};

namespace Com
{
#line 61
    typedef short int16;
    
#line 62
    extern int16 ____unused_int16;
};

namespace Com
{
#line 61
    typedef int int32;
    
#line 62
    extern int32 ____unused_int32;
};

namespace Com
{
#line 61
    typedef long long int64;
    
#line 62
    extern int64 ____unused_int64;
};

namespace Com
{
#line 61
    typedef char int8;
    
#line 62
    extern int8 ____unused_int8;
};

namespace Com
{
#line 61
    typedef unsigned long long uint64;
#line 61
    typedef uint64 qword;
    
#line 62
    extern qword ____unused_qword;
};

namespace Com
{
#line 61
    typedef unsigned short uint16;
    
#line 62
    extern uint16 ____unused_uint16;
#line 62
    extern uint32 ____unused_uint32;
#line 62
    extern uint64 ____unused_uint64;
};

namespace Com
{
#line 61
    typedef uint16 word;
    
#line 62
    extern word ____unused_word;
    
#line 131
    void Break(const char *msg);
#line 45 "../../src/Com/Native.fog"
    int64 DateSeconds(uint64 year, uint64 month, uint64 day);
#line 79 "../../src/Com/Algorithm.fog"
    template < class _1, class _2 >
    _1 FindIf(_1 begin, _1 end, bool(*fn)(_2& , void *), void *arg = 0);
#line 25 "../../src/Com/Hash.fog"
    template < class _1 >
    inline uint32 GetHashValue(const _1& k);
#line 37
    template <>
    inline uint32 GetHashValue < VoidPtr > (const VoidPtr& k);
#line 26
    template <>
    inline uint32 GetHashValue < char > (const char& k);
#line 36
    template <>
    inline uint32 GetHashValue < double > (const double& k);
#line 35
    template <>
    inline uint32 GetHashValue < float > (const float& k);
#line 27
    template <>
    inline uint32 GetHashValue < int > (const int& k);
#line 28
    template <>
    inline uint32 GetHashValue < uint32 > (const uint32& k);
#line 29
    template <>
    inline uint32 GetHashValue < uint64 > (const uint64& k);
#line 12 "../../src/Com/String.fog"
    inline int GetHexDigit(char c);
#line 134 "../../src/Com/Defs.fog"
    template < class _1 >
    inline void IGNORE_RESULT(const _1& );
#line 11 "../../src/Com/String.fog"
    inline bool IsAlpha(char c);
#line 9
    inline bool IsDigit(char c);
#line 8
    inline bool IsHexDigit(char c);
#line 7
    inline bool IsOctDigit(char c);
#line 10
    inline bool IsSpace(char c);
#line 6 "../../src/Com/Native.fog"
    void *MemoryAlloc(int sz);
#line 8
    int MemoryCompare(const void *m1, const void *m2, int sz);
    void *MemoryCopy(void *dest, const void *src, int sz);
#line 7
    void MemoryFree(void *ptr);
#line 10
    void *MemoryMove(void *dest, const void *src, int sz);
    void MemorySet(void *dest, int byte_value, int sz);
#line 47
    uint64 NativeCurrentTime();
#line 51
    void NativeDblStr(double d, char *buf, int buf_size);
    void NativeDblStr(double d, short *buf, int buf_size);
#line 49
    uint64 NativeMilliSeconds();
#line 48
    uint64 NativeNanoSeconds();
#line 55
    const char *NativeUtf16To8(const short *in);
#line 54
    const short *NativeUtf8To16(const char *in);
#line 72 "../../src/Com/Algorithm.fog"
    inline dword Random();
#line 74
    inline dword Random(dword n);
#line 73
    inline uint64 Random64();
#line 75
    inline uint64 Random64(uint64 n);
    inline double Randomf();
    inline void SeedRandom();
#line 12 "../../src/Com/Native.fog"
    int SignificantBits(uint32 x);
    int SignificantBits64(uint64 x);
#line 4
    int StringLength(const char *c, int max_len = 100000000);
    int StringLength(const short *c, int max_len = 100000000);
#line 46
    int64 TimeSeconds(uint64 year, uint64 month, uint64 day, uint64 hour, uint64 minute, uint64 second);
#line 11 "../../src/Com/Algorithm.fog"
    template < class _1 >
    inline const _1& max(const _1& a, const _1& b);
#line 4
    template < class _1 >
    inline const _1& min(const _1& a, const _1& b);
    
    struct AtomicBool
    {
#line 25 "../../src/Com/Native.fog"
        AtomicBool();
        AtomicBool(bool b);
        AtomicBool(const AtomicBool& ai);
#line 29
        bool operator= (bool b);
#line 28
        operator bool();
    };
    
    struct AtomicFlag
    {
#line 16
        void Enter();
        void Leave();
        bool TryEnter();
    };
    
    struct AtomicInt
    {
#line 33
        AtomicInt();
#line 35
        AtomicInt(const AtomicInt& ai);
#line 34
        AtomicInt(int i);
#line 38
        int operator++ ();
#line 40
        int operator++ (int);
#line 39
        int operator-- ();
#line 41
        int operator-- (int);
#line 37
        int operator= (int i);
#line 36
        operator int() const;
    };
    
    class CombineHash
    {
#line 8 "../../src/Com/Hash.fog"
        uint32 hash;
        
    public:
        inline CombineHash();
        inline CombineHash(int v0);
        CombineHash(int v0, int v1);
#line 21
        inline CombineHash& operator<< (int value);
#line 15
        inline operator uint32() const;
        inline uint32 Get() const;
#line 18
        CombineHash& Put(int value);
        CombineHash& Put64(int64 value);
    };
    
    class Env
    {
    public:
#line 19 "../../src/Com/Environment.fog"
        inline int Deinit();
#line 12
        void Init(int argc, const char **argv);
#line 25
        inline void ShutdownThreads();
        
    protected:
#line 36
        inline int GetExitCode();
#line 32
        inline void ParseCommandLine(int argc, const char **argv);
        inline void ReadComCmdlineArgs();
#line 35
        inline void RunExitBlocks();
#line 34
        inline void RunInitBlocks();
#line 31
        inline void SeedRandom();
#line 30
        inline void SetExeFilePath(const char *path);
        
    public:
#line 27
        inline static Env& Local();
    };
    
    class RNG
    {
#line 20 "../../src/Com/Algorithm.fog"
        uint64 state[4];
        
    public:
#line 55
        inline RNG();
#line 59
        inline operator uint64();
#line 58
        inline uint64 Get();
#line 57
        inline uint64 Random(uint64 max);
#line 56
        double Randomf();
#line 60
        inline void Seed();
        void Seed(dword seed);
        
#line 26
        uint64 sNext(uint64 *s);
#line 42
        void sSeed(uint64 *s);
#line 22
        uint64 s_rotl(const uint64 x, int k);
        
    public:
#line 66
        inline static RNG& Local();
    };
    
    class Stream
    {
    };
    
    class String
    {
#line 28 "../../src/Com/String.fog"
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
        uint32 GetHashValue() const;
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
        void Serialize(Stream& s);
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
        static int64 CharInt64(const Char *s);
#line 514
        static uint64 CharIntU64(const Char *s);
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
        static const Char *IntChar64(Char *p, int bufsize, int64 x);
#line 613
        static const Char *IntCharU64(Char *p, int bufsize, uint64 x);
#line 431
        static String IntStr(int i);
#line 437
        static String IntStr64(int64 i);
#line 632
        static int Length(const Char *c, int max_len = - 1);
#line 425
        inline static int OctInt(const String& s);
#line 429
        inline static double StrDbl(const String& s);
#line 427
        inline static int StrInt(const String& s);
        inline static int64 StrInt64(const String& s);
        
        class RefData
        {
#line 32
            Char *data;
            int reserved;
#line 46 "../../src/Com/Meta.fog"
            AtomicInt refs;
            
        public:
#line 36 "../../src/Com/String.fog"
            RefData(Char *str, int reserved);
            ~RefData();
#line 74
            operator ConstChar * () const;
#line 73
            Char *Begin();
#line 39
            void Clear();
#line 49 "../../src/Com/Meta.fog"
            void Dec();
#line 72 "../../src/Com/String.fog"
            ConstChar *Get() const;
#line 47 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 76 "../../src/Com/String.fog"
            int GetReserved() const;
#line 48 "../../src/Com/Meta.fog"
            void Inc();
#line 41 "../../src/Com/String.fog"
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
    
    struct Exc : public Com::String
    {
#line 704
        inline Exc();
        inline Exc(const String& s);
    };
    
    class Tester
    {
    public:
#line 17 "/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog"
        void Run();
        
#line 10
        inline static bool TestCmp(const char& c, void *);
        
        struct SomeRefTuple2
        {
#line 25 "../../src/Com/Meta.fog"
            int& a;
            double& b;
            
            SomeRefTuple2(int& a, double& b);
            String ToString() const;
        };
        
        struct SomeTuple2
        {
#line 6
            int a;
            double b;
            
            String ToString() const;
        };
    };
    
    class WString
    {
#line 28 "../../src/Com/String.fog"
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
        uint32 GetHashValue() const;
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
        void Serialize(Stream& s);
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
        static int64 CharInt64(const Char *s);
#line 514
        static uint64 CharIntU64(const Char *s);
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
        static const Char *IntChar64(Char *p, int bufsize, int64 x);
#line 613
        static const Char *IntCharU64(Char *p, int bufsize, uint64 x);
#line 431
        static WString IntStr(int i);
#line 437
        static WString IntStr64(int64 i);
#line 632
        static int Length(const Char *c, int max_len = - 1);
#line 425
        inline static int OctInt(const WString& s);
#line 429
        inline static double StrDbl(const WString& s);
#line 427
        inline static int StrInt(const WString& s);
        inline static int64 StrInt64(const WString& s);
        
        class RefData
        {
#line 32
            Char *data;
            int reserved;
#line 46 "../../src/Com/Meta.fog"
            AtomicInt refs;
            
        public:
#line 36 "../../src/Com/String.fog"
            RefData(Char *str, int reserved);
            ~RefData();
#line 74
            operator ConstChar * () const;
#line 73
            Char *Begin();
#line 39
            void Clear();
#line 49 "../../src/Com/Meta.fog"
            void Dec();
#line 72 "../../src/Com/String.fog"
            ConstChar *Get() const;
#line 47 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 76 "../../src/Com/String.fog"
            int GetReserved() const;
#line 48 "../../src/Com/Meta.fog"
            void Inc();
#line 41 "../../src/Com/String.fog"
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
    
    namespace
    {
#line 715
        String operator+ (const char *c, const String& l);
#line 747
        inline String DblStr(double d);
#line 750
        String EscapeCharacter(String s);
#line 749
        String EscapeString(String s);
#line 781
        inline int HexDigit(int c);
        inline int HexDigitLower(int c);
#line 743
        inline int HexInt(String s);
#line 783
        inline String HexStr(uint64 p);
#line 799
        inline String HexStr(void *p);
#line 745
        inline String IntStr(int i);
        inline String IntStr64(int64 i);
#line 742
        inline int OctInt(String s);
#line 740
        inline double StrDbl(String s);
        inline int StrInt(String s);
#line 744
        inline int64 StrInt64(String s);
#line 771
        template < class _1 >
        inline int64 ToInt(const _1& o);
#line 779
        template <>
        inline int64 ToInt < String > (const String& o);
#line 772
        template <>
        inline int64 ToInt < bool > (const bool& o);
#line 775
        template <>
        inline int64 ToInt < byte > (const byte& o);
#line 776
        template <>
        inline int64 ToInt < char > (const char& o);
        template <>
        inline int64 ToInt < double > (const double& o);
#line 777
        template <>
        inline int64 ToInt < float > (const float& o);
#line 773
        template <>
        inline int64 ToInt < int > (const int& o);
#line 774
        template <>
        inline int64 ToInt < int64 > (const int64& o);
#line 734
        String ToLower(const String& s);
#line 727
        inline int ToLower(int chr);
#line 755
        template < class _1 >
        inline String ToString(const _1& o);
#line 764
        template <>
        inline String ToString < String > (const String& o);
#line 767
        template <>
        inline String ToString < WString > (const WString& o);
#line 756
        template <>
        inline String ToString < bool > (const bool& o);
#line 760
        template <>
        inline String ToString < byte > (const byte& o);
#line 761
        template <>
        inline String ToString < char > (const char& o);
        template <>
        inline String ToString < double > (const double& o);
#line 762
        template <>
        inline String ToString < float > (const float& o);
#line 757
        template <>
        inline String ToString < int > (const int& o);
        template <>
        inline String ToString < int64 > (const int64& o);
#line 758
        template <>
        inline String ToString < uint32 > (const uint32& o);
#line 733
        String ToUpper(const String& s);
#line 721
        inline int ToUpper(int chr);
#line 736
        inline String ToUpperFirst(const String& s);
#line 766
        template < class _1 >
        inline WString ToWString(const _1& o);
        template <>
        inline WString ToWString < String > (const String& o);
#line 752
        String TrimBoth(String s);
    };
};

namespace Com
{
#line 25 "../../src/Com/Hash.fog"
    template < class _1 >
    inline uint32 GetHashValue(const _1& k)
    {
#line 25
        return k.GetHashValue();
    };
    
#line 37
    template <>
    inline uint32 GetHashValue < VoidPtr > (const VoidPtr& k)
    {
#line 39
        return GetHashValue(k.Int());
    };
    
#line 26
    template <>
    inline uint32 GetHashValue < char > (const char& k)
    {
#line 26
        return k;
    };
    
#line 36
    template <>
    inline uint32 GetHashValue < double > (const double& k)
    {
#line 36
        return GetHashValue(*(uint64 * ) & k);
    };
    
#line 35
    template <>
    inline uint32 GetHashValue < float > (const float& k)
    {
#line 35
        return static_cast< uint32 >(k);
    };
    
#line 27
    template <>
    inline uint32 GetHashValue < int > (const int& k)
    {
#line 27
        return k;
    };
    
#line 28
    template <>
    inline uint32 GetHashValue < uint32 > (const uint32& k)
    {
#line 28
        return k;
    };
    
#line 29
    template <>
    inline uint32 GetHashValue < uint64 > (const uint64& k)
    {
#line 30
        uint32 a = k & 0xFFFFFFFFULL;
        uint32 b = k >> 32ULL;
        uint32 hash = a ^ b;
        return hash;
    };
    
#line 12 "../../src/Com/String.fog"
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
    
#line 134 "../../src/Com/Defs.fog"
    template < class _1 >
    inline void IGNORE_RESULT(const _1& ) {};
    
#line 11 "../../src/Com/String.fog"
    inline bool IsAlpha(char c)
    {
#line 11
        return(c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
    };
    
#line 9
    inline bool IsDigit(char c)
    {
#line 9
        return c >= '0' && c <= '9';
    };
    
#line 8
    inline bool IsHexDigit(char c)
    {
#line 8
        return(c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F');
    };
    
#line 7
    inline bool IsOctDigit(char c)
    {
#line 7
        return c >= '0' && c <= '7';
    };
    
    inline bool IsSpace(char c)
    {
#line 10
        return c == ' ' || c == '\t' || c == '\n' || c == '\r';
    };
    
#line 72 "../../src/Com/Algorithm.fog"
    inline dword Random()
    {
#line 72
        return RNG::Local().Random(4294967295U);
    };
    
#line 74
    inline dword Random(dword n)
    {
#line 74
        return RNG::Local().Random(n);
    };
    
#line 73
    inline uint64 Random64()
    {
#line 73
        return RNG::Local().Get();
    };
    
#line 75
    inline uint64 Random64(uint64 n)
    {
#line 75
        return RNG::Local().Random(n);
    };
    
#line 76
    inline double Randomf()
    {
#line 76
        return RNG::Local().Randomf();
    };
    
#line 77
    inline void SeedRandom()
    {
#line 77
        return RNG::Local().Seed();
    };
    
#line 11
    template < class _1 >
    inline const _1& max(const _1& a, const _1& b)
    {
#line 12
        if (a >= b)
            return a;
        else
            return b;
    };
    
#line 4
    template < class _1 >
    inline const _1& min(const _1& a, const _1& b)
    {
#line 5
        if (a < b)
            return a;
        else
            return b;
    };
    
#line 11 "../../src/Com/Hash.fog"
    inline CombineHash::CombineHash()
    :
        hash(123456789)
    {};
    
#line 12
    inline CombineHash::CombineHash(int v0)
    :
        hash(123456789)
    {
#line 12
        Put(v0);
    };
    
#line 21
    inline CombineHash& CombineHash::operator<< (int value)
    {
#line 21
        Put(value);
#line 21
        return *this;
    };
    
#line 15
    inline CombineHash::operator uint32() const
    {
#line 15
        return hash;
    };
    
#line 16
    inline uint32 CombineHash::Get() const
    {
#line 16
        return hash;
    };
    
#line 19 "../../src/Com/Environment.fog"
    inline int Env::Deinit()
    {
#line 20
        ShutdownThreads();
        RunExitBlocks();
        return GetExitCode();
    };
    
#line 36
    inline int Env::GetExitCode()
    {
#line 36
        return 0;
    };
    
#line 27
    inline Env& Env::Local()
    {
#line 27
        static Env e;
#line 27
        return e;
    };
    
#line 32
    inline void Env::ParseCommandLine(int argc, const char **argv) {};
    
#line 33
    inline void Env::ReadComCmdlineArgs() {};
    
    inline void Env::RunExitBlocks() {};
    
#line 34
    inline void Env::RunInitBlocks() {};
    
#line 31
    inline void Env::SeedRandom()
    {
#line 31
        RNG::Local().Seed();
    };
    
#line 30
    inline void Env::SetExeFilePath(const char *path) {};
    
#line 25
    inline void Env::ShutdownThreads() {};
    
#line 704 "../../src/Com/String.fog"
    inline Exc::Exc() {};
    
#line 705
    inline Exc::Exc(const String& s)
    :
        String(s)
    {};
    
#line 55 "../../src/Com/Algorithm.fog"
    inline RNG::RNG()
    {
#line 55
        Seed();
    };
    
#line 59
    inline RNG::operator uint64()
    {
#line 59
        return Get();
    };
    
#line 58
    inline uint64 RNG::Get()
    {
#line 58
        return sNext(state);
    };
    
#line 66
    inline RNG& RNG::Local()
    {
#line 66
        static thread_local RNG r;
#line 66
        return r;
    };
    
#line 57
    inline uint64 RNG::Random(uint64 max)
    {
#line 57
        return Get() % max;
    };
    
    inline void RNG::Seed()
    {
#line 60
        sSeed(state);
    };
    
#line 415 "../../src/Com/String.fog"
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
        return Set(c, StringLength(c));
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
    inline int64 String::StrInt64(const String& s)
    {
#line 428
        return CharInt64(s.Begin());
    };
    
#line 10 "/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog"
    inline bool Tester::TestCmp(const char& c, void *)
    {
#line 11
        return c == 'c';
    };
    
#line 415 "../../src/Com/String.fog"
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
        return Set(c, StringLength(c));
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
    inline int64 WString::StrInt64(const WString& s)
    {
#line 428
        return CharInt64(s.Begin());
    };
    
    namespace
    {
#line 747
        inline String DblStr(double d)
        {
#line 747
            return String::DblStr(d);
        };
        
#line 781
        inline int HexDigit(int c)
        {
#line 781
            return "0123456789ABCDEF"[c & 15];
        };
        
#line 782
        inline int HexDigitLower(int c)
        {
#line 782
            return "0123456789abcdef"[c & 15];
        };
        
#line 743
        inline int HexInt(String s)
        {
#line 743
            return String::HexInt(s);
        };
        
#line 783
        inline String HexStr(uint64 p)
        {
#line 784
            String o("0x");
            bool zero = true;
            uint64 i = 64;
            do
                {
#line 788
                    i -= 4;
                    byte b = (p >> i) & 15ULL;
                    if (b || !zero)
                    {
#line 791
                        zero = false;
                        o.Cat(HexDigit(b));
                    }
                }while (i);
#line 796
            if (zero)
#line 796
                o.Cat('0');
            return o;
        };
        
#line 799
        inline String HexStr(void *p)
        {
#line 799
            return HexStr((uint64) p);
        };
        
#line 745
        inline String IntStr(int i)
        {
#line 745
            return String::IntStr(i);
        };
        
#line 746
        inline String IntStr64(int64 i)
        {
#line 746
            return String::IntStr64(i);
        };
        
#line 742
        inline int OctInt(String s)
        {
#line 742
            return String::OctInt(s);
        };
        
#line 740
        inline double StrDbl(String s)
        {
#line 740
            return String::StrDbl(s);
        };
        
#line 741
        inline int StrInt(String s)
        {
#line 741
            return String::StrInt(s);
        };
        
        inline int64 StrInt64(String s)
        {
#line 744
            return String::StrInt64(s);
        };
        
#line 771
        template < class _1 >
        inline int64 ToInt(const _1& o)
        {
#line 771
            return o.ToInt();
        };
        
#line 779
        template <>
        inline int64 ToInt < String > (const String& o)
        {
#line 779
            return StrInt(o);
        };
        
#line 772
        template <>
        inline int64 ToInt < bool > (const bool& o)
        {
#line 772
            return(int64) o;
        };
        
        template <>
        inline int64 ToInt < byte > (const byte& o)
        {
#line 775
            return(int64) o;
        };
        
#line 776
        template <>
        inline int64 ToInt < char > (const char& o)
        {
#line 776
            return(int64) o;
        };
        
#line 778
        template <>
        inline int64 ToInt < double > (const double& o)
        {
#line 778
            return(int64) o;
        };
        
#line 777
        template <>
        inline int64 ToInt < float > (const float& o)
        {
#line 777
            return(int64) o;
        };
        
#line 773
        template <>
        inline int64 ToInt < int > (const int& o)
        {
#line 773
            return(int64) o;
        };
        
#line 774
        template <>
        inline int64 ToInt < int64 > (const int64& o)
        {
#line 774
            return(int64) o;
        };
        
#line 727
        inline int ToLower(int chr)
        {
#line 728
            if (chr >= 'A' && chr <= 'Z')
                return 'a' + (chr - 'A');
            return chr;
        };
        
#line 755
        template < class _1 >
        inline String ToString(const _1& o)
        {
#line 755
            return o.ToString();
        };
        
#line 764
        template <>
        inline String ToString < String > (const String& o)
        {
#line 764
            return o;
        };
        
        template <>
        inline String ToString < WString > (const WString& o)
        {
#line 767
            return NativeUtf16To8(o.Begin());
        };
        
#line 756
        template <>
        inline String ToString < bool > (const bool& o)
        {
#line 756
            if (o)
#line 756
                return "true";
            else
#line 756
                return "false";
        };
        
#line 760
        template <>
        inline String ToString < byte > (const byte& o)
        {
#line 760
            return IntStr(o);
        };
        
#line 761
        template <>
        inline String ToString < char > (const char& o)
        {
#line 761
            String s;
#line 761
            s.Cat(o);
#line 761
            return s;
        };
        
#line 763
        template <>
        inline String ToString < double > (const double& o)
        {
#line 763
            return DblStr(o);
        };
        
#line 762
        template <>
        inline String ToString < float > (const float& o)
        {
#line 762
            return DblStr(o);
        };
        
#line 757
        template <>
        inline String ToString < int > (const int& o)
        {
#line 757
            return IntStr(o);
        };
        
#line 759
        template <>
        inline String ToString < int64 > (const int64& o)
        {
#line 759
            return IntStr64(o);
        };
        
#line 758
        template <>
        inline String ToString < uint32 > (const uint32& o)
        {
#line 758
            return IntStr64(o);
        };
        
#line 721
        inline int ToUpper(int chr)
        {
#line 722
            if (chr >= 'a' && chr <= 'z')
                return 'A' + (chr - 'a');
            return chr;
        };
        
#line 736
        inline String ToUpperFirst(const String& s)
        {
#line 737
            return ToUpper(s.Left(1)) + s.Mid(1);
        };
        
#line 766
        template < class _1 >
        inline WString ToWString(const _1& o)
        {
#line 766
            return o.ToWString();
        };
        
#line 768
        template <>
        inline WString ToWString < String > (const String& o)
        {
#line 768
            return NativeUtf8To16(o.Begin());
        };
        
    };
};

#endif
