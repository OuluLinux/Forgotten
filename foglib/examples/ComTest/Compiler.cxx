#ifndef COMPILER_CXX
#define COMPILER_CXX

#include <new>

#ifndef COMPILER_HXX
#include <Compiler.hxx>
#endif

namespace Compiler
{
#line 20 "../../src/Com/CompilerBase.fog"
    bool FileLocation::operator== (const FileLocation& t) const
    {
#line 8
        return Lang::Memory::Compare(this, &t, sizeof (FileLocation)) == 0;
    };
    
#line 36
    ProcMsg::ProcMsg()
    :
        severity(0),
        src(- 1),
        msg(- 1)
    {};
    
#line 38
    ProcMsg::ProcMsg(Text::String source, FileLocation loc, int severity, Text::String msg)
    :
        severity(0),
        src(- 1),
        msg(- 1)
    {
#line 39
        this -> src = cache.GetAdd(source);
        SetFileLocation(loc);
        this -> severity = severity;
        this -> msg = cache.GetAdd(msg);
    };
    
#line 37
    ProcMsg::ProcMsg(const ProcMsg& e)
    :
        severity(0),
        src(- 1),
        msg(- 1)
    {
#line 37
        *this = e;
    };
    
#line 47
    void ProcMsg::operator= (const ProcMsg& e)
    {
#line 48
        msg = e.msg;
        file = e.file;
        src = e.src;
        line = e.line;
        col = e.col;
        severity = e.severity;
    };
    
#line 45
    bool ProcMsg::operator== (const ProcMsg& t) const
    {
#line 8
        return Lang::Memory::Compare(this, &t, sizeof (ProcMsg)) == 0;
    };
    
#line 63
    Text::String ProcMsg::AsString() const
    {
#line 64
        Text::String s;
        s << Text::String::IntStr(src) << Prim::InlineIf < Text::String > (src >= 0, (Text::String)": " + cache.Get(src), "") << ": " << cache.Get(file) << ":" << line << ":" << col << ": " << GetSeverityString() << ": " << cache.Get(msg);
#line 72
        return s;
    };
    
    Text::String ProcMsg::GetSeverityString() const
    {
#line 76
        switch (severity)
        {
#line 77
            case PROCMSG_SKIP:
#line 77
                return "skip";
            case PROCMSG_INFO:
#line 78
                return "info";
            case PROCMSG_WARNING:
#line 79
                return "warning";
            case PROCMSG_ERROR:
#line 80
                return "error";
            default:
#line 81
                return "<invalid severity>";
        }
    };
    
#line 56
    void ProcMsg::Set(Text::String source, FileLocation loc, int severity, Text::String msg)
    {
#line 57
        this -> src = cache.GetAdd(source);
        SetFileLocation(loc);
        this -> severity = severity;
        this -> msg = cache.GetAdd(msg);
    };
    
};

#endif
