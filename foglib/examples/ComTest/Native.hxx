#ifndef NATIVE_HXX
#define NATIVE_HXX

#include <new>

#ifndef LANG_HXX
#include <Lang.hxx>
#endif

namespace Native
{
#line 62 "../../src/Com/Native.fog"
    void CreateDirectory(const char *path);
#line 27
    Lang::uint64 CurrentTime();
#line 25
    Lang::int64 DateSeconds(Lang::uint64 year, Lang::uint64 month, Lang::uint64 day);
#line 41
    void DblStr(double d, char *buf, int buf_size);
    void DblStr(double d, short *buf, int buf_size);
#line 75
    Lang::int64 Delay(Lang::int64 cpu_ticks);
#line 63
    void DeleteFile(const char *path);
#line 60
    bool DirExists(const char *path);
};

namespace Native {
struct FILE;
}

namespace Native
{
#line 47
    void FileClose(FILE *s);
#line 55
    void FileFlush(FILE *s);
#line 48
    void FileOpen(FILE **s, const char *path, bool rw, bool append);
#line 51
    int FileRead(void *buf, int size, int nmemb, FILE *s);
#line 53
    void FileSeekEnd(FILE *s, int offset = 0);
#line 52
    void FileSeekSet(FILE *s, int offset);
#line 49
    int FileTell(FILE *s);
    int FileWrite(const void *buf, int size, int nmemb, FILE *s);
#line 74
    Lang::int64 GetCpuTicks();
#line 65
    void GetDirFiles(const char *dir, void(*add_path)(const char *, void *), void *arg);
#line 58
    const char *GetEnv(const char *id);
#line 57
    const char *GetHomeDir();
#line 20
    FILE *GetStdErr();
#line 19
    FILE *GetStdIn();
#line 18
    FILE *GetStdOut();
#line 30
    void GetSysTime(short& year, Lang::byte& mon, Lang::byte& day, Lang::byte& hour, Lang::byte& min, Lang::byte& sec);
#line 69
    int HammingDistance32(int count, const Lang::dword *a, const Lang::dword *b);
    int HammingDistance64(int count, const Lang::uint64 *a, const Lang::uint64 *b);
#line 54
    bool IsFileEnd(FILE *s);
#line 73
    bool IsFinite(double f);
#line 72
    bool IsFinite(float f);
#line 29
    Lang::uint64 MilliSeconds();
#line 28
    Lang::uint64 NanoSeconds();
#line 61
    bool PathExists(const char *path);
#line 68
    int PopCount32(Lang::dword i);
#line 67
    int PopCount64(Lang::uint64 i);
#line 64
    void RenameFile(const char *oldpath, const char *newpath);
#line 22
    int SignificantBits(Lang::uint32 x);
    int SignificantBits64(Lang::uint64 x);
#line 26
    Lang::int64 TimeSeconds(Lang::uint64 year, Lang::uint64 month, Lang::uint64 day, Lang::uint64 hour, Lang::uint64 minute, Lang::uint64 second);
#line 45
    const char *Utf16To8(const short *in);
#line 44
    const short *Utf8To16(const char *in);
    
    struct HighResTimePoint
    {
#line 34
        int Elapsed() const;
        double ElapsedSeconds() const;
#line 33
        void Reset();
#line 36
        int ResetElapsed();
        double ResetElapsedSeconds();
        
#line 38
        static HighResTimePoint *Create();
    };
    
    struct Trans8x16
    {
#line 84
        void TransFrom16x8();
        void Zero();
        
        union
        {
        public:
#line 79
            Lang::uint16 u16[8];
#line 81
            Lang::uint64 u64[2];
#line 80
            Lang::uint8 u8[16];
        };
    };
};

#endif
