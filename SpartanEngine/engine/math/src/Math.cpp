#include "Math.h"
#include "../../utilities/src/Vector.h"

#include <stdlib.h>
#include <time.h>  

//The most perfected method example (method 14) at http://www.codeproject.com/Articles/69941/Best-Square-Root-Method-Algorithm-Function-Precisi 
//According to the examples there, its better then std::sqrt(n)
double inline __declspec (naked) __fastcall InternalSqrt(double n)
{
	_asm fld qword ptr [esp+4]
	_asm fsqrt
	_asm ret 8
} 

double semRandom(double lowerRange, double higherRange)
{
	srand(time(NULL));
	return (lowerRange + rand()) % higherRange;
}

double semPI()
{
	return M_PI;
}

Vector semDistance(Vector point1, Vector point2)
{
	return point1 - point2;
}

double semToDegrees(double radian)
{
	return radian*180/semPI();
}

double semToRadians(double degree)
{
	return degree*semPI()/180;
}

double semFractionTime(double start, double end, double current)
{
	return ( current - start ) / ( end - start );
}

double semSqrt(double square)
{
	return InternalSqrt(square);
}

//The C library already handles functions like sin, cos, tan, ect. perfectly enough
double semSin(double x, bool convert)
{
	if(convert)
		x = semToDegrees(x);
	return std::sin(x);
}

double semCos(double x, bool convert)
{
	if(convert)
		x = semToDegrees(x);
	return std::cos(x);
}

double semTan(double x, bool convert)
{
	if(convert)
		x = semToDegrees(x);
	return std::tan(x);
}

double semAtan(double x, bool convert)
{
	if(convert)
		x = semToDegrees(x);
	return std::atan(x);
}

double semAtan2(double x, double y, bool convert)
{
	if(convert)
	{
		x = semToDegrees(x);
		y = semToDegrees(y);
	}
	return std::atan2(x,y);
}