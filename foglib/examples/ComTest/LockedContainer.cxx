#ifndef LOCKEDCONTAINER_CXX
#define LOCKEDCONTAINER_CXX

#include <new>

#ifndef LOCKEDCONTAINER_HXX
#include <LockedContainer.hxx>
#endif

namespace LockedContainer
{
#line 144 "../../src/Com/LockedContainer.fog"
    void HugePersistent::Alloc()
    {
#line 144
        Free();
        {
#line 144
            if (!(data_size > 0))
            {
#line 144
                Lang::SysBreak("Assertion failed: data_size > 0");
            }
        }
#line 144
        ;
#line 144
        data = Lang::Memory::Alloc(data_size);
    };
    
#line 145
    void HugePersistent::Free()
    {
#line 145
        if (data)
        {
#line 145
            Lang::Memory::Free(data);
#line 145
            data = 0;
        }
    };
    
#line 550
    void HugePersistent::LoadData()
    {
#line 551
        if (persistent_size == 0)
            Lang::SysBreak("Database size is 0");
        {
#line 553
            if (!(filename.GetCount()))
            {
#line 553
                Lang::SysBreak("Assertion failed: filename.GetCount()");
            }
        }
#line 554
        ;
#line 554
        Util::RealizeDirectory(Util::GetDataDirectory());
        Text::String file = Util::AppendFileName(Util::GetDataDirectory(), filename);
        Text::String prev_file = file + ".0";
#line 558
        if (Util::FileExists(prev_file))
            file = prev_file;
#line 561
        Stream::FileIn fin(file);
        Lang::int64 file_persistent_size = 0;
        fin.Get(&file_persistent_size, sizeof (file_persistent_size));
        if (file_persistent_size != persistent_size)
            Util::Panic((Text::String)"File header size mismatch configuration size: " + Text::String::IntStr64(file_persistent_size) + " != " + Text::String::IntStr64(persistent_size));
#line 567
        if (!data)
        {
#line 568
            data = Lang::Memory::Alloc(data_size);
#line 570
            Lang::byte * zero_begin = (Lang::byte * ) data + persistent_size;
            Lang::int64 zero_size = data_size - persistent_size;
            Lang::Memory::Set(data, 0, zero_size);
        }
#line 575
        Chrono::TimeStop ts;
        Lang::dword * data = (Lang::dword * ) this -> data;
        Lang::int64 data_left = persistent_size;
        int chunk_dwords = 0x1000000;
        int chunk = chunk_dwords * sizeof (int);
        while (data_left > 0)
            {
#line 581
                if (data_left > chunk)
                {
#line 582
                    fin.Get(data, chunk);
                    data += chunk_dwords;
                    data_left -= chunk;
                }
                else
                {
#line 587
                    fin.Get(data, data_left);
                    data_left = 0;
                }
            }
        {
#line 591
            Util::Log() << "Loading database took " << ts.AsString() << "\n";
#line 591
            Util::Log().Flush();
        }
#line 592
        ;
    };
    
#line 514
    void HugePersistent::StoreData()
    {
        {
#line 515
            if (!(data_size > 0))
            {
#line 515
                Lang::SysBreak("Assertion failed: data_size > 0");
            }
        }
#line 516
        ;
        {
#line 516
            if (!(persistent_size > 0))
            {
#line 516
                Lang::SysBreak("Assertion failed: persistent_size > 0");
            }
        }
#line 517
        ;
        {
#line 517
            if (!(data))
            {
#line 517
                Lang::SysBreak("Assertion failed: data");
            }
        }
#line 518
        ;
        {
#line 518
            if (!(filename.GetCount()))
            {
#line 518
                Lang::SysBreak("Assertion failed: filename.GetCount()");
            }
        }
#line 519
        ;
#line 519
        Util::RealizeDirectory(Util::GetDataDirectory());
        Text::String file = Util::AppendFileName(Util::GetDataDirectory(), filename);
        Text::String prev_file = file + ".0";
#line 523
        if (Util::FileExists(file))
        {
#line 524
            if (Util::FileExists(prev_file))
                Util::DeleteFile(prev_file);
            Util::RenameFile(file, prev_file);
        }
        Stream::FileOut fout(file);
        fout.Put(&persistent_size, sizeof (persistent_size));
#line 531
        Lang::dword * data = (Lang::dword * ) this -> data;
        Lang::int64 data_left = persistent_size;
        int chunk_dwords = 0x1000000;
        int chunk = chunk_dwords * sizeof (int);
        while (data_left > 0)
            {
#line 536
                if (data_left > chunk)
                {
#line 537
                    fout.Put(data, chunk);
                    data += chunk_dwords;
                    data_left -= chunk;
                }
                else
                {
#line 542
                    fout.Put(data, data_left);
                    data_left = 0;
                }
            }
#line 547
        Util::DeleteFile(prev_file);
    };
    
#line 377
    void OrderedLinkedList::Add(Lang::dword key, Lang::dword value)
    {
#line 378
        lock.Enter();
        OrderedLinkedItem & it = Alloc();
        it.key = key;
        it.value = value;
        Lang::dword begin_i = GetBeginPos(key);
        OrderedLinkedItem * &key_begin = begins.Ref(begin_i);
        if (key_begin)
        {
#line 385
            if (key < key_begin -> key)
            {
#line 386
                InsertBetween(&it, key_begin -> prev, key_begin);
                key_begin = &it;
            }
            else
            {
#line 390
                OrderedLinkedItem * prev = FindWhereNext(key, key_begin);
                {
#line 391
                    if (!(prev -> key <= key))
                    {
#line 391
                        Lang::SysBreak("Assertion failed: prev->key <= key");
                    }
                }
#line 392
                ;
#line 392
                InsertBetween(&it, prev, prev -> next);
            }
        }
        else
        {
#line 396
            key_begin = &it;
            OrderedLinkedItem * closest = FindClosest(begin_i, key);
            if (!closest)
                InsertBetween(&it, 0, 0);
            else
            {
#line 401
                if (closest -> key <= key)
                    InsertBetween(&it, closest, closest -> next);
                else
                    InsertBetween(&it, closest -> prev, closest);
            }
        }
        total_added ++ ;
        count ++ ;
#line 410
        lock.Leave();
    };
    
#line 228
    OrderedLinkedItem& OrderedLinkedList::Alloc()
    {
#line 229
        if (unused.GetCount())
            return *unused.Pop();
        else
            return items.Add();
    };
    
#line 179
    void OrderedLinkedList::Clear()
    {
#line 180
        items.SetCount(0);
        begins.SetCount(0);
        unused.SetCount(0);
        begin = 0;
        end = 0;
        min = 0;
        max = 0;
        step = 0;
        total_added = 0;
        count = 0;
    };
    
#line 239
    int OrderedLinkedList::CountDistanceNotZero(OrderedLinkedItem *a, OrderedLinkedItem *b)
    {
#line 240
        bool do_next = true;
        ;
#line 241
        if (b -> key < a -> key)
            do_next = false;
        for (int i = 0; i < 2; i ++ )
            {
#line 244
                if (i)
#line 244
                    do_next = !do_next;
                OrderedLinkedItem * it = a;
                int dist = 0;
                while (true)
                    {
#line 248
                        if (dist > 0 && it == b)
                            return dist;
                        if (do_next)
                        {
#line 251
                            if (it -> next)
                                it = it -> next;
                            else
                                break;
                        
                        }
                        else
                        {
#line 257
                            if (it -> prev)
                                it = it -> prev;
                            else
                                break;
                        
                        }
#line 262
                        dist ++ ;
                    }
            }
        return - 1;
    };
    
#line 343
    OrderedLinkedItem *OrderedLinkedList::FindClosest(Lang::dword begin_i, Lang::dword key)
    {
#line 344
        int dec = begin_i - 1;
        int inc = begin_i + 1;
        while (true)
            {
#line 347
                bool part_succ = false;
                if (dec >= 0)
                {
#line 349
                    OrderedLinkedItem * it = &begins[dec];
                    if (it)
                    {
#line 351
                        while (it -> next && it -> next -> key < key)
                            it = it -> next;
                        return it;
                    }
                    dec -- ;
                    part_succ = true;
                }
                if (inc < begins.GetCount())
                {
#line 359
                    OrderedLinkedItem * it = &begins[inc];
                    if (it)
                        return it;
                    inc ++ ;
                    part_succ = true;
                }
                if (!part_succ)
#line 365
                    break;
            
            }
#line 367
        return 0;
    };
    
#line 334
    OrderedLinkedItem *OrderedLinkedList::FindWhereNext(Lang::dword key, OrderedLinkedItem *prev)
    {
#line 335
        while (prev -> next)
            {
#line 336
                if (prev -> next -> key > key)
                    break;
                
#line 338
                prev = prev -> next;
            }
        return prev;
    };
    
#line 235
    void OrderedLinkedList::Free(OrderedLinkedItem *t)
    {
#line 236
        unused.Add(t);
    };
    
#line 370
    Lang::dword OrderedLinkedList::GetBeginPos(Lang::dword key)
    {
#line 371
        if (key < min || key >= max + step)
            Util::Panic(Interface::Formater("Invalid key %s (not between %s and %s)")(key)(min)(max));
        Lang::dword begin_i = (key - min) / step;
        return begin_i;
    };
    
#line 213
    void OrderedLinkedList::Init(Lang::dword min, Lang::dword max, Lang::dword step)
    {
#line 214
        Clear();
        if (max <= min || !step)
            Util::Panic(Interface::Formater("Invalid OrderedLinkedList usage: min=%s, max=%s, step=%s")(min)(max)(step));
#line 219
        this -> min = min;
        this -> max = max;
        this -> step = step;
        Lang::dword count = (max - min) / step + 1;
        if (!count || count > 10000000)
            Util::Panic(Interface::Formater("Invalid OrderedLinkedList usage: count=%s")(count));
        begins.SetCount(count);
    };
    
#line 280
    void OrderedLinkedList::InsertBetween(OrderedLinkedItem *it, OrderedLinkedItem *prev, OrderedLinkedItem *next)
    {
#line 281
        it -> prev = prev;
        it -> next = next;
#line 284
        if (!prev)
        {
#line 285
            begin = it;
            if (next)
            {
                {
#line 287
                    if (!(next -> prev != it))
                    {
#line 287
                        Lang::SysBreak("Assertion failed: next->prev != it");
                    }
                }
#line 288
                ;
#line 288
                next -> prev = it;
            }
            else
                end = it;
        }
        else 
#line 293
        if (!next)
        {
#line 294
            end = it;
            if (prev)
            {
                {
#line 296
                    if (!(prev -> next != it))
                    {
#line 296
                        Lang::SysBreak("Assertion failed: prev->next != it");
                    }
                }
#line 297
                ;
#line 297
                prev -> next = it;
            }
            else
                begin = it;
        }
        else
        {
            {
#line 303
                if (!(prev -> next != it))
                {
#line 303
                    Lang::SysBreak("Assertion failed: prev->next != it");
                }
            }
#line 304
            ;
            {
#line 304
                if (!(next -> prev != it))
                {
#line 304
                    Lang::SysBreak("Assertion failed: next->prev != it");
                }
            }
#line 305
            ;
#line 305
            prev -> next = it;
            next -> prev = it;
        }
    };
    
#line 268
    bool OrderedLinkedList::IsOrdered() const
    {
#line 269
        OrderedLinkedItem * it = begin;
        Lang::dword key = min;
        while (it != end)
            {
#line 272
                if (it -> key < key)
                    return false;
                key = it -> key;
                it = it -> next;
            }
        return true;
    };
    
#line 477
    bool OrderedLinkedList::PopBegin(Lang::dword& key, Lang::dword& value)
    {
#line 478
        bool succ = false;
        lock.Enter();
        if (begin)
        {
#line 481
            OrderedLinkedItem * it = begin;
            key = it -> key;
            value = it -> value;
            RemoveUnsafe(it);
            succ = true;
        }
        lock.Leave();
        return succ;
    };
    
#line 413
    void OrderedLinkedList::Remove(Lang::dword key, Lang::dword value)
    {
#line 414
        if (key < min || key >= max + step)
            Util::Panic(Interface::Formater("Invalid key %s (not between %s and %s)")(key)(min)(max));
#line 417
        lock.Enter();
        Lang::dword begin_i = GetBeginPos(key);
        OrderedLinkedItem * it = 0;
        OrderedLinkedItem * &key_begin = begins.Ref(begin_i);
        {
#line 421
            if (!(key_begin))
            {
#line 421
                Lang::SysBreak("Assertion failed: key_begin");
            }
        }
#line 422
        ;
#line 422
        if (key_begin -> value == value)
        {
#line 423
            it = key_begin;
            if (key_begin -> next)
            {
#line 425
                Lang::dword next_begin_i = GetBeginPos(key_begin -> next -> key);
                if (begin_i == next_begin_i)
                    key_begin = key_begin -> next;
                else
                    key_begin = 0;
            }
            else
#line 431
                key_begin = 0;
        }
        else
        {
#line 434
            OrderedLinkedItem * find = key_begin -> next;
            while (find && find -> value != value && find -> next)
                find = find -> next;
            {
#line 437
                if (!(find && find -> value == value))
                {
#line 437
                    Lang::SysBreak("Assertion failed: find && find->value == value");
                }
            }
#line 438
            ;
#line 438
            it = find;
        }
        {
#line 440
            if (!(it && it -> value == value))
            {
#line 440
                Lang::SysBreak("Assertion failed: it && it->value == value");
            }
        }
#line 441
        ;
#line 441
        if (it && it -> value == value)
        {
#line 442
            RemoveBetween(it);
            Free(it);
            count -- ;
        }
#line 447
        lock.Leave();
    };
    
    void OrderedLinkedList::Remove(OrderedLinkedItem *it)
    {
#line 451
        if (!it)
            return;
        lock.Enter();
        RemoveUnsafe(it);
        lock.Leave();
    };
    
#line 311
    void OrderedLinkedList::RemoveBetween(OrderedLinkedItem *it)
    {
        if (it -> prev && it -> next)
        {
#line 314
            it -> next -> prev = it -> prev;
            it -> prev -> next = it -> next;
        }
        else 
#line 317
        if (it -> prev)
        {
#line 318
            end = it -> prev;
            it -> prev -> next = 0;
        }
        else 
#line 321
        if (it -> next)
        {
#line 322
            begin = it -> next;
            it -> next -> prev = 0;
        }
        else
        {
#line 326
            begin = 0;
            end = 0;
        }
        it -> prev = 0;
        it -> next = 0;
    };
    
#line 458
    void OrderedLinkedList::RemoveUnsafe(OrderedLinkedItem *it)
    {
#line 459
        Lang::dword begin_i = GetBeginPos(it -> key);
        OrderedLinkedItem * &key_begin = begins.Ref(begin_i);
        {
#line 461
            if (!(key_begin))
            {
#line 461
                Lang::SysBreak("Assertion failed: key_begin");
            }
        }
#line 462
        ;
#line 462
        if (key_begin == it)
        {
#line 463
            if (key_begin -> next)
            {
#line 464
                Lang::dword next_begin_i = GetBeginPos(key_begin -> next -> key);
                if (begin_i == next_begin_i)
                    key_begin = key_begin -> next;
                else
                    key_begin = 0;
            }
            else
#line 470
                key_begin = 0;
        }
        RemoveBetween(it);
        count -- ;
        Free(it);
    };
    
#line 192
    void OrderedLinkedList::Zero()
    {
#line 193
        lock.Enter();
#line 195
        Lang::FwdPtrIterator < OrderedLinkedItem > it = begins.Begin();
        Lang::FwdPtrIterator < OrderedLinkedItem > end = begins.End();
        for (; it != end; ++ it)
            it.Ref() = 0;
        unused.SetCount(items.GetCount());
        Lang::FwdPtrIterator < OrderedLinkedItem > dst = unused.Begin();
        it = items.Begin();
        end = items.End();
        for (; it != end; ++ it, ++ dst)
            dst.Ref() = it.Get();
        begin = 0;
        end = 0;
        total_added = 0;
        count = 0;
#line 210
        lock.Leave();
    };
    
#line 101
    template < class _1 >
    void Recycler < _1 >::Cleanup(_1& o) {};
    
#line 105
    template < class _1 >
    void Recycler < _1 >::Clear()
    {
#line 106
        arr_lock.Enter();
        used_lock.Enter();
#line 109
        arr.Clear();
        used.Clear();
#line 112
        used_lock.Leave();
        arr_lock.Leave();
    };
    
    template < class _1 >
    _1& Recycler < _1 >::Create()
    {
#line 116
        _1 * e = Used();
#line 116
        if (e)
#line 116
            return *e;
#line 116
        return New();
    };
    
#line 91
    template < class _1 >
    _1& Recycler < _1 >::New()
    {
#line 92
        arr_lock.Enter();
        _1 & e = arr.Add(NewOperator());
        arr_lock.Leave();
        return e;
    };
    
#line 117
    template < class _1 >
    void Recycler < _1 >::Recycle(_1& e)
    {
#line 118
        Cleanup(e);
        used_lock.Enter();
        used.Add(&e);
        used_lock.Leave();
    };
    
#line 100
    template < class _1 >
    void Recycler < _1 >::Refurbish(_1& o) {};
    
#line 77
    template < class _1 >
    _1 *Recycler < _1 >::Used()
    {
#line 78
        if (used.IsEmpty())
#line 78
            return 0;
#line 80
        _1 * e = 0;
        used_lock.Enter();
        if (!used.IsEmpty())
            e = used.Pop();
        used_lock.Leave();
#line 86
        Refurbish(*e);
#line 88
        return e;
    };
    
#line 65
    RecyclerBase::~RecyclerBase() {};
    
#line 66
    void RecyclerBase::Clear() {};
    
};

#endif
