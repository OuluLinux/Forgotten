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

#ifndef MAIN_CXX
#define MAIN_CXX

#include <new>

#ifndef MAIN_HXX
#include <Main.hxx>
#endif

namespace Main
{
#line 195 "ComTest.mfog"
    void App::TestShared()
    {
#line 205
        Shared::Ptr < Dumb > s0a;
#line 207
        ;
        {
#line 208
            Shared::Ptr < Dumber > s1a;
            Shared::Ptr < Dumb > s1b;
#line 211
            ;
            ;
            s1b = Shared::Ptr < Dumb > ().WrapObject(new Dumb);
#line 215
            ;
            s1a = s1b.As < Dumber > ();
#line 218
            ;
            {
                Shared::Ptr < Dumber > s2;
#line 222
                ;
#line 222
                s2 = s1a;
#line 224
                ;
#line 224
                s0a = s2.As < Dumb > ();
#line 226
                ;
            }
            ;
        }
        ;
    };
    
#line 188
    App::Dumber::~Dumber()
    {
#line 188
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
    
#line 29 "ComTest.mfog"
    App::VirtualBase::~VirtualBase() {};
    
};

#endif
