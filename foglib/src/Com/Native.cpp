#include "Com.h"

namespace Native {
using namespace Com;


int SignificantBits(dword x) {
	// basically log2(x) + 1 except that for 0 this is 0, number of significant bits of x
#ifdef COMPILER_MSC
	DWORD index;
	return _BitScanReverse(&index, x) ? index + 1 : 0;
#else
	return x ? 32 - __builtin_clz(x) : 0;
#endif
}


int SignificantBits64(uint64 x) {
	static_assert(sizeof(uint64) == 8, "Expecting 8-byte uint64");
	
	// basically log2(x) + 1 except that for 0 this is 0, number of significant bits of x
#ifdef COMPILER_MSC
#ifdef CPU_64
	DWORD index;
	return _BitScanReverse64(&index, x) ? index + 1 : 0;
#else
	if (x & 0xffffffff00000000)
		return SignificantBits(HIDWORD(x)) + 32;
	else
		return SignificantBits((DWORD)x);
#endif
#else
	return x ? 64 - __builtin_clzl(x) : 0;
#endif
}










static int s_month[] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

static int s_month_off[] = {
	  0,  31,  59,  90, 120, 151,
	181, 212, 243, 273, 304, 334
};

bool IsLeapYear(int year) {
	return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0);
}

int  GetDaysOfMonth(int m, int y) {
	ASSERT(m >= 1 && m <= 12);
	return s_month[m - 1] + (m == 2) * IsLeapYear(y);
}

int64 DateSeconds(uint64 year, uint64 month, uint64 day) {
	int64 y400 = (year / 400 ) - 2;
	int64 ym = year - y400 * 400;
	return y400 * (400 * 365 + 100 - 3) +
	        ym * 365 + s_month_off[month - 1] + (day - 1) +
	       (ym - 1) / 4 - (ym - 1) / 100 + (ym - 1) / 400 + 1 +
	       (month > 2) * IsLeapYear(ym);
}

int64 TimeSeconds(uint64 year, uint64 month, uint64 day, uint64 hour, uint64 minute, uint64 second) {
	int64 date = DateSeconds(year, month, day);
	return date * (int64)24 * 3600 + hour * 3600 + minute * 60 + second;
}

int64 CurrentTime() {
	time_t rawtime;
	time(&rawtime);
	
	struct tm t;
	#ifdef flagWIN32
	localtime_s(&t, &rawtime);
	#else
	t = *localtime(&rawtime);
	#endif
	
	return TimeSeconds(
		t.tm_year + 1900, t.tm_mon, t.tm_mday,
		t.tm_hour, t.tm_min, t.tm_sec);
}

uint64 NanoSeconds() {
	auto p2 = std::chrono::high_resolution_clock::now();
	return std::chrono::duration_cast<std::chrono::microseconds>(p2.time_since_epoch()).count();
}

uint64 MilliSeconds() {
	auto p2 = std::chrono::steady_clock::now();
	return (int)std::chrono::duration_cast<std::chrono::milliseconds>(p2.time_since_epoch()).count();
}




void DblStr(double d, char* buf, int buf_size) {
	snprintf(buf, buf_size, "%g", d);
}

void DblStr(double d, short* buf, int buf_size) {
	char tmp[50];
	snprintf(tmp, 50, "%g", d);
	int len = std::min(50, buf_size);
	char* it = tmp;
	char* end = it + len;
	while (it != end)
		*buf++ = *it++;
}



typedef std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> UnicodeConverter;

inline UnicodeConverter& GetUnicodeConverter() {thread_local static UnicodeConverter conv; return conv;}

const short* Utf8To16(const char* in) {
	thread_local static std::wstring ws = GetUnicodeConverter().from_bytes(std::string(in));
	thread_local static std::vector<short> v;
	v.resize(ws.size());
	int i = 0;
	for(wchar_t w : ws)
		v[i++] = w;
	v[i] = 0;
	return v.data();
}

const char* Utf16To8(const short* in) {
	thread_local static std::vector<wchar_t> v;
	int len = Lang::StringLength(in, 10000000);
	v.resize(len + 1);
	for(wchar_t& s : v) s = *in++;
	v[len] = 0;
	thread_local static std::string s = GetUnicodeConverter().to_bytes(std::wstring(v.data()));
	return s.c_str();
}




}
