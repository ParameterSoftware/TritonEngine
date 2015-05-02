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
			
			/** @brief The function signature for mouse callbacks
			 *  
			 *  The function signature for mouse callbacks
			 *  
			 *  @param[in] mouseButton The current checked [Mouse Button](@ref MouseButton)
			 *  @param[in] action The action the button is currently expressing
			 *  @param[in] mods The current bit field modifier describing what modifier keys were held
			 */
			typedef void (* mousecallfun)(MouseButton, System::Action, int);
			
			System::Action GetButtonAction(MouseButton button);
			void 					SetMouseCallback(mousecallfun callback);
		protected:
			Mouse(InputID id);
			System::Action	m_ButtonAction[LAST_BUTTON+1]
		private:
			mousecallfun m_Callback;
		};
	}
}

#endif