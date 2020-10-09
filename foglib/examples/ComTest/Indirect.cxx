#ifndef INDIRECT_CXX
#define INDIRECT_CXX

#include <new>

#ifndef INDIRECT_HXX
#include <Indirect.hxx>
#endif

namespace Indirect
{
#line 417 "../../src/Com/Indirect.fog"
    void RunExitBlocks()
    {
#line 418
        Lang::FwdIterator < Callback > it = __ExitBlocks().Begin();
        Lang::FwdIterator < Callback > end = __ExitBlocks().End();
        for (; it != end; ++ it)
#line 420
            it -> Execute();
    };
    
#line 411
    void RunInitBlocks()
    {
#line 412
        Lang::FwdIterator < Callback > it = __InitBlocks().Begin();
        Lang::FwdIterator < Callback > end = __InitBlocks().End();
        for (; it != end; ++ it)
#line 414
            it -> Execute();
    };
    
#line 12
    CallBaseObject::~CallBaseObject() {};
    
#line 15
    void CallBaseObject::Dec()
    {
#line 15
        if ((void * ) this == 0)
#line 15
            return;
#line 15
        refs -- ;
#line 15
        if (refs <= 0)
        {
#line 15
            delete this;
        }
    };
    
#line 143
    Callback::Callback(CallBase *cb)
    {
        {
#line 143
            if (!(cb))
            {
#line 143
                Lang::SysBreak("Assertion failed: cb");
            }
        }
#line 143
        ;
#line 143
        calls.Add(cb);
    };
    
#line 150
    void Callback::operator<< (const Callback& cb)
    {
#line 151
        int begin = calls.GetCount();
        calls.Append(cb.calls);
        for (int i = begin; i < calls.GetCount(); i ++ )
            calls[i].Inc();
    };
    
#line 156
    void Callback::Clear()
    {
#line 157
        for (int i = 0; i < calls.GetCount(); i ++ )
            calls[i].Dec();
        calls.Clear();
    };
    
#line 161
    void Callback::Execute() const
    {
#line 162
        for (int i = 0; i < calls.GetCount(); i ++ )
            calls[i].Execute();
    };
    
#line 185
    template < class _1 >
    Callback1 < _1 >::Callback1(Base *cb)
    {
        {
#line 185
            if (!(cb))
            {
#line 185
                Lang::SysBreak("Assertion failed: cb");
            }
        }
#line 185
        ;
#line 185
        calls.Add(cb);
    };
    
#line 186
    template < class _1 >
    Callback1 < _1 >::Callback1(Fn fn)
    {
#line 186
        Base * cb = new Base(fn);
#line 186
        calls.Add(cb);
    };
    
#line 192
    template < class _1 >
    void Callback1 < _1 >::operator<< (const Callback1& cb)
    {
#line 193
        int begin = calls.GetCount();
        calls.Append(cb.calls);
        for (int i = begin; i < calls.GetCount(); i ++ )
            calls[i] -> Inc();
    };
    
#line 198
    template < class _1 >
    void Callback1 < _1 >::Clear()
    {
#line 199
        for (int i = 0; i < calls.GetCount(); i ++ )
            calls[i] -> Dec();
        calls.Clear();
    };
    
#line 203
    template < class _1 >
    void Callback1 < _1 >::Execute(const _1& a0) const
    {
#line 204
        for (int i = 0; i < calls.GetCount(); i ++ )
            calls[i] -> Execute(a0);
    };
    
#line 273
    template < class _1, class _2 >
    Callback2 < _1, _2 >::Callback2(Base *cb)
    {
        {
#line 273
            if (!(cb))
            {
#line 273
                Lang::SysBreak("Assertion failed: cb");
            }
        }
#line 273
        ;
#line 273
        calls.Add(cb);
    };
    
#line 279
    template < class _1, class _2 >
    void Callback2 < _1, _2 >::operator<< (const Callback2& cb)
    {
#line 280
        int begin = calls.GetCount();
        calls.Append(cb.calls);
        for (int i = begin; i < calls.GetCount(); i ++ )
            calls[i] -> Inc();
    };
    
#line 285
    template < class _1, class _2 >
    void Callback2 < _1, _2 >::Clear()
    {
#line 286
        for (int i = 0; i < calls.GetCount(); i ++ )
            calls[i] -> Dec();
        calls.Clear();
    };
    
#line 290
    template < class _1, class _2 >
    void Callback2 < _1, _2 >::Execute(const _1& a0, const _2& a1) const
    {
#line 291
        for (int i = 0; i < calls.GetCount(); i ++ )
            calls[i] -> Execute(a0, a1);
    };
    
#line 59
    template < class _1 >
    Caller < _1 >::Caller(Fn fn, Cls *obj)
    :
        fn(fn),
        obj(obj)
    {};
    
#line 60
    template < class _1 >
    void Caller < _1 >::Execute() const
    {
#line 60
        (*obj .* fn)();
    };
    
#line 81
    template < class _1, class _2 >
    Caller1 < _1, _2 >::Caller1(Fn fn, Cls *obj)
    :
        fn(fn),
        obj(obj)
    {};
    
#line 82
    template < class _1, class _2 >
    void Caller1 < _1, _2 >::Execute(const _1& a0) const
    {
#line 82
        (*obj .* fn)(a0);
    };
    
#line 108
    template < class _1, class _2, class _3 >
    Caller1_1 < _1, _2, _3 >::Caller1_1(Fn fn, _2 *obj, _3 a1)
    :
        fn(fn),
        obj(obj),
        a1(a1)
    {};
    
#line 109
    template < class _1, class _2, class _3 >
    void Caller1_1 < _1, _2, _3 >::Execute(const _1& a0) const
    {
#line 109
        (*obj .* fn)(a0, a1);
    };
    
#line 120
    template < class _1, class _2, class _3 >
    Caller2 < _1, _2, _3 >::Caller2(Fn fn, _3 *obj)
    :
        fn(fn),
        obj(obj)
    {};
    
#line 121
    template < class _1, class _2, class _3 >
    void Caller2 < _1, _2, _3 >::Execute(const _1& a0, const _2& a1) const
    {
#line 121
        (*obj .* fn)(a0, a1);
    };
    
#line 95
    template < class _1, class _2 >
    Caller_1 < _1, _2 >::Caller_1(Fn fn, _1 *obj, _2 a0)
    :
        fn(fn),
        obj(obj),
        a0(a0)
    {};
    
#line 96
    template < class _1, class _2 >
    void Caller_1 < _1, _2 >::Execute() const
    {
#line 96
        (*obj .* fn)(a0);
    };
    
#line 226
    DynamicCallback1::DynamicCallback1(const DynamicCallback1& cb)
    :
        arg0fn(0)
    {
#line 226
        *this = cb;
    };
    
#line 228
    void DynamicCallback1::operator= (const DynamicCallback1& cb)
    {
#line 229
        anon_cb = cb.anon_cb;
        arg0fn = cb.arg0fn;
    };
    
#line 234
    template < class _1 >
    Callback1 < _1 > & DynamicCallback1::Create()
    {
#line 236
        Clear();
        typedef _1 Arg;
        arg0fn = &Container::TypeFn < Arg > ;
        return anon_cb.Create < Callback1 < Arg > > ();
    };
    
    template < class _1 >
    bool DynamicCallback1::Execute(const _1& a0) const
    {
#line 244
        if (!arg0fn)
            return true;
        typedef _1 Arg;
        void * try_arg0fn = &Container::TypeFn < Arg > ;
        if (try_arg0fn == arg0fn)
        {
#line 249
            Callback1 < Arg > * cb = anon_cb.TryGet < Callback1 < Arg > > ();
            {
#line 250
                if (!(cb))
                {
#line 250
                    Lang::SysBreak("Assertion failed: cb");
                }
            }
#line 251
            ;
#line 251
            if (cb)
                cb -> Execute(a0);
            return true;
        }
        return false;
    };
    
#line 313
    void ProxyCaller::Execute() const
    {
#line 313
        cb -> Execute();
    };
    
#line 323
    template < class _1 >
    void ProxyCaller1 < _1 >::Execute(const _1& a0) const
    {
#line 323
        cb -> Execute(a0);
    };
    
#line 46
    void StaticCaller::Execute() const
    {
#line 46
        fn();
    };
    
#line 70
    template < class _1 >
    void StaticCaller1 < _1 >::Execute(const _1& a0) const
    {
#line 70
        fn(a0);
    };
    
};

#endif
