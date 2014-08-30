#include "SEPGravity.h"

SEPGravity::SEPGravity(SEvector gravity)
{
	this->gravity = gravity;
}

SEPGravity::~SEPGravity() {}

SEVector SEPGravity::GetGravity()
{
	return gravity;
}

SEPGravity3D::SEPGravity3D(SEVector gravity, SEVector pull_location)
{
	this->gravity = gravity;
	this->pull_location = pull_location;
}

SEPGravity3D::~SEPGravity3D() {}

SEVector SEPGravity3D::GetLocation()
{
	return pull_location;
}
