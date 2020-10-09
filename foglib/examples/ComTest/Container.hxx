#ifndef CONTAINER_HXX
#define CONTAINER_HXX

#include <new>

#ifndef TEXT_HXX
#include <Text.hxx>
#endif

namespace Container
{
#line 668 "../../src/Com/Container.fog"
    template < class _1, class _2 >
    inline _1 FindIf(_1 first, _1 last, _2 pred);
#line 36
    template < class _1 >
    inline void Reverse(_1& t);
#line 28
    template < class _1 >
    inline void Swap(_1& a, _1& b);
#line 899
    template < class _1 >
    inline void TypeFn(_1 *o);
    
    struct AnonTypeBase
    {
#line 903
        void *typefn;
        
        virtual ~AnonTypeBase();
#line 908
        /*pure*/virtual Text::String AsString() const = 0;
#line 907
        /*pure*/virtual AnonTypeBase *CopyNew() const = 0;
#line 906
        /*pure*/virtual void Set(const AnonTypeBase *src) = 0;
        
    protected:
#line 911
        inline AnonTypeBase();
    };
    
    template < class _1 >
    struct AnonType : public Container::AnonTypeBase
    {
#line 916
        typedef _1 Cls;
        
#line 917
        Cls obj;
        
        inline AnonType();
#line 931
        virtual Text::String AsString() const;
#line 928
        inline virtual AnonTypeBase *CopyNew() const;
#line 921
        inline virtual void Set(const AnonTypeBase *src);
    };
    
    template < class _1 >
    class Array
    {
    public:
#line 341
        typedef Lang::ConstFwdPtrIterator < _1 > CIterator;
        typedef Lang::ConstBwdPtrIterator < _1 > CRIterator;
#line 338
        typedef const _1 ConstK;
#line 337
        typedef _1 IndirectK;
#line 339
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 333
        Lang::DynArray < _1 * > l;
        
    public:
#line 345
        inline Array();
        inline ~Array();
#line 443
        inline Array < _1 > & operator<< (const _1& v);
#line 436
        inline void operator<<= (const Array& a);
#line 396
        inline _1& operator[](int i);
#line 402
        inline const _1& operator[](int i) const;
#line 387
        inline _1& Add();
#line 389
        inline _1& Add(_1 *k);
#line 388
        inline _1& Add(const _1& v);
#line 357
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 355
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 423
        inline void Clear();
#line 394
        inline _1 *Detach(int i);
#line 358
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 356
        inline Lang::FwdPtrIterator < _1 > End();
#line 350
        inline _1 **Get() const;
#line 352
        inline const _1 **GetConst() const;
        inline const _1 **GetConstEnd() const;
#line 392
        inline int GetCount() const;
#line 351
        inline _1 **GetEnd() const;
#line 390
        inline _1& Insert(int i);
        inline _1& Insert(int i, const _1& key);
#line 393
        inline bool IsEmpty() const;
#line 363
        inline Lang::BwdPtrIterator < _1 > RBegin();
#line 365
        inline Lang::ConstBwdPtrIterator < _1 > RBegin() const;
#line 364
        inline Lang::BwdPtrIterator < _1 > REnd();
#line 366
        inline Lang::ConstBwdPtrIterator < _1 > REnd() const;
#line 413
        inline void Remove(const int *sorted_list, int n);
#line 407
        inline void Remove(int i);
#line 422
        inline void RemoveLast();
#line 372
        inline void Reserve(int i);
        inline void SetCount(int new_count);
#line 432
        inline _1& Top();
#line 361
        inline Lang::ConstFwdPtrIterator < _1 > begin() const;
#line 359
        inline Lang::FwdPtrIterator < _1 > begin();
#line 362
        inline Lang::ConstFwdPtrIterator < _1 > end() const;
#line 360
        inline Lang::FwdPtrIterator < _1 > end();
#line 367
        inline Lang::BwdPtrIterator < _1 > rbegin();
#line 369
        inline Lang::ConstBwdPtrIterator < _1 > rbegin() const;
#line 368
        inline Lang::BwdPtrIterator < _1 > rend();
#line 370
        inline Lang::ConstBwdPtrIterator < _1 > rend() const;
    };
    
    template < class _1 >
    struct FixedArray2
    {
#line 696
        _1 vector[2];
        
#line 701
        inline void operator= (const FixedArray2& value);
#line 700
        inline void operator= (const _1& value);
#line 698
        inline _1& operator[](int i);
        inline const _1& operator[](int i) const;
        
#line 694
        static const int size;
    };
    
    template < class _1 >
    class Index
    {
    public:
#line 456
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 452
        Lang::DynArray < unsigned int > hashes;
        Lang::DynArray < _1 > values;
        
    public:
#line 459
        inline Index();
#line 514
        inline void operator<<= (const Index& a);
#line 470
        inline const _1& operator[](int i) const;
#line 480
        inline const _1& Add(const _1& value);
#line 465
        inline Lang::ConstFwdPtrIterator < _1 > Begin() const;
#line 461
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 509
        inline void Clear();
#line 466
        inline Lang::ConstFwdPtrIterator < _1 > End() const;
#line 463
        inline Lang::FwdPtrIterator < _1 > End();
#line 494
        inline int Find(const _1& key) const;
        inline int FindAdd(const _1& key);
#line 497
        inline int FindHash(Lang::uint32 hash) const;
#line 467
        inline _1 *Get();
#line 479
        inline int GetCount() const;
#line 468
        inline _1 *GetEnd();
#line 487
        inline _1& Insert(int i, const _1& value);
#line 510
        inline void Remove(int i);
#line 512
        inline void RemoveKey(const _1& key);
#line 511
        inline void RemoveLast();
#line 475
        inline void Set(const Index& i);
#line 462
        inline Lang::FwdPtrIterator < _1 > begin();
#line 464
        inline Lang::FwdPtrIterator < _1 > end();
    };
    
    template < class _1, class _2 >
    class ArrayMap
    {
    public:
#line 526
        typedef Array < _2 > ArrayV;
#line 525
        typedef Index < _1 > IndexK;
#line 630
        typedef Lang::FwdPairPtrIterator < _1, _2 > Iterator;
#line 527
        typedef ArrayMap < _1, _2 > MapKV;
#line 631
        typedef Lang::BwdPairPtrIterator < _1, _2 > RIterator;
        
#line 521
        Index < _1 > keys;
        Array < _2 > values;
        
    public:
#line 529
        inline ArrayMap();
#line 594
        inline void operator<<= (const ArrayMap& a);
#line 573
        inline _2& operator[](int i);
#line 572
        inline const _2& operator[](int i) const;
#line 535
        inline _2& Add(const _1& key);
#line 545
        inline _2& Add(const _1& key, _2 *value);
#line 540
        inline _2& Add(const _1& key, const _2& value);
#line 567
        inline _2& At(int i);
#line 562
        inline const _2& At(int i) const;
#line 651
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > Begin() const;
#line 649
        inline Lang::FwdPairPtrIterator < _1, _2 > Begin();
#line 585
        inline void Clear();
#line 589
        inline void ClearAndPickValues(Array < _2 > & a);
#line 652
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > End() const;
#line 650
        inline Lang::FwdPairPtrIterator < _1, _2 > End();
#line 577
        inline int Find(const _1& key) const;
#line 642
        inline Lang::FwdPairPtrIterator < _1, _2 > FindIterator(const _1& key) const;
#line 579
        inline _2 Get(const _1& key, _2 value) const;
#line 578
        inline _2& Get(const _1& key);
#line 550
        inline _2& GetAdd(const _1& key);
#line 580
        inline int GetCount() const;
#line 560
        inline const _1& GetKey(int i) const;
#line 531
        inline const Index < _1 > & GetKeys() const;
#line 632
        inline int GetPos(const Iterator& it);
#line 533
        inline Array < _2 > & GetValues();
#line 532
        inline const Array < _2 > & GetValues() const;
#line 557
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 641
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 640
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 639
        inline Lang::FwdPairPtrIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 581
        inline bool IsEmpty() const;
#line 638
        inline void Remove(const Iterator& it);
#line 584
        inline void Remove(int i);
#line 583
        inline void RemoveKey(const _1& key);
#line 575
        inline _2& Top();
#line 655
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > begin() const;
#line 653
        inline Lang::FwdPairPtrIterator < _1, _2 > begin();
#line 656
        inline Lang::ConstFwdPairPtrIterator < _1, _2 > end() const;
#line 654
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
    
    class OneAnon
    {
#line 935
        One < AnonTypeBase > obj;
        
    public:
#line 939
        inline OneAnon();
        inline OneAnon(const OneAnon& o);
#line 964
        void operator= (const OneAnon& o);
#line 983
        inline operator bool() const;
        inline Lang::int64 AsInt() const;
        Text::String AsString() const;
#line 942
        inline void Clear();
#line 944
        template < class _1 >
        _1& Create();
#line 982
        inline bool IsEmpty() const;
#line 952
        template < class _1 >
        _1 *TryGet();
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
#line 820
        Lang::DynArray < Lang::DynArray < int > > data;
        Lang::DynArray < Lang::uint64 > value_mask;
        int count;
        int first_data_i;
        
#line 850
        void Add(int key, int value);
#line 833
        void Clear();
#line 825
        void Reserve(int count);
    };
    
    struct TopValueSorter10
    {
#line 711
        typedef int Key;
        typedef double Value;
        
        Key key[10];
        Value value[10];
        int count;
        
#line 719
        inline TopValueSorter10();
#line 727
        void Add(const Key& key, const Value& value);
#line 720
        void Reset();
#line 743
        void Serialize(Abstract::StreamBase& s);
        
#line 710
        static const int size;
    };
    
    template < class _1 >
    class TreeArray
    {
    public:
#line 758
        typedef TreeArray < _1 > PA;
        
#line 761
        PA *down;
        Array < _1 > branch;
        
    public:
#line 774
        inline _1& Add(_1 *n);
#line 783
        inline _1& At(int i);
#line 785
        inline _1& At(int i, _1& n);
        inline const _1& At(int i) const;
#line 784
        inline _1& AtTop(int i);
#line 777
        inline void Clear();
#line 781
        inline _1 *Detach(int i);
#line 789
        inline int GetCount() const;
#line 773
        inline _1 *GetParent() const;
#line 775
        inline _1& Insert(int i, _1 *n);
#line 790
        inline bool IsEmpty() const;
#line 778
        inline void Remove(int i);
        inline void Remove(int i, int count);
        inline void RemoveLast();
#line 799
        inline void Serialize(Abstract::StreamBase& s);
#line 792
        inline void SortByInt();
#line 787
        inline _1& Top();
        
    protected:
#line 766
        inline _1& Add();
#line 769
        inline void Copy(const PA& src);
#line 767
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
#line 256
        inline void Shrink();
#line 222
        inline void Split(Text::String to_split, Text::String split_str, bool ignore_empty = true);
    };
    
    template < class _1 >
    struct CachingVector
    {
#line 879
        typedef Vector < _1 > Vec;
        
#line 880
        Vector < _1 > data;
        int count;
        
#line 885
        inline _1& operator[](int i);
#line 884
        inline const _1& operator[](int i) const;
#line 889
        inline typename Lang::FwdIterator < _1 > Begin();
#line 891
        inline typename Lang::FwdIterator < _1 > End();
#line 886
        inline int GetCount() const;
        void SetCount(int i);
        inline typename Lang::FwdIterator < _1 > begin();
#line 890
        inline typename Lang::FwdIterator < _1 > end();
    };
    
    template < class _1, class _2 >
    class VectorMap
    {
    public:
#line 526
        typedef Vector < _2 > ArrayV;
#line 525
        typedef Index < _1 > IndexK;
#line 601
        typedef Lang::FwdPairIterator < _1, _2 > Iterator;
#line 527
        typedef VectorMap < _1, _2 > MapKV;
#line 602
        typedef Lang::BwdPairIterator < _1, _2 > RIterator;
        
#line 521
        Index < _1 > keys;
        Vector < _2 > values;
        
    public:
#line 529
        inline VectorMap();
#line 594
        inline void operator<<= (const VectorMap& a);
#line 573
        inline _2& operator[](int i);
#line 572
        inline const _2& operator[](int i) const;
#line 535
        inline _2& Add(const _1& key);
#line 545
        inline _2& Add(const _1& key, _2 *value);
#line 540
        inline _2& Add(const _1& key, const _2& value);
#line 567
        inline _2& At(int i);
#line 562
        inline const _2& At(int i) const;
#line 622
        inline Lang::ConstFwdPairIterator < _1, _2 > Begin() const;
#line 620
        inline Lang::FwdPairIterator < _1, _2 > Begin();
#line 585
        inline void Clear();
#line 589
        inline void ClearAndPickValues(Vector < _2 > & a);
#line 623
        inline Lang::ConstFwdPairIterator < _1, _2 > End() const;
#line 621
        inline Lang::FwdPairIterator < _1, _2 > End();
#line 577
        inline int Find(const _1& key) const;
#line 613
        inline Lang::FwdPairIterator < _1, _2 > FindIterator(const _1& key) const;
#line 579
        inline _2 Get(const _1& key, _2 value) const;
#line 578
        inline _2& Get(const _1& key);
#line 550
        inline _2& GetAdd(const _1& key);
#line 580
        inline int GetCount() const;
#line 560
        inline const _1& GetKey(int i) const;
#line 531
        inline const Index < _1 > & GetKeys() const;
#line 603
        inline int GetPos(const Iterator& it);
#line 533
        inline Vector < _2 > & GetValues();
#line 532
        inline const Vector < _2 > & GetValues() const;
#line 557
        inline _2& Insert(int i, const _1& key);
        inline _2& Insert(int i, const _1& key, const _2& value);
#line 612
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key);
#line 611
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, _2 *value);
#line 610
        inline Lang::FwdPairIterator < _1, _2 > InsertIterator(const Iterator& it, const _1& key, const _2& value);
#line 581
        inline bool IsEmpty() const;
#line 609
        inline void Remove(const Iterator& it);
#line 584
        inline void Remove(int i);
#line 583
        inline void RemoveKey(const _1& key);
#line 575
        inline _2& Top();
#line 626
        inline Lang::ConstFwdPairIterator < _1, _2 > begin() const;
#line 624
        inline Lang::FwdPairIterator < _1, _2 > begin();
#line 627
        inline Lang::ConstFwdPairIterator < _1, _2 > end() const;
#line 625
        inline Lang::FwdPairIterator < _1, _2 > end();
    };
    
    template < class _1 >
    class VectorPtr
    {
    public:
#line 279
        typedef Lang::ConstFwdPtrIterator < _1 > ConstIterator;
        typedef Lang::ConstBwdPtrIterator < _1 > ConstRIterator;
        typedef Lang::FwdPtrIterator < _1 > Iterator;
        typedef Lang::BwdPtrIterator < _1 > RIterator;
        
#line 274
        Lang::DynArray < _1 * > data;
        
    public:
#line 284
        inline VectorPtr();
        inline VectorPtr(const VectorPtr& v);
#line 292
        inline _1& operator[](int i);
        inline const _1& operator[](int i) const;
#line 288
        inline _1& Add(_1 *o);
#line 290
        inline void Append(const VectorPtr& v);
        inline void Append(const VectorPtr& v, int i, int n);
#line 298
        inline Lang::FwdPtrIterator < _1 > Begin();
#line 295
        inline void Clear();
#line 299
        inline Lang::FwdPtrIterator < _1 > End();
#line 289
        inline int GetCount() const;
#line 301
        inline Text::String Join(Text::String join_str = "", bool ignore_empty = true) const;
#line 296
        inline _1 *Pop();
#line 294
        inline _1 *& Ref(int i);
#line 297
        inline void SetCount(int i);
    };
};

namespace Container
{
#line 668
    template < class _1, class _2 >
    inline _1 FindIf(_1 first, _1 last, _2 pred)
    {
#line 670
        while (first != last)
            {
#line 671
                int i = pred._2::operator()(*first);
                if (i)
#line 672
                    return first;
#line 674
                ++ first;
            }
#line 677
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
    
#line 899
    template < class _1 >
    inline void TypeFn(_1 *o) {};
    
#line 919
    template < class _1 >
    inline AnonType < _1 >::AnonType()
    {
#line 919
        typefn = &TypeFn < Cls > ;
    };
    
#line 928
    template < class _1 >
    inline AnonTypeBase *AnonType < _1 >::CopyNew() const
    {
#line 929
        return new Cls(obj);
    };
    
#line 921
    template < class _1 >
    inline void AnonType < _1 >::Set(const AnonTypeBase *src)
    {
#line 922
        if (typefn == src -> typefn)
        {
#line 923
            const AnonType < Cls > * cls_src = dynamic_cast< const AnonType < Cls > * >(src);
            if (cls_src)
                obj = *cls_src;
        }
    };
    
#line 911
    inline AnonTypeBase::AnonTypeBase() {};
    
#line 345
    template < class _1 >
    inline Array < _1 >::Array() {};
    
#line 346
    template < class _1 >
    inline Array < _1 >::~Array()
    {
#line 346
        Clear();
    };
    
#line 443
    template < class _1 >
    inline Array < _1 > & Array < _1 >::operator<< (const _1& v)
    {
#line 443
        Add(v);
#line 443
        return *this;
    };
    
#line 436
    template < class _1 >
    inline void Array < _1 >::operator<<= (const Array& a)
    {
#line 437
        Clear();
        l.SetCount(a.GetCount(), 0);
        for (int i = 0; i < a.GetCount(); i ++ )
            l[i] = new _1(*a.l[i]);
    };
    
#line 396
    template < class _1 >
    inline _1& Array < _1 >::operator[](int i)
    {
        {
#line 397
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 397
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 398
        ;
#line 398
        _1 * *it = l.Get();
        it = it + i;
        return **it;
    };
    
#line 402
    template < class _1 >
    inline const _1& Array < _1 >::operator[](int i) const
    {
        {
#line 403
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 403
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 404
        ;
#line 404
        return **(l.Get() + i);
    };
    
#line 387
    template < class _1 >
    inline _1& Array < _1 >::Add()
    {
#line 387
        _1 * k = new _1;
#line 387
        l.Add(k);
#line 387
        return *k;
    };
    
#line 389
    template < class _1 >
    inline _1& Array < _1 >::Add(_1 *k)
    {
#line 389
        l.Add(k);
#line 389
        return *k;
    };
    
#line 388
    template < class _1 >
    inline _1& Array < _1 >::Add(const _1& v)
    {
#line 388
        _1 * k = new _1(v);
#line 388
        l.Add(k);
#line 388
        return *k;
    };
    
#line 357
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::Begin() const
    {
#line 357
        return CIterator((const _1 * *) l.Get());
    };
    
#line 355
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::Begin()
    {
#line 355
        return Iterator(l.Get());
    };
    
#line 423
    template < class _1 >
    inline void Array < _1 >::Clear()
    {
#line 424
        Lang::DynArray < _1 * > tmp;
        Swap(tmp, l);
        _1 * *ptr = tmp.Get();
        _1 * *end = ptr + tmp.GetCount();
        while (ptr != end)
            delete *(ptr ++ );
    };
    
#line 394
    template < class _1 >
    inline _1 *Array < _1 >::Detach(int i)
    {
#line 394
        _1 * o = l[i];
#line 394
        l.Remove(i);
#line 394
        return o;
    };
    
#line 358
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::End() const
    {
#line 358
        return CIterator((const _1 * *) l.GetEnd());
    };
    
#line 356
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::End()
    {
#line 356
        return Iterator(l.GetEnd());
    };
    
#line 350
    template < class _1 >
    inline _1 **Array < _1 >::Get() const
    {
#line 350
        return l.Get();
    };
    
#line 352
    template < class _1 >
    inline const _1 **Array < _1 >::GetConst() const
    {
#line 352
        return l.Get();
    };
    
#line 353
    template < class _1 >
    inline const _1 **Array < _1 >::GetConstEnd() const
    {
#line 353
        return l.GetEnd();
    };
    
#line 392
    template < class _1 >
    inline int Array < _1 >::GetCount() const
    {
#line 392
        return l.GetCount();
    };
    
#line 351
    template < class _1 >
    inline _1 **Array < _1 >::GetEnd() const
    {
#line 351
        return l.GetEnd();
    };
    
#line 390
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i)
    {
#line 390
        return *l.Insert(i, new _1);
    };
    
#line 391
    template < class _1 >
    inline _1& Array < _1 >::Insert(int i, const _1& key)
    {
#line 391
        return *l.Insert(i, new _1(key));
    };
    
#line 393
    template < class _1 >
    inline bool Array < _1 >::IsEmpty() const
    {
#line 393
        return GetCount() == 0;
    };
    
#line 363
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::RBegin()
    {
#line 363
        return RIterator(l.GetEnd() - 1);
    };
    
#line 365
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::RBegin() const
    {
#line 365
        return CRIterator(l.GetConstEnd() - 1);
    };
    
#line 364
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::REnd()
    {
#line 364
        return RIterator(l.Get() - 1);
    };
    
#line 366
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::REnd() const
    {
#line 366
        return CRIterator(l.GetConst() - 1);
    };
    
#line 413
    template < class _1 >
    inline void Array < _1 >::Remove(const int *sorted_list, int n)
    {
#line 414
        if (!n)
#line 414
            return;
        const int * it = sorted_list;
        const int * end = sorted_list + n;
        _1 * *vector = l.Get();
        while (it != end)
            Lang::Destruct(**(vector + *it ++ ));
        l.Remove(sorted_list, n);
    };
    
#line 407
    template < class _1 >
    inline void Array < _1 >::Remove(int i)
    {
        {
#line 408
            if (!(i >= 0 && i < l.GetCount()))
            {
#line 408
                Lang::SysBreak("Assertion failed: i >= 0 && i < l.GetCount()");
            }
        }
#line 409
        ;
#line 409
        delete *(l.Get() + i);
        l.Remove(i);
    };
    
#line 422
    template < class _1 >
    inline void Array < _1 >::RemoveLast()
    {
        {
#line 422
            if (!(GetCount()))
            {
#line 422
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 422
        ;
#line 422
        Remove(GetCount() - 1);
    };
    
#line 372
    template < class _1 >
    inline void Array < _1 >::Reserve(int i)
    {
#line 372
        l.Reserve(i);
    };
    
#line 373
    template < class _1 >
    inline void Array < _1 >::SetCount(int new_count)
    {
#line 374
        int count = l.GetCount();
        if (new_count == count)
#line 375
            return;
        if (new_count > count)
        {
#line 377
            l.SetCount(new_count);
            for (int i = count; i < new_count; i ++ )
                l[i] = new _1;
        }
        else
        {
#line 382
            for (int i = count - 1; i >= new_count; i -- )
                delete l[i];
            l.SetCount(new_count);
        }
    };
    
#line 432
    template < class _1 >
    inline _1& Array < _1 >::Top()
    {
        {
#line 433
            if (!(GetCount() > 0))
            {
#line 433
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 434
        ;
#line 434
        return **(l.Get() + l.GetCount() - 1);
    };
    
#line 361
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::begin() const
    {
#line 361
        return Begin();
    };
    
#line 359
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::begin()
    {
#line 359
        return Begin();
    };
    
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Array < _1 >::end() const
    {
#line 362
        return End();
    };
    
#line 360
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Array < _1 >::end()
    {
#line 360
        return End();
    };
    
#line 367
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rbegin()
    {
#line 367
        return RBegin();
    };
    
#line 369
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rbegin() const
    {
#line 369
        return RBegin();
    };
    
#line 368
    template < class _1 >
    inline Lang::BwdPtrIterator < _1 > Array < _1 >::rend()
    {
#line 368
        return REnd();
    };
    
#line 370
    template < class _1 >
    inline Lang::ConstBwdPtrIterator < _1 > Array < _1 >::rend() const
    {
#line 370
        return REnd();
    };
    
#line 529
    template < class _1, class _2 >
    inline ArrayMap < _1, _2 >::ArrayMap() {};
    
#line 594
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::operator<<= (const ArrayMap& a)
    {
#line 595
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 573
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::operator[](int i)
    {
#line 573
        return At(i);
    };
    
#line 572
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::operator[](int i) const
    {
#line 572
        return At(i);
    };
    
#line 535
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key)
    {
#line 536
        keys.Add(key);
        return values.Add();
    };
    
#line 545
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 546
        keys.Add(key);
        return values.Add(value);
    };
    
#line 540
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 541
        keys.Add(key);
        return values.Add(value);
    };
    
#line 567
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::At(int i)
    {
        {
#line 568
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 568
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 569
        ;
#line 569
        return values[i];
    };
    
#line 562
    template < class _1, class _2 >
    inline const _2& ArrayMap < _1, _2 >::At(int i) const
    {
        {
#line 563
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 563
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 564
        ;
#line 564
        return values[i];
    };
    
#line 651
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin() const
    {
#line 651
        return Iterator(keys.Get(), values.Get());
    };
    
#line 649
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::Begin()
    {
#line 649
        return Iterator(keys.Get(), values.Get());
    };
    
#line 585
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Clear()
    {
#line 586
        keys.Clear();
        values.Clear();
    };
    
#line 589
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::ClearAndPickValues(Array < _2 > & a)
    {
#line 590
        Swap(a, values);
        Clear();
    };
    
#line 652
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End() const
    {
#line 652
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 650
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::End()
    {
#line 650
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 577
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::Find(const _1& key) const
    {
#line 577
        return keys.Find(key);
    };
    
#line 642
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 643
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 645
            it += GetCount();
        else
#line 646
            it += pos;
        return it;
    };
    
#line 579
    template < class _1, class _2 >
    inline _2 ArrayMap < _1, _2 >::Get(const _1& key, _2 value) const
    {
#line 579
        int i = Find(key);
#line 579
        if (i < 0)
#line 579
            return value;
#line 579
        return values[i];
    };
    
#line 578
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Get(const _1& key)
    {
#line 578
        return values[Find(key)];
    };
    
#line 550
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 551
        int i = keys.Find(key);
        if (i >= 0)
#line 552
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 580
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetCount() const
    {
#line 580
        return keys.GetCount();
    };
    
#line 560
    template < class _1, class _2 >
    inline const _1& ArrayMap < _1, _2 >::GetKey(int i) const
    {
#line 560
        return keys[i];
    };
    
#line 531
    template < class _1, class _2 >
    inline const Index < _1 > & ArrayMap < _1, _2 >::GetKeys() const
    {
#line 531
        return keys;
    };
    
#line 632
    template < class _1, class _2 >
    inline int ArrayMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 633
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 533
    template < class _1, class _2 >
    inline Array < _2 > & ArrayMap < _1, _2 >::GetValues()
    {
#line 533
        return values;
    };
    
#line 532
    template < class _1, class _2 >
    inline const Array < _2 > & ArrayMap < _1, _2 >::GetValues() const
    {
#line 532
        return values;
    };
    
#line 557
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 557
        keys.Insert(i, key);
#line 557
        return values.Insert(i);
    };
    
#line 558
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 558
        keys.Insert(i, key);
#line 558
        return values.Insert(i, value);
    };
    
#line 641
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 641
        int pos = GetPos(it);
#line 641
        Insert(pos, key);
#line 641
        Iterator cur = Begin();
#line 641
        cur += pos;
#line 641
        return cur;
    };
    
#line 640
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 640
        int pos = GetPos(it);
#line 640
        Insert(pos, key, value);
#line 640
        Iterator cur = Begin();
#line 640
        cur += pos;
#line 640
        return cur;
    };
    
#line 639
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 639
        int pos = GetPos(it);
#line 639
        Insert(pos, key, value);
#line 639
        Iterator cur = Begin();
#line 639
        cur += pos;
#line 639
        return cur;
    };
    
#line 581
    template < class _1, class _2 >
    inline bool ArrayMap < _1, _2 >::IsEmpty() const
    {
#line 581
        return GetCount() == 0;
    };
    
#line 638
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 638
        Remove(GetPos(it));
    };
    
#line 584
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::Remove(int i)
    {
        {
#line 584
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 584
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 584
        ;
#line 584
        keys.Remove(i);
#line 584
        values.Remove(i);
    };
    
#line 583
    template < class _1, class _2 >
    inline void ArrayMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 583
        int i = Find(key);
#line 583
        if (i >= 0)
#line 583
            Remove(i);
    };
    
#line 575
    template < class _1, class _2 >
    inline _2& ArrayMap < _1, _2 >::Top()
    {
        {
#line 575
            if (!(GetCount() > 0))
            {
#line 575
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 575
        ;
#line 575
        return values.Top();
    };
    
#line 655
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin() const
    {
#line 655
        return Begin();
    };
    
#line 653
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::begin()
    {
#line 653
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end() const
    {
#line 656
        return End();
    };
    
#line 654
    template < class _1, class _2 >
    inline Lang::FwdPairPtrIterator < _1, _2 > ArrayMap < _1, _2 >::end()
    {
#line 654
        return End();
    };
    
#line 885
    template < class _1 >
    inline _1& CachingVector < _1 >::operator[](int i)
    {
#line 885
        return data[i];
    };
    
#line 884
    template < class _1 >
    inline const _1& CachingVector < _1 >::operator[](int i) const
    {
#line 884
        return data[i];
    };
    
#line 889
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::Begin()
    {
#line 889
        return data.begin();
    };
    
#line 891
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::End()
    {
#line 891
        return data.begin() + count;
    };
    
#line 886
    template < class _1 >
    inline int CachingVector < _1 >::GetCount() const
    {
#line 886
        return count;
    };
    
#line 888
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::begin()
    {
#line 888
        return data.begin();
    };
    
#line 890
    template < class _1 >
    inline typename Lang::FwdIterator < _1 > CachingVector < _1 >::end()
    {
#line 890
        return data.begin() + count;
    };
    
#line 701
    template < class _1 >
    inline void FixedArray2 < _1 >::operator= (const FixedArray2& value)
    {
#line 701
        for (int i = 0; i < size; i ++ )
#line 701
            this -> vector[i] = value.vector[i];
    };
    
#line 700
    template < class _1 >
    inline void FixedArray2 < _1 >::operator= (const _1& value)
    {
#line 700
        for (int i = 0; i < size; i ++ )
#line 700
            this -> vector[i] = value;
    };
    
#line 698
    template < class _1 >
    inline _1& FixedArray2 < _1 >::operator[](int i)
    {
        {
#line 698
            if (!(i >= 0 && i < size))
            {
#line 698
                Lang::SysBreak("Assertion failed: i >= 0 && i < size");
            }
        }
#line 698
        ;
#line 698
        return vector[i];
    };
    
#line 699
    template < class _1 >
    inline const _1& FixedArray2 < _1 >::operator[](int i) const
    {
        {
#line 699
            if (!(i >= 0 && i < size))
            {
#line 699
                Lang::SysBreak("Assertion failed: i >= 0 && i < size");
            }
        }
#line 699
        ;
#line 699
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
    
#line 459
    template < class _1 >
    inline Index < _1 >::Index() {};
    
#line 514
    template < class _1 >
    inline void Index < _1 >::operator<<= (const Index& a)
    {
#line 514
        Set(a);
    };
    
#line 470
    template < class _1 >
    inline const _1& Index < _1 >::operator[](int i) const
    {
        {
#line 471
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 471
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 472
        ;
#line 472
        return values[i];
    };
    
#line 480
    template < class _1 >
    inline const _1& Index < _1 >::Add(const _1& value)
    {
#line 481
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Add(hash);
        return values.Add(value);
    };
    
#line 465
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::Begin() const
    {
#line 465
        return Iterator(values.Begin());
    };
    
#line 461
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::Begin()
    {
#line 461
        return Iterator(values.Begin());
    };
    
#line 509
    template < class _1 >
    inline void Index < _1 >::Clear()
    {
#line 509
        hashes.Clear();
#line 509
        values.Clear();
    };
    
#line 466
    template < class _1 >
    inline Lang::ConstFwdPtrIterator < _1 > Index < _1 >::End() const
    {
#line 466
        return Iterator(values.End());
    };
    
#line 463
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::End()
    {
#line 463
        return Iterator(values.End());
    };
    
#line 494
    template < class _1 >
    inline int Index < _1 >::Find(const _1& key) const
    {
#line 494
        return FindHash(Hash::GetValue(key));
    };
    
#line 495
    template < class _1 >
    inline int Index < _1 >::FindAdd(const _1& key)
    {
#line 495
        int i = Find(key);
#line 495
        if (i >= 0)
#line 495
            return i;
#line 495
        i = GetCount();
#line 495
        Add(key);
#line 495
        return i;
    };
    
#line 497
    template < class _1 >
    inline int Index < _1 >::FindHash(Lang::uint32 hash) const
    {
#line 498
        unsigned int * begin = hashes.Get();
        unsigned int * it = begin;
        unsigned int * end = begin + hashes.GetCount();
        while (it != end)
            {
#line 502
                if (*it == hash)
                    return it - begin;
                it ++ ;
            }
        return - 1;
    };
    
#line 467
    template < class _1 >
    inline _1 *Index < _1 >::Get()
    {
#line 467
        return values.Get();
    };
    
#line 479
    template < class _1 >
    inline int Index < _1 >::GetCount() const
    {
#line 479
        return values.GetCount();
    };
    
#line 468
    template < class _1 >
    inline _1 *Index < _1 >::GetEnd()
    {
#line 468
        return values.GetEnd();
    };
    
#line 487
    template < class _1 >
    inline _1& Index < _1 >::Insert(int i, const _1& value)
    {
#line 488
        Lang::uint32 hash = Hash::GetValue(value);
        if (FindHash(hash) >= 0)
            throw Text::Exc("Index has value already");
        hashes.Insert(i, hash);
        return values.Insert(i, value);
    };
    
#line 510
    template < class _1 >
    inline void Index < _1 >::Remove(int i)
    {
#line 510
        hashes.Remove(i);
#line 510
        values.Remove(i);
    };
    
#line 512
    template < class _1 >
    inline void Index < _1 >::RemoveKey(const _1& key)
    {
#line 512
        int i = Find(key);
#line 512
        if (i >= 0)
#line 512
            Remove(i);
    };
    
#line 511
    template < class _1 >
    inline void Index < _1 >::RemoveLast()
    {
        {
#line 511
            if (!(GetCount()))
            {
#line 511
                Lang::SysBreak("Assertion failed: GetCount()");
            }
        }
#line 511
        ;
#line 511
        if (GetCount())
#line 511
            Remove(GetCount() - 1);
    };
    
#line 475
    template < class _1 >
    inline void Index < _1 >::Set(const Index& i)
    {
#line 476
        hashes <<= i.hashes;
        values <<= i.values;
    };
    
#line 462
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::begin()
    {
#line 462
        return Iterator(values.Begin());
    };
    
#line 464
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > Index < _1 >::end()
    {
#line 464
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
    
#line 939
    inline OneAnon::OneAnon() {};
    
#line 940
    inline OneAnon::OneAnon(const OneAnon& o)
    {
#line 940
        *this = o;
    };
    
#line 983
    inline OneAnon::operator bool() const
    {
#line 983
        return !IsEmpty();
    };
    
#line 984
    inline Lang::int64 OneAnon::AsInt() const
    {
#line 984
        return(!obj.IsEmpty()) * 1;
    };
    
#line 942
    inline void OneAnon::Clear()
    {
#line 942
        obj.Clear();
    };
    
#line 982
    inline bool OneAnon::IsEmpty() const
    {
#line 982
        return obj.IsEmpty();
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
    
#line 719
    inline TopValueSorter10::TopValueSorter10()
    :
        count(0)
    {
#line 719
        Reset();
    };
    
#line 766
    template < class _1 >
    inline _1& TreeArray < _1 >::Add()
    {
#line 766
        _1 & t = branch.Add();
#line 766
        t.down = this;
#line 766
        return t;
    };
    
#line 774
    template < class _1 >
    inline _1& TreeArray < _1 >::Add(_1 *n)
    {
        {
#line 774
            if (!(n -> down == 0))
            {
#line 774
                Lang::SysBreak("Assertion failed: n->down == NULL");
            }
        }
#line 774
        ;
#line 774
        _1 & t = branch.Add(n);
#line 774
        t.down = this;
#line 774
        return t;
    };
    
#line 783
    template < class _1 >
    inline _1& TreeArray < _1 >::At(int i)
    {
#line 783
        return branch[i];
    };
    
#line 785
    template < class _1 >
    inline _1& TreeArray < _1 >::At(int i, _1& n)
    {
#line 785
        if (i < branch.GetCount())
#line 785
            return branch[i];
#line 785
        return n;
    };
    
#line 786
    template < class _1 >
    inline const _1& TreeArray < _1 >::At(int i) const
    {
#line 786
        return branch[i];
    };
    
#line 784
    template < class _1 >
    inline _1& TreeArray < _1 >::AtTop(int i)
    {
#line 784
        if (i < branch.GetCount())
#line 784
            return branch[i];
#line 784
        return branch.Top();
    };
    
#line 777
    template < class _1 >
    inline void TreeArray < _1 >::Clear()
    {
#line 777
        branch.Clear();
    };
    
#line 769
    template < class _1 >
    inline void TreeArray < _1 >::Copy(const PA& src)
    {
#line 769
        branch <<= src.branch;
#line 769
        for (int i = 0; i < branch.GetCount(); i ++ )
#line 769
            branch[i].down = this;
    };
    
#line 781
    template < class _1 >
    inline _1 *TreeArray < _1 >::Detach(int i)
    {
#line 781
        _1 * t = branch.Detach(i);
#line 781
        t -> down = 0;
#line 781
        return t;
    };
    
#line 789
    template < class _1 >
    inline int TreeArray < _1 >::GetCount() const
    {
#line 789
        return branch.GetCount();
    };
    
#line 773
    template < class _1 >
    inline _1 *TreeArray < _1 >::GetParent() const
    {
#line 773
        return down;
    };
    
#line 767
    template < class _1 >
    inline _1& TreeArray < _1 >::Insert(int i)
    {
#line 767
        _1 & t = branch.Insert(i);
#line 767
        t.down = this;
#line 767
        return t;
    };
    
#line 775
    template < class _1 >
    inline _1& TreeArray < _1 >::Insert(int i, _1 *n)
    {
        {
#line 775
            if (!(n -> down == 0))
            {
#line 775
                Lang::SysBreak("Assertion failed: n->down == NULL");
            }
        }
#line 775
        ;
#line 775
        _1 & t = branch.Insert(i, n);
#line 775
        t.down = this;
#line 775
        return t;
    };
    
#line 790
    template < class _1 >
    inline bool TreeArray < _1 >::IsEmpty() const
    {
#line 790
        return branch.IsEmpty();
    };
    
#line 778
    template < class _1 >
    inline void TreeArray < _1 >::Remove(int i)
    {
#line 778
        branch.Remove(i);
    };
    
#line 779
    template < class _1 >
    inline void TreeArray < _1 >::Remove(int i, int count)
    {
#line 779
        branch.Remove(i, count);
    };
    
#line 780
    template < class _1 >
    inline void TreeArray < _1 >::RemoveLast()
    {
#line 780
        branch.Remove(branch.GetCount() - 1);
    };
    
#line 799
    template < class _1 >
    inline void TreeArray < _1 >::Serialize(Abstract::StreamBase& s)
    {
#line 800
        s % branch;
        if (s.IsLoading())
            for (int i = 0; i < branch.GetCount(); i ++ )
                branch[i].down = this;
    };
    
#line 792
    template < class _1 >
    inline void TreeArray < _1 >::SortByInt()
    {
#line 793
        struct Sorter;
#line 796
        Sort(branch, Sorter());
    };
    
#line 787
    template < class _1 >
    inline _1& TreeArray < _1 >::Top()
    {
#line 787
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
    
#line 529
    template < class _1, class _2 >
    inline VectorMap < _1, _2 >::VectorMap() {};
    
#line 594
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::operator<<= (const VectorMap& a)
    {
#line 595
        keys <<= a.keys;
        values <<= a.values;
    };
    
#line 573
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::operator[](int i)
    {
#line 573
        return At(i);
    };
    
#line 572
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::operator[](int i) const
    {
#line 572
        return At(i);
    };
    
#line 535
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key)
    {
#line 536
        keys.Add(key);
        return values.Add();
    };
    
#line 545
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, _2 *value)
    {
#line 546
        keys.Add(key);
        return values.Add(value);
    };
    
#line 540
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Add(const _1& key, const _2& value)
    {
#line 541
        keys.Add(key);
        return values.Add(value);
    };
    
#line 567
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::At(int i)
    {
        {
#line 568
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 568
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 569
        ;
#line 569
        return values[i];
    };
    
#line 562
    template < class _1, class _2 >
    inline const _2& VectorMap < _1, _2 >::At(int i) const
    {
        {
#line 563
            if (!(i >= 0 && i < values.GetCount()))
            {
#line 563
                Lang::SysBreak("Assertion failed: i >= 0 && i < values.GetCount()");
            }
        }
#line 564
        ;
#line 564
        return values[i];
    };
    
#line 622
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin() const
    {
#line 622
        return Iterator(keys.Get(), values.Get());
    };
    
#line 620
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::Begin()
    {
#line 620
        return Iterator(keys.Get(), values.Get());
    };
    
#line 585
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Clear()
    {
#line 586
        keys.Clear();
        values.Clear();
    };
    
#line 589
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::ClearAndPickValues(Vector < _2 > & a)
    {
#line 590
        Swap(a, values);
        Clear();
    };
    
#line 623
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End() const
    {
#line 623
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 621
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::End()
    {
#line 621
        return Iterator(keys.GetEnd(), values.GetEnd());
    };
    
#line 577
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::Find(const _1& key) const
    {
#line 577
        return keys.Find(key);
    };
    
#line 613
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::FindIterator(const _1& key) const
    {
#line 614
        Iterator it = Begin();
        int pos = Find(key);
        if (pos == - 1)
#line 616
            it += GetCount();
        else
#line 617
            it += pos;
        return it;
    };
    
#line 579
    template < class _1, class _2 >
    inline _2 VectorMap < _1, _2 >::Get(const _1& key, _2 value) const
    {
#line 579
        int i = Find(key);
#line 579
        if (i < 0)
#line 579
            return value;
#line 579
        return values[i];
    };
    
#line 578
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Get(const _1& key)
    {
#line 578
        return values[Find(key)];
    };
    
#line 550
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::GetAdd(const _1& key)
    {
#line 551
        int i = keys.Find(key);
        if (i >= 0)
#line 552
            return values[i];
        keys.Add(key);
        return values.Add();
    };
    
#line 580
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetCount() const
    {
#line 580
        return keys.GetCount();
    };
    
#line 560
    template < class _1, class _2 >
    inline const _1& VectorMap < _1, _2 >::GetKey(int i) const
    {
#line 560
        return keys[i];
    };
    
#line 531
    template < class _1, class _2 >
    inline const Index < _1 > & VectorMap < _1, _2 >::GetKeys() const
    {
#line 531
        return keys;
    };
    
#line 603
    template < class _1, class _2 >
    inline int VectorMap < _1, _2 >::GetPos(const Iterator& it)
    {
#line 604
        _1 * begin = keys.Get();
        _1 * cur = &it.Key();
        int pos = cur - begin;
        return pos;
    };
    
#line 533
    template < class _1, class _2 >
    inline Vector < _2 > & VectorMap < _1, _2 >::GetValues()
    {
#line 533
        return values;
    };
    
#line 532
    template < class _1, class _2 >
    inline const Vector < _2 > & VectorMap < _1, _2 >::GetValues() const
    {
#line 532
        return values;
    };
    
#line 557
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key)
    {
#line 557
        keys.Insert(i, key);
#line 557
        return values.Insert(i);
    };
    
#line 558
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Insert(int i, const _1& key, const _2& value)
    {
#line 558
        keys.Insert(i, key);
#line 558
        return values.Insert(i, value);
    };
    
#line 612
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key)
    {
#line 612
        int pos = GetPos(it);
#line 612
        Insert(pos, key);
#line 612
        Iterator cur = Begin();
#line 612
        cur += pos;
#line 612
        return cur;
    };
    
#line 611
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, _2 *value)
    {
#line 611
        int pos = GetPos(it);
#line 611
        Insert(pos, key, value);
#line 611
        Iterator cur = Begin();
#line 611
        cur += pos;
#line 611
        return cur;
    };
    
#line 610
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::InsertIterator(const Iterator& it, const _1& key, const _2& value)
    {
#line 610
        int pos = GetPos(it);
#line 610
        Insert(pos, key, value);
#line 610
        Iterator cur = Begin();
#line 610
        cur += pos;
#line 610
        return cur;
    };
    
#line 581
    template < class _1, class _2 >
    inline bool VectorMap < _1, _2 >::IsEmpty() const
    {
#line 581
        return GetCount() == 0;
    };
    
#line 609
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(const Iterator& it)
    {
#line 609
        Remove(GetPos(it));
    };
    
#line 584
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::Remove(int i)
    {
        {
#line 584
            if (!(i >= 0 && i < keys.GetCount()))
            {
#line 584
                Lang::SysBreak("Assertion failed: i >= 0 && i < keys.GetCount()");
            }
        }
#line 584
        ;
#line 584
        keys.Remove(i);
#line 584
        values.Remove(i);
    };
    
#line 583
    template < class _1, class _2 >
    inline void VectorMap < _1, _2 >::RemoveKey(const _1& key)
    {
#line 583
        int i = Find(key);
#line 583
        if (i >= 0)
#line 583
            Remove(i);
    };
    
#line 575
    template < class _1, class _2 >
    inline _2& VectorMap < _1, _2 >::Top()
    {
        {
#line 575
            if (!(GetCount() > 0))
            {
#line 575
                Lang::SysBreak("Assertion failed: GetCount() > 0");
            }
        }
#line 575
        ;
#line 575
        return values.Top();
    };
    
#line 626
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin() const
    {
#line 626
        return Begin();
    };
    
#line 624
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::begin()
    {
#line 624
        return Begin();
    };
    
    template < class _1, class _2 >
    inline Lang::ConstFwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end() const
    {
#line 627
        return End();
    };
    
#line 625
    template < class _1, class _2 >
    inline Lang::FwdPairIterator < _1, _2 > VectorMap < _1, _2 >::end()
    {
#line 625
        return End();
    };
    
#line 284
    template < class _1 >
    inline VectorPtr < _1 >::VectorPtr() {};
    
#line 285
    template < class _1 >
    inline VectorPtr < _1 >::VectorPtr(const VectorPtr& v)
    :
        data(v)
    {};
    
#line 292
    template < class _1 >
    inline _1& VectorPtr < _1 >::operator[](int i)
    {
#line 292
        return *data[i];
    };
    
#line 293
    template < class _1 >
    inline const _1& VectorPtr < _1 >::operator[](int i) const
    {
#line 293
        return *data[i];
    };
    
#line 288
    template < class _1 >
    inline _1& VectorPtr < _1 >::Add(_1 *o)
    {
#line 288
        data.Add(o);
#line 288
        return *o;
    };
    
#line 290
    template < class _1 >
    inline void VectorPtr < _1 >::Append(const VectorPtr& v)
    {
#line 290
        data.Append(v.data);
    };
    
#line 291
    template < class _1 >
    inline void VectorPtr < _1 >::Append(const VectorPtr& v, int i, int n)
    {
#line 291
        data.Append(v.data, i, n);
    };
    
#line 298
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > VectorPtr < _1 >::Begin()
    {
#line 298
        return Lang::FwdPtrIterator < _1 > (data.Get());
    };
    
#line 295
    template < class _1 >
    inline void VectorPtr < _1 >::Clear()
    {
#line 295
        data.Clear();
    };
    
#line 299
    template < class _1 >
    inline Lang::FwdPtrIterator < _1 > VectorPtr < _1 >::End()
    {
#line 299
        return Lang::FwdPtrIterator < _1 > (data.GetEnd());
    };
    
#line 289
    template < class _1 >
    inline int VectorPtr < _1 >::GetCount() const
    {
#line 289
        return data.GetCount();
    };
    
#line 301
    template < class _1 >
    inline Text::String VectorPtr < _1 >::Join(Text::String join_str, bool ignore_empty) const
    {
#line 302
        Text::String out;
        ConstIterator end = data.End();
        for (ConstIterator it = data.Begin(); it != end; ++ it)
            {
#line 305
                Text::String s = Text::ToString < _1 > (**it);
                if (s.IsEmpty() && ignore_empty)
                    continue;
                
#line 308
                if (!out.IsEmpty())
                    out << join_str;
                out << s;
            }
        return out;
    };
    
#line 296
    template < class _1 >
    inline _1 *VectorPtr < _1 >::Pop()
    {
#line 296
        return data.Pop();
    };
    
#line 294
    template < class _1 >
    inline _1 *& VectorPtr < _1 >::Ref(int i)
    {
#line 294
        return data[i];
    };
    
    template < class _1 >
    inline void VectorPtr < _1 >::SetCount(int i)
    {
#line 297
        data.SetCount(i, 0);
    };
    
};

#endif
