#ifndef MAIN_CXX
#define MAIN_CXX

#include <new>

#ifndef MAIN_HXX
#include <Main.hxx>
#endif

namespace Main
{
#line 252 "ComTest.mfog"
    void App::TestShared()
    {
#line 262
        Shared::Ptr < Dumb > s0a;
#line 264
        ;
        {
#line 265
            Shared::Ptr < Dumber > s1a;
            Shared::Ptr < Dumb > s1b;
#line 268
            ;
            ;
            s1b = Shared::Ptr < Dumb > ().WrapObject(new Dumb);
#line 272
            ;
            s1a = s1b.As < Dumber > ();
#line 275
            ;
            {
                Shared::Ptr < Dumber > s2;
#line 279
                ;
#line 279
                s2 = s1a;
#line 281
                ;
#line 281
                s0a = s2.As < Dumb > ();
#line 283
                ;
            }
            ;
        }
        ;
    };
    
#line 245
    App::Dumber::~Dumber()
    {
#line 245
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
    
#line 31 "ComTest.mfog"
    App::VirtualBase::~VirtualBase() {};
    
};

#endif
