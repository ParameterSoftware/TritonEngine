#ifndef _LIS_BASE_H_
#define _LIS_BASE_H_

#include <leak/util/util.h>

namespace Tri
{
	namespace Input
	{
		typedef unsigned int InputID;
		
		namespace System
		{
			enum Action
			{
				RELEASE,
				PRESS,
				REPEAT
			};
			
			enum KeyMod
			{
				SHIFT = 0x0001,
				CONTROL = 0x0002,
				ALT = 0x0004,
				SUPER = 0x0008
			};
		}
		
		class InputObject
		{
		protected:
			friend class InputManager;
		};
	}
}

#endif