#ifndef _LIS_UTIL_H_
#define _LIS_UTIL_H_

#include "key.h"
#include "mouse.h"
#include "joystick.h"

namespace Leak
{
	namespace Input
	{		
		class InputInterface;
		class InputObject;
		
		class InputManager
		{
			LUS::DList<Keybind> 	mKeybinds;
			Key								mKeys[Key::KeyIndex::LAST+1];
			Mouse*							mpMouse;
			
			InputInterface* 				mInterface;
		public:
			InputManager(InputInterface* interface): mInterface(interface) {}
			
			void 			Update();
			
			/** @brief Allows creation of keybinds
			 *  
			 *  @param key The KeyIndex for the keybind to check
			 *  @param pAction [out] Pointer to the action the keybind is representing @ref Leak::Input::System::Action (output)
			 */
			void		 	CreateKeybind(Key::KeyIndex key, System::Action* pAction);
			Mouse*		FindMouse(InputID id);
			Joystick	GetJoystick(Enum::JoystickAdapter id);
			
			~InputManager()
			{
				delete mouse;
				for(LUS::DList<Keybind*>::iterator it = keybinds.begin(); it != keybinds.end(); ++it) delete *it;
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
			virtual Joystick	GetJoystick(InputID id) {}
		};
	}
}

#endif