#include "Com.h"

NAMESPACE_SDK_BEGIN

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

uint64 NativeNanoSeconds() {
	auto p2 = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::microseconds>(p2.time_since_epoch()).count();
}

uint64 NativeMilliSeconds() {
	auto p2 = std::chrono::steady_clock::now();
	return (int)std::chrono::duration_cast<std::chrono::milliseconds>(p2.time_since_epoch()).count();
}


NAMESPACE_SDK_END
