#ifndef CONTAINER_HXX
#define CONTAINER_HXX

#include <new>

#ifndef TEXT_HXX
#include <Text.hxx>
#endif

namespace Container
{
#line 655 "../../src/Com/Container.fog"
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
#line 332
        typedef Lang::ConstFwdPtrIterator < _1 > CIterator;
        typedef Lang::ConstBwdPtrIterator < _1 > CRIterator;
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
#line 336
        inline Array();
        inline ~Array();
#line 434
        inline Array < _1 > & operator<< (const _1& v);
#line 427
        inline void operator<<= (const Array& a);
#line 387
        inline _1& operator[](int i);
#line 393
        inline const _1& operator[](int i) const;
#line 378
        inline _1& Add();
#line 380
        inline _1& Add(_1 *k);
#line 379
        inline _1& Add(const _1& v);
#line 348
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 346
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 414
        inline void Clear();
#line 385
        inline _1 *Detach(int i);
#line 349
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 347
        inline Lang::FwdPtrIterator < _1 > End();
#line 341
        inline _1 **Get() const;
#line 343
        inline const _1 **GetConst() const;
        inline const _1 **GetConstEnd() const;
#line 383
        inline int GetCount() const;
#line 342
        inline _1 **GetEnd() const;
#line 381
        inline _1& Insert(int i);
        inline _1& Insert(int i, const _1& key);
#line 384
        inline bool IsEmpty() const;
#line 354
        inline Lang::BwdPtrIterator < _1 > RBegin();
#line 356
        inline Lang::ConstBwdPtrIterator < _1 > RBegin() const;
#line 355
        inline Lang::BwdPtrIterator < _1 > REnd();
#line 357
        inline Lang::ConstBwdPtrIterator < _1 > REnd() const;
#line 404
        inline void Remove(const int *sorted_list, int n);
#line 398
        inline void Remove(int i);
#line 413
        inline void RemoveLast();
#line 363
        inline void Reserve(int i);
        inline void SetCount(int new_count);
#line 423
        inline _1& Top();
#line 352
        inline Lang::ConstFwdPtrIterator < _1 > begin() const;
#line 350
        inline Lang::FwdPtrIterator < _1 > begin();
#line 353
        inline Lang::ConstFwdPtrIterator < _1 > end() const;
#line 351
        inline Lang::FwdPtrIterator < _1 > end();
#line 358
        inline Lang::BwdPtrIterator < _1 > rbegin();
#line 360
        inline Lang::ConstBwdPtrIterator < _1 > rbegin() const;
#line 359
        inline Lang::BwdPtrIterator < _1 > rend();
#line 361
        inline Lang::ConstBwdPtrIterator < _1 > rend() const;
    };
    
    template < class _1 >
    struct FixedArray2
    {
#line 683
        _1 vector[2];
        
#line 688
        inline void operator= (const FixedArray2& value);
#line 687
        inline void operator= (const _1& value);
#line 685
        inline _1& operator[](int i);
        inline const _1& operator[](int i) const;
        
#line 681
        static const int size;
    };
    
    template < class _1 >
    class Index
    {
    public:
#line 447
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 443
        Lang::DynArray < unsigned int > hashes;
        Lang::DynArray < _1 > values;
        
    public:
#line 450
        inline Index();
#line 505
        inline void operator<<= (const Index& a);
#line 461
        inline const _1& operator[](int i) const;
#line 471
        inline const _1& Add(const _1& value);
#line 456
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 452
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 500
        inline void Clear();
#line 457
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 454
        inline Lang::FwdPtrIterator < _1 > End();
#line 485
        inline int Find(const _1& key) const;
        inline int FindAdd(const _1& key);
#line 488
        inline int FindHash(Lang::uint32 hash) const;
#line 458
        inline _1 *Get();
#line 470
        inline int GetCount() const;
#line 459
        inline _1 *GetEnd();
#line 478
        inline _1& Insert(int i, const _1& value);
#line 501
        inline void Remove(int i);
#line 503
        inline void RemoveKey(const _1& key);
#line 502
        inline void RemoveLast();
#line 466
        inline void Set(const Index& i);
#line 453
        inline Lang::FwdPtrIterator < _1 > begin();
#line 455
        inline Lang::FwdPtrIterator < _1 > end();
    };
    
    template < class _1, class _2 >
    class ArrayMap
    {
    public:
#line 517
        typedef Array < _2 > ArrayV;
#line 516
        typedef Index < _1 > IndexK;
#line 617
        typedef Lang::FwdPairPtrIterator < _1, _2 > Iterator;
#line 518
        typedef ArrayMap < _1, _2 > MapKV;
#line 618
        typedef Lang::BwdPairPtrIterator < _1, _2 > RIterator;
        
#line 512
        Index < _1 > keys;
        Array < _2 > values;
        
    public:
#line 520
        inline ArrayMap();
#line 581
        inline void operator<<= (const ArrayMap& a);
#line 564
        inline _2& operator[](int i);
#line 563
        inline const _2& operator[](int i) const;
#line 526
        inline _2& Add(const _1& key);
#line 536
        inline _2& Add(const _1& key, _2 *value);
#line 531
        inline _2& Add(const _1& key, const _2& value);
#line 558
        inline _2& At(int i);
#line 553
        inline const _2& At(int i) const;
#line 638
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > Begin() const;
#line 636
        inline Lang::FwdPairPtrIterator < _1, _2 > Begin();
#line 576
        inline void Clear();
#line 639
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > End() const;
#line 637
        inline Lang::FwdPairPtrIterator < _1, _2 > End();
#line 568
        inline int Find(const _1& key) const;
#line 629
        inline Lang::FwdPairPtrIterator < _1, _2 > FindIterator(const _1& key) const;
#line 570
        inline _2 Get(const _1& key, _2 value);
#line 569
        inline _2& Get(const _1& key);
#line 541
        inline _2& GetAdd(const _1& key);
#line 571
        inline int GetCount() const;
#line 551
        inline const _1& GetKey(int i) const;
#line 522
        inline const Index < _1 > & GetKeys() const;
#line 619
        inline int GetPos(const Iterator& it);
#line 524
        inline Array < _2 > & GetValues();
#line 523
        inline const Array < _2 > & GetValues() const;
#line 548
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 628
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 627
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 626
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 572
        inline bool IsEmpty() const;
#line 625
        inline void Remove(const Iterator& it);
#line 575
        inline void Remove(int i);
#line 574
        inline void RemoveKey(const _1& key);
#line 566
        inline _2& Top();
#line 642
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > begin() const;
#line 640
        inline Lang::FwdPairPtrIterator < _1, _2 > begin();
#line 643
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > end() const;
#line 641
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
#line 807
        Lang::DynArray < Lang::DynArray < int > > data;
        Lang::DynArray < Lang::uint64 > value_mask;
        int count;
        int first_data_i;
        
#line 837
        void Add(int key, int value);
#line 820
        void Clear();
#line 812
        void Reserve(int count);
    };
    
    struct TopValueSorter10
    {
#line 698
        typedef int Key;
        typedef double Value;
        
        Key key[10];
        Value value[10];
        int count;
        
#line 706
        inline TopValueSorter10();
#line 714
        void Add(const Key& key, const Value& value);
#line 707
        void Reset();
#line 730
        void Serialize(Abstract::StreamBase& s);
        
#line 697
        static const int size;
    };
    
    template < class _1 >
    class TreeArray
    {
    public:
#line 745
        typedef TreeArray < _1 > PA;
        
#line 748
        PA *down;
        Array < _1 > branch;
        
    public:
#line 761
        inline _1& Add(_1 *n);
#line 770
        inline _1& At(int i);
#line 772
        inline _1& At(int i, _1& n);
        inline const _1& At(int i) const;
#line 771
        inline _1& AtTop(int i);
#line 764
        inline void Clear();
#line 768
        inline _1 *Detach(int i);
#line 776
        inline int GetCount() const;
#line 760
        inline _1 *GetParent() const;
#line 762
        inline _1& Insert(int i, _1 *n);
#line 777
        inline bool IsEmpty() const;
#line 765
        inline void Remove(int i);
        inline void Remove(int i, int count);
        inline void RemoveLast();
#line 786
        inline void Serialize(Abstract::StreamBase& s);
#line 779
        inline void SortByInt();
#line 774
        inline _1& Top();
        
    protected:
#line 753
        inline _1& Add();
#line 756
        inline void Copy(const PA& src);
#line 754
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
#line 866
        typedef Vector < _1 > Vec;
        
#line 867
        Vector < _1 > data;
        int count;
        
#line 872
        inline _1& operator[](int i);
#line 871
        inline const _1& operator[](int i) const;
#line 876
        inline typename Lang::FwdIterator < _1 > Begin();
#line 878
        inline typename Lang::FwdIterator < _1 > End();
#line 873
        inline int GetCount() const;
        void SetCount(int i);
        inline typename Lang::FwdIterator < _1 > begin();
#line 877
        inline typename Lang::FwdIterator < _1 > end();
    };
    
    template < class _1, class _2 >
    class VectorMap
    {
    public:
#line 517
        typedef Vector < _2 > ArrayV;
#line 516
        typedef Index < _1 > IndexK;
#line 588
        typedef Lang::FwdPairIterator < _1, _2 > Iterator;
#line 518
        typedef VectorMap < _1, _2 > MapKV;
#line 589
        typedef Lang::BwdPairIterator < _1, _2 > RIterator;
        
#line 512
        Index < _1 > keys;
        Vector < _2 > values;
        
    public:
#line 520
        inline VectorMap();
#line 581
        inline void operator<<= (const VectorMap& a);
#line 564
        inline _2& operator[](int i);
#line 563
        inline const _2& operator[](int i) const;
#line 526
        inline _2& Add(const _1& key);
#line 536
        inline _2& Add(const _1& key, _2 *value);
#line 531
        inline _2& Add(const _1& key, const _2& value);
#line 558
        inline _2& At(int i);
#line 553
        inline const _2& At(int i) const;
#line 609
        inline Lang::ConstFwdPairIterator < _1, _2 > Begin() const;
#line 607
        inline Lang::FwdPairIterator < _1, _2 > Begin();
#line 576
        inline void Clear();
#line 610
        inline Lang::ConstFwdPairIterator < _1, _2 > End() const;
#line 608
        inline Lang::FwdPairIterator < _1, _2 > End();
#line 568
        inline int Find(const _1& key) const;
#line 600
        inline Lang::FwdPairIterator < _1, _2 > FindIterator(const _1& key) const;
#line 570
        inline _2 Get(const _1& key, _2 value);
#line 569
        inline _2& Get(const _1& key);
#line 541
        inline _2& GetAdd(const _1& key);
#line 571
        inline int GetCount() const;
#line 551
        inline const _1& GetKey(int i) const;
#line 522
        inline const Index < _1 > & GetKeys() const;
#line 590
        inline int GetPos(const Iterator& it);
#line 524
        inline Vector < _2 > & GetValues();
#line 523
        inline const Vector < _2 > & GetValues() const;
#line 548
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 599
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 598
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 597
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 572
        inline bool IsEmpty() const;
#line 596
        inline void Remove(const Iterator& it);
#line 575
        inline void Remove(int i);
#line 574
        inline void RemoveKey(const _1& key);
#line 566
        inline _2& Top();
#line 613
        inline Lang::ConstFwdPairIterator < _1, _2 > begin() const;
#line 611
        inline Lang::FwdPairIterator < _1, _2 > begin();
#line 614
        inline Lang::ConstFwdPairIterator < _1, _2 > end() const;
#line 612
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
#line 655
    template < class _1, class _2 >
    inline _1 FindIf(_1 first, _1 last, _2 pred)
    {
#line 657
        while (first != last)
            {
#line 658
                int i = pred._2::operator()(*first);
                if (i)
#line 659
                    return first;
#line 661
                ++ first;
            }
#line 664
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
    
#line 336
    template < class _1 >
    inline Array < _1 >::Array() {};
    
#line 337
    template < class _1 >
    inline Array < _1 >::~Array()
    {
#line 337
        Clear();
    };
    
#line 434
    template < class _1 >
    inline Array < _1 > & Array < _1 >::operator<< (const _1& v)
    {
#line 434
        Add(v);
#line 434
        return *this;
    };
    
#line 427
    template < class _1 >
    inline void Array < _1 >::operator<<= (const Array& a)
    {
#line 428
        Clear();
        l.SetCount(a.GetCount(), 0);
        for (int i = 0; i < a.GetCount(); i ++ )
            l[i] = new _1(*a.l[i]);
    };
    
#line 387
    template < class _1 >
    inline _1& Array < _1 >::operator[](int i)
    {
        {
#line 388
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 388
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 389
        ;
#line 389
        _1 * *it = l.Get();
        it = it + i;
        return **it;
    };
    
#line 393
    template < class _1 >
    inline const _1& Array < _1 >::operator[](int i) const
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
        return **(l.Get() + i);
    };
    
#line 378
    template < class _1 >
    inline _1& Array < _1 >::Add()
    {
#line 378
        _1 * k = new _1;
#line 378
        l.Add(k);
#line 378
        return *k;
    };
    
#line 380
    template < class _1 >
    inline _1& Array < _1 >::Add(_1 *k)
    {
#line 380
        l.Add(k);
#line 380
        return *k;
    };
    
#line 379
    template < class _1 >
    inline _1& Array < _1 >::Add(const _1& v)
    {
#line 379
        _1 * k = new _1(v);
#line 379
        l.Add(k);
#line 379
        return *k;
    };
    
#line 348
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::Begin() const
    {
#line 348
        return CIterator((const _1 * *) l.Get());
    };
    
#line 346
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::Begin()
    {
#line 346
        return Iterator(l.Get());
    };
    
#line 414
    template < class _1 >
    inline void Array < _1 >::Clear()
    {
#line 415
        Lang::DynArray < _1 * > tmp;
        Swap(tmp, l);
        _1 * *ptr = tmp.Get();
        _1 * *end = ptr + tmp.GetCount();
        while (ptr != end)
            delete *(ptr ++ );
    };
    
#line 385
    template < class _1 >
    inline _1 *Array < _1 >::Detach(int i)
    {
#line 385
        _1 * o = l[i];
#line 385
        l.Remove(i);
#line 385
        return o;
    };
    
#line 349
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::End() const
    {
#line 349
        return CIterator((const _1 * *) l.GetEnd());
    };
    
#line 347
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::End()
    {
#line 347
        return Iterator(l.GetEnd());
    };
    
#line 341
    template < class _1 >
    inline _1 **Array < _1 >::Get() const
    {
#line 341
        return l.Get();
    };
    
#line 343
    template < class _1 >
    inline const _1 **Array < _1 >::GetConst() const
    {
#line 343
        return l.Get();
    };
    
#line 344
    template < class _1 >
    inline const _1 **Array < _1 >::GetConstEnd() const
    {
#line 344
        return l.GetEnd();
    };
    
#line 383
    template < class _1 >
    inline int Array < _1 >::GetCount() const
    {
#line 383
        return l.GetCount();
    };
    
#line 342
    template < class _1 >
    inline _1 **Array < _1 >::GetEnd() const
    {
#line 342
        return l.GetEnd();
    };
    
#line 381
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i)
    {
#line 381
        return *l.Insert(i, new _1);
    };
    
#line 382
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i, const _1& key)
    {
#line 382
        return *l.Insert(i, new _1(key));
    };
    
#line 384
    template < class _1 >
    inline bool Array < _1 >::IsEmpty() const
    {
#line 384
        return GetCount() == 0;
    };
    
#line 354
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::RBegin()
    {
#line 354
        return RIterator(l.GetEnd() - 1);
    };
    
#line 356
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::RBegin() const
    {
#line 356
        return CRIterator(l.GetConstEnd() - 1);
    };
    
#line 355
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::REnd()
    {
#line 355
        return RIterator(l.Get() - 1);
    };
    
#line 357
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::REnd() const
    {
#line 357
        return CRIterator(l.GetConst() - 1);
    };
    
#line 404
    template < class _1 >
    inline void Array < _1 >::Remove(const int *sorted_list, int n)
    {
#line 405
        if (!n)
#line 405
            return;
        const int * it = sorted_list;
        const int * end = sorted_list + n;
        _1 * *vector = l.Get();
        while (it != end)
            Lang::Destruct(**(vector + *it ++ ));
        l.Remove(sorted_list, n);
    };
    
#line 398
    template < class _1 >
    inline void Array < _1 >::Remove(int i)
    {
        {
#line 399
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 399
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 400
        ;
#line 400
        delete *(l.Get() + i);
        l.Remove(i);
    };
    
#line 413
    template < class _1 >
    inline void Array < _1 >::RemoveLast()
    {
        {
#line 413
            if (!(GetCount()))
            {
#line 413
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 413
        ;
#line 413
        Remove(GetCount() - 1);
    };
    
#line 363
    template < class _1 >
    inline void Array < _1 >::Reserve(int i)
    {
#line 363
        l.Reserve(i);
    };
    
#line 364
    template < class _1 >
    inline void Array < _1 >::SetCount(int new_count)
    {
#line 365
        int count = l.GetCount();
        if (new_count == count)
#line 366
            return;
        if (new_count > count)
        {
#line 368
            l.SetCount(new_count);
            for (int i = count; i < new_count; i ++ )
                l[i] = new _1;
        }
        else
        {
#line 373
            for (int i = count - 1; i >= new_count; i -- )
                delete l[i];
            l.SetCount(new_count);
        }
    };
    
#line 423
    template < class _1 >
    inline _1& Array < _1 >::Top()
    {
        {
#line 424
            if (!(GetCount() > 0))
            {
#line 424
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 425
        ;
#line 425
        return **(l.Get() + l.GetCount() - 1);
    };
    
#line 352
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::begin() const
    {
#line 352
        return Begin();
    };
    
#line 350
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::begin()
    {
#line 350
        return Begin();
    };
    
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::end() const
    {
#line 353
        return End();
    };
    
#line 351
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::end()
    {
#line 351
        return End();
    };
    
#line 358
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rbegin()
    {
#line 358
        return RBegin();
    };
    
#line 360
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rbegin() const
    {
#line 360
        return RBegin();
    };
    
#line 359
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rend()
    {
#line 359
        return REnd();
    };
    
#line 361
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rend() const
    {
#line 361
        return REnd();
    };
    
#line 520
    template < class _1, class _2 >
    inline ArrayMap < _1, _2 >::ArrayMap() {};
    
#line 581
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::operator<<= (const ArrayMap& a)
    {
#line 582
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 564
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::operator[](int i)
    {
#line 564
        return At(i);
    };
    
#line 563
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::operator[](int i) const
    {
#line 563
        return At(i);
    };
    
#line 526
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key)
    {
#line 527
        keys.Add(key);
        return values.Add();
    };
    
#line 536
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 537
        keys.Add(key);
        return values.Add(value);
    };
    
#line 531
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 532
        keys.Add(key);
        return values.Add(value);
    };
    
#line 558
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::At(int i)
    {
        {
#line 559
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 559
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 560
        ;
#line 560
        return values[i];
    };
    
#line 553
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::At(int i) const
    {
        {
#line 554
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 554
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 555
        ;
#line 555
        return values[i];
    };
    
#line 638
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin() const
    {
#line 638
        return Iterator(keys.Get(), values.Get());
    };
    
#line 636
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin()
    {
#line 636
        return Iterator(keys.Get(), values.Get());
    };
    
#line 576
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Clear()
    {
#line 577
        keys.Clear();
        values.Clear();
    };
    
#line 639
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End() const
    {
#line 639
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 637
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End()
    {
#line 637
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 568
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::Find(const _1& key) const
    {
#line 568
        return keys.Find(key);
    };
    
#line 629
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 630
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 632
            it += GetCount();
        else
#line 633
            it += pos;
        return it;
    };
    
#line 570
    template < class _1, class _2 >
    inline _2 ArrayMap < _1, _2 >::Get(const _1& key, _2 value)
    {
#line 570
        int i = Find(key);
#line 570
        if (i < 0)
#line 570
            return value;
#line 570
        return values[i];
    };
    
#line 569
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Get(const _1& key)
    {
#line 569
        return values[Find(key)];
    };
    
#line 541
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 542
        int i = keys.Find(key);
        if (i >= 0)
#line 543
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 571
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetCount() const
    {
#line 571
        return keys.GetCount();
    };
    
#line 551
    template < class _1, class _2 >
    inline const _1& ArrayMap < _1, _2 >::GetKey(int i) const
    {
#line 551
        return keys[i];
    };
    
#line 522
    template < class _1, class _2 >
    inline const Index < _1 > & ArrayMap < _1, _2 >::GetKeys() const
    {
#line 522
        return keys;
    };
    
#line 619
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 620
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 524
    template < class _1, class _2 >
    inline Array < _2 > & ArrayMap < _1, _2 >::GetValues()
    {
#line 524
        return values;
    };
    
#line 523
    template < class _1, class _2 >
    inline const Array < _2 > & ArrayMap < _1, _2 >::GetValues() const
    {
#line 523
        return values;
    };
    
#line 548
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 548
        keys.Insert(i, key);
#line 548
        return values.Insert(i);
    };
    
#line 549
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 549
        keys.Insert(i, key);
#line 549
        return values.Insert(i, value);
    };
    
#line 628
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 628
        int pos = GetPos(it);
#line 628
        Insert(pos, key);
#line 628
        Iterator cur = Begin();
#line 628
        cur += pos;
#line 628
        return cur;
    };
    
#line 627
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 627
        int pos = GetPos(it);
#line 627
        Insert(pos, key, value);
#line 627
        Iterator cur = Begin();
#line 627
        cur += pos;
#line 627
        return cur;
    };
    
#line 626
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 626
        int pos = GetPos(it);
#line 626
        Insert(pos, key, value);
#line 626
        Iterator cur = Begin();
#line 626
        cur += pos;
#line 626
        return cur;
    };
    
#line 572
    template < class _1, class _2 >
    inline bool ArrayMap < _1, _2 >::IsEmpty() const
    {
#line 572
        return GetCount() == 0;
    };
    
#line 625
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 625
        Remove(GetPos(it));
    };
    
#line 575
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(int i)
    {
        {
#line 575
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 575
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 575
        ;
#line 575
        keys.Remove(i);
#line 575
        values.Remove(i);
    };
    
#line 574
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 574
        int i = Find(key);
#line 574
        if (i >= 0)
#line 574
            Remove(i);
    };
    
#line 566
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Top()
    {
        {
#line 566
            if (!(GetCount() > 0))
            {
#line 566
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 566
        ;
#line 566
        return values.Top();
    };
    
#line 642
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin() const
    {
#line 642
        return Begin();
    };
    
#line 640
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin()
    {
#line 640
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end() const
    {
#line 643
        return End();
    };
    
#line 641
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end()
    {
#line 641
        return End();
    };
    
#line 872
    template < class _1 >
    inline _1& CachingVector < _1 >::operator[](int i)
    {
#line 872
        return data[i];
    };
    
#line 871
    template < class _1 >
    inline const _1& CachingVector < _1 >::operator[](int i) const
    {
#line 871
        return data[i];
    };
    
#line 876
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::Begin()
    {
#line 876
        return data.begin();
    };
    
#line 878
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::End()
    {
#line 878
        return data.begin() + count;
    };
    
#line 873
    template < class _1 >
    inline int CachingVector < _1 >::GetCount() const
    {
#line 873
        return count;
    };
    
#line 875
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::begin()
    {
#line 875
        return data.begin();
    };
    
#line 877
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::end()
    {
#line 877
        return data.begin() + count;
    };
    
#line 688
    template < class _1 >
    inline void FixedArray2 < _1 >::operator= (const FixedArray2& value)
    {
#line 688
        for (int i = 0; i < size; i ++ )
#line 688
            this -> vector[i] = value.vector[i];
    };
    
#line 687
    template < class _1 >
    inline void FixedArray2 < _1 >::operator= (const _1& value)
    {
#line 687
        for (int i = 0; i < size; i ++ )
#line 687
            this -> vector[i] = value;
    };
    
#line 685
    template < class _1 >
    inline _1& FixedArray2 < _1 >::operator[](int i)
    {
        {
#line 685
            if (!(i >= 0 && i < size))
            {
#line 685
                Lang::SysBreak("Assertion failed: i >= 0 && i < size");
            }
        }
#line 685
        ;
#line 685
        return vector[i];
    };
    
#line 686
    template < class _1 >
    inline const _1& FixedArray2 < _1 >::operator[](int i) const
    {
        {
#line 686
            if (!(i >= 0 && i < size))
            {
#line 686
                Lang::SysBreak("Assertion failed: i >= 0 && i < size");
            }
        }
#line 686
        ;
#line 686
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
    
#line 450
    template < class _1 >
    inline Index < _1 >::Index() {};
    
#line 505
    template < class _1 >
    inline void Index < _1 >::operator<<= (const Index& a)
    {
#line 505
        Set(a);
    };
    
#line 461
    template < class _1 >
    inline const _1& Index < _1 >::operator[](int i) const
    {
        {
#line 462
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 462
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 463
        ;
#line 463
        return values[i];
    };
    
#line 471
    template < class _1 >
    inline const _1& Index < _1 >::Add(const _1& value)
    {
#line 472
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Add(hash);
        return values.Add(value);
    };
    
#line 456
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::Begin() const
    {
#line 456
        return Iterator(values.Begin());
    };
    
#line 452
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::Begin()
    {
#line 452
        return Iterator(values.Begin());
    };
    
#line 500
    template < class _1 >
    inline void Index < _1 >::Clear()
    {
#line 500
        hashes.Clear();
#line 500
        values.Clear();
    };
    
#line 457
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::End() const
    {
#line 457
        return Iterator(values.End());
    };
    
#line 454
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::End()
    {
#line 454
        return Iterator(values.End());
    };
    
#line 485
    template < class _1 >
    inline int Index < _1 >::Find(const _1& key) const
    {
#line 485
        return FindHash(Hash::GetValue(key));
    };
    
#line 486
    template < class _1 >
    inline int Index < _1 >::FindAdd(const _1& key)
    {
#line 486
        int i = Find(key);
#line 486
        if (i >= 0)
#line 486
            return i;
#line 486
        i = GetCount();
#line 486
        Add(key);
#line 486
        return i;
    };
    
#line 488
    template < class _1 >
    inline int Index < _1 >::FindHash(Lang::uint32 hash) const
    {
#line 489
        unsigned int * begin = hashes.Get();
        unsigned int * it = begin;
        unsigned int * end = begin + hashes.GetCount();
        while (it != end)
            {
#line 493
                if (*it == hash)
                    return it - begin;
                it ++ ;
            }
        return - 1;
    };
    
#line 458
    template < class _1 >
    inline _1 *Index < _1 >::Get()
    {
#line 458
        return values.Get();
    };
    
#line 470
    template < class _1 >
    inline int Index < _1 >::GetCount() const
    {
#line 470
        return values.GetCount();
    };
    
#line 459
    template < class _1 >
    inline _1 *Index < _1 >::GetEnd()
    {
#line 459
        return values.GetEnd();
    };
    
#line 478
    template < class _1 >
    inline _1& Index < _1 >::Insert(int i, const _1& value)
    {
#line 479
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Insert(i, hash);
        return values.Insert(i, value);
    };
    
#line 501
    template < class _1 >
    inline void Index < _1 >::Remove(int i)
    {
#line 501
        hashes.Remove(i);
#line 501
        values.Remove(i);
    };
    
#line 503
    template < class _1 >
    inline void Index < _1 >::RemoveKey(const _1& key)
    {
#line 503
        int i = Find(key);
#line 503
        if (i >= 0)
#line 503
            Remove(i);
    };
    
#line 502
    template < class _1 >
    inline void Index < _1 >::RemoveLast()
    {
        {
#line 502
            if (!(GetCount()))
            {
#line 502
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 502
        ;
#line 502
        if (GetCount())
#line 502
            Remove(GetCount() - 1);
    };
    
#line 466
    template < class _1 >
    inline void Index < _1 >::Set(const Index& i)
    {
#line 467
        hashes <<= i.hashes;
        values <<= i.values;
    };
    
#line 453
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::begin()
    {
#line 453
        return Iterator(values.Begin());
    };
    
#line 455
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::end()
    {
#line 455
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
    
#line 706
    inline TopValueSorter10::TopValueSorter10()
    :
        count(0)
    {
#line 706
        Reset();
    };
    
#line 753
    template < class _1 >
    inline _1& TreeArray < _1 >::Add()
    {
#line 753
        _1 & t = branch.Add();
#line 753
        t.down = this;
#line 753
        return t;
    };
    
#line 761
    template < class _1 >
    inline _1& TreeArray < _1 >::Add(_1 *n)
    {
        {
#line 761
            if (!(n -> down == 0))
            {
#line 761
                Lang::SysBreak("Assertion failed: n->down == NULL");
            }
        }
#line 761
        ;
#line 761
        _1 & t = branch.Add(n);
#line 761
        t.down = this;
#line 761
        return t;
    };
    
#line 770
    template < class _1 >
    inline _1& TreeArray < _1 >::At(int i)
    {
#line 770
        return branch[i];
    };
    
#line 772
    template < class _1 >
    inline _1& TreeArray < _1 >::At(int i, _1& n)
    {
#line 772
        if (i < branch.GetCount())
#line 772
            return branch[i];
#line 772
        return n;
    };
    
#line 773
    template < class _1 >
    inline const _1& TreeArray < _1 >::At(int i) const
    {
#line 773
        return branch[i];
    };
    
#line 771
    template < class _1 >
    inline _1& TreeArray < _1 >::AtTop(int i)
    {
#line 771
        if (i < branch.GetCount())
#line 771
            return branch[i];
#line 771
        return branch.Top();
    };
    
#line 764
    template < class _1 >
    inline void TreeArray < _1 >::Clear()
    {
#line 764
        branch.Clear();
    };
    
#line 756
    template < class _1 >
    inline void TreeArray < _1 >::Copy(const PA& src)
    {
#line 756
        branch <<= src.branch;
#line 756
        for (int i = 0; i < branch.GetCount(); i ++ )
#line 756
            branch[i].down = this;
    };
    
#line 768
    template < class _1 >
    inline _1 *TreeArray < _1 >::Detach(int i)
    {
#line 768
        _1 * t = branch.Detach(i);
#line 768
        t -> down = 0;
#line 768
        return t;
    };
    
#line 776
    template < class _1 >
    inline int TreeArray < _1 >::GetCount() const
    {
#line 776
        return branch.GetCount();
    };
    
#line 760
    template < class _1 >
    inline _1 *TreeArray < _1 >::GetParent() const
    {
#line 760
        return down;
    };
    
#line 754
    template < class _1 >
    inline _1& TreeArray < _1 >::Insert(int i)
    {
#line 754
        _1 & t = branch.Insert(i);
#line 754
        t.down = this;
#line 754
        return t;
    };
    
#line 762
    template < class _1 >
    inline _1& TreeArray < _1 >::Insert(int i, _1 *n)
    {
        {
#line 762
            if (!(n -> down == 0))
            {
#line 762
                Lang::SysBreak("Assertion failed: n->down == NULL");
            }
        }
#line 762
        ;
#line 762
        _1 & t = branch.Insert(i, n);
#line 762
        t.down = this;
#line 762
        return t;
    };
    
#line 777
    template < class _1 >
    inline bool TreeArray < _1 >::IsEmpty() const
    {
#line 777
        return branch.IsEmpty();
    };
    
#line 765
    template < class _1 >
    inline void TreeArray < _1 >::Remove(int i)
    {
#line 765
        branch.Remove(i);
    };
    
#line 766
    template < class _1 >
    inline void TreeArray < _1 >::Remove(int i, int count)
    {
#line 766
        branch.Remove(i, count);
    };
    
#line 767
    template < class _1 >
    inline void TreeArray < _1 >::RemoveLast()
    {
#line 767
        branch.Remove(branch.GetCount() - 1);
    };
    
#line 786
    template < class _1 >
    inline void TreeArray < _1 >::Serialize(Abstract::StreamBase& s)
    {
#line 787
        s % branch;
        if (s.IsLoading())
            for (int i = 0; i < branch.GetCount(); i ++ )
                branch[i].down = this;
    };
    
#line 779
    template < class _1 >
    inline void TreeArray < _1 >::SortByInt()
    {
#line 780
        struct Sorter;
#line 783
        Sort(branch, Sorter());
    };
    
#line 774
    template < class _1 >
    inline _1& TreeArray < _1 >::Top()
    {
#line 774
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
    
#line 520
    template < class _1, class _2 >
    inline VectorMap < _1, _2 >::VectorMap() {};
    
#line 581
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::operator<<= (const VectorMap& a)
    {
#line 582
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 564
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::operator[](int i)
    {
#line 564
        return At(i);
    };
    
#line 563
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::operator[](int i) const
    {
#line 563
        return At(i);
    };
    
#line 526
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key)
    {
#line 527
        keys.Add(key);
        return values.Add();
    };
    
#line 536
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 537
        keys.Add(key);
        return values.Add(value);
    };
    
#line 531
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 532
        keys.Add(key);
        return values.Add(value);
    };
    
#line 558
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::At(int i)
    {
        {
#line 559
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 559
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 560
        ;
#line 560
        return values[i];
    };
    
#line 553
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::At(int i) const
    {
        {
#line 554
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 554
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 555
        ;
#line 555
        return values[i];
    };
    
#line 609
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin() const
    {
#line 609
        return Iterator(keys.Get(), values.Get());
    };
    
#line 607
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin()
    {
#line 607
        return Iterator(keys.Get(), values.Get());
    };
    
#line 576
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Clear()
    {
#line 577
        keys.Clear();
        values.Clear();
    };
    
#line 610
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End() const
    {
#line 610
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 608
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End()
    {
#line 608
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 568
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::Find(const _1& key) const
    {
#line 568
        return keys.Find(key);
    };
    
#line 600
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 601
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 603
            it += GetCount();
        else
#line 604
            it += pos;
        return it;
    };
    
#line 570
    template < class _1, class _2 >
    inline _2 VectorMap < _1, _2 >::Get(const _1& key, _2 value)
    {
#line 570
        int i = Find(key);
#line 570
        if (i < 0)
#line 570
            return value;
#line 570
        return values[i];
    };
    
#line 569
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Get(const _1& key)
    {
#line 569
        return values[Find(key)];
    };
    
#line 541
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 542
        int i = keys.Find(key);
        if (i >= 0)
#line 543
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 571
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetCount() const
    {
#line 571
        return keys.GetCount();
    };
    
#line 551
    template < class _1, class _2 >
    inline const _1& VectorMap < _1, _2 >::GetKey(int i) const
    {
#line 551
        return keys[i];
    };
    
#line 522
    template < class _1, class _2 >
    inline const Index < _1 > & VectorMap < _1, _2 >::GetKeys() const
    {
#line 522
        return keys;
    };
    
#line 590
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 591
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 524
    template < class _1, class _2 >
    inline Vector < _2 > & VectorMap < _1, _2 >::GetValues()
    {
#line 524
        return values;
    };
    
#line 523
    template < class _1, class _2 >
    inline const Vector < _2 > & VectorMap < _1, _2 >::GetValues() const
    {
#line 523
        return values;
    };
    
#line 548
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 548
        keys.Insert(i, key);
#line 548
        return values.Insert(i);
    };
    
#line 549
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 549
        keys.Insert(i, key);
#line 549
        return values.Insert(i, value);
    };
    
#line 599
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 599
        int pos = GetPos(it);
#line 599
        Insert(pos, key);
#line 599
        Iterator cur = Begin();
#line 599
        cur += pos;
#line 599
        return cur;
    };
    
#line 598
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 598
        int pos = GetPos(it);
#line 598
        Insert(pos, key, value);
#line 598
        Iterator cur = Begin();
#line 598
        cur += pos;
#line 598
        return cur;
    };
    
#line 597
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 597
        int pos = GetPos(it);
#line 597
        Insert(pos, key, value);
#line 597
        Iterator cur = Begin();
#line 597
        cur += pos;
#line 597
        return cur;
    };
    
#line 572
    template < class _1, class _2 >
    inline bool VectorMap < _1, _2 >::IsEmpty() const
    {
#line 572
        return GetCount() == 0;
    };
    
#line 596
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 596
        Remove(GetPos(it));
    };
    
#line 575
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(int i)
    {
        {
#line 575
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 575
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 575
        ;
#line 575
        keys.Remove(i);
#line 575
        values.Remove(i);
    };
    
#line 574
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 574
        int i = Find(key);
#line 574
        if (i >= 0)
#line 574
            Remove(i);
    };
    
#line 566
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Top()
    {
        {
#line 566
            if (!(GetCount() > 0))
            {
#line 566
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 566
        ;
#line 566
        return values.Top();
    };
    
#line 613
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin() const
    {
#line 613
        return Begin();
    };
    
#line 611
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin()
    {
#line 611
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end() const
    {
#line 614
        return End();
    };
    
#line 612
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end()
    {
#line 612
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
