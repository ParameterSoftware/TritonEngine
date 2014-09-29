#ifndef __SE__
#define __SE__

#include "Window.h"

#define SE_FAILED	0
#define SE_SUCCESS	1
#define SE_NOTRUN	2

#define SE_GLFW		SE_NOTRUN
#define SE_GLEW		SE_NOTRUN
#define SE_SDL		SE_NOTRUN

namespace se
{
	bool init();
}

#endif /* define(__SE__) */