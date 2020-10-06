#ifndef MAIN_CXX
#define MAIN_CXX

#include <new>

#ifndef MAIN_HXX
#include <Main.hxx>
#endif

namespace Main
{
#line 262 "ComTest.mfog"
    void App::TestShared()
    {
#line 272
        Shared::Ptr < Dumb > s0a;
#line 274
        ;
        {
#line 275
            Shared::Ptr < Dumber > s1a;
            Shared::Ptr < Dumb > s1b;
#line 278
            ;
            ;
            s1b = Shared::Ptr < Dumb > ().WrapObject(new Dumb);
#line 282
            ;
            s1a = s1b.As < Dumber > ();
#line 285
            ;
            {
                Shared::Ptr < Dumber > s2;
#line 289
                ;
#line 289
                s2 = s1a;
#line 291
                ;
#line 291
                s0a = s2.As < Dumb > ();
#line 293
                ;
            }
            ;
        }
        ;
    };
    
#line 255
    App::Dumber::~Dumber()
    {
#line 255
        ;
    };
    
#line 76 "../../src/Com/Meta.fog"
    App::SomeRefTuple2::SomeRefTuple2(int& a, double& b)
    :
        a(a),
        b(b)
    {};
    
#line 77
    Text::String App::SomeRefTuple2::AsString() const
    {
#line 77
        return Text::ToString(a) + ", " + Text::ToString(b);
    };
    
#line 57
    Text::String App::SomeTuple2::AsString() const
    {
#line 57
        return Text::ToString(a) + ", " + Text::ToString(b);
    };
    
#line 32 "ComTest.mfog"
    App::VirtualBase::~VirtualBase() {};
    
};

#endif
