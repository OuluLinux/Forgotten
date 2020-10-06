#ifndef CONTAINER_HXX
#define CONTAINER_HXX

#include <new>

#ifndef TEXT_HXX
#include <Text.hxx>
#endif

namespace Container
{
#line 660 "../../src/Com/Container.fog"
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
#line 337
        typedef Lang::ConstFwdPtrIterator < _1 > CIterator;
        typedef Lang::ConstBwdPtrIterator < _1 > CRIterator;
#line 334
        typedef const _1 ConstK;
#line 333
        typedef _1 IndirectK;
#line 335
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 329
        Lang::DynArray < _1 * > l;
        
    public:
#line 341
        inline Array();
        inline ~Array();
#line 439
        inline Array < _1 > & operator<< (const _1& v);
#line 432
        inline void operator<<= (const Array& a);
#line 392
        inline _1& operator[](int i);
#line 398
        inline const _1& operator[](int i) const;
#line 383
        inline _1& Add();
#line 385
        inline _1& Add(_1 *k);
#line 384
        inline _1& Add(const _1& v);
#line 353
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 351
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 419
        inline void Clear();
#line 390
        inline _1 *Detach(int i);
#line 354
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 352
        inline Lang::FwdPtrIterator < _1 > End();
#line 346
        inline _1 **Get() const;
#line 348
        inline const _1 **GetConst() const;
        inline const _1 **GetConstEnd() const;
#line 388
        inline int GetCount() const;
#line 347
        inline _1 **GetEnd() const;
#line 386
        inline _1& Insert(int i);
        inline _1& Insert(int i, const _1& key);
#line 389
        inline bool IsEmpty() const;
#line 359
        inline Lang::BwdPtrIterator < _1 > RBegin();
#line 361
        inline Lang::ConstBwdPtrIterator < _1 > RBegin() const;
#line 360
        inline Lang::BwdPtrIterator < _1 > REnd();
#line 362
        inline Lang::ConstBwdPtrIterator < _1 > REnd() const;
#line 409
        inline void Remove(const int *sorted_list, int n);
#line 403
        inline void Remove(int i);
#line 418
        inline void RemoveLast();
#line 368
        inline void Reserve(int i);
        inline void SetCount(int new_count);
#line 428
        inline _1& Top();
#line 357
        inline Lang::ConstFwdPtrIterator < _1 > begin() const;
#line 355
        inline Lang::FwdPtrIterator < _1 > begin();
#line 358
        inline Lang::ConstFwdPtrIterator < _1 > end() const;
#line 356
        inline Lang::FwdPtrIterator < _1 > end();
#line 363
        inline Lang::BwdPtrIterator < _1 > rbegin();
#line 365
        inline Lang::ConstBwdPtrIterator < _1 > rbegin() const;
#line 364
        inline Lang::BwdPtrIterator < _1 > rend();
#line 366
        inline Lang::ConstBwdPtrIterator < _1 > rend() const;
    };
    
    template < class _1 >
    struct FixedArray2
    {
#line 688
        _1 vector[2];
        
#line 693
        inline void operator= (const FixedArray2& value);
#line 692
        inline void operator= (const _1& value);
#line 690
        inline _1& operator[](int i);
        inline const _1& operator[](int i) const;
        
#line 686
        static const int size;
    };
    
    template < class _1 >
    class Index
    {
    public:
#line 452
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 448
        Lang::DynArray < unsigned int > hashes;
        Lang::DynArray < _1 > values;
        
    public:
#line 455
        inline Index();
#line 510
        inline void operator<<= (const Index& a);
#line 466
        inline const _1& operator[](int i) const;
#line 476
        inline const _1& Add(const _1& value);
#line 461
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 457
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 505
        inline void Clear();
#line 462
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 459
        inline Lang::FwdPtrIterator < _1 > End();
#line 490
        inline int Find(const _1& key) const;
        inline int FindAdd(const _1& key);
#line 493
        inline int FindHash(Lang::uint32 hash) const;
#line 463
        inline _1 *Get();
#line 475
        inline int GetCount() const;
#line 464
        inline _1 *GetEnd();
#line 483
        inline _1& Insert(int i, const _1& value);
#line 506
        inline void Remove(int i);
#line 508
        inline void RemoveKey(const _1& key);
#line 507
        inline void RemoveLast();
#line 471
        inline void Set(const Index& i);
#line 458
        inline Lang::FwdPtrIterator < _1 > begin();
#line 460
        inline Lang::FwdPtrIterator < _1 > end();
    };
    
    template < class _1, class _2 >
    class ArrayMap
    {
    public:
#line 522
        typedef Array < _2 > ArrayV;
#line 521
        typedef Index < _1 > IndexK;
#line 622
        typedef Lang::FwdPairPtrIterator < _1, _2 > Iterator;
#line 523
        typedef ArrayMap < _1, _2 > MapKV;
#line 623
        typedef Lang::BwdPairPtrIterator < _1, _2 > RIterator;
        
#line 517
        Index < _1 > keys;
        Array < _2 > values;
        
    public:
#line 525
        inline ArrayMap();
#line 586
        inline void operator<<= (const ArrayMap& a);
#line 569
        inline _2& operator[](int i);
#line 568
        inline const _2& operator[](int i) const;
#line 531
        inline _2& Add(const _1& key);
#line 541
        inline _2& Add(const _1& key, _2 *value);
#line 536
        inline _2& Add(const _1& key, const _2& value);
#line 563
        inline _2& At(int i);
#line 558
        inline const _2& At(int i) const;
#line 643
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > Begin() const;
#line 641
        inline Lang::FwdPairPtrIterator < _1, _2 > Begin();
#line 581
        inline void Clear();
#line 644
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > End() const;
#line 642
        inline Lang::FwdPairPtrIterator < _1, _2 > End();
#line 573
        inline int Find(const _1& key) const;
#line 634
        inline Lang::FwdPairPtrIterator < _1, _2 > FindIterator(const _1& key) const;
#line 575
        inline _2 Get(const _1& key, _2 value);
#line 574
        inline _2& Get(const _1& key);
#line 546
        inline _2& GetAdd(const _1& key);
#line 576
        inline int GetCount() const;
#line 556
        inline const _1& GetKey(int i) const;
#line 527
        inline const Index < _1 > & GetKeys() const;
#line 624
        inline int GetPos(const Iterator& it);
#line 529
        inline Array < _2 > & GetValues();
#line 528
        inline const Array < _2 > & GetValues() const;
#line 553
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 633
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 632
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 631
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 577
        inline bool IsEmpty() const;
#line 630
        inline void Remove(const Iterator& it);
#line 580
        inline void Remove(int i);
#line 579
        inline void RemoveKey(const _1& key);
#line 571
        inline _2& Top();
#line 647
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > begin() const;
#line 645
        inline Lang::FwdPairPtrIterator < _1, _2 > begin();
#line 648
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > end() const;
#line 646
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
#line 812
        Lang::DynArray < Lang::DynArray < int > > data;
        Lang::DynArray < Lang::uint64 > value_mask;
        int count;
        int first_data_i;
        
#line 842
        void Add(int key, int value);
#line 825
        void Clear();
#line 817
        void Reserve(int count);
    };
    
    struct TopValueSorter10
    {
#line 703
        typedef int Key;
        typedef double Value;
        
        Key key[10];
        Value value[10];
        int count;
        
#line 711
        inline TopValueSorter10();
#line 719
        void Add(const Key& key, const Value& value);
#line 712
        void Reset();
#line 735
        void Serialize(Abstract::StreamBase& s);
        
#line 702
        static const int size;
    };
    
    template < class _1 >
    class TreeArray
    {
    public:
#line 750
        typedef TreeArray < _1 > PA;
        
#line 753
        PA *down;
        Array < _1 > branch;
        
    public:
#line 766
        inline _1& Add(_1 *n);
#line 775
        inline _1& At(int i);
#line 777
        inline _1& At(int i, _1& n);
        inline const _1& At(int i) const;
#line 776
        inline _1& AtTop(int i);
#line 769
        inline void Clear();
#line 773
        inline _1 *Detach(int i);
#line 781
        inline int GetCount() const;
#line 765
        inline _1 *GetParent() const;
#line 767
        inline _1& Insert(int i, _1 *n);
#line 782
        inline bool IsEmpty() const;
#line 770
        inline void Remove(int i);
        inline void Remove(int i, int count);
        inline void RemoveLast();
#line 791
        inline void Serialize(Abstract::StreamBase& s);
#line 784
        inline void SortByInt();
#line 779
        inline _1& Top();
        
    protected:
#line 758
        inline _1& Add();
#line 761
        inline void Copy(const PA& src);
#line 759
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
#line 871
        typedef Vector < _1 > Vec;
        
#line 872
        Vector < _1 > data;
        int count;
        
#line 877
        inline _1& operator[](int i);
#line 876
        inline const _1& operator[](int i) const;
#line 881
        inline typename Lang::FwdIterator < _1 > Begin();
#line 883
        inline typename Lang::FwdIterator < _1 > End();
#line 878
        inline int GetCount() const;
        void SetCount(int i);
        inline typename Lang::FwdIterator < _1 > begin();
#line 882
        inline typename Lang::FwdIterator < _1 > end();
    };
    
    template < class _1, class _2 >
    class VectorMap
    {
    public:
#line 522
        typedef Vector < _2 > ArrayV;
#line 521
        typedef Index < _1 > IndexK;
#line 593
        typedef Lang::FwdPairIterator < _1, _2 > Iterator;
#line 523
        typedef VectorMap < _1, _2 > MapKV;
#line 594
        typedef Lang::BwdPairIterator < _1, _2 > RIterator;
        
#line 517
        Index < _1 > keys;
        Vector < _2 > values;
        
    public:
#line 525
        inline VectorMap();
#line 586
        inline void operator<<= (const VectorMap& a);
#line 569
        inline _2& operator[](int i);
#line 568
        inline const _2& operator[](int i) const;
#line 531
        inline _2& Add(const _1& key);
#line 541
        inline _2& Add(const _1& key, _2 *value);
#line 536
        inline _2& Add(const _1& key, const _2& value);
#line 563
        inline _2& At(int i);
#line 558
        inline const _2& At(int i) const;
#line 614
        inline Lang::ConstFwdPairIterator < _1, _2 > Begin() const;
#line 612
        inline Lang::FwdPairIterator < _1, _2 > Begin();
#line 581
        inline void Clear();
#line 615
        inline Lang::ConstFwdPairIterator < _1, _2 > End() const;
#line 613
        inline Lang::FwdPairIterator < _1, _2 > End();
#line 573
        inline int Find(const _1& key) const;
#line 605
        inline Lang::FwdPairIterator < _1, _2 > FindIterator(const _1& key) const;
#line 575
        inline _2 Get(const _1& key, _2 value);
#line 574
        inline _2& Get(const _1& key);
#line 546
        inline _2& GetAdd(const _1& key);
#line 576
        inline int GetCount() const;
#line 556
        inline const _1& GetKey(int i) const;
#line 527
        inline const Index < _1 > & GetKeys() const;
#line 595
        inline int GetPos(const Iterator& it);
#line 529
        inline Vector < _2 > & GetValues();
#line 528
        inline const Vector < _2 > & GetValues() const;
#line 553
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 604
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 603
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 602
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 577
        inline bool IsEmpty() const;
#line 601
        inline void Remove(const Iterator& it);
#line 580
        inline void Remove(int i);
#line 579
        inline void RemoveKey(const _1& key);
#line 571
        inline _2& Top();
#line 618
        inline Lang::ConstFwdPairIterator < _1, _2 > begin() const;
#line 616
        inline Lang::FwdPairIterator < _1, _2 > begin();
#line 619
        inline Lang::ConstFwdPairIterator < _1, _2 > end() const;
#line 617
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
#line 294
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 291
        inline void Clear();
#line 295
        inline Lang::FwdPtrIterator < _1 > End();
#line 286
        inline int GetCount() const;
#line 297
        inline Text::String Join(Text::String join_str = "", bool ignore_empty = true) const;
#line 292
        inline _1 *Pop();
#line 290
        inline _1 *& Ref(int i);
#line 293
        inline void SetCount(int i);
    };
};

namespace Container
{
#line 660
    template < class _1, class _2 >
    inline _1 FindIf(_1 first, _1 last, _2 pred)
    {
#line 662
        while (first != last)
            {
#line 663
                int i = pred._2::operator()(*first);
                if (i)
#line 664
                    return first;
#line 666
                ++ first;
            }
#line 669
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
    
#line 341
    template < class _1 >
    inline Array < _1 >::Array() {};
    
#line 342
    template < class _1 >
    inline Array < _1 >::~Array()
    {
#line 342
        Clear();
    };
    
#line 439
    template < class _1 >
    inline Array < _1 > & Array < _1 >::operator<< (const _1& v)
    {
#line 439
        Add(v);
#line 439
        return *this;
    };
    
#line 432
    template < class _1 >
    inline void Array < _1 >::operator<<= (const Array& a)
    {
#line 433
        Clear();
        l.SetCount(a.GetCount(), 0);
        for (int i = 0; i < a.GetCount(); i ++ )
            l[i] = new _1(*a.l[i]);
    };
    
#line 392
    template < class _1 >
    inline _1& Array < _1 >::operator[](int i)
    {
        {
#line 393
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 393
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 394
        ;
#line 394
        _1 * *it = l.Get();
        it = it + i;
        return **it;
    };
    
#line 398
    template < class _1 >
    inline const _1& Array < _1 >::operator[](int i) const
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
        return **(l.Get() + i);
    };
    
#line 383
    template < class _1 >
    inline _1& Array < _1 >::Add()
    {
#line 383
        _1 * k = new _1;
#line 383
        l.Add(k);
#line 383
        return *k;
    };
    
#line 385
    template < class _1 >
    inline _1& Array < _1 >::Add(_1 *k)
    {
#line 385
        l.Add(k);
#line 385
        return *k;
    };
    
#line 384
    template < class _1 >
    inline _1& Array < _1 >::Add(const _1& v)
    {
#line 384
        _1 * k = new _1(v);
#line 384
        l.Add(k);
#line 384
        return *k;
    };
    
#line 353
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::Begin() const
    {
#line 353
        return CIterator((const _1 * *) l.Get());
    };
    
#line 351
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::Begin()
    {
#line 351
        return Iterator(l.Get());
    };
    
#line 419
    template < class _1 >
    inline void Array < _1 >::Clear()
    {
#line 420
        Lang::DynArray < _1 * > tmp;
        Swap(tmp, l);
        _1 * *ptr = tmp.Get();
        _1 * *end = ptr + tmp.GetCount();
        while (ptr != end)
            delete *(ptr ++ );
    };
    
#line 390
    template < class _1 >
    inline _1 *Array < _1 >::Detach(int i)
    {
#line 390
        _1 * o = l[i];
#line 390
        l.Remove(i);
#line 390
        return o;
    };
    
#line 354
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::End() const
    {
#line 354
        return CIterator((const _1 * *) l.GetEnd());
    };
    
#line 352
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::End()
    {
#line 352
        return Iterator(l.GetEnd());
    };
    
#line 346
    template < class _1 >
    inline _1 **Array < _1 >::Get() const
    {
#line 346
        return l.Get();
    };
    
#line 348
    template < class _1 >
    inline const _1 **Array < _1 >::GetConst() const
    {
#line 348
        return l.Get();
    };
    
#line 349
    template < class _1 >
    inline const _1 **Array < _1 >::GetConstEnd() const
    {
#line 349
        return l.GetEnd();
    };
    
#line 388
    template < class _1 >
    inline int Array < _1 >::GetCount() const
    {
#line 388
        return l.GetCount();
    };
    
#line 347
    template < class _1 >
    inline _1 **Array < _1 >::GetEnd() const
    {
#line 347
        return l.GetEnd();
    };
    
#line 386
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i)
    {
#line 386
        return *l.Insert(i, new _1);
    };
    
#line 387
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i, const _1& key)
    {
#line 387
        return *l.Insert(i, new _1(key));
    };
    
#line 389
    template < class _1 >
    inline bool Array < _1 >::IsEmpty() const
    {
#line 389
        return GetCount() == 0;
    };
    
#line 359
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::RBegin()
    {
#line 359
        return RIterator(l.GetEnd() - 1);
    };
    
#line 361
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::RBegin() const
    {
#line 361
        return CRIterator(l.GetConstEnd() - 1);
    };
    
#line 360
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::REnd()
    {
#line 360
        return RIterator(l.Get() - 1);
    };
    
#line 362
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::REnd() const
    {
#line 362
        return CRIterator(l.GetConst() - 1);
    };
    
#line 409
    template < class _1 >
    inline void Array < _1 >::Remove(const int *sorted_list, int n)
    {
#line 410
        if (!n)
#line 410
            return;
        const int * it = sorted_list;
        const int * end = sorted_list + n;
        _1 * *vector = l.Get();
        while (it != end)
            Lang::Destruct(**(vector + *it ++ ));
        l.Remove(sorted_list, n);
    };
    
#line 403
    template < class _1 >
    inline void Array < _1 >::Remove(int i)
    {
        {
#line 404
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 404
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 405
        ;
#line 405
        delete *(l.Get() + i);
        l.Remove(i);
    };
    
#line 418
    template < class _1 >
    inline void Array < _1 >::RemoveLast()
    {
        {
#line 418
            if (!(GetCount()))
            {
#line 418
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 418
        ;
#line 418
        Remove(GetCount() - 1);
    };
    
#line 368
    template < class _1 >
    inline void Array < _1 >::Reserve(int i)
    {
#line 368
        l.Reserve(i);
    };
    
#line 369
    template < class _1 >
    inline void Array < _1 >::SetCount(int new_count)
    {
#line 370
        int count = l.GetCount();
        if (new_count == count)
#line 371
            return;
        if (new_count > count)
        {
#line 373
            l.SetCount(new_count);
            for (int i = count; i < new_count; i ++ )
                l[i] = new _1;
        }
        else
        {
#line 378
            for (int i = count - 1; i >= new_count; i -- )
                delete l[i];
            l.SetCount(new_count);
        }
    };
    
#line 428
    template < class _1 >
    inline _1& Array < _1 >::Top()
    {
        {
#line 429
            if (!(GetCount() > 0))
            {
#line 429
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 430
        ;
#line 430
        return **(l.Get() + l.GetCount() - 1);
    };
    
#line 357
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::begin() const
    {
#line 357
        return Begin();
    };
    
#line 355
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::begin()
    {
#line 355
        return Begin();
    };
    
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::end() const
    {
#line 358
        return End();
    };
    
#line 356
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::end()
    {
#line 356
        return End();
    };
    
#line 363
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rbegin()
    {
#line 363
        return RBegin();
    };
    
#line 365
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rbegin() const
    {
#line 365
        return RBegin();
    };
    
#line 364
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rend()
    {
#line 364
        return REnd();
    };
    
#line 366
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rend() const
    {
#line 366
        return REnd();
    };
    
#line 525
    template < class _1, class _2 >
    inline ArrayMap < _1, _2 >::ArrayMap() {};
    
#line 586
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::operator<<= (const ArrayMap& a)
    {
#line 587
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 569
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::operator[](int i)
    {
#line 569
        return At(i);
    };
    
#line 568
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::operator[](int i) const
    {
#line 568
        return At(i);
    };
    
#line 531
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key)
    {
#line 532
        keys.Add(key);
        return values.Add();
    };
    
#line 541
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 542
        keys.Add(key);
        return values.Add(value);
    };
    
#line 536
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 537
        keys.Add(key);
        return values.Add(value);
    };
    
#line 563
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::At(int i)
    {
        {
#line 564
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 564
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 565
        ;
#line 565
        return values[i];
    };
    
#line 558
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::At(int i) const
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
    
#line 643
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin() const
    {
#line 643
        return Iterator(keys.Get(), values.Get());
    };
    
#line 641
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin()
    {
#line 641
        return Iterator(keys.Get(), values.Get());
    };
    
#line 581
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Clear()
    {
#line 582
        keys.Clear();
        values.Clear();
    };
    
#line 644
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End() const
    {
#line 644
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 642
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End()
    {
#line 642
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 573
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::Find(const _1& key) const
    {
#line 573
        return keys.Find(key);
    };
    
#line 634
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 635
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 637
            it += GetCount();
        else
#line 638
            it += pos;
        return it;
    };
    
#line 575
    template < class _1, class _2 >
    inline _2 ArrayMap < _1, _2 >::Get(const _1& key, _2 value)
    {
#line 575
        int i = Find(key);
#line 575
        if (i < 0)
#line 575
            return value;
#line 575
        return values[i];
    };
    
#line 574
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Get(const _1& key)
    {
#line 574
        return values[Find(key)];
    };
    
#line 546
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 547
        int i = keys.Find(key);
        if (i >= 0)
#line 548
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 576
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetCount() const
    {
#line 576
        return keys.GetCount();
    };
    
#line 556
    template < class _1, class _2 >
    inline const _1& ArrayMap < _1, _2 >::GetKey(int i) const
    {
#line 556
        return keys[i];
    };
    
#line 527
    template < class _1, class _2 >
    inline const Index < _1 > & ArrayMap < _1, _2 >::GetKeys() const
    {
#line 527
        return keys;
    };
    
#line 624
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 625
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 529
    template < class _1, class _2 >
    inline Array < _2 > & ArrayMap < _1, _2 >::GetValues()
    {
#line 529
        return values;
    };
    
#line 528
    template < class _1, class _2 >
    inline const Array < _2 > & ArrayMap < _1, _2 >::GetValues() const
    {
#line 528
        return values;
    };
    
#line 553
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 553
        keys.Insert(i, key);
#line 553
        return values.Insert(i);
    };
    
#line 554
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 554
        keys.Insert(i, key);
#line 554
        return values.Insert(i, value);
    };
    
#line 633
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 633
        int pos = GetPos(it);
#line 633
        Insert(pos, key);
#line 633
        Iterator cur = Begin();
#line 633
        cur += pos;
#line 633
        return cur;
    };
    
#line 632
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 632
        int pos = GetPos(it);
#line 632
        Insert(pos, key, value);
#line 632
        Iterator cur = Begin();
#line 632
        cur += pos;
#line 632
        return cur;
    };
    
#line 631
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 631
        int pos = GetPos(it);
#line 631
        Insert(pos, key, value);
#line 631
        Iterator cur = Begin();
#line 631
        cur += pos;
#line 631
        return cur;
    };
    
#line 577
    template < class _1, class _2 >
    inline bool ArrayMap < _1, _2 >::IsEmpty() const
    {
#line 577
        return GetCount() == 0;
    };
    
#line 630
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 630
        Remove(GetPos(it));
    };
    
#line 580
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(int i)
    {
        {
#line 580
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 580
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 580
        ;
#line 580
        keys.Remove(i);
#line 580
        values.Remove(i);
    };
    
#line 579
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 579
        int i = Find(key);
#line 579
        if (i >= 0)
#line 579
            Remove(i);
    };
    
#line 571
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Top()
    {
        {
#line 571
            if (!(GetCount() > 0))
            {
#line 571
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 571
        ;
#line 571
        return values.Top();
    };
    
#line 647
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin() const
    {
#line 647
        return Begin();
    };
    
#line 645
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin()
    {
#line 645
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end() const
    {
#line 648
        return End();
    };
    
#line 646
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end()
    {
#line 646
        return End();
    };
    
#line 877
    template < class _1 >
    inline _1& CachingVector < _1 >::operator[](int i)
    {
#line 877
        return data[i];
    };
    
#line 876
    template < class _1 >
    inline const _1& CachingVector < _1 >::operator[](int i) const
    {
#line 876
        return data[i];
    };
    
#line 881
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::Begin()
    {
#line 881
        return data.begin();
    };
    
#line 883
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::End()
    {
#line 883
        return data.begin() + count;
    };
    
#line 878
    template < class _1 >
    inline int CachingVector < _1 >::GetCount() const
    {
#line 878
        return count;
    };
    
#line 880
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::begin()
    {
#line 880
        return data.begin();
    };
    
#line 882
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::end()
    {
#line 882
        return data.begin() + count;
    };
    
#line 693
    template < class _1 >
    inline void FixedArray2 < _1 >::operator= (const FixedArray2& value)
    {
#line 693
        for (int i = 0; i < size; i ++ )
#line 693
            this -> vector[i] = value.vector[i];
    };
    
#line 692
    template < class _1 >
    inline void FixedArray2 < _1 >::operator= (const _1& value)
    {
#line 692
        for (int i = 0; i < size; i ++ )
#line 692
            this -> vector[i] = value;
    };
    
#line 690
    template < class _1 >
    inline _1& FixedArray2 < _1 >::operator[](int i)
    {
        {
#line 690
            if (!(i >= 0 && i < size))
            {
#line 690
                Lang::SysBreak("Assertion failed: i >= 0 && i < size");
            }
        }
#line 690
        ;
#line 690
        return vector[i];
    };
    
#line 691
    template < class _1 >
    inline const _1& FixedArray2 < _1 >::operator[](int i) const
    {
        {
#line 691
            if (!(i >= 0 && i < size))
            {
#line 691
                Lang::SysBreak("Assertion failed: i >= 0 && i < size");
            }
        }
#line 691
        ;
#line 691
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
    
#line 455
    template < class _1 >
    inline Index < _1 >::Index() {};
    
#line 510
    template < class _1 >
    inline void Index < _1 >::operator<<= (const Index& a)
    {
#line 510
        Set(a);
    };
    
#line 466
    template < class _1 >
    inline const _1& Index < _1 >::operator[](int i) const
    {
        {
#line 467
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 467
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 468
        ;
#line 468
        return values[i];
    };
    
#line 476
    template < class _1 >
    inline const _1& Index < _1 >::Add(const _1& value)
    {
#line 477
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Add(hash);
        return values.Add(value);
    };
    
#line 461
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::Begin() const
    {
#line 461
        return Iterator(values.Begin());
    };
    
#line 457
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::Begin()
    {
#line 457
        return Iterator(values.Begin());
    };
    
#line 505
    template < class _1 >
    inline void Index < _1 >::Clear()
    {
#line 505
        hashes.Clear();
#line 505
        values.Clear();
    };
    
#line 462
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::End() const
    {
#line 462
        return Iterator(values.End());
    };
    
#line 459
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::End()
    {
#line 459
        return Iterator(values.End());
    };
    
#line 490
    template < class _1 >
    inline int Index < _1 >::Find(const _1& key) const
    {
#line 490
        return FindHash(Hash::GetValue(key));
    };
    
#line 491
    template < class _1 >
    inline int Index < _1 >::FindAdd(const _1& key)
    {
#line 491
        int i = Find(key);
#line 491
        if (i >= 0)
#line 491
            return i;
#line 491
        i = GetCount();
#line 491
        Add(key);
#line 491
        return i;
    };
    
#line 493
    template < class _1 >
    inline int Index < _1 >::FindHash(Lang::uint32 hash) const
    {
#line 494
        unsigned int * begin = hashes.Get();
        unsigned int * it = begin;
        unsigned int * end = begin + hashes.GetCount();
        while (it != end)
            {
#line 498
                if (*it == hash)
                    return it - begin;
                it ++ ;
            }
        return - 1;
    };
    
#line 463
    template < class _1 >
    inline _1 *Index < _1 >::Get()
    {
#line 463
        return values.Get();
    };
    
#line 475
    template < class _1 >
    inline int Index < _1 >::GetCount() const
    {
#line 475
        return values.GetCount();
    };
    
#line 464
    template < class _1 >
    inline _1 *Index < _1 >::GetEnd()
    {
#line 464
        return values.GetEnd();
    };
    
#line 483
    template < class _1 >
    inline _1& Index < _1 >::Insert(int i, const _1& value)
    {
#line 484
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Insert(i, hash);
        return values.Insert(i, value);
    };
    
#line 506
    template < class _1 >
    inline void Index < _1 >::Remove(int i)
    {
#line 506
        hashes.Remove(i);
#line 506
        values.Remove(i);
    };
    
#line 508
    template < class _1 >
    inline void Index < _1 >::RemoveKey(const _1& key)
    {
#line 508
        int i = Find(key);
#line 508
        if (i >= 0)
#line 508
            Remove(i);
    };
    
#line 507
    template < class _1 >
    inline void Index < _1 >::RemoveLast()
    {
        {
#line 507
            if (!(GetCount()))
            {
#line 507
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 507
        ;
#line 507
        if (GetCount())
#line 507
            Remove(GetCount() - 1);
    };
    
#line 471
    template < class _1 >
    inline void Index < _1 >::Set(const Index& i)
    {
#line 472
        hashes <<= i.hashes;
        values <<= i.values;
    };
    
#line 458
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::begin()
    {
#line 458
        return Iterator(values.Begin());
    };
    
#line 460
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::end()
    {
#line 460
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
    
#line 711
    inline TopValueSorter10::TopValueSorter10()
    :
        count(0)
    {
#line 711
        Reset();
    };
    
#line 758
    template < class _1 >
    inline _1& TreeArray < _1 >::Add()
    {
#line 758
        _1 & t = branch.Add();
#line 758
        t.down = this;
#line 758
        return t;
    };
    
#line 766
    template < class _1 >
    inline _1& TreeArray < _1 >::Add(_1 *n)
    {
        {
#line 766
            if (!(n -> down == 0))
            {
#line 766
                Lang::SysBreak("Assertion failed: n->down == NULL");
            }
        }
#line 766
        ;
#line 766
        _1 & t = branch.Add(n);
#line 766
        t.down = this;
#line 766
        return t;
    };
    
#line 775
    template < class _1 >
    inline _1& TreeArray < _1 >::At(int i)
    {
#line 775
        return branch[i];
    };
    
#line 777
    template < class _1 >
    inline _1& TreeArray < _1 >::At(int i, _1& n)
    {
#line 777
        if (i < branch.GetCount())
#line 777
            return branch[i];
#line 777
        return n;
    };
    
#line 778
    template < class _1 >
    inline const _1& TreeArray < _1 >::At(int i) const
    {
#line 778
        return branch[i];
    };
    
#line 776
    template < class _1 >
    inline _1& TreeArray < _1 >::AtTop(int i)
    {
#line 776
        if (i < branch.GetCount())
#line 776
            return branch[i];
#line 776
        return branch.Top();
    };
    
#line 769
    template < class _1 >
    inline void TreeArray < _1 >::Clear()
    {
#line 769
        branch.Clear();
    };
    
#line 761
    template < class _1 >
    inline void TreeArray < _1 >::Copy(const PA& src)
    {
#line 761
        branch <<= src.branch;
#line 761
        for (int i = 0; i < branch.GetCount(); i ++ )
#line 761
            branch[i].down = this;
    };
    
#line 773
    template < class _1 >
    inline _1 *TreeArray < _1 >::Detach(int i)
    {
#line 773
        _1 * t = branch.Detach(i);
#line 773
        t -> down = 0;
#line 773
        return t;
    };
    
#line 781
    template < class _1 >
    inline int TreeArray < _1 >::GetCount() const
    {
#line 781
        return branch.GetCount();
    };
    
#line 765
    template < class _1 >
    inline _1 *TreeArray < _1 >::GetParent() const
    {
#line 765
        return down;
    };
    
#line 759
    template < class _1 >
    inline _1& TreeArray < _1 >::Insert(int i)
    {
#line 759
        _1 & t = branch.Insert(i);
#line 759
        t.down = this;
#line 759
        return t;
    };
    
#line 767
    template < class _1 >
    inline _1& TreeArray < _1 >::Insert(int i, _1 *n)
    {
        {
#line 767
            if (!(n -> down == 0))
            {
#line 767
                Lang::SysBreak("Assertion failed: n->down == NULL");
            }
        }
#line 767
        ;
#line 767
        _1 & t = branch.Insert(i, n);
#line 767
        t.down = this;
#line 767
        return t;
    };
    
#line 782
    template < class _1 >
    inline bool TreeArray < _1 >::IsEmpty() const
    {
#line 782
        return branch.IsEmpty();
    };
    
#line 770
    template < class _1 >
    inline void TreeArray < _1 >::Remove(int i)
    {
#line 770
        branch.Remove(i);
    };
    
#line 771
    template < class _1 >
    inline void TreeArray < _1 >::Remove(int i, int count)
    {
#line 771
        branch.Remove(i, count);
    };
    
#line 772
    template < class _1 >
    inline void TreeArray < _1 >::RemoveLast()
    {
#line 772
        branch.Remove(branch.GetCount() - 1);
    };
    
#line 791
    template < class _1 >
    inline void TreeArray < _1 >::Serialize(Abstract::StreamBase& s)
    {
#line 792
        s % branch;
        if (s.IsLoading())
            for (int i = 0; i < branch.GetCount(); i ++ )
                branch[i].down = this;
    };
    
#line 784
    template < class _1 >
    inline void TreeArray < _1 >::SortByInt()
    {
#line 785
        struct Sorter;
#line 788
        Sort(branch, Sorter());
    };
    
#line 779
    template < class _1 >
    inline _1& TreeArray < _1 >::Top()
    {
#line 779
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
    
#line 525
    template < class _1, class _2 >
    inline VectorMap < _1, _2 >::VectorMap() {};
    
#line 586
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::operator<<= (const VectorMap& a)
    {
#line 587
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 569
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::operator[](int i)
    {
#line 569
        return At(i);
    };
    
#line 568
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::operator[](int i) const
    {
#line 568
        return At(i);
    };
    
#line 531
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key)
    {
#line 532
        keys.Add(key);
        return values.Add();
    };
    
#line 541
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 542
        keys.Add(key);
        return values.Add(value);
    };
    
#line 536
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 537
        keys.Add(key);
        return values.Add(value);
    };
    
#line 563
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::At(int i)
    {
        {
#line 564
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 564
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 565
        ;
#line 565
        return values[i];
    };
    
#line 558
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::At(int i) const
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
    
#line 614
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin() const
    {
#line 614
        return Iterator(keys.Get(), values.Get());
    };
    
#line 612
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin()
    {
#line 612
        return Iterator(keys.Get(), values.Get());
    };
    
#line 581
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Clear()
    {
#line 582
        keys.Clear();
        values.Clear();
    };
    
#line 615
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End() const
    {
#line 615
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 613
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End()
    {
#line 613
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 573
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::Find(const _1& key) const
    {
#line 573
        return keys.Find(key);
    };
    
#line 605
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 606
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 608
            it += GetCount();
        else
#line 609
            it += pos;
        return it;
    };
    
#line 575
    template < class _1, class _2 >
    inline _2 VectorMap < _1, _2 >::Get(const _1& key, _2 value)
    {
#line 575
        int i = Find(key);
#line 575
        if (i < 0)
#line 575
            return value;
#line 575
        return values[i];
    };
    
#line 574
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Get(const _1& key)
    {
#line 574
        return values[Find(key)];
    };
    
#line 546
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 547
        int i = keys.Find(key);
        if (i >= 0)
#line 548
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 576
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetCount() const
    {
#line 576
        return keys.GetCount();
    };
    
#line 556
    template < class _1, class _2 >
    inline const _1& VectorMap < _1, _2 >::GetKey(int i) const
    {
#line 556
        return keys[i];
    };
    
#line 527
    template < class _1, class _2 >
    inline const Index < _1 > & VectorMap < _1, _2 >::GetKeys() const
    {
#line 527
        return keys;
    };
    
#line 595
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 596
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 529
    template < class _1, class _2 >
    inline Vector < _2 > & VectorMap < _1, _2 >::GetValues()
    {
#line 529
        return values;
    };
    
#line 528
    template < class _1, class _2 >
    inline const Vector < _2 > & VectorMap < _1, _2 >::GetValues() const
    {
#line 528
        return values;
    };
    
#line 553
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 553
        keys.Insert(i, key);
#line 553
        return values.Insert(i);
    };
    
#line 554
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 554
        keys.Insert(i, key);
#line 554
        return values.Insert(i, value);
    };
    
#line 604
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 604
        int pos = GetPos(it);
#line 604
        Insert(pos, key);
#line 604
        Iterator cur = Begin();
#line 604
        cur += pos;
#line 604
        return cur;
    };
    
#line 603
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 603
        int pos = GetPos(it);
#line 603
        Insert(pos, key, value);
#line 603
        Iterator cur = Begin();
#line 603
        cur += pos;
#line 603
        return cur;
    };
    
#line 602
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 602
        int pos = GetPos(it);
#line 602
        Insert(pos, key, value);
#line 602
        Iterator cur = Begin();
#line 602
        cur += pos;
#line 602
        return cur;
    };
    
#line 577
    template < class _1, class _2 >
    inline bool VectorMap < _1, _2 >::IsEmpty() const
    {
#line 577
        return GetCount() == 0;
    };
    
#line 601
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 601
        Remove(GetPos(it));
    };
    
#line 580
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(int i)
    {
        {
#line 580
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 580
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 580
        ;
#line 580
        keys.Remove(i);
#line 580
        values.Remove(i);
    };
    
#line 579
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 579
        int i = Find(key);
#line 579
        if (i >= 0)
#line 579
            Remove(i);
    };
    
#line 571
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Top()
    {
        {
#line 571
            if (!(GetCount() > 0))
            {
#line 571
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 571
        ;
#line 571
        return values.Top();
    };
    
#line 618
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin() const
    {
#line 618
        return Begin();
    };
    
#line 616
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin()
    {
#line 616
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end() const
    {
#line 619
        return End();
    };
    
#line 617
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end()
    {
#line 617
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
    
#line 294
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > VectorPtr < _1 >::Begin()
    {
#line 294
        return Lang::FwdPtrIterator < _1 > (data.Get());
    };
    
#line 291
    template < class _1 >
    inline void VectorPtr < _1 >::Clear()
    {
#line 291
        data.Clear();
    };
    
#line 295
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > VectorPtr < _1 >::End()
    {
#line 295
        return Lang::FwdPtrIterator < _1 > (data.GetEnd());
    };
    
#line 286
    template < class _1 >
    inline int VectorPtr < _1 >::GetCount() const
    {
#line 286
        return data.GetCount();
    };
    
#line 297
    template < class _1 >
    inline Text::String VectorPtr < _1 >::Join(Text::String join_str, bool ignore_empty) const
    {
#line 298
        Text::String out;
        ConstIterator end = data.End();
        for (ConstIterator it = data.Begin(); it != end; ++ it)
            {
#line 301
                Text::String s = Text::ToString < _1 > (**it);
                if (s.IsEmpty() && ignore_empty)
                    continue;
                
#line 304
                if (!out.IsEmpty())
                    out << join_str;
                out << s;
            }
        return out;
    };
    
#line 292
    template < class _1 >
    inline _1 *VectorPtr < _1 >::Pop()
    {
#line 292
        return data.Pop();
    };
    
#line 290
    template < class _1 >
    inline _1 *& VectorPtr < _1 >::Ref(int i)
    {
#line 290
        return data[i];
    };
    
    template < class _1 >
    inline void VectorPtr < _1 >::SetCount(int i)
    {
#line 293
        data.SetCount(i, 0);
    };
    
};

#endif
