#ifndef SHARED_HXX
#define SHARED_HXX

#include <new>

#ifndef CONTAINER_HXX
#include <Container.hxx>
#endif

namespace Shared
{
};

namespace Shared {
template < class _1 > class Ptr;
}

namespace Shared
{
#line 215 "../../src/Com/Shared.fog"
    template < class _1 >
    inline Ptr < _1 > MakePtr();
#line 216
    template < class _1, class _2 >
    inline Ptr < _1 > MakePtr1(_2 a0);
#line 217
    template < class _1, class _2, class _3 >
    inline Ptr < _1 > MakePtr2(_2 a0, _3 a1);
#line 218
    template < class _1, class _2, class _3, class _4 >
    inline Ptr < _1 > MakePtr3(_2 a0, _3 a1, _4 a2);
#line 219
    template < class _1, class _2, class _3, class _4, class _5 >
    inline Ptr < _1 > MakePtr4(_2 a0, _3 a1, _4 a2, _5 a3);
#line 220
    template < class _1, class _2, class _3, class _4, class _5, class _6 >
    inline Ptr < _1 > MakePtr5(_2 a0, _3 a1, _4 a2, _5 a3, _6 a4);
#line 221
    template < class _1, class _2, class _3, class _4, class _5, class _6, class _7 >
    inline Ptr < _1 > MakePtr6(_2 a0, _3 a1, _4 a2, _5 a3, _6 a4, _7 a5);
#line 222
    template < class _1, class _2, class _3, class _4, class _5, class _6, class _7, class _8 >
    inline Ptr < _1 > MakePtr7(_2 a0, _3 a1, _4 a2, _5 a3, _6 a4, _7 a5, _8 a6);
#line 265
    template < class _1, class _2 >
    inline Ptr < _1 > StaticPointerCast(_2 it);
};

namespace Shared {
class Slot;
}

namespace Shared
{
    class Attachable
    {
#line 50
        typedef Lang::FwdIterator < void * > Iter;
        
#line 48
        Lang::DynArray < void * > slots;
        
    public:
#line 70
        virtual ~Attachable();
#line 72
        inline void Attach(Slot& s);
#line 85
        void Detach(Slot *ptr);
#line 73
        void DetachAll();
#line 90
        inline Slot& Get(int i) const;
#line 89
        inline int GetCount() const;
#line 78
        bool IsAttached(Slot *ptr);
        
#line 159 "../../src/Com/Meta.fog"
        void AddSlot(Slot *ptr);
#line 52 "../../src/Com/Shared.fog"
        void DoAttach(Slot *s);
#line 57
        void DoDetach(Slot *s);
#line 156 "../../src/Com/Meta.fog"
        Slot& GetSlot(int i);
#line 158
        int GetSlotCount();
#line 157
        void RemoveSlot(int i);
    };
};

namespace Shared {
template < class _1 > class EnablePtrFromThis;
}
namespace Shared {
class RefBase;
}

namespace Shared
{
    template < class _1 >
    class Ptr
    {
    protected:
#line 157 "../../src/Com/Shared.fog"
        RefBase *r;
        _1 *o;
        
    public:
        inline Ptr();
        inline Ptr(const Ptr& o);
#line 165
        inline ~Ptr();
#line 176
        inline _1& operator*() const;
#line 172
        inline _1 *operator-> ();
        inline _1 *operator-> () const;
#line 170
        inline void operator= (const Ptr < _1 > & s);
#line 178
        inline bool operator== (const Ptr& s) const;
#line 177
        inline bool operator== (const _1 *ptr) const;
#line 175
        inline operator bool() const;
#line 179
        template < class _2 >
        inline Ptr < _2 > As();
#line 169
        inline void Clear();
#line 167
        inline void Create();
        template < class _2 >
        inline void CreateAbstract();
#line 174
        inline _1 *Get() const;
#line 207
        inline const RefBase *GetBase() const;
#line 171
        inline bool IsEmpty() const;
#line 192
        inline void SetPtr(_1 *o, RefBase *r);
#line 198
        inline Ptr < _1 > & WrapObject(_1 *obj);
    };
};

namespace Shared {
struct WeakBase;
}

namespace Shared
{
    class RefBase
    {
    public:
#line 110
        void *obj;
#line 122
        Lang::DynArray < void * > weaks;
        Lang::AtomicInt refs;
        
    public:
        RefBase();
        virtual ~RefBase();
#line 159 "../../src/Com/Meta.fog"
        void AddWeak(WeakBase *ptr);
#line 129 "../../src/Com/Shared.fog"
        void Dec();
#line 138
        void DecWeak(WeakBase *w);
#line 156 "../../src/Com/Meta.fog"
        WeakBase& GetWeak(int i);
#line 158
        int GetWeakCount();
#line 128 "../../src/Com/Shared.fog"
        void Inc();
#line 137
        void IncWeak(WeakBase *w);
#line 157 "../../src/Com/Meta.fog"
        void RemoveWeak(int i);
    };
    
    template < class _1 >
    struct RefTemplate : public Shared::RefBase
    {
#line 149 "../../src/Com/Shared.fog"
        inline ~RefTemplate();
    };
    
    class Slot
    {
#line 7
        Attachable *ptr;
        
    public:
        inline Slot();
        virtual ~Slot();
#line 42
        inline Attachable& operator*() const;
#line 37
        inline Attachable *operator-> () const;
        inline operator bool() const;
#line 13
        virtual bool CanAttach(Attachable& a);
#line 29
        void Clear();
#line 39
        inline Attachable& Get() const;
        inline Attachable *GetPtr() const;
#line 16
        inline bool IsEmpty() const;
        void Set(Attachable& a);
#line 15
        inline void SetPtr(Attachable *p);
#line 23
        void TestSet(Attachable& a);
    };
    
    struct WeakBase
    {
#line 100
        /*pure*/virtual void SetDeleted() = 0;
    };
    
    template < class _1 >
    class Weak : public Shared::WeakBase
    {
#line 228
        struct RefBase *r;
        _1 *o;
        
    public:
        inline Weak();
#line 234
        inline Weak(const Ptr < _1 > & s);
#line 233
        inline Weak(const Weak& w);
#line 235
        inline ~Weak();
#line 243
        inline _1 *operator-> ();
#line 239
        inline void operator= (const Ptr < _1 > & s);
#line 241
        inline void operator= (const Weak < _1 > & p);
#line 245
        inline operator bool();
#line 238
        inline void Clear();
#line 246
        inline Ptr < _1 > Enter() const;
#line 244
        inline _1 *Get();
#line 242
        inline bool IsEmpty() const;
#line 237
        inline virtual void SetDeleted();
    };
    
    template < class _1 >
    class EnablePtrFromThis
    {
#line 252
        Weak < _1 > weak;
        
    public:
        inline virtual ~EnablePtrFromThis();
#line 261
        template < class _2 >
        inline Ptr < _2 > AsPtr();
#line 259
        inline bool HasWeak() const;
#line 257
        inline void InitWeak(const Ptr < _1 > & s);
    };
    
    struct WeakBasePtr : public Prim::CPtr < WeakBase >
    {
    };
};

namespace Shared
{
#line 215
    template < class _1 >
    inline Ptr < _1 > MakePtr()
    {
#line 215
        return Ptr < _1 > (new _1);
    };
    
#line 216
    template < class _1, class _2 >
    inline Ptr < _1 > MakePtr1(_2 a0)
    {
#line 216
        return Ptr < _1 > (new _1(a0));
    };
    
#line 217
    template < class _1, class _2, class _3 >
    inline Ptr < _1 > MakePtr2(_2 a0, _3 a1)
    {
#line 217
        return Ptr < _1 > (new _1(a0, a1));
    };
    
#line 218
    template < class _1, class _2, class _3, class _4 >
    inline Ptr < _1 > MakePtr3(_2 a0, _3 a1, _4 a2)
    {
#line 218
        return Ptr < _1 > (new _1(a0, a1, a2));
    };
    
#line 219
    template < class _1, class _2, class _3, class _4, class _5 >
    inline Ptr < _1 > MakePtr4(_2 a0, _3 a1, _4 a2, _5 a3)
    {
#line 219
        return Ptr < _1 > (new _1(a0, a1, a2, a3));
    };
    
#line 220
    template < class _1, class _2, class _3, class _4, class _5, class _6 >
    inline Ptr < _1 > MakePtr5(_2 a0, _3 a1, _4 a2, _5 a3, _6 a4)
    {
#line 220
        return Ptr < _1 > (new _1(a0, a1, a2, a3, a4));
    };
    
#line 221
    template < class _1, class _2, class _3, class _4, class _5, class _6, class _7 >
    inline Ptr < _1 > MakePtr6(_2 a0, _3 a1, _4 a2, _5 a3, _6 a4, _7 a5)
    {
#line 221
        return Ptr < _1 > (new _1(a0, a1, a2, a3, a4, a5));
    };
    
#line 222
    template < class _1, class _2, class _3, class _4, class _5, class _6, class _7, class _8 >
    inline Ptr < _1 > MakePtr7(_2 a0, _3 a1, _4 a2, _5 a3, _6 a4, _7 a5, _8 a6)
    {
#line 222
        return Ptr < _1 > (new _1(a0, a1, a2, a3, a4, a5, a6));
    };
    
#line 265
    template < class _1, class _2 >
    inline Ptr < _1 > StaticPointerCast(_2 it) {};
    
#line 72
    inline void Attachable::Attach(Slot& s)
    {
#line 72
        s.Set(*this);
    };
    
#line 90
    inline Slot& Attachable::Get(int i) const
    {
#line 90
        return *(Slot * ) slots[i];
    };
    
#line 89
    inline int Attachable::GetCount() const
    {
#line 89
        return slots.GetCount();
    };
    
#line 255
    template < class _1 >
    inline EnablePtrFromThis < _1 >::~EnablePtrFromThis() {};
    
#line 261
    template < class _1 >
    template < class _2 >
    inline Ptr < _2 > EnablePtrFromThis < _1 >::AsPtr()
    {
        {
#line 262
            if (!(!weak.IsEmpty()))
            {
#line 262
                Lang::SysBreak("Assertion failed: !weak.IsEmpty()");
            }
        }
#line 262
        ;
#line 262
        return weak.Enter();
    };
    
#line 259
    template < class _1 >
    inline bool EnablePtrFromThis < _1 >::HasWeak() const
    {
#line 259
        return !weak.IsEmpty();
    };
    
#line 257
    template < class _1 >
    inline void EnablePtrFromThis < _1 >::InitWeak(const Ptr < _1 > & s)
    {
        {
#line 257
            if (!(weak.IsEmpty()))
            {
#line 257
                Lang::SysBreak("Assertion failed: weak.IsEmpty()");
            }
        }
#line 257
        ;
#line 257
        weak = s;
    };
    
#line 161
    template < class _1 >
    inline Ptr < _1 >::Ptr()
    :
        r(0),
        o(0)
    {};
    
#line 162
    template < class _1 >
    inline Ptr < _1 >::Ptr(const Ptr& o)
    :
        r(0),
        o(0)
    {
#line 162
        *this = o;
    };
    
    template < class _1 >
    inline Ptr < _1 >::~Ptr()
    {
#line 165
        Clear();
    };
    
#line 176
    template < class _1 >
    inline _1& Ptr < _1 >::operator*() const
    {
#line 176
        return *Get();
    };
    
#line 172
    template < class _1 >
    inline _1 *Ptr < _1 >::operator-> ()
    {
#line 172
        if (r)
#line 172
            return o;
#line 172
        return 0;
    };
    
#line 173
    template < class _1 >
    inline _1 *Ptr < _1 >::operator-> () const
    {
#line 173
        if (r)
#line 173
            return o;
#line 173
        return 0;
    };
    
#line 170
    template < class _1 >
    inline void Ptr < _1 >::operator= (const Ptr < _1 > & s)
    {
#line 170
        if (r == s.r)
#line 170
            return;
#line 170
        SetPtr(s.o, s.r);
    };
    
#line 178
    template < class _1 >
    inline bool Ptr < _1 >::operator== (const Ptr& s) const
    {
#line 178
        if (r && s.r)
#line 178
            return o == s.o;
#line 178
        return false;
    };
    
#line 177
    template < class _1 >
    inline bool Ptr < _1 >::operator== (const _1 *ptr) const
    {
#line 177
        if (r)
#line 177
            return o == ptr;
#line 177
        return false;
    };
    
#line 175
    template < class _1 >
    inline Ptr < _1 >::operator bool() const
    {
#line 175
        return !IsEmpty();
    };
    
#line 179
    template < class _1 >
    template < class _2 >
    inline Ptr < _2 > Ptr < _1 >::As()
    {
#line 180
        static_assert(std::is_base_of < _1, _2 > () || std::is_base_of < _2, _1 > (), "K -> T or T -> K inheritance is required");
#line 182
        if (o)
        {
#line 183
            _2 * ptr = dynamic_cast< _2 * >(o);
            if (ptr)
            {
#line 185
                Ptr < _2 > s;
                s.SetPtr(ptr, r);
                return s;
            }
        }
        return Ptr < _2 > ();
    };
    
#line 169
    template < class _1 >
    inline void Ptr < _1 >::Clear()
    {
#line 169
        if (r)
        {
#line 169
            r -> Dec();
#line 169
            r = 0;
#line 169
            o = 0;
        }
    };
    
#line 167
    template < class _1 >
    inline void Ptr < _1 >::Create()
    {
#line 167
        Clear();
#line 167
        r = new RefTemplate < _1 > ;
#line 167
        o = new _1;
#line 167
        r -> obj = o;
    };
    
#line 168
    template < class _1 >
    template < class _2 >
    inline void Ptr < _1 >::CreateAbstract()
    {
#line 168
        Clear();
#line 168
        r = new RefTemplate < _1 > ;
#line 168
        o = new _2;
#line 168
        r -> obj = o;
    };
    
#line 174
    template < class _1 >
    inline _1 *Ptr < _1 >::Get() const
    {
#line 174
        if (r)
#line 174
            return o;
#line 174
        return 0;
    };
    
#line 207
    template < class _1 >
    inline const RefBase *Ptr < _1 >::GetBase() const
    {
#line 207
        return r;
    };
    
#line 171
    template < class _1 >
    inline bool Ptr < _1 >::IsEmpty() const
    {
#line 171
        return r == 0;
    };
    
#line 192
    template < class _1 >
    inline void Ptr < _1 >::SetPtr(_1 *o, RefBase *r)
    {
#line 193
        Ptr < _1 > tmp;
#line 193
        Container::Swap(*this, tmp);
        this -> o = o;
        this -> r = r;
        if (r)
#line 196
            r -> Inc();
    };
    
#line 198
    template < class _1 >
    inline Ptr < _1 > & Ptr < _1 >::WrapObject(_1 *obj)
    {
#line 199
        Clear();
        if (obj)
        {
#line 201
            r = new RefTemplate < _1 > ;
            r -> obj = obj;
            o = obj;
        }
        return *this;
    };
    
#line 149
    template < class _1 >
    inline RefTemplate < _1 >::~RefTemplate()
    {
#line 149
        if (obj)
#line 149
            delete ((_1 * ) obj);
#line 149
        obj = 0;
    };
    
#line 10
    inline Slot::Slot()
    :
        ptr(0)
    {};
    
#line 42
    inline Attachable& Slot::operator*() const
    {
#line 42
        return *ptr;
    };
    
#line 37
    inline Attachable *Slot::operator-> () const
    {
#line 37
        return ptr;
    };
    
#line 38
    inline Slot::operator bool() const
    {
#line 38
        return ptr != 0;
    };
    
#line 39
    inline Attachable& Slot::Get() const
    {
#line 39
        return *ptr;
    };
    
#line 40
    inline Attachable *Slot::GetPtr() const
    {
#line 40
        return ptr;
    };
    
#line 16
    inline bool Slot::IsEmpty() const
    {
#line 16
        return ptr == 0;
    };
    
#line 15
    inline void Slot::SetPtr(Attachable *p)
    {
#line 15
        ptr = p;
    };
    
#line 232
    template < class _1 >
    inline Weak < _1 >::Weak()
    :
        r(0),
        o(0)
    {};
    
#line 234
    template < class _1 >
    inline Weak < _1 >::Weak(const Ptr < _1 > & s)
    :
        r(s.r),
        o(s.o)
    {
#line 234
        if (r)
#line 234
            r -> IncWeak(this);
    };
    
#line 233
    template < class _1 >
    inline Weak < _1 >::Weak(const Weak& w)
    :
        r(w.r),
        o(w.o)
    {
#line 233
        if (r)
#line 233
            r -> IncWeak(this);
    };
    
#line 235
    template < class _1 >
    inline Weak < _1 >::~Weak()
    {
#line 235
        Clear();
    };
    
#line 243
    template < class _1 >
    inline _1 *Weak < _1 >::operator-> ()
    {
#line 243
        return o;
    };
    
#line 239
    template < class _1 >
    inline void Weak < _1 >::operator= (const Ptr < _1 > & s)
    {
#line 239
        Clear();
#line 239
        r = s.r;
#line 239
        o = s.o;
#line 239
        if (r)
#line 239
            r -> IncWeak(this);
    };
    
#line 241
    template < class _1 >
    inline void Weak < _1 >::operator= (const Weak < _1 > & p)
    {
#line 241
        Clear();
#line 241
        r = p.r;
#line 241
        o = p.o;
#line 241
        if (r)
#line 241
            r -> IncWeak(this);
    };
    
#line 245
    template < class _1 >
    inline Weak < _1 >::operator bool()
    {
#line 245
        return !IsEmpty();
    };
    
#line 238
    template < class _1 >
    inline void Weak < _1 >::Clear()
    {
#line 238
        if (r)
#line 238
            r -> DecWeak(this);
#line 238
        r = 0;
#line 238
        o = 0;
    };
    
#line 246
    template < class _1 >
    inline Ptr < _1 > Weak < _1 >::Enter() const
    {
#line 246
        Ptr < _1 > s;
#line 246
        s.r = r;
#line 246
        s.o = o;
#line 246
        if (s.r)
#line 246
            s.r -> Inc();
#line 246
        return s;
    };
    
#line 244
    template < class _1 >
    inline _1 *Weak < _1 >::Get()
    {
#line 244
        return o;
    };
    
#line 242
    template < class _1 >
    inline bool Weak < _1 >::IsEmpty() const
    {
#line 242
        return r == 0;
    };
    
#line 237
    template < class _1 >
    inline void Weak < _1 >::SetDeleted()
    {
#line 237
        r = 0;
    };
    
};

#endif
