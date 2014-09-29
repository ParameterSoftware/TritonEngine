#include "SpartanEngine.h"
#include <GL\glew.h>

#pragma comment(lib, "glfw3")
#pragma comment(lib, "glfw3dll")
#pragma comment(lib, "glew32")
#pragma comment(lib, "glew32s")

bool se::init()
{
	if( !glfwInit() )
	{
		#define SE_GLFW SE_FAILED
		return SE_FAILED;
	}

	glewExperimental = true;
	if( glewInit )
	{
		#define SE_GLEW SE_FAILED
		return SE_FAILED;
	}
	
}