#ifndef __SEWINDOW__
#define __SEWINDOW__

#include <GLFW\glfw3.h>

class Window
{
public:
	Window(int height, int width, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	Window(int height, int width, const char* title);
	Window(const char* title);
	Window();
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
	bool isFull;
private:
	GLFWwindow* window;
	const char* title;
	double winDeltaTime;
};

SEWindow sewGetMainWindow();

#endif /* defined(__SEWINDOW__) */