#ifndef __SEP__
#define __SEP__

#include <iostream>
#include "SEVector.h"

class SEPhysics
{
private:
	SEVector gravity;
	static SEPhysics instance;
	SEPhysics();
public:
	static SEPhysics getInstance();
	void setGravity(SEVector gravity);
	SEVector getGravity();
};


#endif //define(__SEP__)
