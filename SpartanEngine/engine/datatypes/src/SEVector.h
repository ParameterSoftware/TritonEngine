#ifndef __SEVECTOR__
#define __SEVECTOR__

#include <iostream>

template<typedef T>

class SEVector
{
public:
	T x, y, z;
	SEVector(T xyz);
	SEVector(T xy, T z);
	SEVector(T x, T y, T z);
	bool checkFor(T check);
	SEVector operator+(SEVector other);
	SEVector operator-(SEVector other);
	SSEVector operator*(SEVector other);
	SEVector operator/(SEVector other);
	SEVector operator=(SEVector other);
	SEVector operator+(T other);
	SEVector operator-(T other);
	SEVector operator*(T other);
	SEVector operator/(T other);
	SEVector operator=(T other);
	int size();
}

#endif //define(__SEVECTOR__)
