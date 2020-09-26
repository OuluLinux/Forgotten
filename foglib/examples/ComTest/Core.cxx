/*!$@FOG@$!
 *	Generated at Sat Sep 26 09:29:30 2020
 *
 *	by fog 0.1.a of 08:09:34 Sep 23 2020
 *
 *	from
 *		../../src/Core/Concurrency.fog
 *		../../src/Core/Core.fog
 *		../../src/Core/Defs.fog
 *		../../src/Core/Environment.fog
 *		../../src/Core/Macros.fog
 *		../../src/Core/Math.fog
 *		../../src/Core/Native.fog
 *		../../src/Core/Stream.fog
 *		/home/sblo/Forgotten/foglib/examples/CoreTest/CoreTest.mfog
 */

#ifndef CORE_CXX
#define CORE_CXX

#ifndef CORE_HXX
#include <Core.hxx>
#endif

namespace Core
{
#line 10 "/home/sblo/Forgotten/foglib/examples/CoreTest/CoreTest.mfog"
    void Tester::Run()
    {
#line 15
        uint64 v = 4294967295U;
        {
#line 16
            if (!(sizeof (v) == 8))
            {
#line 16
                Break("Assertion failed: sizeof(v) == 8");
            }
        }
#line 17
        ;
        VOID_PTR p;
        p = Null;
        {
            if (!(SignificantBits(0x8000) == 16))
            {
#line 21
                Break("Assertion failed: SignificantBits(0x8000) == 16");
            }
        }
#line 22
        ;
        {
#line 22
            if (!(SignificantBits64(0x8000) == 16))
            {
#line 22
                Break("Assertion failed: SignificantBits64(0x8000) == 16");
            }
        }
#line 23
        ;
    };
    
};
#line 10 "../../src/Core/Environment.fog"
void Env::Init(int argc, const char **argv)
{
#line 11
    SetExeFilePath(argv[0]);
    SeedRandom();
    ParseCommandLine(argc, argv);
    ReadCoreCmdlineArgs();
    RunInitBlocks();
};

#endif
