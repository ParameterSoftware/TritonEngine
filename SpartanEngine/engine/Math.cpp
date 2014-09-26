#include "Math.h"
#include "Vector.h"

#include <stdlib.h>
#include <time.h>  

using namespace sem;

//The most perfected method example (method 14) at http://www.codeproject.com/Articles/69941/Best-Square-Root-Method-Algorithm-Function-Precisi 
//According to the examples there, its better then std::sqrt(n)
double inline __declspec (naked) __fastcall InternalSqrt(double n)
{
	_asm fld qword ptr [esp+4]
	_asm fsqrt
	_asm ret 8
}

double random(double lowerRange, double higherRange)
{
	srand(time(NULL));
	return (lowerRange + rand()) % higherRange;
}

double PI()
{
	return M_PI;
}

Vector distance(Vector point1, Vector point2)
{
	return point1 - point2;
}

double toDegrees(double radian)
{
	return radian*180/PI();
}

double toRadians(double degree)
{
	return degree*PI()/180;
}

double fractionTime(double start, double end, double current)
{
	return ( current - start ) / ( end - start );
}

double sqrt(double square)
{
	return InternalSqrt(square);
}

//The C library already handles functions like sin, cos, tan, ect. perfectly enough
double sin(double x, bool convert)
{
	if(convert)
		x = ToDegrees(x);
	return std::sin(x);
}

double cos(double x, bool convert)
{
	if(convert)
		x = toDegrees(x);
	return std::cos(x);
}

double tan(double x, bool convert)
{
	if(convert)
		x = toDegrees(x);
	return std::tan(x);
}

double atan(double x, bool convert)
{
	if(convert)
		x = toDegrees(x);
	return std::atan(x);
}

double atan2(double x, double y, bool convert)
{
	if(convert)
	{
		x = toDegrees(x);
		y = toDegrees(y);
	}
	return std::atan2(x,y);
}