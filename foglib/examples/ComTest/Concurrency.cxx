#ifndef CONCURRENCY_CXX
#define CONCURRENCY_CXX

#include <new>

#ifndef CONCURRENCY_HXX
#include <Concurrency.hxx>
#endif

namespace Concurrency
{
#line 98 "../../src/Com/Concurrency.fog"
    void Mutex::Create()
    {
#line 98
        m.Clear();
#line 98
        m = Native::StdMutex::Create();
    };
    
#line 109
    MutexLocker::MutexLocker(Mutex& m)
    :
        m(m)
    {
#line 109
        m.Enter();
    };
    
#line 120
    void RWMutex::Create()
    {
#line 120
        m.Clear();
#line 120
        m = Native::StdSharedMutex::Create();
    };
    
#line 131
    RWMutexReadLocker::RWMutexReadLocker(RWMutex& m)
    :
        m(m)
    {
#line 131
        m.EnterRead();
    };
    
#line 138
    RWMutexWriteLocker::RWMutexWriteLocker(RWMutex& m)
    :
        m(m)
    {
#line 138
        m.EnterWrite();
    };
    
#line 362
    RunningFlag::RunningFlag()
    :
        sleep_time(100),
        running(false)
    {
#line 362
        workers_running = 0;
    };
    
#line 367
    void RunningFlag::DecreaseRunning()
    {
#line 367
        workers_running -- ;
#line 367
        if (workers_running == 0)
#line 367
            running = false;
    };
    
#line 363
    void RunningFlag::Start(int count)
    {
#line 363
        Stop();
#line 363
        running = true;
#line 363
        workers_running = count;
    };
    
#line 364
    void RunningFlag::Stop()
    {
#line 364
        running = false;
#line 364
        while (workers_running > 0)
#line 364
            Native::Sleep(sleep_time);
    };
    
#line 348
    RunningFlagSingle::RunningFlagSingle()
    :
        running(false),
        stopped(true)
    {};
    
#line 353
    void RunningFlagSingle::Stop()
    {
#line 353
        running = false;
#line 353
        while (!stopped)
#line 353
            Native::Sleep(100);
    };
    
#line 71
    void Thread::Run(Indirect::Callback cb)
    {
        {
#line 72
            if (!(t.IsEmpty()))
            {
#line 72
                Lang::SysBreak("Assertion failed: t.IsEmpty()");
            }
        }
#line 73
        ;
#line 73
        this -> cb = cb;
        t.Clear();
        t = Native::StdThread::Create();
        t -> Run(&Thread::NativeCallback, this);
    };
    
#line 84
    void Thread::ShutdownAndWaitThreads()
    {
#line 85
        shutdown() = true;
        while (thrd_count() != 0)
#line 86
            Native::Sleep(100);
    };
    
#line 63
    void Thread::Start(Indirect::Callback cb)
    {
#line 64
        Thread * t = new Thread;
        t -> cb = cb;
        t -> t.Clear();
        t -> t = Native::StdThread::Create();
        t -> t -> Run(&Thread::NativeCallback, t);
    };
    
#line 300
    void TimelineEnv::AddGlobalTicks(Lang::uint32 ticks)
    {
#line 301
        Lang::uint32 prev_global_ticks = global_ticks;
        global_ticks += ticks;
#line 305
        if (global_ticks < prev_global_ticks)
            DecreaseTimeCallbackEpoch();
#line 308
        ExecuteTimeCallback();
    };
    
#line 286
    void TimelineEnv::DecreaseTimeCallbackEpoch()
    {
#line 287
        m.Enter();
#line 289
        for (int i = 0; i < cb.GetCount(); i ++ )
            {
#line 290
                TimeCallbackItem & it = cb[i];
                if (it.epoch > 0)
                    it.epoch -- ;
                else
                    cb.Remove(i -- );
            }
#line 297
        m.Leave();
    };
    
#line 256
    void TimelineEnv::ExecuteTimeCallback()
    {
#line 257
        remlist.SetCount(0);
#line 259
        Lang::FwdPtrIterator < TimeCallbackItem > it = cb.Begin();
        Lang::FwdPtrIterator < TimeCallbackItem > end = cb.End();
        int i = 0;
        while (it != end)
            {
#line 263
                if (it -> epoch == 0 && it -> ticks <= global_ticks)
                {
#line 264
                    it -> cb.Execute();
                    if (it -> is_periodical)
                    {
#line 266
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
#line 279
        if (remlist.GetCount())
        {
#line 280
            m.Enter();
            cb.Remove(remlist.Begin(), remlist.GetCount());
            m.Leave();
        }
    };
    
#line 245
    bool TimelineEnv::ExistsTimeCallback(void *id)
    {
#line 246
        Lang::FwdPtrIterator < TimeCallbackItem > it = cb.Begin();
        Lang::FwdPtrIterator < TimeCallbackItem > end = cb.End();
        while (it != end)
            {
#line 249
                if (it -> id == id)
                    return true;
                ++ it;
            }
        return false;
    };
    
#line 229
    void TimelineEnv::KillTimeCallback(void *id)
    {
#line 230
        Lang::FwdPtrIterator < TimeCallbackItem > it = cb.Begin();
        Lang::FwdPtrIterator < TimeCallbackItem > end = cb.End();
        int i = 0;
        while (it != end)
            {
#line 234
                if (it -> id == id)
                {
#line 235
                    m.Enter();
                    cb.Remove(i);
                    m.Leave();
                    break;
                
                }
#line 240
                ++ it;
                ++ i;
            }
    };
    
#line 173
    void TimelineEnv::SetTimeCallback(int delay_ms, Indirect::Callback cb, void *id)
    {
#line 191
        bool is_periodical = false;
        if (delay_ms < 0)
        {
#line 193
            delay_ms *= - 1;
            is_periodical = true;
        }
#line 197
        for (int i = 0; i < this -> cb.GetCount(); i ++ )
            {
#line 198
                TimeCallbackItem & it = this -> cb[i];
                if (it.id == id)
                {
#line 200
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
#line 213
        m.Enter();
#line 215
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
#line 226
        m.Leave();
    };
    
};

#endif
