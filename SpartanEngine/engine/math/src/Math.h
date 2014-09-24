#ifndef __Math__
#define __Math__

#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#undef _USE_MATH_DEFINES
#include "../../utilities/src/Vector.h"

/**
 *	Generates a random number
 *	
 *	Generates a random numbers using the standard c++ number generator
 *	with srand handled by the function
 *
 *	@param lowerRange	The lowest possible number for the generator
 *	@param higherRange	The highest possible number for the generator
 *
 *	@return A random number between lowerRange and higherRange
 */
double semRandom(double lowerRange, double higherRange);

/**
 *	Gets PI
 *	
 *	Gets PI
 *
 *	@return \pi
 */
double semPI();

/**
 *	Calculates the Distance between two points
 *	
 *	Calculates the Distance between two 3D points using 
 *	Spartan Engine Vectors
 *
 *	@param point1	The start point 
 *	@param point2	The end point
 *
 *	@return The Vector difference
 */
SEVector semDistance(SEVector point1, SEVector point2);

/**
 *	Converts Radians to Degrees
 *
 *	@param radian	The radian to convert
 *
 *	@return The degree of radian
 */
double semToDegrees(double radian);

/**
 *	Converts Degrees to Radians
 *
 *	@param degree	The degree to convert
 *
 *	@return The radian of degree
 */
double semToRadians(double degree);

/**
 *	Provides the fraction of time
 *
 *	Provides the fraction of time based on
 *	current
 *
 *	@param start	The start of the time
 *	@param end		The end of the time
 *	@param current	The current time to divide turn into a fraction
 *
 *	@return The fraction of time
 */
double semFractionTime(double start, double end, double current);

/**
 *	Gets the square root of square
 *
 *	Gets the square root of square but is much more accurate and
 *	faster then the standard library
 *
 *	@param square	The number to find the square root
 *
 *	@return The square root of square
 */
double semSqrt(double square);

/**
 *
 *	Gets the sin of x
 *
 *	Gets the sine of x in radians unless convert
 *	is true
 *	
 *	@param x		The number to get the sin of
 *	@param convert	Use to get a degree instead	Default: false
 *	
 *	@return	The sin of x (in radians unless convert = true)
 *
*/
double semSin(double x, bool convert = false);

/**
 *
 *	Gets the cos of x
 *
 *	Gets the cosine of x in radians unless convert
 *	is true
 *	
 *	@param x		The number to get the cos of
 *	@param convert	Use to get a degree instead	Default: false
 *	
 *	@return	The cos of x (in radians unless convert = true)
 *
*/
double semCos(double x, bool convert = false);

/**
 *
 *	Gets the tan of x
 *
 *	Gets the tangent of x in radians unless convert
 *	is true
 *	
 *	@param x		The number to get the tan of
 *	@param convert	Use to get a degree instead	Default: false
 *	
 *	@return	The tan of x (in radians unless convert = true)
 *
*/
double semTan(double x, bool convert = false);


#endif /* defined(__Math__) */