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
#line 181 "../../src/Com/Concurrency.fog"
    inline TimelineEnv& GetTimelineEnv();
#line 185
    inline void PostCallback(Indirect::Callback cb, void *id = 0);
#line 182
    inline TimelineEnv& TLEnv();
};

namespace Concurrency {
class Mutex;
}

namespace Concurrency
{
    class MutexLocker
    {
#line 107
        Mutex& m;
        
    public:
#line 109
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
            StdMutex();
            ~StdMutex();
            void Enter();
            void Leave();
            bool TryEnter();
            
#line 29
            static StdMutex *Create();
        };
        
        struct StdSharedMutex
        {
#line 33
            StdSharedMutex();
            ~StdSharedMutex();
#line 37
            void EnterRead();
#line 35
            void EnterWrite();
#line 38
            void LeaveRead();
#line 36
            void LeaveWrite();
            
#line 39
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
#line 92
        typedef Native::StdMutex Std;
        
#line 93
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
#line 115
        typedef Native::StdSharedMutex Std;
        
#line 116
        Container::One < Std > m;
        
    public:
        inline RWMutex();
        void Create();
#line 123
        inline void EnterRead();
#line 121
        inline void EnterWrite();
#line 124
        inline void LeaveRead();
#line 122
        inline void LeaveWrite();
    };
    
    class RWMutexReadLocker
    {
#line 129
        RWMutex& m;
        
    public:
#line 131
        RWMutexReadLocker(RWMutex& m);
        inline ~RWMutexReadLocker();
    };
    
    class RWMutexWriteLocker
    {
#line 136
        RWMutex& m;
        
    public:
#line 138
        RWMutexWriteLocker(RWMutex& m);
        inline ~RWMutexWriteLocker();
    };
    
    struct RunningFlag
    {
#line 358
        int sleep_time;
        bool running;
        Lang::AtomicInt workers_running;
        
        RunningFlag();
#line 367
        void DecreaseRunning();
#line 366
        inline void IncreaseRunning();
#line 368
        inline bool IsRunning() const;
#line 365
        inline void SetNotRunning();
#line 363
        void Start(int count);
        void Stop();
#line 369
        inline void Wait();
    };
    
    class RunningFlagSingle
    {
#line 345
        bool running;
#line 345
        bool stopped;
        
    public:
        RunningFlagSingle();
        inline bool IsRunning() const;
#line 351
        inline void SetNotRunning();
#line 350
        inline void SetStopped();
#line 352
        inline void Start();
        void Stop();
    };
    
    class Thread
    {
#line 48
        typedef Native::StdThread Std;
        
#line 49
        Container::One < Std > t;
        Indirect::Callback cb;
        
    public:
#line 56
        inline Thread();
        inline ~Thread();
#line 80
        inline void Detach();
#line 59
        inline void ExecuteCallbackOnly();
#line 71
        void Run(Indirect::Callback cb);
#line 79
        inline void Wait();
        
    public:
        inline static bool IsShutdownThreads();
#line 61
        inline static void NativeCallback(void *arg);
#line 84
        static void ShutdownAndWaitThreads();
#line 83
        inline static void ShutdownThreads(bool b = true);
#line 63
        static void Start(Indirect::Callback cb);
        
#line 52
        inline static bool& shutdown();
        inline static Lang::AtomicInt& thrd_count();
    };
    
    class TimeCallback
    {
#line 332
        Lang::byte dummy;
        
    public:
#line 323
        inline ~TimeCallback();
#line 327
        inline void Kill();
#line 329
        inline void KillPost(Indirect::Callback cb);
#line 328
        inline void KillSet(int delay, Indirect::Callback cb);
#line 326
        inline void Post(Indirect::Callback cb);
#line 325
        inline void Set(int delay, Indirect::Callback cb);
    };
    
    struct TimeCallbackItem
    {
#line 154
        void *id;
        Indirect::Callback cb;
        Lang::uint32 ticks;
        Lang::uint32 delay;
        bool is_periodical;
        Lang::byte epoch;
    };
    
    class TimelineEnv
    {
#line 163
        Container::Array < TimeCallbackItem > cb;
        Container::Vector < int > remlist;
        Lang::uint32 global_ticks;
        Mutex m;
        
    public:
#line 171
        inline TimelineEnv();
#line 300
        void AddGlobalTicks(Lang::uint32 ticks);
#line 245
        bool ExistsTimeCallback(void *id);
#line 178
        inline Lang::uint32 GetGlobalTicks();
#line 176
        Lang::dword GetTimeClick();
#line 229
        void KillTimeCallback(void *id);
#line 173
        void SetTimeCallback(int delay_ms, Indirect::Callback cb, void *id = 0);
        
#line 286
        void DecreaseTimeCallbackEpoch();
#line 256
        void ExecuteTimeCallback();
    };
};

namespace Concurrency
{
#line 181
    inline TimelineEnv& GetTimelineEnv()
    {
#line 181
        static TimelineEnv e;
#line 181
        return e;
    };
    
#line 185
    inline void PostCallback(Indirect::Callback cb, void *id)
    {
#line 186
        TLEnv().SetTimeCallback(1, cb, id);
    };
    
#line 182
    inline TimelineEnv& TLEnv()
    {
#line 182
        return GetTimelineEnv();
    };
    
#line 96
    inline Mutex::Mutex()
    {
#line 96
        Create();
    };
    
#line 97
    inline Mutex::~Mutex() {};
    
    inline void Mutex::Enter()
    {
#line 99
        m -> Enter();
    };
    
#line 100
    inline void Mutex::Leave()
    {
#line 100
        m -> Leave();
    };
    
#line 101
    inline bool Mutex::TryEnter()
    {
#line 101
        return m -> TryEnter();
    };
    
#line 110
    inline MutexLocker::~MutexLocker()
    {
#line 110
        m.Leave();
    };
    
#line 119
    inline RWMutex::RWMutex()
    {
#line 119
        Create();
    };
    
#line 123
    inline void RWMutex::EnterRead()
    {
#line 123
        m -> EnterRead();
    };
    
#line 121
    inline void RWMutex::EnterWrite()
    {
#line 121
        m -> EnterWrite();
    };
    
    inline void RWMutex::LeaveRead()
    {
#line 124
        m -> LeaveRead();
    };
    
#line 122
    inline void RWMutex::LeaveWrite()
    {
#line 122
        m -> LeaveWrite();
    };
    
#line 132
    inline RWMutexReadLocker::~RWMutexReadLocker()
    {
#line 132
        m.LeaveRead();
    };
    
#line 139
    inline RWMutexWriteLocker::~RWMutexWriteLocker()
    {
#line 139
        m.LeaveWrite();
    };
    
#line 366
    inline void RunningFlag::IncreaseRunning()
    {
#line 366
        workers_running ++ ;
    };
    
#line 368
    inline bool RunningFlag::IsRunning() const
    {
#line 368
        return running;
    };
    
#line 365
    inline void RunningFlag::SetNotRunning()
    {
#line 365
        running = false;
    };
    
#line 369
    inline void RunningFlag::Wait()
    {
#line 369
        while ((int) workers_running != 0)
#line 369
            Native::Sleep(100);
    };
    
#line 349
    inline bool RunningFlagSingle::IsRunning() const
    {
#line 349
        return running;
    };
    
#line 351
    inline void RunningFlagSingle::SetNotRunning()
    {
#line 351
        running = false;
    };
    
#line 350
    inline void RunningFlagSingle::SetStopped()
    {
#line 350
        stopped = true;
    };
    
#line 352
    inline void RunningFlagSingle::Start()
    {
#line 352
        running = true;
#line 352
        stopped = false;
    };
    
#line 56
    inline Thread::Thread()
    {
#line 56
        thrd_count()++ ;
    };
    
#line 57
    inline Thread::~Thread()
    {
#line 57
        thrd_count()-- ;
    };
    
#line 80
    inline void Thread::Detach()
    {
#line 80
        if (t)
#line 80
            t -> Detach();
    };
    
#line 59
    inline void Thread::ExecuteCallbackOnly()
    {
#line 59
        cb.Execute();
    };
    
#line 82
    inline bool Thread::IsShutdownThreads()
    {
#line 82
        return shutdown();
    };
    
#line 61
    inline void Thread::NativeCallback(void *arg)
    {
#line 61
        ((Thread * ) arg)-> ExecuteCallbackOnly();
    };
    
#line 83
    inline void Thread::ShutdownThreads(bool b)
    {
#line 83
        shutdown() = b;
    };
    
#line 79
    inline void Thread::Wait()
    {
#line 79
        if (t)
#line 79
            t -> Wait();
    };
    
#line 52
    inline bool& Thread::shutdown()
    {
#line 52
        static bool b;
#line 52
        return b;
    };
    
#line 53
    inline Lang::AtomicInt& Thread::thrd_count()
    {
#line 53
        static Lang::AtomicInt a;
#line 53
        return a;
    };
    
#line 323
    inline TimeCallback::~TimeCallback()
    {
#line 323
        Kill();
#line 323
        (void) dummy;
    };
    
#line 327
    inline void TimeCallback::Kill()
    {
#line 327
        TLEnv().KillTimeCallback(this);
    };
    
#line 329
    inline void TimeCallback::KillPost(Indirect::Callback cb)
    {
#line 329
        Kill();
#line 329
        Post(cb);
    };
    
#line 328
    inline void TimeCallback::KillSet(int delay, Indirect::Callback cb)
    {
#line 328
        Kill();
#line 328
        Set(delay, cb);
    };
    
#line 326
    inline void TimeCallback::Post(Indirect::Callback cb)
    {
#line 326
        PostCallback(cb, this);
    };
    
#line 325
    inline void TimeCallback::Set(int delay, Indirect::Callback cb)
    {
#line 325
        TLEnv().SetTimeCallback(delay, cb, this);
    };
    
#line 171
    inline TimelineEnv::TimelineEnv()
    :
        global_ticks(0)
    {};
    
#line 178
    inline Lang::uint32 TimelineEnv::GetGlobalTicks()
    {
#line 178
        return global_ticks;
    };
    
};

#endif
