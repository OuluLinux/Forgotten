#include "Com.h"

NAMESPACE_SDK_BEGIN

uint64 NativeNanoSeconds() {
	auto p2 = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::microseconds>(p2.time_since_epoch()).count();
}

uint64 NativeMilliSeconds() {
	auto p2 = std::chrono::steady_clock::now();
	return (int)std::chrono::duration_cast<std::chrono::milliseconds>(p2.time_since_epoch()).count();
}


NAMESPACE_SDK_END
