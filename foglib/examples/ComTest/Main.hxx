#ifndef MAIN_HXX
#define MAIN_HXX

#include <new>

#ifndef UTIL_HXX
#include <Util.hxx>
#endif

struct NamespaceInterfaceLinker
{
};

#ifndef CONCURRENCY_HXX
#include <Concurrency.hxx>
#endif
#ifndef MATH_HXX
#include <Math.hxx>
#endif
#ifndef COM_HXX
#include <Com.hxx>
#endif

namespace Main
{
    class App
    {
#line 21 "ComTest.mfog"
        Container::VectorMap < int, int > arr;
        
    public:
#line 45
        inline void Run();
        
#line 257
        void TestShared();
        
        struct Dumber
        {
#line 249
            inline Dumber();
            virtual ~Dumber();
        };
        
        struct Dumb : public Main::App::Dumber
        {
#line 253
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
#line 25 "ComTest.mfog"
            inline bool operator()(const char& c);
        };
        
        struct VirtualBase
        {
#line 34
            int a;
            
#line 31
            inline VirtualBase();
            virtual ~VirtualBase();
        };
        
        struct DerivedBase : public Main::App::VirtualBase
        {
#line 39
            int a;
            
#line 37
            inline DerivedBase();
        };
    };
};

namespace Main
{
#line 45
    inline void App::Run()
    {
#line 46
        Lang::uint64 v = 4294967295U;
        {
#line 47
            if (!(sizeof (v) == 8))
            {
#line 47
                Lang::SysBreak("Assertion failed: sizeof(v) == 8");
            }
        }
#line 48
        ;
        Lang::VoidPtr p;
        {
#line 50
            if (!(p == 0))
            {
#line 50
                Lang::SysBreak("Assertion failed: p == NULL");
            }
        }
#line 51
        ;
        {
#line 52
            if (!(Native::SignificantBits(0x8000) == 16))
            {
#line 52
                Lang::SysBreak("Assertion failed: SignificantBits(0x8000) == 16");
            }
        }
#line 53
        ;
        {
#line 53
            if (!(Native::SignificantBits64(0x8000) == 16))
            {
#line 53
                Lang::SysBreak("Assertion failed: SignificantBits64(0x8000) == 16");
            }
        }
#line 54
        ;
        Hash::Combine ch;
        ch.Put(777999777).Put(123).Put64(0xF0F0F0F0F0F0F0F0);
        Lang::dword hash = ch;
        {
#line 58
            if (!(hash == 1894504625))
            {
#line 58
                Lang::SysBreak("Assertion failed: hash == 1894504625");
            }
        }
#line 59
        ;
#line 59
        int a = 0;
        int b = 1;
        {
#line 61
            if (!(Algorithm::Minimum(a, b) < Algorithm::Maximum(a, b)))
            {
#line 61
                Lang::SysBreak("Assertion failed: Min(a, b) < Max(a, b)");
            }
        }
#line 62
        ;
        int r = Random::Int();
        float f = Random::Float();
        float d = Random::Double();
        int j = d;
#line 69
        const char * test_str = "abcdef";
        int test_strlen = Lang::StringLength(test_str);
        {
#line 71
            if (!(Container::FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2))
            {
#line 71
                Lang::SysBreak("Assertion failed: FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2");
            }
        }
#line 72
        ;
        {
            if (!(Text::String("test") == "test"))
            {
#line 74
                Lang::SysBreak("Assertion failed: String(\"test\") == \"test\"");
            }
        }
#line 75
        ;
        {
#line 75
            if (!(Text::String::DblStr(1.2) == "1.2"))
            {
#line 75
                Lang::SysBreak("Assertion failed: DblStr(1.2) == \"1.2\"");
            }
        }
#line 76
        ;
        {
#line 76
            if (!((Text::String)"abc" + Text::String("def") == "abcdef"))
            {
#line 76
                Lang::SysBreak("Assertion failed: (String)\"abc\" + String(\"def\") == \"abcdef\"");
            }
        }
#line 77
        ;
        {
#line 77
            if (!(Text::String("abc") + "def" == "abcdef"))
            {
#line 77
                Lang::SysBreak("Assertion failed: String(\"abc\") + \"def\" == \"abcdef\"");
            }
        }
#line 78
        ;
        {
#line 78
            if (!(Text::ToString(Text::ToWString < Text::String > ("abc")) == "abc"))
            {
#line 78
                Lang::SysBreak("Assertion failed: ToString(ToWString<String>(\"abc\")) == \"abc\"");
            }
        }
#line 79
        ;
        {
#line 79
            if (!(Text::ToInt < Text::String > ("123") == 123))
            {
#line 79
                Lang::SysBreak("Assertion failed: ToInt<String>(\"123\") == 123");
            }
        }
#line 80
        ;
        {
#line 80
            if (!(Text::ToString(123) == "123"))
            {
#line 80
                Lang::SysBreak("Assertion failed: ToString(123) == \"123\"");
            }
        }
#line 81
        ;
        {
#line 81
            if (!(Text::HexStr((void * )0x123f) == "0x123F"))
            {
#line 81
                Lang::SysBreak("Assertion failed: HexStr((void*)0x123f) == \"0x123F\"");
            }
        }
#line 82
        ;
#line 84
        SomeTuple2 ttt = 
        {
            1,
            1.2
        };
        {
#line 85
            if (!(Text::ToString(ttt) == "1, 1.2"))
            {
#line 85
                Lang::SysBreak("Assertion failed: ToString(ttt) == \"1, 1.2\"");
            }
        }
#line 86
        ;
        SomeRefTuple2 tttref(ttt.a, ttt.b);
        {
#line 88
            if (!(Text::ToString(tttref) == "1, 1.2"))
            {
#line 88
                Lang::SysBreak("Assertion failed: ToString(tttref) == \"1, 1.2\"");
            }
        }
#line 89
        ;
        Container::One < Text::String > onestr;
        onestr.Create();
        *onestr = "hello";
        {
#line 93
            if (!(*onestr == "hello"))
            {
#line 93
                Lang::SysBreak("Assertion failed: *onestr == \"hello\"");
            }
        }
#line 94
        ;
        Container::One < VirtualBase > onebase;
        onebase.CreateDerived < DerivedBase > ();
        {
#line 97
            if (!(onebase.GetDerived < DerivedBase > ()-> a == 8))
            {
#line 97
                Lang::SysBreak("Assertion failed: onebase.GetDerived<DerivedBase>()->a == 8");
            }
        }
#line 98
        ;
        Container::FutureOne < Text::String > fone;
        fone = new Text::String;
        fone.Wait();
#line 103
        Container::Vector < Text::String > strvec;
        Container::Array < Text::String > strarr;
        for (int i = 0; i < 3; i ++ )
            {
#line 106
                strvec << Text::String::IntStr(i);
                strarr << Text::String::IntStr(i);
            }
        for (int i = 0; i < 3; i ++ )
            {
                {
#line 110
                    if (!(strvec[i] == strarr[i]))
                    {
#line 110
                        Lang::SysBreak("Assertion failed: strvec[i] == strarr[i]");
                    }
                }
#line 111
                ;
            }
        Container::Index < Text::String > stridx;
        stridx.Add("abc");
        {
#line 115
            if (!(stridx.GetCount() == 1))
            {
#line 115
                Lang::SysBreak("Assertion failed: stridx.GetCount() == 1");
            }
        }
#line 116
        ;
        {
#line 116
            if (!(stridx.Find("abc") == 0))
            {
#line 116
                Lang::SysBreak("Assertion failed: stridx.Find(\"abc\") == 0");
            }
        }
#line 117
        ;
#line 117
        stridx.Add("def");
        {
#line 118
            if (!(stridx.Find("abc") == 0))
            {
#line 118
                Lang::SysBreak("Assertion failed: stridx.Find(\"abc\") == 0");
            }
        }
#line 119
        ;
        {
#line 119
            if (!(stridx.Find("def") == 1))
            {
#line 119
                Lang::SysBreak("Assertion failed: stridx.Find(\"def\") == 1");
            }
        }
#line 120
        ;
#line 122
        Container::VectorMap < Text::String, int > vmap;
        Container::ArrayMap < Text::String, int > amap;
#line 125
        vmap.Add("abc", 123);
        vmap.Add("def", 456);
        {
#line 127
            if (!(vmap.GetKeys().Find("abc") == 0))
            {
#line 127
                Lang::SysBreak("Assertion failed: vmap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 128
        ;
        {
#line 128
            if (!(vmap.GetValues()[0] == 123))
            {
#line 128
                Lang::SysBreak("Assertion failed: vmap.GetValues()[0] == 123");
            }
        }
#line 129
        ;
        {
#line 129
            if (!(vmap.Find("abc") == 0))
            {
#line 129
                Lang::SysBreak("Assertion failed: vmap.Find(\"abc\") == 0");
            }
        }
#line 130
        ;
        {
#line 130
            if (!(vmap.Find("dfasgsg") == - 1))
            {
#line 130
                Lang::SysBreak("Assertion failed: vmap.Find(\"dfasgsg\") == -1");
            }
        }
#line 131
        ;
        {
#line 131
            if (!(vmap.GetValues().Join() == "123456"))
            {
#line 131
                Lang::SysBreak("Assertion failed: vmap.GetValues().Join() == \"123456\"");
            }
        }
#line 132
        ;
#line 132
        Container::Vector < int > vmap_keys;
        vmap_keys.Split(vmap.GetValues().Join(" "), " ");
        {
#line 134
            if (!(vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456))
            {
#line 134
                Lang::SysBreak("Assertion failed: vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456");
            }
        }
#line 135
        ;
#line 137
        amap.Add("abc", 123);
        amap.Add("def", 456);
        {
#line 139
            if (!(amap.GetKeys().Find("abc") == 0))
            {
#line 139
                Lang::SysBreak("Assertion failed: amap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 140
        ;
        {
#line 140
            if (!(amap.GetValues()[0] == 123))
            {
#line 140
                Lang::SysBreak("Assertion failed: amap.GetValues()[0] == 123");
            }
        }
#line 141
        ;
        {
#line 141
            if (!(amap.Find("abc") == 0))
            {
#line 141
                Lang::SysBreak("Assertion failed: amap.Find(\"abc\") == 0");
            }
        }
#line 142
        ;
        {
#line 142
            if (!(amap.Find("dfasgsg") == - 1))
            {
#line 142
                Lang::SysBreak("Assertion failed: amap.Find(\"dfasgsg\") == -1");
            }
        }
#line 143
        ;
#line 143
        Lang::FwdPairPtrIterator < Text::String, int > it = amap.Begin();
        for (int i = 0; i < 2; i ++ )
            {
#line 145
                if (i == 0)
                {
                    {
#line 146
                        if (!(it.Key() == "abc"))
                        {
#line 146
                            Lang::SysBreak("Assertion failed: it.Key() == \"abc\"");
                        }
                    }
#line 147
                    ;
                    {
#line 147
                        if (!(it.Value() == 123))
                        {
#line 147
                            Lang::SysBreak("Assertion failed: it.Value() == 123");
                        }
                    }
#line 148
                    ;
                }
                else 
#line 149
                if (i == 1)
                {
                    {
#line 150
                        if (!(it.Key() == "def"))
                        {
#line 150
                            Lang::SysBreak("Assertion failed: it.Key() == \"def\"");
                        }
                    }
#line 151
                    ;
                    {
#line 151
                        if (!(it.Value() == 456))
                        {
#line 151
                            Lang::SysBreak("Assertion failed: it.Value() == 456");
                        }
                    }
#line 152
                    ;
                }
#line 153
                ++ it;
            }
        {
#line 158
            Shared::Attachable a;
            Shared::Slot s;
            a.Attach(s);
            s.Clear();
        }
#line 165
        TestShared();
        {
#line 168
            Stream::StringStream ss;
            ss << "abc";
        }
#line 172
        Text::String s;
        {
            Stream::FileIn fin;
            {
#line 175
                if (!(fin.Open("/home/sblo/Fuck.cxx")))
                {
#line 175
                    Lang::SysBreak("Assertion failed: fin.Open(\"/home/sblo/Fuck.cxx\")");
                }
            }
#line 176
            ;
#line 176
            s = fin.Get(fin.GetSize());
            int sz = s.GetCount();
        }
#line 180
        Util::Log() << "Lol does this work\?\n";
#line 182
        Stream::FileOut fout;
        fout % r % f % d;
#line 185
        const Container::Vector < Text::String > & cmd = Util::Env::Local().CommandLine();
        for (int i = 0; i < cmd.GetCount(); i ++ )
            {
#line 187
                Text::String arg = cmd[i];
            }
#line 190
        Container::Index < Text::String > files;
        Util::GetDirectoryFiles("/", files);
        {
#line 192
            if (!(files.Find("home") >= 0))
            {
#line 192
                Lang::SysBreak("Assertion failed: files.Find(\"home\") >= 0");
            }
        }
#line 193
        ;
#line 193
        for (int i = 0; i < files.GetCount(); i ++ )
            {
#line 194
                Text::String s = files[i];
                const char * c = s.Begin();
                int len = Lang::StringLength(c);
            }
        {
#line 200
            double d = Math::FastSin(3.14159265358979323846);
            d = Math::FastCos(3.14159265358979323846);
        }
        {
#line 205
            Math::RandomGaussian & gaus = Math::GetRandomGaussian(13);
            double d = gaus;
            d = gaus;
            d = gaus;
            d = gaus;
        }
        {
#line 213
            Chrono::Time t1(2020, 10, 5, 3, 28, 0);
            Lang::int64 i64 = t1.Get();
            Chrono::Time t2;
            t2.Set(i64);
            {
#line 217
                if (!(t1 == t2))
                {
#line 217
                    Lang::SysBreak("Assertion failed: t1 == t2");
                }
            }
#line 218
            ;
        }
        {
#line 222
            Concurrency::Thread t;
            Concurrency::Mutex m;
        }
    };
    
#line 37
    inline App::DerivedBase::DerivedBase()
    :
        a(8)
    {};
    
#line 253
    inline App::Dumb::Dumb()
    {
#line 253
        ;
    };
    
#line 254
    inline App::Dumb::~Dumb()
    {
#line 254
        ;
    };
    
#line 249
    inline App::Dumber::Dumber()
    {
#line 249
        ;
    };
    
#line 25
    inline bool App::TestCmp::operator()(const char& c)
    {
#line 26
        return c == 'c';
    };
    
#line 31
    inline App::VirtualBase::VirtualBase()
    :
        a(3)
    {};
    
};

#endif
