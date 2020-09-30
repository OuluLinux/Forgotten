/*!$@FOG@$!
 *	Generated at Wed Sep 30 06:41:13 2020
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
 *		../../src/Com/Text.fog
 *		/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog
 */

#ifndef MAIN_CXX
#define MAIN_CXX

#include <new>

#ifndef MAIN_HXX
#include <Main.hxx>
#endif

namespace Main
{
#line 73 "../../src/Com/Meta.fog"
    App::SomeRefTuple2::SomeRefTuple2(int& a, double& b)
    :
        a(a),
        b(b)
    {};
    
#line 74
    Text::String App::SomeRefTuple2::ToString() const
    {
#line 74
        return Text::ToString(a) + ", " + Text::ToString(b);
    };
    
#line 54
    Text::String App::SomeTuple2::ToString() const
    {
#line 54
        return Text::ToString(a) + ", " + Text::ToString(b);
    };
    
#line 28 "/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog"
    App::VirtualBase::~VirtualBase() {};
    
};

#endif
