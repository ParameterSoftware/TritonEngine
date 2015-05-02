#ifndef _LUS_UTIL_H_
#define _LUS_UTIL_H_

#include <string>
#incudle <vector>
#include <memory>

namespace Leak
{
	namespace Util
	{
		typedef std::string String; ///< A standard C++ string used as short hand for std::string
		
		template<class charT>
		class BasicCString
		{
			charT* 	m_str;
			size_t	m_size;
		public:
			void SetString(charT* str)
			{
				m_size = strlen(str);
				m_str = str;
			}
			
			BaseString ()
			{
			   m_str = NULL;
			   m_size = 0;
			}
			
			BaseString (charT* str)
			{
			   SetString(str);
			}
			
			const charT* c_str()
			{
				return m_str;   
			}
			
			const size_t size()
			{
				return m_size;   
			}
			
			BaseString& operator= (const BaseString& str)
			{
				SetString(str.c_str());
				return (*this);
			}
			
			BaseString& operator= (const charT* s)
			{
				char* str = NULL;
				strcpy(str, s);
				SetString(str);
				return (*this);
			}
			
			BaseString& operator= (charT* s)
			{
				SetString(s);
				return (*this);
			}   
			
			BaseString& operator= (charT c)
			{
				m_size = 1;
				m_str = &c;
				return (*this);
			}
			
			charT& operator[] (size_t pos)
			{
				pos = CLAMP(pos, 0, m_size-1);
				return m_str[pos];
			}
			
			const charT& operator[] (size_t pos) const
			{
				pos = CLAMP(pos, 0, m_size-1);
				return m_str[pos];
			}
			
			char& at (size_t pos)
			{
				return (*this)[pos];
			}
			
			const char& at (size_t pos) const
			{
				return (*this)[pos];
			}
			
			void clear()
			{
				(*this) = BaseString<charT>();
			}
			
			bool empty()
			{
				return m_size == 0;   
			}
		};
		
		typedef BasicCString<char> CString;
		
		/// @brief A standard C++ vector for better clarification and short hand of vectors
		template<typename T, class Alloc = std::allocator<T>>
		class DynArray : public std::vector<T, Alloc>
		{};
		// This is a discouraged practice (normally) but if I don't screw with regular methods or members, this should be good, especially since this is only supposed to be a shorthand version of std::vector
		
		typedef signed char 		byte;
		typedef unsigned char 	ubyte;
		
		/** A simple and efficient clamp function
		 *  
		 *  @param x input
		 *  @param a minimum number
		 *  @param b maximum number
		 */
		template<typename T>T clamp(T x, T a, T b)
		{
			return x < a ? a : (x > b ? b : x);
		}
	}
}

#endif