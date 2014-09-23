#include <iostream>
#include "../../utilities/src/SEVector.h"

#ifndef __SEGOBJECT__
#define __SEGOBJECT__

class SEGObject
{
public:
	SEGObject(SEVector position);
	virtual bool Start();
	virtual void Update();
	virtual void Stop();
	void SetPosition(SEVector pos);
	SEVector GetPosition();
private:
	SEVector position;
	virtual void UpdateGraphics();
};

#endif /* define(__SEGOBJECT__) */
