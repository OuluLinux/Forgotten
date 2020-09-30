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

#ifndef CONTAINER_HXX
#define CONTAINER_HXX

#include <new>

#ifndef TEXT_HXX
#include <Text.hxx>
#endif

namespace Container
{
#line 604 "../../src/Com/Container.fog"
    template < class _1, class _2 >
    inline _1 FindIf(_1 first, _1 last, _2 pred);
#line 36
    template < class _1 >
    inline void Reverse(_1& t);
#line 28
    template < class _1 >
    inline void Swap(_1& a, _1& b);
    
    template < class _1 >
    class Array
    {
    public:
#line 282
        typedef const _1 ConstK;
#line 281
        typedef _1 IndirectK;
#line 283
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 277
        Lang::DynArray < _1 * > l;
        
    public:
#line 287
        inline Array();
        inline ~Array();
#line 383
        inline Array < _1 > & operator<< (const _1& v);
#line 376
        inline void operator<<= (const Array& a);
#line 336
        inline _1& operator[](int i);
#line 342
        inline const _1& operator[](int i) const;
#line 327
        inline _1& Add();
#line 329
        inline _1& Add(_1 *k);
#line 328
        inline _1& Add(const _1& v);
#line 297
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 295
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 363
        inline void Clear();
#line 334
        inline _1 *Detach(int i);
#line 298
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 296
        inline Lang::FwdPtrIterator < _1 > End();
#line 292
        inline _1 **Get() const;
#line 332
        inline int GetCount() const;
#line 293
        inline _1 **GetEnd() const;
#line 330
        inline _1& Insert(int i);
        inline _1& Insert(int i, const _1& key);
#line 333
        inline bool IsEmpty() const;
#line 303
        inline Lang::BwdPtrIterator < _1 > RBegin();
#line 305
        inline Lang::ConstBwdPtrIterator < _1 > RBegin() const;
#line 304
        inline Lang::BwdPtrIterator < _1 > REnd();
#line 306
        inline Lang::ConstBwdPtrIterator < _1 > REnd() const;
#line 353
        inline void Remove(const int *sorted_list, int n);
#line 347
        inline void Remove(int i);
#line 362
        inline void RemoveLast();
#line 312
        inline void Reserve(int i);
        inline void SetCount(int new_count);
#line 372
        inline _1& Top();
#line 301
        inline Lang::ConstFwdPtrIterator < _1 > begin() const;
#line 299
        inline Lang::FwdPtrIterator < _1 > begin();
#line 302
        inline Lang::ConstFwdPtrIterator < _1 > end() const;
#line 300
        inline Lang::FwdPtrIterator < _1 > end();
#line 307
        inline Lang::BwdPtrIterator < _1 > rbegin();
#line 309
        inline Lang::ConstBwdPtrIterator < _1 > rbegin() const;
#line 308
        inline Lang::BwdPtrIterator < _1 > rend();
#line 310
        inline Lang::ConstBwdPtrIterator < _1 > rend() const;
    };
    
    template < class _1 >
    class Index
    {
    public:
#line 396
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 392
        Lang::DynArray < unsigned int > hashes;
        Lang::DynArray < _1 > values;
        
    public:
#line 399
        inline Index();
#line 454
        inline void operator<<= (const Index& a);
#line 410
        inline const _1& operator[](int i) const;
#line 420
        inline const _1& Add(const _1& value);
#line 405
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 401
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 449
        inline void Clear();
#line 406
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 403
        inline Lang::FwdPtrIterator < _1 > End();
#line 434
        inline int Find(const _1& key) const;
        inline int FindAdd(const _1& key);
#line 437
        inline int FindHash(Lang::uint32 hash) const;
#line 407
        inline _1 *Get();
#line 419
        inline int GetCount() const;
#line 408
        inline _1 *GetEnd();
#line 427
        inline _1& Insert(int i, const _1& value);
#line 450
        inline void Remove(int i);
#line 452
        inline void RemoveKey(const _1& key);
#line 451
        inline void RemoveLast();
#line 415
        inline void Set(const Index& i);
#line 402
        inline Lang::FwdPtrIterator < _1 > begin();
#line 404
        inline Lang::FwdPtrIterator < _1 > end();
    };
    
    template < class _1, class _2 >
    class ArrayMap
    {
    public:
#line 466
        typedef Array < _2 > ArrayV;
#line 465
        typedef Index < _1 > IndexK;
#line 566
        typedef Lang::FwdPairPtrIterator < _1, _2 > Iterator;
#line 467
        typedef ArrayMap < _1, _2 > MapKV;
#line 567
        typedef Lang::BwdPairPtrIterator < _1, _2 > RIterator;
        
#line 461
        Index < _1 > keys;
        Array < _2 > values;
        
    public:
#line 469
        inline ArrayMap();
#line 530
        inline void operator<<= (const ArrayMap& a);
#line 513
        inline _2& operator[](int i);
#line 512
        inline const _2& operator[](int i) const;
#line 475
        inline _2& Add(const _1& key);
#line 485
        inline _2& Add(const _1& key, _2 *value);
#line 480
        inline _2& Add(const _1& key, const _2& value);
#line 507
        inline _2& At(int i);
#line 502
        inline const _2& At(int i) const;
#line 587
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > Begin() const;
#line 585
        inline Lang::FwdPairPtrIterator < _1, _2 > Begin();
#line 525
        inline void Clear();
#line 588
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > End() const;
#line 586
        inline Lang::FwdPairPtrIterator < _1, _2 > End();
#line 517
        inline int Find(const _1& key) const;
#line 578
        inline Lang::FwdPairPtrIterator < _1, _2 > FindIterator(const _1& key) const;
#line 519
        inline _2 Get(const _1& key, _2 value);
#line 518
        inline _2& Get(const _1& key);
#line 490
        inline _2& GetAdd(const _1& key);
#line 520
        inline int GetCount() const;
#line 500
        inline const _1& GetKey(int i) const;
#line 471
        inline const Index < _1 > & GetKeys() const;
#line 568
        inline int GetPos(const Iterator& it);
#line 473
        inline Array < _2 > & GetValues();
#line 472
        inline const Array < _2 > & GetValues() const;
#line 497
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 577
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 576
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 575
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 521
        inline bool IsEmpty() const;
#line 574
        inline void Remove(const Iterator& it);
#line 524
        inline void Remove(int i);
#line 523
        inline void RemoveKey(const _1& key);
#line 515
        inline _2& Top();
#line 591
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > begin() const;
#line 589
        inline Lang::FwdPairPtrIterator < _1, _2 > begin();
#line 592
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > end() const;
#line 590
        inline Lang::FwdPairPtrIterator < _1, _2 > end();
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
        Lang::ConditionalVar cond;
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
        typedef Container::Pick < Optional > PickOpt;
#line 119
        typedef Container::Pick < _1 > PickT;
        
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
    class Vector : public Lang::DynArray < _1 >
    {
#line 150
        typedef Lang::DynArray < _1 > Base;
        
    public:
#line 155
        typedef Lang::ConstFwdIterator < _1 > ConstIterator;
        typedef Lang::ConstBwdIterator < _1 > ConstRIterator;
        typedef Lang::FwdIterator < _1 > Iterator;
        typedef Lang::BwdIterator < _1 > RIterator;
        
    public:
#line 160
        inline Vector();
        inline Vector(const Vector& v);
#line 166
        inline Text::String Join(Text::String join_str = "", bool ignore_empty = true) const;
#line 180
        inline void Split(Text::String to_split, Text::String split_str, bool ignore_empty = true);
    };
    
    template < class _1, class _2 >
    class VectorMap
    {
    public:
#line 466
        typedef Vector < _2 > ArrayV;
#line 465
        typedef Index < _1 > IndexK;
#line 537
        typedef Lang::FwdPairIterator < _1, _2 > Iterator;
#line 467
        typedef VectorMap < _1, _2 > MapKV;
#line 538
        typedef Lang::BwdPairIterator < _1, _2 > RIterator;
        
#line 461
        Index < _1 > keys;
        Vector < _2 > values;
        
    public:
#line 469
        inline VectorMap();
#line 530
        inline void operator<<= (const VectorMap& a);
#line 513
        inline _2& operator[](int i);
#line 512
        inline const _2& operator[](int i) const;
#line 475
        inline _2& Add(const _1& key);
#line 485
        inline _2& Add(const _1& key, _2 *value);
#line 480
        inline _2& Add(const _1& key, const _2& value);
#line 507
        inline _2& At(int i);
#line 502
        inline const _2& At(int i) const;
#line 558
        inline Lang::ConstFwdPairIterator < _1, _2 > Begin() const;
#line 556
        inline Lang::FwdPairIterator < _1, _2 > Begin();
#line 525
        inline void Clear();
#line 559
        inline Lang::ConstFwdPairIterator < _1, _2 > End() const;
#line 557
        inline Lang::FwdPairIterator < _1, _2 > End();
#line 517
        inline int Find(const _1& key) const;
#line 549
        inline Lang::FwdPairIterator < _1, _2 > FindIterator(const _1& key) const;
#line 519
        inline _2 Get(const _1& key, _2 value);
#line 518
        inline _2& Get(const _1& key);
#line 490
        inline _2& GetAdd(const _1& key);
#line 520
        inline int GetCount() const;
#line 500
        inline const _1& GetKey(int i) const;
#line 471
        inline const Index < _1 > & GetKeys() const;
#line 539
        inline int GetPos(const Iterator& it);
#line 473
        inline Vector < _2 > & GetValues();
#line 472
        inline const Vector < _2 > & GetValues() const;
#line 497
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 548
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 547
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 546
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 521
        inline bool IsEmpty() const;
#line 545
        inline void Remove(const Iterator& it);
#line 524
        inline void Remove(int i);
#line 523
        inline void RemoveKey(const _1& key);
#line 515
        inline _2& Top();
#line 562
        inline Lang::ConstFwdPairIterator < _1, _2 > begin() const;
#line 560
        inline Lang::FwdPairIterator < _1, _2 > begin();
#line 563
        inline Lang::ConstFwdPairIterator < _1, _2 > end() const;
#line 561
        inline Lang::FwdPairIterator < _1, _2 > end();
    };
    
    template < class _1 >
    class VectorPtr
    {
    public:
#line 234
        typedef Lang::ConstFwdPtrIterator < _1 > ConstIterator;
        typedef Lang::ConstBwdPtrIterator < _1 > ConstRIterator;
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 229
        Lang::DynArray < _1 * > data;
        
    public:
#line 239
        inline VectorPtr();
        inline VectorPtr(const VectorPtr& v);
#line 245
        inline Text::String Join(Text::String join_str = "", bool ignore_empty = true) const;
    };
};

namespace Container
{
#line 604
    template < class _1, class _2 >
    inline _1 FindIf(_1 first, _1 last, _2 pred)
    {
#line 606
        while (first != last)
            {
#line 607
                int i = pred._2::operator()(*first);
                if (i)
#line 608
                    return first;
#line 610
                ++ first;
            }
#line 613
        return last;
    };
    
#line 36
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
    
#line 28
    template < class _1 >
    inline void Swap(_1& a, _1& b)
    {
#line 30
        Lang::uint8 tmp[sizeof (_1)];
        Lang::Memory::Copy(tmp, &a, sizeof (_1));
        Lang::Memory::Copy(&a, &b, sizeof (_1));
        Lang::Memory::Copy(&b, tmp, sizeof (_1));
    };
    
#line 287
    template < class _1 >
    inline Array < _1 >::Array() {};
    
#line 288
    template < class _1 >
    inline Array < _1 >::~Array()
    {
#line 288
        Clear();
    };
    
#line 383
    template < class _1 >
    inline Array < _1 > & Array < _1 >::operator<< (const _1& v)
    {
#line 383
        Add(v);
#line 383
        return *this;
    };
    
#line 376
    template < class _1 >
    inline void Array < _1 >::operator<<= (const Array& a)
    {
#line 377
        Clear();
        l.SetCount(a.GetCount(), 0);
        for (int i = 0; i < a.GetCount(); i ++ )
            l[i] = new _1(*a.l[i]);
    };
    
#line 336
    template < class _1 >
    inline _1& Array < _1 >::operator[](int i)
    {
        {
#line 337
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 337
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 338
        ;
#line 338
        _1 * *it = l.Get();
        it = it + i;
        return **it;
    };
    
#line 342
    template < class _1 >
    inline const _1& Array < _1 >::operator[](int i) const
    {
        {
#line 343
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 343
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 344
        ;
#line 344
        return **(l.Get() + i);
    };
    
#line 327
    template < class _1 >
    inline _1& Array < _1 >::Add()
    {
#line 327
        _1 * k = new _1;
#line 327
        l.Add(k);
#line 327
        return *k;
    };
    
#line 329
    template < class _1 >
    inline _1& Array < _1 >::Add(_1 *k)
    {
#line 329
        l.Add(k);
#line 329
        return *k;
    };
    
#line 328
    template < class _1 >
    inline _1& Array < _1 >::Add(const _1& v)
    {
#line 328
        _1 * k = new _1(v);
#line 328
        l.Add(k);
#line 328
        return *k;
    };
    
#line 297
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::Begin() const
    {
#line 297
        return Iterator(l.Begin());
    };
    
#line 295
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::Begin()
    {
#line 295
        return Iterator(l.Begin());
    };
    
#line 363
    template < class _1 >
    inline void Array < _1 >::Clear()
    {
#line 364
        Lang::DynArray < _1 * > tmp;
        Swap(tmp, l);
        _1 * *ptr = tmp.Get();
        _1 * *end = ptr + tmp.GetCount();
        while (ptr != end)
            delete *(ptr ++ );
    };
    
#line 334
    template < class _1 >
    inline _1 *Array < _1 >::Detach(int i)
    {
#line 334
        _1 * o = l[i];
#line 334
        l.Remove(i);
#line 334
        return o;
    };
    
#line 298
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::End() const
    {
#line 298
        return Iterator(l.End());
    };
    
#line 296
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::End()
    {
#line 296
        return Iterator(l.End());
    };
    
#line 292
    template < class _1 >
    inline _1 **Array < _1 >::Get() const
    {
#line 292
        return l.Get();
    };
    
#line 332
    template < class _1 >
    inline int Array < _1 >::GetCount() const
    {
#line 332
        return l.GetCount();
    };
    
#line 293
    template < class _1 >
    inline _1 **Array < _1 >::GetEnd() const
    {
#line 293
        return l.GetEnd();
    };
    
#line 330
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i)
    {
#line 330
        return *l.Insert(i, new _1);
    };
    
#line 331
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i, const _1& key)
    {
#line 331
        return *l.Insert(i, new _1(key));
    };
    
#line 333
    template < class _1 >
    inline bool Array < _1 >::IsEmpty() const
    {
#line 333
        return GetCount() == 0;
    };
    
#line 303
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::RBegin()
    {
#line 303
        return RIterator(l.End() - 1);
    };
    
#line 305
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::RBegin() const
    {
#line 305
        return RIterator(l.End() - 1);
    };
    
#line 304
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::REnd()
    {
#line 304
        return RIterator(l.Begin() - 1);
    };
    
#line 306
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::REnd() const
    {
#line 306
        return RIterator(l.Begin() - 1);
    };
    
#line 353
    template < class _1 >
    inline void Array < _1 >::Remove(const int *sorted_list, int n)
    {
#line 354
        if (!n)
#line 354
            return;
        const int * it = sorted_list;
        const int * end = sorted_list + n;
        _1 * *vector = l.Get();
        while (it != end)
            (*(vector + *it ++ ))-> ~K();
        l.Remove(sorted_list, n);
    };
    
#line 347
    template < class _1 >
    inline void Array < _1 >::Remove(int i)
    {
        {
#line 348
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 348
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 349
        ;
#line 349
        delete *(l.Get() + i);
        l.Remove(i);
    };
    
#line 362
    template < class _1 >
    inline void Array < _1 >::RemoveLast()
    {
        {
#line 362
            if (!(GetCount()))
            {
#line 362
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 362
        ;
#line 362
        Remove(GetCount() - 1);
    };
    
#line 312
    template < class _1 >
    inline void Array < _1 >::Reserve(int i)
    {
#line 312
        l.Reserve(i);
    };
    
#line 313
    template < class _1 >
    inline void Array < _1 >::SetCount(int new_count)
    {
#line 314
        int count = l.GetCount();
        if (new_count == count)
#line 315
            return;
        if (new_count > count)
        {
#line 317
            l.SetCount(new_count);
            for (int i = count; i < new_count; i ++ )
                l[i] = new _1;
        }
        else
        {
#line 322
            for (int i = count - 1; i >= new_count; i -- )
                delete l[i];
            l.SetCount(new_count);
        }
    };
    
#line 372
    template < class _1 >
    inline _1& Array < _1 >::Top()
    {
        {
#line 373
            if (!(GetCount() > 0))
            {
#line 373
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 374
        ;
#line 374
        return **(l.Get() + l.GetCount() - 1);
    };
    
#line 301
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::begin() const
    {
#line 301
        return Begin();
    };
    
#line 299
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::begin()
    {
#line 299
        return Begin();
    };
    
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::end() const
    {
#line 302
        return End();
    };
    
#line 300
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::end()
    {
#line 300
        return End();
    };
    
#line 307
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rbegin()
    {
#line 307
        return RBegin();
    };
    
#line 309
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rbegin() const
    {
#line 309
        return RBegin();
    };
    
#line 308
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rend()
    {
#line 308
        return REnd();
    };
    
#line 310
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rend() const
    {
#line 310
        return REnd();
    };
    
#line 469
    template < class _1, class _2 >
    inline ArrayMap < _1, _2 >::ArrayMap() {};
    
#line 530
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::operator<<= (const ArrayMap& a)
    {
#line 531
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 513
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::operator[](int i)
    {
#line 513
        return At(i);
    };
    
#line 512
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::operator[](int i) const
    {
#line 512
        return At(i);
    };
    
#line 475
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key)
    {
#line 476
        keys.Add(key);
        return values.Add();
    };
    
#line 485
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 486
        keys.Add(key);
        return values.Add(value);
    };
    
#line 480
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 481
        keys.Add(key);
        return values.Add(value);
    };
    
#line 507
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::At(int i)
    {
        {
#line 508
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 508
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 509
        ;
#line 509
        return values[i];
    };
    
#line 502
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::At(int i) const
    {
        {
#line 503
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 503
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 504
        ;
#line 504
        return values[i];
    };
    
#line 587
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin() const
    {
#line 587
        return Iterator(keys.Get(), values.Get());
    };
    
#line 585
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin()
    {
#line 585
        return Iterator(keys.Get(), values.Get());
    };
    
#line 525
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Clear()
    {
#line 526
        keys.Clear();
        values.Clear();
    };
    
#line 588
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End() const
    {
#line 588
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 586
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End()
    {
#line 586
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 517
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::Find(const _1& key) const
    {
#line 517
        return keys.Find(key);
    };
    
#line 578
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 579
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 581
            it += GetCount();
        else
#line 582
            it += pos;
        return it;
    };
    
#line 519
    template < class _1, class _2 >
    inline _2 ArrayMap < _1, _2 >::Get(const _1& key, _2 value)
    {
#line 519
        int i = Find(key);
#line 519
        if (i < 0)
#line 519
            return value;
#line 519
        return values[i];
    };
    
#line 518
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Get(const _1& key)
    {
#line 518
        return values[Find(key)];
    };
    
#line 490
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 491
        int i = keys.Find(key);
        if (i >= 0)
#line 492
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 520
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetCount() const
    {
#line 520
        return keys.GetCount();
    };
    
#line 500
    template < class _1, class _2 >
    inline const _1& ArrayMap < _1, _2 >::GetKey(int i) const
    {
#line 500
        return keys[i];
    };
    
#line 471
    template < class _1, class _2 >
    inline const Index < _1 > & ArrayMap < _1, _2 >::GetKeys() const
    {
#line 471
        return keys;
    };
    
#line 568
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 569
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 473
    template < class _1, class _2 >
    inline Array < _2 > & ArrayMap < _1, _2 >::GetValues()
    {
#line 473
        return values;
    };
    
#line 472
    template < class _1, class _2 >
    inline const Array < _2 > & ArrayMap < _1, _2 >::GetValues() const
    {
#line 472
        return values;
    };
    
#line 497
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 497
        keys.Insert(i, key);
#line 497
        return values.Insert(i);
    };
    
#line 498
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 498
        keys.Insert(i, key);
#line 498
        return values.Insert(i, value);
    };
    
#line 577
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 577
        int pos = GetPos(it);
#line 577
        Insert(pos, key);
#line 577
        Iterator cur = Begin();
#line 577
        cur += pos;
#line 577
        return cur;
    };
    
#line 576
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 576
        int pos = GetPos(it);
#line 576
        Insert(pos, key, value);
#line 576
        Iterator cur = Begin();
#line 576
        cur += pos;
#line 576
        return cur;
    };
    
#line 575
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 575
        int pos = GetPos(it);
#line 575
        Insert(pos, key, value);
#line 575
        Iterator cur = Begin();
#line 575
        cur += pos;
#line 575
        return cur;
    };
    
#line 521
    template < class _1, class _2 >
    inline bool ArrayMap < _1, _2 >::IsEmpty() const
    {
#line 521
        return GetCount() == 0;
    };
    
#line 574
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 574
        Remove(GetPos(it));
    };
    
#line 524
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(int i)
    {
        {
#line 524
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 524
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 524
        ;
#line 524
        keys.Remove(i);
#line 524
        values.Remove(i);
    };
    
#line 523
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 523
        int i = Find(key);
#line 523
        if (i >= 0)
#line 523
            Remove(i);
    };
    
#line 515
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Top()
    {
        {
#line 515
            if (!(GetCount() > 0))
            {
#line 515
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 515
        ;
#line 515
        return values.Top();
    };
    
#line 591
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin() const
    {
#line 591
        return Begin();
    };
    
#line 589
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin()
    {
#line 589
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end() const
    {
#line 592
        return End();
    };
    
#line 590
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end()
    {
#line 590
        return End();
    };
    
#line 86
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
    
#line 399
    template < class _1 >
    inline Index < _1 >::Index() {};
    
#line 454
    template < class _1 >
    inline void Index < _1 >::operator<<= (const Index& a)
    {
#line 454
        Set(a);
    };
    
#line 410
    template < class _1 >
    inline const _1& Index < _1 >::operator[](int i) const
    {
        {
#line 411
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 411
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 412
        ;
#line 412
        return values[i];
    };
    
#line 420
    template < class _1 >
    inline const _1& Index < _1 >::Add(const _1& value)
    {
#line 421
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Add(hash);
        return values.Add(value);
    };
    
#line 405
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::Begin() const
    {
#line 405
        return Iterator(values.Begin());
    };
    
#line 401
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::Begin()
    {
#line 401
        return Iterator(values.Begin());
    };
    
#line 449
    template < class _1 >
    inline void Index < _1 >::Clear()
    {
#line 449
        hashes.Clear();
#line 449
        values.Clear();
    };
    
#line 406
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::End() const
    {
#line 406
        return Iterator(values.End());
    };
    
#line 403
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::End()
    {
#line 403
        return Iterator(values.End());
    };
    
#line 434
    template < class _1 >
    inline int Index < _1 >::Find(const _1& key) const
    {
#line 434
        return FindHash(Hash::GetValue(key));
    };
    
#line 435
    template < class _1 >
    inline int Index < _1 >::FindAdd(const _1& key)
    {
#line 435
        int i = Find(key);
#line 435
        if (i >= 0)
#line 435
            return i;
#line 435
        i = GetCount();
#line 435
        Add(key);
#line 435
        return i;
    };
    
#line 437
    template < class _1 >
    inline int Index < _1 >::FindHash(Lang::uint32 hash) const
    {
#line 438
        unsigned int * begin = hashes.Get();
        unsigned int * it = begin;
        unsigned int * end = begin + hashes.GetCount();
        while (it != end)
            {
#line 442
                if (*it == hash)
                    return it - begin;
                it ++ ;
            }
        return - 1;
    };
    
#line 407
    template < class _1 >
    inline _1 *Index < _1 >::Get()
    {
#line 407
        return values.Get();
    };
    
#line 419
    template < class _1 >
    inline int Index < _1 >::GetCount() const
    {
#line 419
        return values.GetCount();
    };
    
#line 408
    template < class _1 >
    inline _1 *Index < _1 >::GetEnd()
    {
#line 408
        return values.GetEnd();
    };
    
#line 427
    template < class _1 >
    inline _1& Index < _1 >::Insert(int i, const _1& value)
    {
#line 428
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Insert(i, hash);
        return values.Insert(i, value);
    };
    
#line 450
    template < class _1 >
    inline void Index < _1 >::Remove(int i)
    {
#line 450
        hashes.Remove(i);
#line 450
        values.Remove(i);
    };
    
#line 452
    template < class _1 >
    inline void Index < _1 >::RemoveKey(const _1& key)
    {
#line 452
        int i = Find(key);
#line 452
        if (i >= 0)
#line 452
            Remove(i);
    };
    
#line 451
    template < class _1 >
    inline void Index < _1 >::RemoveLast()
    {
        {
#line 451
            if (!(GetCount()))
            {
#line 451
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 451
        ;
#line 451
        if (GetCount())
#line 451
            Remove(GetCount() - 1);
    };
    
#line 415
    template < class _1 >
    inline void Index < _1 >::Set(const Index& i)
    {
#line 416
        hashes <<= i.hashes;
        values <<= i.values;
    };
    
#line 402
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::begin()
    {
#line 402
        return Iterator(values.Begin());
    };
    
#line 404
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::end()
    {
#line 404
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
                Lang::SysBreak("Assertion failed: obj");
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
                Lang::SysBreak("Assertion failed: obj");
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
    
#line 160
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
    inline Text::String Vector < _1 >::Join(Text::String join_str, bool ignore_empty) const
    {
#line 167
        Text::String out;
        ConstIterator end = Base::End();
        for (ConstIterator it = Base::Begin(); it != end; ++ it)
            {
#line 170
                Text::String s = Text::ToString < _1 > (*it);
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
    inline void Vector < _1 >::Split(Text::String to_split, Text::String split_str, bool ignore_empty)
    {
#line 181
        Base::SetCount(0);
        if (to_split.IsEmpty() || split_str.IsEmpty())
            return;
#line 185
        int i = to_split.Find(split_str);
        if (i == - 1)
            Text::FromString(to_split, Base::Add());
        else
        {
#line 189
            int j = 0;
            while (i >= 0)
                {
#line 191
                    Text::String str = to_split.Mid(j, i - j);
                    if (str.GetCount() == 0)
                    {
#line 193
                        if (!ignore_empty)
                            Text::FromString(str, Base::Add());
                    }
                    else
                        Text::FromString(str, Base::Add());
                    i += split_str.GetCount();
                    j = i;
                    i = to_split.Find(split_str, i);
                }
            i = to_split.GetCount();
            Text::String str = to_split.Mid(j, i - j);
            if (str.GetCount() == 0)
            {
#line 205
                if (!ignore_empty)
                    Text::FromString(str, Base::Add());
            }
            else
            {
#line 209
                Text::FromString(str, Base::Add());
            }
        }
    };
    
#line 469
    template < class _1, class _2 >
    inline VectorMap < _1, _2 >::VectorMap() {};
    
#line 530
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::operator<<= (const VectorMap& a)
    {
#line 531
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 513
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::operator[](int i)
    {
#line 513
        return At(i);
    };
    
#line 512
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::operator[](int i) const
    {
#line 512
        return At(i);
    };
    
#line 475
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key)
    {
#line 476
        keys.Add(key);
        return values.Add();
    };
    
#line 485
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 486
        keys.Add(key);
        return values.Add(value);
    };
    
#line 480
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 481
        keys.Add(key);
        return values.Add(value);
    };
    
#line 507
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::At(int i)
    {
        {
#line 508
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 508
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 509
        ;
#line 509
        return values[i];
    };
    
#line 502
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::At(int i) const
    {
        {
#line 503
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 503
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 504
        ;
#line 504
        return values[i];
    };
    
#line 558
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin() const
    {
#line 558
        return Iterator(keys.Get(), values.Get());
    };
    
#line 556
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin()
    {
#line 556
        return Iterator(keys.Get(), values.Get());
    };
    
#line 525
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Clear()
    {
#line 526
        keys.Clear();
        values.Clear();
    };
    
#line 559
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End() const
    {
#line 559
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 557
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End()
    {
#line 557
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 517
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::Find(const _1& key) const
    {
#line 517
        return keys.Find(key);
    };
    
#line 549
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 550
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 552
            it += GetCount();
        else
#line 553
            it += pos;
        return it;
    };
    
#line 519
    template < class _1, class _2 >
    inline _2 VectorMap < _1, _2 >::Get(const _1& key, _2 value)
    {
#line 519
        int i = Find(key);
#line 519
        if (i < 0)
#line 519
            return value;
#line 519
        return values[i];
    };
    
#line 518
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Get(const _1& key)
    {
#line 518
        return values[Find(key)];
    };
    
#line 490
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 491
        int i = keys.Find(key);
        if (i >= 0)
#line 492
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 520
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetCount() const
    {
#line 520
        return keys.GetCount();
    };
    
#line 500
    template < class _1, class _2 >
    inline const _1& VectorMap < _1, _2 >::GetKey(int i) const
    {
#line 500
        return keys[i];
    };
    
#line 471
    template < class _1, class _2 >
    inline const Index < _1 > & VectorMap < _1, _2 >::GetKeys() const
    {
#line 471
        return keys;
    };
    
#line 539
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 540
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 473
    template < class _1, class _2 >
    inline Vector < _2 > & VectorMap < _1, _2 >::GetValues()
    {
#line 473
        return values;
    };
    
#line 472
    template < class _1, class _2 >
    inline const Vector < _2 > & VectorMap < _1, _2 >::GetValues() const
    {
#line 472
        return values;
    };
    
#line 497
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 497
        keys.Insert(i, key);
#line 497
        return values.Insert(i);
    };
    
#line 498
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 498
        keys.Insert(i, key);
#line 498
        return values.Insert(i, value);
    };
    
#line 548
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 548
        int pos = GetPos(it);
#line 548
        Insert(pos, key);
#line 548
        Iterator cur = Begin();
#line 548
        cur += pos;
#line 548
        return cur;
    };
    
#line 547
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 547
        int pos = GetPos(it);
#line 547
        Insert(pos, key, value);
#line 547
        Iterator cur = Begin();
#line 547
        cur += pos;
#line 547
        return cur;
    };
    
#line 546
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 546
        int pos = GetPos(it);
#line 546
        Insert(pos, key, value);
#line 546
        Iterator cur = Begin();
#line 546
        cur += pos;
#line 546
        return cur;
    };
    
#line 521
    template < class _1, class _2 >
    inline bool VectorMap < _1, _2 >::IsEmpty() const
    {
#line 521
        return GetCount() == 0;
    };
    
#line 545
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 545
        Remove(GetPos(it));
    };
    
#line 524
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(int i)
    {
        {
#line 524
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 524
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 524
        ;
#line 524
        keys.Remove(i);
#line 524
        values.Remove(i);
    };
    
#line 523
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 523
        int i = Find(key);
#line 523
        if (i >= 0)
#line 523
            Remove(i);
    };
    
#line 515
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Top()
    {
        {
#line 515
            if (!(GetCount() > 0))
            {
#line 515
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 515
        ;
#line 515
        return values.Top();
    };
    
#line 562
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin() const
    {
#line 562
        return Begin();
    };
    
#line 560
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin()
    {
#line 560
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end() const
    {
#line 563
        return End();
    };
    
#line 561
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end()
    {
#line 561
        return End();
    };
    
#line 239
    template < class _1 >
    inline VectorPtr < _1 >::VectorPtr() {};
    
#line 240
    template < class _1 >
    inline VectorPtr < _1 >::VectorPtr(const VectorPtr& v)
    :
        data(v)
    {};
    
#line 245
    template < class _1 >
    inline Text::String VectorPtr < _1 >::Join(Text::String join_str, bool ignore_empty) const
    {
#line 246
        Text::String out;
        ConstIterator end = data.End();
        for (ConstIterator it = data.Begin(); it != end; ++ it)
            {
#line 249
                Text::String s = Text::ToString < _1 > (**it);
                if (s.IsEmpty() && ignore_empty)
                    continue;
                
#line 252
                if (!out.IsEmpty())
                    out << join_str;
                out << s;
            }
        return out;
    };
    
};

#endif
