#ifndef MAIN_HXX
#define MAIN_HXX

#include <new>

#ifndef UTIL_HXX
#include <Util.hxx>
#endif

struct NamespaceInterfaceLinker
{
};

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
#line 19 "ComTest.mfog"
        Container::VectorMap < int, int > arr;
        
    public:
#line 43
        inline void Run();
        
#line 242
        void TestShared();
        
        struct Dumber
        {
#line 234
            inline Dumber();
            virtual ~Dumber();
        };
        
        struct Dumb : public Main::App::Dumber
        {
#line 238
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
#line 23 "ComTest.mfog"
            inline bool operator()(const char& c);
        };
        
        struct VirtualBase
        {
#line 32
            int a;
            
#line 29
            inline VirtualBase();
            virtual ~VirtualBase();
        };
        
        struct DerivedBase : public Main::App::VirtualBase
        {
#line 37
            int a;
            
#line 35
            inline DerivedBase();
        };
    };
};

namespace Main
{
#line 43
    inline void App::Run()
    {
#line 44
        Lang::uint64 v = 4294967295U;
        {
#line 45
            if (!(sizeof (v) == 8))
            {
#line 45
                Lang::SysBreak("Assertion failed: sizeof(v) == 8");
            }
        }
#line 46
        ;
        Lang::VoidPtr p;
        {
#line 48
            if (!(p == 0))
            {
#line 48
                Lang::SysBreak("Assertion failed: p == NULL");
            }
        }
#line 49
        ;
        {
#line 50
            if (!(Native::SignificantBits(0x8000) == 16))
            {
#line 50
                Lang::SysBreak("Assertion failed: SignificantBits(0x8000) == 16");
            }
        }
#line 51
        ;
        {
#line 51
            if (!(Native::SignificantBits64(0x8000) == 16))
            {
#line 51
                Lang::SysBreak("Assertion failed: SignificantBits64(0x8000) == 16");
            }
        }
#line 52
        ;
        Hash::Combine ch;
        ch.Put(777999777).Put(123).Put64(0xF0F0F0F0F0F0F0F0);
        Lang::dword hash = ch;
        {
#line 56
            if (!(hash == 1894504625))
            {
#line 56
                Lang::SysBreak("Assertion failed: hash == 1894504625");
            }
        }
#line 57
        ;
#line 57
        int a = 0;
        int b = 1;
        {
#line 59
            if (!(Algorithm::Minimum(a, b) < Algorithm::Maximum(a, b)))
            {
#line 59
                Lang::SysBreak("Assertion failed: Min(a, b) < Max(a, b)");
            }
        }
#line 60
        ;
        int r = Random::Int();
        float f = Random::Float();
        float d = Random::Double();
        int j = d;
#line 67
        const char * test_str = "abcdef";
        int test_strlen = Lang::StringLength(test_str);
        {
#line 69
            if (!(Container::FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2))
            {
#line 69
                Lang::SysBreak("Assertion failed: FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2");
            }
        }
#line 70
        ;
        {
            if (!(Text::String("test") == "test"))
            {
#line 72
                Lang::SysBreak("Assertion failed: String(\"test\") == \"test\"");
            }
        }
#line 73
        ;
        {
#line 73
            if (!(Text::String::DblStr(1.2) == "1.2"))
            {
#line 73
                Lang::SysBreak("Assertion failed: DblStr(1.2) == \"1.2\"");
            }
        }
#line 74
        ;
        {
#line 74
            if (!((Text::String)"abc" + Text::String("def") == "abcdef"))
            {
#line 74
                Lang::SysBreak("Assertion failed: (String)\"abc\" + String(\"def\") == \"abcdef\"");
            }
        }
#line 75
        ;
        {
#line 75
            if (!(Text::String("abc") + "def" == "abcdef"))
            {
#line 75
                Lang::SysBreak("Assertion failed: String(\"abc\") + \"def\" == \"abcdef\"");
            }
        }
#line 76
        ;
        {
#line 76
            if (!(Text::ToString(Text::ToWString < Text::String > ("abc")) == "abc"))
            {
#line 76
                Lang::SysBreak("Assertion failed: ToString(ToWString<String>(\"abc\")) == \"abc\"");
            }
        }
#line 77
        ;
        {
#line 77
            if (!(Text::ToInt < Text::String > ("123") == 123))
            {
#line 77
                Lang::SysBreak("Assertion failed: ToInt<String>(\"123\") == 123");
            }
        }
#line 78
        ;
        {
#line 78
            if (!(Text::ToString(123) == "123"))
            {
#line 78
                Lang::SysBreak("Assertion failed: ToString(123) == \"123\"");
            }
        }
#line 79
        ;
        {
#line 79
            if (!(Text::HexStr((void * )0x123f) == "0x123F"))
            {
#line 79
                Lang::SysBreak("Assertion failed: HexStr((void*)0x123f) == \"0x123F\"");
            }
        }
#line 80
        ;
#line 82
        SomeTuple2 ttt = 
        {
            1,
            1.2
        };
        {
#line 83
            if (!(Text::ToString(ttt) == "1, 1.2"))
            {
#line 83
                Lang::SysBreak("Assertion failed: ToString(ttt) == \"1, 1.2\"");
            }
        }
#line 84
        ;
        SomeRefTuple2 tttref(ttt.a, ttt.b);
        {
#line 86
            if (!(Text::ToString(tttref) == "1, 1.2"))
            {
#line 86
                Lang::SysBreak("Assertion failed: ToString(tttref) == \"1, 1.2\"");
            }
        }
#line 87
        ;
        Container::One < Text::String > onestr;
        onestr.Create();
        *onestr = "hello";
        {
#line 91
            if (!(*onestr == "hello"))
            {
#line 91
                Lang::SysBreak("Assertion failed: *onestr == \"hello\"");
            }
        }
#line 92
        ;
        Container::One < VirtualBase > onebase;
        onebase.CreateDerived < DerivedBase > ();
        {
#line 95
            if (!(onebase.GetDerived < DerivedBase > ()-> a == 8))
            {
#line 95
                Lang::SysBreak("Assertion failed: onebase.GetDerived<DerivedBase>()->a == 8");
            }
        }
#line 96
        ;
        Container::FutureOne < Text::String > fone;
        fone = new Text::String;
        fone.Wait();
#line 101
        Container::Vector < Text::String > strvec;
        Container::Array < Text::String > strarr;
        for (int i = 0; i < 3; i ++ )
            {
#line 104
                strvec << Text::String::IntStr(i);
                strarr << Text::String::IntStr(i);
            }
        for (int i = 0; i < 3; i ++ )
            {
                {
#line 108
                    if (!(strvec[i] == strarr[i]))
                    {
#line 108
                        Lang::SysBreak("Assertion failed: strvec[i] == strarr[i]");
                    }
                }
#line 109
                ;
            }
        Container::Index < Text::String > stridx;
        stridx.Add("abc");
        {
#line 113
            if (!(stridx.GetCount() == 1))
            {
#line 113
                Lang::SysBreak("Assertion failed: stridx.GetCount() == 1");
            }
        }
#line 114
        ;
        {
#line 114
            if (!(stridx.Find("abc") == 0))
            {
#line 114
                Lang::SysBreak("Assertion failed: stridx.Find(\"abc\") == 0");
            }
        }
#line 115
        ;
#line 115
        stridx.Add("def");
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
        {
#line 117
            if (!(stridx.Find("def") == 1))
            {
#line 117
                Lang::SysBreak("Assertion failed: stridx.Find(\"def\") == 1");
            }
        }
#line 118
        ;
#line 120
        Container::VectorMap < Text::String, int > vmap;
        Container::ArrayMap < Text::String, int > amap;
#line 123
        vmap.Add("abc", 123);
        vmap.Add("def", 456);
        {
#line 125
            if (!(vmap.GetKeys().Find("abc") == 0))
            {
#line 125
                Lang::SysBreak("Assertion failed: vmap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 126
        ;
        {
#line 126
            if (!(vmap.GetValues()[0] == 123))
            {
#line 126
                Lang::SysBreak("Assertion failed: vmap.GetValues()[0] == 123");
            }
        }
#line 127
        ;
        {
#line 127
            if (!(vmap.Find("abc") == 0))
            {
#line 127
                Lang::SysBreak("Assertion failed: vmap.Find(\"abc\") == 0");
            }
        }
#line 128
        ;
        {
#line 128
            if (!(vmap.Find("dfasgsg") == - 1))
            {
#line 128
                Lang::SysBreak("Assertion failed: vmap.Find(\"dfasgsg\") == -1");
            }
        }
#line 129
        ;
        {
#line 129
            if (!(vmap.GetValues().Join() == "123456"))
            {
#line 129
                Lang::SysBreak("Assertion failed: vmap.GetValues().Join() == \"123456\"");
            }
        }
#line 130
        ;
#line 130
        Container::Vector < int > vmap_keys;
        vmap_keys.Split(vmap.GetValues().Join(" "), " ");
        {
#line 132
            if (!(vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456))
            {
#line 132
                Lang::SysBreak("Assertion failed: vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456");
            }
        }
#line 133
        ;
#line 135
        amap.Add("abc", 123);
        amap.Add("def", 456);
        {
#line 137
            if (!(amap.GetKeys().Find("abc") == 0))
            {
#line 137
                Lang::SysBreak("Assertion failed: amap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 138
        ;
        {
#line 138
            if (!(amap.GetValues()[0] == 123))
            {
#line 138
                Lang::SysBreak("Assertion failed: amap.GetValues()[0] == 123");
            }
        }
#line 139
        ;
        {
#line 139
            if (!(amap.Find("abc") == 0))
            {
#line 139
                Lang::SysBreak("Assertion failed: amap.Find(\"abc\") == 0");
            }
        }
#line 140
        ;
        {
#line 140
            if (!(amap.Find("dfasgsg") == - 1))
            {
#line 140
                Lang::SysBreak("Assertion failed: amap.Find(\"dfasgsg\") == -1");
            }
        }
#line 141
        ;
#line 141
        Lang::FwdPairPtrIterator < Text::String, int > it = amap.Begin();
        for (int i = 0; i < 2; i ++ )
            {
#line 143
                if (i == 0)
                {
                    {
#line 144
                        if (!(it.Key() == "abc"))
                        {
#line 144
                            Lang::SysBreak("Assertion failed: it.Key() == \"abc\"");
                        }
                    }
#line 145
                    ;
                    {
#line 145
                        if (!(it.Value() == 123))
                        {
#line 145
                            Lang::SysBreak("Assertion failed: it.Value() == 123");
                        }
                    }
#line 146
                    ;
                }
                else 
#line 147
                if (i == 1)
                {
                    {
#line 148
                        if (!(it.Key() == "def"))
                        {
#line 148
                            Lang::SysBreak("Assertion failed: it.Key() == \"def\"");
                        }
                    }
#line 149
                    ;
                    {
#line 149
                        if (!(it.Value() == 456))
                        {
#line 149
                            Lang::SysBreak("Assertion failed: it.Value() == 456");
                        }
                    }
#line 150
                    ;
                }
#line 151
                ++ it;
            }
        {
#line 156
            Shared::Attachable a;
            Shared::Slot s;
            a.Attach(s);
            s.Clear();
        }
#line 163
        TestShared();
        {
#line 166
            Stream::StringStream ss;
            ss << "abc";
        }
#line 170
        Text::String s;
        {
            Stream::FileIn fin;
            {
#line 173
                if (!(fin.Open("/home/sblo/Fuck.cxx")))
                {
#line 173
                    Lang::SysBreak("Assertion failed: fin.Open(\"/home/sblo/Fuck.cxx\")");
                }
            }
#line 174
            ;
#line 174
            s = fin.Get(fin.GetSize());
            int sz = s.GetCount();
        }
#line 178
        Util::Log() << "Lol does this work\?\n";
#line 180
        Stream::FileOut fout;
        fout % r % f % d;
#line 183
        const Container::Vector < Text::String > & cmd = Util::Env::Local().CommandLine();
        for (int i = 0; i < cmd.GetCount(); i ++ )
            {
#line 185
                Text::String arg = cmd[i];
            }
#line 188
        Container::Index < Text::String > files;
        Util::GetDirectoryFiles("/", files);
        {
#line 190
            if (!(files.Find("home") >= 0))
            {
#line 190
                Lang::SysBreak("Assertion failed: files.Find(\"home\") >= 0");
            }
        }
#line 191
        ;
#line 191
        for (int i = 0; i < files.GetCount(); i ++ )
            {
#line 192
                Text::String s = files[i];
                const char * c = s.Begin();
                int len = Lang::StringLength(c);
            }
        {
#line 198
            double d = Math::FastSin(3.14159265358979323846);
            d = Math::FastCos(3.14159265358979323846);
        }
        {
#line 203
            Math::RandomGaussian & gaus = Math::GetRandomGaussian(13);
            double d = gaus;
            d = gaus;
            d = gaus;
            d = gaus;
        }
    };
    
#line 35
    inline App::DerivedBase::DerivedBase()
    :
        a(8)
    {};
    
#line 238
    inline App::Dumb::Dumb()
    {
#line 238
        ;
    };
    
#line 239
    inline App::Dumb::~Dumb()
    {
#line 239
        ;
    };
    
#line 234
    inline App::Dumber::Dumber()
    {
#line 234
        ;
    };
    
#line 23
    inline bool App::TestCmp::operator()(const char& c)
    {
#line 24
        return c == 'c';
    };
    
#line 29
    inline App::VirtualBase::VirtualBase()
    :
        a(3)
    {};
    
};

#endif
