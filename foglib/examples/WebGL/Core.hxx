/*!$@FOG@$!
 *	Generated at Thu Sep 24 03:04:12 2020
 *
 *	by fog 0.1.a of 08:09:34 Sep 23 2020
 *
 *	from
 *		../../src/Core/Core.fog
 *		../../src/Core/Stream.fog
 *		../../src/Core/String.fog
 *		../../src/MachCore/MachCore.fog
 *		../../src/MachLib/MachLib.fog
 *		../../src/ManyCore/ManyCore.fog
 *		../../src/ManyCore/Program.fog
 *		../../src/Math/Math.fog
 *		/home/sblo/Forgotten/prototyping/FogLib/examples/WebGL/WebGL.mfog
 */

#ifndef CORE_HXX
#define CORE_HXX

struct Console
{
#line 7 "../../src/Core/Stream.fog"
    static int Get(char *buf, int size);
    static void Put(const char *msg);
};

namespace Core
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

#line 149
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

#endif
