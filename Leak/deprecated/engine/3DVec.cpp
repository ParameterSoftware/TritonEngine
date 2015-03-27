#include "Vector.h"

using namespace seu;

Vector::Vector( double x, double y, double z )
{
	this->x = x;
	this->y = y;
	this->z = z;
}

bool Vector::checkFor(double check)
{
	if(check == this->x || check == this->y || check == this->z)
		return true;
	return false;
}

Vector Vector::operator+(Vector other)
{
	double x = this->x + other.x;
	double y = this->y + other.y;
	double z = this->z + other.z;
	return Vector(x, y, z);
}

Vector Vector::operator-(Vector other)
{
	double x = this->x - other.x;
	double y = this->y - other.y;
	double z = this->z - other.z;
	return Vector(x, y, z);
}

Vector Vector::operator*(Vector other)
{
	double x = this->x * other.x;
	double y = this->y * other.y;
	double z = this->z * other.z;
	return Vector(x, y, z);
}

Vector Vector::operator/(Vector other)
{
	double x = this->x / other.x;
	double y = this->y / other.y;
	double z = this->z / other.z;
	return Vector(x, y, z);
}

Vector Vector::operator=(Vector other)
{
	double x = this->x = other.x;
	double y = this->y = other.y;
	double z = this->z = other.z;
	return Vector(x, y, z);
}

Vector Vector::operator+(double other)
{
	double x = this->x + other;
	double y = this->y + other;
	double z = this->z + other;
	return Vector(x, y, z);
}

Vector Vector::operator-(double other)
{
	double x = this->x - other;
	double y = this->y - other;
	double z = this->z - other;
	return Vector(x, y, z);
}

Vector Vector::operator*(double other)
{
	double x = this->x * other;
	double y = this->y * other;
	double z = this->z * other;
	return Vector(x, y, z);
}

Vector Vector::operator+(double other)
{
	double x = this->x / other;
	double y = this->y / other;
	double z = this->z / other;
	return Vector(x, y, z);
}

Vector Vector::operator+(double other)
{
	double x = this->x + other;
	double y = this->y + other;
	double z = this->z + other;
	return Vector(x, y, z);
}

int Vector::size()
{
	return 3;
}
