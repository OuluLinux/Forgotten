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
#line 151
        _1 *kit;
        
    public:
#line 122
        inline BwdIterator();
#line 152
        inline BwdIterator(_1 *kit);
#line 123
        inline BwdIterator(const BwdIterator& it);
#line 159
        inline bool operator!= (const BwdIterator& it) const;
#line 158
        inline _1& operator()() const;
#line 157
        inline _1& operator*() const;
#line 125
        inline BwdIterator < _1 > & operator++ ();
#line 127
        inline void operator+= (int i);
#line 126
        inline void operator-- (int i);
#line 155
        inline _1 *operator-> () const;
#line 124
        inline void operator= (const BwdIterator& it);
#line 156
        inline operator _1 * () const;
#line 153
        inline _1 *Get() const;
    };
    
    template < class _1, class _2 >
    class BwdPairIterator
    {
#line 201
        const _1 *kit;
#line 210
        _2 *vit;
        
    public:
#line 176
        inline BwdPairIterator();
        inline BwdPairIterator(const BwdPairIterator& it);
#line 211
        inline BwdPairIterator(const _1 *kit, _2 *vit);
#line 203
        inline bool operator!= (const BwdPairIterator& it) const;
#line 179
        inline BwdPairIterator < _1, _2 > & operator++ ();
#line 181
        inline void operator+= (int i);
#line 180
        inline void operator-- (int i);
#line 178
        inline void operator= (const BwdPairIterator& it);
#line 212
        inline _2& Value() const;
        
#line 202
        inline const _1& Key() const;
    };
    
    template < class _1, class _2 >
    class BwdPairPtrIterator
    {
#line 201
        const _1 *kit;
#line 205
        _2 **vit;
        
    public:
#line 176
        inline BwdPairPtrIterator();
        inline BwdPairPtrIterator(const BwdPairPtrIterator& it);
#line 206
        inline BwdPairPtrIterator(const _1 *kit, _2 **vit);
#line 203
        inline bool operator!= (const BwdPairPtrIterator& it) const;
#line 179
        inline BwdPairPtrIterator < _1, _2 > & operator++ ();
#line 181
        inline void operator+= (int i);
#line 180
        inline void operator-- (int i);
#line 178
        inline void operator= (const BwdPairPtrIterator& it);
#line 207
        inline _2& Value() const;
        
#line 202
        inline const _1& Key() const;
    };
    
    template < class _1 >
    class BwdPtrIterator
    {
#line 147
        _1 **kit;
        
    public:
#line 122
        inline BwdPtrIterator();
#line 148
        inline BwdPtrIterator(_1 **kit);
#line 123
        inline BwdPtrIterator(const BwdPtrIterator& it);
#line 159
        inline bool operator!= (const BwdPtrIterator& it) const;
#line 158
        inline _1& operator()() const;
#line 157
        inline _1& operator*() const;
#line 125
        inline BwdPtrIterator < _1 > & operator++ ();
#line 127
        inline void operator+= (int i);
#line 126
        inline void operator-- (int i);
#line 155
        inline _1 *operator-> () const;
#line 124
        inline void operator= (const BwdPtrIterator& it);
#line 156
        inline operator _1 * () const;
#line 149
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
#line 130
        typedef const _1 ConstK;
        
#line 136
        const _1 *kit;
        
    public:
#line 122
        inline ConstBwdIterator();
        inline ConstBwdIterator(const ConstBwdIterator& it);
#line 137
        inline ConstBwdIterator(const _1 *kit);
#line 144
        inline bool operator!= (const ConstBwdIterator& it) const;
#line 143
        inline const _1& operator()() const;
#line 142
        inline const _1& operator*() const;
#line 125
        inline ConstBwdIterator < _1 > & operator++ ();
#line 127
        inline void operator+= (int i);
#line 126
        inline void operator-- (int i);
#line 140
        inline const _1 *operator-> () const;
#line 124
        inline void operator= (const ConstBwdIterator& it);
#line 141
        inline operator ConstK * () const;
#line 138
        inline const _1 *Get() const;
    };
    
    template < class _1, class _2 >
    class ConstBwdPairIterator
    {
#line 184
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 186
        const _1 *kit;
#line 195
        const _2 **vit;
        
    public:
#line 176
        inline ConstBwdPairIterator();
        inline ConstBwdPairIterator(const ConstBwdPairIterator& it);
#line 196
        inline ConstBwdPairIterator(const _1 *kit, const _2 **vit);
#line 188
        inline bool operator!= (const ConstBwdPairIterator& it) const;
#line 179
        inline ConstBwdPairIterator < _1, _2 > & operator++ ();
#line 181
        inline void operator+= (int i);
#line 180
        inline void operator-- (int i);
#line 178
        inline void operator= (const ConstBwdPairIterator& it);
#line 187
        inline const _1& Key() const;
#line 197
        inline const _2& Value() const;
    };
    
    template < class _1, class _2 >
    class ConstBwdPairPtrIterator
    {
#line 184
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 186
        const _1 *kit;
#line 190
        const _2 *vit;
        
    public:
#line 176
        inline ConstBwdPairPtrIterator();
        inline ConstBwdPairPtrIterator(const ConstBwdPairPtrIterator& it);
#line 191
        inline ConstBwdPairPtrIterator(const _1 *kit, const _2 *vit);
#line 188
        inline bool operator!= (const ConstBwdPairPtrIterator& it) const;
#line 179
        inline ConstBwdPairPtrIterator < _1, _2 > & operator++ ();
#line 181
        inline void operator+= (int i);
#line 180
        inline void operator-- (int i);
#line 178
        inline void operator= (const ConstBwdPairPtrIterator& it);
#line 187
        inline const _1& Key() const;
#line 192
        inline const _2& Value() const;
    };
    
    template < class _1 >
    class ConstBwdPtrIterator
    {
    public:
#line 130
        typedef const _1 ConstK;
        
        const _1 **kit;
        
    public:
#line 122
        inline ConstBwdPtrIterator();
        inline ConstBwdPtrIterator(const ConstBwdPtrIterator& it);
#line 133
        inline ConstBwdPtrIterator(const _1 **kit);
#line 144
        inline bool operator!= (const ConstBwdPtrIterator& it) const;
#line 143
        inline const _1& operator()() const;
#line 142
        inline const _1& operator*() const;
#line 125
        inline ConstBwdPtrIterator < _1 > & operator++ ();
#line 127
        inline void operator+= (int i);
#line 126
        inline void operator-- (int i);
#line 140
        inline const _1 *operator-> () const;
#line 124
        inline void operator= (const ConstBwdPtrIterator& it);
#line 141
        inline operator ConstK * () const;
#line 134
        inline const _1 *Get() const;
    };
    
    template < class _1 >
    class ConstFwdIterator
    {
    public:
#line 130
        typedef const _1 ConstK;
        
#line 136
        const _1 *kit;
        
    public:
#line 122
        inline ConstFwdIterator();
        inline ConstFwdIterator(const ConstFwdIterator& it);
#line 137
        inline ConstFwdIterator(const _1 *kit);
#line 144
        inline bool operator!= (const ConstFwdIterator& it) const;
#line 143
        inline const _1& operator()() const;
#line 142
        inline const _1& operator*() const;
#line 125
        inline ConstFwdIterator < _1 > & operator++ ();
#line 127
        inline void operator+= (int i);
#line 126
        inline void operator-- (int i);
#line 140
        inline const _1 *operator-> () const;
#line 124
        inline void operator= (const ConstFwdIterator& it);
#line 141
        inline operator ConstK * () const;
#line 138
        inline const _1 *Get() const;
    };
    
    template < class _1, class _2 >
    class ConstFwdPairIterator
    {
#line 184
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 186
        const _1 *kit;
#line 195
        const _2 **vit;
        
    public:
#line 176
        inline ConstFwdPairIterator();
        inline ConstFwdPairIterator(const ConstFwdPairIterator& it);
#line 196
        inline ConstFwdPairIterator(const _1 *kit, const _2 **vit);
#line 188
        inline bool operator!= (const ConstFwdPairIterator& it) const;
#line 179
        inline ConstFwdPairIterator < _1, _2 > & operator++ ();
#line 181
        inline void operator+= (int i);
#line 180
        inline void operator-- (int i);
#line 178
        inline void operator= (const ConstFwdPairIterator& it);
#line 187
        inline const _1& Key() const;
#line 197
        inline const _2& Value() const;
    };
    
    template < class _1, class _2 >
    class ConstFwdPairPtrIterator
    {
#line 184
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 186
        const _1 *kit;
#line 190
        const _2 *vit;
        
    public:
#line 176
        inline ConstFwdPairPtrIterator();
        inline ConstFwdPairPtrIterator(const ConstFwdPairPtrIterator& it);
#line 191
        inline ConstFwdPairPtrIterator(const _1 *kit, const _2 *vit);
#line 188
        inline bool operator!= (const ConstFwdPairPtrIterator& it) const;
#line 179
        inline ConstFwdPairPtrIterator < _1, _2 > & operator++ ();
#line 181
        inline void operator+= (int i);
#line 180
        inline void operator-- (int i);
#line 178
        inline void operator= (const ConstFwdPairPtrIterator& it);
#line 187
        inline const _1& Key() const;
#line 192
        inline const _2& Value() const;
    };
    
    template < class _1 >
    class ConstFwdPtrIterator
    {
    public:
#line 130
        typedef const _1 ConstK;
        
        const _1 **kit;
        
    public:
#line 122
        inline ConstFwdPtrIterator();
        inline ConstFwdPtrIterator(const ConstFwdPtrIterator& it);
#line 133
        inline ConstFwdPtrIterator(const _1 **kit);
#line 144
        inline bool operator!= (const ConstFwdPtrIterator& it) const;
#line 143
        inline const _1& operator()() const;
#line 142
        inline const _1& operator*() const;
#line 125
        inline ConstFwdPtrIterator < _1 > & operator++ ();
#line 127
        inline void operator+= (int i);
#line 126
        inline void operator-- (int i);
#line 140
        inline const _1 *operator-> () const;
#line 124
        inline void operator= (const ConstFwdPtrIterator& it);
#line 141
        inline operator ConstK * () const;
#line 134
        inline const _1 *Get() const;
    };
    
    template < class _1 >
    class FwdIterator
    {
#line 151
        _1 *kit;
        
    public:
#line 122
        inline FwdIterator();
#line 152
        inline FwdIterator(_1 *kit);
#line 123
        inline FwdIterator(const FwdIterator& it);
#line 159
        inline bool operator!= (const FwdIterator& it) const;
#line 158
        inline _1& operator()() const;
#line 157
        inline _1& operator*() const;
#line 125
        inline FwdIterator < _1 > & operator++ ();
#line 127
        inline void operator+= (int i);
#line 126
        inline void operator-- (int i);
#line 155
        inline _1 *operator-> () const;
#line 124
        inline void operator= (const FwdIterator& it);
#line 156
        inline operator _1 * () const;
#line 153
        inline _1 *Get() const;
    };
    
    template < class _1 >
    class DynArray
    {
    public:
#line 254
        typedef ConstFwdIterator < _1 > ConstIterator;
#line 252
        typedef const _1 ConstK;
#line 255
        typedef ConstBwdIterator < _1 > ConstRIterator;
#line 253
        typedef DynArray < _1 > DynArrayK;
#line 251
        typedef _1 IndirectK;
#line 256
        typedef FwdIterator < _1 > Iterator;
        typedef BwdIterator < _1 > RIterator;
        
    private:
#line 230
        typedef unsigned long long uint64;
        
#line 233
        _1 *data;
        int reserved;
        int count;
        
    public:
#line 259
        inline DynArray();
        inline DynArray(const DynArray& v);
        inline DynArray(int i);
        inline ~DynArray();
#line 315
        inline DynArray < _1 > & operator<< (const _1& v);
#line 348
        inline void operator<<= (const DynArray& a);
#line 380
        inline _1& operator[](int i);
#line 384
        inline const _1& operator[](int i) const;
#line 293
        inline _1& Add();
#line 300
        inline _1& Add(const _1& v);
#line 355
        inline void Append(const DynArray& a);
#line 275
        inline Lang::ConstFwdIterator < _1 > Begin() const;
#line 273
        inline Lang::FwdIterator < _1 > Begin();
#line 482
        inline void Clear();
#line 276
        inline Lang::ConstFwdIterator < _1 > End() const;
#line 274
        inline Lang::FwdIterator < _1 > End();
#line 290
        inline _1 *Get() const;
#line 376
        inline int GetCount() const;
#line 291
        inline _1 *GetEnd() const;
#line 377
        inline int GetReserved() const;
#line 363
        inline void IncreaseReserve(int more_reserved);
#line 443
        inline _1& Insert(int i);
#line 454
        inline _1& Insert(int i, ConstK& key);
#line 378
        inline bool IsEmpty() const;
#line 468
        inline _1 Pop();
#line 281
        inline Lang::BwdIterator < _1 > RBegin();
#line 283
        inline Lang::ConstBwdIterator < _1 > RBegin() const;
#line 282
        inline Lang::BwdIterator < _1 > REnd();
#line 284
        inline Lang::ConstBwdIterator < _1 > REnd() const;
#line 422
        inline void Remove(const DynArray < int > & sorted_list);
#line 404
        inline void Remove(const Iterator& it);
#line 411
        inline void Remove(const Iterator& it, const Iterator& end);
#line 423
        inline void Remove(const int *sorted_list, int n);
#line 389
        inline void Remove(int i);
#line 396
        inline void Remove(int i, int count);
#line 477
        inline void RemoveLast();
#line 364
        inline void Reserve(int new_reserved);
#line 317
        inline void SetCount(int new_count);
#line 333
        inline void SetCount(int new_count, ConstK& value);
#line 466
        inline _1& Top();
#line 279
        inline Lang::ConstFwdIterator < _1 > begin() const;
#line 277
        inline Lang::FwdIterator < _1 > begin();
#line 280
        inline Lang::ConstFwdIterator < _1 > end() const;
#line 278
        inline Lang::FwdIterator < _1 > end();
#line 285
        inline Lang::BwdIterator < _1 > rbegin();
#line 287
        inline Lang::ConstBwdIterator < _1 > rbegin() const;
#line 286
        inline Lang::BwdIterator < _1 > rend();
#line 288
        inline Lang::ConstBwdIterator < _1 > rend() const;
        
#line 238
        inline void IncreaseReserved();
#line 247
        inline void Pick0(DynArray& v);
    };
    
    template < class _1, class _2 >
    class FwdPairIterator
    {
#line 201
        const _1 *kit;
#line 210
        _2 *vit;
        
    public:
#line 176
        inline FwdPairIterator();
        inline FwdPairIterator(const FwdPairIterator& it);
#line 211
        inline FwdPairIterator(const _1 *kit, _2 *vit);
#line 203
        inline bool operator!= (const FwdPairIterator& it) const;
#line 179
        inline FwdPairIterator < _1, _2 > & operator++ ();
#line 181
        inline void operator+= (int i);
#line 180
        inline void operator-- (int i);
#line 178
        inline void operator= (const FwdPairIterator& it);
#line 212
        inline _2& Value() const;
        
#line 202
        inline const _1& Key() const;
    };
    
    template < class _1, class _2 >
    class FwdPairPtrIterator
    {
#line 201
        const _1 *kit;
#line 205
        _2 **vit;
        
    public:
#line 176
        inline FwdPairPtrIterator();
        inline FwdPairPtrIterator(const FwdPairPtrIterator& it);
#line 206
        inline FwdPairPtrIterator(const _1 *kit, _2 **vit);
#line 203
        inline bool operator!= (const FwdPairPtrIterator& it) const;
#line 179
        inline FwdPairPtrIterator < _1, _2 > & operator++ ();
#line 181
        inline void operator+= (int i);
#line 180
        inline void operator-- (int i);
#line 178
        inline void operator= (const FwdPairPtrIterator& it);
#line 207
        inline _2& Value() const;
        
#line 202
        inline const _1& Key() const;
    };
    
    template < class _1 >
    class FwdPtrIterator
    {
#line 147
        _1 **kit;
        
    public:
#line 122
        inline FwdPtrIterator();
#line 148
        inline FwdPtrIterator(_1 **kit);
#line 123
        inline FwdPtrIterator(const FwdPtrIterator& it);
#line 159
        inline bool operator!= (const FwdPtrIterator& it) const;
#line 158
        inline _1& operator()() const;
#line 157
        inline _1& operator*() const;
#line 125
        inline FwdPtrIterator < _1 > & operator++ ();
#line 127
        inline void operator+= (int i);
#line 126
        inline void operator-- (int i);
#line 155
        inline _1 *operator-> () const;
#line 124
        inline void operator= (const FwdPtrIterator& it);
#line 156
        inline operator _1 * () const;
#line 149
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
#line 110
        const char *msg;
        
#line 111
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
    
#line 122
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator() {};
    
#line 152
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator(_1 *kit)
    :
        kit(kit)
    {};
    
#line 123
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator(const BwdIterator& it)
    {
#line 123
        *this = it;
    };
    
#line 159
    template < class _1 >
    inline bool BwdIterator < _1 >::operator!= (const BwdIterator& it) const
    {
#line 159
        return it.kit != kit;
    };
    
#line 158
    template < class _1 >
    inline _1& BwdIterator < _1 >::operator()() const
    {
#line 158
        return *Get();
    };
    
#line 157
    template < class _1 >
    inline _1& BwdIterator < _1 >::operator*() const
    {
#line 157
        return *Get();
    };
    
#line 125
    template < class _1 >
    inline BwdIterator < _1 > & BwdIterator < _1 >::operator++ ()
    {
#line 125
        kit += -1;
#line 125
        return *this;
    };
    
#line 127
    template < class _1 >
    inline void BwdIterator < _1 >::operator+= (int i)
    {
#line 127
        kit += i;
    };
    
#line 126
    template < class _1 >
    inline void BwdIterator < _1 >::operator-- (int i)
    {
#line 126
        kit -= -1;
    };
    
#line 155
    template < class _1 >
    inline _1 *BwdIterator < _1 >::operator-> () const
    {
#line 155
        return Get();
    };
    
#line 124
    template < class _1 >
    inline void BwdIterator < _1 >::operator= (const BwdIterator& it)
    {
#line 124
        kit = it.kit;
    };
    
#line 156
    template < class _1 >
    inline BwdIterator < _1 >::operator _1 * () const
    {
#line 156
        return Get();
    };
    
#line 153
    template < class _1 >
    inline _1 *BwdIterator < _1 >::Get() const
    {
#line 153
        return kit;
    };
    
#line 176
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 >::BwdPairIterator() {};
    
#line 177
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 >::BwdPairIterator(const BwdPairIterator& it)
    {
#line 177
        *this = it;
    };
    
#line 211
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 >::BwdPairIterator(const _1 *kit, _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 203
    template < class _1, class _2 >
    inline bool BwdPairIterator < _1, _2 >::operator!= (const BwdPairIterator& it) const
    {
#line 203
        return it.kit != kit;
    };
    
#line 179
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 > & BwdPairIterator < _1, _2 >::operator++ ()
    {
#line 179
        kit += -1;
#line 179
        vit += -1;
#line 179
        return *this;
    };
    
#line 181
    template < class _1, class _2 >
    inline void BwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 181
        kit += i;
#line 181
        vit += i;
    };
    
#line 180
    template < class _1, class _2 >
    inline void BwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 180
        kit -= -1;
#line 180
        vit -= -1;
    };
    
#line 178
    template < class _1, class _2 >
    inline void BwdPairIterator < _1, _2 >::operator= (const BwdPairIterator& it)
    {
#line 178
        kit = it.kit;
#line 178
        vit = it.vit;
    };
    
#line 202
    template < class _1, class _2 >
    inline const _1& BwdPairIterator < _1, _2 >::Key() const
    {
#line 202
        return *kit;
    };
    
#line 212
    template < class _1, class _2 >
    inline _2& BwdPairIterator < _1, _2 >::Value() const
    {
#line 212
        return *vit;
    };
    
#line 176
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 >::BwdPairPtrIterator() {};
    
#line 177
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 >::BwdPairPtrIterator(const BwdPairPtrIterator& it)
    {
#line 177
        *this = it;
    };
    
#line 206
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 >::BwdPairPtrIterator(const _1 *kit, _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 203
    template < class _1, class _2 >
    inline bool BwdPairPtrIterator < _1, _2 >::operator!= (const BwdPairPtrIterator& it) const
    {
#line 203
        return it.kit != kit;
    };
    
#line 179
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 > & BwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 179
        kit += -1;
#line 179
        vit += -1;
#line 179
        return *this;
    };
    
#line 181
    template < class _1, class _2 >
    inline void BwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 181
        kit += i;
#line 181
        vit += i;
    };
    
#line 180
    template < class _1, class _2 >
    inline void BwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 180
        kit -= -1;
#line 180
        vit -= -1;
    };
    
#line 178
    template < class _1, class _2 >
    inline void BwdPairPtrIterator < _1, _2 >::operator= (const BwdPairPtrIterator& it)
    {
#line 178
        kit = it.kit;
#line 178
        vit = it.vit;
    };
    
#line 202
    template < class _1, class _2 >
    inline const _1& BwdPairPtrIterator < _1, _2 >::Key() const
    {
#line 202
        return *kit;
    };
    
#line 207
    template < class _1, class _2 >
    inline _2& BwdPairPtrIterator < _1, _2 >::Value() const
    {
#line 207
        return **vit;
    };
    
#line 122
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator() {};
    
#line 148
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator(_1 **kit)
    :
        kit(kit)
    {};
    
#line 123
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator(const BwdPtrIterator& it)
    {
#line 123
        *this = it;
    };
    
#line 159
    template < class _1 >
    inline bool BwdPtrIterator < _1 >::operator!= (const BwdPtrIterator& it) const
    {
#line 159
        return it.kit != kit;
    };
    
#line 158
    template < class _1 >
    inline _1& BwdPtrIterator < _1 >::operator()() const
    {
#line 158
        return *Get();
    };
    
#line 157
    template < class _1 >
    inline _1& BwdPtrIterator < _1 >::operator*() const
    {
#line 157
        return *Get();
    };
    
#line 125
    template < class _1 >
    inline BwdPtrIterator < _1 > & BwdPtrIterator < _1 >::operator++ ()
    {
#line 125
        kit += -1;
#line 125
        return *this;
    };
    
#line 127
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator+= (int i)
    {
#line 127
        kit += i;
    };
    
#line 126
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator-- (int i)
    {
#line 126
        kit -= -1;
    };
    
#line 155
    template < class _1 >
    inline _1 *BwdPtrIterator < _1 >::operator-> () const
    {
#line 155
        return Get();
    };
    
#line 124
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator= (const BwdPtrIterator& it)
    {
#line 124
        kit = it.kit;
    };
    
#line 156
    template < class _1 >
    inline BwdPtrIterator < _1 >::operator _1 * () const
    {
#line 156
        return Get();
    };
    
#line 149
    template < class _1 >
    inline _1 *BwdPtrIterator < _1 >::Get() const
    {
#line 149
        return *kit;
    };
    
#line 122
    template < class _1 >
    inline ConstBwdIterator < _1 >::ConstBwdIterator() {};
    
#line 123
    template < class _1 >
    inline ConstBwdIterator < _1 >::ConstBwdIterator(const ConstBwdIterator& it)
    {
#line 123
        *this = it;
    };
    
#line 137
    template < class _1 >
    inline ConstBwdIterator < _1 >::ConstBwdIterator(const _1 *kit)
    :
        kit(kit)
    {};
    
#line 144
    template < class _1 >
    inline bool ConstBwdIterator < _1 >::operator!= (const ConstBwdIterator& it) const
    {
#line 144
        return it.kit != kit;
    };
    
#line 143
    template < class _1 >
    inline const _1& ConstBwdIterator < _1 >::operator()() const
    {
#line 143
        return *Get();
    };
    
#line 142
    template < class _1 >
    inline const _1& ConstBwdIterator < _1 >::operator*() const
    {
#line 142
        return *Get();
    };
    
#line 125
    template < class _1 >
    inline ConstBwdIterator < _1 > & ConstBwdIterator < _1 >::operator++ ()
    {
#line 125
        kit += -1;
#line 125
        return *this;
    };
    
#line 127
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator+= (int i)
    {
#line 127
        kit += i;
    };
    
#line 126
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator-- (int i)
    {
#line 126
        kit -= -1;
    };
    
#line 140
    template < class _1 >
    inline const _1 *ConstBwdIterator < _1 >::operator-> () const
    {
#line 140
        return Get();
    };
    
#line 124
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator= (const ConstBwdIterator& it)
    {
#line 124
        kit = it.kit;
    };
    
#line 141
    template < class _1 >
    inline ConstBwdIterator < _1 >::operator ConstK * () const
    {
#line 141
        return Get();
    };
    
#line 138
    template < class _1 >
    inline const _1 *ConstBwdIterator < _1 >::Get() const
    {
#line 138
        return kit;
    };
    
#line 176
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 >::ConstBwdPairIterator() {};
    
#line 177
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 >::ConstBwdPairIterator(const ConstBwdPairIterator& it)
    {
#line 177
        *this = it;
    };
    
#line 196
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 >::ConstBwdPairIterator(const _1 *kit, const _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 188
    template < class _1, class _2 >
    inline bool ConstBwdPairIterator < _1, _2 >::operator!= (const ConstBwdPairIterator& it) const
    {
#line 188
        return it.kit != kit;
    };
    
#line 179
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 > & ConstBwdPairIterator < _1, _2 >::operator++ ()
    {
#line 179
        kit += -1;
#line 179
        vit += -1;
#line 179
        return *this;
    };
    
#line 181
    template < class _1, class _2 >
    inline void ConstBwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 181
        kit += i;
#line 181
        vit += i;
    };
    
#line 180
    template < class _1, class _2 >
    inline void ConstBwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 180
        kit -= -1;
#line 180
        vit -= -1;
    };
    
#line 178
    template < class _1, class _2 >
    inline void ConstBwdPairIterator < _1, _2 >::operator= (const ConstBwdPairIterator& it)
    {
#line 178
        kit = it.kit;
#line 178
        vit = it.vit;
    };
    
#line 187
    template < class _1, class _2 >
    inline const _1& ConstBwdPairIterator < _1, _2 >::Key() const
    {
#line 187
        return *kit;
    };
    
#line 197
    template < class _1, class _2 >
    inline const _2& ConstBwdPairIterator < _1, _2 >::Value() const
    {
#line 197
        return **vit;
    };
    
#line 176
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 >::ConstBwdPairPtrIterator() {};
    
#line 177
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 >::ConstBwdPairPtrIterator(const ConstBwdPairPtrIterator& it)
    {
#line 177
        *this = it;
    };
    
#line 191
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 >::ConstBwdPairPtrIterator(const _1 *kit, const _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 188
    template < class _1, class _2 >
    inline bool ConstBwdPairPtrIterator < _1, _2 >::operator!= (const ConstBwdPairPtrIterator& it) const
    {
#line 188
        return it.kit != kit;
    };
    
#line 179
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 > & ConstBwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 179
        kit += -1;
#line 179
        vit += -1;
#line 179
        return *this;
    };
    
#line 181
    template < class _1, class _2 >
    inline void ConstBwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 181
        kit += i;
#line 181
        vit += i;
    };
    
#line 180
    template < class _1, class _2 >
    inline void ConstBwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 180
        kit -= -1;
#line 180
        vit -= -1;
    };
    
#line 178
    template < class _1, class _2 >
    inline void ConstBwdPairPtrIterator < _1, _2 >::operator= (const ConstBwdPairPtrIterator& it)
    {
#line 178
        kit = it.kit;
#line 178
        vit = it.vit;
    };
    
#line 187
    template < class _1, class _2 >
    inline const _1& ConstBwdPairPtrIterator < _1, _2 >::Key() const
    {
#line 187
        return *kit;
    };
    
#line 192
    template < class _1, class _2 >
    inline const _2& ConstBwdPairPtrIterator < _1, _2 >::Value() const
    {
#line 192
        return *vit;
    };
    
#line 122
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator() {};
    
#line 123
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator(const ConstBwdPtrIterator& it)
    {
#line 123
        *this = it;
    };
    
#line 133
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator(const _1 **kit)
    :
        kit(kit)
    {};
    
#line 144
    template < class _1 >
    inline bool ConstBwdPtrIterator < _1 >::operator!= (const ConstBwdPtrIterator& it) const
    {
#line 144
        return it.kit != kit;
    };
    
#line 143
    template < class _1 >
    inline const _1& ConstBwdPtrIterator < _1 >::operator()() const
    {
#line 143
        return *Get();
    };
    
#line 142
    template < class _1 >
    inline const _1& ConstBwdPtrIterator < _1 >::operator*() const
    {
#line 142
        return *Get();
    };
    
#line 125
    template < class _1 >
    inline ConstBwdPtrIterator < _1 > & ConstBwdPtrIterator < _1 >::operator++ ()
    {
#line 125
        kit += -1;
#line 125
        return *this;
    };
    
#line 127
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator+= (int i)
    {
#line 127
        kit += i;
    };
    
#line 126
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator-- (int i)
    {
#line 126
        kit -= -1;
    };
    
#line 140
    template < class _1 >
    inline const _1 *ConstBwdPtrIterator < _1 >::operator-> () const
    {
#line 140
        return Get();
    };
    
#line 124
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator= (const ConstBwdPtrIterator& it)
    {
#line 124
        kit = it.kit;
    };
    
#line 141
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::operator ConstK * () const
    {
#line 141
        return Get();
    };
    
#line 134
    template < class _1 >
    inline const _1 *ConstBwdPtrIterator < _1 >::Get() const
    {
#line 134
        return *kit;
    };
    
#line 122
    template < class _1 >
    inline ConstFwdIterator < _1 >::ConstFwdIterator() {};
    
#line 123
    template < class _1 >
    inline ConstFwdIterator < _1 >::ConstFwdIterator(const ConstFwdIterator& it)
    {
#line 123
        *this = it;
    };
    
#line 137
    template < class _1 >
    inline ConstFwdIterator < _1 >::ConstFwdIterator(const _1 *kit)
    :
        kit(kit)
    {};
    
#line 144
    template < class _1 >
    inline bool ConstFwdIterator < _1 >::operator!= (const ConstFwdIterator& it) const
    {
#line 144
        return it.kit != kit;
    };
    
#line 143
    template < class _1 >
    inline const _1& ConstFwdIterator < _1 >::operator()() const
    {
#line 143
        return *Get();
    };
    
#line 142
    template < class _1 >
    inline const _1& ConstFwdIterator < _1 >::operator*() const
    {
#line 142
        return *Get();
    };
    
#line 125
    template < class _1 >
    inline ConstFwdIterator < _1 > & ConstFwdIterator < _1 >::operator++ ()
    {
#line 125
        kit += 1;
#line 125
        return *this;
    };
    
#line 127
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator+= (int i)
    {
#line 127
        kit += i;
    };
    
#line 126
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator-- (int i)
    {
#line 126
        kit -= 1;
    };
    
#line 140
    template < class _1 >
    inline const _1 *ConstFwdIterator < _1 >::operator-> () const
    {
#line 140
        return Get();
    };
    
#line 124
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator= (const ConstFwdIterator& it)
    {
#line 124
        kit = it.kit;
    };
    
#line 141
    template < class _1 >
    inline ConstFwdIterator < _1 >::operator ConstK * () const
    {
#line 141
        return Get();
    };
    
#line 138
    template < class _1 >
    inline const _1 *ConstFwdIterator < _1 >::Get() const
    {
#line 138
        return kit;
    };
    
#line 176
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 >::ConstFwdPairIterator() {};
    
#line 177
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 >::ConstFwdPairIterator(const ConstFwdPairIterator& it)
    {
#line 177
        *this = it;
    };
    
#line 196
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 >::ConstFwdPairIterator(const _1 *kit, const _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 188
    template < class _1, class _2 >
    inline bool ConstFwdPairIterator < _1, _2 >::operator!= (const ConstFwdPairIterator& it) const
    {
#line 188
        return it.kit != kit;
    };
    
#line 179
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 > & ConstFwdPairIterator < _1, _2 >::operator++ ()
    {
#line 179
        kit += 1;
#line 179
        vit += 1;
#line 179
        return *this;
    };
    
#line 181
    template < class _1, class _2 >
    inline void ConstFwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 181
        kit += i;
#line 181
        vit += i;
    };
    
#line 180
    template < class _1, class _2 >
    inline void ConstFwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 180
        kit -= 1;
#line 180
        vit -= 1;
    };
    
#line 178
    template < class _1, class _2 >
    inline void ConstFwdPairIterator < _1, _2 >::operator= (const ConstFwdPairIterator& it)
    {
#line 178
        kit = it.kit;
#line 178
        vit = it.vit;
    };
    
#line 187
    template < class _1, class _2 >
    inline const _1& ConstFwdPairIterator < _1, _2 >::Key() const
    {
#line 187
        return *kit;
    };
    
#line 197
    template < class _1, class _2 >
    inline const _2& ConstFwdPairIterator < _1, _2 >::Value() const
    {
#line 197
        return **vit;
    };
    
#line 176
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 >::ConstFwdPairPtrIterator() {};
    
#line 177
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 >::ConstFwdPairPtrIterator(const ConstFwdPairPtrIterator& it)
    {
#line 177
        *this = it;
    };
    
#line 191
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 >::ConstFwdPairPtrIterator(const _1 *kit, const _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 188
    template < class _1, class _2 >
    inline bool ConstFwdPairPtrIterator < _1, _2 >::operator!= (const ConstFwdPairPtrIterator& it) const
    {
#line 188
        return it.kit != kit;
    };
    
#line 179
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 > & ConstFwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 179
        kit += 1;
#line 179
        vit += 1;
#line 179
        return *this;
    };
    
#line 181
    template < class _1, class _2 >
    inline void ConstFwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 181
        kit += i;
#line 181
        vit += i;
    };
    
#line 180
    template < class _1, class _2 >
    inline void ConstFwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 180
        kit -= 1;
#line 180
        vit -= 1;
    };
    
#line 178
    template < class _1, class _2 >
    inline void ConstFwdPairPtrIterator < _1, _2 >::operator= (const ConstFwdPairPtrIterator& it)
    {
#line 178
        kit = it.kit;
#line 178
        vit = it.vit;
    };
    
#line 187
    template < class _1, class _2 >
    inline const _1& ConstFwdPairPtrIterator < _1, _2 >::Key() const
    {
#line 187
        return *kit;
    };
    
#line 192
    template < class _1, class _2 >
    inline const _2& ConstFwdPairPtrIterator < _1, _2 >::Value() const
    {
#line 192
        return *vit;
    };
    
#line 122
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator() {};
    
#line 123
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator(const ConstFwdPtrIterator& it)
    {
#line 123
        *this = it;
    };
    
#line 133
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator(const _1 **kit)
    :
        kit(kit)
    {};
    
#line 144
    template < class _1 >
    inline bool ConstFwdPtrIterator < _1 >::operator!= (const ConstFwdPtrIterator& it) const
    {
#line 144
        return it.kit != kit;
    };
    
#line 143
    template < class _1 >
    inline const _1& ConstFwdPtrIterator < _1 >::operator()() const
    {
#line 143
        return *Get();
    };
    
#line 142
    template < class _1 >
    inline const _1& ConstFwdPtrIterator < _1 >::operator*() const
    {
#line 142
        return *Get();
    };
    
#line 125
    template < class _1 >
    inline ConstFwdPtrIterator < _1 > & ConstFwdPtrIterator < _1 >::operator++ ()
    {
#line 125
        kit += 1;
#line 125
        return *this;
    };
    
#line 127
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator+= (int i)
    {
#line 127
        kit += i;
    };
    
#line 126
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator-- (int i)
    {
#line 126
        kit -= 1;
    };
    
#line 140
    template < class _1 >
    inline const _1 *ConstFwdPtrIterator < _1 >::operator-> () const
    {
#line 140
        return Get();
    };
    
#line 124
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator= (const ConstFwdPtrIterator& it)
    {
#line 124
        kit = it.kit;
    };
    
#line 141
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::operator ConstK * () const
    {
#line 141
        return Get();
    };
    
#line 134
    template < class _1 >
    inline const _1 *ConstFwdPtrIterator < _1 >::Get() const
    {
#line 134
        return *kit;
    };
    
#line 259
    template < class _1 >
    inline DynArray < _1 >::DynArray()
    :
        data(0),
        reserved(0),
        count(0)
    {};
    
#line 260
    template < class _1 >
    inline DynArray < _1 >::DynArray(const DynArray& v)
    :
        data(0),
        reserved(0),
        count(0)
    {
#line 260
        *this <<= v;
    };
    
#line 261
    template < class _1 >
    inline DynArray < _1 >::DynArray(int i)
    :
        data(0),
        reserved(0),
        count(0)
    {
#line 261
        SetCount(i);
    };
    
#line 262
    template < class _1 >
    inline DynArray < _1 >::~DynArray()
    {
#line 263
        Clear();
        return;
        ;
    };
    
#line 315
    template < class _1 >
    inline DynArray < _1 > & DynArray < _1 >::operator<< (const _1& v)
    {
#line 315
        Add(v);
#line 315
        return *this;
    };
    
#line 348
    template < class _1 >
    inline void DynArray < _1 >::operator<<= (const DynArray& a)
    {
#line 349
        SetCount(0);
        Reserve(a.GetCount());
        for (int i = 0; i < a.GetCount(); i ++ )
            new (&data[i])_1(a[i]);
        count = a.GetCount();
    };
    
#line 380
    template < class _1 >
    inline _1& DynArray < _1 >::operator[](int i)
    {
        {
#line 381
            if (!(i >= 0 && i < count))
            {
#line 381
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 382
        ;
#line 382
        return *(data + i);
    };
    
#line 384
    template < class _1 >
    inline const _1& DynArray < _1 >::operator[](int i) const
    {
        {
#line 385
            if (!(i >= 0 && i < count))
            {
#line 385
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 386
        ;
#line 386
        return *(data + i);
    };
    
#line 293
    template < class _1 >
    inline _1& DynArray < _1 >::Add()
    {
#line 294
        if (count + 1 > reserved)
#line 294
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        new (&data[count])_1;
        return data[count ++ ];
    };
    
#line 300
    template < class _1 >
    inline _1& DynArray < _1 >::Add(const _1& v)
    {
#line 301
        if (count + 1 > reserved)
#line 301
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        _1 * ptr = &data[count];
        new (ptr)_1(v);
        return data[count ++ ];
    };
    
#line 355
    template < class _1 >
    inline void DynArray < _1 >::Append(const DynArray& a)
    {
#line 356
        int begin = count;
        int new_count = count + a.GetCount();
        Reserve(new_count);
        for (int i = begin, j = 0; i < new_count; i ++ , j ++ )
            new (&data[i])_1(a[j]);
        count = new_count;
    };
    
#line 275
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::Begin() const
    {
#line 275
        return ConstIterator(data);
    };
    
#line 273
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::Begin()
    {
#line 273
        return Iterator(data);
    };
    
#line 482
    template < class _1 >
    inline void DynArray < _1 >::Clear()
    {
#line 483
        if (!reserved)
#line 483
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
    
#line 276
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::End() const
    {
#line 276
        return ConstIterator(data + count);
    };
    
#line 274
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::End()
    {
#line 274
        return Iterator(data + count);
    };
    
#line 290
    template < class _1 >
    inline _1 *DynArray < _1 >::Get() const
    {
#line 290
        return data;
    };
    
#line 376
    template < class _1 >
    inline int DynArray < _1 >::GetCount() const
    {
#line 376
        return count;
    };
    
#line 291
    template < class _1 >
    inline _1 *DynArray < _1 >::GetEnd() const
    {
#line 291
        return data + count;
    };
    
#line 377
    template < class _1 >
    inline int DynArray < _1 >::GetReserved() const
    {
#line 377
        return reserved;
    };
    
#line 363
    template < class _1 >
    inline void DynArray < _1 >::IncreaseReserve(int more_reserved)
    {
#line 363
        Reserve(GetCount() + more_reserved);
    };
    
#line 238
    template < class _1 >
    inline void DynArray < _1 >::IncreaseReserved()
    {
#line 239
        uint64 new_reserved = 1;
        while (new_reserved <= reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2000000000)
            new_reserved = 2000000000;
        Reserve((int) new_reserved);
    };
    
#line 443
    template < class _1 >
    inline _1& DynArray < _1 >::Insert(int i)
    {
#line 444
        if (count + 1 > reserved)
#line 444
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
    
#line 454
    template < class _1 >
    inline _1& DynArray < _1 >::Insert(int i, ConstK& key)
    {
#line 455
        if (count + 1 > reserved)
#line 455
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
    
#line 378
    template < class _1 >
    inline bool DynArray < _1 >::IsEmpty() const
    {
#line 378
        return GetCount() == 0;
    };
    
#line 247
    template < class _1 >
    inline void DynArray < _1 >::Pick0(DynArray& v)
    {
#line 247
        data = v.data;
#line 247
        v.data = 0;
#line 247
        reserved = v.reserved;
#line 247
        v.reserved = 0;
#line 247
        count = v.count;
#line 247
        v.count = 0;
    };
    
#line 468
    template < class _1 >
    inline _1 DynArray < _1 >::Pop()
    {
        {
#line 469
            if (!(GetCount() > 0))
            {
#line 469
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 470
        ;
#line 470
        int i = count - 1;
        _1 ret(data[i]);
        data[i].~K();
        count -- ;
        return ret;
    };
    
#line 281
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::RBegin()
    {
#line 281
        return RIterator(data + count - 1);
    };
    
#line 283
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::RBegin() const
    {
#line 283
        return ConstRIterator(data + count - 1);
    };
    
#line 282
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::REnd()
    {
#line 282
        return RIterator(data - 1);
    };
    
#line 284
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::REnd() const
    {
#line 284
        return ConstRIterator(data - 1);
    };
    
#line 422
    template < class _1 >
    inline void DynArray < _1 >::Remove(const DynArray < int > & sorted_list)
    {
#line 422
        Remove(sorted_list.Begin(), sorted_list.GetCount());
    };
    
#line 404
    template < class _1 >
    inline void DynArray < _1 >::Remove(const Iterator& it)
    {
#line 405
        _1 * begin = data;
        _1 * cur = it.Get();
        int pos = cur - begin;
        Remove(pos);
    };
    
    template < class _1 >
    inline void DynArray < _1 >::Remove(const Iterator& it, const Iterator& end)
    {
#line 412
        _1 * begin = data;
        _1 * cur = it.Get();
        _1 * cur_end = end.Get();
        int pos0 = cur - begin;
        int pos1 = cur_end - begin;
        int len = pos1 - pos0;
        if (!len)
#line 418
            return;
        Remove(pos0, len);
    };
    
#line 423
    template < class _1 >
    inline void DynArray < _1 >::Remove(const int *sorted_list, int n)
    {
#line 424
        if (!n)
#line 424
            return;
        int pos = *sorted_list;
        int npos = pos;
        for (;;)
            {
                {
#line 428
                    if (!(pos < count))
                    {
#line 428
                        Lang::SysBreak("Assertion failed: pos < count");
                    }
                }
#line 429
                ;
#line 429
                if (pos == *sorted_list)
                {
#line 430
                    (data + pos)-> ~K();
                    pos ++ ;
                    sorted_list ++ ;
                    if (-- n == 0)
#line 433
                        break;
                    
                    {
#line 434
                        if (!(*sorted_list >= pos))
                        {
#line 434
                            Lang::SysBreak("Assertion failed: *sorted_list >= pos");
                        }
                    }
#line 435
                    ;
                }
                else
#line 437
                    Memory::Copy(data + npos ++ , data + pos ++ , sizeof (_1));
            }
        while (pos < count)
            Memory::Copy(data + npos ++ , data + pos ++ , sizeof (_1));
        count = npos;
    };
    
#line 389
    template < class _1 >
    inline void DynArray < _1 >::Remove(int i)
    {
        {
#line 390
            if (!(i >= 0 && i < count))
            {
#line 390
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 391
        ;
#line 391
        int tail = count - (i + 1);
        if (tail > 0)
            Memory::Move(data + i, data + i + 1, tail * sizeof (_1));
        count -- ;
    };
    
#line 396
    template < class _1 >
    inline void DynArray < _1 >::Remove(int i, int count)
    {
        {
#line 397
            if (!(count > 0))
            {
#line 397
                Lang::SysBreak("Assertion failed: count > 0");
            }
        }
#line 398
        ;
        {
#line 398
            if (!(i >= 0 && i + count <= this -> count))
            {
#line 398
                Lang::SysBreak("Assertion failed: i >= 0 && i + count <= this->count");
            }
        }
#line 399
        ;
#line 399
        int tail = this -> count - (i + count);
        if (tail > 0)
            Memory::Move(data + i, data + i + count, tail * sizeof (_1));
        this -> count -= count;
    };
    
#line 477
    template < class _1 >
    inline void DynArray < _1 >::RemoveLast()
    {
        {
#line 478
            if (!(GetCount() > 0))
            {
#line 478
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 479
        ;
#line 479
        data[-- count].~K();
    };
    
#line 364
    template < class _1 >
    inline void DynArray < _1 >::Reserve(int new_reserved)
    {
#line 365
        if (new_reserved <= reserved || new_reserved <= 0)
            return;
        _1 * new_data = (_1 * ) Memory::Alloc(new_reserved * sizeof (_1));
        if (data)
        {
#line 369
            if (count > 0)
                Memory::Copy((void * ) new_data, (void * ) data, sizeof (_1) * count);
            Memory::Free(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
#line 317
    template < class _1 >
    inline void DynArray < _1 >::SetCount(int new_count)
    {
        {
#line 318
            if (!(new_count >= 0))
            {
#line 318
                Lang::SysBreak("Assertion failed: new_count >= 0");
            }
        }
#line 319
        ;
#line 319
        if (new_count < 0)
#line 319
            return;
        if (new_count > reserved)
#line 320
            Reserve(new_count);
        if (new_count == count)
#line 321
            return;
        if (new_count > count)
        {
#line 323
            for (int i = count; i < new_count; i ++ )
                new (&data[i])_1;
        }
        else
        {
#line 327
            for (int i = count - 1; i >= new_count; i -- )
                Destruct(data[i]);
        }
#line 331
        count = new_count;
    };
    
#line 333
    template < class _1 >
    inline void DynArray < _1 >::SetCount(int new_count, ConstK& value)
    {
        {
#line 334
            if (!(new_count >= 0))
            {
#line 334
                Lang::SysBreak("Assertion failed: new_count >= 0");
            }
        }
#line 335
        ;
#line 335
        if (new_count < 0)
#line 335
            return;
        if (new_count > reserved)
#line 336
            Reserve(new_count);
        if (new_count == count)
#line 337
            return;
        if (new_count > count)
        {
#line 339
            for (int i = count; i < new_count; i ++ )
                new (&data[i])_1(value);
        }
        else
        {
#line 343
            for (int i = count - 1; i >= new_count; i -- )
                Destruct(data[i]);
        }
        count = new_count;
    };
    
#line 466
    template < class _1 >
    inline _1& DynArray < _1 >::Top()
    {
        {
#line 466
            if (!(GetCount() > 0))
            {
#line 466
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 466
        ;
#line 466
        return data[count - 1];
    };
    
#line 279
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::begin() const
    {
#line 279
        return Begin();
    };
    
#line 277
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::begin()
    {
#line 277
        return Begin();
    };
    
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::end() const
    {
#line 280
        return End();
    };
    
#line 278
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::end()
    {
#line 278
        return End();
    };
    
#line 285
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::rbegin()
    {
#line 285
        return RBegin();
    };
    
#line 287
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::rbegin() const
    {
#line 287
        return RBegin();
    };
    
#line 286
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::rend()
    {
#line 286
        return REnd();
    };
    
#line 288
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::rend() const
    {
#line 288
        return REnd();
    };
    
#line 122
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator() {};
    
#line 152
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator(_1 *kit)
    :
        kit(kit)
    {};
    
#line 123
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator(const FwdIterator& it)
    {
#line 123
        *this = it;
    };
    
#line 159
    template < class _1 >
    inline bool FwdIterator < _1 >::operator!= (const FwdIterator& it) const
    {
#line 159
        return it.kit != kit;
    };
    
#line 158
    template < class _1 >
    inline _1& FwdIterator < _1 >::operator()() const
    {
#line 158
        return *Get();
    };
    
#line 157
    template < class _1 >
    inline _1& FwdIterator < _1 >::operator*() const
    {
#line 157
        return *Get();
    };
    
#line 125
    template < class _1 >
    inline FwdIterator < _1 > & FwdIterator < _1 >::operator++ ()
    {
#line 125
        kit += 1;
#line 125
        return *this;
    };
    
#line 127
    template < class _1 >
    inline void FwdIterator < _1 >::operator+= (int i)
    {
#line 127
        kit += i;
    };
    
#line 126
    template < class _1 >
    inline void FwdIterator < _1 >::operator-- (int i)
    {
#line 126
        kit -= 1;
    };
    
#line 155
    template < class _1 >
    inline _1 *FwdIterator < _1 >::operator-> () const
    {
#line 155
        return Get();
    };
    
#line 124
    template < class _1 >
    inline void FwdIterator < _1 >::operator= (const FwdIterator& it)
    {
#line 124
        kit = it.kit;
    };
    
#line 156
    template < class _1 >
    inline FwdIterator < _1 >::operator _1 * () const
    {
#line 156
        return Get();
    };
    
#line 153
    template < class _1 >
    inline _1 *FwdIterator < _1 >::Get() const
    {
#line 153
        return kit;
    };
    
#line 176
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 >::FwdPairIterator() {};
    
#line 177
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 >::FwdPairIterator(const FwdPairIterator& it)
    {
#line 177
        *this = it;
    };
    
#line 211
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 >::FwdPairIterator(const _1 *kit, _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 203
    template < class _1, class _2 >
    inline bool FwdPairIterator < _1, _2 >::operator!= (const FwdPairIterator& it) const
    {
#line 203
        return it.kit != kit;
    };
    
#line 179
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 > & FwdPairIterator < _1, _2 >::operator++ ()
    {
#line 179
        kit += 1;
#line 179
        vit += 1;
#line 179
        return *this;
    };
    
#line 181
    template < class _1, class _2 >
    inline void FwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 181
        kit += i;
#line 181
        vit += i;
    };
    
#line 180
    template < class _1, class _2 >
    inline void FwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 180
        kit -= 1;
#line 180
        vit -= 1;
    };
    
#line 178
    template < class _1, class _2 >
    inline void FwdPairIterator < _1, _2 >::operator= (const FwdPairIterator& it)
    {
#line 178
        kit = it.kit;
#line 178
        vit = it.vit;
    };
    
#line 202
    template < class _1, class _2 >
    inline const _1& FwdPairIterator < _1, _2 >::Key() const
    {
#line 202
        return *kit;
    };
    
#line 212
    template < class _1, class _2 >
    inline _2& FwdPairIterator < _1, _2 >::Value() const
    {
#line 212
        return *vit;
    };
    
#line 176
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 >::FwdPairPtrIterator() {};
    
#line 177
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 >::FwdPairPtrIterator(const FwdPairPtrIterator& it)
    {
#line 177
        *this = it;
    };
    
#line 206
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 >::FwdPairPtrIterator(const _1 *kit, _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 203
    template < class _1, class _2 >
    inline bool FwdPairPtrIterator < _1, _2 >::operator!= (const FwdPairPtrIterator& it) const
    {
#line 203
        return it.kit != kit;
    };
    
#line 179
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 > & FwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 179
        kit += 1;
#line 179
        vit += 1;
#line 179
        return *this;
    };
    
#line 181
    template < class _1, class _2 >
    inline void FwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 181
        kit += i;
#line 181
        vit += i;
    };
    
#line 180
    template < class _1, class _2 >
    inline void FwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 180
        kit -= 1;
#line 180
        vit -= 1;
    };
    
#line 178
    template < class _1, class _2 >
    inline void FwdPairPtrIterator < _1, _2 >::operator= (const FwdPairPtrIterator& it)
    {
#line 178
        kit = it.kit;
#line 178
        vit = it.vit;
    };
    
#line 202
    template < class _1, class _2 >
    inline const _1& FwdPairPtrIterator < _1, _2 >::Key() const
    {
#line 202
        return *kit;
    };
    
#line 207
    template < class _1, class _2 >
    inline _2& FwdPairPtrIterator < _1, _2 >::Value() const
    {
#line 207
        return **vit;
    };
    
#line 122
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator() {};
    
#line 148
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator(_1 **kit)
    :
        kit(kit)
    {};
    
#line 123
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator(const FwdPtrIterator& it)
    {
#line 123
        *this = it;
    };
    
#line 159
    template < class _1 >
    inline bool FwdPtrIterator < _1 >::operator!= (const FwdPtrIterator& it) const
    {
#line 159
        return it.kit != kit;
    };
    
#line 158
    template < class _1 >
    inline _1& FwdPtrIterator < _1 >::operator()() const
    {
#line 158
        return *Get();
    };
    
#line 157
    template < class _1 >
    inline _1& FwdPtrIterator < _1 >::operator*() const
    {
#line 157
        return *Get();
    };
    
#line 125
    template < class _1 >
    inline FwdPtrIterator < _1 > & FwdPtrIterator < _1 >::operator++ ()
    {
#line 125
        kit += 1;
#line 125
        return *this;
    };
    
#line 127
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator+= (int i)
    {
#line 127
        kit += i;
    };
    
#line 126
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator-- (int i)
    {
#line 126
        kit -= 1;
    };
    
#line 155
    template < class _1 >
    inline _1 *FwdPtrIterator < _1 >::operator-> () const
    {
#line 155
        return Get();
    };
    
#line 124
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator= (const FwdPtrIterator& it)
    {
#line 124
        kit = it.kit;
    };
    
#line 156
    template < class _1 >
    inline FwdPtrIterator < _1 >::operator _1 * () const
    {
#line 156
        return Get();
    };
    
#line 149
    template < class _1 >
    inline _1 *FwdPtrIterator < _1 >::Get() const
    {
#line 149
        return *kit;
    };
    
#line 111
    inline MemoryLimitExc::MemoryLimitExc()
    :
        msg(0)
    {};
    
#line 112
    inline MemoryLimitExc::MemoryLimitExc(const char *s)
    :
        msg(s)
    {};
    
};

#endif
