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