#ifndef COM_CXX
#define COM_CXX

#include <new>

#ifndef COM_HXX
#include <Com.hxx>
#endif

namespace Com
{
#line 10 "../../src/Com/Environment.fog"
    void Env::Init(int argc, const char **argv)
    {
#line 11
        SetExeFilePath(argv[0]);
        ParseCommandLine(argc, argv);
        ReadComCmdlineArgs();
        RunInitBlocks();
    };
    
};

#endif
