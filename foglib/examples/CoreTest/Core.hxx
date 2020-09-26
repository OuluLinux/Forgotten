/*!$@FOG@$!
 *	Generated at Sat Sep 26 06:11:06 2020
 *
 *	by fog 0.1.a of 08:09:34 Sep 23 2020
 *
 *	from
 *		../../src/Core/Core.fog
 *		../../src/Core/Defs.fog
 *		../../src/Core/Stream.fog
 *		../../src/Core/String.fog
 *		CoreTest.mfog
 */

#ifndef CORE_HXX
#define CORE_HXX

struct Nuller;

template < class _1 >
struct CPtr
{
#line 65 "../../src/Core/Defs.fog"
    _1 *value;
    
    inline CPtr();
    inline CPtr(_1 *p);
#line 70
    inline void operator= (Nuller p);
#line 69
    inline void operator= (_1 *p);
#line 71
    inline operator _1 * () const;
};

struct Console
{
#line 7 "../../src/Core/Stream.fog"
    static int Get(char *buf, int size);
    static void Put(const char *msg);
};

namespace Core
{
};

struct Nuller
{
};

#line 2 "../../src/Core/String.fog"
typedef const char ConstChar;

class String
{
#line 142
    bool is_big;
    
public:
#line 148
    String();
    inline String(const char *c);
#line 158
    inline operator ConstChar * () const;
#line 153
    inline ConstChar *Get() const;
    
    struct Data
    {
#line 134
        char *data;
    };
    
    union
    {
    public:
#line 139
        char data[8];
        Data *ptr;
    };
};

namespace
{
#line 81 "../../src/Core/Defs.fog"
    extern Nuller Null;
};

namespace
{
#line 88
    typedef unsigned char Byte;
    
#line 89
    extern Byte ____unused_Byte;
};

namespace
{
#line 93
    typedef CPtr < const void > CONST_VOID_PTR;
    
#line 94
    extern CONST_VOID_PTR ____unused_CONST_VOID_PTR;
};

namespace
{
#line 93
    typedef CPtr < const char > CString;
    
#line 94
    extern CString ____unused_CString;
};

namespace
{
#line 88
    typedef unsigned long DWORD;
    
#line 89
    extern DWORD ____unused_DWORD;
};

namespace
{
#line 93
    typedef CPtr < void > VOID_PTR;
    
#line 94
    extern VOID_PTR ____unused_VOID_PTR;
};

namespace
{
#line 88
    typedef unsigned char byte;
    
#line 89
    extern byte ____unused_byte;
};

namespace
{
#line 88
    typedef unsigned int uint32;
#line 88
    typedef uint32 dword;
    
#line 89
    extern dword ____unused_dword;
};

namespace
{
#line 88
    typedef short int16;
    
#line 89
    extern int16 ____unused_int16;
};

namespace
{
#line 88
    typedef int int32;
    
#line 89
    extern int32 ____unused_int32;
};

namespace
{
#line 88
    typedef long long int64;
    
#line 89
    extern int64 ____unused_int64;
};

namespace
{
#line 88
    typedef char int8;
    
#line 89
    extern int8 ____unused_int8;
};

namespace
{
#line 88
    typedef unsigned long long uint64;
#line 88
    typedef uint64 qword;
    
#line 89
    extern qword ____unused_qword;
};

namespace
{
#line 88
    typedef unsigned short uint16;
    
#line 89
    extern uint16 ____unused_uint16;
#line 89
    extern uint32 ____unused_uint32;
#line 89
    extern uint64 ____unused_uint64;
};

namespace
{
#line 88
    typedef uint16 word;
    
#line 89
    extern word ____unused_word;
    
#line 97
    void Break(const char *msg);
#line 118
    template < class _1 >
    inline void IGNORE_RESULT(const _1& );
};

#line 67
template < class _1 >
inline CPtr < _1 >::CPtr()
:
    value(0)
{};

#line 68
template < class _1 >
inline CPtr < _1 >::CPtr(_1 *p)
:
    value(p)
{};

#line 70
template < class _1 >
inline void CPtr < _1 >::operator= (Nuller p)
{
#line 70
    value = 0;
};

#line 69
template < class _1 >
inline void CPtr < _1 >::operator= (_1 *p)
{
#line 69
    value = p;
};

#line 71
template < class _1 >
inline CPtr < _1 >::operator _1 * () const
{
#line 71
    return value;
};

#line 149 "../../src/Core/String.fog"
inline String::String(const char *c)
:
    is_big(false)
{};

#line 158
inline String::operator ConstChar * () const
{
#line 158
    return Get();
};

#line 153
inline ConstChar *String::Get() const
{
#line 154
    if (is_big)
#line 154
        return ptr -> data;
    else
#line 155
        return&data[0];
};

namespace
{
#line 118 "../../src/Core/Defs.fog"
    template < class _1 >
    inline void IGNORE_RESULT(const _1& ) {};
    
};

#endif
