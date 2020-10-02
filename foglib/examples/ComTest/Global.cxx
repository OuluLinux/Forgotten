#ifndef GLOBAL_CXX
#define GLOBAL_CXX

#include <new>

#ifndef GLOBAL_HXX
#include <Global.hxx>
#endif

extern "C"
{
#line 117 "../../src/Com/Meta.fog"
    int main(int argc, const char **argv)
    {
#line 118
        Com::Env & e = Com::Env::Local();
        e.Init(argc, argv);
        Main::App().Run();
        return e.Deinit();
    };
    
};

#endif
