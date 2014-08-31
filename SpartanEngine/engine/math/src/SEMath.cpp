
#include "SEMath.h"

#define _USE_MATH_DEFINES
#include <math.h>
#include <stdlib.h>
#include <time.h>  

//The most perfected method example (method 14) at http://www.codeproject.com/Articles/69941/Best-Square-Root-Method-Algorithm-Function-Precisi 
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

SEVector semDistance(SEVector point1, SEVector point2)
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