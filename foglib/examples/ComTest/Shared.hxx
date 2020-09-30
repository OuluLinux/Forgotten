/*!$@FOG@$!
 *	Generated at Wed Sep 30 06:41:10 2020
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
 *		../../src/Com/Text.fog
 *		ComTest.mfog
 */

#ifndef SHARED_HXX
#define SHARED_HXX

#include <new>

#ifndef COM_HXX
#include <Com.hxx>
#endif
#ifndef NATIVE_HXX
#include <Native.hxx>
#endif
#ifndef PRIM_HXX
#include <Prim.hxx>
#endif

namespace Lang
{
#line 9 "../../src/Com/Lang.fog"
    typedef Prim::CPtr < const char > CString;
#line 9
    typedef Prim::CPtr < const void > ConstVoidPtr;
#line 9
    typedef Prim::CPtr < void > VoidPtr;
#line 142 "../../src/Com/Meta.fog"
    typedef unsigned char byte;
#line 142
    typedef short int16;
#line 142
    typedef int int32;
#line 142
    typedef long long int64;
#line 142
    typedef char int8;
#line 142
    typedef unsigned short uint16;
#line 142
    typedef unsigned int uint32;
#line 142
    typedef uint32 dword;
#line 142
    typedef unsigned long long uint64;
#line 142
    typedef uint64 qword;
#line 142
    typedef unsigned char uint8;
#line 142
    typedef uint16 word;
};

namespace Shared
{
};

namespace Shared {
template < class _1 > class Ptr;
}

namespace Shared
{
#line 221 "../../src/Com/Shared.fog"
    template < class _1 >
    inline Ptr < _1 > MakePtr();
#line 225
    template < class _1, class _2 >
    inline Ptr < _1 > MakePtr1(_2 a0);
#line 226
    template < class _1, class _2, class _3 >
    inline Ptr < _1 > MakePtr2(_2 a0, _3 a1);
#line 227
    template < class _1, class _2, class _3, class _4 >
    inline Ptr < _1 > MakePtr3(_2 a0, _3 a1, _4 a2);
#line 228
    template < class _1, class _2, class _3, class _4, class _5 >
    inline Ptr < _1 > MakePtr4(_2 a0, _3 a1, _4 a2, _5 a3);
#line 229
    template < class _1, class _2, class _3, class _4, class _5, class _6 >
    inline Ptr < _1 > MakePtr5(_2 a0, _3 a1, _4 a2, _5 a3, _6 a4);
#line 230
    template < class _1, class _2, class _3, class _4, class _5, class _6, class _7 >
    inline Ptr < _1 > MakePtr6(_2 a0, _3 a1, _4 a2, _5 a3, _6 a4, _7 a5);
#line 231
    template < class _1, class _2, class _3, class _4, class _5, class _6, class _7, class _8 >
    inline Ptr < _1 > MakePtr7(_2 a0, _3 a1, _4 a2, _5 a3, _6 a4, _7 a5, _8 a6);
#line 274
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
#line 56
        typedef Lang::FwdIterator < void * > Iter;
        
#line 54
        Lang::DynArray < void * > slots;
        
    public:
#line 76
        virtual ~Attachable();
#line 78
        inline void Attach(Slot& s);
#line 91
        void Detach(Slot *ptr);
#line 79
        void DetachAll();
#line 96
        inline Slot& Get(int i) const;
#line 95
        inline int GetCount() const;
#line 84
        bool IsAttached(Slot *ptr);
        
#line 156 "../../src/Com/Meta.fog"
        void AddSlot(Slot *ptr);
#line 58 "../../src/Com/Shared.fog"
        void DoAttach(Slot *s);
#line 63
        void DoDetach(Slot *s);
#line 153 "../../src/Com/Meta.fog"
        Slot& GetSlot(int i);
#line 155
        int GetSlotCount();
#line 154
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
#line 163 "../../src/Com/Shared.fog"
        RefBase *r;
        _1 *o;
        
    public:
        inline Ptr();
        inline Ptr(const Ptr& o);
#line 171
        inline ~Ptr();
#line 182
        inline _1& operator*() const;
#line 178
        inline _1 *operator-> ();
        inline _1 *operator-> () const;
#line 176
        inline void operator= (const Ptr < _1 > & s);
#line 184
        inline bool operator== (const Ptr& s) const;
#line 183
        inline bool operator== (const _1 *ptr) const;
#line 181
        inline operator bool() const;
#line 185
        template < class _2 >
        inline Ptr < _2 > As();
#line 175
        inline void Clear();
#line 173
        inline void Create();
        template < class _2 >
        inline void CreateAbstract();
#line 180
        inline _1 *Get() const;
#line 213
        inline const RefBase *GetBase() const;
#line 177
        inline bool IsEmpty() const;
#line 198
        inline void SetPtr(_1 *o, RefBase *r);
#line 204
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
#line 116
        void *obj;
#line 128
        Lang::DynArray < void * > weaks;
        Lang::AtomicInt refs;
        
    public:
        RefBase();
        virtual ~RefBase();
#line 156 "../../src/Com/Meta.fog"
        void AddWeak(WeakBase *ptr);
#line 135 "../../src/Com/Shared.fog"
        void Dec();
#line 144
        void DecWeak(WeakBase *w);
#line 153 "../../src/Com/Meta.fog"
        WeakBase& GetWeak(int i);
#line 155
        int GetWeakCount();
#line 134 "../../src/Com/Shared.fog"
        void Inc();
#line 143
        void IncWeak(WeakBase *w);
#line 154 "../../src/Com/Meta.fog"
        void RemoveWeak(int i);
    };
    
    template < class _1 >
    struct RefTemplate : public Shared::RefBase
    {
#line 155 "../../src/Com/Shared.fog"
        ~RefTemplate();
    };
    
    class Slot
    {
#line 13
        Attachable *ptr;
        
    public:
        inline Slot();
        virtual ~Slot();
#line 48
        inline Attachable& operator*() const;
#line 43
        inline Attachable *operator-> () const;
        inline operator bool() const;
#line 19
        virtual bool CanAttach(Attachable& a);
#line 35
        void Clear();
#line 45
        inline Attachable& Get() const;
        inline Attachable *GetPtr() const;
#line 22
        inline bool IsEmpty() const;
        void Set(Attachable& a);
#line 21
        inline void SetPtr(Attachable *p);
#line 29
        void TestSet(Attachable& a);
    };
    
    struct WeakBase
    {
#line 106
        /*pure*/virtual void SetDeleted() = 0;
    };
    
    template < class _1 >
    class Weak : public Shared::WeakBase
    {
#line 237
        struct RefBase *r;
        _1 *o;
        
    public:
        inline Weak();
#line 243
        inline Weak(const Ptr < _1 > & s);
#line 242
        inline Weak(const Weak& w);
#line 244
        inline ~Weak();
#line 252
        inline _1 *operator-> ();
#line 248
        inline void operator= (const Ptr < _1 > & s);
#line 250
        inline void operator= (const Weak < _1 > & p);
#line 254
        inline operator bool();
#line 247
        inline void Clear();
#line 255
        inline Ptr < _1 > Enter() const;
#line 253
        inline _1 *Get();
#line 251
        inline bool IsEmpty() const;
#line 246
        inline virtual void SetDeleted();
    };
    
    template < class _1 >
    class EnablePtrFromThis
    {
#line 261
        Weak < _1 > weak;
        
    public:
        inline virtual ~EnablePtrFromThis();
#line 270
        template < class _2 >
        inline Ptr < _2 > AsPtr();
#line 268
        inline bool HasWeak() const;
#line 266
        inline void InitWeak(const Ptr < _1 > & s);
    };
    
    struct WeakBasePtr : public Prim::CPtr < WeakBase >
    {
    };
};

namespace Shared
{
#line 221
    template < class _1 >
    inline Ptr < _1 > MakePtr()
    {
#line 221
        return Ptr < _1 > (new _1);
    };
    
#line 225
    template < class _1, class _2 >
    inline Ptr < _1 > MakePtr1(_2 a0)
    {
#line 225
        return Ptr < _1 > (new _1(a0));
    };
    
#line 226
    template < class _1, class _2, class _3 >
    inline Ptr < _1 > MakePtr2(_2 a0, _3 a1)
    {
#line 226
        return Ptr < _1 > (new _1(a0, a1));
    };
    
#line 227
    template < class _1, class _2, class _3, class _4 >
    inline Ptr < _1 > MakePtr3(_2 a0, _3 a1, _4 a2)
    {
#line 227
        return Ptr < _1 > (new _1(a0, a1, a2));
    };
    
#line 228
    template < class _1, class _2, class _3, class _4, class _5 >
    inline Ptr < _1 > MakePtr4(_2 a0, _3 a1, _4 a2, _5 a3)
    {
#line 228
        return Ptr < _1 > (new _1(a0, a1, a2, a3));
    };
    
#line 229
    template < class _1, class _2, class _3, class _4, class _5, class _6 >
    inline Ptr < _1 > MakePtr5(_2 a0, _3 a1, _4 a2, _5 a3, _6 a4)
    {
#line 229
        return Ptr < _1 > (new _1(a0, a1, a2, a3, a4));
    };
    
#line 230
    template < class _1, class _2, class _3, class _4, class _5, class _6, class _7 >
    inline Ptr < _1 > MakePtr6(_2 a0, _3 a1, _4 a2, _5 a3, _6 a4, _7 a5)
    {
#line 230
        return Ptr < _1 > (new _1(a0, a1, a2, a3, a4, a5));
    };
    
#line 231
    template < class _1, class _2, class _3, class _4, class _5, class _6, class _7, class _8 >
    inline Ptr < _1 > MakePtr7(_2 a0, _3 a1, _4 a2, _5 a3, _6 a4, _7 a5, _8 a6)
    {
#line 231
        return Ptr < _1 > (new _1(a0, a1, a2, a3, a4, a5, a6));
    };
    
#line 274
    template < class _1, class _2 >
    inline Ptr < _1 > StaticPointerCast(_2 it) {};
    
#line 78
    inline void Attachable::Attach(Slot& s)
    {
#line 78
        s.Set(*this);
    };
    
#line 96
    inline Slot& Attachable::Get(int i) const
    {
#line 96
        return *(Slot * ) slots[i];
    };
    
#line 95
    inline int Attachable::GetCount() const
    {
#line 95
        return slots.GetCount();
    };
    
#line 264
    template < class _1 >
    inline EnablePtrFromThis < _1 >::~EnablePtrFromThis() {};
    
#line 270
    template < class _1 >
    template < class _2 >
    inline Ptr < _2 > EnablePtrFromThis < _1 >::AsPtr()
    {
        {
#line 271
            if (!(!weak.IsEmpty()))
            {
#line 271
                Lang::SysBreak("Assertion failed: !weak.IsEmpty()");
            }
        }
#line 271
        ;
#line 271
        return weak.Enter();
    };
    
#line 268
    template < class _1 >
    inline bool EnablePtrFromThis < _1 >::HasWeak() const
    {
#line 268
        return !weak.IsEmpty();
    };
    
#line 266
    template < class _1 >
    inline void EnablePtrFromThis < _1 >::InitWeak(const Ptr < _1 > & s)
    {
        {
#line 266
            if (!(weak.IsEmpty()))
            {
#line 266
                Lang::SysBreak("Assertion failed: weak.IsEmpty()");
            }
        }
#line 266
        ;
#line 266
        weak = s;
    };
    
#line 167
    template < class _1 >
    inline Ptr < _1 >::Ptr()
    :
        r(0),
        o(0)
    {};
    
#line 168
    template < class _1 >
    inline Ptr < _1 >::Ptr(const Ptr& o)
    :
        r(0),
        o(0)
    {
#line 168
        *this = o;
    };
    
    template < class _1 >
    inline Ptr < _1 >::~Ptr()
    {
#line 171
        Clear();
    };
    
#line 182
    template < class _1 >
    inline _1& Ptr < _1 >::operator*() const
    {
#line 182
        return *Get();
    };
    
#line 178
    template < class _1 >
    inline _1 *Ptr < _1 >::operator-> ()
    {
#line 178
        if (r)
#line 178
            return o;
#line 178
        return 0;
    };
    
#line 179
    template < class _1 >
    inline _1 *Ptr < _1 >::operator-> () const
    {
#line 179
        if (r)
#line 179
            return o;
#line 179
        return 0;
    };
    
#line 176
    template < class _1 >
    inline void Ptr < _1 >::operator= (const Ptr < _1 > & s)
    {
#line 176
        if (r == s.r)
#line 176
            return;
#line 176
        SetPtr(s.o, s.r);
    };
    
#line 184
    template < class _1 >
    inline bool Ptr < _1 >::operator== (const Ptr& s) const
    {
#line 184
        if (r && s.r)
#line 184
            return o == s.o;
#line 184
        return false;
    };
    
#line 183
    template < class _1 >
    inline bool Ptr < _1 >::operator== (const _1 *ptr) const
    {
#line 183
        if (r)
#line 183
            return o == ptr;
#line 183
        return false;
    };
    
#line 181
    template < class _1 >
    inline Ptr < _1 >::operator bool() const
    {
#line 181
        return !IsEmpty();
    };
    
#line 185
    template < class _1 >
    template < class _2 >
    inline Ptr < _2 > Ptr < _1 >::As()
    {
#line 186
        static_assert(std::is_base_of < _1, _2 > () || std::is_base_of < _2, _1 > (), "K -> T or T -> K inheritance is required");
#line 188
        if (o)
        {
#line 189
            _2 * ptr = dynamic_cast< _2 * >(o);
            if (ptr)
            {
#line 191
                Ptr < _2 > s;
                s.SetPtr(ptr, r);
                return s;
            }
        }
        return Ptr < _2 > ();
    };
    
#line 175
    template < class _1 >
    inline void Ptr < _1 >::Clear()
    {
#line 175
        if (r)
        {
#line 175
            r -> Dec();
#line 175
            r = 0;
#line 175
            o = 0;
        }
    };
    
#line 173
    template < class _1 >
    inline void Ptr < _1 >::Create()
    {
#line 173
        Clear();
#line 173
        r = new RefTemplate < _1 > ;
#line 173
        o = new _1;
#line 173
        r -> obj = o;
    };
    
#line 174
    template < class _1 >
    template < class _2 >
    inline void Ptr < _1 >::CreateAbstract()
    {
#line 174
        Clear();
#line 174
        r = new RefTemplate < _1 > ;
#line 174
        o = new _2;
#line 174
        r -> obj = o;
    };
    
#line 180
    template < class _1 >
    inline _1 *Ptr < _1 >::Get() const
    {
#line 180
        if (r)
#line 180
            return o;
#line 180
        return 0;
    };
    
#line 213
    template < class _1 >
    inline const RefBase *Ptr < _1 >::GetBase() const
    {
#line 213
        return r;
    };
    
#line 177
    template < class _1 >
    inline bool Ptr < _1 >::IsEmpty() const
    {
#line 177
        return r == 0;
    };
    
#line 198
    template < class _1 >
    inline void Ptr < _1 >::SetPtr(_1 *o, RefBase *r)
    {
#line 199
        Ptr < _1 > tmp;
#line 199
        Container::Swap(*this, tmp);
        this -> o = o;
        this -> r = r;
        if (r)
#line 202
            r -> Inc();
    };
    
#line 204
    template < class _1 >
    inline Ptr < _1 > & Ptr < _1 >::WrapObject(_1 *obj)
    {
#line 205
        Clear();
        if (obj)
        {
#line 207
            r = new RefTemplate < _1 > ;
            r -> obj = obj;
            o = obj;
        }
        return *this;
    };
    
#line 16
    inline Slot::Slot()
    :
        ptr(0)
    {};
    
#line 48
    inline Attachable& Slot::operator*() const
    {
#line 48
        return *ptr;
    };
    
#line 43
    inline Attachable *Slot::operator-> () const
    {
#line 43
        return ptr;
    };
    
#line 44
    inline Slot::operator bool() const
    {
#line 44
        return ptr != 0;
    };
    
#line 45
    inline Attachable& Slot::Get() const
    {
#line 45
        return *ptr;
    };
    
#line 46
    inline Attachable *Slot::GetPtr() const
    {
#line 46
        return ptr;
    };
    
#line 22
    inline bool Slot::IsEmpty() const
    {
#line 22
        return ptr == 0;
    };
    
#line 21
    inline void Slot::SetPtr(Attachable *p)
    {
#line 21
        ptr = p;
    };
    
#line 241
    template < class _1 >
    inline Weak < _1 >::Weak()
    :
        r(0),
        o(0)
    {};
    
#line 243
    template < class _1 >
    inline Weak < _1 >::Weak(const Ptr < _1 > & s)
    :
        r(s.r),
        o(s.o)
    {
#line 243
        if (r)
#line 243
            r -> IncWeak(this);
    };
    
#line 242
    template < class _1 >
    inline Weak < _1 >::Weak(const Weak& w)
    :
        r(w.r),
        o(w.o)
    {
#line 242
        if (r)
#line 242
            r -> IncWeak(this);
    };
    
#line 244
    template < class _1 >
    inline Weak < _1 >::~Weak()
    {
#line 244
        Clear();
    };
    
#line 252
    template < class _1 >
    inline _1 *Weak < _1 >::operator-> ()
    {
#line 252
        return o;
    };
    
#line 248
    template < class _1 >
    inline void Weak < _1 >::operator= (const Ptr < _1 > & s)
    {
#line 248
        Clear();
#line 248
        r = s.r;
#line 248
        o = s.o;
#line 248
        if (r)
#line 248
            r -> IncWeak(this);
    };
    
#line 250
    template < class _1 >
    inline void Weak < _1 >::operator= (const Weak < _1 > & p)
    {
#line 250
        Clear();
#line 250
        r = p.r;
#line 250
        o = p.o;
#line 250
        if (r)
#line 250
            r -> IncWeak(this);
    };
    
#line 254
    template < class _1 >
    inline Weak < _1 >::operator bool()
    {
#line 254
        return !IsEmpty();
    };
    
#line 247
    template < class _1 >
    inline void Weak < _1 >::Clear()
    {
#line 247
        if (r)
#line 247
            r -> DecWeak(this);
#line 247
        r = 0;
#line 247
        o = 0;
    };
    
#line 255
    template < class _1 >
    inline Ptr < _1 > Weak < _1 >::Enter() const
    {
#line 255
        Ptr < _1 > s;
#line 255
        s.r = r;
#line 255
        s.o = o;
#line 255
        if (s.r)
#line 255
            s.r -> Inc();
#line 255
        return s;
    };
    
#line 253
    template < class _1 >
    inline _1 *Weak < _1 >::Get()
    {
#line 253
        return o;
    };
    
#line 251
    template < class _1 >
    inline bool Weak < _1 >::IsEmpty() const
    {
#line 251
        return r == 0;
    };
    
#line 246
    template < class _1 >
    inline void Weak < _1 >::SetDeleted()
    {
#line 246
        r = 0;
    };
    
};

#endif
