#ifndef CONCURRENCY_CXX
#define CONCURRENCY_CXX

#include <new>

#ifndef CONCURRENCY_HXX
#include <Concurrency.hxx>
#endif

namespace Concurrency
{
#line 99 "../../src/Com/Concurrency.fog"
    void Mutex::Create()
    {
#line 99
        m.Clear();
#line 99
        m = Native::StdMutex::Create();
    };
    
#line 110
    Mutex_Locker::Mutex_Locker(Mutex& m)
    :
        m(m)
    {
#line 110
        m.Enter();
    };
    
#line 121
    void RWMutex::Create()
    {
#line 121
        m.Clear();
#line 121
        m = Native::StdSharedMutex::Create();
    };
    
#line 132
    RWMutex_ReadLocker::RWMutex_ReadLocker(RWMutex& m)
    :
        m(m)
    {
#line 132
        m.EnterRead();
    };
    
#line 139
    RWMutex_WriteLocker::RWMutex_WriteLocker(RWMutex& m)
    :
        m(m)
    {
#line 139
        m.EnterWrite();
    };
    
#line 72
    void Thread::Run(Indirect::Callback cb)
    {
        {
#line 73
            if (!(t.IsEmpty()))
            {
#line 73
                Lang::SysBreak("Assertion failed: t.IsEmpty()");
            }
        }
#line 74
        ;
#line 74
        this -> cb = cb;
        t.Clear();
        t = Native::StdThread::Create();
        t -> Run(&Thread::NativeCallback, this);
    };
    
#line 85
    void Thread::ShutdownAndWaitThreads()
    {
#line 86
        shutdown() = true;
        while (thrd_count() != 0)
#line 87
            Native::Sleep(100);
    };
    
#line 64
    void Thread::Start(Indirect::Callback cb)
    {
#line 65
        Thread * t = new Thread;
        t -> cb = cb;
        t -> t.Clear();
        t -> t = Native::StdThread::Create();
        t -> t -> Run(&Thread::NativeCallback, t);
    };
    
#line 301
    void TimelineEnv::AddGlobalTicks(Lang::uint32 ticks)
    {
#line 302
        Lang::uint32 prev_global_ticks = global_ticks;
        global_ticks += ticks;
#line 306
        if (global_ticks < prev_global_ticks)
            DecreaseTimeCallbackEpoch();
#line 309
        ExecuteTimeCallback();
    };
    
#line 287
    void TimelineEnv::DecreaseTimeCallbackEpoch()
    {
#line 288
        m.Enter();
#line 290
        for (int i = 0; i < cb.GetCount(); i ++ )
            {
#line 291
                TimeCallbackItem & it = cb[i];
                if (it.epoch > 0)
                    it.epoch -- ;
                else
                    cb.Remove(i -- );
            }
#line 298
        m.Leave();
    };
    
#line 257
    void TimelineEnv::ExecuteTimeCallback()
    {
#line 258
        remlist.SetCount(0);
#line 260
        Lang::FwdPtrIterator < TimeCallbackItem > it = cb.Begin();
        Lang::FwdPtrIterator < TimeCallbackItem > end = cb.End();
        int i = 0;
        while (it != end)
            {
#line 264
                if (it -> epoch == 0 && it -> ticks <= global_ticks)
                {
#line 265
                    it -> cb.Execute();
                    if (it -> is_periodical)
                    {
#line 267
                        it -> ticks = global_ticks + it -> delay;
                        if (it -> ticks < global_ticks)
                            it -> epoch = 1;
                        else
                            it -> epoch = 0;
                    }
                    else
                        remlist.Add(i);
                }
                ++ it;
                ++ i;
            }
#line 280
        if (remlist.GetCount())
        {
#line 281
            m.Enter();
            cb.Remove(remlist.Begin(), remlist.GetCount());
            m.Leave();
        }
    };
    
#line 246
    bool TimelineEnv::ExistsTimeCallback(void *id)
    {
#line 247
        Lang::FwdPtrIterator < TimeCallbackItem > it = cb.Begin();
        Lang::FwdPtrIterator < TimeCallbackItem > end = cb.End();
        while (it != end)
            {
#line 250
                if (it -> id == id)
                    return true;
                ++ it;
            }
        return false;
    };
    
#line 230
    void TimelineEnv::KillTimeCallback(void *id)
    {
#line 231
        Lang::FwdPtrIterator < TimeCallbackItem > it = cb.Begin();
        Lang::FwdPtrIterator < TimeCallbackItem > end = cb.End();
        int i = 0;
        while (it != end)
            {
#line 235
                if (it -> id == id)
                {
#line 236
                    m.Enter();
                    cb.Remove(i);
                    m.Leave();
                    break;
                
                }
#line 241
                ++ it;
                ++ i;
            }
    };
    
#line 174
    void TimelineEnv::SetTimeCallback(int delay_ms, Indirect::Callback cb, void *id)
    {
#line 192
        bool is_periodical = false;
        if (delay_ms < 0)
        {
#line 194
            delay_ms *= - 1;
            is_periodical = true;
        }
#line 198
        for (int i = 0; i < this -> cb.GetCount(); i ++ )
            {
#line 199
                TimeCallbackItem & it = this -> cb[i];
                if (it.id == id)
                {
#line 201
                    it.cb = cb;
                    it.ticks = global_ticks + delay_ms;
                    it.delay = delay_ms;
                    it.is_periodical = is_periodical;
                    if (it.ticks < global_ticks)
                        it.epoch = 1;
                    else
                        it.epoch = 0;
                    return;
                }
            }
#line 214
        m.Enter();
#line 216
        TimeCallbackItem & it = this -> cb.Add();
        it.id = id;
        it.cb = cb;
        it.ticks = global_ticks + delay_ms;
        it.delay = delay_ms;
        it.is_periodical = is_periodical;
        if (it.ticks < global_ticks)
            it.epoch = 1;
        else
            it.epoch = 0;
#line 227
        m.Leave();
    };
    
};

#endif
