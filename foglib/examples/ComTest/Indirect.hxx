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
#line 340 "../../src/Com/Indirect.fog"
    inline void AddExitBlock(Callback cb);
#line 339
    inline void AddInitBlock(Callback cb);
#line 324
    inline Callback Proxy(Callback cb);
};

namespace Indirect {
template < class _1 > class Callback1;
}

namespace Indirect
{
#line 328
    template < class _1 >
    inline Callback1 < _1 > Proxy_1(Callback1 < _1 > cb);
#line 347
    void RunExitBlocks();
#line 341
    void RunInitBlocks();
#line 337
    inline Container::Vector < Callback > & __ExitBlocks();
#line 336
    inline Container::Vector < Callback > & __InitBlocks();
    
    class CallBaseObject
    {
#line 5
        int refs;
        
    public:
        inline CallBaseObject();
        virtual ~CallBaseObject();
#line 12
        void Dec();
#line 11
        inline void Inc();
    };
    
    class CallBase : public Indirect::CallBaseObject
    {
    public:
#line 18
        /*pure*/virtual void Execute() const = 0;
    };
    
    template < class _1 >
    class CallBase1 : public Indirect::CallBaseObject
    {
    public:
#line 24
        /*pure*/virtual void Execute(const _1& a0) const = 0;
    };
    
    template < class _1, class _2 >
    class CallBase2 : public Indirect::CallBaseObject
    {
    public:
#line 30
        /*pure*/virtual void Execute(const _1& a0, const _2& a1) const = 0;
    };
    
    class Callback
    {
    public:
#line 121
        typedef void(*Fn)();
        
#line 117
        Container::VectorPtr < CallBase > calls;
        
    public:
#line 123
        inline Callback();
#line 125
        Callback(CallBase *cb);
        inline Callback(Fn fn);
#line 124
        inline Callback(const Callback& cb);
#line 127
        inline ~Callback();
#line 148
        inline void operator()() const;
#line 132
        void operator<< (const Callback& cb);
#line 128
        inline void operator= (const Callback& cb);
#line 149
        inline operator bool() const;
#line 151
        inline Lang::int64 AsInt() const;
#line 150
        inline Text::String AsString() const;
#line 138
        void Clear();
#line 143
        void Execute() const;
    };
    
    template < class _1 >
    class Callback1
    {
#line 159
        typedef Indirect::CallBase1 < _1 > Base;
        
#line 160
        Container::VectorPtr < Base > calls;
        
    public:
        inline Callback1();
#line 165
        Callback1(Base *cb);
#line 164
        inline Callback1(const Callback1& cb);
#line 166
        inline ~Callback1();
#line 187
        inline void operator()(const _1& a0) const;
#line 171
        void operator<< (const Callback1& cb);
#line 167
        inline void operator= (const Callback1& cb);
#line 188
        inline operator bool() const;
#line 190
        inline Lang::int64 AsInt() const;
#line 189
        inline Text::String AsString() const;
#line 177
        void Clear();
#line 182
        void Execute(const _1& a0) const;
    };
    
    template < class _1, class _2 >
    class Callback2
    {
#line 197
        typedef CallBase2 < _1, _2 > Base;
        
#line 198
        Container::VectorPtr < Base > calls;
        
    public:
        inline Callback2();
#line 203
        Callback2(Base *cb);
#line 202
        inline Callback2(const Callback2& cb);
#line 204
        inline ~Callback2();
#line 225
        inline void operator()(const _1& a0, const _2& a1) const;
#line 209
        void operator<< (const Callback2& cb);
#line 205
        inline void operator= (const Callback2& cb);
#line 226
        inline operator bool() const;
#line 228
        inline Lang::int64 AsInt() const;
#line 227
        inline Text::String AsString() const;
#line 215
        void Clear();
#line 220
        void Execute(const _1& a0, const _2& a1) const;
    };
    
    template < class _1 >
    class Caller : public Indirect::CallBase
    {
#line 46
        typedef _1 Cls;
        typedef void(Cls::*Fn)();
        
#line 48
        Fn fn;
        Cls *obj;
        
    public:
        Caller(Fn fn, Cls *obj);
        virtual void Execute() const;
    };
    
    template < class _1, class _2 >
    class Caller1 : public Indirect::CallBase1 < _1 >
    {
#line 58
        typedef _2 Cls;
        typedef void(Cls::*Fn)(_1);
        
#line 60
        Fn fn;
        Cls *obj;
        
    public:
        Caller1(Fn fn, Cls *obj);
        virtual void Execute(const _1& a0) const;
    };
    
    template < class _1, class _2, class _3 >
    class Caller1_1 : public Indirect::CallBase1 < _1 >
    {
#line 83
        typedef _2 Cls;
        typedef void(Cls::*Fn)(_1, _3);
        
#line 85
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
#line 96
        typedef _3 Cls;
        typedef void(Cls::*Fn)(_1, _2);
        
#line 98
        Fn fn;
        _3 *obj;
        
    public:
        Caller2(Fn fn, _3 *obj);
        virtual void Execute(const _1& a0, const _2& a1) const;
    };
    
    template < class _1, class _2 >
    class Caller_1 : public Indirect::CallBase
    {
#line 70
        typedef _1 Cls;
        typedef void(Cls::*Fn)(_2);
        
#line 72
        Fn fn;
        _1 *obj;
        _2 a0;
        
    public:
        Caller_1(Fn fn, _1 *obj, _2 a0);
        virtual void Execute() const;
    };
    
    struct Callexit
    {
#line 359
        typedef void(*Fn)();
        
#line 360
        inline Callexit(Fn fn);
    };
    
    struct Callinit
    {
#line 354
        typedef void(*Fn)();
        
#line 355
        inline Callinit(Fn fn);
    };
    
    class ProxyCaller : public Indirect::CallBase
    {
#line 240
        const Callback *cb;
        
    public:
#line 242
        inline ProxyCaller(const Callback& cb);
#line 244
        inline operator bool() const;
#line 243
        virtual void Execute() const;
    };
    
    template < class _1 >
    class ProxyCaller1 : public Indirect::CallBase1 < _1 >
    {
        typedef Callback1 < _1 > Cb;
        
#line 250
        const Cb *cb;
        
    public:
#line 252
        inline ProxyCaller1(const Cb& cb);
#line 254
        inline operator bool() const;
#line 253
        virtual void Execute(const _1& a0) const;
    };
    
    class StaticCaller : public Indirect::CallBase
    {
#line 35
        void(*fn)();
        
    public:
        inline StaticCaller(void(*fn)());
        virtual void Execute() const;
    };
    
    template < class _1 >
    struct callback
    {
#line 268
        typedef _1 Cls;
        typedef void(Cls::*Fn)();
        
#line 270
        Callback cb;
        
        inline callback(Fn fn, Cls *obj);
        inline operator Callback() const;
    };
    
    template < class _1, class _2 >
    struct callback1
    {
#line 288
        typedef _2 Cls;
        typedef void(Cls::*Fn)(_1);
        
#line 290
        Callback cb;
        
        inline callback1(Fn fn, Cls *obj, _1 a0);
        inline operator Callback() const;
    };
    
    template < class _1, class _2, class _3 >
    struct callback1_1
    {
#line 298
        typedef _2 Cls;
        typedef void(Cls::*Fn)(_1, _3);
        
#line 300
        Callback1 < _1 > cb;
        
        inline callback1_1(Fn fn, Cls *obj, _3 a1);
        inline operator Callback1 < _1 > () const;
    };
    
    template < class _1, class _2 >
    struct callback_1
    {
#line 278
        typedef _2 Cls;
        typedef void(Cls::*Fn)(_1);
        
#line 280
        Callback1 < _1 > cb;
        
        inline callback_1(Fn fn, Cls *obj);
        inline operator Callback1 < _1 > () const;
    };
    
    template < class _1, class _2, class _3 >
    struct callback_2
    {
#line 308
        typedef _3 Cls;
        typedef void(Cls::*Fn)(_1, _2);
        
#line 310
        Callback2 < _1, _2 > cb;
        
        inline callback_2(Fn fn, Cls *obj);
        inline operator Callback2 < _1, _2 > () const;
    };
};

namespace Indirect
{
#line 340
    inline void AddExitBlock(Callback cb)
    {
#line 340
        __ExitBlocks() << cb;
    };
    
#line 339
    inline void AddInitBlock(Callback cb)
    {
#line 339
        __InitBlocks() << cb;
    };
    
#line 324
    inline Callback Proxy(Callback cb)
    {
#line 325
        return Callback(new ProxyCaller(cb));
    };
    
    template < class _1 >
    inline Callback1 < _1 > Proxy_1(Callback1 < _1 > cb)
    {
#line 330
        return Callback1 < _1 > (new ProxyCaller1 < _1 > (cb));
    };
    
#line 337
    inline Container::Vector < Callback > & __ExitBlocks()
    {
#line 337
        static Container::Vector < Callback > v;
#line 337
        return v;
    };
    
#line 336
    inline Container::Vector < Callback > & __InitBlocks()
    {
#line 336
        static Container::Vector < Callback > v;
#line 336
        return v;
    };
    
#line 8
    inline CallBaseObject::CallBaseObject()
    :
        refs(1)
    {};
    
#line 11
    inline void CallBaseObject::Inc()
    {
#line 11
        refs ++ ;
    };
    
#line 123
    inline Callback::Callback() {};
    
#line 126
    inline Callback::Callback(Fn fn)
    {
#line 126
        calls.Add(new StaticCaller(fn));
    };
    
#line 124
    inline Callback::Callback(const Callback& cb)
    {
#line 124
        *this = cb;
    };
    
    inline Callback::~Callback()
    {
#line 127
        Clear();
    };
    
#line 148
    inline void Callback::operator()() const
    {
#line 148
        Execute();
    };
    
#line 128
    inline void Callback::operator= (const Callback& cb)
    {
#line 129
        Clear();
        *this << cb;
    };
    
#line 149
    inline Callback::operator bool() const
    {
#line 149
        return calls.GetCount();
    };
    
#line 151
    inline Lang::int64 Callback::AsInt() const
    {
#line 151
        return calls.GetCount();
    };
    
#line 150
    inline Text::String Callback::AsString() const
    {
#line 150
        return "Callback";
    };
    
#line 163
    template < class _1 >
    inline Callback1 < _1 >::Callback1() {};
    
#line 164
    template < class _1 >
    inline Callback1 < _1 >::Callback1(const Callback1& cb)
    {
#line 164
        *this = cb;
    };
    
#line 166
    template < class _1 >
    inline Callback1 < _1 >::~Callback1()
    {
#line 166
        Clear();
    };
    
#line 187
    template < class _1 >
    inline void Callback1 < _1 >::operator()(const _1& a0) const
    {
#line 187
        Execute(a0);
    };
    
#line 167
    template < class _1 >
    inline void Callback1 < _1 >::operator= (const Callback1& cb)
    {
#line 168
        Clear();
        *this << cb;
    };
    
#line 188
    template < class _1 >
    inline Callback1 < _1 >::operator bool() const
    {
#line 188
        return calls.GetCount();
    };
    
#line 190
    template < class _1 >
    inline Lang::int64 Callback1 < _1 >::AsInt() const
    {
#line 190
        return calls.GetCount();
    };
    
#line 189
    template < class _1 >
    inline Text::String Callback1 < _1 >::AsString() const
    {
#line 189
        return "Callback1";
    };
    
#line 201
    template < class _1, class _2 >
    inline Callback2 < _1, _2 >::Callback2() {};
    
#line 202
    template < class _1, class _2 >
    inline Callback2 < _1, _2 >::Callback2(const Callback2& cb)
    {
#line 202
        *this = cb;
    };
    
#line 204
    template < class _1, class _2 >
    inline Callback2 < _1, _2 >::~Callback2()
    {
#line 204
        Clear();
    };
    
#line 225
    template < class _1, class _2 >
    inline void Callback2 < _1, _2 >::operator()(const _1& a0, const _2& a1) const
    {
#line 225
        Execute(a0, a1);
    };
    
#line 205
    template < class _1, class _2 >
    inline void Callback2 < _1, _2 >::operator= (const Callback2& cb)
    {
#line 206
        Clear();
        *this << cb;
    };
    
#line 226
    template < class _1, class _2 >
    inline Callback2 < _1, _2 >::operator bool() const
    {
#line 226
        return calls.GetCount();
    };
    
#line 228
    template < class _1, class _2 >
    inline Lang::int64 Callback2 < _1, _2 >::AsInt() const
    {
#line 228
        return calls.GetCount();
    };
    
#line 227
    template < class _1, class _2 >
    inline Text::String Callback2 < _1, _2 >::AsString() const
    {
#line 227
        return "Callback2";
    };
    
#line 360
    inline Callexit::Callexit(Fn fn)
    {
#line 360
        AddExitBlock(Callback(fn));
    };
    
#line 355
    inline Callinit::Callinit(Fn fn)
    {
#line 355
        AddInitBlock(Callback(fn));
    };
    
#line 242
    inline ProxyCaller::ProxyCaller(const Callback& cb)
    :
        cb(&cb)
    {};
    
#line 244
    inline ProxyCaller::operator bool() const
    {
#line 244
        return cb;
    };
    
#line 252
    template < class _1 >
    inline ProxyCaller1 < _1 >::ProxyCaller1(const Cb& cb)
    :
        cb(&cb)
    {};
    
#line 254
    template < class _1 >
    inline ProxyCaller1 < _1 >::operator bool() const
    {
#line 254
        return cb;
    };
    
#line 38
    inline StaticCaller::StaticCaller(void(*fn)())
    :
        fn(fn)
    {};
    
#line 272
    template < class _1 >
    inline callback < _1 >::callback(Fn fn, Cls *obj)
    {
#line 272
        cb = Callback(new Caller < Cls > (fn, obj));
    };
    
#line 273
    template < class _1 >
    inline callback < _1 >::operator Callback() const
    {
#line 273
        return cb;
    };
    
#line 292
    template < class _1, class _2 >
    inline callback1 < _1, _2 >::callback1(Fn fn, Cls *obj, _1 a0)
    {
#line 292
        cb = Callback(new Caller_1 < _1, Cls > (fn, obj, a0));
    };
    
#line 293
    template < class _1, class _2 >
    inline callback1 < _1, _2 >::operator Callback() const
    {
#line 293
        return cb;
    };
    
#line 302
    template < class _1, class _2, class _3 >
    inline callback1_1 < _1, _2, _3 >::callback1_1(Fn fn, Cls *obj, _3 a1)
    {
#line 302
        cb = Callback1 < _1 > (new Caller1_1 < _1, Cls, _3 > (fn, obj, a1));
    };
    
#line 303
    template < class _1, class _2, class _3 >
    inline callback1_1 < _1, _2, _3 >::operator Callback1 < _1 > () const
    {
#line 303
        return cb;
    };
    
#line 282
    template < class _1, class _2 >
    inline callback_1 < _1, _2 >::callback_1(Fn fn, Cls *obj)
    {
#line 282
        cb = Callback1 < _1 > (new Caller1 < _1, Cls > (fn, obj));
    };
    
#line 283
    template < class _1, class _2 >
    inline callback_1 < _1, _2 >::operator Callback1 < _1 > () const
    {
#line 283
        return cb;
    };
    
#line 312
    template < class _1, class _2, class _3 >
    inline callback_2 < _1, _2, _3 >::callback_2(Fn fn, Cls *obj)
    {
#line 312
        cb = Callback2 < _1, _2 > (new Caller2 < _1, _2, Cls > (fn, obj));
    };
    
#line 313
    template < class _1, class _2, class _3 >
    inline callback_2 < _1, _2, _3 >::operator Callback2 < _1, _2 > () const
    {
#line 313
        return cb;
    };
    
};

#endif
