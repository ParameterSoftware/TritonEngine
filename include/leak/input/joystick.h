#ifndef _LIS_JOYSTICK_H_
#define _LIS_JOYSTICK_H_

#include "base.h"

namespace Leak
{
	namespace Input
	{
		class Joystick: public InputObject
		{
			Util::String m_Name;
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
			
			/** @brief The function signature for key callbacks
			 *  
			 *  The function signature for key callbacks for use with keybinds
			 *  
			 *  @param[in] axeCount The axe count for the array axes
			 *  @param[in] axes The array of axes with a length of axeCount
			 *  @param[in] buttonCount The button count for array buttons
			 *  @param[in] buttons The array of buttons with a length of buttonCount
			 *  @param[in] mods The current bit field modifier describing what modifier keys were held
			 */
			typedef void (* joystickcallfun)(int, float*, int, System::Action*, int);
			
			float						GetJoystickPosition(int index);
			System::Action		GetJoystickAction(int index);
			Util::String				GetName();
			JoystickIndex		GetJoystickIndex();
			void						SetJoystickCallback(joystickcallfun callback);
			bool						IsJoystickIndex(JoystickIndex index);
			bool						IsPresent();
		protected:
			float*						m_JoystickPosition;
			System::Action*	m_JoystickAction;
		
			Joystick(JoystickIndex index);
		private:
			joystickcallfun m_Callback;
		};
	}
}

#endif