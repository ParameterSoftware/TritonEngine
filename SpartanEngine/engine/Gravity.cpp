#include "Gravity.h"
#include "Vector.h"

using namespace seu;
using namespace sep;

Gravity::Gravity(Vector gravity)
{
	this->gravity = gravity;
}

Gravity::~Gravity() {}

Vector Gravity::GetGravity()
{
	return gravity;
}

Gravity3D::Gravity3D(Vector gravity, Vector grav_location)
{
	this->gravity = gravity;
	this->grav_location = grav_location;
}

Gravity3D::~Gravity3D() {}

Vector Gravity3D::GetLocation()
{
	return grav_location;
}
