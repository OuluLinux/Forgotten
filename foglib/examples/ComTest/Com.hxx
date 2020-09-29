/*!$@FOG@$!
 *	Generated at Tue Sep 29 13:48:51 2020
 *
 *	by fog 0.1.a of 12:17:36 Sep 29 2020
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
 *		../../src/Com/Shared.fog
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
};

namespace Com
{
#line 28 "../../src/Com/Lang.fog"
    typedef unsigned char Byte;
    
#line 29
    extern Byte ____unused_Byte;
};

namespace Com
{
#line 39 "../../src/Com/Defs.fog"
    typedef C::CPtr < const char > CString;
    
#line 40
    extern CString ____unused_CString;
};

namespace Com
{
#line 39
    typedef C::CPtr < const void > ConstVoidPtr;
    
#line 40
    extern ConstVoidPtr ____unused_ConstVoidPtr;
};

namespace Com
{
#line 28 "../../src/Com/Lang.fog"
    typedef unsigned long DWORD;
    
#line 29
    extern DWORD ____unused_DWORD;
};

namespace Com
{
#line 39 "../../src/Com/Defs.fog"
    typedef C::CPtr < void > VoidPtr;
    
#line 40
    extern VoidPtr ____unused_VoidPtr;
};

namespace Com
{
#line 28 "../../src/Com/Lang.fog"
    typedef unsigned char byte;
    
#line 29
    extern byte ____unused_byte;
};

namespace Com
{
#line 28
    typedef unsigned int uint32;
#line 28
    typedef uint32 dword;
    
#line 29
    extern dword ____unused_dword;
};

namespace Com
{
#line 28
    typedef short int16;
    
#line 29
    extern int16 ____unused_int16;
};

namespace Com
{
#line 28
    typedef int int32;
    
#line 29
    extern int32 ____unused_int32;
};

namespace Com
{
#line 28
    typedef long long int64;
    
#line 29
    extern int64 ____unused_int64;
};

namespace Com
{
#line 28
    typedef char int8;
    
#line 29
    extern int8 ____unused_int8;
};

namespace Com
{
#line 28
    typedef unsigned long long uint64;
#line 28
    typedef uint64 qword;
    
#line 29
    extern qword ____unused_qword;
};

namespace Com
{
#line 28
    typedef unsigned short uint16;
    
#line 29
    extern uint16 ____unused_uint16;
#line 29
    extern uint32 ____unused_uint32;
#line 29
    extern uint64 ____unused_uint64;
};

namespace Com
{
#line 28
    typedef unsigned char uint8;
    
#line 29
    extern uint8 ____unused_uint8;
};

namespace Com
{
#line 28
    typedef uint16 word;
    
#line 29
    extern word ____unused_word;
    
#line 16 "../../src/Com/Defs.fog"
    void Break(const char *msg);
#line 19 "../../src/Com/Native.fog"
    int64 DateSeconds(uint64 year, uint64 month, uint64 day);
#line 557 "../../src/Com/Vector.fog"
    template < class _1, class _2 >
    inline _1 FindIf(_1 first, _1 last, _2 pred);
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
#line 10 "../../src/Com/Defs.fog"
    void *MemoryAlloc(int sz);
#line 12
    int MemoryCompare(const void *m1, const void *m2, int sz);
    void *MemoryCopy(void *dest, const void *src, int sz);
#line 11
    void MemoryFree(void *ptr);
#line 14
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
    inline void Swap(_1& a, _1& b);
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
#line 235 "../../src/Com/Vector.fog"
        typedef const _1 ConstK;
#line 234
        typedef _1 IndirectK;
#line 236
        typedef C::FwdPtrIterator < _1 > Iterator;
        typedef C::BwdPtrIterator < _1 > RIterator;
        
#line 230
        C::DynArray < _1 * > l;
        
    public:
#line 240
        inline Array();
        inline ~Array();
#line 336
        inline Array < _1 > & operator<< (const _1& v);
#line 329
        inline void operator<<= (const Array& a);
#line 289
        inline _1& operator[](int i);
#line 295
        inline const _1& operator[](int i) const;
#line 280
        inline _1& Add();
#line 282
        inline _1& Add(_1 *k);
#line 281
        inline _1& Add(const _1& v);
#line 250
        inline C::ConstFwdPtrIterator < _1 > Begin() const;
#line 248
        inline C::FwdPtrIterator < _1 > Begin();
#line 316
        inline void Clear();
#line 287
        inline _1 *Detach(int i);
#line 251
        inline C::ConstFwdPtrIterator < _1 > End() const;
#line 249
        inline C::FwdPtrIterator < _1 > End();
#line 245
        inline _1 **Get() const;
#line 285
        inline int GetCount() const;
#line 246
        inline _1 **GetEnd() const;
#line 283
        inline _1& Insert(int i);
        inline _1& Insert(int i, const _1& key);
#line 286
        inline bool IsEmpty() const;
#line 256
        inline C::BwdPtrIterator < _1 > RBegin();
#line 258
        inline C::ConstBwdPtrIterator < _1 > RBegin() const;
#line 257
        inline C::BwdPtrIterator < _1 > REnd();
#line 259
        inline C::ConstBwdPtrIterator < _1 > REnd() const;
#line 306
        inline void Remove(const int *sorted_list, int n);
#line 300
        inline void Remove(int i);
#line 315
        inline void RemoveLast();
#line 265
        inline void Reserve(int i);
        inline void SetCount(int new_count);
#line 325
        inline _1& Top();
#line 254
        inline C::ConstFwdPtrIterator < _1 > begin() const;
#line 252
        inline C::FwdPtrIterator < _1 > begin();
#line 255
        inline C::ConstFwdPtrIterator < _1 > end() const;
#line 253
        inline C::FwdPtrIterator < _1 > end();
#line 260
        inline C::BwdPtrIterator < _1 > rbegin();
#line 262
        inline C::ConstBwdPtrIterator < _1 > rbegin() const;
#line 261
        inline C::BwdPtrIterator < _1 > rend();
#line 263
        inline C::ConstBwdPtrIterator < _1 > rend() const;
    };
};

namespace Com {
class Slot;
}

namespace Com
{
    class Attachable
    {
#line 50 "../../src/Com/Shared.fog"
        typedef C::FwdIterator < void * > Iter;
        
#line 48
        C::DynArray < void * > slots;
        
    public:
#line 70
        virtual ~Attachable();
#line 72
        inline void Attach(Slot& s);
#line 85
        void Detach(Slot *ptr);
#line 73
        void DetachAll();
#line 90
        inline Slot& Get(int i) const;
#line 89
        inline int GetCount() const;
#line 78
        bool IsAttached(Slot *ptr);
        
#line 42 "../../src/Com/Lang.fog"
        void AddSlot(Slot *ptr);
#line 52 "../../src/Com/Shared.fog"
        void DoAttach(Slot *s);
#line 57
        void DoDetach(Slot *s);
#line 39 "../../src/Com/Lang.fog"
        Slot& GetSlot(int i);
#line 41
        int GetSlotCount();
#line 40
        void RemoveSlot(int i);
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
    class Index
    {
    public:
#line 349 "../../src/Com/Vector.fog"
        typedef C::FwdPtrIterator < _1 > Iterator;
        typedef C::BwdPtrIterator < _1 > RIterator;
        
#line 345
        C::DynArray < unsigned int > hashes;
        C::DynArray < _1 > values;
        
    public:
#line 352
        inline Index();
#line 407
        inline void operator<<= (const Index& a);
#line 363
        inline const _1& operator[](int i) const;
#line 373
        inline const _1& Add(const _1& value);
#line 358
        inline C::ConstFwdPtrIterator < _1 > Begin() const;
#line 354
        inline C::FwdPtrIterator < _1 > Begin();
#line 402
        inline void Clear();
#line 359
        inline C::ConstFwdPtrIterator < _1 > End() const;
#line 356
        inline C::FwdPtrIterator < _1 > End();
#line 387
        inline int Find(const _1& key) const;
        inline int FindAdd(const _1& key);
#line 390
        inline int FindHash(uint32 hash) const;
#line 360
        inline _1 *Get();
#line 372
        inline int GetCount() const;
#line 361
        inline _1 *GetEnd();
#line 380
        inline _1& Insert(int i, const _1& value);
#line 403
        inline void Remove(int i);
#line 405
        inline void RemoveKey(const _1& key);
#line 404
        inline void RemoveLast();
#line 368
        inline void Set(const Index& i);
#line 355
        inline C::FwdPtrIterator < _1 > begin();
#line 357
        inline C::FwdPtrIterator < _1 > end();
    };
    
    template < class _1, class _2 >
    class ArrayMap
    {
    public:
#line 419
        typedef Array < _2 > ArrayV;
#line 418
        typedef Index < _1 > IndexK;
#line 519
        typedef C::FwdPairPtrIterator < _1, _2 > Iterator;
#line 420
        typedef ArrayMap < _1, _2 > MapKV;
#line 520
        typedef C::BwdPairPtrIterator < _1, _2 > RIterator;
        
#line 414
        Index < _1 > keys;
        Array < _2 > values;
        
    public:
#line 422
        inline ArrayMap();
#line 483
        inline void operator<<= (const ArrayMap& a);
#line 466
        inline _2& operator[](int i);
#line 465
        inline const _2& operator[](int i) const;
#line 428
        inline _2& Add(const _1& key);
#line 438
        inline _2& Add(const _1& key, _2 *value);
#line 433
        inline _2& Add(const _1& key, const _2& value);
#line 460
        inline _2& At(int i);
#line 455
        inline const _2& At(int i) const;
#line 540
        inline C::ConstFwdPairPtrIterator < _1, _2 > Begin() const;
#line 538
        inline C::FwdPairPtrIterator < _1, _2 > Begin();
#line 478
        inline void Clear();
#line 541
        inline C::ConstFwdPairPtrIterator < _1, _2 > End() const;
#line 539
        inline C::FwdPairPtrIterator < _1, _2 > End();
#line 470
        inline int Find(const _1& key) const;
#line 531
        inline C::FwdPairPtrIterator < _1, _2 > FindIterator(const _1& key) const;
#line 472
        inline _2 Get(const _1& key, _2 value);
#line 471
        inline _2& Get(const _1& key);
#line 443
        inline _2& GetAdd(const _1& key);
#line 473
        inline int GetCount() const;
#line 453
        inline const _1& GetKey(int i) const;
#line 424
        inline const Index < _1 > & GetKeys() const;
#line 521
        inline int GetPos(const Iterator& it);
#line 426
        inline Array < _2 > & GetValues();
#line 425
        inline const Array < _2 > & GetValues() const;
#line 450
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 530
        inline C::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 529
        inline C::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 528
        inline C::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 474
        inline bool IsEmpty() const;
#line 527
        inline void Remove(const Iterator& it);
#line 477
        inline void Remove(int i);
#line 476
        inline void RemoveKey(const _1& key);
#line 468
        inline _2& Top();
#line 544
        inline C::ConstFwdPairPtrIterator < _1, _2 > begin() const;
#line 542
        inline C::FwdPairPtrIterator < _1, _2 > begin();
#line 545
        inline C::ConstFwdPairPtrIterator < _1, _2 > end() const;
#line 543
        inline C::FwdPairPtrIterator < _1, _2 > end();
    };
    
    template < class _1 >
    class One
    {
    public:
#line 52
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
#line 16
        _1 *var;
        
    public:
#line 18
        inline Pick(_1& var);
        inline Pick(const Pick& p);
#line 21
        inline _1& Get() const;
        
    public:
#line 23
        inline static Pick < _1 > Make(_1 *p);
    };
    
    template < class _1 >
    class Optional
    {
    public:
#line 120
        typedef Com::Pick < Optional > PickOpt;
#line 119
        typedef Com::Pick < _1 > PickT;
        
#line 116
        _1 *obj;
        
    public:
#line 122
        inline Optional();
#line 126
        inline Optional(_1 *obj);
#line 124
        Optional(const Optional& opt);
#line 127
        Optional(const PickT& n);
#line 125
        Optional(const _1& obj);
#line 128
        inline ~Optional();
#line 141
        inline _1& operator*();
#line 139
        _1 *operator-> ();
#line 134
        void operator= (const Optional& o);
        void operator= (const PickOpt& n);
#line 133
        inline void operator= (const _1& obj);
#line 140
        inline operator bool() const;
#line 132
        inline void Clear();
#line 130
        inline void Create();
        template < class _2 >
        inline void Create1(const _2& arg);
#line 138
        inline _1& GetValue() const;
#line 137
        inline bool IsEmpty() const;
#line 136
        void Pick(Optional& o);
    };
    
    template < class _1 >
    struct Ptr
    {
#line 24 "../../src/Com/Defs.fog"
        _1 *value;
        
        inline Ptr();
        inline Ptr(_1 *p);
        inline void operator= (_1 *p);
#line 30
        inline bool operator== (const Ptr& p) const;
#line 29
        inline operator _1 * () const;
#line 33
        inline unsigned long long Int() const;
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
    
    class Slot
    {
#line 7 "../../src/Com/Shared.fog"
        Attachable *ptr;
        
    public:
        inline Slot();
        virtual ~Slot();
#line 42
        inline Attachable& operator*() const;
#line 37
        inline Attachable *operator-> () const;
        inline operator bool() const;
#line 13
        virtual bool CanAttach(Attachable& a);
#line 29
        void Clear();
#line 39
        inline Attachable& Get() const;
        inline Attachable *GetPtr() const;
#line 16
        inline bool IsEmpty() const;
        void Set(Attachable& a);
#line 15
        inline void SetPtr(Attachable *p);
#line 23
        void TestSet(Attachable& a);
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
#line 28 "ComTest.mfog"
            inline void Run();
            
#line 166
            inline void TestShared();
            
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
            
            struct TestCmp
            {
#line 8 "ComTest.mfog"
                inline bool operator()(const char& c);
            };
            
            struct VirtualBase
            {
#line 17
                int a;
                
#line 14
                inline VirtualBase();
                virtual ~VirtualBase();
            };
            
            struct DerivedBase : public Com::Tester::App::VirtualBase
            {
#line 22
                int a;
                
#line 20
                inline DerivedBase();
            };
        };
    };
    
    template < class _1 >
    class Vector : public C::DynArray < _1 >
    {
#line 150 "../../src/Com/Vector.fog"
        typedef C::DynArray < _1 > Base;
        
    public:
#line 155
        typedef C::ConstFwdIterator < _1 > ConstIterator;
        typedef C::ConstBwdIterator < _1 > ConstRIterator;
        typedef C::FwdIterator < _1 > Iterator;
        typedef C::BwdIterator < _1 > RIterator;
        
    public:
#line 160
        inline Vector();
        inline Vector(const Vector& v);
#line 166
        inline String Join(String join_str = "", bool ignore_empty = true) const;
#line 180
        inline void Split(String to_split, String split_str, bool ignore_empty = true);
    };
    
    template < class _1, class _2 >
    class VectorMap
    {
    public:
#line 419
        typedef Vector < _2 > ArrayV;
#line 418
        typedef Index < _1 > IndexK;
#line 490
        typedef C::FwdPairIterator < _1, _2 > Iterator;
#line 420
        typedef VectorMap < _1, _2 > MapKV;
#line 491
        typedef C::BwdPairIterator < _1, _2 > RIterator;
        
#line 414
        Index < _1 > keys;
        Vector < _2 > values;
        
    public:
#line 422
        inline VectorMap();
#line 483
        inline void operator<<= (const VectorMap& a);
#line 466
        inline _2& operator[](int i);
#line 465
        inline const _2& operator[](int i) const;
#line 428
        inline _2& Add(const _1& key);
#line 438
        inline _2& Add(const _1& key, _2 *value);
#line 433
        inline _2& Add(const _1& key, const _2& value);
#line 460
        inline _2& At(int i);
#line 455
        inline const _2& At(int i) const;
#line 511
        inline C::ConstFwdPairIterator < _1, _2 > Begin() const;
#line 509
        inline C::FwdPairIterator < _1, _2 > Begin();
#line 478
        inline void Clear();
#line 512
        inline C::ConstFwdPairIterator < _1, _2 > End() const;
#line 510
        inline C::FwdPairIterator < _1, _2 > End();
#line 470
        inline int Find(const _1& key) const;
#line 502
        inline C::FwdPairIterator < _1, _2 > FindIterator(const _1& key) const;
#line 472
        inline _2 Get(const _1& key, _2 value);
#line 471
        inline _2& Get(const _1& key);
#line 443
        inline _2& GetAdd(const _1& key);
#line 473
        inline int GetCount() const;
#line 453
        inline const _1& GetKey(int i) const;
#line 424
        inline const Index < _1 > & GetKeys() const;
#line 492
        inline int GetPos(const Iterator& it);
#line 426
        inline Vector < _2 > & GetValues();
#line 425
        inline const Vector < _2 > & GetValues() const;
#line 450
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 501
        inline C::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 500
        inline C::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 499
        inline C::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 474
        inline bool IsEmpty() const;
#line 498
        inline void Remove(const Iterator& it);
#line 477
        inline void Remove(int i);
#line 476
        inline void RemoveKey(const _1& key);
#line 468
        inline _2& Top();
#line 515
        inline C::ConstFwdPairIterator < _1, _2 > begin() const;
#line 513
        inline C::FwdPairIterator < _1, _2 > begin();
#line 516
        inline C::ConstFwdPairIterator < _1, _2 > end() const;
#line 514
        inline C::FwdPairIterator < _1, _2 > end();
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
#line 809
        inline void FromString(const String& s, String& o);
#line 805
        inline void FromString(const String& s, byte& o);
#line 804
        inline void FromString(const String& s, int64& o);
#line 803
        inline void FromString(const String& s, uint32& o);
#line 800
        template < class _1 >
        inline void FromString(const String& s, _1& o);
#line 801
        inline void FromString(const String& s, bool& o);
#line 806
        inline void FromString(const String& s, char& o);
#line 808
        inline void FromString(const String& s, double& o);
#line 807
        inline void FromString(const String& s, float& o);
#line 802
        inline void FromString(const String& s, int& o);
#line 821
        inline int HexDigit(int c);
        inline int HexDigitLower(int c);
#line 773
        inline int HexInt(String s);
#line 823
        inline String HexStr(uint64 p);
#line 839
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
#line 811
        template < class _1 >
        inline int64 ToInt(const _1& o);
#line 819
        template <>
        inline int64 ToInt < String > (const String& o);
#line 812
        template <>
        inline int64 ToInt < bool > (const bool& o);
#line 815
        template <>
        inline int64 ToInt < byte > (const byte& o);
#line 816
        template <>
        inline int64 ToInt < char > (const char& o);
        template <>
        inline int64 ToInt < double > (const double& o);
#line 817
        template <>
        inline int64 ToInt < float > (const float& o);
#line 813
        template <>
        inline int64 ToInt < int > (const int& o);
#line 814
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
#line 557 "../../src/Com/Vector.fog"
    template < class _1, class _2 >
    inline _1 FindIf(_1 first, _1 last, _2 pred)
    {
#line 559
        while (first != last)
            {
#line 560
                int i = pred._2::operator()(*first);
                if (i)
#line 561
                    return first;
#line 563
                ++ first;
            }
#line 566
        return last;
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
    
#line 28 "../../src/Com/Vector.fog"
    template < class _1 >
    inline void Swap(_1& a, _1& b)
    {
#line 30
        uint8 tmp[sizeof (_1)];
        MemoryCopy(tmp, &a, sizeof (_1));
        MemoryCopy(&a, &b, sizeof (_1));
        MemoryCopy(&b, tmp, sizeof (_1));
    };
    
#line 11 "../../src/Com/Algorithm.fog"
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
    
#line 240 "../../src/Com/Vector.fog"
    template < class _1 >
    inline Array < _1 >::Array() {};
    
#line 241
    template < class _1 >
    inline Array < _1 >::~Array()
    {
#line 241
        Clear();
    };
    
#line 336
    template < class _1 >
    inline Array < _1 > & Array < _1 >::operator<< (const _1& v)
    {
#line 336
        Add(v);
#line 336
        return *this;
    };
    
#line 329
    template < class _1 >
    inline void Array < _1 >::operator<<= (const Array& a)
    {
#line 330
        Clear();
        l.SetCount(a.GetCount(), 0);
        for (int i = 0; i < a.GetCount(); i ++ )
            l[i] = new _1(*a.l[i]);
    };
    
#line 289
    template < class _1 >
    inline _1& Array < _1 >::operator[](int i)
    {
        {
#line 290
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 290
                Break("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 291
        ;
#line 291
        _1 * *it = l.Get();
        it = it + i;
        return **it;
    };
    
#line 295
    template < class _1 >
    inline const _1& Array < _1 >::operator[](int i) const
    {
        {
#line 296
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 296
                Break("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 297
        ;
#line 297
        return **(l.Get() + i);
    };
    
#line 280
    template < class _1 >
    inline _1& Array < _1 >::Add()
    {
#line 280
        _1 * k = new _1;
#line 280
        l.Add(k);
#line 280
        return *k;
    };
    
#line 282
    template < class _1 >
    inline _1& Array < _1 >::Add(_1 *k)
    {
#line 282
        l.Add(k);
#line 282
        return *k;
    };
    
#line 281
    template < class _1 >
    inline _1& Array < _1 >::Add(const _1& v)
    {
#line 281
        _1 * k = new _1(v);
#line 281
        l.Add(k);
#line 281
        return *k;
    };
    
#line 250
    template < class _1 >
    inline C::ConstFwdPtrIterator < _1 > Array < _1 >::Begin() const
    {
#line 250
        return Iterator(l.Begin());
    };
    
#line 248
    template < class _1 >
    inline C::FwdPtrIterator < _1 > Array < _1 >::Begin()
    {
#line 248
        return Iterator(l.Begin());
    };
    
#line 316
    template < class _1 >
    inline void Array < _1 >::Clear()
    {
#line 317
        C::DynArray < _1 * > tmp;
        Swap(tmp, l);
        _1 * *ptr = tmp.Get();
        _1 * *end = ptr + tmp.GetCount();
        while (ptr != end)
            delete *(ptr ++ );
    };
    
#line 287
    template < class _1 >
    inline _1 *Array < _1 >::Detach(int i)
    {
#line 287
        _1 * o = l[i];
#line 287
        l.Remove(i);
#line 287
        return o;
    };
    
#line 251
    template < class _1 >
    inline C::ConstFwdPtrIterator < _1 > Array < _1 >::End() const
    {
#line 251
        return Iterator(l.End());
    };
    
#line 249
    template < class _1 >
    inline C::FwdPtrIterator < _1 > Array < _1 >::End()
    {
#line 249
        return Iterator(l.End());
    };
    
#line 245
    template < class _1 >
    inline _1 **Array < _1 >::Get() const
    {
#line 245
        return l.Get();
    };
    
#line 285
    template < class _1 >
    inline int Array < _1 >::GetCount() const
    {
#line 285
        return l.GetCount();
    };
    
#line 246
    template < class _1 >
    inline _1 **Array < _1 >::GetEnd() const
    {
#line 246
        return l.GetEnd();
    };
    
#line 283
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i)
    {
#line 283
        return *l.Insert(i, new _1);
    };
    
#line 284
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i, const _1& key)
    {
#line 284
        return *l.Insert(i, new _1(key));
    };
    
#line 286
    template < class _1 >
    inline bool Array < _1 >::IsEmpty() const
    {
#line 286
        return GetCount() == 0;
    };
    
#line 256
    template < class _1 >
    inline C::BwdPtrIterator < _1 > Array < _1 >::RBegin()
    {
#line 256
        return RIterator(l.End() - 1);
    };
    
#line 258
    template < class _1 >
    inline C::ConstBwdPtrIterator < _1 > Array < _1 >::RBegin() const
    {
#line 258
        return RIterator(l.End() - 1);
    };
    
#line 257
    template < class _1 >
    inline C::BwdPtrIterator < _1 > Array < _1 >::REnd()
    {
#line 257
        return RIterator(l.Begin() - 1);
    };
    
#line 259
    template < class _1 >
    inline C::ConstBwdPtrIterator < _1 > Array < _1 >::REnd() const
    {
#line 259
        return RIterator(l.Begin() - 1);
    };
    
#line 306
    template < class _1 >
    inline void Array < _1 >::Remove(const int *sorted_list, int n)
    {
#line 307
        if (!n)
#line 307
            return;
        const int * it = sorted_list;
        const int * end = sorted_list + n;
        _1 * *vector = l.Get();
        while (it != end)
            (*(vector + *it ++ ))-> ~K();
        l.Remove(sorted_list, n);
    };
    
#line 300
    template < class _1 >
    inline void Array < _1 >::Remove(int i)
    {
        {
#line 301
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 301
                Break("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 302
        ;
#line 302
        delete *(l.Get() + i);
        l.Remove(i);
    };
    
#line 315
    template < class _1 >
    inline void Array < _1 >::RemoveLast()
    {
        {
#line 315
            if (!(GetCount()))
            {
#line 315
                Break("Assertion failed: GetCount()");
            }
        }
#line 315
        ;
#line 315
        Remove(GetCount() - 1);
    };
    
#line 265
    template < class _1 >
    inline void Array < _1 >::Reserve(int i)
    {
#line 265
        l.Reserve(i);
    };
    
#line 266
    template < class _1 >
    inline void Array < _1 >::SetCount(int new_count)
    {
#line 267
        int count = l.GetCount();
        if (new_count == count)
#line 268
            return;
        if (new_count > count)
        {
#line 270
            l.SetCount(new_count);
            for (int i = count; i < new_count; i ++ )
                l[i] = new _1;
        }
        else
        {
#line 275
            for (int i = count - 1; i >= new_count; i -- )
                delete l[i];
            l.SetCount(new_count);
        }
    };
    
#line 325
    template < class _1 >
    inline _1& Array < _1 >::Top()
    {
        {
#line 326
            if (!(GetCount() > 0))
            {
#line 326
                Break("Assertion failed: GetCount() > 0");
            }
        }
#line 327
        ;
#line 327
        return **(l.Get() + l.GetCount() - 1);
    };
    
#line 254
    template < class _1 >
    inline C::ConstFwdPtrIterator < _1 > Array < _1 >::begin() const
    {
#line 254
        return Begin();
    };
    
#line 252
    template < class _1 >
    inline C::FwdPtrIterator < _1 > Array < _1 >::begin()
    {
#line 252
        return Begin();
    };
    
    template < class _1 >
    inline C::ConstFwdPtrIterator < _1 > Array < _1 >::end() const
    {
#line 255
        return End();
    };
    
#line 253
    template < class _1 >
    inline C::FwdPtrIterator < _1 > Array < _1 >::end()
    {
#line 253
        return End();
    };
    
#line 260
    template < class _1 >
    inline C::BwdPtrIterator < _1 > Array < _1 >::rbegin()
    {
#line 260
        return RBegin();
    };
    
#line 262
    template < class _1 >
    inline C::ConstBwdPtrIterator < _1 > Array < _1 >::rbegin() const
    {
#line 262
        return RBegin();
    };
    
#line 261
    template < class _1 >
    inline C::BwdPtrIterator < _1 > Array < _1 >::rend()
    {
#line 261
        return REnd();
    };
    
#line 263
    template < class _1 >
    inline C::ConstBwdPtrIterator < _1 > Array < _1 >::rend() const
    {
#line 263
        return REnd();
    };
    
#line 422
    template < class _1, class _2 >
    inline ArrayMap < _1, _2 >::ArrayMap() {};
    
#line 483
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::operator<<= (const ArrayMap& a)
    {
#line 484
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 466
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::operator[](int i)
    {
#line 466
        return At(i);
    };
    
#line 465
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::operator[](int i) const
    {
#line 465
        return At(i);
    };
    
#line 428
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key)
    {
#line 429
        keys.Add(key);
        return values.Add();
    };
    
#line 438
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 439
        keys.Add(key);
        return values.Add(value);
    };
    
#line 433
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 434
        keys.Add(key);
        return values.Add(value);
    };
    
#line 460
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::At(int i)
    {
        {
#line 461
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 461
                Break("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 462
        ;
#line 462
        return values[i];
    };
    
#line 455
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::At(int i) const
    {
        {
#line 456
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 456
                Break("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 457
        ;
#line 457
        return values[i];
    };
    
#line 540
    template < class _1, class _2 >
    inline C::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin() const
    {
#line 540
        return Iterator(keys.Get(), values.Get());
    };
    
#line 538
    template < class _1, class _2 >
    inline C::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin()
    {
#line 538
        return Iterator(keys.Get(), values.Get());
    };
    
#line 478
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Clear()
    {
#line 479
        keys.Clear();
        values.Clear();
    };
    
#line 541
    template < class _1, class _2 >
    inline C::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End() const
    {
#line 541
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 539
    template < class _1, class _2 >
    inline C::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End()
    {
#line 539
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 470
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::Find(const _1& key) const
    {
#line 470
        return keys.Find(key);
    };
    
#line 531
    template < class _1, class _2 >
    inline C::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 532
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 534
            it += GetCount();
        else
#line 535
            it += pos;
        return it;
    };
    
#line 472
    template < class _1, class _2 >
    inline _2 ArrayMap < _1, _2 >::Get(const _1& key, _2 value)
    {
#line 472
        int i = Find(key);
#line 472
        if (i < 0)
#line 472
            return value;
#line 472
        return values[i];
    };
    
#line 471
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Get(const _1& key)
    {
#line 471
        return values[Find(key)];
    };
    
#line 443
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 444
        int i = keys.Find(key);
        if (i >= 0)
#line 445
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 473
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetCount() const
    {
#line 473
        return keys.GetCount();
    };
    
#line 453
    template < class _1, class _2 >
    inline const _1& ArrayMap < _1, _2 >::GetKey(int i) const
    {
#line 453
        return keys[i];
    };
    
#line 424
    template < class _1, class _2 >
    inline const Index < _1 > & ArrayMap < _1, _2 >::GetKeys() const
    {
#line 424
        return keys;
    };
    
#line 521
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 522
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 426
    template < class _1, class _2 >
    inline Array < _2 > & ArrayMap < _1, _2 >::GetValues()
    {
#line 426
        return values;
    };
    
#line 425
    template < class _1, class _2 >
    inline const Array < _2 > & ArrayMap < _1, _2 >::GetValues() const
    {
#line 425
        return values;
    };
    
#line 450
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 450
        keys.Insert(i, key);
#line 450
        return values.Insert(i);
    };
    
#line 451
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 451
        keys.Insert(i, key);
#line 451
        return values.Insert(i, value);
    };
    
#line 530
    template < class _1, class _2 >
    inline C::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 530
        int pos = GetPos(it);
#line 530
        Insert(pos, key);
#line 530
        Iterator cur = Begin();
#line 530
        cur += pos;
#line 530
        return cur;
    };
    
#line 529
    template < class _1, class _2 >
    inline C::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 529
        int pos = GetPos(it);
#line 529
        Insert(pos, key, value);
#line 529
        Iterator cur = Begin();
#line 529
        cur += pos;
#line 529
        return cur;
    };
    
#line 528
    template < class _1, class _2 >
    inline C::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 528
        int pos = GetPos(it);
#line 528
        Insert(pos, key, value);
#line 528
        Iterator cur = Begin();
#line 528
        cur += pos;
#line 528
        return cur;
    };
    
#line 474
    template < class _1, class _2 >
    inline bool ArrayMap < _1, _2 >::IsEmpty() const
    {
#line 474
        return GetCount() == 0;
    };
    
#line 527
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 527
        Remove(GetPos(it));
    };
    
#line 477
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(int i)
    {
        {
#line 477
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 477
                Break("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 477
        ;
#line 477
        keys.Remove(i);
#line 477
        values.Remove(i);
    };
    
#line 476
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 476
        int i = Find(key);
#line 476
        if (i >= 0)
#line 476
            Remove(i);
    };
    
#line 468
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Top()
    {
        {
#line 468
            if (!(GetCount() > 0))
            {
#line 468
                Break("Assertion failed: GetCount() > 0");
            }
        }
#line 468
        ;
#line 468
        return values.Top();
    };
    
#line 544
    template < class _1, class _2 >
    inline C::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin() const
    {
#line 544
        return Begin();
    };
    
#line 542
    template < class _1, class _2 >
    inline C::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin()
    {
#line 542
        return Begin();
    };
    
    template < class _1, class _2 >
    inline C::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end() const
    {
#line 545
        return End();
    };
    
#line 543
    template < class _1, class _2 >
    inline C::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end()
    {
#line 543
        return End();
    };
    
#line 72 "../../src/Com/Shared.fog"
    inline void Attachable::Attach(Slot& s)
    {
#line 72
        s.Set(*this);
    };
    
#line 90
    inline Slot& Attachable::Get(int i) const
    {
#line 90
        return *(Slot * ) slots[i];
    };
    
#line 89
    inline int Attachable::GetCount() const
    {
#line 89
        return slots.GetCount();
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
    
#line 352
    template < class _1 >
    inline Index < _1 >::Index() {};
    
#line 407
    template < class _1 >
    inline void Index < _1 >::operator<<= (const Index& a)
    {
#line 407
        Set(a);
    };
    
#line 363
    template < class _1 >
    inline const _1& Index < _1 >::operator[](int i) const
    {
        {
#line 364
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 364
                Break("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 365
        ;
#line 365
        return values[i];
    };
    
#line 373
    template < class _1 >
    inline const _1& Index < _1 >::Add(const _1& value)
    {
#line 374
        uint32 hash = GetHashValue(value);
        if (FindHash(hash) >= 0)
            throw Exc("Index has value already");
        hashes.Add(hash);
        return values.Add(value);
    };
    
#line 358
    template < class _1 >
    inline C::ConstFwdPtrIterator < _1 > Index < _1 >::Begin() const
    {
#line 358
        return Iterator(values.Begin());
    };
    
#line 354
    template < class _1 >
    inline C::FwdPtrIterator < _1 > Index < _1 >::Begin()
    {
#line 354
        return Iterator(values.Begin());
    };
    
#line 402
    template < class _1 >
    inline void Index < _1 >::Clear()
    {
#line 402
        hashes.Clear();
#line 402
        values.Clear();
    };
    
#line 359
    template < class _1 >
    inline C::ConstFwdPtrIterator < _1 > Index < _1 >::End() const
    {
#line 359
        return Iterator(values.End());
    };
    
#line 356
    template < class _1 >
    inline C::FwdPtrIterator < _1 > Index < _1 >::End()
    {
#line 356
        return Iterator(values.End());
    };
    
#line 387
    template < class _1 >
    inline int Index < _1 >::Find(const _1& key) const
    {
#line 387
        return FindHash(GetHashValue(key));
    };
    
#line 388
    template < class _1 >
    inline int Index < _1 >::FindAdd(const _1& key)
    {
#line 388
        int i = Find(key);
#line 388
        if (i >= 0)
#line 388
            return i;
#line 388
        i = GetCount();
#line 388
        Add(key);
#line 388
        return i;
    };
    
#line 390
    template < class _1 >
    inline int Index < _1 >::FindHash(uint32 hash) const
    {
#line 391
        unsigned int * begin = hashes.Get();
        unsigned int * it = begin;
        unsigned int * end = begin + hashes.GetCount();
        while (it != end)
            {
#line 395
                if (*it == hash)
                    return it - begin;
                it ++ ;
            }
        return - 1;
    };
    
#line 360
    template < class _1 >
    inline _1 *Index < _1 >::Get()
    {
#line 360
        return values.Get();
    };
    
#line 372
    template < class _1 >
    inline int Index < _1 >::GetCount() const
    {
#line 372
        return values.GetCount();
    };
    
#line 361
    template < class _1 >
    inline _1 *Index < _1 >::GetEnd()
    {
#line 361
        return values.GetEnd();
    };
    
#line 380
    template < class _1 >
    inline _1& Index < _1 >::Insert(int i, const _1& value)
    {
#line 381
        uint32 hash = GetHashValue(value);
        if (FindHash(hash) >= 0)
            throw Exc("Index has value already");
        hashes.Insert(i, hash);
        return values.Insert(i, value);
    };
    
#line 403
    template < class _1 >
    inline void Index < _1 >::Remove(int i)
    {
#line 403
        hashes.Remove(i);
#line 403
        values.Remove(i);
    };
    
#line 405
    template < class _1 >
    inline void Index < _1 >::RemoveKey(const _1& key)
    {
#line 405
        int i = Find(key);
#line 405
        if (i >= 0)
#line 405
            Remove(i);
    };
    
#line 404
    template < class _1 >
    inline void Index < _1 >::RemoveLast()
    {
        {
#line 404
            if (!(GetCount()))
            {
#line 404
                Break("Assertion failed: GetCount()");
            }
        }
#line 404
        ;
#line 404
        if (GetCount())
#line 404
            Remove(GetCount() - 1);
    };
    
#line 368
    template < class _1 >
    inline void Index < _1 >::Set(const Index& i)
    {
#line 369
        hashes <<= i.hashes;
        values <<= i.values;
    };
    
#line 355
    template < class _1 >
    inline C::FwdPtrIterator < _1 > Index < _1 >::begin()
    {
#line 355
        return Iterator(values.Begin());
    };
    
#line 357
    template < class _1 >
    inline C::FwdPtrIterator < _1 > Index < _1 >::end()
    {
#line 357
        return Iterator(values.End());
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
    
#line 126
    template < class _1 >
    inline Optional < _1 >::Optional(_1 *obj)
    :
        obj(obj)
    {};
    
#line 128
    template < class _1 >
    inline Optional < _1 >::~Optional()
    {
#line 128
        Clear();
    };
    
#line 141
    template < class _1 >
    inline _1& Optional < _1 >::operator*()
    {
#line 141
        return *obj;
    };
    
#line 133
    template < class _1 >
    inline void Optional < _1 >::operator= (const _1& obj)
    {
#line 133
        Clear();
#line 133
        this -> obj = new _1(obj);
    };
    
#line 140
    template < class _1 >
    inline Optional < _1 >::operator bool() const
    {
#line 140
        return obj != 0;
    };
    
#line 132
    template < class _1 >
    inline void Optional < _1 >::Clear()
    {
#line 132
        if (obj)
        {
#line 132
            delete obj;
#line 132
            obj = 0;
        }
    };
    
#line 130
    template < class _1 >
    inline void Optional < _1 >::Create()
    {
#line 130
        Clear();
#line 130
        obj = new _1;
    };
    
#line 131
    template < class _1 >
    template < class _2 >
    inline void Optional < _1 >::Create1(const _2& arg)
    {
#line 131
        Clear();
#line 131
        this -> obj = new _1(arg);
    };
    
#line 138
    template < class _1 >
    inline _1& Optional < _1 >::GetValue() const
    {
#line 138
        return *obj;
    };
    
#line 137
    template < class _1 >
    inline bool Optional < _1 >::IsEmpty() const
    {
#line 137
        return obj == 0;
    };
    
#line 18
    template < class _1 >
    inline Pick < _1 >::Pick(_1& var)
    :
        var(&var)
    {};
    
#line 19
    template < class _1 >
    inline Pick < _1 >::Pick(const Pick& p)
    :
        var(p.var)
    {};
    
#line 21
    template < class _1 >
    inline _1& Pick < _1 >::Get() const
    {
#line 21
        return *var;
    };
    
#line 23
    template < class _1 >
    inline Pick < _1 > Pick < _1 >::Make(_1 *p)
    {
#line 23
        return Pick < _1 > (p);
    };
    
#line 26 "../../src/Com/Defs.fog"
    template < class _1 >
    inline Ptr < _1 >::Ptr()
    :
        value(0)
    {};
    
#line 27
    template < class _1 >
    inline Ptr < _1 >::Ptr(_1 *p)
    :
        value(p)
    {};
    
#line 28
    template < class _1 >
    inline void Ptr < _1 >::operator= (_1 *p)
    {
#line 28
        value = p;
    };
    
#line 30
    template < class _1 >
    inline bool Ptr < _1 >::operator== (const Ptr& p) const
    {
#line 30
        return value == p.value;
    };
    
#line 29
    template < class _1 >
    inline Ptr < _1 >::operator _1 * () const
    {
#line 29
        return value;
    };
    
#line 33
    template < class _1 >
    inline unsigned long long Ptr < _1 >::Int() const
    {
#line 33
        return(unsigned long long) value;
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
    
#line 10 "../../src/Com/Shared.fog"
    inline Slot::Slot()
    :
        ptr(0)
    {};
    
#line 42
    inline Attachable& Slot::operator*() const
    {
#line 42
        return *ptr;
    };
    
#line 37
    inline Attachable *Slot::operator-> () const
    {
#line 37
        return ptr;
    };
    
#line 38
    inline Slot::operator bool() const
    {
#line 38
        return ptr != 0;
    };
    
#line 39
    inline Attachable& Slot::Get() const
    {
#line 39
        return *ptr;
    };
    
#line 40
    inline Attachable *Slot::GetPtr() const
    {
#line 40
        return ptr;
    };
    
#line 16
    inline bool Slot::IsEmpty() const
    {
#line 16
        return ptr == 0;
    };
    
#line 15
    inline void Slot::SetPtr(Attachable *p)
    {
#line 15
        ptr = p;
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
#line 28 "ComTest.mfog"
        inline void App::Run()
        {
#line 29
            uint64 v = 4294967295U;
            {
#line 30
                if (!(sizeof (v) == 8))
                {
#line 30
                    Break("Assertion failed: sizeof(v) == 8");
                }
            }
#line 31
            ;
            VoidPtr p;
            {
#line 33
                if (!(p == 0))
                {
#line 33
                    Break("Assertion failed: p == NULL");
                }
            }
#line 34
            ;
            {
#line 35
                if (!(SignificantBits(0x8000) == 16))
                {
#line 35
                    Break("Assertion failed: SignificantBits(0x8000) == 16");
                }
            }
#line 36
            ;
            {
#line 36
                if (!(SignificantBits64(0x8000) == 16))
                {
#line 36
                    Break("Assertion failed: SignificantBits64(0x8000) == 16");
                }
            }
#line 37
            ;
            CombineHash ch;
            ch.Put(777999777).Put(123).Put64(0xF0F0F0F0F0F0F0F0);
            dword hash = ch;
            {
#line 41
                if (!(hash == 1894504625))
                {
#line 41
                    Break("Assertion failed: hash == 1894504625");
                }
            }
#line 42
            ;
#line 42
            int a = 0;
            int b = 1;
            {
#line 44
                if (!(min(a, b) < max(a, b)))
                {
#line 44
                    Break("Assertion failed: min(a, b) < max(a, b)");
                }
            }
#line 45
            ;
            int r = Random();
            double d = Randomf();
            int j = d;
#line 51
            const char * test_str = "abcdef";
            int test_strlen = C::StringLength(test_str);
            {
#line 53
                if (!(FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2))
                {
#line 53
                    Break("Assertion failed: FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2");
                }
            }
#line 54
            ;
            {
                if (!(String("test") == "test"))
                {
#line 56
                    Break("Assertion failed: String(\"test\") == \"test\"");
                }
            }
#line 57
            ;
            {
#line 57
                if (!(String::DblStr(1.2) == "1.2"))
                {
#line 57
                    Break("Assertion failed: String::DblStr(1.2) == \"1.2\"");
                }
            }
#line 58
            ;
            {
#line 58
                if (!("abc" + String("def") == "abcdef"))
                {
#line 58
                    Break("Assertion failed: \"abc\" + String(\"def\") == \"abcdef\"");
                }
            }
#line 59
            ;
            {
#line 59
                if (!(String("abc") + "def" == "abcdef"))
                {
#line 59
                    Break("Assertion failed: String(\"abc\") + \"def\" == \"abcdef\"");
                }
            }
#line 60
            ;
            {
#line 60
                if (!(ToString(ToWString < String > ("abc")) == "abc"))
                {
#line 60
                    Break("Assertion failed: ToString(ToWString<String>(\"abc\")) == \"abc\"");
                }
            }
#line 61
            ;
            {
#line 61
                if (!(ToInt < String > ("123") == 123))
                {
#line 61
                    Break("Assertion failed: ToInt<String>(\"123\") == 123");
                }
            }
#line 62
            ;
            {
#line 62
                if (!(ToString(123) == "123"))
                {
#line 62
                    Break("Assertion failed: ToString(123) == \"123\"");
                }
            }
#line 63
            ;
            {
#line 63
                if (!(HexStr((void * )0x123f) == "0x123F"))
                {
#line 63
                    Break("Assertion failed: HexStr((void*)0x123f) == \"0x123F\"");
                }
            }
#line 64
            ;
#line 66
            SomeTuple2 ttt = 
            {
                1,
                1.2
            };
            {
#line 67
                if (!(ToString(ttt) == "1, 1.2"))
                {
#line 67
                    Break("Assertion failed: ToString(ttt) == \"1, 1.2\"");
                }
            }
#line 68
            ;
            SomeRefTuple2 tttref(ttt.a, ttt.b);
            {
#line 70
                if (!(ToString(tttref) == "1, 1.2"))
                {
#line 70
                    Break("Assertion failed: ToString(tttref) == \"1, 1.2\"");
                }
            }
#line 71
            ;
            One < String > onestr;
            onestr.Create();
            *onestr = "hello";
            {
#line 75
                if (!(*onestr == "hello"))
                {
#line 75
                    Break("Assertion failed: *onestr == \"hello\"");
                }
            }
#line 76
            ;
            One < VirtualBase > onebase;
            onebase.CreateDerived < DerivedBase > ();
            {
#line 79
                if (!(onebase.GetDerived < DerivedBase > ()-> a == 8))
                {
#line 79
                    Break("Assertion failed: onebase.GetDerived<DerivedBase>()->a == 8");
                }
            }
#line 80
            ;
            FutureOne < String > fone;
            fone = new String;
            fone.Wait();
#line 85
            Vector < String > strvec;
            Array < String > strarr;
            for (int i = 0; i < 3; i ++ )
                {
#line 88
                    strvec << IntStr(i);
                    strarr << IntStr(i);
                }
            for (int i = 0; i < 3; i ++ )
                {
                    {
#line 92
                        if (!(strvec[i] == strarr[i]))
                        {
#line 92
                            Break("Assertion failed: strvec[i] == strarr[i]");
                        }
                    }
#line 93
                    ;
                }
            Index < String > stridx;
            stridx.Add("abc");
            {
#line 97
                if (!(stridx.GetCount() == 1))
                {
#line 97
                    Break("Assertion failed: stridx.GetCount() == 1");
                }
            }
#line 98
            ;
            {
#line 98
                if (!(stridx.Find("abc") == 0))
                {
#line 98
                    Break("Assertion failed: stridx.Find(\"abc\") == 0");
                }
            }
#line 99
            ;
#line 99
            stridx.Add("def");
            {
#line 100
                if (!(stridx.Find("abc") == 0))
                {
#line 100
                    Break("Assertion failed: stridx.Find(\"abc\") == 0");
                }
            }
#line 101
            ;
            {
#line 101
                if (!(stridx.Find("def") == 1))
                {
#line 101
                    Break("Assertion failed: stridx.Find(\"def\") == 1");
                }
            }
#line 102
            ;
#line 104
            VectorMap < String, int > vmap;
            ArrayMap < String, int > amap;
#line 107
            vmap.Add("abc", 123);
            vmap.Add("def", 456);
            {
#line 109
                if (!(vmap.GetKeys().Find("abc") == 0))
                {
#line 109
                    Break("Assertion failed: vmap.GetKeys().Find(\"abc\") == 0");
                }
            }
#line 110
            ;
            {
#line 110
                if (!(vmap.GetValues()[0] == 123))
                {
#line 110
                    Break("Assertion failed: vmap.GetValues()[0] == 123");
                }
            }
#line 111
            ;
            {
#line 111
                if (!(vmap.Find("abc") == 0))
                {
#line 111
                    Break("Assertion failed: vmap.Find(\"abc\") == 0");
                }
            }
#line 112
            ;
            {
#line 112
                if (!(vmap.Find("dfasgsg") == - 1))
                {
#line 112
                    Break("Assertion failed: vmap.Find(\"dfasgsg\") == -1");
                }
            }
#line 113
            ;
            {
#line 113
                if (!(vmap.GetValues().Join() == "123456"))
                {
#line 113
                    Break("Assertion failed: vmap.GetValues().Join() == \"123456\"");
                }
            }
#line 114
            ;
#line 114
            Vector < int > vmap_keys;
            vmap_keys.Split(vmap.GetValues().Join(" "), " ");
            {
#line 116
                if (!(vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456))
                {
#line 116
                    Break("Assertion failed: vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456");
                }
            }
#line 117
            ;
#line 119
            amap.Add("abc", 123);
            amap.Add("def", 456);
            {
#line 121
                if (!(amap.GetKeys().Find("abc") == 0))
                {
#line 121
                    Break("Assertion failed: amap.GetKeys().Find(\"abc\") == 0");
                }
            }
#line 122
            ;
            {
#line 122
                if (!(amap.GetValues()[0] == 123))
                {
#line 122
                    Break("Assertion failed: amap.GetValues()[0] == 123");
                }
            }
#line 123
            ;
            {
#line 123
                if (!(amap.Find("abc") == 0))
                {
#line 123
                    Break("Assertion failed: amap.Find(\"abc\") == 0");
                }
            }
#line 124
            ;
            {
#line 124
                if (!(amap.Find("dfasgsg") == - 1))
                {
#line 124
                    Break("Assertion failed: amap.Find(\"dfasgsg\") == -1");
                }
            }
#line 125
            ;
#line 125
            C::FwdPairPtrIterator < String, int > it = amap.Begin();
            for (int i = 0; i < 2; i ++ )
                {
#line 127
                    if (i == 0)
                    {
                        {
#line 128
                            if (!(it.Key() == "abc"))
                            {
#line 128
                                Break("Assertion failed: it.Key() == \"abc\"");
                            }
                        }
#line 129
                        ;
                        {
#line 129
                            if (!(it.Value() == 123))
                            {
#line 129
                                Break("Assertion failed: it.Value() == 123");
                            }
                        }
#line 130
                        ;
                    }
                    else 
#line 131
                    if (i == 1)
                    {
                        {
#line 132
                            if (!(it.Key() == "def"))
                            {
#line 132
                                Break("Assertion failed: it.Key() == \"def\"");
                            }
                        }
#line 133
                        ;
                        {
#line 133
                            if (!(it.Value() == 456))
                            {
#line 133
                                Break("Assertion failed: it.Value() == 456");
                            }
                        }
#line 134
                        ;
                    }
#line 135
                    ++ it;
                }
            {
#line 140
                Attachable a;
                Slot s;
                a.Attach(s);
                s.Clear();
            }
#line 146
            TestShared();
        };
        
#line 166
        inline void App::TestShared()
        {
#line 167
            struct Dumber;
#line 171
            struct Dumb;
#line 208
            Break("TODO");
        };
        
#line 20
        inline App::DerivedBase::DerivedBase()
        :
            a(8)
        {};
        
#line 8
        inline bool App::TestCmp::operator()(const char& c)
        {
#line 9
            return c == 'c';
        };
        
#line 14
        inline App::VirtualBase::VirtualBase()
        :
            a(3)
        {};
        
    };
#line 160 "../../src/Com/Vector.fog"
    template < class _1 >
    inline Vector < _1 >::Vector() {};
    
#line 161
    template < class _1 >
    inline Vector < _1 >::Vector(const Vector& v)
    :
        Base(v)
    {};
    
#line 166
    template < class _1 >
    inline String Vector < _1 >::Join(String join_str, bool ignore_empty) const
    {
#line 167
        String out;
        ConstIterator end = Base::End();
        for (ConstIterator it = Base::Begin(); it != end; ++ it)
            {
#line 170
                String s = ToString < _1 > (*it);
                if (s.IsEmpty() && ignore_empty)
                    continue;
                
#line 173
                if (!out.IsEmpty())
                    out << join_str;
                out << s;
            }
        return out;
    };
    
    template < class _1 >
    inline void Vector < _1 >::Split(String to_split, String split_str, bool ignore_empty)
    {
#line 181
        Base::SetCount(0);
        if (to_split.IsEmpty() || split_str.IsEmpty())
            return;
#line 185
        int i = to_split.Find(split_str);
        if (i == - 1)
            FromString(to_split, Base::Add());
        else
        {
#line 189
            int j = 0;
            while (i >= 0)
                {
#line 191
                    String str = to_split.Mid(j, i - j);
                    if (str.GetCount() == 0)
                    {
#line 193
                        if (!ignore_empty)
                            FromString(str, Base::Add());
                    }
                    else
                        FromString(str, Base::Add());
                    i += split_str.GetCount();
                    j = i;
                    i = to_split.Find(split_str, i);
                }
            i = to_split.GetCount();
            String str = to_split.Mid(j, i - j);
            if (str.GetCount() == 0)
            {
#line 205
                if (!ignore_empty)
                    FromString(str, Base::Add());
            }
            else
            {
#line 209
                FromString(str, Base::Add());
            }
        }
    };
    
#line 422
    template < class _1, class _2 >
    inline VectorMap < _1, _2 >::VectorMap() {};
    
#line 483
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::operator<<= (const VectorMap& a)
    {
#line 484
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 466
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::operator[](int i)
    {
#line 466
        return At(i);
    };
    
#line 465
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::operator[](int i) const
    {
#line 465
        return At(i);
    };
    
#line 428
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key)
    {
#line 429
        keys.Add(key);
        return values.Add();
    };
    
#line 438
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 439
        keys.Add(key);
        return values.Add(value);
    };
    
#line 433
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 434
        keys.Add(key);
        return values.Add(value);
    };
    
#line 460
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::At(int i)
    {
        {
#line 461
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 461
                Break("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 462
        ;
#line 462
        return values[i];
    };
    
#line 455
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::At(int i) const
    {
        {
#line 456
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 456
                Break("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 457
        ;
#line 457
        return values[i];
    };
    
#line 511
    template < class _1, class _2 >
    inline C::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin() const
    {
#line 511
        return Iterator(keys.Get(), values.Get());
    };
    
#line 509
    template < class _1, class _2 >
    inline C::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin()
    {
#line 509
        return Iterator(keys.Get(), values.Get());
    };
    
#line 478
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Clear()
    {
#line 479
        keys.Clear();
        values.Clear();
    };
    
#line 512
    template < class _1, class _2 >
    inline C::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End() const
    {
#line 512
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 510
    template < class _1, class _2 >
    inline C::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End()
    {
#line 510
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 470
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::Find(const _1& key) const
    {
#line 470
        return keys.Find(key);
    };
    
#line 502
    template < class _1, class _2 >
    inline C::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 503
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 505
            it += GetCount();
        else
#line 506
            it += pos;
        return it;
    };
    
#line 472
    template < class _1, class _2 >
    inline _2 VectorMap < _1, _2 >::Get(const _1& key, _2 value)
    {
#line 472
        int i = Find(key);
#line 472
        if (i < 0)
#line 472
            return value;
#line 472
        return values[i];
    };
    
#line 471
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Get(const _1& key)
    {
#line 471
        return values[Find(key)];
    };
    
#line 443
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 444
        int i = keys.Find(key);
        if (i >= 0)
#line 445
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 473
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetCount() const
    {
#line 473
        return keys.GetCount();
    };
    
#line 453
    template < class _1, class _2 >
    inline const _1& VectorMap < _1, _2 >::GetKey(int i) const
    {
#line 453
        return keys[i];
    };
    
#line 424
    template < class _1, class _2 >
    inline const Index < _1 > & VectorMap < _1, _2 >::GetKeys() const
    {
#line 424
        return keys;
    };
    
#line 492
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 493
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 426
    template < class _1, class _2 >
    inline Vector < _2 > & VectorMap < _1, _2 >::GetValues()
    {
#line 426
        return values;
    };
    
#line 425
    template < class _1, class _2 >
    inline const Vector < _2 > & VectorMap < _1, _2 >::GetValues() const
    {
#line 425
        return values;
    };
    
#line 450
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 450
        keys.Insert(i, key);
#line 450
        return values.Insert(i);
    };
    
#line 451
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 451
        keys.Insert(i, key);
#line 451
        return values.Insert(i, value);
    };
    
#line 501
    template < class _1, class _2 >
    inline C::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 501
        int pos = GetPos(it);
#line 501
        Insert(pos, key);
#line 501
        Iterator cur = Begin();
#line 501
        cur += pos;
#line 501
        return cur;
    };
    
#line 500
    template < class _1, class _2 >
    inline C::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 500
        int pos = GetPos(it);
#line 500
        Insert(pos, key, value);
#line 500
        Iterator cur = Begin();
#line 500
        cur += pos;
#line 500
        return cur;
    };
    
#line 499
    template < class _1, class _2 >
    inline C::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 499
        int pos = GetPos(it);
#line 499
        Insert(pos, key, value);
#line 499
        Iterator cur = Begin();
#line 499
        cur += pos;
#line 499
        return cur;
    };
    
#line 474
    template < class _1, class _2 >
    inline bool VectorMap < _1, _2 >::IsEmpty() const
    {
#line 474
        return GetCount() == 0;
    };
    
#line 498
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 498
        Remove(GetPos(it));
    };
    
#line 477
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(int i)
    {
        {
#line 477
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 477
                Break("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 477
        ;
#line 477
        keys.Remove(i);
#line 477
        values.Remove(i);
    };
    
#line 476
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 476
        int i = Find(key);
#line 476
        if (i >= 0)
#line 476
            Remove(i);
    };
    
#line 468
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Top()
    {
        {
#line 468
            if (!(GetCount() > 0))
            {
#line 468
                Break("Assertion failed: GetCount() > 0");
            }
        }
#line 468
        ;
#line 468
        return values.Top();
    };
    
#line 515
    template < class _1, class _2 >
    inline C::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin() const
    {
#line 515
        return Begin();
    };
    
#line 513
    template < class _1, class _2 >
    inline C::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin()
    {
#line 513
        return Begin();
    };
    
    template < class _1, class _2 >
    inline C::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end() const
    {
#line 516
        return End();
    };
    
#line 514
    template < class _1, class _2 >
    inline C::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end()
    {
#line 514
        return End();
    };
    
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
        
#line 809
        inline void FromString(const String& s, String& o)
        {
#line 809
            o = s;
        };
        
#line 805
        inline void FromString(const String& s, byte& o)
        {
#line 805
            o = StrInt(s);
        };
        
#line 804
        inline void FromString(const String& s, int64& o)
        {
#line 804
            o = StrInt64(s);
        };
        
#line 803
        inline void FromString(const String& s, uint32& o)
        {
#line 803
            o = StrInt64(s);
        };
        
#line 800
        template < class _1 >
        inline void FromString(const String& s, _1& o)
        {
#line 800
            o.FromString(s);
        };
        
#line 801
        inline void FromString(const String& s, bool& o)
        {
#line 801
            o = (ToLower(s) != "false" && s != "0" && s.GetCount());
        };
        
#line 806
        inline void FromString(const String& s, char& o)
        {
#line 806
            o = StrInt(s);
        };
        
#line 808
        inline void FromString(const String& s, double& o)
        {
#line 808
            o = StrDbl(s);
        };
        
#line 807
        inline void FromString(const String& s, float& o)
        {
#line 807
            o = StrDbl(s);
        };
        
#line 802
        inline void FromString(const String& s, int& o)
        {
#line 802
            o = StrInt(s);
        };
        
#line 821
        inline int HexDigit(int c)
        {
#line 821
            return "0123456789ABCDEF"[c & 15];
        };
        
#line 822
        inline int HexDigitLower(int c)
        {
#line 822
            return "0123456789abcdef"[c & 15];
        };
        
#line 773
        inline int HexInt(String s)
        {
#line 773
            return String::HexInt(s);
        };
        
#line 823
        inline String HexStr(uint64 p)
        {
#line 824
            String o("0x");
            bool zero = true;
            uint64 i = 64;
            do
                {
#line 828
                    i -= 4;
                    byte b = (p >> i) & 15ULL;
                    if (b || !zero)
                    {
#line 831
                        zero = false;
                        o.Cat(HexDigit(b));
                    }
                }while (i);
#line 836
            if (zero)
#line 836
                o.Cat('0');
            return o;
        };
        
#line 839
        inline String HexStr(void *p)
        {
#line 839
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
        
#line 811
        template < class _1 >
        inline int64 ToInt(const _1& o)
        {
#line 811
            return o.ToInt();
        };
        
#line 819
        template <>
        inline int64 ToInt < String > (const String& o)
        {
#line 819
            return StrInt(o);
        };
        
#line 812
        template <>
        inline int64 ToInt < bool > (const bool& o)
        {
#line 812
            return(int64) o;
        };
        
        template <>
        inline int64 ToInt < byte > (const byte& o)
        {
#line 815
            return(int64) o;
        };
        
#line 816
        template <>
        inline int64 ToInt < char > (const char& o)
        {
#line 816
            return(int64) o;
        };
        
#line 818
        template <>
        inline int64 ToInt < double > (const double& o)
        {
#line 818
            return(int64) o;
        };
        
#line 817
        template <>
        inline int64 ToInt < float > (const float& o)
        {
#line 817
            return(int64) o;
        };
        
#line 813
        template <>
        inline int64 ToInt < int > (const int& o)
        {
#line 813
            return(int64) o;
        };
        
#line 814
        template <>
        inline int64 ToInt < int64 > (const int64& o)
        {
#line 814
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
