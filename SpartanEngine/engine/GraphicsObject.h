#include <iostream>
#include "Vector.h"

#ifndef __GOBJ__
#define __GOBJ__

class GraphicsObject
{
public:
	GraphicsObject(Vector position);
	virtual bool Start();
	virtual void Update();
	virtual void Stop();
	void SetPosition(Vector pos);
	Vector GetPosition();
private:
	Vector position;
	virtual void UpdateGraphics();
};

#endif /* define(__GOBJ__) */
