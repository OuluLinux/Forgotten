/*!$@FOG@$!
 *	Generated at Wed Sep 30 06:41:13 2020
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
 *		../../src/Com/Text.fog
 *		/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog
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

#ifndef SHARED_HXX
#include <Shared.hxx>
#endif

namespace Main
{
#line 10 "/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog"
    inline Text::String operator+ (const char *c, const Text::String& l);
    
    class App
    {
#line 17
        Container::VectorMap < int, int > arr;
        
    public:
#line 41
        inline void Run();
        
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
#line 21 "/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog"
            inline bool operator()(const char& c);
        };
        
        struct VirtualBase
        {
#line 30
            int a;
            
#line 27
            inline VirtualBase();
            virtual ~VirtualBase();
        };
        
        struct DerivedBase : public Main::App::VirtualBase
        {
#line 35
            int a;
            
#line 33
            inline DerivedBase();
        };
    };
};

namespace Main
{
#line 10
    inline Text::String operator+ (const char *c, const Text::String& l)
    {
#line 838 "../../src/Com/Text.fog"
        Text::String s(c);
        s.Cat(l);
        return s;
    };
    
#line 41 "/home/sblo/Forgotten/foglib/examples/ComTest/ComTest.mfog"
    inline void App::Run()
    {
#line 42
        Lang::uint64 v = 4294967295U;
        {
#line 43
            if (!(sizeof (v) == 8))
            {
#line 43
                Lang::SysBreak("Assertion failed: sizeof(v) == 8");
            }
        }
#line 44
        ;
        Lang::VoidPtr p;
        {
#line 46
            if (!(p == 0))
            {
#line 46
                Lang::SysBreak("Assertion failed: p == NULL");
            }
        }
#line 47
        ;
        {
#line 48
            if (!(Native::SignificantBits(0x8000) == 16))
            {
#line 48
                Lang::SysBreak("Assertion failed: SignificantBits(0x8000) == 16");
            }
        }
#line 49
        ;
        {
#line 49
            if (!(Native::SignificantBits64(0x8000) == 16))
            {
#line 49
                Lang::SysBreak("Assertion failed: SignificantBits64(0x8000) == 16");
            }
        }
#line 50
        ;
        Hash::Combine ch;
        ch.Put(777999777).Put(123).Put64(0xF0F0F0F0F0F0F0F0);
        Lang::dword hash = ch;
        {
#line 54
            if (!(hash == 1894504625))
            {
#line 54
                Lang::SysBreak("Assertion failed: hash == 1894504625");
            }
        }
#line 55
        ;
#line 55
        int a = 0;
        int b = 1;
        {
#line 57
            if (!(Algorithm::Minimum(a, b) < Algorithm::Maximum(a, b)))
            {
#line 57
                Lang::SysBreak("Assertion failed: Min(a, b) < Max(a, b)");
            }
        }
#line 58
        ;
        int r = Random::Int();
        float f = Random::Float();
        float d = Random::Double();
        int j = d;
#line 65
        const char * test_str = "abcdef";
        int test_strlen = Lang::StringLength(test_str);
        {
#line 67
            if (!(Container::FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2))
            {
#line 67
                Lang::SysBreak("Assertion failed: FindIf(test_str, test_str + test_strlen, TestCmp()) == test_str + 2");
            }
        }
#line 68
        ;
        {
            if (!(Text::String("test") == "test"))
            {
#line 70
                Lang::SysBreak("Assertion failed: String(\"test\") == \"test\"");
            }
        }
#line 71
        ;
        {
#line 71
            if (!(Text::String::DblStr(1.2) == "1.2"))
            {
#line 71
                Lang::SysBreak("Assertion failed: DblStr(1.2) == \"1.2\"");
            }
        }
#line 72
        ;
        {
#line 72
            if (!("abc" + Text::String("def") == "abcdef"))
            {
#line 72
                Lang::SysBreak("Assertion failed: \"abc\" + String(\"def\") == \"abcdef\"");
            }
        }
#line 73
        ;
        {
#line 73
            if (!(Text::String("abc") + "def" == "abcdef"))
            {
#line 73
                Lang::SysBreak("Assertion failed: String(\"abc\") + \"def\" == \"abcdef\"");
            }
        }
#line 74
        ;
        {
#line 74
            if (!(Text::ToString(Text::ToWString < Text::String > ("abc")) == "abc"))
            {
#line 74
                Lang::SysBreak("Assertion failed: ToString(ToWString<String>(\"abc\")) == \"abc\"");
            }
        }
#line 75
        ;
        {
#line 75
            if (!(Text::ToInt < Text::String > ("123") == 123))
            {
#line 75
                Lang::SysBreak("Assertion failed: ToInt<String>(\"123\") == 123");
            }
        }
#line 76
        ;
        {
#line 76
            if (!(Text::ToString(123) == "123"))
            {
#line 76
                Lang::SysBreak("Assertion failed: ToString(123) == \"123\"");
            }
        }
#line 77
        ;
        {
#line 77
            if (!(Text::HexStr((void * )0x123f) == "0x123F"))
            {
#line 77
                Lang::SysBreak("Assertion failed: HexStr((void*)0x123f) == \"0x123F\"");
            }
        }
#line 78
        ;
#line 80
        SomeTuple2 ttt = 
        {
            1,
            1.2
        };
        {
#line 81
            if (!(Text::ToString(ttt) == "1, 1.2"))
            {
#line 81
                Lang::SysBreak("Assertion failed: ToString(ttt) == \"1, 1.2\"");
            }
        }
#line 82
        ;
        SomeRefTuple2 tttref(ttt.a, ttt.b);
        {
#line 84
            if (!(Text::ToString(tttref) == "1, 1.2"))
            {
#line 84
                Lang::SysBreak("Assertion failed: ToString(tttref) == \"1, 1.2\"");
            }
        }
#line 85
        ;
        Container::One < Text::String > onestr;
        onestr.Create();
        *onestr = "hello";
        {
#line 89
            if (!(*onestr == "hello"))
            {
#line 89
                Lang::SysBreak("Assertion failed: *onestr == \"hello\"");
            }
        }
#line 90
        ;
        Container::One < VirtualBase > onebase;
        onebase.CreateDerived < DerivedBase > ();
        {
#line 93
            if (!(onebase.GetDerived < DerivedBase > ()-> a == 8))
            {
#line 93
                Lang::SysBreak("Assertion failed: onebase.GetDerived<DerivedBase>()->a == 8");
            }
        }
#line 94
        ;
        Container::FutureOne < Text::String > fone;
        fone = new Text::String;
        fone.Wait();
#line 99
        Container::Vector < Text::String > strvec;
        Container::Array < Text::String > strarr;
        for (int i = 0; i < 3; i ++ )
            {
#line 102
                strvec << Text::String::IntStr(i);
                strarr << Text::String::IntStr(i);
            }
        for (int i = 0; i < 3; i ++ )
            {
                {
#line 106
                    if (!(strvec[i] == strarr[i]))
                    {
#line 106
                        Lang::SysBreak("Assertion failed: strvec[i] == strarr[i]");
                    }
                }
#line 107
                ;
            }
        Container::Index < Text::String > stridx;
        stridx.Add("abc");
        {
#line 111
            if (!(stridx.GetCount() == 1))
            {
#line 111
                Lang::SysBreak("Assertion failed: stridx.GetCount() == 1");
            }
        }
#line 112
        ;
        {
#line 112
            if (!(stridx.Find("abc") == 0))
            {
#line 112
                Lang::SysBreak("Assertion failed: stridx.Find(\"abc\") == 0");
            }
        }
#line 113
        ;
#line 113
        stridx.Add("def");
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
        {
#line 115
            if (!(stridx.Find("def") == 1))
            {
#line 115
                Lang::SysBreak("Assertion failed: stridx.Find(\"def\") == 1");
            }
        }
#line 116
        ;
#line 118
        Container::VectorMap < Text::String, int > vmap;
        Container::ArrayMap < Text::String, int > amap;
#line 121
        vmap.Add("abc", 123);
        vmap.Add("def", 456);
        {
#line 123
            if (!(vmap.GetKeys().Find("abc") == 0))
            {
#line 123
                Lang::SysBreak("Assertion failed: vmap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 124
        ;
        {
#line 124
            if (!(vmap.GetValues()[0] == 123))
            {
#line 124
                Lang::SysBreak("Assertion failed: vmap.GetValues()[0] == 123");
            }
        }
#line 125
        ;
        {
#line 125
            if (!(vmap.Find("abc") == 0))
            {
#line 125
                Lang::SysBreak("Assertion failed: vmap.Find(\"abc\") == 0");
            }
        }
#line 126
        ;
        {
#line 126
            if (!(vmap.Find("dfasgsg") == - 1))
            {
#line 126
                Lang::SysBreak("Assertion failed: vmap.Find(\"dfasgsg\") == -1");
            }
        }
#line 127
        ;
        {
#line 127
            if (!(vmap.GetValues().Join() == "123456"))
            {
#line 127
                Lang::SysBreak("Assertion failed: vmap.GetValues().Join() == \"123456\"");
            }
        }
#line 128
        ;
#line 128
        Container::Vector < int > vmap_keys;
        vmap_keys.Split(vmap.GetValues().Join(" "), " ");
        {
#line 130
            if (!(vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456))
            {
#line 130
                Lang::SysBreak("Assertion failed: vmap_keys.GetCount() == 2 && vmap_keys[0] == 123 && vmap_keys[1] == 456");
            }
        }
#line 131
        ;
#line 133
        amap.Add("abc", 123);
        amap.Add("def", 456);
        {
#line 135
            if (!(amap.GetKeys().Find("abc") == 0))
            {
#line 135
                Lang::SysBreak("Assertion failed: amap.GetKeys().Find(\"abc\") == 0");
            }
        }
#line 136
        ;
        {
#line 136
            if (!(amap.GetValues()[0] == 123))
            {
#line 136
                Lang::SysBreak("Assertion failed: amap.GetValues()[0] == 123");
            }
        }
#line 137
        ;
        {
#line 137
            if (!(amap.Find("abc") == 0))
            {
#line 137
                Lang::SysBreak("Assertion failed: amap.Find(\"abc\") == 0");
            }
        }
#line 138
        ;
        {
#line 138
            if (!(amap.Find("dfasgsg") == - 1))
            {
#line 138
                Lang::SysBreak("Assertion failed: amap.Find(\"dfasgsg\") == -1");
            }
        }
#line 139
        ;
#line 139
        Lang::FwdPairPtrIterator < Text::String, int > it = amap.Begin();
        for (int i = 0; i < 2; i ++ )
            {
#line 141
                if (i == 0)
                {
                    {
#line 142
                        if (!(it.Key() == "abc"))
                        {
#line 142
                            Lang::SysBreak("Assertion failed: it.Key() == \"abc\"");
                        }
                    }
#line 143
                    ;
                    {
#line 143
                        if (!(it.Value() == 123))
                        {
#line 143
                            Lang::SysBreak("Assertion failed: it.Value() == 123");
                        }
                    }
#line 144
                    ;
                }
                else 
#line 145
                if (i == 1)
                {
                    {
#line 146
                        if (!(it.Key() == "def"))
                        {
#line 146
                            Lang::SysBreak("Assertion failed: it.Key() == \"def\"");
                        }
                    }
#line 147
                    ;
                    {
#line 147
                        if (!(it.Value() == 456))
                        {
#line 147
                            Lang::SysBreak("Assertion failed: it.Value() == 456");
                        }
                    }
#line 148
                    ;
                }
#line 149
                ++ it;
            }
        {
#line 154
            Shared::Attachable a;
            Shared::Slot s;
            a.Attach(s);
            s.Clear();
        }
    };
    
#line 33
    inline App::DerivedBase::DerivedBase()
    :
        a(8)
    {};
    
#line 21
    inline bool App::TestCmp::operator()(const char& c)
    {
#line 22
        return c == 'c';
    };
    
#line 27
    inline App::VirtualBase::VirtualBase()
    :
        a(3)
    {};
    
};

#endif
