#ifndef _utils___
#define _utils___

#include "internals.h"
#include <string>
#include <vector>

//==========================================================
// Doxygen Group Definitions
//==========================================================
/** @defgroup window Window Management
 *  @brief Simplies and C++ifies the C-based Window Management of GLFW
 *  
 *  Uses all GLFW functions and variables as C++ functions and variables,
 *  allowing it to be simplified and more advanced at the same time
 */
//==========================================================
/** @defgroup utility Engine Utilities
 *  @brief Creates simplified utilities for engine work
 *  
 *  Simplifies general problems or required classes that
 *  don't exist or need to look better
 */
//==========================================================
/** @defgroup input Engine Input
 *  @brief Simple Input Readers and Objects
 *  
 *  Simplifies input from sources like joysticks and Keys
 */
//==========================================================
/** @defgroup video Video Objects
 *  @brief Generalized Video Objects that store visual information
 *  
 *  A standard of visual information as well as data holders for the related
 */
//==========================================================

#define LEAK_WINDOW_ACTION_SHOW 0
#define LEAK_WINDOW_ACTION_HIDE 1
#define LEAK_WINDOW_ACTION_RESTORE 2
#define LEAK_WINDOW_ACTION_ICONIFY 3
namespace Leak 
{
	struct Window;

	typedef void (* leakWindowActionFunc)(GLFWwindow*);
	typedef void (* leakWindowKeyFunc) (Window*, int, int, int, int);
	
	typedef int 		KeyValue;
	typedef int 		MouseButtonValue;
	typedef int			JoystickValue;
	
	struct KeyInput
	{
		KeyValue value;
		int mods;
		int action;
		int scancode;
	};
	
	namespace Utility 
	{
		typedef std::string 	String;
		
		/** @brief An easy way to transform an Array to anything required
		 *  
		 *  A simple way to turn any normal C language Array (or regular array) into
		 *  a new type that stores the size and the array
		 *  
		 *  @ingroup utility
		 */
		 */
		template <typename T> struct CArray<T> 
		{
			CArray(T* array, int size = 0);
		
			/** @brief The size of the @ref CArray
			 */
			int size;
			
			/** @brief The array object of the @ref CArray
			 */
			T* array;
		};
		
		/** @brief An interface for a location vector
		 *  
		 *  @ingroup utility
		 */
		struct Vector 
		{
			virtual Vector	operator+(Vector v) = 0;
			virtual Vector	operator-(Vector v) = 0;
			virtual Vector	operator*(Vector v) = 0;
			virtual Vector	operator/(Vector v) = 0;
			virtual Vector	operator%(Vector v) = 0;
		};
		
		/** @brief A 2 dimension holder of @ref Vector
		 *  
		 *  @ingroup utility
		 */
		struct Vec2 : public Vector 
		{
			Vec2(int x = 0, int y = 0);
			
			int x;
			int y;
			
			virtual int		distance(Vec2 vec2);
		};
		
		/** @brief A 3 dimension holder based off of @ref Vec2
		 *  
		 *  @ingroup utility
		 */
		struct Vec3 : public Vec2
		{
			Vec3(int x = 0, int y = 0, int z = 0);
			Vec3(const Vec2& vec);
			
			Vec3& operator=(const Vec2& vec);
			operator Vec2();
			
			int z;
			
		};
		
		/** @brief A 2 dimension float holder of @ref Vector
		 *  
		 *  @ingroup utility
		 */
		struct Vec2F : public Vector 
		{
			Vec2F(float x = 0, float y = 0);
			
			float x;
			float y;
			
			virtual float	distance(Vec2F vec2);
		};
		
		
		/** @brief A 3 dimension holder based off of @ref Vec2F
		 *  
		 *  @ingroup utility
		 */
		struct Vec3F: public Vec2F 
		{
			Vec3F(float x = 0, float y = 0, float z = 0);
			Vec3F(const &Vec2F vec);
			
			Vec3F& operator=(const Vec2F& vec);
			operator Vec2F();
			
			float z;
		};
		
		struct Vec2D : public Vector 
		{
			Vec2D(double x = 0, double y = 0);
			
			double x;
			double y;
			
			virtual double	distance(Vec2D vec2);
		};
		
		struct Vec3D : public Vec2D
		{
			Vec3D(double x = 0, double y = 0, double z = 0);
			Vec3D(const &Vec2D vec);
			
			Vec3D& operator=(const Vec2D& vec);
			operator Vec2D();
			
			double z;
		};
		
		struct Vec2L : public Vector 
		{
			Vec2L(long x = 0, long y = 0);
			
			long x;
			long y;
			
			virtual long	distance(Vec2L vec2);
		};
		
		struct Vec3L : public Vec2L
		{
			Vec3L(long x = 0, long y = 0, long z = 0);
			Vec3L(const &Vec2L vec);
			
			Vec3L& operator=(const Vec2L& vec);
			operator Vec2L();
			
			long z;
		};
		
		/** @brief A Leak Standard Exception that is thrown on generalized failures
		 *  
		 *  @ingroup utility
		 */
		struct Exception : public std::exception
		{
			String msg;
		public:
			Exception(String msg = "");
			
			const char* what() const throw();
		};
	}
	
	namespace Video 
	{
		struct DepthBit 
		{
			int red;
			int green;
			int blue;
		};
		
		struct GammaRamp 
		{
			unsigned int size;
			unsigned short* red;
			unsigned short* green;
			unsigned short* blue;
		};
		
		struct VideoMode 
		{
			Vec2 size;
			DepthBit bitDepth;
			int refreshRate;
		};
	}
	
	class KeyInput
	{
		int id;
		int mods;
		int action;
	public:
		KeyInput(int id, int mods);
		
		void 		setAction(action);
		
		int			getAction();
		
		bool 		isPressed();
		
		bool		wasReleased();
	}
	
	class Joystick 
	{
		bool present;
		std::vector<float> axesPosition;
		std::vector<int> buttonState;
		String name;
	public:
		Joystick(CArray<float> axes, CArray<int> buttons, String name = "");
		
		bool	isPresent();
		float	getAxePos(int index);
		int		getButtonState(int index);
		String	getName();
	};
	
	class Monitor
	{
		GLFWmonitor* glfwMon;
	public:
		static std::vector<Monitor*> monitorVec;
		
		static Monitor*					getPrimaryMonitor();
		
		Monitor(GLFWmonitor* monitor);
		
		std::vector<Video::VideoMode>	getVideoModes();
		Video::VideoMode				getCurrentVideoMode();
		Utility::String					getName();
		Utility::Vec2					getPhysicalSize();
		Utility::Vec2					getMonitorPos();
		Video::GammaRamp				getGammaRamp();
		
		void							setGamma(float gamma);
		void							setGammaRamp(Video::GammaRamp ramp);
	};
	
	struct Frame
	{
		Utility::Vec2 vertical;
		Utility::Vec2 horizontal;
		
		Frame(Utility::Vec2 vertical, Utility::Vec2 horizontal);
		Frame(int posX, int posY, int width, int height);
	};
	
	class Window: public _GLFWwindow
	{
		int id;
		std::vector<leakWindowActionFunc*> actions;
		KeyInput activeKey;
		
		static std::vector<Window*> windowVec;
		static int currentContextId;
		
		void setAction(int index, leakWindowActionFunc action);
	public:
		
		static Window* 	getContextWindow();
		static Window*	getWindow(int index);
	
		Window(String title, int width, int height);
		~Window();
		
		KeyInput		getActiveKey();
		int				getKeyAction(KeyValue key);
		int				getMouseButton(MouseButtonValue button);
		Utility::Vec2	getCursorPos();
		Utility::Vec2	getWindowSize();
		Utility::Vec2	getWindowPos();
		Utility::Vec2	getFramebufferSize();
		Frame			getFrameSize();
		Joystick*		getJoystick(JoystickValue joystick);
		Utility::String	getClipboardString();
		int				getInputMode(int mode);
		
		bool			wasKeyPressed(KeyValue key);
		
		bool 			running();		
		bool			shouldClose();
		
		void			setShouldClose();
		void			setWindowSize(int x, int y);
		void			setWindowPos(int x, int y);
		void			setCursorPos(Utility::Vec2 position);
		void 			setClipboardString(Utility::String str);
		void			setInputMode(int mode, int value);
		void			setContextCurrent();
		void			setWindowAction(int action);
		
		void			setActiveKey(KeyInput input);
	};
}

#endif