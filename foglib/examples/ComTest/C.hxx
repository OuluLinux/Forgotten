/*!$@FOG@$!
 *	Generated at Sat Sep 26 10:29:56 2020
 *
 *	by fog 0.1.a of 08:09:34 Sep 23 2020
 *
 *	from
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Concurrency.fog
 *		../../src/Com/Defs.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Math.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/Stream.fog
 *		ComTest.mfog
 */

#ifndef C_HXX
#define C_HXX

namespace C
{
    struct Nuller
    {
    };
    
    template < class _1 >
    struct Ptr
    {
#line 23 "../../src/Com/Defs.fog"
        _1 *value;
        
        inline Ptr();
        inline Ptr(_1 *p);
        inline void operator= (_1 *p);
        inline void operator= (const Nuller& p);
#line 31
        inline bool operator== (const Nuller& p) const;
#line 30
        inline bool operator== (const Ptr& p) const;
#line 29
        inline operator _1 * () const;
#line 34
        inline unsigned long long Int() const;
    };
};

namespace C
{
#line 25
    template < class _1 >
    inline Ptr < _1 >::Ptr()
    :
        value(0)
    {};
    
#line 26
    template < class _1 >
    inline Ptr < _1 >::Ptr(_1 *p)
    :
        value(p)
    {};
    
#line 27
    template < class _1 >
    inline void Ptr < _1 >::operator= (_1 *p)
    {
#line 27
        value = p;
    };
    
#line 28
    template < class _1 >
    inline void Ptr < _1 >::operator= (const Nuller& p)
    {
#line 28
        value = 0;
    };
    
    template < class _1 >
    inline bool Ptr < _1 >::operator== (const Nuller& p) const
    {
#line 31
        return value == 0;
    };
    
#line 30
    template < class _1 >
    inline bool Ptr < _1 >::operator== (const Ptr& p) const
    {
#line 30
        return value == p.value;
    };
    
#line 29
    template < class _1 >
    inline Ptr < _1 >::operator _1 * () const
    {
#line 29
        return value;
    };
    
#line 34
    template < class _1 >
    inline unsigned long long Ptr < _1 >::Int() const
    {
#line 34
        return(unsigned long long) value;
    };
    
};

#endif
