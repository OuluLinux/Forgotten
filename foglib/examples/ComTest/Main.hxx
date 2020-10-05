#ifndef MAIN_HXX
#define MAIN_HXX

#include <new>

#ifndef UTIL_HXX
#include <Util.hxx>
#endif

struct NamespaceInterfaceLinker
{
};

#ifndef CHRONO_HXX
#include <Chrono.hxx>
#endif
#ifndef COM_HXX
#include <Com.hxx>
#endif

namespace Main
{
    class App
    {
#line 20 "ComTest.mfog"
        Container::VectorMap < int, int > arr;
        
    public:
#line 44
        inline void Run();
        
#line 252
        void TestShared();
        
        struct Dumber
        {
#line 244
            inline Dumber();
            virtual ~Dumber();
        };
        
        struct Dumb : public Main::App::Dumber
        {
#line 248
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
#line 24 "ComTest.mfog"
            inline bool operator()(const char& c);
        };
        
        struct VirtualBase
        {
#line 33
            int a;
            
#line 30
            inline VirtualBase();
            virtual ~VirtualBase();
        };
        
        struct DerivedBase : public Main::App::VirtualBase
        {
#line 38
            int a;
            
#line 36
            inline DerivedBase();
        };
    };
};

namespace Main
{
#line 44
    inline void App::Run()
    {
#line 45
        Lang::uint64 v = 4294967295U;
        {
#line 46
            if (!(sizeof (v) == 8))
            {
#line 46
                Lang::SysBreak("Assertion failed: sizeof(v) == 8");
            }
        }
#line 47
        ;
        Lang::VoidPtr p;
        {
#line 49
            if (!(p == 0))
            {
#line 49
                Lang::SysBreak("Assertion failed: p == NULL");
            }
        }
#line 50
        ;
        {
#line 51
            if (!(Native::SignificantBits(0x8000) == 16))
            {
#line 51
                Lang::SysBreak("Assertion failed: SignificantBits(0x8000) == 16");
            }
        }
#line 52
        ;
        {
#line 52
            if (!(Native::SignificantBits64(0x8000) == 16))
            {
#line 52
                Lang::SysBreak("Assertion failed: SignificantBits64(0x8000) == 16");
            }
        }
#line 53
        ;
        Hash::Combine ch;
        ch.Put(777999777).Put(123).Put64(0xF0F0F0F0F0F0F0F0);
        Lang::dword hash = ch;
        {
#line 57
            if (!(hash == 1894504625))
            {
#line 57
                Lang::SysBreak("Assertion failed: hash == 1894504625");
            }
        }
#line 58
        ;
#line 58
        int a = 0;
        int b = 1;
        {
#line 60
            if (!(Algorithm::Minimum(a, b) < Algorithm::Maximum(a, b)))
            {
#line 60
                Lang::SysBreak("Assertion failed: Min(a, b) < Max(a, b)");
            }
        }
#line 61
        ;
        int r = Random::Int();
        float f = Random::Float();
        float d = Random::Double();
        int j = d;
#line 68
        const char * test_str = "abcdef";
        int test_strlen = Lang::StringLength(test_str);
        {
#line 70
            if (!(Container::FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2))
            {
#line 70
                Lang::SysBreak("Assertion failed: FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2");
            }
        }
#line 71
        ;
        {
            if (!(Text::String("test") == "test"))
            {
#line 73
                Lang::SysBreak("Assertion failed: String(\"test\") == \"test\"");
            }
        }
#line 74
        ;
        {
#line 74
            if (!(Text::String::DblStr(1.2) == "1.2"))
            {
#line 74
                Lang::SysBreak("Assertion failed: DblStr(1.2) == \"1.2\"");
            }
        }
#line 75
        ;
        {
#line 75
            if (!((Text::String)"abc" + Text::String("def") == "abcdef"))
            {
#line 75
                Lang::SysBreak("Assertion failed: (String)\"abc\" + String(\"def\") == \"abcdef\"");
            }
        }
#line 76
        ;
        {
#line 76
            if (!(Text::String("abc") + "def" == "abcdef"))
            {
#line 76
                Lang::SysBreak("Assertion failed: String(\"abc\") + \"def\" == \"abcdef\"");
            }
        }
#line 77
        ;
        {
#line 77
            if (!(Text::ToString(Text::ToWString < Text::String > ("abc")) == "abc"))
            {
#line 77
                Lang::SysBreak("Assertion failed: ToString(ToWString<String>(\"abc\")) == \"abc\"");
            }
        }
#line 78
        ;
        {
#line 78
            if (!(Text::ToInt < Text::String > ("123") == 123))
            {
#line 78
                Lang::SysBreak("Assertion failed: ToInt<String>(\"123\") == 123");
            }
        }
#line 79
        ;
        {
#line 79
            if (!(Text::ToString(123) == "123"))
            {
#line 79
                Lang::SysBreak("Assertion failed: ToString(123) == \"123\"");
            }
        }
#line 80
        ;
        {
#line 80
            if (!(Text::HexStr((void * )0x123f) == "0x123F"))
            {
#line 80
                Lang::SysBreak("Assertion failed: HexStr((void*)0x123f) == \"0x123F\"");
            }
        }
#line 81
        ;
#line 83
        SomeTuple2 ttt = 
        {
            1,
            1.2
        };
        {
#line 84
            if (!(Text::ToString(ttt) == "1, 1.2"))
            {
#line 84
                Lang::SysBreak("Assertion failed: ToString(ttt) == \"1, 1.2\"");
            }
        }
#line 85
        ;
        SomeRefTuple2 tttref(ttt.a, ttt.b);
        {
#line 87
            if (!(Text::ToString(tttref) == "1, 1.2"))
            {
#line 87
                Lang::SysBreak("Assertion failed: ToString(tttref) == \"1, 1.2\"");
            }
        }
#line 88
        ;
        Container::One < Text::String > onestr;
        onestr.Create();
        *onestr = "hello";
        {
#line 92
            if (!(*onestr == "hello"))
            {
#line 92
                Lang::SysBreak("Assertion failed: *onestr == \"hello\"");
            }
        }
#line 93
        ;
        Container::One < VirtualBase > onebase;
        onebase.CreateDerived < DerivedBase > ();
        {
#line 96
            if (!(onebase.GetDerived < DerivedBase > ()-> a == 8))
            {
#line 96
                Lang::SysBreak("Assertion failed: onebase.GetDerived<DerivedBase>()->a == 8");
            }
        }
#line 97
        ;
        Container::FutureOne < Text::String > fone;
        fone = new Text::String;
        fone.Wait();
#line 102
        Container::Vector < Text::String > strvec;
        Container::Array < Text::String > strarr;
        for (int i = 0; i < 3; i ++ )
            {
#line 105
                strvec << Text::String::IntStr(i);
                strarr << Text::String::IntStr(i);
            }
        for (int i = 0; i < 3; i ++ )
            {
                {
#line 109
                    if (!(strvec[i] == strarr[i]))
                    {
#line 109
                        Lang::SysBreak("Assertion failed: strvec[i] == strarr[i]");
                    }
                }
#line 110
                ;
            }
        Container::Index < Text::String > stridx;
        stridx.Add("abc");
        {
#line 114
            if (!(stridx.GetCount() == 1))
            {
#line 114
                Lang::SysBreak("Assertion failed: stridx.GetCount() == 1");
            }
        }
#line 115
        ;
        {
#line 115
            if (!(stridx.Find("abc") == 0))
            {
#line 115
                Lang::SysBreak("Assertion failed: stridx.Find(\"abc\") == 0");
            }
        }
#line 116
        ;
#line 116
        stridx.Add("def");
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
        {
#line 118
            if (!(stridx.Find("def") == 1))
            {
#line 118
                Lang::SysBreak("Assertion failed: stridx.Find(\"def\") == 1");
            }
        }
#line 119
        ;
#line 121
        Container::VectorMap < Text::String, int > vmap;
        Container::ArrayMap < Text::String, int > amap;
#line 124
        vmap.Add("abc", 123);
        vmap.Add("def", 456);
        {
#line 126
            if (!(vmap.GetKeys().Find("abc") == 0))
            {
#line 126
                Lang::SysBreak("Assertion failed: vmap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 127
        ;
        {
#line 127
            if (!(vmap.GetValues()[0] == 123))
            {
#line 127
                Lang::SysBreak("Assertion failed: vmap.GetValues()[0] == 123");
            }
        }
#line 128
        ;
        {
#line 128
            if (!(vmap.Find("abc") == 0))
            {
#line 128
                Lang::SysBreak("Assertion failed: vmap.Find(\"abc\") == 0");
            }
        }
#line 129
        ;
        {
#line 129
            if (!(vmap.Find("dfasgsg") == - 1))
            {
#line 129
                Lang::SysBreak("Assertion failed: vmap.Find(\"dfasgsg\") == -1");
            }
        }
#line 130
        ;
        {
#line 130
            if (!(vmap.GetValues().Join() == "123456"))
            {
#line 130
                Lang::SysBreak("Assertion failed: vmap.GetValues().Join() == \"123456\"");
            }
        }
#line 131
        ;
#line 131
        Container::Vector < int > vmap_keys;
        vmap_keys.Split(vmap.GetValues().Join(" "), " ");
        {
#line 133
            if (!(vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456))
            {
#line 133
                Lang::SysBreak("Assertion failed: vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456");
            }
        }
#line 134
        ;
#line 136
        amap.Add("abc", 123);
        amap.Add("def", 456);
        {
#line 138
            if (!(amap.GetKeys().Find("abc") == 0))
            {
#line 138
                Lang::SysBreak("Assertion failed: amap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 139
        ;
        {
#line 139
            if (!(amap.GetValues()[0] == 123))
            {
#line 139
                Lang::SysBreak("Assertion failed: amap.GetValues()[0] == 123");
            }
        }
#line 140
        ;
        {
#line 140
            if (!(amap.Find("abc") == 0))
            {
#line 140
                Lang::SysBreak("Assertion failed: amap.Find(\"abc\") == 0");
            }
        }
#line 141
        ;
        {
#line 141
            if (!(amap.Find("dfasgsg") == - 1))
            {
#line 141
                Lang::SysBreak("Assertion failed: amap.Find(\"dfasgsg\") == -1");
            }
        }
#line 142
        ;
#line 142
        Lang::FwdPairPtrIterator < Text::String, int > it = amap.Begin();
        for (int i = 0; i < 2; i ++ )
            {
#line 144
                if (i == 0)
                {
                    {
#line 145
                        if (!(it.Key() == "abc"))
                        {
#line 145
                            Lang::SysBreak("Assertion failed: it.Key() == \"abc\"");
                        }
                    }
#line 146
                    ;
                    {
#line 146
                        if (!(it.Value() == 123))
                        {
#line 146
                            Lang::SysBreak("Assertion failed: it.Value() == 123");
                        }
                    }
#line 147
                    ;
                }
                else 
#line 148
                if (i == 1)
                {
                    {
#line 149
                        if (!(it.Key() == "def"))
                        {
#line 149
                            Lang::SysBreak("Assertion failed: it.Key() == \"def\"");
                        }
                    }
#line 150
                    ;
                    {
#line 150
                        if (!(it.Value() == 456))
                        {
#line 150
                            Lang::SysBreak("Assertion failed: it.Value() == 456");
                        }
                    }
#line 151
                    ;
                }
#line 152
                ++ it;
            }
        {
#line 157
            Shared::Attachable a;
            Shared::Slot s;
            a.Attach(s);
            s.Clear();
        }
#line 164
        TestShared();
        {
#line 167
            Stream::StringStream ss;
            ss << "abc";
        }
#line 171
        Text::String s;
        {
            Stream::FileIn fin;
            {
#line 174
                if (!(fin.Open("/home/sblo/Fuck.cxx")))
                {
#line 174
                    Lang::SysBreak("Assertion failed: fin.Open(\"/home/sblo/Fuck.cxx\")");
                }
            }
#line 175
            ;
#line 175
            s = fin.Get(fin.GetSize());
            int sz = s.GetCount();
        }
#line 179
        Util::Log() << "Lol does this work\?\n";
#line 181
        Stream::FileOut fout;
        fout % r % f % d;
#line 184
        const Container::Vector < Text::String > & cmd = Util::Env::Local().CommandLine();
        for (int i = 0; i < cmd.GetCount(); i ++ )
            {
#line 186
                Text::String arg = cmd[i];
            }
#line 189
        Container::Index < Text::String > files;
        Util::GetDirectoryFiles("/", files);
        {
#line 191
            if (!(files.Find("home") >= 0))
            {
#line 191
                Lang::SysBreak("Assertion failed: files.Find(\"home\") >= 0");
            }
        }
#line 192
        ;
#line 192
        for (int i = 0; i < files.GetCount(); i ++ )
            {
#line 193
                Text::String s = files[i];
                const char * c = s.Begin();
                int len = Lang::StringLength(c);
            }
        {
#line 199
            double d = Math::FastSin(3.14159265358979323846);
            d = Math::FastCos(3.14159265358979323846);
        }
        {
#line 204
            Math::RandomGaussian & gaus = Math::GetRandomGaussian(13);
            double d = gaus;
            d = gaus;
            d = gaus;
            d = gaus;
        }
        {
#line 212
            Chrono::Time t1(2020, 10, 5, 3, 28, 0);
            Lang::int64 i64 = t1.Get();
            Chrono::Time t2;
            t2.Set(i64);
            {
#line 216
                if (!(t1 == t2))
                {
#line 216
                    Lang::SysBreak("Assertion failed: t1 == t2");
                }
            }
#line 217
            ;
        }
    };
    
#line 36
    inline App::DerivedBase::DerivedBase()
    :
        a(8)
    {};
    
#line 248
    inline App::Dumb::Dumb()
    {
#line 248
        ;
    };
    
#line 249
    inline App::Dumb::~Dumb()
    {
#line 249
        ;
    };
    
#line 244
    inline App::Dumber::Dumber()
    {
#line 244
        ;
    };
    
#line 24
    inline bool App::TestCmp::operator()(const char& c)
    {
#line 25
        return c == 'c';
    };
    
#line 30
    inline App::VirtualBase::VirtualBase()
    :
        a(3)
    {};
    
};

#endif
