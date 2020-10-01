/*!$@FOG@$!
 *	Generated at Thu Oct  1 09:26:12 2020
 *
 *	by fog 0.1.a of 12:17:36 Sep 29 2020
 *
 *	from
 *		../../src/Com/Abstract.fog
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Container.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Lang.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Meta.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/Prim.fog
 *		../../src/Com/Random.fog
 *		../../src/Com/Shared.fog
 *		../../src/Com/Stream.fog
 *		../../src/Com/Text.fog
 *		../../src/Com/Util.fog
 *		ComTest.mfog
 */

#ifndef COM_HXX
#define COM_HXX

#include <new>

#ifndef CONTAINER_HXX
#include <Container.hxx>
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
