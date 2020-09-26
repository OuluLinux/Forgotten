/*!$@FOG@$!
 *	Generated at Sat Sep 26 09:29:30 2020
 *
 *	by fog 0.1.a of 08:09:34 Sep 23 2020
 *
 *	from
 *		../../src/Core/Concurrency.fog
 *		../../src/Core/Core.fog
 *		../../src/Core/Defs.fog
 *		../../src/Core/Environment.fog
 *		../../src/Core/Macros.fog
 *		../../src/Core/Math.fog
 *		../../src/Core/Native.fog
 *		../../src/Core/Stream.fog
 *		/home/sblo/Forgotten/foglib/examples/CoreTest/CoreTest.mfog
 */

#ifndef CORE_HXX
#define CORE_HXX

#ifndef C_HXX
#include <C.hxx>
#endif

struct Console
{
#line 7 "../../src/Core/Stream.fog"
    static int Get(char *buf, int size);
    static void Put(const char *msg);
};

struct CoreInterfaceLinker
{
};

class Env
{
public:
#line 18 "../../src/Core/Environment.fog"
    inline int Deinit();
#line 10
    void Init(int argc, const char **argv);
#line 24
    inline void ShutdownThreads();
    
protected:
#line 35
    inline int GetExitCode();
#line 31
    inline void ParseCommandLine(int argc, const char **argv);
    inline void ReadCoreCmdlineArgs();
#line 34
    inline void RunExitBlocks();
#line 33
    inline void RunInitBlocks();
#line 30
    inline void SeedRandom();
#line 29
    inline void SetExeFilePath(const char *path);
    
public:
#line 26
    inline static Env& Local();
};

namespace Core
{
#line 30 "../../src/Core/Defs.fog"
    extern C::Nuller Null;
};

namespace Core
{
#line 49
    typedef unsigned char Byte;
    
#line 50
    extern Byte ____unused_Byte;
};

namespace Core
{
#line 54
    typedef C::Ptr < const void > CONST_VOID_PTR;
    
#line 55
    extern CONST_VOID_PTR ____unused_CONST_VOID_PTR;
};

namespace Core
{
#line 54
    typedef C::Ptr < const char > CString;
    
#line 55
    extern CString ____unused_CString;
};

namespace Core
{
#line 49
    typedef unsigned long DWORD;
    
#line 50
    extern DWORD ____unused_DWORD;
};

namespace Core
{
#line 54
    typedef C::Ptr < void > VOID_PTR;
    
#line 55
    extern VOID_PTR ____unused_VOID_PTR;
};

namespace Core
{
#line 49
    typedef unsigned char byte;
    
#line 50
    extern byte ____unused_byte;
};

namespace Core
{
#line 49
    typedef unsigned int uint32;
#line 49
    typedef uint32 dword;
    
#line 50
    extern dword ____unused_dword;
};

namespace Core
{
#line 49
    typedef short int16;
    
#line 50
    extern int16 ____unused_int16;
};

namespace Core
{
#line 49
    typedef int int32;
    
#line 50
    extern int32 ____unused_int32;
};

namespace Core
{
#line 49
    typedef long long int64;
    
#line 50
    extern int64 ____unused_int64;
};

namespace Core
{
#line 49
    typedef char int8;
    
#line 50
    extern int8 ____unused_int8;
};

namespace Core
{
#line 49
    typedef unsigned long long uint64;
#line 49
    typedef uint64 qword;
    
#line 50
    extern qword ____unused_qword;
};

namespace Core
{
#line 49
    typedef unsigned short uint16;
    
#line 50
    extern uint16 ____unused_uint16;
#line 50
    extern uint32 ____unused_uint32;
#line 50
    extern uint64 ____unused_uint64;
};

namespace Core
{
#line 49
    typedef uint16 word;
    
#line 50
    extern word ____unused_word;
    
#line 129
    void Break(const char *msg);
#line 132
    template < class _1 >
    inline void IGNORE_RESULT(const _1& );
#line 4 "../../src/Core/Native.fog"
    int MemoryCompare(const void *m1, const void *m2, int sz);
    void *MemoryCopy(void *dest, const void *src, int sz);
    void *MemoryMove(void *dest, const void *src, int sz);
    int SignificantBits(uint32 x);
    int SignificantBits64(uint64 x);
    
    class Tester
    {
    public:
#line 10 "/home/sblo/Forgotten/foglib/examples/CoreTest/CoreTest.mfog"
        void Run();
    };
};

namespace Core
{
#line 132 "../../src/Core/Defs.fog"
    template < class _1 >
    inline void IGNORE_RESULT(const _1& ) {};
    
};
#line 18 "../../src/Core/Environment.fog"
inline int Env::Deinit()
{
#line 19
    ShutdownThreads();
    RunExitBlocks();
    return GetExitCode();
};

#line 35
inline int Env::GetExitCode()
{
#line 35
    return 0;
};

#line 26
inline Env& Env::Local()
{
#line 26
    static Env e;
#line 26
    return e;
};

#line 31
inline void Env::ParseCommandLine(int argc, const char **argv) {};

#line 32
inline void Env::ReadCoreCmdlineArgs() {};

inline void Env::RunExitBlocks() {};

#line 33
inline void Env::RunInitBlocks() {};

#line 30
inline void Env::SeedRandom() {};

#line 29
inline void Env::SetExeFilePath(const char *path) {};

#line 24
inline void Env::ShutdownThreads() {};

#endif
