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
#line 7 "../../src/Com/Lang.fog"
    typedef Prim::CPtr < const char > CString;
    
#line 8
    extern CString ____unused_CString;
};

namespace Lang
{
#line 7
    typedef Prim::CPtr < const void > ConstVoidPtr;
    
#line 8
    extern ConstVoidPtr ____unused_ConstVoidPtr;
};

namespace Lang
{
#line 7
    typedef Prim::CPtr < void > VoidPtr;
    
#line 8
    extern VoidPtr ____unused_VoidPtr;
};

namespace Lang
{
#line 145 "../../src/Com/Meta.fog"
    typedef unsigned char byte;
    
#line 146
    extern byte ____unused_byte;
};

namespace Lang
{
#line 145
    typedef unsigned int uint32;
#line 145
    typedef uint32 dword;
    
#line 146
    extern dword ____unused_dword;
};

namespace Lang
{
#line 145
    typedef short int16;
    
#line 146
    extern int16 ____unused_int16;
};

namespace Lang
{
#line 145
    typedef int int32;
    
#line 146
    extern int32 ____unused_int32;
};

namespace Lang
{
#line 145
    typedef long long int64;
    
#line 146
    extern int64 ____unused_int64;
};

namespace Lang
{
#line 145
    typedef char int8;
    
#line 146
    extern int8 ____unused_int8;
};

namespace Lang
{
#line 145
    typedef unsigned long long uint64;
#line 145
    typedef uint64 qword;
    
#line 146
    extern qword ____unused_qword;
};

namespace Lang
{
#line 145
    typedef unsigned short uint16;
    
#line 146
    extern uint16 ____unused_uint16;
#line 146
    extern uint32 ____unused_uint32;
#line 146
    extern uint64 ____unused_uint64;
};

namespace Lang
{
#line 145
    typedef unsigned char uint8;
    
#line 146
    extern uint8 ____unused_uint8;
};

namespace Lang
{
#line 145
    typedef uint16 word;
    
#line 146
    extern word ____unused_word;
    
#line 33 "../../src/Com/Lang.fog"
    inline void Destruct(int16& o);
#line 35
    inline void Destruct(int32& o);
#line 37
    inline void Destruct(int64& o);
#line 31
    inline void Destruct(int8& o);
    inline void Destruct(uint16& o);
#line 34
    inline void Destruct(uint32& o);
#line 36
    inline void Destruct(uint64& o);
#line 30
    inline void Destruct(uint8& o);
#line 29
    template < class _1 >
    inline void Destruct(_1& o);
#line 39
    inline void Destruct(double& o);
#line 38
    inline void Destruct(float& o);
#line 40
    inline void Destruct(void *o);
#line 55
    int StringLength(const char *c, int max_len = 100000000);
    int StringLength(const short *c, int max_len = 100000000);
#line 53
    void SysBreak(const char *msg);
    
    struct AtomicBool
    {
#line 69
        AtomicBool();
        AtomicBool(bool b);
        AtomicBool(const AtomicBool& ai);
#line 73
        bool operator= (bool b);
#line 72
        operator bool();
    };
    
    struct AtomicFlag
    {
#line 61
        void Enter();
        void Leave();
        bool TryEnter();
    };
    
    struct AtomicInt
    {
#line 79
        AtomicInt();
#line 81
        AtomicInt(const AtomicInt& ai);
#line 80
        AtomicInt(int i);
#line 84
        int operator++ ();
#line 86
        int operator++ (int);
#line 85
        int operator-- ();
#line 87
        int operator-- (int);
#line 83
        int operator= (int i);
#line 82
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
#line 92
        ConditionalVar();
#line 95
        bool IsReady() const;
#line 94
        void SetReady(bool b = true);
#line 93
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
#line 255
        typedef ConstFwdIterator < _1 > ConstIterator;
#line 253
        typedef const _1 ConstK;
#line 256
        typedef ConstBwdIterator < _1 > ConstRIterator;
#line 251
        typedef const _1 ConstUnit;
#line 254
        typedef DynArray < _1 > DynArrayK;
#line 252
        typedef _1 IndirectK;
#line 257
        typedef FwdIterator < _1 > Iterator;
        typedef BwdIterator < _1 > RIterator;
#line 250
        typedef _1 Unit;
        
    private:
#line 229
        typedef unsigned long long uint64;
        
#line 232
        _1 *data;
        int reserved;
        int count;
        
    public:
#line 260
        inline DynArray();
        inline DynArray(const DynArray& v);
        inline DynArray(int i);
        inline ~DynArray();
#line 316
        inline DynArray < _1 > & operator<< (const _1& v);
#line 349
        inline void operator<<= (const DynArray& a);
#line 381
        inline _1& operator[](int i);
#line 385
        inline const _1& operator[](int i) const;
#line 294
        inline _1& Add();
#line 301
        inline _1& Add(const _1& v);
#line 356
        inline void Append(const DynArray& a);
#line 276
        inline Lang::ConstFwdIterator < _1 > Begin() const;
#line 274
        inline Lang::FwdIterator < _1 > Begin();
#line 483
        inline void Clear();
#line 277
        inline Lang::ConstFwdIterator < _1 > End() const;
#line 275
        inline Lang::FwdIterator < _1 > End();
#line 291
        inline _1 *Get() const;
#line 377
        inline int GetCount() const;
#line 292
        inline _1 *GetEnd() const;
#line 378
        inline int GetReserved() const;
#line 364
        inline void IncreaseReserve(int more_reserved);
#line 444
        inline _1& Insert(int i);
#line 455
        inline _1& Insert(int i, ConstK& key);
#line 379
        inline bool IsEmpty() const;
#line 469
        inline _1 Pop();
#line 282
        inline Lang::BwdIterator < _1 > RBegin();
#line 284
        inline Lang::ConstBwdIterator < _1 > RBegin() const;
#line 283
        inline Lang::BwdIterator < _1 > REnd();
#line 285
        inline Lang::ConstBwdIterator < _1 > REnd() const;
#line 423
        inline void Remove(const DynArray < int > & sorted_list);
#line 405
        inline void Remove(const Iterator& it);
#line 412
        inline void Remove(const Iterator& it, const Iterator& end);
#line 424
        inline void Remove(const int *sorted_list, int n);
#line 390
        inline void Remove(int i);
#line 397
        inline void Remove(int i, int count);
#line 478
        inline void RemoveLast();
#line 365
        inline void Reserve(int new_reserved);
#line 318
        inline void SetCount(int new_count);
#line 334
        inline void SetCount(int new_count, ConstK& value);
#line 467
        inline _1& Top();
#line 280
        inline Lang::ConstFwdIterator < _1 > begin() const;
#line 278
        inline Lang::FwdIterator < _1 > begin();
#line 281
        inline Lang::ConstFwdIterator < _1 > end() const;
#line 279
        inline Lang::FwdIterator < _1 > end();
#line 286
        inline Lang::BwdIterator < _1 > rbegin();
#line 288
        inline Lang::ConstBwdIterator < _1 > rbegin() const;
#line 287
        inline Lang::BwdIterator < _1 > rend();
#line 289
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
#line 44
        void *Alloc(int sz);
#line 46
        int Compare(const void *m1, const void *m2, int sz);
        void *Copy(void *dest, const void *src, int sz);
#line 45
        void Free(void *ptr);
#line 48
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
#line 33
    inline void Destruct(int16& o) {};
    
    inline void Destruct(int32& o) {};
    
    inline void Destruct(int64& o) {};
    
#line 31
    inline void Destruct(int8& o) {};
    
#line 32
    inline void Destruct(uint16& o) {};
    
    inline void Destruct(uint32& o) {};
    
    inline void Destruct(uint64& o) {};
    
#line 30
    inline void Destruct(uint8& o) {};
    
#line 29
    template < class _1 >
    inline void Destruct(_1& o)
    {
#line 29
        o.~_1();
    };
    
#line 39
    inline void Destruct(double& o) {};
    
#line 38
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
    
#line 260
    template < class _1 >
    inline DynArray < _1 >::DynArray()
    :
        data(0),
        reserved(0),
        count(0)
    {};
    
#line 261
    template < class _1 >
    inline DynArray < _1 >::DynArray(const DynArray& v)
    :
        data(0),
        reserved(0),
        count(0)
    {
#line 261
        *this <<= v;
    };
    
#line 262
    template < class _1 >
    inline DynArray < _1 >::DynArray(int i)
    :
        data(0),
        reserved(0),
        count(0)
    {
#line 262
        SetCount(i);
    };
    
#line 263
    template < class _1 >
    inline DynArray < _1 >::~DynArray()
    {
#line 264
        Clear();
        return;
        ;
    };
    
#line 316
    template < class _1 >
    inline DynArray < _1 > & DynArray < _1 >::operator<< (const _1& v)
    {
#line 316
        Add(v);
#line 316
        return *this;
    };
    
#line 349
    template < class _1 >
    inline void DynArray < _1 >::operator<<= (const DynArray& a)
    {
#line 350
        SetCount(0);
        Reserve(a.GetCount());
        for (int i = 0; i < a.GetCount(); i ++ )
            new (&data[i])_1(a[i]);
        count = a.GetCount();
    };
    
#line 381
    template < class _1 >
    inline _1& DynArray < _1 >::operator[](int i)
    {
        {
#line 382
            if (!(i >= 0 && i < count))
            {
#line 382
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 383
        ;
#line 383
        return *(data + i);
    };
    
#line 385
    template < class _1 >
    inline const _1& DynArray < _1 >::operator[](int i) const
    {
        {
#line 386
            if (!(i >= 0 && i < count))
            {
#line 386
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 387
        ;
#line 387
        return *(data + i);
    };
    
#line 294
    template < class _1 >
    inline _1& DynArray < _1 >::Add()
    {
#line 295
        if (count + 1 > reserved)
#line 295
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        new (&data[count])_1;
        return data[count ++ ];
    };
    
#line 301
    template < class _1 >
    inline _1& DynArray < _1 >::Add(const _1& v)
    {
#line 302
        if (count + 1 > reserved)
#line 302
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        _1 * ptr = &data[count];
        new (ptr)_1(v);
        return data[count ++ ];
    };
    
#line 356
    template < class _1 >
    inline void DynArray < _1 >::Append(const DynArray& a)
    {
#line 357
        int begin = count;
        int new_count = count + a.GetCount();
        Reserve(new_count);
        for (int i = begin, j = 0; i < new_count; i ++ , j ++ )
            new (&data[i])_1(a[j]);
        count = new_count;
    };
    
#line 276
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::Begin() const
    {
#line 276
        return ConstIterator(data);
    };
    
#line 274
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::Begin()
    {
#line 274
        return Iterator(data);
    };
    
#line 483
    template < class _1 >
    inline void DynArray < _1 >::Clear()
    {
#line 484
        if (!reserved)
#line 484
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
    
#line 277
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::End() const
    {
#line 277
        return ConstIterator(data + count);
    };
    
#line 275
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::End()
    {
#line 275
        return Iterator(data + count);
    };
    
#line 291
    template < class _1 >
    inline _1 *DynArray < _1 >::Get() const
    {
#line 291
        return data;
    };
    
#line 377
    template < class _1 >
    inline int DynArray < _1 >::GetCount() const
    {
#line 377
        return count;
    };
    
#line 292
    template < class _1 >
    inline _1 *DynArray < _1 >::GetEnd() const
    {
#line 292
        return data + count;
    };
    
#line 378
    template < class _1 >
    inline int DynArray < _1 >::GetReserved() const
    {
#line 378
        return reserved;
    };
    
#line 364
    template < class _1 >
    inline void DynArray < _1 >::IncreaseReserve(int more_reserved)
    {
#line 364
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
    
#line 444
    template < class _1 >
    inline _1& DynArray < _1 >::Insert(int i)
    {
#line 445
        if (count + 1 > reserved)
#line 445
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
    
#line 455
    template < class _1 >
    inline _1& DynArray < _1 >::Insert(int i, ConstK& key)
    {
#line 456
        if (count + 1 > reserved)
#line 456
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
    
#line 379
    template < class _1 >
    inline bool DynArray < _1 >::IsEmpty() const
    {
#line 379
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
    
#line 469
    template < class _1 >
    inline _1 DynArray < _1 >::Pop()
    {
        {
#line 470
            if (!(GetCount() > 0))
            {
#line 470
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 471
        ;
#line 471
        int i = count - 1;
        _1 ret(data[i]);
        Destruct(data[i]);
        count -- ;
        return ret;
    };
    
#line 282
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::RBegin()
    {
#line 282
        return RIterator(data + count - 1);
    };
    
#line 284
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::RBegin() const
    {
#line 284
        return ConstRIterator(data + count - 1);
    };
    
#line 283
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::REnd()
    {
#line 283
        return RIterator(data - 1);
    };
    
#line 285
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::REnd() const
    {
#line 285
        return ConstRIterator(data - 1);
    };
    
#line 423
    template < class _1 >
    inline void DynArray < _1 >::Remove(const DynArray < int > & sorted_list)
    {
#line 423
        Remove(sorted_list.Begin(), sorted_list.GetCount());
    };
    
#line 405
    template < class _1 >
    inline void DynArray < _1 >::Remove(const Iterator& it)
    {
#line 406
        _1 * begin = data;
        _1 * cur = it.Get();
        int pos = cur - begin;
        Remove(pos);
    };
    
    template < class _1 >
    inline void DynArray < _1 >::Remove(const Iterator& it, const Iterator& end)
    {
#line 413
        _1 * begin = data;
        _1 * cur = it.Get();
        _1 * cur_end = end.Get();
        int pos0 = cur - begin;
        int pos1 = cur_end - begin;
        int len = pos1 - pos0;
        if (!len)
#line 419
            return;
        Remove(pos0, len);
    };
    
#line 424
    template < class _1 >
    inline void DynArray < _1 >::Remove(const int *sorted_list, int n)
    {
#line 425
        if (!n)
#line 425
            return;
        int pos = *sorted_list;
        int npos = pos;
        for (;;)
            {
                {
#line 429
                    if (!(pos < count))
                    {
#line 429
                        Lang::SysBreak("Assertion failed: pos < count");
                    }
                }
#line 430
                ;
#line 430
                if (pos == *sorted_list)
                {
#line 431
                    (data + pos)-> ~K();
                    pos ++ ;
                    sorted_list ++ ;
                    if (-- n == 0)
#line 434
                        break;
                    
                    {
#line 435
                        if (!(*sorted_list >= pos))
                        {
#line 435
                            Lang::SysBreak("Assertion failed: *sorted_list >= pos");
                        }
                    }
#line 436
                    ;
                }
                else
#line 438
                    Memory::Copy(data + npos ++ , data + pos ++ , sizeof (_1));
            }
        while (pos < count)
            Memory::Copy(data + npos ++ , data + pos ++ , sizeof (_1));
        count = npos;
    };
    
#line 390
    template < class _1 >
    inline void DynArray < _1 >::Remove(int i)
    {
        {
#line 391
            if (!(i >= 0 && i < count))
            {
#line 391
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 392
        ;
#line 392
        int tail = count - (i + 1);
        if (tail > 0)
            Memory::Move(data + i, data + i + 1, tail * sizeof (_1));
        count -- ;
    };
    
#line 397
    template < class _1 >
    inline void DynArray < _1 >::Remove(int i, int count)
    {
        {
#line 398
            if (!(count > 0))
            {
#line 398
                Lang::SysBreak("Assertion failed: count > 0");
            }
        }
#line 399
        ;
        {
#line 399
            if (!(i >= 0 && i + count <= this -> count))
            {
#line 399
                Lang::SysBreak("Assertion failed: i >= 0 && i + count <= this->count");
            }
        }
#line 400
        ;
#line 400
        int tail = this -> count - (i + count);
        if (tail > 0)
            Memory::Move(data + i, data + i + count, tail * sizeof (_1));
        this -> count -= count;
    };
    
#line 478
    template < class _1 >
    inline void DynArray < _1 >::RemoveLast()
    {
        {
#line 479
            if (!(GetCount() > 0))
            {
#line 479
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 480
        ;
#line 480
        data[-- count].~K();
    };
    
#line 365
    template < class _1 >
    inline void DynArray < _1 >::Reserve(int new_reserved)
    {
#line 366
        if (new_reserved <= reserved || new_reserved <= 0)
            return;
        _1 * new_data = (_1 * ) Memory::Alloc(new_reserved * sizeof (_1));
        if (data)
        {
#line 370
            if (count > 0)
                Memory::Copy((void * ) new_data, (void * ) data, sizeof (_1) * count);
            Memory::Free(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
#line 318
    template < class _1 >
    inline void DynArray < _1 >::SetCount(int new_count)
    {
        {
#line 319
            if (!(new_count >= 0))
            {
#line 319
                Lang::SysBreak("Assertion failed: new_count >= 0");
            }
        }
#line 320
        ;
#line 320
        if (new_count < 0)
#line 320
            return;
        if (new_count > reserved)
#line 321
            Reserve(new_count);
        if (new_count == count)
#line 322
            return;
        if (new_count > count)
        {
#line 324
            for (int i = count; i < new_count; i ++ )
                new (&data[i])_1;
        }
        else
        {
#line 328
            for (int i = count - 1; i >= new_count; i -- )
                Destruct(data[i]);
        }
#line 332
        count = new_count;
    };
    
#line 334
    template < class _1 >
    inline void DynArray < _1 >::SetCount(int new_count, ConstK& value)
    {
        {
#line 335
            if (!(new_count >= 0))
            {
#line 335
                Lang::SysBreak("Assertion failed: new_count >= 0");
            }
        }
#line 336
        ;
#line 336
        if (new_count < 0)
#line 336
            return;
        if (new_count > reserved)
#line 337
            Reserve(new_count);
        if (new_count == count)
#line 338
            return;
        if (new_count > count)
        {
#line 340
            for (int i = count; i < new_count; i ++ )
                new (&data[i])_1(value);
        }
        else
        {
#line 344
            for (int i = count - 1; i >= new_count; i -- )
                Destruct(data[i]);
        }
        count = new_count;
    };
    
#line 467
    template < class _1 >
    inline _1& DynArray < _1 >::Top()
    {
        {
#line 467
            if (!(GetCount() > 0))
            {
#line 467
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 467
        ;
#line 467
        return data[count - 1];
    };
    
#line 280
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::begin() const
    {
#line 280
        return Begin();
    };
    
#line 278
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::begin()
    {
#line 278
        return Begin();
    };
    
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::end() const
    {
#line 281
        return End();
    };
    
#line 279
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::end()
    {
#line 279
        return End();
    };
    
#line 286
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::rbegin()
    {
#line 286
        return RBegin();
    };
    
#line 288
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::rbegin() const
    {
#line 288
        return RBegin();
    };
    
#line 287
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::rend()
    {
#line 287
        return REnd();
    };
    
#line 289
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::rend() const
    {
#line 289
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
