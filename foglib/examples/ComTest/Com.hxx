#ifndef COM_HXX
#define COM_HXX

#include <new>

#ifndef UTIL_HXX
#include <Util.hxx>
#endif

namespace Com
{
    class Env
    {
    public:
#line 17 "../../src/Com/Environment.fog"
        inline int Deinit();
#line 10
        void Init(int argc, const char **argv);
#line 23
        inline void ShutdownThreads();
        
    protected:
#line 34
        inline int GetExitCode();
#line 30
        inline void ParseCommandLine(int argc, const char **argv);
        inline void ReadComCmdlineArgs();
#line 33
        inline void RunExitBlocks();
#line 32
        inline void RunInitBlocks();
#line 29
        inline void SeedRandom();
#line 28
        inline void SetExeFilePath(const char *path);
        
    public:
#line 25
        inline static Env& Local();
    };
};

namespace Com
{
#line 17
    inline int Env::Deinit()
    {
#line 18
        ShutdownThreads();
        RunExitBlocks();
        return GetExitCode();
    };
    
#line 34
    inline int Env::GetExitCode()
    {
#line 34
        return 0;
    };
    
#line 25
    inline Env& Env::Local()
    {
#line 25
        static Env e;
#line 25
        return e;
    };
    
#line 30
    inline void Env::ParseCommandLine(int argc, const char **argv) {};
    
#line 31
    inline void Env::ReadComCmdlineArgs() {};
    
    inline void Env::RunExitBlocks() {};
    
#line 32
    inline void Env::RunInitBlocks() {};
    
#line 29
    inline void Env::SeedRandom()
    {
#line 29
        Random::Generator::Local().Seed();
    };
    
#line 28
    inline void Env::SetExeFilePath(const char *path) {};
    
#line 23
    inline void Env::ShutdownThreads() {};
    
};

#endif
