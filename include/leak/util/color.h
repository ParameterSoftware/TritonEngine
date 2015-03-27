#ifndef _LUS_COLOR_H_
#define _LUS_COLOR_H_
namespace Leak
{
	namespace Util
	{
		/**
		 *  @addtogroup lus_color
		 *  @{
		 */
	
		/// @brief An rgb color object
		struct RGB
		{
			const int max = 255;
			const int min = 0;
			unsigned short r;
			unsigned short g;
			unsigned short b;
			RGB(unsigned short r = 0, unsigned short g = 0, unsigned short b = 0): r(clamp(r,min,max), g(clamp(g,min,max)), b(clamp(b,min,max)) {}

			RGB 	invert();
		};
		
		/// @brief An @ref RGB object with Alpha
		///
		/// Based on @ref RGB
		struct RGBA: public RGB
		{
			unsigned short a;

			RGBA(unsigned short r = 0, unsigned short g = 0, unsigned short b = 0, unsigned short a = max): RGB(r,g,b), a(clamp(a,min,max)) {}
			RGBA(const RGB& rgb, unsigned short a = max): RGB(rgb.r, rgb.g, rgb.b), a(clamp(a,min,max) {}

			RGBA& operator=(const RGB& rgb, unsigned short a = max);
			operator RGB();
		};
	}
}
	
#endif