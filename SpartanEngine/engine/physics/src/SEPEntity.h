#ifndef __SEPENTITY__
#define __SEPENTITY__

#include <iostream>
#include "SEVector.h"

class PhysicsState
{
public:
	EntityState(SEVector position, SEVector rotation, SEVector velocity, SEVector acceleration);
	EntityState(SEVector position, SEVector rotation);
	EntityState();
	~EntityState();
	void ToggleGravity();
	void TogglePhysics(bool toggleGravity = true);
	bool UsesGravity();
	bool HasPhysics();
	
	SEVector position;
	SEVector rotation;
	SEVector velocity;
	SEVector acceleration;
private:
	bool hasPhysics;
	bool useGravity;
};

class SEPEntity
{
public:
	SEPEntity(PhysicsState state);
	~SEPEntity();
	Update();
	PhysicsState pState;
};

#endif /* defined(__SEPENTITY__) */
