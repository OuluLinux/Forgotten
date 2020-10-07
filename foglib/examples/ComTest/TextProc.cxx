#ifndef TEXTPROC_CXX
#define TEXTPROC_CXX

#include <new>

#ifndef TEXTPROC_HXX
#include <TextProc.hxx>
#endif

namespace TextProc
{
#line 270 "../../src/Com/Tokenizer.fog"
    CBase::CBase()
    :
        tokens(0),
        pos(0),
        ignore_newline(true)
    {};
    
#line 271
    CBase::CBase(Text::String s)
    :
        tokens(0),
        pos(0),
        ignore_newline(true)
    {
#line 271
        t.Create();
#line 271
        t -> Load(s, "cparser");
#line 271
        Load(t -> GetTokens());
    };
    
#line 272
    CBase::CBase(const Container::Vector < Token > & tokens)
    :
        tokens(0),
        pos(0),
        ignore_newline(true)
    {
#line 272
        Load(tokens);
    };
    
#line 895
    const Token& CBase::GetCurrent() const
    {
#line 896
        if (!tokens)
            throw InputExc("No token vector set");
        if (pos < 0 || pos >= tokens -> GetCount())
            throw InputExc("Invalid token position");
        return(*tokens)[pos];
    };
    
#line 911
    TextProc::FileLocation CBase::GetLocation() const
    {
#line 912
        return GetCurrent().loc;
    };
    
#line 283
    int CBase::GetTokenCount() const
    {
#line 283
        if (tokens)
#line 283
            return tokens -> GetCount();
        else
#line 283
            return 0;
    };
    
#line 943
    bool CBase::Id(Text::String id)
    {
#line 944
        const Token & tk = GetCurrent();
        if (tk.IsType(TK_ID) && tk.str_value == id)
        {
#line 946
            pos ++ ;
            return true;
        }
        return false;
    };
    
#line 903
    void CBase::IgnoreNewline(bool b)
    {
#line 904
        ignore_newline = b;
    };
    
    bool CBase::IsEnd() const
    {
#line 908
        return !tokens || pos >= tokens -> GetCount();
    };
    
#line 970
    bool CBase::IsId() const
    {
#line 971
        return GetCurrent().IsType(TK_ID);
    };
    
    bool CBase::IsInt() const
    {
#line 975
        return GetCurrent().IsType(TK_INTEGER);
    };
    
    bool CBase::IsType(int i) const
    {
#line 979
        return GetCurrent().IsType(i);
    };
    
#line 890
    void CBase::Load(const Container::Vector < Token > & tokens)
    {
#line 891
        this -> tokens = &tokens;
        pos = 0;
    };
    
#line 961
    bool CBase::Newline()
    {
#line 962
        const Token & tk = GetCurrent();
        if (tk.IsType(TK_NEWLINE))
        {
#line 964
            pos ++ ;
            return true;
        }
        return false;
    };
    
#line 295
    void CBase::PassId(Text::String s)
    {
#line 296
        if (IsType(TextProc::TK_ID) && GetCurrent().GetString() == s)
            Next();
        else
            throw InputExc((Text::String)"Expected id '" + s + "'");
    };
    
#line 936
    void CBase::PassNewline()
    {
#line 937
        const Token & tk = GetCurrent();
        if (tk.IsType(TK_NEWLINE))
            throw InputExc("Token is not newline");
        pos ++ ;
    };
    
#line 294
    void CBase::PassType(int i)
    {
#line 294
        if (!Type(i))
        {
#line 294
            throw InputExc((Text::String)"Expected type '" + Token::StaticGetTypeString(i) + "'");
        }
    };
    
#line 915
    Text::String CBase::ReadId()
    {
#line 916
        const Token & tk = GetCurrent();
        if (!tk.IsType(TK_ID))
            throw InputExc("Token is not id");
        pos ++ ;
        return tk.str_value;
    };
    
    int CBase::ReadInt()
    {
#line 924
        const Token & tk = GetCurrent();
        pos ++ ;
        if (tk.IsType(TK_OCT))
            return Text::String::OctInt(tk.str_value);
        if (tk.IsType(TK_HEX))
            return Text::String::HexInt(tk.str_value);
        if (tk.IsType(TK_INTEGER))
            return Text::String::StrInt(tk.str_value);
        pos -- ;
        throw InputExc("Token is not int");
    };
    
#line 952
    bool CBase::Type(int i)
    {
#line 953
        const Token & tk = GetCurrent();
        if (tk.IsType(i))
        {
#line 955
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
    
#line 101 "../../src/Com/Tokenizer.fog"
    Token::Token()
    :
        type(0),
        spaces(0)
    {};
    
#line 102
    Token::Token(const Token& t)
    :
        type(0),
        spaces(0)
    {
#line 102
        *this = t;
    };
    
#line 103
    void Token::operator= (const Token& t)
    {
#line 103
        type = t.type;
#line 103
        str_value = t.str_value;
#line 103
        loc = t.loc;
#line 103
        end = t.end;
#line 103
        spaces = t.spaces;
    };
    
#line 104
    bool Token::operator== (const Token& t) const
    {
#line 104
        return t.type == type && t.str_value == str_value && t.loc == loc && end == t.end && t.spaces == spaces;
    };
    
#line 154
    Text::String Token::AsString() const
    {
#line 155
        Text::String s = GetTypeString() + ": " + Text::EscapeString(GetTextValue());
        return s;
    };
    
    Text::String Token::StaticGetTextValue(int type, Text::String str_value)
    {
#line 160
        switch (type)
        {
#line 161
            case TK_UNKNOWN:
#line 161
                return "";
            case TK_ID:
#line 162
                return str_value;
            case TK_INTEGER:
#line 163
                return str_value;
            case TK_FLOAT:
#line 164
                return str_value;
            case TK_DOUBLE:
#line 165
                return str_value;
            case TK_EXCLAMATION:
#line 166
                return "!";
            case TK_STRING:
#line 167
                return(Text::String)"\"" + Text::EscapeString(str_value) + "\"";
            case TK_NUMBERSIGN:
#line 168
                return "#";
            case TK_PERCENT:
#line 169
                return "%";
            case TK_AMPERSAND:
#line 170
                return "&";
            case TK_BRACKET_BEGIN:
#line 171
                return "{";
            case TK_BRACKET_END:
#line 172
                return "}";
            case TK_DIV:
#line 173
                return "/";
            case TK_PARENTHESIS_BEGIN:
#line 174
                return "(";
            case TK_PARENTHESIS_END:
#line 175
                return ")";
            case TK_SQUARE_BEGIN:
#line 176
                return "[";
            case TK_SQUARE_END:
#line 177
                return "]";
            case TK_ASS:
#line 178
                return "=";
            case TK_QUESTION:
#line 179
                return "\?";
            case TK_PLUS:
#line 180
                return "+";
            case TK_SOLIDUS:
#line 181
                return "\\";
            case TK_ACCENT:
#line 182
                return "^";
            case TK_TILDE:
#line 183
                return "~";
            case TK_MUL:
#line 184
                return "*";
            case TK_CHAR:
#line 185
                return(Text::String)"'" + Text::EscapeString(str_value) + "'";
            case TK_OR:
#line 186
                return "|";
            case TK_MINUS:
#line 187
                return "-";
            case TK_SEMICOLON:
#line 188
                return ";";
            case TK_COMMA:
#line 189
                return ",";
            case TK_PUNCT:
#line 190
                return ".";
            case TK_COLON:
#line 191
                return ":";
            case TK_LESS:
#line 192
                return "<";
            case TK_GREATER:
#line 193
                return ">";
            case TK_NEWLINE:
#line 194
                return "\n";
            case TK_BLOCK_COMMENT:
#line 195
                return(Text::String)"/* " + str_value + "*/";
            case TK_COMMENT:
#line 196
                return(Text::String)"// " + str_value;
            case TK_HEX:
#line 197
                return str_value;
            case TK_OCT:
#line 198
                return str_value;
            case TK_DOLLARSIGN:
#line 199
                return "$";
            case TK_EOF:
#line 200
                return "EOF";
            default:
#line 201
                Util::Panic("Unhandled token type");
        }
        return "";
    };
    
#line 109
    Text::String Token::StaticGetTypeString(int type)
    {
#line 110
        switch (type)
        {
#line 111
            case TK_UNKNOWN:
#line 111
                return "<unknown>";
            case TK_ID:
#line 112
                return "id";
            case TK_INTEGER:
#line 113
                return "integer";
            case TK_FLOAT:
#line 114
                return "float";
            case TK_DOUBLE:
#line 115
                return "double";
            case TK_EXCLAMATION:
#line 116
                return "exclamation";
            case TK_STRING:
#line 117
                return "string";
            case TK_NUMBERSIGN:
#line 118
                return "number-sign";
            case TK_PERCENT:
#line 119
                return "percent";
            case TK_AMPERSAND:
#line 120
                return "ampersand";
            case TK_DIV:
#line 121
                return "divide";
            case TK_BRACKET_BEGIN:
#line 122
                return "bracket-begin";
            case TK_BRACKET_END:
#line 123
                return "bracket-end";
            case TK_PARENTHESIS_BEGIN:
#line 124
                return "parenthesis-begin";
            case TK_PARENTHESIS_END:
#line 125
                return "parenthesis-end";
            case TK_SQUARE_BEGIN:
#line 126
                return "square-begin";
            case TK_SQUARE_END:
#line 127
                return "square-end";
            case TK_ASS:
#line 128
                return "assign";
            case TK_QUESTION:
#line 129
                return "question-mark";
            case TK_PLUS:
#line 130
                return "plus";
            case TK_SOLIDUS:
#line 131
                return "solidus";
            case TK_ACCENT:
#line 132
                return "accent";
            case TK_TILDE:
#line 133
                return "tilde";
            case TK_MUL:
#line 134
                return "multiply";
            case TK_CHAR:
#line 135
                return "char";
            case TK_OR:
#line 136
                return "or";
            case TK_MINUS:
#line 137
                return "minus";
            case TK_SEMICOLON:
#line 138
                return "semicolon";
            case TK_COMMA:
#line 139
                return "comma";
            case TK_PUNCT:
#line 140
                return "punct";
            case TK_COLON:
#line 141
                return "colon";
            case TK_LESS:
#line 142
                return "less";
            case TK_GREATER:
#line 143
                return "greater";
            case TK_NEWLINE:
#line 144
                return "newline";
            case TK_BLOCK_COMMENT:
#line 145
                return "block-comment";
            case TK_COMMENT:
#line 146
                return "comment";
            case TK_HEX:
#line 147
                return "hex-number";
            case TK_OCT:
#line 148
                return "oct-number";
            case TK_INVALID:
#line 149
                return "invalid";
            case TK_EOF:
#line 150
                return "end-of-file";
        }
        return "";
    };
    
#line 324
    Tokenizer::Tokenizer()
    :
        cursor(0),
        skip_comments(false),
        skip_newlines(false),
        skip_separateunary(false),
        pass_cursor(0),
        tab_size(4)
    {};
    
#line 328
    Token& Tokenizer::Add(int token_id)
    {
#line 329
        struct Token & t = tokens.Add();
        t.loc = loc;
        t.end = loc;
        t.end.col ++ ;
        t.type = token_id;
        return t;
    };
    
#line 227
    void Tokenizer::AddError(TextProc::FileLocation loc, Text::String msg)
    {
#line 227
        messages.Add().Set("Tokenizer", loc, PROCMSG_ERROR, msg);
    };
    
#line 228
    void Tokenizer::AddWarning(TextProc::FileLocation loc, Text::String msg)
    {
#line 228
        messages.Add().Set("Tokenizer", loc, PROCMSG_WARNING, msg);
    };
    
#line 818
    void Tokenizer::AppendString(Text::String& s)
    {
#line 819
        int chr = input[cursor];
        if (chr == '\\')
        {
#line 821
            int chr1;
            if (cursor + 1 < input.GetCount())
#line 822
                chr1 = input[cursor + 1];
            else
#line 823
                chr1 = 0;
            if (chr1 == '\'')
            {
#line 825
                Next();
#line 825
                Next();
                s.Cat(0x27);
            }
            else 
#line 828
            if (chr1 == '"')
            {
#line 829
                Next();
#line 829
                Next();
                s.Cat(0x22);
            }
            else 
#line 832
            if (chr1 == '\?')
            {
#line 833
                Next();
#line 833
                Next();
                s.Cat(0x3F);
            }
            else 
#line 836
            if (chr1 == '\\')
            {
#line 837
                Next();
#line 837
                Next();
                s.Cat(0x5c);
            }
            else 
#line 840
            if (chr1 == 'a')
            {
#line 841
                Next();
#line 841
                Next();
                s.Cat(0x07);
            }
            else 
#line 844
            if (chr1 == 'b')
            {
#line 845
                Next();
#line 845
                Next();
                s.Cat(0x08);
            }
            else 
#line 848
            if (chr1 == 'f')
            {
#line 849
                Next();
#line 849
                Next();
                s.Cat(0x0c);
            }
            else 
#line 852
            if (chr1 == 'n')
            {
#line 853
                Next();
#line 853
                Next();
                s.Cat(0x0a);
            }
            else 
#line 856
            if (chr1 == 'r')
            {
#line 857
                Next();
#line 857
                Next();
                s.Cat(0x0d);
            }
            else 
#line 860
            if (chr1 == 't')
            {
#line 861
                Next();
#line 861
                Next();
                s.Cat(0x09);
            }
            else 
#line 864
            if (chr1 == 'v')
            {
#line 865
                Next();
#line 865
                Next();
                s.Cat(0x0b);
            }
            else
            {
#line 869
                s.Cat(chr);
                Next();
            }
        }
        else
        {
#line 874
            s.Cat(chr);
            Next();
        }
    };
    
#line 238
    void Tokenizer::Dump() const
    {
        {
            {
#line 238
                Util::Log() << "tokens" << " {" << "\n";
#line 238
                Util::Log().Flush();
            }
#line 238
            ;
#line 238
            for (int i = 0; i < tokens.GetCount(); i ++ )
                {
#line 238
                    Util::Log() << "\t[" << i << "]: " << Text::ToString(tokens[i]) << "\n";
#line 238
                    Util::Log().Flush();
                }
#line 238
            ;
            {
#line 238
                Util::Log() << "}" << "\n";
#line 238
                Util::Log().Flush();
            }
#line 238
            ;
        }
#line 238
        ;
    };
    
#line 348
    bool Tokenizer::IsToken(int tk)
    {
#line 349
        if (pass_cursor >= tokens.GetCount())
#line 349
            return false;
        return tokens[pass_cursor].type == tk;
    };
    
#line 379
    bool Tokenizer::Load(Text::String str, Text::String path)
    {
#line 380
        input = str;
#line 382
        loc.file = path;
        loc.line = 1;
        loc.col = 1;
#line 386
        cursor = 0;
#line 388
        while (cursor < input.GetCount())
            {
#line 389
                int chr = input[cursor];
#line 391
                if (Text::IsAlpha(chr) || chr == '_')
                {
#line 392
                    Token & t = Add(TK_ID);
                    t.str_value.Cat(chr);
                    Next();
                    while (cursor < input.GetCount())
                        {
#line 396
                            int chr = input[cursor];
                            if (Text::IsAlpha(chr) || chr == '_' || Text::IsDigit(chr))
                            {
#line 398
                                t.str_value.Cat(chr);
                                Next();
                            }
                            else
                                break;
                        
                        }
#line 404
                    t.end = loc;
                }
                else 
#line 406
                if (Text::IsDigit(chr))
                {
#line 407
                    Text::String n;
                    if (skip_separateunary && tokens.GetCount())
                    {
#line 409
                        while (tokens.GetCount() && tokens.Top().IsType(TK_MINUS))
                            {
#line 410
                                tokens.Pop();
                                n.Cat('-');
                            }
                        while (tokens.GetCount() && tokens.Top().IsType(TK_PLUS))
                            {
#line 414
                                tokens.Pop();
                            }
                    }
                    Token & tk = Add(TK_INTEGER);
                    bool is_double = false;
#line 418
                    bool is_float = false;
                    n.Cat(chr);
                    Next();
                    int exp;
                    if (chr == '0')
#line 422
                        exp = FP_OCTHEX;
                    else
#line 423
                        exp = FP_INT;
                    while (cursor < input.GetCount())
                        {
#line 425
                            int chr = input[cursor];
                            bool cat = false;
#line 428
                            if (exp == FP_INT)
                            {
#line 429
                                if (Text::IsDigit(chr))
                                    cat = true;
                                else 
#line 431
                                if (chr == '.')
                                {
#line 432
                                    exp = FP_FRAC;
                                    cat = true;
                                    is_double = true;
                                }
                                else 
#line 436
                                if (chr == 'e' || chr == 'E')
                                {
#line 437
                                    exp = FP_SIGN;
                                    cat = true;
                                    is_double = true;
                                }
                            }
                            else 
#line 442
                            if (exp == FP_FRAC)
                            {
#line 443
                                if (Text::IsDigit(chr))
                                    cat = true;
                                else 
#line 445
                                if (chr == 'e' || chr == 'E')
                                {
#line 446
                                    exp = FP_SIGN;
                                    cat = true;
                                    is_double = true;
                                }
                            }
                            else 
#line 451
                            if (exp == FP_SIGN)
                            {
#line 452
                                if (chr == '+' || chr == '-' || Text::IsDigit(chr))
                                {
#line 453
                                    exp = FP_EXP;
                                    cat = true;
                                }
                                else 
#line 456
                                if (chr == 'f' || chr == 'F')
                                {
#line 457
                                    exp = FP_END;
                                    cat = true;
                                    is_float = true;
                                }
                            }
                            else 
#line 462
                            if (exp == FP_EXP)
                            {
#line 463
                                if (Text::IsDigit(chr))
                                    cat = true;
                                else 
#line 465
                                if (chr == 'f' || chr == 'F')
                                {
#line 466
                                    exp = FP_END;
                                    cat = true;
                                    is_float = true;
                                }
                            }
                            else 
#line 471
                            if (exp == FP_OCTHEX)
                            {
#line 472
                                if (chr == 'x' || chr == 'X')
                                {
#line 473
                                    exp = FP_HEX;
                                    cat = true;
                                }
                                else 
#line 476
                                if (chr >= '0' && chr <= '7')
                                {
#line 477
                                    exp = FP_OCT;
                                    cat = true;
                                }
                                else 
#line 480
                                if (chr == '.')
                                {
#line 481
                                    exp = FP_FRAC;
                                    cat = true;
                                    is_double = true;
                                }
                            }
                            else 
#line 486
                            if (exp == FP_HEX)
                            {
#line 487
                                if ((chr >= '0' && chr <= '9') || (chr >= 'a' && chr <= 'f') || (chr >= 'A' && chr <= 'F'))
                                {
#line 490
                                    cat = true;
                                }
                            }
                            else 
#line 493
                            if (exp == FP_OCT)
                            {
#line 494
                                if (chr >= '0' && chr <= '7')
                                {
#line 495
                                    cat = true;
                                }
                            }
#line 499
                            if (cat)
                            {
#line 500
                                Next();
                                n.Cat(chr);
                                if (exp == FP_END)
#line 502
                                    break;
                            
                            }
                            else
#line 504
                                break;
                        
                        }
                    tk.str_value = n;
#line 509
                    if (exp == FP_HEX)
                        tk.type = TK_HEX;
                    else 
#line 511
                    if (exp == FP_OCT)
                        tk.type = TK_OCT;
                    else 
#line 513
                    if (is_double)
                    {
#line 514
                        if (!is_float)
                            tk.type = TK_DOUBLE;
                        else
                            tk.type = TK_FLOAT;
                    }
#line 520
                    tk.end = loc;
                }
                else 
#line 522
                if (chr == '!')
                {
#line 523
                    Token & tk = Add(TK_EXCLAMATION);
                    Next();
                    tk.end = loc;
                }
                else 
#line 527
                if (chr == '"')
                {
#line 528
                    Token & tk = Add(TK_STRING);
                    int begin_line = loc.line;
                    int begin_col = loc.col;
                    Next();
                    Text::String str;
                    bool success = false;
                    while (cursor < input.GetCount())
                        {
#line 535
                            int chr = input[cursor];
                            Text::String tmp;
                            tmp.Cat(chr);
                            if (chr == '\n')
                            {
#line 539
                                AddError(tk.loc, "no newline allowed in string literal");
                                Next();
                                loc.line ++ ;
                                loc.col = 1;
                            }
                            else 
#line 544
                            if (chr == '"')
                            {
#line 545
                                Next();
                                success = true;
                                break;
                            
                            }
                            else 
#line 549
                            if (chr == '\\')
                            {
#line 550
                                AppendString(str);
                            }
                            else
                            {
#line 553
                                str.Cat(chr);
                                Next();
                            }
                        }
                    tk.end = loc;
#line 559
                    if (success)
                    {
#line 560
                        tk.str_value = str;
                    }
                    else
                    {
#line 563
                        AddError(tk.loc, "no finishing \" in string literal");
                        return false;
                    }
                }
                else 
#line 567
                if (chr == '#')
                {
#line 568
                    Token & tk = Add(TK_NUMBERSIGN);
                    Next();
                    tk.end = loc;
                }
                else 
#line 572
                if (chr == '%')
                {
#line 573
                    Token & tk = Add(TK_PERCENT);
                    Next();
                    tk.end = loc;
                }
                else 
#line 577
                if (chr == '&')
                {
#line 578
                    Token & tk = Add(TK_AMPERSAND);
                    Next();
                    tk.end = loc;
                }
                else 
#line 582
                if (chr == '/')
                {
#line 583
                    int begin_line = loc.line;
                    int begin_col = loc.col;
                    int chr1;
                    if (cursor + 1 < input.GetCount())
#line 586
                        chr1 = input[cursor + 1];
                    else
#line 587
                        chr1 = 0;
                    if (chr1 == '*')
                    {
#line 589
                        Token * tk = 0;
                        if (!skip_comments)
                            tk = &Add(TK_BLOCK_COMMENT);
                        Next();
                        Next();
                        Text::String c;
                        bool succ = false;
                        while (cursor < input.GetCount())
                            {
#line 597
                                chr = input[cursor];
                                if (chr == '*')
                                {
#line 599
                                    if (cursor + 1 < input.GetCount())
#line 599
                                        chr1 = input[cursor + 1];
                                    else
#line 600
                                        chr1 = 0;
                                    if (chr1 == '/')
                                    {
#line 602
                                        Next();
                                        Next();
                                        if (tk)
#line 604
                                            tk -> str_value = c;
                                        succ = true;
                                        break;
                                    
                                    }
                                    else
#line 608
                                        c.Cat(chr);
                                }
                                else
#line 610
                                    c.Cat(chr);
                                Next();
                            }
                        if (tk)
                        {
#line 614
                            tk -> end = loc;
                            if (!succ)
                                AddError(tk -> loc, "unterminated /* comment");
                        }
                    }
                    else 
#line 619
                    if (chr1 == '/')
                    {
#line 620
                        Token * tk = 0;
                        if (!skip_comments)
                            tk = &Add(TK_COMMENT);
                        Next();
                        Next();
                        Text::String c;
                        while (cursor < input.GetCount())
                            {
#line 627
                                chr = input[cursor];
                                if (chr == '\n')
                                {
#line 629
                                    if (tk)
#line 629
                                        tk -> str_value = c;
                                    break;
                                
                                }
                                else
#line 632
                                    c.Cat(chr);
                                Next();
                            }
                        if (tk)
#line 635
                            tk -> end = loc;
                    }
                    else
                    {
#line 638
                        Token & tk = Add(TK_DIV);
                        Next();
                        tk.end = loc;
                    }
                }
                else 
#line 643
                if (chr == '{')
                {
#line 644
                    Add(TK_BRACKET_BEGIN);
                    Next();
                }
                else 
#line 647
                if (chr == '}')
                {
#line 648
                    Add(TK_BRACKET_END);
                    Next();
                }
                else 
#line 651
                if (chr == '(')
                {
#line 652
                    Add(TK_PARENTHESIS_BEGIN);
                    Next();
                }
                else 
#line 655
                if (chr == ')')
                {
#line 656
                    Add(TK_PARENTHESIS_END);
                    Next();
                }
                else 
#line 659
                if (chr == '[')
                {
#line 660
                    Add(TK_SQUARE_BEGIN);
                    Next();
                }
                else 
#line 663
                if (chr == ']')
                {
#line 664
                    Add(TK_SQUARE_END);
                    Next();
                }
                else 
#line 667
                if (chr == '=')
                {
#line 668
                    Add(TK_ASS);
                    Next();
                }
                else 
#line 671
                if (chr == '+')
                {
#line 672
                    Add(TK_PLUS);
                    Next();
                }
                else 
#line 675
                if (chr == '\?')
                {
#line 676
                    Add(TK_QUESTION);
                    Next();
                }
                else 
#line 679
                if (chr == '\\')
                {
#line 680
                    Add(TK_SOLIDUS);
                    Next();
                }
                else 
#line 683
                if (chr == '^')
                {
#line 684
                    Add(TK_ACCENT);
                    Next();
                }
                else 
#line 687
                if (chr == '~')
                {
#line 688
                    Add(TK_TILDE);
                    Next();
                }
                else 
#line 691
                if (chr == '*')
                {
#line 692
                    Add(TK_MUL);
                    Next();
                }
                else 
#line 695
                if (chr == '@')
                {
#line 696
                    Add(TK_AT);
                    Next();
                }
                else 
#line 699
                if (chr == '\'')
                {
#line 700
                    Token & tk = Add(TK_CHAR);
                    Next();
                    Text::String str;
                    bool success = false;
                    while (cursor < input.GetCount())
                        {
#line 705
                            int chr = input[cursor];
                            if (chr == '\n')
                            {
#line 707
                                AddError(tk.loc, "no newline allowed in char literal");
                                Next();
                                loc.line ++ ;
                                loc.col = 1;
                            }
                            else 
#line 712
                            if (chr == '\'')
                            {
#line 713
                                Next();
                                success = true;
                                break;
                            
                            }
                            else 
#line 717
                            if (chr == '\\')
                            {
#line 718
                                AppendString(str);
                            }
                            else
                            {
#line 721
                                str.Cat(chr);
                                Next();
                            }
                        }
                    tk.end = loc;
#line 727
                    if (success)
                    {
#line 728
                        tk.str_value = str;
                    }
                    else
                    {
#line 731
                        AddError(tk.loc, "no finishing ' in char literal");
                        return false;
                    }
                }
                else 
#line 735
                if (chr == '-')
                {
#line 736
                    Add(TK_MINUS);
                    Next();
                }
                else 
#line 739
                if (chr == ';')
                {
#line 740
                    Add(TK_SEMICOLON);
                    Next();
                }
                else 
#line 743
                if (chr == ',')
                {
#line 744
                    Add(TK_COMMA);
                    Next();
                }
                else 
#line 747
                if (chr == '.')
                {
#line 748
                    Add(TK_PUNCT);
                    Next();
                }
                else 
#line 751
                if (chr == ':')
                {
#line 752
                    Add(TK_COLON);
                    Next();
                }
                else 
#line 755
                if (chr == '<')
                {
#line 756
                    Add(TK_LESS);
                    Next();
                }
                else 
#line 759
                if (chr == '>')
                {
#line 760
                    Add(TK_GREATER);
                    Next();
                }
                else 
#line 763
                if (chr == '|')
                {
#line 764
                    Add(TK_OR);
                    Next();
                }
                else 
#line 767
                if (chr == '\n')
                {
#line 768
                    if (!skip_newlines)
                    {
#line 769
                        Token & tk = Add(TK_NEWLINE);
                        tk.end.col = 1;
#line 770
                        tk.end.line ++ ;
                    }
                    Next();
                    loc.line ++ ;
                    loc.col = 1;
                }
                else 
#line 776
                if (chr == '\t')
                {
#line 777
                    if (!tokens.IsEmpty())
                        tokens.Top().spaces += tab_size;
                    Next();
                    loc.col += tab_size - 1;
                }
                else 
#line 782
                if (Text::IsSpace(chr))
                {
#line 783
                    if (!tokens.IsEmpty())
                        tokens.Top().spaces ++ ;
                    Next();
                }
                else 
#line 787
                if (chr == 0)
                    break;
                
                else
                {
#line 790
                    Lang::byte b = chr;
                    if (b >= 0x80 && b <= 0xFF)
                    {
#line 792
                        Next();
                        while (cursor < input.GetCount())
                            {
#line 794
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
#line 805
                        Text::String msg = "unexpected character '";
                        msg.Cat(chr);
                        msg.Cat('\'');
                        AddError(loc, msg);
                        Next();
                    }
                }
            }
        Add(TK_EOF);
#line 815
        return messages.IsEmpty();
    };
    
#line 343
    void Tokenizer::PassToken(int tk)
    {
#line 344
        if (!IsToken(tk))
#line 344
            throw InputExc("Unexpected token");
        pass_cursor ++ ;
    };
    
#line 374
    double Tokenizer::ReadDouble()
    {
#line 375
        if (!IsToken(TK_DOUBLE) && !IsToken(TK_FLOAT))
#line 375
            throw InputExc("Unexpected token");
        return Text::String::StrDbl(tokens[pass_cursor ++ ].str_value);
    };
    
#line 364
    Text::String Tokenizer::ReadId()
    {
#line 365
        if (!IsToken(TK_ID))
#line 365
            throw InputExc("Unexpected token");
        return tokens[pass_cursor ++ ].str_value;
    };
    
    Lang::int64 Tokenizer::ReadInt()
    {
#line 370
        if (!IsToken(TK_INTEGER))
#line 370
            throw InputExc("Unexpected token");
        return Text::String::StrInt64(tokens[pass_cursor ++ ].str_value);
    };
    
#line 359
    Text::String Tokenizer::ReadString()
    {
#line 360
        if (!IsToken(TK_STRING))
#line 360
            throw InputExc("Unexpected token");
        return tokens[pass_cursor ++ ].str_value;
    };
    
#line 353
    bool Tokenizer::TryPassToken(int tk)
    {
#line 354
        if (!IsToken(tk))
#line 354
            return false;
        pass_cursor ++ ;
        return true;
    };
    
};

#endif
