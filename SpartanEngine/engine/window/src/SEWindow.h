#ifndef __SEWINDOW__
#define __SEWINDOW__

#include <GLFW\glfw3.h>

class SEWindow
{
public:
	SEWindow(int height, int width, const char* title, GLFWmonitor* monitor, GLFWwindow* share);
	SEWindow(int height, int width, const char* title);
	SEWindow(const char* title);
	SEWindow();
	~SEWindow();
	GLFWwindow* GetWindow();
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