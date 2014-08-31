#ifndef __SEMATH__
#define __SEMATH__

#include <iostream>
#include "SEVector.h"

/**
 *	Generates a random number
 *	
 *	Generates a random numbers using the standard c++ number generator
 *	with every part handled by the function
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
 *	@return \pi is returned
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
 *	@param square	The number to find the square root
 *
 *	@return The square root of square
 */
double semSqrt(double square);


#endif /* defined(__SEMATH__) */