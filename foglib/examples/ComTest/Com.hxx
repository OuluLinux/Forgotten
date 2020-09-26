/*!$@FOG@$!
 *	Generated at Sat Sep 26 10:29:57 2020
 *
 *	by fog 0.1.a of 08:09:34 Sep 23 2020
 *
 *	from
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Concurrency.fog
 *		../../src/Com/Defs.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Math.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/Stream.fog
 *		/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog
 */

#ifndef COM_HXX
#define COM_HXX

#ifndef C_HXX
#include <C.hxx>
#endif

struct ComInterfaceLinker
{
};

struct Console
{
#line 7 "../../src/Com/Stream.fog"
    static int Get(char *buf, int size);
    static void Put(const char *msg);
};

class Env
{
public:
#line 18 "../../src/Com/Environment.fog"
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
    inline void ReadComCmdlineArgs();
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

namespace Com
{
#line 50 "../../src/Com/Defs.fog"
    extern C::Nuller Null;
};

namespace Com
{
#line 69
    typedef unsigned char Byte;
    
#line 70
    extern Byte ____unused_Byte;
};

namespace Com
{
#line 74
    typedef C::Ptr < const void > CONST_VOID_PTR;
    
#line 75
    extern CONST_VOID_PTR ____unused_CONST_VOID_PTR;
};

namespace Com
{
#line 74
    typedef C::Ptr < const char > CString;
    
#line 75
    extern CString ____unused_CString;
};

namespace Com
{
#line 69
    typedef unsigned long DWORD;
    
#line 70
    extern DWORD ____unused_DWORD;
};

namespace Com
{
#line 74
    typedef C::Ptr < void > VOID_PTR;
    
#line 75
    extern VOID_PTR ____unused_VOID_PTR;
};

namespace Com
{
#line 69
    typedef unsigned char byte;
    
#line 70
    extern byte ____unused_byte;
};

namespace Com
{
#line 69
    typedef unsigned int uint32;
#line 69
    typedef uint32 dword;
    
#line 70
    extern dword ____unused_dword;
};

namespace Com
{
#line 69
    typedef short int16;
    
#line 70
    extern int16 ____unused_int16;
};

namespace Com
{
#line 69
    typedef int int32;
    
#line 70
    extern int32 ____unused_int32;
};

namespace Com
{
#line 69
    typedef long long int64;
    
#line 70
    extern int64 ____unused_int64;
};

namespace Com
{
#line 69
    typedef char int8;
    
#line 70
    extern int8 ____unused_int8;
};

namespace Com
{
#line 69
    typedef unsigned long long uint64;
#line 69
    typedef uint64 qword;
    
#line 70
    extern qword ____unused_qword;
};

namespace Com
{
#line 69
    typedef unsigned short uint16;
    
#line 70
    extern uint16 ____unused_uint16;
#line 70
    extern uint32 ____unused_uint32;
#line 70
    extern uint64 ____unused_uint64;
};

namespace Com
{
#line 69
    typedef uint16 word;
    
#line 70
    extern word ____unused_word;
    
#line 140
    void Break(const char *msg);
#line 25 "../../src/Com/Hash.fog"
    template < class _1 >
    inline uint32 GetHashValue(const _1& k);
#line 37
    template <>
    inline uint32 GetHashValue < VOID_PTR > (const VOID_PTR& k);
#line 26
    template <>
    inline uint32 GetHashValue < char > (const char& k);
#line 36
    template <>
    inline uint32 GetHashValue < double > (const double& k);
#line 35
    template <>
    inline uint32 GetHashValue < float > (const float& k);
#line 27
    template <>
    inline uint32 GetHashValue < int > (const int& k);
#line 28
    template <>
    inline uint32 GetHashValue < uint32 > (const uint32& k);
#line 29
    template <>
    inline uint32 GetHashValue < uint64 > (const uint64& k);
#line 143 "../../src/Com/Defs.fog"
    template < class _1 >
    inline void IGNORE_RESULT(const _1& );
#line 4 "../../src/Com/Native.fog"
    int MemoryCompare(const void *m1, const void *m2, int sz);
    void *MemoryCopy(void *dest, const void *src, int sz);
    void *MemoryMove(void *dest, const void *src, int sz);
    int SignificantBits(uint32 x);
    int SignificantBits64(uint64 x);
#line 11 "../../src/Com/Algorithm.fog"
    template < class _1 >
    inline const _1& max(const _1& a, const _1& b);
#line 4
    template < class _1 >
    inline const _1& min(const _1& a, const _1& b);
    
    class CombineHash
    {
#line 8 "../../src/Com/Hash.fog"
        uint32 hash;
        
    public:
        inline CombineHash();
        inline CombineHash(int v0);
        CombineHash(int v0, int v1);
#line 21
        inline CombineHash& operator<< (int value);
#line 15
        inline operator uint32() const;
        inline uint32 Get() const;
#line 18
        CombineHash& Put(int value);
        CombineHash& Put64(int64 value);
    };
    
    class Tester
    {
    public:
#line 10 "/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog"
        void Run();
    };
};

namespace Com
{
#line 25 "../../src/Com/Hash.fog"
    template < class _1 >
    inline uint32 GetHashValue(const _1& k)
    {
#line 25
        return k.GetHashValue();
    };
    
#line 37
    template <>
    inline uint32 GetHashValue < VOID_PTR > (const VOID_PTR& k)
    {
#line 39
        return GetHashValue(k.Int());
    };
    
#line 26
    template <>
    inline uint32 GetHashValue < char > (const char& k)
    {
#line 26
        return k;
    };
    
#line 36
    template <>
    inline uint32 GetHashValue < double > (const double& k)
    {
#line 36
        return GetHashValue(*(uint64 * ) & k);
    };
    
#line 35
    template <>
    inline uint32 GetHashValue < float > (const float& k)
    {
#line 35
        return static_cast< uint32 >(k);
    };
    
#line 27
    template <>
    inline uint32 GetHashValue < int > (const int& k)
    {
#line 27
        return k;
    };
    
#line 28
    template <>
    inline uint32 GetHashValue < uint32 > (const uint32& k)
    {
#line 28
        return k;
    };
    
#line 29
    template <>
    inline uint32 GetHashValue < uint64 > (const uint64& k)
    {
#line 30
        uint32 a = k & 0xFFFFFFFFULL;
        uint32 b = k >> 32ULL;
        uint32 hash = a ^ b;
        return hash;
    };
    
#line 143 "../../src/Com/Defs.fog"
    template < class _1 >
    inline void IGNORE_RESULT(const _1& ) {};
    
#line 11 "../../src/Com/Algorithm.fog"
    template < class _1 >
    inline const _1& max(const _1& a, const _1& b)
    {
#line 12
        if (a >= b)
            return a;
        else
            return b;
    };
    
#line 4
    template < class _1 >
    inline const _1& min(const _1& a, const _1& b)
    {
#line 5
        if (a < b)
            return a;
        else
            return b;
    };
    
#line 11 "../../src/Com/Hash.fog"
    inline CombineHash::CombineHash()
    :
        hash(123456789)
    {};
    
#line 12
    inline CombineHash::CombineHash(int v0)
    :
        hash(123456789)
    {
#line 12
        Put(v0);
    };
    
#line 21
    inline CombineHash& CombineHash::operator<< (int value)
    {
#line 21
        Put(value);
#line 21
        return *this;
    };
    
#line 15
    inline CombineHash::operator uint32() const
    {
#line 15
        return hash;
    };
    
#line 16
    inline uint32 CombineHash::Get() const
    {
#line 16
        return hash;
    };
    
};
#line 18 "../../src/Com/Environment.fog"
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
inline void Env::ReadComCmdlineArgs() {};

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
