#ifndef __SEPENTITY__
#define __SEPENTITY__

#include <iostream>
#include "SEVector.h"

class EntityState
{
public:
	EntityState(SEVector position, SEVector rotation, SEVector velocity, SEVector acceleration);
	EntityState();
	~EntityState();
	SEVector GetPositon();
	SEVector GetRotation();
	SEVector GetVelocity();
	SEVector GetAcceleration();
	void ToggleGravity();
	void TogglePhysics(bool toggleGravity = true);
	bool UsesGravity();
	bool HasPhysics();
private:
	SEVector position;
	SEVector rotation;
	SEVector velocity;
	SEVector acceleration;
	bool hasPhysics;
	bool useGravity;
};

class SEPEntity
{
public:
	SEPEntity(EntityState state);
	~SEPEntity();
	EntityState entityState;
};

#endif /* defined(__SEPENTITY__) */
