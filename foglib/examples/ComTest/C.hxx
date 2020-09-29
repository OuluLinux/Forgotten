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

#ifndef C_HXX
#define C_HXX

#include <new>

namespace C
{
};

namespace C
{
#line 28 "../../src/Com/Lang.fog"
    typedef unsigned char Byte;
    
#line 29
    extern Byte ____unused_Byte;
};

namespace C
{
#line 28
    typedef unsigned long DWORD;
    
#line 29
    extern DWORD ____unused_DWORD;
};

namespace C
{
#line 28
    typedef unsigned char byte;
    
#line 29
    extern byte ____unused_byte;
};

namespace C
{
#line 28
    typedef unsigned int uint32;
#line 28
    typedef uint32 dword;
    
#line 29
    extern dword ____unused_dword;
};

namespace C
{
#line 28
    typedef short int16;
    
#line 29
    extern int16 ____unused_int16;
};

namespace C
{
#line 28
    typedef int int32;
    
#line 29
    extern int32 ____unused_int32;
};

namespace C
{
#line 28
    typedef long long int64;
    
#line 29
    extern int64 ____unused_int64;
};

namespace C
{
#line 28
    typedef char int8;
    
#line 29
    extern int8 ____unused_int8;
};

namespace C
{
#line 28
    typedef unsigned long long uint64;
#line 28
    typedef uint64 qword;
    
#line 29
    extern qword ____unused_qword;
};

namespace C
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

namespace C
{
#line 28
    typedef unsigned char uint8;
    
#line 29
    extern uint8 ____unused_uint8;
};

namespace C
{
#line 28
    typedef uint16 word;
    
#line 29
    extern word ____unused_word;
    
#line 91
    inline void Destruct(int16& o);
#line 93
    inline void Destruct(int32& o);
#line 95
    inline void Destruct(int64& o);
#line 89
    inline void Destruct(int8& o);
    inline void Destruct(uint16& o);
#line 92
    inline void Destruct(uint32& o);
#line 94
    inline void Destruct(uint64& o);
#line 88
    inline void Destruct(uint8& o);
#line 87
    template < class _1 >
    inline void Destruct(_1& o);
#line 97
    inline void Destruct(double& o);
#line 96
    inline void Destruct(float& o);
#line 98
    inline void Destruct(void *o);
#line 113
    int StringLength(const char *c, int max_len = 100000000);
    int StringLength(const short *c, int max_len = 100000000);
#line 111
    void SysBreak(const char *msg);
    
    struct AtomicBool
    {
#line 129
        AtomicBool();
        AtomicBool(bool b);
        AtomicBool(const AtomicBool& ai);
#line 133
        bool operator= (bool b);
#line 132
        operator bool();
    };
    
    struct AtomicFlag
    {
#line 119
        void Enter();
        void Leave();
        bool TryEnter();
    };
    
    struct AtomicInt
    {
#line 139
        AtomicInt();
#line 141
        AtomicInt(const AtomicInt& ai);
#line 140
        AtomicInt(int i);
#line 144
        int operator++ ();
#line 146
        int operator++ (int);
#line 145
        int operator-- ();
#line 147
        int operator-- (int);
#line 143
        int operator= (int i);
#line 142
        operator int() const;
    };
    
    template < class _1 >
    class BwdIterator
    {
#line 209
        _1 *kit;
        
    public:
#line 180
        inline BwdIterator();
#line 210
        inline BwdIterator(_1 *kit);
#line 181
        inline BwdIterator(const BwdIterator& it);
#line 217
        inline bool operator!= (const BwdIterator& it) const;
#line 216
        inline _1& operator()() const;
#line 215
        inline _1& operator*() const;
#line 183
        inline BwdIterator < _1 > & operator++ ();
#line 185
        inline void operator+= (int i);
#line 184
        inline void operator-- (int i);
#line 213
        inline _1 *operator-> () const;
#line 182
        inline void operator= (const BwdIterator& it);
#line 214
        inline operator _1 * () const;
#line 211
        inline _1 *Get() const;
    };
    
    template < class _1, class _2 >
    class BwdPairIterator
    {
#line 259
        const _1 *kit;
#line 268
        _2 *vit;
        
    public:
#line 234
        inline BwdPairIterator();
        inline BwdPairIterator(const BwdPairIterator& it);
#line 269
        inline BwdPairIterator(const _1 *kit, _2 *vit);
#line 261
        inline bool operator!= (const BwdPairIterator& it) const;
#line 237
        inline BwdPairIterator < _1, _2 > & operator++ ();
#line 239
        inline void operator+= (int i);
#line 238
        inline void operator-- (int i);
#line 236
        inline void operator= (const BwdPairIterator& it);
#line 270
        inline _2& Value() const;
        
#line 260
        inline const _1& Key() const;
    };
    
    template < class _1, class _2 >
    class BwdPairPtrIterator
    {
#line 259
        const _1 *kit;
#line 263
        _2 **vit;
        
    public:
#line 234
        inline BwdPairPtrIterator();
        inline BwdPairPtrIterator(const BwdPairPtrIterator& it);
#line 264
        inline BwdPairPtrIterator(const _1 *kit, _2 **vit);
#line 261
        inline bool operator!= (const BwdPairPtrIterator& it) const;
#line 237
        inline BwdPairPtrIterator < _1, _2 > & operator++ ();
#line 239
        inline void operator+= (int i);
#line 238
        inline void operator-- (int i);
#line 236
        inline void operator= (const BwdPairPtrIterator& it);
#line 265
        inline _2& Value() const;
        
#line 260
        inline const _1& Key() const;
    };
    
    template < class _1 >
    class BwdPtrIterator
    {
#line 205
        _1 **kit;
        
    public:
#line 180
        inline BwdPtrIterator();
#line 206
        inline BwdPtrIterator(_1 **kit);
#line 181
        inline BwdPtrIterator(const BwdPtrIterator& it);
#line 217
        inline bool operator!= (const BwdPtrIterator& it) const;
#line 216
        inline _1& operator()() const;
#line 215
        inline _1& operator*() const;
#line 183
        inline BwdPtrIterator < _1 > & operator++ ();
#line 185
        inline void operator+= (int i);
#line 184
        inline void operator-- (int i);
#line 213
        inline _1 *operator-> () const;
#line 182
        inline void operator= (const BwdPtrIterator& it);
#line 214
        inline operator _1 * () const;
#line 207
        inline _1 *Get() const;
    };
    
    template < class _1 >
    struct CPtr
    {
#line 56
        _1 *value;
        
        inline CPtr();
        inline CPtr(_1 *p);
        inline void operator= (_1 *p);
#line 62
        inline bool operator== (const CPtr& p) const;
        inline bool operator== (void *p) const;
#line 61
        inline operator _1 * () const;
#line 66
        inline unsigned long long Int() const;
    };
    
    struct ConditionalVar
    {
#line 152
        ConditionalVar();
#line 155
        bool IsReady() const;
#line 154
        void SetReady(bool b = true);
#line 153
        void Wait();
    };
    
    template < class _1 >
    class ConstBwdIterator
    {
    public:
#line 188
        typedef const _1 ConstK;
        
#line 194
        const _1 *kit;
        
    public:
#line 180
        inline ConstBwdIterator();
        inline ConstBwdIterator(const ConstBwdIterator& it);
#line 195
        inline ConstBwdIterator(const _1 *kit);
#line 202
        inline bool operator!= (const ConstBwdIterator& it) const;
#line 201
        inline const _1& operator()() const;
#line 200
        inline const _1& operator*() const;
#line 183
        inline ConstBwdIterator < _1 > & operator++ ();
#line 185
        inline void operator+= (int i);
#line 184
        inline void operator-- (int i);
#line 198
        inline const _1 *operator-> () const;
#line 182
        inline void operator= (const ConstBwdIterator& it);
#line 199
        inline operator ConstK * () const;
#line 196
        inline const _1 *Get() const;
    };
    
    template < class _1, class _2 >
    class ConstBwdPairIterator
    {
#line 242
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 244
        const _1 *kit;
#line 253
        const _2 **vit;
        
    public:
#line 234
        inline ConstBwdPairIterator();
        inline ConstBwdPairIterator(const ConstBwdPairIterator& it);
#line 254
        inline ConstBwdPairIterator(const _1 *kit, const _2 **vit);
#line 246
        inline bool operator!= (const ConstBwdPairIterator& it) const;
#line 237
        inline ConstBwdPairIterator < _1, _2 > & operator++ ();
#line 239
        inline void operator+= (int i);
#line 238
        inline void operator-- (int i);
#line 236
        inline void operator= (const ConstBwdPairIterator& it);
#line 245
        inline const _1& Key() const;
#line 255
        inline const _2& Value() const;
    };
    
    template < class _1, class _2 >
    class ConstBwdPairPtrIterator
    {
#line 242
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 244
        const _1 *kit;
#line 248
        const _2 *vit;
        
    public:
#line 234
        inline ConstBwdPairPtrIterator();
        inline ConstBwdPairPtrIterator(const ConstBwdPairPtrIterator& it);
#line 249
        inline ConstBwdPairPtrIterator(const _1 *kit, const _2 *vit);
#line 246
        inline bool operator!= (const ConstBwdPairPtrIterator& it) const;
#line 237
        inline ConstBwdPairPtrIterator < _1, _2 > & operator++ ();
#line 239
        inline void operator+= (int i);
#line 238
        inline void operator-- (int i);
#line 236
        inline void operator= (const ConstBwdPairPtrIterator& it);
#line 245
        inline const _1& Key() const;
#line 250
        inline const _2& Value() const;
    };
    
    template < class _1 >
    class ConstBwdPtrIterator
    {
    public:
#line 188
        typedef const _1 ConstK;
        
        const _1 **kit;
        
    public:
#line 180
        inline ConstBwdPtrIterator();
        inline ConstBwdPtrIterator(const ConstBwdPtrIterator& it);
#line 191
        inline ConstBwdPtrIterator(const _1 **kit);
#line 202
        inline bool operator!= (const ConstBwdPtrIterator& it) const;
#line 201
        inline const _1& operator()() const;
#line 200
        inline const _1& operator*() const;
#line 183
        inline ConstBwdPtrIterator < _1 > & operator++ ();
#line 185
        inline void operator+= (int i);
#line 184
        inline void operator-- (int i);
#line 198
        inline const _1 *operator-> () const;
#line 182
        inline void operator= (const ConstBwdPtrIterator& it);
#line 199
        inline operator ConstK * () const;
#line 192
        inline const _1 *Get() const;
    };
    
    template < class _1 >
    class ConstFwdIterator
    {
    public:
#line 188
        typedef const _1 ConstK;
        
#line 194
        const _1 *kit;
        
    public:
#line 180
        inline ConstFwdIterator();
        inline ConstFwdIterator(const ConstFwdIterator& it);
#line 195
        inline ConstFwdIterator(const _1 *kit);
#line 202
        inline bool operator!= (const ConstFwdIterator& it) const;
#line 201
        inline const _1& operator()() const;
#line 200
        inline const _1& operator*() const;
#line 183
        inline ConstFwdIterator < _1 > & operator++ ();
#line 185
        inline void operator+= (int i);
#line 184
        inline void operator-- (int i);
#line 198
        inline const _1 *operator-> () const;
#line 182
        inline void operator= (const ConstFwdIterator& it);
#line 199
        inline operator ConstK * () const;
#line 196
        inline const _1 *Get() const;
    };
    
    template < class _1, class _2 >
    class ConstFwdPairIterator
    {
#line 242
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 244
        const _1 *kit;
#line 253
        const _2 **vit;
        
    public:
#line 234
        inline ConstFwdPairIterator();
        inline ConstFwdPairIterator(const ConstFwdPairIterator& it);
#line 254
        inline ConstFwdPairIterator(const _1 *kit, const _2 **vit);
#line 246
        inline bool operator!= (const ConstFwdPairIterator& it) const;
#line 237
        inline ConstFwdPairIterator < _1, _2 > & operator++ ();
#line 239
        inline void operator+= (int i);
#line 238
        inline void operator-- (int i);
#line 236
        inline void operator= (const ConstFwdPairIterator& it);
#line 245
        inline const _1& Key() const;
#line 255
        inline const _2& Value() const;
    };
    
    template < class _1, class _2 >
    class ConstFwdPairPtrIterator
    {
#line 242
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 244
        const _1 *kit;
#line 248
        const _2 *vit;
        
    public:
#line 234
        inline ConstFwdPairPtrIterator();
        inline ConstFwdPairPtrIterator(const ConstFwdPairPtrIterator& it);
#line 249
        inline ConstFwdPairPtrIterator(const _1 *kit, const _2 *vit);
#line 246
        inline bool operator!= (const ConstFwdPairPtrIterator& it) const;
#line 237
        inline ConstFwdPairPtrIterator < _1, _2 > & operator++ ();
#line 239
        inline void operator+= (int i);
#line 238
        inline void operator-- (int i);
#line 236
        inline void operator= (const ConstFwdPairPtrIterator& it);
#line 245
        inline const _1& Key() const;
#line 250
        inline const _2& Value() const;
    };
    
    template < class _1 >
    class ConstFwdPtrIterator
    {
    public:
#line 188
        typedef const _1 ConstK;
        
        const _1 **kit;
        
    public:
#line 180
        inline ConstFwdPtrIterator();
        inline ConstFwdPtrIterator(const ConstFwdPtrIterator& it);
#line 191
        inline ConstFwdPtrIterator(const _1 **kit);
#line 202
        inline bool operator!= (const ConstFwdPtrIterator& it) const;
#line 201
        inline const _1& operator()() const;
#line 200
        inline const _1& operator*() const;
#line 183
        inline ConstFwdPtrIterator < _1 > & operator++ ();
#line 185
        inline void operator+= (int i);
#line 184
        inline void operator-- (int i);
#line 198
        inline const _1 *operator-> () const;
#line 182
        inline void operator= (const ConstFwdPtrIterator& it);
#line 199
        inline operator ConstK * () const;
#line 192
        inline const _1 *Get() const;
    };
    
    template < class _1 >
    class FwdIterator
    {
#line 209
        _1 *kit;
        
    public:
#line 180
        inline FwdIterator();
#line 210
        inline FwdIterator(_1 *kit);
#line 181
        inline FwdIterator(const FwdIterator& it);
#line 217
        inline bool operator!= (const FwdIterator& it) const;
#line 216
        inline _1& operator()() const;
#line 215
        inline _1& operator*() const;
#line 183
        inline FwdIterator < _1 > & operator++ ();
#line 185
        inline void operator+= (int i);
#line 184
        inline void operator-- (int i);
#line 213
        inline _1 *operator-> () const;
#line 182
        inline void operator= (const FwdIterator& it);
#line 214
        inline operator _1 * () const;
#line 211
        inline _1 *Get() const;
    };
    
    template < class _1 >
    class DynArray
    {
    public:
#line 312
        typedef ConstFwdIterator < _1 > ConstIterator;
#line 310
        typedef const _1 ConstK;
#line 313
        typedef ConstBwdIterator < _1 > ConstRIterator;
#line 311
        typedef DynArray < _1 > DynArrayK;
#line 309
        typedef _1 IndirectK;
#line 314
        typedef FwdIterator < _1 > Iterator;
        typedef BwdIterator < _1 > RIterator;
        
    private:
#line 288
        typedef unsigned long long uint64;
        
#line 291
        _1 *data;
        int reserved;
        int count;
        
    public:
#line 317
        inline DynArray();
        inline DynArray(const DynArray& v);
        inline DynArray(int i);
        inline ~DynArray();
#line 373
        inline DynArray < _1 > & operator<< (const _1& v);
#line 406
        inline void operator<<= (const DynArray& a);
#line 438
        inline _1& operator[](int i);
#line 442
        inline const _1& operator[](int i) const;
#line 351
        inline _1& Add();
#line 358
        inline _1& Add(const _1& v);
#line 413
        inline void Append(const DynArray& a);
#line 333
        inline C::ConstFwdIterator < _1 > Begin() const;
#line 331
        inline C::FwdIterator < _1 > Begin();
#line 540
        inline void Clear();
#line 334
        inline C::ConstFwdIterator < _1 > End() const;
#line 332
        inline C::FwdIterator < _1 > End();
#line 348
        inline _1 *Get() const;
#line 434
        inline int GetCount() const;
#line 349
        inline _1 *GetEnd() const;
#line 435
        inline int GetReserved() const;
#line 421
        inline void IncreaseReserve(int more_reserved);
#line 501
        inline _1& Insert(int i);
#line 512
        inline _1& Insert(int i, ConstK& key);
#line 436
        inline bool IsEmpty() const;
#line 526
        inline _1 Pop();
#line 339
        inline C::BwdIterator < _1 > RBegin();
#line 341
        inline C::ConstBwdIterator < _1 > RBegin() const;
#line 340
        inline C::BwdIterator < _1 > REnd();
#line 342
        inline C::ConstBwdIterator < _1 > REnd() const;
#line 480
        inline void Remove(const DynArray < int > & sorted_list);
#line 462
        inline void Remove(const Iterator& it);
#line 469
        inline void Remove(const Iterator& it, const Iterator& end);
#line 481
        inline void Remove(const int *sorted_list, int n);
#line 447
        inline void Remove(int i);
#line 454
        inline void Remove(int i, int count);
#line 535
        inline void RemoveLast();
#line 422
        inline void Reserve(int new_reserved);
#line 375
        inline void SetCount(int new_count);
#line 391
        inline void SetCount(int new_count, ConstK& value);
#line 524
        inline _1& Top();
#line 337
        inline C::ConstFwdIterator < _1 > begin() const;
#line 335
        inline C::FwdIterator < _1 > begin();
#line 338
        inline C::ConstFwdIterator < _1 > end() const;
#line 336
        inline C::FwdIterator < _1 > end();
#line 343
        inline C::BwdIterator < _1 > rbegin();
#line 345
        inline C::ConstBwdIterator < _1 > rbegin() const;
#line 344
        inline C::BwdIterator < _1 > rend();
#line 346
        inline C::ConstBwdIterator < _1 > rend() const;
        
#line 296
        inline void IncreaseReserved();
#line 305
        inline void Pick0(DynArray& v);
    };
    
    template < class _1, class _2 >
    class FwdPairIterator
    {
#line 259
        const _1 *kit;
#line 268
        _2 *vit;
        
    public:
#line 234
        inline FwdPairIterator();
        inline FwdPairIterator(const FwdPairIterator& it);
#line 269
        inline FwdPairIterator(const _1 *kit, _2 *vit);
#line 261
        inline bool operator!= (const FwdPairIterator& it) const;
#line 237
        inline FwdPairIterator < _1, _2 > & operator++ ();
#line 239
        inline void operator+= (int i);
#line 238
        inline void operator-- (int i);
#line 236
        inline void operator= (const FwdPairIterator& it);
#line 270
        inline _2& Value() const;
        
#line 260
        inline const _1& Key() const;
    };
    
    template < class _1, class _2 >
    class FwdPairPtrIterator
    {
#line 259
        const _1 *kit;
#line 263
        _2 **vit;
        
    public:
#line 234
        inline FwdPairPtrIterator();
        inline FwdPairPtrIterator(const FwdPairPtrIterator& it);
#line 264
        inline FwdPairPtrIterator(const _1 *kit, _2 **vit);
#line 261
        inline bool operator!= (const FwdPairPtrIterator& it) const;
#line 237
        inline FwdPairPtrIterator < _1, _2 > & operator++ ();
#line 239
        inline void operator+= (int i);
#line 238
        inline void operator-- (int i);
#line 236
        inline void operator= (const FwdPairPtrIterator& it);
#line 265
        inline _2& Value() const;
        
#line 260
        inline const _1& Key() const;
    };
    
    template < class _1 >
    class FwdPtrIterator
    {
#line 205
        _1 **kit;
        
    public:
#line 180
        inline FwdPtrIterator();
#line 206
        inline FwdPtrIterator(_1 **kit);
#line 181
        inline FwdPtrIterator(const FwdPtrIterator& it);
#line 217
        inline bool operator!= (const FwdPtrIterator& it) const;
#line 216
        inline _1& operator()() const;
#line 215
        inline _1& operator*() const;
#line 183
        inline FwdPtrIterator < _1 > & operator++ ();
#line 185
        inline void operator+= (int i);
#line 184
        inline void operator-- (int i);
#line 213
        inline _1 *operator-> () const;
#line 182
        inline void operator= (const FwdPtrIterator& it);
#line 214
        inline operator _1 * () const;
#line 207
        inline _1 *Get() const;
    };
    
    namespace Memory
    {
#line 102
        void *Alloc(int sz);
#line 104
        int Compare(const void *m1, const void *m2, int sz);
        void *Copy(void *dest, const void *src, int sz);
#line 103
        void Free(void *ptr);
#line 106
        void *Move(void *dest, const void *src, int sz);
        void Set(void *dest, int byte_value, int sz);
    };
    
    struct MemoryLimitExc
    {
#line 168
        const char *msg;
        
#line 169
        inline MemoryLimitExc();
        inline MemoryLimitExc(const char *s);
    };
};

namespace C
{
#line 91
    inline void Destruct(int16& o) {};
    
    inline void Destruct(int32& o) {};
    
    inline void Destruct(int64& o) {};
    
#line 89
    inline void Destruct(int8& o) {};
    
#line 90
    inline void Destruct(uint16& o) {};
    
    inline void Destruct(uint32& o) {};
    
    inline void Destruct(uint64& o) {};
    
#line 88
    inline void Destruct(uint8& o) {};
    
#line 87
    template < class _1 >
    inline void Destruct(_1& o)
    {
#line 87
        o.~T();
    };
    
#line 97
    inline void Destruct(double& o) {};
    
#line 96
    inline void Destruct(float& o) {};
    
    inline void Destruct(void *o) {};
    
#line 180
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator() {};
    
#line 210
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator(_1 *kit)
    :
        kit(kit)
    {};
    
#line 181
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator(const BwdIterator& it)
    {
#line 181
        *this = it;
    };
    
#line 217
    template < class _1 >
    inline bool BwdIterator < _1 >::operator!= (const BwdIterator& it) const
    {
#line 217
        return it.kit != kit;
    };
    
#line 216
    template < class _1 >
    inline _1& BwdIterator < _1 >::operator()() const
    {
#line 216
        return *Get();
    };
    
#line 215
    template < class _1 >
    inline _1& BwdIterator < _1 >::operator*() const
    {
#line 215
        return *Get();
    };
    
#line 183
    template < class _1 >
    inline BwdIterator < _1 > & BwdIterator < _1 >::operator++ ()
    {
#line 183
        kit += -1;
#line 183
        return *this;
    };
    
#line 185
    template < class _1 >
    inline void BwdIterator < _1 >::operator+= (int i)
    {
#line 185
        kit += i;
    };
    
#line 184
    template < class _1 >
    inline void BwdIterator < _1 >::operator-- (int i)
    {
#line 184
        kit -= -1;
    };
    
#line 213
    template < class _1 >
    inline _1 *BwdIterator < _1 >::operator-> () const
    {
#line 213
        return Get();
    };
    
#line 182
    template < class _1 >
    inline void BwdIterator < _1 >::operator= (const BwdIterator& it)
    {
#line 182
        kit = it.kit;
    };
    
#line 214
    template < class _1 >
    inline BwdIterator < _1 >::operator _1 * () const
    {
#line 214
        return Get();
    };
    
#line 211
    template < class _1 >
    inline _1 *BwdIterator < _1 >::Get() const
    {
#line 211
        return kit;
    };
    
#line 234
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 >::BwdPairIterator() {};
    
#line 235
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 >::BwdPairIterator(const BwdPairIterator& it)
    {
#line 235
        *this = it;
    };
    
#line 269
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 >::BwdPairIterator(const _1 *kit, _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 261
    template < class _1, class _2 >
    inline bool BwdPairIterator < _1, _2 >::operator!= (const BwdPairIterator& it) const
    {
#line 261
        return it.kit != kit;
    };
    
#line 237
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 > & BwdPairIterator < _1, _2 >::operator++ ()
    {
#line 237
        kit += -1;
#line 237
        vit += -1;
#line 237
        return *this;
    };
    
#line 239
    template < class _1, class _2 >
    inline void BwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 239
        kit += i;
#line 239
        vit += i;
    };
    
#line 238
    template < class _1, class _2 >
    inline void BwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 238
        kit -= -1;
#line 238
        vit -= -1;
    };
    
#line 236
    template < class _1, class _2 >
    inline void BwdPairIterator < _1, _2 >::operator= (const BwdPairIterator& it)
    {
#line 236
        kit = it.kit;
#line 236
        vit = it.vit;
    };
    
#line 260
    template < class _1, class _2 >
    inline const _1& BwdPairIterator < _1, _2 >::Key() const
    {
#line 260
        return *kit;
    };
    
#line 270
    template < class _1, class _2 >
    inline _2& BwdPairIterator < _1, _2 >::Value() const
    {
#line 270
        return *vit;
    };
    
#line 234
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 >::BwdPairPtrIterator() {};
    
#line 235
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 >::BwdPairPtrIterator(const BwdPairPtrIterator& it)
    {
#line 235
        *this = it;
    };
    
#line 264
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 >::BwdPairPtrIterator(const _1 *kit, _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 261
    template < class _1, class _2 >
    inline bool BwdPairPtrIterator < _1, _2 >::operator!= (const BwdPairPtrIterator& it) const
    {
#line 261
        return it.kit != kit;
    };
    
#line 237
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 > & BwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 237
        kit += -1;
#line 237
        vit += -1;
#line 237
        return *this;
    };
    
#line 239
    template < class _1, class _2 >
    inline void BwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 239
        kit += i;
#line 239
        vit += i;
    };
    
#line 238
    template < class _1, class _2 >
    inline void BwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 238
        kit -= -1;
#line 238
        vit -= -1;
    };
    
#line 236
    template < class _1, class _2 >
    inline void BwdPairPtrIterator < _1, _2 >::operator= (const BwdPairPtrIterator& it)
    {
#line 236
        kit = it.kit;
#line 236
        vit = it.vit;
    };
    
#line 260
    template < class _1, class _2 >
    inline const _1& BwdPairPtrIterator < _1, _2 >::Key() const
    {
#line 260
        return *kit;
    };
    
#line 265
    template < class _1, class _2 >
    inline _2& BwdPairPtrIterator < _1, _2 >::Value() const
    {
#line 265
        return **vit;
    };
    
#line 180
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator() {};
    
#line 206
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator(_1 **kit)
    :
        kit(kit)
    {};
    
#line 181
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator(const BwdPtrIterator& it)
    {
#line 181
        *this = it;
    };
    
#line 217
    template < class _1 >
    inline bool BwdPtrIterator < _1 >::operator!= (const BwdPtrIterator& it) const
    {
#line 217
        return it.kit != kit;
    };
    
#line 216
    template < class _1 >
    inline _1& BwdPtrIterator < _1 >::operator()() const
    {
#line 216
        return *Get();
    };
    
#line 215
    template < class _1 >
    inline _1& BwdPtrIterator < _1 >::operator*() const
    {
#line 215
        return *Get();
    };
    
#line 183
    template < class _1 >
    inline BwdPtrIterator < _1 > & BwdPtrIterator < _1 >::operator++ ()
    {
#line 183
        kit += -1;
#line 183
        return *this;
    };
    
#line 185
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator+= (int i)
    {
#line 185
        kit += i;
    };
    
#line 184
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator-- (int i)
    {
#line 184
        kit -= -1;
    };
    
#line 213
    template < class _1 >
    inline _1 *BwdPtrIterator < _1 >::operator-> () const
    {
#line 213
        return Get();
    };
    
#line 182
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator= (const BwdPtrIterator& it)
    {
#line 182
        kit = it.kit;
    };
    
#line 214
    template < class _1 >
    inline BwdPtrIterator < _1 >::operator _1 * () const
    {
#line 214
        return Get();
    };
    
#line 207
    template < class _1 >
    inline _1 *BwdPtrIterator < _1 >::Get() const
    {
#line 207
        return *kit;
    };
    
#line 58
    template < class _1 >
    inline CPtr < _1 >::CPtr()
    :
        value(0)
    {};
    
#line 59
    template < class _1 >
    inline CPtr < _1 >::CPtr(_1 *p)
    :
        value(p)
    {};
    
#line 60
    template < class _1 >
    inline void CPtr < _1 >::operator= (_1 *p)
    {
#line 60
        value = p;
    };
    
#line 62
    template < class _1 >
    inline bool CPtr < _1 >::operator== (const CPtr& p) const
    {
#line 62
        return value == p.value;
    };
    
#line 63
    template < class _1 >
    inline bool CPtr < _1 >::operator== (void *p) const
    {
#line 63
        return(void * ) value == p;
    };
    
#line 61
    template < class _1 >
    inline CPtr < _1 >::operator _1 * () const
    {
#line 61
        return value;
    };
    
#line 66
    template < class _1 >
    inline unsigned long long CPtr < _1 >::Int() const
    {
#line 66
        return(unsigned long long) value;
    };
    
#line 180
    template < class _1 >
    inline ConstBwdIterator < _1 >::ConstBwdIterator() {};
    
#line 181
    template < class _1 >
    inline ConstBwdIterator < _1 >::ConstBwdIterator(const ConstBwdIterator& it)
    {
#line 181
        *this = it;
    };
    
#line 195
    template < class _1 >
    inline ConstBwdIterator < _1 >::ConstBwdIterator(const _1 *kit)
    :
        kit(kit)
    {};
    
#line 202
    template < class _1 >
    inline bool ConstBwdIterator < _1 >::operator!= (const ConstBwdIterator& it) const
    {
#line 202
        return it.kit != kit;
    };
    
#line 201
    template < class _1 >
    inline const _1& ConstBwdIterator < _1 >::operator()() const
    {
#line 201
        return *Get();
    };
    
#line 200
    template < class _1 >
    inline const _1& ConstBwdIterator < _1 >::operator*() const
    {
#line 200
        return *Get();
    };
    
#line 183
    template < class _1 >
    inline ConstBwdIterator < _1 > & ConstBwdIterator < _1 >::operator++ ()
    {
#line 183
        kit += -1;
#line 183
        return *this;
    };
    
#line 185
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator+= (int i)
    {
#line 185
        kit += i;
    };
    
#line 184
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator-- (int i)
    {
#line 184
        kit -= -1;
    };
    
#line 198
    template < class _1 >
    inline const _1 *ConstBwdIterator < _1 >::operator-> () const
    {
#line 198
        return Get();
    };
    
#line 182
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator= (const ConstBwdIterator& it)
    {
#line 182
        kit = it.kit;
    };
    
#line 199
    template < class _1 >
    inline ConstBwdIterator < _1 >::operator ConstK * () const
    {
#line 199
        return Get();
    };
    
#line 196
    template < class _1 >
    inline const _1 *ConstBwdIterator < _1 >::Get() const
    {
#line 196
        return kit;
    };
    
#line 234
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 >::ConstBwdPairIterator() {};
    
#line 235
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 >::ConstBwdPairIterator(const ConstBwdPairIterator& it)
    {
#line 235
        *this = it;
    };
    
#line 254
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 >::ConstBwdPairIterator(const _1 *kit, const _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 246
    template < class _1, class _2 >
    inline bool ConstBwdPairIterator < _1, _2 >::operator!= (const ConstBwdPairIterator& it) const
    {
#line 246
        return it.kit != kit;
    };
    
#line 237
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 > & ConstBwdPairIterator < _1, _2 >::operator++ ()
    {
#line 237
        kit += -1;
#line 237
        vit += -1;
#line 237
        return *this;
    };
    
#line 239
    template < class _1, class _2 >
    inline void ConstBwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 239
        kit += i;
#line 239
        vit += i;
    };
    
#line 238
    template < class _1, class _2 >
    inline void ConstBwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 238
        kit -= -1;
#line 238
        vit -= -1;
    };
    
#line 236
    template < class _1, class _2 >
    inline void ConstBwdPairIterator < _1, _2 >::operator= (const ConstBwdPairIterator& it)
    {
#line 236
        kit = it.kit;
#line 236
        vit = it.vit;
    };
    
#line 245
    template < class _1, class _2 >
    inline const _1& ConstBwdPairIterator < _1, _2 >::Key() const
    {
#line 245
        return *kit;
    };
    
#line 255
    template < class _1, class _2 >
    inline const _2& ConstBwdPairIterator < _1, _2 >::Value() const
    {
#line 255
        return **vit;
    };
    
#line 234
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 >::ConstBwdPairPtrIterator() {};
    
#line 235
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 >::ConstBwdPairPtrIterator(const ConstBwdPairPtrIterator& it)
    {
#line 235
        *this = it;
    };
    
#line 249
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 >::ConstBwdPairPtrIterator(const _1 *kit, const _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 246
    template < class _1, class _2 >
    inline bool ConstBwdPairPtrIterator < _1, _2 >::operator!= (const ConstBwdPairPtrIterator& it) const
    {
#line 246
        return it.kit != kit;
    };
    
#line 237
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 > & ConstBwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 237
        kit += -1;
#line 237
        vit += -1;
#line 237
        return *this;
    };
    
#line 239
    template < class _1, class _2 >
    inline void ConstBwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 239
        kit += i;
#line 239
        vit += i;
    };
    
#line 238
    template < class _1, class _2 >
    inline void ConstBwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 238
        kit -= -1;
#line 238
        vit -= -1;
    };
    
#line 236
    template < class _1, class _2 >
    inline void ConstBwdPairPtrIterator < _1, _2 >::operator= (const ConstBwdPairPtrIterator& it)
    {
#line 236
        kit = it.kit;
#line 236
        vit = it.vit;
    };
    
#line 245
    template < class _1, class _2 >
    inline const _1& ConstBwdPairPtrIterator < _1, _2 >::Key() const
    {
#line 245
        return *kit;
    };
    
#line 250
    template < class _1, class _2 >
    inline const _2& ConstBwdPairPtrIterator < _1, _2 >::Value() const
    {
#line 250
        return *vit;
    };
    
#line 180
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator() {};
    
#line 181
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator(const ConstBwdPtrIterator& it)
    {
#line 181
        *this = it;
    };
    
#line 191
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator(const _1 **kit)
    :
        kit(kit)
    {};
    
#line 202
    template < class _1 >
    inline bool ConstBwdPtrIterator < _1 >::operator!= (const ConstBwdPtrIterator& it) const
    {
#line 202
        return it.kit != kit;
    };
    
#line 201
    template < class _1 >
    inline const _1& ConstBwdPtrIterator < _1 >::operator()() const
    {
#line 201
        return *Get();
    };
    
#line 200
    template < class _1 >
    inline const _1& ConstBwdPtrIterator < _1 >::operator*() const
    {
#line 200
        return *Get();
    };
    
#line 183
    template < class _1 >
    inline ConstBwdPtrIterator < _1 > & ConstBwdPtrIterator < _1 >::operator++ ()
    {
#line 183
        kit += -1;
#line 183
        return *this;
    };
    
#line 185
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator+= (int i)
    {
#line 185
        kit += i;
    };
    
#line 184
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator-- (int i)
    {
#line 184
        kit -= -1;
    };
    
#line 198
    template < class _1 >
    inline const _1 *ConstBwdPtrIterator < _1 >::operator-> () const
    {
#line 198
        return Get();
    };
    
#line 182
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator= (const ConstBwdPtrIterator& it)
    {
#line 182
        kit = it.kit;
    };
    
#line 199
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::operator ConstK * () const
    {
#line 199
        return Get();
    };
    
#line 192
    template < class _1 >
    inline const _1 *ConstBwdPtrIterator < _1 >::Get() const
    {
#line 192
        return *kit;
    };
    
#line 180
    template < class _1 >
    inline ConstFwdIterator < _1 >::ConstFwdIterator() {};
    
#line 181
    template < class _1 >
    inline ConstFwdIterator < _1 >::ConstFwdIterator(const ConstFwdIterator& it)
    {
#line 181
        *this = it;
    };
    
#line 195
    template < class _1 >
    inline ConstFwdIterator < _1 >::ConstFwdIterator(const _1 *kit)
    :
        kit(kit)
    {};
    
#line 202
    template < class _1 >
    inline bool ConstFwdIterator < _1 >::operator!= (const ConstFwdIterator& it) const
    {
#line 202
        return it.kit != kit;
    };
    
#line 201
    template < class _1 >
    inline const _1& ConstFwdIterator < _1 >::operator()() const
    {
#line 201
        return *Get();
    };
    
#line 200
    template < class _1 >
    inline const _1& ConstFwdIterator < _1 >::operator*() const
    {
#line 200
        return *Get();
    };
    
#line 183
    template < class _1 >
    inline ConstFwdIterator < _1 > & ConstFwdIterator < _1 >::operator++ ()
    {
#line 183
        kit += 1;
#line 183
        return *this;
    };
    
#line 185
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator+= (int i)
    {
#line 185
        kit += i;
    };
    
#line 184
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator-- (int i)
    {
#line 184
        kit -= 1;
    };
    
#line 198
    template < class _1 >
    inline const _1 *ConstFwdIterator < _1 >::operator-> () const
    {
#line 198
        return Get();
    };
    
#line 182
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator= (const ConstFwdIterator& it)
    {
#line 182
        kit = it.kit;
    };
    
#line 199
    template < class _1 >
    inline ConstFwdIterator < _1 >::operator ConstK * () const
    {
#line 199
        return Get();
    };
    
#line 196
    template < class _1 >
    inline const _1 *ConstFwdIterator < _1 >::Get() const
    {
#line 196
        return kit;
    };
    
#line 234
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 >::ConstFwdPairIterator() {};
    
#line 235
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 >::ConstFwdPairIterator(const ConstFwdPairIterator& it)
    {
#line 235
        *this = it;
    };
    
#line 254
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 >::ConstFwdPairIterator(const _1 *kit, const _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 246
    template < class _1, class _2 >
    inline bool ConstFwdPairIterator < _1, _2 >::operator!= (const ConstFwdPairIterator& it) const
    {
#line 246
        return it.kit != kit;
    };
    
#line 237
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 > & ConstFwdPairIterator < _1, _2 >::operator++ ()
    {
#line 237
        kit += 1;
#line 237
        vit += 1;
#line 237
        return *this;
    };
    
#line 239
    template < class _1, class _2 >
    inline void ConstFwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 239
        kit += i;
#line 239
        vit += i;
    };
    
#line 238
    template < class _1, class _2 >
    inline void ConstFwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 238
        kit -= 1;
#line 238
        vit -= 1;
    };
    
#line 236
    template < class _1, class _2 >
    inline void ConstFwdPairIterator < _1, _2 >::operator= (const ConstFwdPairIterator& it)
    {
#line 236
        kit = it.kit;
#line 236
        vit = it.vit;
    };
    
#line 245
    template < class _1, class _2 >
    inline const _1& ConstFwdPairIterator < _1, _2 >::Key() const
    {
#line 245
        return *kit;
    };
    
#line 255
    template < class _1, class _2 >
    inline const _2& ConstFwdPairIterator < _1, _2 >::Value() const
    {
#line 255
        return **vit;
    };
    
#line 234
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 >::ConstFwdPairPtrIterator() {};
    
#line 235
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 >::ConstFwdPairPtrIterator(const ConstFwdPairPtrIterator& it)
    {
#line 235
        *this = it;
    };
    
#line 249
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 >::ConstFwdPairPtrIterator(const _1 *kit, const _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 246
    template < class _1, class _2 >
    inline bool ConstFwdPairPtrIterator < _1, _2 >::operator!= (const ConstFwdPairPtrIterator& it) const
    {
#line 246
        return it.kit != kit;
    };
    
#line 237
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 > & ConstFwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 237
        kit += 1;
#line 237
        vit += 1;
#line 237
        return *this;
    };
    
#line 239
    template < class _1, class _2 >
    inline void ConstFwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 239
        kit += i;
#line 239
        vit += i;
    };
    
#line 238
    template < class _1, class _2 >
    inline void ConstFwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 238
        kit -= 1;
#line 238
        vit -= 1;
    };
    
#line 236
    template < class _1, class _2 >
    inline void ConstFwdPairPtrIterator < _1, _2 >::operator= (const ConstFwdPairPtrIterator& it)
    {
#line 236
        kit = it.kit;
#line 236
        vit = it.vit;
    };
    
#line 245
    template < class _1, class _2 >
    inline const _1& ConstFwdPairPtrIterator < _1, _2 >::Key() const
    {
#line 245
        return *kit;
    };
    
#line 250
    template < class _1, class _2 >
    inline const _2& ConstFwdPairPtrIterator < _1, _2 >::Value() const
    {
#line 250
        return *vit;
    };
    
#line 180
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator() {};
    
#line 181
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator(const ConstFwdPtrIterator& it)
    {
#line 181
        *this = it;
    };
    
#line 191
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator(const _1 **kit)
    :
        kit(kit)
    {};
    
#line 202
    template < class _1 >
    inline bool ConstFwdPtrIterator < _1 >::operator!= (const ConstFwdPtrIterator& it) const
    {
#line 202
        return it.kit != kit;
    };
    
#line 201
    template < class _1 >
    inline const _1& ConstFwdPtrIterator < _1 >::operator()() const
    {
#line 201
        return *Get();
    };
    
#line 200
    template < class _1 >
    inline const _1& ConstFwdPtrIterator < _1 >::operator*() const
    {
#line 200
        return *Get();
    };
    
#line 183
    template < class _1 >
    inline ConstFwdPtrIterator < _1 > & ConstFwdPtrIterator < _1 >::operator++ ()
    {
#line 183
        kit += 1;
#line 183
        return *this;
    };
    
#line 185
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator+= (int i)
    {
#line 185
        kit += i;
    };
    
#line 184
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator-- (int i)
    {
#line 184
        kit -= 1;
    };
    
#line 198
    template < class _1 >
    inline const _1 *ConstFwdPtrIterator < _1 >::operator-> () const
    {
#line 198
        return Get();
    };
    
#line 182
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator= (const ConstFwdPtrIterator& it)
    {
#line 182
        kit = it.kit;
    };
    
#line 199
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::operator ConstK * () const
    {
#line 199
        return Get();
    };
    
#line 192
    template < class _1 >
    inline const _1 *ConstFwdPtrIterator < _1 >::Get() const
    {
#line 192
        return *kit;
    };
    
#line 317
    template < class _1 >
    inline DynArray < _1 >::DynArray()
    :
        data(0),
        reserved(0),
        count(0)
    {};
    
#line 318
    template < class _1 >
    inline DynArray < _1 >::DynArray(const DynArray& v)
    :
        data(0),
        reserved(0),
        count(0)
    {
#line 318
        *this <<= v;
    };
    
#line 319
    template < class _1 >
    inline DynArray < _1 >::DynArray(int i)
    :
        data(0),
        reserved(0),
        count(0)
    {
#line 319
        SetCount(i);
    };
    
#line 320
    template < class _1 >
    inline DynArray < _1 >::~DynArray()
    {
#line 321
        Clear();
        return;
        ;
    };
    
#line 373
    template < class _1 >
    inline DynArray < _1 > & DynArray < _1 >::operator<< (const _1& v)
    {
#line 373
        Add(v);
#line 373
        return *this;
    };
    
#line 406
    template < class _1 >
    inline void DynArray < _1 >::operator<<= (const DynArray& a)
    {
#line 407
        SetCount(0);
        Reserve(a.GetCount());
        for (int i = 0; i < a.GetCount(); i ++ )
            new (&data[i])_1(a[i]);
        count = a.GetCount();
    };
    
#line 438
    template < class _1 >
    inline _1& DynArray < _1 >::operator[](int i)
    {
        {
#line 439
            if (!(i >= 0 && i < count))
            {
#line 439
                SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 440
        ;
#line 440
        return *(data + i);
    };
    
#line 442
    template < class _1 >
    inline const _1& DynArray < _1 >::operator[](int i) const
    {
        {
#line 443
            if (!(i >= 0 && i < count))
            {
#line 443
                SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 444
        ;
#line 444
        return *(data + i);
    };
    
#line 351
    template < class _1 >
    inline _1& DynArray < _1 >::Add()
    {
#line 352
        if (count + 1 > reserved)
#line 352
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        new (&data[count])_1;
        return data[count ++ ];
    };
    
#line 358
    template < class _1 >
    inline _1& DynArray < _1 >::Add(const _1& v)
    {
#line 359
        if (count + 1 > reserved)
#line 359
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        _1 * ptr = &data[count];
        new (ptr)_1(v);
        return data[count ++ ];
    };
    
#line 413
    template < class _1 >
    inline void DynArray < _1 >::Append(const DynArray& a)
    {
#line 414
        int begin = count;
        int new_count = count + a.GetCount();
        Reserve(new_count);
        for (int i = begin, j = 0; i < new_count; i ++ , j ++ )
            new (&data[i])_1(a[j]);
        count = new_count;
    };
    
#line 333
    template < class _1 >
    inline C::ConstFwdIterator < _1 > DynArray < _1 >::Begin() const
    {
#line 333
        return ConstIterator(data);
    };
    
#line 331
    template < class _1 >
    inline C::FwdIterator < _1 > DynArray < _1 >::Begin()
    {
#line 331
        return Iterator(data);
    };
    
#line 540
    template < class _1 >
    inline void DynArray < _1 >::Clear()
    {
#line 541
        if (!reserved)
#line 541
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
    
#line 334
    template < class _1 >
    inline C::ConstFwdIterator < _1 > DynArray < _1 >::End() const
    {
#line 334
        return ConstIterator(data + count);
    };
    
#line 332
    template < class _1 >
    inline C::FwdIterator < _1 > DynArray < _1 >::End()
    {
#line 332
        return Iterator(data + count);
    };
    
#line 348
    template < class _1 >
    inline _1 *DynArray < _1 >::Get() const
    {
#line 348
        return data;
    };
    
#line 434
    template < class _1 >
    inline int DynArray < _1 >::GetCount() const
    {
#line 434
        return count;
    };
    
#line 349
    template < class _1 >
    inline _1 *DynArray < _1 >::GetEnd() const
    {
#line 349
        return data + count;
    };
    
#line 435
    template < class _1 >
    inline int DynArray < _1 >::GetReserved() const
    {
#line 435
        return reserved;
    };
    
#line 421
    template < class _1 >
    inline void DynArray < _1 >::IncreaseReserve(int more_reserved)
    {
#line 421
        Reserve(GetCount() + more_reserved);
    };
    
#line 296
    template < class _1 >
    inline void DynArray < _1 >::IncreaseReserved()
    {
#line 297
        uint64 new_reserved = 1;
        while (new_reserved <= reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2000000000)
            new_reserved = 2000000000;
        Reserve((int) new_reserved);
    };
    
#line 501
    template < class _1 >
    inline _1& DynArray < _1 >::Insert(int i)
    {
#line 502
        if (count + 1 > reserved)
#line 502
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
    
#line 512
    template < class _1 >
    inline _1& DynArray < _1 >::Insert(int i, ConstK& key)
    {
#line 513
        if (count + 1 > reserved)
#line 513
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
    
#line 436
    template < class _1 >
    inline bool DynArray < _1 >::IsEmpty() const
    {
#line 436
        return GetCount() == 0;
    };
    
#line 305
    template < class _1 >
    inline void DynArray < _1 >::Pick0(DynArray& v)
    {
#line 305
        data = v.data;
#line 305
        v.data = 0;
#line 305
        reserved = v.reserved;
#line 305
        v.reserved = 0;
#line 305
        count = v.count;
#line 305
        v.count = 0;
    };
    
#line 526
    template < class _1 >
    inline _1 DynArray < _1 >::Pop()
    {
        {
#line 527
            if (!(GetCount() > 0))
            {
#line 527
                SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 528
        ;
#line 528
        int i = count - 1;
        _1 ret(data[i]);
        data[i].~K();
        count -- ;
        return ret;
    };
    
#line 339
    template < class _1 >
    inline C::BwdIterator < _1 > DynArray < _1 >::RBegin()
    {
#line 339
        return RIterator(data + count - 1);
    };
    
#line 341
    template < class _1 >
    inline C::ConstBwdIterator < _1 > DynArray < _1 >::RBegin() const
    {
#line 341
        return ConstRIterator(data + count - 1);
    };
    
#line 340
    template < class _1 >
    inline C::BwdIterator < _1 > DynArray < _1 >::REnd()
    {
#line 340
        return RIterator(data - 1);
    };
    
#line 342
    template < class _1 >
    inline C::ConstBwdIterator < _1 > DynArray < _1 >::REnd() const
    {
#line 342
        return ConstRIterator(data - 1);
    };
    
#line 480
    template < class _1 >
    inline void DynArray < _1 >::Remove(const DynArray < int > & sorted_list)
    {
#line 480
        Remove(sorted_list.Begin(), sorted_list.GetCount());
    };
    
#line 462
    template < class _1 >
    inline void DynArray < _1 >::Remove(const Iterator& it)
    {
#line 463
        _1 * begin = data;
        _1 * cur = it.Get();
        int pos = cur - begin;
        Remove(pos);
    };
    
    template < class _1 >
    inline void DynArray < _1 >::Remove(const Iterator& it, const Iterator& end)
    {
#line 470
        _1 * begin = data;
        _1 * cur = it.Get();
        _1 * cur_end = end.Get();
        int pos0 = cur - begin;
        int pos1 = cur_end - begin;
        int len = pos1 - pos0;
        if (!len)
#line 476
            return;
        Remove(pos0, len);
    };
    
#line 481
    template < class _1 >
    inline void DynArray < _1 >::Remove(const int *sorted_list, int n)
    {
#line 482
        if (!n)
#line 482
            return;
        int pos = *sorted_list;
        int npos = pos;
        for (;;)
            {
                {
#line 486
                    if (!(pos < count))
                    {
#line 486
                        SysBreak("Assertion failed: pos < count");
                    }
                }
#line 487
                ;
#line 487
                if (pos == *sorted_list)
                {
#line 488
                    (data + pos)-> ~K();
                    pos ++ ;
                    sorted_list ++ ;
                    if (-- n == 0)
#line 491
                        break;
                    
                    {
#line 492
                        if (!(*sorted_list >= pos))
                        {
#line 492
                            SysBreak("Assertion failed: *sorted_list >= pos");
                        }
                    }
#line 493
                    ;
                }
                else
#line 495
                    Memory::Copy(data + npos ++ , data + pos ++ , sizeof (_1));
            }
        while (pos < count)
            Memory::Copy(data + npos ++ , data + pos ++ , sizeof (_1));
        count = npos;
    };
    
#line 447
    template < class _1 >
    inline void DynArray < _1 >::Remove(int i)
    {
        {
#line 448
            if (!(i >= 0 && i < count))
            {
#line 448
                SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 449
        ;
#line 449
        int tail = count - (i + 1);
        if (tail > 0)
            Memory::Move(data + i, data + i + 1, tail * sizeof (_1));
        count -- ;
    };
    
#line 454
    template < class _1 >
    inline void DynArray < _1 >::Remove(int i, int count)
    {
        {
#line 455
            if (!(count > 0))
            {
#line 455
                SysBreak("Assertion failed: count > 0");
            }
        }
#line 456
        ;
        {
#line 456
            if (!(i >= 0 && i + count <= this -> count))
            {
#line 456
                SysBreak("Assertion failed: i >= 0 && i + count <= this->count");
            }
        }
#line 457
        ;
#line 457
        int tail = this -> count - (i + count);
        if (tail > 0)
            Memory::Move(data + i, data + i + count, tail * sizeof (_1));
        this -> count -= count;
    };
    
#line 535
    template < class _1 >
    inline void DynArray < _1 >::RemoveLast()
    {
        {
#line 536
            if (!(GetCount() > 0))
            {
#line 536
                SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 537
        ;
#line 537
        data[-- count].~K();
    };
    
#line 422
    template < class _1 >
    inline void DynArray < _1 >::Reserve(int new_reserved)
    {
#line 423
        if (new_reserved <= reserved || new_reserved <= 0)
            return;
        _1 * new_data = (_1 * ) Memory::Alloc(new_reserved * sizeof (_1));
        if (data)
        {
#line 427
            if (count > 0)
                Memory::Copy((void * ) new_data, (void * ) data, sizeof (_1) * count);
            Memory::Free(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
#line 375
    template < class _1 >
    inline void DynArray < _1 >::SetCount(int new_count)
    {
        {
#line 376
            if (!(new_count >= 0))
            {
#line 376
                SysBreak("Assertion failed: new_count >= 0");
            }
        }
#line 377
        ;
#line 377
        if (new_count < 0)
#line 377
            return;
        if (new_count > reserved)
#line 378
            Reserve(new_count);
        if (new_count == count)
#line 379
            return;
        if (new_count > count)
        {
#line 381
            for (int i = count; i < new_count; i ++ )
                new (&data[i])_1;
        }
        else
        {
#line 385
            for (int i = count - 1; i >= new_count; i -- )
                Destruct(data[i]);
        }
#line 389
        count = new_count;
    };
    
#line 391
    template < class _1 >
    inline void DynArray < _1 >::SetCount(int new_count, ConstK& value)
    {
        {
#line 392
            if (!(new_count >= 0))
            {
#line 392
                SysBreak("Assertion failed: new_count >= 0");
            }
        }
#line 393
        ;
#line 393
        if (new_count < 0)
#line 393
            return;
        if (new_count > reserved)
#line 394
            Reserve(new_count);
        if (new_count == count)
#line 395
            return;
        if (new_count > count)
        {
#line 397
            for (int i = count; i < new_count; i ++ )
                new (&data[i])_1(value);
        }
        else
        {
#line 401
            for (int i = count - 1; i >= new_count; i -- )
                data[i].~K();
        }
        count = new_count;
    };
    
#line 524
    template < class _1 >
    inline _1& DynArray < _1 >::Top()
    {
        {
#line 524
            if (!(GetCount() > 0))
            {
#line 524
                SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 524
        ;
#line 524
        return data[count - 1];
    };
    
#line 337
    template < class _1 >
    inline C::ConstFwdIterator < _1 > DynArray < _1 >::begin() const
    {
#line 337
        return Begin();
    };
    
#line 335
    template < class _1 >
    inline C::FwdIterator < _1 > DynArray < _1 >::begin()
    {
#line 335
        return Begin();
    };
    
    template < class _1 >
    inline C::ConstFwdIterator < _1 > DynArray < _1 >::end() const
    {
#line 338
        return End();
    };
    
#line 336
    template < class _1 >
    inline C::FwdIterator < _1 > DynArray < _1 >::end()
    {
#line 336
        return End();
    };
    
#line 343
    template < class _1 >
    inline C::BwdIterator < _1 > DynArray < _1 >::rbegin()
    {
#line 343
        return RBegin();
    };
    
#line 345
    template < class _1 >
    inline C::ConstBwdIterator < _1 > DynArray < _1 >::rbegin() const
    {
#line 345
        return RBegin();
    };
    
#line 344
    template < class _1 >
    inline C::BwdIterator < _1 > DynArray < _1 >::rend()
    {
#line 344
        return REnd();
    };
    
#line 346
    template < class _1 >
    inline C::ConstBwdIterator < _1 > DynArray < _1 >::rend() const
    {
#line 346
        return REnd();
    };
    
#line 180
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator() {};
    
#line 210
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator(_1 *kit)
    :
        kit(kit)
    {};
    
#line 181
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator(const FwdIterator& it)
    {
#line 181
        *this = it;
    };
    
#line 217
    template < class _1 >
    inline bool FwdIterator < _1 >::operator!= (const FwdIterator& it) const
    {
#line 217
        return it.kit != kit;
    };
    
#line 216
    template < class _1 >
    inline _1& FwdIterator < _1 >::operator()() const
    {
#line 216
        return *Get();
    };
    
#line 215
    template < class _1 >
    inline _1& FwdIterator < _1 >::operator*() const
    {
#line 215
        return *Get();
    };
    
#line 183
    template < class _1 >
    inline FwdIterator < _1 > & FwdIterator < _1 >::operator++ ()
    {
#line 183
        kit += 1;
#line 183
        return *this;
    };
    
#line 185
    template < class _1 >
    inline void FwdIterator < _1 >::operator+= (int i)
    {
#line 185
        kit += i;
    };
    
#line 184
    template < class _1 >
    inline void FwdIterator < _1 >::operator-- (int i)
    {
#line 184
        kit -= 1;
    };
    
#line 213
    template < class _1 >
    inline _1 *FwdIterator < _1 >::operator-> () const
    {
#line 213
        return Get();
    };
    
#line 182
    template < class _1 >
    inline void FwdIterator < _1 >::operator= (const FwdIterator& it)
    {
#line 182
        kit = it.kit;
    };
    
#line 214
    template < class _1 >
    inline FwdIterator < _1 >::operator _1 * () const
    {
#line 214
        return Get();
    };
    
#line 211
    template < class _1 >
    inline _1 *FwdIterator < _1 >::Get() const
    {
#line 211
        return kit;
    };
    
#line 234
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 >::FwdPairIterator() {};
    
#line 235
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 >::FwdPairIterator(const FwdPairIterator& it)
    {
#line 235
        *this = it;
    };
    
#line 269
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 >::FwdPairIterator(const _1 *kit, _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 261
    template < class _1, class _2 >
    inline bool FwdPairIterator < _1, _2 >::operator!= (const FwdPairIterator& it) const
    {
#line 261
        return it.kit != kit;
    };
    
#line 237
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 > & FwdPairIterator < _1, _2 >::operator++ ()
    {
#line 237
        kit += 1;
#line 237
        vit += 1;
#line 237
        return *this;
    };
    
#line 239
    template < class _1, class _2 >
    inline void FwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 239
        kit += i;
#line 239
        vit += i;
    };
    
#line 238
    template < class _1, class _2 >
    inline void FwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 238
        kit -= 1;
#line 238
        vit -= 1;
    };
    
#line 236
    template < class _1, class _2 >
    inline void FwdPairIterator < _1, _2 >::operator= (const FwdPairIterator& it)
    {
#line 236
        kit = it.kit;
#line 236
        vit = it.vit;
    };
    
#line 260
    template < class _1, class _2 >
    inline const _1& FwdPairIterator < _1, _2 >::Key() const
    {
#line 260
        return *kit;
    };
    
#line 270
    template < class _1, class _2 >
    inline _2& FwdPairIterator < _1, _2 >::Value() const
    {
#line 270
        return *vit;
    };
    
#line 234
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 >::FwdPairPtrIterator() {};
    
#line 235
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 >::FwdPairPtrIterator(const FwdPairPtrIterator& it)
    {
#line 235
        *this = it;
    };
    
#line 264
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 >::FwdPairPtrIterator(const _1 *kit, _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 261
    template < class _1, class _2 >
    inline bool FwdPairPtrIterator < _1, _2 >::operator!= (const FwdPairPtrIterator& it) const
    {
#line 261
        return it.kit != kit;
    };
    
#line 237
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 > & FwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 237
        kit += 1;
#line 237
        vit += 1;
#line 237
        return *this;
    };
    
#line 239
    template < class _1, class _2 >
    inline void FwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 239
        kit += i;
#line 239
        vit += i;
    };
    
#line 238
    template < class _1, class _2 >
    inline void FwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 238
        kit -= 1;
#line 238
        vit -= 1;
    };
    
#line 236
    template < class _1, class _2 >
    inline void FwdPairPtrIterator < _1, _2 >::operator= (const FwdPairPtrIterator& it)
    {
#line 236
        kit = it.kit;
#line 236
        vit = it.vit;
    };
    
#line 260
    template < class _1, class _2 >
    inline const _1& FwdPairPtrIterator < _1, _2 >::Key() const
    {
#line 260
        return *kit;
    };
    
#line 265
    template < class _1, class _2 >
    inline _2& FwdPairPtrIterator < _1, _2 >::Value() const
    {
#line 265
        return **vit;
    };
    
#line 180
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator() {};
    
#line 206
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator(_1 **kit)
    :
        kit(kit)
    {};
    
#line 181
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator(const FwdPtrIterator& it)
    {
#line 181
        *this = it;
    };
    
#line 217
    template < class _1 >
    inline bool FwdPtrIterator < _1 >::operator!= (const FwdPtrIterator& it) const
    {
#line 217
        return it.kit != kit;
    };
    
#line 216
    template < class _1 >
    inline _1& FwdPtrIterator < _1 >::operator()() const
    {
#line 216
        return *Get();
    };
    
#line 215
    template < class _1 >
    inline _1& FwdPtrIterator < _1 >::operator*() const
    {
#line 215
        return *Get();
    };
    
#line 183
    template < class _1 >
    inline FwdPtrIterator < _1 > & FwdPtrIterator < _1 >::operator++ ()
    {
#line 183
        kit += 1;
#line 183
        return *this;
    };
    
#line 185
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator+= (int i)
    {
#line 185
        kit += i;
    };
    
#line 184
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator-- (int i)
    {
#line 184
        kit -= 1;
    };
    
#line 213
    template < class _1 >
    inline _1 *FwdPtrIterator < _1 >::operator-> () const
    {
#line 213
        return Get();
    };
    
#line 182
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator= (const FwdPtrIterator& it)
    {
#line 182
        kit = it.kit;
    };
    
#line 214
    template < class _1 >
    inline FwdPtrIterator < _1 >::operator _1 * () const
    {
#line 214
        return Get();
    };
    
#line 207
    template < class _1 >
    inline _1 *FwdPtrIterator < _1 >::Get() const
    {
#line 207
        return *kit;
    };
    
#line 169
    inline MemoryLimitExc::MemoryLimitExc()
    :
        msg(0)
    {};
    
#line 170
    inline MemoryLimitExc::MemoryLimitExc(const char *s)
    :
        msg(s)
    {};
    
};

#endif
