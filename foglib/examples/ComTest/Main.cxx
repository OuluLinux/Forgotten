/*!$@FOG@$!
 *	Generated at Thu Oct  1 09:45:53 2020
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
 *		../../src/Com/Util.fog
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
#line 208 "/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog"
    void App::TestShared()
    {
#line 218
        Shared::Ptr < Dumb > s0a;
#line 220
        ;
        {
#line 221
            Shared::Ptr < Dumber > s1a;
            Shared::Ptr < Dumb > s1b;
#line 224
            ;
            ;
            s1b = Shared::Ptr < Dumb > ().WrapObject(new Dumb);
#line 228
            ;
            s1a = s1b.As < Dumber > ();
#line 231
            ;
            {
                Shared::Ptr < Dumber > s2;
#line 235
                ;
#line 235
                s2 = s1a;
#line 237
                ;
#line 237
                s0a = s2.As < Dumb > ();
#line 239
                ;
            }
            ;
        }
        ;
    };
    
#line 201
    App::Dumber::~Dumber()
    {
#line 201
        ;
    };
    
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
    
#line 29 "/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog"
    App::VirtualBase::~VirtualBase() {};
    
};

#endif
