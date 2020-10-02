#ifndef MAIN_CXX
#define MAIN_CXX

#include <new>

#ifndef MAIN_HXX
#include <Main.hxx>
#endif

namespace Main
{
#line 227 "ComTest.mfog"
    void App::TestShared()
    {
#line 237
        Shared::Ptr < Dumb > s0a;
#line 239
        ;
        {
#line 240
            Shared::Ptr < Dumber > s1a;
            Shared::Ptr < Dumb > s1b;
#line 243
            ;
            ;
            s1b = Shared::Ptr < Dumb > ().WrapObject(new Dumb);
#line 247
            ;
            s1a = s1b.As < Dumber > ();
#line 250
            ;
            {
                Shared::Ptr < Dumber > s2;
#line 254
                ;
#line 254
                s2 = s1a;
#line 256
                ;
#line 256
                s0a = s2.As < Dumb > ();
#line 258
                ;
            }
            ;
        }
        ;
    };
    
#line 220
    App::Dumber::~Dumber()
    {
#line 220
        ;
    };
    
#line 73 "../../src/Com/Meta.fog"
    App::SomeRefTuple2::SomeRefTuple2(int& a, double& b)
    :
        a(a),
        b(b)
    {};
    
#line 74
    Text::String App::SomeRefTuple2::AsString() const
    {
#line 74
        return Text::ToString(a) + ", " + Text::ToString(b);
    };
    
#line 54
    Text::String App::SomeTuple2::AsString() const
    {
#line 54
        return Text::ToString(a) + ", " + Text::ToString(b);
    };
    
#line 29 "ComTest.mfog"
    App::VirtualBase::~VirtualBase() {};
    
};

#endif
