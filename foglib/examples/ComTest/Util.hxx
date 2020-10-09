#ifndef UTIL_HXX
#define UTIL_HXX

#include <new>

#ifndef CONTAINER_HXX
#include <Container.hxx>
#endif

#ifndef CHRONO_HXX
#include <Chrono.hxx>
#endif

#ifndef ABSTRACT_HXX
#include <Abstract.hxx>
#endif

namespace Util
{
#line 458 "../../src/Com/Util.fog"
    inline void AddLocalFileDirectory(Text::String dir);
#line 228
    Text::String AppendFileName(Text::String a, Text::String b);
#line 393
    Stream::CharStream& Cerr();
#line 388
    Stream::CharStream& Cin();
#line 247
    Text::String ConfigFile(Text::String file_name);
#line 79
    inline Text::String& ConfigPath();
#line 873
    template < class _1, class _2 >
    inline void CopyHeapless(const _1& from, _1& to);
#line 886
    template < class _1, class _2 >
    inline void CopyHeaplessMat(const _1& from, _1& to);
#line 378
    Stream::CharStream& Cout();
#line 337
    inline void DeleteFile(Text::String path);
#line 440
    inline bool DirectoryExists(Text::String path);
#line 383
    Stream::CharStream& Errout();
#line 439
    inline bool FileExists(Text::String path);
#line 1042
    int FindArg(const char *value, const char *a0);
#line 1042
    int FindArg(const char *value, const char *a0, const char *a1);
#line 1042
    int FindArg(const char *value, const char *a0, const char *a1, const char *a2);
#line 1042
    int FindArg(const char *value, const char *a0, const char *a1, const char *a2, const char *a3);
#line 1042
    int FindArg(const char *value, const char *a0, const char *a1, const char *a2, const char *a3, const char *a4);
#line 1042
    int FindArg(const char *value, const char *a0, const char *a1, const char *a2, const char *a3, const char *a4, const char *a5);
#line 1042
    int FindArg(const char *value, const char *a0, const char *a1, const char *a2, const char *a3, const char *a4, const char *a5, const char *a6);
#line 1042
    int FindArg(const char *value, const char *a0, const char *a1, const char *a2, const char *a3, const char *a4, const char *a5, const char *a6, const char *a7);
#line 1041
    int FindArg(int value, int a0);
#line 1041
    int FindArg(int value, int a0, int a1);
#line 1041
    int FindArg(int value, int a0, int a1, int a2);
#line 1041
    int FindArg(int value, int a0, int a1, int a2, int a3);
#line 1041
    int FindArg(int value, int a0, int a1, int a2, int a3, int a4);
#line 1041
    int FindArg(int value, int a0, int a1, int a2, int a3, int a4, int a5);
#line 1041
    int FindArg(int value, int a0, int a1, int a2, int a3, int a4, int a5, int a6);
#line 1041
    int FindArg(int value, int a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7);
#line 444
    Text::String FindLocalFile(Text::String filename);
#line 419
    Text::String GetDataDirectory();
#line 435
    inline Text::String GetDataDirectoryFile(Text::String file);
#line 425
    Text::String GetDataFile(Text::String filename);
#line 472
    void GetDirectoryFiles(Text::String dir, Container::Index < Text::String > & files);
#line 409
    Text::String GetEnv(Text::String id);
#line 405
    Text::String GetExeDirFile(Text::String filename);
#line 278
    Text::String GetFileDirectory(Text::String path);
#line 314
    Text::String GetFileExt(Text::String path);
#line 263
    Text::String GetFileName(Text::String path);
#line 270
    Text::String GetFileTitle(Text::String path);
#line 78
    inline Text::String GetHomeDir();
#line 290
    Text::String GetParentDirectory(Text::String path, int steps);
#line 477
    bool IsClose(double a, double b);
#line 109
    inline bool IsDotString(Text::String s);
#line 463
    bool IsVerbose();
#line 350
    Stream::CharStream& Log();
#line 345
    void Panic(Text::String s);
#line 119
    template < class _1 >
    inline _1& PtrRef(_1 *o, Text::String throw_msg);
#line 98
    void ReadCoreCmdlineArgs();
#line 398
    Text::String ReadStdIn();
#line 326
    void RealizeDirectory(Text::String dir);
#line 341
    void RenameFile(Text::String oldpath, Text::String newpath);
#line 415
    inline void SetDataPath(Text::String path);
#line 108
    void SetVerbose(bool b = true);
#line 113
    template < class _1 >
    inline _1& Single();
#line 762
    template < class _1, class _2 >
    void Sort(_1& vector, const _2& sorter);
#line 912
    bool StreamCopy(Abstract::StreamBase& dest, Abstract::StreamBase& src);
#line 85
    Text::String TrimFileDirectory(Text::String path);
#line 87
    Text::String TrimFileExt(Text::String path);
#line 83
    Text::String TrimFileName(Text::String path);
    Text::String TrimFileTitle(Text::String path);
#line 86
    Text::String TrimParentDirectory(Text::String path, int steps = 1);
#line 898
    inline void VectorAdd(const Container::Vector < double > & from, Container::Vector < double > & to);
#line 403
    inline Text::String& __ConfigPath();
#line 402
    inline Text::String& __DataPath();
#line 466
    void __FileAdder(const char *str, void *files_idx);
#line 677
    template < class _1, class _2 >
    inline void __FinalSort(_1 begin, _1 end, const _2& less);
#line 665
    template < class _1 >
    inline void __IterSwap(_1 a, _1 b);
#line 442
    inline Container::Vector < Text::String > & __LocalFileDirs();
#line 671
    template < class _1, class _2 >
    inline void __OrderIter2(_1 a, _1 b, const _2& less);
#line 717
    template < class _1, class _2 >
    void __Sort(_1 l, _1 h, const _2& less);
#line 462
    bool& __Verbose();
    
    struct CmdArg
    {
#line 175
        char key;
        Text::String desc;
        bool has_value;
    };
    
    struct CmdInput
    {
#line 181
        char key;
        Text::String value;
    };
    
    class CommandLineArguments
    {
#line 189
        Container::Array < CmdArg > args;
        Container::Array < CmdInput > inputs;
        
    public:
#line 194
        inline CommandLineArguments();
#line 790
        void AddArg(char key, const char *desc, bool has_value);
#line 198
        inline int GetInputCount() const;
        inline const Container::Array < CmdInput > & GetInputs() const;
#line 797
        bool Parse();
#line 836
        void PrintHelp();
        
#line 187
        static const int max_args;
#line 186
        static const int max_inputs;
    };
    
    template < class _1 >
    struct DtorValueSetter
    {
#line 207
        _1& obj;
        int value;
        
#line 209
        DtorValueSetter(_1& obj);
        inline ~DtorValueSetter();
    };
    
    class Env
    {
#line 8
        Container::Vector < Text::String > cmd;
        Text::String exe_path;
        int exit_code;
        
    public:
#line 36
        inline const Container::Vector < Text::String > & CommandLine() const;
#line 21
        int Deinit();
#line 35
        inline Text::String GetExeFilePath() const;
#line 34
        inline int GetExitCode() const;
#line 14
        void Init(int argc, const char **argv);
#line 32
        inline void SetExitCode(int i);
#line 27
        inline void ShutdownThreads();
        
    protected:
#line 41
        void ParseCommandLine(int argc, const char **argv);
#line 45
        void ReadComCmdlineArgs();
#line 60
        inline void RunExitBlocks();
#line 59
        inline void RunInitBlocks();
#line 40
        inline void SeedRandom();
#line 62
        void SetCoreArg(Text::String key, Text::String value);
#line 39
        inline void SetExeFilePath(const char *path);
        
    public:
#line 29
        inline static Env& Local();
    };
    
    struct FindFile
    {
#line 160
        typedef FindFile CLASSNAME;
        
#line 629
        FindFile();
#line 649
        Text::String GetName() const;
#line 645
        Text::String GetPath() const;
#line 641
        bool IsDirectory() const;
#line 637
        bool Next();
#line 633
        bool Search(Text::String path);
    };
    
    struct FloatTrans
    {
#line 942
        double value;
        
        inline FloatTrans();
        inline FloatTrans(double d);
#line 963
        inline bool operator!= (double d);
#line 960
        inline double operator*= (double d);
#line 958
        inline double operator+= (double d);
        inline double operator-= (double d);
#line 961
        inline double operator/= (double d);
#line 957
        inline double operator= (double d);
#line 962
        inline bool operator== (double d);
#line 964
        inline operator double() const;
        inline Text::String AsString() const;
#line 946
        void Serialize(Abstract::StreamBase& s);
    };
    
    template < class _1 >
    struct StdGreater
    {
#line 771
        inline bool operator()(const _1& a, const _1& b) const;
    };
    
    template < class _1 >
    struct StdLess
    {
#line 770
        inline bool operator()(const _1& a, const _1& b) const;
    };
    
    class StringCache
    {
#line 144
        Container::Vector < unsigned int > hashes;
        Container::Vector < Text::String > strings;
        Container::Vector < int > free_slots;
        int str_counter;
        Lang::AtomicFlag lock;
        
    public:
#line 573
        StringCache();
#line 610
        Text::String Get(int i) const;
#line 575
        int GetAdd(const Text::String& s);
#line 614
        int GetCount() const;
#line 601
        void Remove(int i);
    };
    
    struct StringParser
    {
#line 126
        Text::String s;
        int cursor;
        
        StringParser(Text::String s);
#line 499
        bool Char(int chr);
#line 540
        int GetChar();
#line 548
        bool IsChar(int chr);
#line 131
        void PassChar(int chr, bool do_pass_white = true);
#line 552
        void PassWhite();
#line 544
        int PeekChar();
#line 518
        Text::String ReadId();
#line 509
        int ReadInt();
    };
    
    struct Version
    {
#line 976
        Lang::byte write_v;
#line 976
        Lang::byte read_v;
        Abstract::StreamBase& s;
        
        Version(Lang::byte write_v, Abstract::StreamBase& s);
#line 986
        bool Is(Lang::byte cmp_v);
    };
};

namespace Util
{
#line 458
    inline void AddLocalFileDirectory(Text::String dir)
    {
#line 459
        __LocalFileDirs().Add(dir);
    };
    
#line 79
    inline Text::String& ConfigPath()
    {
#line 79
        static Text::String s;
#line 79
        return s;
    };
    
#line 873
    template < class _1, class _2 >
    inline void CopyHeapless(const _1& from, _1& to)
    {
#line 875
        Lang::FwdIterator < _2 > src = from.Begin();
        Lang::FwdIterator < _2 > end = from.End();
        Lang::FwdIterator < _2 > dst = to.Begin();
        to.SetCount(from.GetCount());
        while (src != end)
            {
#line 880
                *dst = *src;
                src ++ ;
                dst ++ ;
            }
    };
    
    template < class _1, class _2 >
    inline void CopyHeaplessMat(const _1& from, _1& to)
    {
#line 888
        to.SetCount(from.GetCount());
        for (int i = 0; i < to.GetCount(); i ++ )
            {
#line 890
                const _2 & from0 = from[i];
                _2 & to0 = to[i];
                to0.SetCount(from0.GetCount());
                for (int i = 0; i < to0.GetCount(); i ++ )
                    to0[i] = from0[i];
            }
    };
    
#line 337
    inline void DeleteFile(Text::String path)
    {
#line 338
        Native::DeleteFile(path.Begin());
    };
    
#line 440
    inline bool DirectoryExists(Text::String path)
    {
#line 440
        return Native::DirExists(path.Begin());
    };
    
#line 439
    inline bool FileExists(Text::String path)
    {
#line 439
        return Native::PathExists(path.Begin());
    };
    
#line 435
    inline Text::String GetDataDirectoryFile(Text::String file)
    {
#line 436
        return AppendFileName(GetDataDirectory(), file);
    };
    
#line 78
    inline Text::String GetHomeDir()
    {
#line 78
        return Native::GetHomeDir();
    };
    
#line 109
    inline bool IsDotString(Text::String s)
    {
#line 109
        return s == "." || s == "..";
    };
    
#line 119
    template < class _1 >
    inline _1& PtrRef(_1 *o, Text::String throw_msg)
    {
#line 121
        if (!o)
#line 121
            throw throw_msg;
        return *o;
    };
    
#line 415
    inline void SetDataPath(Text::String path)
    {
#line 416
        __DataPath() = path;
    };
    
#line 113
    template < class _1 >
    inline _1& Single()
    {
#line 115
        static _1 o;
        return o;
    };
    
#line 898
    inline void VectorAdd(const Container::Vector < double > & from, Container::Vector < double > & to)
    {
        {
#line 899
            if (!(from.GetCount() == to.GetCount()))
            {
#line 899
                Lang::SysBreak("Assertion failed: from.GetCount() == to.GetCount()");
            }
        }
#line 900
        ;
#line 900
        Lang::ConstFwdIterator < double > src = from.Begin();
        Lang::FwdIterator < double > dst = to.Begin();
        Lang::FwdIterator < double > end = to.End();
        while (dst != end)
            {
#line 904
                *dst = *src;
                ++ dst;
                ++ src;
            }
    };
    
#line 403
    inline Text::String& __ConfigPath()
    {
#line 403
        static Text::String s;
#line 403
        return s;
    };
    
#line 402
    inline Text::String& __DataPath()
    {
#line 402
        static Text::String s;
#line 402
        return s;
    };
    
#line 677
    template < class _1, class _2 >
    inline void __FinalSort(_1 begin, _1 end, const _2& less)
    {
#line 679
        if (begin == end)
            return;
        _1 last = end;
        -- last;
        while (!(begin == last))
            {
#line 684
                _1 best = last;
                _1 next = last;
                _1 ptr = last;
                for (;;)
                    {
#line 688
                        if (less(*best, *-- ptr))
                        {
                            do
#line 690
                                if (ptr == begin)
                                {
#line 691
                                    __IterSwap(begin, best);
                                    ++ begin;
                                    goto NEXT_ITEM;
                                }while (less(*best, *-- ptr));
#line 696
                            if (ptr == begin)
                            {
#line 697
                                __IterSwap(++ begin, best);
                                ++ begin;
                                break;
                            
                            }
#line 701
                            next = ptr;
                            ++ next;
                        }
                        else 
                        if (ptr == begin)
                        {
#line 706
                            begin = next;
                            break;
                        
                        }
#line 709
                        best = ptr;
                    }
                NEXT_ITEM:
                    ;
            }
    };
    
#line 665
    template < class _1 >
    inline void __IterSwap(_1 a, _1 b)
    {
#line 667
        if (a != b)
            Container::Swap(*a, *b);
    };
    
#line 442
    inline Container::Vector < Text::String > & __LocalFileDirs()
    {
#line 442
        static Container::Vector < Text::String > v;
#line 442
        return v;
    };
    
#line 671
    template < class _1, class _2 >
    inline void __OrderIter2(_1 a, _1 b, const _2& less)
    {
#line 673
        if (less(*b, *a))
            __IterSwap(a, b);
    };
    
#line 194
    inline CommandLineArguments::CommandLineArguments() {};
    
#line 198
    inline int CommandLineArguments::GetInputCount() const
    {
#line 198
        return inputs.GetCount();
    };
    
#line 199
    inline const Container::Array < CmdInput > & CommandLineArguments::GetInputs() const
    {
#line 199
        return inputs;
    };
    
#line 210
    template < class _1 >
    inline DtorValueSetter < _1 >::~DtorValueSetter()
    {
#line 210
        obj = value;
    };
    
#line 36
    inline const Container::Vector < Text::String > & Env::CommandLine() const
    {
#line 36
        return cmd;
    };
    
#line 35
    inline Text::String Env::GetExeFilePath() const
    {
#line 35
        return exe_path;
    };
    
#line 34
    inline int Env::GetExitCode() const
    {
#line 34
        return 0;
    };
    
#line 29
    inline Env& Env::Local()
    {
#line 29
        static Env e;
#line 29
        return e;
    };
    
#line 60
    inline void Env::RunExitBlocks() {};
    
#line 59
    inline void Env::RunInitBlocks() {};
    
#line 40
    inline void Env::SeedRandom()
    {
#line 40
        Random::Generator::Local().Seed();
    };
    
#line 39
    inline void Env::SetExeFilePath(const char *path)
    {
#line 39
        exe_path = path;
    };
    
#line 32
    inline void Env::SetExitCode(int i)
    {
#line 32
        exit_code = i;
    };
    
#line 27
    inline void Env::ShutdownThreads() {};
    
#line 944
    inline FloatTrans::FloatTrans()
    {
#line 944
        value = 0;
    };
    
#line 945
    inline FloatTrans::FloatTrans(double d)
    {
#line 945
        value = d;
    };
    
#line 963
    inline bool FloatTrans::operator!= (double d)
    {
#line 963
        return value != d;
    };
    
#line 960
    inline double FloatTrans::operator*= (double d)
    {
#line 960
        value *= d;
#line 960
        return d;
    };
    
#line 958
    inline double FloatTrans::operator+= (double d)
    {
#line 958
        value += d;
#line 958
        return d;
    };
    
#line 959
    inline double FloatTrans::operator-= (double d)
    {
#line 959
        value -= d;
#line 959
        return d;
    };
    
#line 961
    inline double FloatTrans::operator/= (double d)
    {
#line 961
        value /= d;
#line 961
        return d;
    };
    
#line 957
    inline double FloatTrans::operator= (double d)
    {
#line 957
        value = d;
#line 957
        return d;
    };
    
#line 962
    inline bool FloatTrans::operator== (double d)
    {
#line 962
        return value == d;
    };
    
#line 964
    inline FloatTrans::operator double() const
    {
#line 964
        return value;
    };
    
#line 965
    inline Text::String FloatTrans::AsString() const
    {
#line 965
        return Text::String::DblStr(value);
    };
    
#line 771
    template < class _1 >
    inline bool StdGreater < _1 >::operator()(const _1& a, const _1& b) const
    {
#line 771
        return a > b;
    };
    
#line 770
    template < class _1 >
    inline bool StdLess < _1 >::operator()(const _1& a, const _1& b) const
    {
#line 770
        return a < b;
    };
    
};

#endif
