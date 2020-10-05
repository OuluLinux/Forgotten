#ifndef COMPILER_HXX
#define COMPILER_HXX

#include <new>

#ifndef UTIL_HXX
#include <Util.hxx>
#endif

namespace Compiler
{
    enum _anon_17
    {
        PROCMSG_UNKNOWN,
        PROCMSG_SKIP,
        PROCMSG_INFO,
        PROCMSG_WARNING,
        PROCMSG_ERROR
    };
    
    class ErrorSource
    {
#line 89 "../../src/Com/CompilerBase.fog"
        Text::String error_path;
#line 89
        Text::String src;
        bool fail;
        
    public:
#line 106
        inline ErrorSource();
#line 108
        inline void SetErrorPath(Text::String path);
        inline void SetSource(Text::String s);
        
    protected:
#line 98
        void Error(Text::String msg);
#line 97
        void Error(Text::String msg, Text::String file, int line, int col);
#line 96
        void Error(Text::String msg, int line, int col);
#line 102
        void Info(Text::String msg);
#line 94
        void Internal(Text::String msg);
        void InternalWarning(Text::String msg);
#line 93
        void PrintHeader(Text::String file = "", int line = - 1, int col = - 1);
#line 101
        void Warning(Text::String msg);
#line 100
        void Warning(Text::String msg, Text::String file, int line, int col);
#line 99
        void Warning(Text::String msg, int line, int col);
    };
    
    struct FileLocation
    {
#line 16
        int file;
        int line;
#line 17
        int col;
        
#line 20
        bool operator== (const FileLocation& t) const;
#line 19
        inline void SetFileLocation(const FileLocation& loc);
    };
    
    struct ProcMsg : public Compiler::FileLocation
    {
#line 32
        int severity;
        int src;
        int msg;
        
        ProcMsg();
#line 38
        ProcMsg(Text::String source, FileLocation loc, int severity, Text::String msg);
#line 37
        ProcMsg(const ProcMsg& e);
#line 47
        void operator= (const ProcMsg& e);
#line 45
        bool operator== (const ProcMsg& t) const;
#line 63
        Text::String AsString() const;
#line 75
        Text::String GetSeverityString() const;
#line 56
        void Set(Text::String source, FileLocation loc, int severity, Text::String msg);
        
#line 30
        static Util::StringCache cache;
    };
};

namespace Compiler
{
#line 106
    inline ErrorSource::ErrorSource()
    :
        fail(false)
    {};
    
#line 108
    inline void ErrorSource::SetErrorPath(Text::String path)
    {
#line 108
        error_path = path;
    };
    
#line 109
    inline void ErrorSource::SetSource(Text::String s)
    {
#line 109
        src = s;
    };
    
#line 19
    inline void FileLocation::SetFileLocation(const FileLocation& loc)
    {
#line 19
        *this = loc;
    };
    
};

#endif
