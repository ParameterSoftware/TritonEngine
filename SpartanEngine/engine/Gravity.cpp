#include "Gravity.h"
#include "../../utilities/src/Vector.h"

Gravity::Gravity(Vector gravity)
{
	this->gravity = gravity;
}

Gravity::~Gravity() {}

Vector Gravity::GetGravity()
{
	return gravity;
}

Gravity3D::Gravity3D(Vector gravity, Vector pull_location)
{
	this->gravity = gravity;
	this->pull_location = pull_location;
}

Gravity3D::~Gravity3D() {}

Vector Gravity3D::GetLocation()
{
	return pull_location;
}
