#ifndef CONTAINER_CXX
#define CONTAINER_CXX

#include <new>

#ifndef CONTAINER_HXX
#include <Container.hxx>
#endif

namespace Container
{
#line 884 "../../src/Com/Container.fog"
    template < class _1 >
    void CachingVector < _1 >::SetCount(int i)
    {
#line 884
        if (data.GetCount() < i)
#line 884
            data.SetCount(i);
#line 884
        count = i;
    };
    
#line 691
    template < class _1 >
    const int FixedArray2 < _1 >::size = 2;
    
#line 124
    template < class _1 >
    Optional < _1 >::Optional(const Optional& opt)
    :
        obj(0)
    {
#line 124
        if (opt.obj)
#line 124
            this -> obj = new _1(*opt.obj);
    };
    
    template < class _1 >
    Optional < _1 >::Optional(const PickT& n)
    :
        obj(0)
    {
#line 127
        *this = n;
    };
    
#line 125
    template < class _1 >
    Optional < _1 >::Optional(const _1& obj)
    :
        obj(0)
    {
#line 125
        this -> obj = new _1(obj);
    };
    
#line 139
    template < class _1 >
    _1 *Optional < _1 >::operator-> ()
    {
        {
#line 139
            if (!(obj))
            {
#line 139
                Lang::SysBreak("Assertion failed: obj");
            }
        }
#line 139
        ;
#line 139
        return obj;
    };
    
#line 134
    template < class _1 >
    void Optional < _1 >::operator= (const Optional& o)
    {
#line 134
        Clear();
#line 134
        if (!o.IsEmpty())
        {
#line 134
            this -> obj = new _1(*o.obj);
        }
    };
    
#line 135
    template < class _1 >
    void Optional < _1 >::operator= (const PickOpt& n)
    {
#line 135
        Clear();
#line 135
        if (!n.Get().IsEmpty())
        {
#line 135
            Pick(n.Get());
        }
    };
    
#line 136
    template < class _1 >
    void Optional < _1 >::Pick(Optional& o)
    {
#line 136
        obj = o.obj;
#line 136
        o.obj = 0;
    };
    
#line 847
    void SortedIntMap::Add(int key, int value)
    {
#line 848
        Lang::DynArray < int > & key_vec = data[key];
        if (key_vec.IsEmpty())
        {
#line 850
            int mask_i = key / 64;
            Lang::int64 bit_i = key % 64;
            Lang::uint64 & v = value_mask[mask_i];
            Lang::uint64 add = 1LL << bit_i;
            v |= add;
        }
        key_vec.Add(value);
        count ++ ;
        if (key < first_data_i)
            first_data_i = key;
    };
    
#line 830
    void SortedIntMap::Clear()
    {
        {
#line 832
            Lang::FwdIterator < Lang::DynArray < int > > it = data.Begin();
            Lang::FwdIterator < Lang::DynArray < int > > end = data.End();
            for (; it != end; ++ it)
#line 834
                it -> SetCount(0);
        }
        {
            Lang::FwdIterator < Lang::uint64 > it = value_mask.Begin();
            Lang::FwdIterator < Lang::uint64 > end = value_mask.End();
            for (; it != end; ++ it)
#line 839
                *it = 0;
        }
#line 843
        count = 0;
        first_data_i = 2147483647;
    };
    
#line 822
    void SortedIntMap::Reserve(int count)
    {
#line 823
        if (count > data.GetCount())
        {
#line 824
            data.SetCount(count);
            int value_count = count / 64 + 1;
            value_mask.SetCount(value_count, 0);
        }
    };
    
#line 707
    const int TopValueSorter10::size = 10;
    
#line 724
    void TopValueSorter10::Add(const Key& key, const Value& value)
    {
#line 725
        if (value <= this -> value[size - 1])
            return;
        for (int i = 0; i < size; i ++ )
            {
#line 728
                if (value > this -> value[i])
                {
#line 729
                    for (int j = size - 1; j > i; j -- )
                        {
#line 730
                            this -> value[j] = this -> value[j - 1];
                            this -> key[j] = this -> key[j - 1];
                        }
                    this -> value[i] = value;
                    this -> key[i] = key;
                    count = Algorithm::Minimum(count + 1, size);
                    break;
                
                }
            }
    };
    
#line 717
    void TopValueSorter10::Reset()
    {
#line 718
        count = 0;
        for (int i = 0; i < size; i ++ )
            {
#line 720
                value[i] = - 1.7976931348623157e+306;
                key[i] = - 1;
            }
    };
    
#line 740
    void TopValueSorter10::Serialize(Abstract::StreamBase& s)
    {
#line 741
        for (int i = 0; i < size; i ++ )
            s % value[i] % key[i];
    };
    
};

#endif
