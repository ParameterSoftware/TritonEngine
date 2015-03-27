#ifndef _LWS_INCLUDE_H_
#define _LWS_INCLUDE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <exception>

#include <cctype>

#if !defined(_WIN32) && (defined(__WIN32__) || defined(WIN32) || defined(__CYGWIN__))
	#define _WIN32
#endif

#ifndef APIENTRY
	#ifdef _WIN32
		#define APIENTRY __stdcall
	#else
		#define APIENTRY
	#endif
#endif

#if !defined(WINGDIAPI) && defined(_WIN32)
	#if defined(_MSC_VER) || defined(__BORLANDC__) || defined(__POCC__)
		/* Microsoft Visual C++, Borland C++ Builder and Pelles C */
		#define WINGDIAPI __declspec(dllimport)
	#elif defined(__LCC__)
		/* LCC-Win32 */
		#define WINGDIAPI __stdcall
	#else
		/* Others (e.g. MinGW, Cygwin) */
		#define WINGDIAPI extern
	#endif
	#define LWS_WINGDIAPI_DEFINED
#endif

#if !defined(CALLBACK) && defined(_WIN32)
	#if defined(_MSC_VER)
		/* Microsoft Visual C++ */
		#if (defined(_M_MRX000) || defined(_M_IX86) || defined(_M_ALPHA) || defined(_M_PPC)) && !defined(MIDL_PASS)
			#define CALLBACK __stdcall
		#else
			#define CALLBACK
		#endif
	#else
		/* Other Windows compilers */
		#define CALLBACK __stdcall
	#endif
	#define LWS_CALLBACK_DEFINED
#endif

#if !defined(LWS_INCLUDE_NONE)
	#include <stddef.h>
#endif

#if defined(__APPLE_CC__)
	#if defined(LWS_INCLUDE_GLCOREARB)
		#include <OpenGL/gl3.h>
		#if defined(LWS_INCLUDE_GLEXT)
			#include <OpenGL/gl3ext.h>
		#endif
	#elif !defined(LWS_INCLUDE_NONE)
		#if !defined(LWS_INCLUDE_GLEXT)
			#define GL_GLEXT_LEGACY
		#endif
		#include <OpenGL/gl.h>
	#endif
	
	#if defined(LWS_INCLUDE_GLU)
		#include <OpenGL/glu.h>
	#endif
#else
	#if defined(LWS_INCLUDE_GLCOREARB)
		#include <GL/glcorearb.h>
	#elif defined(LWS_INCLUDE_ES1)
		#include <GLES/gl.h>
		#if defined(LWS_INCLUDE_GLEXT)
			#include <GLES/glext.h>
		#endif
	#elif defined(LWS_INCLUDE_ES2)
		#include <GLES2/gl2.h>
		#if defined(LWS_INCLUDE_GLEXT)
			#include <GLES2/gl2ext.h>
		#endif
	#elif defined(LWS_INCLUDE_ES3)
		#include <GLES3/gl3.h>
		#if defined(LWS_INCLUDE_GLEXT)
			#include <GLES3/gl2ext.h>
		#endif
	#elif defined(LWS_INCLUDE_ES31)
		#include <GLES3/gl31.h>
		#if defined(LWS_INCLUDE_GLEXT)
			#include <GLES3/gl2ext.h>
		#endif
	#elif !defined(LWS_INCLUDE_NONE)
		#include <GL/gl.h>
		#if defined(LWS_INCLUDE_GLEXT)
			#include <GL/glext.h>
		#endif
	#endif
	
	#if defined(LWS_INCLUDE_GLU)
		#include <GL/glu.h>
	#endif
#endif

#if defined(LWS_DLL) && defined(_LWS_BUILD_DLL)
 /* LWS_DLL must be defined by applications that are linking against the DLL
  * version of the LWS library.  _LWS_BUILD_DLL is defined by the LWS
  * configuration header when compiling the DLL version of the library.
  */
 #error "You must not have both LWS_DLL and _LWS_BUILD_DLL defined"
#endif

#if defined(_WIN32) && defined(_LWS_BUILD_DLL)
	/* We are building LWS as a Win32 DLL */
	#define LWSAPI __declspec(dllexport)
#elif defined(_WIN32) && defined(LWS_DLL)
	/* We are calling LWS as a Win32 DLL */
	#if defined(__LCC__)
		#define LWSAPI extern
	#else
		#define LWSAPI __declspec(dllimport)
	#endif
#elif defined(__GNUC__) && defined(_LWS_BUILD_DLL)
	/* We are building LWS as a shared / dynamic library */
	#define LWSAPI __attribute__((visibility("default")))
#else
	/* We are building or calling LWS as a static library */
	#define LWSAPI
#endif


#define LWS_VERSION_MAJOR	0

#define LWS_VERSION_MINOR	1

#define LWS_VERSION_REVISION	0

/****************************************************************
 *  Doxygen Documentation
 ****************************************************************/
 /** @defgroup lws Leak Window System
  *  @ingroup leak
  *  
  *  The window manager for @ref leak
  */
 /** @defgroup lws_enums Enums
  *  @ingroup lws
  *  
  *  A collection of useful enums for @ref lws
  */
 /** @defgroup lws_system System
  *  @ingroup lws
  *  
  *  A group of system objects for @ref lws
  */
 /** @defgroup lws_lib Library
  *  @ingroup lws
  *  
  *  A group of more generalized library objects
  */
namespace LWS
{
	class Library;
	
	namespace System 
	{
		class Monitor;
		class Window;
		class Joystick;
		class Frame;
	}
	
	enum Key;
	enum KeyMod;
	enum MouseButton;
	enum JoystickAdapter;
	enum Action;
	enum WindowAttrib;
	enum CursorShape;
	enum Connection;
	
	typedef (montcontfun*)(System::Monitor*, Connection);

	enum Key
	{
		UNKNOWN = -1,
		SPACE = 32,																			/*   */
		APOSTROPHE = 39,																	/* ' */
		COMMA = 44,																			/* , */
		MINUS,																						/* - */
		PERIOD,																					/* . */
		SLASH,																					/* / */
		NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, 
				NUM_5, NUM_6, NUM_7, NUM_8, NUM_9, 						/* Default Numerical Keys */
		SEMICOLON = 59,																	/* ; */
		EQUAL = 61,																			/* = */
		A = 65, B, C, D, E, F, G, H, I, J, K, 
				L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, 						/* Letter Keys */
		LEFT_BRACKET, 																		/* [ */
		BACKSLASH, 																			/* \ */
		RIGHT_BRACKET,																	/* ] */
		GRAVE_ACCENT = 96,  															/* ` */
		WORLD_1 = 161, WORLD_2, 													/* Non-US Keys */
		ESCAPE = 256, ENTER, TAB, BACKSPACE, INSERT, DELETE,	/* Function Keys */
		RIGHT, LEFT, DOWN, UP, 														/* Arrow Keys */
		PAGE_UP, PAGE_DOWN,														/* Page Keys */
		HOME, END,																			/* Home and End Keys */
		CAPS_LOCK = 280, SCROLL_LOCK, NUM_LOCK, 					/* Lock Keys */
		PRINT_SCREEN,																		/* PrntScr Key */
		PAUSE,																					/* Pause Key */
		F1 = 290, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, 
			F12, F13, F14, F15, F16, F17, F18, F19, F20, 
							F21,F22, F23, F24, F25, 										/* F-Numerical Function Keys */
		KP_0 = 320, KP_1, KP_2, KP_3, KP_4, KP_5, KP_6, KP_7, 
				KP_8, KP_9, 																	/* Keypad Numerical Keys */
		KP_DECIMAL, KP_DIVIDE, KP_MULTIPLY, KP_SUBTRACT, 
			KP_ADD, KP_ENTER, KP_EQUAL, 										/* Keypad Non-Numerical Keys */
		LEFT_SHIFT = 340, LEFT_CONTROL, LEFT_ALT, LEFT_SUPER, /* Left Mod Keys */
		RIGHT_SHIFT, RIGHT_CONTROL, RIGHT_ALT, RIGHT_SUPER,	/* Right Mod Keys */
		MENU,																						/* Menu Key */
		LAST = MENU																			/* Last Key (Size) */
	};
	
	enum KeyMod
	{
		SHIFT = 0x0001,
		CONTROL = 0x0002,
		ALT = 0x0004,
		SUPER = 0x0008
	};
	
	enum MouseButton
	{
		BUTTON_1 = 0,
		BUTTON_2,
		BUTTON_3,
		BUTTON_4,
		BUTTON_5,
		BUTTON_6,
		BUTTON_7,
		BUTTON_8,
		LAST_BUTTON = BUTTON_8,
		LEFT_BUTTON = BUTTON_1,
		RIGHT_BUTTON = BUTTON_2,
		MIDDLE_BUTTON = BUTTON_3
	};
	
	enum JoystickAdapter
	{
		JOYSTICK_1 = 0,
		JOYSTICK_2,
		JOYSTICK_3,
		JOYSTICK_4,
		JOYSTICK_5,
		JOYSTICK_6,
		JOYSTICK_7,
		JOYSTICK_8,
		JOYSTICK_9,
		JOYSTICK_10,
		JOYSTICK_11,
		JOYSTICK_12,
		JOYSTICK_13,
		JOYSTICK_14,
		JOYSTICK_15,
		JOYSTICK_16,
		JOYSTICK_LAST = JOYSTICK_16
	};
	
	enum Action
	{
		RELEASE = 0,
		PRESS,
		REPEAT
	};
	
	enum WindowAttrib
	{
		FOCUSED = 0x00020001,
		ICONIFIED,
		RESIZEABLE,
		VISIBLE,
		DECORATED,
		AUTO_ICONIFIED,
		FLOATING
	};
	
	enum CursorShape
	{
		ARROW = 0x00036001,
		IBEAM,
		CROSSHAIR,
		HAND,
		HRESIZE,
		VRESIZE
	};
	
	enum Connection
	{
		UNKNOWN = -1,
		CONNECTED = 0x00040001,
		DISCONNECTED
	};
	
	namespace System
	{	
		class Joystick
		{
			friend class Library;
			
			JoystickAdapter joystick;
			
			Joystick(JoystickAdapter joystick);
		public:
			DList<float>	getAxes();
			DList<int>		getButtons();
			String			getName();
		};
		
		class Frame
		{
			friend class Window;
			
			Util::Vec2<int> vert;
			Util::Vec2<int> hori;
			Frame(int left, int right, int top, int bottom);
		public:
			int		getTop();
			int		getBottom();
			int		getLeft();
			int 		getRight();
		};
	
		class Monitor
		{
			friend class Library;
			friend class Window;
		
			Util::Vec2<int>	position;
			Util::Vec2<int> physicalSize;
			String			title;
			
			VideoMode		currentVidMode;
		
			Monitor(String title, Util::Vec2<int> pos, Util::Vec2<int> phySize);
			DList<Window*> windowsIn;
		public:
			bool 				isWindowHere(Window* win);
			
			Window* 			getWindow(int index);
			Util::Vec2<int>		getPosition();
			Util::Vec2<int>		getPhysicalSize();
			String				getTitle();
			VideoMode			getCurrentVideoMode();
			DList<VideoMode>	getSupportedVideoModes();
		};
		
		class Window
		{
		
			struct  {
				GLboolean           resizable;
				GLboolean           decorated;
				GLboolean           autoIconify;
				GLboolean           floating;
				GLboolean           closed;
				GLboolean			fullscreen;
				
				GLboolean           stickyKeys;
				GLboolean           stickyMouseButtons;
				double              cursorPosX, cursorPosY;
				int                 cursorMode;
			} flags;
			
			struct {
				int             api;
				int             major, minor, revision;
				GLboolean       forward, debug;
				int             profile;
				int             robustness;
				int             release;
			} oglContext;
			
			Monitor* 					windowsMonitor;
			Window*						next;
		public:
			Window(String title, int width, int height, Monitor* placeIn = Library::getIntsance.getPrimaryMonitor(), Window* share = NULL);
			
			static Window*		getCurrentContext();
			
			void				toggleFullscreen(Monitor* monitor=windowsMonitor);
			
			void				pollEvents();
			void				waitEvents();
			void				postEvent();
			void				swapBuffers();
			
			String						getTitle();
			Util::Vec2<int>			getPosition();
			Util::Vec2<int>			getSize();
			Util::Vec2<int>			getFramebufferSize();
			Util::Vec2<double>	getCursorPosition();
			Action						getKey(Key key);
			Action						getMouse(MouseButton mouseButton);
			Frame*						getFrame();
			bool							getWindowAttrib(WindowAttrib attrib);
			int							getInputMode(int mode);
			String						getClipboardString();
			
			void				setClosing();
			void				setTitle(String title);
			void				setPosition(Util::Vec2<int> pos);
			void				setSize(Util::Vec2<int> size);
			void				setCursorPosition(Util::Vec2<double> pos);
			void				setInputMode(int mode, int value);
			void				setClipboardString(String clip);
			void				setSwapInterval(int interval);
			void				setVSync(int interval); //Same as setSwapInterval(interval)
			
			int				isClosing();
			int				isFullscreen();
			
			virtual void		onPositionChange(Util::Vec2 pos);
			virtual void		onResize(Util::Vec2 size);
			virtual void		onClose();
			virtual void		onRefresh();
			virtual void		onFocus(int gainFocus);
			virtual void		onIconify(int becomeIcon);
			virtual void		onFramebufferResize(Util::Vec2<int> size);
			virtual void		onMouseClicked(MouseButton button, Action action, int mod);
			virtual void		onCursorMovement(Util::Vec2<double> pos);
			virtual void		onCursorFocus(int focused);
			virtual void		onScroll(Util::Vec2<double> axis);
			virtual void		onKeyChange(Key key, int scancode, Action action, int mod);
			virtual void		onCharTyped(char character);
			virtual void		onCharTypedWithMods(char character, int mod);
			virtual void		onFileDrop(DList<String> fileDirs);
			virtual void		onUpdate();
			
			~Window();
		};
	}
	
	struct VideoMode
	{
		int width;
		int height;
		int redBit;
		int greenBit;
		int blueBit;
		int refreshRate;
	};
	
	class Library
	{	
		friend class System::Window;
	
		static Library* instance;
		struct version_t
		{
			int major;
			int minor;
			int revis;
		} version;
		
		struct {
			int         redBits;
			int         greenBits;
			int         blueBits;
			int         alphaBits;
			int         depthBits;
			int         stencilBits;
			int         accumRedBits;
			int         accumGreenBits;
			int         accumBlueBits;
			int         accumAlphaBits;
			int         auxBuffers;
			int         stereo;
			int         resizable;
			int         visible;
			int         decorated;
			int         focused;
			int         autoIconify;
			int         floating;
			int         samples;
			int         sRGB;
			int         refreshRate;
			int         doublebuffer;
			int         api;
			int         major;
			int         minor;
			int         forward;
			int         debug;
			int         profile;
			int         robustness;
			int         release;
		} hints;
		
		DList<System::Window*>		windowList;
		System::Window*					focusedWindow;
		
		DList<System::Monitor*>		monitorList;
		
		errorhandlefun			errorHandler;
		MonitorHandler*			monitorHandler;
		
		Library(int major, int minor, int rev);
	public:
		static Library*					getIntsance();
		
		version_t 							getVersion();
		String								getVersionString();
		DList<System::Monitor*>	getMonitors();
		System::Monitor*				getPrimaryMonitor();
		Joystick*							getJoystick(JoystickAdapter joystick);	
		double								getTime();
		System::Window*				getCurrentContext();
		
		void						setErrorHandler(LUS::errorhandlefun errorHandler);
		void						setMonitorHandler(montcontfun montiorHandler);
		void						setWindowHint(int target, int hint);
		void						setWindowHintDefault();
		void						setTime(double time);
		void						setCurrentContext(System::Window* window);
		
		void						onError(int errorCode, String errorRead);
		void						onMonitorConnect(Monitor* monitor, Connection connect);
	};

}

#endif