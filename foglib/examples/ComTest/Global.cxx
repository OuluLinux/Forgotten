#ifndef GLOBAL_CXX
#define GLOBAL_CXX

#include <new>

#ifndef GLOBAL_HXX
#include <Global.hxx>
#endif

extern "C"
{
#line 148 "../../src/Com/Meta.fog"
    int main(int argc, const char **argv)
    {
#line 149
        Util::Env & e = Util::Env::Local();
        e.Init(argc, argv);
        Main::App().Run();
        return e.Deinit();
    };
    
};

#endif
