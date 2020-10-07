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
#line 96 "../../src/Com/Tokenizer.fog"
        TextProc::FileLocation loc;
#line 96
        TextProc::FileLocation end;
        int type;
        Text::String str_value;
        int spaces;
        
        Token();
        Token(const Token& t);
#line 105
        inline bool operator!= (const Token& t) const;
#line 103
        void operator= (const Token& t);
        bool operator== (const Token& t) const;
#line 154
        Text::String AsString() const;
#line 107
        inline Text::String GetString() const;
#line 158
        inline Text::String GetTextValue() const;
#line 108
        inline Text::String GetTypeString() const;
#line 106
        inline bool IsType(int i) const;
        
#line 159
        static Text::String StaticGetTextValue(int type, Text::String str_value);
#line 109
        static Text::String StaticGetTypeString(int type);
    };
    
    class Tokenizer
    {
#line 209
        TextProc::FileLocation loc;
        int cursor;
        Text::String input;
        bool skip_comments;
        bool skip_newlines;
        bool skip_separateunary;
        int pass_cursor;
#line 217
        int tab_size;
        
    protected:
#line 221
        Container::Vector < Token > tokens;
        
    public:
#line 255
        Container::Vector < ProcMsg > messages;
        
    public:
#line 324
        Tokenizer();
#line 238
        void Dump() const;
#line 245
        inline int GetPassCursor() const;
#line 240
        inline const Container::Vector < Token > & GetTokens() const;
#line 348
        bool IsToken(int tk);
#line 379
        bool Load(Text::String str, Text::String path);
#line 343
        void PassToken(int tk);
#line 374
        double ReadDouble();
#line 364
        Text::String ReadId();
#line 369
        Lang::int64 ReadInt();
#line 359
        Text::String ReadString();
#line 242
        inline void Remove(int i);
#line 236
        inline void SetTabSize(int i);
#line 233
        inline void SkipComments(bool b = true);
        inline void SkipNewLines(bool b = true);
        inline void SkipSeparateUnary(bool b = true);
#line 353
        bool TryPassToken(int tk);
        
    protected:
#line 328
        Token& Add(int token_id);
#line 227
        void AddError(TextProc::FileLocation loc, Text::String msg);
        void AddWarning(TextProc::FileLocation loc, Text::String msg);
#line 818
        void AppendString(Text::String& s);
#line 223
        inline void Next();
    };
    
    class CBase
    {
    public:
#line 269
        typedef CBase CLASSNAME;
        
    private:
#line 266
        typedef TextProc::Tokenizer Toknzr;
        
#line 261
        const Container::Vector < Token > *tokens;
        int pos;
#line 264
        bool ignore_newline;
#line 267
        Container::One < Toknzr > t;
        
    public:
        CBase();
        CBase(Text::String s);
        CBase(const Container::Vector < Token > & tokens);
#line 895
        const Token& GetCurrent() const;
#line 911
        TextProc::FileLocation GetLocation() const;
#line 283
        int GetTokenCount() const;
        inline int GetTokenPos() const;
#line 277
        inline const Container::Vector < Token > & GetTokens() const;
#line 943
        bool Id(Text::String id);
#line 903
        void IgnoreNewline(bool b);
#line 907
        bool IsEnd() const;
#line 970
        bool IsId() const;
#line 974
        bool IsInt() const;
#line 978
        bool IsType(int i) const;
#line 890
        void Load(const Container::Vector < Token > & tokens);
#line 961
        bool Newline();
#line 279
        inline void Next();
#line 295
        void PassId(Text::String s);
#line 936
        void PassNewline();
#line 294
        void PassType(int i);
#line 915
        Text::String ReadId();
#line 923
        int ReadInt();
#line 280
        inline void SkipTerm();
#line 306
        inline void ThrowError(Text::String msg);
#line 952
        bool Type(int i);
    };
};

namespace TextProc
{
#line 284
    inline int CBase::GetTokenPos() const
    {
#line 284
        return pos;
    };
    
#line 277
    inline const Container::Vector < Token > & CBase::GetTokens() const
    {
#line 277
        return *tokens;
    };
    
#line 279
    inline void CBase::Next()
    {
#line 279
        pos ++ ;
    };
    
#line 280
    inline void CBase::SkipTerm()
    {
#line 280
        pos ++ ;
    };
    
#line 306
    inline void CBase::ThrowError(Text::String msg)
    {
#line 306
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
    
#line 34 "../../src/Com/CompilerBase.fog"
    inline ProcMsg::ProcMsg()
    :
        severity(0)
    {};
    
#line 105 "../../src/Com/Tokenizer.fog"
    inline bool Token::operator!= (const Token& t) const
    {
#line 105
        return !(t == *this);
    };
    
#line 107
    inline Text::String Token::GetString() const
    {
#line 107
        return str_value;
    };
    
#line 158
    inline Text::String Token::GetTextValue() const
    {
#line 158
        return StaticGetTextValue(type, str_value);
    };
    
#line 108
    inline Text::String Token::GetTypeString() const
    {
#line 108
        return StaticGetTypeString(type);
    };
    
#line 106
    inline bool Token::IsType(int i) const
    {
#line 106
        return type == i;
    };
    
#line 245
    inline int Tokenizer::GetPassCursor() const
    {
#line 245
        return pass_cursor;
    };
    
#line 240
    inline const Container::Vector < Token > & Tokenizer::GetTokens() const
    {
#line 240
        return tokens;
    };
    
#line 223
    inline void Tokenizer::Next()
    {
#line 223
        loc.col ++ ;
#line 223
        cursor ++ ;
    };
    
#line 242
    inline void Tokenizer::Remove(int i)
    {
#line 242
        tokens.Remove(i);
    };
    
#line 236
    inline void Tokenizer::SetTabSize(int i)
    {
#line 236
        tab_size = i;
    };
    
#line 233
    inline void Tokenizer::SkipComments(bool b)
    {
#line 233
        skip_comments = b;
    };
    
#line 234
    inline void Tokenizer::SkipNewLines(bool b)
    {
#line 234
        skip_newlines = b;
    };
    
#line 235
    inline void Tokenizer::SkipSeparateUnary(bool b)
    {
#line 235
        skip_separateunary = b;
    };
    
};

#endif
