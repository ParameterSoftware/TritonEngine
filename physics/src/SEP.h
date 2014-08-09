#ifndef __SEP__
#define __SEP__

#include <iostream>
#include "SEVector.h"

class SEPGravity
{
public:
	SEPGravity(SEvector gravity);
	~SEPGravity();
	SEVector GetGravity();
private:
	SEVector gravity;
};

class SEPGravity3D : public SEPGravity
{
public:
	SEPGravity3D(SEVector gravity, SEVector pull_location);
	~SEPGravity3D();
	SEVector GetLocation();
private:
	SEVectir pull_location;
};

#endif //define(__SEP__)
