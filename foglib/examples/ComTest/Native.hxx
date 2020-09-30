/*!$@FOG@$!
 *	Generated at Wed Sep 30 12:25:17 2020
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
#line 22 "../../src/Com/Native.fog"
    Lang::uint64 CurrentTime();
#line 20
    Lang::int64 DateSeconds(Lang::uint64 year, Lang::uint64 month, Lang::uint64 day);
#line 26
    void DblStr(double d, char *buf, int buf_size);
    void DblStr(double d, short *buf, int buf_size);
#line 24
    Lang::uint64 MilliSeconds();
#line 23
    Lang::uint64 NanoSeconds();
#line 17
    int SignificantBits(Lang::uint32 x);
    int SignificantBits64(Lang::uint64 x);
#line 21
    Lang::int64 TimeSeconds(Lang::uint64 year, Lang::uint64 month, Lang::uint64 day, Lang::uint64 hour, Lang::uint64 minute, Lang::uint64 second);
#line 30
    const char *Utf16To8(const short *in);
#line 29
    const short *Utf8To16(const char *in);
};

#endif
