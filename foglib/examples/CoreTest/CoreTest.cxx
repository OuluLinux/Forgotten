/*!$@FOG@$!
 *	Generated at Sat Sep 26 06:11:06 2020
 *
 *	by fog 0.1.a of 08:09:34 Sep 23 2020
 *
 *	from
 *		../../src/Core/Core.fog
 *		../../src/Core/Defs.fog
 *		../../src/Core/Stream.fog
 *		../../src/Core/String.fog
 *		CoreTest.mfog
 */

#ifndef CORETEST_CXX
#define CORETEST_CXX

#ifndef CORETEST_HXX
#include <CoreTest.hxx>
#endif

#line 14 "CoreTest.mfog"
int CoreTester::Main()
{
#line 15
    String s("test");
    ConstChar * c = s;
    Console::Put("Starting Core-testing\n");
#line 19
    uint64 v;
    {
#line 20
        if (!(sizeof (v) == 8))
        {
#line 20
            Break("Assertion failed: sizeof(v) == 8");
        }
    }
#line 21
    ;
    VOID_PTR p;
    p = Null;
#line 31
    return 0;
};

#endif
