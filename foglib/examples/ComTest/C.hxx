/*!$@FOG@$!
 *	Generated at Sat Sep 26 09:29:26 2020
 *
 *	by fog 0.1.a of 08:09:34 Sep 23 2020
 *
 *	from
 *		../../src/Core/Concurrency.fog
 *		../../src/Core/Core.fog
 *		../../src/Core/Defs.fog
 *		../../src/Core/Environment.fog
 *		../../src/Core/Macros.fog
 *		../../src/Core/Math.fog
 *		../../src/Core/Native.fog
 *		../../src/Core/Stream.fog
 *		CoreTest.mfog
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
#line 10 "../../src/Core/Defs.fog"
        _1 *value;
        
        inline Ptr();
        inline Ptr(_1 *p);
        inline void operator= (_1 *p);
        inline void operator= (const Nuller& p);
        inline operator _1 * () const;
    };
};

namespace C
{
#line 12
    template < class _1 >
    inline Ptr < _1 >::Ptr()
    :
        value(0)
    {};
    
#line 13
    template < class _1 >
    inline Ptr < _1 >::Ptr(_1 *p)
    :
        value(p)
    {};
    
#line 14
    template < class _1 >
    inline void Ptr < _1 >::operator= (_1 *p)
    {
#line 14
        value = p;
    };
    
#line 15
    template < class _1 >
    inline void Ptr < _1 >::operator= (const Nuller& p)
    {
#line 15
        value = 0;
    };
    
#line 16
    template < class _1 >
    inline Ptr < _1 >::operator _1 * () const
    {
#line 16
        return value;
    };
    
};

#endif
