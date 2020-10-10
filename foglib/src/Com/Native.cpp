#include "Com.h"

namespace Native {
using namespace Com;

FILE* GetStdOut()	{return stdout;}
FILE* GetStdIn()	{return stdin;}
FILE* GetStdErr()	{return stderr;}

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

void GetSysTime(short& year, byte& mon, byte& day, byte& hour, byte& min, byte& sec) {
	time_t rawtime;
	
	time(&rawtime);
	
	struct tm tmp;
	#ifdef flagWIN32
	localtime_s(&tmp, &rawtime);
	#else
	tmp = *localtime(&rawtime);
	#endif
	
	year	= 1900 + tmp.tm_year;
	mon		= 1 + tmp.tm_mon;
	day		= tmp.tm_mday;
	hour	= tmp.tm_hour;
	min		= tmp.tm_min;
	sec		= tmp.tm_sec;
}

struct HighResTimePoint {
	high_resolution_clock::time_point start;
	
	void Reset();
	int Elapsed() const;
	double ElapsedSeconds() const;
	int ResetElapsed();
	double ResetElapsedSeconds();
	static HighResTimePoint* Create();
};

void HighResTimePoint::Reset() {
	start = high_resolution_clock::now();
}

int HighResTimePoint::Elapsed() const {
	return (int)(ElapsedSeconds() * 1000);
}

double HighResTimePoint::ElapsedSeconds() const {
	std::chrono::high_resolution_clock::time_point stop = high_resolution_clock::now();
	duration<double> time_span = duration_cast<duration<double> >(stop - start);
	return time_span.count();
}

int HighResTimePoint::ResetElapsed() {
	return (int)(ResetElapsedSeconds() * 1000);
}

double HighResTimePoint::ResetElapsedSeconds() {
		std::chrono::high_resolution_clock::time_point stop = high_resolution_clock::now();
		duration<double> time_span = duration_cast<duration<double> >(stop - start);
		start = stop;
		return time_span.count();
}

HighResTimePoint* HighResTimePoint::Create() {
	return new HighResTimePoint();
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
	thread_local static std::string s;
	
	int len = Lang::StringLength(in, 10000000);
	v.resize(len + 1);
	for(wchar_t& w : v)
		w = *in++;
	v[len] = 0;
	std::wstring ws(v.data());
	s = GetUnicodeConverter().to_bytes(ws);
	return s.c_str();
}



const char* GetHomeDir() {
	#ifdef flagPOSIX
	struct passwd *pw = getpwuid(getuid());
	const char *homedir = pw->pw_dir;
	return homedir;
	#else
	char homedir[2048];
	getenv_s(0, homedir, 2048, "USERPROFILE");
	return homedir;
	#endif
}


bool DirExists(const char* path) {
	DIR* d = opendir(path);
	if (d) {
	    closedir(d);
	    return true;
	}
	return false;
}

bool PathExists(const char* path) {
	#ifdef flagWIN32
	#ifndef flagUWP
	return PathFileExistsA(path);
	#else
	struct stat stat_info = {0};
	if (stat(path, &stat_info) != 0)
		return false;
	return true;
	#endif
	#else
	return access( path, F_OK ) != -1;
	#endif
}

void CreateDirectory(const char* path) {
	mkdir(path, 0700);
}

void DeleteFile(const char* path) {
	unlink(path);
}

void RenameFile(const char* oldpath, const char* newpath) {
	rename(oldpath, newpath);
}


const char* GetEnv(const char* id) {
	#ifdef flagWIN32
	size_t len = 0;
	char homedir[2048];
	getenv_s(&len, &homedir[0], 2048, id);
	return String(homedir, len);
	#else
	return getenv(id);
	#endif
}

bool is_dot_string(const char* s) {
	int len = strlen(s);
	if (!len) return false;
	if (len == 1 && !memcmp(s, ".", 1)) return true;
	if (len == 2 && !memcmp(s, "..", 2)) return true;
	return false;
}

void GetDirFiles(const char* dir, void(*add_path)(const char*, void*), void* arg) {
	#ifdef flagPOSIX
	DIR* dirp = opendir(dir);
    struct dirent * dp;
    while ((dp = readdir(dirp)) != NULL) {
        if (!is_dot_string(dp->d_name))
            add_path(dp->d_name, arg);
    }
    closedir(dirp);
    #endif
    
    #ifdef flagWIN32
    std::string pattern = std::string(dir) + "\\*";
    WIN32_FIND_DATA data;
    HANDLE hFind;
    if ((hFind = FindFirstFile(pattern.c_str(), &data)) != INVALID_HANDLE_VALUE) {
        do {
            if (!IsDotString(data.cFileName))
                add_path(data.cFileName, arg);
        }
        while (FindNextFile(hFind, &data) != 0);
        FindClose(hFind);
    }
    #endif
}






int PopCount64(uint64 i) {
	#ifdef flagMSC
	#if CPU_64
	return (int)__popcnt64(i);
	#elif CPU_32
	return __popcnt(i) + __popcnt(i >> 32);
	#endif
	#else
	return (int)__builtin_popcountll(i);
	#endif
}

int PopCount32(dword i) {
	#ifdef flagMSC
	return (int)__popcnt64(i);
	#else
	return (int)__builtin_popcountl(i);
	#endif
}

int HammingDistance32(int count, const dword* a, const dword* b) {
	if (count <= 0) return 0;
	const dword* end = a + count;
	int distance = 0;
	while(a != end)
		distance += PopCount32(*a++ ^ *b++);
	return distance;
}

int HammingDistance64(int count, const uint64* a, const uint64* b) {
	if (count <= 0) return 0;
	const uint64* end = a + count;
	int distance = 0;
	while(a != end)
		distance += PopCount64(*a++ ^ *b++);
	return distance;
}

bool IsFinite(float f) {
	return ::isfinite(f);
}

bool IsFinite(double f) {
	return ::isfinite(f);
}

int64 GetCpuTicks() {
	#ifdef flagWIN32
    return __rdtsc();
    #else
    return clock();
    #endif
}

int64 Delay(int64 cpu_ticks) {
	int64 end = GetCpuTicks() + cpu_ticks;
	int64 iters = 0;
	while (GetCpuTicks() < end)
		iters++;
	return iters;
}


struct Trans8x16 {
	union {
		uint16 u16[8];
		uint8 u8[16];
		__m128i m;
		uint64 u64[2];
	};
	
	void TransFrom16x8();
	void Zero();
};

void Trans8x16::TransFrom16x8() {
	__m128i x = m;
    for (int i = 0; i < 8; ++i) {
        u16[7-i] = _mm_movemask_epi8(x);
        x = _mm_slli_epi64(x,1);
    }
}

void Trans8x16::Zero() {u64[0] = 0; u64[1] = 0;}

}
