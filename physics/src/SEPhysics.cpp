#include "SEPhysics.h"

SEPhysics::SEPhysics()
{
}

SEPhysics SEPhysics::getInstance()
{
	if(instance == NULL)
		instance = new SEPhysics();
	return instance;
}

void SEPhysics::setGravity(SEVector gravity)
{
	this.gravity = gravity;
}

SEVector SEPhysics::getGravity()
{
	return this.gravity
}
