#ifndef CONTAINER_HXX
#define CONTAINER_HXX

#include <new>

#ifndef TEXT_HXX
#include <Text.hxx>
#endif

namespace Container
{
#line 651 "../../src/Com/Container.fog"
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
#line 329
        typedef const _1 ConstK;
#line 328
        typedef _1 IndirectK;
#line 330
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 324
        Lang::DynArray < _1 * > l;
        
    public:
#line 334
        inline Array();
        inline ~Array();
#line 430
        inline Array < _1 > & operator<< (const _1& v);
#line 423
        inline void operator<<= (const Array& a);
#line 383
        inline _1& operator[](int i);
#line 389
        inline const _1& operator[](int i) const;
#line 374
        inline _1& Add();
#line 376
        inline _1& Add(_1 *k);
#line 375
        inline _1& Add(const _1& v);
#line 344
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 342
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 410
        inline void Clear();
#line 381
        inline _1 *Detach(int i);
#line 345
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 343
        inline Lang::FwdPtrIterator < _1 > End();
#line 339
        inline _1 **Get() const;
#line 379
        inline int GetCount() const;
#line 340
        inline _1 **GetEnd() const;
#line 377
        inline _1& Insert(int i);
        inline _1& Insert(int i, const _1& key);
#line 380
        inline bool IsEmpty() const;
#line 350
        inline Lang::BwdPtrIterator < _1 > RBegin();
#line 352
        inline Lang::ConstBwdPtrIterator < _1 > RBegin() const;
#line 351
        inline Lang::BwdPtrIterator < _1 > REnd();
#line 353
        inline Lang::ConstBwdPtrIterator < _1 > REnd() const;
#line 400
        inline void Remove(const int *sorted_list, int n);
#line 394
        inline void Remove(int i);
#line 409
        inline void RemoveLast();
#line 359
        inline void Reserve(int i);
        inline void SetCount(int new_count);
#line 419
        inline _1& Top();
#line 348
        inline Lang::ConstFwdPtrIterator < _1 > begin() const;
#line 346
        inline Lang::FwdPtrIterator < _1 > begin();
#line 349
        inline Lang::ConstFwdPtrIterator < _1 > end() const;
#line 347
        inline Lang::FwdPtrIterator < _1 > end();
#line 354
        inline Lang::BwdPtrIterator < _1 > rbegin();
#line 356
        inline Lang::ConstBwdPtrIterator < _1 > rbegin() const;
#line 355
        inline Lang::BwdPtrIterator < _1 > rend();
#line 357
        inline Lang::ConstBwdPtrIterator < _1 > rend() const;
    };
    
    template < class _1 >
    struct FixedArray2
    {
#line 679
        _1 vector[2];
        
#line 684
        inline void operator= (const FixedArray2& value);
#line 683
        inline void operator= (const _1& value);
#line 681
        inline _1& operator[](int i);
        inline const _1& operator[](int i) const;
        
#line 677
        static const int size;
    };
    
    template < class _1 >
    class Index
    {
    public:
#line 443
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 439
        Lang::DynArray < unsigned int > hashes;
        Lang::DynArray < _1 > values;
        
    public:
#line 446
        inline Index();
#line 501
        inline void operator<<= (const Index& a);
#line 457
        inline const _1& operator[](int i) const;
#line 467
        inline const _1& Add(const _1& value);
#line 452
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 448
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 496
        inline void Clear();
#line 453
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 450
        inline Lang::FwdPtrIterator < _1 > End();
#line 481
        inline int Find(const _1& key) const;
        inline int FindAdd(const _1& key);
#line 484
        inline int FindHash(Lang::uint32 hash) const;
#line 454
        inline _1 *Get();
#line 466
        inline int GetCount() const;
#line 455
        inline _1 *GetEnd();
#line 474
        inline _1& Insert(int i, const _1& value);
#line 497
        inline void Remove(int i);
#line 499
        inline void RemoveKey(const _1& key);
#line 498
        inline void RemoveLast();
#line 462
        inline void Set(const Index& i);
#line 449
        inline Lang::FwdPtrIterator < _1 > begin();
#line 451
        inline Lang::FwdPtrIterator < _1 > end();
    };
    
    template < class _1, class _2 >
    class ArrayMap
    {
    public:
#line 513
        typedef Array < _2 > ArrayV;
#line 512
        typedef Index < _1 > IndexK;
#line 613
        typedef Lang::FwdPairPtrIterator < _1, _2 > Iterator;
#line 514
        typedef ArrayMap < _1, _2 > MapKV;
#line 614
        typedef Lang::BwdPairPtrIterator < _1, _2 > RIterator;
        
#line 508
        Index < _1 > keys;
        Array < _2 > values;
        
    public:
#line 516
        inline ArrayMap();
#line 577
        inline void operator<<= (const ArrayMap& a);
#line 560
        inline _2& operator[](int i);
#line 559
        inline const _2& operator[](int i) const;
#line 522
        inline _2& Add(const _1& key);
#line 532
        inline _2& Add(const _1& key, _2 *value);
#line 527
        inline _2& Add(const _1& key, const _2& value);
#line 554
        inline _2& At(int i);
#line 549
        inline const _2& At(int i) const;
#line 634
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > Begin() const;
#line 632
        inline Lang::FwdPairPtrIterator < _1, _2 > Begin();
#line 572
        inline void Clear();
#line 635
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > End() const;
#line 633
        inline Lang::FwdPairPtrIterator < _1, _2 > End();
#line 564
        inline int Find(const _1& key) const;
#line 625
        inline Lang::FwdPairPtrIterator < _1, _2 > FindIterator(const _1& key) const;
#line 566
        inline _2 Get(const _1& key, _2 value);
#line 565
        inline _2& Get(const _1& key);
#line 537
        inline _2& GetAdd(const _1& key);
#line 567
        inline int GetCount() const;
#line 547
        inline const _1& GetKey(int i) const;
#line 518
        inline const Index < _1 > & GetKeys() const;
#line 615
        inline int GetPos(const Iterator& it);
#line 520
        inline Array < _2 > & GetValues();
#line 519
        inline const Array < _2 > & GetValues() const;
#line 544
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 624
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 623
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 622
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 568
        inline bool IsEmpty() const;
#line 621
        inline void Remove(const Iterator& it);
#line 571
        inline void Remove(int i);
#line 570
        inline void RemoveKey(const _1& key);
#line 562
        inline _2& Top();
#line 638
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > begin() const;
#line 636
        inline Lang::FwdPairPtrIterator < _1, _2 > begin();
#line 639
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > end() const;
#line 637
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
#line 803
        Lang::DynArray < Lang::DynArray < int > > data;
        Lang::DynArray < Lang::uint64 > value_mask;
        int count;
        int first_data_i;
        
#line 833
        void Add(int key, int value);
#line 816
        void Clear();
#line 808
        void Reserve(int count);
    };
    
    struct TopValueSorter10
    {
#line 694
        typedef int Key;
        typedef double Value;
        
        Key key[10];
        Value value[10];
        int count;
        
#line 702
        inline TopValueSorter10();
#line 710
        void Add(const Key& key, const Value& value);
#line 703
        void Reset();
#line 726
        void Serialize(Abstract::StreamBase& s);
        
#line 693
        static const int size;
    };
    
    template < class _1 >
    class TreeArray
    {
    public:
#line 741
        typedef TreeArray < _1 > PA;
        
#line 744
        PA *down;
        Array < _1 > branch;
        
    public:
#line 757
        inline _1& Add(_1 *n);
#line 766
        inline _1& At(int i);
#line 768
        inline _1& At(int i, _1& n);
        inline const _1& At(int i) const;
#line 767
        inline _1& AtTop(int i);
#line 760
        inline void Clear();
#line 764
        inline _1 *Detach(int i);
#line 772
        inline int GetCount() const;
#line 756
        inline _1 *GetParent() const;
#line 758
        inline _1& Insert(int i, _1 *n);
#line 773
        inline bool IsEmpty() const;
#line 761
        inline void Remove(int i);
        inline void Remove(int i, int count);
        inline void RemoveLast();
#line 782
        inline void Serialize(Abstract::StreamBase& s);
#line 775
        inline void SortByInt();
#line 770
        inline _1& Top();
        
    protected:
#line 749
        inline _1& Add();
#line 752
        inline void Copy(const PA& src);
#line 750
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
#line 862
        typedef Vector < _1 > Vec;
        
#line 863
        Vector < _1 > data;
        int count;
        
#line 868
        inline _1& operator[](int i);
#line 867
        inline const _1& operator[](int i) const;
#line 872
        inline typename Lang::FwdIterator < _1 > Begin();
#line 874
        inline typename Lang::FwdIterator < _1 > End();
#line 869
        inline int GetCount() const;
        void SetCount(int i);
        inline typename Lang::FwdIterator < _1 > begin();
#line 873
        inline typename Lang::FwdIterator < _1 > end();
    };
    
    template < class _1, class _2 >
    class VectorMap
    {
    public:
#line 513
        typedef Vector < _2 > ArrayV;
#line 512
        typedef Index < _1 > IndexK;
#line 584
        typedef Lang::FwdPairIterator < _1, _2 > Iterator;
#line 514
        typedef VectorMap < _1, _2 > MapKV;
#line 585
        typedef Lang::BwdPairIterator < _1, _2 > RIterator;
        
#line 508
        Index < _1 > keys;
        Vector < _2 > values;
        
    public:
#line 516
        inline VectorMap();
#line 577
        inline void operator<<= (const VectorMap& a);
#line 560
        inline _2& operator[](int i);
#line 559
        inline const _2& operator[](int i) const;
#line 522
        inline _2& Add(const _1& key);
#line 532
        inline _2& Add(const _1& key, _2 *value);
#line 527
        inline _2& Add(const _1& key, const _2& value);
#line 554
        inline _2& At(int i);
#line 549
        inline const _2& At(int i) const;
#line 605
        inline Lang::ConstFwdPairIterator < _1, _2 > Begin() const;
#line 603
        inline Lang::FwdPairIterator < _1, _2 > Begin();
#line 572
        inline void Clear();
#line 606
        inline Lang::ConstFwdPairIterator < _1, _2 > End() const;
#line 604
        inline Lang::FwdPairIterator < _1, _2 > End();
#line 564
        inline int Find(const _1& key) const;
#line 596
        inline Lang::FwdPairIterator < _1, _2 > FindIterator(const _1& key) const;
#line 566
        inline _2 Get(const _1& key, _2 value);
#line 565
        inline _2& Get(const _1& key);
#line 537
        inline _2& GetAdd(const _1& key);
#line 567
        inline int GetCount() const;
#line 547
        inline const _1& GetKey(int i) const;
#line 518
        inline const Index < _1 > & GetKeys() const;
#line 586
        inline int GetPos(const Iterator& it);
#line 520
        inline Vector < _2 > & GetValues();
#line 519
        inline const Vector < _2 > & GetValues() const;
#line 544
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 595
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 594
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 593
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 568
        inline bool IsEmpty() const;
#line 592
        inline void Remove(const Iterator& it);
#line 571
        inline void Remove(int i);
#line 570
        inline void RemoveKey(const _1& key);
#line 562
        inline _2& Top();
#line 609
        inline Lang::ConstFwdPairIterator < _1, _2 > begin() const;
#line 607
        inline Lang::FwdPairIterator < _1, _2 > begin();
#line 610
        inline Lang::ConstFwdPairIterator < _1, _2 > end() const;
#line 608
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
#line 288
        inline _1& operator[](int i);
        inline const _1& operator[](int i) const;
#line 285
        inline _1& Add(_1 *o);
#line 287
        inline void Append(const VectorPtr& v);
#line 290
        inline void Clear();
#line 286
        inline int GetCount() const;
#line 292
        inline Text::String Join(Text::String join_str = "", bool ignore_empty = true) const;
    };
};

namespace Container
{
#line 651
    template < class _1, class _2 >
    inline _1 FindIf(_1 first, _1 last, _2 pred)
    {
#line 653
        while (first != last)
            {
#line 654
                int i = pred._2::operator()(*first);
                if (i)
#line 655
                    return first;
#line 657
                ++ first;
            }
#line 660
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
    
#line 334
    template < class _1 >
    inline Array < _1 >::Array() {};
    
#line 335
    template < class _1 >
    inline Array < _1 >::~Array()
    {
#line 335
        Clear();
    };
    
#line 430
    template < class _1 >
    inline Array < _1 > & Array < _1 >::operator<< (const _1& v)
    {
#line 430
        Add(v);
#line 430
        return *this;
    };
    
#line 423
    template < class _1 >
    inline void Array < _1 >::operator<<= (const Array& a)
    {
#line 424
        Clear();
        l.SetCount(a.GetCount(), 0);
        for (int i = 0; i < a.GetCount(); i ++ )
            l[i] = new _1(*a.l[i]);
    };
    
#line 383
    template < class _1 >
    inline _1& Array < _1 >::operator[](int i)
    {
        {
#line 384
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 384
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 385
        ;
#line 385
        _1 * *it = l.Get();
        it = it + i;
        return **it;
    };
    
#line 389
    template < class _1 >
    inline const _1& Array < _1 >::operator[](int i) const
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
        return **(l.Get() + i);
    };
    
#line 374
    template < class _1 >
    inline _1& Array < _1 >::Add()
    {
#line 374
        _1 * k = new _1;
#line 374
        l.Add(k);
#line 374
        return *k;
    };
    
#line 376
    template < class _1 >
    inline _1& Array < _1 >::Add(_1 *k)
    {
#line 376
        l.Add(k);
#line 376
        return *k;
    };
    
#line 375
    template < class _1 >
    inline _1& Array < _1 >::Add(const _1& v)
    {
#line 375
        _1 * k = new _1(v);
#line 375
        l.Add(k);
#line 375
        return *k;
    };
    
#line 344
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::Begin() const
    {
#line 344
        return Iterator(l.Begin());
    };
    
#line 342
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::Begin()
    {
#line 342
        return Iterator(l.Begin());
    };
    
#line 410
    template < class _1 >
    inline void Array < _1 >::Clear()
    {
#line 411
        Lang::DynArray < _1 * > tmp;
        Swap(tmp, l);
        _1 * *ptr = tmp.Get();
        _1 * *end = ptr + tmp.GetCount();
        while (ptr != end)
            delete *(ptr ++ );
    };
    
#line 381
    template < class _1 >
    inline _1 *Array < _1 >::Detach(int i)
    {
#line 381
        _1 * o = l[i];
#line 381
        l.Remove(i);
#line 381
        return o;
    };
    
#line 345
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::End() const
    {
#line 345
        return Iterator(l.End());
    };
    
#line 343
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::End()
    {
#line 343
        return Iterator(l.End());
    };
    
#line 339
    template < class _1 >
    inline _1 **Array < _1 >::Get() const
    {
#line 339
        return l.Get();
    };
    
#line 379
    template < class _1 >
    inline int Array < _1 >::GetCount() const
    {
#line 379
        return l.GetCount();
    };
    
#line 340
    template < class _1 >
    inline _1 **Array < _1 >::GetEnd() const
    {
#line 340
        return l.GetEnd();
    };
    
#line 377
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i)
    {
#line 377
        return *l.Insert(i, new _1);
    };
    
#line 378
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i, const _1& key)
    {
#line 378
        return *l.Insert(i, new _1(key));
    };
    
#line 380
    template < class _1 >
    inline bool Array < _1 >::IsEmpty() const
    {
#line 380
        return GetCount() == 0;
    };
    
#line 350
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::RBegin()
    {
#line 350
        return RIterator(l.End() - 1);
    };
    
#line 352
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::RBegin() const
    {
#line 352
        return RIterator(l.End() - 1);
    };
    
#line 351
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::REnd()
    {
#line 351
        return RIterator(l.Begin() - 1);
    };
    
#line 353
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::REnd() const
    {
#line 353
        return RIterator(l.Begin() - 1);
    };
    
#line 400
    template < class _1 >
    inline void Array < _1 >::Remove(const int *sorted_list, int n)
    {
#line 401
        if (!n)
#line 401
            return;
        const int * it = sorted_list;
        const int * end = sorted_list + n;
        _1 * *vector = l.Get();
        while (it != end)
            Lang::Destruct(**(vector + *it ++ ));
        l.Remove(sorted_list, n);
    };
    
#line 394
    template < class _1 >
    inline void Array < _1 >::Remove(int i)
    {
        {
#line 395
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 395
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 396
        ;
#line 396
        delete *(l.Get() + i);
        l.Remove(i);
    };
    
#line 409
    template < class _1 >
    inline void Array < _1 >::RemoveLast()
    {
        {
#line 409
            if (!(GetCount()))
            {
#line 409
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 409
        ;
#line 409
        Remove(GetCount() - 1);
    };
    
#line 359
    template < class _1 >
    inline void Array < _1 >::Reserve(int i)
    {
#line 359
        l.Reserve(i);
    };
    
#line 360
    template < class _1 >
    inline void Array < _1 >::SetCount(int new_count)
    {
#line 361
        int count = l.GetCount();
        if (new_count == count)
#line 362
            return;
        if (new_count > count)
        {
#line 364
            l.SetCount(new_count);
            for (int i = count; i < new_count; i ++ )
                l[i] = new _1;
        }
        else
        {
#line 369
            for (int i = count - 1; i >= new_count; i -- )
                delete l[i];
            l.SetCount(new_count);
        }
    };
    
#line 419
    template < class _1 >
    inline _1& Array < _1 >::Top()
    {
        {
#line 420
            if (!(GetCount() > 0))
            {
#line 420
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 421
        ;
#line 421
        return **(l.Get() + l.GetCount() - 1);
    };
    
#line 348
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::begin() const
    {
#line 348
        return Begin();
    };
    
#line 346
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::begin()
    {
#line 346
        return Begin();
    };
    
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::end() const
    {
#line 349
        return End();
    };
    
#line 347
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::end()
    {
#line 347
        return End();
    };
    
#line 354
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rbegin()
    {
#line 354
        return RBegin();
    };
    
#line 356
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rbegin() const
    {
#line 356
        return RBegin();
    };
    
#line 355
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rend()
    {
#line 355
        return REnd();
    };
    
#line 357
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rend() const
    {
#line 357
        return REnd();
    };
    
#line 516
    template < class _1, class _2 >
    inline ArrayMap < _1, _2 >::ArrayMap() {};
    
#line 577
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::operator<<= (const ArrayMap& a)
    {
#line 578
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 560
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::operator[](int i)
    {
#line 560
        return At(i);
    };
    
#line 559
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::operator[](int i) const
    {
#line 559
        return At(i);
    };
    
#line 522
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key)
    {
#line 523
        keys.Add(key);
        return values.Add();
    };
    
#line 532
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 533
        keys.Add(key);
        return values.Add(value);
    };
    
#line 527
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 528
        keys.Add(key);
        return values.Add(value);
    };
    
#line 554
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::At(int i)
    {
        {
#line 555
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 555
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 556
        ;
#line 556
        return values[i];
    };
    
#line 549
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::At(int i) const
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
    
#line 634
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin() const
    {
#line 634
        return Iterator(keys.Get(), values.Get());
    };
    
#line 632
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin()
    {
#line 632
        return Iterator(keys.Get(), values.Get());
    };
    
#line 572
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Clear()
    {
#line 573
        keys.Clear();
        values.Clear();
    };
    
#line 635
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End() const
    {
#line 635
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 633
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End()
    {
#line 633
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 564
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::Find(const _1& key) const
    {
#line 564
        return keys.Find(key);
    };
    
#line 625
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 626
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 628
            it += GetCount();
        else
#line 629
            it += pos;
        return it;
    };
    
#line 566
    template < class _1, class _2 >
    inline _2 ArrayMap < _1, _2 >::Get(const _1& key, _2 value)
    {
#line 566
        int i = Find(key);
#line 566
        if (i < 0)
#line 566
            return value;
#line 566
        return values[i];
    };
    
#line 565
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Get(const _1& key)
    {
#line 565
        return values[Find(key)];
    };
    
#line 537
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 538
        int i = keys.Find(key);
        if (i >= 0)
#line 539
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 567
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetCount() const
    {
#line 567
        return keys.GetCount();
    };
    
#line 547
    template < class _1, class _2 >
    inline const _1& ArrayMap < _1, _2 >::GetKey(int i) const
    {
#line 547
        return keys[i];
    };
    
#line 518
    template < class _1, class _2 >
    inline const Index < _1 > & ArrayMap < _1, _2 >::GetKeys() const
    {
#line 518
        return keys;
    };
    
#line 615
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 616
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 520
    template < class _1, class _2 >
    inline Array < _2 > & ArrayMap < _1, _2 >::GetValues()
    {
#line 520
        return values;
    };
    
#line 519
    template < class _1, class _2 >
    inline const Array < _2 > & ArrayMap < _1, _2 >::GetValues() const
    {
#line 519
        return values;
    };
    
#line 544
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 544
        keys.Insert(i, key);
#line 544
        return values.Insert(i);
    };
    
#line 545
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 545
        keys.Insert(i, key);
#line 545
        return values.Insert(i, value);
    };
    
#line 624
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 624
        int pos = GetPos(it);
#line 624
        Insert(pos, key);
#line 624
        Iterator cur = Begin();
#line 624
        cur += pos;
#line 624
        return cur;
    };
    
#line 623
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 623
        int pos = GetPos(it);
#line 623
        Insert(pos, key, value);
#line 623
        Iterator cur = Begin();
#line 623
        cur += pos;
#line 623
        return cur;
    };
    
#line 622
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 622
        int pos = GetPos(it);
#line 622
        Insert(pos, key, value);
#line 622
        Iterator cur = Begin();
#line 622
        cur += pos;
#line 622
        return cur;
    };
    
#line 568
    template < class _1, class _2 >
    inline bool ArrayMap < _1, _2 >::IsEmpty() const
    {
#line 568
        return GetCount() == 0;
    };
    
#line 621
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 621
        Remove(GetPos(it));
    };
    
#line 571
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(int i)
    {
        {
#line 571
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 571
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 571
        ;
#line 571
        keys.Remove(i);
#line 571
        values.Remove(i);
    };
    
#line 570
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 570
        int i = Find(key);
#line 570
        if (i >= 0)
#line 570
            Remove(i);
    };
    
#line 562
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Top()
    {
        {
#line 562
            if (!(GetCount() > 0))
            {
#line 562
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 562
        ;
#line 562
        return values.Top();
    };
    
#line 638
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin() const
    {
#line 638
        return Begin();
    };
    
#line 636
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin()
    {
#line 636
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end() const
    {
#line 639
        return End();
    };
    
#line 637
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end()
    {
#line 637
        return End();
    };
    
#line 868
    template < class _1 >
    inline _1& CachingVector < _1 >::operator[](int i)
    {
#line 868
        return data[i];
    };
    
#line 867
    template < class _1 >
    inline const _1& CachingVector < _1 >::operator[](int i) const
    {
#line 867
        return data[i];
    };
    
#line 872
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::Begin()
    {
#line 872
        return data.begin();
    };
    
#line 874
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::End()
    {
#line 874
        return data.begin() + count;
    };
    
#line 869
    template < class _1 >
    inline int CachingVector < _1 >::GetCount() const
    {
#line 869
        return count;
    };
    
#line 871
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::begin()
    {
#line 871
        return data.begin();
    };
    
#line 873
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::end()
    {
#line 873
        return data.begin() + count;
    };
    
#line 684
    template < class _1 >
    inline void FixedArray2 < _1 >::operator= (const FixedArray2& value)
    {
#line 684
        for (int i = 0; i < size; i ++ )
#line 684
            this -> vector[i] = value.vector[i];
    };
    
#line 683
    template < class _1 >
    inline void FixedArray2 < _1 >::operator= (const _1& value)
    {
#line 683
        for (int i = 0; i < size; i ++ )
#line 683
            this -> vector[i] = value;
    };
    
#line 681
    template < class _1 >
    inline _1& FixedArray2 < _1 >::operator[](int i)
    {
        {
#line 681
            if (!(i >= 0 && i < size))
            {
#line 681
                Lang::SysBreak("Assertion failed: i >= 0 && i < size");
            }
        }
#line 681
        ;
#line 681
        return vector[i];
    };
    
#line 682
    template < class _1 >
    inline const _1& FixedArray2 < _1 >::operator[](int i) const
    {
        {
#line 682
            if (!(i >= 0 && i < size))
            {
#line 682
                Lang::SysBreak("Assertion failed: i >= 0 && i < size");
            }
        }
#line 682
        ;
#line 682
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
    
#line 446
    template < class _1 >
    inline Index < _1 >::Index() {};
    
#line 501
    template < class _1 >
    inline void Index < _1 >::operator<<= (const Index& a)
    {
#line 501
        Set(a);
    };
    
#line 457
    template < class _1 >
    inline const _1& Index < _1 >::operator[](int i) const
    {
        {
#line 458
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 458
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 459
        ;
#line 459
        return values[i];
    };
    
#line 467
    template < class _1 >
    inline const _1& Index < _1 >::Add(const _1& value)
    {
#line 468
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Add(hash);
        return values.Add(value);
    };
    
#line 452
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::Begin() const
    {
#line 452
        return Iterator(values.Begin());
    };
    
#line 448
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::Begin()
    {
#line 448
        return Iterator(values.Begin());
    };
    
#line 496
    template < class _1 >
    inline void Index < _1 >::Clear()
    {
#line 496
        hashes.Clear();
#line 496
        values.Clear();
    };
    
#line 453
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::End() const
    {
#line 453
        return Iterator(values.End());
    };
    
#line 450
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::End()
    {
#line 450
        return Iterator(values.End());
    };
    
#line 481
    template < class _1 >
    inline int Index < _1 >::Find(const _1& key) const
    {
#line 481
        return FindHash(Hash::GetValue(key));
    };
    
#line 482
    template < class _1 >
    inline int Index < _1 >::FindAdd(const _1& key)
    {
#line 482
        int i = Find(key);
#line 482
        if (i >= 0)
#line 482
            return i;
#line 482
        i = GetCount();
#line 482
        Add(key);
#line 482
        return i;
    };
    
#line 484
    template < class _1 >
    inline int Index < _1 >::FindHash(Lang::uint32 hash) const
    {
#line 485
        unsigned int * begin = hashes.Get();
        unsigned int * it = begin;
        unsigned int * end = begin + hashes.GetCount();
        while (it != end)
            {
#line 489
                if (*it == hash)
                    return it - begin;
                it ++ ;
            }
        return - 1;
    };
    
#line 454
    template < class _1 >
    inline _1 *Index < _1 >::Get()
    {
#line 454
        return values.Get();
    };
    
#line 466
    template < class _1 >
    inline int Index < _1 >::GetCount() const
    {
#line 466
        return values.GetCount();
    };
    
#line 455
    template < class _1 >
    inline _1 *Index < _1 >::GetEnd()
    {
#line 455
        return values.GetEnd();
    };
    
#line 474
    template < class _1 >
    inline _1& Index < _1 >::Insert(int i, const _1& value)
    {
#line 475
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Insert(i, hash);
        return values.Insert(i, value);
    };
    
#line 497
    template < class _1 >
    inline void Index < _1 >::Remove(int i)
    {
#line 497
        hashes.Remove(i);
#line 497
        values.Remove(i);
    };
    
#line 499
    template < class _1 >
    inline void Index < _1 >::RemoveKey(const _1& key)
    {
#line 499
        int i = Find(key);
#line 499
        if (i >= 0)
#line 499
            Remove(i);
    };
    
#line 498
    template < class _1 >
    inline void Index < _1 >::RemoveLast()
    {
        {
#line 498
            if (!(GetCount()))
            {
#line 498
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 498
        ;
#line 498
        if (GetCount())
#line 498
            Remove(GetCount() - 1);
    };
    
#line 462
    template < class _1 >
    inline void Index < _1 >::Set(const Index& i)
    {
#line 463
        hashes <<= i.hashes;
        values <<= i.values;
    };
    
#line 449
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::begin()
    {
#line 449
        return Iterator(values.Begin());
    };
    
#line 451
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::end()
    {
#line 451
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
    
#line 702
    inline TopValueSorter10::TopValueSorter10()
    :
        count(0)
    {
#line 702
        Reset();
    };
    
#line 749
    template < class _1 >
    inline _1& TreeArray < _1 >::Add()
    {
#line 749
        _1 & t = branch.Add();
#line 749
        t.down = this;
#line 749
        return t;
    };
    
#line 757
    template < class _1 >
    inline _1& TreeArray < _1 >::Add(_1 *n)
    {
        {
#line 757
            if (!(n -> down == 0))
            {
#line 757
                Lang::SysBreak("Assertion failed: n->down == NULL");
            }
        }
#line 757
        ;
#line 757
        _1 & t = branch.Add(n);
#line 757
        t.down = this;
#line 757
        return t;
    };
    
#line 766
    template < class _1 >
    inline _1& TreeArray < _1 >::At(int i)
    {
#line 766
        return branch[i];
    };
    
#line 768
    template < class _1 >
    inline _1& TreeArray < _1 >::At(int i, _1& n)
    {
#line 768
        if (i < branch.GetCount())
#line 768
            return branch[i];
#line 768
        return n;
    };
    
#line 769
    template < class _1 >
    inline const _1& TreeArray < _1 >::At(int i) const
    {
#line 769
        return branch[i];
    };
    
#line 767
    template < class _1 >
    inline _1& TreeArray < _1 >::AtTop(int i)
    {
#line 767
        if (i < branch.GetCount())
#line 767
            return branch[i];
#line 767
        return branch.Top();
    };
    
#line 760
    template < class _1 >
    inline void TreeArray < _1 >::Clear()
    {
#line 760
        branch.Clear();
    };
    
#line 752
    template < class _1 >
    inline void TreeArray < _1 >::Copy(const PA& src)
    {
#line 752
        branch <<= src.branch;
#line 752
        for (int i = 0; i < branch.GetCount(); i ++ )
#line 752
            branch[i].down = this;
    };
    
#line 764
    template < class _1 >
    inline _1 *TreeArray < _1 >::Detach(int i)
    {
#line 764
        _1 * t = branch.Detach(i);
#line 764
        t -> down = 0;
#line 764
        return t;
    };
    
#line 772
    template < class _1 >
    inline int TreeArray < _1 >::GetCount() const
    {
#line 772
        return branch.GetCount();
    };
    
#line 756
    template < class _1 >
    inline _1 *TreeArray < _1 >::GetParent() const
    {
#line 756
        return down;
    };
    
#line 750
    template < class _1 >
    inline _1& TreeArray < _1 >::Insert(int i)
    {
#line 750
        _1 & t = branch.Insert(i);
#line 750
        t.down = this;
#line 750
        return t;
    };
    
#line 758
    template < class _1 >
    inline _1& TreeArray < _1 >::Insert(int i, _1 *n)
    {
        {
#line 758
            if (!(n -> down == 0))
            {
#line 758
                Lang::SysBreak("Assertion failed: n->down == NULL");
            }
        }
#line 758
        ;
#line 758
        _1 & t = branch.Insert(i, n);
#line 758
        t.down = this;
#line 758
        return t;
    };
    
#line 773
    template < class _1 >
    inline bool TreeArray < _1 >::IsEmpty() const
    {
#line 773
        return branch.IsEmpty();
    };
    
#line 761
    template < class _1 >
    inline void TreeArray < _1 >::Remove(int i)
    {
#line 761
        branch.Remove(i);
    };
    
#line 762
    template < class _1 >
    inline void TreeArray < _1 >::Remove(int i, int count)
    {
#line 762
        branch.Remove(i, count);
    };
    
#line 763
    template < class _1 >
    inline void TreeArray < _1 >::RemoveLast()
    {
#line 763
        branch.Remove(branch.GetCount() - 1);
    };
    
#line 782
    template < class _1 >
    inline void TreeArray < _1 >::Serialize(Abstract::StreamBase& s)
    {
#line 783
        s % branch;
        if (s.IsLoading())
            for (int i = 0; i < branch.GetCount(); i ++ )
                branch[i].down = this;
    };
    
#line 775
    template < class _1 >
    inline void TreeArray < _1 >::SortByInt()
    {
#line 776
        struct Sorter;
#line 779
        Sort(branch, Sorter());
    };
    
#line 770
    template < class _1 >
    inline _1& TreeArray < _1 >::Top()
    {
#line 770
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
    
#line 516
    template < class _1, class _2 >
    inline VectorMap < _1, _2 >::VectorMap() {};
    
#line 577
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::operator<<= (const VectorMap& a)
    {
#line 578
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 560
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::operator[](int i)
    {
#line 560
        return At(i);
    };
    
#line 559
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::operator[](int i) const
    {
#line 559
        return At(i);
    };
    
#line 522
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key)
    {
#line 523
        keys.Add(key);
        return values.Add();
    };
    
#line 532
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 533
        keys.Add(key);
        return values.Add(value);
    };
    
#line 527
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 528
        keys.Add(key);
        return values.Add(value);
    };
    
#line 554
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::At(int i)
    {
        {
#line 555
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 555
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 556
        ;
#line 556
        return values[i];
    };
    
#line 549
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::At(int i) const
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
    
#line 605
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin() const
    {
#line 605
        return Iterator(keys.Get(), values.Get());
    };
    
#line 603
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin()
    {
#line 603
        return Iterator(keys.Get(), values.Get());
    };
    
#line 572
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Clear()
    {
#line 573
        keys.Clear();
        values.Clear();
    };
    
#line 606
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End() const
    {
#line 606
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 604
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End()
    {
#line 604
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 564
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::Find(const _1& key) const
    {
#line 564
        return keys.Find(key);
    };
    
#line 596
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 597
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 599
            it += GetCount();
        else
#line 600
            it += pos;
        return it;
    };
    
#line 566
    template < class _1, class _2 >
    inline _2 VectorMap < _1, _2 >::Get(const _1& key, _2 value)
    {
#line 566
        int i = Find(key);
#line 566
        if (i < 0)
#line 566
            return value;
#line 566
        return values[i];
    };
    
#line 565
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Get(const _1& key)
    {
#line 565
        return values[Find(key)];
    };
    
#line 537
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 538
        int i = keys.Find(key);
        if (i >= 0)
#line 539
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 567
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetCount() const
    {
#line 567
        return keys.GetCount();
    };
    
#line 547
    template < class _1, class _2 >
    inline const _1& VectorMap < _1, _2 >::GetKey(int i) const
    {
#line 547
        return keys[i];
    };
    
#line 518
    template < class _1, class _2 >
    inline const Index < _1 > & VectorMap < _1, _2 >::GetKeys() const
    {
#line 518
        return keys;
    };
    
#line 586
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 587
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 520
    template < class _1, class _2 >
    inline Vector < _2 > & VectorMap < _1, _2 >::GetValues()
    {
#line 520
        return values;
    };
    
#line 519
    template < class _1, class _2 >
    inline const Vector < _2 > & VectorMap < _1, _2 >::GetValues() const
    {
#line 519
        return values;
    };
    
#line 544
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 544
        keys.Insert(i, key);
#line 544
        return values.Insert(i);
    };
    
#line 545
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 545
        keys.Insert(i, key);
#line 545
        return values.Insert(i, value);
    };
    
#line 595
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 595
        int pos = GetPos(it);
#line 595
        Insert(pos, key);
#line 595
        Iterator cur = Begin();
#line 595
        cur += pos;
#line 595
        return cur;
    };
    
#line 594
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 594
        int pos = GetPos(it);
#line 594
        Insert(pos, key, value);
#line 594
        Iterator cur = Begin();
#line 594
        cur += pos;
#line 594
        return cur;
    };
    
#line 593
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 593
        int pos = GetPos(it);
#line 593
        Insert(pos, key, value);
#line 593
        Iterator cur = Begin();
#line 593
        cur += pos;
#line 593
        return cur;
    };
    
#line 568
    template < class _1, class _2 >
    inline bool VectorMap < _1, _2 >::IsEmpty() const
    {
#line 568
        return GetCount() == 0;
    };
    
#line 592
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 592
        Remove(GetPos(it));
    };
    
#line 571
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(int i)
    {
        {
#line 571
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 571
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 571
        ;
#line 571
        keys.Remove(i);
#line 571
        values.Remove(i);
    };
    
#line 570
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 570
        int i = Find(key);
#line 570
        if (i >= 0)
#line 570
            Remove(i);
    };
    
#line 562
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Top()
    {
        {
#line 562
            if (!(GetCount() > 0))
            {
#line 562
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 562
        ;
#line 562
        return values.Top();
    };
    
#line 609
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin() const
    {
#line 609
        return Begin();
    };
    
#line 607
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin()
    {
#line 607
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end() const
    {
#line 610
        return End();
    };
    
#line 608
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end()
    {
#line 608
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
    
    template < class _1 >
    inline _1& VectorPtr < _1 >::operator[](int i)
    {
#line 288
        return *data[i];
    };
    
#line 289
    template < class _1 >
    inline const _1& VectorPtr < _1 >::operator[](int i) const
    {
#line 289
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
    
    template < class _1 >
    inline void VectorPtr < _1 >::Clear()
    {
#line 290
        data.Clear();
    };
    
#line 286
    template < class _1 >
    inline int VectorPtr < _1 >::GetCount() const
    {
#line 286
        return data.GetCount();
    };
    
#line 292
    template < class _1 >
    inline Text::String VectorPtr < _1 >::Join(Text::String join_str, bool ignore_empty) const
    {
#line 293
        Text::String out;
        ConstIterator end = data.End();
        for (ConstIterator it = data.Begin(); it != end; ++ it)
            {
#line 296
                Text::String s = Text::ToString < _1 > (**it);
                if (s.IsEmpty() && ignore_empty)
                    continue;
                
#line 299
                if (!out.IsEmpty())
                    out << join_str;
                out << s;
            }
        return out;
    };
    
};

#endif
