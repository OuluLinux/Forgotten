/*!$@FOG@$!
 *	Generated at Mon Sep 28 10:34:35 2020
 *
 *	by fog 0.1.a of 08:56:34 Sep 28 2020
 *
 *	from
 *		../../src/Com/Algorithm.fog
 *		../../src/Com/Com.fog
 *		../../src/Com/Defs.fog
 *		../../src/Com/Environment.fog
 *		../../src/Com/Hash.fog
 *		../../src/Com/Lang.fog
 *		../../src/Com/Macros.fog
 *		../../src/Com/Meta.fog
 *		../../src/Com/Native.fog
 *		../../src/Com/String.fog
 *		../../src/Com/Vector.fog
 *		ComTest.mfog
 */

#ifndef C_CXX
#define C_CXX

#include <new>

#ifndef C_HXX
#include <C.hxx>
#endif

namespace C
{
#line 129 "../../src/Com/Lang.fog"
    template < class _1 >
    BwdIterator < _1 >::BwdIterator(const BwdIterator& it)
    :
        kit(NULL)
    {
#line 129
        *this = it;
    };
    
#line 131
    template < class _1 >
    BwdIterator < _1 > & BwdIterator < _1 >::operator++ ()
    {
#line 131
        kit += 1;
#line 131
        return *this;
    };
    
#line 133
    template < class _1 >
    void BwdIterator < _1 >::operator-- (int i)
    {
#line 133
        kit -= 1;
    };
    
#line 169
    template < class _1 >
    BwdPtrIterator < _1 >::BwdPtrIterator(const BwdPtrIterator& it)
    :
        kit(NULL)
    {
#line 169
        *this = it;
    };
    
#line 171
    template < class _1 >
    BwdPtrIterator < _1 > & BwdPtrIterator < _1 >::operator++ ()
    {
#line 171
        kit += 1;
#line 171
        return *this;
    };
    
#line 172
    template < class _1 >
    void BwdPtrIterator < _1 >::operator-- (int i)
    {
#line 172
        kit -= 1;
    };
    
#line 129
    template < class _1 >
    ConstBwdIterator < _1 >::ConstBwdIterator(const ConstBwdIterator& it)
    :
        kit(NULL)
    {
#line 129
        *this = it;
    };
    
#line 131
    template < class _1 >
    ConstBwdIterator < _1 > & ConstBwdIterator < _1 >::operator++ ()
    {
#line 131
        kit += 1;
#line 131
        return *this;
    };
    
#line 133
    template < class _1 >
    void ConstBwdIterator < _1 >::operator-- (int i)
    {
#line 133
        kit -= 1;
    };
    
#line 169
    template < class _1 >
    ConstBwdPtrIterator < _1 >::ConstBwdPtrIterator(const ConstBwdPtrIterator& it)
    :
        kit(NULL)
    {
#line 169
        *this = it;
    };
    
#line 171
    template < class _1 >
    ConstBwdPtrIterator < _1 > & ConstBwdPtrIterator < _1 >::operator++ ()
    {
#line 171
        kit += 1;
#line 171
        return *this;
    };
    
#line 172
    template < class _1 >
    void ConstBwdPtrIterator < _1 >::operator-- (int i)
    {
#line 172
        kit -= 1;
    };
    
#line 129
    template < class _1 >
    ConstFwdIterator < _1 >::ConstFwdIterator(const ConstFwdIterator& it)
    :
        kit(NULL)
    {
#line 129
        *this = it;
    };
    
#line 131
    template < class _1 >
    ConstFwdIterator < _1 > & ConstFwdIterator < _1 >::operator++ ()
    {
#line 131
        kit += 1;
#line 131
        return *this;
    };
    
#line 133
    template < class _1 >
    void ConstFwdIterator < _1 >::operator-- (int i)
    {
#line 133
        kit -= 1;
    };
    
#line 169
    template < class _1 >
    ConstFwdPtrIterator < _1 >::ConstFwdPtrIterator(const ConstFwdPtrIterator& it)
    :
        kit(NULL)
    {
#line 169
        *this = it;
    };
    
#line 171
    template < class _1 >
    ConstFwdPtrIterator < _1 > & ConstFwdPtrIterator < _1 >::operator++ ()
    {
#line 171
        kit += 1;
#line 171
        return *this;
    };
    
#line 172
    template < class _1 >
    void ConstFwdPtrIterator < _1 >::operator-- (int i)
    {
#line 172
        kit -= 1;
    };
    
#line 129
    template < class _1 >
    FwdIterator < _1 >::FwdIterator(const FwdIterator& it)
    :
        kit(NULL)
    {
#line 129
        *this = it;
    };
    
#line 131
    template < class _1 >
    FwdIterator < _1 > & FwdIterator < _1 >::operator++ ()
    {
#line 131
        kit += 1;
#line 131
        return *this;
    };
    
#line 133
    template < class _1 >
    void FwdIterator < _1 >::operator-- (int i)
    {
#line 133
        kit -= 1;
    };
    
#line 169
    template < class _1 >
    FwdPtrIterator < _1 >::FwdPtrIterator(const FwdPtrIterator& it)
    :
        kit(NULL)
    {
#line 169
        *this = it;
    };
    
#line 171
    template < class _1 >
    FwdPtrIterator < _1 > & FwdPtrIterator < _1 >::operator++ ()
    {
#line 171
        kit += 1;
#line 171
        return *this;
    };
    
#line 172
    template < class _1 >
    void FwdPtrIterator < _1 >::operator-- (int i)
    {
#line 172
        kit -= 1;
    };
    
};

#endif
