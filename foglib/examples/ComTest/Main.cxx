#ifndef MAIN_CXX
#define MAIN_CXX

#include <new>

#ifndef MAIN_HXX
#include <Main.hxx>
#endif

namespace Main
{
#line 257 "ComTest.mfog"
    void App::TestShared()
    {
#line 267
        Shared::Ptr < Dumb > s0a;
#line 269
        ;
        {
#line 270
            Shared::Ptr < Dumber > s1a;
            Shared::Ptr < Dumb > s1b;
#line 273
            ;
            ;
            s1b = Shared::Ptr < Dumb > ().WrapObject(new Dumb);
#line 277
            ;
            s1a = s1b.As < Dumber > ();
#line 280
            ;
            {
                Shared::Ptr < Dumber > s2;
#line 284
                ;
#line 284
                s2 = s1a;
#line 286
                ;
#line 286
                s0a = s2.As < Dumb > ();
#line 288
                ;
            }
            ;
        }
        ;
    };
    
#line 250
    App::Dumber::~Dumber()
    {
#line 250
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
