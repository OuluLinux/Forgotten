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

#ifndef REFTEMPLATE_C
#define REFTEMPLATE_C

#include <new>

#ifndef REFTEMPLATE_H
#include <RefTemplate.H>
#endif

#line 150 "../../src/Com/Shared.fog"
template < class _1 >
RefTemplate < _1 >::~RefTemplate()
{
#line 150
    if (obj)
#line 150
        delete ((_1 * ) obj);
#line 150
    obj = 0;
};

#endif
