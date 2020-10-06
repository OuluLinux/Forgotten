#ifndef LOCKEDCONTAINER_HXX
#define LOCKEDCONTAINER_HXX

#include <new>

#ifndef CONCURRENCY_HXX
#include <Concurrency.hxx>
#endif
#ifndef INTERFACE_HXX
#include <Interface.hxx>
#endif

namespace LockedContainer
{
    struct HugePersistent
    {
#line 133 "../../src/Com/LockedContainer.fog"
        Text::String filename;
        Lang::int64 data_size;
        Lang::int64 persistent_size;
#line 139
        void *data;
        
#line 143
        inline ~HugePersistent();
        void Alloc();
        void Free();
#line 550
        void LoadData();
#line 150
        inline void Serialize(Abstract::StreamBase& s);
#line 514
        void StoreData();
    };
    
    struct OrderedLinkedItem
    {
#line 6
        typedef OrderedLinkedItem Item;
        
        Item *prev;
        Item *next;
        Lang::dword value;
        Lang::dword key;
    };
    
    struct OrderedLinkedList
    {
#line 29
        Container::Array < OrderedLinkedItem > items;
        Container::VectorPtr < OrderedLinkedItem > begins;
        Container::VectorPtr < OrderedLinkedItem > unused;
        OrderedLinkedItem *begin;
#line 32
        OrderedLinkedItem *end;
        Lang::dword min;
#line 33
        Lang::dword max;
#line 33
        Lang::dword step;
        Concurrency::Mutex lock;
        Lang::dword total_added;
        Lang::dword count;
        
#line 377
        void Add(Lang::dword key, Lang::dword value);
#line 228
        OrderedLinkedItem& Alloc();
#line 179
        void Clear();
#line 239
        int CountDistanceNotZero(OrderedLinkedItem *a, OrderedLinkedItem *b);
#line 343
        OrderedLinkedItem *FindClosest(Lang::dword begin_i, Lang::dword key);
#line 334
        OrderedLinkedItem *FindWhereNext(Lang::dword key, OrderedLinkedItem *prev);
#line 235
        void Free(OrderedLinkedItem *t);
#line 370
        Lang::dword GetBeginPos(Lang::dword key);
#line 56
        inline Lang::dword GetMaxKey() const;
#line 55
        inline Lang::dword GetMinKey() const;
#line 213
        void Init(Lang::dword min, Lang::dword max, Lang::dword step);
#line 280
        void InsertBetween(OrderedLinkedItem *it, OrderedLinkedItem *prev, OrderedLinkedItem *next);
#line 268
        bool IsOrdered() const;
#line 477
        bool PopBegin(Lang::dword& key, Lang::dword& value);
#line 413
        void Remove(Lang::dword key, Lang::dword value);
#line 450
        void Remove(OrderedLinkedItem *it);
#line 311
        void RemoveBetween(OrderedLinkedItem *it);
#line 458
        void RemoveUnsafe(OrderedLinkedItem *it);
#line 192
        void Zero();
    };
    
    class RecyclerBase
    {
    public:
#line 65
        virtual ~RecyclerBase();
        virtual void Clear();
    };
    
    template < class _1 >
    class Recycler : public LockedContainer::RecyclerBase
    {
        Container::Array < _1 > arr;
        Container::VectorPtr < _1 > used;
        Concurrency::Mutex arr_lock;
#line 74
        Concurrency::Mutex used_lock;
        
    public:
#line 105
        virtual void Clear();
#line 116
        _1& Create();
#line 125
        inline Container::Array < _1 > & GetArray();
#line 117
        void Recycle(_1& e);
#line 123
        inline void Reserve(int i);
        
    protected:
#line 101
        virtual void Cleanup(_1& o);
#line 99
        /*pure*/virtual _1 *NewOperator() = 0;
        virtual void Refurbish(_1& o);
        
#line 91
        _1& New();
#line 77
        _1 *Used();
    };
};

namespace LockedContainer
{
#line 143
    inline HugePersistent::~HugePersistent()
    {
#line 143
        Free();
    };
    
#line 150
    inline void HugePersistent::Serialize(Abstract::StreamBase& s)
    {
#line 151
        s % filename % data_size % persistent_size;
    };
    
#line 56
    inline Lang::dword OrderedLinkedList::GetMaxKey() const
    {
#line 56
        if (end)
#line 56
            return end -> key;
#line 56
        return 0;
    };
    
#line 55
    inline Lang::dword OrderedLinkedList::GetMinKey() const
    {
#line 55
        if (begin)
#line 55
            return begin -> key;
#line 55
        return 0;
    };
    
#line 125
    template < class _1 >
    inline Container::Array < _1 > & Recycler < _1 >::GetArray()
    {
#line 125
        return arr;
    };
    
#line 123
    template < class _1 >
    inline void Recycler < _1 >::Reserve(int i)
    {
#line 123
        arr.Reserve(i);
    };
    
};

#endif
