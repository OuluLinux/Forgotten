/*!$@FOG@$!
 *	Generated at Mon Sep 28 10:34:35 2020
 *
 *	by fog 0.1.a of 08:56:34 Sep 28 2020
 *
 *	from
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Defs.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Lang.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Meta.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/String.fog
 *		../../src/Com/Vector.fog
 *		ComTest.mfog
 */

#ifndef COM_HXX
#define COM_HXX

#include <new>

#ifndef C_HXX
#include <C.hxx>
#endif

struct ComInterfaceLinker
{
};

namespace Com
{
#line 9 "../../src/Com/Defs.fog"
    extern C::Nuller Null;
};

namespace Com
{
#line 34
    typedef unsigned char Byte;
    
#line 35
    extern Byte ____unused_Byte;
};

namespace Com
{
#line 39
    typedef C::Ptr < const char > CString;
    
#line 40
    extern CString ____unused_CString;
};

namespace Com
{
#line 39
    typedef C::Ptr < const void > ConstVoidPtr;
    
#line 40
    extern ConstVoidPtr ____unused_ConstVoidPtr;
};

namespace Com
{
#line 34
    typedef unsigned long DWORD;
    
#line 35
    extern DWORD ____unused_DWORD;
};

namespace Com
{
#line 39
    typedef C::Ptr < void > VoidPtr;
    
#line 40
    extern VoidPtr ____unused_VoidPtr;
};

namespace Com
{
#line 34
    typedef unsigned char byte;
    
#line 35
    extern byte ____unused_byte;
};

namespace Com
{
#line 34
    typedef unsigned int uint32;
#line 34
    typedef uint32 dword;
    
#line 35
    extern dword ____unused_dword;
};

namespace Com
{
#line 34
    typedef short int16;
    
#line 35
    extern int16 ____unused_int16;
};

namespace Com
{
#line 34
    typedef int int32;
    
#line 35
    extern int32 ____unused_int32;
};

namespace Com
{
#line 34
    typedef long long int64;
    
#line 35
    extern int64 ____unused_int64;
};

namespace Com
{
#line 34
    typedef char int8;
    
#line 35
    extern int8 ____unused_int8;
};

namespace Com
{
#line 34
    typedef unsigned long long uint64;
#line 34
    typedef uint64 qword;
    
#line 35
    extern qword ____unused_qword;
};

namespace Com
{
#line 34
    typedef unsigned short uint16;
    
#line 35
    extern uint16 ____unused_uint16;
#line 35
    extern uint32 ____unused_uint32;
#line 35
    extern uint64 ____unused_uint64;
};

namespace Com
{
#line 34
    typedef unsigned char uint8;
    
#line 35
    extern uint8 ____unused_uint8;
};

namespace Com
{
#line 34
    typedef uint16 word;
    
#line 35
    extern word ____unused_word;
    
#line 17
    void Break(const char *msg);
#line 19 "../../src/Com/Native.fog"
    int64 DateSeconds(uint64 year, uint64 month, uint64 day);
#line 81 "../../src/Com/Algorithm.fog"
    template < class _1, class _2 >
    inline _1 FindIf(_1 begin, _1 end, bool(*fn)(_2& , void *), void *arg = 0);
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
#line 108 "../../src/Com/Defs.fog"
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
#line 11 "../../src/Com/Defs.fog"
    void *MemoryAlloc(int sz);
#line 13
    int MemoryCompare(const void *m1, const void *m2, int sz);
    void *MemoryCopy(void *dest, const void *src, int sz);
#line 12
    void MemoryFree(void *ptr);
#line 15
    void *MemoryMove(void *dest, const void *src, int sz);
    void MemorySet(void *dest, int byte_value, int sz);
#line 21 "../../src/Com/Native.fog"
    uint64 NativeCurrentTime();
#line 25
    void NativeDblStr(double d, char *buf, int buf_size);
    void NativeDblStr(double d, short *buf, int buf_size);
#line 23
    uint64 NativeMilliSeconds();
#line 22
    uint64 NativeNanoSeconds();
#line 29
    const char *NativeUtf16To8(const short *in);
#line 28
    const short *NativeUtf8To16(const char *in);
#line 74 "../../src/Com/Algorithm.fog"
    inline dword Random();
#line 76
    inline dword Random(dword n);
#line 75
    inline uint64 Random64();
#line 77
    inline uint64 Random64(uint64 n);
    inline double Randomf();
#line 36 "../../src/Com/Vector.fog"
    template < class _1 >
    inline void Reverse(_1& t);
#line 79 "../../src/Com/Algorithm.fog"
    inline void SeedRandom();
#line 16 "../../src/Com/Native.fog"
    int SignificantBits(uint32 x);
    int SignificantBits64(uint64 x);
#line 28 "../../src/Com/Vector.fog"
    template < class _1 >
    void Swap(_1& a, _1& b);
#line 20 "../../src/Com/Native.fog"
    int64 TimeSeconds(uint64 year, uint64 month, uint64 day, uint64 hour, uint64 minute, uint64 second);
#line 11 "../../src/Com/Algorithm.fog"
    template < class _1 >
    inline const _1& max(const _1& a, const _1& b);
#line 4
    template < class _1 >
    inline const _1& min(const _1& a, const _1& b);
    
    template < class _1 >
    class Array
    {
    public:
#line 186 "../../src/Com/Vector.fog"
        typedef const _1 ConstK;
#line 185
        typedef _1 IndirectK;
#line 187
        typedef C::FwdPtrIterator < _1 > Iterator;
        typedef C::BwdPtrIterator < _1 > RIterator;
        
#line 181
        C::DynArray < _1 * > l;
        
    public:
#line 191
        inline Array();
#line 198
        inline ~Array();
#line 289
        inline Array < _1 > & operator<< (const _1& v);
#line 282
        inline void operator<<= (const Array& a);
#line 243
        inline _1& operator[](int i);
#line 249
        inline const _1& operator[](int i) const;
#line 234
        inline _1& Add();
#line 236
        inline _1& Add(_1 *k);
#line 235
        inline _1& Add(const _1& v);
#line 204
        inline C::ConstFwdPtrIterator < _1 > Begin() const;
#line 202
        inline C::FwdPtrIterator < _1 > Begin();
#line 270
        inline void Clear();
#line 241
        inline _1 *Detach(int i);
#line 205
        inline C::ConstFwdPtrIterator < _1 > End() const;
#line 203
        inline C::FwdPtrIterator < _1 > End();
#line 239
        inline int GetCount() const;
#line 237
        inline _1& Insert(int i);
        inline _1& Insert(int i, const _1& key);
#line 240
        inline bool IsEmpty() const;
#line 210
        inline C::BwdPtrIterator < _1 > RBegin();
#line 212
        inline C::ConstBwdPtrIterator < _1 > RBegin() const;
#line 211
        inline C::BwdPtrIterator < _1 > REnd();
#line 213
        inline C::ConstBwdPtrIterator < _1 > REnd() const;
#line 260
        inline void Remove(const int *sorted_list, int n);
#line 254
        inline void Remove(int i);
#line 269
        inline void RemoveLast();
#line 219
        inline void Reserve(int i);
        inline void SetCount(int new_count);
#line 278
        inline _1& Top();
#line 208
        inline C::ConstFwdPtrIterator < _1 > begin() const;
#line 206
        inline C::FwdPtrIterator < _1 > begin();
#line 209
        inline C::ConstFwdPtrIterator < _1 > end() const;
#line 207
        inline C::FwdPtrIterator < _1 > end();
#line 214
        inline C::BwdPtrIterator < _1 > rbegin();
#line 216
        inline C::ConstBwdPtrIterator < _1 > rbegin() const;
#line 215
        inline C::BwdPtrIterator < _1 > rend();
#line 217
        inline C::ConstBwdPtrIterator < _1 > rend() const;
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
    
    template < class _1 >
    class One
    {
    public:
#line 52 "../../src/Com/Vector.fog"
        typedef const _1 ConstT;
        
#line 49
        _1 *obj;
        
    public:
#line 54
        inline One();
        inline One(One& o);
        inline One(_1 *obj);
        inline ~One();
#line 73
        inline bool operator!= (void *ptr);
#line 66
        inline _1& operator*();
        inline const _1& operator*() const;
#line 64
        _1 *operator-> ();
        const _1 *operator-> () const;
#line 61
        inline void operator= (_1 *obj);
#line 75
        operator ConstT & () const;
#line 74
        operator _1 & ();
#line 72
        inline operator bool() const;
#line 60
        inline void Clear();
#line 59
        inline void Create();
#line 77
        template < class _2 >
        inline void CreateDerived();
#line 71
        _1 *Detach();
#line 68
        inline _1 *Get();
        inline const _1 *Get() const;
#line 78
        template < class _2 >
        inline _2 *GetDerived();
#line 62
        inline bool Is() const;
        inline bool IsEmpty() const;
#line 70
        inline _1& Value();
    };
    
    template < class _1 >
    class FutureOne
    {
#line 82
        C::ConditionalVar cond;
        One < _1 > one;
        
    public:
        inline FutureOne();
#line 109
        inline _1 *operator= (_1 *o);
#line 93
        inline void Clear();
#line 95
        inline _1 *Detach();
#line 94
        inline _1 *Get();
#line 96
        inline bool IsEmpty() const;
#line 88
        inline void Set(_1 *o);
#line 97
        inline void Wait();
    };
    
    template < class _1 >
    class Pick
    {
#line 17
        _1 *var;
        
    public:
#line 19
        inline Pick(_1& var);
        inline Pick(const Pick& p);
#line 22
        inline _1& Get() const;
        
    public:
#line 24
        inline static Pick < _1 > Ptr(_1 *p);
    };
};

namespace Com
{
#line 8 "../../src/Com/Defs.fog"
    typedef C::Nuller Nuller;
    
    template < class _1 >
    class Optional
    {
    public:
#line 120 "../../src/Com/Vector.fog"
        typedef Com::Pick < Optional > PickOpt;
#line 119
        typedef Com::Pick < _1 > PickT;
        
#line 116
        _1 *obj;
        
    public:
#line 122
        inline Optional();
#line 127
        inline Optional(_1 *obj);
#line 126
        inline Optional(const Nuller& n);
#line 124
        Optional(const Optional& opt);
#line 128
        Optional(const PickT& n);
#line 125
        Optional(const _1& obj);
#line 129
        inline ~Optional();
#line 143
        inline _1& operator*();
#line 141
        _1 *operator-> ();
#line 134
        inline void operator= (const Nuller& );
#line 136
        void operator= (const Optional& o);
        void operator= (const PickOpt& n);
#line 135
        inline void operator= (const _1& obj);
#line 142
        inline operator bool() const;
#line 133
        inline void Clear();
#line 131
        inline void Create();
        template < class _2 >
        inline void Create1(const _2& arg);
#line 140
        inline _1& GetValue() const;
#line 139
        inline bool IsEmpty() const;
#line 138
        void Pick(Optional& o);
    };
    
    class RNG
    {
#line 22 "../../src/Com/Algorithm.fog"
        uint64 state[4];
        
    public:
#line 57
        inline RNG();
#line 61
        inline operator uint64();
#line 60
        inline uint64 Get();
#line 59
        inline uint64 Random(uint64 max);
#line 58
        double Randomf();
#line 62
        inline void Seed();
        void Seed(dword seed);
        
#line 28
        uint64 sNext(uint64 *s);
#line 44
        void sSeed(uint64 *s);
#line 24
        uint64 s_rotl(const uint64 x, int k);
        
    public:
#line 68
        inline static RNG& Local();
    };
    
    class Stream
    {
    };
    
    class String
    {
#line 30 "../../src/Com/String.fog"
        typedef char Char;
        typedef const char ConstChar;
        
#line 90
        bool is_ref;
        int count;
        
    public:
#line 99
        String();
#line 102
        String(const String& s);
#line 100
        String(const Char *c);
        String(const Char *c, int len);
#line 103
        ~String();
#line 417
        inline bool operator!= (const String& s) const;
#line 425
        String operator+ (const String& s);
#line 150
        String operator+ (const String& l) const;
#line 422
        inline String& operator+= (const String& s);
        inline String& operator<< (const String& s);
        inline String& operator<< (int i);
#line 132
        String& operator= (const String& str);
#line 131
        inline String& operator= (const Char *c);
#line 412
        bool operator== (const String& s) const;
#line 419
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 409
        const Char *Begin() const;
#line 162
        String& Cat(Char i);
#line 156
        String& Cat(Char c, int count);
#line 205
        String& Cat(const String& str);
#line 451
        inline String CharoString() const;
#line 106
        void Clear();
#line 410
        inline const Char *End() const;
#line 286
        int Find(const String& str, int pos = 0) const;
#line 313
        int FindFirstNotOf(const Char *str) const;
#line 284
        inline int GetCount() const;
#line 453
        uint32 GetHashValue() const;
#line 391
        bool Insert(int begin, const Char *str, int n);
#line 285
        inline bool IsEmpty() const;
#line 368
        inline String Left(int i) const;
#line 361
        String Mid(int i) const;
        String Mid(int i, int size) const;
#line 371
        void Remove(int begin, int count);
#line 246
        void Replace(const String& s, const String& value);
#line 255
        void Replace(int i, int len, const String& value);
#line 300
        inline int ReverseFind(const String& str) const;
        int ReverseFind(const String& str, int pos) const;
#line 337
        int ReverseFindFirstNotOf(const Char *str) const;
#line 369
        inline String Right(int i) const;
#line 112
        void Serialize(Stream& s);
        String& Set(const Char *c, int len);
        
#line 94
        void Zero();
        
    public:
#line 529
        static double CharDbl(const Char *s);
#line 475
        static int CharHexInt(const Char *s);
#line 490
        static int CharInt(const Char *s);
#line 503
        static int64 CharInt64(const Char *s);
#line 516
        static uint64 CharIntU64(const Char *s);
#line 461
        static int CharOctInt(const Char *s);
#line 655
        static int Compare(const Char *a, const Char *b);
#line 666
        static int Compare(const Char *a, const Char *b, int len);
#line 678
        static void Copy(Char *dst, const Char *src);
#line 445
        static String DblStr(double d);
#line 686
        inline static ConstChar *Empty();
#line 428
        inline static int HexInt(const String& s);
#line 579
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 597
        static const Char *IntChar64(Char *p, int bufsize, int64 x);
#line 615
        static const Char *IntCharU64(Char *p, int bufsize, uint64 x);
#line 433
        static String IntStr(int i);
#line 439
        static String IntStr64(int64 i);
#line 634
        static int Length(const Char *c, int max_len = - 1);
#line 427
        inline static int OctInt(const String& s);
#line 431
        inline static double StrDbl(const String& s);
#line 429
        inline static int StrInt(const String& s);
        inline static int64 StrInt64(const String& s);
        
        class RefData
        {
#line 34
            Char *data;
            int reserved;
#line 46 "../../src/Com/Meta.fog"
            C::AtomicInt refs;
            
        public:
#line 38 "../../src/Com/String.fog"
            RefData(Char *str, int reserved);
            ~RefData();
#line 76
            operator ConstChar * () const;
#line 75
            Char *Begin();
#line 41
            void Clear();
#line 49 "../../src/Com/Meta.fog"
            void Dec();
#line 74 "../../src/Com/String.fog"
            ConstChar *Get() const;
#line 47 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 78 "../../src/Com/String.fog"
            int GetReserved() const;
#line 48 "../../src/Com/Meta.fog"
            void Inc();
#line 43 "../../src/Com/String.fog"
            void IncreaseReserved();
#line 52
            void IncreaseReserved(int min_reserved);
#line 61
            void Reserve(int new_reserved);
        };
        
        union
        {
        public:
#line 87
            Char buf[8];
            RefData *ref[0];
        };
    };
    
    struct Exc : public Com::String
    {
#line 706
        inline Exc();
        inline Exc(const String& s);
    };
    
    namespace Tester
    {
        class App
        {
        public:
#line 26 "ComTest.mfog"
            inline void Run();
            
#line 7
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
            
            struct VirtualBase
            {
#line 15 "ComTest.mfog"
                int a;
                
#line 12
                inline VirtualBase();
                virtual ~VirtualBase();
            };
            
            struct DerivedBase : public Com::Tester::App::VirtualBase
            {
#line 20
                int a;
                
#line 18
                inline DerivedBase();
            };
        };
    };
    
    template < class _1 >
    class Vector : public C::DynArray < _1 >
    {
#line 152 "../../src/Com/Vector.fog"
        typedef C::DynArray < _1 > Base;
        
    public:
#line 158
        inline Vector();
        inline Vector(const Vector& v);
    };
    
    class WString
    {
#line 30 "../../src/Com/String.fog"
        typedef short Char;
        typedef const short ConstChar;
        
#line 90
        bool is_ref;
        int count;
        
    public:
#line 99
        WString();
#line 102
        WString(const WString& s);
#line 100
        WString(const Char *c);
        WString(const Char *c, int len);
#line 103
        ~WString();
#line 417
        inline bool operator!= (const WString& s) const;
#line 425
        WString operator+ (const WString& s);
#line 150
        WString operator+ (const WString& l) const;
#line 422
        inline WString& operator+= (const WString& s);
        inline WString& operator<< (const WString& s);
        inline WString& operator<< (int i);
#line 132
        WString& operator= (const WString& str);
#line 131
        inline WString& operator= (const Char *c);
#line 412
        bool operator== (const WString& s) const;
#line 419
        inline Char operator[](int i) const;
        Char At(int i) const;
#line 409
        const Char *Begin() const;
#line 162
        WString& Cat(Char i);
#line 156
        WString& Cat(Char c, int count);
#line 205
        WString& Cat(const WString& str);
#line 451
        inline WString CharoString() const;
#line 106
        void Clear();
#line 410
        inline const Char *End() const;
#line 286
        int Find(const WString& str, int pos = 0) const;
#line 313
        int FindFirstNotOf(const Char *str) const;
#line 284
        inline int GetCount() const;
#line 453
        uint32 GetHashValue() const;
#line 391
        bool Insert(int begin, const Char *str, int n);
#line 285
        inline bool IsEmpty() const;
#line 368
        inline WString Left(int i) const;
#line 361
        WString Mid(int i) const;
        WString Mid(int i, int size) const;
#line 371
        void Remove(int begin, int count);
#line 246
        void Replace(const WString& s, const WString& value);
#line 255
        void Replace(int i, int len, const WString& value);
#line 300
        inline int ReverseFind(const WString& str) const;
        int ReverseFind(const WString& str, int pos) const;
#line 337
        int ReverseFindFirstNotOf(const Char *str) const;
#line 369
        inline WString Right(int i) const;
#line 112
        void Serialize(Stream& s);
        WString& Set(const Char *c, int len);
        
#line 94
        void Zero();
        
    public:
#line 529
        static double CharDbl(const Char *s);
#line 475
        static int CharHexInt(const Char *s);
#line 490
        static int CharInt(const Char *s);
#line 503
        static int64 CharInt64(const Char *s);
#line 516
        static uint64 CharIntU64(const Char *s);
#line 461
        static int CharOctInt(const Char *s);
#line 655
        static int Compare(const Char *a, const Char *b);
#line 666
        static int Compare(const Char *a, const Char *b, int len);
#line 678
        static void Copy(Char *dst, const Char *src);
#line 445
        static WString DblStr(double d);
#line 686
        inline static ConstChar *Empty();
#line 428
        inline static int HexInt(const WString& s);
#line 579
        static const Char *IntChar(Char *p, int bufsize, int x);
#line 597
        static const Char *IntChar64(Char *p, int bufsize, int64 x);
#line 615
        static const Char *IntCharU64(Char *p, int bufsize, uint64 x);
#line 433
        static WString IntStr(int i);
#line 439
        static WString IntStr64(int64 i);
#line 634
        static int Length(const Char *c, int max_len = - 1);
#line 427
        inline static int OctInt(const WString& s);
#line 431
        inline static double StrDbl(const WString& s);
#line 429
        inline static int StrInt(const WString& s);
        inline static int64 StrInt64(const WString& s);
        
        class RefData
        {
#line 34
            Char *data;
            int reserved;
#line 46 "../../src/Com/Meta.fog"
            C::AtomicInt refs;
            
        public:
#line 38 "../../src/Com/String.fog"
            RefData(Char *str, int reserved);
            ~RefData();
#line 76
            operator ConstChar * () const;
#line 75
            Char *Begin();
#line 41
            void Clear();
#line 49 "../../src/Com/Meta.fog"
            void Dec();
#line 74 "../../src/Com/String.fog"
            ConstChar *Get() const;
#line 47 "../../src/Com/Meta.fog"
            int GetRefs() const;
#line 78 "../../src/Com/String.fog"
            int GetReserved() const;
#line 48 "../../src/Com/Meta.fog"
            void Inc();
#line 43 "../../src/Com/String.fog"
            void IncreaseReserved();
#line 52
            void IncreaseReserved(int min_reserved);
#line 61
            void Reserve(int new_reserved);
        };
        
        union
        {
        public:
#line 87
            Char buf[8];
            RefData *ref[0];
        };
    };
    
    namespace
    {
#line 720
        inline String operator+ (const char *c, const String& l);
#line 777
        inline String DblStr(double d);
#line 780
        String EscapeCharacter(String s);
#line 779
        String EscapeString(String s);
#line 811
        inline int HexDigit(int c);
        inline int HexDigitLower(int c);
#line 773
        inline int HexInt(String s);
#line 813
        inline String HexStr(uint64 p);
#line 829
        inline String HexStr(void *p);
#line 775
        inline String IntStr(int i);
        inline String IntStr64(int64 i);
#line 772
        inline int OctInt(String s);
#line 770
        inline double StrDbl(String s);
        inline int StrInt(String s);
#line 774
        inline int64 StrInt64(String s);
#line 801
        template < class _1 >
        inline int64 ToInt(const _1& o);
#line 809
        template <>
        inline int64 ToInt < String > (const String& o);
#line 802
        template <>
        inline int64 ToInt < bool > (const bool& o);
#line 805
        template <>
        inline int64 ToInt < byte > (const byte& o);
#line 806
        template <>
        inline int64 ToInt < char > (const char& o);
        template <>
        inline int64 ToInt < double > (const double& o);
#line 807
        template <>
        inline int64 ToInt < float > (const float& o);
#line 803
        template <>
        inline int64 ToInt < int > (const int& o);
#line 804
        template <>
        inline int64 ToInt < int64 > (const int64& o);
#line 752
        String ToLower(const String& s);
#line 732
        int ToLowerChar(int chr);
#line 785
        template < class _1 >
        inline String ToString(const _1& o);
#line 794
        template <>
        inline String ToString < String > (const String& o);
#line 797
        template <>
        inline String ToString < WString > (const WString& o);
#line 786
        template <>
        inline String ToString < bool > (const bool& o);
#line 790
        template <>
        inline String ToString < byte > (const byte& o);
#line 791
        template <>
        inline String ToString < char > (const char& o);
        template <>
        inline String ToString < double > (const double& o);
#line 792
        template <>
        inline String ToString < float > (const float& o);
#line 787
        template <>
        inline String ToString < int > (const int& o);
        template <>
        inline String ToString < int64 > (const int64& o);
#line 788
        template <>
        inline String ToString < uint32 > (const uint32& o);
#line 738
        String ToUpper(const String& s);
#line 726
        int ToUpperChar(int chr);
#line 766
        inline String ToUpperFirst(const String& s);
#line 796
        template < class _1 >
        inline WString ToWString(const _1& o);
        template <>
        inline WString ToWString < String > (const String& o);
#line 782
        String TrimBoth(String s);
    };
};

namespace Com
{
#line 81 "../../src/Com/Algorithm.fog"
    template < class _1, class _2 >
    inline _1 FindIf(_1 begin, _1 end, bool(*fn)(_2& , void *), void *arg)
    {
#line 83
        while (begin != end)
            {
#line 84
                if (fn(*begin, arg))
                    return begin;
                begin ++ ;
            }
        return end;
    };
    
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
    
#line 108 "../../src/Com/Defs.fog"
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
    
#line 74 "../../src/Com/Algorithm.fog"
    inline dword Random()
    {
#line 74
        return RNG::Local().Random(4294967295U);
    };
    
#line 76
    inline dword Random(dword n)
    {
#line 76
        return RNG::Local().Random(n);
    };
    
#line 75
    inline uint64 Random64()
    {
#line 75
        return RNG::Local().Get();
    };
    
#line 77
    inline uint64 Random64(uint64 n)
    {
#line 77
        return RNG::Local().Random(n);
    };
    
#line 78
    inline double Randomf()
    {
#line 78
        return RNG::Local().Randomf();
    };
    
#line 36 "../../src/Com/Vector.fog"
    template < class _1 >
    inline void Reverse(_1& t)
    {
#line 38
        int count = t.GetCount();
        int count_2 = count / 2;
        int a = 0;
        int b = count - 1;
        for (int i = 0; i < count_2; i ++ )
            {
#line 43
                Swap(t[a ++ ], t[b -- ]);
            }
    };
    
#line 79 "../../src/Com/Algorithm.fog"
    inline void SeedRandom()
    {
#line 79
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
    
#line 191 "../../src/Com/Vector.fog"
    template < class _1 >
    inline Array < _1 >::Array() {};
    
#line 198
    template < class _1 >
    inline Array < _1 >::~Array()
    {
#line 198
        Clear();
    };
    
#line 289
    template < class _1 >
    inline Array < _1 > & Array < _1 >::operator<< (const _1& v)
    {
#line 289
        Add(v);
#line 289
        return *this;
    };
    
#line 282
    template < class _1 >
    inline void Array < _1 >::operator<<= (const Array& a)
    {
#line 283
        Clear();
        l.SetCount(a.GetCount(), 0);
        for (int i = 0; i < a.GetCount(); i ++ )
            l[i] = new _1(*a.l[i]);
    };
    
#line 243
    template < class _1 >
    inline _1& Array < _1 >::operator[](int i)
    {
        {
#line 244
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 244
                Break("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 245
        ;
#line 245
        _1 * *it = l.Get();
        it = it + i;
        return **it;
    };
    
#line 249
    template < class _1 >
    inline const _1& Array < _1 >::operator[](int i) const
    {
        {
#line 250
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 250
                Break("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 251
        ;
#line 251
        return **(l.Get() + i);
    };
    
#line 234
    template < class _1 >
    inline _1& Array < _1 >::Add()
    {
#line 234
        _1 * k = new _1;
#line 234
        l.Add(k);
#line 234
        return *k;
    };
    
#line 236
    template < class _1 >
    inline _1& Array < _1 >::Add(_1 *k)
    {
#line 236
        l.Add(k);
#line 236
        return *k;
    };
    
#line 235
    template < class _1 >
    inline _1& Array < _1 >::Add(const _1& v)
    {
#line 235
        _1 * k = new _1(v);
#line 235
        l.Add(k);
#line 235
        return *k;
    };
    
#line 204
    template < class _1 >
    inline C::ConstFwdPtrIterator < _1 > Array < _1 >::Begin() const
    {
#line 204
        return Iterator(l.Begin());
    };
    
#line 202
    template < class _1 >
    inline C::FwdPtrIterator < _1 > Array < _1 >::Begin()
    {
#line 202
        return Iterator(l.Begin());
    };
    
#line 270
    template < class _1 >
    inline void Array < _1 >::Clear()
    {
#line 271
        _1 * *ptr = l.Get();
        _1 * *end = ptr + l.GetCount();
        while (ptr != end)
            delete *(ptr ++ );
        l.Clear();
    };
    
#line 241
    template < class _1 >
    inline _1 *Array < _1 >::Detach(int i)
    {
#line 241
        _1 * o = l[i];
#line 241
        l.Remove(i);
#line 241
        return o;
    };
    
#line 205
    template < class _1 >
    inline C::ConstFwdPtrIterator < _1 > Array < _1 >::End() const
    {
#line 205
        return Iterator(l.End());
    };
    
#line 203
    template < class _1 >
    inline C::FwdPtrIterator < _1 > Array < _1 >::End()
    {
#line 203
        return Iterator(l.End());
    };
    
#line 239
    template < class _1 >
    inline int Array < _1 >::GetCount() const
    {
#line 239
        return l.GetCount();
    };
    
#line 237
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i)
    {
#line 237
        return *l.Insert(i, new _1);
    };
    
#line 238
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i, const _1& key)
    {
#line 238
        return *l.Insert(i, new _1(key));
    };
    
#line 240
    template < class _1 >
    inline bool Array < _1 >::IsEmpty() const
    {
#line 240
        return GetCount() == 0;
    };
    
#line 210
    template < class _1 >
    inline C::BwdPtrIterator < _1 > Array < _1 >::RBegin()
    {
#line 210
        return RIterator(l.End() - 1);
    };
    
#line 212
    template < class _1 >
    inline C::ConstBwdPtrIterator < _1 > Array < _1 >::RBegin() const
    {
#line 212
        return RIterator(l.End() - 1);
    };
    
#line 211
    template < class _1 >
    inline C::BwdPtrIterator < _1 > Array < _1 >::REnd()
    {
#line 211
        return RIterator(l.Begin() - 1);
    };
    
#line 213
    template < class _1 >
    inline C::ConstBwdPtrIterator < _1 > Array < _1 >::REnd() const
    {
#line 213
        return RIterator(l.Begin() - 1);
    };
    
#line 260
    template < class _1 >
    inline void Array < _1 >::Remove(const int *sorted_list, int n)
    {
#line 261
        if (!n)
#line 261
            return;
        const int * it = sorted_list;
        const int * end = sorted_list + n;
        _1 * *vector = l.Get();
        while (it != end)
            (*(vector + *it ++ ))-> ~K();
        l.Remove(sorted_list, n);
    };
    
#line 254
    template < class _1 >
    inline void Array < _1 >::Remove(int i)
    {
        {
#line 255
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 255
                Break("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 256
        ;
#line 256
        delete *(l.Get() + i);
        l.Remove(i);
    };
    
#line 269
    template < class _1 >
    inline void Array < _1 >::RemoveLast()
    {
        {
#line 269
            if (!(GetCount()))
            {
#line 269
                Break("Assertion failed: GetCount()");
            }
        }
#line 269
        ;
#line 269
        Remove(GetCount() - 1);
    };
    
#line 219
    template < class _1 >
    inline void Array < _1 >::Reserve(int i)
    {
#line 219
        l.Reserve(i);
    };
    
#line 220
    template < class _1 >
    inline void Array < _1 >::SetCount(int new_count)
    {
#line 221
        int count = l.GetCount();
        if (new_count == count)
#line 222
            return;
        if (new_count > count)
        {
#line 224
            l.SetCount(new_count);
            for (int i = count; i < new_count; i ++ )
                l[i] = new _1;
        }
        else
        {
#line 229
            for (int i = count - 1; i >= new_count; i -- )
                delete l[i];
            l.SetCount(new_count);
        }
    };
    
#line 278
    template < class _1 >
    inline _1& Array < _1 >::Top()
    {
        {
#line 279
            if (!(GetCount() > 0))
            {
#line 279
                Break("Assertion failed: GetCount() > 0");
            }
        }
#line 280
        ;
#line 280
        return **(l.Get() + l.GetCount() - 1);
    };
    
#line 208
    template < class _1 >
    inline C::ConstFwdPtrIterator < _1 > Array < _1 >::begin() const
    {
#line 208
        return Begin();
    };
    
#line 206
    template < class _1 >
    inline C::FwdPtrIterator < _1 > Array < _1 >::begin()
    {
#line 206
        return Begin();
    };
    
    template < class _1 >
    inline C::ConstFwdPtrIterator < _1 > Array < _1 >::end() const
    {
#line 209
        return End();
    };
    
#line 207
    template < class _1 >
    inline C::FwdPtrIterator < _1 > Array < _1 >::end()
    {
#line 207
        return End();
    };
    
#line 214
    template < class _1 >
    inline C::BwdPtrIterator < _1 > Array < _1 >::rbegin()
    {
#line 214
        return RBegin();
    };
    
#line 216
    template < class _1 >
    inline C::ConstBwdPtrIterator < _1 > Array < _1 >::rbegin() const
    {
#line 216
        return RBegin();
    };
    
#line 215
    template < class _1 >
    inline C::BwdPtrIterator < _1 > Array < _1 >::rend()
    {
#line 215
        return REnd();
    };
    
#line 217
    template < class _1 >
    inline C::ConstBwdPtrIterator < _1 > Array < _1 >::rend() const
    {
#line 217
        return REnd();
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
    
#line 706 "../../src/Com/String.fog"
    inline Exc::Exc() {};
    
#line 707
    inline Exc::Exc(const String& s)
    :
        String(s)
    {};
    
#line 86 "../../src/Com/Vector.fog"
    template < class _1 >
    inline FutureOne < _1 >::FutureOne() {};
    
#line 109
    template < class _1 >
    inline _1 *FutureOne < _1 >::operator= (_1 *o)
    {
#line 109
        Set(o);
#line 109
        return o;
    };
    
#line 93
    template < class _1 >
    inline void FutureOne < _1 >::Clear()
    {
#line 93
        one.Clear();
#line 93
        cond.SetReady(false);
    };
    
#line 95
    template < class _1 >
    inline _1 *FutureOne < _1 >::Detach()
    {
#line 95
        _1 * o = one.Detach();
#line 95
        cond.SetReady(false);
#line 95
        return o;
    };
    
#line 94
    template < class _1 >
    inline _1 *FutureOne < _1 >::Get()
    {
#line 94
        if (one.IsEmpty())
#line 94
            return 0;
#line 94
        return&*one;
    };
    
#line 96
    template < class _1 >
    inline bool FutureOne < _1 >::IsEmpty() const
    {
#line 96
        return one.IsEmpty();
    };
    
#line 88
    template < class _1 >
    inline void FutureOne < _1 >::Set(_1 *o)
    {
#line 89
        Clear();
        one = o;
        cond.SetReady(o != 0);
    };
    
#line 97
    template < class _1 >
    inline void FutureOne < _1 >::Wait()
    {
#line 98
        if (cond.IsReady())
        {
#line 99
            if (!one.IsEmpty())
#line 99
                return;
            cond.SetReady(false);
        }
        else
        {
#line 103
            if (!one.IsEmpty())
            {
#line 103
                cond.SetReady();
#line 103
                return;
            }
        }
#line 105
        cond.Wait();
    };
    
#line 54
    template < class _1 >
    inline One < _1 >::One()
    :
        obj(0)
    {};
    
#line 55
    template < class _1 >
    inline One < _1 >::One(One& o)
    :
        obj(0)
    {
#line 55
        obj = o.obj;
#line 55
        o.obj = 0;
    };
    
#line 56
    template < class _1 >
    inline One < _1 >::One(_1 *obj)
    :
        obj(obj)
    {};
    
#line 57
    template < class _1 >
    inline One < _1 >::~One()
    {
#line 57
        Clear();
    };
    
#line 73
    template < class _1 >
    inline bool One < _1 >::operator!= (void *ptr)
    {
#line 73
        return ptr != obj;
    };
    
#line 66
    template < class _1 >
    inline _1& One < _1 >::operator*()
    {
        {
#line 66
            if (!(obj))
            {
#line 66
                Break("Assertion failed: obj");
            }
        }
#line 66
        ;
#line 66
        return *obj;
    };
    
#line 67
    template < class _1 >
    inline const _1& One < _1 >::operator*() const
    {
        {
#line 67
            if (!(obj))
            {
#line 67
                Break("Assertion failed: obj");
            }
        }
#line 67
        ;
#line 67
        return *obj;
    };
    
#line 61
    template < class _1 >
    inline void One < _1 >::operator= (_1 *obj)
    {
#line 61
        Clear();
#line 61
        this -> obj = obj;
    };
    
#line 72
    template < class _1 >
    inline One < _1 >::operator bool() const
    {
#line 72
        return !IsEmpty();
    };
    
#line 60
    template < class _1 >
    inline void One < _1 >::Clear()
    {
#line 60
        if (obj)
        {
#line 60
            delete obj;
#line 60
            obj = 0;
        }
    };
    
#line 59
    template < class _1 >
    inline void One < _1 >::Create()
    {
#line 59
        Clear();
#line 59
        obj = new _1;
    };
    
#line 77
    template < class _1 >
    template < class _2 >
    inline void One < _1 >::CreateDerived()
    {
#line 77
        Clear();
#line 77
        obj = new _2;
    };
    
#line 68
    template < class _1 >
    inline _1 *One < _1 >::Get()
    {
#line 68
        return obj;
    };
    
#line 69
    template < class _1 >
    inline const _1 *One < _1 >::Get() const
    {
#line 69
        return obj;
    };
    
#line 78
    template < class _1 >
    template < class _2 >
    inline _2 *One < _1 >::GetDerived()
    {
#line 78
        return dynamic_cast< _2 * >(obj);
    };
    
#line 62
    template < class _1 >
    inline bool One < _1 >::Is() const
    {
#line 62
        return obj != 0;
    };
    
#line 63
    template < class _1 >
    inline bool One < _1 >::IsEmpty() const
    {
#line 63
        return obj == 0;
    };
    
#line 70
    template < class _1 >
    inline _1& One < _1 >::Value()
    {
#line 70
        return *obj;
    };
    
#line 122
    template < class _1 >
    inline Optional < _1 >::Optional()
    :
        obj(0)
    {};
    
#line 127
    template < class _1 >
    inline Optional < _1 >::Optional(_1 *obj)
    :
        obj(obj)
    {};
    
#line 126
    template < class _1 >
    inline Optional < _1 >::Optional(const Nuller& n)
    :
        obj(0)
    {};
    
#line 129
    template < class _1 >
    inline Optional < _1 >::~Optional()
    {
#line 129
        Clear();
    };
    
#line 143
    template < class _1 >
    inline _1& Optional < _1 >::operator*()
    {
#line 143
        return *obj;
    };
    
#line 134
    template < class _1 >
    inline void Optional < _1 >::operator= (const Nuller& )
    {
#line 134
        Clear();
    };
    
#line 135
    template < class _1 >
    inline void Optional < _1 >::operator= (const _1& obj)
    {
#line 135
        Clear();
#line 135
        this -> obj = new _1(obj);
    };
    
#line 142
    template < class _1 >
    inline Optional < _1 >::operator bool() const
    {
#line 142
        return obj != 0;
    };
    
#line 133
    template < class _1 >
    inline void Optional < _1 >::Clear()
    {
#line 133
        if (obj)
        {
#line 133
            delete obj;
#line 133
            obj = 0;
        }
    };
    
#line 131
    template < class _1 >
    inline void Optional < _1 >::Create()
    {
#line 131
        Clear();
#line 131
        obj = new _1;
    };
    
#line 132
    template < class _1 >
    template < class _2 >
    inline void Optional < _1 >::Create1(const _2& arg)
    {
#line 132
        Clear();
#line 132
        this -> obj = new _1(arg);
    };
    
#line 140
    template < class _1 >
    inline _1& Optional < _1 >::GetValue() const
    {
#line 140
        return *obj;
    };
    
#line 139
    template < class _1 >
    inline bool Optional < _1 >::IsEmpty() const
    {
#line 139
        return obj == 0;
    };
    
#line 19
    template < class _1 >
    inline Pick < _1 >::Pick(_1& var)
    :
        var(&var)
    {};
    
#line 20
    template < class _1 >
    inline Pick < _1 >::Pick(const Pick& p)
    :
        var(p.var)
    {};
    
#line 22
    template < class _1 >
    inline _1& Pick < _1 >::Get() const
    {
#line 22
        return *var;
    };
    
#line 24
    template < class _1 >
    inline Pick < _1 > Pick < _1 >::Ptr(_1 *p)
    {
#line 24
        return Pick < _1 > (p);
    };
    
#line 57 "../../src/Com/Algorithm.fog"
    inline RNG::RNG()
    {
#line 57
        Seed();
    };
    
#line 61
    inline RNG::operator uint64()
    {
#line 61
        return Get();
    };
    
#line 60
    inline uint64 RNG::Get()
    {
#line 60
        return sNext(state);
    };
    
#line 68
    inline RNG& RNG::Local()
    {
#line 68
        static thread_local RNG r;
#line 68
        return r;
    };
    
#line 59
    inline uint64 RNG::Random(uint64 max)
    {
#line 59
        return Get() % max;
    };
    
    inline void RNG::Seed()
    {
#line 62
        sSeed(state);
    };
    
#line 417 "../../src/Com/String.fog"
    inline bool String::operator!= (const String& s) const
    {
#line 417
        return !(*this == s);
    };
    
#line 422
    inline String& String::operator+= (const String& s)
    {
#line 422
        Cat(s);
#line 422
        return *this;
    };
    
#line 423
    inline String& String::operator<< (const String& s)
    {
#line 423
        Cat(s);
#line 423
        return *this;
    };
    
#line 424
    inline String& String::operator<< (int i)
    {
#line 424
        Cat(IntStr(i));
#line 424
        return *this;
    };
    
#line 131
    inline String& String::operator= (const Char *c)
    {
#line 131
        return Set(c, C::StringLength(c));
    };
    
#line 419
    inline String::Char String::operator[](int i) const
    {
#line 419
        return At(i);
    };
    
#line 451
    inline String String::CharoString() const
    {
#line 451
        return *this;
    };
    
#line 686
    inline String::ConstChar *String::Empty()
    {
#line 687
        static Char buf[1] = 
        {
            0
        };
#line 688
        return buf;
    };
    
#line 410
    inline const String::Char *String::End() const
    {
#line 410
        return Begin() + GetCount();
    };
    
#line 284
    inline int String::GetCount() const
    {
#line 284
        return count;
    };
    
#line 428
    inline int String::HexInt(const String& s)
    {
#line 428
        return CharHexInt(s.Begin());
    };
    
#line 285
    inline bool String::IsEmpty() const
    {
#line 285
        return count == 0;
    };
    
#line 368
    inline String String::Left(int i) const
    {
#line 368
        return Mid(0, i);
    };
    
#line 427
    inline int String::OctInt(const String& s)
    {
#line 427
        return CharOctInt(s.Begin());
    };
    
#line 300
    inline int String::ReverseFind(const String& str) const
    {
#line 300
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 369
    inline String String::Right(int i) const
    {
#line 369
        return Mid(GetCount() - i, i);
    };
    
#line 431
    inline double String::StrDbl(const String& s)
    {
#line 431
        return CharDbl(s.Begin());
    };
    
#line 429
    inline int String::StrInt(const String& s)
    {
#line 429
        return CharInt(s.Begin());
    };
    
#line 430
    inline int64 String::StrInt64(const String& s)
    {
#line 430
        return CharInt64(s.Begin());
    };
    
    namespace Tester
    {
#line 26 "ComTest.mfog"
        inline void App::Run()
        {
#line 27
            uint64 v = 4294967295U;
            {
#line 28
                if (!(sizeof (v) == 8))
                {
#line 28
                    Break("Assertion failed: sizeof(v) == 8");
                }
            }
#line 29
            ;
            VoidPtr p;
            {
#line 31
                if (!(p == Null))
                {
#line 31
                    Break("Assertion failed: p == Null");
                }
            }
#line 32
            ;
            {
#line 33
                if (!(SignificantBits(0x8000) == 16))
                {
#line 33
                    Break("Assertion failed: SignificantBits(0x8000) == 16");
                }
            }
#line 34
            ;
            {
#line 34
                if (!(SignificantBits64(0x8000) == 16))
                {
#line 34
                    Break("Assertion failed: SignificantBits64(0x8000) == 16");
                }
            }
#line 35
            ;
            CombineHash ch;
            ch.Put(777999777).Put(123).Put64(0xF0F0F0F0F0F0F0F0);
            dword hash = ch;
            {
#line 39
                if (!(hash == 1894504625))
                {
#line 39
                    Break("Assertion failed: hash == 1894504625");
                }
            }
#line 40
            ;
#line 40
            int a = 0;
            int b = 1;
            {
#line 42
                if (!(min(a, b) < max(a, b)))
                {
#line 42
                    Break("Assertion failed: min(a, b) < max(a, b)");
                }
            }
#line 43
            ;
            int r = Random();
            double d = Randomf();
            int j = d;
#line 49
            const char * test_str = "abcdef";
            int test_strlen = C::StringLength(test_str);
            {
#line 51
                if (!(FindIf(test_str, test_str + test_strlen, &TestCmp)))
                {
#line 51
                    Break("Assertion failed: FindIf(test_str, test_str + test_strlen, &TestCmp)");
                }
            }
#line 52
            ;
            {
                if (!(String("test") == "test"))
                {
#line 54
                    Break("Assertion failed: String(\"test\") == \"test\"");
                }
            }
#line 55
            ;
            {
#line 55
                if (!(String::DblStr(1.2) == "1.2"))
                {
#line 55
                    Break("Assertion failed: String::DblStr(1.2) == \"1.2\"");
                }
            }
#line 56
            ;
            {
#line 56
                if (!("abc" + String("def") == "abcdef"))
                {
#line 56
                    Break("Assertion failed: \"abc\" + String(\"def\") == \"abcdef\"");
                }
            }
#line 57
            ;
            {
#line 57
                if (!(String("abc") + "def" == "abcdef"))
                {
#line 57
                    Break("Assertion failed: String(\"abc\") + \"def\" == \"abcdef\"");
                }
            }
#line 58
            ;
            {
#line 58
                if (!(ToString(ToWString < String > ("abc")) == "abc"))
                {
#line 58
                    Break("Assertion failed: ToString(ToWString<String>(\"abc\")) == \"abc\"");
                }
            }
#line 59
            ;
            {
#line 59
                if (!(ToInt < String > ("123") == 123))
                {
#line 59
                    Break("Assertion failed: ToInt<String>(\"123\") == 123");
                }
            }
#line 60
            ;
            {
#line 60
                if (!(ToString(123) == "123"))
                {
#line 60
                    Break("Assertion failed: ToString(123) == \"123\"");
                }
            }
#line 61
            ;
            {
#line 61
                if (!(HexStr((void * )0x123f) == "0x123F"))
                {
#line 61
                    Break("Assertion failed: HexStr((void*)0x123f) == \"0x123F\"");
                }
            }
#line 62
            ;
#line 64
            SomeTuple2 ttt = 
            {
                1,
                1.2
            };
            {
#line 65
                if (!(ToString(ttt) == "1, 1.2"))
                {
#line 65
                    Break("Assertion failed: ToString(ttt) == \"1, 1.2\"");
                }
            }
#line 66
            ;
            SomeRefTuple2 tttref(ttt.a, ttt.b);
            {
#line 68
                if (!(ToString(tttref) == "1, 1.2"))
                {
#line 68
                    Break("Assertion failed: ToString(tttref) == \"1, 1.2\"");
                }
            }
#line 69
            ;
            One < String > onestr;
            onestr.Create();
            *onestr = "hello";
            {
#line 73
                if (!(*onestr == "hello"))
                {
#line 73
                    Break("Assertion failed: *onestr == \"hello\"");
                }
            }
#line 74
            ;
            One < VirtualBase > onebase;
            onebase.CreateDerived < DerivedBase > ();
            {
#line 77
                if (!(onebase.GetDerived < DerivedBase > ()-> a == 8))
                {
#line 77
                    Break("Assertion failed: onebase.GetDerived<DerivedBase>()->a == 8");
                }
            }
#line 78
            ;
            FutureOne < String > fone;
            fone = new String;
            fone.Wait();
#line 83
            Vector < String > strvec;
            Array < String > strarr;
            for (int i = 0; i < 3; i ++ )
                {
#line 86
                    strvec << IntStr(i);
                    strarr << IntStr(i);
                }
            for (int i = 0; i < 3; i ++ )
                {
                    {
#line 90
                        if (!(strvec[i] == strarr[i]))
                        {
#line 90
                            Break("Assertion failed: strvec[i] == strarr[i]");
                        }
                    }
#line 91
                    ;
                }
        };
        
#line 7
        inline bool App::TestCmp(const char& c, void *)
        {
#line 8
            return c == 'c';
        };
        
#line 18
        inline App::DerivedBase::DerivedBase()
        :
            a(8)
        {};
        
#line 12
        inline App::VirtualBase::VirtualBase()
        :
            a(3)
        {};
        
    };
#line 158 "../../src/Com/Vector.fog"
    template < class _1 >
    inline Vector < _1 >::Vector() {};
    
#line 159
    template < class _1 >
    inline Vector < _1 >::Vector(const Vector& v)
    :
        Base(v)
    {};
    
#line 417 "../../src/Com/String.fog"
    inline bool WString::operator!= (const WString& s) const
    {
#line 417
        return !(*this == s);
    };
    
#line 422
    inline WString& WString::operator+= (const WString& s)
    {
#line 422
        Cat(s);
#line 422
        return *this;
    };
    
#line 423
    inline WString& WString::operator<< (const WString& s)
    {
#line 423
        Cat(s);
#line 423
        return *this;
    };
    
#line 424
    inline WString& WString::operator<< (int i)
    {
#line 424
        Cat(IntStr(i));
#line 424
        return *this;
    };
    
#line 131
    inline WString& WString::operator= (const Char *c)
    {
#line 131
        return Set(c, C::StringLength(c));
    };
    
#line 419
    inline WString::Char WString::operator[](int i) const
    {
#line 419
        return At(i);
    };
    
#line 451
    inline WString WString::CharoString() const
    {
#line 451
        return *this;
    };
    
#line 686
    inline WString::ConstChar *WString::Empty()
    {
#line 687
        static Char buf[1] = 
        {
            0
        };
#line 688
        return buf;
    };
    
#line 410
    inline const WString::Char *WString::End() const
    {
#line 410
        return Begin() + GetCount();
    };
    
#line 284
    inline int WString::GetCount() const
    {
#line 284
        return count;
    };
    
#line 428
    inline int WString::HexInt(const WString& s)
    {
#line 428
        return CharHexInt(s.Begin());
    };
    
#line 285
    inline bool WString::IsEmpty() const
    {
#line 285
        return count == 0;
    };
    
#line 368
    inline WString WString::Left(int i) const
    {
#line 368
        return Mid(0, i);
    };
    
#line 427
    inline int WString::OctInt(const WString& s)
    {
#line 427
        return CharOctInt(s.Begin());
    };
    
#line 300
    inline int WString::ReverseFind(const WString& str) const
    {
#line 300
        return ReverseFind(str, GetCount() - 1);
    };
    
#line 369
    inline WString WString::Right(int i) const
    {
#line 369
        return Mid(GetCount() - i, i);
    };
    
#line 431
    inline double WString::StrDbl(const WString& s)
    {
#line 431
        return CharDbl(s.Begin());
    };
    
#line 429
    inline int WString::StrInt(const WString& s)
    {
#line 429
        return CharInt(s.Begin());
    };
    
#line 430
    inline int64 WString::StrInt64(const WString& s)
    {
#line 430
        return CharInt64(s.Begin());
    };
    
    namespace
    {
#line 720
        inline String operator+ (const char *c, const String& l)
        {
#line 721
            String s(c);
            s.Cat(l);
            return s;
        };
        
#line 777
        inline String DblStr(double d)
        {
#line 777
            return String::DblStr(d);
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
        
#line 773
        inline int HexInt(String s)
        {
#line 773
            return String::HexInt(s);
        };
        
#line 813
        inline String HexStr(uint64 p)
        {
#line 814
            String o("0x");
            bool zero = true;
            uint64 i = 64;
            do
                {
#line 818
                    i -= 4;
                    byte b = (p >> i) & 15ULL;
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
            return HexStr((uint64) p);
        };
        
#line 775
        inline String IntStr(int i)
        {
#line 775
            return String::IntStr(i);
        };
        
#line 776
        inline String IntStr64(int64 i)
        {
#line 776
            return String::IntStr64(i);
        };
        
#line 772
        inline int OctInt(String s)
        {
#line 772
            return String::OctInt(s);
        };
        
#line 770
        inline double StrDbl(String s)
        {
#line 770
            return String::StrDbl(s);
        };
        
#line 771
        inline int StrInt(String s)
        {
#line 771
            return String::StrInt(s);
        };
        
        inline int64 StrInt64(String s)
        {
#line 774
            return String::StrInt64(s);
        };
        
#line 801
        template < class _1 >
        inline int64 ToInt(const _1& o)
        {
#line 801
            return o.ToInt();
        };
        
#line 809
        template <>
        inline int64 ToInt < String > (const String& o)
        {
#line 809
            return StrInt(o);
        };
        
#line 802
        template <>
        inline int64 ToInt < bool > (const bool& o)
        {
#line 802
            return(int64) o;
        };
        
        template <>
        inline int64 ToInt < byte > (const byte& o)
        {
#line 805
            return(int64) o;
        };
        
#line 806
        template <>
        inline int64 ToInt < char > (const char& o)
        {
#line 806
            return(int64) o;
        };
        
#line 808
        template <>
        inline int64 ToInt < double > (const double& o)
        {
#line 808
            return(int64) o;
        };
        
#line 807
        template <>
        inline int64 ToInt < float > (const float& o)
        {
#line 807
            return(int64) o;
        };
        
#line 803
        template <>
        inline int64 ToInt < int > (const int& o)
        {
#line 803
            return(int64) o;
        };
        
#line 804
        template <>
        inline int64 ToInt < int64 > (const int64& o)
        {
#line 804
            return(int64) o;
        };
        
#line 785
        template < class _1 >
        inline String ToString(const _1& o)
        {
#line 785
            return o.ToString();
        };
        
#line 794
        template <>
        inline String ToString < String > (const String& o)
        {
#line 794
            return o;
        };
        
        template <>
        inline String ToString < WString > (const WString& o)
        {
#line 797
            return NativeUtf16To8(o.Begin());
        };
        
#line 786
        template <>
        inline String ToString < bool > (const bool& o)
        {
#line 786
            if (o)
#line 786
                return "true";
            else
#line 786
                return "false";
        };
        
#line 790
        template <>
        inline String ToString < byte > (const byte& o)
        {
#line 790
            return IntStr(o);
        };
        
#line 791
        template <>
        inline String ToString < char > (const char& o)
        {
#line 791
            String s;
#line 791
            s.Cat(o);
#line 791
            return s;
        };
        
#line 793
        template <>
        inline String ToString < double > (const double& o)
        {
#line 793
            return DblStr(o);
        };
        
#line 792
        template <>
        inline String ToString < float > (const float& o)
        {
#line 792
            return DblStr(o);
        };
        
#line 787
        template <>
        inline String ToString < int > (const int& o)
        {
#line 787
            return IntStr(o);
        };
        
#line 789
        template <>
        inline String ToString < int64 > (const int64& o)
        {
#line 789
            return IntStr64(o);
        };
        
#line 788
        template <>
        inline String ToString < uint32 > (const uint32& o)
        {
#line 788
            return IntStr64(o);
        };
        
#line 766
        inline String ToUpperFirst(const String& s)
        {
#line 767
            return ToUpper(s.Left(1)) + s.Mid(1);
        };
        
#line 796
        template < class _1 >
        inline WString ToWString(const _1& o)
        {
#line 796
            return o.ToWString();
        };
        
#line 798
        template <>
        inline WString ToWString < String > (const String& o)
        {
#line 798
            return NativeUtf8To16(o.Begin());
        };
        
    };
};

#endif
