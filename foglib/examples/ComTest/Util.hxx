#ifndef UTIL_HXX
#define UTIL_HXX

#include <new>

#ifndef CONTAINER_HXX
#include <Container.hxx>
#endif

#ifndef STREAM_HXX
#include <Stream.hxx>
#endif

namespace Util
{
#line 446 "../../src/Com/Util.fog"
    inline void AddLocalFileDirectory(Text::String dir);
#line 166
    Text::String AppendFileName(Text::String a, Text::String b);
#line 335
    Stream::CharStream& Cerr();
#line 330
    Stream::CharStream& Cin();
#line 354
    inline const Container::Vector < Text::String > & CommandLine();
#line 189
    Text::String ConfigFile(Text::String file_name);
#line 10
    inline Text::String& ConfigPath();
#line 861
    template < class _1, class _2 >
    inline void CopyHeapless(const _1& from, _1& to);
#line 874
    template < class _1, class _2 >
    inline void CopyHeaplessMat(const _1& from, _1& to);
#line 320
    Stream::CharStream& Cout();
#line 279
    inline void DeleteFile(Text::String path);
#line 428
    inline bool DirectoryExists(Text::String path);
#line 325
    Stream::CharStream& Errout();
#line 6
    inline Text::String& ExeFilePath();
#line 427
    inline bool FileExists(Text::String path);
#line 432
    Text::String FindLocalFile(Text::String filename);
#line 407
    Text::String GetDataDirectory();
#line 423
    inline Text::String GetDataDirectoryFile(Text::String file);
#line 413
    Text::String GetDataFile(Text::String filename);
#line 460
    void GetDirectoryFiles(Text::String dir, Container::Index < Text::String > & files);
#line 382
    Text::String GetEnv(Text::String id);
#line 185
    Text::String GetExeDirFile(Text::String filename);
#line 8
    inline Text::String GetExeFilePath();
#line 357
    inline int GetExitCode();
#line 220
    Text::String GetFileDirectory(Text::String path);
#line 256
    Text::String GetFileExt(Text::String path);
#line 205
    Text::String GetFileName(Text::String path);
#line 212
    Text::String GetFileTitle(Text::String path);
#line 9
    inline Text::String GetHomeDir();
#line 17
    Text::String GetParentDirectory(Text::String path, int steps = 1);
#line 465
    bool IsClose(double a, double b);
#line 47
    inline bool IsDotString(Text::String s);
#line 451
    inline bool IsVerbose();
#line 292
    Stream::CharStream& Log();
#line 287
    void Panic(Text::String s);
#line 344
    inline void ParseCommandLine(const char *cmdline);
#line 348
    void ParseCommandLine(int argc, const char **argv);
#line 57
    template < class _1 >
    inline _1& PtrRef(_1 *o, Text::String throw_msg);
#line 388
    void ReadCoreCmdlineArgs();
#line 340
    Text::String ReadStdIn();
#line 268
    void RealizeDirectory(Text::String dir);
#line 283
    void RenameFile(Text::String oldpath, Text::String newpath);
#line 363
    void SetCoreArg(Text::String key, Text::String value);
#line 403
    inline void SetDataPath(Text::String path);
#line 7
    inline void SetExeFilePath(Text::String s);
#line 358
    inline void SetExitCode(int i);
#line 46
    inline void SetVerbose(bool b = true);
#line 51
    template < class _1 >
    inline _1& Single();
#line 750
    template < class _1, class _2 >
    void Sort(_1& vector, const _2& sorter);
#line 900
    bool StreamCopy(Abstract::StreamBase& dest, Abstract::StreamBase& src);
#line 886
    inline void VectorAdd(const Container::Vector < double > & from, Container::Vector < double > & to);
#line 342
    inline Container::Vector < Text::String > & __CommandLine();
#line 361
    inline Text::String& __ConfigPath();
#line 360
    inline Text::String& __DataPath();
#line 356
    inline int& __ExitCode();
#line 454
    void __FileAdder(const char *str, void *files_idx);
#line 665
    template < class _1, class _2 >
    inline void __FinalSort(_1 begin, _1 end, const _2& less);
#line 653
    template < class _1 >
    inline void __IterSwap(_1 a, _1 b);
#line 430
    inline Container::Vector < Text::String > & __LocalFileDirs();
#line 659
    template < class _1, class _2 >
    inline void __OrderIter2(_1 a, _1 b, const _2& less);
#line 705
    template < class _1, class _2 >
    void __Sort(_1 l, _1 h, const _2& less);
#line 450
    inline bool& __Verbose();
    
    struct CmdArg
    {
#line 113
        char key;
        Text::String desc;
        bool has_value;
    };
    
    struct CmdInput
    {
#line 119
        char key;
        Text::String value;
    };
    
    class CommandLineArguments
    {
#line 127
        Container::Array < CmdArg > args;
        Container::Array < CmdInput > inputs;
        
    public:
#line 132
        inline CommandLineArguments();
#line 778
        void AddArg(char key, const char *desc, bool has_value);
#line 136
        inline int GetInputCount() const;
        inline const Container::Array < CmdInput > & GetInputs() const;
#line 785
        bool Parse();
#line 824
        void PrintHelp();
        
#line 125
        static const int max_args;
#line 124
        static const int max_inputs;
    };
    
    template < class _1 >
    struct DtorValueSetter
    {
#line 145
        _1& obj;
        int value;
        
#line 147
        DtorValueSetter(_1& obj);
        inline ~DtorValueSetter();
    };
    
    struct FindFile
    {
#line 98
        typedef FindFile CLASSNAME;
        
#line 617
        FindFile();
#line 637
        Text::String GetName() const;
#line 633
        Text::String GetPath() const;
#line 629
        bool IsDirectory() const;
#line 625
        bool Next();
#line 621
        bool Search(Text::String path);
    };
    
    template < class _1 >
    struct StdGreater
    {
#line 759
        inline bool operator()(const _1& a, const _1& b) const;
    };
    
    template < class _1 >
    struct StdLess
    {
#line 758
        inline bool operator()(const _1& a, const _1& b) const;
    };
    
    class StringCache
    {
#line 82
        Container::Vector < unsigned int > hashes;
        Container::Vector < Text::String > strings;
        Container::Vector < int > free_slots;
        int str_counter;
        Lang::AtomicFlag lock;
        
    public:
#line 561
        StringCache();
#line 598
        Text::String Get(int i) const;
#line 563
        int GetAdd(const Text::String& s);
#line 602
        int GetCount() const;
#line 589
        void Remove(int i);
    };
    
    struct StringParser
    {
#line 64
        Text::String s;
        int cursor;
        
        StringParser(Text::String s);
#line 487
        bool Char(int chr);
#line 528
        int GetChar();
#line 536
        bool IsChar(int chr);
#line 69
        void PassChar(int chr, bool do_pass_white = true);
#line 540
        void PassWhite();
#line 532
        int PeekChar();
#line 506
        Text::String ReadId();
#line 497
        int ReadInt();
    };
};

namespace Util
{
#line 446
    inline void AddLocalFileDirectory(Text::String dir)
    {
#line 447
        __LocalFileDirs().Add(dir);
    };
    
#line 354
    inline const Container::Vector < Text::String > & CommandLine()
    {
#line 354
        return __CommandLine();
    };
    
#line 10
    inline Text::String& ConfigPath()
    {
#line 10
        static Text::String s;
#line 10
        return s;
    };
    
#line 861
    template < class _1, class _2 >
    inline void CopyHeapless(const _1& from, _1& to)
    {
#line 863
        Lang::FwdIterator < _2 > src = from.Begin();
        Lang::FwdIterator < _2 > end = from.End();
        Lang::FwdIterator < _2 > dst = to.Begin();
        to.SetCount(from.GetCount());
        while (src != end)
            {
#line 868
                *dst = *src;
                src ++ ;
                dst ++ ;
            }
    };
    
    template < class _1, class _2 >
    inline void CopyHeaplessMat(const _1& from, _1& to)
    {
#line 876
        to.SetCount(from.GetCount());
        for (int i = 0; i < to.GetCount(); i ++ )
            {
#line 878
                const _2 & from0 = from[i];
                _2 & to0 = to[i];
                to0.SetCount(from0.GetCount());
                for (int i = 0; i < to0.GetCount(); i ++ )
                    to0[i] = from0[i];
            }
    };
    
#line 279
    inline void DeleteFile(Text::String path)
    {
#line 280
        Native::DeleteFile(path.Begin());
    };
    
#line 428
    inline bool DirectoryExists(Text::String path)
    {
#line 428
        return Native::DirExists(path.Begin());
    };
    
#line 6
    inline Text::String& ExeFilePath()
    {
#line 6
        static Text::String s;
#line 6
        return s;
    };
    
#line 427
    inline bool FileExists(Text::String path)
    {
#line 427
        return Native::PathExists(path.Begin());
    };
    
#line 423
    inline Text::String GetDataDirectoryFile(Text::String file)
    {
#line 424
        return AppendFileName(GetDataDirectory(), file);
    };
    
#line 8
    inline Text::String GetExeFilePath()
    {
#line 8
        return ExeFilePath();
    };
    
#line 357
    inline int GetExitCode()
    {
#line 357
        return __ExitCode();
    };
    
#line 9
    inline Text::String GetHomeDir()
    {
#line 9
        return Native::GetHomeDir();
    };
    
#line 47
    inline bool IsDotString(Text::String s)
    {
#line 47
        return s == "." || s == "..";
    };
    
#line 451
    inline bool IsVerbose()
    {
#line 451
        return __Verbose();
    };
    
#line 344
    inline void ParseCommandLine(const char *cmdline)
    {
#line 345
        __CommandLine().Split((Text::String) cmdline, " ");
    };
    
#line 57
    template < class _1 >
    inline _1& PtrRef(_1 *o, Text::String throw_msg)
    {
#line 59
        if (!o)
#line 59
            throw throw_msg;
        return *o;
    };
    
#line 403
    inline void SetDataPath(Text::String path)
    {
#line 404
        __DataPath() = path;
    };
    
#line 7
    inline void SetExeFilePath(Text::String s)
    {
#line 7
        ExeFilePath() = s;
    };
    
#line 358
    inline void SetExitCode(int i)
    {
#line 358
        __ExitCode() = i;
    };
    
#line 46
    inline void SetVerbose(bool b)
    {
#line 452
        __Verbose() = b;
    };
    
#line 51
    template < class _1 >
    inline _1& Single()
    {
#line 53
        static _1 o;
        return o;
    };
    
#line 886
    inline void VectorAdd(const Container::Vector < double > & from, Container::Vector < double > & to)
    {
        {
#line 887
            if (!(from.GetCount() == to.GetCount()))
            {
#line 887
                Lang::SysBreak("Assertion failed: from.GetCount() == to.GetCount()");
            }
        }
#line 888
        ;
#line 888
        Lang::ConstFwdIterator < double > src = from.Begin();
        Lang::FwdIterator < double > dst = to.Begin();
        Lang::FwdIterator < double > end = to.End();
        while (dst != end)
            {
#line 892
                *dst = *src;
                ++ dst;
                ++ src;
            }
    };
    
#line 342
    inline Container::Vector < Text::String > & __CommandLine()
    {
#line 342
        static Container::Vector < Text::String > v;
#line 342
        return v;
    };
    
#line 361
    inline Text::String& __ConfigPath()
    {
#line 361
        static Text::String s;
#line 361
        return s;
    };
    
#line 360
    inline Text::String& __DataPath()
    {
#line 360
        static Text::String s;
#line 360
        return s;
    };
    
#line 356
    inline int& __ExitCode()
    {
#line 356
        static int i;
#line 356
        return i;
    };
    
#line 665
    template < class _1, class _2 >
    inline void __FinalSort(_1 begin, _1 end, const _2& less)
    {
#line 667
        if (begin == end)
            return;
        _1 last = end;
        -- last;
        while (!(begin == last))
            {
#line 672
                _1 best = last;
                _1 next = last;
                _1 ptr = last;
                for (;;)
                    {
#line 676
                        if (less(*best, *-- ptr))
                        {
                            do
#line 678
                                if (ptr == begin)
                                {
#line 679
                                    __IterSwap(begin, best);
                                    ++ begin;
                                    goto NEXT_ITEM;
                                }while (less(*best, *-- ptr));
#line 684
                            if (ptr == begin)
                            {
#line 685
                                __IterSwap(++ begin, best);
                                ++ begin;
                                break;
                            
                            }
#line 689
                            next = ptr;
                            ++ next;
                        }
                        else 
                        if (ptr == begin)
                        {
#line 694
                            begin = next;
                            break;
                        
                        }
#line 697
                        best = ptr;
                    }
                NEXT_ITEM:
                    ;
            }
    };
    
#line 653
    template < class _1 >
    inline void __IterSwap(_1 a, _1 b)
    {
#line 655
        if (a != b)
            Container::Swap(*a, *b);
    };
    
#line 430
    inline Container::Vector < Text::String > & __LocalFileDirs()
    {
#line 430
        static Container::Vector < Text::String > v;
#line 430
        return v;
    };
    
#line 659
    template < class _1, class _2 >
    inline void __OrderIter2(_1 a, _1 b, const _2& less)
    {
#line 661
        if (less(*b, *a))
            __IterSwap(a, b);
    };
    
#line 450
    inline bool& __Verbose()
    {
#line 450
        static bool b;
#line 450
        return b;
    };
    
#line 132
    inline CommandLineArguments::CommandLineArguments() {};
    
#line 136
    inline int CommandLineArguments::GetInputCount() const
    {
#line 136
        return inputs.GetCount();
    };
    
#line 137
    inline const Container::Array < CmdInput > & CommandLineArguments::GetInputs() const
    {
#line 137
        return inputs;
    };
    
#line 148
    template < class _1 >
    inline DtorValueSetter < _1 >::~DtorValueSetter()
    {
#line 148
        obj = value;
    };
    
#line 759
    template < class _1 >
    inline bool StdGreater < _1 >::operator()(const _1& a, const _1& b) const
    {
#line 759
        return a > b;
    };
    
#line 758
    template < class _1 >
    inline bool StdLess < _1 >::operator()(const _1& a, const _1& b) const
    {
#line 758
        return a < b;
    };
    
};

#endif
