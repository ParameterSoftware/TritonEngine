#ifndef _LIS_KEY_H_
#define _LIS_KEY_H_

#include "base.h"

namespace Tri
{
	namespace Input
	{	
		struct Key: public InputObject
		{		
			enum KeyIndex
			{
				UNKNOWN = -1,
				SPACE = 32,																			/*   */
				APOSTROPHE = 39,																	/* ' */
				COMMA = 44,																			/* , */
				MINUS,																						/* - */
				PERIOD,																					/* . */
				SLASH,																					/* / */
				NUM_0, NUM_1, NUM_2, NUM_3, NUM_4, 
						NUM_5, NUM_6, NUM_7, NUM_8, NUM_9, 						/* Default Numerical Keys */
				SEMICOLON = 59,																	/* ; */
				EQUAL = 61,																			/* = */
				A = 65, B, C, D, E, F, G, H, I, J, K, 
						L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z, 						/* Letter Keys */
				LEFT_BRACKET, 																		/* [ */
				BACKSLASH, 																			/* \ */
				RIGHT_BRACKET,																	/* ] */
				GRAVE_ACCENT = 96,  															/* ` */
				WORLD_1 = 161, WORLD_2, 													/* Non-US Keys */
				ESCAPE = 256, ENTER, TAB, BACKSPACE, INSERT, DELETE,	/* Function Keys */
				RIGHT, LEFT, DOWN, UP, 														/* Arrow Keys */
				PAGE_UP, PAGE_DOWN,														/* Page Keys */
				HOME, END,																			/* Home and End Keys */
				CAPS_LOCK = 280, SCROLL_LOCK, NUM_LOCK, 					/* Lock Keys */
				PRINT_SCREEN,																		/* PrntScr Key */
				PAUSE,																					/* Pause Key */
				F1 = 290, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, 
					F12, F13, F14, F15, F16, F17, F18, F19, F20, 
									F21,F22, F23, F24, F25, 										/* F-Numerical Function Keys */
				KP_0 = 320, KP_1, KP_2, KP_3, KP_4, KP_5, KP_6, KP_7, 
						KP_8, KP_9, 																	/* Keypad Numerical Keys */
				KP_DECIMAL, KP_DIVIDE, KP_MULTIPLY, KP_SUBTRACT, 
					KP_ADD, KP_ENTER, KP_EQUAL, 										/* Keypad Non-Numerical Keys */
				LEFT_SHIFT = 340, LEFT_CONTROL, LEFT_ALT, LEFT_SUPER, /* Left Mod Keys */
				RIGHT_SHIFT, RIGHT_CONTROL, RIGHT_ALT, RIGHT_SUPER,	/* Right Mod Keys */
				MENU,																						/* Menu Key */
				LAST = MENU																			/* Last Key (Size) */
			};
			
			System::Action 	GetAction();
			KeyIndex				GetKey();
			bool						IsPressed();
			bool						IsKey(KeyIndex index);
		private:
			KeyIndex 				m_Key;
		protected:
			System::Action* 	m_Action;
			
			Key(KeyIndex index): m_Key(index) {}
		};
		
		class Keybind: public Key
		{
		public:
			/** @brief The function signature for key callbacks
			 *  
			 *  The function signature for key callbacks for use with keybinds
			 *  
			 *  @param[in] scancode The scancode that is currently representing the key
			 *  @param[in] action The action the key is currently expressing
			 *  @param[in] mods The current bit field modifier describing what modifier keys were held
			 */
			typedef void (* keycallfun)(int, System::Action, int);
		
			KeyBind(KeyIndex index): Key(index) {}
			
			void						SetKey(KeyIndex index);
			void						SetKeyCallback(keycallfun callback);
		private:
			keycallfun 			m_Callback;
		};
	}
}

#endif