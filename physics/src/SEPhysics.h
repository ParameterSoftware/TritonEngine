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
	static getInstance();
	setGravity(SEVector gravity);
};


#endif //define(__SEP__)
