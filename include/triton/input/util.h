#ifndef _LIS_UTIL_H_
#define _LIS_UTIL_H_

#include "key.h"
#include "mouse.h"
#include "joystick.h"

namespace Tri
{
	namespace Input
	{		
		class InputInterface;
		class InputObject;
		
		class InputManager
		{
			Util::DList<Keybind*> 		m_KeybindsPList;
			Key									m_Keys[Key::LAST+1];
			Mouse*								m_pMouse;
			Joystick							m_Joysticks[Joystick::JOYSTICK_LAST+1]
			
			InputInterface* 					m_pInterface;
		public:
			InputManager(InputInterface* pInterface): m_pInterface(pInterface) {}
			
			/** @brief Creates keybinds
			 *  
			 *  @param key The KeyIndex for the keybind to check
			 */
			const KeyBind	CreateKeybind(Key::KeyIndex key);
			Mouse*				FindMouse(InputID id);
			Joystick*			GetJoystick(Joystick::JoystickIndex id);
			
			~InputManager()
			{
				delete m_pMouse;
				for(Util::DList<Keybind*>::iterator it = m_KeybindsPList.begin(); it != m_KeybindsPList.end(); ++it) delete *it;
			}
		};
		
		struct InputInterface
		{
			virtual InputInterface()
			{
				InputManager(*this);
			}
		
			virtual Key* 		GetKeyFromID(InputID id) = 0;
			virtual Mouse*	GetMouse(InputID id)  = 0;
			virtual Joystick*	GetJoystick(InputID id) { return NULL; }
		};
	}
}

#endif