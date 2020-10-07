#ifndef MAIN_CXX
#define MAIN_CXX

#include <new>

#ifndef MAIN_HXX
#include <Main.hxx>
#endif

namespace Main
{
#line 283 "ComTest.mfog"
    void App::TestShared()
    {
#line 293
        Shared::Ptr < Dumb > s0a;
#line 295
        ;
        {
#line 296
            Shared::Ptr < Dumber > s1a;
            Shared::Ptr < Dumb > s1b;
#line 299
            ;
            ;
            s1b = Shared::Ptr < Dumb > ().WrapObject(new Dumb);
#line 303
            ;
            s1a = s1b.As < Dumber > ();
#line 306
            ;
            {
                Shared::Ptr < Dumber > s2;
#line 310
                ;
#line 310
                s2 = s1a;
#line 312
                ;
#line 312
                s0a = s2.As < Dumb > ();
#line 314
                ;
            }
            ;
        }
        ;
    };
    
#line 276
    App::Dumber::~Dumber()
    {
#line 276
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
    
#line 33 "ComTest.mfog"
    App::VirtualBase::~VirtualBase() {};
    
};

#endif
