#ifndef __SEVECTOR__
#define __SEVECTOR__

#include <iostream>

namespace seu
{
	struct Vector
	{
		double x;
		double y;
		double z;
		Vector(double x = 0, double y = 0, double z = 0);
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

	struct DDVector
	{
		double x, y;
		DDVector(double x = 0, double y = 0);
		bool checkFor(double check);
		DDVector operator+(DDVector other);
		DDVector operator-(DDVector other);
		DDVector operator*(DDVector other);
		DDVector operator/(DDVector other);
		DDVector operator=(DDVector other);
		DDVector operator+(double other);
		DDVector operator-(double other);
		DDVector operator*(double other);
		DDVector operator/(double other);
		DDVector operator=(double other);
		int size();
	};

}

#endif //define(__SEVECTOR__)
