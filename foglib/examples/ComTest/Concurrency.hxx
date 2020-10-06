#ifndef CONCURRENCY_HXX
#define CONCURRENCY_HXX

#include <new>

#ifndef INDIRECT_HXX
#include <Indirect.hxx>
#endif

namespace Concurrency
{
};

namespace Concurrency {
class TimelineEnv;
}

namespace Concurrency
{
#line 182 "../../src/Com/Concurrency.fog"
    inline TimelineEnv& GetTimelineEnv();
#line 186
    inline void PostCallback(Indirect::Callback cb, void *id = 0);
#line 183
    inline TimelineEnv& TLEnv();
};

namespace Concurrency {
class Mutex;
}

namespace Concurrency
{
    class MutexLocker
    {
#line 108
        Mutex& m;
        
    public:
#line 110
        MutexLocker(Mutex& m);
        inline ~MutexLocker();
    };
    
    namespace Native
    {
#line 8
        int CPU_Cores();
        void Sleep(int ms);
        
        struct StdMutex
        {
#line 24
            typedef void(*Fn)(void *);
            
#line 25
            StdMutex();
            ~StdMutex();
            void Enter();
            void Leave();
            bool TryEnter();
            
#line 30
            static StdMutex *Create();
        };
        
        struct StdSharedMutex
        {
#line 34
            StdSharedMutex();
            ~StdSharedMutex();
#line 38
            void EnterRead();
#line 36
            void EnterWrite();
#line 39
            void LeaveRead();
#line 37
            void LeaveWrite();
            
#line 40
            static StdSharedMutex *Create();
        };
        
        struct StdThread
        {
#line 12
            typedef void(*Fn)(void *);
            
#line 13
            StdThread();
            ~StdThread();
            void Clear();
#line 18
            void Detach();
#line 16
            void Run(Fn fn, void *arg);
            void Wait();
            
            static StdThread *Create();
            static void Start(Fn fn, void *arg);
        };
    };
    
    class Mutex
    {
#line 93
        typedef Native::StdMutex Std;
        
#line 94
        Container::One < Std > m;
        
    public:
        inline Mutex();
        inline ~Mutex();
        void Create();
        inline void Enter();
        inline void Leave();
        inline bool TryEnter();
    };
    
    class RWMutex
    {
#line 116
        typedef Native::StdSharedMutex Std;
        
#line 117
        Container::One < Std > m;
        
    public:
        inline RWMutex();
        void Create();
#line 124
        inline void EnterRead();
#line 122
        inline void EnterWrite();
#line 125
        inline void LeaveRead();
#line 123
        inline void LeaveWrite();
    };
    
    class RWMutexReadLocker
    {
#line 130
        RWMutex& m;
        
    public:
#line 132
        RWMutexReadLocker(RWMutex& m);
        inline ~RWMutexReadLocker();
    };
    
    class RWMutexWriteLocker
    {
#line 137
        RWMutex& m;
        
    public:
#line 139
        RWMutexWriteLocker(RWMutex& m);
        inline ~RWMutexWriteLocker();
    };
    
    struct RunningFlag
    {
#line 359
        int sleep_time;
        bool running;
        Lang::AtomicInt workers_running;
        
        RunningFlag();
#line 368
        void DecreaseRunning();
#line 367
        inline void IncreaseRunning();
#line 369
        inline bool IsRunning() const;
#line 366
        inline void SetNotRunning();
#line 364
        void Start(int count);
        void Stop();
#line 370
        inline void Wait();
    };
    
    class RunningFlagSingle
    {
#line 346
        bool running;
#line 346
        bool stopped;
        
    public:
        RunningFlagSingle();
        inline bool IsRunning() const;
#line 352
        inline void SetNotRunning();
#line 351
        inline void SetStopped();
#line 353
        inline void Start();
        void Stop();
    };
    
    class Thread
    {
#line 49
        typedef Native::StdThread Std;
        
#line 50
        Container::One < Std > t;
        Indirect::Callback cb;
        
    public:
#line 57
        inline Thread();
        inline ~Thread();
#line 81
        inline void Detach();
#line 60
        inline void ExecuteCallbackOnly();
#line 72
        void Run(Indirect::Callback cb);
#line 80
        inline void Wait();
        
    public:
        inline static bool IsShutdownThreads();
#line 62
        inline static void NativeCallback(void *arg);
#line 85
        static void ShutdownAndWaitThreads();
#line 84
        inline static void ShutdownThreads(bool b = true);
#line 64
        static void Start(Indirect::Callback cb);
        
#line 53
        inline static bool& shutdown();
        inline static Lang::AtomicInt& thrd_count();
    };
    
    class TimeCallback
    {
#line 333
        Lang::byte dummy;
        
    public:
#line 324
        inline ~TimeCallback();
#line 328
        inline void Kill();
#line 330
        inline void KillPost(Indirect::Callback cb);
#line 329
        inline void KillSet(int delay, Indirect::Callback cb);
#line 327
        inline void Post(Indirect::Callback cb);
#line 326
        inline void Set(int delay, Indirect::Callback cb);
    };
    
    struct TimeCallbackItem
    {
#line 155
        void *id;
        Indirect::Callback cb;
        Lang::uint32 ticks;
        Lang::uint32 delay;
        bool is_periodical;
        Lang::byte epoch;
    };
    
    class TimelineEnv
    {
#line 164
        Container::Array < TimeCallbackItem > cb;
        Container::Vector < int > remlist;
        Lang::uint32 global_ticks;
        Mutex m;
        
    public:
#line 172
        inline TimelineEnv();
#line 301
        void AddGlobalTicks(Lang::uint32 ticks);
#line 246
        bool ExistsTimeCallback(void *id);
#line 179
        inline Lang::uint32 GetGlobalTicks();
#line 177
        Lang::dword GetTimeClick();
#line 230
        void KillTimeCallback(void *id);
#line 174
        void SetTimeCallback(int delay_ms, Indirect::Callback cb, void *id = 0);
        
#line 287
        void DecreaseTimeCallbackEpoch();
#line 257
        void ExecuteTimeCallback();
    };
};

namespace Concurrency
{
#line 182
    inline TimelineEnv& GetTimelineEnv()
    {
#line 182
        static TimelineEnv e;
#line 182
        return e;
    };
    
#line 186
    inline void PostCallback(Indirect::Callback cb, void *id)
    {
#line 187
        TLEnv().SetTimeCallback(1, cb, id);
    };
    
#line 183
    inline TimelineEnv& TLEnv()
    {
#line 183
        return GetTimelineEnv();
    };
    
#line 97
    inline Mutex::Mutex()
    {
#line 97
        Create();
    };
    
#line 98
    inline Mutex::~Mutex() {};
    
    inline void Mutex::Enter()
    {
#line 100
        m -> Enter();
    };
    
#line 101
    inline void Mutex::Leave()
    {
#line 101
        m -> Leave();
    };
    
#line 102
    inline bool Mutex::TryEnter()
    {
#line 102
        return m -> TryEnter();
    };
    
#line 111
    inline MutexLocker::~MutexLocker()
    {
#line 111
        m.Leave();
    };
    
#line 120
    inline RWMutex::RWMutex()
    {
#line 120
        Create();
    };
    
#line 124
    inline void RWMutex::EnterRead()
    {
#line 124
        m -> EnterRead();
    };
    
#line 122
    inline void RWMutex::EnterWrite()
    {
#line 122
        m -> EnterWrite();
    };
    
    inline void RWMutex::LeaveRead()
    {
#line 125
        m -> LeaveRead();
    };
    
#line 123
    inline void RWMutex::LeaveWrite()
    {
#line 123
        m -> LeaveWrite();
    };
    
#line 133
    inline RWMutexReadLocker::~RWMutexReadLocker()
    {
#line 133
        m.LeaveRead();
    };
    
#line 140
    inline RWMutexWriteLocker::~RWMutexWriteLocker()
    {
#line 140
        m.LeaveWrite();
    };
    
#line 367
    inline void RunningFlag::IncreaseRunning()
    {
#line 367
        workers_running ++ ;
    };
    
#line 369
    inline bool RunningFlag::IsRunning() const
    {
#line 369
        return running;
    };
    
#line 366
    inline void RunningFlag::SetNotRunning()
    {
#line 366
        running = false;
    };
    
#line 370
    inline void RunningFlag::Wait()
    {
#line 370
        while ((int) workers_running != 0)
#line 370
            Native::Sleep(100);
    };
    
#line 350
    inline bool RunningFlagSingle::IsRunning() const
    {
#line 350
        return running;
    };
    
#line 352
    inline void RunningFlagSingle::SetNotRunning()
    {
#line 352
        running = false;
    };
    
#line 351
    inline void RunningFlagSingle::SetStopped()
    {
#line 351
        stopped = true;
    };
    
#line 353
    inline void RunningFlagSingle::Start()
    {
#line 353
        running = true;
#line 353
        stopped = false;
    };
    
#line 57
    inline Thread::Thread()
    {
#line 57
        thrd_count()++ ;
    };
    
#line 58
    inline Thread::~Thread()
    {
#line 58
        thrd_count()-- ;
    };
    
#line 81
    inline void Thread::Detach()
    {
#line 81
        if (t)
#line 81
            t -> Detach();
    };
    
#line 60
    inline void Thread::ExecuteCallbackOnly()
    {
#line 60
        cb.Execute();
    };
    
#line 83
    inline bool Thread::IsShutdownThreads()
    {
#line 83
        return shutdown();
    };
    
#line 62
    inline void Thread::NativeCallback(void *arg)
    {
#line 62
        ((Thread * ) arg)-> ExecuteCallbackOnly();
    };
    
#line 84
    inline void Thread::ShutdownThreads(bool b)
    {
#line 84
        shutdown() = b;
    };
    
#line 80
    inline void Thread::Wait()
    {
#line 80
        if (t)
#line 80
            t -> Wait();
    };
    
#line 53
    inline bool& Thread::shutdown()
    {
#line 53
        static bool b;
#line 53
        return b;
    };
    
#line 54
    inline Lang::AtomicInt& Thread::thrd_count()
    {
#line 54
        static Lang::AtomicInt a;
#line 54
        return a;
    };
    
#line 324
    inline TimeCallback::~TimeCallback()
    {
#line 324
        Kill();
#line 324
        (void) dummy;
    };
    
#line 328
    inline void TimeCallback::Kill()
    {
#line 328
        TLEnv().KillTimeCallback(this);
    };
    
#line 330
    inline void TimeCallback::KillPost(Indirect::Callback cb)
    {
#line 330
        Kill();
#line 330
        Post(cb);
    };
    
#line 329
    inline void TimeCallback::KillSet(int delay, Indirect::Callback cb)
    {
#line 329
        Kill();
#line 329
        Set(delay, cb);
    };
    
#line 327
    inline void TimeCallback::Post(Indirect::Callback cb)
    {
#line 327
        PostCallback(cb, this);
    };
    
#line 326
    inline void TimeCallback::Set(int delay, Indirect::Callback cb)
    {
#line 326
        TLEnv().SetTimeCallback(delay, cb, this);
    };
    
#line 172
    inline TimelineEnv::TimelineEnv()
    :
        global_ticks(0)
    {};
    
#line 179
    inline Lang::uint32 TimelineEnv::GetGlobalTicks()
    {
#line 179
        return global_ticks;
    };
    
};

#endif
