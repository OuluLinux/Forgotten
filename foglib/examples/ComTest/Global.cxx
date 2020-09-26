/*!$@FOG@$!
 *	Generated at Sat Sep 26 10:29:56 2020
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
 *		ComTest.mfog
 */

#ifndef GLOBAL_CXX
#define GLOBAL_CXX

#ifndef GLOBAL_HXX
#include <Global.hxx>
#endif

extern "C"
{
#line 82 "../../src/Com/Macros.fog"
    int main(int argc, const char **argv)
    {
#line 83
        Env & e = Env::Local();
        e.Init(argc, argv);
        Com::Tester().Run();
        return e.Deinit();
    };
    
};

#endif
