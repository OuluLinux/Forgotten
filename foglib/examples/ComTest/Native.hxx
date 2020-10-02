#ifndef NATIVE_HXX
#define NATIVE_HXX

#include <new>

#ifndef LANG_HXX
#include <Lang.hxx>
#endif

namespace Native
{
#line 52 "../../src/Com/Native.fog"
    void CreateDirectory(const char *path);
#line 27
    Lang::uint64 CurrentTime();
#line 25
    Lang::int64 DateSeconds(Lang::uint64 year, Lang::uint64 month, Lang::uint64 day);
#line 31
    void DblStr(double d, char *buf, int buf_size);
    void DblStr(double d, short *buf, int buf_size);
#line 65
    Lang::int64 Delay(Lang::int64 cpu_ticks);
#line 53
    void DeleteFile(const char *path);
#line 50
    bool DirExists(const char *path);
};

namespace Native {
struct FILE;
}

namespace Native
{
#line 37
    void FileClose(FILE *s);
#line 45
    void FileFlush(FILE *s);
#line 38
    void FileOpen(FILE **s, const char *path, bool rw, bool append);
#line 41
    int FileRead(void *buf, int size, int nmemb, FILE *s);
#line 43
    void FileSeekEnd(FILE *s, int offset = 0);
#line 42
    void FileSeekSet(FILE *s, int offset);
#line 39
    int FileTell(FILE *s);
    int FileWrite(const void *buf, int size, int nmemb, FILE *s);
#line 64
    Lang::int64 GetCpuTicks();
#line 55
    void GetDirFiles(const char *dir, void(*add_path)(const char *, void *), void *arg);
#line 48
    const char *GetEnv(const char *id);
#line 47
    const char *GetHomeDir();
#line 20
    FILE *GetStdErr();
#line 19
    FILE *GetStdIn();
#line 18
    FILE *GetStdOut();
#line 59
    int HammingDistance32(int count, const Lang::dword *a, const Lang::dword *b);
    int HammingDistance64(int count, const Lang::uint64 *a, const Lang::uint64 *b);
#line 44
    bool IsFileEnd(FILE *s);
#line 63
    bool IsFinite(double f);
#line 62
    bool IsFinite(float f);
#line 29
    Lang::uint64 MilliSeconds();
#line 28
    Lang::uint64 NanoSeconds();
#line 51
    bool PathExists(const char *path);
#line 58
    int PopCount32(Lang::dword i);
#line 57
    int PopCount64(Lang::uint64 i);
#line 54
    void RenameFile(const char *oldpath, const char *newpath);
#line 22
    int SignificantBits(Lang::uint32 x);
    int SignificantBits64(Lang::uint64 x);
#line 26
    Lang::int64 TimeSeconds(Lang::uint64 year, Lang::uint64 month, Lang::uint64 day, Lang::uint64 hour, Lang::uint64 minute, Lang::uint64 second);
#line 35
    const char *Utf16To8(const short *in);
#line 34
    const short *Utf8To16(const char *in);
    
    struct Trans8x16
    {
#line 74
        void TransFrom16x8();
        void Zero();
        
        union
        {
        public:
#line 69
            Lang::uint16 u16[8];
#line 71
            Lang::uint64 u64[2];
#line 70
            Lang::uint8 u8[16];
        };
    };
};

#endif
