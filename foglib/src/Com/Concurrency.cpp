#include "Com.h"

namespace Concurrency::Native {

int CPU_Cores() {return std::thread::hardware_concurrency();}

void Sleep(int ms) {
#if defined(flagWIN32)
	::Sleep(ms);
#elif defined(flagPOSIX)
	usleep(ms * 1000);
#endif
}

struct StdThread {
	std::thread* t = NULL;
	
	typedef void(*Fn)(void*);
	StdThread();
	~StdThread();
	void Clear();
	static void Start(Fn fn, void* arg);
	void Run(Fn fn, void* arg);
	void Wait();
	void Detach();
	static StdThread* Create();
};

StdThread::StdThread() {}
StdThread::~StdThread() {Clear();}

void StdThread::Clear() {
	if (t) {
		delete t;
		t = 0;
	}
}

void StdThread::Run(Fn fn, void* arg) {
	Clear();
	t = new std::thread([this, fn, arg]() {
		fn(arg);
		delete t;
		t = 0;
	});
}

void StdThread::Wait() {
	if (t) t->join();
}

void StdThread::Detach() {
	if (t) t->detach();
}

StdThread* StdThread::Create() {return new StdThread();}

void StdThread::Start(Fn fn, void* arg) {
	std::thread* t = new std::thread([t, fn, arg]() {
		fn(arg);
		delete t;
	});
}










struct StdMutex {
	std::mutex m;
	
	StdMutex();
	~StdMutex();
	void Enter();
	void Leave();
	bool TryEnter();
	static StdMutex* Create();
};

StdMutex::StdMutex() {}
StdMutex::~StdMutex() {}
void StdMutex::Enter() {m.lock();}
void StdMutex::Leave() {m.unlock();}
bool StdMutex::TryEnter() {return m.try_lock();}
StdMutex* StdMutex::Create() {return new StdMutex();}





struct StdSharedMutex {
    std::atomic<int> refcount{0};
    
    StdSharedMutex();
    ~StdSharedMutex();
	void EnterWrite();
	void LeaveWrite();
	void EnterRead();
	void LeaveRead();
	static StdSharedMutex* Create();
};

StdSharedMutex::StdSharedMutex() {}
StdSharedMutex::~StdSharedMutex() {}

StdSharedMutex* StdSharedMutex::Create() {return new StdSharedMutex();}

void StdSharedMutex::EnterWrite() {
	int val;
    do {
        val = 0; // Can only take a write lock when refcount == 0
    } while (!refcount.compare_exchange_weak(val, -1, std::memory_order_acquire));
    // can memory_order_relaxed be used if only a single thread takes write locks ?
}

void StdSharedMutex::LeaveWrite() {
	refcount.store(0, std::memory_order_release);
}

void StdSharedMutex::EnterRead() {
	int val;
    do {
        do {
            val = refcount.load(std::memory_order_relaxed);

        } while (val == -1); // spinning until the write lock is released

    } while (!refcount.compare_exchange_weak(val, val+1, std::memory_order_acquire));
}

void StdSharedMutex::LeaveRead() {
	refcount.fetch_sub(1, std::memory_order_relaxed);
}

}
