/*!$@FOG@$!
 *	Generated at Tue Sep 29 13:48:51 2020
 *
 *	by fog 0.1.a of 12:17:36 Sep 29 2020
 *
 *	from
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Defs.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Lang.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Meta.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/Shared.fog
 *		../../src/Com/String.fog
 *		../../src/Com/Vector.fog
 *		ComTest.mfog
 */

#ifndef GLOBAL_CXX
#define GLOBAL_CXX

#include <new>

#ifndef GLOBAL_HXX
#include <Global.hxx>
#endif

extern "C"
{
#line 79 "../../src/Com/Meta.fog"
    int main(int argc, const char **argv)
    {
#line 80
        Com::Env & e = Com::Env::Local();
        e.Init(argc, argv);
        Com::Tester::App().Run();
        return e.Deinit();
    };
    
};

#endif
