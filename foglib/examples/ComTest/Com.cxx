/*!$@FOG@$!
 *	Generated at Sat Sep 26 14:43:13 2020
 *
 *	by fog 0.1.a of 08:09:34 Sep 23 2020
 *
 *	from
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Concurrency.fog
 *		../../src/Com/Defs.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Math.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/Stream.fog
 *		/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog
 */

#ifndef COM_CXX
#define COM_CXX

#ifndef COM_HXX
#include <Com.hxx>
#endif

namespace Com
{
#line 13 "../../src/Com/Hash.fog"
    CombineHash::CombineHash(int v0, int v1)
    :
        hash(123456789)
    {
#line 13
        Put(v0);
#line 13
        Put(v1);
    };
    
#line 18
    CombineHash& CombineHash::Put(int value)
    {
#line 18
        hash = ((hash << 5) + hash) + value;
#line 18
        return *this;
    };
    
#line 19
    CombineHash& CombineHash::Put64(int64 value)
    {
#line 19
        Put((int)(value >> 32));
#line 19
        Put((int)(value & 0xFFFFFFFFULL));
#line 19
        return *this;
    };
    
#line 10 "/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog"
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
        {
#line 19
            if (!(p == Null))
            {
#line 19
                Break("Assertion failed: p == Null");
            }
        }
#line 20
        ;
        {
#line 21
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
        CombineHash ch;
        ch.Put(777999777).Put(123).Put64(0xF0F0F0F0F0F0F0F0);
        dword hash = ch;
        {
#line 27
            if (!(hash == 1894504625))
            {
#line 27
                Break("Assertion failed: hash == 1894504625");
            }
        }
#line 28
        ;
#line 28
        int a = 0;
        int b = 1;
        {
#line 30
            if (!(min(a, b) < max(a, b)))
            {
#line 30
                Break("Assertion failed: min(a, b) < max(a, b)");
            }
        }
#line 31
        ;
    };
    
};
#line 10 "../../src/Com/Environment.fog"
void Env::Init(int argc, const char **argv)
{
#line 11
    SetExeFilePath(argv[0]);
    SeedRandom();
    ParseCommandLine(argc, argv);
    ReadComCmdlineArgs();
    RunInitBlocks();
};

#endif
