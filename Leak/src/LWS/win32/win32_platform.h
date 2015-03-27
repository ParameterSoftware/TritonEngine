#ifndef _lws_win32_platform_h_
#define _lws_win32_platform_h_

#include <lws.h>

#ifndef NOMINMAX
	#define NOMINMAX
#endif

#ifndef VC_EXTRALEAN
	#define VC_EXTRALEAN
#endif

#ifndef WIN32_LEAN_AND_MEAN
	#define WIN32_LEAN_AND_MEAN
#endif

#ifndef UNICODE
	#define UNICODE
#endif

#undef APIENTRY

#include <windows.h>
#include <mmsystem.h>
#include <dbt.h>

#if defined(_MSC_VER)
	#include <malloc.h>
	#define strdup _strdup
#endif

#ifndef WM_MOUSEHWHEEL
	#define WM_MOUSEHWHEEL 0x020E
#endif
#ifndef WM_DWMCOMPOSITIONCHANGED
	#define WM_DWMCOMPOSITIONCHANGED 0x031E
#endif
#ifndef WM_COPYGLOBALDATA
	#define WM_COPYGLOBALDATA 0x0049
#endif
#ifndef WM_UNICHAR
	#define WM_UNICHAR 0x0109
#endif
#ifndef UNICODE_NOCHAR
	#define UNICODE_NOCHAR 0xFFFF
#endif

#if WINVER < 0x0601
struct tagCHANGEFILTERSTRUCT
{
	DWORD cbSize;
	DWORD ExtStatus;
	
} CHANGEFILTERSTRUCT, *PCHANGEFILTERSTRUCT;
	#ifndef MSGFLT_ALLOW
		#define MSGFLT_ALLOW 1
	#endif
#endif

namespace ILWS
{	
	typedef std::string String;

	struct Win32WindowData
	{
		HWND 			handle;
		DWORD 			dwStyle;
		DWORD			dwExStyle;
		
		GLboolean		cursorInside;
		GLboolean		iconified;
		
		int				cursorPosX, cursorPosY;
	};
	
	struct Win32System
	{
		DWORD					foregroundLockoutTimeout;
		String					clipboardString;
		DList<Key>				publicKeys;
		
		// winmm.dll
		struct {
			HINSTANCE       instance;
			JOYGETDEVCAPS_T joyGetDevCaps;
			JOYGETPOS_T     joyGetPos;
			JOYGETPOSEX_T   joyGetPosEx;
			TIMEGETTIME_T   timeGetTime;
		} winmm;

		// user32.dll
		struct {
			HINSTANCE       				instance;
			SETPROCESSDPIAWARE_T 			SetProcessDPIAware;
			CHANGEWINDOWMESSAGEFILTEREX_T 	ChangeWindowMessageFilterEx;
		} user32;

		// dwmapi.dll
		struct {
			HINSTANCE       			instance;
			DWMISCOMPOSITIONENABLED_T 	DwmIsCompositionEnabled;
		} dwmapi;
	};
	
	struct Win32Monitor
	{
		String			adapterName;
		String			displayName;
		String			publicAdapterName;
		String			publicDisplayName;
		GLboolean		modeChanged;
	};
	
	struct Win32Cursor
	{
		HCURSOR instance;
	};
	
	struct Win32Timer
	{
		GLboolean           hasPC;
		double              resolution;
		unsigned __int64    base;
		
		Win32Timer();
		
		double 	getTime();
		void 	setTime(double time);
	};
	
	struct Win32TLS
	{
		GLboolean		allocated;
		DWORD			context;
		
		Win32TLS();
		~Win32TLS();
		
		setCurrentContext(ILWS::Window*	context);
	};	
	#define _ILWS_WINDOW_STATE_			Win32Window			win32_window
	#define _ILWS_LIBRARY_WINDOW_STATE_	Win32System			win32_library
	#define _ILWS_LIBRARY_TIME_STATE_ 	Win32Timer 			win32_time
	#define _ILWS_MONITOR_STATE_		Win32Monitor		win32_monitor
	#define _ILWS_CURSOR_STATE_			Win32Cursor			win32_cursor
	
	#define _ILWS_W_LW_LT_M_C_DEFINED		1
}

#endif