/*!$@FOG@$!
 *	Generated at Thu Oct  1 09:26:12 2020
 *
 *	by fog 0.1.a of 12:17:36 Sep 29 2020
 *
 *	from
 *		../../src/Com/Abstract.fog
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Container.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Lang.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Meta.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/Prim.fog
 *		../../src/Com/Random.fog
 *		../../src/Com/Shared.fog
 *		../../src/Com/Stream.fog
 *		../../src/Com/Text.fog
 *		../../src/Com/Util.fog
 *		ComTest.mfog
 */

#ifndef NATIVE_HXX
#define NATIVE_HXX

#include <new>

#ifndef LANG_HXX
#include <Lang.hxx>
#endif

namespace Native
{
#line 24 "../../src/Com/Native.fog"
    Lang::uint64 CurrentTime();
#line 22
    Lang::int64 DateSeconds(Lang::uint64 year, Lang::uint64 month, Lang::uint64 day);
#line 28
    void DblStr(double d, char *buf, int buf_size);
    void DblStr(double d, short *buf, int buf_size);
};

namespace Native {
struct FILE;
}

namespace Native
{
#line 34
    void FileClose(FILE *s);
#line 42
    void FileFlush(FILE *s);
#line 35
    void FileOpen(FILE **s, const char *path, bool rw, bool append);
#line 38
    int FileRead(void *buf, int size, int nmemb, FILE *s);
#line 40
    void FileSeekEnd(FILE *s, int offset = 0);
#line 39
    void FileSeekSet(FILE *s, int offset);
#line 36
    int FileTell(FILE *s);
    int FileWrite(const void *buf, int size, int nmemb, FILE *s);
#line 41
    bool IsFileEnd(FILE *s);
#line 26
    Lang::uint64 MilliSeconds();
#line 25
    Lang::uint64 NanoSeconds();
#line 19
    int SignificantBits(Lang::uint32 x);
    int SignificantBits64(Lang::uint64 x);
#line 23
    Lang::int64 TimeSeconds(Lang::uint64 year, Lang::uint64 month, Lang::uint64 day, Lang::uint64 hour, Lang::uint64 minute, Lang::uint64 second);
#line 32
    const char *Utf16To8(const short *in);
#line 31
    const short *Utf8To16(const char *in);
};

#endif
