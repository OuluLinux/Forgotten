#include "Com.h"

namespace C {
	

int StringLength(const char* c, int max_len) {
	return strnlen(c, max_len);
}

int StringLength(const short* c, int max_len) {
	ASSERT(c);
	if (!c) return 0;
	int count = 0;
	if (max_len < 0) {
		while (*c) {
			count++;
			c++;
		}
		return count;
	}
	else {
		while (max_len > 0 && *c) {
			count++;
			c++;
			max_len--;
		}
		return count;
	}
}


struct AtomicFlag {
    std::atomic_flag locked = ATOMIC_FLAG_INIT;
    
	void Enter() {
		while (locked.test_and_set(std::memory_order_acquire)) { ; }
	}
	
	void Leave() {
		locked.clear(std::memory_order_release);
	}
	
	bool TryEnter() {
		return !locked.test_and_set(std::memory_order_acquire);
	}
};




AtomicBool::AtomicBool() {value = 0;}
AtomicBool::AtomicBool(bool b) {value = b;}
AtomicBool::AtomicBool(const AtomicBool& ai) {value = (bool)ai.value;}
AtomicBool::operator bool() {return value;}
bool AtomicBool::operator= (bool b) {value = b; return b;}

AtomicInt::AtomicInt() {value = 0;}
AtomicInt::AtomicInt(int i) {value = i;}
AtomicInt::AtomicInt(const AtomicInt& ai) {value = (int)ai.value;}
AtomicInt::operator int() const {return value;}
int AtomicInt::operator = (int i) {value = i; return i;}
int AtomicInt::operator++() {return ++value;}
int AtomicInt::operator--() {return --value;}
int AtomicInt::operator++(int) {return value++;}
int AtomicInt::operator--(int) {return value--;}




ConditionalVar::ConditionalVar() {}

void ConditionalVar::Wait() {
    std::unique_lock<std::mutex> lk(m);
    cv.wait(lk, [this] {return ready;});
    lk.unlock();
    cv.notify_one();
}

void ConditionalVar::SetReady(bool b) {
	ready = b;
	if (ready)
		cv.notify_one();
}

bool ConditionalVar::IsReady() const {
	return ready;
}


}
