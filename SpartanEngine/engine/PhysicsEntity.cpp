#include "SEPEntity.h"

using PhysicsState;
using SEPEntity;

EntityState(SEVector position, SEVector rotation, SEVector velocity, SEVector acceleration)
{
	this->position = position;
	this->rotation = rotation;
	this->velocity = velocity;
	this->acceleration = acceleration;
	this->hasPhysics = true;
	this->usesGravity = true;
}
EntityState(SEVector position, SEVector rotation)
{
	this->position = position;
	this->rotation = rotation;
	this->velocity = 0;
	this->acceleration = 0;
	this->hasPhysics = true;
	this->usesGravity = true;
}

EntityState()
{
	this->position = 0;
	this->rotation = 0;
	this->velocity = 0;
	this->acceleration = 0;
	this->hasPhysics = true;
	this->usesGravity = true;
}

~EntityState()
{}

void ToggleGravity()
{
	usesGravity = !usesGravity;
}

void TogglePhysics(bool toggleGravity)
{
	if(toggleGravity)
		ToggleGravity();
	hasPhysics = !hasPhysics;
}

bool UsesGravity()
{
	return usesGravity;
}

bool HasPhysics()
{
	return hasPhysics;
}

SEPEntity(PhysicsState state)
{
	this->pState = state;
}

~SEPEntity()
{
	~PhysicsState();
}