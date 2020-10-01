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

#ifndef CONTAINER_HXX
#define CONTAINER_HXX

#include <new>

#ifndef TEXT_HXX
#include <Text.hxx>
#endif

namespace Container
{
#line 646 "../../src/Com/Container.fog"
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
#line 324
        typedef const _1 ConstK;
#line 323
        typedef _1 IndirectK;
#line 325
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 319
        Lang::DynArray < _1 * > l;
        
    public:
#line 329
        inline Array();
        inline ~Array();
#line 425
        inline Array < _1 > & operator<< (const _1& v);
#line 418
        inline void operator<<= (const Array& a);
#line 378
        inline _1& operator[](int i);
#line 384
        inline const _1& operator[](int i) const;
#line 369
        inline _1& Add();
#line 371
        inline _1& Add(_1 *k);
#line 370
        inline _1& Add(const _1& v);
#line 339
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 337
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 405
        inline void Clear();
#line 376
        inline _1 *Detach(int i);
#line 340
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 338
        inline Lang::FwdPtrIterator < _1 > End();
#line 334
        inline _1 **Get() const;
#line 374
        inline int GetCount() const;
#line 335
        inline _1 **GetEnd() const;
#line 372
        inline _1& Insert(int i);
        inline _1& Insert(int i, const _1& key);
#line 375
        inline bool IsEmpty() const;
#line 345
        inline Lang::BwdPtrIterator < _1 > RBegin();
#line 347
        inline Lang::ConstBwdPtrIterator < _1 > RBegin() const;
#line 346
        inline Lang::BwdPtrIterator < _1 > REnd();
#line 348
        inline Lang::ConstBwdPtrIterator < _1 > REnd() const;
#line 395
        inline void Remove(const int *sorted_list, int n);
#line 389
        inline void Remove(int i);
#line 404
        inline void RemoveLast();
#line 354
        inline void Reserve(int i);
        inline void SetCount(int new_count);
#line 414
        inline _1& Top();
#line 343
        inline Lang::ConstFwdPtrIterator < _1 > begin() const;
#line 341
        inline Lang::FwdPtrIterator < _1 > begin();
#line 344
        inline Lang::ConstFwdPtrIterator < _1 > end() const;
#line 342
        inline Lang::FwdPtrIterator < _1 > end();
#line 349
        inline Lang::BwdPtrIterator < _1 > rbegin();
#line 351
        inline Lang::ConstBwdPtrIterator < _1 > rbegin() const;
#line 350
        inline Lang::BwdPtrIterator < _1 > rend();
#line 352
        inline Lang::ConstBwdPtrIterator < _1 > rend() const;
    };
    
    template < class _1 >
    class Index
    {
    public:
#line 438
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 434
        Lang::DynArray < unsigned int > hashes;
        Lang::DynArray < _1 > values;
        
    public:
#line 441
        inline Index();
#line 496
        inline void operator<<= (const Index& a);
#line 452
        inline const _1& operator[](int i) const;
#line 462
        inline const _1& Add(const _1& value);
#line 447
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 443
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 491
        inline void Clear();
#line 448
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 445
        inline Lang::FwdPtrIterator < _1 > End();
#line 476
        inline int Find(const _1& key) const;
        inline int FindAdd(const _1& key);
#line 479
        inline int FindHash(Lang::uint32 hash) const;
#line 449
        inline _1 *Get();
#line 461
        inline int GetCount() const;
#line 450
        inline _1 *GetEnd();
#line 469
        inline _1& Insert(int i, const _1& value);
#line 492
        inline void Remove(int i);
#line 494
        inline void RemoveKey(const _1& key);
#line 493
        inline void RemoveLast();
#line 457
        inline void Set(const Index& i);
#line 444
        inline Lang::FwdPtrIterator < _1 > begin();
#line 446
        inline Lang::FwdPtrIterator < _1 > end();
    };
    
    template < class _1, class _2 >
    class ArrayMap
    {
    public:
#line 508
        typedef Array < _2 > ArrayV;
#line 507
        typedef Index < _1 > IndexK;
#line 608
        typedef Lang::FwdPairPtrIterator < _1, _2 > Iterator;
#line 509
        typedef ArrayMap < _1, _2 > MapKV;
#line 609
        typedef Lang::BwdPairPtrIterator < _1, _2 > RIterator;
        
#line 503
        Index < _1 > keys;
        Array < _2 > values;
        
    public:
#line 511
        inline ArrayMap();
#line 572
        inline void operator<<= (const ArrayMap& a);
#line 555
        inline _2& operator[](int i);
#line 554
        inline const _2& operator[](int i) const;
#line 517
        inline _2& Add(const _1& key);
#line 527
        inline _2& Add(const _1& key, _2 *value);
#line 522
        inline _2& Add(const _1& key, const _2& value);
#line 549
        inline _2& At(int i);
#line 544
        inline const _2& At(int i) const;
#line 629
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > Begin() const;
#line 627
        inline Lang::FwdPairPtrIterator < _1, _2 > Begin();
#line 567
        inline void Clear();
#line 630
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > End() const;
#line 628
        inline Lang::FwdPairPtrIterator < _1, _2 > End();
#line 559
        inline int Find(const _1& key) const;
#line 620
        inline Lang::FwdPairPtrIterator < _1, _2 > FindIterator(const _1& key) const;
#line 561
        inline _2 Get(const _1& key, _2 value);
#line 560
        inline _2& Get(const _1& key);
#line 532
        inline _2& GetAdd(const _1& key);
#line 562
        inline int GetCount() const;
#line 542
        inline const _1& GetKey(int i) const;
#line 513
        inline const Index < _1 > & GetKeys() const;
#line 610
        inline int GetPos(const Iterator& it);
#line 515
        inline Array < _2 > & GetValues();
#line 514
        inline const Array < _2 > & GetValues() const;
#line 539
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 619
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 618
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 617
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 563
        inline bool IsEmpty() const;
#line 616
        inline void Remove(const Iterator& it);
#line 566
        inline void Remove(int i);
#line 565
        inline void RemoveKey(const _1& key);
#line 557
        inline _2& Top();
#line 633
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > begin() const;
#line 631
        inline Lang::FwdPairPtrIterator < _1, _2 > begin();
#line 634
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > end() const;
#line 632
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
#line 208
        inline Text::String Join(Text::String join_str = "", bool ignore_empty = true) const;
#line 163
        void Serialize(Abstract::Stream& s);
#line 222
        inline void Split(Text::String to_split, Text::String split_str, bool ignore_empty = true);
    };
    
    template < class _1, class _2 >
    class VectorMap
    {
    public:
#line 508
        typedef Vector < _2 > ArrayV;
#line 507
        typedef Index < _1 > IndexK;
#line 579
        typedef Lang::FwdPairIterator < _1, _2 > Iterator;
#line 509
        typedef VectorMap < _1, _2 > MapKV;
#line 580
        typedef Lang::BwdPairIterator < _1, _2 > RIterator;
        
#line 503
        Index < _1 > keys;
        Vector < _2 > values;
        
    public:
#line 511
        inline VectorMap();
#line 572
        inline void operator<<= (const VectorMap& a);
#line 555
        inline _2& operator[](int i);
#line 554
        inline const _2& operator[](int i) const;
#line 517
        inline _2& Add(const _1& key);
#line 527
        inline _2& Add(const _1& key, _2 *value);
#line 522
        inline _2& Add(const _1& key, const _2& value);
#line 549
        inline _2& At(int i);
#line 544
        inline const _2& At(int i) const;
#line 600
        inline Lang::ConstFwdPairIterator < _1, _2 > Begin() const;
#line 598
        inline Lang::FwdPairIterator < _1, _2 > Begin();
#line 567
        inline void Clear();
#line 601
        inline Lang::ConstFwdPairIterator < _1, _2 > End() const;
#line 599
        inline Lang::FwdPairIterator < _1, _2 > End();
#line 559
        inline int Find(const _1& key) const;
#line 591
        inline Lang::FwdPairIterator < _1, _2 > FindIterator(const _1& key) const;
#line 561
        inline _2 Get(const _1& key, _2 value);
#line 560
        inline _2& Get(const _1& key);
#line 532
        inline _2& GetAdd(const _1& key);
#line 562
        inline int GetCount() const;
#line 542
        inline const _1& GetKey(int i) const;
#line 513
        inline const Index < _1 > & GetKeys() const;
#line 581
        inline int GetPos(const Iterator& it);
#line 515
        inline Vector < _2 > & GetValues();
#line 514
        inline const Vector < _2 > & GetValues() const;
#line 539
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 590
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 589
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 588
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 563
        inline bool IsEmpty() const;
#line 587
        inline void Remove(const Iterator& it);
#line 566
        inline void Remove(int i);
#line 565
        inline void RemoveKey(const _1& key);
#line 557
        inline _2& Top();
#line 604
        inline Lang::ConstFwdPairIterator < _1, _2 > begin() const;
#line 602
        inline Lang::FwdPairIterator < _1, _2 > begin();
#line 605
        inline Lang::ConstFwdPairIterator < _1, _2 > end() const;
#line 603
        inline Lang::FwdPairIterator < _1, _2 > end();
    };
    
    template < class _1 >
    class VectorPtr
    {
    public:
#line 276
        typedef Lang::ConstFwdPtrIterator < _1 > ConstIterator;
        typedef Lang::ConstBwdPtrIterator < _1 > ConstRIterator;
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 271
        Lang::DynArray < _1 * > data;
        
    public:
#line 281
        inline VectorPtr();
        inline VectorPtr(const VectorPtr& v);
#line 287
        inline Text::String Join(Text::String join_str = "", bool ignore_empty = true) const;
    };
};

namespace Container
{
#line 646
    template < class _1, class _2 >
    inline _1 FindIf(_1 first, _1 last, _2 pred)
    {
#line 648
        while (first != last)
            {
#line 649
                int i = pred._2::operator()(*first);
                if (i)
#line 650
                    return first;
#line 652
                ++ first;
            }
#line 655
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
    
#line 329
    template < class _1 >
    inline Array < _1 >::Array() {};
    
#line 330
    template < class _1 >
    inline Array < _1 >::~Array()
    {
#line 330
        Clear();
    };
    
#line 425
    template < class _1 >
    inline Array < _1 > & Array < _1 >::operator<< (const _1& v)
    {
#line 425
        Add(v);
#line 425
        return *this;
    };
    
#line 418
    template < class _1 >
    inline void Array < _1 >::operator<<= (const Array& a)
    {
#line 419
        Clear();
        l.SetCount(a.GetCount(), 0);
        for (int i = 0; i < a.GetCount(); i ++ )
            l[i] = new _1(*a.l[i]);
    };
    
#line 378
    template < class _1 >
    inline _1& Array < _1 >::operator[](int i)
    {
        {
#line 379
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 379
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 380
        ;
#line 380
        _1 * *it = l.Get();
        it = it + i;
        return **it;
    };
    
#line 384
    template < class _1 >
    inline const _1& Array < _1 >::operator[](int i) const
    {
        {
#line 385
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 385
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 386
        ;
#line 386
        return **(l.Get() + i);
    };
    
#line 369
    template < class _1 >
    inline _1& Array < _1 >::Add()
    {
#line 369
        _1 * k = new _1;
#line 369
        l.Add(k);
#line 369
        return *k;
    };
    
#line 371
    template < class _1 >
    inline _1& Array < _1 >::Add(_1 *k)
    {
#line 371
        l.Add(k);
#line 371
        return *k;
    };
    
#line 370
    template < class _1 >
    inline _1& Array < _1 >::Add(const _1& v)
    {
#line 370
        _1 * k = new _1(v);
#line 370
        l.Add(k);
#line 370
        return *k;
    };
    
#line 339
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::Begin() const
    {
#line 339
        return Iterator(l.Begin());
    };
    
#line 337
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::Begin()
    {
#line 337
        return Iterator(l.Begin());
    };
    
#line 405
    template < class _1 >
    inline void Array < _1 >::Clear()
    {
#line 406
        Lang::DynArray < _1 * > tmp;
        Swap(tmp, l);
        _1 * *ptr = tmp.Get();
        _1 * *end = ptr + tmp.GetCount();
        while (ptr != end)
            delete *(ptr ++ );
    };
    
#line 376
    template < class _1 >
    inline _1 *Array < _1 >::Detach(int i)
    {
#line 376
        _1 * o = l[i];
#line 376
        l.Remove(i);
#line 376
        return o;
    };
    
#line 340
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::End() const
    {
#line 340
        return Iterator(l.End());
    };
    
#line 338
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::End()
    {
#line 338
        return Iterator(l.End());
    };
    
#line 334
    template < class _1 >
    inline _1 **Array < _1 >::Get() const
    {
#line 334
        return l.Get();
    };
    
#line 374
    template < class _1 >
    inline int Array < _1 >::GetCount() const
    {
#line 374
        return l.GetCount();
    };
    
#line 335
    template < class _1 >
    inline _1 **Array < _1 >::GetEnd() const
    {
#line 335
        return l.GetEnd();
    };
    
#line 372
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i)
    {
#line 372
        return *l.Insert(i, new _1);
    };
    
#line 373
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i, const _1& key)
    {
#line 373
        return *l.Insert(i, new _1(key));
    };
    
#line 375
    template < class _1 >
    inline bool Array < _1 >::IsEmpty() const
    {
#line 375
        return GetCount() == 0;
    };
    
#line 345
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::RBegin()
    {
#line 345
        return RIterator(l.End() - 1);
    };
    
#line 347
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::RBegin() const
    {
#line 347
        return RIterator(l.End() - 1);
    };
    
#line 346
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::REnd()
    {
#line 346
        return RIterator(l.Begin() - 1);
    };
    
#line 348
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::REnd() const
    {
#line 348
        return RIterator(l.Begin() - 1);
    };
    
#line 395
    template < class _1 >
    inline void Array < _1 >::Remove(const int *sorted_list, int n)
    {
#line 396
        if (!n)
#line 396
            return;
        const int * it = sorted_list;
        const int * end = sorted_list + n;
        _1 * *vector = l.Get();
        while (it != end)
            (*(vector + *it ++ ))-> ~K();
        l.Remove(sorted_list, n);
    };
    
#line 389
    template < class _1 >
    inline void Array < _1 >::Remove(int i)
    {
        {
#line 390
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 390
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 391
        ;
#line 391
        delete *(l.Get() + i);
        l.Remove(i);
    };
    
#line 404
    template < class _1 >
    inline void Array < _1 >::RemoveLast()
    {
        {
#line 404
            if (!(GetCount()))
            {
#line 404
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 404
        ;
#line 404
        Remove(GetCount() - 1);
    };
    
#line 354
    template < class _1 >
    inline void Array < _1 >::Reserve(int i)
    {
#line 354
        l.Reserve(i);
    };
    
#line 355
    template < class _1 >
    inline void Array < _1 >::SetCount(int new_count)
    {
#line 356
        int count = l.GetCount();
        if (new_count == count)
#line 357
            return;
        if (new_count > count)
        {
#line 359
            l.SetCount(new_count);
            for (int i = count; i < new_count; i ++ )
                l[i] = new _1;
        }
        else
        {
#line 364
            for (int i = count - 1; i >= new_count; i -- )
                delete l[i];
            l.SetCount(new_count);
        }
    };
    
#line 414
    template < class _1 >
    inline _1& Array < _1 >::Top()
    {
        {
#line 415
            if (!(GetCount() > 0))
            {
#line 415
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 416
        ;
#line 416
        return **(l.Get() + l.GetCount() - 1);
    };
    
#line 343
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::begin() const
    {
#line 343
        return Begin();
    };
    
#line 341
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::begin()
    {
#line 341
        return Begin();
    };
    
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::end() const
    {
#line 344
        return End();
    };
    
#line 342
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::end()
    {
#line 342
        return End();
    };
    
#line 349
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rbegin()
    {
#line 349
        return RBegin();
    };
    
#line 351
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rbegin() const
    {
#line 351
        return RBegin();
    };
    
#line 350
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rend()
    {
#line 350
        return REnd();
    };
    
#line 352
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rend() const
    {
#line 352
        return REnd();
    };
    
#line 511
    template < class _1, class _2 >
    inline ArrayMap < _1, _2 >::ArrayMap() {};
    
#line 572
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::operator<<= (const ArrayMap& a)
    {
#line 573
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 555
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::operator[](int i)
    {
#line 555
        return At(i);
    };
    
#line 554
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::operator[](int i) const
    {
#line 554
        return At(i);
    };
    
#line 517
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key)
    {
#line 518
        keys.Add(key);
        return values.Add();
    };
    
#line 527
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 528
        keys.Add(key);
        return values.Add(value);
    };
    
#line 522
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 523
        keys.Add(key);
        return values.Add(value);
    };
    
#line 549
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::At(int i)
    {
        {
#line 550
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 550
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 551
        ;
#line 551
        return values[i];
    };
    
#line 544
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::At(int i) const
    {
        {
#line 545
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 545
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 546
        ;
#line 546
        return values[i];
    };
    
#line 629
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin() const
    {
#line 629
        return Iterator(keys.Get(), values.Get());
    };
    
#line 627
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin()
    {
#line 627
        return Iterator(keys.Get(), values.Get());
    };
    
#line 567
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Clear()
    {
#line 568
        keys.Clear();
        values.Clear();
    };
    
#line 630
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End() const
    {
#line 630
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 628
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End()
    {
#line 628
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 559
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::Find(const _1& key) const
    {
#line 559
        return keys.Find(key);
    };
    
#line 620
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 621
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 623
            it += GetCount();
        else
#line 624
            it += pos;
        return it;
    };
    
#line 561
    template < class _1, class _2 >
    inline _2 ArrayMap < _1, _2 >::Get(const _1& key, _2 value)
    {
#line 561
        int i = Find(key);
#line 561
        if (i < 0)
#line 561
            return value;
#line 561
        return values[i];
    };
    
#line 560
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Get(const _1& key)
    {
#line 560
        return values[Find(key)];
    };
    
#line 532
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 533
        int i = keys.Find(key);
        if (i >= 0)
#line 534
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 562
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetCount() const
    {
#line 562
        return keys.GetCount();
    };
    
#line 542
    template < class _1, class _2 >
    inline const _1& ArrayMap < _1, _2 >::GetKey(int i) const
    {
#line 542
        return keys[i];
    };
    
#line 513
    template < class _1, class _2 >
    inline const Index < _1 > & ArrayMap < _1, _2 >::GetKeys() const
    {
#line 513
        return keys;
    };
    
#line 610
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 611
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 515
    template < class _1, class _2 >
    inline Array < _2 > & ArrayMap < _1, _2 >::GetValues()
    {
#line 515
        return values;
    };
    
#line 514
    template < class _1, class _2 >
    inline const Array < _2 > & ArrayMap < _1, _2 >::GetValues() const
    {
#line 514
        return values;
    };
    
#line 539
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 539
        keys.Insert(i, key);
#line 539
        return values.Insert(i);
    };
    
#line 540
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 540
        keys.Insert(i, key);
#line 540
        return values.Insert(i, value);
    };
    
#line 619
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 619
        int pos = GetPos(it);
#line 619
        Insert(pos, key);
#line 619
        Iterator cur = Begin();
#line 619
        cur += pos;
#line 619
        return cur;
    };
    
#line 618
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 618
        int pos = GetPos(it);
#line 618
        Insert(pos, key, value);
#line 618
        Iterator cur = Begin();
#line 618
        cur += pos;
#line 618
        return cur;
    };
    
#line 617
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 617
        int pos = GetPos(it);
#line 617
        Insert(pos, key, value);
#line 617
        Iterator cur = Begin();
#line 617
        cur += pos;
#line 617
        return cur;
    };
    
#line 563
    template < class _1, class _2 >
    inline bool ArrayMap < _1, _2 >::IsEmpty() const
    {
#line 563
        return GetCount() == 0;
    };
    
#line 616
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 616
        Remove(GetPos(it));
    };
    
#line 566
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(int i)
    {
        {
#line 566
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 566
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 566
        ;
#line 566
        keys.Remove(i);
#line 566
        values.Remove(i);
    };
    
#line 565
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 565
        int i = Find(key);
#line 565
        if (i >= 0)
#line 565
            Remove(i);
    };
    
#line 557
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Top()
    {
        {
#line 557
            if (!(GetCount() > 0))
            {
#line 557
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 557
        ;
#line 557
        return values.Top();
    };
    
#line 633
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin() const
    {
#line 633
        return Begin();
    };
    
#line 631
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin()
    {
#line 631
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end() const
    {
#line 634
        return End();
    };
    
#line 632
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end()
    {
#line 632
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
    
#line 441
    template < class _1 >
    inline Index < _1 >::Index() {};
    
#line 496
    template < class _1 >
    inline void Index < _1 >::operator<<= (const Index& a)
    {
#line 496
        Set(a);
    };
    
#line 452
    template < class _1 >
    inline const _1& Index < _1 >::operator[](int i) const
    {
        {
#line 453
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 453
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 454
        ;
#line 454
        return values[i];
    };
    
#line 462
    template < class _1 >
    inline const _1& Index < _1 >::Add(const _1& value)
    {
#line 463
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Add(hash);
        return values.Add(value);
    };
    
#line 447
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::Begin() const
    {
#line 447
        return Iterator(values.Begin());
    };
    
#line 443
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::Begin()
    {
#line 443
        return Iterator(values.Begin());
    };
    
#line 491
    template < class _1 >
    inline void Index < _1 >::Clear()
    {
#line 491
        hashes.Clear();
#line 491
        values.Clear();
    };
    
#line 448
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::End() const
    {
#line 448
        return Iterator(values.End());
    };
    
#line 445
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::End()
    {
#line 445
        return Iterator(values.End());
    };
    
#line 476
    template < class _1 >
    inline int Index < _1 >::Find(const _1& key) const
    {
#line 476
        return FindHash(Hash::GetValue(key));
    };
    
#line 477
    template < class _1 >
    inline int Index < _1 >::FindAdd(const _1& key)
    {
#line 477
        int i = Find(key);
#line 477
        if (i >= 0)
#line 477
            return i;
#line 477
        i = GetCount();
#line 477
        Add(key);
#line 477
        return i;
    };
    
#line 479
    template < class _1 >
    inline int Index < _1 >::FindHash(Lang::uint32 hash) const
    {
#line 480
        unsigned int * begin = hashes.Get();
        unsigned int * it = begin;
        unsigned int * end = begin + hashes.GetCount();
        while (it != end)
            {
#line 484
                if (*it == hash)
                    return it - begin;
                it ++ ;
            }
        return - 1;
    };
    
#line 449
    template < class _1 >
    inline _1 *Index < _1 >::Get()
    {
#line 449
        return values.Get();
    };
    
#line 461
    template < class _1 >
    inline int Index < _1 >::GetCount() const
    {
#line 461
        return values.GetCount();
    };
    
#line 450
    template < class _1 >
    inline _1 *Index < _1 >::GetEnd()
    {
#line 450
        return values.GetEnd();
    };
    
#line 469
    template < class _1 >
    inline _1& Index < _1 >::Insert(int i, const _1& value)
    {
#line 470
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Insert(i, hash);
        return values.Insert(i, value);
    };
    
#line 492
    template < class _1 >
    inline void Index < _1 >::Remove(int i)
    {
#line 492
        hashes.Remove(i);
#line 492
        values.Remove(i);
    };
    
#line 494
    template < class _1 >
    inline void Index < _1 >::RemoveKey(const _1& key)
    {
#line 494
        int i = Find(key);
#line 494
        if (i >= 0)
#line 494
            Remove(i);
    };
    
#line 493
    template < class _1 >
    inline void Index < _1 >::RemoveLast()
    {
        {
#line 493
            if (!(GetCount()))
            {
#line 493
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 493
        ;
#line 493
        if (GetCount())
#line 493
            Remove(GetCount() - 1);
    };
    
#line 457
    template < class _1 >
    inline void Index < _1 >::Set(const Index& i)
    {
#line 458
        hashes <<= i.hashes;
        values <<= i.values;
    };
    
#line 444
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::begin()
    {
#line 444
        return Iterator(values.Begin());
    };
    
#line 446
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::end()
    {
#line 446
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
    
#line 208
    template < class _1 >
    inline Text::String Vector < _1 >::Join(Text::String join_str, bool ignore_empty) const
    {
#line 209
        Text::String out;
        ConstIterator end = Base::End();
        for (ConstIterator it = Base::Begin(); it != end; ++ it)
            {
#line 212
                Text::String s = Text::ToString < _1 > (*it);
                if (s.IsEmpty() && ignore_empty)
                    continue;
                
#line 215
                if (!out.IsEmpty())
                    out << join_str;
                out << s;
            }
        return out;
    };
    
    template < class _1 >
    inline void Vector < _1 >::Split(Text::String to_split, Text::String split_str, bool ignore_empty)
    {
#line 223
        Base::SetCount(0);
        if (to_split.IsEmpty() || split_str.IsEmpty())
            return;
#line 227
        int i = to_split.Find(split_str);
        if (i == - 1)
            Text::FromString(to_split, Base::Add());
        else
        {
#line 231
            int j = 0;
            while (i >= 0)
                {
#line 233
                    Text::String str = to_split.Mid(j, i - j);
                    if (str.GetCount() == 0)
                    {
#line 235
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
#line 247
                if (!ignore_empty)
                    Text::FromString(str, Base::Add());
            }
            else
            {
#line 251
                Text::FromString(str, Base::Add());
            }
        }
    };
    
#line 511
    template < class _1, class _2 >
    inline VectorMap < _1, _2 >::VectorMap() {};
    
#line 572
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::operator<<= (const VectorMap& a)
    {
#line 573
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 555
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::operator[](int i)
    {
#line 555
        return At(i);
    };
    
#line 554
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::operator[](int i) const
    {
#line 554
        return At(i);
    };
    
#line 517
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key)
    {
#line 518
        keys.Add(key);
        return values.Add();
    };
    
#line 527
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 528
        keys.Add(key);
        return values.Add(value);
    };
    
#line 522
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 523
        keys.Add(key);
        return values.Add(value);
    };
    
#line 549
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::At(int i)
    {
        {
#line 550
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 550
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 551
        ;
#line 551
        return values[i];
    };
    
#line 544
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::At(int i) const
    {
        {
#line 545
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 545
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 546
        ;
#line 546
        return values[i];
    };
    
#line 600
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin() const
    {
#line 600
        return Iterator(keys.Get(), values.Get());
    };
    
#line 598
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin()
    {
#line 598
        return Iterator(keys.Get(), values.Get());
    };
    
#line 567
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Clear()
    {
#line 568
        keys.Clear();
        values.Clear();
    };
    
#line 601
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End() const
    {
#line 601
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 599
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End()
    {
#line 599
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 559
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::Find(const _1& key) const
    {
#line 559
        return keys.Find(key);
    };
    
#line 591
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 592
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 594
            it += GetCount();
        else
#line 595
            it += pos;
        return it;
    };
    
#line 561
    template < class _1, class _2 >
    inline _2 VectorMap < _1, _2 >::Get(const _1& key, _2 value)
    {
#line 561
        int i = Find(key);
#line 561
        if (i < 0)
#line 561
            return value;
#line 561
        return values[i];
    };
    
#line 560
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Get(const _1& key)
    {
#line 560
        return values[Find(key)];
    };
    
#line 532
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 533
        int i = keys.Find(key);
        if (i >= 0)
#line 534
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 562
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetCount() const
    {
#line 562
        return keys.GetCount();
    };
    
#line 542
    template < class _1, class _2 >
    inline const _1& VectorMap < _1, _2 >::GetKey(int i) const
    {
#line 542
        return keys[i];
    };
    
#line 513
    template < class _1, class _2 >
    inline const Index < _1 > & VectorMap < _1, _2 >::GetKeys() const
    {
#line 513
        return keys;
    };
    
#line 581
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 582
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 515
    template < class _1, class _2 >
    inline Vector < _2 > & VectorMap < _1, _2 >::GetValues()
    {
#line 515
        return values;
    };
    
#line 514
    template < class _1, class _2 >
    inline const Vector < _2 > & VectorMap < _1, _2 >::GetValues() const
    {
#line 514
        return values;
    };
    
#line 539
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 539
        keys.Insert(i, key);
#line 539
        return values.Insert(i);
    };
    
#line 540
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 540
        keys.Insert(i, key);
#line 540
        return values.Insert(i, value);
    };
    
#line 590
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 590
        int pos = GetPos(it);
#line 590
        Insert(pos, key);
#line 590
        Iterator cur = Begin();
#line 590
        cur += pos;
#line 590
        return cur;
    };
    
#line 589
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 589
        int pos = GetPos(it);
#line 589
        Insert(pos, key, value);
#line 589
        Iterator cur = Begin();
#line 589
        cur += pos;
#line 589
        return cur;
    };
    
#line 588
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 588
        int pos = GetPos(it);
#line 588
        Insert(pos, key, value);
#line 588
        Iterator cur = Begin();
#line 588
        cur += pos;
#line 588
        return cur;
    };
    
#line 563
    template < class _1, class _2 >
    inline bool VectorMap < _1, _2 >::IsEmpty() const
    {
#line 563
        return GetCount() == 0;
    };
    
#line 587
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 587
        Remove(GetPos(it));
    };
    
#line 566
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(int i)
    {
        {
#line 566
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 566
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 566
        ;
#line 566
        keys.Remove(i);
#line 566
        values.Remove(i);
    };
    
#line 565
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 565
        int i = Find(key);
#line 565
        if (i >= 0)
#line 565
            Remove(i);
    };
    
#line 557
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Top()
    {
        {
#line 557
            if (!(GetCount() > 0))
            {
#line 557
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 557
        ;
#line 557
        return values.Top();
    };
    
#line 604
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin() const
    {
#line 604
        return Begin();
    };
    
#line 602
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin()
    {
#line 602
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end() const
    {
#line 605
        return End();
    };
    
#line 603
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end()
    {
#line 603
        return End();
    };
    
#line 281
    template < class _1 >
    inline VectorPtr < _1 >::VectorPtr() {};
    
#line 282
    template < class _1 >
    inline VectorPtr < _1 >::VectorPtr(const VectorPtr& v)
    :
        data(v)
    {};
    
#line 287
    template < class _1 >
    inline Text::String VectorPtr < _1 >::Join(Text::String join_str, bool ignore_empty) const
    {
#line 288
        Text::String out;
        ConstIterator end = data.End();
        for (ConstIterator it = data.Begin(); it != end; ++ it)
            {
#line 291
                Text::String s = Text::ToString < _1 > (**it);
                if (s.IsEmpty() && ignore_empty)
                    continue;
                
#line 294
                if (!out.IsEmpty())
                    out << join_str;
                out << s;
            }
        return out;
    };
    
};

#endif
