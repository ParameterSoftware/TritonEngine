#include <iostream>
#include "../../utilities/src/Vector.h"

#ifndef __PhysicsObject__
#define __PhysicsObject__

class PhysicsObject
{
public:
	PhysicsObject(Vector position);
	virtual bool Start();
	virtual void Update();
	virtual void Stop();
	void SetPosition(Vector pos);
	Vector GetPosition();
private:
	Vector position;
	virtual void UpdateGraphics();
};

#endif /* define(__PhysicsObject__) */
