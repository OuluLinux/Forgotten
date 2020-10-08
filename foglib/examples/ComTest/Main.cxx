#ifndef MAIN_CXX
#define MAIN_CXX

#include <new>

#ifndef MAIN_HXX
#include <Main.hxx>
#endif

namespace Main
{
#line 290 "ComTest.mfog"
    void App::TestShared()
    {
#line 300
        Shared::Ptr < Dumb > s0a;
#line 302
        ;
        {
#line 303
            Shared::Ptr < Dumber > s1a;
            Shared::Ptr < Dumb > s1b;
#line 306
            ;
            ;
            s1b = Shared::Ptr < Dumb > ().WrapObject(new Dumb);
#line 310
            ;
            s1a = s1b.As < Dumber > ();
#line 313
            ;
            {
                Shared::Ptr < Dumber > s2;
#line 317
                ;
#line 317
                s2 = s1a;
#line 319
                ;
#line 319
                s0a = s2.As < Dumb > ();
#line 321
                ;
            }
            ;
        }
        ;
    };
    
#line 283
    App::Dumber::~Dumber()
    {
#line 283
        ;
    };
    
#line 104 "../../src/Com/Meta.fog"
    App::SomeRefTuple2::SomeRefTuple2(int& a, double& b)
    :
        a(a),
        b(b)
    {};
    
#line 105
    Text::String App::SomeRefTuple2::AsString() const
    {
#line 105
        return Text::ToString(a) + ", " + Text::ToString(b);
    };
    
#line 85
    Text::String App::SomeTuple2::AsString() const
    {
#line 85
        return Text::ToString(a) + ", " + Text::ToString(b);
    };
    
#line 40 "ComTest.mfog"
    App::VirtualBase::~VirtualBase() {};
    
};

#endif
