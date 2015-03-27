#include <exception>
#include "utils.h"

using namespace Leak::Utility;

///////////////////////////////////////////////////////
//////////////Vector Methods///////////////////////////
///////////////////////////////////////////////////////
Vec2::Vec2(int x, int y): x(x), y(y) {}

Vector Vec2::operator+(Vector v)
{
	Vec2 v2 = (Vec2) v;
	v2.x = this->x + v2.x;
	v2.y = this->y + v2.y;
	return v2;
}

Vector Vec2::operator-(Vector v)
{
	Vec2 v2 = (Vec2) v;
	v2.x = this->x - v2.x;
	v2.y = this->y - v2.y;
	return v2;
}

Vector Vec2::operator*(Vector v)
{
	Vec2 v2 = (Vec2) v;
	v2.x = this->x * v2.x;
	v2.y = this->y * v2.y;
	return v2;
}

Vector Vec2::operator/(Vector v)
{
	Vec2 v2 = (Vec2) v;
	v2.x = this->x / v2.x;
	v2.y = this->y / v2.y;
	return v2;
}

Vector Vec2::operator%(Vector v)
{
	Vec2 v2 = (Vec2) v;
	v2.x = this->x % v2.x;
	v2.y = this->y % v2.y;
	return v2;
}

Vec2 Vec2::distance(Vec2 vec2)
{
	return (*this - vec2);
}

Vec3::Vec3(int x, int y, int z): x(x), y(y), z(z) {}
Vec3::Vec3(const Vec2& vec): x(vec.x), y(vec.y) {}

Vec3& Vec3::operator=(const Vec2& vec) {return *this;}

Vec3::operator Vec2() {return Vec2(this->x, this->y);}

Vector Vec3::operator+(Vector v)
{
	Vec3 v2 = (Vec3) v;
	v2.x = this->x + v2.x;
	v2.y = this->y + v2.y;
	v2.z = this->z + v2.z;
	return v2;
}

Vector Vec3::operator-(Vector v)
{
	Vec3 v2 = (Vec3) v;
	v2.x = this->x - v2.x;
	v2.y = this->y - v2.y;
	v2.z = this->z - v2.z;
	return v2;
}

Vector Vec3::operator*(Vector v)
{
	Vec3 v2 = (Vec3) v;
	v2.x = this->x * v2.x;
	v2.y = this->y * v2.y;
	v2.z = this->z * v2.z;
	return v2;
}

Vector Vec3::operator/(Vector v)
{
	Vec3 v2 = (Vec3) v;
	v2.x = this->x / v2.x;
	v2.y = this->y / v2.y;
	v2.z = this->z / v2.z;
	return v2;
}

Vector Vec3::operator%(Vector v)
{
	Vec3 v2 = (Vec3) v;
	v2.x = this->x % v2.x;
	v2.y = this->y % v2.y;
	v2.z = this->z % v2.z;
	return v2;
}

Vec2 Vec3::distance(Vec2 vec2)
{
	return (*this - (Vec3)vec2);
}

Vec2F::Vec2F(float x, float y): x(x), y(y) {}

Vector Vec2F::operator+(Vector v)
{
	Vec2F v2 = (Vec2F) v;
	v2.x = this->x + v2.x;
	v2.y = this->y + v2.y;
	return v2;
}

Vector Vec2F::operator-(Vector v)
{
	Vec2F v2 = (Vec2F) v;
	v2.x = this->x - v2.x;
	v2.y = this->y - v2.y;
	return v2;
}

Vector Vec2F::operator*(Vector v)
{
	Vec2F v2 = (Vec2F) v;
	v2.x = this->x * v2.x;
	v2.y = this->y * v2.y;
	return v2;
}

Vector Vec2F::operator/(Vector v)
{
	Vec2F v2 = (Vec2F) v;
	v2.x = this->x / v2.x;
	v2.y = this->y / v2.y;
	return v2;
}

Vector Vec2F::operator%(Vector v)
{
	Vec2F v2 = (Vec2F) v;
	v2.x = this->x % v2.x;
	v2.y = this->y % v2.y;
	return v2;
}

Vec3F::Vec3F(float x, float y, float z): x(x), y(y), z(z) {}
Vec3F::Vec3F(const Vec2F& vec): x(vec.x), y(vec.y) {}

Vec3F& Vec3F::operator=(const Vec2F& vec) {return *this;}

Vec3F::operator Vec2F() {return Vec2F(this->x, this->y);}

Vector Vec3F::operator+(Vector v)
{
	Vec3F v2 = (Vec3F) v;
	v2.x = this->x + v2.x;
	v2.y = this->y + v2.y;
	v2.z = this->z + v2.z;
	return v2;
}

Vector Vec3F::operator-(Vector v)
{
	Vec3F v2 = (Vec3F) v;
	v2.x = this->x - v2.x;
	v2.y = this->y - v2.y;
	v2.z = this->z - v2.z;
	return v2;
}

Vector Vec3F::operator*(Vector v)
{
	Vec3F v2 = (Vec3F) v;
	v2.x = this->x * v2.x;
	v2.y = this->y * v2.y;
	v2.z = this->z * v2.z;
	return v2;
}

Vector Vec3F::operator/(Vector v)
{
	Vec3F v2 = (Vec3F) v;
	v2.x = this->x / v2.x;
	v2.y = this->y / v2.y;
	v2.z = this->z / v2.z;
	return v2;
}

Vector Vec3F::operator%(Vector v)
{
	Vec3F v2 = (Vec3F) v;
	v2.x = this->x % v2.x;
	v2.y = this->y % v2.y;
	v2.z = this->z % v2.z;
	return v2;
}
///////////////////////////////////////////////////////
//End of Vector Methods////////////////////////////////
///////////////////////////////////////////////////////

Exception::Exception(String msg) : msg(msg) {}

Exception::what()
{
	return "Leak Standard Exception: "+msg;
}

using namespace Leak;

Joystick::Joystick(CArray<float> axes, CArray<int> buttons, String name): axesPosition(std::vector<float>(axes.array, axe.size)), 
	buttonState(std::vector<int>(buttons.array, buttons.size)), name(name), present(!name.empty()) {}
	
bool Joystick::isPresent()
{
	return present;
}

float Joystick::getAxePos(int index)
{
	return axesPosition[index];
}

int Joystick::getButtonState(int index)
{
	return buttonState[index];
}

Utility::String getName()
{
	return name;
}

void Window::setAction(int index, leakWindowAction action)
{
	if(index >= action.size())
	{
		actions.resize(index+1);
	}
	
	actions[index] = action;
}

void keyCallback(Window* window, int key, int scancode, int action, int mods)
{
	KeyInput input;
	input.value = key;
	input.action = action;
	input.mods = mods;
	input.scancode = scancode;
	window->setActiveKey(input);
}

Window::Window(String title, int width int height)
{
	if(windowVec.empty() || !glfwInit())
	{
		if(!glfwInit()) throw Utility::Exception("GLFW Failed To Initialize");
	}
	
	this = glfwCreateWindow(title.c_str(), width, height);
	
	setAction(LEAK_WINDOW_ACTION_SHOW, &glfwShowWindow(this));
	setAction(LEAK_WINDOW_ACTION_HIDE, &glfwHideWindow(this));
	setAction(LEAK_WINDOW_ACTION_RESTORE, &glfwRestoreWindow(this));
	setAction(LEAK_WINDOW_ACTION_ICONIFY, &glfwIconifyWindow(this));
	
	id = windowVec.size();
	windowVec.push_back(this);
	
	if(glfwGetCurrentContext() == glfwWin) 
	{
		currentContextId = id;
	}
	
	glfwSetKeyCallback(keyCallback);
}

Window::~Window()
{
	glfwDestroyWindow(glfwWin);
	
	windowVec.erase(id);
	
	if(windowVec.empty())
	{
		glfwTerminate();
	}
}

KeyInput Window::getActiveKey()
{
	return activeKey;
}

bool Window::wasKeyPressed(KeyValue key)
{
	if(getActiveKey().action == GLFW_PRESS) return true;
	return false;
}


int Window::getMouseButton(MouseButtonValue button)
{
	return glfwGetMouseButton(glfwWin, (int)button);
}

Utility::Vec2 Window::getCursorPos()
{
	Utility::Vec2 result;
	glfwGetCursorPos(glfwWin,&result.x,&result.y);
	return result;
}

Utility::Vec2 Window::getWindowSize()
{
	Utility::Vec2 result;
	glfwGetWindowSize(glfwWin,&result.x,&result.y);
	return result;
}

Utility::Vec2 Window::getWindowPos()
{
	Utility::Vec2 result;
	glfwGetWindowPos(glfwWin,&result.x,&result.y);
	return result;
}

Frame Window::getFramebufferSize()
{
	Utility::Vec2 bufferSize;
	glfwGetFramebufferSize(glfwWin,&bufferSize.x, &bufferSize.y);
	return new Frame(v, h);
}

Frame Window::getFrameSize()
{
	Utility::Vec2 v, h;
	glfwGetWindowFrameSize(glfwWin,&h.x, &h.y, &v.x, &v.y);
	return new Frame(v, h);
}

Joystick* Window::getJoystick(JoystickValue joystick)
{
	Utility::CArray axes, buttons;
	if(glfwJoystickPresent(joystick))
	{
		int* size;
		float* axe = glfwGetJoystickAxes(joystick, size);
		axes = new Utility::CArray(axe, *size);
		axe = glfwGetJoystickButtons(joystick, size);
		buttons = new Utility::CArray(axe, *size);
		return new Joystick(axes, buttons, glfwGetJoystickName(joystick));
	}
	
	return new Joystick(axes, buttons);
}

Utility::String Window::getClipboardString()
{
	return new Utility::String(glfwGetClipboardString());
}

int Window::getInputMode(int mode)
{
	return glfwGetInputMode(glfwWin, mode);
}

bool Window::shouldClose()
{
	int flag = glfwGetWindowShouldClose(glfwWin);
	if(flag)
	{
		~Window();
	}
	
	return flag;
}

bool Window::running()
{
	return !shouldClose();
}

void Window::setCurrentContext()
{
	glfwSetCurrentContext(glfwWin);
	currentContextId = id;
}

void Window::setShouldClose()
{
	glfwSetWindowShouldClose(glfwWin, true);
}

void Window::setWindowSize(int width, int height)
{
	glfwSetWindowSize(glfwWin, width, height);
}

void Window::setWindowPos(int x, int y)
{
	glfwSetWindowPos(glfwWin, x, y);
}

void Window::setCursorPos(Utility::Vec2 position)
{
	glfwSetCursorPos(glfwWin, position.x, position.y);
}

void Window::setClipboardString(Utility::String str)
{
	glfwSetClipboardString(glfwWin, str.c_str());
}

void Window::setInputMode(int mode, int value)
{
	glfwSetInputMode(glfwWin, mode, value);
}

void Window::setWindowAction(int action)
{
	actions[action](glfwWin);
}

Window* Window::getContextWindow()
{
	return windowVec[currentContextId];
}

Window* Window::getWindow(int index)
{
	return windowVec[index];
}

Frame::Frame(Utility::Vec2 vertical, Utility::Vec2 horizontal)
{
	this->vertical = vertical;
	this->horizontal = horizontal;
}

Frame::Frame(int posX, int posY, int width, int height)
{
	vertical = new Utility::Vec2(width, width);
	horizontal = new Utility::Vec2(height, height);
}