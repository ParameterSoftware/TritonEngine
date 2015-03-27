#ifndef _LIS_MOUSE_H_
#define _LIS_MOUSE_H_

#include "base.h"

namespace Leak
{
	namespace Input
	{
		class Mouse: public InputObject
		{
		public:
			enum MouseButton
			{
				BUTTON_1,
				BUTTON_2,
				BUTTON_3,
				BUTTON_4,
				BUTTON_5,
				BUTTON_6,
				BUTTON_7,
				BUTTON_8,
				LAST_BUTTON = BUTTON_8,
				LEFT_BUTTON = BUTTON_1,
				RIGHT_BUTTON = BUTTON_2,
				MIDDLE_BUTTON = BUTTON_3
			};
			
			System::Action* GetButtonAction(MouseButton button);
		protected:
			Mouse(InputID id);
			System::Action	mButtonAction[LAST_BUTTON+1]
		};
	}
}

#endif