#include "Window.h"

using namespace sewm;

Window* mainWindow = NULL;

void saveAsMainWindow(Window* window)
{
	mainWindow = window;
}

Window* getMainWindow()
{
	return mainWindow;
}

Window::Window(int width, int height, const char* title, GLFWmonitor* monitor, GLFWwindow* share)
{
	this->title = title;
	window = glfwCreateWindow(width, height, this->title, monitor, share);
	screenObject = monitor;
	if(!getMainWindow())
		saveAsMainWindow(this);
	Startup();
}

Window::~Window()
{
	glfwDestroyWindow(this->window);
	Close();
}

GLFWwindow* Window::GetWindowObject()
{
	return window;
}

int* Window::GetDimensions()
{
	int dimen[2];
	glfwGetWindowSize(window, dimen, dimen+1);
	return dimen;
}

const char* Window::GetTitle()
{
	return title;
}
bool Window::isFullScreen()
{
	return screenObject != NULL;
}

void Window::ToggleFullscreen(GLFWmonitor* monitor = glfwGetPrimaryMonitor())
{
	int *dim = GetDimensions();
	screenObject = (!isFullScreen()) ? monitor : NULL;
	GLFWwindow* wind = glfwCreateWindow(dim[0], dim[1], GetTitle(), screenObject, this->window);
	glfwDestroyWindow(this->window);
	this->window = wind;
}

void Window::Startup()
{}

void Window::Update()
{
	//Proper Update Function
	double lastTime = glfwGetTime();
	//Find All Update Functions and stick them here
	double currentTime = glfwGetTime();
	winDeltaTime = lastTime - currentTime;
}

void Window::Close()
{}

double Window::GetDeltaTime()
{
	return winDeltaTime;
}