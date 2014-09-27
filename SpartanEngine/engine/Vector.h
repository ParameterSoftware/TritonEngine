#ifndef __SEVECTOR__
#define __SEVECTOR__

#include <iostream>

namespace seu
{
	class Vector
	{
	public:
		double x;
		double y;
		double z;
		Vector(double x = 0, double y = x, double z = y);
		bool checkFor(double check);
		Vector operator+(Vector other);
		Vector operator-(Vector other);
		Vector operator*(Vector other);
		Vector operator/(Vector other);
		Vector operator=(Vector other);
		Vector operator+(double other);
		Vector operator-(double other);
		Vector operator*(double other);
		Vector operator/(double other);
		Vector operator=(double other);
		int size();
	};

}

#endif //define(__SEVECTOR__)
