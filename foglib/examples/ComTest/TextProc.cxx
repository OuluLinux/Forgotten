#ifndef TEXTPROC_CXX
#define TEXTPROC_CXX

#include <new>

#ifndef TEXTPROC_HXX
#include <TextProc.hxx>
#endif

namespace TextProc
{
#line 281 "../../src/Com/Tokenizer.fog"
    CBase::CBase()
    :
        tokens(0),
        pos(0),
        ignore_newline(true)
    {};
    
#line 282
    CBase::CBase(Text::String s)
    :
        tokens(0),
        pos(0),
        ignore_newline(true)
    {
#line 282
        t.Create();
#line 282
        t -> Load(s, "cparser");
#line 282
        Load(t -> GetTokens());
    };
    
#line 283
    CBase::CBase(const Container::Vector < Token > & tokens)
    :
        tokens(0),
        pos(0),
        ignore_newline(true)
    {
#line 283
        Load(tokens);
    };
    
#line 911
    const Token& CBase::GetCurrent() const
    {
#line 912
        if (!tokens)
            throw InputExc("No token vector set");
        if (pos < 0 || pos >= tokens -> GetCount())
            throw InputExc("Invalid token position");
        return(*tokens)[pos];
    };
    
#line 927
    TextProc::FileLocation CBase::GetLocation() const
    {
#line 928
        return GetCurrent().loc;
    };
    
#line 297
    Pos CBase::GetPos()
    {
#line 297
        Pos p;
#line 297
        p.pos = pos;
#line 297
        return p;
    };
    
#line 294
    int CBase::GetTokenCount() const
    {
#line 294
        if (tokens)
#line 294
            return tokens -> GetCount();
        else
#line 294
            return 0;
    };
    
#line 957
    bool CBase::Id(Text::String id)
    {
#line 958
        const Token & tk = GetCurrent();
        if (tk.IsType(TK_ID) && tk.str_value == id)
        {
#line 960
            pos ++ ;
            return true;
        }
        return false;
    };
    
#line 919
    void CBase::IgnoreNewline(bool b)
    {
#line 920
        ignore_newline = b;
    };
    
    bool CBase::IsEnd() const
    {
#line 924
        return !tokens || pos >= tokens -> GetCount();
    };
    
#line 984
    bool CBase::IsId() const
    {
#line 985
        return GetCurrent().IsType(TK_ID);
    };
    
    bool CBase::IsInt() const
    {
#line 989
        return GetCurrent().IsType(TK_INTEGER);
    };
    
    bool CBase::IsType(int i) const
    {
#line 993
        return GetCurrent().IsType(i);
    };
    
#line 906
    void CBase::Load(const Container::Vector < Token > & tokens)
    {
#line 907
        this -> tokens = &tokens;
        pos = 0;
    };
    
#line 975
    bool CBase::Newline()
    {
#line 976
        const Token & tk = GetCurrent();
        if (tk.IsType(TK_NEWLINE))
        {
#line 978
            pos ++ ;
            return true;
        }
        return false;
    };
    
#line 308
    void CBase::PassId(Text::String s)
    {
#line 309
        if (IsType(TextProc::TK_ID) && GetCurrent().GetString() == s)
            Next();
        else
            throw InputExc((Text::String)"Expected id '" + s + "'");
    };
    
#line 950
    void CBase::PassNewline()
    {
#line 951
        const Token & tk = GetCurrent();
        if (tk.IsType(TK_NEWLINE))
            throw InputExc("Token is not newline");
        pos ++ ;
    };
    
#line 307
    void CBase::PassType(int i)
    {
#line 307
        if (!Type(i))
        {
#line 307
            throw InputExc((Text::String)"Expected type '" + Token::StaticGetTypeString(i) + "'");
        }
    };
    
#line 931
    Text::String CBase::ReadId()
    {
#line 932
        const Token & tk = GetCurrent();
        if (!tk.IsType(TK_ID))
            throw InputExc("Token is not id");
        pos ++ ;
        return tk.str_value;
    };
    
    int CBase::ReadInt()
    {
#line 940
        const Token & tk = GetCurrent();
        pos ++ ;
        if (tk.IsType(TextProc::TK_BIN))
#line 942
            return Text::String::BinInt(tk.str_value);
        if (tk.IsType(TextProc::TK_OCT))
#line 943
            return Text::String::OctInt(tk.str_value);
        if (tk.IsType(TextProc::TK_HEX))
#line 944
            return Text::String::HexInt(tk.str_value);
        if (tk.IsType(TextProc::TK_INTEGER))
#line 945
            return Text::String::StrInt(tk.str_value);
        pos -- ;
        throw InputExc("Token is not int");
    };
    
#line 298
    void CBase::SetPos(const Pos& p)
    {
        {
#line 298
            if (!(tokens && p.pos >= 0 && p.pos < tokens -> GetCount()))
            {
#line 298
                Lang::SysBreak("Assertion failed: tokens && p.pos >= 0 && p.pos < tokens->GetCount()");
            }
        }
#line 298
        ;
#line 298
        pos = p.pos;
    };
    
#line 966
    bool CBase::Type(int i)
    {
#line 967
        const Token & tk = GetCurrent();
        if (tk.IsType(i))
        {
#line 969
            pos ++ ;
            return true;
        }
        return false;
    };
    
#line 20 "../../src/Com/CompilerBase.fog"
    bool FileLocation::operator== (const FileLocation& t) const
    {
#line 8
        return Lang::Memory::Compare(this, &t, sizeof (FileLocation)) == 0;
    };
    
#line 8 "../../src/Com/JSON.fog"
    Interface::Value JSON::ParseArray(Tokenizer& tk)
    {
#line 9
        Interface::Value ret;
        Interface::ValueArray & arr = ret.CreateArray();
#line 12
        tk.PassToken('[');
#line 14
        while (!tk.IsToken(']'))
            {
                if (tk.IsToken(TextProc::TK_BRACKET_BEGIN))
                {
#line 17
                    arr.Add(ParseMap(tk));
                }
                else 
#line 19
                if (tk.IsToken(TextProc::TK_SQUARE_BEGIN))
                {
#line 20
                    arr.Add(ParseArray(tk));
                }
                else 
#line 22
                if (tk.IsToken(TextProc::TK_ID))
                {
#line 23
                    Text::String value = tk.ReadId();
                    if (value == "true")
                        arr.AddAsValue(true);
                    else 
#line 26
                    if (value == "false")
                        arr.AddAsValue(false);
                    else
                        arr.AddAsValue(value);
                }
                else 
#line 31
                if (tk.IsToken(TextProc::TK_INTEGER))
                {
#line 32
                    Lang::int64 value = tk.ReadInt();
                    arr.AddAsValue(value);
                }
                else 
#line 35
                if (tk.IsToken(TextProc::TK_FLOAT) || tk.IsToken(TextProc::TK_DOUBLE))
                {
#line 36
                    double value = tk.ReadDouble();
                    arr.AddAsValue(value);
                }
                else 
#line 39
                if (tk.IsToken(TextProc::TK_STRING))
                {
#line 40
                    Text::String value = tk.ReadString();
                    arr.AddAsValue(value);
                }
                else
                {
#line 44
                    throw Text::Exc("Unexpected token");
                }
#line 47
                tk.TryPassToken(TextProc::TK_COMMA);
            }
#line 50
        tk.PassToken(']');
#line 52
        return ret;
    };
    
#line 115
    Interface::Value JSON::ParseJSON(Text::String json)
    {
#line 116
        Interface::Value v;
#line 118
        Tokenizer tk;
        tk.SkipComments();
        tk.SkipNewLines();
        tk.SkipSeparateUnary();
#line 123
        if (!tk.Load(json, "json"))
        {
            {
#line 124
                Util::Log() << "Warning: Json tokenization failed" << "\n";
#line 124
                Util::Log().Flush();
            }
#line 125
            ;
#line 125
            for (int i = 0; i < tk.messages.GetCount(); i ++ )
                {
#line 126
                    ProcMsg & e = tk.messages[i];
                    {
#line 127
                        Util::Log() << "\t" << i << ": " << e.line << ":" << e.col << ": " << e.msg << "\n";
#line 127
                        Util::Log().Flush();
                    }
#line 128
                    ;
                }
        }
        try
        {
#line 132
            v = ParseMap(tk);
        }
        catch (Text::Exc e)
        {
#line 135
            tk.Dump();
            {
#line 136
                Util::Log() << "Error: Json parsing failed at " << tk.GetPassCursor() << ": " << e << "\n";
#line 136
                Util::Log().Flush();
            }
#line 137
            ;
        }
        return v;
    };
    
#line 55
    Interface::Value JSON::ParseMap(Tokenizer& tk)
    {
#line 56
        Interface::Value ret;
        Interface::ValueMap & vm = ret.CreateMap();
#line 59
        tk.PassToken(TextProc::TK_BRACKET_BEGIN);
#line 61
        while (!tk.IsToken(TextProc::TK_BRACKET_END))
            {
#line 62
                Text::String key;
                if (tk.IsToken(TextProc::TK_ID))
                    key = tk.ReadId();
                else
                    key = tk.ReadString();
#line 68
                if (tk.IsToken(TextProc::TK_COMMA) || tk.IsToken(TextProc::TK_BRACKET_END))
                {
#line 69
                    tk.TryPassToken(TextProc::TK_COMMA);
                    vm.Add(key);
                    continue;
                
                }
                tk.PassToken(TextProc::TK_COLON);
#line 76
                if (tk.IsToken(TextProc::TK_BRACKET_BEGIN))
                {
#line 77
                    vm.Add(key, ParseMap(tk));
                }
                else 
#line 79
                if (tk.IsToken(TextProc::TK_SQUARE_BEGIN))
                {
#line 80
                    vm.Add(key, ParseArray(tk));
                }
                else 
#line 82
                if (tk.IsToken(TextProc::TK_ID))
                {
#line 83
                    Text::String value = tk.ReadId();
                    if (value == "true")
                        vm.AddAsValue(key, true);
                    else 
#line 86
                    if (value == "false")
                        vm.AddAsValue(key, false);
                    else
                        vm.AddAsValue(key, value);
                }
                else 
#line 91
                if (tk.IsToken(TextProc::TK_INTEGER))
                {
#line 92
                    Lang::int64 value = tk.ReadInt();
                    vm.AddAsValue(key, value);
                }
                else 
#line 95
                if (tk.IsToken(TextProc::TK_FLOAT) || tk.IsToken(TextProc::TK_DOUBLE))
                {
#line 96
                    double value = tk.ReadDouble();
                    vm.AddAsValue(key, value);
                }
                else 
#line 99
                if (tk.IsToken(TextProc::TK_STRING))
                {
#line 100
                    Text::String value = tk.ReadString();
                    vm.AddAsValue(key, value);
                }
                else
                {
#line 104
                    throw Text::Exc("Unexpected token");
                }
#line 107
                tk.TryPassToken(TextProc::TK_COMMA);
            }
#line 110
        tk.PassToken(TextProc::TK_BRACKET_END);
#line 112
        return ret;
    };
    
#line 36 "../../src/Com/CompilerBase.fog"
    ProcMsg::ProcMsg(Text::String source, FileLocation loc, int severity, Text::String msg)
    :
        severity(0)
    {
#line 37
        src = source;
        SetFileLocation(loc);
        this -> severity = severity;
        this -> msg = msg;
    };
    
#line 35
    ProcMsg::ProcMsg(const ProcMsg& e)
    :
        severity(0)
    {
#line 35
        *this = e;
    };
    
#line 45
    void ProcMsg::operator= (const ProcMsg& e)
    {
#line 46
        msg = e.msg;
        file = e.file;
        src = e.src;
        line = e.line;
        col = e.col;
        severity = e.severity;
    };
    
#line 43
    bool ProcMsg::operator== (const ProcMsg& t) const
    {
#line 8
        return Lang::Memory::Compare(this, &t, sizeof (ProcMsg)) == 0;
    };
    
#line 61
    Text::String ProcMsg::AsString() const
    {
#line 62
        Text::String s;
        s << src << ": " << file << ":" << line << ":" << col << ": " << GetSeverityString() << ": " << msg;
#line 69
        return s;
    };
    
    Text::String ProcMsg::GetSeverityString() const
    {
#line 73
        switch (severity)
        {
#line 74
            case PROCMSG_SKIP:
#line 74
                return "skip";
            case PROCMSG_INFO:
#line 75
                return "info";
            case PROCMSG_WARNING:
#line 76
                return "warning";
            case PROCMSG_ERROR:
#line 77
                return "error";
            default:
#line 78
                return "<invalid severity>";
        }
    };
    
#line 54
    void ProcMsg::Set(Text::String source, FileLocation loc, int severity, Text::String msg)
    {
#line 55
        this -> src = source;
        SetFileLocation(loc);
        this -> severity = severity;
        this -> msg = msg;
    };
    
#line 103 "../../src/Com/Tokenizer.fog"
    Token::Token()
    :
        type(0),
        spaces(0)
    {};
    
#line 104
    Token::Token(const Token& t)
    :
        type(0),
        spaces(0)
    {
#line 104
        *this = t;
    };
    
#line 105
    void Token::operator= (const Token& t)
    {
#line 105
        type = t.type;
#line 105
        str_value = t.str_value;
#line 105
        loc = t.loc;
#line 105
        end = t.end;
#line 105
        spaces = t.spaces;
    };
    
#line 106
    bool Token::operator== (const Token& t) const
    {
#line 106
        return t.type == type && t.str_value == str_value && t.loc == loc && end == t.end && t.spaces == spaces;
    };
    
#line 157
    Text::String Token::AsString() const
    {
#line 158
        Text::String s = GetTypeString() + ": " + Text::EscapeString(GetTextValue());
        return s;
    };
    
    Text::String Token::StaticGetTextValue(int type, Text::String str_value)
    {
#line 163
        switch (type)
        {
#line 164
            case TK_UNKNOWN:
#line 164
                return "";
            case TK_ID:
#line 165
                return str_value;
            case TK_INTEGER:
#line 166
                return str_value;
            case TK_FLOAT:
#line 167
                return str_value;
            case TK_DOUBLE:
#line 168
                return str_value;
            case TK_EXCLAMATION:
#line 169
                return "!";
            case TK_STRING:
#line 170
                return(Text::String)"\"" + Text::EscapeString(str_value) + "\"";
            case TK_NUMBERSIGN:
#line 171
                return "#";
            case TK_PERCENT:
#line 172
                return "%";
            case TK_AMPERSAND:
#line 173
                return "&";
            case TK_BRACKET_BEGIN:
#line 174
                return "{";
            case TK_BRACKET_END:
#line 175
                return "}";
            case TK_DIV:
#line 176
                return "/";
            case TK_PARENTHESIS_BEGIN:
#line 177
                return "(";
            case TK_PARENTHESIS_END:
#line 178
                return ")";
            case TK_SQUARE_BEGIN:
#line 179
                return "[";
            case TK_SQUARE_END:
#line 180
                return "]";
            case TK_ASS:
#line 181
                return "=";
            case TK_QUESTION:
#line 182
                return "\?";
            case TK_PLUS:
#line 183
                return "+";
            case TK_SOLIDUS:
#line 184
                return "\\";
            case TK_ACCENT:
#line 185
                return "^";
            case TK_TILDE:
#line 186
                return "~";
            case TK_MUL:
#line 187
                return "*";
            case TK_CHAR:
#line 188
                return(Text::String)"'" + Text::EscapeString(str_value) + "'";
            case TK_OR:
#line 189
                return "|";
            case TK_MINUS:
#line 190
                return "-";
            case TK_SEMICOLON:
#line 191
                return ";";
            case TK_COMMA:
#line 192
                return ",";
            case TK_PUNCT:
#line 193
                return ".";
            case TK_COLON:
#line 194
                return ":";
            case TK_LESS:
#line 195
                return "<";
            case TK_GREATER:
#line 196
                return ">";
            case TK_NEWLINE:
#line 197
                return "\n";
            case TK_BLOCK_COMMENT:
#line 198
                return(Text::String)"/* " + str_value + "*/";
            case TK_COMMENT:
#line 199
                return(Text::String)"// " + str_value;
            case TK_BIN:
#line 200
                return str_value;
            case TK_HEX:
#line 201
                return str_value;
            case TK_OCT:
#line 202
                return str_value;
            case TK_DOLLARSIGN:
#line 203
                return "$";
            case TK_EOF:
#line 204
                return "EOF";
            default:
#line 205
                Util::Panic("Unhandled token type");
        }
        return "";
    };
    
#line 111
    Text::String Token::StaticGetTypeString(int type)
    {
#line 112
        switch (type)
        {
#line 113
            case TK_UNKNOWN:
#line 113
                return "<unknown>";
            case TK_ID:
#line 114
                return "id";
            case TK_INTEGER:
#line 115
                return "integer";
            case TK_FLOAT:
#line 116
                return "float";
            case TK_DOUBLE:
#line 117
                return "double";
            case TK_EXCLAMATION:
#line 118
                return "exclamation";
            case TK_STRING:
#line 119
                return "string";
            case TK_NUMBERSIGN:
#line 120
                return "number-sign";
            case TK_PERCENT:
#line 121
                return "percent";
            case TK_AMPERSAND:
#line 122
                return "ampersand";
            case TK_DIV:
#line 123
                return "divide";
            case TK_BRACKET_BEGIN:
#line 124
                return "bracket-begin";
            case TK_BRACKET_END:
#line 125
                return "bracket-end";
            case TK_PARENTHESIS_BEGIN:
#line 126
                return "parenthesis-begin";
            case TK_PARENTHESIS_END:
#line 127
                return "parenthesis-end";
            case TK_SQUARE_BEGIN:
#line 128
                return "square-begin";
            case TK_SQUARE_END:
#line 129
                return "square-end";
            case TK_ASS:
#line 130
                return "assign";
            case TK_QUESTION:
#line 131
                return "question-mark";
            case TK_PLUS:
#line 132
                return "plus";
            case TK_SOLIDUS:
#line 133
                return "solidus";
            case TK_ACCENT:
#line 134
                return "accent";
            case TK_TILDE:
#line 135
                return "tilde";
            case TK_MUL:
#line 136
                return "multiply";
            case TK_CHAR:
#line 137
                return "char";
            case TK_OR:
#line 138
                return "or";
            case TK_MINUS:
#line 139
                return "minus";
            case TK_SEMICOLON:
#line 140
                return "semicolon";
            case TK_COMMA:
#line 141
                return "comma";
            case TK_PUNCT:
#line 142
                return "punct";
            case TK_COLON:
#line 143
                return "colon";
            case TK_LESS:
#line 144
                return "less";
            case TK_GREATER:
#line 145
                return "greater";
            case TK_NEWLINE:
#line 146
                return "newline";
            case TK_BLOCK_COMMENT:
#line 147
                return "block-comment";
            case TK_COMMENT:
#line 148
                return "comment";
            case TK_BIN:
#line 149
                return "binary-number";
            case TK_HEX:
#line 150
                return "hex-number";
            case TK_OCT:
#line 151
                return "oct-number";
            case TK_INVALID:
#line 152
                return "invalid";
            case TK_EOF:
#line 153
                return "end-of-file";
        }
        return "";
    };
    
#line 337
    Tokenizer::Tokenizer()
    :
        cursor(0),
        skip_comments(false),
        skip_newlines(false),
        skip_separateunary(false),
        pass_cursor(0),
        tab_size(4)
    {};
    
#line 341
    Token& Tokenizer::Add(int token_id)
    {
#line 342
        struct Token & t = tokens.Add();
        t.loc = loc;
        t.end = loc;
        t.end.col ++ ;
        t.type = token_id;
        return t;
    };
    
#line 231
    void Tokenizer::AddError(TextProc::FileLocation loc, Text::String msg)
    {
#line 231
        messages.Add().Set("Tokenizer", loc, PROCMSG_ERROR, msg);
    };
    
#line 232
    void Tokenizer::AddWarning(TextProc::FileLocation loc, Text::String msg)
    {
#line 232
        messages.Add().Set("Tokenizer", loc, PROCMSG_WARNING, msg);
    };
    
#line 834
    void Tokenizer::AppendString(Text::String& s)
    {
#line 835
        int chr = input[cursor];
        if (chr == '\\')
        {
#line 837
            int chr1;
            if (cursor + 1 < input.GetCount())
#line 838
                chr1 = input[cursor + 1];
            else
#line 839
                chr1 = 0;
            if (chr1 == '\'')
            {
#line 841
                Next();
#line 841
                Next();
                s.Cat(0x27);
            }
            else 
#line 844
            if (chr1 == '"')
            {
#line 845
                Next();
#line 845
                Next();
                s.Cat(0x22);
            }
            else 
#line 848
            if (chr1 == '\?')
            {
#line 849
                Next();
#line 849
                Next();
                s.Cat(0x3F);
            }
            else 
#line 852
            if (chr1 == '\\')
            {
#line 853
                Next();
#line 853
                Next();
                s.Cat(0x5c);
            }
            else 
#line 856
            if (chr1 == 'a')
            {
#line 857
                Next();
#line 857
                Next();
                s.Cat(0x07);
            }
            else 
#line 860
            if (chr1 == 'b')
            {
#line 861
                Next();
#line 861
                Next();
                s.Cat(0x08);
            }
            else 
#line 864
            if (chr1 == 'f')
            {
#line 865
                Next();
#line 865
                Next();
                s.Cat(0x0c);
            }
            else 
#line 868
            if (chr1 == 'n')
            {
#line 869
                Next();
#line 869
                Next();
                s.Cat(0x0a);
            }
            else 
#line 872
            if (chr1 == 'r')
            {
#line 873
                Next();
#line 873
                Next();
                s.Cat(0x0d);
            }
            else 
#line 876
            if (chr1 == 't')
            {
#line 877
                Next();
#line 877
                Next();
                s.Cat(0x09);
            }
            else 
#line 880
            if (chr1 == 'v')
            {
#line 881
                Next();
#line 881
                Next();
                s.Cat(0x0b);
            }
            else
            {
#line 885
                s.Cat(chr);
                Next();
            }
        }
        else
        {
#line 890
            s.Cat(chr);
            Next();
        }
    };
    
#line 242
    void Tokenizer::Dump() const
    {
        {
            {
#line 242
                Util::Log() << "tokens" << " {" << "\n";
#line 242
                Util::Log().Flush();
            }
#line 242
            ;
#line 242
            for (int i = 0; i < tokens.GetCount(); i ++ )
                {
#line 242
                    Util::Log() << "\t[" << i << "]: " << Text::ToString(tokens[i]) << "\n";
#line 242
                    Util::Log().Flush();
                }
#line 242
            ;
            {
#line 242
                Util::Log() << "}" << "\n";
#line 242
                Util::Log().Flush();
            }
#line 242
            ;
        }
#line 242
        ;
    };
    
#line 361
    bool Tokenizer::IsToken(int tk)
    {
#line 362
        if (pass_cursor >= tokens.GetCount())
#line 362
            return false;
        return tokens[pass_cursor].type == tk;
    };
    
#line 392
    bool Tokenizer::Load(Text::String str, Text::String path)
    {
#line 393
        input = str;
#line 395
        loc.file = path;
        loc.line = 1;
        loc.col = 1;
#line 399
        cursor = 0;
#line 401
        while (cursor < input.GetCount())
            {
#line 402
                int chr = input[cursor];
#line 404
                if (Text::IsAlpha(chr) || chr == '_')
                {
#line 405
                    Token & t = Add(TK_ID);
                    t.str_value.Cat(chr);
                    Next();
                    while (cursor < input.GetCount())
                        {
#line 409
                            int chr = input[cursor];
                            if (Text::IsAlpha(chr) || chr == '_' || Text::IsDigit(chr))
                            {
#line 411
                                t.str_value.Cat(chr);
                                Next();
                            }
                            else
                                break;
                        
                        }
#line 417
                    t.end = loc;
                }
                else 
#line 419
                if (Text::IsDigit(chr))
                {
#line 420
                    Text::String n;
                    if (skip_separateunary && tokens.GetCount())
                    {
#line 422
                        while (tokens.GetCount() && tokens.Top().IsType(TK_MINUS))
                            {
#line 423
                                tokens.Pop();
                                n.Cat('-');
                            }
                        while (tokens.GetCount() && tokens.Top().IsType(TK_PLUS))
                            {
#line 427
                                tokens.Pop();
                            }
                    }
                    Token & tk = Add(TK_INTEGER);
                    bool is_double = false;
#line 431
                    bool is_float = false;
                    n.Cat(chr);
                    Next();
                    int exp;
                    if (chr == '0')
#line 435
                        exp = FP_OCTHEX;
                    else
#line 436
                        exp = FP_INT;
                    while (cursor < input.GetCount())
                        {
#line 438
                            int chr = input[cursor];
                            bool cat = false;
#line 441
                            if (exp == FP_INT)
                            {
#line 442
                                if (Text::IsDigit(chr))
                                    cat = true;
                                else 
#line 444
                                if (chr == '.')
                                {
#line 445
                                    exp = FP_FRAC;
                                    cat = true;
                                    is_double = true;
                                }
                                else 
#line 449
                                if (chr == 'e' || chr == 'E')
                                {
#line 450
                                    exp = FP_SIGN;
                                    cat = true;
                                    is_double = true;
                                }
                            }
                            else 
#line 455
                            if (exp == FP_FRAC)
                            {
#line 456
                                if (Text::IsDigit(chr))
                                    cat = true;
                                else 
#line 458
                                if (chr == 'e' || chr == 'E')
                                {
#line 459
                                    exp = FP_SIGN;
                                    cat = true;
                                    is_double = true;
                                }
                            }
                            else 
#line 464
                            if (exp == FP_SIGN)
                            {
#line 465
                                if (chr == '+' || chr == '-' || Text::IsDigit(chr))
                                {
#line 466
                                    exp = FP_EXP;
                                    cat = true;
                                }
                                else 
#line 469
                                if (chr == 'f' || chr == 'F')
                                {
#line 470
                                    exp = FP_END;
                                    cat = true;
                                    is_float = true;
                                }
                            }
                            else 
#line 475
                            if (exp == FP_EXP)
                            {
#line 476
                                if (Text::IsDigit(chr))
                                    cat = true;
                                else 
#line 478
                                if (chr == 'f' || chr == 'F')
                                {
#line 479
                                    exp = FP_END;
                                    cat = true;
                                    is_float = true;
                                }
                            }
                            else 
#line 484
                            if (exp == FP_OCTHEX)
                            {
#line 485
                                if (chr == 'b' || chr == 'B')
                                {
#line 486
                                    exp = FP_BIN;
                                    cat = true;
                                }
                                else 
#line 489
                                if (chr == 'x' || chr == 'X')
                                {
#line 490
                                    exp = FP_HEX;
                                    cat = true;
                                }
                                else 
#line 493
                                if (chr >= '0' && chr <= '7')
                                {
#line 494
                                    exp = FP_OCT;
                                    cat = true;
                                }
                                else 
#line 497
                                if (chr == '.')
                                {
#line 498
                                    exp = FP_FRAC;
                                    cat = true;
                                    is_double = true;
                                }
                            }
                            else 
#line 503
                            if (exp == FP_HEX)
                            {
#line 504
                                if ((chr >= '0' && chr <= '9') || (chr >= 'a' && chr <= 'f') || (chr >= 'A' && chr <= 'F'))
                                {
#line 507
                                    cat = true;
                                }
                            }
                            else 
#line 510
                            if (exp == FP_OCT)
                            {
#line 511
                                if (chr >= '0' && chr <= '7')
                                {
#line 512
                                    cat = true;
                                }
                            }
#line 516
                            if (cat)
                            {
#line 517
                                Next();
                                n.Cat(chr);
                                if (exp == FP_END)
#line 519
                                    break;
                            
                            }
                            else
#line 521
                                break;
                        
                        }
                    tk.str_value = n;
#line 526
                    if (exp == FP_BIN)
#line 526
                        tk.type = TK_BIN;
                    else 
#line 527
                    if (exp == FP_HEX)
#line 527
                        tk.type = TK_HEX;
                    else 
#line 528
                    if (exp == FP_OCT)
#line 528
                        tk.type = TK_OCT;
                    else 
#line 529
                    if (is_double)
                    {
#line 530
                        if (!is_float)
                            tk.type = TK_DOUBLE;
                        else
                            tk.type = TK_FLOAT;
                    }
#line 536
                    tk.end = loc;
                }
                else 
#line 538
                if (chr == '!')
                {
#line 539
                    Token & tk = Add(TK_EXCLAMATION);
                    Next();
                    tk.end = loc;
                }
                else 
#line 543
                if (chr == '"')
                {
#line 544
                    Token & tk = Add(TK_STRING);
                    int begin_line = loc.line;
                    int begin_col = loc.col;
                    Next();
                    Text::String str;
                    bool success = false;
                    while (cursor < input.GetCount())
                        {
#line 551
                            int chr = input[cursor];
                            Text::String tmp;
                            tmp.Cat(chr);
                            if (chr == '\n')
                            {
#line 555
                                AddError(tk.loc, "no newline allowed in string literal");
                                Next();
                                loc.line ++ ;
                                loc.col = 1;
                            }
                            else 
#line 560
                            if (chr == '"')
                            {
#line 561
                                Next();
                                success = true;
                                break;
                            
                            }
                            else 
#line 565
                            if (chr == '\\')
                            {
#line 566
                                AppendString(str);
                            }
                            else
                            {
#line 569
                                str.Cat(chr);
                                Next();
                            }
                        }
                    tk.end = loc;
#line 575
                    if (success)
                    {
#line 576
                        tk.str_value = str;
                    }
                    else
                    {
#line 579
                        AddError(tk.loc, "no finishing \" in string literal");
                        return false;
                    }
                }
                else 
#line 583
                if (chr == '#')
                {
#line 584
                    Token & tk = Add(TK_NUMBERSIGN);
                    Next();
                    tk.end = loc;
                }
                else 
#line 588
                if (chr == '%')
                {
#line 589
                    Token & tk = Add(TK_PERCENT);
                    Next();
                    tk.end = loc;
                }
                else 
#line 593
                if (chr == '&')
                {
#line 594
                    Token & tk = Add(TK_AMPERSAND);
                    Next();
                    tk.end = loc;
                }
                else 
#line 598
                if (chr == '/')
                {
#line 599
                    int begin_line = loc.line;
                    int begin_col = loc.col;
                    int chr1;
                    if (cursor + 1 < input.GetCount())
#line 602
                        chr1 = input[cursor + 1];
                    else
#line 603
                        chr1 = 0;
                    if (chr1 == '*')
                    {
#line 605
                        Token * tk = 0;
                        if (!skip_comments)
                            tk = &Add(TK_BLOCK_COMMENT);
                        Next();
                        Next();
                        Text::String c;
                        bool succ = false;
                        while (cursor < input.GetCount())
                            {
#line 613
                                chr = input[cursor];
                                if (chr == '*')
                                {
#line 615
                                    if (cursor + 1 < input.GetCount())
#line 615
                                        chr1 = input[cursor + 1];
                                    else
#line 616
                                        chr1 = 0;
                                    if (chr1 == '/')
                                    {
#line 618
                                        Next();
                                        Next();
                                        if (tk)
#line 620
                                            tk -> str_value = c;
                                        succ = true;
                                        break;
                                    
                                    }
                                    else
#line 624
                                        c.Cat(chr);
                                }
                                else
#line 626
                                    c.Cat(chr);
                                Next();
                            }
                        if (tk)
                        {
#line 630
                            tk -> end = loc;
                            if (!succ)
                                AddError(tk -> loc, "unterminated /* comment");
                        }
                    }
                    else 
#line 635
                    if (chr1 == '/')
                    {
#line 636
                        Token * tk = 0;
                        if (!skip_comments)
                            tk = &Add(TK_COMMENT);
                        Next();
                        Next();
                        Text::String c;
                        while (cursor < input.GetCount())
                            {
#line 643
                                chr = input[cursor];
                                if (chr == '\n')
                                {
#line 645
                                    if (tk)
#line 645
                                        tk -> str_value = c;
                                    break;
                                
                                }
                                else
#line 648
                                    c.Cat(chr);
                                Next();
                            }
                        if (tk)
#line 651
                            tk -> end = loc;
                    }
                    else
                    {
#line 654
                        Token & tk = Add(TK_DIV);
                        Next();
                        tk.end = loc;
                    }
                }
                else 
#line 659
                if (chr == '{')
                {
#line 660
                    Add(TK_BRACKET_BEGIN);
                    Next();
                }
                else 
#line 663
                if (chr == '}')
                {
#line 664
                    Add(TK_BRACKET_END);
                    Next();
                }
                else 
#line 667
                if (chr == '(')
                {
#line 668
                    Add(TK_PARENTHESIS_BEGIN);
                    Next();
                }
                else 
#line 671
                if (chr == ')')
                {
#line 672
                    Add(TK_PARENTHESIS_END);
                    Next();
                }
                else 
#line 675
                if (chr == '[')
                {
#line 676
                    Add(TK_SQUARE_BEGIN);
                    Next();
                }
                else 
#line 679
                if (chr == ']')
                {
#line 680
                    Add(TK_SQUARE_END);
                    Next();
                }
                else 
#line 683
                if (chr == '=')
                {
#line 684
                    Add(TK_ASS);
                    Next();
                }
                else 
#line 687
                if (chr == '+')
                {
#line 688
                    Add(TK_PLUS);
                    Next();
                }
                else 
#line 691
                if (chr == '\?')
                {
#line 692
                    Add(TK_QUESTION);
                    Next();
                }
                else 
#line 695
                if (chr == '\\')
                {
#line 696
                    Add(TK_SOLIDUS);
                    Next();
                }
                else 
#line 699
                if (chr == '^')
                {
#line 700
                    Add(TK_ACCENT);
                    Next();
                }
                else 
#line 703
                if (chr == '~')
                {
#line 704
                    Add(TK_TILDE);
                    Next();
                }
                else 
#line 707
                if (chr == '*')
                {
#line 708
                    Add(TK_MUL);
                    Next();
                }
                else 
#line 711
                if (chr == '@')
                {
#line 712
                    Add(TK_AT);
                    Next();
                }
                else 
#line 715
                if (chr == '\'')
                {
#line 716
                    Token & tk = Add(TK_CHAR);
                    Next();
                    Text::String str;
                    bool success = false;
                    while (cursor < input.GetCount())
                        {
#line 721
                            int chr = input[cursor];
                            if (chr == '\n')
                            {
#line 723
                                AddError(tk.loc, "no newline allowed in char literal");
                                Next();
                                loc.line ++ ;
                                loc.col = 1;
                            }
                            else 
#line 728
                            if (chr == '\'')
                            {
#line 729
                                Next();
                                success = true;
                                break;
                            
                            }
                            else 
#line 733
                            if (chr == '\\')
                            {
#line 734
                                AppendString(str);
                            }
                            else
                            {
#line 737
                                str.Cat(chr);
                                Next();
                            }
                        }
                    tk.end = loc;
#line 743
                    if (success)
                    {
#line 744
                        tk.str_value = str;
                    }
                    else
                    {
#line 747
                        AddError(tk.loc, "no finishing ' in char literal");
                        return false;
                    }
                }
                else 
#line 751
                if (chr == '-')
                {
#line 752
                    Add(TK_MINUS);
                    Next();
                }
                else 
#line 755
                if (chr == ';')
                {
#line 756
                    Add(TK_SEMICOLON);
                    Next();
                }
                else 
#line 759
                if (chr == ',')
                {
#line 760
                    Add(TK_COMMA);
                    Next();
                }
                else 
#line 763
                if (chr == '.')
                {
#line 764
                    Add(TK_PUNCT);
                    Next();
                }
                else 
#line 767
                if (chr == ':')
                {
#line 768
                    Add(TK_COLON);
                    Next();
                }
                else 
#line 771
                if (chr == '<')
                {
#line 772
                    Add(TK_LESS);
                    Next();
                }
                else 
#line 775
                if (chr == '>')
                {
#line 776
                    Add(TK_GREATER);
                    Next();
                }
                else 
#line 779
                if (chr == '|')
                {
#line 780
                    Add(TK_OR);
                    Next();
                }
                else 
#line 783
                if (chr == '\n')
                {
#line 784
                    if (!skip_newlines)
                    {
#line 785
                        Token & tk = Add(TK_NEWLINE);
                        tk.end.col = 1;
#line 786
                        tk.end.line ++ ;
                    }
                    Next();
                    loc.line ++ ;
                    loc.col = 1;
                }
                else 
#line 792
                if (chr == '\t')
                {
#line 793
                    if (!tokens.IsEmpty())
                        tokens.Top().spaces += tab_size;
                    Next();
                    loc.col += tab_size - 1;
                }
                else 
#line 798
                if (Text::IsSpace(chr))
                {
#line 799
                    if (!tokens.IsEmpty())
                        tokens.Top().spaces ++ ;
                    Next();
                }
                else 
#line 803
                if (chr == 0)
                    break;
                
                else
                {
#line 806
                    Lang::byte b = chr;
                    if (b >= 0x80 && b <= 0xFF)
                    {
#line 808
                        Next();
                        while (cursor < input.GetCount())
                            {
#line 810
                                b = input[cursor];
                                if (b >= 0x80 && b <= 0xFF)
                                    cursor ++ ;
                                else
                                    break;
                            
                            }
                        if (!tokens.IsEmpty())
                            tokens.Top().spaces ++ ;
                    }
                    else
                    {
#line 821
                        Text::String msg = "unexpected character '";
                        msg.Cat(chr);
                        msg.Cat('\'');
                        AddError(loc, msg);
                        Next();
                    }
                }
            }
        Add(TK_EOF);
#line 831
        return messages.IsEmpty();
    };
    
#line 356
    void Tokenizer::PassToken(int tk)
    {
#line 357
        if (!IsToken(tk))
#line 357
            throw InputExc("Unexpected token");
        pass_cursor ++ ;
    };
    
#line 387
    double Tokenizer::ReadDouble()
    {
#line 388
        if (!IsToken(TK_DOUBLE) && !IsToken(TK_FLOAT))
#line 388
            throw InputExc("Unexpected token");
        return Text::String::StrDbl(tokens[pass_cursor ++ ].str_value);
    };
    
#line 377
    Text::String Tokenizer::ReadId()
    {
#line 378
        if (!IsToken(TK_ID))
#line 378
            throw InputExc("Unexpected token");
        return tokens[pass_cursor ++ ].str_value;
    };
    
    Lang::int64 Tokenizer::ReadInt()
    {
#line 383
        if (!IsToken(TK_INTEGER))
#line 383
            throw InputExc("Unexpected token");
        return Text::String::StrInt64(tokens[pass_cursor ++ ].str_value);
    };
    
#line 372
    Text::String Tokenizer::ReadString()
    {
#line 373
        if (!IsToken(TK_STRING))
#line 373
            throw InputExc("Unexpected token");
        return tokens[pass_cursor ++ ].str_value;
    };
    
#line 366
    bool Tokenizer::TryPassToken(int tk)
    {
#line 367
        if (!IsToken(tk))
#line 367
            return false;
        pass_cursor ++ ;
        return true;
    };
    
};

#endif
