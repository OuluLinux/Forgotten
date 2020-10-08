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
#line 29 "ComTest.mfog"
        Container::VectorMap < int, int > arr;
        
    public:
#line 53
        inline void Run();
        
#line 290
        void TestShared();
        
        struct Dumber
        {
#line 282
            inline Dumber();
            virtual ~Dumber();
        };
        
        struct Dumb : public Main::App::Dumber
        {
#line 286
            inline Dumb();
            inline ~Dumb();
        };
        
        struct SomeRefTuple2
        {
#line 101 "../../src/Com/Meta.fog"
            int& a;
            double& b;
            
            SomeRefTuple2(int& a, double& b);
            Text::String AsString() const;
        };
        
        struct SomeTuple2
        {
#line 82
            int a;
            double b;
            
            Text::String AsString() const;
        };
        
        struct TestCmp
        {
#line 33 "ComTest.mfog"
            inline bool operator()(const char& c);
        };
        
        struct VirtualBase
        {
#line 42
            int a;
            
#line 39
            inline VirtualBase();
            virtual ~VirtualBase();
        };
        
        struct DerivedBase : public Main::App::VirtualBase
        {
#line 47
            int a;
            
#line 45
            inline DerivedBase();
        };
    };
};

namespace Main
{
#line 53
    inline void App::Run()
    {
#line 54
        Lang::uint64 v = 4294967295U;
        {
#line 55
            if (!(sizeof (v) == 8))
            {
#line 55
                Lang::SysBreak("Assertion failed: sizeof(v) == 8");
            }
        }
#line 56
        ;
        Lang::VoidPtr p;
        {
#line 58
            if (!(p == 0))
            {
#line 58
                Lang::SysBreak("Assertion failed: p == NULL");
            }
        }
#line 59
        ;
        {
#line 60
            if (!(Native::SignificantBits(0x8000) == 16))
            {
#line 60
                Lang::SysBreak("Assertion failed: SignificantBits(0x8000) == 16");
            }
        }
#line 61
        ;
        {
#line 61
            if (!(Native::SignificantBits64(0x8000) == 16))
            {
#line 61
                Lang::SysBreak("Assertion failed: SignificantBits64(0x8000) == 16");
            }
        }
#line 62
        ;
        Hash::Combine ch;
        ch.Put(777999777).Put(123).Put64(0xF0F0F0F0F0F0F0F0);
        Lang::dword hash = ch;
        {
#line 66
            if (!(hash == 1894504625))
            {
#line 66
                Lang::SysBreak("Assertion failed: hash == 1894504625");
            }
        }
#line 67
        ;
#line 67
        int a = 0;
        int b = 1;
        {
#line 69
            if (!(Algorithm::Minimum(a, b) < Algorithm::Maximum(a, b)))
            {
#line 69
                Lang::SysBreak("Assertion failed: Min(a, b) < Max(a, b)");
            }
        }
#line 70
        ;
        int r = Random::Int();
        float f = Random::Float();
        float d = Random::Double();
        int j = d;
#line 77
        const char * test_str = "abcdef";
        int test_strlen = Lang::StringLength(test_str);
        {
#line 79
            if (!(Container::FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2))
            {
#line 79
                Lang::SysBreak("Assertion failed: FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2");
            }
        }
#line 80
        ;
        {
            if (!(Text::String("test") == "test"))
            {
#line 82
                Lang::SysBreak("Assertion failed: String(\"test\") == \"test\"");
            }
        }
#line 83
        ;
        {
#line 83
            if (!(Text::String::DblStr(1.2) == "1.2"))
            {
#line 83
                Lang::SysBreak("Assertion failed: DblStr(1.2) == \"1.2\"");
            }
        }
#line 84
        ;
        {
#line 84
            if (!((Text::String)"abc" + Text::String("def") == "abcdef"))
            {
#line 84
                Lang::SysBreak("Assertion failed: (String)\"abc\" + String(\"def\") == \"abcdef\"");
            }
        }
#line 85
        ;
        {
#line 85
            if (!(Text::String("abc") + "def" == "abcdef"))
            {
#line 85
                Lang::SysBreak("Assertion failed: String(\"abc\") + \"def\" == \"abcdef\"");
            }
        }
#line 86
        ;
        {
#line 86
            if (!(Text::ToString(Text::ToWString < Text::String > ("abc")) == "abc"))
            {
#line 86
                Lang::SysBreak("Assertion failed: ToString(ToWString<String>(\"abc\")) == \"abc\"");
            }
        }
#line 87
        ;
        {
#line 87
            if (!(Text::ToInt < Text::String > ("123") == 123))
            {
#line 87
                Lang::SysBreak("Assertion failed: ToInt<String>(\"123\") == 123");
            }
        }
#line 88
        ;
        {
#line 88
            if (!(Text::ToString(123) == "123"))
            {
#line 88
                Lang::SysBreak("Assertion failed: ToString(123) == \"123\"");
            }
        }
#line 89
        ;
        {
#line 89
            if (!(Text::HexStr((void * )0x123f) == "0x123F"))
            {
#line 89
                Lang::SysBreak("Assertion failed: HexStr((void*)0x123f) == \"0x123F\"");
            }
        }
#line 90
        ;
#line 92
        SomeTuple2 ttt = 
        {
            1,
            1.2
        };
        {
#line 93
            if (!(Text::ToString(ttt) == "1, 1.2"))
            {
#line 93
                Lang::SysBreak("Assertion failed: ToString(ttt) == \"1, 1.2\"");
            }
        }
#line 94
        ;
        SomeRefTuple2 tttref(ttt.a, ttt.b);
        {
#line 96
            if (!(Text::ToString(tttref) == "1, 1.2"))
            {
#line 96
                Lang::SysBreak("Assertion failed: ToString(tttref) == \"1, 1.2\"");
            }
        }
#line 97
        ;
        Container::One < Text::String > onestr;
        onestr.Create();
        *onestr = "hello";
        {
#line 101
            if (!(*onestr == "hello"))
            {
#line 101
                Lang::SysBreak("Assertion failed: *onestr == \"hello\"");
            }
        }
#line 102
        ;
        Container::One < VirtualBase > onebase;
        onebase.CreateDerived < DerivedBase > ();
        {
#line 105
            if (!(onebase.GetDerived < DerivedBase > ()-> a == 8))
            {
#line 105
                Lang::SysBreak("Assertion failed: onebase.GetDerived<DerivedBase>()->a == 8");
            }
        }
#line 106
        ;
        Container::FutureOne < Text::String > fone;
        fone = new Text::String;
        fone.Wait();
#line 111
        Container::Vector < Text::String > strvec;
        Container::Array < Text::String > strarr;
        for (int i = 0; i < 3; i ++ )
            {
#line 114
                strvec << Text::String::IntStr(i);
                strarr << Text::String::IntStr(i);
            }
        for (int i = 0; i < 3; i ++ )
            {
                {
#line 118
                    if (!(strvec[i] == strarr[i]))
                    {
#line 118
                        Lang::SysBreak("Assertion failed: strvec[i] == strarr[i]");
                    }
                }
#line 119
                ;
            }
        Container::Index < Text::String > stridx;
        stridx.Add("abc");
        {
#line 123
            if (!(stridx.GetCount() == 1))
            {
#line 123
                Lang::SysBreak("Assertion failed: stridx.GetCount() == 1");
            }
        }
#line 124
        ;
        {
#line 124
            if (!(stridx.Find("abc") == 0))
            {
#line 124
                Lang::SysBreak("Assertion failed: stridx.Find(\"abc\") == 0");
            }
        }
#line 125
        ;
#line 125
        stridx.Add("def");
        {
#line 126
            if (!(stridx.Find("abc") == 0))
            {
#line 126
                Lang::SysBreak("Assertion failed: stridx.Find(\"abc\") == 0");
            }
        }
#line 127
        ;
        {
#line 127
            if (!(stridx.Find("def") == 1))
            {
#line 127
                Lang::SysBreak("Assertion failed: stridx.Find(\"def\") == 1");
            }
        }
#line 128
        ;
#line 130
        Container::VectorMap < Text::String, int > vmap;
        Container::ArrayMap < Text::String, int > amap;
#line 133
        vmap.Add("abc", 123);
        vmap.Add("def", 456);
        {
#line 135
            if (!(vmap.GetKeys().Find("abc") == 0))
            {
#line 135
                Lang::SysBreak("Assertion failed: vmap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 136
        ;
        {
#line 136
            if (!(vmap.GetValues()[0] == 123))
            {
#line 136
                Lang::SysBreak("Assertion failed: vmap.GetValues()[0] == 123");
            }
        }
#line 137
        ;
        {
#line 137
            if (!(vmap.Find("abc") == 0))
            {
#line 137
                Lang::SysBreak("Assertion failed: vmap.Find(\"abc\") == 0");
            }
        }
#line 138
        ;
        {
#line 138
            if (!(vmap.Find("dfasgsg") == - 1))
            {
#line 138
                Lang::SysBreak("Assertion failed: vmap.Find(\"dfasgsg\") == -1");
            }
        }
#line 139
        ;
        {
#line 139
            if (!(vmap.GetValues().Join() == "123456"))
            {
#line 139
                Lang::SysBreak("Assertion failed: vmap.GetValues().Join() == \"123456\"");
            }
        }
#line 140
        ;
#line 140
        Container::Vector < int > vmap_keys;
        vmap_keys.Split(vmap.GetValues().Join(" "), " ");
        {
#line 142
            if (!(vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456))
            {
#line 142
                Lang::SysBreak("Assertion failed: vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456");
            }
        }
#line 143
        ;
#line 145
        amap.Add("abc", 123);
        amap.Add("def", 456);
        {
#line 147
            if (!(amap.GetKeys().Find("abc") == 0))
            {
#line 147
                Lang::SysBreak("Assertion failed: amap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 148
        ;
        {
#line 148
            if (!(amap.GetValues()[0] == 123))
            {
#line 148
                Lang::SysBreak("Assertion failed: amap.GetValues()[0] == 123");
            }
        }
#line 149
        ;
        {
#line 149
            if (!(amap.Find("abc") == 0))
            {
#line 149
                Lang::SysBreak("Assertion failed: amap.Find(\"abc\") == 0");
            }
        }
#line 150
        ;
        {
#line 150
            if (!(amap.Find("dfasgsg") == - 1))
            {
#line 150
                Lang::SysBreak("Assertion failed: amap.Find(\"dfasgsg\") == -1");
            }
        }
#line 151
        ;
#line 151
        Lang::FwdPairPtrIterator < Text::String, int > it = amap.Begin();
        for (int i = 0; i < 2; i ++ )
            {
#line 153
                if (i == 0)
                {
                    {
#line 154
                        if (!(it.GetKey() == "abc"))
                        {
#line 154
                            Lang::SysBreak("Assertion failed: it.GetKey() == \"abc\"");
                        }
                    }
#line 155
                    ;
                    {
#line 155
                        if (!(it.GetValue() == 123))
                        {
#line 155
                            Lang::SysBreak("Assertion failed: it.GetValue() == 123");
                        }
                    }
#line 156
                    ;
                }
                else 
#line 157
                if (i == 1)
                {
                    {
#line 158
                        if (!(it.GetKey() == "def"))
                        {
#line 158
                            Lang::SysBreak("Assertion failed: it.GetKey() == \"def\"");
                        }
                    }
#line 159
                    ;
                    {
#line 159
                        if (!(it.GetValue() == 456))
                        {
#line 159
                            Lang::SysBreak("Assertion failed: it.GetValue() == 456");
                        }
                    }
#line 160
                    ;
                }
#line 161
                ++ it;
            }
        {
#line 166
            Shared::Attachable a;
            Shared::Slot s;
            a.Attach(s);
            s.Clear();
        }
#line 173
        TestShared();
        {
#line 176
            Stream::StringStream ss;
            ss << "abc";
        }
        {
#line 181
            Stream::WStringStream wss;
            wss.Cat('t');
            wss.Cat('e');
            wss.Cat('s');
            wss.Cat('t');
            {
#line 186
                if (!(Text::ToString(wss.GetResult()) == "test"))
                {
#line 186
                    Lang::SysBreak("Assertion failed: ToString(wss.GetResult()) == \"test\"");
                }
            }
#line 187
            ;
        }
        Text::String s;
        {
            Stream::FileIn fin;
            {
#line 192
                if (!(fin.Open("/home/sblo/Fuck.cxx")))
                {
#line 192
                    Lang::SysBreak("Assertion failed: fin.Open(\"/home/sblo/Fuck.cxx\")");
                }
            }
#line 193
            ;
#line 193
            s = fin.Get(fin.GetSize());
            int sz = s.GetCount();
        }
#line 197
        Util::Log() << "Lol does this work\?\n";
#line 199
        Stream::FileOut fout;
        fout % r % f % d;
#line 202
        const Container::Vector < Text::String > & cmd = Util::Env::Local().CommandLine();
        for (int i = 0; i < cmd.GetCount(); i ++ )
            {
#line 204
                Text::String arg = cmd[i];
            }
#line 207
        Container::Index < Text::String > files;
        Util::GetDirectoryFiles("/", files);
        {
#line 209
            if (!(files.Find("home") >= 0))
            {
#line 209
                Lang::SysBreak("Assertion failed: files.Find(\"home\") >= 0");
            }
        }
#line 210
        ;
#line 210
        for (int i = 0; i < files.GetCount(); i ++ )
            {
#line 211
                Text::String s = files[i];
                const char * c = s.Begin();
                int len = Lang::StringLength(c);
            }
        {
#line 217
            double d = Math::FastSin(3.14159265358979323846);
            d = Math::FastCos(3.14159265358979323846);
        }
        {
#line 222
            Math::RandomGaussian & gaus = Math::GetRandomGaussian(13);
            double d = gaus;
            d = gaus;
            d = gaus;
            d = gaus;
        }
        {
#line 230
            Chrono::Time t1(2020, 10, 5, 3, 28, 0);
            Lang::int64 i64 = t1.Get();
            Chrono::Time t2;
            t2.Set(i64);
            {
#line 234
                if (!(t1 == t2))
                {
#line 234
                    Lang::SysBreak("Assertion failed: t1 == t2");
                }
            }
#line 235
            ;
#line 235
            Chrono::Time t3 = Chrono::GetSysTime();
        }
        {
#line 240
            Concurrency::Thread t;
            Concurrency::Mutex m;
        }
        {
#line 245
            Network::TcpSocket s;
            {
#line 246
                if (!(s.Listen(8005, 5)))
                {
#line 246
                    Lang::SysBreak("Assertion failed: s.Listen(8005, 5)");
                }
            }
#line 247
            ;
        }
        {
            TextProc::Tokenizer t;
        }
        {
#line 255
            TextProc::JSON j;
        }
    };
    
#line 45
    inline App::DerivedBase::DerivedBase()
    :
        a(8)
    {};
    
#line 286
    inline App::Dumb::Dumb()
    {
#line 286
        ;
    };
    
#line 287
    inline App::Dumb::~Dumb()
    {
#line 287
        ;
    };
    
#line 282
    inline App::Dumber::Dumber()
    {
#line 282
        ;
    };
    
#line 33
    inline bool App::TestCmp::operator()(const char& c)
    {
#line 34
        return c == 'c';
    };
    
#line 39
    inline App::VirtualBase::VirtualBase()
    :
        a(3)
    {};
    
};

#endif
