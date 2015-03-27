#include "Vector.h"

using namespace seu;

DDVector::DDVector(double x, double y)
{
	this->x = x;
	this->y = y;
}

bool DDVector::checkFor(double check)
{
	if(check == this->x || check == this->y)
		return true;
	return false;
}

Vector Vector::operator+(Vector other)
{
	double x = this->x + other.x;
	double y = this->y + other.y;
	return Vector(x, y, z);
}

Vector Vector::operator-(Vector other)
{
	double x = this->x - other.x;
	double y = this->y - other.y;
	return Vector(x, y, z);
}

Vector Vector::operator*(Vector other)
{
	double x = this->x * other.x;
	double y = this->y * other.y;
	return Vector(x, y, z);
}

Vector Vector::operator/(Vector other)
{
	double x = this->x / other.x;
	double y = this->y / other.y;
	return Vector(x, y, z);
}

Vector Vector::operator=(Vector other)
{
	double x = this->x = other.x;
	double y = this->y = other.y;
	return Vector(x, y, z);
}

Vector Vector::operator+(double other)
{
	double x = this->x + other;
	double y = this->y + other;
	return Vector(x, y, z);
}

Vector Vector::operator-(double other)
{
	double x = this->x - other;
	double y = this->y - other;
	return Vector(x, y, z);
}

Vector Vector::operator*(double other)
{
	double x = this->x * other;
	double y = this->y * other;
	return Vector(x, y, z);
}

Vector Vector::operator+(double other)
{
	double x = this->x / other;
	double y = this->y / other;
	return Vector(x, y, z);
}

Vector Vector::operator+(double other)
{
	double x = this->x + other;
	double y = this->y + other;
	return Vector(x, y, z);
}

int Vector::size()
{
	return 2;
}
