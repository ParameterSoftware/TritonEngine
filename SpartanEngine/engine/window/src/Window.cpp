#include "SEWindow.h"

using SEWindow;

static SEWindow* mainWindow = NULL;

void sewSaveAsMainWindow(SEWindow* window)
{
	mainWindow = window;
}

SEWindow* sewGetMainWindow()
{
	return mainWindow
}

SEWindow(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	this->width = width;
	this->height = height;
	this->title = title
	window = glfwCreateWindow(width, height, this->title, monitor, share);
	if(sewGetMainWindow() == NULL)
		sewSaveAsMainWindow(this);
}

SEWindow(int width, int height, const char* title)
{
	this(width, height, title, NULL, NULL);
}

SEWindow(const char* title)
{
	this(640, 480, title);
}

SEWindow()
{
	this("Example");
}

~SEWindow()
{
	glfwDestroyWindow(this->window);
}

GLFWwindow* GetWindow()
{
	return window;
}

int[2] GetDimensions()
{
	int[2] dimen;
	glfwGetWindowSize(window, dimen, dimen+1);
	return dimen;
}

const char* GetTitle()
{
	return title;
}
bool isFullScreen()
{
	return isFull;
}

void ToggleFullscreen(GLFWmonitor* monitor)
{
	int[2] dim = GetDimensions();
	SEWindow* wind = SEWindow(dim[0], dim[1], GetTitle(), (!isFull) ? monitor : NULL, this->window);
	bool fullScr = !isFull;
	glfwDestroy(this->window);
	this = wind;
	this->isFull = fullScr;
}

void Startup()
{}

void Update()
{
	//Proper Update Function
	double lastTime = glfwGetTime();
	//Find All Update Functions and stick them here
	double currentTime = glfwGetTime();
	winDeltaTime = lastTime - currentTime;
}

virtual void Close()
{}

double GetDeltaTime()
{
	return winDeltaTime;
}