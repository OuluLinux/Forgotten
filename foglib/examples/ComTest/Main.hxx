/*!$@FOG@$!
 *	Generated at Wed Sep 30 12:25:17 2020
 *
 *	by fog 0.1.a of 12:17:36 Sep 29 2020
 *
 *	from
 *		../../src/Com/Abstract.fog
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Container.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Lang.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Meta.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/Prim.fog
 *		../../src/Com/Random.fog
 *		../../src/Com/Shared.fog
 *		../../src/Com/Stream.fog
 *		../../src/Com/Text.fog
 *		ComTest.mfog
 */

#ifndef MAIN_HXX
#define MAIN_HXX

#include <new>

#ifndef CONTAINER_HXX
#include <Container.hxx>
#endif

struct NamespaceInterfaceLinker
{
};

#ifndef STREAM_HXX
#include <Stream.hxx>
#endif
#ifndef SHARED_HXX
#include <Shared.hxx>
#endif

namespace Main
{
#line 11 "ComTest.mfog"
    inline Text::String operator+ (const char *c, const Text::String& l);
    
    class App
    {
#line 18
        Container::VectorMap < int, int > arr;
        
    public:
#line 42
        inline void Run();
        
#line 195
        void TestShared();
        
        struct Dumber
        {
#line 187
            inline Dumber();
            virtual ~Dumber();
        };
        
        struct Dumb : public Main::App::Dumber
        {
#line 191
            inline Dumb();
            inline ~Dumb();
        };
        
        struct SomeRefTuple2
        {
#line 70 "../../src/Com/Meta.fog"
            int& a;
            double& b;
            
            SomeRefTuple2(int& a, double& b);
            Text::String ToString() const;
        };
        
        struct SomeTuple2
        {
#line 51
            int a;
            double b;
            
            Text::String ToString() const;
        };
        
        struct TestCmp
        {
#line 22 "ComTest.mfog"
            inline bool operator()(const char& c);
        };
        
        struct VirtualBase
        {
#line 31
            int a;
            
#line 28
            inline VirtualBase();
            virtual ~VirtualBase();
        };
        
        struct DerivedBase : public Main::App::VirtualBase
        {
#line 36
            int a;
            
#line 34
            inline DerivedBase();
        };
    };
};

namespace Main
{
#line 11
    inline Text::String operator+ (const char *c, const Text::String& l)
    {
#line 838 "../../src/Com/Text.fog"
        Text::String s(c);
        s.Cat(l);
        return s;
    };
    
#line 42 "ComTest.mfog"
    inline void App::Run()
    {
#line 43
        Lang::uint64 v = 4294967295U;
        {
#line 44
            if (!(sizeof (v) == 8))
            {
#line 44
                Lang::SysBreak("Assertion failed: sizeof(v) == 8");
            }
        }
#line 45
        ;
        Lang::VoidPtr p;
        {
#line 47
            if (!(p == 0))
            {
#line 47
                Lang::SysBreak("Assertion failed: p == NULL");
            }
        }
#line 48
        ;
        {
#line 49
            if (!(Native::SignificantBits(0x8000) == 16))
            {
#line 49
                Lang::SysBreak("Assertion failed: SignificantBits(0x8000) == 16");
            }
        }
#line 50
        ;
        {
#line 50
            if (!(Native::SignificantBits64(0x8000) == 16))
            {
#line 50
                Lang::SysBreak("Assertion failed: SignificantBits64(0x8000) == 16");
            }
        }
#line 51
        ;
        Hash::Combine ch;
        ch.Put(777999777).Put(123).Put64(0xF0F0F0F0F0F0F0F0);
        Lang::dword hash = ch;
        {
#line 55
            if (!(hash == 1894504625))
            {
#line 55
                Lang::SysBreak("Assertion failed: hash == 1894504625");
            }
        }
#line 56
        ;
#line 56
        int a = 0;
        int b = 1;
        {
#line 58
            if (!(Algorithm::Minimum(a, b) < Algorithm::Maximum(a, b)))
            {
#line 58
                Lang::SysBreak("Assertion failed: Min(a, b) < Max(a, b)");
            }
        }
#line 59
        ;
        int r = Random::Int();
        float f = Random::Float();
        float d = Random::Double();
        int j = d;
#line 66
        const char * test_str = "abcdef";
        int test_strlen = Lang::StringLength(test_str);
        {
#line 68
            if (!(Container::FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2))
            {
#line 68
                Lang::SysBreak("Assertion failed: FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2");
            }
        }
#line 69
        ;
        {
            if (!(Text::String("test") == "test"))
            {
#line 71
                Lang::SysBreak("Assertion failed: String(\"test\") == \"test\"");
            }
        }
#line 72
        ;
        {
#line 72
            if (!(Text::String::DblStr(1.2) == "1.2"))
            {
#line 72
                Lang::SysBreak("Assertion failed: DblStr(1.2) == \"1.2\"");
            }
        }
#line 73
        ;
        {
#line 73
            if (!("abc" + Text::String("def") == "abcdef"))
            {
#line 73
                Lang::SysBreak("Assertion failed: \"abc\" + String(\"def\") == \"abcdef\"");
            }
        }
#line 74
        ;
        {
#line 74
            if (!(Text::String("abc") + "def" == "abcdef"))
            {
#line 74
                Lang::SysBreak("Assertion failed: String(\"abc\") + \"def\" == \"abcdef\"");
            }
        }
#line 75
        ;
        {
#line 75
            if (!(Text::ToString(Text::ToWString < Text::String > ("abc")) == "abc"))
            {
#line 75
                Lang::SysBreak("Assertion failed: ToString(ToWString<String>(\"abc\")) == \"abc\"");
            }
        }
#line 76
        ;
        {
#line 76
            if (!(Text::ToInt < Text::String > ("123") == 123))
            {
#line 76
                Lang::SysBreak("Assertion failed: ToInt<String>(\"123\") == 123");
            }
        }
#line 77
        ;
        {
#line 77
            if (!(Text::ToString(123) == "123"))
            {
#line 77
                Lang::SysBreak("Assertion failed: ToString(123) == \"123\"");
            }
        }
#line 78
        ;
        {
#line 78
            if (!(Text::HexStr((void * )0x123f) == "0x123F"))
            {
#line 78
                Lang::SysBreak("Assertion failed: HexStr((void*)0x123f) == \"0x123F\"");
            }
        }
#line 79
        ;
#line 81
        SomeTuple2 ttt = 
        {
            1,
            1.2
        };
        {
#line 82
            if (!(Text::ToString(ttt) == "1, 1.2"))
            {
#line 82
                Lang::SysBreak("Assertion failed: ToString(ttt) == \"1, 1.2\"");
            }
        }
#line 83
        ;
        SomeRefTuple2 tttref(ttt.a, ttt.b);
        {
#line 85
            if (!(Text::ToString(tttref) == "1, 1.2"))
            {
#line 85
                Lang::SysBreak("Assertion failed: ToString(tttref) == \"1, 1.2\"");
            }
        }
#line 86
        ;
        Container::One < Text::String > onestr;
        onestr.Create();
        *onestr = "hello";
        {
#line 90
            if (!(*onestr == "hello"))
            {
#line 90
                Lang::SysBreak("Assertion failed: *onestr == \"hello\"");
            }
        }
#line 91
        ;
        Container::One < VirtualBase > onebase;
        onebase.CreateDerived < DerivedBase > ();
        {
#line 94
            if (!(onebase.GetDerived < DerivedBase > ()-> a == 8))
            {
#line 94
                Lang::SysBreak("Assertion failed: onebase.GetDerived<DerivedBase>()->a == 8");
            }
        }
#line 95
        ;
        Container::FutureOne < Text::String > fone;
        fone = new Text::String;
        fone.Wait();
#line 100
        Container::Vector < Text::String > strvec;
        Container::Array < Text::String > strarr;
        for (int i = 0; i < 3; i ++ )
            {
#line 103
                strvec << Text::String::IntStr(i);
                strarr << Text::String::IntStr(i);
            }
        for (int i = 0; i < 3; i ++ )
            {
                {
#line 107
                    if (!(strvec[i] == strarr[i]))
                    {
#line 107
                        Lang::SysBreak("Assertion failed: strvec[i] == strarr[i]");
                    }
                }
#line 108
                ;
            }
        Container::Index < Text::String > stridx;
        stridx.Add("abc");
        {
#line 112
            if (!(stridx.GetCount() == 1))
            {
#line 112
                Lang::SysBreak("Assertion failed: stridx.GetCount() == 1");
            }
        }
#line 113
        ;
        {
#line 113
            if (!(stridx.Find("abc") == 0))
            {
#line 113
                Lang::SysBreak("Assertion failed: stridx.Find(\"abc\") == 0");
            }
        }
#line 114
        ;
#line 114
        stridx.Add("def");
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
        {
#line 116
            if (!(stridx.Find("def") == 1))
            {
#line 116
                Lang::SysBreak("Assertion failed: stridx.Find(\"def\") == 1");
            }
        }
#line 117
        ;
#line 119
        Container::VectorMap < Text::String, int > vmap;
        Container::ArrayMap < Text::String, int > amap;
#line 122
        vmap.Add("abc", 123);
        vmap.Add("def", 456);
        {
#line 124
            if (!(vmap.GetKeys().Find("abc") == 0))
            {
#line 124
                Lang::SysBreak("Assertion failed: vmap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 125
        ;
        {
#line 125
            if (!(vmap.GetValues()[0] == 123))
            {
#line 125
                Lang::SysBreak("Assertion failed: vmap.GetValues()[0] == 123");
            }
        }
#line 126
        ;
        {
#line 126
            if (!(vmap.Find("abc") == 0))
            {
#line 126
                Lang::SysBreak("Assertion failed: vmap.Find(\"abc\") == 0");
            }
        }
#line 127
        ;
        {
#line 127
            if (!(vmap.Find("dfasgsg") == - 1))
            {
#line 127
                Lang::SysBreak("Assertion failed: vmap.Find(\"dfasgsg\") == -1");
            }
        }
#line 128
        ;
        {
#line 128
            if (!(vmap.GetValues().Join() == "123456"))
            {
#line 128
                Lang::SysBreak("Assertion failed: vmap.GetValues().Join() == \"123456\"");
            }
        }
#line 129
        ;
#line 129
        Container::Vector < int > vmap_keys;
        vmap_keys.Split(vmap.GetValues().Join(" "), " ");
        {
#line 131
            if (!(vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456))
            {
#line 131
                Lang::SysBreak("Assertion failed: vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456");
            }
        }
#line 132
        ;
#line 134
        amap.Add("abc", 123);
        amap.Add("def", 456);
        {
#line 136
            if (!(amap.GetKeys().Find("abc") == 0))
            {
#line 136
                Lang::SysBreak("Assertion failed: amap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 137
        ;
        {
#line 137
            if (!(amap.GetValues()[0] == 123))
            {
#line 137
                Lang::SysBreak("Assertion failed: amap.GetValues()[0] == 123");
            }
        }
#line 138
        ;
        {
#line 138
            if (!(amap.Find("abc") == 0))
            {
#line 138
                Lang::SysBreak("Assertion failed: amap.Find(\"abc\") == 0");
            }
        }
#line 139
        ;
        {
#line 139
            if (!(amap.Find("dfasgsg") == - 1))
            {
#line 139
                Lang::SysBreak("Assertion failed: amap.Find(\"dfasgsg\") == -1");
            }
        }
#line 140
        ;
#line 140
        Lang::FwdPairPtrIterator < Text::String, int > it = amap.Begin();
        for (int i = 0; i < 2; i ++ )
            {
#line 142
                if (i == 0)
                {
                    {
#line 143
                        if (!(it.Key() == "abc"))
                        {
#line 143
                            Lang::SysBreak("Assertion failed: it.Key() == \"abc\"");
                        }
                    }
#line 144
                    ;
                    {
#line 144
                        if (!(it.Value() == 123))
                        {
#line 144
                            Lang::SysBreak("Assertion failed: it.Value() == 123");
                        }
                    }
#line 145
                    ;
                }
                else 
#line 146
                if (i == 1)
                {
                    {
#line 147
                        if (!(it.Key() == "def"))
                        {
#line 147
                            Lang::SysBreak("Assertion failed: it.Key() == \"def\"");
                        }
                    }
#line 148
                    ;
                    {
#line 148
                        if (!(it.Value() == 456))
                        {
#line 148
                            Lang::SysBreak("Assertion failed: it.Value() == 456");
                        }
                    }
#line 149
                    ;
                }
#line 150
                ++ it;
            }
        {
#line 155
            Shared::Attachable a;
            Shared::Slot s;
            a.Attach(s);
            s.Clear();
        }
#line 162
        TestShared();
#line 164
        Stream::FileOut fout;
        fout % r % f % d;
    };
    
#line 34
    inline App::DerivedBase::DerivedBase()
    :
        a(8)
    {};
    
#line 191
    inline App::Dumb::Dumb()
    {
#line 191
        ;
    };
    
#line 192
    inline App::Dumb::~Dumb()
    {
#line 192
        ;
    };
    
#line 187
    inline App::Dumber::Dumber()
    {
#line 187
        ;
    };
    
#line 22
    inline bool App::TestCmp::operator()(const char& c)
    {
#line 23
        return c == 'c';
    };
    
#line 28
    inline App::VirtualBase::VirtualBase()
    :
        a(3)
    {};
    
};

#endif
