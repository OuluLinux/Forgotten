/*!$@FOG@$!
 *	Generated at Wed Sep 30 06:41:10 2020
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
 *		../../src/Com/Text.fog
 *		ComTest.mfog
 */

#ifndef LANG_HXX
#define LANG_HXX

#include <new>

#ifndef PRIM_HXX
#include <Prim.hxx>
#endif

namespace Lang
{
};

namespace Lang
{
#line 9 "../../src/Com/Lang.fog"
    typedef Prim::CPtr < const char > CString;
    
#line 10
    extern CString ____unused_CString;
};

namespace Lang
{
#line 9
    typedef Prim::CPtr < const void > ConstVoidPtr;
    
#line 10
    extern ConstVoidPtr ____unused_ConstVoidPtr;
};

namespace Lang
{
#line 9
    typedef Prim::CPtr < void > VoidPtr;
    
#line 10
    extern VoidPtr ____unused_VoidPtr;
};

namespace Lang
{
#line 142 "../../src/Com/Meta.fog"
    typedef unsigned char byte;
    
#line 143
    extern byte ____unused_byte;
};

namespace Lang
{
#line 142
    typedef unsigned int uint32;
#line 142
    typedef uint32 dword;
    
#line 143
    extern dword ____unused_dword;
};

namespace Lang
{
#line 142
    typedef short int16;
    
#line 143
    extern int16 ____unused_int16;
};

namespace Lang
{
#line 142
    typedef int int32;
    
#line 143
    extern int32 ____unused_int32;
};

namespace Lang
{
#line 142
    typedef long long int64;
    
#line 143
    extern int64 ____unused_int64;
};

namespace Lang
{
#line 142
    typedef char int8;
    
#line 143
    extern int8 ____unused_int8;
};

namespace Lang
{
#line 142
    typedef unsigned long long uint64;
#line 142
    typedef uint64 qword;
    
#line 143
    extern qword ____unused_qword;
};

namespace Lang
{
#line 142
    typedef unsigned short uint16;
    
#line 143
    extern uint16 ____unused_uint16;
#line 143
    extern uint32 ____unused_uint32;
#line 143
    extern uint64 ____unused_uint64;
};

namespace Lang
{
#line 142
    typedef unsigned char uint8;
    
#line 143
    extern uint8 ____unused_uint8;
};

namespace Lang
{
#line 142
    typedef uint16 word;
    
#line 143
    extern word ____unused_word;
    
#line 34 "../../src/Com/Lang.fog"
    inline void Destruct(int16& o);
#line 36
    inline void Destruct(int32& o);
#line 38
    inline void Destruct(int64& o);
#line 32
    inline void Destruct(int8& o);
    inline void Destruct(uint16& o);
#line 35
    inline void Destruct(uint32& o);
#line 37
    inline void Destruct(uint64& o);
#line 31
    inline void Destruct(uint8& o);
#line 30
    template < class _1 >
    inline void Destruct(_1& o);
#line 40
    inline void Destruct(double& o);
#line 39
    inline void Destruct(float& o);
#line 41
    inline void Destruct(void *o);
#line 56
    int StringLength(const char *c, int max_len = 100000000);
    int StringLength(const short *c, int max_len = 100000000);
#line 54
    void SysBreak(const char *msg);
    
    struct AtomicBool
    {
#line 70
        AtomicBool();
        AtomicBool(bool b);
        AtomicBool(const AtomicBool& ai);
#line 74
        bool operator= (bool b);
#line 73
        operator bool();
    };
    
    struct AtomicFlag
    {
#line 62
        void Enter();
        void Leave();
        bool TryEnter();
    };
    
    struct AtomicInt
    {
#line 80
        AtomicInt();
#line 82
        AtomicInt(const AtomicInt& ai);
#line 81
        AtomicInt(int i);
#line 85
        int operator++ ();
#line 87
        int operator++ (int);
#line 86
        int operator-- ();
#line 88
        int operator-- (int);
#line 84
        int operator= (int i);
#line 83
        operator int() const;
    };
    
    template < class _1 >
    class BwdIterator
    {
#line 150
        _1 *kit;
        
    public:
#line 121
        inline BwdIterator();
#line 151
        inline BwdIterator(_1 *kit);
#line 122
        inline BwdIterator(const BwdIterator& it);
#line 158
        inline bool operator!= (const BwdIterator& it) const;
#line 157
        inline _1& operator()() const;
#line 156
        inline _1& operator*() const;
#line 124
        inline BwdIterator < _1 > & operator++ ();
#line 126
        inline void operator+= (int i);
#line 125
        inline void operator-- (int i);
#line 154
        inline _1 *operator-> () const;
#line 123
        inline void operator= (const BwdIterator& it);
#line 155
        inline operator _1 * () const;
#line 152
        inline _1 *Get() const;
    };
    
    template < class _1, class _2 >
    class BwdPairIterator
    {
#line 200
        const _1 *kit;
#line 209
        _2 *vit;
        
    public:
#line 175
        inline BwdPairIterator();
        inline BwdPairIterator(const BwdPairIterator& it);
#line 210
        inline BwdPairIterator(const _1 *kit, _2 *vit);
#line 202
        inline bool operator!= (const BwdPairIterator& it) const;
#line 178
        inline BwdPairIterator < _1, _2 > & operator++ ();
#line 180
        inline void operator+= (int i);
#line 179
        inline void operator-- (int i);
#line 177
        inline void operator= (const BwdPairIterator& it);
#line 211
        inline _2& Value() const;
        
#line 201
        inline const _1& Key() const;
    };
    
    template < class _1, class _2 >
    class BwdPairPtrIterator
    {
#line 200
        const _1 *kit;
#line 204
        _2 **vit;
        
    public:
#line 175
        inline BwdPairPtrIterator();
        inline BwdPairPtrIterator(const BwdPairPtrIterator& it);
#line 205
        inline BwdPairPtrIterator(const _1 *kit, _2 **vit);
#line 202
        inline bool operator!= (const BwdPairPtrIterator& it) const;
#line 178
        inline BwdPairPtrIterator < _1, _2 > & operator++ ();
#line 180
        inline void operator+= (int i);
#line 179
        inline void operator-- (int i);
#line 177
        inline void operator= (const BwdPairPtrIterator& it);
#line 206
        inline _2& Value() const;
        
#line 201
        inline const _1& Key() const;
    };
    
    template < class _1 >
    class BwdPtrIterator
    {
#line 146
        _1 **kit;
        
    public:
#line 121
        inline BwdPtrIterator();
#line 147
        inline BwdPtrIterator(_1 **kit);
#line 122
        inline BwdPtrIterator(const BwdPtrIterator& it);
#line 158
        inline bool operator!= (const BwdPtrIterator& it) const;
#line 157
        inline _1& operator()() const;
#line 156
        inline _1& operator*() const;
#line 124
        inline BwdPtrIterator < _1 > & operator++ ();
#line 126
        inline void operator+= (int i);
#line 125
        inline void operator-- (int i);
#line 154
        inline _1 *operator-> () const;
#line 123
        inline void operator= (const BwdPtrIterator& it);
#line 155
        inline operator _1 * () const;
#line 148
        inline _1 *Get() const;
    };
    
    struct ConditionalVar
    {
#line 93
        ConditionalVar();
#line 96
        bool IsReady() const;
#line 95
        void SetReady(bool b = true);
#line 94
        void Wait();
    };
    
    template < class _1 >
    class ConstBwdIterator
    {
    public:
#line 129
        typedef const _1 ConstK;
        
#line 135
        const _1 *kit;
        
    public:
#line 121
        inline ConstBwdIterator();
        inline ConstBwdIterator(const ConstBwdIterator& it);
#line 136
        inline ConstBwdIterator(const _1 *kit);
#line 143
        inline bool operator!= (const ConstBwdIterator& it) const;
#line 142
        inline const _1& operator()() const;
#line 141
        inline const _1& operator*() const;
#line 124
        inline ConstBwdIterator < _1 > & operator++ ();
#line 126
        inline void operator+= (int i);
#line 125
        inline void operator-- (int i);
#line 139
        inline const _1 *operator-> () const;
#line 123
        inline void operator= (const ConstBwdIterator& it);
#line 140
        inline operator ConstK * () const;
#line 137
        inline const _1 *Get() const;
    };
    
    template < class _1, class _2 >
    class ConstBwdPairIterator
    {
#line 183
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 185
        const _1 *kit;
#line 194
        const _2 **vit;
        
    public:
#line 175
        inline ConstBwdPairIterator();
        inline ConstBwdPairIterator(const ConstBwdPairIterator& it);
#line 195
        inline ConstBwdPairIterator(const _1 *kit, const _2 **vit);
#line 187
        inline bool operator!= (const ConstBwdPairIterator& it) const;
#line 178
        inline ConstBwdPairIterator < _1, _2 > & operator++ ();
#line 180
        inline void operator+= (int i);
#line 179
        inline void operator-- (int i);
#line 177
        inline void operator= (const ConstBwdPairIterator& it);
#line 186
        inline const _1& Key() const;
#line 196
        inline const _2& Value() const;
    };
    
    template < class _1, class _2 >
    class ConstBwdPairPtrIterator
    {
#line 183
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 185
        const _1 *kit;
#line 189
        const _2 *vit;
        
    public:
#line 175
        inline ConstBwdPairPtrIterator();
        inline ConstBwdPairPtrIterator(const ConstBwdPairPtrIterator& it);
#line 190
        inline ConstBwdPairPtrIterator(const _1 *kit, const _2 *vit);
#line 187
        inline bool operator!= (const ConstBwdPairPtrIterator& it) const;
#line 178
        inline ConstBwdPairPtrIterator < _1, _2 > & operator++ ();
#line 180
        inline void operator+= (int i);
#line 179
        inline void operator-- (int i);
#line 177
        inline void operator= (const ConstBwdPairPtrIterator& it);
#line 186
        inline const _1& Key() const;
#line 191
        inline const _2& Value() const;
    };
    
    template < class _1 >
    class ConstBwdPtrIterator
    {
    public:
#line 129
        typedef const _1 ConstK;
        
        const _1 **kit;
        
    public:
#line 121
        inline ConstBwdPtrIterator();
        inline ConstBwdPtrIterator(const ConstBwdPtrIterator& it);
#line 132
        inline ConstBwdPtrIterator(const _1 **kit);
#line 143
        inline bool operator!= (const ConstBwdPtrIterator& it) const;
#line 142
        inline const _1& operator()() const;
#line 141
        inline const _1& operator*() const;
#line 124
        inline ConstBwdPtrIterator < _1 > & operator++ ();
#line 126
        inline void operator+= (int i);
#line 125
        inline void operator-- (int i);
#line 139
        inline const _1 *operator-> () const;
#line 123
        inline void operator= (const ConstBwdPtrIterator& it);
#line 140
        inline operator ConstK * () const;
#line 133
        inline const _1 *Get() const;
    };
    
    template < class _1 >
    class ConstFwdIterator
    {
    public:
#line 129
        typedef const _1 ConstK;
        
#line 135
        const _1 *kit;
        
    public:
#line 121
        inline ConstFwdIterator();
        inline ConstFwdIterator(const ConstFwdIterator& it);
#line 136
        inline ConstFwdIterator(const _1 *kit);
#line 143
        inline bool operator!= (const ConstFwdIterator& it) const;
#line 142
        inline const _1& operator()() const;
#line 141
        inline const _1& operator*() const;
#line 124
        inline ConstFwdIterator < _1 > & operator++ ();
#line 126
        inline void operator+= (int i);
#line 125
        inline void operator-- (int i);
#line 139
        inline const _1 *operator-> () const;
#line 123
        inline void operator= (const ConstFwdIterator& it);
#line 140
        inline operator ConstK * () const;
#line 137
        inline const _1 *Get() const;
    };
    
    template < class _1, class _2 >
    class ConstFwdPairIterator
    {
#line 183
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 185
        const _1 *kit;
#line 194
        const _2 **vit;
        
    public:
#line 175
        inline ConstFwdPairIterator();
        inline ConstFwdPairIterator(const ConstFwdPairIterator& it);
#line 195
        inline ConstFwdPairIterator(const _1 *kit, const _2 **vit);
#line 187
        inline bool operator!= (const ConstFwdPairIterator& it) const;
#line 178
        inline ConstFwdPairIterator < _1, _2 > & operator++ ();
#line 180
        inline void operator+= (int i);
#line 179
        inline void operator-- (int i);
#line 177
        inline void operator= (const ConstFwdPairIterator& it);
#line 186
        inline const _1& Key() const;
#line 196
        inline const _2& Value() const;
    };
    
    template < class _1, class _2 >
    class ConstFwdPairPtrIterator
    {
#line 183
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 185
        const _1 *kit;
#line 189
        const _2 *vit;
        
    public:
#line 175
        inline ConstFwdPairPtrIterator();
        inline ConstFwdPairPtrIterator(const ConstFwdPairPtrIterator& it);
#line 190
        inline ConstFwdPairPtrIterator(const _1 *kit, const _2 *vit);
#line 187
        inline bool operator!= (const ConstFwdPairPtrIterator& it) const;
#line 178
        inline ConstFwdPairPtrIterator < _1, _2 > & operator++ ();
#line 180
        inline void operator+= (int i);
#line 179
        inline void operator-- (int i);
#line 177
        inline void operator= (const ConstFwdPairPtrIterator& it);
#line 186
        inline const _1& Key() const;
#line 191
        inline const _2& Value() const;
    };
    
    template < class _1 >
    class ConstFwdPtrIterator
    {
    public:
#line 129
        typedef const _1 ConstK;
        
        const _1 **kit;
        
    public:
#line 121
        inline ConstFwdPtrIterator();
        inline ConstFwdPtrIterator(const ConstFwdPtrIterator& it);
#line 132
        inline ConstFwdPtrIterator(const _1 **kit);
#line 143
        inline bool operator!= (const ConstFwdPtrIterator& it) const;
#line 142
        inline const _1& operator()() const;
#line 141
        inline const _1& operator*() const;
#line 124
        inline ConstFwdPtrIterator < _1 > & operator++ ();
#line 126
        inline void operator+= (int i);
#line 125
        inline void operator-- (int i);
#line 139
        inline const _1 *operator-> () const;
#line 123
        inline void operator= (const ConstFwdPtrIterator& it);
#line 140
        inline operator ConstK * () const;
#line 133
        inline const _1 *Get() const;
    };
    
    template < class _1 >
    class FwdIterator
    {
#line 150
        _1 *kit;
        
    public:
#line 121
        inline FwdIterator();
#line 151
        inline FwdIterator(_1 *kit);
#line 122
        inline FwdIterator(const FwdIterator& it);
#line 158
        inline bool operator!= (const FwdIterator& it) const;
#line 157
        inline _1& operator()() const;
#line 156
        inline _1& operator*() const;
#line 124
        inline FwdIterator < _1 > & operator++ ();
#line 126
        inline void operator+= (int i);
#line 125
        inline void operator-- (int i);
#line 154
        inline _1 *operator-> () const;
#line 123
        inline void operator= (const FwdIterator& it);
#line 155
        inline operator _1 * () const;
#line 152
        inline _1 *Get() const;
    };
    
    template < class _1 >
    class DynArray
    {
    public:
#line 253
        typedef ConstFwdIterator < _1 > ConstIterator;
#line 251
        typedef const _1 ConstK;
#line 254
        typedef ConstBwdIterator < _1 > ConstRIterator;
#line 252
        typedef DynArray < _1 > DynArrayK;
#line 250
        typedef _1 IndirectK;
#line 255
        typedef FwdIterator < _1 > Iterator;
        typedef BwdIterator < _1 > RIterator;
        
    private:
#line 229
        typedef unsigned long long uint64;
        
#line 232
        _1 *data;
        int reserved;
        int count;
        
    public:
#line 258
        inline DynArray();
        inline DynArray(const DynArray& v);
        inline DynArray(int i);
        inline ~DynArray();
#line 314
        inline DynArray < _1 > & operator<< (const _1& v);
#line 347
        inline void operator<<= (const DynArray& a);
#line 379
        inline _1& operator[](int i);
#line 383
        inline const _1& operator[](int i) const;
#line 292
        inline _1& Add();
#line 299
        inline _1& Add(const _1& v);
#line 354
        inline void Append(const DynArray& a);
#line 274
        inline Lang::ConstFwdIterator < _1 > Begin() const;
#line 272
        inline Lang::FwdIterator < _1 > Begin();
#line 481
        inline void Clear();
#line 275
        inline Lang::ConstFwdIterator < _1 > End() const;
#line 273
        inline Lang::FwdIterator < _1 > End();
#line 289
        inline _1 *Get() const;
#line 375
        inline int GetCount() const;
#line 290
        inline _1 *GetEnd() const;
#line 376
        inline int GetReserved() const;
#line 362
        inline void IncreaseReserve(int more_reserved);
#line 442
        inline _1& Insert(int i);
#line 453
        inline _1& Insert(int i, ConstK& key);
#line 377
        inline bool IsEmpty() const;
#line 467
        inline _1 Pop();
#line 280
        inline Lang::BwdIterator < _1 > RBegin();
#line 282
        inline Lang::ConstBwdIterator < _1 > RBegin() const;
#line 281
        inline Lang::BwdIterator < _1 > REnd();
#line 283
        inline Lang::ConstBwdIterator < _1 > REnd() const;
#line 421
        inline void Remove(const DynArray < int > & sorted_list);
#line 403
        inline void Remove(const Iterator& it);
#line 410
        inline void Remove(const Iterator& it, const Iterator& end);
#line 422
        inline void Remove(const int *sorted_list, int n);
#line 388
        inline void Remove(int i);
#line 395
        inline void Remove(int i, int count);
#line 476
        inline void RemoveLast();
#line 363
        inline void Reserve(int new_reserved);
#line 316
        inline void SetCount(int new_count);
#line 332
        inline void SetCount(int new_count, ConstK& value);
#line 465
        inline _1& Top();
#line 278
        inline Lang::ConstFwdIterator < _1 > begin() const;
#line 276
        inline Lang::FwdIterator < _1 > begin();
#line 279
        inline Lang::ConstFwdIterator < _1 > end() const;
#line 277
        inline Lang::FwdIterator < _1 > end();
#line 284
        inline Lang::BwdIterator < _1 > rbegin();
#line 286
        inline Lang::ConstBwdIterator < _1 > rbegin() const;
#line 285
        inline Lang::BwdIterator < _1 > rend();
#line 287
        inline Lang::ConstBwdIterator < _1 > rend() const;
        
#line 237
        inline void IncreaseReserved();
#line 246
        inline void Pick0(DynArray& v);
    };
    
    template < class _1, class _2 >
    class FwdPairIterator
    {
#line 200
        const _1 *kit;
#line 209
        _2 *vit;
        
    public:
#line 175
        inline FwdPairIterator();
        inline FwdPairIterator(const FwdPairIterator& it);
#line 210
        inline FwdPairIterator(const _1 *kit, _2 *vit);
#line 202
        inline bool operator!= (const FwdPairIterator& it) const;
#line 178
        inline FwdPairIterator < _1, _2 > & operator++ ();
#line 180
        inline void operator+= (int i);
#line 179
        inline void operator-- (int i);
#line 177
        inline void operator= (const FwdPairIterator& it);
#line 211
        inline _2& Value() const;
        
#line 201
        inline const _1& Key() const;
    };
    
    template < class _1, class _2 >
    class FwdPairPtrIterator
    {
#line 200
        const _1 *kit;
#line 204
        _2 **vit;
        
    public:
#line 175
        inline FwdPairPtrIterator();
        inline FwdPairPtrIterator(const FwdPairPtrIterator& it);
#line 205
        inline FwdPairPtrIterator(const _1 *kit, _2 **vit);
#line 202
        inline bool operator!= (const FwdPairPtrIterator& it) const;
#line 178
        inline FwdPairPtrIterator < _1, _2 > & operator++ ();
#line 180
        inline void operator+= (int i);
#line 179
        inline void operator-- (int i);
#line 177
        inline void operator= (const FwdPairPtrIterator& it);
#line 206
        inline _2& Value() const;
        
#line 201
        inline const _1& Key() const;
    };
    
    template < class _1 >
    class FwdPtrIterator
    {
#line 146
        _1 **kit;
        
    public:
#line 121
        inline FwdPtrIterator();
#line 147
        inline FwdPtrIterator(_1 **kit);
#line 122
        inline FwdPtrIterator(const FwdPtrIterator& it);
#line 158
        inline bool operator!= (const FwdPtrIterator& it) const;
#line 157
        inline _1& operator()() const;
#line 156
        inline _1& operator*() const;
#line 124
        inline FwdPtrIterator < _1 > & operator++ ();
#line 126
        inline void operator+= (int i);
#line 125
        inline void operator-- (int i);
#line 154
        inline _1 *operator-> () const;
#line 123
        inline void operator= (const FwdPtrIterator& it);
#line 155
        inline operator _1 * () const;
#line 148
        inline _1 *Get() const;
    };
    
    namespace Memory
    {
#line 45
        void *Alloc(int sz);
#line 47
        int Compare(const void *m1, const void *m2, int sz);
        void *Copy(void *dest, const void *src, int sz);
#line 46
        void Free(void *ptr);
#line 49
        void *Move(void *dest, const void *src, int sz);
        void Set(void *dest, int byte_value, int sz);
    };
    
    struct MemoryLimitExc
    {
#line 109
        const char *msg;
        
#line 110
        inline MemoryLimitExc();
        inline MemoryLimitExc(const char *s);
    };
};

namespace Lang
{
#line 34
    inline void Destruct(int16& o) {};
    
    inline void Destruct(int32& o) {};
    
    inline void Destruct(int64& o) {};
    
#line 32
    inline void Destruct(int8& o) {};
    
#line 33
    inline void Destruct(uint16& o) {};
    
    inline void Destruct(uint32& o) {};
    
    inline void Destruct(uint64& o) {};
    
#line 31
    inline void Destruct(uint8& o) {};
    
#line 30
    template < class _1 >
    inline void Destruct(_1& o)
    {
#line 30
        o.~T();
    };
    
#line 40
    inline void Destruct(double& o) {};
    
#line 39
    inline void Destruct(float& o) {};
    
    inline void Destruct(void *o) {};
    
#line 121
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator() {};
    
#line 151
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator(_1 *kit)
    :
        kit(kit)
    {};
    
#line 122
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator(const BwdIterator& it)
    {
#line 122
        *this = it;
    };
    
#line 158
    template < class _1 >
    inline bool BwdIterator < _1 >::operator!= (const BwdIterator& it) const
    {
#line 158
        return it.kit != kit;
    };
    
#line 157
    template < class _1 >
    inline _1& BwdIterator < _1 >::operator()() const
    {
#line 157
        return *Get();
    };
    
#line 156
    template < class _1 >
    inline _1& BwdIterator < _1 >::operator*() const
    {
#line 156
        return *Get();
    };
    
#line 124
    template < class _1 >
    inline BwdIterator < _1 > & BwdIterator < _1 >::operator++ ()
    {
#line 124
        kit += -1;
#line 124
        return *this;
    };
    
#line 126
    template < class _1 >
    inline void BwdIterator < _1 >::operator+= (int i)
    {
#line 126
        kit += i;
    };
    
#line 125
    template < class _1 >
    inline void BwdIterator < _1 >::operator-- (int i)
    {
#line 125
        kit -= -1;
    };
    
#line 154
    template < class _1 >
    inline _1 *BwdIterator < _1 >::operator-> () const
    {
#line 154
        return Get();
    };
    
#line 123
    template < class _1 >
    inline void BwdIterator < _1 >::operator= (const BwdIterator& it)
    {
#line 123
        kit = it.kit;
    };
    
#line 155
    template < class _1 >
    inline BwdIterator < _1 >::operator _1 * () const
    {
#line 155
        return Get();
    };
    
#line 152
    template < class _1 >
    inline _1 *BwdIterator < _1 >::Get() const
    {
#line 152
        return kit;
    };
    
#line 175
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 >::BwdPairIterator() {};
    
#line 176
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 >::BwdPairIterator(const BwdPairIterator& it)
    {
#line 176
        *this = it;
    };
    
#line 210
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 >::BwdPairIterator(const _1 *kit, _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 202
    template < class _1, class _2 >
    inline bool BwdPairIterator < _1, _2 >::operator!= (const BwdPairIterator& it) const
    {
#line 202
        return it.kit != kit;
    };
    
#line 178
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 > & BwdPairIterator < _1, _2 >::operator++ ()
    {
#line 178
        kit += -1;
#line 178
        vit += -1;
#line 178
        return *this;
    };
    
#line 180
    template < class _1, class _2 >
    inline void BwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 180
        kit += i;
#line 180
        vit += i;
    };
    
#line 179
    template < class _1, class _2 >
    inline void BwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 179
        kit -= -1;
#line 179
        vit -= -1;
    };
    
#line 177
    template < class _1, class _2 >
    inline void BwdPairIterator < _1, _2 >::operator= (const BwdPairIterator& it)
    {
#line 177
        kit = it.kit;
#line 177
        vit = it.vit;
    };
    
#line 201
    template < class _1, class _2 >
    inline const _1& BwdPairIterator < _1, _2 >::Key() const
    {
#line 201
        return *kit;
    };
    
#line 211
    template < class _1, class _2 >
    inline _2& BwdPairIterator < _1, _2 >::Value() const
    {
#line 211
        return *vit;
    };
    
#line 175
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 >::BwdPairPtrIterator() {};
    
#line 176
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 >::BwdPairPtrIterator(const BwdPairPtrIterator& it)
    {
#line 176
        *this = it;
    };
    
#line 205
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 >::BwdPairPtrIterator(const _1 *kit, _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 202
    template < class _1, class _2 >
    inline bool BwdPairPtrIterator < _1, _2 >::operator!= (const BwdPairPtrIterator& it) const
    {
#line 202
        return it.kit != kit;
    };
    
#line 178
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 > & BwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 178
        kit += -1;
#line 178
        vit += -1;
#line 178
        return *this;
    };
    
#line 180
    template < class _1, class _2 >
    inline void BwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 180
        kit += i;
#line 180
        vit += i;
    };
    
#line 179
    template < class _1, class _2 >
    inline void BwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 179
        kit -= -1;
#line 179
        vit -= -1;
    };
    
#line 177
    template < class _1, class _2 >
    inline void BwdPairPtrIterator < _1, _2 >::operator= (const BwdPairPtrIterator& it)
    {
#line 177
        kit = it.kit;
#line 177
        vit = it.vit;
    };
    
#line 201
    template < class _1, class _2 >
    inline const _1& BwdPairPtrIterator < _1, _2 >::Key() const
    {
#line 201
        return *kit;
    };
    
#line 206
    template < class _1, class _2 >
    inline _2& BwdPairPtrIterator < _1, _2 >::Value() const
    {
#line 206
        return **vit;
    };
    
#line 121
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator() {};
    
#line 147
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator(_1 **kit)
    :
        kit(kit)
    {};
    
#line 122
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator(const BwdPtrIterator& it)
    {
#line 122
        *this = it;
    };
    
#line 158
    template < class _1 >
    inline bool BwdPtrIterator < _1 >::operator!= (const BwdPtrIterator& it) const
    {
#line 158
        return it.kit != kit;
    };
    
#line 157
    template < class _1 >
    inline _1& BwdPtrIterator < _1 >::operator()() const
    {
#line 157
        return *Get();
    };
    
#line 156
    template < class _1 >
    inline _1& BwdPtrIterator < _1 >::operator*() const
    {
#line 156
        return *Get();
    };
    
#line 124
    template < class _1 >
    inline BwdPtrIterator < _1 > & BwdPtrIterator < _1 >::operator++ ()
    {
#line 124
        kit += -1;
#line 124
        return *this;
    };
    
#line 126
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator+= (int i)
    {
#line 126
        kit += i;
    };
    
#line 125
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator-- (int i)
    {
#line 125
        kit -= -1;
    };
    
#line 154
    template < class _1 >
    inline _1 *BwdPtrIterator < _1 >::operator-> () const
    {
#line 154
        return Get();
    };
    
#line 123
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator= (const BwdPtrIterator& it)
    {
#line 123
        kit = it.kit;
    };
    
#line 155
    template < class _1 >
    inline BwdPtrIterator < _1 >::operator _1 * () const
    {
#line 155
        return Get();
    };
    
#line 148
    template < class _1 >
    inline _1 *BwdPtrIterator < _1 >::Get() const
    {
#line 148
        return *kit;
    };
    
#line 121
    template < class _1 >
    inline ConstBwdIterator < _1 >::ConstBwdIterator() {};
    
#line 122
    template < class _1 >
    inline ConstBwdIterator < _1 >::ConstBwdIterator(const ConstBwdIterator& it)
    {
#line 122
        *this = it;
    };
    
#line 136
    template < class _1 >
    inline ConstBwdIterator < _1 >::ConstBwdIterator(const _1 *kit)
    :
        kit(kit)
    {};
    
#line 143
    template < class _1 >
    inline bool ConstBwdIterator < _1 >::operator!= (const ConstBwdIterator& it) const
    {
#line 143
        return it.kit != kit;
    };
    
#line 142
    template < class _1 >
    inline const _1& ConstBwdIterator < _1 >::operator()() const
    {
#line 142
        return *Get();
    };
    
#line 141
    template < class _1 >
    inline const _1& ConstBwdIterator < _1 >::operator*() const
    {
#line 141
        return *Get();
    };
    
#line 124
    template < class _1 >
    inline ConstBwdIterator < _1 > & ConstBwdIterator < _1 >::operator++ ()
    {
#line 124
        kit += -1;
#line 124
        return *this;
    };
    
#line 126
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator+= (int i)
    {
#line 126
        kit += i;
    };
    
#line 125
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator-- (int i)
    {
#line 125
        kit -= -1;
    };
    
#line 139
    template < class _1 >
    inline const _1 *ConstBwdIterator < _1 >::operator-> () const
    {
#line 139
        return Get();
    };
    
#line 123
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator= (const ConstBwdIterator& it)
    {
#line 123
        kit = it.kit;
    };
    
#line 140
    template < class _1 >
    inline ConstBwdIterator < _1 >::operator ConstK * () const
    {
#line 140
        return Get();
    };
    
#line 137
    template < class _1 >
    inline const _1 *ConstBwdIterator < _1 >::Get() const
    {
#line 137
        return kit;
    };
    
#line 175
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 >::ConstBwdPairIterator() {};
    
#line 176
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 >::ConstBwdPairIterator(const ConstBwdPairIterator& it)
    {
#line 176
        *this = it;
    };
    
#line 195
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 >::ConstBwdPairIterator(const _1 *kit, const _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 187
    template < class _1, class _2 >
    inline bool ConstBwdPairIterator < _1, _2 >::operator!= (const ConstBwdPairIterator& it) const
    {
#line 187
        return it.kit != kit;
    };
    
#line 178
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 > & ConstBwdPairIterator < _1, _2 >::operator++ ()
    {
#line 178
        kit += -1;
#line 178
        vit += -1;
#line 178
        return *this;
    };
    
#line 180
    template < class _1, class _2 >
    inline void ConstBwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 180
        kit += i;
#line 180
        vit += i;
    };
    
#line 179
    template < class _1, class _2 >
    inline void ConstBwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 179
        kit -= -1;
#line 179
        vit -= -1;
    };
    
#line 177
    template < class _1, class _2 >
    inline void ConstBwdPairIterator < _1, _2 >::operator= (const ConstBwdPairIterator& it)
    {
#line 177
        kit = it.kit;
#line 177
        vit = it.vit;
    };
    
#line 186
    template < class _1, class _2 >
    inline const _1& ConstBwdPairIterator < _1, _2 >::Key() const
    {
#line 186
        return *kit;
    };
    
#line 196
    template < class _1, class _2 >
    inline const _2& ConstBwdPairIterator < _1, _2 >::Value() const
    {
#line 196
        return **vit;
    };
    
#line 175
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 >::ConstBwdPairPtrIterator() {};
    
#line 176
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 >::ConstBwdPairPtrIterator(const ConstBwdPairPtrIterator& it)
    {
#line 176
        *this = it;
    };
    
#line 190
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 >::ConstBwdPairPtrIterator(const _1 *kit, const _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 187
    template < class _1, class _2 >
    inline bool ConstBwdPairPtrIterator < _1, _2 >::operator!= (const ConstBwdPairPtrIterator& it) const
    {
#line 187
        return it.kit != kit;
    };
    
#line 178
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 > & ConstBwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 178
        kit += -1;
#line 178
        vit += -1;
#line 178
        return *this;
    };
    
#line 180
    template < class _1, class _2 >
    inline void ConstBwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 180
        kit += i;
#line 180
        vit += i;
    };
    
#line 179
    template < class _1, class _2 >
    inline void ConstBwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 179
        kit -= -1;
#line 179
        vit -= -1;
    };
    
#line 177
    template < class _1, class _2 >
    inline void ConstBwdPairPtrIterator < _1, _2 >::operator= (const ConstBwdPairPtrIterator& it)
    {
#line 177
        kit = it.kit;
#line 177
        vit = it.vit;
    };
    
#line 186
    template < class _1, class _2 >
    inline const _1& ConstBwdPairPtrIterator < _1, _2 >::Key() const
    {
#line 186
        return *kit;
    };
    
#line 191
    template < class _1, class _2 >
    inline const _2& ConstBwdPairPtrIterator < _1, _2 >::Value() const
    {
#line 191
        return *vit;
    };
    
#line 121
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator() {};
    
#line 122
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator(const ConstBwdPtrIterator& it)
    {
#line 122
        *this = it;
    };
    
#line 132
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator(const _1 **kit)
    :
        kit(kit)
    {};
    
#line 143
    template < class _1 >
    inline bool ConstBwdPtrIterator < _1 >::operator!= (const ConstBwdPtrIterator& it) const
    {
#line 143
        return it.kit != kit;
    };
    
#line 142
    template < class _1 >
    inline const _1& ConstBwdPtrIterator < _1 >::operator()() const
    {
#line 142
        return *Get();
    };
    
#line 141
    template < class _1 >
    inline const _1& ConstBwdPtrIterator < _1 >::operator*() const
    {
#line 141
        return *Get();
    };
    
#line 124
    template < class _1 >
    inline ConstBwdPtrIterator < _1 > & ConstBwdPtrIterator < _1 >::operator++ ()
    {
#line 124
        kit += -1;
#line 124
        return *this;
    };
    
#line 126
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator+= (int i)
    {
#line 126
        kit += i;
    };
    
#line 125
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator-- (int i)
    {
#line 125
        kit -= -1;
    };
    
#line 139
    template < class _1 >
    inline const _1 *ConstBwdPtrIterator < _1 >::operator-> () const
    {
#line 139
        return Get();
    };
    
#line 123
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator= (const ConstBwdPtrIterator& it)
    {
#line 123
        kit = it.kit;
    };
    
#line 140
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::operator ConstK * () const
    {
#line 140
        return Get();
    };
    
#line 133
    template < class _1 >
    inline const _1 *ConstBwdPtrIterator < _1 >::Get() const
    {
#line 133
        return *kit;
    };
    
#line 121
    template < class _1 >
    inline ConstFwdIterator < _1 >::ConstFwdIterator() {};
    
#line 122
    template < class _1 >
    inline ConstFwdIterator < _1 >::ConstFwdIterator(const ConstFwdIterator& it)
    {
#line 122
        *this = it;
    };
    
#line 136
    template < class _1 >
    inline ConstFwdIterator < _1 >::ConstFwdIterator(const _1 *kit)
    :
        kit(kit)
    {};
    
#line 143
    template < class _1 >
    inline bool ConstFwdIterator < _1 >::operator!= (const ConstFwdIterator& it) const
    {
#line 143
        return it.kit != kit;
    };
    
#line 142
    template < class _1 >
    inline const _1& ConstFwdIterator < _1 >::operator()() const
    {
#line 142
        return *Get();
    };
    
#line 141
    template < class _1 >
    inline const _1& ConstFwdIterator < _1 >::operator*() const
    {
#line 141
        return *Get();
    };
    
#line 124
    template < class _1 >
    inline ConstFwdIterator < _1 > & ConstFwdIterator < _1 >::operator++ ()
    {
#line 124
        kit += 1;
#line 124
        return *this;
    };
    
#line 126
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator+= (int i)
    {
#line 126
        kit += i;
    };
    
#line 125
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator-- (int i)
    {
#line 125
        kit -= 1;
    };
    
#line 139
    template < class _1 >
    inline const _1 *ConstFwdIterator < _1 >::operator-> () const
    {
#line 139
        return Get();
    };
    
#line 123
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator= (const ConstFwdIterator& it)
    {
#line 123
        kit = it.kit;
    };
    
#line 140
    template < class _1 >
    inline ConstFwdIterator < _1 >::operator ConstK * () const
    {
#line 140
        return Get();
    };
    
#line 137
    template < class _1 >
    inline const _1 *ConstFwdIterator < _1 >::Get() const
    {
#line 137
        return kit;
    };
    
#line 175
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 >::ConstFwdPairIterator() {};
    
#line 176
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 >::ConstFwdPairIterator(const ConstFwdPairIterator& it)
    {
#line 176
        *this = it;
    };
    
#line 195
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 >::ConstFwdPairIterator(const _1 *kit, const _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 187
    template < class _1, class _2 >
    inline bool ConstFwdPairIterator < _1, _2 >::operator!= (const ConstFwdPairIterator& it) const
    {
#line 187
        return it.kit != kit;
    };
    
#line 178
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 > & ConstFwdPairIterator < _1, _2 >::operator++ ()
    {
#line 178
        kit += 1;
#line 178
        vit += 1;
#line 178
        return *this;
    };
    
#line 180
    template < class _1, class _2 >
    inline void ConstFwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 180
        kit += i;
#line 180
        vit += i;
    };
    
#line 179
    template < class _1, class _2 >
    inline void ConstFwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 179
        kit -= 1;
#line 179
        vit -= 1;
    };
    
#line 177
    template < class _1, class _2 >
    inline void ConstFwdPairIterator < _1, _2 >::operator= (const ConstFwdPairIterator& it)
    {
#line 177
        kit = it.kit;
#line 177
        vit = it.vit;
    };
    
#line 186
    template < class _1, class _2 >
    inline const _1& ConstFwdPairIterator < _1, _2 >::Key() const
    {
#line 186
        return *kit;
    };
    
#line 196
    template < class _1, class _2 >
    inline const _2& ConstFwdPairIterator < _1, _2 >::Value() const
    {
#line 196
        return **vit;
    };
    
#line 175
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 >::ConstFwdPairPtrIterator() {};
    
#line 176
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 >::ConstFwdPairPtrIterator(const ConstFwdPairPtrIterator& it)
    {
#line 176
        *this = it;
    };
    
#line 190
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 >::ConstFwdPairPtrIterator(const _1 *kit, const _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 187
    template < class _1, class _2 >
    inline bool ConstFwdPairPtrIterator < _1, _2 >::operator!= (const ConstFwdPairPtrIterator& it) const
    {
#line 187
        return it.kit != kit;
    };
    
#line 178
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 > & ConstFwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 178
        kit += 1;
#line 178
        vit += 1;
#line 178
        return *this;
    };
    
#line 180
    template < class _1, class _2 >
    inline void ConstFwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 180
        kit += i;
#line 180
        vit += i;
    };
    
#line 179
    template < class _1, class _2 >
    inline void ConstFwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 179
        kit -= 1;
#line 179
        vit -= 1;
    };
    
#line 177
    template < class _1, class _2 >
    inline void ConstFwdPairPtrIterator < _1, _2 >::operator= (const ConstFwdPairPtrIterator& it)
    {
#line 177
        kit = it.kit;
#line 177
        vit = it.vit;
    };
    
#line 186
    template < class _1, class _2 >
    inline const _1& ConstFwdPairPtrIterator < _1, _2 >::Key() const
    {
#line 186
        return *kit;
    };
    
#line 191
    template < class _1, class _2 >
    inline const _2& ConstFwdPairPtrIterator < _1, _2 >::Value() const
    {
#line 191
        return *vit;
    };
    
#line 121
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator() {};
    
#line 122
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator(const ConstFwdPtrIterator& it)
    {
#line 122
        *this = it;
    };
    
#line 132
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator(const _1 **kit)
    :
        kit(kit)
    {};
    
#line 143
    template < class _1 >
    inline bool ConstFwdPtrIterator < _1 >::operator!= (const ConstFwdPtrIterator& it) const
    {
#line 143
        return it.kit != kit;
    };
    
#line 142
    template < class _1 >
    inline const _1& ConstFwdPtrIterator < _1 >::operator()() const
    {
#line 142
        return *Get();
    };
    
#line 141
    template < class _1 >
    inline const _1& ConstFwdPtrIterator < _1 >::operator*() const
    {
#line 141
        return *Get();
    };
    
#line 124
    template < class _1 >
    inline ConstFwdPtrIterator < _1 > & ConstFwdPtrIterator < _1 >::operator++ ()
    {
#line 124
        kit += 1;
#line 124
        return *this;
    };
    
#line 126
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator+= (int i)
    {
#line 126
        kit += i;
    };
    
#line 125
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator-- (int i)
    {
#line 125
        kit -= 1;
    };
    
#line 139
    template < class _1 >
    inline const _1 *ConstFwdPtrIterator < _1 >::operator-> () const
    {
#line 139
        return Get();
    };
    
#line 123
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator= (const ConstFwdPtrIterator& it)
    {
#line 123
        kit = it.kit;
    };
    
#line 140
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::operator ConstK * () const
    {
#line 140
        return Get();
    };
    
#line 133
    template < class _1 >
    inline const _1 *ConstFwdPtrIterator < _1 >::Get() const
    {
#line 133
        return *kit;
    };
    
#line 258
    template < class _1 >
    inline DynArray < _1 >::DynArray()
    :
        data(0),
        reserved(0),
        count(0)
    {};
    
#line 259
    template < class _1 >
    inline DynArray < _1 >::DynArray(const DynArray& v)
    :
        data(0),
        reserved(0),
        count(0)
    {
#line 259
        *this <<= v;
    };
    
#line 260
    template < class _1 >
    inline DynArray < _1 >::DynArray(int i)
    :
        data(0),
        reserved(0),
        count(0)
    {
#line 260
        SetCount(i);
    };
    
#line 261
    template < class _1 >
    inline DynArray < _1 >::~DynArray()
    {
#line 262
        Clear();
        return;
        ;
    };
    
#line 314
    template < class _1 >
    inline DynArray < _1 > & DynArray < _1 >::operator<< (const _1& v)
    {
#line 314
        Add(v);
#line 314
        return *this;
    };
    
#line 347
    template < class _1 >
    inline void DynArray < _1 >::operator<<= (const DynArray& a)
    {
#line 348
        SetCount(0);
        Reserve(a.GetCount());
        for (int i = 0; i < a.GetCount(); i ++ )
            new (&data[i])_1(a[i]);
        count = a.GetCount();
    };
    
#line 379
    template < class _1 >
    inline _1& DynArray < _1 >::operator[](int i)
    {
        {
#line 380
            if (!(i >= 0 && i < count))
            {
#line 380
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 381
        ;
#line 381
        return *(data + i);
    };
    
#line 383
    template < class _1 >
    inline const _1& DynArray < _1 >::operator[](int i) const
    {
        {
#line 384
            if (!(i >= 0 && i < count))
            {
#line 384
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 385
        ;
#line 385
        return *(data + i);
    };
    
#line 292
    template < class _1 >
    inline _1& DynArray < _1 >::Add()
    {
#line 293
        if (count + 1 > reserved)
#line 293
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        new (&data[count])_1;
        return data[count ++ ];
    };
    
#line 299
    template < class _1 >
    inline _1& DynArray < _1 >::Add(const _1& v)
    {
#line 300
        if (count + 1 > reserved)
#line 300
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        _1 * ptr = &data[count];
        new (ptr)_1(v);
        return data[count ++ ];
    };
    
#line 354
    template < class _1 >
    inline void DynArray < _1 >::Append(const DynArray& a)
    {
#line 355
        int begin = count;
        int new_count = count + a.GetCount();
        Reserve(new_count);
        for (int i = begin, j = 0; i < new_count; i ++ , j ++ )
            new (&data[i])_1(a[j]);
        count = new_count;
    };
    
#line 274
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::Begin() const
    {
#line 274
        return ConstIterator(data);
    };
    
#line 272
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::Begin()
    {
#line 272
        return Iterator(data);
    };
    
#line 481
    template < class _1 >
    inline void DynArray < _1 >::Clear()
    {
#line 482
        if (!reserved)
#line 482
            return;
        _1 * it = data;
        _1 * end = data + count;
        while (it != end)
            it ++ -> ~IndirectK();
        count = 0;
        Memory::Free(data);
        data = 0;
        reserved = 0;
    };
    
#line 275
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::End() const
    {
#line 275
        return ConstIterator(data + count);
    };
    
#line 273
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::End()
    {
#line 273
        return Iterator(data + count);
    };
    
#line 289
    template < class _1 >
    inline _1 *DynArray < _1 >::Get() const
    {
#line 289
        return data;
    };
    
#line 375
    template < class _1 >
    inline int DynArray < _1 >::GetCount() const
    {
#line 375
        return count;
    };
    
#line 290
    template < class _1 >
    inline _1 *DynArray < _1 >::GetEnd() const
    {
#line 290
        return data + count;
    };
    
#line 376
    template < class _1 >
    inline int DynArray < _1 >::GetReserved() const
    {
#line 376
        return reserved;
    };
    
#line 362
    template < class _1 >
    inline void DynArray < _1 >::IncreaseReserve(int more_reserved)
    {
#line 362
        Reserve(GetCount() + more_reserved);
    };
    
#line 237
    template < class _1 >
    inline void DynArray < _1 >::IncreaseReserved()
    {
#line 238
        uint64 new_reserved = 1;
        while (new_reserved <= reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2000000000)
            new_reserved = 2000000000;
        Reserve((int) new_reserved);
    };
    
#line 442
    template < class _1 >
    inline _1& DynArray < _1 >::Insert(int i)
    {
#line 443
        if (count + 1 > reserved)
#line 443
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        int tail = this -> count - i;
        if (tail > 0)
            Memory::Move(data + i + 1, data + i, tail * sizeof (_1));
        new (&data[i])_1;
        count ++ ;
        return data[i];
    };
    
#line 453
    template < class _1 >
    inline _1& DynArray < _1 >::Insert(int i, ConstK& key)
    {
#line 454
        if (count + 1 > reserved)
#line 454
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        int tail = this -> count - i;
        if (tail > 0)
            Memory::Move(data + i + 1, data + i, tail * sizeof (_1));
        new (&data[i])_1(key);
        count ++ ;
        return data[i];
    };
    
#line 377
    template < class _1 >
    inline bool DynArray < _1 >::IsEmpty() const
    {
#line 377
        return GetCount() == 0;
    };
    
#line 246
    template < class _1 >
    inline void DynArray < _1 >::Pick0(DynArray& v)
    {
#line 246
        data = v.data;
#line 246
        v.data = 0;
#line 246
        reserved = v.reserved;
#line 246
        v.reserved = 0;
#line 246
        count = v.count;
#line 246
        v.count = 0;
    };
    
#line 467
    template < class _1 >
    inline _1 DynArray < _1 >::Pop()
    {
        {
#line 468
            if (!(GetCount() > 0))
            {
#line 468
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 469
        ;
#line 469
        int i = count - 1;
        _1 ret(data[i]);
        data[i].~K();
        count -- ;
        return ret;
    };
    
#line 280
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::RBegin()
    {
#line 280
        return RIterator(data + count - 1);
    };
    
#line 282
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::RBegin() const
    {
#line 282
        return ConstRIterator(data + count - 1);
    };
    
#line 281
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::REnd()
    {
#line 281
        return RIterator(data - 1);
    };
    
#line 283
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::REnd() const
    {
#line 283
        return ConstRIterator(data - 1);
    };
    
#line 421
    template < class _1 >
    inline void DynArray < _1 >::Remove(const DynArray < int > & sorted_list)
    {
#line 421
        Remove(sorted_list.Begin(), sorted_list.GetCount());
    };
    
#line 403
    template < class _1 >
    inline void DynArray < _1 >::Remove(const Iterator& it)
    {
#line 404
        _1 * begin = data;
        _1 * cur = it.Get();
        int pos = cur - begin;
        Remove(pos);
    };
    
    template < class _1 >
    inline void DynArray < _1 >::Remove(const Iterator& it, const Iterator& end)
    {
#line 411
        _1 * begin = data;
        _1 * cur = it.Get();
        _1 * cur_end = end.Get();
        int pos0 = cur - begin;
        int pos1 = cur_end - begin;
        int len = pos1 - pos0;
        if (!len)
#line 417
            return;
        Remove(pos0, len);
    };
    
#line 422
    template < class _1 >
    inline void DynArray < _1 >::Remove(const int *sorted_list, int n)
    {
#line 423
        if (!n)
#line 423
            return;
        int pos = *sorted_list;
        int npos = pos;
        for (;;)
            {
                {
#line 427
                    if (!(pos < count))
                    {
#line 427
                        Lang::SysBreak("Assertion failed: pos < count");
                    }
                }
#line 428
                ;
#line 428
                if (pos == *sorted_list)
                {
#line 429
                    (data + pos)-> ~K();
                    pos ++ ;
                    sorted_list ++ ;
                    if (-- n == 0)
#line 432
                        break;
                    
                    {
#line 433
                        if (!(*sorted_list >= pos))
                        {
#line 433
                            Lang::SysBreak("Assertion failed: *sorted_list >= pos");
                        }
                    }
#line 434
                    ;
                }
                else
#line 436
                    Memory::Copy(data + npos ++ , data + pos ++ , sizeof (_1));
            }
        while (pos < count)
            Memory::Copy(data + npos ++ , data + pos ++ , sizeof (_1));
        count = npos;
    };
    
#line 388
    template < class _1 >
    inline void DynArray < _1 >::Remove(int i)
    {
        {
#line 389
            if (!(i >= 0 && i < count))
            {
#line 389
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 390
        ;
#line 390
        int tail = count - (i + 1);
        if (tail > 0)
            Memory::Move(data + i, data + i + 1, tail * sizeof (_1));
        count -- ;
    };
    
#line 395
    template < class _1 >
    inline void DynArray < _1 >::Remove(int i, int count)
    {
        {
#line 396
            if (!(count > 0))
            {
#line 396
                Lang::SysBreak("Assertion failed: count > 0");
            }
        }
#line 397
        ;
        {
#line 397
            if (!(i >= 0 && i + count <= this -> count))
            {
#line 397
                Lang::SysBreak("Assertion failed: i >= 0 && i + count <= this->count");
            }
        }
#line 398
        ;
#line 398
        int tail = this -> count - (i + count);
        if (tail > 0)
            Memory::Move(data + i, data + i + count, tail * sizeof (_1));
        this -> count -= count;
    };
    
#line 476
    template < class _1 >
    inline void DynArray < _1 >::RemoveLast()
    {
        {
#line 477
            if (!(GetCount() > 0))
            {
#line 477
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 478
        ;
#line 478
        data[-- count].~K();
    };
    
#line 363
    template < class _1 >
    inline void DynArray < _1 >::Reserve(int new_reserved)
    {
#line 364
        if (new_reserved <= reserved || new_reserved <= 0)
            return;
        _1 * new_data = (_1 * ) Memory::Alloc(new_reserved * sizeof (_1));
        if (data)
        {
#line 368
            if (count > 0)
                Memory::Copy((void * ) new_data, (void * ) data, sizeof (_1) * count);
            Memory::Free(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
#line 316
    template < class _1 >
    inline void DynArray < _1 >::SetCount(int new_count)
    {
        {
#line 317
            if (!(new_count >= 0))
            {
#line 317
                Lang::SysBreak("Assertion failed: new_count >= 0");
            }
        }
#line 318
        ;
#line 318
        if (new_count < 0)
#line 318
            return;
        if (new_count > reserved)
#line 319
            Reserve(new_count);
        if (new_count == count)
#line 320
            return;
        if (new_count > count)
        {
#line 322
            for (int i = count; i < new_count; i ++ )
                new (&data[i])_1;
        }
        else
        {
#line 326
            for (int i = count - 1; i >= new_count; i -- )
                Destruct(data[i]);
        }
#line 330
        count = new_count;
    };
    
#line 332
    template < class _1 >
    inline void DynArray < _1 >::SetCount(int new_count, ConstK& value)
    {
        {
#line 333
            if (!(new_count >= 0))
            {
#line 333
                Lang::SysBreak("Assertion failed: new_count >= 0");
            }
        }
#line 334
        ;
#line 334
        if (new_count < 0)
#line 334
            return;
        if (new_count > reserved)
#line 335
            Reserve(new_count);
        if (new_count == count)
#line 336
            return;
        if (new_count > count)
        {
#line 338
            for (int i = count; i < new_count; i ++ )
                new (&data[i])_1(value);
        }
        else
        {
#line 342
            for (int i = count - 1; i >= new_count; i -- )
                data[i].~K();
        }
        count = new_count;
    };
    
#line 465
    template < class _1 >
    inline _1& DynArray < _1 >::Top()
    {
        {
#line 465
            if (!(GetCount() > 0))
            {
#line 465
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 465
        ;
#line 465
        return data[count - 1];
    };
    
#line 278
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::begin() const
    {
#line 278
        return Begin();
    };
    
#line 276
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::begin()
    {
#line 276
        return Begin();
    };
    
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::end() const
    {
#line 279
        return End();
    };
    
#line 277
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::end()
    {
#line 277
        return End();
    };
    
#line 284
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::rbegin()
    {
#line 284
        return RBegin();
    };
    
#line 286
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::rbegin() const
    {
#line 286
        return RBegin();
    };
    
#line 285
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::rend()
    {
#line 285
        return REnd();
    };
    
#line 287
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::rend() const
    {
#line 287
        return REnd();
    };
    
#line 121
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator() {};
    
#line 151
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator(_1 *kit)
    :
        kit(kit)
    {};
    
#line 122
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator(const FwdIterator& it)
    {
#line 122
        *this = it;
    };
    
#line 158
    template < class _1 >
    inline bool FwdIterator < _1 >::operator!= (const FwdIterator& it) const
    {
#line 158
        return it.kit != kit;
    };
    
#line 157
    template < class _1 >
    inline _1& FwdIterator < _1 >::operator()() const
    {
#line 157
        return *Get();
    };
    
#line 156
    template < class _1 >
    inline _1& FwdIterator < _1 >::operator*() const
    {
#line 156
        return *Get();
    };
    
#line 124
    template < class _1 >
    inline FwdIterator < _1 > & FwdIterator < _1 >::operator++ ()
    {
#line 124
        kit += 1;
#line 124
        return *this;
    };
    
#line 126
    template < class _1 >
    inline void FwdIterator < _1 >::operator+= (int i)
    {
#line 126
        kit += i;
    };
    
#line 125
    template < class _1 >
    inline void FwdIterator < _1 >::operator-- (int i)
    {
#line 125
        kit -= 1;
    };
    
#line 154
    template < class _1 >
    inline _1 *FwdIterator < _1 >::operator-> () const
    {
#line 154
        return Get();
    };
    
#line 123
    template < class _1 >
    inline void FwdIterator < _1 >::operator= (const FwdIterator& it)
    {
#line 123
        kit = it.kit;
    };
    
#line 155
    template < class _1 >
    inline FwdIterator < _1 >::operator _1 * () const
    {
#line 155
        return Get();
    };
    
#line 152
    template < class _1 >
    inline _1 *FwdIterator < _1 >::Get() const
    {
#line 152
        return kit;
    };
    
#line 175
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 >::FwdPairIterator() {};
    
#line 176
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 >::FwdPairIterator(const FwdPairIterator& it)
    {
#line 176
        *this = it;
    };
    
#line 210
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 >::FwdPairIterator(const _1 *kit, _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 202
    template < class _1, class _2 >
    inline bool FwdPairIterator < _1, _2 >::operator!= (const FwdPairIterator& it) const
    {
#line 202
        return it.kit != kit;
    };
    
#line 178
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 > & FwdPairIterator < _1, _2 >::operator++ ()
    {
#line 178
        kit += 1;
#line 178
        vit += 1;
#line 178
        return *this;
    };
    
#line 180
    template < class _1, class _2 >
    inline void FwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 180
        kit += i;
#line 180
        vit += i;
    };
    
#line 179
    template < class _1, class _2 >
    inline void FwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 179
        kit -= 1;
#line 179
        vit -= 1;
    };
    
#line 177
    template < class _1, class _2 >
    inline void FwdPairIterator < _1, _2 >::operator= (const FwdPairIterator& it)
    {
#line 177
        kit = it.kit;
#line 177
        vit = it.vit;
    };
    
#line 201
    template < class _1, class _2 >
    inline const _1& FwdPairIterator < _1, _2 >::Key() const
    {
#line 201
        return *kit;
    };
    
#line 211
    template < class _1, class _2 >
    inline _2& FwdPairIterator < _1, _2 >::Value() const
    {
#line 211
        return *vit;
    };
    
#line 175
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 >::FwdPairPtrIterator() {};
    
#line 176
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 >::FwdPairPtrIterator(const FwdPairPtrIterator& it)
    {
#line 176
        *this = it;
    };
    
#line 205
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 >::FwdPairPtrIterator(const _1 *kit, _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 202
    template < class _1, class _2 >
    inline bool FwdPairPtrIterator < _1, _2 >::operator!= (const FwdPairPtrIterator& it) const
    {
#line 202
        return it.kit != kit;
    };
    
#line 178
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 > & FwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 178
        kit += 1;
#line 178
        vit += 1;
#line 178
        return *this;
    };
    
#line 180
    template < class _1, class _2 >
    inline void FwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 180
        kit += i;
#line 180
        vit += i;
    };
    
#line 179
    template < class _1, class _2 >
    inline void FwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 179
        kit -= 1;
#line 179
        vit -= 1;
    };
    
#line 177
    template < class _1, class _2 >
    inline void FwdPairPtrIterator < _1, _2 >::operator= (const FwdPairPtrIterator& it)
    {
#line 177
        kit = it.kit;
#line 177
        vit = it.vit;
    };
    
#line 201
    template < class _1, class _2 >
    inline const _1& FwdPairPtrIterator < _1, _2 >::Key() const
    {
#line 201
        return *kit;
    };
    
#line 206
    template < class _1, class _2 >
    inline _2& FwdPairPtrIterator < _1, _2 >::Value() const
    {
#line 206
        return **vit;
    };
    
#line 121
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator() {};
    
#line 147
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator(_1 **kit)
    :
        kit(kit)
    {};
    
#line 122
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator(const FwdPtrIterator& it)
    {
#line 122
        *this = it;
    };
    
#line 158
    template < class _1 >
    inline bool FwdPtrIterator < _1 >::operator!= (const FwdPtrIterator& it) const
    {
#line 158
        return it.kit != kit;
    };
    
#line 157
    template < class _1 >
    inline _1& FwdPtrIterator < _1 >::operator()() const
    {
#line 157
        return *Get();
    };
    
#line 156
    template < class _1 >
    inline _1& FwdPtrIterator < _1 >::operator*() const
    {
#line 156
        return *Get();
    };
    
#line 124
    template < class _1 >
    inline FwdPtrIterator < _1 > & FwdPtrIterator < _1 >::operator++ ()
    {
#line 124
        kit += 1;
#line 124
        return *this;
    };
    
#line 126
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator+= (int i)
    {
#line 126
        kit += i;
    };
    
#line 125
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator-- (int i)
    {
#line 125
        kit -= 1;
    };
    
#line 154
    template < class _1 >
    inline _1 *FwdPtrIterator < _1 >::operator-> () const
    {
#line 154
        return Get();
    };
    
#line 123
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator= (const FwdPtrIterator& it)
    {
#line 123
        kit = it.kit;
    };
    
#line 155
    template < class _1 >
    inline FwdPtrIterator < _1 >::operator _1 * () const
    {
#line 155
        return Get();
    };
    
#line 148
    template < class _1 >
    inline _1 *FwdPtrIterator < _1 >::Get() const
    {
#line 148
        return *kit;
    };
    
#line 110
    inline MemoryLimitExc::MemoryLimitExc()
    :
        msg(0)
    {};
    
#line 111
    inline MemoryLimitExc::MemoryLimitExc(const char *s)
    :
        msg(s)
    {};
    
};

#endif
