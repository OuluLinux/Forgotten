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

#ifndef COM_CXX
#define COM_CXX

#include <new>

#ifndef COM_HXX
#include <Com.hxx>
#endif

namespace Com
{
#line 10 "../../src/Com/Environment.fog"
    void Env::Init(int argc, const char **argv)
    {
#line 11
        SetExeFilePath(argv[0]);
        ParseCommandLine(argc, argv);
        ReadComCmdlineArgs();
        RunInitBlocks();
    };
    
};

#endif
