#ifndef UTIL_CXX
#define UTIL_CXX

#include <new>

#ifndef UTIL_HXX
#include <Util.hxx>
#endif

namespace Util
{
#line 166 "../../src/Com/Util.fog"
    Text::String AppendFileName(Text::String a, Text::String b)
    {
#line 167
        if (b.IsEmpty())
#line 167
            return a;
        if (a.IsEmpty())
#line 168
            return b;
        bool a_sep = a.ReverseFind("/") == a.GetCount() - 1;
        bool b_sep = b.Find("/") == 0;
        if (!a_sep)
        {
#line 172
            if (!b_sep)
                return a + "/" + b;
            else
                return a + b;
        }
        else
        {
#line 178
            if (!b_sep)
                return a + b;
            else
                return a + b.Mid(1);
        }
    };
    
#line 335
    Stream::CharStream& Cerr()
    {
#line 336
        static Stream::FileOut fout(Native::GetStdErr());
        return fout;
    };
    
#line 330
    Stream::CharStream& Cin()
    {
#line 331
        static Stream::FileOut fout(Native::GetStdIn());
        return fout;
    };
    
#line 189
    Text::String ConfigFile(Text::String file_name)
    {
#line 190
        if (ConfigPath().GetCount())
            return AppendFileName(ConfigPath(), file_name);
#line 193
        Text::String dir = GetExeDirFile("");
#line 202
        return AppendFileName(dir, file_name);
    };
    
#line 320
    Stream::CharStream& Cout()
    {
#line 321
        static Stream::FileOut fout(Native::GetStdOut());
        return fout;
    };
    
    Stream::CharStream& Errout()
    {
#line 326
        static Stream::FileOut fout(Native::GetStdErr());
        return fout;
    };
    
#line 432
    Text::String FindLocalFile(Text::String filename)
    {
#line 433
        Text::String exe_dir_file = GetExeDirFile(filename);
        if (FileExists(exe_dir_file))
            return exe_dir_file;
#line 437
        for (int i = 0; i < __LocalFileDirs().GetCount(); i ++ )
            {
#line 438
                Text::String dir_file = AppendFileName(__LocalFileDirs()[i], filename);
                if (Native::PathExists(dir_file.Begin()) || Native::DirExists(dir_file.Begin()))
                    return dir_file;
            }
#line 443
        return ConfigFile(filename);
    };
    
#line 407
    Text::String GetDataDirectory()
    {
#line 408
        if (__DataPath().GetCount())
            return __DataPath();
        return Native::GetEnv("UPP_MAIN__");
    };
    
    Text::String GetDataFile(Text::String filename)
    {
#line 414
        if (__DataPath().GetCount())
            return AppendFileName(__DataPath(), filename);
        Text::String s = Native::GetEnv("UPP_MAIN__");
        if (s.GetCount())
            return AppendFileName(s, filename);
        else
            return GetExeDirFile(filename);
    };
    
#line 460
    void GetDirectoryFiles(Text::String dir, Container::Index < Text::String > & files)
    {
#line 461
        files.Clear();
        Native::GetDirFiles(dir.Begin(), &__FileAdder, (void * ) & files);
    };
    
#line 382
    Text::String GetEnv(Text::String id)
    {
#line 383
        if (id.IsEmpty())
            return Text::String();
        return Native::GetEnv(id.Begin());
    };
    
#line 185
    Text::String GetExeDirFile(Text::String filename)
    {
#line 186
        return AppendFileName(GetFileDirectory(GetExeFilePath()), filename);
#line 379
        return AppendFileName(GetFileDirectory(GetExeFilePath()), filename);
    };
    
#line 220
    Text::String GetFileDirectory(Text::String path)
    {
#line 221
        int i = path.ReverseFind("\\");
        int j = path.ReverseFind("/");
        if (i >= 0 && j >= 0)
            return path.Left(Algorithm::Maximum(i, j));
        if (i >= 0)
            return path.Left(i);
        if (j >= 0)
            return path.Left(j);
        return "";
    };
    
#line 256
    Text::String GetFileExt(Text::String path)
    {
#line 257
        static const char * path_str = "/";
        for (int i = path.GetCount() - 1; i >= 0; i -- )
            {
#line 259
                int chr = path[i];
                if (chr == path_str[0])
                    return "";
                if (chr == '.')
                    return path.Mid(i);
            }
        return "";
    };
    
#line 205
    Text::String GetFileName(Text::String path)
    {
#line 206
        int i = path.ReverseFind("/");
        if (i >= 0)
            return path.Mid(i + 1);
        return path;
    };
    
    Text::String GetFileTitle(Text::String path)
    {
#line 213
        Text::String fname = GetFileName(path);
        int i = fname.ReverseFind(".");
        if (i >= 0)
            return fname.Left(i);
        return fname;
    };
    
#line 17
    Text::String GetParentDirectory(Text::String path, int steps)
    {
#line 233
        path = TrimBoth(path);
        Text::String last_known_dir = path;
        for (int i = 0; i < steps; i ++ )
            {
#line 236
                if (path.IsEmpty())
                    return last_known_dir;
#line 239
                while (path.Right(1) == "/")
                    path = path.Left(path.GetCount() - 1);
#line 242
                int j = path.ReverseFind("/");
#line 244
                if (!j)
                    return "/";
#line 247
                if (j <= 0)
                    return path;
#line 250
                path = path.Left(j);
                last_known_dir = path;
            }
        return path;
    };
    
#line 465
    bool IsClose(double a, double b)
    {
#line 466
        if (Native::IsFinite(a) && Native::IsFinite(b))
        {
#line 467
            double diff = Algorithm::Absolute(a - b);
            return diff < 0.0001;
        }
        else
#line 470
            return a == b;
    };
    
#line 292
    Stream::CharStream& Log()
    {
#line 293
        static Stream::FileOut fout;
        static Stream::StringStream ss;
        if (!fout.IsOpen())
        {
#line 296
            Text::String exepath = GetExeFilePath();
            if (exepath.IsEmpty())
            {
#line 298
                return ss;
            }
            else
            {
#line 301
                Text::String exe_title = GetFileTitle(exepath);
                Text::String path = ConfigFile(exe_title + ".log");
                const char * p = path.Begin();
                RealizeDirectory(GetFileDirectory(path));
#line 306
                fout.Open(path);
#line 309
                fout << " *** " << GetExeFilePath() << " ***" << "\n";
#line 311
                if (ss.GetSize())
                    fout << ss.GetResult();
#line 314
                fout.Flush();
            }
        }
        return fout;
    };
    
#line 287
    void Panic(Text::String s)
    {
#line 288
        Lang::SysBreak(s.Begin());
    };
    
#line 348
    void ParseCommandLine(int argc, const char **argv)
    {
#line 349
        __CommandLine().Clear();
        for (int i = 1; i < argc; i ++ )
            __CommandLine().Add(argv[i]);
    };
    
#line 388
    void ReadCoreCmdlineArgs()
    {
#line 389
        for (int i = 0; i < __CommandLine().GetCount(); i ++ )
            {
#line 390
                Text::String arg = __CommandLine()[i];
                int j = arg.Find("=");
                if (j >= 0)
                {
#line 393
                    Text::String key = arg.Left(j);
                    Text::String value = arg.Mid(j + 1);
                    if (key.Left(2) == "-E")
                    {
#line 396
                        key = key.Mid(2);
                        SetCoreArg(key, value);
                    }
                }
            }
    };
    
#line 340
    Text::String ReadStdIn()
    {
#line 340
        return Cin().GetLine();
    };
    
#line 268
    void RealizeDirectory(Text::String dir)
    {
#line 269
        if (dir.IsEmpty())
            return;
        if (!Native::DirExists(dir.Begin()))
        {
#line 272
            RealizeDirectory(GetFileDirectory(dir));
#line 274
            if (!Native::PathExists(dir.Begin()))
                Native::CreateDirectory(dir.Begin());
        }
    };
    
#line 283
    void RenameFile(Text::String oldpath, Text::String newpath)
    {
#line 284
        Native::RenameFile(oldpath.Begin(), newpath.Begin());
    };
    
#line 363
    void SetCoreArg(Text::String key, Text::String value)
    {
#line 364
        if (key.IsEmpty())
            return;
        {
            Log() << "core-arg: \"" << key << "\" -> \"" << value << "\"" << "\n";
#line 367
            Log().Flush();
        }
#line 368
        ;
#line 368
        if (key == "datapath")
        {
            {
#line 369
                if (!(DirectoryExists(value)))
                {
#line 369
                    Lang::SysBreak("Assertion failed: DirectoryExists(value)");
                }
            }
#line 370
            ;
#line 370
            __DataPath() = value;
        }
        else 
#line 372
        if (key == "config")
        {
            {
#line 373
                if (!(DirectoryExists(value)))
                {
#line 373
                    Lang::SysBreak("Assertion failed: DirectoryExists(value)");
                }
            }
#line 374
            ;
#line 374
            __ConfigPath() = value;
        }
    };
    
#line 750
    template < class _1, class _2 >
    void Sort(_1& vector, const _2& sorter)
    {
#line 752
        if (vector.GetCount() < 2)
            return;
#line 755
        __Sort(vector.Begin().Get(), vector.End().Get(), sorter);
    };
    
#line 900
    bool StreamCopy(Abstract::StreamBase& dest, Abstract::StreamBase& src)
    {
#line 901
        dest.Seek(0);
        src.Seek(0);
        Lang::byte buf[1024];
        Lang::int64 size_left = src.GetSize();
        while (size_left > 0)
            {
#line 906
                int block;
                if (size_left < 1024)
#line 907
                    block = (int) size_left;
                else
#line 908
                    block = 1024;
                int got = src.Get(buf, block);
                if (got != block)
                    return false;
                dest.Put(buf, block);
                size_left -= block;
            }
        return true;
    };
    
#line 454
    void __FileAdder(const char *str, void *files_idx)
    {
#line 455
        typedef Container::Index < Text::String > Idx;
        Idx * p = (Idx * ) files_idx;
        p -> Add(str);
    };
    
#line 705
    template < class _1, class _2 >
    void __Sort(_1 l, _1 h, const _2& less)
    {
        for (;;)
            {
#line 709
                int count = int(h - l);
                if (count < 2)
                    return;
                if (count < 8)
                {
#line 713
                    __FinalSort(l, h, less);
                    return;
                }
                int pass = 4;
                for (;;)
                    {
#line 718
                        _1 middle = l + (count >> 1);
                        __OrderIter2(l, middle, less);
                        __OrderIter2(middle, h - 1, less);
                        __OrderIter2(l, middle, less);
                        __IterSwap(l + 1, middle);
                        _1 ii = l + 1;
                        for (_1 i = l + 2; i != h - 1; ++ i)
                            if (less(*i, *(l + 1)))
                                __IterSwap(++ ii, i);
                        __IterSwap(ii, l + 1);
                        _1 iih = ii;
                        while (iih + 1 != h && !less(*ii, *(iih + 1)))
                            ++ iih;
                        if (pass > 5 || min(ii - l, h - iih) > (max(ii - l, h - iih) >> pass))
                        {
#line 732
                            if (ii - l < h - iih - 1)
                            {
#line 733
                                __Sort(l, ii, less);
                                l = iih + 1;
                            }
                            else
                            {
#line 737
                                __Sort(iih + 1, h, less);
                                h = ii;
                            }
                            break;
                        
                        }
#line 742
                        __IterSwap(l, l + Random::Range(count));
                        __IterSwap(middle, l + Random::Range(count));
                        __IterSwap(h - 1, l + Random::Range(count));
                        pass ++ ;
                    }
            }
    };
    
#line 125
    const int CommandLineArguments::max_args = 100;
#line 124
    const int CommandLineArguments::max_inputs = 300;
    
#line 778
    void CommandLineArguments::AddArg(char key, const char *desc, bool has_value)
    {
#line 779
        CmdArg & a = args.Add();
        a.key = key;
        a.desc = desc;
        a.has_value = has_value;
    };
    
    bool CommandLineArguments::Parse()
    {
#line 786
        const Container::Vector < Text::String > & args = CommandLine();
#line 788
        for (int i = 0; i < args.GetCount(); i ++ )
            {
#line 789
                Text::String arg = args[i];
#line 791
                if (arg.GetCount() < 2)
#line 791
                    return false;
#line 793
                bool found = false;
#line 795
                if (arg[0] == '-')
                {
#line 796
                    char key = arg[1];
                    if (key)
                    {
#line 798
                        for (int j = 0; j < this -> args.GetCount(); j ++ )
                            {
#line 799
                                CmdArg & a = this -> args[j];
                                if (a.key == key)
                                {
#line 801
                                    found = true;
                                    CmdInput & in = inputs.Add();
                                    in.key = key;
                                    if (a.has_value)
                                    {
#line 805
                                        if (i + 1 >= args.GetCount())
                                        {
#line 806
                                            Errout() << "No value provided: " << arg << "\n";
                                            return false;
                                        }
                                        in.value = args[i + 1];
                                        i ++ ;
                                    }
                                    break;
                                
                                }
                            }
                    }
                }
                if (!found)
                {
#line 818
                    Errout() << "Invalid argument: " << arg << "\n";
#line 818
                    return false;
                }
            }
        return true;
    };
    
    void CommandLineArguments::PrintHelp()
    {
#line 825
        Text::String exe = GetExeFilePath();
        int i = exe.ReverseFind("/");
        if (i >= 0)
            exe = exe.Mid(i + 1);
#line 830
        Stream::CharStream & cout = Cout();
        cout << exe << " [-";
        for (int i = 0; i < args.GetCount(); i ++ )
            if (args[i].has_value)
                cout << args[i].key;
        cout << " value]";
#line 837
        cout << " [-";
        for (int i = 0; i < args.GetCount(); i ++ )
            if (!args[i].has_value)
                cout << args[i].key;
        cout << "]" << "\n";
#line 843
        for (int i = 0; i < args.GetCount(); i ++ )
            {
#line 844
                CmdArg & a = args[i];
                cout << "\t-" << a.key;
                if (a.has_value)
                    cout << " value";
                cout << ": " << a.desc << "\n";
            }
    };
    
#line 147
    template < class _1 >
    DtorValueSetter < _1 >::DtorValueSetter(_1& obj)
    :
        obj(obj),
        value(0)
    {};
    
#line 617
    FindFile::FindFile() {};
    
#line 637
    Text::String FindFile::GetName() const
    {
        {
#line 638
            Panic("TODO");
#line 638
            throw Text::Exc();
        }
    };
    
#line 633
    Text::String FindFile::GetPath() const
    {
        {
#line 634
            Panic("TODO");
#line 634
            throw Text::Exc();
        }
    };
    
#line 629
    bool FindFile::IsDirectory() const
    {
        {
#line 630
            Panic("TODO");
#line 630
            throw Text::Exc();
        }
    };
    
#line 625
    bool FindFile::Next()
    {
        {
#line 626
            Panic("TODO");
#line 626
            throw Text::Exc();
        }
    };
    
#line 621
    bool FindFile::Search(Text::String path)
    {
        {
#line 622
            Panic("TODO");
#line 622
            throw Text::Exc();
        }
    };
    
#line 561
    StringCache::StringCache()
    :
        str_counter(0)
    {};
    
#line 598
    Text::String StringCache::Get(int i) const
    {
#line 599
        return strings[i];
    };
    
#line 563
    int StringCache::GetAdd(const Text::String& s)
    {
#line 564
        Lang::uint32 hash = s.GetHashValue();
        Lang::FwdIterator < Lang::uint32 > it = hashes.Begin();
        Lang::FwdIterator < Lang::uint32 > end = hashes.End();
        int i = 0;
        while (it != end)
            {
#line 569
                if (*it == hash)
                    return i;
                ++ i;
#line 571
                ++ it;
            }
#line 574
        lock.Enter();
        if (free_slots.GetCount())
            i = free_slots.Pop();
        else
        {
#line 578
            i = hashes.GetCount();
            hashes.Add();
            strings.Add();
        }
        lock.Leave();
#line 584
        hashes[i] = hash;
        strings[i] = s;
        return i;
    };
    
#line 602
    int StringCache::GetCount() const
    {
#line 603
        return strings.GetCount();
    };
    
#line 589
    void StringCache::Remove(int i)
    {
#line 590
        hashes[i] = 0xFFFFFFFF;
        strings[i] = 0;
#line 593
        lock.Enter();
        free_slots.Add(i);
        lock.Leave();
    };
    
#line 67
    StringParser::StringParser(Text::String s)
    :
        s(s),
        cursor(0)
    {};
    
#line 487
    bool StringParser::Char(int chr)
    {
#line 488
        int curchr = s[cursor];
        if (curchr == chr)
        {
#line 490
            cursor ++ ;
            PassWhite();
            return true;
        }
        return false;
    };
    
#line 528
    int StringParser::GetChar()
    {
#line 529
        return s[cursor ++ ];
    };
    
#line 536
    bool StringParser::IsChar(int chr)
    {
#line 537
        return s[cursor] == chr;
    };
    
#line 69
    void StringParser::PassChar(int chr, bool do_pass_white)
    {
#line 480
        if (!IsChar(chr))
            throw Text::Exc("unexpected char");
        cursor ++ ;
        if (do_pass_white)
            PassWhite();
    };
    
#line 540
    void StringParser::PassWhite()
    {
#line 541
        while (cursor < s.GetCount())
            {
#line 542
                int chr = s[cursor];
                if (Text::IsSpace(chr))
                    cursor ++ ;
                else
                    break;
            
            }
    };
    
#line 532
    int StringParser::PeekChar()
    {
#line 533
        return s[cursor];
    };
    
#line 506
    Text::String StringParser::ReadId()
    {
#line 507
        Text::String id;
        while (cursor < s.GetCount())
            {
#line 509
                int chr = s[cursor];
                if (Text::IsSpace(chr))
                    break;
                
                if (chr == '\\')
                {
#line 514
                    cursor ++ ;
                    chr = s[cursor];
                }
                if (Text::IsAlpha(chr) || chr == '_' || Text::IsDigit(chr))
                {
#line 518
                    id.Cat(chr);
                    cursor ++ ;
                }
                else
                    break;
            
            }
#line 524
        PassWhite();
        return id;
    };
    
#line 497
    int StringParser::ReadInt()
    {
#line 498
        Text::String i;
        while (Text::IsDigit(s[cursor]))
            {
#line 500
                i.Cat(s[cursor ++ ]);
            }
        PassWhite();
        return Text::String::StrInt(i);
    };
    
};

#endif
