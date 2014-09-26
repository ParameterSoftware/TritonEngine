#include "Vector.h"

using namespace seu;

template<typedef T>
Vector::Vector( T xyz )
{
	x = xyz;
	y = xyz;
	z = xyz;
}

Vector::Vector( T xy, T z )
{
	x = xy;
	y = xy;
	this.z = z
}

Vector::Vector( T x, T y, T z )
{
	this.x = x;
	this.y = y;
	this.z = z;
}

bool Vector::checkFor(T check)
{
	if(check == this.x || check == this.y || check == this.z)
		return true;
	return false;
}

Vector Vector::operator+(Vector other)
{
	T x = this.x + other.x;
	T y = this.y + other.y;
	T z = this.z + other.z;
	return Vector(x, y, z);
}

Vector Vector::operator-(Vector other)
{
	T x = this.x - other.x;
	T y = this.y - other.y;
	T z = this.z - other.z;
	return Vector(x, y, z);
}

Vector Vector::operator*(Vector other)
{
	T x = this.x * other.x;
	T y = this.y * other.y;
	T z = this.z * other.z;
	return Vector(x, y, z);
}

Vector Vector::operator/(Vector other)
{
	T x = this.x / other.x;
	T y = this.y / other.y;
	T z = this.z / other.z;
	return Vector(x, y, z);
}

Vector Vector::operator=(Vector other)
{
	T x = this.x = other.x;
	T y = this.y = other.y;
	T z = this.z = other.z;
	return Vector(x, y, z);
}

Vector Vector::operator+(T other)
{
	T x = this.x + other;
	T y = this.y + other;
	T z = this.z + other;
	return Vector(x, y, z);
}

Vector Vector::operator-(T other)
{
	T x = this.x - other;
	T y = this.y - other;
	T z = this.z - other;
	return Vector(x, y, z);
}

Vector Vector::operator*(T other)
{
	T x = this.x * other;
	T y = this.y * other;
	T z = this.z * other;
	return Vector(x, y, z);
}

Vector Vector::operator+(T other)
{
	T x = this.x / other;
	T y = this.y / other;
	T z = this.z / other;
	return Vector(x, y, z);
}

Vector Vector::operator+(T other)
{
	T x = this.x = other;
	T y = this.y = other;
	T z = this.z = other;
	return Vector(x, y, z);
}

int Vector::size()
{
	return 3;
}
