
#include "internal.h"

#include <stdlib.h>
#include <malloc.h>
#include <afx.h>

#ifdef __BORLANDC__
// With the Borland C++ compiler, we want to disable FPU exceptions
#include <float.h>
#endif // __BORLANDC__


#if defined(_LWS_USE_OPTIMUS_HPG)

// Applications exporting this symbol with this value will be automatically
// directed to the high-performance GPU on Nvidia Optimus systems
//
__declspec(dllexport) DWORD NvOptimusEnablement = 0x00000001;

#endif // _LWS_USE_OPTIMUS_HPG

#if defined(_LWS_BUILD_DLL)

// LWS DLL entry point
//
BOOL WINAPI DllMain(HINSTANCE instance, DWORD reason, LPVOID reserved)
{
    return TRUE;
}

#endif // _LWS_BUILD_DLL

#define _ILWS_CLASSNAME_ L"ILWS1"

////////////////////////////////////////////////////////
//// 				Exceptions						////
////////////////////////////////////////////////////////

class LibraryFailException: public LWS::Exception
{
public:
	LibraryFailException(String libName): LWS::Exception("LibraryFailException: "+libName) {}
};

class APIFailException: public LWS::Exception
{
	bool shouldStop;
public:
	APIFailException(String failedSystem, bool shouldStop = false): LWS::Exception("APIFailException: "+ failedSystem), shouldStop(shouldStop) {}
	
	bool causesStop()
	{
		return shouldStop;
	}
}

////////////////////////////////////////////////////////

using namespace ILWS;

////////////////////////////////////////////////////////
//// 				General Functions				////
////////////////////////////////////////////////////////

//	Returns a wide string version of the specified UTF-8 string
//
WCHAR* _createWideStringFromUTF8(std::string source)
{
    WCHAR* target;
    int length = source.size();
    if (!length)
        return NULL;

    target = calloc(length, sizeof(WCHAR));

    if (!MultiByteToWideChar(CP_UTF8, 0, source.c_str(), -1, target, length))
    {
        free(target);
        return NULL;
    }

    return target;
}

// Returns a UTF-8 string version of the specified wide string
//
std::string _createUTF8FromWideString(const WCHAR* source)
{	
	char* target;
    int length;

    length = WideCharToMultiByte(CP_UTF8, 0, source, -1, NULL, 0, NULL, NULL);
    if (!length)
        return NULL;

    target = calloc(length, sizeof(char));

    if (!WideCharToMultiByte(CP_UTF8, 0, source, -1, target, length, NULL, NULL))
    {
        free(target);
        return NULL;
    }
	
	std::string str(target);

    return str;
}

////////////////////////////////////////////////////////
//// 				Window Registry					////
////////////////////////////////////////////////////////

void _registerWindowClass()
{
	WNDCLASSW wc;
	
	wc.style         = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
    wc.lpfnWndProc   = (WNDPROC) windowProc;
    wc.cbClsExtra    = 0;                           // No extra class data
    wc.cbWndExtra    = sizeof(void*) + sizeof(int); // Make room for one pointer
    wc.hInstance     = GetModuleHandleW(NULL);
    wc.hCursor       = LoadCursorW(NULL, IDC_ARROW);
    wc.hbrBackground = NULL;                        // No background
    wc.lpszMenuName  = NULL;                        // No menu
	wc.lpszClassName = _ILWS_CLASSNAME_;
	
	 // Load user-provided icon if available
    wc.hIcon = LoadIconW(GetModuleHandleW(NULL), L"LWS_ICON");
    if (!wc.hIcon)
    {
        // No user-provided icon found, load default icon
        wc.hIcon = LoadIconW(NULL, IDI_WINLOGO);
    }
	
	if(!RegisterClassW(&wc))
	{
		throw LibraryFailException("Win32 Window Registry");
	}
}

void _unregisterWindowClass(void)
{
    UnregisterClassW(_ILWS_CLASSNAME_, GetModuleHandleW(NULL));
}

////////////////////////////////////////////////////////
//// 				Window Creation					////
////////////////////////////////////////////////////////



////////////////////////////////////////////////////////
//// 				Initialization					////
////////////////////////////////////////////////////////

static void _initLibs()
{
	ILWS.win32_library.winmm.instance = LoadLibraryW(L"winmm.dll");
	if(!ILWS.win32_library.winmm.instance) throw LibraryFailException("winmm.dll");
	
	ILWS.win32_library.winmm.joyGetDevCaps = (JOYGETDEVCAPS_T) GetProcAddress(ILWS.win32_library.winmm.instance, "joyGetDevCapsW");
    ILWS.win32_library.winmm.joyGetPos = (JOYGETPOS_T) GetProcAddress(ILWS.win32_library.winmm.instance, "joyGetPos");
    ILWS.win32_library.winmm.joyGetPosEx = (JOYGETPOSEX_T) GetProcAddress(ILWS.win32_library.winmm.instance, "joyGetPosEx");
    ILWS.win32_library.winmm.timeGetTime = (TIMEGETTIME_T) GetProcAddress(ILWS.win32_library.winmm.instance, "timeGetTime");
	
	if(
	!ILWS.win32_library.winmm.joyGetDevCaps || 
	!ILWS.win32_library.winmm.joyGetPos || 
	!ILWS.win32_library.winmm.joyGetPosEx || 
	!ILWS.win32_library.winmm.timeGetTime
	) throw LibraryFailException("winmm functions");
	
	ILWS.win32_library.user32.instance = LoadLibraryW(L"user32.dll");
	if(ILWS.win32_library.user32.instance)
	{
		ILWS.win32_library.user32.SetProcessDPIAware = (SETPROCESSDPIAWARE_T)
            GetProcAddress(ILWS.win32_library.user32.instance, "SetProcessDPIAware");
        ILWS.win32_library.user32.ChangeWindowMessageFilterEx = (CHANGEWINDOWMESSAGEFILTEREX_T)
			GetProcAddress(ILWS.win32_library.user32.instance, "ChangeWindowMessageFilterEx");
	}
	
	ILWS.win32_library.dwmapi.instance = LoadLibraryW(L"dwmapi.dll");
    if (ILWS.win32_library.dwmapi.instance)
    {
        ILWS.win32_library.dwmapi.DwmIsCompositionEnabled = (DWMISCOMPOSITIONENABLED_T)
            GetProcAddress(ILWS.win32_library.dwmapi.instance, "DwmIsCompositionEnabled");
    }
}

static void _terminateLibs()
{
	 if (ILWS.win32_library.winmm.instance)
        FreeLibrary(ILWS.win32_library.winmm.instance);

    if (ILWS.win32_library.user32.instance)
        FreeLibrary(ILWS.win32_library.user32.instance);

    if (ILWS.win32_library.dwmapi.instance)
        FreeLibrary(ILWS.win32_library.dwmapi.instance);
}

static void _createKeyTables()
{
	ILWS.win32_library.publicKeys(512, UNKNOWN);
	
	ILWS.win32_library.publicKeys[0x00B] = NUM_0;
    ILWS.win32_library.publicKeys[0x002] = NUM_1;
    ILWS.win32_library.publicKeys[0x003] = NUM_2;
    ILWS.win32_library.publicKeys[0x004] = NUM_3;
    ILWS.win32_library.publicKeys[0x005] = NUM_4;
    ILWS.win32_library.publicKeys[0x006] = NUM_5;
    ILWS.win32_library.publicKeys[0x007] = NUM_6;
    ILWS.win32_library.publicKeys[0x008] = NUM_7;
    ILWS.win32_library.publicKeys[0x009] = NUM_8;
    ILWS.win32_library.publicKeys[0x00A] = NUM_9;
    ILWS.win32_library.publicKeys[0x01E] = A;
    ILWS.win32_library.publicKeys[0x030] = B;
    ILWS.win32_library.publicKeys[0x02E] = C;
    ILWS.win32_library.publicKeys[0x020] = D;
    ILWS.win32_library.publicKeys[0x012] = E;
    ILWS.win32_library.publicKeys[0x021] = F;
    ILWS.win32_library.publicKeys[0x022] = G;
    ILWS.win32_library.publicKeys[0x023] = H;
    ILWS.win32_library.publicKeys[0x017] = I;
    ILWS.win32_library.publicKeys[0x024] = J;
    ILWS.win32_library.publicKeys[0x025] = K;
    ILWS.win32_library.publicKeys[0x026] = L;
    ILWS.win32_library.publicKeys[0x032] = M;
    ILWS.win32_library.publicKeys[0x031] = N;
    ILWS.win32_library.publicKeys[0x018] = O;
    ILWS.win32_library.publicKeys[0x019] = P;
    ILWS.win32_library.publicKeys[0x010] = Q;
    ILWS.win32_library.publicKeys[0x013] = R;
    ILWS.win32_library.publicKeys[0x01F] = S;
    ILWS.win32_library.publicKeys[0x014] = T;
    ILWS.win32_library.publicKeys[0x016] = U;
    ILWS.win32_library.publicKeys[0x02F] = V;
    ILWS.win32_library.publicKeys[0x011] = W;
    ILWS.win32_library.publicKeys[0x02D] = X;
    ILWS.win32_library.publicKeys[0x015] = Y;
    ILWS.win32_library.publicKeys[0x02C] = Z;

    ILWS.win32_library.publicKeys[0x028] = APOSTROPHE;
    ILWS.win32_library.publicKeys[0x02B] = BACKSLASH;
    ILWS.win32_library.publicKeys[0x033] = COMMA;
    ILWS.win32_library.publicKeys[0x00D] = EQUAL;
    ILWS.win32_library.publicKeys[0x029] = GRAVE_ACCENT;
    ILWS.win32_library.publicKeys[0x01A] = LEFT_BRACKET;
    ILWS.win32_library.publicKeys[0x00C] = MINUS;
    ILWS.win32_library.publicKeys[0x034] = PERIOD;
    ILWS.win32_library.publicKeys[0x01B] = RIGHT_BRACKET;
    ILWS.win32_library.publicKeys[0x027] = SEMICOLON;
    ILWS.win32_library.publicKeys[0x035] = SLASH;
    ILWS.win32_library.publicKeys[0x056] = WORLD_2;

    ILWS.win32_library.publicKeys[0x00E] = BACKSPACE;
    ILWS.win32_library.publicKeys[0x153] = DELETE;
    ILWS.win32_library.publicKeys[0x14F] = END;
    ILWS.win32_library.publicKeys[0x01C] = ENTER;
    ILWS.win32_library.publicKeys[0x001] = ESCAPE;
    ILWS.win32_library.publicKeys[0x147] = HOME;
    ILWS.win32_library.publicKeys[0x152] = INSERT;
    ILWS.win32_library.publicKeys[0x15D] = MENU;
    ILWS.win32_library.publicKeys[0x151] = PAGE_DOWN;
    ILWS.win32_library.publicKeys[0x149] = PAGE_UP;
    ILWS.win32_library.publicKeys[0x045] = PAUSE;
    ILWS.win32_library.publicKeys[0x039] = SPACE;
    ILWS.win32_library.publicKeys[0x00F] = TAB;
    ILWS.win32_library.publicKeys[0x03A] = CAPS_LOCK;
    ILWS.win32_library.publicKeys[0x145] = NUM_LOCK;
    ILWS.win32_library.publicKeys[0x046] = SCROLL_LOCK;
    ILWS.win32_library.publicKeys[0x03B] = F1;
    ILWS.win32_library.publicKeys[0x03C] = F2;
    ILWS.win32_library.publicKeys[0x03D] = F3;
    ILWS.win32_library.publicKeys[0x03E] = F4;
    ILWS.win32_library.publicKeys[0x03F] = F5;
    ILWS.win32_library.publicKeys[0x040] = F6;
    ILWS.win32_library.publicKeys[0x041] = F7;
    ILWS.win32_library.publicKeys[0x042] = F8;
    ILWS.win32_library.publicKeys[0x043] = F9;
    ILWS.win32_library.publicKeys[0x044] = F10;
    ILWS.win32_library.publicKeys[0x057] = F11;
    ILWS.win32_library.publicKeys[0x058] = F12;
    ILWS.win32_library.publicKeys[0x064] = F13;
    ILWS.win32_library.publicKeys[0x065] = F14;
    ILWS.win32_library.publicKeys[0x066] = F15;
    ILWS.win32_library.publicKeys[0x067] = F16;
    ILWS.win32_library.publicKeys[0x068] = F17;
    ILWS.win32_library.publicKeys[0x069] = F18;
    ILWS.win32_library.publicKeys[0x06A] = F19;
    ILWS.win32_library.publicKeys[0x06B] = F20;
    ILWS.win32_library.publicKeys[0x06C] = F21;
    ILWS.win32_library.publicKeys[0x06D] = F22;
    ILWS.win32_library.publicKeys[0x06E] = F23;
    ILWS.win32_library.publicKeys[0x076] = F24;
    ILWS.win32_library.publicKeys[0x038] = LEFT_ALT;
    ILWS.win32_library.publicKeys[0x01D] = LEFT_CONTROL;
    ILWS.win32_library.publicKeys[0x02A] = LEFT_SHIFT;
    ILWS.win32_library.publicKeys[0x15B] = LEFT_SUPER;
    ILWS.win32_library.publicKeys[0x137] = PRINT_SCREEN;
    ILWS.win32_library.publicKeys[0x138] = RIGHT_ALT;
    ILWS.win32_library.publicKeys[0x11D] = RIGHT_CONTROL;
    ILWS.win32_library.publicKeys[0x036] = RIGHT_SHIFT;
    ILWS.win32_library.publicKeys[0x15C] = RIGHT_SUPER;
    ILWS.win32_library.publicKeys[0x150] = DOWN;
    ILWS.win32_library.publicKeys[0x14B] = LEFT;
    ILWS.win32_library.publicKeys[0x14D] = RIGHT;
    ILWS.win32_library.publicKeys[0x148] = UP;

    ILWS.win32_library.publicKeys[0x052] = KP_0;
    ILWS.win32_library.publicKeys[0x04F] = KP_1;
    ILWS.win32_library.publicKeys[0x050] = KP_2;
    ILWS.win32_library.publicKeys[0x051] = KP_3;
    ILWS.win32_library.publicKeys[0x04B] = KP_4;
    ILWS.win32_library.publicKeys[0x04C] = KP_5;
    ILWS.win32_library.publicKeys[0x04D] = KP_6;
    ILWS.win32_library.publicKeys[0x047] = KP_7;
    ILWS.win32_library.publicKeys[0x048] = KP_8;
    ILWS.win32_library.publicKeys[0x049] = KP_9;
    ILWS.win32_library.publicKeys[0x04E] = KP_ADD;
    ILWS.win32_library.publicKeys[0x053] = KP_DECIMAL;
    ILWS.win32_library.publicKeys[0x135] = KP_DIVIDE;
    ILWS.win32_library.publicKeys[0x11C] = KP_ENTER;
    ILWS.win32_library.publicKeys[0x037] = KP_MULTIPLY;
    ILWS.win32_library.publicKeys[0x04A] = KP_SUBTRACT;
}

bool _isCompositionEnabled()
{
	BOOL enabled;
	
	if (!ILWS.win32_library.dwmapi.DwmIsCompositionEnabled && ILWS.win32_library.dwmapi.DwmIsCompositionEnabled(&enabled) != S_OK) return false;
	
	if(enabled)
		return true;
	
	return false;
}

bool _initLWS()
{
	SystemParametersInfoW(SPI_GETFOREGROUNDLOCKTIMEOUT, 0,&ILWS.win32_library.foregroundLockTimeout, 0);
    SystemParametersInfoW(SPI_SETFOREGROUNDLOCKTIMEOUT, 0, UIntToPtr(0),SPIF_SENDCHANGE); 
	
	try 
	{
		_initLibs();
	} 
	catch (LibraryFailException e) 
	{
		return false;
	}
	
	_createKeyTables();
	
	if(ILWS.win32_library.user32.SetProcessDPIAware) ILWS.win32_library.user32.SetProcessDPIAware();
	
	#ifdef __BORLANDC__
    // With the Borland C++ compiler, we want to disable FPU exceptions
    // (this is recommended for OpenGL applications under Windows)
    _control87(MCW_EM, MCW_EM);
	#endif
	
	try
	{
		_registerWndClass();
		_initContextAPI();
		_initTimer();
		_initJoysticks();
	}
	catch (APIFailException e)
	{
		if(e.causesStop())
		{
			return false;
		}
	}
	
	return true;
}

void _terminate()
{
	_unregisterWndClass();
	
	// Restore previous foreground lock timeout system setting
    SystemParametersInfoW(SPI_SETFOREGROUNDLOCKTIMEOUT, 0, UIntToPtr(_glfw.win32.foregroundLockTimeout), SPIF_SENDCHANGE);
	
	_terminateJoysticks();
    _terminateContextAPI\);
    _terminateLib();
}