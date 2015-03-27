#ifndef _lws_internal_h_
#define _lws_internal_h_

#define _LWS_VERSION_STRING "0.1.0"

#include <lws.h>
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

#if defined(_LWS_USE_CONFIG_)
	#include "lws_config.h"
#endif



#if defined(_LWS_WIN32)
	#include "win32_platform.h"
#elif
#endif

namespace ILWS
{
	#ifndef _LWS_STRUCTS_MACROS_DEFINED_
		#error "Undefined Managment of OS"
	#endif
	
	struct Window
	{
		LWS::System::Window* mainObject;
	
		_ILWS_WINDOW_STATE_;
	};

	struct Library
	{
		_ILWS_LIBRARY_WINDOW_STATE_;
		_ILWS_LIBRARY_TIME_STATE_;
	};
	
	extern Libary ILWS;
}

#endif