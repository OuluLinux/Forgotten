/*!$@FOG@$!
 *	Generated at Sat Sep 26 09:29:26 2020
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
 *		CoreTest.mfog
 */

#ifndef GLOBAL_CXX
#define GLOBAL_CXX

#ifndef GLOBAL_HXX
#include <Global.hxx>
#endif

extern "C"
{
#line 82 "../../src/Core/Macros.fog"
    int main(int argc, const char **argv)
    {
#line 83
        Env & e = Env::Local();
        e.Init(argc, argv);
        Core::Tester().Run();
        return e.Deinit();
    };
    
};

#endif
