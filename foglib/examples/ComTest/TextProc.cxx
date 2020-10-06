#ifndef TEXTPROC_CXX
#define TEXTPROC_CXX

#include <new>

#ifndef TEXTPROC_HXX
#include <TextProc.hxx>
#endif

namespace TextProc
{
#line 266 "../../src/Com/Tokenizer.fog"
    CParser::CParser()
    :
        tokens(0),
        pos(0),
        ignore_newline(true)
    {};
    
#line 267
    CParser::CParser(Text::String s)
    :
        tokens(0),
        pos(0),
        ignore_newline(true)
    {
#line 267
        t.Create();
#line 267
        t -> Load(s, "cparser");
#line 267
        Load(t -> GetTokens());
    };
    
#line 268
    CParser::CParser(const Container::Vector < Token > & tokens)
    :
        tokens(0),
        pos(0),
        ignore_newline(true)
    {
#line 268
        Load(tokens);
    };
    
#line 893
    const Token& CParser::GetCurrent() const
    {
#line 894
        if (!tokens)
            throw Text::Exc("No token vector set");
        if (pos < 0 || pos >= tokens -> GetCount())
            throw Text::Exc("Invalid token position");
        return(*tokens)[pos];
    };
    
#line 909
    FileLocation CParser::GetLocation() const
    {
#line 910
        return GetCurrent().loc;
    };
    
#line 278
    int CParser::GetTokenCount() const
    {
#line 278
        if (tokens)
#line 278
            return tokens -> GetCount();
        else
#line 278
            return 0;
    };
    
#line 941
    bool CParser::Id(Text::String id)
    {
#line 942
        const Token & tk = GetCurrent();
        if (tk.IsType(TK_ID) && tk.str_value == id)
        {
#line 944
            pos ++ ;
            return true;
        }
        return false;
    };
    
#line 901
    void CParser::IgnoreNewline(bool b)
    {
#line 902
        ignore_newline = b;
    };
    
    bool CParser::IsEnd() const
    {
#line 906
        return !tokens || pos >= tokens -> GetCount();
    };
    
#line 968
    bool CParser::IsId() const
    {
#line 969
        return GetCurrent().IsType(TK_ID);
    };
    
    bool CParser::IsInt() const
    {
#line 973
        return GetCurrent().IsType(TK_INTEGER);
    };
    
    bool CParser::IsType(int i) const
    {
#line 977
        return GetCurrent().IsType(i);
    };
    
#line 888
    void CParser::Load(const Container::Vector < Token > & tokens)
    {
#line 889
        this -> tokens = &tokens;
        pos = 0;
    };
    
#line 959
    bool CParser::Newline()
    {
#line 960
        const Token & tk = GetCurrent();
        if (tk.IsType(TK_NEWLINE))
        {
#line 962
            pos ++ ;
            return true;
        }
        return false;
    };
    
#line 934
    void CParser::PassNewline()
    {
#line 935
        const Token & tk = GetCurrent();
        if (tk.IsType(TK_NEWLINE))
            throw Text::Exc("Token is not newline");
        pos ++ ;
    };
    
#line 913
    Text::String CParser::ReadId()
    {
#line 914
        const Token & tk = GetCurrent();
        if (!tk.IsType(TK_ID))
            throw Text::Exc("Token is not id");
        pos ++ ;
        return tk.str_value;
    };
    
    int CParser::ReadInt()
    {
#line 922
        const Token & tk = GetCurrent();
        pos ++ ;
        if (tk.IsType(TK_OCT))
            return Text::String::OctInt(tk.str_value);
        if (tk.IsType(TK_HEX))
            return Text::String::HexInt(tk.str_value);
        if (tk.IsType(TK_INTEGER))
            return Text::String::StrInt(tk.str_value);
        pos -- ;
        throw Text::Exc("Token is not int");
    };
    
#line 950
    bool CParser::Type(int i)
    {
#line 951
        const Token & tk = GetCurrent();
        if (tk.IsType(i))
        {
#line 953
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
    
#line 36
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
    
#line 99 "../../src/Com/Tokenizer.fog"
    Token::Token()
    :
        type(0),
        spaces(0)
    {};
    
#line 100
    Token::Token(const Token& t)
    :
        type(0),
        spaces(0)
    {
#line 100
        *this = t;
    };
    
#line 101
    void Token::operator= (const Token& t)
    {
#line 101
        type = t.type;
#line 101
        str_value = t.str_value;
#line 101
        loc = t.loc;
#line 101
        end = t.end;
#line 101
        spaces = t.spaces;
    };
    
#line 102
    bool Token::operator== (const Token& t) const
    {
#line 102
        return t.type == type && t.str_value == str_value && t.loc == loc && end == t.end && t.spaces == spaces;
    };
    
#line 151
    Text::String Token::AsString() const
    {
#line 152
        Text::String s = GetTypeString() + ": " + Text::EscapeString(GetTextValue());
        return s;
    };
    
#line 155
    Text::String Token::GetTextValue() const
    {
#line 156
        switch (type)
        {
#line 157
            case TK_UNKNOWN:
#line 157
                return "";
            case TK_ID:
#line 158
                return str_value;
            case TK_INTEGER:
#line 159
                return str_value;
            case TK_FLOAT:
#line 160
                return str_value;
            case TK_DOUBLE:
#line 161
                return str_value;
            case TK_EXCLAMATION:
#line 162
                return "!";
            case TK_STRING:
#line 163
                return(Text::String)"\"" + Text::EscapeString(str_value) + "\"";
            case TK_NUMBERSIGN:
#line 164
                return "#";
            case TK_PERCENT:
#line 165
                return "%";
            case TK_AMPERSAND:
#line 166
                return "&";
            case TK_BRACKET_BEGIN:
#line 167
                return "{";
            case TK_BRACKET_END:
#line 168
                return "}";
            case TK_DIV:
#line 169
                return "/";
            case TK_PARENTHESIS_BEGIN:
#line 170
                return "(";
            case TK_PARENTHESIS_END:
#line 171
                return ")";
            case TK_SQUARE_BEGIN:
#line 172
                return "[";
            case TK_SQUARE_END:
#line 173
                return "]";
            case TK_ASS:
#line 174
                return "=";
            case TK_QUESTION:
#line 175
                return "\?";
            case TK_PLUS:
#line 176
                return "+";
            case TK_SOLIDUS:
#line 177
                return "\\";
            case TK_ACCENT:
#line 178
                return "^";
            case TK_TILDE:
#line 179
                return "~";
            case TK_MUL:
#line 180
                return "*";
            case TK_CHAR:
#line 181
                return(Text::String)"'" + Text::EscapeString(str_value) + "'";
            case TK_OR:
#line 182
                return "|";
            case TK_MINUS:
#line 183
                return "-";
            case TK_SEMICOLON:
#line 184
                return ";";
            case TK_COMMA:
#line 185
                return ",";
            case TK_PUNCT:
#line 186
                return ".";
            case TK_COLON:
#line 187
                return ":";
            case TK_LESS:
#line 188
                return "<";
            case TK_GREATER:
#line 189
                return ">";
            case TK_NEWLINE:
#line 190
                return "\n";
            case TK_BLOCK_COMMENT:
#line 191
                return(Text::String)"/* " + str_value + "*/";
            case TK_COMMENT:
#line 192
                return(Text::String)"// " + str_value;
            case TK_HEX:
#line 193
                return str_value;
            case TK_OCT:
#line 194
                return str_value;
            case TK_DOLLARSIGN:
#line 195
                return "$";
            case TK_EOF:
#line 196
                return "EOF";
            default:
#line 197
                Util::Panic("Unhandled token type");
        }
        return "";
    };
    
#line 106
    Text::String Token::GetTypeString() const
    {
#line 107
        switch (type)
        {
#line 108
            case TK_UNKNOWN:
#line 108
                return "<unknown>";
            case TK_ID:
#line 109
                return "id";
            case TK_INTEGER:
#line 110
                return "integer";
            case TK_FLOAT:
#line 111
                return "float";
            case TK_DOUBLE:
#line 112
                return "double";
            case TK_EXCLAMATION:
#line 113
                return "exclamation";
            case TK_STRING:
#line 114
                return "string";
            case TK_NUMBERSIGN:
#line 115
                return "number-sign";
            case TK_PERCENT:
#line 116
                return "percent";
            case TK_AMPERSAND:
#line 117
                return "ampersand";
            case TK_DIV:
#line 118
                return "divide";
            case TK_BRACKET_BEGIN:
#line 119
                return "bracket-begin";
            case TK_BRACKET_END:
#line 120
                return "bracket-end";
            case TK_PARENTHESIS_BEGIN:
#line 121
                return "parenthesis-begin";
            case TK_PARENTHESIS_END:
#line 122
                return "parenthesis-end";
            case TK_SQUARE_BEGIN:
#line 123
                return "square-begin";
            case TK_SQUARE_END:
#line 124
                return "square-end";
            case TK_ASS:
#line 125
                return "assign";
            case TK_QUESTION:
#line 126
                return "question-mark";
            case TK_PLUS:
#line 127
                return "plus";
            case TK_SOLIDUS:
#line 128
                return "solidus";
            case TK_ACCENT:
#line 129
                return "accent";
            case TK_TILDE:
#line 130
                return "tilde";
            case TK_MUL:
#line 131
                return "multiply";
            case TK_CHAR:
#line 132
                return "char";
            case TK_OR:
#line 133
                return "or";
            case TK_MINUS:
#line 134
                return "minus";
            case TK_SEMICOLON:
#line 135
                return "semicolon";
            case TK_COMMA:
#line 136
                return "comma";
            case TK_PUNCT:
#line 137
                return "punct";
            case TK_COLON:
#line 138
                return "colon";
            case TK_LESS:
#line 139
                return "less";
            case TK_GREATER:
#line 140
                return "greater";
            case TK_NEWLINE:
#line 141
                return "newline";
            case TK_BLOCK_COMMENT:
#line 142
                return "block-comment";
            case TK_COMMENT:
#line 143
                return "comment";
            case TK_HEX:
#line 144
                return "hex-number";
            case TK_OCT:
#line 145
                return "oct-number";
            case TK_INVALID:
#line 146
                return "invalid";
            case TK_EOF:
#line 147
                return "end-of-file";
        }
        return "";
    };
    
#line 310
    Tokenizer::Tokenizer()
    :
        cursor(0),
        skip_comments(false),
        skip_newlines(false),
        skip_separateunary(false),
        pass_cursor(0),
        tab_size(4)
    {};
    
#line 314
    Token& Tokenizer::Add(int token_id)
    {
#line 315
        struct Token & t = tokens.Add();
        t.loc = loc;
        t.end = loc;
        t.end.col ++ ;
        t.type = token_id;
        return t;
    };
    
#line 223
    void Tokenizer::AddError(FileLocation loc, Text::String msg)
    {
#line 223
        messages.Add().Set("Tokenizer", loc, PROCMSG_ERROR, msg);
    };
    
#line 224
    void Tokenizer::AddWarning(FileLocation loc, Text::String msg)
    {
#line 224
        messages.Add().Set("Tokenizer", loc, PROCMSG_WARNING, msg);
    };
    
#line 804
    void Tokenizer::AppendString(Text::String& s)
    {
#line 805
        int chr = input[cursor];
        if (chr == '\\')
        {
#line 807
            int chr1;
            if (cursor + 1 < input.GetCount())
#line 808
                chr1 = input[cursor + 1];
            else
#line 809
                chr1 = 0;
            if (chr1 == '\'')
            {
#line 811
                Next();
#line 811
                Next();
                s.Cat(0x27);
            }
            else 
#line 814
            if (chr1 == '"')
            {
#line 815
                Next();
#line 815
                Next();
                s.Cat(0x22);
            }
            else 
#line 818
            if (chr1 == '\?')
            {
#line 819
                Next();
#line 819
                Next();
                s.Cat(0x3F);
            }
            else 
#line 822
            if (chr1 == '\\')
            {
#line 823
                Next();
#line 823
                Next();
                s.Cat(0x5c);
            }
            else 
#line 826
            if (chr1 == 'a')
            {
#line 827
                Next();
#line 827
                Next();
                s.Cat(0x07);
            }
            else 
#line 830
            if (chr1 == 'b')
            {
#line 831
                Next();
#line 831
                Next();
                s.Cat(0x08);
            }
            else 
#line 834
            if (chr1 == 'f')
            {
#line 835
                Next();
#line 835
                Next();
                s.Cat(0x0c);
            }
            else 
#line 838
            if (chr1 == 'n')
            {
#line 839
                Next();
#line 839
                Next();
                s.Cat(0x0a);
            }
            else 
#line 842
            if (chr1 == 'r')
            {
#line 843
                Next();
#line 843
                Next();
                s.Cat(0x0d);
            }
            else 
#line 846
            if (chr1 == 't')
            {
#line 847
                Next();
#line 847
                Next();
                s.Cat(0x09);
            }
            else 
#line 850
            if (chr1 == 'v')
            {
#line 851
                Next();
#line 851
                Next();
                s.Cat(0x0b);
            }
            else
            {
#line 855
                s.Cat(chr);
                Next();
            }
        }
        else
        {
#line 860
            s.Cat(chr);
            Next();
        }
    };
    
#line 234
    void Tokenizer::Dump() const
    {
        {
            {
#line 234
                Util::Log() << "tokens" << " {" << "\n";
#line 234
                Util::Log().Flush();
            }
#line 234
            ;
#line 234
            for (int i = 0; i < tokens.GetCount(); i ++ )
                {
#line 234
                    Util::Log() << "\t[" << i << "]: " << Text::ToString(tokens[i]) << "\n";
#line 234
                    Util::Log().Flush();
                }
#line 234
            ;
            {
#line 234
                Util::Log() << "}" << "\n";
#line 234
                Util::Log().Flush();
            }
#line 234
            ;
        }
#line 234
        ;
    };
    
#line 334
    bool Tokenizer::IsToken(int tk)
    {
#line 335
        if (pass_cursor >= tokens.GetCount())
#line 335
            return false;
        return tokens[pass_cursor].type == tk;
    };
    
#line 365
    bool Tokenizer::Load(Text::String str, Text::String path)
    {
#line 366
        input = str;
#line 368
        loc.file = path;
        loc.line = 1;
        loc.col = 1;
#line 372
        cursor = 0;
#line 374
        while (cursor < input.GetCount())
            {
#line 375
                int chr = input[cursor];
#line 377
                if (Text::IsAlpha(chr) || chr == '_')
                {
#line 378
                    Token & t = Add(TK_ID);
                    t.str_value.Cat(chr);
                    Next();
                    while (cursor < input.GetCount())
                        {
#line 382
                            int chr = input[cursor];
                            if (Text::IsAlpha(chr) || chr == '_' || Text::IsDigit(chr))
                            {
#line 384
                                t.str_value.Cat(chr);
                                Next();
                            }
                            else
                                break;
                        
                        }
#line 390
                    t.end = loc;
                }
                else 
#line 392
                if (Text::IsDigit(chr))
                {
#line 393
                    Text::String n;
                    if (skip_separateunary && tokens.GetCount())
                    {
#line 395
                        while (tokens.GetCount() && tokens.Top().IsType(TK_MINUS))
                            {
#line 396
                                tokens.Pop();
                                n.Cat('-');
                            }
                        while (tokens.GetCount() && tokens.Top().IsType(TK_PLUS))
                            {
#line 400
                                tokens.Pop();
                            }
                    }
                    Token & tk = Add(TK_INTEGER);
                    bool is_double = false;
#line 404
                    bool is_float = false;
                    n.Cat(chr);
                    Next();
                    int exp;
                    if (chr == '0')
#line 408
                        exp = FP_OCTHEX;
                    else
#line 409
                        exp = FP_INT;
                    while (cursor < input.GetCount())
                        {
#line 411
                            int chr = input[cursor];
                            bool cat = false;
#line 414
                            if (exp == FP_INT)
                            {
#line 415
                                if (Text::IsDigit(chr))
                                    cat = true;
                                else 
#line 417
                                if (chr == '.')
                                {
#line 418
                                    exp = FP_FRAC;
                                    cat = true;
                                    is_double = true;
                                }
                                else 
#line 422
                                if (chr == 'e' || chr == 'E')
                                {
#line 423
                                    exp = FP_SIGN;
                                    cat = true;
                                    is_double = true;
                                }
                            }
                            else 
#line 428
                            if (exp == FP_FRAC)
                            {
#line 429
                                if (Text::IsDigit(chr))
                                    cat = true;
                                else 
#line 431
                                if (chr == 'e' || chr == 'E')
                                {
#line 432
                                    exp = FP_SIGN;
                                    cat = true;
                                    is_double = true;
                                }
                            }
                            else 
#line 437
                            if (exp == FP_SIGN)
                            {
#line 438
                                if (chr == '+' || chr == '-' || Text::IsDigit(chr))
                                {
#line 439
                                    exp = FP_EXP;
                                    cat = true;
                                }
                                else 
#line 442
                                if (chr == 'f' || chr == 'F')
                                {
#line 443
                                    exp = FP_END;
                                    cat = true;
                                    is_float = true;
                                }
                            }
                            else 
#line 448
                            if (exp == FP_EXP)
                            {
#line 449
                                if (Text::IsDigit(chr))
                                    cat = true;
                                else 
#line 451
                                if (chr == 'f' || chr == 'F')
                                {
#line 452
                                    exp = FP_END;
                                    cat = true;
                                    is_float = true;
                                }
                            }
                            else 
#line 457
                            if (exp == FP_OCTHEX)
                            {
#line 458
                                if (chr == 'x' || chr == 'X')
                                {
#line 459
                                    exp = FP_HEX;
                                    cat = true;
                                }
                                else 
#line 462
                                if (chr >= '0' && chr <= '7')
                                {
#line 463
                                    exp = FP_OCT;
                                    cat = true;
                                }
                                else 
#line 466
                                if (chr == '.')
                                {
#line 467
                                    exp = FP_FRAC;
                                    cat = true;
                                    is_double = true;
                                }
                            }
                            else 
#line 472
                            if (exp == FP_HEX)
                            {
#line 473
                                if ((chr >= '0' && chr <= '9') || (chr >= 'a' && chr <= 'f') || (chr >= 'A' && chr <= 'F'))
                                {
#line 476
                                    cat = true;
                                }
                            }
                            else 
#line 479
                            if (exp == FP_OCT)
                            {
#line 480
                                if (chr >= '0' && chr <= '7')
                                {
#line 481
                                    cat = true;
                                }
                            }
#line 485
                            if (cat)
                            {
#line 486
                                Next();
                                n.Cat(chr);
                                if (exp == FP_END)
#line 488
                                    break;
                            
                            }
                            else
#line 490
                                break;
                        
                        }
                    tk.str_value = n;
#line 495
                    if (exp == FP_HEX)
                        tk.type = TK_HEX;
                    else 
#line 497
                    if (exp == FP_OCT)
                        tk.type = TK_OCT;
                    else 
#line 499
                    if (is_double)
                    {
#line 500
                        if (!is_float)
                            tk.type = TK_DOUBLE;
                        else
                            tk.type = TK_FLOAT;
                    }
#line 506
                    tk.end = loc;
                }
                else 
#line 508
                if (chr == '!')
                {
#line 509
                    Token & tk = Add(TK_EXCLAMATION);
                    Next();
                    tk.end = loc;
                }
                else 
#line 513
                if (chr == '"')
                {
#line 514
                    Token & tk = Add(TK_STRING);
                    int begin_line = loc.line;
                    int begin_col = loc.col;
                    Next();
                    Text::String str;
                    bool success = false;
                    while (cursor < input.GetCount())
                        {
#line 521
                            int chr = input[cursor];
                            Text::String tmp;
                            tmp.Cat(chr);
                            if (chr == '\n')
                            {
#line 525
                                AddError(tk.loc, "no newline allowed in string literal");
                                Next();
                                loc.line ++ ;
                                loc.col = 1;
                            }
                            else 
#line 530
                            if (chr == '"')
                            {
#line 531
                                Next();
                                success = true;
                                break;
                            
                            }
                            else 
#line 535
                            if (chr == '\\')
                            {
#line 536
                                AppendString(str);
                            }
                            else
                            {
#line 539
                                str.Cat(chr);
                                Next();
                            }
                        }
                    tk.end = loc;
#line 545
                    if (success)
                    {
#line 546
                        tk.str_value = str;
                    }
                    else
                    {
#line 549
                        AddError(tk.loc, "no finishing \" in string literal");
                        return false;
                    }
                }
                else 
#line 553
                if (chr == '#')
                {
#line 554
                    Token & tk = Add(TK_NUMBERSIGN);
                    Next();
                    tk.end = loc;
                }
                else 
#line 558
                if (chr == '%')
                {
#line 559
                    Token & tk = Add(TK_PERCENT);
                    Next();
                    tk.end = loc;
                }
                else 
#line 563
                if (chr == '&')
                {
#line 564
                    Token & tk = Add(TK_AMPERSAND);
                    Next();
                    tk.end = loc;
                }
                else 
#line 568
                if (chr == '/')
                {
#line 569
                    int begin_line = loc.line;
                    int begin_col = loc.col;
                    int chr1;
                    if (cursor + 1 < input.GetCount())
#line 572
                        chr1 = input[cursor + 1];
                    else
#line 573
                        chr1 = 0;
                    if (chr1 == '*')
                    {
#line 575
                        Token * tk = 0;
                        if (!skip_comments)
                            tk = &Add(TK_BLOCK_COMMENT);
                        Next();
                        Next();
                        Text::String c;
                        bool succ = false;
                        while (cursor < input.GetCount())
                            {
#line 583
                                chr = input[cursor];
                                if (chr == '*')
                                {
#line 585
                                    if (cursor + 1 < input.GetCount())
#line 585
                                        chr1 = input[cursor + 1];
                                    else
#line 586
                                        chr1 = 0;
                                    if (chr1 == '/')
                                    {
#line 588
                                        Next();
                                        Next();
                                        if (tk)
#line 590
                                            tk -> str_value = c;
                                        succ = true;
                                        break;
                                    
                                    }
                                    else
#line 594
                                        c.Cat(chr);
                                }
                                else
#line 596
                                    c.Cat(chr);
                                Next();
                            }
                        if (tk)
                        {
#line 600
                            tk -> end = loc;
                            if (!succ)
                                AddError(tk -> loc, "unterminated /* comment");
                        }
                    }
                    else 
#line 605
                    if (chr1 == '/')
                    {
#line 606
                        Token * tk = 0;
                        if (!skip_comments)
                            tk = &Add(TK_COMMENT);
                        Next();
                        Next();
                        Text::String c;
                        while (cursor < input.GetCount())
                            {
#line 613
                                chr = input[cursor];
                                if (chr == '\n')
                                {
#line 615
                                    if (tk)
#line 615
                                        tk -> str_value = c;
                                    break;
                                
                                }
                                else
#line 618
                                    c.Cat(chr);
                                Next();
                            }
                        if (tk)
#line 621
                            tk -> end = loc;
                    }
                    else
                    {
#line 624
                        Token & tk = Add(TK_DIV);
                        Next();
                        tk.end = loc;
                    }
                }
                else 
#line 629
                if (chr == '{')
                {
#line 630
                    Add(TK_BRACKET_BEGIN);
                    Next();
                }
                else 
#line 633
                if (chr == '}')
                {
#line 634
                    Add(TK_BRACKET_END);
                    Next();
                }
                else 
#line 637
                if (chr == '(')
                {
#line 638
                    Add(TK_PARENTHESIS_BEGIN);
                    Next();
                }
                else 
#line 641
                if (chr == ')')
                {
#line 642
                    Add(TK_PARENTHESIS_END);
                    Next();
                }
                else 
#line 645
                if (chr == '[')
                {
#line 646
                    Add(TK_SQUARE_BEGIN);
                    Next();
                }
                else 
#line 649
                if (chr == ']')
                {
#line 650
                    Add(TK_SQUARE_END);
                    Next();
                }
                else 
#line 653
                if (chr == '=')
                {
#line 654
                    Add(TK_ASS);
                    Next();
                }
                else 
#line 657
                if (chr == '+')
                {
#line 658
                    Add(TK_PLUS);
                    Next();
                }
                else 
#line 661
                if (chr == '\?')
                {
#line 662
                    Add(TK_QUESTION);
                    Next();
                }
                else 
#line 665
                if (chr == '\\')
                {
#line 666
                    Add(TK_SOLIDUS);
                    Next();
                }
                else 
#line 669
                if (chr == '^')
                {
#line 670
                    Add(TK_ACCENT);
                    Next();
                }
                else 
#line 673
                if (chr == '~')
                {
#line 674
                    Add(TK_TILDE);
                    Next();
                }
                else 
#line 677
                if (chr == '*')
                {
#line 678
                    Add(TK_MUL);
                    Next();
                }
                else 
#line 681
                if (chr == '@')
                {
#line 682
                    Add(TK_AT);
                    Next();
                }
                else 
#line 685
                if (chr == '\'')
                {
#line 686
                    Token & tk = Add(TK_CHAR);
                    Next();
                    Text::String str;
                    bool success = false;
                    while (cursor < input.GetCount())
                        {
#line 691
                            int chr = input[cursor];
                            if (chr == '\n')
                            {
#line 693
                                AddError(tk.loc, "no newline allowed in char literal");
                                Next();
                                loc.line ++ ;
                                loc.col = 1;
                            }
                            else 
#line 698
                            if (chr == '\'')
                            {
#line 699
                                Next();
                                success = true;
                                break;
                            
                            }
                            else 
#line 703
                            if (chr == '\\')
                            {
#line 704
                                AppendString(str);
                            }
                            else
                            {
#line 707
                                str.Cat(chr);
                                Next();
                            }
                        }
                    tk.end = loc;
#line 713
                    if (success)
                    {
#line 714
                        tk.str_value = str;
                    }
                    else
                    {
#line 717
                        AddError(tk.loc, "no finishing ' in char literal");
                        return false;
                    }
                }
                else 
#line 721
                if (chr == '-')
                {
#line 722
                    Add(TK_MINUS);
                    Next();
                }
                else 
#line 725
                if (chr == ';')
                {
#line 726
                    Add(TK_SEMICOLON);
                    Next();
                }
                else 
#line 729
                if (chr == ',')
                {
#line 730
                    Add(TK_COMMA);
                    Next();
                }
                else 
#line 733
                if (chr == '.')
                {
#line 734
                    Add(TK_PUNCT);
                    Next();
                }
                else 
#line 737
                if (chr == ':')
                {
#line 738
                    Add(TK_COLON);
                    Next();
                }
                else 
#line 741
                if (chr == '<')
                {
#line 742
                    Add(TK_LESS);
                    Next();
                }
                else 
#line 745
                if (chr == '>')
                {
#line 746
                    Add(TK_GREATER);
                    Next();
                }
                else 
#line 749
                if (chr == '|')
                {
#line 750
                    Add(TK_OR);
                    Next();
                }
                else 
#line 753
                if (chr == '\n')
                {
#line 754
                    if (!skip_newlines)
                    {
#line 755
                        Token & tk = Add(TK_NEWLINE);
                        tk.end.col = 1;
#line 756
                        tk.end.line ++ ;
                    }
                    Next();
                    loc.line ++ ;
                    loc.col = 1;
                }
                else 
#line 762
                if (chr == '\t')
                {
#line 763
                    if (!tokens.IsEmpty())
                        tokens.Top().spaces += tab_size;
                    Next();
                    loc.col += tab_size - 1;
                }
                else 
#line 768
                if (Text::IsSpace(chr))
                {
#line 769
                    if (!tokens.IsEmpty())
                        tokens.Top().spaces ++ ;
                    Next();
                }
                else 
#line 773
                if (chr == 0)
                    break;
                
                else
                {
#line 776
                    Lang::byte b = chr;
                    if (b >= 0x80 && b <= 0xFF)
                    {
#line 778
                        Next();
                        while (cursor < input.GetCount())
                            {
#line 780
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
#line 791
                        Text::String msg = "unexpected character '";
                        msg.Cat(chr);
                        msg.Cat('\'');
                        AddError(loc, msg);
                        Next();
                    }
                }
            }
        Add(TK_EOF);
#line 801
        return messages.IsEmpty();
    };
    
#line 329
    void Tokenizer::PassToken(int tk)
    {
#line 330
        if (!IsToken(tk))
#line 330
            throw Text::Exc("Unexpected token");
        pass_cursor ++ ;
    };
    
#line 360
    double Tokenizer::ReadDouble()
    {
#line 361
        if (!IsToken(TK_DOUBLE) && !IsToken(TK_FLOAT))
#line 361
            throw Text::Exc("Unexpected token");
        return Text::String::StrDbl(tokens[pass_cursor ++ ].str_value);
    };
    
#line 350
    Text::String Tokenizer::ReadId()
    {
#line 351
        if (!IsToken(TK_ID))
#line 351
            throw Text::Exc("Unexpected token");
        return tokens[pass_cursor ++ ].str_value;
    };
    
    Lang::int64 Tokenizer::ReadInt()
    {
#line 356
        if (!IsToken(TK_INTEGER))
#line 356
            throw Text::Exc("Unexpected token");
        return Text::String::StrInt64(tokens[pass_cursor ++ ].str_value);
    };
    
#line 345
    Text::String Tokenizer::ReadString()
    {
#line 346
        if (!IsToken(TK_STRING))
#line 346
            throw Text::Exc("Unexpected token");
        return tokens[pass_cursor ++ ].str_value;
    };
    
#line 339
    bool Tokenizer::TryPassToken(int tk)
    {
#line 340
        if (!IsToken(tk))
#line 340
            return false;
        pass_cursor ++ ;
        return true;
    };
    
};

#endif
