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

#ifndef C_HXX
#define C_HXX

#include <new>

namespace C
{
#line 38 "../../src/Com/Lang.fog"
    int StringLength(const char *c, int max_len = 100000000);
    int StringLength(const short *c, int max_len = 100000000);
#line 36
    void SysBreak(const char *msg);
    
    struct AtomicBool
    {
#line 54
        AtomicBool();
        AtomicBool(bool b);
        AtomicBool(const AtomicBool& ai);
#line 58
        bool operator= (bool b);
#line 57
        operator bool();
    };
    
    struct AtomicFlag
    {
#line 44
        void Enter();
        void Leave();
        bool TryEnter();
    };
    
    struct AtomicInt
    {
#line 64
        AtomicInt();
#line 66
        AtomicInt(const AtomicInt& ai);
#line 65
        AtomicInt(int i);
#line 69
        int operator++ ();
#line 71
        int operator++ (int);
#line 70
        int operator-- ();
#line 72
        int operator-- (int);
#line 68
        int operator= (int i);
#line 67
        operator int() const;
    };
    
    template < class _1 >
    struct BwdIterator
    {
#line 147
        _1 *kit;
        
#line 128
        inline BwdIterator();
#line 148
        inline BwdIterator(_1 *kit);
#line 129
        BwdIterator(const BwdIterator& it);
#line 153
        inline bool operator!= (const BwdIterator& it) const;
        inline _1& operator()() const;
#line 152
        inline _1& operator*() const;
#line 131
        BwdIterator < _1 > & operator++ ();
#line 134
        inline void operator+= (int i);
#line 133
        void operator-- (int i);
#line 149
        inline _1 *operator-> () const;
#line 130
        inline void operator= (const BwdIterator& it);
#line 151
        inline operator _1 * () const;
#line 150
        inline _1 *Get() const;
    };
    
    template < class _1 >
    struct BwdPtrIterator
    {
#line 186
        _1 **kit;
        
#line 168
        inline BwdPtrIterator();
#line 187
        inline BwdPtrIterator(_1 **kit);
#line 169
        BwdPtrIterator(const BwdPtrIterator& it);
#line 192
        inline bool operator!= (const BwdPtrIterator& it) const;
        inline _1& operator()() const;
#line 191
        inline _1& operator*() const;
#line 171
        BwdPtrIterator < _1 > & operator++ ();
#line 173
        inline void operator+= (int i);
#line 172
        void operator-- (int i);
#line 188
        inline _1 *operator-> () const;
#line 170
        inline void operator= (const BwdPtrIterator& it);
#line 190
        inline operator _1 * () const;
#line 189
        inline _1 *Get() const;
    };
    
    struct ConditionalVar
    {
#line 77
        ConditionalVar();
#line 80
        bool IsReady() const;
#line 79
        void SetReady(bool b = true);
#line 78
        void Wait();
    };
    
    template < class _1 >
    struct ConstBwdIterator
    {
#line 137
        typedef const _1 ConstK;
        
#line 138
        const _1 *kit;
        
#line 128
        inline ConstBwdIterator();
        ConstBwdIterator(const ConstBwdIterator& it);
#line 139
        inline ConstBwdIterator(const _1 *kit);
#line 144
        inline bool operator!= (const ConstBwdIterator& it) const;
        inline const _1& operator()() const;
#line 143
        inline const _1& operator*() const;
#line 131
        ConstBwdIterator < _1 > & operator++ ();
#line 134
        inline void operator+= (int i);
#line 133
        void operator-- (int i);
#line 140
        inline const _1 *operator-> () const;
#line 130
        inline void operator= (const ConstBwdIterator& it);
#line 142
        inline operator ConstK * () const;
#line 141
        inline const _1 *Get() const;
    };
    
    template < class _1 >
    struct ConstBwdPtrIterator
    {
#line 176
        typedef const _1 ConstK;
        
#line 177
        const _1 **kit;
        
#line 168
        inline ConstBwdPtrIterator();
        ConstBwdPtrIterator(const ConstBwdPtrIterator& it);
#line 178
        inline ConstBwdPtrIterator(const _1 **kit);
#line 183
        inline bool operator!= (const ConstBwdPtrIterator& it) const;
        inline const _1& operator()() const;
#line 182
        inline const _1& operator*() const;
#line 171
        ConstBwdPtrIterator < _1 > & operator++ ();
#line 173
        inline void operator+= (int i);
#line 172
        void operator-- (int i);
#line 179
        inline const _1 *operator-> () const;
#line 170
        inline void operator= (const ConstBwdPtrIterator& it);
#line 181
        inline operator ConstK * () const;
#line 180
        inline const _1 *Get() const;
    };
    
    template < class _1 >
    struct ConstFwdIterator
    {
#line 137
        typedef const _1 ConstK;
        
#line 138
        const _1 *kit;
        
#line 128
        inline ConstFwdIterator();
        ConstFwdIterator(const ConstFwdIterator& it);
#line 139
        inline ConstFwdIterator(const _1 *kit);
#line 144
        inline bool operator!= (const ConstFwdIterator& it) const;
        inline const _1& operator()() const;
#line 143
        inline const _1& operator*() const;
#line 131
        ConstFwdIterator < _1 > & operator++ ();
#line 134
        inline void operator+= (int i);
#line 133
        void operator-- (int i);
#line 140
        inline const _1 *operator-> () const;
#line 130
        inline void operator= (const ConstFwdIterator& it);
#line 142
        inline operator ConstK * () const;
#line 141
        inline const _1 *Get() const;
    };
    
    template < class _1 >
    struct ConstFwdPtrIterator
    {
#line 176
        typedef const _1 ConstK;
        
#line 177
        const _1 **kit;
        
#line 168
        inline ConstFwdPtrIterator();
        ConstFwdPtrIterator(const ConstFwdPtrIterator& it);
#line 178
        inline ConstFwdPtrIterator(const _1 **kit);
#line 183
        inline bool operator!= (const ConstFwdPtrIterator& it) const;
        inline const _1& operator()() const;
#line 182
        inline const _1& operator*() const;
#line 171
        ConstFwdPtrIterator < _1 > & operator++ ();
#line 173
        inline void operator+= (int i);
#line 172
        void operator-- (int i);
#line 179
        inline const _1 *operator-> () const;
#line 170
        inline void operator= (const ConstFwdPtrIterator& it);
#line 181
        inline operator ConstK * () const;
#line 180
        inline const _1 *Get() const;
    };
    
    template < class _1 >
    struct FwdIterator
    {
#line 147
        _1 *kit;
        
#line 128
        inline FwdIterator();
#line 148
        inline FwdIterator(_1 *kit);
#line 129
        FwdIterator(const FwdIterator& it);
#line 153
        inline bool operator!= (const FwdIterator& it) const;
        inline _1& operator()() const;
#line 152
        inline _1& operator*() const;
#line 131
        FwdIterator < _1 > & operator++ ();
#line 134
        inline void operator+= (int i);
#line 133
        void operator-- (int i);
#line 149
        inline _1 *operator-> () const;
#line 130
        inline void operator= (const FwdIterator& it);
#line 151
        inline operator _1 * () const;
#line 150
        inline _1 *Get() const;
    };
    
    template < class _1 >
    class DynArray
    {
    public:
#line 230
        typedef const _1 ConstK;
        typedef DynArray < _1 > DynArrayK;
#line 229
        typedef _1 IndirectK;
#line 232
        typedef FwdIterator < _1 > Iterator;
        typedef BwdIterator < _1 > RIterator;
        
    private:
#line 208
        typedef unsigned long long uint64;
        
#line 211
        _1 *data;
        int reserved;
        int count;
        
    public:
#line 243
        inline DynArray();
#line 246
        inline DynArray(const DynArray& v);
        inline DynArray(int i);
        inline ~DynArray();
#line 300
        inline DynArray < _1 > & operator<< (const _1& v);
#line 332
        inline void operator<<= (const DynArray& a);
#line 364
        inline _1& operator[](int i);
#line 368
        inline const _1& operator[](int i) const;
#line 278
        inline _1& Add();
#line 285
        inline _1& Add(const _1& v);
#line 339
        inline void Append(const DynArray& a);
#line 261
        inline C::ConstFwdIterator < _1 > Begin() const;
#line 259
        inline C::FwdIterator < _1 > Begin();
#line 466
        inline void Clear();
#line 262
        inline C::ConstFwdIterator < _1 > End() const;
#line 260
        inline C::FwdIterator < _1 > End();
#line 276
        inline _1 *Get() const;
#line 360
        inline int GetCount() const;
        inline int GetReserved() const;
#line 347
        inline void IncreaseReserve(int more_reserved);
#line 427
        inline _1& Insert(int i);
#line 438
        inline _1& Insert(int i, ConstK& key);
#line 362
        inline bool IsEmpty() const;
#line 452
        inline _1 Pop();
#line 267
        inline C::BwdIterator < _1 > RBegin();
#line 269
        inline C::ConstBwdIterator < _1 > RBegin() const;
#line 268
        inline C::BwdIterator < _1 > REnd();
#line 270
        inline C::ConstBwdIterator < _1 > REnd() const;
#line 406
        inline void Remove(const DynArray < int > & sorted_list);
#line 388
        inline void Remove(const Iterator& it);
#line 395
        inline void Remove(const Iterator& it, const Iterator& end);
#line 407
        inline void Remove(const int *sorted_list, int n);
#line 373
        inline void Remove(int i);
#line 380
        inline void Remove(int i, int count);
#line 461
        inline void RemoveLast();
#line 348
        inline void Reserve(int new_reserved);
#line 302
        inline void SetCount(int new_count);
#line 317
        inline void SetCount(int new_count, ConstK& value);
#line 450
        inline _1& Top();
#line 265
        inline C::ConstFwdIterator < _1 > begin() const;
#line 263
        inline C::FwdIterator < _1 > begin();
#line 266
        inline C::ConstFwdIterator < _1 > end() const;
#line 264
        inline C::FwdIterator < _1 > end();
#line 271
        inline C::BwdIterator < _1 > rbegin();
#line 273
        inline C::ConstBwdIterator < _1 > rbegin() const;
#line 272
        inline C::BwdIterator < _1 > rend();
#line 274
        inline C::ConstBwdIterator < _1 > rend() const;
        
#line 216
        inline void IncreaseReserved();
#line 225
        inline void Pick0(DynArray& v);
    };
    
    template < class _1 >
    struct FwdPtrIterator
    {
#line 186
        _1 **kit;
        
#line 168
        inline FwdPtrIterator();
#line 187
        inline FwdPtrIterator(_1 **kit);
#line 169
        FwdPtrIterator(const FwdPtrIterator& it);
#line 192
        inline bool operator!= (const FwdPtrIterator& it) const;
        inline _1& operator()() const;
#line 191
        inline _1& operator*() const;
#line 171
        FwdPtrIterator < _1 > & operator++ ();
#line 173
        inline void operator+= (int i);
#line 172
        void operator-- (int i);
#line 188
        inline _1 *operator-> () const;
#line 170
        inline void operator= (const FwdPtrIterator& it);
#line 190
        inline operator _1 * () const;
#line 189
        inline _1 *Get() const;
    };
    
    namespace Memory
    {
#line 27
        void *Alloc(int sz);
#line 29
        int Compare(const void *m1, const void *m2, int sz);
        void *Copy(void *dest, const void *src, int sz);
#line 28
        void Free(void *ptr);
#line 31
        void *Move(void *dest, const void *src, int sz);
        void Set(void *dest, int byte_value, int sz);
    };
    
    struct MemoryLimitExc
    {
#line 116
        const char *msg;
        
#line 117
        inline MemoryLimitExc();
        inline MemoryLimitExc(const char *s);
    };
    
    struct Nuller
    {
    };
    
    template < class _1 >
    struct Ptr
    {
#line 95
        _1 *value;
        
        inline Ptr();
        inline Ptr(_1 *p);
        inline void operator= (_1 *p);
        inline void operator= (const Nuller& p);
#line 103
        inline bool operator== (const Nuller& p) const;
#line 102
        inline bool operator== (const Ptr& p) const;
#line 101
        inline operator _1 * () const;
#line 106
        inline unsigned long long Int() const;
    };
};

namespace C
{
#line 128
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator()
    :
        kit(NULL)
    {};
    
#line 148
    template < class _1 >
    inline BwdIterator < _1 >::BwdIterator(_1 *kit)
    :
        kit(kit)
    {};
    
#line 153
    template < class _1 >
    inline bool BwdIterator < _1 >::operator!= (const BwdIterator& it) const
    {
#line 153
        return it.kit != kit;
    };
    
#line 154
    template < class _1 >
    inline _1& BwdIterator < _1 >::operator()() const
    {
#line 154
        return *kit;
    };
    
#line 152
    template < class _1 >
    inline _1& BwdIterator < _1 >::operator*() const
    {
#line 152
        return *kit;
    };
    
#line 134
    template < class _1 >
    inline void BwdIterator < _1 >::operator+= (int i)
    {
#line 134
        kit += i;
    };
    
#line 149
    template < class _1 >
    inline _1 *BwdIterator < _1 >::operator-> () const
    {
#line 149
        return kit;
    };
    
#line 130
    template < class _1 >
    inline void BwdIterator < _1 >::operator= (const BwdIterator& it)
    {
#line 130
        kit = it.kit;
    };
    
#line 151
    template < class _1 >
    inline BwdIterator < _1 >::operator _1 * () const
    {
#line 151
        return kit;
    };
    
#line 150
    template < class _1 >
    inline _1 *BwdIterator < _1 >::Get() const
    {
#line 150
        return kit;
    };
    
#line 168
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator()
    :
        kit(NULL)
    {};
    
#line 187
    template < class _1 >
    inline BwdPtrIterator < _1 >::BwdPtrIterator(_1 **kit)
    :
        kit(kit)
    {};
    
#line 192
    template < class _1 >
    inline bool BwdPtrIterator < _1 >::operator!= (const BwdPtrIterator& it) const
    {
#line 192
        return it.kit != kit;
    };
    
#line 193
    template < class _1 >
    inline _1& BwdPtrIterator < _1 >::operator()() const
    {
#line 193
        return **kit;
    };
    
#line 191
    template < class _1 >
    inline _1& BwdPtrIterator < _1 >::operator*() const
    {
#line 191
        return **kit;
    };
    
#line 173
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator+= (int i)
    {
#line 173
        kit += i;
    };
    
#line 188
    template < class _1 >
    inline _1 *BwdPtrIterator < _1 >::operator-> () const
    {
#line 188
        return *kit;
    };
    
#line 170
    template < class _1 >
    inline void BwdPtrIterator < _1 >::operator= (const BwdPtrIterator& it)
    {
#line 170
        kit = it.kit;
    };
    
#line 190
    template < class _1 >
    inline BwdPtrIterator < _1 >::operator _1 * () const
    {
#line 190
        return *kit;
    };
    
#line 189
    template < class _1 >
    inline _1 *BwdPtrIterator < _1 >::Get() const
    {
#line 189
        return *kit;
    };
    
#line 128
    template < class _1 >
    inline ConstBwdIterator < _1 >::ConstBwdIterator()
    :
        kit(NULL)
    {};
    
#line 139
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
    
#line 145
    template < class _1 >
    inline const _1& ConstBwdIterator < _1 >::operator()() const
    {
#line 145
        return *kit;
    };
    
#line 143
    template < class _1 >
    inline const _1& ConstBwdIterator < _1 >::operator*() const
    {
#line 143
        return *kit;
    };
    
#line 134
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator+= (int i)
    {
#line 134
        kit += i;
    };
    
#line 140
    template < class _1 >
    inline const _1 *ConstBwdIterator < _1 >::operator-> () const
    {
#line 140
        return kit;
    };
    
#line 130
    template < class _1 >
    inline void ConstBwdIterator < _1 >::operator= (const ConstBwdIterator& it)
    {
#line 130
        kit = it.kit;
    };
    
#line 142
    template < class _1 >
    inline ConstBwdIterator < _1 >::operator ConstK * () const
    {
#line 142
        return kit;
    };
    
#line 141
    template < class _1 >
    inline const _1 *ConstBwdIterator < _1 >::Get() const
    {
#line 141
        return kit;
    };
    
#line 168
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator()
    :
        kit(NULL)
    {};
    
#line 178
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator(const _1 **kit)
    :
        kit(kit)
    {};
    
#line 183
    template < class _1 >
    inline bool ConstBwdPtrIterator < _1 >::operator!= (const ConstBwdPtrIterator& it) const
    {
#line 183
        return it.kit != kit;
    };
    
#line 184
    template < class _1 >
    inline const _1& ConstBwdPtrIterator < _1 >::operator()() const
    {
#line 184
        return **kit;
    };
    
#line 182
    template < class _1 >
    inline const _1& ConstBwdPtrIterator < _1 >::operator*() const
    {
#line 182
        return **kit;
    };
    
#line 173
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator+= (int i)
    {
#line 173
        kit += i;
    };
    
#line 179
    template < class _1 >
    inline const _1 *ConstBwdPtrIterator < _1 >::operator-> () const
    {
#line 179
        return *kit;
    };
    
#line 170
    template < class _1 >
    inline void ConstBwdPtrIterator < _1 >::operator= (const ConstBwdPtrIterator& it)
    {
#line 170
        kit = it.kit;
    };
    
#line 181
    template < class _1 >
    inline ConstBwdPtrIterator < _1 >::operator ConstK * () const
    {
#line 181
        return *kit;
    };
    
#line 180
    template < class _1 >
    inline const _1 *ConstBwdPtrIterator < _1 >::Get() const
    {
#line 180
        return *kit;
    };
    
#line 128
    template < class _1 >
    inline ConstFwdIterator < _1 >::ConstFwdIterator()
    :
        kit(NULL)
    {};
    
#line 139
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
    
#line 145
    template < class _1 >
    inline const _1& ConstFwdIterator < _1 >::operator()() const
    {
#line 145
        return *kit;
    };
    
#line 143
    template < class _1 >
    inline const _1& ConstFwdIterator < _1 >::operator*() const
    {
#line 143
        return *kit;
    };
    
#line 134
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator+= (int i)
    {
#line 134
        kit += i;
    };
    
#line 140
    template < class _1 >
    inline const _1 *ConstFwdIterator < _1 >::operator-> () const
    {
#line 140
        return kit;
    };
    
#line 130
    template < class _1 >
    inline void ConstFwdIterator < _1 >::operator= (const ConstFwdIterator& it)
    {
#line 130
        kit = it.kit;
    };
    
#line 142
    template < class _1 >
    inline ConstFwdIterator < _1 >::operator ConstK * () const
    {
#line 142
        return kit;
    };
    
#line 141
    template < class _1 >
    inline const _1 *ConstFwdIterator < _1 >::Get() const
    {
#line 141
        return kit;
    };
    
#line 168
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator()
    :
        kit(NULL)
    {};
    
#line 178
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator(const _1 **kit)
    :
        kit(kit)
    {};
    
#line 183
    template < class _1 >
    inline bool ConstFwdPtrIterator < _1 >::operator!= (const ConstFwdPtrIterator& it) const
    {
#line 183
        return it.kit != kit;
    };
    
#line 184
    template < class _1 >
    inline const _1& ConstFwdPtrIterator < _1 >::operator()() const
    {
#line 184
        return **kit;
    };
    
#line 182
    template < class _1 >
    inline const _1& ConstFwdPtrIterator < _1 >::operator*() const
    {
#line 182
        return **kit;
    };
    
#line 173
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator+= (int i)
    {
#line 173
        kit += i;
    };
    
#line 179
    template < class _1 >
    inline const _1 *ConstFwdPtrIterator < _1 >::operator-> () const
    {
#line 179
        return *kit;
    };
    
#line 170
    template < class _1 >
    inline void ConstFwdPtrIterator < _1 >::operator= (const ConstFwdPtrIterator& it)
    {
#line 170
        kit = it.kit;
    };
    
#line 181
    template < class _1 >
    inline ConstFwdPtrIterator < _1 >::operator ConstK * () const
    {
#line 181
        return *kit;
    };
    
#line 180
    template < class _1 >
    inline const _1 *ConstFwdPtrIterator < _1 >::Get() const
    {
#line 180
        return *kit;
    };
    
#line 243
    template < class _1 >
    inline DynArray < _1 >::DynArray()
    :
        data(NULL),
        reserved(0),
        count(0)
    {};
    
#line 246
    template < class _1 >
    inline DynArray < _1 >::DynArray(const DynArray& v)
    :
        data(NULL),
        reserved(0),
        count(0)
    {
#line 246
        *this <<= v;
    };
    
#line 247
    template < class _1 >
    inline DynArray < _1 >::DynArray(int i)
    :
        data(NULL),
        reserved(0),
        count(0)
    {
#line 247
        SetCount(i);
    };
    
#line 248
    template < class _1 >
    inline DynArray < _1 >::~DynArray()
    {
#line 249
        Clear();
        return;
        ;
    };
    
#line 300
    template < class _1 >
    inline DynArray < _1 > & DynArray < _1 >::operator<< (const _1& v)
    {
#line 300
        Add(v);
#line 300
        return *this;
    };
    
#line 332
    template < class _1 >
    inline void DynArray < _1 >::operator<<= (const DynArray& a)
    {
#line 333
        SetCount(0);
        Reserve(a.GetCount());
        for (int i = 0; i < a.GetCount(); i ++ )
            new (&data[i])_1(a[i]);
        count = a.GetCount();
    };
    
#line 364
    template < class _1 >
    inline _1& DynArray < _1 >::operator[](int i)
    {
        {
#line 365
            if (!(i >= 0 && i < count))
            {
#line 365
                SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 366
        ;
#line 366
        return *(data + i);
    };
    
#line 368
    template < class _1 >
    inline const _1& DynArray < _1 >::operator[](int i) const
    {
        {
#line 369
            if (!(i >= 0 && i < count))
            {
#line 369
                SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 370
        ;
#line 370
        return *(data + i);
    };
    
#line 278
    template < class _1 >
    inline _1& DynArray < _1 >::Add()
    {
#line 279
        if (count + 1 > reserved)
#line 279
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        new (&data[count])_1;
        return data[count ++ ];
    };
    
#line 285
    template < class _1 >
    inline _1& DynArray < _1 >::Add(const _1& v)
    {
#line 286
        if (count + 1 > reserved)
#line 286
            IncreaseReserved();
        if (count >= reserved)
            throw MemoryLimitExc("DynArray maximum size exceeded");
        _1 * ptr = &data[count];
        new (ptr)_1(v);
        return data[count ++ ];
    };
    
#line 339
    template < class _1 >
    inline void DynArray < _1 >::Append(const DynArray& a)
    {
#line 340
        int begin = count;
        int new_count = count + a.GetCount();
        Reserve(new_count);
        for (int i = begin, j = 0; i < new_count; i ++ , j ++ )
            new (&data[i])_1(a[j]);
        count = new_count;
    };
    
#line 261
    template < class _1 >
    inline C::ConstFwdIterator < _1 > DynArray < _1 >::Begin() const
    {
#line 261
        return Iterator(data);
    };
    
#line 259
    template < class _1 >
    inline C::FwdIterator < _1 > DynArray < _1 >::Begin()
    {
#line 259
        return Iterator(data);
    };
    
#line 466
    template < class _1 >
    inline void DynArray < _1 >::Clear()
    {
#line 467
        if (!reserved)
#line 467
            return;
        _1 * it = data;
        _1 * end = data + count;
        while (it != end)
            it ++ -> ~IndirectK();
        count = 0;
        Memory::Free(data);
        data = NULL;
        reserved = 0;
    };
    
#line 262
    template < class _1 >
    inline C::ConstFwdIterator < _1 > DynArray < _1 >::End() const
    {
#line 262
        return Iterator(data + count);
    };
    
#line 260
    template < class _1 >
    inline C::FwdIterator < _1 > DynArray < _1 >::End()
    {
#line 260
        return Iterator(data + count);
    };
    
#line 276
    template < class _1 >
    inline _1 *DynArray < _1 >::Get() const
    {
#line 276
        return data;
    };
    
#line 360
    template < class _1 >
    inline int DynArray < _1 >::GetCount() const
    {
#line 360
        return count;
    };
    
#line 361
    template < class _1 >
    inline int DynArray < _1 >::GetReserved() const
    {
#line 361
        return reserved;
    };
    
#line 347
    template < class _1 >
    inline void DynArray < _1 >::IncreaseReserve(int more_reserved)
    {
#line 347
        Reserve(GetCount() + more_reserved);
    };
    
#line 216
    template < class _1 >
    inline void DynArray < _1 >::IncreaseReserved()
    {
#line 217
        uint64 new_reserved = 1;
        while (new_reserved <= reserved)
            new_reserved <<= 1;
        if (new_reserved >= 2000000000)
            new_reserved = 2000000000;
        Reserve((int) new_reserved);
    };
    
#line 427
    template < class _1 >
    inline _1& DynArray < _1 >::Insert(int i)
    {
#line 428
        if (count + 1 > reserved)
#line 428
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
    
#line 438
    template < class _1 >
    inline _1& DynArray < _1 >::Insert(int i, ConstK& key)
    {
#line 439
        if (count + 1 > reserved)
#line 439
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
    
#line 362
    template < class _1 >
    inline bool DynArray < _1 >::IsEmpty() const
    {
#line 362
        return GetCount() == 0;
    };
    
#line 225
    template < class _1 >
    inline void DynArray < _1 >::Pick0(DynArray& v)
    {
#line 225
        data = v.data;
#line 225
        v.data = 0;
#line 225
        reserved = v.reserved;
#line 225
        v.reserved = 0;
#line 225
        count = v.count;
#line 225
        v.count = 0;
    };
    
#line 452
    template < class _1 >
    inline _1 DynArray < _1 >::Pop()
    {
        {
#line 453
            if (!(GetCount() > 0))
            {
#line 453
                SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 454
        ;
#line 454
        int i = count - 1;
        _1 ret(data[i]);
        data[i].~K();
        count -- ;
        return ret;
    };
    
#line 267
    template < class _1 >
    inline C::BwdIterator < _1 > DynArray < _1 >::RBegin()
    {
#line 267
        return RIterator(data + count - 1);
    };
    
#line 269
    template < class _1 >
    inline C::ConstBwdIterator < _1 > DynArray < _1 >::RBegin() const
    {
#line 269
        return RIterator(data + count - 1);
    };
    
#line 268
    template < class _1 >
    inline C::BwdIterator < _1 > DynArray < _1 >::REnd()
    {
#line 268
        return RIterator(data - 1);
    };
    
#line 270
    template < class _1 >
    inline C::ConstBwdIterator < _1 > DynArray < _1 >::REnd() const
    {
#line 270
        return RIterator(data - 1);
    };
    
#line 406
    template < class _1 >
    inline void DynArray < _1 >::Remove(const DynArray < int > & sorted_list)
    {
#line 406
        Remove(sorted_list.Begin(), sorted_list.GetCount());
    };
    
#line 388
    template < class _1 >
    inline void DynArray < _1 >::Remove(const Iterator& it)
    {
#line 389
        _1 * begin = data;
        _1 * cur = it.Get();
        int pos = cur - begin;
        Remove(pos);
    };
    
    template < class _1 >
    inline void DynArray < _1 >::Remove(const Iterator& it, const Iterator& end)
    {
#line 396
        _1 * begin = data;
        _1 * cur = it.Get();
        _1 * cur_end = end.Get();
        int pos0 = cur - begin;
        int pos1 = cur_end - begin;
        int len = pos1 - pos0;
        if (!len)
#line 402
            return;
        Remove(pos0, len);
    };
    
#line 407
    template < class _1 >
    inline void DynArray < _1 >::Remove(const int *sorted_list, int n)
    {
#line 408
        if (!n)
#line 408
            return;
        int pos = *sorted_list;
        int npos = pos;
        for (;;)
            {
                {
#line 412
                    if (!(pos < count))
                    {
#line 412
                        SysBreak("Assertion failed: pos < count");
                    }
                }
#line 413
                ;
#line 413
                if (pos == *sorted_list)
                {
#line 414
                    (data + pos)-> ~K();
                    pos ++ ;
                    sorted_list ++ ;
                    if (-- n == 0)
#line 417
                        break;
                    
                    {
#line 418
                        if (!(*sorted_list >= pos))
                        {
#line 418
                            SysBreak("Assertion failed: *sorted_list >= pos");
                        }
                    }
#line 419
                    ;
                }
                else
#line 421
                    Memory::Copy(data + npos ++ , data + pos ++ , sizeof (_1));
            }
        while (pos < count)
            Memory::Copy(data + npos ++ , data + pos ++ , sizeof (_1));
        count = npos;
    };
    
#line 373
    template < class _1 >
    inline void DynArray < _1 >::Remove(int i)
    {
        {
#line 374
            if (!(i >= 0 && i < count))
            {
#line 374
                SysBreak("Assertion failed: i >= 0 && i < count");
            }
        }
#line 375
        ;
#line 375
        int tail = count - (i + 1);
        if (tail > 0)
            Memory::Move(data + i, data + i + 1, tail * sizeof (_1));
        count -- ;
    };
    
#line 380
    template < class _1 >
    inline void DynArray < _1 >::Remove(int i, int count)
    {
        {
#line 381
            if (!(count > 0))
            {
#line 381
                SysBreak("Assertion failed: count > 0");
            }
        }
#line 382
        ;
        {
#line 382
            if (!(i >= 0 && i + count <= this -> count))
            {
#line 382
                SysBreak("Assertion failed: i >= 0 && i + count <= this->count");
            }
        }
#line 383
        ;
#line 383
        int tail = this -> count - (i + count);
        if (tail > 0)
            Memory::Move(data + i, data + i + count, tail * sizeof (_1));
        this -> count -= count;
    };
    
#line 461
    template < class _1 >
    inline void DynArray < _1 >::RemoveLast()
    {
        {
#line 462
            if (!(GetCount() > 0))
            {
#line 462
                SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 463
        ;
#line 463
        data[-- count].~K();
    };
    
#line 348
    template < class _1 >
    inline void DynArray < _1 >::Reserve(int new_reserved)
    {
#line 349
        if (new_reserved <= reserved || new_reserved <= 0)
            return;
        _1 * new_data = (_1 * ) Memory::Alloc(new_reserved * sizeof (_1));
        if (data)
        {
#line 353
            if (count > 0)
                Memory::Copy((void * ) new_data, (void * ) data, sizeof (_1) * count);
            Memory::Free(data);
        }
        data = new_data;
        reserved = new_reserved;
    };
    
#line 302
    template < class _1 >
    inline void DynArray < _1 >::SetCount(int new_count)
    {
        {
#line 303
            if (!(new_count >= 0))
            {
#line 303
                SysBreak("Assertion failed: new_count >= 0");
            }
        }
#line 304
        ;
#line 304
        if (new_count < 0)
#line 304
            return;
        if (new_count > reserved)
#line 305
            Reserve(new_count);
        if (new_count == count)
#line 306
            return;
        if (new_count > count)
        {
#line 308
            for (int i = count; i < new_count; i ++ )
                new (&data[i])_1;
        }
        else
        {
#line 312
            for (int i = count - 1; i >= new_count; i -- )
                data[i].~K();
        }
        count = new_count;
    };
    
#line 317
    template < class _1 >
    inline void DynArray < _1 >::SetCount(int new_count, ConstK& value)
    {
        {
#line 318
            if (!(new_count >= 0))
            {
#line 318
                SysBreak("Assertion failed: new_count >= 0");
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
                new (&data[i])_1(value);
        }
        else
        {
#line 327
            for (int i = count - 1; i >= new_count; i -- )
                data[i].~K();
        }
        count = new_count;
    };
    
#line 450
    template < class _1 >
    inline _1& DynArray < _1 >::Top()
    {
        {
#line 450
            if (!(GetCount() > 0))
            {
#line 450
                SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 450
        ;
#line 450
        return data[count - 1];
    };
    
#line 265
    template < class _1 >
    inline C::ConstFwdIterator < _1 > DynArray < _1 >::begin() const
    {
#line 265
        return Begin();
    };
    
#line 263
    template < class _1 >
    inline C::FwdIterator < _1 > DynArray < _1 >::begin()
    {
#line 263
        return Begin();
    };
    
    template < class _1 >
    inline C::ConstFwdIterator < _1 > DynArray < _1 >::end() const
    {
#line 266
        return End();
    };
    
#line 264
    template < class _1 >
    inline C::FwdIterator < _1 > DynArray < _1 >::end()
    {
#line 264
        return End();
    };
    
#line 271
    template < class _1 >
    inline C::BwdIterator < _1 > DynArray < _1 >::rbegin()
    {
#line 271
        return RBegin();
    };
    
#line 273
    template < class _1 >
    inline C::ConstBwdIterator < _1 > DynArray < _1 >::rbegin() const
    {
#line 273
        return RBegin();
    };
    
#line 272
    template < class _1 >
    inline C::BwdIterator < _1 > DynArray < _1 >::rend()
    {
#line 272
        return REnd();
    };
    
#line 274
    template < class _1 >
    inline C::ConstBwdIterator < _1 > DynArray < _1 >::rend() const
    {
#line 274
        return REnd();
    };
    
#line 128
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator()
    :
        kit(NULL)
    {};
    
#line 148
    template < class _1 >
    inline FwdIterator < _1 >::FwdIterator(_1 *kit)
    :
        kit(kit)
    {};
    
#line 153
    template < class _1 >
    inline bool FwdIterator < _1 >::operator!= (const FwdIterator& it) const
    {
#line 153
        return it.kit != kit;
    };
    
#line 154
    template < class _1 >
    inline _1& FwdIterator < _1 >::operator()() const
    {
#line 154
        return *kit;
    };
    
#line 152
    template < class _1 >
    inline _1& FwdIterator < _1 >::operator*() const
    {
#line 152
        return *kit;
    };
    
#line 134
    template < class _1 >
    inline void FwdIterator < _1 >::operator+= (int i)
    {
#line 134
        kit += i;
    };
    
#line 149
    template < class _1 >
    inline _1 *FwdIterator < _1 >::operator-> () const
    {
#line 149
        return kit;
    };
    
#line 130
    template < class _1 >
    inline void FwdIterator < _1 >::operator= (const FwdIterator& it)
    {
#line 130
        kit = it.kit;
    };
    
#line 151
    template < class _1 >
    inline FwdIterator < _1 >::operator _1 * () const
    {
#line 151
        return kit;
    };
    
#line 150
    template < class _1 >
    inline _1 *FwdIterator < _1 >::Get() const
    {
#line 150
        return kit;
    };
    
#line 168
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator()
    :
        kit(NULL)
    {};
    
#line 187
    template < class _1 >
    inline FwdPtrIterator < _1 >::FwdPtrIterator(_1 **kit)
    :
        kit(kit)
    {};
    
#line 192
    template < class _1 >
    inline bool FwdPtrIterator < _1 >::operator!= (const FwdPtrIterator& it) const
    {
#line 192
        return it.kit != kit;
    };
    
#line 193
    template < class _1 >
    inline _1& FwdPtrIterator < _1 >::operator()() const
    {
#line 193
        return **kit;
    };
    
#line 191
    template < class _1 >
    inline _1& FwdPtrIterator < _1 >::operator*() const
    {
#line 191
        return **kit;
    };
    
#line 173
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator+= (int i)
    {
#line 173
        kit += i;
    };
    
#line 188
    template < class _1 >
    inline _1 *FwdPtrIterator < _1 >::operator-> () const
    {
#line 188
        return *kit;
    };
    
#line 170
    template < class _1 >
    inline void FwdPtrIterator < _1 >::operator= (const FwdPtrIterator& it)
    {
#line 170
        kit = it.kit;
    };
    
#line 190
    template < class _1 >
    inline FwdPtrIterator < _1 >::operator _1 * () const
    {
#line 190
        return *kit;
    };
    
#line 189
    template < class _1 >
    inline _1 *FwdPtrIterator < _1 >::Get() const
    {
#line 189
        return *kit;
    };
    
#line 117
    inline MemoryLimitExc::MemoryLimitExc()
    :
        msg(0)
    {};
    
#line 118
    inline MemoryLimitExc::MemoryLimitExc(const char *s)
    :
        msg(s)
    {};
    
#line 97
    template < class _1 >
    inline Ptr < _1 >::Ptr()
    :
        value(0)
    {};
    
#line 98
    template < class _1 >
    inline Ptr < _1 >::Ptr(_1 *p)
    :
        value(p)
    {};
    
#line 99
    template < class _1 >
    inline void Ptr < _1 >::operator= (_1 *p)
    {
#line 99
        value = p;
    };
    
#line 100
    template < class _1 >
    inline void Ptr < _1 >::operator= (const Nuller& p)
    {
#line 100
        value = 0;
    };
    
    template < class _1 >
    inline bool Ptr < _1 >::operator== (const Nuller& p) const
    {
#line 103
        return value == 0;
    };
    
#line 102
    template < class _1 >
    inline bool Ptr < _1 >::operator== (const Ptr& p) const
    {
#line 102
        return value == p.value;
    };
    
#line 101
    template < class _1 >
    inline Ptr < _1 >::operator _1 * () const
    {
#line 101
        return value;
    };
    
#line 106
    template < class _1 >
    inline unsigned long long Ptr < _1 >::Int() const
    {
#line 106
        return(unsigned long long) value;
    };
    
};

#endif
