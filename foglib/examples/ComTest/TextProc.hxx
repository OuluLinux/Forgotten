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
        FP_BIN,
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
#line 264 "../../src/Com/Tokenizer.fog"
        int pos;
        
#line 265
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
#line 98 "../../src/Com/Tokenizer.fog"
        TextProc::FileLocation loc;
#line 98
        TextProc::FileLocation end;
        int type;
        Text::String str_value;
        int spaces;
        
        Token();
        Token(const Token& t);
#line 107
        inline bool operator!= (const Token& t) const;
#line 105
        void operator= (const Token& t);
        bool operator== (const Token& t) const;
#line 157
        Text::String AsString() const;
#line 109
        inline Text::String GetString() const;
#line 161
        inline Text::String GetTextValue() const;
#line 110
        inline Text::String GetTypeString() const;
#line 108
        inline bool IsType(int i) const;
        
#line 162
        static Text::String StaticGetTextValue(int type, Text::String str_value);
#line 111
        static Text::String StaticGetTypeString(int type);
    };
    
    class Tokenizer
    {
#line 213
        TextProc::FileLocation loc;
        int cursor;
        Text::String input;
        bool skip_comments;
        bool skip_newlines;
        bool skip_separateunary;
        int pass_cursor;
#line 221
        int tab_size;
        
    protected:
#line 225
        Container::Vector < Token > tokens;
        
    public:
#line 259
        Container::Vector < ProcMsg > messages;
        
    public:
#line 337
        Tokenizer();
#line 242
        void Dump() const;
#line 249
        inline int GetPassCursor() const;
#line 244
        inline const Container::Vector < Token > & GetTokens() const;
#line 361
        bool IsToken(int tk);
#line 392
        bool Load(Text::String str, Text::String path);
#line 356
        void PassToken(int tk);
#line 387
        double ReadDouble();
#line 377
        Text::String ReadId();
#line 382
        Lang::int64 ReadInt();
#line 372
        Text::String ReadString();
#line 246
        inline void Remove(int i);
#line 240
        inline void SetTabSize(int i);
#line 237
        inline void SkipComments(bool b = true);
        inline void SkipNewLines(bool b = true);
        inline void SkipSeparateUnary(bool b = true);
#line 366
        bool TryPassToken(int tk);
        
    protected:
#line 341
        Token& Add(int token_id);
#line 231
        void AddError(TextProc::FileLocation loc, Text::String msg);
        void AddWarning(TextProc::FileLocation loc, Text::String msg);
#line 834
        void AppendString(Text::String& s);
#line 227
        inline void Next();
    };
    
    class CBase
    {
    public:
#line 280
        typedef CBase CLASSNAME;
        
    private:
#line 271
        typedef TextProc::Tokenizer Toknzr;
        
        const Container::Vector < Token > *tokens;
        int pos;
#line 276
        bool ignore_newline;
#line 278
        Container::One < Toknzr > t;
        
    public:
        CBase();
        CBase(Text::String s);
        CBase(const Container::Vector < Token > & tokens);
#line 911
        const Token& GetCurrent() const;
#line 927
        TextProc::FileLocation GetLocation() const;
#line 297
        Pos GetPos();
#line 294
        int GetTokenCount() const;
        inline int GetTokenPos() const;
#line 288
        inline const Container::Vector < Token > & GetTokens() const;
#line 957
        bool Id(Text::String id);
#line 919
        void IgnoreNewline(bool b);
#line 923
        bool IsEnd() const;
#line 984
        bool IsId() const;
#line 988
        bool IsInt() const;
#line 992
        bool IsType(int i) const;
#line 906
        void Load(const Container::Vector < Token > & tokens);
#line 975
        bool Newline();
#line 290
        inline void Next();
#line 308
        void PassId(Text::String s);
#line 950
        void PassNewline();
#line 307
        void PassType(int i);
#line 931
        Text::String ReadId();
#line 939
        int ReadInt();
#line 298
        void SetPos(const Pos& p);
#line 291
        inline void SkipTerm();
#line 319
        inline void ThrowError(Text::String msg);
#line 966
        bool Type(int i);
    };
};

namespace TextProc
{
#line 295
    inline int CBase::GetTokenPos() const
    {
#line 295
        return pos;
    };
    
#line 288
    inline const Container::Vector < Token > & CBase::GetTokens() const
    {
#line 288
        return *tokens;
    };
    
#line 290
    inline void CBase::Next()
    {
#line 290
        pos ++ ;
    };
    
#line 291
    inline void CBase::SkipTerm()
    {
#line 291
        pos ++ ;
    };
    
#line 319
    inline void CBase::ThrowError(Text::String msg)
    {
#line 319
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
    
#line 265 "../../src/Com/Tokenizer.fog"
    inline Pos::Pos()
    :
        pos(- 1)
    {};
    
#line 266
    inline Pos::Pos(const Pos& p)
    :
        pos(p.pos)
    {};
    
#line 267
    inline bool Pos::Is() const
    {
#line 267
        return pos >= 0;
    };
    
#line 34 "../../src/Com/CompilerBase.fog"
    inline ProcMsg::ProcMsg()
    :
        severity(0)
    {};
    
#line 107 "../../src/Com/Tokenizer.fog"
    inline bool Token::operator!= (const Token& t) const
    {
#line 107
        return !(t == *this);
    };
    
#line 109
    inline Text::String Token::GetString() const
    {
#line 109
        return str_value;
    };
    
#line 161
    inline Text::String Token::GetTextValue() const
    {
#line 161
        return StaticGetTextValue(type, str_value);
    };
    
#line 110
    inline Text::String Token::GetTypeString() const
    {
#line 110
        return StaticGetTypeString(type);
    };
    
#line 108
    inline bool Token::IsType(int i) const
    {
#line 108
        return type == i;
    };
    
#line 249
    inline int Tokenizer::GetPassCursor() const
    {
#line 249
        return pass_cursor;
    };
    
#line 244
    inline const Container::Vector < Token > & Tokenizer::GetTokens() const
    {
#line 244
        return tokens;
    };
    
#line 227
    inline void Tokenizer::Next()
    {
#line 227
        loc.col ++ ;
#line 227
        cursor ++ ;
    };
    
#line 246
    inline void Tokenizer::Remove(int i)
    {
#line 246
        tokens.Remove(i);
    };
    
#line 240
    inline void Tokenizer::SetTabSize(int i)
    {
#line 240
        tab_size = i;
    };
    
#line 237
    inline void Tokenizer::SkipComments(bool b)
    {
#line 237
        skip_comments = b;
    };
    
#line 238
    inline void Tokenizer::SkipNewLines(bool b)
    {
#line 238
        skip_newlines = b;
    };
    
#line 239
    inline void Tokenizer::SkipSeparateUnary(bool b)
    {
#line 239
        skip_separateunary = b;
    };
    
};

#endif
