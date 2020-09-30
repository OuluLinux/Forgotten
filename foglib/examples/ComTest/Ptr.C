/*!$@FOG@$!
 *	Generated at Wed Sep 30 06:32:22 2020
 *
 *	by fog 0.1.a of 12:17:36 Sep 29 2020
 *
 *	from
 *		../../src/Com/Abstract.fog
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Container.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Lang.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Meta.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/Prim.fog
 *		../../src/Com/Random.fog
 *		../../src/Com/Shared.fog
 *		../../src/Com/Text.fog
 *		ComTest.mfog
 */

#ifndef PTR_C
#define PTR_C

#include <new>

#ifndef PTR_H
#include <Ptr.H>
#endif

#line 162 "../../src/Com/Shared.fog"
template < class _1 >
Ptr < _1 >::Ptr()
:
    r(0),
    o(0)
{};

#line 163
template < class _1 >
Ptr < _1 >::Ptr(const Ptr& o)
:
    r(0),
    o(0)
{
#line 163
    *this = o;
};

#line 171
template < class _1 >
void Ptr < _1 >::operator= (const Ptr < _1 > & s)
{
#line 171
    if (r == s.r)
#line 171
        return;
#line 171
    SetPtr(s.o, s.r);
};

#line 179
template < class _1 >
bool Ptr < _1 >::operator== (const Ptr& s) const
{
#line 179
    if (r && s.r)
#line 179
        return o == s.o;
#line 179
    return false;
};

#line 180
template < class _1 >
template < class _2 >
Ptr < _2 > Ptr < _1 >::As()
{
#line 181
    static_assert(std::is_base_of < _1, _2 > () || std::is_base_of < _2, _1 > (), "K -> T or T -> K inheritance is required");
#line 183
    if (o)
    {
#line 184
        _2 * ptr = dynamic_cast< _2 * >(o);
        if (ptr)
        {
#line 186
            Ptr < _2 > s;
            s.SetPtr(ptr, r);
            return s;
        }
    }
    return Ptr < _2 > ();
};

#line 170
template < class _1 >
void Ptr < _1 >::Clear()
{
#line 170
    if (r)
    {
#line 170
        r -> Dec();
#line 170
        r = 0;
#line 170
        o = 0;
    }
};

#line 168
template < class _1 >
void Ptr < _1 >::Create()
{
#line 168
    Clear();
#line 168
    r = new RefTemplate < _1 > ;
#line 168
    o = new _1;
#line 168
    r -> obj = o;
};

#line 169
template < class _1 >
template < class _2 >
void Ptr < _1 >::CreateAbstract()
{
#line 169
    Clear();
#line 169
    r = new RefTemplate < _1 > ;
#line 169
    o = new _2;
#line 169
    r -> obj = o;
};

#line 193
template < class _1 >
void Ptr < _1 >::SetPtr(_1 *o, RefBase *r)
{
#line 194
    Ptr < _1 > tmp;
#line 194
    Container::Swap(*this, tmp);
    this -> o = o;
    this -> r = r;
    if (r)
#line 197
        r -> Inc();
};

#line 199
template < class _1 >
Ptr < _1 > & Ptr < _1 >::WrapObject(_1 *obj)
{
#line 200
    Clear();
    if (obj)
    {
#line 202
        r = new RefTemplate < _1 > ;
        r -> obj = obj;
        o = obj;
    }
    return *this;
};

#endif
