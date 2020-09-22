#ifndef _CoreLib_CoreLib_h_
#define _CoreLib_CoreLib_h_

#include <Core/Core.h>


#ifndef NAMESPACE_SDK_BEGIN
	#define NAMESPACE_SDK_BEGIN namespace  Upp {
	#define NAMESPACE_SDK_END }
#endif

#ifndef endl
	#ifdef flagWIN32
		#define ENDL "\r\n"
		#define endl "\r\n"
	#else
		#define ENDL "\n"
		#define endl "\n"
	#endif
#endif

NAMESPACE_SDK_BEGIN







NAMESPACE_SDK_END


#include "Util.h"
#include "UppManagement.h"


#endif
