#include "PhysicsEntity.h"

using namespace seu;
using namespace sep;

PhysicsProperties::PhysicsProperties(bool gravity, bool collision, bool rigidBody, bool otherPhysics)
{
	this->gravity = gravity;
	this->collision = collision;
	this->rigidBody = rigidBody;
	this->otherPhysics = otherPhysics;
}

PhysicsProperties::~PhysicsProperties()
{}

bool PhysicsProperties::ToggleGravity()
{
	gravity = !gravity;
	return gravity;
}

bool PhysicsProperties::ToggleCollision()
{
	collision = !collision;
	return collision;
}

bool PhysicsProperties::ToggleRigidBody()
{
	rigidBody = !rigidBody;
	return rigidBody;
}

bool PhysicsProperties::ToggleAlternatePhysics()
{
	otherPhysics = !otherPhysics;
	return otherPhysics;
}

bool PhysicsProperties::TogglePhysics()
{
	bool physics = ToggleGravity() && ToggleCollision() && ToggleRigidBody() && ToggleAlternatePhysics();
	return physics;
}

bool PhysicsProperties::HasGravity()
{
	return gravity;
}

bool PhysicsProperties::HasCollision()
{
	return collision;
}

bool PhysicsProperties::HasRigidBody()
{
	return rigidBody;
}

bool PhysicsProperties::UsesAlternatePhysics()
{
	return otherPhysics;
}

PhysicsState::PhysicsState(Vector position, Vector rotation, Vector velocity, Vector acceleration, PhysicsProperties pProps)
{
	this->position = position;
	this->rotation = rotation;
	this->velocity = velocity;
	this->acceleration = acceleration;
	this->physicsProps = pProps;
}

PhysicsState::~PhysicsState()
{}

PhysicsEntity::PhysicsEntity(PhysicsState state)
{
	this->pState = state;
}

PhysicsEntity::~PhysicsEntity()
{
	this->pState.~PhysicsState();
}