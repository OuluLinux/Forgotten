#ifndef UTIL_CXX
#define UTIL_CXX

#include <new>

#ifndef UTIL_HXX
#include <Util.hxx>
#endif

namespace Util
{
#line 228 "../../src/Com/Util.fog"
    Text::String AppendFileName(Text::String a, Text::String b)
    {
#line 229
        if (b.IsEmpty())
#line 229
            return a;
        if (a.IsEmpty())
#line 230
            return b;
        bool a_sep = a.ReverseFind("/") == a.GetCount() - 1;
        bool b_sep = b.Find("/") == 0;
        if (!a_sep)
        {
#line 234
            if (!b_sep)
                return a + "/" + b;
            else
                return a + b;
        }
        else
        {
#line 240
            if (!b_sep)
                return a + b;
            else
                return a + b.Mid(1);
        }
    };
    
#line 394
    Stream::CharStream& Cerr()
    {
#line 395
        static Stream::FileOut fout(Native::GetStdErr());
        return fout;
    };
    
#line 389
    Stream::CharStream& Cin()
    {
#line 390
        static Stream::FileOut fout(Native::GetStdIn());
        return fout;
    };
    
#line 247
    Text::String ConfigFile(Text::String file_name)
    {
#line 248
        if (ConfigPath().GetCount())
            return AppendFileName(ConfigPath(), file_name);
#line 254
        Text::String home_dir = GetHomeDir();
        Text::String upp = AppendFileName(home_dir, ".config");
        upp = AppendFileName(upp, "u++");
        Text::String dir = AppendFileName(upp, GetFileTitle(Env::Local().GetExeFilePath()));
#line 260
        return AppendFileName(dir, file_name);
    };
    
#line 379
    Stream::CharStream& Cout()
    {
#line 380
        static Stream::FileOut fout(Native::GetStdOut());
        return fout;
    };
    
    Stream::CharStream& Errout()
    {
#line 385
        static Stream::FileOut fout(Native::GetStdErr());
        return fout;
    };
    
#line 445
    Text::String FindLocalFile(Text::String filename)
    {
#line 446
        Text::String exe_dir_file = GetExeDirFile(filename);
        if (FileExists(exe_dir_file))
            return exe_dir_file;
#line 450
        for (int i = 0; i < __LocalFileDirs().GetCount(); i ++ )
            {
#line 451
                Text::String dir_file = AppendFileName(__LocalFileDirs()[i], filename);
                if (Native::PathExists(dir_file.Begin()) || Native::DirExists(dir_file.Begin()))
                    return dir_file;
            }
#line 456
        return ConfigFile(filename);
    };
    
#line 420
    Text::String GetDataDirectory()
    {
#line 421
        if (__DataPath().GetCount())
            return __DataPath();
        return Native::GetEnv("UPP_MAIN__");
    };
    
    Text::String GetDataFile(Text::String filename)
    {
#line 427
        if (__DataPath().GetCount())
            return AppendFileName(__DataPath(), filename);
        Text::String s = Native::GetEnv("UPP_MAIN__");
        if (s.GetCount())
            return AppendFileName(s, filename);
        else
            return GetExeDirFile(filename);
    };
    
#line 473
    void GetDirectoryFiles(Text::String dir, Container::Index < Text::String > & files)
    {
#line 474
        files.Clear();
        Native::GetDirFiles(dir.Begin(), &__FileAdder, (void * ) & files);
    };
    
#line 410
    Text::String GetEnv(Text::String id)
    {
#line 411
        if (id.IsEmpty())
            return Text::String();
        return Native::GetEnv(id.Begin());
    };
    
#line 406
    Text::String GetExeDirFile(Text::String filename)
    {
#line 407
        return AppendFileName(GetFileDirectory(Env::Local().GetExeFilePath()), filename);
    };
    
#line 278
    Text::String GetFileDirectory(Text::String path)
    {
#line 279
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
    
#line 314
    Text::String GetFileExt(Text::String path)
    {
#line 315
        static const char * path_str = "/";
        for (int i = path.GetCount() - 1; i >= 0; i -- )
            {
#line 317
                int chr = path[i];
                if (chr == path_str[0])
                    return "";
                if (chr == '.')
                    return path.Mid(i);
            }
        return "";
    };
    
#line 263
    Text::String GetFileName(Text::String path)
    {
#line 264
        int i = path.ReverseFind("/");
        if (i >= 0)
            return path.Mid(i + 1);
        return path;
    };
    
    Text::String GetFileTitle(Text::String path)
    {
#line 271
        Text::String fname = GetFileName(path);
        int i = fname.ReverseFind(".");
        if (i >= 0)
            return fname.Left(i);
        return fname;
    };
    
#line 86
    Text::String GetParentDirectory(Text::String path, int steps)
    {
#line 291
        path = TrimBoth(path);
        Text::String last_known_dir = path;
        for (int i = 0; i < steps; i ++ )
            {
#line 294
                if (path.IsEmpty())
                    return last_known_dir;
#line 297
                while (path.Right(1) == "/")
                    path = path.Left(path.GetCount() - 1);
#line 300
                int j = path.ReverseFind("/");
#line 302
                if (!j)
                    return "/";
#line 305
                if (j <= 0)
                    return path;
#line 308
                path = path.Left(j);
                last_known_dir = path;
            }
        return path;
    };
    
#line 478
    bool IsClose(double a, double b)
    {
#line 479
        if (Native::IsFinite(a) && Native::IsFinite(b))
        {
#line 480
            double diff = Algorithm::Absolute(a - b);
            return diff < 0.0001;
        }
        else
#line 483
            return a == b;
    };
    
#line 464
    bool IsVerbose()
    {
#line 464
        return __Verbose();
    };
    
#line 350
    Stream::CharStream& Log()
    {
#line 351
        static Stream::FileOut fout;
        static Stream::StringStream ss;
        if (!fout.IsOpen())
        {
#line 354
            Text::String exepath = Env::Local().GetExeFilePath();
            if (exepath.IsEmpty())
            {
#line 356
                return ss;
            }
            else
            {
#line 359
                const char * e = exepath.Begin();
                Text::String exe_title = GetFileTitle(exepath);
                Text::String path = ConfigFile(exe_title + ".log");
                const char * p = path.Begin();
                RealizeDirectory(GetFileDirectory(path));
#line 365
                fout.Open(path);
                fout << " *** " << Chrono::GetSysTime().AsString() << " ***" << "\n";
                fout << " *** " << exepath << " ***" << "\n";
#line 370
                if (ss.GetSize())
                    fout << ss.GetResult();
#line 373
                fout.Flush();
            }
        }
        return fout;
    };
    
#line 345
    void Panic(Text::String s)
    {
#line 346
        Lang::SysBreak(s.Begin());
    };
    
#line 399
    Text::String ReadStdIn()
    {
#line 399
        return Cin().GetLine();
    };
    
#line 326
    void RealizeDirectory(Text::String dir)
    {
#line 327
        if (dir.IsEmpty())
            return;
        if (!Native::DirExists(dir.Begin()))
        {
#line 330
            RealizeDirectory(GetFileDirectory(dir));
#line 332
            if (!Native::PathExists(dir.Begin()))
                Native::CreateDirectory(dir.Begin());
        }
    };
    
#line 341
    void RenameFile(Text::String oldpath, Text::String newpath)
    {
#line 342
        Native::RenameFile(oldpath.Begin(), newpath.Begin());
    };
    
#line 108
    void SetVerbose(bool b)
    {
#line 465
        __Verbose() = b;
    };
    
#line 763
    template < class _1, class _2 >
    void Sort(_1& vector, const _2& sorter)
    {
#line 765
        if (vector.GetCount() < 2)
            return;
#line 768
        __Sort(vector.Begin().Get(), vector.End().Get(), sorter);
    };
    
#line 913
    bool StreamCopy(Abstract::StreamBase& dest, Abstract::StreamBase& src)
    {
#line 914
        dest.Seek(0);
        src.Seek(0);
        Lang::byte buf[1024];
        Lang::int64 size_left = src.GetSize();
        while (size_left > 0)
            {
#line 919
                int block;
                if (size_left < 1024)
#line 920
                    block = (int) size_left;
                else
#line 921
                    block = 1024;
                int got = src.Get(buf, block);
                if (got != block)
                    return false;
                dest.Put(buf, block);
                size_left -= block;
            }
        return true;
    };
    
#line 467
    void __FileAdder(const char *str, void *files_idx)
    {
#line 468
        typedef Container::Index < Text::String > Idx;
        Idx * p = (Idx * ) files_idx;
        p -> Add(str);
    };
    
#line 718
    template < class _1, class _2 >
    void __Sort(_1 l, _1 h, const _2& less)
    {
        for (;;)
            {
#line 722
                int count = int(h - l);
                if (count < 2)
                    return;
                if (count < 8)
                {
#line 726
                    __FinalSort(l, h, less);
                    return;
                }
                int pass = 4;
                for (;;)
                    {
#line 731
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
#line 745
                            if (ii - l < h - iih - 1)
                            {
#line 746
                                __Sort(l, ii, less);
                                l = iih + 1;
                            }
                            else
                            {
#line 750
                                __Sort(iih + 1, h, less);
                                h = ii;
                            }
                            break;
                        
                        }
#line 755
                        __IterSwap(l, l + Random::Range(count));
                        __IterSwap(middle, l + Random::Range(count));
                        __IterSwap(h - 1, l + Random::Range(count));
                        pass ++ ;
                    }
            }
    };
    
#line 463
    bool& __Verbose()
    {
#line 463
        static bool b;
#line 463
        return b;
    };
    
#line 187
    const int CommandLineArguments::max_args = 100;
#line 186
    const int CommandLineArguments::max_inputs = 300;
    
#line 791
    void CommandLineArguments::AddArg(char key, const char *desc, bool has_value)
    {
#line 792
        CmdArg & a = args.Add();
        a.key = key;
        a.desc = desc;
        a.has_value = has_value;
    };
    
    bool CommandLineArguments::Parse()
    {
#line 799
        const Container::Vector < Text::String > & args = Env::Local().CommandLine();
#line 801
        for (int i = 0; i < args.GetCount(); i ++ )
            {
#line 802
                Text::String arg = args[i];
#line 804
                if (arg.GetCount() < 2)
#line 804
                    return false;
#line 806
                bool found = false;
#line 808
                if (arg[0] == '-')
                {
#line 809
                    char key = arg[1];
                    if (key)
                    {
#line 811
                        for (int j = 0; j < this -> args.GetCount(); j ++ )
                            {
#line 812
                                CmdArg & a = this -> args[j];
                                if (a.key == key)
                                {
#line 814
                                    found = true;
                                    CmdInput & in = inputs.Add();
                                    in.key = key;
                                    if (a.has_value)
                                    {
#line 818
                                        if (i + 1 >= args.GetCount())
                                        {
#line 819
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
#line 831
                    Errout() << "Invalid argument: " << arg << "\n";
#line 831
                    return false;
                }
            }
        return true;
    };
    
    void CommandLineArguments::PrintHelp()
    {
#line 838
        Text::String exe = Env::Local().GetExeFilePath();
        int i = exe.ReverseFind("/");
        if (i >= 0)
            exe = exe.Mid(i + 1);
#line 843
        Stream::CharStream & cout = Cout();
        cout << exe << " [-";
        for (int i = 0; i < args.GetCount(); i ++ )
            if (args[i].has_value)
                cout << args[i].key;
        cout << " value]";
#line 850
        cout << " [-";
        for (int i = 0; i < args.GetCount(); i ++ )
            if (!args[i].has_value)
                cout << args[i].key;
        cout << "]" << "\n";
#line 856
        for (int i = 0; i < args.GetCount(); i ++ )
            {
#line 857
                CmdArg & a = args[i];
                cout << "\t-" << a.key;
                if (a.has_value)
                    cout << " value";
                cout << ": " << a.desc << "\n";
            }
    };
    
#line 209
    template < class _1 >
    DtorValueSetter < _1 >::DtorValueSetter(_1& obj)
    :
        obj(obj),
        value(0)
    {};
    
#line 21
    int Env::Deinit()
    {
#line 22
        ShutdownThreads();
        RunExitBlocks();
        return GetExitCode();
    };
    
#line 14
    void Env::Init(int argc, const char **argv)
    {
#line 15
        SetExeFilePath(argv[0]);
        ParseCommandLine(argc, argv);
        ReadComCmdlineArgs();
        RunInitBlocks();
    };
    
#line 41
    void Env::ParseCommandLine(int argc, const char **argv)
    {
#line 42
        for (int i = 1; i < argc; i ++ )
            cmd.Add(argv[i]);
    };
    
#line 45
    void Env::ReadComCmdlineArgs()
    {
#line 46
        for (int i = 0; i < cmd.GetCount(); i ++ )
            {
#line 47
                Text::String arg = cmd[i];
                int j = arg.Find("=");
                if (j >= 0)
                {
#line 50
                    Text::String key = arg.Left(j);
                    Text::String value = arg.Mid(j + 1);
                    if (key.Left(2) == "-E")
                    {
#line 53
                        key = key.Mid(2);
                        SetCoreArg(key, value);
                    }
                }
            }
    };
    
#line 62
    void Env::SetCoreArg(Text::String key, Text::String value)
    {
#line 63
        if (key.IsEmpty())
            return;
        {
            Log() << "core-arg: \"" << key << "\" -> \"" << value << "\"" << "\n";
#line 66
            Log().Flush();
        }
#line 67
        ;
#line 67
        if (key == "datapath")
        {
            {
#line 68
                if (!(DirectoryExists(value)))
                {
#line 68
                    Lang::SysBreak("Assertion failed: DirectoryExists(value)");
                }
            }
#line 69
            ;
#line 69
            __DataPath() = value;
        }
        else 
#line 71
        if (key == "config")
        {
            {
#line 72
                if (!(DirectoryExists(value)))
                {
#line 72
                    Lang::SysBreak("Assertion failed: DirectoryExists(value)");
                }
            }
#line 73
            ;
#line 73
            __ConfigPath() = value;
        }
    };
    
#line 630
    FindFile::FindFile() {};
    
#line 650
    Text::String FindFile::GetName() const
    {
        {
#line 651
            Panic("TODO");
#line 651
            throw Text::Exc();
        }
    };
    
#line 646
    Text::String FindFile::GetPath() const
    {
        {
#line 647
            Panic("TODO");
#line 647
            throw Text::Exc();
        }
    };
    
#line 642
    bool FindFile::IsDirectory() const
    {
        {
#line 643
            Panic("TODO");
#line 643
            throw Text::Exc();
        }
    };
    
#line 638
    bool FindFile::Next()
    {
        {
#line 639
            Panic("TODO");
#line 639
            throw Text::Exc();
        }
    };
    
#line 634
    bool FindFile::Search(Text::String path)
    {
        {
#line 635
            Panic("TODO");
#line 635
            throw Text::Exc();
        }
    };
    
#line 947
    void FloatTrans::Serialize(Abstract::StreamBase& s)
    {
#line 948
        if (s.IsLoading())
        {
#line 949
            float f;
            s % f;
            value = f;
        }
        else
        {
#line 954
            s % value;
        }
    };
    
#line 574
    StringCache::StringCache()
    :
        str_counter(0)
    {};
    
#line 611
    Text::String StringCache::Get(int i) const
    {
#line 612
        return strings[i];
    };
    
#line 576
    int StringCache::GetAdd(const Text::String& s)
    {
#line 577
        Lang::uint32 hash = s.GetHashValue();
        Lang::FwdIterator < Lang::uint32 > it = hashes.Begin();
        Lang::FwdIterator < Lang::uint32 > end = hashes.End();
        int i = 0;
        while (it != end)
            {
#line 582
                if (*it == hash)
                    return i;
                ++ i;
#line 584
                ++ it;
            }
#line 587
        lock.Enter();
        if (free_slots.GetCount())
            i = free_slots.Pop();
        else
        {
#line 591
            i = hashes.GetCount();
            hashes.Add();
            strings.Add();
        }
        lock.Leave();
#line 597
        hashes[i] = hash;
        strings[i] = s;
        return i;
    };
    
#line 615
    int StringCache::GetCount() const
    {
#line 616
        return strings.GetCount();
    };
    
#line 602
    void StringCache::Remove(int i)
    {
#line 603
        hashes[i] = 0xFFFFFFFF;
        strings[i] = 0;
#line 606
        lock.Enter();
        free_slots.Add(i);
        lock.Leave();
    };
    
#line 129
    StringParser::StringParser(Text::String s)
    :
        s(s),
        cursor(0)
    {};
    
#line 500
    bool StringParser::Char(int chr)
    {
#line 501
        int curchr = s[cursor];
        if (curchr == chr)
        {
#line 503
            cursor ++ ;
            PassWhite();
            return true;
        }
        return false;
    };
    
#line 541
    int StringParser::GetChar()
    {
#line 542
        return s[cursor ++ ];
    };
    
#line 549
    bool StringParser::IsChar(int chr)
    {
#line 550
        return s[cursor] == chr;
    };
    
#line 131
    void StringParser::PassChar(int chr, bool do_pass_white)
    {
#line 493
        if (!IsChar(chr))
            throw Text::Exc("unexpected char");
        cursor ++ ;
        if (do_pass_white)
            PassWhite();
    };
    
#line 553
    void StringParser::PassWhite()
    {
#line 554
        while (cursor < s.GetCount())
            {
#line 555
                int chr = s[cursor];
                if (Text::IsSpace(chr))
                    cursor ++ ;
                else
                    break;
            
            }
    };
    
#line 545
    int StringParser::PeekChar()
    {
#line 546
        return s[cursor];
    };
    
#line 519
    Text::String StringParser::ReadId()
    {
#line 520
        Text::String id;
        while (cursor < s.GetCount())
            {
#line 522
                int chr = s[cursor];
                if (Text::IsSpace(chr))
                    break;
                
                if (chr == '\\')
                {
#line 527
                    cursor ++ ;
                    chr = s[cursor];
                }
                if (Text::IsAlpha(chr) || chr == '_' || Text::IsDigit(chr))
                {
#line 531
                    id.Cat(chr);
                    cursor ++ ;
                }
                else
                    break;
            
            }
#line 537
        PassWhite();
        return id;
    };
    
#line 510
    int StringParser::ReadInt()
    {
#line 511
        Text::String i;
        while (Text::IsDigit(s[cursor]))
            {
#line 513
                i.Cat(s[cursor ++ ]);
            }
        PassWhite();
        return Text::String::StrInt(i);
    };
    
#line 980
    Version::Version(Lang::byte write_v, Abstract::StreamBase& s)
    :
        write_v(write_v),
        read_v(0),
        s(s)
    {
#line 981
        if (s.IsStoring())
            s.Put(&write_v, sizeof (write_v));
        else
            s.Get(&read_v, sizeof (read_v));
    };
    
    bool Version::Is(Lang::byte cmp_v)
    {
#line 988
        if (s.IsStoring())
            return cmp_v <= write_v;
        else
            return cmp_v <= read_v;
    };
    
};

#endif
