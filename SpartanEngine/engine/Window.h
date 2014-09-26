#ifndef __SEWINDOW__
#define __SEWINDOW__

#include <GLFW\glfw3.h>
#include <vector>

namespace sewm
{
	class Window
	{
	public:
		Window(int height = 640, int width = 800, const char* title = "Spartan Engine", GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);
		~Window();
		GLFWwindow* GetWindowObject();
		int* GetDimensions();
		const char* GetTitle();
		bool isFullScreen();
		void ToggleFullscreen(GLFWmonitor* monitor = glfwGetPrimaryMonitor());
		virtual void Startup();
		virtual void Update();
		virtual void Close();
		double GetDeltaTime();
	protected:
		GLFWmonitor* screenObject;
	private:
		GLFWwindow* window;
		const char* title;
		double winDeltaTime;
	};

	Window* getMainWindow();
}

#endif /* defined(__SEWINDOW__) */