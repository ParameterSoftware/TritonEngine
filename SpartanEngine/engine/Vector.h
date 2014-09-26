#ifndef __SEVECTOR__
#define __SEVECTOR__

#include <iostream>

namespace seu
{
	class Vector
	{
	public:
		T x, y, z;
		Vector(T xyz);
		Vector(T xy, T z);
		Vector(T x, T y, T z);
		bool checkFor(T check);
		Vector operator+(Vector other);
		Vector operator-(Vector other);
		Vector operator*(Vector other);
		Vector operator/(Vector other);
		Vector operator=(Vector other);
		Vector operator+(T other);
		Vector operator-(T other);
		Vector operator*(T other);
		Vector operator/(T other);
		Vector operator=(T other);
		int size();
	};

}

#endif //define(__SEVECTOR__)
