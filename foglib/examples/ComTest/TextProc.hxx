#ifndef TEXTPROC_HXX
#define TEXTPROC_HXX

#include <new>

#ifndef INTERFACE_HXX
#include <Interface.hxx>
#endif
#ifndef UTIL_HXX
#include <Util.hxx>
#endif

#ifndef LOCKEDCONTAINER_HXX
#include <LockedContainer.hxx>
#endif

namespace TextProc
{
    enum _anon_21
    {
        PROCMSG_UNKNOWN,
        PROCMSG_SKIP,
        PROCMSG_INFO,
        PROCMSG_WARNING,
        PROCMSG_ERROR
    };
    enum _anon_22
    {
        FP_INT,
        FP_DEC,
        FP_FRAC,
        FP_SIGN,
        FP_EXP,
        FP_F,
        FP_END,
        FP_BIN,
        FP_OCTHEX,
        FP_OCT,
        FP_HEX
    };
    enum _anon_23
    {
        TK_UNKNOWN,
        TK_EXCLAMATION = '!',
        TK_NUMBERSIGN = '#',
        TK_PERCENT = '%',
        TK_AMPERSAND = '&',
        TK_DIV = '/',
        TK_BRACKET_BEGIN = '{',
        TK_BRACKET_END = '}',
        TK_PARENTHESIS_BEGIN = '(',
        TK_PARENTHESIS_END = ')',
        TK_SQUARE_BEGIN = '[',
        TK_SQUARE_END = ']',
        TK_ASS = '=',
        TK_QUESTION = '\?',
        TK_PLUS = '+',
        TK_SOLIDUS = '\\',
        TK_ACCENT = '^',
        TK_TILDE = '~',
        TK_MUL = '*',
        TK_AT = '@',
        TK_OR = '|',
        TK_MINUS = '-',
        TK_SEMICOLON = ';',
        TK_COMMA = ',',
        TK_PUNCT = '.',
        TK_COLON = ':',
        TK_LESS = '<',
        TK_GREATER = '>',
        TK_NEWLINE = '\n',
        TK_DOLLARSIGN = '$',
        TK_ID = 1000,
        TK_INTEGER,
        TK_BIN,
        TK_HEX,
        TK_OCT,
        TK_FLOAT,
        TK_DOUBLE,
        TK_STRING,
        TK_CHAR,
        TK_BLOCK_COMMENT,
        TK_COMMENT,
        TK_INVALID,
        TK_INC,
        TK_DEC,
        TK_LSHIFT,
        TK_RSHIFT,
        TK_EQ,
        TK_LSEQ,
        TK_GREQ,
        TK_INEQ,
        TK_LOGAND,
        TK_LOGOR,
        TK_MULASS,
        TK_DIVASS,
        TK_MODASS,
        TK_ADDASS,
        TK_SUBASS,
        TK_ANDASS,
        TK_XORASS,
        TK_ORASS,
        TK_LSHIFTASS,
        TK_RSHIFTASS,
        TK_3DOTS,
        TK_EOF = 100000,
        TK_COMBINED2_BEGIN = TK_INC,
        TK_COMBINED3_BEGIN = TK_LSHIFTASS
    };
    
    class ErrorSource
    {
#line 86 "../../src/Com/CompilerBase.fog"
        Text::String error_path;
#line 86
        Text::String src;
        bool fail;
        
    public:
#line 103
        inline ErrorSource();
#line 105
        inline void SetErrorPath(Text::String path);
        inline void SetSource(Text::String s);
        
    protected:
#line 95
        void Error(Text::String msg);
#line 94
        void Error(Text::String msg, Text::String file, int line, int col);
#line 93
        void Error(Text::String msg, int line, int col);
#line 99
        void Info(Text::String msg);
#line 91
        void Internal(Text::String msg);
        void InternalWarning(Text::String msg);
#line 90
        void PrintHeader(Text::String file = "", int line = - 1, int col = - 1);
#line 98
        void Warning(Text::String msg);
#line 97
        void Warning(Text::String msg, Text::String file, int line, int col);
#line 96
        void Warning(Text::String msg, int line, int col);
    };
    
    struct FileLocation
    {
#line 16
        Text::String file;
        int line;
#line 17
        int col;
        
#line 20
        bool operator== (const FileLocation& t) const;
#line 19
        inline void SetFileLocation(const FileLocation& loc);
    };
    
    struct InputExc : public Text::String
    {
#line 192 "../../src/Com/Meta.fog"
        inline InputExc();
        inline InputExc(const Text::String& s);
    };
};

namespace TextProc {
class Tokenizer;
}

namespace TextProc
{
    struct JSON
    {
#line 8 "../../src/Com/JSON.fog"
        static Interface::Value ParseArray(Tokenizer& tk);
#line 115
        static Interface::Value ParseJSON(Text::String json);
#line 55
        static Interface::Value ParseMap(Tokenizer& tk);
    };
    
    struct Pos
    {
#line 267 "../../src/Com/Tokenizer.fog"
        int pos;
        
#line 268
        inline Pos();
        inline Pos(const Pos& p);
        inline bool Is() const;
    };
    
    struct ProcMsg : public TextProc::FileLocation
    {
#line 30 "../../src/Com/CompilerBase.fog"
        int severity;
        Text::String src;
        Text::String msg;
        
        inline ProcMsg();
#line 36
        ProcMsg(Text::String source, FileLocation loc, int severity, Text::String msg);
#line 35
        ProcMsg(const ProcMsg& e);
#line 45
        void operator= (const ProcMsg& e);
#line 43
        bool operator== (const ProcMsg& t) const;
#line 61
        Text::String AsString() const;
#line 72
        Text::String GetSeverityString() const;
#line 54
        void Set(Text::String source, FileLocation loc, int severity, Text::String msg);
    };
    
    struct Token
    {
#line 99 "../../src/Com/Tokenizer.fog"
        TextProc::FileLocation loc;
#line 99
        TextProc::FileLocation end;
        int type;
        Text::String str_value;
        int spaces;
        
        Token();
        Token(const Token& t);
#line 108
        inline bool operator!= (const Token& t) const;
#line 106
        void operator= (const Token& t);
        bool operator== (const Token& t) const;
#line 159
        Text::String AsString() const;
#line 110
        inline Text::String GetString() const;
#line 163
        inline Text::String GetTextValue() const;
#line 111
        inline Text::String GetTypeString() const;
#line 109
        inline bool IsType(int i) const;
        
#line 164
        static Text::String StaticGetTextValue(int type, Text::String str_value);
#line 112
        static Text::String StaticGetTypeString(int type);
    };
    
    class Tokenizer
    {
#line 216
        TextProc::FileLocation loc;
        int cursor;
        Text::String input;
        bool skip_comments;
        bool skip_newlines;
        bool skip_separateunary;
        int pass_cursor;
#line 224
        int tab_size;
        
    protected:
#line 228
        Container::Vector < Token > tokens;
        
    public:
#line 262
        Container::Vector < ProcMsg > messages;
        
    public:
#line 347
        Tokenizer();
#line 245
        void Dump() const;
#line 252
        inline int GetPassCursor() const;
#line 247
        inline const Container::Vector < Token > & GetTokens() const;
#line 371
        bool IsToken(int tk);
#line 402
        bool Load(Text::String str, Text::String path);
#line 366
        void PassToken(int tk);
#line 397
        double ReadDouble();
#line 387
        Text::String ReadId();
#line 392
        Lang::int64 ReadInt();
#line 382
        Text::String ReadString();
#line 249
        inline void Remove(int i);
#line 243
        inline void SetTabSize(int i);
#line 240
        inline void SkipComments(bool b = true);
        inline void SkipNewLines(bool b = true);
        inline void SkipSeparateUnary(bool b = true);
#line 376
        bool TryPassToken(int tk);
        
    protected:
#line 351
        Token& Add(int token_id);
#line 234
        void AddError(TextProc::FileLocation loc, Text::String msg);
        void AddWarning(TextProc::FileLocation loc, Text::String msg);
#line 852
        void AppendString(Text::String& s);
#line 230
        inline void Next();
    };
    
    class CBase
    {
    public:
#line 283
        typedef CBase CLASSNAME;
        
    private:
#line 274
        typedef TextProc::Tokenizer Toknzr;
        
        const Container::Vector < Token > *tokens;
        int pos;
#line 279
        bool ignore_newline;
#line 281
        Container::One < Toknzr > t;
        
    public:
        CBase();
        CBase(Text::String str);
        CBase(Text::String str, Text::String src_name);
        CBase(const Container::Vector < Token > & tokens);
#line 929
        const Token& GetCurrent() const;
#line 289
        Text::String GetFileName() const;
        int GetLine() const;
#line 945
        TextProc::FileLocation GetLocation() const;
#line 304
        Pos GetPos();
#line 326
        const char *GetPtr() const;
#line 301
        int GetTokenCount() const;
        inline int GetTokenPos() const;
#line 295
        inline const Container::Vector < Token > & GetTokens() const;
#line 975
        bool Id(Text::String id);
#line 937
        void IgnoreNewline(bool b);
#line 941
        bool IsEnd() const;
#line 1002
        bool IsId() const;
#line 1006
        bool IsInt() const;
#line 1010
        bool IsType(int i) const;
#line 924
        void Load(const Container::Vector < Token > & tokens);
#line 993
        bool Newline();
#line 297
        inline void Next();
#line 315
        void PassId(Text::String s);
#line 968
        void PassNewline();
#line 314
        void PassType(int i);
#line 949
        Text::String ReadId();
#line 957
        int ReadInt();
#line 305
        void SetPos(const Pos& p);
#line 298
        inline void SkipTerm();
#line 329
        inline void ThrowError(Text::String msg);
#line 984
        bool Type(int i);
    };
};

namespace TextProc
{
#line 302
    inline int CBase::GetTokenPos() const
    {
#line 302
        return pos;
    };
    
#line 295
    inline const Container::Vector < Token > & CBase::GetTokens() const
    {
#line 295
        return *tokens;
    };
    
#line 297
    inline void CBase::Next()
    {
#line 297
        pos ++ ;
    };
    
#line 298
    inline void CBase::SkipTerm()
    {
#line 298
        pos ++ ;
    };
    
#line 329
    inline void CBase::ThrowError(Text::String msg)
    {
#line 329
        throw TextProc::InputExc(msg);
    };
    
#line 103 "../../src/Com/CompilerBase.fog"
    inline ErrorSource::ErrorSource()
    :
        fail(false)
    {};
    
#line 105
    inline void ErrorSource::SetErrorPath(Text::String path)
    {
#line 105
        error_path = path;
    };
    
#line 106
    inline void ErrorSource::SetSource(Text::String s)
    {
#line 106
        src = s;
    };
    
#line 19
    inline void FileLocation::SetFileLocation(const FileLocation& loc)
    {
#line 19
        *this = loc;
    };
    
#line 192 "../../src/Com/Meta.fog"
    inline InputExc::InputExc() {};
    
#line 193
    inline InputExc::InputExc(const Text::String& s)
    :
        String(s)
    {};
    
#line 268 "../../src/Com/Tokenizer.fog"
    inline Pos::Pos()
    :
        pos(- 1)
    {};
    
#line 269
    inline Pos::Pos(const Pos& p)
    :
        pos(p.pos)
    {};
    
#line 270
    inline bool Pos::Is() const
    {
#line 270
        return pos >= 0;
    };
    
#line 34 "../../src/Com/CompilerBase.fog"
    inline ProcMsg::ProcMsg()
    :
        severity(0)
    {};
    
#line 108 "../../src/Com/Tokenizer.fog"
    inline bool Token::operator!= (const Token& t) const
    {
#line 108
        return !(t == *this);
    };
    
#line 110
    inline Text::String Token::GetString() const
    {
#line 110
        return str_value;
    };
    
#line 163
    inline Text::String Token::GetTextValue() const
    {
#line 163
        return StaticGetTextValue(type, str_value);
    };
    
#line 111
    inline Text::String Token::GetTypeString() const
    {
#line 111
        return StaticGetTypeString(type);
    };
    
#line 109
    inline bool Token::IsType(int i) const
    {
#line 109
        return type == i;
    };
    
#line 252
    inline int Tokenizer::GetPassCursor() const
    {
#line 252
        return pass_cursor;
    };
    
#line 247
    inline const Container::Vector < Token > & Tokenizer::GetTokens() const
    {
#line 247
        return tokens;
    };
    
#line 230
    inline void Tokenizer::Next()
    {
#line 230
        loc.col ++ ;
#line 230
        cursor ++ ;
    };
    
#line 249
    inline void Tokenizer::Remove(int i)
    {
#line 249
        tokens.Remove(i);
    };
    
#line 243
    inline void Tokenizer::SetTabSize(int i)
    {
#line 243
        tab_size = i;
    };
    
#line 240
    inline void Tokenizer::SkipComments(bool b)
    {
#line 240
        skip_comments = b;
    };
    
#line 241
    inline void Tokenizer::SkipNewLines(bool b)
    {
#line 241
        skip_newlines = b;
    };
    
#line 242
    inline void Tokenizer::SkipSeparateUnary(bool b)
    {
#line 242
        skip_separateunary = b;
    };
    
};

#endif
