#ifndef _LIS_JOYSTICK_H_
#define _LIS_JOYSTICK_H_

#include "base.h"

namespace Leak
{
	namespace Input
	{
		class Joystick: public InputObject
		{
			Util::String mName;
		public:
			enum JoystickIndex
			{
				JOYSTICK_1,
				JOYSTICK_2,
				JOYSTICK_3,
				JOYSTICK_4,
				JOYSTICK_5,
				JOYSTICK_6,
				JOYSTICK_7,
				JOYSTICK_8,
				JOYSTICK_9,
				JOYSTICK_10,
				JOYSTICK_11,
				JOYSTICK_12,
				JOYSTICK_13,
				JOYSTICK_14,
				JOYSTICK_15,
				JOYSTICK_16,
				JOYSTICK_LAST = JOYSTICK_16
			};	
			
			float*						GetJoystickPosition(int index);
			System::Action*	GetJoystickAction(int index);
		protected:
			float*						mJoystickPosition;
			System::Action*	mJoystickAction;
		
			Joystick(JoystickIndex index);
		};
	}
}

#endif