#ifndef NATIVE_HXX
#define NATIVE_HXX

#include <new>

#ifndef LANG_HXX
#include <Lang.hxx>
#endif

namespace Native
{
#line 61 "../../src/Com/Native.fog"
    void CreateDirectory(const char *path);
#line 27
    Lang::uint64 CurrentTime();
#line 25
    Lang::int64 DateSeconds(Lang::uint64 year, Lang::uint64 month, Lang::uint64 day);
#line 40
    void DblStr(double d, char *buf, int buf_size);
    void DblStr(double d, short *buf, int buf_size);
#line 74
    Lang::int64 Delay(Lang::int64 cpu_ticks);
#line 62
    void DeleteFile(const char *path);
#line 59
    bool DirExists(const char *path);
};

namespace Native {
struct FILE;
}

namespace Native
{
#line 46
    void FileClose(FILE *s);
#line 54
    void FileFlush(FILE *s);
#line 47
    void FileOpen(FILE **s, const char *path, bool rw, bool append);
#line 50
    int FileRead(void *buf, int size, int nmemb, FILE *s);
#line 52
    void FileSeekEnd(FILE *s, int offset = 0);
#line 51
    void FileSeekSet(FILE *s, int offset);
#line 48
    int FileTell(FILE *s);
    int FileWrite(const void *buf, int size, int nmemb, FILE *s);
#line 73
    Lang::int64 GetCpuTicks();
#line 64
    void GetDirFiles(const char *dir, void(*add_path)(const char *, void *), void *arg);
#line 57
    const char *GetEnv(const char *id);
#line 56
    const char *GetHomeDir();
#line 20
    FILE *GetStdErr();
#line 19
    FILE *GetStdIn();
#line 18
    FILE *GetStdOut();
#line 68
    int HammingDistance32(int count, const Lang::dword *a, const Lang::dword *b);
    int HammingDistance64(int count, const Lang::uint64 *a, const Lang::uint64 *b);
#line 53
    bool IsFileEnd(FILE *s);
#line 72
    bool IsFinite(double f);
#line 71
    bool IsFinite(float f);
#line 29
    Lang::uint64 MilliSeconds();
#line 28
    Lang::uint64 NanoSeconds();
#line 60
    bool PathExists(const char *path);
#line 67
    int PopCount32(Lang::dword i);
#line 66
    int PopCount64(Lang::uint64 i);
#line 63
    void RenameFile(const char *oldpath, const char *newpath);
#line 22
    int SignificantBits(Lang::uint32 x);
    int SignificantBits64(Lang::uint64 x);
#line 26
    Lang::int64 TimeSeconds(Lang::uint64 year, Lang::uint64 month, Lang::uint64 day, Lang::uint64 hour, Lang::uint64 minute, Lang::uint64 second);
#line 44
    const char *Utf16To8(const short *in);
#line 43
    const short *Utf8To16(const char *in);
    
    struct HighResTimePoint
    {
#line 33
        int Elapsed() const;
        double ElapsedSeconds() const;
#line 32
        void Reset();
#line 35
        int ResetElapsed();
        double ResetElapsedSeconds();
        
#line 37
        static HighResTimePoint *Create();
    };
    
    struct Trans8x16
    {
#line 83
        void TransFrom16x8();
        void Zero();
        
        union
        {
        public:
#line 78
            Lang::uint16 u16[8];
#line 80
            Lang::uint64 u64[2];
#line 79
            Lang::uint8 u8[16];
        };
    };
};

#endif
