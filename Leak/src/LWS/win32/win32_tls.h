#ifndef _LWS_WIN32_TLS_H_
#define _LWS_WIN32_TLS_H_

namespace ILWS
{

	struct Win32TLS
	{
		GLboolean		allocated;
		DWORD			context;
		
		Win32TLS();
		~Win32TLS();
		
		setCurrentContext(ILWS::Window*	context);
	};
	
	#define _ILWS_LIBRARY_TLS_STATE_	Win32TLS			win32_tls
}

#endif