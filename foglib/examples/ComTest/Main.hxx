#ifndef MAIN_HXX
#define MAIN_HXX

#include <new>

#ifndef UTIL_HXX
#include <Util.hxx>
#endif

struct NamespaceInterfaceLinker
{
};

#ifndef TEXTPROC_HXX
#include <TextProc.hxx>
#endif

namespace Main
{
    class App
    {
#line 22 "ComTest.mfog"
        Container::VectorMap < int, int > arr;
        
    public:
#line 46
        inline void Run();
        
#line 273
        void TestShared();
        
        struct Dumber
        {
#line 265
            inline Dumber();
            virtual ~Dumber();
        };
        
        struct Dumb : public Main::App::Dumber
        {
#line 269
            inline Dumb();
            inline ~Dumb();
        };
        
        struct SomeRefTuple2
        {
#line 73 "../../src/Com/Meta.fog"
            int& a;
            double& b;
            
            SomeRefTuple2(int& a, double& b);
            Text::String AsString() const;
        };
        
        struct SomeTuple2
        {
#line 54
            int a;
            double b;
            
            Text::String AsString() const;
        };
        
        struct TestCmp
        {
#line 26 "ComTest.mfog"
            inline bool operator()(const char& c);
        };
        
        struct VirtualBase
        {
#line 35
            int a;
            
#line 32
            inline VirtualBase();
            virtual ~VirtualBase();
        };
        
        struct DerivedBase : public Main::App::VirtualBase
        {
#line 40
            int a;
            
#line 38
            inline DerivedBase();
        };
    };
};

namespace Main
{
#line 46
    inline void App::Run()
    {
#line 47
        Lang::uint64 v = 4294967295U;
        {
#line 48
            if (!(sizeof (v) == 8))
            {
#line 48
                Lang::SysBreak("Assertion failed: sizeof(v) == 8");
            }
        }
#line 49
        ;
        Lang::VoidPtr p;
        {
#line 51
            if (!(p == 0))
            {
#line 51
                Lang::SysBreak("Assertion failed: p == NULL");
            }
        }
#line 52
        ;
        {
#line 53
            if (!(Native::SignificantBits(0x8000) == 16))
            {
#line 53
                Lang::SysBreak("Assertion failed: SignificantBits(0x8000) == 16");
            }
        }
#line 54
        ;
        {
#line 54
            if (!(Native::SignificantBits64(0x8000) == 16))
            {
#line 54
                Lang::SysBreak("Assertion failed: SignificantBits64(0x8000) == 16");
            }
        }
#line 55
        ;
        Hash::Combine ch;
        ch.Put(777999777).Put(123).Put64(0xF0F0F0F0F0F0F0F0);
        Lang::dword hash = ch;
        {
#line 59
            if (!(hash == 1894504625))
            {
#line 59
                Lang::SysBreak("Assertion failed: hash == 1894504625");
            }
        }
#line 60
        ;
#line 60
        int a = 0;
        int b = 1;
        {
#line 62
            if (!(Algorithm::Minimum(a, b) < Algorithm::Maximum(a, b)))
            {
#line 62
                Lang::SysBreak("Assertion failed: Min(a, b) < Max(a, b)");
            }
        }
#line 63
        ;
        int r = Random::Int();
        float f = Random::Float();
        float d = Random::Double();
        int j = d;
#line 70
        const char * test_str = "abcdef";
        int test_strlen = Lang::StringLength(test_str);
        {
#line 72
            if (!(Container::FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2))
            {
#line 72
                Lang::SysBreak("Assertion failed: FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2");
            }
        }
#line 73
        ;
        {
            if (!(Text::String("test") == "test"))
            {
#line 75
                Lang::SysBreak("Assertion failed: String(\"test\") == \"test\"");
            }
        }
#line 76
        ;
        {
#line 76
            if (!(Text::String::DblStr(1.2) == "1.2"))
            {
#line 76
                Lang::SysBreak("Assertion failed: DblStr(1.2) == \"1.2\"");
            }
        }
#line 77
        ;
        {
#line 77
            if (!((Text::String)"abc" + Text::String("def") == "abcdef"))
            {
#line 77
                Lang::SysBreak("Assertion failed: (String)\"abc\" + String(\"def\") == \"abcdef\"");
            }
        }
#line 78
        ;
        {
#line 78
            if (!(Text::String("abc") + "def" == "abcdef"))
            {
#line 78
                Lang::SysBreak("Assertion failed: String(\"abc\") + \"def\" == \"abcdef\"");
            }
        }
#line 79
        ;
        {
#line 79
            if (!(Text::ToString(Text::ToWString < Text::String > ("abc")) == "abc"))
            {
#line 79
                Lang::SysBreak("Assertion failed: ToString(ToWString<String>(\"abc\")) == \"abc\"");
            }
        }
#line 80
        ;
        {
#line 80
            if (!(Text::ToInt < Text::String > ("123") == 123))
            {
#line 80
                Lang::SysBreak("Assertion failed: ToInt<String>(\"123\") == 123");
            }
        }
#line 81
        ;
        {
#line 81
            if (!(Text::ToString(123) == "123"))
            {
#line 81
                Lang::SysBreak("Assertion failed: ToString(123) == \"123\"");
            }
        }
#line 82
        ;
        {
#line 82
            if (!(Text::HexStr((void * )0x123f) == "0x123F"))
            {
#line 82
                Lang::SysBreak("Assertion failed: HexStr((void*)0x123f) == \"0x123F\"");
            }
        }
#line 83
        ;
#line 85
        SomeTuple2 ttt = 
        {
            1,
            1.2
        };
        {
#line 86
            if (!(Text::ToString(ttt) == "1, 1.2"))
            {
#line 86
                Lang::SysBreak("Assertion failed: ToString(ttt) == \"1, 1.2\"");
            }
        }
#line 87
        ;
        SomeRefTuple2 tttref(ttt.a, ttt.b);
        {
#line 89
            if (!(Text::ToString(tttref) == "1, 1.2"))
            {
#line 89
                Lang::SysBreak("Assertion failed: ToString(tttref) == \"1, 1.2\"");
            }
        }
#line 90
        ;
        Container::One < Text::String > onestr;
        onestr.Create();
        *onestr = "hello";
        {
#line 94
            if (!(*onestr == "hello"))
            {
#line 94
                Lang::SysBreak("Assertion failed: *onestr == \"hello\"");
            }
        }
#line 95
        ;
        Container::One < VirtualBase > onebase;
        onebase.CreateDerived < DerivedBase > ();
        {
#line 98
            if (!(onebase.GetDerived < DerivedBase > ()-> a == 8))
            {
#line 98
                Lang::SysBreak("Assertion failed: onebase.GetDerived<DerivedBase>()->a == 8");
            }
        }
#line 99
        ;
        Container::FutureOne < Text::String > fone;
        fone = new Text::String;
        fone.Wait();
#line 104
        Container::Vector < Text::String > strvec;
        Container::Array < Text::String > strarr;
        for (int i = 0; i < 3; i ++ )
            {
#line 107
                strvec << Text::String::IntStr(i);
                strarr << Text::String::IntStr(i);
            }
        for (int i = 0; i < 3; i ++ )
            {
                {
#line 111
                    if (!(strvec[i] == strarr[i]))
                    {
#line 111
                        Lang::SysBreak("Assertion failed: strvec[i] == strarr[i]");
                    }
                }
#line 112
                ;
            }
        Container::Index < Text::String > stridx;
        stridx.Add("abc");
        {
#line 116
            if (!(stridx.GetCount() == 1))
            {
#line 116
                Lang::SysBreak("Assertion failed: stridx.GetCount() == 1");
            }
        }
#line 117
        ;
        {
#line 117
            if (!(stridx.Find("abc") == 0))
            {
#line 117
                Lang::SysBreak("Assertion failed: stridx.Find(\"abc\") == 0");
            }
        }
#line 118
        ;
#line 118
        stridx.Add("def");
        {
#line 119
            if (!(stridx.Find("abc") == 0))
            {
#line 119
                Lang::SysBreak("Assertion failed: stridx.Find(\"abc\") == 0");
            }
        }
#line 120
        ;
        {
#line 120
            if (!(stridx.Find("def") == 1))
            {
#line 120
                Lang::SysBreak("Assertion failed: stridx.Find(\"def\") == 1");
            }
        }
#line 121
        ;
#line 123
        Container::VectorMap < Text::String, int > vmap;
        Container::ArrayMap < Text::String, int > amap;
#line 126
        vmap.Add("abc", 123);
        vmap.Add("def", 456);
        {
#line 128
            if (!(vmap.GetKeys().Find("abc") == 0))
            {
#line 128
                Lang::SysBreak("Assertion failed: vmap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 129
        ;
        {
#line 129
            if (!(vmap.GetValues()[0] == 123))
            {
#line 129
                Lang::SysBreak("Assertion failed: vmap.GetValues()[0] == 123");
            }
        }
#line 130
        ;
        {
#line 130
            if (!(vmap.Find("abc") == 0))
            {
#line 130
                Lang::SysBreak("Assertion failed: vmap.Find(\"abc\") == 0");
            }
        }
#line 131
        ;
        {
#line 131
            if (!(vmap.Find("dfasgsg") == - 1))
            {
#line 131
                Lang::SysBreak("Assertion failed: vmap.Find(\"dfasgsg\") == -1");
            }
        }
#line 132
        ;
        {
#line 132
            if (!(vmap.GetValues().Join() == "123456"))
            {
#line 132
                Lang::SysBreak("Assertion failed: vmap.GetValues().Join() == \"123456\"");
            }
        }
#line 133
        ;
#line 133
        Container::Vector < int > vmap_keys;
        vmap_keys.Split(vmap.GetValues().Join(" "), " ");
        {
#line 135
            if (!(vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456))
            {
#line 135
                Lang::SysBreak("Assertion failed: vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456");
            }
        }
#line 136
        ;
#line 138
        amap.Add("abc", 123);
        amap.Add("def", 456);
        {
#line 140
            if (!(amap.GetKeys().Find("abc") == 0))
            {
#line 140
                Lang::SysBreak("Assertion failed: amap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 141
        ;
        {
#line 141
            if (!(amap.GetValues()[0] == 123))
            {
#line 141
                Lang::SysBreak("Assertion failed: amap.GetValues()[0] == 123");
            }
        }
#line 142
        ;
        {
#line 142
            if (!(amap.Find("abc") == 0))
            {
#line 142
                Lang::SysBreak("Assertion failed: amap.Find(\"abc\") == 0");
            }
        }
#line 143
        ;
        {
#line 143
            if (!(amap.Find("dfasgsg") == - 1))
            {
#line 143
                Lang::SysBreak("Assertion failed: amap.Find(\"dfasgsg\") == -1");
            }
        }
#line 144
        ;
#line 144
        Lang::FwdPairPtrIterator < Text::String, int > it = amap.Begin();
        for (int i = 0; i < 2; i ++ )
            {
#line 146
                if (i == 0)
                {
                    {
#line 147
                        if (!(it.GetKey() == "abc"))
                        {
#line 147
                            Lang::SysBreak("Assertion failed: it.GetKey() == \"abc\"");
                        }
                    }
#line 148
                    ;
                    {
#line 148
                        if (!(it.GetValue() == 123))
                        {
#line 148
                            Lang::SysBreak("Assertion failed: it.GetValue() == 123");
                        }
                    }
#line 149
                    ;
                }
                else 
#line 150
                if (i == 1)
                {
                    {
#line 151
                        if (!(it.GetKey() == "def"))
                        {
#line 151
                            Lang::SysBreak("Assertion failed: it.GetKey() == \"def\"");
                        }
                    }
#line 152
                    ;
                    {
#line 152
                        if (!(it.GetValue() == 456))
                        {
#line 152
                            Lang::SysBreak("Assertion failed: it.GetValue() == 456");
                        }
                    }
#line 153
                    ;
                }
#line 154
                ++ it;
            }
        {
#line 159
            Shared::Attachable a;
            Shared::Slot s;
            a.Attach(s);
            s.Clear();
        }
#line 166
        TestShared();
        {
#line 169
            Stream::StringStream ss;
            ss << "abc";
        }
#line 173
        Text::String s;
        {
            Stream::FileIn fin;
            {
#line 176
                if (!(fin.Open("/home/sblo/Fuck.cxx")))
                {
#line 176
                    Lang::SysBreak("Assertion failed: fin.Open(\"/home/sblo/Fuck.cxx\")");
                }
            }
#line 177
            ;
#line 177
            s = fin.Get(fin.GetSize());
            int sz = s.GetCount();
        }
#line 181
        Util::Log() << "Lol does this work\?\n";
#line 183
        Stream::FileOut fout;
        fout % r % f % d;
#line 186
        const Container::Vector < Text::String > & cmd = Util::Env::Local().CommandLine();
        for (int i = 0; i < cmd.GetCount(); i ++ )
            {
#line 188
                Text::String arg = cmd[i];
            }
#line 191
        Container::Index < Text::String > files;
        Util::GetDirectoryFiles("/", files);
        {
#line 193
            if (!(files.Find("home") >= 0))
            {
#line 193
                Lang::SysBreak("Assertion failed: files.Find(\"home\") >= 0");
            }
        }
#line 194
        ;
#line 194
        for (int i = 0; i < files.GetCount(); i ++ )
            {
#line 195
                Text::String s = files[i];
                const char * c = s.Begin();
                int len = Lang::StringLength(c);
            }
        {
#line 201
            double d = Math::FastSin(3.14159265358979323846);
            d = Math::FastCos(3.14159265358979323846);
        }
        {
#line 206
            Math::RandomGaussian & gaus = Math::GetRandomGaussian(13);
            double d = gaus;
            d = gaus;
            d = gaus;
            d = gaus;
        }
        {
#line 214
            Chrono::Time t1(2020, 10, 5, 3, 28, 0);
            Lang::int64 i64 = t1.Get();
            Chrono::Time t2;
            t2.Set(i64);
            {
#line 218
                if (!(t1 == t2))
                {
#line 218
                    Lang::SysBreak("Assertion failed: t1 == t2");
                }
            }
#line 219
            ;
        }
        {
#line 223
            Concurrency::Thread t;
            Concurrency::Mutex m;
        }
        {
#line 228
            Network::TcpSocket s;
            {
#line 229
                if (!(s.Listen(8005, 5)))
                {
#line 229
                    Lang::SysBreak("Assertion failed: s.Listen(8005, 5)");
                }
            }
#line 230
            ;
        }
        {
            TextProc::Tokenizer t;
        }
        {
#line 238
            TextProc::JSON j;
        }
    };
    
#line 38
    inline App::DerivedBase::DerivedBase()
    :
        a(8)
    {};
    
#line 269
    inline App::Dumb::Dumb()
    {
#line 269
        ;
    };
    
#line 270
    inline App::Dumb::~Dumb()
    {
#line 270
        ;
    };
    
#line 265
    inline App::Dumber::Dumber()
    {
#line 265
        ;
    };
    
#line 26
    inline bool App::TestCmp::operator()(const char& c)
    {
#line 27
        return c == 'c';
    };
    
#line 32
    inline App::VirtualBase::VirtualBase()
    :
        a(3)
    {};
    
};

#endif
