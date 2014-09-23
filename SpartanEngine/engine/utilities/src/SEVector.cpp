#include "SEVector.h"

template<typedef T>
SEVector::SEVector( T xyz )
{
	x = xyz;
	y = xyz;
	z = xyz;
}

SEVector::SEVector( T xy, T z )
{
	x = xy;
	y = xy;
	this.z = z
}

SEVector::SEVector( T x, T y, T z )
{
	this.x = x;
	this.y = y;
	this.z = z;
}

bool SEVector::checkFor(T check)
{
	if(check == this.x || check == this.y || check == this.z)
		return true;
	return false;
}

SEVector SEVector::operator+(SEVector other)
{
	T x = this.x + other.x;
	T y = this.y + other.y;
	T z = this.z + other.z;
	return SEVector(x, y, z);
}

SEVector SEVector::operator-(SEVector other)
{
	T x = this.x - other.x;
	T y = this.y - other.y;
	T z = this.z - other.z;
	return SEVector(x, y, z);
}

SEVector SEVector::operator*(SEVector other)
{
	T x = this.x * other.x;
	T y = this.y * other.y;
	T z = this.z * other.z;
	return SEVector(x, y, z);
}

SEVector SEVector::operator/(SEVector other)
{
	T x = this.x / other.x;
	T y = this.y / other.y;
	T z = this.z / other.z;
	return SEVector(x, y, z);
}

SEVector SEVector::operator=(SEVector other)
{
	T x = this.x = other.x;
	T y = this.y = other.y;
	T z = this.z = other.z;
	return SEVector(x, y, z);
}

SEVector SEVector::operator+(T other)
{
	T x = this.x + other;
	T y = this.y + other;
	T z = this.z + other;
	return SEVector(x, y, z);
}

SEVector SEVector::operator-(T other)
{
	T x = this.x - other;
	T y = this.y - other;
	T z = this.z - other;
	return SEVector(x, y, z);
}

SEVector SEVector::operator*(T other)
{
	T x = this.x * other;
	T y = this.y * other;
	T z = this.z * other;
	return SEVector(x, y, z);
}

SEVector SEVector::operator+(T other)
{
	T x = this.x / other;
	T y = this.y / other;
	T z = this.z / other;
	return SEVector(x, y, z);
}

SEVector SEVector::operator+(T other)
{
	T x = this.x = other;
	T y = this.y = other;
	T z = this.z = other;
	return SEVector(x, y, z);
}

int SEVector::size()
{
	return 3;
}
