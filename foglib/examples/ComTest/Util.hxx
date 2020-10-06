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
#line 459 "../../src/Com/Util.fog"
    inline void AddLocalFileDirectory(Text::String dir);
#line 228
    Text::String AppendFileName(Text::String a, Text::String b);
#line 394
    Stream::CharStream& Cerr();
#line 389
    Stream::CharStream& Cin();
#line 247
    Text::String ConfigFile(Text::String file_name);
#line 79
    inline Text::String& ConfigPath();
#line 874
    template < class _1, class _2 >
    inline void CopyHeapless(const _1& from, _1& to);
#line 887
    template < class _1, class _2 >
    inline void CopyHeaplessMat(const _1& from, _1& to);
#line 379
    Stream::CharStream& Cout();
#line 337
    inline void DeleteFile(Text::String path);
#line 441
    inline bool DirectoryExists(Text::String path);
#line 384
    Stream::CharStream& Errout();
#line 440
    inline bool FileExists(Text::String path);
#line 445
    Text::String FindLocalFile(Text::String filename);
#line 420
    Text::String GetDataDirectory();
#line 436
    inline Text::String GetDataDirectoryFile(Text::String file);
#line 426
    Text::String GetDataFile(Text::String filename);
#line 473
    void GetDirectoryFiles(Text::String dir, Container::Index < Text::String > & files);
#line 410
    Text::String GetEnv(Text::String id);
#line 406
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
#line 86
    Text::String GetParentDirectory(Text::String path, int steps = 1);
#line 478
    bool IsClose(double a, double b);
#line 109
    inline bool IsDotString(Text::String s);
#line 464
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
#line 399
    Text::String ReadStdIn();
#line 326
    void RealizeDirectory(Text::String dir);
#line 341
    void RenameFile(Text::String oldpath, Text::String newpath);
#line 416
    inline void SetDataPath(Text::String path);
#line 108
    void SetVerbose(bool b = true);
#line 113
    template < class _1 >
    inline _1& Single();
#line 763
    template < class _1, class _2 >
    void Sort(_1& vector, const _2& sorter);
#line 913
    bool StreamCopy(Abstract::StreamBase& dest, Abstract::StreamBase& src);
#line 899
    inline void VectorAdd(const Container::Vector < double > & from, Container::Vector < double > & to);
#line 404
    inline Text::String& __ConfigPath();
#line 403
    inline Text::String& __DataPath();
#line 467
    void __FileAdder(const char *str, void *files_idx);
#line 678
    template < class _1, class _2 >
    inline void __FinalSort(_1 begin, _1 end, const _2& less);
#line 666
    template < class _1 >
    inline void __IterSwap(_1 a, _1 b);
#line 443
    inline Container::Vector < Text::String > & __LocalFileDirs();
#line 672
    template < class _1, class _2 >
    inline void __OrderIter2(_1 a, _1 b, const _2& less);
#line 718
    template < class _1, class _2 >
    void __Sort(_1 l, _1 h, const _2& less);
#line 463
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
#line 791
        void AddArg(char key, const char *desc, bool has_value);
#line 198
        inline int GetInputCount() const;
        inline const Container::Array < CmdInput > & GetInputs() const;
#line 798
        bool Parse();
#line 837
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
        
#line 630
        FindFile();
#line 650
        Text::String GetName() const;
#line 646
        Text::String GetPath() const;
#line 642
        bool IsDirectory() const;
#line 638
        bool Next();
#line 634
        bool Search(Text::String path);
    };
    
    struct FloatTrans
    {
#line 943
        double value;
        
        inline FloatTrans();
        inline FloatTrans(double d);
#line 964
        inline bool operator!= (double d);
#line 961
        inline double operator*= (double d);
#line 959
        inline double operator+= (double d);
        inline double operator-= (double d);
#line 962
        inline double operator/= (double d);
#line 958
        inline double operator= (double d);
#line 963
        inline bool operator== (double d);
#line 965
        inline operator double() const;
        inline Text::String AsString() const;
#line 947
        void Serialize(Abstract::StreamBase& s);
    };
    
    template < class _1 >
    struct StdGreater
    {
#line 772
        inline bool operator()(const _1& a, const _1& b) const;
    };
    
    template < class _1 >
    struct StdLess
    {
#line 771
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
#line 574
        StringCache();
#line 611
        Text::String Get(int i) const;
#line 576
        int GetAdd(const Text::String& s);
#line 615
        int GetCount() const;
#line 602
        void Remove(int i);
    };
    
    struct StringParser
    {
#line 126
        Text::String s;
        int cursor;
        
        StringParser(Text::String s);
#line 500
        bool Char(int chr);
#line 541
        int GetChar();
#line 549
        bool IsChar(int chr);
#line 131
        void PassChar(int chr, bool do_pass_white = true);
#line 553
        void PassWhite();
#line 545
        int PeekChar();
#line 519
        Text::String ReadId();
#line 510
        int ReadInt();
    };
    
    struct Version
    {
#line 977
        Lang::byte write_v;
#line 977
        Lang::byte read_v;
        Abstract::StreamBase& s;
        
        Version(Lang::byte write_v, Abstract::StreamBase& s);
#line 987
        bool Is(Lang::byte cmp_v);
    };
};

namespace Util
{
#line 459
    inline void AddLocalFileDirectory(Text::String dir)
    {
#line 460
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
    
#line 874
    template < class _1, class _2 >
    inline void CopyHeapless(const _1& from, _1& to)
    {
#line 876
        Lang::FwdIterator < _2 > src = from.Begin();
        Lang::FwdIterator < _2 > end = from.End();
        Lang::FwdIterator < _2 > dst = to.Begin();
        to.SetCount(from.GetCount());
        while (src != end)
            {
#line 881
                *dst = *src;
                src ++ ;
                dst ++ ;
            }
    };
    
    template < class _1, class _2 >
    inline void CopyHeaplessMat(const _1& from, _1& to)
    {
#line 889
        to.SetCount(from.GetCount());
        for (int i = 0; i < to.GetCount(); i ++ )
            {
#line 891
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
    
#line 441
    inline bool DirectoryExists(Text::String path)
    {
#line 441
        return Native::DirExists(path.Begin());
    };
    
#line 440
    inline bool FileExists(Text::String path)
    {
#line 440
        return Native::PathExists(path.Begin());
    };
    
#line 436
    inline Text::String GetDataDirectoryFile(Text::String file)
    {
#line 437
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
    
#line 416
    inline void SetDataPath(Text::String path)
    {
#line 417
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
    
#line 899
    inline void VectorAdd(const Container::Vector < double > & from, Container::Vector < double > & to)
    {
        {
#line 900
            if (!(from.GetCount() == to.GetCount()))
            {
#line 900
                Lang::SysBreak("Assertion failed: from.GetCount() == to.GetCount()");
            }
        }
#line 901
        ;
#line 901
        Lang::ConstFwdIterator < double > src = from.Begin();
        Lang::FwdIterator < double > dst = to.Begin();
        Lang::FwdIterator < double > end = to.End();
        while (dst != end)
            {
#line 905
                *dst = *src;
                ++ dst;
                ++ src;
            }
    };
    
#line 404
    inline Text::String& __ConfigPath()
    {
#line 404
        static Text::String s;
#line 404
        return s;
    };
    
#line 403
    inline Text::String& __DataPath()
    {
#line 403
        static Text::String s;
#line 403
        return s;
    };
    
#line 678
    template < class _1, class _2 >
    inline void __FinalSort(_1 begin, _1 end, const _2& less)
    {
#line 680
        if (begin == end)
            return;
        _1 last = end;
        -- last;
        while (!(begin == last))
            {
#line 685
                _1 best = last;
                _1 next = last;
                _1 ptr = last;
                for (;;)
                    {
#line 689
                        if (less(*best, *-- ptr))
                        {
                            do
#line 691
                                if (ptr == begin)
                                {
#line 692
                                    __IterSwap(begin, best);
                                    ++ begin;
                                    goto NEXT_ITEM;
                                }while (less(*best, *-- ptr));
#line 697
                            if (ptr == begin)
                            {
#line 698
                                __IterSwap(++ begin, best);
                                ++ begin;
                                break;
                            
                            }
#line 702
                            next = ptr;
                            ++ next;
                        }
                        else 
                        if (ptr == begin)
                        {
#line 707
                            begin = next;
                            break;
                        
                        }
#line 710
                        best = ptr;
                    }
                NEXT_ITEM:
                    ;
            }
    };
    
#line 666
    template < class _1 >
    inline void __IterSwap(_1 a, _1 b)
    {
#line 668
        if (a != b)
            Container::Swap(*a, *b);
    };
    
#line 443
    inline Container::Vector < Text::String > & __LocalFileDirs()
    {
#line 443
        static Container::Vector < Text::String > v;
#line 443
        return v;
    };
    
#line 672
    template < class _1, class _2 >
    inline void __OrderIter2(_1 a, _1 b, const _2& less)
    {
#line 674
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
    
#line 945
    inline FloatTrans::FloatTrans()
    {
#line 945
        value = 0;
    };
    
#line 946
    inline FloatTrans::FloatTrans(double d)
    {
#line 946
        value = d;
    };
    
#line 964
    inline bool FloatTrans::operator!= (double d)
    {
#line 964
        return value != d;
    };
    
#line 961
    inline double FloatTrans::operator*= (double d)
    {
#line 961
        value *= d;
#line 961
        return d;
    };
    
#line 959
    inline double FloatTrans::operator+= (double d)
    {
#line 959
        value += d;
#line 959
        return d;
    };
    
#line 960
    inline double FloatTrans::operator-= (double d)
    {
#line 960
        value -= d;
#line 960
        return d;
    };
    
#line 962
    inline double FloatTrans::operator/= (double d)
    {
#line 962
        value /= d;
#line 962
        return d;
    };
    
#line 958
    inline double FloatTrans::operator= (double d)
    {
#line 958
        value = d;
#line 958
        return d;
    };
    
#line 963
    inline bool FloatTrans::operator== (double d)
    {
#line 963
        return value == d;
    };
    
#line 965
    inline FloatTrans::operator double() const
    {
#line 965
        return value;
    };
    
#line 966
    inline Text::String FloatTrans::AsString() const
    {
#line 966
        return Text::String::DblStr(value);
    };
    
#line 772
    template < class _1 >
    inline bool StdGreater < _1 >::operator()(const _1& a, const _1& b) const
    {
#line 772
        return a > b;
    };
    
#line 771
    template < class _1 >
    inline bool StdLess < _1 >::operator()(const _1& a, const _1& b) const
    {
#line 771
        return a < b;
    };
    
};

#endif
