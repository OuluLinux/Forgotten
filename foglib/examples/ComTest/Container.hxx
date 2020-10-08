#ifndef CONTAINER_HXX
#define CONTAINER_HXX

#include <new>

#ifndef TEXT_HXX
#include <Text.hxx>
#endif

namespace Container
{
#line 665 "../../src/Com/Container.fog"
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
#line 338
        typedef Lang::ConstFwdPtrIterator < _1 > CIterator;
        typedef Lang::ConstBwdPtrIterator < _1 > CRIterator;
#line 335
        typedef const _1 ConstK;
#line 334
        typedef _1 IndirectK;
#line 336
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 330
        Lang::DynArray < _1 * > l;
        
    public:
#line 342
        inline Array();
        inline ~Array();
#line 440
        inline Array < _1 > & operator<< (const _1& v);
#line 433
        inline void operator<<= (const Array& a);
#line 393
        inline _1& operator[](int i);
#line 399
        inline const _1& operator[](int i) const;
#line 384
        inline _1& Add();
#line 386
        inline _1& Add(_1 *k);
#line 385
        inline _1& Add(const _1& v);
#line 354
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 352
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 420
        inline void Clear();
#line 391
        inline _1 *Detach(int i);
#line 355
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 353
        inline Lang::FwdPtrIterator < _1 > End();
#line 347
        inline _1 **Get() const;
#line 349
        inline const _1 **GetConst() const;
        inline const _1 **GetConstEnd() const;
#line 389
        inline int GetCount() const;
#line 348
        inline _1 **GetEnd() const;
#line 387
        inline _1& Insert(int i);
        inline _1& Insert(int i, const _1& key);
#line 390
        inline bool IsEmpty() const;
#line 360
        inline Lang::BwdPtrIterator < _1 > RBegin();
#line 362
        inline Lang::ConstBwdPtrIterator < _1 > RBegin() const;
#line 361
        inline Lang::BwdPtrIterator < _1 > REnd();
#line 363
        inline Lang::ConstBwdPtrIterator < _1 > REnd() const;
#line 410
        inline void Remove(const int *sorted_list, int n);
#line 404
        inline void Remove(int i);
#line 419
        inline void RemoveLast();
#line 369
        inline void Reserve(int i);
        inline void SetCount(int new_count);
#line 429
        inline _1& Top();
#line 358
        inline Lang::ConstFwdPtrIterator < _1 > begin() const;
#line 356
        inline Lang::FwdPtrIterator < _1 > begin();
#line 359
        inline Lang::ConstFwdPtrIterator < _1 > end() const;
#line 357
        inline Lang::FwdPtrIterator < _1 > end();
#line 364
        inline Lang::BwdPtrIterator < _1 > rbegin();
#line 366
        inline Lang::ConstBwdPtrIterator < _1 > rbegin() const;
#line 365
        inline Lang::BwdPtrIterator < _1 > rend();
#line 367
        inline Lang::ConstBwdPtrIterator < _1 > rend() const;
    };
    
    template < class _1 >
    struct FixedArray2
    {
#line 693
        _1 vector[2];
        
#line 698
        inline void operator= (const FixedArray2& value);
#line 697
        inline void operator= (const _1& value);
#line 695
        inline _1& operator[](int i);
        inline const _1& operator[](int i) const;
        
#line 691
        static const int size;
    };
    
    template < class _1 >
    class Index
    {
    public:
#line 453
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 449
        Lang::DynArray < unsigned int > hashes;
        Lang::DynArray < _1 > values;
        
    public:
#line 456
        inline Index();
#line 511
        inline void operator<<= (const Index& a);
#line 467
        inline const _1& operator[](int i) const;
#line 477
        inline const _1& Add(const _1& value);
#line 462
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 458
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 506
        inline void Clear();
#line 463
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 460
        inline Lang::FwdPtrIterator < _1 > End();
#line 491
        inline int Find(const _1& key) const;
        inline int FindAdd(const _1& key);
#line 494
        inline int FindHash(Lang::uint32 hash) const;
#line 464
        inline _1 *Get();
#line 476
        inline int GetCount() const;
#line 465
        inline _1 *GetEnd();
#line 484
        inline _1& Insert(int i, const _1& value);
#line 507
        inline void Remove(int i);
#line 509
        inline void RemoveKey(const _1& key);
#line 508
        inline void RemoveLast();
#line 472
        inline void Set(const Index& i);
#line 459
        inline Lang::FwdPtrIterator < _1 > begin();
#line 461
        inline Lang::FwdPtrIterator < _1 > end();
    };
    
    template < class _1, class _2 >
    class ArrayMap
    {
    public:
#line 523
        typedef Array < _2 > ArrayV;
#line 522
        typedef Index < _1 > IndexK;
#line 627
        typedef Lang::FwdPairPtrIterator < _1, _2 > Iterator;
#line 524
        typedef ArrayMap < _1, _2 > MapKV;
#line 628
        typedef Lang::BwdPairPtrIterator < _1, _2 > RIterator;
        
#line 518
        Index < _1 > keys;
        Array < _2 > values;
        
    public:
#line 526
        inline ArrayMap();
#line 591
        inline void operator<<= (const ArrayMap& a);
#line 570
        inline _2& operator[](int i);
#line 569
        inline const _2& operator[](int i) const;
#line 532
        inline _2& Add(const _1& key);
#line 542
        inline _2& Add(const _1& key, _2 *value);
#line 537
        inline _2& Add(const _1& key, const _2& value);
#line 564
        inline _2& At(int i);
#line 559
        inline const _2& At(int i) const;
#line 648
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > Begin() const;
#line 646
        inline Lang::FwdPairPtrIterator < _1, _2 > Begin();
#line 582
        inline void Clear();
#line 586
        inline void ClearAndPickValues(Array < _2 > & a);
#line 649
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > End() const;
#line 647
        inline Lang::FwdPairPtrIterator < _1, _2 > End();
#line 574
        inline int Find(const _1& key) const;
#line 639
        inline Lang::FwdPairPtrIterator < _1, _2 > FindIterator(const _1& key) const;
#line 576
        inline _2 Get(const _1& key, _2 value) const;
#line 575
        inline _2& Get(const _1& key);
#line 547
        inline _2& GetAdd(const _1& key);
#line 577
        inline int GetCount() const;
#line 557
        inline const _1& GetKey(int i) const;
#line 528
        inline const Index < _1 > & GetKeys() const;
#line 629
        inline int GetPos(const Iterator& it);
#line 530
        inline Array < _2 > & GetValues();
#line 529
        inline const Array < _2 > & GetValues() const;
#line 554
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 638
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 637
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 636
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 578
        inline bool IsEmpty() const;
#line 635
        inline void Remove(const Iterator& it);
#line 581
        inline void Remove(int i);
#line 580
        inline void RemoveKey(const _1& key);
#line 572
        inline _2& Top();
#line 652
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > begin() const;
#line 650
        inline Lang::FwdPairPtrIterator < _1, _2 > begin();
#line 653
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > end() const;
#line 651
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
        inline _1 *operator-> ();
        inline const _1 *operator-> () const;
#line 61
        inline void operator= (_1 *obj);
#line 75
        inline operator ConstT & () const;
#line 74
        inline operator _1 & ();
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
        inline _1 *Detach();
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
    
    struct SortedIntMap
    {
#line 817
        Lang::DynArray < Lang::DynArray < int > > data;
        Lang::DynArray < Lang::uint64 > value_mask;
        int count;
        int first_data_i;
        
#line 847
        void Add(int key, int value);
#line 830
        void Clear();
#line 822
        void Reserve(int count);
    };
    
    struct TopValueSorter10
    {
#line 708
        typedef int Key;
        typedef double Value;
        
        Key key[10];
        Value value[10];
        int count;
        
#line 716
        inline TopValueSorter10();
#line 724
        void Add(const Key& key, const Value& value);
#line 717
        void Reset();
#line 740
        void Serialize(Abstract::StreamBase& s);
        
#line 707
        static const int size;
    };
    
    template < class _1 >
    class TreeArray
    {
    public:
#line 755
        typedef TreeArray < _1 > PA;
        
#line 758
        PA *down;
        Array < _1 > branch;
        
    public:
#line 771
        inline _1& Add(_1 *n);
#line 780
        inline _1& At(int i);
#line 782
        inline _1& At(int i, _1& n);
        inline const _1& At(int i) const;
#line 781
        inline _1& AtTop(int i);
#line 774
        inline void Clear();
#line 778
        inline _1 *Detach(int i);
#line 786
        inline int GetCount() const;
#line 770
        inline _1 *GetParent() const;
#line 772
        inline _1& Insert(int i, _1 *n);
#line 787
        inline bool IsEmpty() const;
#line 775
        inline void Remove(int i);
        inline void Remove(int i, int count);
        inline void RemoveLast();
#line 796
        inline void Serialize(Abstract::StreamBase& s);
#line 789
        inline void SortByInt();
#line 784
        inline _1& Top();
        
    protected:
#line 763
        inline _1& Add();
#line 766
        inline void Copy(const PA& src);
#line 764
        inline _1& Insert(int i);
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
        inline void Serialize(Abstract::StreamBase& s);
#line 222
        inline void Split(Text::String to_split, Text::String split_str, bool ignore_empty = true);
    };
    
    template < class _1 >
    struct CachingVector
    {
#line 876
        typedef Vector < _1 > Vec;
        
#line 877
        Vector < _1 > data;
        int count;
        
#line 882
        inline _1& operator[](int i);
#line 881
        inline const _1& operator[](int i) const;
#line 886
        inline typename Lang::FwdIterator < _1 > Begin();
#line 888
        inline typename Lang::FwdIterator < _1 > End();
#line 883
        inline int GetCount() const;
        void SetCount(int i);
        inline typename Lang::FwdIterator < _1 > begin();
#line 887
        inline typename Lang::FwdIterator < _1 > end();
    };
    
    template < class _1, class _2 >
    class VectorMap
    {
    public:
#line 523
        typedef Vector < _2 > ArrayV;
#line 522
        typedef Index < _1 > IndexK;
#line 598
        typedef Lang::FwdPairIterator < _1, _2 > Iterator;
#line 524
        typedef VectorMap < _1, _2 > MapKV;
#line 599
        typedef Lang::BwdPairIterator < _1, _2 > RIterator;
        
#line 518
        Index < _1 > keys;
        Vector < _2 > values;
        
    public:
#line 526
        inline VectorMap();
#line 591
        inline void operator<<= (const VectorMap& a);
#line 570
        inline _2& operator[](int i);
#line 569
        inline const _2& operator[](int i) const;
#line 532
        inline _2& Add(const _1& key);
#line 542
        inline _2& Add(const _1& key, _2 *value);
#line 537
        inline _2& Add(const _1& key, const _2& value);
#line 564
        inline _2& At(int i);
#line 559
        inline const _2& At(int i) const;
#line 619
        inline Lang::ConstFwdPairIterator < _1, _2 > Begin() const;
#line 617
        inline Lang::FwdPairIterator < _1, _2 > Begin();
#line 582
        inline void Clear();
#line 586
        inline void ClearAndPickValues(Vector < _2 > & a);
#line 620
        inline Lang::ConstFwdPairIterator < _1, _2 > End() const;
#line 618
        inline Lang::FwdPairIterator < _1, _2 > End();
#line 574
        inline int Find(const _1& key) const;
#line 610
        inline Lang::FwdPairIterator < _1, _2 > FindIterator(const _1& key) const;
#line 576
        inline _2 Get(const _1& key, _2 value) const;
#line 575
        inline _2& Get(const _1& key);
#line 547
        inline _2& GetAdd(const _1& key);
#line 577
        inline int GetCount() const;
#line 557
        inline const _1& GetKey(int i) const;
#line 528
        inline const Index < _1 > & GetKeys() const;
#line 600
        inline int GetPos(const Iterator& it);
#line 530
        inline Vector < _2 > & GetValues();
#line 529
        inline const Vector < _2 > & GetValues() const;
#line 554
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 609
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 608
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 607
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 578
        inline bool IsEmpty() const;
#line 606
        inline void Remove(const Iterator& it);
#line 581
        inline void Remove(int i);
#line 580
        inline void RemoveKey(const _1& key);
#line 572
        inline _2& Top();
#line 623
        inline Lang::ConstFwdPairIterator < _1, _2 > begin() const;
#line 621
        inline Lang::FwdPairIterator < _1, _2 > begin();
#line 624
        inline Lang::ConstFwdPairIterator < _1, _2 > end() const;
#line 622
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
#line 289
        inline _1& operator[](int i);
        inline const _1& operator[](int i) const;
#line 285
        inline _1& Add(_1 *o);
#line 287
        inline void Append(const VectorPtr& v);
        inline void Append(const VectorPtr& v, int i, int n);
#line 295
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 292
        inline void Clear();
#line 296
        inline Lang::FwdPtrIterator < _1 > End();
#line 286
        inline int GetCount() const;
#line 298
        inline Text::String Join(Text::String join_str = "", bool ignore_empty = true) const;
#line 293
        inline _1 *Pop();
#line 291
        inline _1 *& Ref(int i);
#line 294
        inline void SetCount(int i);
    };
};

namespace Container
{
#line 665
    template < class _1, class _2 >
    inline _1 FindIf(_1 first, _1 last, _2 pred)
    {
#line 667
        while (first != last)
            {
#line 668
                int i = pred._2::operator()(*first);
                if (i)
#line 669
                    return first;
#line 671
                ++ first;
            }
#line 674
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
    
#line 342
    template < class _1 >
    inline Array < _1 >::Array() {};
    
#line 343
    template < class _1 >
    inline Array < _1 >::~Array()
    {
#line 343
        Clear();
    };
    
#line 440
    template < class _1 >
    inline Array < _1 > & Array < _1 >::operator<< (const _1& v)
    {
#line 440
        Add(v);
#line 440
        return *this;
    };
    
#line 433
    template < class _1 >
    inline void Array < _1 >::operator<<= (const Array& a)
    {
#line 434
        Clear();
        l.SetCount(a.GetCount(), 0);
        for (int i = 0; i < a.GetCount(); i ++ )
            l[i] = new _1(*a.l[i]);
    };
    
#line 393
    template < class _1 >
    inline _1& Array < _1 >::operator[](int i)
    {
        {
#line 394
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 394
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 395
        ;
#line 395
        _1 * *it = l.Get();
        it = it + i;
        return **it;
    };
    
#line 399
    template < class _1 >
    inline const _1& Array < _1 >::operator[](int i) const
    {
        {
#line 400
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 400
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 401
        ;
#line 401
        return **(l.Get() + i);
    };
    
#line 384
    template < class _1 >
    inline _1& Array < _1 >::Add()
    {
#line 384
        _1 * k = new _1;
#line 384
        l.Add(k);
#line 384
        return *k;
    };
    
#line 386
    template < class _1 >
    inline _1& Array < _1 >::Add(_1 *k)
    {
#line 386
        l.Add(k);
#line 386
        return *k;
    };
    
#line 385
    template < class _1 >
    inline _1& Array < _1 >::Add(const _1& v)
    {
#line 385
        _1 * k = new _1(v);
#line 385
        l.Add(k);
#line 385
        return *k;
    };
    
#line 354
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::Begin() const
    {
#line 354
        return CIterator((const _1 * *) l.Get());
    };
    
#line 352
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::Begin()
    {
#line 352
        return Iterator(l.Get());
    };
    
#line 420
    template < class _1 >
    inline void Array < _1 >::Clear()
    {
#line 421
        Lang::DynArray < _1 * > tmp;
        Swap(tmp, l);
        _1 * *ptr = tmp.Get();
        _1 * *end = ptr + tmp.GetCount();
        while (ptr != end)
            delete *(ptr ++ );
    };
    
#line 391
    template < class _1 >
    inline _1 *Array < _1 >::Detach(int i)
    {
#line 391
        _1 * o = l[i];
#line 391
        l.Remove(i);
#line 391
        return o;
    };
    
#line 355
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::End() const
    {
#line 355
        return CIterator((const _1 * *) l.GetEnd());
    };
    
#line 353
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::End()
    {
#line 353
        return Iterator(l.GetEnd());
    };
    
#line 347
    template < class _1 >
    inline _1 **Array < _1 >::Get() const
    {
#line 347
        return l.Get();
    };
    
#line 349
    template < class _1 >
    inline const _1 **Array < _1 >::GetConst() const
    {
#line 349
        return l.Get();
    };
    
#line 350
    template < class _1 >
    inline const _1 **Array < _1 >::GetConstEnd() const
    {
#line 350
        return l.GetEnd();
    };
    
#line 389
    template < class _1 >
    inline int Array < _1 >::GetCount() const
    {
#line 389
        return l.GetCount();
    };
    
#line 348
    template < class _1 >
    inline _1 **Array < _1 >::GetEnd() const
    {
#line 348
        return l.GetEnd();
    };
    
#line 387
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i)
    {
#line 387
        return *l.Insert(i, new _1);
    };
    
#line 388
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i, const _1& key)
    {
#line 388
        return *l.Insert(i, new _1(key));
    };
    
#line 390
    template < class _1 >
    inline bool Array < _1 >::IsEmpty() const
    {
#line 390
        return GetCount() == 0;
    };
    
#line 360
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::RBegin()
    {
#line 360
        return RIterator(l.GetEnd() - 1);
    };
    
#line 362
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::RBegin() const
    {
#line 362
        return CRIterator(l.GetConstEnd() - 1);
    };
    
#line 361
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::REnd()
    {
#line 361
        return RIterator(l.Get() - 1);
    };
    
#line 363
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::REnd() const
    {
#line 363
        return CRIterator(l.GetConst() - 1);
    };
    
#line 410
    template < class _1 >
    inline void Array < _1 >::Remove(const int *sorted_list, int n)
    {
#line 411
        if (!n)
#line 411
            return;
        const int * it = sorted_list;
        const int * end = sorted_list + n;
        _1 * *vector = l.Get();
        while (it != end)
            Lang::Destruct(**(vector + *it ++ ));
        l.Remove(sorted_list, n);
    };
    
#line 404
    template < class _1 >
    inline void Array < _1 >::Remove(int i)
    {
        {
#line 405
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 405
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 406
        ;
#line 406
        delete *(l.Get() + i);
        l.Remove(i);
    };
    
#line 419
    template < class _1 >
    inline void Array < _1 >::RemoveLast()
    {
        {
#line 419
            if (!(GetCount()))
            {
#line 419
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 419
        ;
#line 419
        Remove(GetCount() - 1);
    };
    
#line 369
    template < class _1 >
    inline void Array < _1 >::Reserve(int i)
    {
#line 369
        l.Reserve(i);
    };
    
#line 370
    template < class _1 >
    inline void Array < _1 >::SetCount(int new_count)
    {
#line 371
        int count = l.GetCount();
        if (new_count == count)
#line 372
            return;
        if (new_count > count)
        {
#line 374
            l.SetCount(new_count);
            for (int i = count; i < new_count; i ++ )
                l[i] = new _1;
        }
        else
        {
#line 379
            for (int i = count - 1; i >= new_count; i -- )
                delete l[i];
            l.SetCount(new_count);
        }
    };
    
#line 429
    template < class _1 >
    inline _1& Array < _1 >::Top()
    {
        {
#line 430
            if (!(GetCount() > 0))
            {
#line 430
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 431
        ;
#line 431
        return **(l.Get() + l.GetCount() - 1);
    };
    
#line 358
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::begin() const
    {
#line 358
        return Begin();
    };
    
#line 356
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::begin()
    {
#line 356
        return Begin();
    };
    
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::end() const
    {
#line 359
        return End();
    };
    
#line 357
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::end()
    {
#line 357
        return End();
    };
    
#line 364
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rbegin()
    {
#line 364
        return RBegin();
    };
    
#line 366
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rbegin() const
    {
#line 366
        return RBegin();
    };
    
#line 365
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rend()
    {
#line 365
        return REnd();
    };
    
#line 367
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rend() const
    {
#line 367
        return REnd();
    };
    
#line 526
    template < class _1, class _2 >
    inline ArrayMap < _1, _2 >::ArrayMap() {};
    
#line 591
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::operator<<= (const ArrayMap& a)
    {
#line 592
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 570
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::operator[](int i)
    {
#line 570
        return At(i);
    };
    
#line 569
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::operator[](int i) const
    {
#line 569
        return At(i);
    };
    
#line 532
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key)
    {
#line 533
        keys.Add(key);
        return values.Add();
    };
    
#line 542
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 543
        keys.Add(key);
        return values.Add(value);
    };
    
#line 537
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 538
        keys.Add(key);
        return values.Add(value);
    };
    
#line 564
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::At(int i)
    {
        {
#line 565
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 565
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 566
        ;
#line 566
        return values[i];
    };
    
#line 559
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::At(int i) const
    {
        {
#line 560
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 560
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 561
        ;
#line 561
        return values[i];
    };
    
#line 648
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin() const
    {
#line 648
        return Iterator(keys.Get(), values.Get());
    };
    
#line 646
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin()
    {
#line 646
        return Iterator(keys.Get(), values.Get());
    };
    
#line 582
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Clear()
    {
#line 583
        keys.Clear();
        values.Clear();
    };
    
#line 586
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::ClearAndPickValues(Array < _2 > & a)
    {
#line 587
        Swap(a, values);
        Clear();
    };
    
#line 649
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End() const
    {
#line 649
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 647
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End()
    {
#line 647
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 574
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::Find(const _1& key) const
    {
#line 574
        return keys.Find(key);
    };
    
#line 639
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 640
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 642
            it += GetCount();
        else
#line 643
            it += pos;
        return it;
    };
    
#line 576
    template < class _1, class _2 >
    inline _2 ArrayMap < _1, _2 >::Get(const _1& key, _2 value) const
    {
#line 576
        int i = Find(key);
#line 576
        if (i < 0)
#line 576
            return value;
#line 576
        return values[i];
    };
    
#line 575
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Get(const _1& key)
    {
#line 575
        return values[Find(key)];
    };
    
#line 547
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 548
        int i = keys.Find(key);
        if (i >= 0)
#line 549
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 577
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetCount() const
    {
#line 577
        return keys.GetCount();
    };
    
#line 557
    template < class _1, class _2 >
    inline const _1& ArrayMap < _1, _2 >::GetKey(int i) const
    {
#line 557
        return keys[i];
    };
    
#line 528
    template < class _1, class _2 >
    inline const Index < _1 > & ArrayMap < _1, _2 >::GetKeys() const
    {
#line 528
        return keys;
    };
    
#line 629
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 630
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 530
    template < class _1, class _2 >
    inline Array < _2 > & ArrayMap < _1, _2 >::GetValues()
    {
#line 530
        return values;
    };
    
#line 529
    template < class _1, class _2 >
    inline const Array < _2 > & ArrayMap < _1, _2 >::GetValues() const
    {
#line 529
        return values;
    };
    
#line 554
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 554
        keys.Insert(i, key);
#line 554
        return values.Insert(i);
    };
    
#line 555
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 555
        keys.Insert(i, key);
#line 555
        return values.Insert(i, value);
    };
    
#line 638
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 638
        int pos = GetPos(it);
#line 638
        Insert(pos, key);
#line 638
        Iterator cur = Begin();
#line 638
        cur += pos;
#line 638
        return cur;
    };
    
#line 637
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 637
        int pos = GetPos(it);
#line 637
        Insert(pos, key, value);
#line 637
        Iterator cur = Begin();
#line 637
        cur += pos;
#line 637
        return cur;
    };
    
#line 636
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 636
        int pos = GetPos(it);
#line 636
        Insert(pos, key, value);
#line 636
        Iterator cur = Begin();
#line 636
        cur += pos;
#line 636
        return cur;
    };
    
#line 578
    template < class _1, class _2 >
    inline bool ArrayMap < _1, _2 >::IsEmpty() const
    {
#line 578
        return GetCount() == 0;
    };
    
#line 635
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 635
        Remove(GetPos(it));
    };
    
#line 581
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(int i)
    {
        {
#line 581
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 581
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 581
        ;
#line 581
        keys.Remove(i);
#line 581
        values.Remove(i);
    };
    
#line 580
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 580
        int i = Find(key);
#line 580
        if (i >= 0)
#line 580
            Remove(i);
    };
    
#line 572
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Top()
    {
        {
#line 572
            if (!(GetCount() > 0))
            {
#line 572
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 572
        ;
#line 572
        return values.Top();
    };
    
#line 652
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin() const
    {
#line 652
        return Begin();
    };
    
#line 650
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin()
    {
#line 650
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end() const
    {
#line 653
        return End();
    };
    
#line 651
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end()
    {
#line 651
        return End();
    };
    
#line 882
    template < class _1 >
    inline _1& CachingVector < _1 >::operator[](int i)
    {
#line 882
        return data[i];
    };
    
#line 881
    template < class _1 >
    inline const _1& CachingVector < _1 >::operator[](int i) const
    {
#line 881
        return data[i];
    };
    
#line 886
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::Begin()
    {
#line 886
        return data.begin();
    };
    
#line 888
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::End()
    {
#line 888
        return data.begin() + count;
    };
    
#line 883
    template < class _1 >
    inline int CachingVector < _1 >::GetCount() const
    {
#line 883
        return count;
    };
    
#line 885
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::begin()
    {
#line 885
        return data.begin();
    };
    
#line 887
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::end()
    {
#line 887
        return data.begin() + count;
    };
    
#line 698
    template < class _1 >
    inline void FixedArray2 < _1 >::operator= (const FixedArray2& value)
    {
#line 698
        for (int i = 0; i < size; i ++ )
#line 698
            this -> vector[i] = value.vector[i];
    };
    
#line 697
    template < class _1 >
    inline void FixedArray2 < _1 >::operator= (const _1& value)
    {
#line 697
        for (int i = 0; i < size; i ++ )
#line 697
            this -> vector[i] = value;
    };
    
#line 695
    template < class _1 >
    inline _1& FixedArray2 < _1 >::operator[](int i)
    {
        {
#line 695
            if (!(i >= 0 && i < size))
            {
#line 695
                Lang::SysBreak("Assertion failed: i >= 0 && i < size");
            }
        }
#line 695
        ;
#line 695
        return vector[i];
    };
    
#line 696
    template < class _1 >
    inline const _1& FixedArray2 < _1 >::operator[](int i) const
    {
        {
#line 696
            if (!(i >= 0 && i < size))
            {
#line 696
                Lang::SysBreak("Assertion failed: i >= 0 && i < size");
            }
        }
#line 696
        ;
#line 696
        return vector[i];
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
    
#line 456
    template < class _1 >
    inline Index < _1 >::Index() {};
    
#line 511
    template < class _1 >
    inline void Index < _1 >::operator<<= (const Index& a)
    {
#line 511
        Set(a);
    };
    
#line 467
    template < class _1 >
    inline const _1& Index < _1 >::operator[](int i) const
    {
        {
#line 468
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 468
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 469
        ;
#line 469
        return values[i];
    };
    
#line 477
    template < class _1 >
    inline const _1& Index < _1 >::Add(const _1& value)
    {
#line 478
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Add(hash);
        return values.Add(value);
    };
    
#line 462
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::Begin() const
    {
#line 462
        return Iterator(values.Begin());
    };
    
#line 458
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::Begin()
    {
#line 458
        return Iterator(values.Begin());
    };
    
#line 506
    template < class _1 >
    inline void Index < _1 >::Clear()
    {
#line 506
        hashes.Clear();
#line 506
        values.Clear();
    };
    
#line 463
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::End() const
    {
#line 463
        return Iterator(values.End());
    };
    
#line 460
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::End()
    {
#line 460
        return Iterator(values.End());
    };
    
#line 491
    template < class _1 >
    inline int Index < _1 >::Find(const _1& key) const
    {
#line 491
        return FindHash(Hash::GetValue(key));
    };
    
#line 492
    template < class _1 >
    inline int Index < _1 >::FindAdd(const _1& key)
    {
#line 492
        int i = Find(key);
#line 492
        if (i >= 0)
#line 492
            return i;
#line 492
        i = GetCount();
#line 492
        Add(key);
#line 492
        return i;
    };
    
#line 494
    template < class _1 >
    inline int Index < _1 >::FindHash(Lang::uint32 hash) const
    {
#line 495
        unsigned int * begin = hashes.Get();
        unsigned int * it = begin;
        unsigned int * end = begin + hashes.GetCount();
        while (it != end)
            {
#line 499
                if (*it == hash)
                    return it - begin;
                it ++ ;
            }
        return - 1;
    };
    
#line 464
    template < class _1 >
    inline _1 *Index < _1 >::Get()
    {
#line 464
        return values.Get();
    };
    
#line 476
    template < class _1 >
    inline int Index < _1 >::GetCount() const
    {
#line 476
        return values.GetCount();
    };
    
#line 465
    template < class _1 >
    inline _1 *Index < _1 >::GetEnd()
    {
#line 465
        return values.GetEnd();
    };
    
#line 484
    template < class _1 >
    inline _1& Index < _1 >::Insert(int i, const _1& value)
    {
#line 485
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Insert(i, hash);
        return values.Insert(i, value);
    };
    
#line 507
    template < class _1 >
    inline void Index < _1 >::Remove(int i)
    {
#line 507
        hashes.Remove(i);
#line 507
        values.Remove(i);
    };
    
#line 509
    template < class _1 >
    inline void Index < _1 >::RemoveKey(const _1& key)
    {
#line 509
        int i = Find(key);
#line 509
        if (i >= 0)
#line 509
            Remove(i);
    };
    
#line 508
    template < class _1 >
    inline void Index < _1 >::RemoveLast()
    {
        {
#line 508
            if (!(GetCount()))
            {
#line 508
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 508
        ;
#line 508
        if (GetCount())
#line 508
            Remove(GetCount() - 1);
    };
    
#line 472
    template < class _1 >
    inline void Index < _1 >::Set(const Index& i)
    {
#line 473
        hashes <<= i.hashes;
        values <<= i.values;
    };
    
#line 459
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::begin()
    {
#line 459
        return Iterator(values.Begin());
    };
    
#line 461
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::end()
    {
#line 461
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
    
#line 64
    template < class _1 >
    inline _1 *One < _1 >::operator-> ()
    {
        {
#line 64
            if (!(obj))
            {
#line 64
                Lang::SysBreak("Assertion failed: obj");
            }
        }
#line 64
        ;
#line 64
        return obj;
    };
    
#line 65
    template < class _1 >
    inline const _1 *One < _1 >::operator-> () const
    {
        {
#line 65
            if (!(obj))
            {
#line 65
                Lang::SysBreak("Assertion failed: obj");
            }
        }
#line 65
        ;
#line 65
        return obj;
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
    
#line 75
    template < class _1 >
    inline One < _1 >::operator ConstT & () const
    {
        {
#line 75
            if (!(obj))
            {
#line 75
                Lang::SysBreak("Assertion failed: obj");
            }
        }
#line 75
        ;
#line 75
        return *obj;
    };
    
#line 74
    template < class _1 >
    inline One < _1 >::operator _1 & ()
    {
        {
#line 74
            if (!(obj))
            {
#line 74
                Lang::SysBreak("Assertion failed: obj");
            }
        }
#line 74
        ;
#line 74
        return *obj;
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
    
#line 71
    template < class _1 >
    inline _1 *One < _1 >::Detach()
    {
        {
#line 71
            if (!(obj))
            {
#line 71
                Lang::SysBreak("Assertion failed: obj");
            }
        }
#line 71
        ;
#line 71
        _1 * tmp = obj;
#line 71
        obj = 0;
#line 71
        return tmp;
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
    
#line 716
    inline TopValueSorter10::TopValueSorter10()
    :
        count(0)
    {
#line 716
        Reset();
    };
    
#line 763
    template < class _1 >
    inline _1& TreeArray < _1 >::Add()
    {
#line 763
        _1 & t = branch.Add();
#line 763
        t.down = this;
#line 763
        return t;
    };
    
#line 771
    template < class _1 >
    inline _1& TreeArray < _1 >::Add(_1 *n)
    {
        {
#line 771
            if (!(n -> down == 0))
            {
#line 771
                Lang::SysBreak("Assertion failed: n->down == NULL");
            }
        }
#line 771
        ;
#line 771
        _1 & t = branch.Add(n);
#line 771
        t.down = this;
#line 771
        return t;
    };
    
#line 780
    template < class _1 >
    inline _1& TreeArray < _1 >::At(int i)
    {
#line 780
        return branch[i];
    };
    
#line 782
    template < class _1 >
    inline _1& TreeArray < _1 >::At(int i, _1& n)
    {
#line 782
        if (i < branch.GetCount())
#line 782
            return branch[i];
#line 782
        return n;
    };
    
#line 783
    template < class _1 >
    inline const _1& TreeArray < _1 >::At(int i) const
    {
#line 783
        return branch[i];
    };
    
#line 781
    template < class _1 >
    inline _1& TreeArray < _1 >::AtTop(int i)
    {
#line 781
        if (i < branch.GetCount())
#line 781
            return branch[i];
#line 781
        return branch.Top();
    };
    
#line 774
    template < class _1 >
    inline void TreeArray < _1 >::Clear()
    {
#line 774
        branch.Clear();
    };
    
#line 766
    template < class _1 >
    inline void TreeArray < _1 >::Copy(const PA& src)
    {
#line 766
        branch <<= src.branch;
#line 766
        for (int i = 0; i < branch.GetCount(); i ++ )
#line 766
            branch[i].down = this;
    };
    
#line 778
    template < class _1 >
    inline _1 *TreeArray < _1 >::Detach(int i)
    {
#line 778
        _1 * t = branch.Detach(i);
#line 778
        t -> down = 0;
#line 778
        return t;
    };
    
#line 786
    template < class _1 >
    inline int TreeArray < _1 >::GetCount() const
    {
#line 786
        return branch.GetCount();
    };
    
#line 770
    template < class _1 >
    inline _1 *TreeArray < _1 >::GetParent() const
    {
#line 770
        return down;
    };
    
#line 764
    template < class _1 >
    inline _1& TreeArray < _1 >::Insert(int i)
    {
#line 764
        _1 & t = branch.Insert(i);
#line 764
        t.down = this;
#line 764
        return t;
    };
    
#line 772
    template < class _1 >
    inline _1& TreeArray < _1 >::Insert(int i, _1 *n)
    {
        {
#line 772
            if (!(n -> down == 0))
            {
#line 772
                Lang::SysBreak("Assertion failed: n->down == NULL");
            }
        }
#line 772
        ;
#line 772
        _1 & t = branch.Insert(i, n);
#line 772
        t.down = this;
#line 772
        return t;
    };
    
#line 787
    template < class _1 >
    inline bool TreeArray < _1 >::IsEmpty() const
    {
#line 787
        return branch.IsEmpty();
    };
    
#line 775
    template < class _1 >
    inline void TreeArray < _1 >::Remove(int i)
    {
#line 775
        branch.Remove(i);
    };
    
#line 776
    template < class _1 >
    inline void TreeArray < _1 >::Remove(int i, int count)
    {
#line 776
        branch.Remove(i, count);
    };
    
#line 777
    template < class _1 >
    inline void TreeArray < _1 >::RemoveLast()
    {
#line 777
        branch.Remove(branch.GetCount() - 1);
    };
    
#line 796
    template < class _1 >
    inline void TreeArray < _1 >::Serialize(Abstract::StreamBase& s)
    {
#line 797
        s % branch;
        if (s.IsLoading())
            for (int i = 0; i < branch.GetCount(); i ++ )
                branch[i].down = this;
    };
    
#line 789
    template < class _1 >
    inline void TreeArray < _1 >::SortByInt()
    {
#line 790
        struct Sorter;
#line 793
        Sort(branch, Sorter());
    };
    
#line 784
    template < class _1 >
    inline _1& TreeArray < _1 >::Top()
    {
#line 784
        return branch.Top();
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
    
#line 163
    template < class _1 >
    inline void Vector < _1 >::Serialize(Abstract::StreamBase& s)
    {
#line 164
        static const Lang::byte correct_pre = 0xA;
        static const Lang::byte correct_post = 0xB;
        Lang::byte pre_magic;
        Lang::byte post_magic;
        Lang::uint32 len = 0;
        if (s.IsLoading())
        {
#line 170
            s.Get(&pre_magic, 1);
            if (pre_magic != correct_pre)
            {
#line 172
                s.SetCorrupted();
                return;
            }
#line 176
            s.Get(&len, sizeof (len));
            if (len > 2000000000)
            {
#line 178
                s.SetCorrupted();
                return;
            }
            Base::SetCount(len);
            Iterator it = Base::Begin();
            Iterator end = Base::End();
            for (; it != end; ++ it)
                Abstract::Serialize(*it, s);
#line 187
            s.Get(&post_magic, 1);
            if (post_magic != correct_post)
            {
#line 189
                s.SetCorrupted();
                return;
            }
        }
        else 
#line 193
        if (s.IsStoring())
        {
#line 194
            s.Put(&correct_pre, 1);
#line 196
            len = Base::GetCount();
            s.Put(&len, sizeof (len));
            Iterator it = Base::Begin();
            Iterator end = Base::End();
            for (; it != end; ++ it)
                Abstract::Serialize(*it, s);
#line 203
            s.Put(&correct_post, 1);
        }
    };
    
#line 222
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
    
#line 526
    template < class _1, class _2 >
    inline VectorMap < _1, _2 >::VectorMap() {};
    
#line 591
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::operator<<= (const VectorMap& a)
    {
#line 592
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 570
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::operator[](int i)
    {
#line 570
        return At(i);
    };
    
#line 569
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::operator[](int i) const
    {
#line 569
        return At(i);
    };
    
#line 532
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key)
    {
#line 533
        keys.Add(key);
        return values.Add();
    };
    
#line 542
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 543
        keys.Add(key);
        return values.Add(value);
    };
    
#line 537
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 538
        keys.Add(key);
        return values.Add(value);
    };
    
#line 564
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::At(int i)
    {
        {
#line 565
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 565
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 566
        ;
#line 566
        return values[i];
    };
    
#line 559
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::At(int i) const
    {
        {
#line 560
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 560
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 561
        ;
#line 561
        return values[i];
    };
    
#line 619
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin() const
    {
#line 619
        return Iterator(keys.Get(), values.Get());
    };
    
#line 617
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin()
    {
#line 617
        return Iterator(keys.Get(), values.Get());
    };
    
#line 582
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Clear()
    {
#line 583
        keys.Clear();
        values.Clear();
    };
    
#line 586
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::ClearAndPickValues(Vector < _2 > & a)
    {
#line 587
        Swap(a, values);
        Clear();
    };
    
#line 620
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End() const
    {
#line 620
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 618
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End()
    {
#line 618
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 574
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::Find(const _1& key) const
    {
#line 574
        return keys.Find(key);
    };
    
#line 610
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 611
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 613
            it += GetCount();
        else
#line 614
            it += pos;
        return it;
    };
    
#line 576
    template < class _1, class _2 >
    inline _2 VectorMap < _1, _2 >::Get(const _1& key, _2 value) const
    {
#line 576
        int i = Find(key);
#line 576
        if (i < 0)
#line 576
            return value;
#line 576
        return values[i];
    };
    
#line 575
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Get(const _1& key)
    {
#line 575
        return values[Find(key)];
    };
    
#line 547
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 548
        int i = keys.Find(key);
        if (i >= 0)
#line 549
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 577
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetCount() const
    {
#line 577
        return keys.GetCount();
    };
    
#line 557
    template < class _1, class _2 >
    inline const _1& VectorMap < _1, _2 >::GetKey(int i) const
    {
#line 557
        return keys[i];
    };
    
#line 528
    template < class _1, class _2 >
    inline const Index < _1 > & VectorMap < _1, _2 >::GetKeys() const
    {
#line 528
        return keys;
    };
    
#line 600
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 601
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 530
    template < class _1, class _2 >
    inline Vector < _2 > & VectorMap < _1, _2 >::GetValues()
    {
#line 530
        return values;
    };
    
#line 529
    template < class _1, class _2 >
    inline const Vector < _2 > & VectorMap < _1, _2 >::GetValues() const
    {
#line 529
        return values;
    };
    
#line 554
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 554
        keys.Insert(i, key);
#line 554
        return values.Insert(i);
    };
    
#line 555
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 555
        keys.Insert(i, key);
#line 555
        return values.Insert(i, value);
    };
    
#line 609
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 609
        int pos = GetPos(it);
#line 609
        Insert(pos, key);
#line 609
        Iterator cur = Begin();
#line 609
        cur += pos;
#line 609
        return cur;
    };
    
#line 608
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 608
        int pos = GetPos(it);
#line 608
        Insert(pos, key, value);
#line 608
        Iterator cur = Begin();
#line 608
        cur += pos;
#line 608
        return cur;
    };
    
#line 607
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 607
        int pos = GetPos(it);
#line 607
        Insert(pos, key, value);
#line 607
        Iterator cur = Begin();
#line 607
        cur += pos;
#line 607
        return cur;
    };
    
#line 578
    template < class _1, class _2 >
    inline bool VectorMap < _1, _2 >::IsEmpty() const
    {
#line 578
        return GetCount() == 0;
    };
    
#line 606
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 606
        Remove(GetPos(it));
    };
    
#line 581
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(int i)
    {
        {
#line 581
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 581
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 581
        ;
#line 581
        keys.Remove(i);
#line 581
        values.Remove(i);
    };
    
#line 580
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 580
        int i = Find(key);
#line 580
        if (i >= 0)
#line 580
            Remove(i);
    };
    
#line 572
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Top()
    {
        {
#line 572
            if (!(GetCount() > 0))
            {
#line 572
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 572
        ;
#line 572
        return values.Top();
    };
    
#line 623
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin() const
    {
#line 623
        return Begin();
    };
    
#line 621
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin()
    {
#line 621
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end() const
    {
#line 624
        return End();
    };
    
#line 622
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end()
    {
#line 622
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
    
#line 289
    template < class _1 >
    inline _1& VectorPtr < _1 >::operator[](int i)
    {
#line 289
        return *data[i];
    };
    
#line 290
    template < class _1 >
    inline const _1& VectorPtr < _1 >::operator[](int i) const
    {
#line 290
        return *data[i];
    };
    
#line 285
    template < class _1 >
    inline _1& VectorPtr < _1 >::Add(_1 *o)
    {
#line 285
        data.Add(o);
#line 285
        return *o;
    };
    
#line 287
    template < class _1 >
    inline void VectorPtr < _1 >::Append(const VectorPtr& v)
    {
#line 287
        data.Append(v.data);
    };
    
#line 288
    template < class _1 >
    inline void VectorPtr < _1 >::Append(const VectorPtr& v, int i, int n)
    {
#line 288
        data.Append(v.data, i, n);
    };
    
#line 295
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > VectorPtr < _1 >::Begin()
    {
#line 295
        return Lang::FwdPtrIterator < _1 > (data.Get());
    };
    
#line 292
    template < class _1 >
    inline void VectorPtr < _1 >::Clear()
    {
#line 292
        data.Clear();
    };
    
#line 296
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > VectorPtr < _1 >::End()
    {
#line 296
        return Lang::FwdPtrIterator < _1 > (data.GetEnd());
    };
    
#line 286
    template < class _1 >
    inline int VectorPtr < _1 >::GetCount() const
    {
#line 286
        return data.GetCount();
    };
    
#line 298
    template < class _1 >
    inline Text::String VectorPtr < _1 >::Join(Text::String join_str, bool ignore_empty) const
    {
#line 299
        Text::String out;
        ConstIterator end = data.End();
        for (ConstIterator it = data.Begin(); it != end; ++ it)
            {
#line 302
                Text::String s = Text::ToString < _1 > (**it);
                if (s.IsEmpty() && ignore_empty)
                    continue;
                
#line 305
                if (!out.IsEmpty())
                    out << join_str;
                out << s;
            }
        return out;
    };
    
#line 293
    template < class _1 >
    inline _1 *VectorPtr < _1 >::Pop()
    {
#line 293
        return data.Pop();
    };
    
#line 291
    template < class _1 >
    inline _1 *& VectorPtr < _1 >::Ref(int i)
    {
#line 291
        return data[i];
    };
    
    template < class _1 >
    inline void VectorPtr < _1 >::SetCount(int i)
    {
#line 294
        data.SetCount(i, 0);
    };
    
};

#endif
