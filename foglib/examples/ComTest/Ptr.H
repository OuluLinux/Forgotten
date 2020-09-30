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

#ifndef PTR_H
#define PTR_H

#include <new>

namespace {
class RefBase;
}

template < class _1 >
class Ptr
{
protected:
#line 158 "../../src/Com/Shared.fog"
    RefBase *r;
    _1 *o;
    
public:
    Ptr();
    Ptr(const Ptr& o);
#line 166
    inline ~Ptr();
#line 177
    inline _1& operator*() const;
#line 173
    inline _1 *operator-> ();
    inline _1 *operator-> () const;
#line 171
    void operator= (const Ptr < _1 > & s);
#line 179
    bool operator== (const Ptr& s) const;
#line 178
    inline bool operator== (const _1 *ptr) const;
#line 176
    inline operator bool() const;
#line 180
    template < class _2 >
    Ptr < _2 > As();
#line 170
    void Clear();
#line 168
    void Create();
    template < class _2 >
    void CreateAbstract();
#line 175
    inline _1 *Get() const;
#line 208
    inline const RefBase *GetBase() const;
#line 172
    inline bool IsEmpty() const;
#line 193
    void SetPtr(_1 *o, RefBase *r);
#line 199
    Ptr < _1 > & WrapObject(_1 *obj);
};

#line 166
template < class _1 >
inline Ptr < _1 >::~Ptr()
{
#line 166
    Clear();
};

#line 177
template < class _1 >
inline _1& Ptr < _1 >::operator*() const
{
#line 177
    return *Get();
};

#line 173
template < class _1 >
inline _1 *Ptr < _1 >::operator-> ()
{
#line 173
    if (r)
#line 173
        return o;
#line 173
    return 0;
};

#line 174
template < class _1 >
inline _1 *Ptr < _1 >::operator-> () const
{
#line 174
    if (r)
#line 174
        return o;
#line 174
    return 0;
};

#line 178
template < class _1 >
inline bool Ptr < _1 >::operator== (const _1 *ptr) const
{
#line 178
    if (r)
#line 178
        return o == ptr;
#line 178
    return false;
};

#line 176
template < class _1 >
inline Ptr < _1 >::operator bool() const
{
#line 176
    return !IsEmpty();
};

#line 175
template < class _1 >
inline _1 *Ptr < _1 >::Get() const
{
#line 175
    if (r)
#line 175
        return o;
#line 175
    return 0;
};

#line 208
template < class _1 >
inline const RefBase *Ptr < _1 >::GetBase() const
{
#line 208
    return r;
};

#line 172
template < class _1 >
inline bool Ptr < _1 >::IsEmpty() const
{
#line 172
    return r == 0;
};

#endif
