/*!$@FOG@$!
 *	Generated at Mon Sep 28 10:34:35 2020
 *
 *	by fog 0.1.a of 08:56:34 Sep 28 2020
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
