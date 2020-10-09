#ifndef INDIRECT_HXX
#define INDIRECT_HXX

#include <new>

#ifndef CONTAINER_HXX
#include <Container.hxx>
#endif

#ifndef MATH_HXX
#include <Math.hxx>
#endif

namespace Indirect
{
};

namespace Indirect {
class Callback;
}

namespace Indirect
{
#line 410 "../../src/Com/Indirect.fog"
    inline void AddExitBlock(Callback cb);
#line 409
    inline void AddInitBlock(Callback cb);
#line 394
    inline Callback Proxy(Callback cb);
};

namespace Indirect {
template < class _1 > class Callback1;
}

namespace Indirect
{
#line 398
    template < class _1 >
    inline Callback1 < _1 > Proxy_1(Callback1 < _1 > cb);
#line 417
    void RunExitBlocks();
#line 411
    void RunInitBlocks();
#line 407
    inline Container::Vector < Callback > & __ExitBlocks();
#line 406
    inline Container::Vector < Callback > & __InitBlocks();
    
    class CallBaseObject
    {
#line 8
        int refs;
        
    public:
        inline CallBaseObject();
        virtual ~CallBaseObject();
#line 15
        void Dec();
#line 14
        inline void Inc();
    };
    
    class CallBase : public Indirect::CallBaseObject
    {
    public:
#line 21
        /*pure*/virtual void Execute() const = 0;
    };
    
    template < class _1 >
    class CallBase1 : public Indirect::CallBaseObject
    {
    public:
#line 27
        /*pure*/virtual void Execute(const _1& a0) const = 0;
    };
    
    template < class _1, class _2 >
    class CallBase2 : public Indirect::CallBaseObject
    {
    public:
#line 33
        /*pure*/virtual void Execute(const _1& a0, const _2& a1) const = 0;
    };
    
    class Callback
    {
    public:
#line 139
        typedef void(*Fn)();
        
#line 135
        Container::VectorPtr < CallBase > calls;
        
    public:
#line 141
        inline Callback();
#line 143
        Callback(CallBase *cb);
        inline Callback(Fn fn);
#line 142
        inline Callback(const Callback& cb);
#line 145
        inline ~Callback();
#line 166
        inline void operator()() const;
#line 150
        void operator<< (const Callback& cb);
#line 146
        inline void operator= (const Callback& cb);
#line 167
        inline operator bool() const;
#line 169
        inline Lang::int64 AsInt() const;
#line 168
        inline Text::String AsString() const;
#line 156
        void Clear();
#line 161
        void Execute() const;
    };
    
    template < class _1 >
    class Callback1
    {
#line 177
        typedef Indirect::CallBase1 < _1 > Base;
        
    public:
#line 181
        typedef void(*Fn)(_1);
        
#line 178
        Container::VectorPtr < Base > calls;
        
    public:
#line 183
        inline Callback1();
#line 185
        Callback1(Base *cb);
        Callback1(Fn fn);
#line 184
        inline Callback1(const Callback1& cb);
#line 187
        inline ~Callback1();
#line 210
        inline void operator()(const _1& a0) const;
#line 192
        void operator<< (const Callback1& cb);
#line 188
        inline void operator= (const Callback1& cb);
#line 211
        inline operator bool() const;
#line 208
        inline void Add(Indirect::CallBase1 < _1 > *call);
#line 213
        inline Lang::int64 AsInt() const;
#line 212
        inline Text::String AsString() const;
#line 198
        void Clear();
#line 203
        void Execute(const _1& a0) const;
    };
    
    template < class _1, class _2 >
    class Callback2
    {
#line 267
        typedef CallBase2 < _1, _2 > Base;
        
#line 268
        Container::VectorPtr < Base > calls;
        
    public:
        inline Callback2();
#line 273
        Callback2(Base *cb);
#line 272
        inline Callback2(const Callback2& cb);
#line 274
        inline ~Callback2();
#line 295
        inline void operator()(const _1& a0, const _2& a1) const;
#line 279
        void operator<< (const Callback2& cb);
#line 275
        inline void operator= (const Callback2& cb);
#line 296
        inline operator bool() const;
#line 298
        inline Lang::int64 AsInt() const;
#line 297
        inline Text::String AsString() const;
#line 285
        void Clear();
#line 290
        void Execute(const _1& a0, const _2& a1) const;
    };
    
    template < class _1 >
    class Caller : public Indirect::CallBase
    {
#line 53
        typedef _1 Cls;
        typedef void(Cls::*Fn)();
        
#line 55
        Fn fn;
        Cls *obj;
        
    public:
        Caller(Fn fn, Cls *obj);
        virtual void Execute() const;
    };
    
    template < class _1, class _2 >
    class Caller1 : public Indirect::CallBase1 < _1 >
    {
#line 75
        typedef _2 Cls;
        typedef void(Cls::*Fn)(_1);
        
#line 77
        Fn fn;
        Cls *obj;
        
    public:
        Caller1(Fn fn, Cls *obj);
        virtual void Execute(const _1& a0) const;
    };
    
    template < class _1, class _2, class _3 >
    class Caller1_1 : public Indirect::CallBase1 < _1 >
    {
#line 101
        typedef _2 Cls;
        typedef void(Cls::*Fn)(_1, _3);
        
#line 103
        Fn fn;
        _2 *obj;
        _3 a1;
        
    public:
        Caller1_1(Fn fn, _2 *obj, _3 a1);
        virtual void Execute(const _1& a0) const;
    };
    
    template < class _1, class _2, class _3 >
    class Caller2 : public Indirect::CallBase2 < _1, _2 >
    {
#line 114
        typedef _3 Cls;
        typedef void(Cls::*Fn)(_1, _2);
        
#line 116
        Fn fn;
        _3 *obj;
        
    public:
        Caller2(Fn fn, _3 *obj);
        virtual void Execute(const _1& a0, const _2& a1) const;
    };
    
    template < class _1, class _2 >
    class Caller_1 : public Indirect::CallBase
    {
#line 88
        typedef _1 Cls;
        typedef void(Cls::*Fn)(_2);
        
#line 90
        Fn fn;
        _1 *obj;
        _2 a0;
        
    public:
        Caller_1(Fn fn, _1 *obj, _2 a0);
        virtual void Execute() const;
    };
    
    struct Callexit
    {
#line 429
        typedef void(*Fn)();
        
#line 430
        inline Callexit(Fn fn);
    };
    
    struct Callinit
    {
#line 424
        typedef void(*Fn)();
        
#line 425
        inline Callinit(Fn fn);
    };
    
    class DynamicCallback1
    {
#line 220
        Container::OneAnon anon_cb;
        void *arg0fn;
        
    public:
#line 225
        inline DynamicCallback1();
        DynamicCallback1(const DynamicCallback1& cb);
        inline ~DynamicCallback1();
        void operator= (const DynamicCallback1& cb);
#line 258
        inline operator bool() const;
#line 260
        inline Lang::int64 AsInt() const;
#line 259
        inline Text::String AsString() const;
#line 232
        inline void Clear();
#line 234
        template < class _1 >
        Callback1 < _1 > & Create();
#line 242
        template < class _1 >
        bool Execute(const _1& a0) const;
    };
    
    class ProxyCaller : public Indirect::CallBase
    {
#line 310
        const Callback *cb;
        
    public:
#line 312
        inline ProxyCaller(const Callback& cb);
#line 314
        inline operator bool() const;
#line 313
        virtual void Execute() const;
    };
    
    template < class _1 >
    class ProxyCaller1 : public Indirect::CallBase1 < _1 >
    {
        typedef Callback1 < _1 > Cb;
        
#line 320
        const Cb *cb;
        
    public:
#line 322
        inline ProxyCaller1(const Cb& cb);
#line 324
        inline operator bool() const;
#line 323
        virtual void Execute(const _1& a0) const;
    };
    
    class StaticCaller : public Indirect::CallBase
    {
#line 42
        void(*fn)();
        
    public:
        inline StaticCaller(void(*fn)());
        virtual void Execute() const;
    };
    
    template < class _1 >
    class StaticCaller1 : public Indirect::CallBase1 < _1 >
    {
#line 65
        typedef void(*Fn)(_1);
        
#line 66
        Fn fn;
        
    public:
        inline StaticCaller1(Fn fn);
        virtual void Execute(const _1& a0) const;
    };
    
    template < class _1 >
    struct callback
    {
#line 338
        typedef _1 Cls;
        typedef void(Cls::*Fn)();
        
#line 340
        Callback cb;
        
        inline callback(Fn fn, Cls *obj);
        inline operator Callback() const;
    };
    
    template < class _1, class _2 >
    struct callback1
    {
#line 358
        typedef _2 Cls;
        typedef void(Cls::*Fn)(_1);
        
#line 360
        Callback cb;
        
        inline callback1(Fn fn, Cls *obj, _1 a0);
        inline operator Callback() const;
    };
    
    template < class _1, class _2, class _3 >
    struct callback1_1
    {
#line 368
        typedef _2 Cls;
        typedef void(Cls::*Fn)(_1, _3);
        
#line 370
        Callback1 < _1 > cb;
        
        inline callback1_1(Fn fn, Cls *obj, _3 a1);
        inline operator Callback1 < _1 > () const;
    };
    
    template < class _1, class _2 >
    struct callback_1
    {
#line 348
        typedef _2 Cls;
        typedef void(Cls::*Fn)(_1);
        
#line 350
        Callback1 < _1 > cb;
        
        inline callback_1(Fn fn, Cls *obj);
        inline operator Callback1 < _1 > () const;
    };
    
    template < class _1, class _2, class _3 >
    struct callback_2
    {
#line 378
        typedef _3 Cls;
        typedef void(Cls::*Fn)(_1, _2);
        
#line 380
        Callback2 < _1, _2 > cb;
        
        inline callback_2(Fn fn, Cls *obj);
        inline operator Callback2 < _1, _2 > () const;
    };
};

namespace Indirect
{
#line 410
    inline void AddExitBlock(Callback cb)
    {
#line 410
        __ExitBlocks() << cb;
    };
    
#line 409
    inline void AddInitBlock(Callback cb)
    {
#line 409
        __InitBlocks() << cb;
    };
    
#line 394
    inline Callback Proxy(Callback cb)
    {
#line 395
        return Callback(new ProxyCaller(cb));
    };
    
    template < class _1 >
    inline Callback1 < _1 > Proxy_1(Callback1 < _1 > cb)
    {
#line 400
        return Callback1 < _1 > (new ProxyCaller1 < _1 > (cb));
    };
    
#line 407
    inline Container::Vector < Callback > & __ExitBlocks()
    {
#line 407
        static Container::Vector < Callback > v;
#line 407
        return v;
    };
    
#line 406
    inline Container::Vector < Callback > & __InitBlocks()
    {
#line 406
        static Container::Vector < Callback > v;
#line 406
        return v;
    };
    
#line 11
    inline CallBaseObject::CallBaseObject()
    :
        refs(1)
    {};
    
#line 14
    inline void CallBaseObject::Inc()
    {
#line 14
        refs ++ ;
    };
    
#line 141
    inline Callback::Callback() {};
    
#line 144
    inline Callback::Callback(Fn fn)
    {
#line 144
        calls.Add(new StaticCaller(fn));
    };
    
#line 142
    inline Callback::Callback(const Callback& cb)
    {
#line 142
        *this = cb;
    };
    
    inline Callback::~Callback()
    {
#line 145
        Clear();
    };
    
#line 166
    inline void Callback::operator()() const
    {
#line 166
        Execute();
    };
    
#line 146
    inline void Callback::operator= (const Callback& cb)
    {
#line 147
        Clear();
        *this << cb;
    };
    
#line 167
    inline Callback::operator bool() const
    {
#line 167
        return calls.GetCount();
    };
    
#line 169
    inline Lang::int64 Callback::AsInt() const
    {
#line 169
        return calls.GetCount();
    };
    
#line 168
    inline Text::String Callback::AsString() const
    {
#line 168
        return "Callback";
    };
    
#line 183
    template < class _1 >
    inline Callback1 < _1 >::Callback1() {};
    
#line 184
    template < class _1 >
    inline Callback1 < _1 >::Callback1(const Callback1& cb)
    {
#line 184
        *this = cb;
    };
    
    template < class _1 >
    inline Callback1 < _1 >::~Callback1()
    {
#line 187
        Clear();
    };
    
#line 210
    template < class _1 >
    inline void Callback1 < _1 >::operator()(const _1& a0) const
    {
#line 210
        Execute(a0);
    };
    
#line 188
    template < class _1 >
    inline void Callback1 < _1 >::operator= (const Callback1& cb)
    {
#line 189
        Clear();
        *this << cb;
    };
    
#line 211
    template < class _1 >
    inline Callback1 < _1 >::operator bool() const
    {
#line 211
        return calls.GetCount();
    };
    
#line 208
    template < class _1 >
    inline void Callback1 < _1 >::Add(Indirect::CallBase1 < _1 > *call)
    {
#line 208
        calls.Add(call);
    };
    
#line 213
    template < class _1 >
    inline Lang::int64 Callback1 < _1 >::AsInt() const
    {
#line 213
        return calls.GetCount();
    };
    
#line 212
    template < class _1 >
    inline Text::String Callback1 < _1 >::AsString() const
    {
#line 212
        return "Callback1";
    };
    
#line 271
    template < class _1, class _2 >
    inline Callback2 < _1, _2 >::Callback2() {};
    
#line 272
    template < class _1, class _2 >
    inline Callback2 < _1, _2 >::Callback2(const Callback2& cb)
    {
#line 272
        *this = cb;
    };
    
#line 274
    template < class _1, class _2 >
    inline Callback2 < _1, _2 >::~Callback2()
    {
#line 274
        Clear();
    };
    
#line 295
    template < class _1, class _2 >
    inline void Callback2 < _1, _2 >::operator()(const _1& a0, const _2& a1) const
    {
#line 295
        Execute(a0, a1);
    };
    
#line 275
    template < class _1, class _2 >
    inline void Callback2 < _1, _2 >::operator= (const Callback2& cb)
    {
#line 276
        Clear();
        *this << cb;
    };
    
#line 296
    template < class _1, class _2 >
    inline Callback2 < _1, _2 >::operator bool() const
    {
#line 296
        return calls.GetCount();
    };
    
#line 298
    template < class _1, class _2 >
    inline Lang::int64 Callback2 < _1, _2 >::AsInt() const
    {
#line 298
        return calls.GetCount();
    };
    
#line 297
    template < class _1, class _2 >
    inline Text::String Callback2 < _1, _2 >::AsString() const
    {
#line 297
        return "Callback2";
    };
    
#line 430
    inline Callexit::Callexit(Fn fn)
    {
#line 430
        AddExitBlock(Callback(fn));
    };
    
#line 425
    inline Callinit::Callinit(Fn fn)
    {
#line 425
        AddInitBlock(Callback(fn));
    };
    
#line 225
    inline DynamicCallback1::DynamicCallback1()
    :
        arg0fn(0)
    {};
    
#line 227
    inline DynamicCallback1::~DynamicCallback1()
    {
#line 227
        Clear();
    };
    
#line 258
    inline DynamicCallback1::operator bool() const
    {
#line 258
        return(bool) anon_cb;
    };
    
#line 260
    inline Lang::int64 DynamicCallback1::AsInt() const
    {
#line 260
        return anon_cb.AsInt();
    };
    
#line 259
    inline Text::String DynamicCallback1::AsString() const
    {
#line 259
        return "DynamicCallback1";
    };
    
#line 232
    inline void DynamicCallback1::Clear()
    {
#line 232
        anon_cb.Clear();
#line 232
        arg0fn = 0;
    };
    
#line 312
    inline ProxyCaller::ProxyCaller(const Callback& cb)
    :
        cb(&cb)
    {};
    
#line 314
    inline ProxyCaller::operator bool() const
    {
#line 314
        return cb;
    };
    
#line 322
    template < class _1 >
    inline ProxyCaller1 < _1 >::ProxyCaller1(const Cb& cb)
    :
        cb(&cb)
    {};
    
#line 324
    template < class _1 >
    inline ProxyCaller1 < _1 >::operator bool() const
    {
#line 324
        return cb;
    };
    
#line 45
    inline StaticCaller::StaticCaller(void(*fn)())
    :
        fn(fn)
    {};
    
#line 69
    template < class _1 >
    inline StaticCaller1 < _1 >::StaticCaller1(Fn fn)
    :
        fn(fn)
    {};
    
#line 342
    template < class _1 >
    inline callback < _1 >::callback(Fn fn, Cls *obj)
    {
#line 342
        cb = Callback(new Caller < Cls > (fn, obj));
    };
    
#line 343
    template < class _1 >
    inline callback < _1 >::operator Callback() const
    {
#line 343
        return cb;
    };
    
#line 362
    template < class _1, class _2 >
    inline callback1 < _1, _2 >::callback1(Fn fn, Cls *obj, _1 a0)
    {
#line 362
        cb = Callback(new Caller_1 < _1, Cls > (fn, obj, a0));
    };
    
#line 363
    template < class _1, class _2 >
    inline callback1 < _1, _2 >::operator Callback() const
    {
#line 363
        return cb;
    };
    
#line 372
    template < class _1, class _2, class _3 >
    inline callback1_1 < _1, _2, _3 >::callback1_1(Fn fn, Cls *obj, _3 a1)
    {
#line 372
        cb = Callback1 < _1 > (new Caller1_1 < _1, Cls, _3 > (fn, obj, a1));
    };
    
#line 373
    template < class _1, class _2, class _3 >
    inline callback1_1 < _1, _2, _3 >::operator Callback1 < _1 > () const
    {
#line 373
        return cb;
    };
    
#line 352
    template < class _1, class _2 >
    inline callback_1 < _1, _2 >::callback_1(Fn fn, Cls *obj)
    {
#line 352
        cb = Callback1 < _1 > (new Caller1 < _1, Cls > (fn, obj));
    };
    
#line 353
    template < class _1, class _2 >
    inline callback_1 < _1, _2 >::operator Callback1 < _1 > () const
    {
#line 353
        return cb;
    };
    
#line 382
    template < class _1, class _2, class _3 >
    inline callback_2 < _1, _2, _3 >::callback_2(Fn fn, Cls *obj)
    {
#line 382
        cb = Callback2 < _1, _2 > (new Caller2 < _1, _2, Cls > (fn, obj));
    };
    
#line 383
    template < class _1, class _2, class _3 >
    inline callback_2 < _1, _2, _3 >::operator Callback2 < _1, _2 > () const
    {
#line 383
        return cb;
    };
    
};

#endif
