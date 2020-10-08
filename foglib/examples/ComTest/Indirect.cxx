#ifndef INDIRECT_CXX
#define INDIRECT_CXX

#include <new>

#ifndef INDIRECT_HXX
#include <Indirect.hxx>
#endif

namespace Indirect
{
#line 347 "../../src/Com/Indirect.fog"
    void RunExitBlocks()
    {
#line 348
        Lang::FwdIterator < Callback > it = __ExitBlocks().Begin();
        Lang::FwdIterator < Callback > end = __ExitBlocks().End();
        for (; it != end; ++ it)
#line 350
            it -> Execute();
    };
    
#line 341
    void RunInitBlocks()
    {
#line 342
        Lang::FwdIterator < Callback > it = __InitBlocks().Begin();
        Lang::FwdIterator < Callback > end = __InitBlocks().End();
        for (; it != end; ++ it)
#line 344
            it -> Execute();
    };
    
#line 9
    CallBaseObject::~CallBaseObject() {};
    
#line 12
    void CallBaseObject::Dec()
    {
#line 12
        if ((void * ) this == 0)
#line 12
            return;
#line 12
        refs -- ;
#line 12
        if (refs <= 0)
        {
#line 12
            delete this;
        }
    };
    
#line 125
    Callback::Callback(CallBase *cb)
    {
        {
#line 125
            if (!(cb))
            {
#line 125
                Lang::SysBreak("Assertion failed: cb");
            }
        }
#line 125
        ;
#line 125
        calls.Add(cb);
    };
    
#line 132
    void Callback::operator<< (const Callback& cb)
    {
#line 133
        int begin = calls.GetCount();
        calls.Append(cb.calls);
        for (int i = begin; i < calls.GetCount(); i ++ )
            calls[i].Inc();
    };
    
#line 138
    void Callback::Clear()
    {
#line 139
        for (int i = 0; i < calls.GetCount(); i ++ )
            calls[i].Dec();
        calls.Clear();
    };
    
#line 143
    void Callback::Execute() const
    {
#line 144
        for (int i = 0; i < calls.GetCount(); i ++ )
            calls[i].Execute();
    };
    
#line 165
    template < class _1 >
    Callback1 < _1 >::Callback1(Base *cb)
    {
        {
#line 165
            if (!(cb))
            {
#line 165
                Lang::SysBreak("Assertion failed: cb");
            }
        }
#line 165
        ;
#line 165
        calls.Add(cb);
    };
    
#line 171
    template < class _1 >
    void Callback1 < _1 >::operator<< (const Callback1& cb)
    {
#line 172
        int begin = calls.GetCount();
        calls.Append(cb.calls);
        for (int i = begin; i < calls.GetCount(); i ++ )
            calls[i] -> Inc();
    };
    
#line 177
    template < class _1 >
    void Callback1 < _1 >::Clear()
    {
#line 178
        for (int i = 0; i < calls.GetCount(); i ++ )
            calls[i] -> Dec();
        calls.Clear();
    };
    
#line 182
    template < class _1 >
    void Callback1 < _1 >::Execute(const _1& a0) const
    {
#line 183
        for (int i = 0; i < calls.GetCount(); i ++ )
            calls[i] -> Execute(a0);
    };
    
#line 203
    template < class _1, class _2 >
    Callback2 < _1, _2 >::Callback2(Base *cb)
    {
        {
#line 203
            if (!(cb))
            {
#line 203
                Lang::SysBreak("Assertion failed: cb");
            }
        }
#line 203
        ;
#line 203
        calls.Add(cb);
    };
    
#line 209
    template < class _1, class _2 >
    void Callback2 < _1, _2 >::operator<< (const Callback2& cb)
    {
#line 210
        int begin = calls.GetCount();
        calls.Append(cb.calls);
        for (int i = begin; i < calls.GetCount(); i ++ )
            calls[i] -> Inc();
    };
    
#line 215
    template < class _1, class _2 >
    void Callback2 < _1, _2 >::Clear()
    {
#line 216
        for (int i = 0; i < calls.GetCount(); i ++ )
            calls[i] -> Dec();
        calls.Clear();
    };
    
#line 220
    template < class _1, class _2 >
    void Callback2 < _1, _2 >::Execute(const _1& a0, const _2& a1) const
    {
#line 221
        for (int i = 0; i < calls.GetCount(); i ++ )
            calls[i] -> Execute(a0, a1);
    };
    
#line 52
    template < class _1 >
    Caller < _1 >::Caller(Fn fn, Cls *obj)
    :
        fn(fn),
        obj(obj)
    {};
    
#line 53
    template < class _1 >
    void Caller < _1 >::Execute() const
    {
#line 53
        (*obj .* fn)();
    };
    
#line 64
    template < class _1, class _2 >
    Caller1 < _1, _2 >::Caller1(Fn fn, Cls *obj)
    :
        fn(fn),
        obj(obj)
    {};
    
#line 65
    template < class _1, class _2 >
    void Caller1 < _1, _2 >::Execute(const _1& a0) const
    {
#line 65
        (*obj .* fn)(a0);
    };
    
#line 90
    template < class _1, class _2, class _3 >
    Caller1_1 < _1, _2, _3 >::Caller1_1(Fn fn, _2 *obj, _3 a1)
    :
        fn(fn),
        obj(obj),
        a1(a1)
    {};
    
#line 91
    template < class _1, class _2, class _3 >
    void Caller1_1 < _1, _2, _3 >::Execute(const _1& a0) const
    {
#line 91
        (*obj .* fn)(a0, a1);
    };
    
#line 102
    template < class _1, class _2, class _3 >
    Caller2 < _1, _2, _3 >::Caller2(Fn fn, _3 *obj)
    :
        fn(fn),
        obj(obj)
    {};
    
#line 103
    template < class _1, class _2, class _3 >
    void Caller2 < _1, _2, _3 >::Execute(const _1& a0, const _2& a1) const
    {
#line 103
        (*obj .* fn)(a0, a1);
    };
    
#line 77
    template < class _1, class _2 >
    Caller_1 < _1, _2 >::Caller_1(Fn fn, _1 *obj, _2 a0)
    :
        fn(fn),
        obj(obj),
        a0(a0)
    {};
    
#line 78
    template < class _1, class _2 >
    void Caller_1 < _1, _2 >::Execute() const
    {
#line 78
        (*obj .* fn)(a0);
    };
    
#line 243
    void ProxyCaller::Execute() const
    {
#line 243
        cb -> Execute();
    };
    
#line 253
    template < class _1 >
    void ProxyCaller1 < _1 >::Execute(const _1& a0) const
    {
#line 253
        cb -> Execute(a0);
    };
    
#line 39
    void StaticCaller::Execute() const
    {
#line 39
        fn();
    };
    
};

#endif
