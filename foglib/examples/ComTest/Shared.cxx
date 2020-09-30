/*!$@FOG@$!
 *	Generated at Wed Sep 30 12:25:17 2020
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
 *		ComTest.mfog
 */

#ifndef SHARED_CXX
#define SHARED_CXX

#include <new>

#ifndef SHARED_HXX
#include <Shared.hxx>
#endif

namespace Shared
{
#line 76 "../../src/Com/Shared.fog"
    Attachable::~Attachable()
    {
#line 76
        DetachAll();
    };
    
#line 156 "../../src/Com/Meta.fog"
    void Attachable::AddSlot(Slot *ptr)
    {
#line 156
        slots.Add(ptr);
    };
    
#line 91 "../../src/Com/Shared.fog"
    void Attachable::Detach(Slot *ptr)
    {
#line 92
        DoDetach(ptr);
        ptr -> SetPtr(0);
    };
    
#line 79
    void Attachable::DetachAll()
    {
#line 80
        for (Iter it = slots.Begin(), end = slots.End(); it != end; ++ it)
            ((Slot * ) * it)-> SetPtr(0);
        slots.Clear();
    };
    
#line 58
    void Attachable::DoAttach(Slot *s)
    {
        {
#line 59
            if (!(s && s -> GetPtr() == 0 && !IsAttached(s)))
            {
#line 59
                Lang::SysBreak("Assertion failed: s && s->GetPtr() == 0 && !IsAttached(s)");
            }
        }
#line 60
        ;
#line 60
        AddSlot(s);
        s -> SetPtr(this);
    };
    
#line 63
    void Attachable::DoDetach(Slot *s)
    {
#line 64
        int i = 0;
        for (Iter it = slots.Begin(), end = slots.End(); it != end; ++ it)
            {
#line 66
                if ((Slot * ) * it == s)
                {
#line 67
                    slots.Remove(i);
                    break;
                
                }
#line 70
                i ++ ;
            }
    };
    
#line 153 "../../src/Com/Meta.fog"
    Slot& Attachable::GetSlot(int i)
    {
#line 153
        return *(Slot * ) slots[i];
    };
    
#line 155
    int Attachable::GetSlotCount()
    {
#line 155
        return slots.GetCount();
    };
    
#line 84 "../../src/Com/Shared.fog"
    bool Attachable::IsAttached(Slot *ptr)
    {
#line 85
        for (Iter it = slots.Begin(), end = slots.End(); it != end; ++ it)
            {
#line 86
                if ((Slot * ) * it == ptr)
                    return true;
            }
        return false;
    };
    
#line 154 "../../src/Com/Meta.fog"
    void Attachable::RemoveSlot(int i)
    {
#line 154
        slots.Remove(i);
    };
    
#line 132 "../../src/Com/Shared.fog"
    RefBase::RefBase()
    :
        obj(0)
    {
#line 132
        refs = 1;
    };
    
#line 133
    RefBase::~RefBase() {};
    
#line 156 "../../src/Com/Meta.fog"
    void RefBase::AddWeak(WeakBase *ptr)
    {
#line 156
        weaks.Add(ptr);
    };
    
#line 135 "../../src/Com/Shared.fog"
    void RefBase::Dec()
    {
#line 136
        refs -- ;
        if (refs <= 0)
        {
#line 138
            for (int i = 0; i < GetWeakCount(); i ++ )
                GetWeak(i).SetDeleted();
            delete this;
        }
    };
    
    void RefBase::DecWeak(WeakBase *w)
    {
#line 145
        for (int i = 0; i < GetWeakCount(); i ++ )
            if (&GetWeak(i) == w)
                RemoveWeak(i -- );
    };
    
#line 153 "../../src/Com/Meta.fog"
    WeakBase& RefBase::GetWeak(int i)
    {
#line 153
        return *(WeakBase * ) weaks[i];
    };
    
#line 155
    int RefBase::GetWeakCount()
    {
#line 155
        return weaks.GetCount();
    };
    
#line 134 "../../src/Com/Shared.fog"
    void RefBase::Inc()
    {
#line 134
        refs ++ ;
    };
    
#line 143
    void RefBase::IncWeak(WeakBase *w)
    {
#line 143
        AddWeak(w);
    };
    
#line 154 "../../src/Com/Meta.fog"
    void RefBase::RemoveWeak(int i)
    {
#line 154
        weaks.Remove(i);
    };
    
#line 17 "../../src/Com/Shared.fog"
    Slot::~Slot()
    {
#line 17
        Clear();
    };
    
#line 19
    bool Slot::CanAttach(Attachable& a)
    {
#line 19
        return true;
    };
    
#line 35
    void Slot::Clear()
    {
#line 36
        if (ptr)
        {
#line 37
            Attachable * a = ptr;
            ptr = 0;
            a -> DoDetach(this);
        }
    };
    
#line 23
    void Slot::Set(Attachable& a)
    {
#line 24
        Clear();
        bool b = CanAttach(a);
        {
#line 26
            if (!(b))
            {
#line 26
                Lang::SysBreak("Assertion failed: b");
            }
        }
#line 27
        ;
#line 27
        if (b)
#line 27
            a.DoAttach(this);
    };
    
#line 29
    void Slot::TestSet(Attachable& a)
    {
#line 30
        if (CanAttach(a))
        {
#line 31
            Clear();
            a.DoAttach(this);
        }
    };
    
};

#endif
