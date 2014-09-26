#include "PhysicsEntity.h"

using namespace seu;

PhysicsState::PhysicsState(Vector position, Vector rotation, Vector velocity, Vector acceleration)
{
	this->position = position;
	this->rotation = rotation;
	this->velocity = velocity;
	this->acceleration = acceleration;
	this->hasPhysics = true;
	this->useGravity = true;
}

PhysicsState::~PhysicsState()
{}

void PhysicsState::ToggleGravity()
{
	useGravity = !useGravity;
}

void PhysicsState::TogglePhysics(bool toggleGravity)
{
	if(toggleGravity)
		ToggleGravity();
	hasPhysics = !hasPhysics;
}

bool PhysicsState::UsesGravity()
{
	return useGravity;
}

bool PhysicsState::HasPhysics()
{
	return hasPhysics;
}

PhysicsEntity::PhysicsEntity(PhysicsState state)
{
	this->pState = state;
}

PhysicsEntity::~PhysicsEntity()
{
	this->pState.~PhysicsState();
}