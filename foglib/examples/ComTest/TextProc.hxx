#ifndef TEXTPROC_HXX
#define TEXTPROC_HXX

#include <new>

#ifndef INTERFACE_HXX
#include <Interface.hxx>
#endif
#ifndef UTIL_HXX
#include <Util.hxx>
#endif

namespace TextProc
{
    enum _anon_19
    {
        PROCMSG_UNKNOWN,
        PROCMSG_SKIP,
        PROCMSG_INFO,
        PROCMSG_WARNING,
        PROCMSG_ERROR
    };
    enum _anon_20
    {
        FP_INT,
        FP_DEC,
        FP_FRAC,
        FP_SIGN,
        FP_EXP,
        FP_F,
        FP_END,
        FP_OCTHEX,
        FP_OCT,
        FP_HEX
    };
    enum _anon_21
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
    
    struct ProcMsg : public TextProc::FileLocation
    {
#line 30
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
#line 94 "../../src/Com/Tokenizer.fog"
        FileLocation loc;
#line 94
        FileLocation end;
        int type;
        Text::String str_value;
        int spaces;
        
        Token();
        Token(const Token& t);
#line 103
        inline bool operator!= (const Token& t) const;
#line 101
        void operator= (const Token& t);
        bool operator== (const Token& t) const;
#line 151
        Text::String AsString() const;
#line 105
        inline Text::String GetString() const;
#line 155
        Text::String GetTextValue() const;
#line 106
        Text::String GetTypeString() const;
#line 104
        inline bool IsType(int i) const;
    };
    
    class Tokenizer
    {
#line 205
        FileLocation loc;
        int cursor;
        Text::String input;
        bool skip_comments;
        bool skip_newlines;
        bool skip_separateunary;
        int pass_cursor;
#line 213
        int tab_size;
        
    protected:
#line 217
        Container::Vector < Token > tokens;
        
    public:
#line 251
        Container::Vector < ProcMsg > messages;
        
    public:
#line 310
        Tokenizer();
#line 234
        void Dump() const;
#line 241
        inline int GetPassCursor() const;
#line 236
        inline const Container::Vector < Token > & GetTokens() const;
#line 334
        bool IsToken(int tk);
#line 365
        bool Load(Text::String str, Text::String path);
#line 329
        void PassToken(int tk);
#line 360
        double ReadDouble();
#line 350
        Text::String ReadId();
#line 355
        Lang::int64 ReadInt();
#line 345
        Text::String ReadString();
#line 238
        inline void Remove(int i);
#line 232
        inline void SetTabSize(int i);
#line 229
        inline void SkipComments(bool b = true);
        inline void SkipNewLines(bool b = true);
        inline void SkipSeparateUnary(bool b = true);
#line 339
        bool TryPassToken(int tk);
        
    protected:
#line 314
        Token& Add(int token_id);
#line 223
        void AddError(FileLocation loc, Text::String msg);
        void AddWarning(FileLocation loc, Text::String msg);
#line 804
        void AppendString(Text::String& s);
#line 219
        inline void Next();
    };
    
    class CParser
    {
    public:
#line 265
        typedef CParser CLASSNAME;
        
    private:
#line 262
        typedef TextProc::Tokenizer Toknzr;
        
#line 257
        const Container::Vector < Token > *tokens;
        int pos;
#line 260
        bool ignore_newline;
#line 263
        Container::One < Toknzr > t;
        
    public:
        CParser();
        CParser(Text::String s);
        CParser(const Container::Vector < Token > & tokens);
#line 893
        const Token& GetCurrent() const;
#line 909
        FileLocation GetLocation() const;
#line 278
        int GetTokenCount() const;
        inline int GetTokenPos() const;
#line 273
        inline const Container::Vector < Token > & GetTokens() const;
#line 941
        bool Id(Text::String id);
#line 901
        void IgnoreNewline(bool b);
#line 905
        bool IsEnd() const;
#line 968
        bool IsId() const;
#line 972
        bool IsInt() const;
#line 976
        bool IsType(int i) const;
#line 888
        void Load(const Container::Vector < Token > & tokens);
#line 959
        bool Newline();
#line 275
        inline void Next();
#line 934
        void PassNewline();
#line 913
        Text::String ReadId();
#line 921
        int ReadInt();
#line 950
        bool Type(int i);
    };
};

namespace TextProc
{
#line 279
    inline int CParser::GetTokenPos() const
    {
#line 279
        return pos;
    };
    
#line 273
    inline const Container::Vector < Token > & CParser::GetTokens() const
    {
#line 273
        return *tokens;
    };
    
#line 275
    inline void CParser::Next()
    {
#line 275
        pos ++ ;
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
    
#line 34
    inline ProcMsg::ProcMsg()
    :
        severity(0)
    {};
    
#line 103 "../../src/Com/Tokenizer.fog"
    inline bool Token::operator!= (const Token& t) const
    {
#line 103
        return !(t == *this);
    };
    
#line 105
    inline Text::String Token::GetString() const
    {
#line 105
        return str_value;
    };
    
#line 104
    inline bool Token::IsType(int i) const
    {
#line 104
        return type == i;
    };
    
#line 241
    inline int Tokenizer::GetPassCursor() const
    {
#line 241
        return pass_cursor;
    };
    
#line 236
    inline const Container::Vector < Token > & Tokenizer::GetTokens() const
    {
#line 236
        return tokens;
    };
    
#line 219
    inline void Tokenizer::Next()
    {
#line 219
        loc.col ++ ;
#line 219
        cursor ++ ;
    };
    
#line 238
    inline void Tokenizer::Remove(int i)
    {
#line 238
        tokens.Remove(i);
    };
    
#line 232
    inline void Tokenizer::SetTabSize(int i)
    {
#line 232
        tab_size = i;
    };
    
#line 229
    inline void Tokenizer::SkipComments(bool b)
    {
#line 229
        skip_comments = b;
    };
    
#line 230
    inline void Tokenizer::SkipNewLines(bool b)
    {
#line 230
        skip_newlines = b;
    };
    
#line 231
    inline void Tokenizer::SkipSeparateUnary(bool b)
    {
#line 231
        skip_separateunary = b;
    };
    
};

#endif
