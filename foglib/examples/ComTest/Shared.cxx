#ifndef SHARED_CXX
#define SHARED_CXX

#include <new>

#ifndef SHARED_HXX
#include <Shared.hxx>
#endif

namespace Shared
{
#line 70 "../../src/Com/Shared.fog"
    Attachable::~Attachable()
    {
#line 70
        DetachAll();
    };
    
#line 181 "../../src/Com/Meta.fog"
    void Attachable::AddSlot(Slot *ptr)
    {
#line 181
        slots.Add(ptr);
    };
    
#line 85 "../../src/Com/Shared.fog"
    void Attachable::Detach(Slot *ptr)
    {
#line 86
        DoDetach(ptr);
        ptr -> SetPtr(0);
    };
    
#line 73
    void Attachable::DetachAll()
    {
#line 74
        for (Iter it = slots.Begin(), end = slots.End(); it != end; ++ it)
            ((Slot * ) * it)-> SetPtr(0);
        slots.Clear();
    };
    
#line 52
    void Attachable::DoAttach(Slot *s)
    {
        {
#line 53
            if (!(s && s -> GetPtr() == 0 && !IsAttached(s)))
            {
#line 53
                Lang::SysBreak("Assertion failed: s && s->GetPtr() == 0 && !IsAttached(s)");
            }
        }
#line 54
        ;
#line 54
        AddSlot(s);
        s -> SetPtr(this);
    };
    
#line 57
    void Attachable::DoDetach(Slot *s)
    {
#line 58
        int i = 0;
        for (Iter it = slots.Begin(), end = slots.End(); it != end; ++ it)
            {
#line 60
                if ((Slot * ) * it == s)
                {
#line 61
                    slots.Remove(i);
                    break;
                
                }
#line 64
                i ++ ;
            }
    };
    
#line 178 "../../src/Com/Meta.fog"
    Slot& Attachable::GetSlot(int i)
    {
#line 178
        return *(Slot * ) slots[i];
    };
    
#line 180
    int Attachable::GetSlotCount()
    {
#line 180
        return slots.GetCount();
    };
    
#line 78 "../../src/Com/Shared.fog"
    bool Attachable::IsAttached(Slot *ptr)
    {
#line 79
        for (Iter it = slots.Begin(), end = slots.End(); it != end; ++ it)
            {
#line 80
                if ((Slot * ) * it == ptr)
                    return true;
            }
        return false;
    };
    
#line 179 "../../src/Com/Meta.fog"
    void Attachable::RemoveSlot(int i)
    {
#line 179
        slots.Remove(i);
    };
    
#line 126 "../../src/Com/Shared.fog"
    RefBase::RefBase()
    :
        obj(0)
    {
#line 126
        refs = 1;
    };
    
#line 127
    RefBase::~RefBase() {};
    
#line 181 "../../src/Com/Meta.fog"
    void RefBase::AddWeak(WeakBase *ptr)
    {
#line 181
        weaks.Add(ptr);
    };
    
#line 129 "../../src/Com/Shared.fog"
    void RefBase::Dec()
    {
#line 130
        refs -- ;
        if (refs <= 0)
        {
#line 132
            for (int i = 0; i < GetWeakCount(); i ++ )
                GetWeak(i).SetDeleted();
            delete this;
        }
    };
    
    void RefBase::DecWeak(WeakBase *w)
    {
#line 139
        for (int i = 0; i < GetWeakCount(); i ++ )
            if (&GetWeak(i) == w)
                RemoveWeak(i -- );
    };
    
#line 178 "../../src/Com/Meta.fog"
    WeakBase& RefBase::GetWeak(int i)
    {
#line 178
        return *(WeakBase * ) weaks[i];
    };
    
#line 180
    int RefBase::GetWeakCount()
    {
#line 180
        return weaks.GetCount();
    };
    
#line 128 "../../src/Com/Shared.fog"
    void RefBase::Inc()
    {
#line 128
        refs ++ ;
    };
    
#line 137
    void RefBase::IncWeak(WeakBase *w)
    {
#line 137
        AddWeak(w);
    };
    
#line 179 "../../src/Com/Meta.fog"
    void RefBase::RemoveWeak(int i)
    {
#line 179
        weaks.Remove(i);
    };
    
#line 11 "../../src/Com/Shared.fog"
    Slot::~Slot()
    {
#line 11
        Clear();
    };
    
#line 13
    bool Slot::CanAttach(Attachable& a)
    {
#line 13
        return true;
    };
    
#line 29
    void Slot::Clear()
    {
#line 30
        if (ptr)
        {
#line 31
            Attachable * a = ptr;
            ptr = 0;
            a -> DoDetach(this);
        }
    };
    
#line 17
    void Slot::Set(Attachable& a)
    {
#line 18
        Clear();
        bool b = CanAttach(a);
        {
#line 20
            if (!(b))
            {
#line 20
                Lang::SysBreak("Assertion failed: b");
            }
        }
#line 21
        ;
#line 21
        if (b)
#line 21
            a.DoAttach(this);
    };
    
#line 23
    void Slot::TestSet(Attachable& a)
    {
#line 24
        if (CanAttach(a))
        {
#line 25
            Clear();
            a.DoAttach(this);
        }
    };
    
};

#endif
