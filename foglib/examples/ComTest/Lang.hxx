#ifndef LANG_HXX
#define LANG_HXX

#include <new>

#ifndef ALGORITHM_HXX
#include <Algorithm.hxx>
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
#line 173 "../../src/Com/Meta.fog"
    typedef unsigned char byte;
    
#line 174
    extern byte ____unused_byte;
};

namespace Lang
{
#line 173
    typedef unsigned int uint32;
#line 173
    typedef uint32 dword;
    
#line 174
    extern dword ____unused_dword;
};

namespace Lang
{
#line 173
    typedef short int16;
    
#line 174
    extern int16 ____unused_int16;
};

namespace Lang
{
#line 173
    typedef int int32;
    
#line 174
    extern int32 ____unused_int32;
};

namespace Lang
{
#line 173
    typedef long long int64;
    
#line 174
    extern int64 ____unused_int64;
};

namespace Lang
{
#line 173
    typedef char int8;
    
#line 174
    extern int8 ____unused_int8;
};

namespace Lang
{
#line 173
    typedef unsigned long long uint64;
#line 173
    typedef uint64 qword;
    
#line 174
    extern qword ____unused_qword;
};

namespace Lang
{
#line 173
    typedef unsigned short uint16;
    
#line 174
    extern uint16 ____unused_uint16;
#line 174
    extern uint32 ____unused_uint32;
#line 174
    extern uint64 ____unused_uint64;
};

namespace Lang
{
#line 173
    typedef unsigned char uint8;
    
#line 174
    extern uint8 ____unused_uint8;
};

namespace Lang
{
#line 173
    typedef uint16 word;
    
#line 174
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
#line 43
    inline bool FitsInInt64(double x);
#line 564
    inline bool IsNull(const int16& v);
    inline bool IsNull(const int32& v);
    inline bool IsNull(const int64& v);
#line 563
    inline bool IsNull(const int8& v);
#line 568
    inline bool IsNull(const uint16& v);
    inline bool IsNull(const uint32& v);
    inline bool IsNull(const uint64& v);
#line 567
    inline bool IsNull(const uint8& v);
#line 561
    template < class _1 >
    inline bool IsNull(const _1& o);
#line 562
    inline bool IsNull(const bool& v);
#line 572
    inline bool IsNull(const double& v);
#line 571
    inline bool IsNull(const float& v);
#line 534
    template < class _1 >
    inline int NumberCompare__(const _1& a, const _1& b);
#line 554
    inline int SgnCompare(const int64& a, const int64& b);
    inline int SgnCompare(const uint64& a, const uint64& b);
#line 542
    template < class _1 >
    inline int SgnCompare(const _1& a, const _1& b);
#line 553
    inline int SgnCompare(const bool& a, const bool& b);
#line 544
    inline int SgnCompare(const char& a, const char& b);
#line 557
    inline int SgnCompare(const double& a, const double& b);
#line 556
    inline int SgnCompare(const float& a, const float& b);
#line 549
    inline int SgnCompare(const int& a, const int& b);
#line 551
    inline int SgnCompare(const long& a, const long& b);
#line 547
    inline int SgnCompare(const short& a, const short& b);
#line 545
    inline int SgnCompare(const signed char& a, const signed char& b);
    inline int SgnCompare(const unsigned char& a, const unsigned char& b);
#line 550
    inline int SgnCompare(const unsigned int& a, const unsigned int& b);
#line 552
    inline int SgnCompare(const unsigned long& a, const unsigned long& b);
#line 548
    inline int SgnCompare(const unsigned short& a, const unsigned short& b);
#line 61
    int StringLength(const char *c, int max_len = 100000000);
    int StringLength(const short *c, int max_len = 100000000);
#line 59
    void SysBreak(const char *msg);
    
    struct AtomicBool
    {
#line 75
        AtomicBool();
        AtomicBool(bool b);
        AtomicBool(const AtomicBool& ai);
#line 79
        bool operator= (bool b);
#line 78
        operator bool();
    };
    
    struct AtomicFlag
    {
#line 67
        void Enter();
        void Leave();
        bool TryEnter();
    };
    
    struct AtomicInt
    {
#line 85
        AtomicInt();
#line 87
        AtomicInt(const AtomicInt& ai);
#line 86
        AtomicInt(int i);
#line 90
        int operator++ ();
#line 92
        int operator++ (int);
#line 91
        int operator-- ();
#line 93
        int operator-- (int);
#line 89
        int operator= (int i);
#line 88
        operator int() const;
    };
    
    template < class _1 >
    class BwdIterator
    {
#line 157
        _1 *kit;
        
    public:
#line 127
        inline BwdIterator();
#line 158
        inline BwdIterator(_1 *kit);
#line 128
        inline BwdIterator(const BwdIterator& it);
#line 165
        inline bool operator!= (const BwdIterator& it) const;
#line 164
        inline _1& operator()() const;
#line 163
        inline _1& operator*() const;
#line 130
        inline BwdIterator < _1 > & operator++ ();
#line 132
        inline void operator+= (int i);
#line 131
        inline void operator-- (int i);
#line 161
        inline _1 *operator-> () const;
#line 129
        inline void operator= (const BwdIterator& it);
#line 162
        inline operator _1 * () const;
#line 159
        inline _1 *Get() const;
    };
    
    template < class _1, class _2 >
    class BwdPairIterator
    {
#line 207
        const _1 *kit;
#line 216
        _2 *vit;
        
    public:
#line 182
        inline BwdPairIterator();
        inline BwdPairIterator(const BwdPairIterator& it);
#line 217
        inline BwdPairIterator(const _1 *kit, _2 *vit);
#line 209
        inline bool operator!= (const BwdPairIterator& it) const;
#line 185
        inline BwdPairIterator < _1, _2 > & operator++ ();
#line 187
        inline void operator+= (int i);
#line 186
        inline void operator-- (int i);
#line 184
        inline void operator= (const BwdPairIterator& it);
#line 218
        inline _2& GetValue() const;
        
#line 208
        inline const _1& GetKey() const;
    };
    
    template < class _1, class _2 >
    class BwdPairPtrIterator
    {
#line 207
        const _1 *kit;
#line 211
        _2 **vit;
        
    public:
#line 182
        inline BwdPairPtrIterator();
        inline BwdPairPtrIterator(const BwdPairPtrIterator& it);
#line 212
        inline BwdPairPtrIterator(const _1 *kit, _2 **vit);
#line 209
        inline bool operator!= (const BwdPairPtrIterator& it) const;
#line 185
        inline BwdPairPtrIterator < _1, _2 > & operator++ ();
#line 187
        inline void operator+= (int i);
#line 186
        inline void operator-- (int i);
#line 184
        inline void operator= (const BwdPairPtrIterator& it);
#line 213
        inline _2& GetValue() const;
        
#line 208
        inline const _1& GetKey() const;
    };
    
    template < class _1 >
    class BwdPtrIterator
    {
#line 152
        _1 **kit;
        
    public:
#line 127
        inline BwdPtrIterator();
#line 153
        inline BwdPtrIterator(_1 **kit);
#line 128
        inline BwdPtrIterator(const BwdPtrIterator& it);
#line 165
        inline bool operator!= (const BwdPtrIterator& it) const;
#line 164
        inline _1& operator()() const;
#line 163
        inline _1& operator*() const;
#line 130
        inline BwdPtrIterator < _1 > & operator++ ();
#line 132
        inline void operator+= (int i);
#line 131
        inline void operator-- (int i);
#line 161
        inline _1 *operator-> () const;
#line 129
        inline void operator= (const BwdPtrIterator& it);
#line 162
        inline operator _1 * () const;
#line 154
        inline _1 *Get() const;
        inline _1 *& Ref();
    };
    
    struct ConditionalVar
    {
#line 98
        ConditionalVar();
#line 101
        bool IsReady() const;
#line 100
        void SetReady(bool b = true);
#line 99
        void Wait();
    };
    
    template < class _1 >
    class ConstBwdIterator
    {
    public:
#line 135
        typedef const _1 ConstK;
        
#line 141
        const _1 *kit;
        
    public:
#line 127
        inline ConstBwdIterator();
        inline ConstBwdIterator(const ConstBwdIterator& it);
#line 142
        inline ConstBwdIterator(const _1 *kit);
#line 149
        inline bool operator!= (const ConstBwdIterator& it) const;
#line 148
        inline const _1& operator()() const;
#line 147
        inline const _1& operator*() const;
#line 130
        inline ConstBwdIterator < _1 > & operator++ ();
#line 132
        inline void operator+= (int i);
#line 131
        inline void operator-- (int i);
#line 145
        inline const _1 *operator-> () const;
#line 129
        inline void operator= (const ConstBwdIterator& it);
#line 146
        inline operator ConstK * () const;
#line 143
        inline const _1 *Get() const;
    };
    
    template < class _1, class _2 >
    class ConstBwdPairIterator
    {
#line 190
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 192
        const _1 *kit;
#line 201
        const _2 **vit;
        
    public:
#line 182
        inline ConstBwdPairIterator();
        inline ConstBwdPairIterator(const ConstBwdPairIterator& it);
#line 202
        inline ConstBwdPairIterator(const _1 *kit, const _2 **vit);
#line 194
        inline bool operator!= (const ConstBwdPairIterator& it) const;
#line 185
        inline ConstBwdPairIterator < _1, _2 > & operator++ ();
#line 187
        inline void operator+= (int i);
#line 186
        inline void operator-- (int i);
#line 184
        inline void operator= (const ConstBwdPairIterator& it);
#line 193
        inline const _1& GetKey() const;
#line 203
        inline const _2& GetValue() const;
    };
    
    template < class _1, class _2 >
    class ConstBwdPairPtrIterator
    {
#line 190
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 192
        const _1 *kit;
#line 196
        const _2 *vit;
        
    public:
#line 182
        inline ConstBwdPairPtrIterator();
        inline ConstBwdPairPtrIterator(const ConstBwdPairPtrIterator& it);
#line 197
        inline ConstBwdPairPtrIterator(const _1 *kit, const _2 *vit);
#line 194
        inline bool operator!= (const ConstBwdPairPtrIterator& it) const;
#line 185
        inline ConstBwdPairPtrIterator < _1, _2 > & operator++ ();
#line 187
        inline void operator+= (int i);
#line 186
        inline void operator-- (int i);
#line 184
        inline void operator= (const ConstBwdPairPtrIterator& it);
#line 193
        inline const _1& GetKey() const;
#line 198
        inline const _2& GetValue() const;
    };
    
    template < class _1 >
    class ConstBwdPtrIterator
    {
    public:
#line 135
        typedef const _1 ConstK;
        
        const _1 **kit;
        
    public:
#line 127
        inline ConstBwdPtrIterator();
        inline ConstBwdPtrIterator(const ConstBwdPtrIterator& it);
#line 138
        inline ConstBwdPtrIterator(const _1 **kit);
#line 149
        inline bool operator!= (const ConstBwdPtrIterator& it) const;
#line 148
        inline const _1& operator()() const;
#line 147
        inline const _1& operator*() const;
#line 130
        inline ConstBwdPtrIterator < _1 > & operator++ ();
#line 132
        inline void operator+= (int i);
#line 131
        inline void operator-- (int i);
#line 145
        inline const _1 *operator-> () const;
#line 129
        inline void operator= (const ConstBwdPtrIterator& it);
#line 146
        inline operator ConstK * () const;
#line 139
        inline const _1 *Get() const;
    };
    
    template < class _1 >
    class ConstFwdIterator
    {
    public:
#line 135
        typedef const _1 ConstK;
        
#line 141
        const _1 *kit;
        
    public:
#line 127
        inline ConstFwdIterator();
        inline ConstFwdIterator(const ConstFwdIterator& it);
#line 142
        inline ConstFwdIterator(const _1 *kit);
#line 149
        inline bool operator!= (const ConstFwdIterator& it) const;
#line 148
        inline const _1& operator()() const;
#line 147
        inline const _1& operator*() const;
#line 130
        inline ConstFwdIterator < _1 > & operator++ ();
#line 132
        inline void operator+= (int i);
#line 131
        inline void operator-- (int i);
#line 145
        inline const _1 *operator-> () const;
#line 129
        inline void operator= (const ConstFwdIterator& it);
#line 146
        inline operator ConstK * () const;
#line 143
        inline const _1 *Get() const;
    };
    
    template < class _1, class _2 >
    class ConstFwdPairIterator
    {
#line 190
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 192
        const _1 *kit;
#line 201
        const _2 **vit;
        
    public:
#line 182
        inline ConstFwdPairIterator();
        inline ConstFwdPairIterator(const ConstFwdPairIterator& it);
#line 202
        inline ConstFwdPairIterator(const _1 *kit, const _2 **vit);
#line 194
        inline bool operator!= (const ConstFwdPairIterator& it) const;
#line 185
        inline ConstFwdPairIterator < _1, _2 > & operator++ ();
#line 187
        inline void operator+= (int i);
#line 186
        inline void operator-- (int i);
#line 184
        inline void operator= (const ConstFwdPairIterator& it);
#line 193
        inline const _1& GetKey() const;
#line 203
        inline const _2& GetValue() const;
    };
    
    template < class _1, class _2 >
    class ConstFwdPairPtrIterator
    {
#line 190
        typedef const _1 ConstK;
        typedef const _2 ConstV;
        
#line 192
        const _1 *kit;
#line 196
        const _2 *vit;
        
    public:
#line 182
        inline ConstFwdPairPtrIterator();
        inline ConstFwdPairPtrIterator(const ConstFwdPairPtrIterator& it);
#line 197
        inline ConstFwdPairPtrIterator(const _1 *kit, const _2 *vit);
#line 194
        inline bool operator!= (const ConstFwdPairPtrIterator& it) const;
#line 185
        inline ConstFwdPairPtrIterator < _1, _2 > & operator++ ();
#line 187
        inline void operator+= (int i);
#line 186
        inline void operator-- (int i);
#line 184
        inline void operator= (const ConstFwdPairPtrIterator& it);
#line 193
        inline const _1& GetKey() const;
#line 198
        inline const _2& GetValue() const;
    };
    
    template < class _1 >
    class ConstFwdPtrIterator
    {
    public:
#line 135
        typedef const _1 ConstK;
        
        const _1 **kit;
        
    public:
#line 127
        inline ConstFwdPtrIterator();
        inline ConstFwdPtrIterator(const ConstFwdPtrIterator& it);
#line 138
        inline ConstFwdPtrIterator(const _1 **kit);
#line 149
        inline bool operator!= (const ConstFwdPtrIterator& it) const;
#line 148
        inline const _1& operator()() const;
#line 147
        inline const _1& operator*() const;
#line 130
        inline ConstFwdPtrIterator < _1 > & operator++ ();
#line 132
        inline void operator+= (int i);
#line 131
        inline void operator-- (int i);
#line 145
        inline const _1 *operator-> () const;
#line 129
        inline void operator= (const ConstFwdPtrIterator& it);
#line 146
        inline operator ConstK * () const;
#line 139
        inline const _1 *Get() const;
    };
    
    template < class _1 >
    class FwdIterator
    {
#line 157
        _1 *kit;
        
    public:
#line 127
        inline FwdIterator();
#line 158
        inline FwdIterator(_1 *kit);
#line 128
        inline FwdIterator(const FwdIterator& it);
#line 165
        inline bool operator!= (const FwdIterator& it) const;
#line 164
        inline _1& operator()() const;
#line 163
        inline _1& operator*() const;
#line 130
        inline FwdIterator < _1 > & operator++ ();
#line 132
        inline void operator+= (int i);
#line 131
        inline void operator-- (int i);
#line 161
        inline _1 *operator-> () const;
#line 129
        inline void operator= (const FwdIterator& it);
#line 162
        inline operator _1 * () const;
#line 159
        inline _1 *Get() const;
    };
    
    template < class _1 >
    class DynArray
    {
    public:
#line 262
        typedef ConstFwdIterator < _1 > ConstIterator;
#line 260
        typedef const _1 ConstK;
#line 263
        typedef ConstBwdIterator < _1 > ConstRIterator;
#line 258
        typedef const _1 ConstUnit;
#line 261
        typedef DynArray < _1 > DynArrayK;
#line 259
        typedef _1 IndirectK;
#line 264
        typedef FwdIterator < _1 > Iterator;
        typedef BwdIterator < _1 > RIterator;
#line 257
        typedef _1 Unit;
        
    private:
#line 236
        typedef unsigned long long uint64;
        
#line 239
        _1 *data;
        int reserved;
        int count;
        
    public:
#line 267
        inline DynArray();
        inline DynArray(const DynArray& v);
        inline DynArray(int i);
        inline ~DynArray();
#line 323
        inline DynArray < _1 > & operator<< (const _1& v);
#line 356
        inline void operator<<= (const DynArray& a);
#line 410
        inline _1& operator[](int i);
        inline const _1& operator[](int i) const;
#line 301
        inline _1& Add();
#line 308
        inline _1& Add(const _1& v);
#line 363
        inline void Append(const DynArray& a);
#line 371
        inline void Append(const DynArray& a, int i, int n);
#line 401
        inline _1& At(int i);
#line 405
        inline const _1& At(int i) const;
#line 283
        inline Lang::ConstFwdIterator < _1 > Begin() const;
#line 281
        inline Lang::FwdIterator < _1 > Begin();
#line 518
        inline void Clear();
#line 284
        inline Lang::ConstFwdIterator < _1 > End() const;
#line 282
        inline Lang::FwdIterator < _1 > End();
#line 298
        inline _1 *Get() const;
#line 397
        inline int GetCount() const;
#line 299
        inline _1 *GetEnd() const;
#line 398
        inline int GetReserved() const;
#line 384
        inline void IncreaseReserve(int more_reserved);
#line 479
        inline _1& Insert(int i);
#line 490
        inline _1& Insert(int i, ConstK& key);
#line 467
        inline void InsertN(int i, int n);
#line 399
        inline bool IsEmpty() const;
#line 504
        inline _1 Pop();
#line 289
        inline Lang::BwdIterator < _1 > RBegin();
#line 291
        inline Lang::ConstBwdIterator < _1 > RBegin() const;
#line 290
        inline Lang::BwdIterator < _1 > REnd();
#line 292
        inline Lang::ConstBwdIterator < _1 > REnd() const;
#line 446
        inline void Remove(const DynArray < int > & sorted_list);
#line 428
        inline void Remove(const Iterator& it);
#line 435
        inline void Remove(const Iterator& it, const Iterator& end);
#line 447
        inline void Remove(const int *sorted_list, int n);
#line 413
        inline void Remove(int i);
#line 420
        inline void Remove(int i, int count);
#line 513
        inline void RemoveLast();
#line 385
        inline void Reserve(int new_reserved);
#line 325
        inline void SetCount(int new_count);
#line 341
        inline void SetCount(int new_count, ConstK& value);
#line 502
        inline _1& Top();
#line 287
        inline Lang::ConstFwdIterator < _1 > begin() const;
#line 285
        inline Lang::FwdIterator < _1 > begin();
#line 288
        inline Lang::ConstFwdIterator < _1 > end() const;
#line 286
        inline Lang::FwdIterator < _1 > end();
#line 293
        inline Lang::BwdIterator < _1 > rbegin();
#line 295
        inline Lang::ConstBwdIterator < _1 > rbegin() const;
#line 294
        inline Lang::BwdIterator < _1 > rend();
#line 296
        inline Lang::ConstBwdIterator < _1 > rend() const;
        
#line 244
        inline void IncreaseReserved();
#line 253
        inline void Pick0(DynArray& v);
    };
    
    template < class _1, class _2 >
    class FwdPairIterator
    {
#line 207
        const _1 *kit;
#line 216
        _2 *vit;
        
    public:
#line 182
        inline FwdPairIterator();
        inline FwdPairIterator(const FwdPairIterator& it);
#line 217
        inline FwdPairIterator(const _1 *kit, _2 *vit);
#line 209
        inline bool operator!= (const FwdPairIterator& it) const;
#line 185
        inline FwdPairIterator < _1, _2 > & operator++ ();
#line 187
        inline void operator+= (int i);
#line 186
        inline void operator-- (int i);
#line 184
        inline void operator= (const FwdPairIterator& it);
#line 218
        inline _2& GetValue() const;
        
#line 208
        inline const _1& GetKey() const;
    };
    
    template < class _1, class _2 >
    class FwdPairPtrIterator
    {
#line 207
        const _1 *kit;
#line 211
        _2 **vit;
        
    public:
#line 182
        inline FwdPairPtrIterator();
        inline FwdPairPtrIterator(const FwdPairPtrIterator& it);
#line 212
        inline FwdPairPtrIterator(const _1 *kit, _2 **vit);
#line 209
        inline bool operator!= (const FwdPairPtrIterator& it) const;
#line 185
        inline FwdPairPtrIterator < _1, _2 > & operator++ ();
#line 187
        inline void operator+= (int i);
#line 186
        inline void operator-- (int i);
#line 184
        inline void operator= (const FwdPairPtrIterator& it);
#line 213
        inline _2& GetValue() const;
        
#line 208
        inline const _1& GetKey() const;
    };
    
    template < class _1 >
    class FwdPtrIterator
    {
#line 152
        _1 **kit;
        
    public:
#line 127
        inline FwdPtrIterator();
#line 153
        inline FwdPtrIterator(_1 **kit);
#line 128
        inline FwdPtrIterator(const FwdPtrIterator& it);
#line 165
        inline bool operator!= (const FwdPtrIterator& it) const;
#line 164
        inline _1& operator()() const;
#line 163
        inline _1& operator*() const;
#line 130
        inline FwdPtrIterator < _1 > & operator++ ();
#line 132
        inline void operator+= (int i);
#line 131
        inline void operator-- (int i);
#line 161
        inline _1 *operator-> () const;
#line 129
        inline void operator= (const FwdPtrIterator& it);
#line 162
        inline operator _1 * () const;
#line 154
        inline _1 *Get() const;
        inline _1 *& Ref();
    };
    
    namespace Memory
    {
#line 49
        void *Alloc(int sz);
#line 51
        int Compare(const void *m1, const void *m2, int sz);
        void *Copy(void *dest, const void *src, int sz);
#line 50
        void Free(void *ptr);
#line 53
        void *Move(void *dest, const void *src, int sz);
        void Set(void *dest, int byte_value, int sz);
        int StringCompare(const char *a, const char *b);
    };
    
    struct MemoryLimitExc
    {
#line 115
        const char *msg;
        
#line 116
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
    
#line 43
    inline bool FitsInInt64(double x)
    {
#line 44
        return x >= - 9223372036854775808.0 && x < 9223372036854775808.0;
    };
    
#line 564
    inline bool IsNull(const int16& v)
    {
#line 564
        return v == 0;
    };
    
#line 565
    inline bool IsNull(const int32& v)
    {
#line 565
        return v == 0;
    };
    
#line 566
    inline bool IsNull(const int64& v)
    {
#line 566
        return v == 0;
    };
    
#line 563
    inline bool IsNull(const int8& v)
    {
#line 563
        return v == 0;
    };
    
#line 568
    inline bool IsNull(const uint16& v)
    {
#line 568
        return v == 0;
    };
    
#line 569
    inline bool IsNull(const uint32& v)
    {
#line 569
        return v == 0;
    };
    
#line 570
    inline bool IsNull(const uint64& v)
    {
#line 570
        return v == 0;
    };
    
#line 567
    inline bool IsNull(const uint8& v)
    {
#line 567
        return v == 0;
    };
    
#line 561
    template < class _1 >
    inline bool IsNull(const _1& o)
    {
#line 561
        return o.IsNull();
    };
    
#line 562
    inline bool IsNull(const bool& v)
    {
#line 562
        return v == false;
    };
    
#line 572
    inline bool IsNull(const double& v)
    {
#line 572
        return v == 0.0;
    };
    
#line 571
    inline bool IsNull(const float& v)
    {
#line 571
        return v == 0.0f;
    };
    
#line 534
    template < class _1 >
    inline int NumberCompare__(const _1& a, const _1& b)
    {
        if (a < b)
#line 537
            return - 1;
        if (a > b)
#line 538
            return 1;
        return 0;
    };
    
#line 554
    inline int SgnCompare(const int64& a, const int64& b)
    {
#line 554
        return NumberCompare__ < int64 > (a, b);
    };
    
#line 555
    inline int SgnCompare(const uint64& a, const uint64& b)
    {
#line 555
        return NumberCompare__ < uint64 > (a, b);
    };
    
#line 542
    template < class _1 >
    inline int SgnCompare(const _1& a, const _1& b)
    {
#line 542
        return a.Compare(b);
    };
    
#line 553
    inline int SgnCompare(const bool& a, const bool& b)
    {
#line 553
        return NumberCompare__ < bool > (a, b);
    };
    
#line 544
    inline int SgnCompare(const char& a, const char& b)
    {
#line 544
        return NumberCompare__ < char > (a, b);
    };
    
#line 557
    inline int SgnCompare(const double& a, const double& b)
    {
#line 557
        return NumberCompare__ < double > (a, b);
    };
    
#line 556
    inline int SgnCompare(const float& a, const float& b)
    {
#line 556
        return NumberCompare__ < float > (a, b);
    };
    
#line 549
    inline int SgnCompare(const int& a, const int& b)
    {
#line 549
        return NumberCompare__ < int > (a, b);
    };
    
#line 551
    inline int SgnCompare(const long& a, const long& b)
    {
#line 551
        return NumberCompare__ < long > (a, b);
    };
    
#line 547
    inline int SgnCompare(const short& a, const short& b)
    {
#line 547
        return NumberCompare__ < short > (a, b);
    };
    
#line 545
    inline int SgnCompare(const signed char& a, const signed char& b)
    {
#line 545
        return NumberCompare__ < char > (a, b);
    };
    
#line 546
    inline int SgnCompare(const unsigned char& a, const unsigned char& b)
    {
#line 546
        return NumberCompare__ < unsigned char > (a, b);
    };
    
#line 550
    inline int SgnCompare(const unsigned int& a, const unsigned int& b)
    {
#line 550
        return NumberCompare__ < unsigned int > (a, b);
    };
    
#line 552
    inline int SgnCompare(const unsigned long& a, const unsigned long& b)
    {
#line 552
        return NumberCompare__ < unsigned long > (a, b);
    };
    
#line 548
    inline int SgnCompare(const unsigned short& a, const unsigned short& b)
    {
#line 548
        return NumberCompare__ < unsigned short > (a, b);
    };
    
#line 127
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator() {};
    
#line 158
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator(_1 *kit)
    :
        kit(kit)
    {};
    
#line 128
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator(const BwdIterator& it)
    {
#line 128
        *this = it;
    };
    
#line 165
    template < class _1 >
    inline bool BwdIterator < _1 >::operator!= (const BwdIterator& it) const
    {
#line 165
        return it.kit != kit;
    };
    
#line 164
    template < class _1 >
    inline _1& BwdIterator < _1 >::operator()() const
    {
#line 164
        return *Get();
    };
    
#line 163
    template < class _1 >
    inline _1& BwdIterator < _1 >::operator*() const
    {
#line 163
        return *Get();
    };
    
#line 130
    template < class _1 >
    inline BwdIterator < _1 > & BwdIterator < _1 >::operator++ ()
    {
#line 130
        kit += -1;
#line 130
        return *this;
    };
    
#line 132
    template < class _1 >
    inline void BwdIterator < _1 >::operator+= (int i)
    {
#line 132
        kit += i;
    };
    
#line 131
    template < class _1 >
    inline void BwdIterator < _1 >::operator-- (int i)
    {
#line 131
        kit -= -1;
    };
    
#line 161
    template < class _1 >
    inline _1 *BwdIterator < _1 >::operator-> () const
    {
#line 161
        return Get();
    };
    
#line 129
    template < class _1 >
    inline void BwdIterator < _1 >::operator= (const BwdIterator& it)
    {
#line 129
        kit = it.kit;
    };
    
#line 162
    template < class _1 >
    inline BwdIterator < _1 >::operator _1 * () const
    {
#line 162
        return Get();
    };
    
#line 159
    template < class _1 >
    inline _1 *BwdIterator < _1 >::Get() const
    {
#line 159
        return kit;
    };
    
#line 182
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 >::BwdPairIterator() {};
    
#line 183
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 >::BwdPairIterator(const BwdPairIterator& it)
    {
#line 183
        *this = it;
    };
    
#line 217
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 >::BwdPairIterator(const _1 *kit, _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 209
    template < class _1, class _2 >
    inline bool BwdPairIterator < _1, _2 >::operator!= (const BwdPairIterator& it) const
    {
#line 209
        return it.kit != kit;
    };
    
#line 185
    template < class _1, class _2 >
    inline BwdPairIterator < _1, _2 > & BwdPairIterator < _1, _2 >::operator++ ()
    {
#line 185
        kit += -1;
#line 185
        vit += -1;
#line 185
        return *this;
    };
    
#line 187
    template < class _1, class _2 >
    inline void BwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 187
        kit += i;
#line 187
        vit += i;
    };
    
#line 186
    template < class _1, class _2 >
    inline void BwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 186
        kit -= -1;
#line 186
        vit -= -1;
    };
    
#line 184
    template < class _1, class _2 >
    inline void BwdPairIterator < _1, _2 >::operator= (const BwdPairIterator& it)
    {
#line 184
        kit = it.kit;
#line 184
        vit = it.vit;
    };
    
#line 208
    template < class _1, class _2 >
    inline const _1& BwdPairIterator < _1, _2 >::GetKey() const
    {
#line 208
        return *kit;
    };
    
#line 218
    template < class _1, class _2 >
    inline _2& BwdPairIterator < _1, _2 >::GetValue() const
    {
#line 218
        return *vit;
    };
    
#line 182
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 >::BwdPairPtrIterator() {};
    
#line 183
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 >::BwdPairPtrIterator(const BwdPairPtrIterator& it)
    {
#line 183
        *this = it;
    };
    
#line 212
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 >::BwdPairPtrIterator(const _1 *kit, _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 209
    template < class _1, class _2 >
    inline bool BwdPairPtrIterator < _1, _2 >::operator!= (const BwdPairPtrIterator& it) const
    {
#line 209
        return it.kit != kit;
    };
    
#line 185
    template < class _1, class _2 >
    inline BwdPairPtrIterator < _1, _2 > & BwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 185
        kit += -1;
#line 185
        vit += -1;
#line 185
        return *this;
    };
    
#line 187
    template < class _1, class _2 >
    inline void BwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 187
        kit += i;
#line 187
        vit += i;
    };
    
#line 186
    template < class _1, class _2 >
    inline void BwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 186
        kit -= -1;
#line 186
        vit -= -1;
    };
    
#line 184
    template < class _1, class _2 >
    inline void BwdPairPtrIterator < _1, _2 >::operator= (const BwdPairPtrIterator& it)
    {
#line 184
        kit = it.kit;
#line 184
        vit = it.vit;
    };
    
#line 208
    template < class _1, class _2 >
    inline const _1& BwdPairPtrIterator < _1, _2 >::GetKey() const
    {
#line 208
        return *kit;
    };
    
#line 213
    template < class _1, class _2 >
    inline _2& BwdPairPtrIterator < _1, _2 >::GetValue() const
    {
#line 213
        return **vit;
    };
    
#line 127
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator() {};
    
#line 153
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator(_1 **kit)
    :
        kit(kit)
    {};
    
#line 128
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator(const BwdPtrIterator& it)
    {
#line 128
        *this = it;
    };
    
#line 165
    template < class _1 >
    inline bool BwdPtrIterator < _1 >::operator!= (const BwdPtrIterator& it) const
    {
#line 165
        return it.kit != kit;
    };
    
#line 164
    template < class _1 >
    inline _1& BwdPtrIterator < _1 >::operator()() const
    {
#line 164
        return *Get();
    };
    
#line 163
    template < class _1 >
    inline _1& BwdPtrIterator < _1 >::operator*() const
    {
#line 163
        return *Get();
    };
    
#line 130
    template < class _1 >
    inline BwdPtrIterator < _1 > & BwdPtrIterator < _1 >::operator++ ()
    {
#line 130
        kit += -1;
#line 130
        return *this;
    };
    
#line 132
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator+= (int i)
    {
#line 132
        kit += i;
    };
    
#line 131
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator-- (int i)
    {
#line 131
        kit -= -1;
    };
    
#line 161
    template < class _1 >
    inline _1 *BwdPtrIterator < _1 >::operator-> () const
    {
#line 161
        return Get();
    };
    
#line 129
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator= (const BwdPtrIterator& it)
    {
#line 129
        kit = it.kit;
    };
    
#line 162
    template < class _1 >
    inline BwdPtrIterator < _1 >::operator _1 * () const
    {
#line 162
        return Get();
    };
    
#line 154
    template < class _1 >
    inline _1 *BwdPtrIterator < _1 >::Get() const
    {
#line 154
        return *kit;
    };
    
#line 155
    template < class _1 >
    inline _1 *& BwdPtrIterator < _1 >::Ref()
    {
#line 155
        return *kit;
    };
    
#line 127
    template < class _1 >
    inline ConstBwdIterator < _1 >::ConstBwdIterator() {};
    
#line 128
    template < class _1 >
    inline ConstBwdIterator < _1 >::ConstBwdIterator(const ConstBwdIterator& it)
    {
#line 128
        *this = it;
    };
    
#line 142
    template < class _1 >
    inline ConstBwdIterator < _1 >::ConstBwdIterator(const _1 *kit)
    :
        kit(kit)
    {};
    
#line 149
    template < class _1 >
    inline bool ConstBwdIterator < _1 >::operator!= (const ConstBwdIterator& it) const
    {
#line 149
        return it.kit != kit;
    };
    
#line 148
    template < class _1 >
    inline const _1& ConstBwdIterator < _1 >::operator()() const
    {
#line 148
        return *Get();
    };
    
#line 147
    template < class _1 >
    inline const _1& ConstBwdIterator < _1 >::operator*() const
    {
#line 147
        return *Get();
    };
    
#line 130
    template < class _1 >
    inline ConstBwdIterator < _1 > & ConstBwdIterator < _1 >::operator++ ()
    {
#line 130
        kit += -1;
#line 130
        return *this;
    };
    
#line 132
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator+= (int i)
    {
#line 132
        kit += i;
    };
    
#line 131
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator-- (int i)
    {
#line 131
        kit -= -1;
    };
    
#line 145
    template < class _1 >
    inline const _1 *ConstBwdIterator < _1 >::operator-> () const
    {
#line 145
        return Get();
    };
    
#line 129
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator= (const ConstBwdIterator& it)
    {
#line 129
        kit = it.kit;
    };
    
#line 146
    template < class _1 >
    inline ConstBwdIterator < _1 >::operator ConstK * () const
    {
#line 146
        return Get();
    };
    
#line 143
    template < class _1 >
    inline const _1 *ConstBwdIterator < _1 >::Get() const
    {
#line 143
        return kit;
    };
    
#line 182
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 >::ConstBwdPairIterator() {};
    
#line 183
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 >::ConstBwdPairIterator(const ConstBwdPairIterator& it)
    {
#line 183
        *this = it;
    };
    
#line 202
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 >::ConstBwdPairIterator(const _1 *kit, const _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 194
    template < class _1, class _2 >
    inline bool ConstBwdPairIterator < _1, _2 >::operator!= (const ConstBwdPairIterator& it) const
    {
#line 194
        return it.kit != kit;
    };
    
#line 185
    template < class _1, class _2 >
    inline ConstBwdPairIterator < _1, _2 > & ConstBwdPairIterator < _1, _2 >::operator++ ()
    {
#line 185
        kit += -1;
#line 185
        vit += -1;
#line 185
        return *this;
    };
    
#line 187
    template < class _1, class _2 >
    inline void ConstBwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 187
        kit += i;
#line 187
        vit += i;
    };
    
#line 186
    template < class _1, class _2 >
    inline void ConstBwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 186
        kit -= -1;
#line 186
        vit -= -1;
    };
    
#line 184
    template < class _1, class _2 >
    inline void ConstBwdPairIterator < _1, _2 >::operator= (const ConstBwdPairIterator& it)
    {
#line 184
        kit = it.kit;
#line 184
        vit = it.vit;
    };
    
#line 193
    template < class _1, class _2 >
    inline const _1& ConstBwdPairIterator < _1, _2 >::GetKey() const
    {
#line 193
        return *kit;
    };
    
#line 203
    template < class _1, class _2 >
    inline const _2& ConstBwdPairIterator < _1, _2 >::GetValue() const
    {
#line 203
        return **vit;
    };
    
#line 182
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 >::ConstBwdPairPtrIterator() {};
    
#line 183
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 >::ConstBwdPairPtrIterator(const ConstBwdPairPtrIterator& it)
    {
#line 183
        *this = it;
    };
    
#line 197
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 >::ConstBwdPairPtrIterator(const _1 *kit, const _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 194
    template < class _1, class _2 >
    inline bool ConstBwdPairPtrIterator < _1, _2 >::operator!= (const ConstBwdPairPtrIterator& it) const
    {
#line 194
        return it.kit != kit;
    };
    
#line 185
    template < class _1, class _2 >
    inline ConstBwdPairPtrIterator < _1, _2 > & ConstBwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 185
        kit += -1;
#line 185
        vit += -1;
#line 185
        return *this;
    };
    
#line 187
    template < class _1, class _2 >
    inline void ConstBwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 187
        kit += i;
#line 187
        vit += i;
    };
    
#line 186
    template < class _1, class _2 >
    inline void ConstBwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 186
        kit -= -1;
#line 186
        vit -= -1;
    };
    
#line 184
    template < class _1, class _2 >
    inline void ConstBwdPairPtrIterator < _1, _2 >::operator= (const ConstBwdPairPtrIterator& it)
    {
#line 184
        kit = it.kit;
#line 184
        vit = it.vit;
    };
    
#line 193
    template < class _1, class _2 >
    inline const _1& ConstBwdPairPtrIterator < _1, _2 >::GetKey() const
    {
#line 193
        return *kit;
    };
    
#line 198
    template < class _1, class _2 >
    inline const _2& ConstBwdPairPtrIterator < _1, _2 >::GetValue() const
    {
#line 198
        return *vit;
    };
    
#line 127
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator() {};
    
#line 128
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator(const ConstBwdPtrIterator& it)
    {
#line 128
        *this = it;
    };
    
#line 138
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator(const _1 **kit)
    :
        kit(kit)
    {};
    
#line 149
    template < class _1 >
    inline bool ConstBwdPtrIterator < _1 >::operator!= (const ConstBwdPtrIterator& it) const
    {
#line 149
        return it.kit != kit;
    };
    
#line 148
    template < class _1 >
    inline const _1& ConstBwdPtrIterator < _1 >::operator()() const
    {
#line 148
        return *Get();
    };
    
#line 147
    template < class _1 >
    inline const _1& ConstBwdPtrIterator < _1 >::operator*() const
    {
#line 147
        return *Get();
    };
    
#line 130
    template < class _1 >
    inline ConstBwdPtrIterator < _1 > & ConstBwdPtrIterator < _1 >::operator++ ()
    {
#line 130
        kit += -1;
#line 130
        return *this;
    };
    
#line 132
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator+= (int i)
    {
#line 132
        kit += i;
    };
    
#line 131
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator-- (int i)
    {
#line 131
        kit -= -1;
    };
    
#line 145
    template < class _1 >
    inline const _1 *ConstBwdPtrIterator < _1 >::operator-> () const
    {
#line 145
        return Get();
    };
    
#line 129
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator= (const ConstBwdPtrIterator& it)
    {
#line 129
        kit = it.kit;
    };
    
#line 146
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::operator ConstK * () const
    {
#line 146
        return Get();
    };
    
#line 139
    template < class _1 >
    inline const _1 *ConstBwdPtrIterator < _1 >::Get() const
    {
#line 139
        return *kit;
    };
    
#line 127
    template < class _1 >
    inline ConstFwdIterator < _1 >::ConstFwdIterator() {};
    
#line 128
    template < class _1 >
    inline ConstFwdIterator < _1 >::ConstFwdIterator(const ConstFwdIterator& it)
    {
#line 128
        *this = it;
    };
    
#line 142
    template < class _1 >
    inline ConstFwdIterator < _1 >::ConstFwdIterator(const _1 *kit)
    :
        kit(kit)
    {};
    
#line 149
    template < class _1 >
    inline bool ConstFwdIterator < _1 >::operator!= (const ConstFwdIterator& it) const
    {
#line 149
        return it.kit != kit;
    };
    
#line 148
    template < class _1 >
    inline const _1& ConstFwdIterator < _1 >::operator()() const
    {
#line 148
        return *Get();
    };
    
#line 147
    template < class _1 >
    inline const _1& ConstFwdIterator < _1 >::operator*() const
    {
#line 147
        return *Get();
    };
    
#line 130
    template < class _1 >
    inline ConstFwdIterator < _1 > & ConstFwdIterator < _1 >::operator++ ()
    {
#line 130
        kit += 1;
#line 130
        return *this;
    };
    
#line 132
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator+= (int i)
    {
#line 132
        kit += i;
    };
    
#line 131
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator-- (int i)
    {
#line 131
        kit -= 1;
    };
    
#line 145
    template < class _1 >
    inline const _1 *ConstFwdIterator < _1 >::operator-> () const
    {
#line 145
        return Get();
    };
    
#line 129
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator= (const ConstFwdIterator& it)
    {
#line 129
        kit = it.kit;
    };
    
#line 146
    template < class _1 >
    inline ConstFwdIterator < _1 >::operator ConstK * () const
    {
#line 146
        return Get();
    };
    
#line 143
    template < class _1 >
    inline const _1 *ConstFwdIterator < _1 >::Get() const
    {
#line 143
        return kit;
    };
    
#line 182
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 >::ConstFwdPairIterator() {};
    
#line 183
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 >::ConstFwdPairIterator(const ConstFwdPairIterator& it)
    {
#line 183
        *this = it;
    };
    
#line 202
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 >::ConstFwdPairIterator(const _1 *kit, const _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 194
    template < class _1, class _2 >
    inline bool ConstFwdPairIterator < _1, _2 >::operator!= (const ConstFwdPairIterator& it) const
    {
#line 194
        return it.kit != kit;
    };
    
#line 185
    template < class _1, class _2 >
    inline ConstFwdPairIterator < _1, _2 > & ConstFwdPairIterator < _1, _2 >::operator++ ()
    {
#line 185
        kit += 1;
#line 185
        vit += 1;
#line 185
        return *this;
    };
    
#line 187
    template < class _1, class _2 >
    inline void ConstFwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 187
        kit += i;
#line 187
        vit += i;
    };
    
#line 186
    template < class _1, class _2 >
    inline void ConstFwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 186
        kit -= 1;
#line 186
        vit -= 1;
    };
    
#line 184
    template < class _1, class _2 >
    inline void ConstFwdPairIterator < _1, _2 >::operator= (const ConstFwdPairIterator& it)
    {
#line 184
        kit = it.kit;
#line 184
        vit = it.vit;
    };
    
#line 193
    template < class _1, class _2 >
    inline const _1& ConstFwdPairIterator < _1, _2 >::GetKey() const
    {
#line 193
        return *kit;
    };
    
#line 203
    template < class _1, class _2 >
    inline const _2& ConstFwdPairIterator < _1, _2 >::GetValue() const
    {
#line 203
        return **vit;
    };
    
#line 182
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 >::ConstFwdPairPtrIterator() {};
    
#line 183
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 >::ConstFwdPairPtrIterator(const ConstFwdPairPtrIterator& it)
    {
#line 183
        *this = it;
    };
    
#line 197
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 >::ConstFwdPairPtrIterator(const _1 *kit, const _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 194
    template < class _1, class _2 >
    inline bool ConstFwdPairPtrIterator < _1, _2 >::operator!= (const ConstFwdPairPtrIterator& it) const
    {
#line 194
        return it.kit != kit;
    };
    
#line 185
    template < class _1, class _2 >
    inline ConstFwdPairPtrIterator < _1, _2 > & ConstFwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 185
        kit += 1;
#line 185
        vit += 1;
#line 185
        return *this;
    };
    
#line 187
    template < class _1, class _2 >
    inline void ConstFwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 187
        kit += i;
#line 187
        vit += i;
    };
    
#line 186
    template < class _1, class _2 >
    inline void ConstFwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 186
        kit -= 1;
#line 186
        vit -= 1;
    };
    
#line 184
    template < class _1, class _2 >
    inline void ConstFwdPairPtrIterator < _1, _2 >::operator= (const ConstFwdPairPtrIterator& it)
    {
#line 184
        kit = it.kit;
#line 184
        vit = it.vit;
    };
    
#line 193
    template < class _1, class _2 >
    inline const _1& ConstFwdPairPtrIterator < _1, _2 >::GetKey() const
    {
#line 193
        return *kit;
    };
    
#line 198
    template < class _1, class _2 >
    inline const _2& ConstFwdPairPtrIterator < _1, _2 >::GetValue() const
    {
#line 198
        return *vit;
    };
    
#line 127
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator() {};
    
#line 128
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator(const ConstFwdPtrIterator& it)
    {
#line 128
        *this = it;
    };
    
#line 138
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator(const _1 **kit)
    :
        kit(kit)
    {};
    
#line 149
    template < class _1 >
    inline bool ConstFwdPtrIterator < _1 >::operator!= (const ConstFwdPtrIterator& it) const
    {
#line 149
        return it.kit != kit;
    };
    
#line 148
    template < class _1 >
    inline const _1& ConstFwdPtrIterator < _1 >::operator()() const
    {
#line 148
        return *Get();
    };
    
#line 147
    template < class _1 >
    inline const _1& ConstFwdPtrIterator < _1 >::operator*() const
    {
#line 147
        return *Get();
    };
    
#line 130
    template < class _1 >
    inline ConstFwdPtrIterator < _1 > & ConstFwdPtrIterator < _1 >::operator++ ()
    {
#line 130
        kit += 1;
#line 130
        return *this;
    };
    
#line 132
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator+= (int i)
    {
#line 132
        kit += i;
    };
    
#line 131
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator-- (int i)
    {
#line 131
        kit -= 1;
    };
    
#line 145
    template < class _1 >
    inline const _1 *ConstFwdPtrIterator < _1 >::operator-> () const
    {
#line 145
        return Get();
    };
    
#line 129
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator= (const ConstFwdPtrIterator& it)
    {
#line 129
        kit = it.kit;
    };
    
#line 146
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::operator ConstK * () const
    {
#line 146
        return Get();
    };
    
#line 139
    template < class _1 >
    inline const _1 *ConstFwdPtrIterator < _1 >::Get() const
    {
#line 139
        return *kit;
    };
    
#line 267
    template < class _1 >
    inline DynArray < _1 >::DynArray()
    :
        data(0),
        reserved(0),
        count(0)
    {};
    
#line 268
    template < class _1 >
    inline DynArray < _1 >::DynArray(const DynArray& v)
    :
        data(0),
        reserved(0),
        count(0)
    {
#line 268
        *this <<= v;
    };
    
#line 269
    template < class _1 >
    inline DynArray < _1 >::DynArray(int i)
    :
        data(0),
        reserved(0),
        count(0)
    {
#line 269
        SetCount(i);
    };
    
#line 270
    template < class _1 >
    inline DynArray < _1 >::~DynArray()
    {
#line 271
        Clear();
        return;
        ;
    };
    
#line 323
    template < class _1 >
    inline DynArray < _1 > & DynArray < _1 >::operator<< (const _1& v)
    {
#line 323
        Add(v);
#line 323
        return *this;
    };
    
#line 356
    template < class _1 >
    inline void DynArray < _1 >::operator<<= (const DynArray& a)
    {
#line 357
        SetCount(0);
        Reserve(a.GetCount());
        for (int i = 0; i < a.GetCount(); i ++ )
            new (&data[i])_1(a[i]);
        count = a.GetCount();
    };
    
#line 410
    template < class _1 >
    inline _1& DynArray < _1 >::operator[](int i)
    {
#line 410
        return At(i);
    };
    
#line 411
    template < class _1 >
    inline const _1& DynArray < _1 >::operator[](int i) const
    {
#line 411
        return At(i);
    };
    
#line 301
    template < class _1 >
    inline _1& DynArray < _1 >::Add()
    {
#line 302
        if (count + 1 > reserved)
#line 302
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        new (&data[count])_1;
        return data[count ++ ];
    };
    
#line 308
    template < class _1 >
    inline _1& DynArray < _1 >::Add(const _1& v)
    {
#line 309
        if (count + 1 > reserved)
#line 309
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        _1 * ptr = &data[count];
        new (ptr)_1(v);
        return data[count ++ ];
    };
    
#line 363
    template < class _1 >
    inline void DynArray < _1 >::Append(const DynArray& a)
    {
#line 364
        int begin = count;
        int new_count = count + a.GetCount();
        Reserve(new_count);
        for (int i = begin, j = 0; i < new_count; i ++ , j ++ )
            new (&data[i])_1(a[j]);
        count = new_count;
    };
    
#line 371
    template < class _1 >
    inline void DynArray < _1 >::Append(const DynArray& a, int i, int n)
    {
        {
#line 372
            if (!(i >= 0 && i < a.GetCount() && n >= 0 && i + n <= a.GetCount()))
            {
#line 372
                Lang::SysBreak("Assertion failed: i >= 0 && i < a.GetCount() && n >= 0 && i+n <= a.GetCount()");
            }
        }
#line 373
        ;
#line 373
        if (n <= 0)
#line 373
            return;
        i = Algorithm::Maximum(0, Algorithm::Minimum(a.GetCount() - 1, i));
        if (i >= a.GetCount())
#line 375
            return;
        n = Algorithm::Minimum(n, a.GetCount() - i);
        int begin = count;
        int new_count = count + n;
        Reserve(new_count);
        for (int k = begin, j = i; k < new_count; k ++ , j ++ )
            new (&data[k])_1(a[j]);
        count = new_count;
    };
    
#line 401
    template < class _1 >
    inline _1& DynArray < _1 >::At(int i)
    {
        {
#line 402
            if (!(i >= 0 && i < count))
            {
#line 402
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 403
        ;
#line 403
        return *(data + i);
    };
    
#line 405
    template < class _1 >
    inline const _1& DynArray < _1 >::At(int i) const
    {
        {
#line 406
            if (!(i >= 0 && i < count))
            {
#line 406
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 407
        ;
#line 407
        return *(data + i);
    };
    
#line 283
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::Begin() const
    {
#line 283
        return ConstIterator(data);
    };
    
#line 281
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::Begin()
    {
#line 281
        return Iterator(data);
    };
    
#line 518
    template < class _1 >
    inline void DynArray < _1 >::Clear()
    {
#line 519
        if (!reserved)
#line 519
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
    
#line 284
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::End() const
    {
#line 284
        return ConstIterator(data + count);
    };
    
#line 282
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::End()
    {
#line 282
        return Iterator(data + count);
    };
    
#line 298
    template < class _1 >
    inline _1 *DynArray < _1 >::Get() const
    {
#line 298
        return data;
    };
    
#line 397
    template < class _1 >
    inline int DynArray < _1 >::GetCount() const
    {
#line 397
        return count;
    };
    
#line 299
    template < class _1 >
    inline _1 *DynArray < _1 >::GetEnd() const
    {
#line 299
        return data + count;
    };
    
#line 398
    template < class _1 >
    inline int DynArray < _1 >::GetReserved() const
    {
#line 398
        return reserved;
    };
    
#line 384
    template < class _1 >
    inline void DynArray < _1 >::IncreaseReserve(int more_reserved)
    {
#line 384
        Reserve(GetCount() + more_reserved);
    };
    
#line 244
    template < class _1 >
    inline void DynArray < _1 >::IncreaseReserved()
    {
#line 245
        uint64 new_reserved = 1;
        while (new_reserved <= reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2000000000)
            new_reserved = 2000000000;
        Reserve((int) new_reserved);
    };
    
#line 479
    template < class _1 >
    inline _1& DynArray < _1 >::Insert(int i)
    {
#line 480
        if (count + 1 > reserved)
#line 480
            IncreaseReserved();
        if (count + 1 > reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        int tail = this -> count - i;
        if (tail > 0)
            Memory::Move(data + i + 1, data + i, tail * sizeof (_1));
        new (&data[i])_1;
        count ++ ;
        return data[i];
    };
    
#line 490
    template < class _1 >
    inline _1& DynArray < _1 >::Insert(int i, ConstK& key)
    {
#line 491
        if (count + 1 > reserved)
#line 491
            IncreaseReserved();
        if (count + 1 > reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        int tail = this -> count - i;
        if (tail > 0)
            Memory::Move(data + i + 1, data + i, tail * sizeof (_1));
        new (&data[i])_1(key);
        count ++ ;
        return data[i];
    };
    
#line 467
    template < class _1 >
    inline void DynArray < _1 >::InsertN(int i, int n)
    {
#line 468
        if (n <= 0)
#line 468
            return;
        if (count + n > reserved)
#line 469
            Reserve(count + n);
        if (count + n > reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        int tail = this -> count - i;
        if (tail > 0)
            Memory::Move(data + i + 1, data + i, tail * sizeof (_1));
        for (int j = 0; j < n; j ++ )
            new (&data[i + j])_1;
        count += n;
    };
    
#line 399
    template < class _1 >
    inline bool DynArray < _1 >::IsEmpty() const
    {
#line 399
        return GetCount() == 0;
    };
    
#line 253
    template < class _1 >
    inline void DynArray < _1 >::Pick0(DynArray& v)
    {
#line 253
        data = v.data;
#line 253
        v.data = 0;
#line 253
        reserved = v.reserved;
#line 253
        v.reserved = 0;
#line 253
        count = v.count;
#line 253
        v.count = 0;
    };
    
#line 504
    template < class _1 >
    inline _1 DynArray < _1 >::Pop()
    {
        {
#line 505
            if (!(GetCount() > 0))
            {
#line 505
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 506
        ;
#line 506
        int i = count - 1;
        _1 ret(data[i]);
        Destruct(data[i]);
        count -- ;
        return ret;
    };
    
#line 289
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::RBegin()
    {
#line 289
        return RIterator(data + count - 1);
    };
    
#line 291
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::RBegin() const
    {
#line 291
        return ConstRIterator(data + count - 1);
    };
    
#line 290
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::REnd()
    {
#line 290
        return RIterator(data - 1);
    };
    
#line 292
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::REnd() const
    {
#line 292
        return ConstRIterator(data - 1);
    };
    
#line 446
    template < class _1 >
    inline void DynArray < _1 >::Remove(const DynArray < int > & sorted_list)
    {
#line 446
        Remove(sorted_list.Begin(), sorted_list.GetCount());
    };
    
#line 428
    template < class _1 >
    inline void DynArray < _1 >::Remove(const Iterator& it)
    {
#line 429
        _1 * begin = data;
        _1 * cur = it.Get();
        int pos = cur - begin;
        Remove(pos);
    };
    
    template < class _1 >
    inline void DynArray < _1 >::Remove(const Iterator& it, const Iterator& end)
    {
#line 436
        _1 * begin = data;
        _1 * cur = it.Get();
        _1 * cur_end = end.Get();
        int pos0 = cur - begin;
        int pos1 = cur_end - begin;
        int len = pos1 - pos0;
        if (!len)
#line 442
            return;
        Remove(pos0, len);
    };
    
#line 447
    template < class _1 >
    inline void DynArray < _1 >::Remove(const int *sorted_list, int n)
    {
#line 448
        if (!n)
#line 448
            return;
        int pos = *sorted_list;
        int npos = pos;
        for (;;)
            {
                {
#line 452
                    if (!(pos < count))
                    {
#line 452
                        Lang::SysBreak("Assertion failed: pos < count");
                    }
                }
#line 453
                ;
#line 453
                if (pos == *sorted_list)
                {
#line 454
                    Destruct(*(data + pos));
                    pos ++ ;
                    sorted_list ++ ;
                    if (-- n == 0)
#line 457
                        break;
                    
                    {
#line 458
                        if (!(*sorted_list >= pos))
                        {
#line 458
                            Lang::SysBreak("Assertion failed: *sorted_list >= pos");
                        }
                    }
#line 459
                    ;
                }
                else
#line 461
                    Memory::Copy(data + npos ++ , data + pos ++ , sizeof (_1));
            }
        while (pos < count)
            Memory::Copy(data + npos ++ , data + pos ++ , sizeof (_1));
        count = npos;
    };
    
#line 413
    template < class _1 >
    inline void DynArray < _1 >::Remove(int i)
    {
        {
#line 414
            if (!(i >= 0 && i < count))
            {
#line 414
                Lang::SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 415
        ;
#line 415
        int tail = count - (i + 1);
        if (tail > 0)
            Memory::Move(data + i, data + i + 1, tail * sizeof (_1));
        count -- ;
    };
    
#line 420
    template < class _1 >
    inline void DynArray < _1 >::Remove(int i, int count)
    {
        {
#line 421
            if (!(count > 0))
            {
#line 421
                Lang::SysBreak("Assertion failed: count > 0");
            }
        }
#line 422
        ;
        {
#line 422
            if (!(i >= 0 && i + count <= this -> count))
            {
#line 422
                Lang::SysBreak("Assertion failed: i >= 0 && i + count <= this->count");
            }
        }
#line 423
        ;
#line 423
        int tail = this -> count - (i + count);
        if (tail > 0)
            Memory::Move(data + i, data + i + count, tail * sizeof (_1));
        this -> count -= count;
    };
    
#line 513
    template < class _1 >
    inline void DynArray < _1 >::RemoveLast()
    {
        {
#line 514
            if (!(GetCount() > 0))
            {
#line 514
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 515
        ;
#line 515
        data[-- count].~K();
    };
    
#line 385
    template < class _1 >
    inline void DynArray < _1 >::Reserve(int new_reserved)
    {
#line 386
        if (new_reserved <= reserved || new_reserved <= 0)
            return;
        _1 * new_data = (_1 * ) Memory::Alloc(new_reserved * sizeof (_1));
        if (data)
        {
#line 390
            if (count > 0)
                Memory::Copy((void * ) new_data, (void * ) data, sizeof (_1) * count);
            Memory::Free(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
#line 325
    template < class _1 >
    inline void DynArray < _1 >::SetCount(int new_count)
    {
        {
#line 326
            if (!(new_count >= 0))
            {
#line 326
                Lang::SysBreak("Assertion failed: new_count >= 0");
            }
        }
#line 327
        ;
#line 327
        if (new_count < 0)
#line 327
            return;
        if (new_count > reserved)
#line 328
            Reserve(new_count);
        if (new_count == count)
#line 329
            return;
        if (new_count > count)
        {
#line 331
            for (int i = count; i < new_count; i ++ )
                new (&data[i])_1;
        }
        else
        {
#line 335
            for (int i = count - 1; i >= new_count; i -- )
                Destruct(data[i]);
        }
#line 339
        count = new_count;
    };
    
#line 341
    template < class _1 >
    inline void DynArray < _1 >::SetCount(int new_count, ConstK& value)
    {
        {
#line 342
            if (!(new_count >= 0))
            {
#line 342
                Lang::SysBreak("Assertion failed: new_count >= 0");
            }
        }
#line 343
        ;
#line 343
        if (new_count < 0)
#line 343
            return;
        if (new_count > reserved)
#line 344
            Reserve(new_count);
        if (new_count == count)
#line 345
            return;
        if (new_count > count)
        {
#line 347
            for (int i = count; i < new_count; i ++ )
                new (&data[i])_1(value);
        }
        else
        {
#line 351
            for (int i = count - 1; i >= new_count; i -- )
                Destruct(data[i]);
        }
        count = new_count;
    };
    
#line 502
    template < class _1 >
    inline _1& DynArray < _1 >::Top()
    {
        {
#line 502
            if (!(GetCount() > 0))
            {
#line 502
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 502
        ;
#line 502
        return data[count - 1];
    };
    
#line 287
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::begin() const
    {
#line 287
        return Begin();
    };
    
#line 285
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::begin()
    {
#line 285
        return Begin();
    };
    
    template < class _1 >
    inline Lang::ConstFwdIterator < _1 > DynArray < _1 >::end() const
    {
#line 288
        return End();
    };
    
#line 286
    template < class _1 >
    inline Lang::FwdIterator < _1 > DynArray < _1 >::end()
    {
#line 286
        return End();
    };
    
#line 293
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::rbegin()
    {
#line 293
        return RBegin();
    };
    
#line 295
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::rbegin() const
    {
#line 295
        return RBegin();
    };
    
#line 294
    template < class _1 >
    inline Lang::BwdIterator < _1 > DynArray < _1 >::rend()
    {
#line 294
        return REnd();
    };
    
#line 296
    template < class _1 >
    inline Lang::ConstBwdIterator < _1 > DynArray < _1 >::rend() const
    {
#line 296
        return REnd();
    };
    
#line 127
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator() {};
    
#line 158
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator(_1 *kit)
    :
        kit(kit)
    {};
    
#line 128
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator(const FwdIterator& it)
    {
#line 128
        *this = it;
    };
    
#line 165
    template < class _1 >
    inline bool FwdIterator < _1 >::operator!= (const FwdIterator& it) const
    {
#line 165
        return it.kit != kit;
    };
    
#line 164
    template < class _1 >
    inline _1& FwdIterator < _1 >::operator()() const
    {
#line 164
        return *Get();
    };
    
#line 163
    template < class _1 >
    inline _1& FwdIterator < _1 >::operator*() const
    {
#line 163
        return *Get();
    };
    
#line 130
    template < class _1 >
    inline FwdIterator < _1 > & FwdIterator < _1 >::operator++ ()
    {
#line 130
        kit += 1;
#line 130
        return *this;
    };
    
#line 132
    template < class _1 >
    inline void FwdIterator < _1 >::operator+= (int i)
    {
#line 132
        kit += i;
    };
    
#line 131
    template < class _1 >
    inline void FwdIterator < _1 >::operator-- (int i)
    {
#line 131
        kit -= 1;
    };
    
#line 161
    template < class _1 >
    inline _1 *FwdIterator < _1 >::operator-> () const
    {
#line 161
        return Get();
    };
    
#line 129
    template < class _1 >
    inline void FwdIterator < _1 >::operator= (const FwdIterator& it)
    {
#line 129
        kit = it.kit;
    };
    
#line 162
    template < class _1 >
    inline FwdIterator < _1 >::operator _1 * () const
    {
#line 162
        return Get();
    };
    
#line 159
    template < class _1 >
    inline _1 *FwdIterator < _1 >::Get() const
    {
#line 159
        return kit;
    };
    
#line 182
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 >::FwdPairIterator() {};
    
#line 183
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 >::FwdPairIterator(const FwdPairIterator& it)
    {
#line 183
        *this = it;
    };
    
#line 217
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 >::FwdPairIterator(const _1 *kit, _2 *vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 209
    template < class _1, class _2 >
    inline bool FwdPairIterator < _1, _2 >::operator!= (const FwdPairIterator& it) const
    {
#line 209
        return it.kit != kit;
    };
    
#line 185
    template < class _1, class _2 >
    inline FwdPairIterator < _1, _2 > & FwdPairIterator < _1, _2 >::operator++ ()
    {
#line 185
        kit += 1;
#line 185
        vit += 1;
#line 185
        return *this;
    };
    
#line 187
    template < class _1, class _2 >
    inline void FwdPairIterator < _1, _2 >::operator+= (int i)
    {
#line 187
        kit += i;
#line 187
        vit += i;
    };
    
#line 186
    template < class _1, class _2 >
    inline void FwdPairIterator < _1, _2 >::operator-- (int i)
    {
#line 186
        kit -= 1;
#line 186
        vit -= 1;
    };
    
#line 184
    template < class _1, class _2 >
    inline void FwdPairIterator < _1, _2 >::operator= (const FwdPairIterator& it)
    {
#line 184
        kit = it.kit;
#line 184
        vit = it.vit;
    };
    
#line 208
    template < class _1, class _2 >
    inline const _1& FwdPairIterator < _1, _2 >::GetKey() const
    {
#line 208
        return *kit;
    };
    
#line 218
    template < class _1, class _2 >
    inline _2& FwdPairIterator < _1, _2 >::GetValue() const
    {
#line 218
        return *vit;
    };
    
#line 182
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 >::FwdPairPtrIterator() {};
    
#line 183
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 >::FwdPairPtrIterator(const FwdPairPtrIterator& it)
    {
#line 183
        *this = it;
    };
    
#line 212
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 >::FwdPairPtrIterator(const _1 *kit, _2 **vit)
    :
        kit(kit),
        vit(vit)
    {};
    
#line 209
    template < class _1, class _2 >
    inline bool FwdPairPtrIterator < _1, _2 >::operator!= (const FwdPairPtrIterator& it) const
    {
#line 209
        return it.kit != kit;
    };
    
#line 185
    template < class _1, class _2 >
    inline FwdPairPtrIterator < _1, _2 > & FwdPairPtrIterator < _1, _2 >::operator++ ()
    {
#line 185
        kit += 1;
#line 185
        vit += 1;
#line 185
        return *this;
    };
    
#line 187
    template < class _1, class _2 >
    inline void FwdPairPtrIterator < _1, _2 >::operator+= (int i)
    {
#line 187
        kit += i;
#line 187
        vit += i;
    };
    
#line 186
    template < class _1, class _2 >
    inline void FwdPairPtrIterator < _1, _2 >::operator-- (int i)
    {
#line 186
        kit -= 1;
#line 186
        vit -= 1;
    };
    
#line 184
    template < class _1, class _2 >
    inline void FwdPairPtrIterator < _1, _2 >::operator= (const FwdPairPtrIterator& it)
    {
#line 184
        kit = it.kit;
#line 184
        vit = it.vit;
    };
    
#line 208
    template < class _1, class _2 >
    inline const _1& FwdPairPtrIterator < _1, _2 >::GetKey() const
    {
#line 208
        return *kit;
    };
    
#line 213
    template < class _1, class _2 >
    inline _2& FwdPairPtrIterator < _1, _2 >::GetValue() const
    {
#line 213
        return **vit;
    };
    
#line 127
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator() {};
    
#line 153
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator(_1 **kit)
    :
        kit(kit)
    {};
    
#line 128
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator(const FwdPtrIterator& it)
    {
#line 128
        *this = it;
    };
    
#line 165
    template < class _1 >
    inline bool FwdPtrIterator < _1 >::operator!= (const FwdPtrIterator& it) const
    {
#line 165
        return it.kit != kit;
    };
    
#line 164
    template < class _1 >
    inline _1& FwdPtrIterator < _1 >::operator()() const
    {
#line 164
        return *Get();
    };
    
#line 163
    template < class _1 >
    inline _1& FwdPtrIterator < _1 >::operator*() const
    {
#line 163
        return *Get();
    };
    
#line 130
    template < class _1 >
    inline FwdPtrIterator < _1 > & FwdPtrIterator < _1 >::operator++ ()
    {
#line 130
        kit += 1;
#line 130
        return *this;
    };
    
#line 132
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator+= (int i)
    {
#line 132
        kit += i;
    };
    
#line 131
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator-- (int i)
    {
#line 131
        kit -= 1;
    };
    
#line 161
    template < class _1 >
    inline _1 *FwdPtrIterator < _1 >::operator-> () const
    {
#line 161
        return Get();
    };
    
#line 129
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator= (const FwdPtrIterator& it)
    {
#line 129
        kit = it.kit;
    };
    
#line 162
    template < class _1 >
    inline FwdPtrIterator < _1 >::operator _1 * () const
    {
#line 162
        return Get();
    };
    
#line 154
    template < class _1 >
    inline _1 *FwdPtrIterator < _1 >::Get() const
    {
#line 154
        return *kit;
    };
    
#line 155
    template < class _1 >
    inline _1 *& FwdPtrIterator < _1 >::Ref()
    {
#line 155
        return *kit;
    };
    
#line 116
    inline MemoryLimitExc::MemoryLimitExc()
    :
        msg(0)
    {};
    
#line 117
    inline MemoryLimitExc::MemoryLimitExc(const char *s)
    :
        msg(s)
    {};
    
};

#endif
