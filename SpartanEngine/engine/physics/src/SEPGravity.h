#ifndef __SEPGRAVITY__
#define __SEPGRAVITY__

#include <iostream>
#include "../../utilities/src/SEVector.h"

class SEPGravity
{
public:
    /**
     *  The constructor of SEPGravity
     *
     *  @param gravity The 2D gravity strength in certains direction that effects all gravity enabled objects
     */
	SEPGravity(SEVector gravity);

	/**
     *  The deconstructor of SEPGravity
     */
	~SEPGravity();

	/**
     *  Gets the current gravity
     *
     *  @return The objects current gravity strength
     */
	virtual SEVector GetGravity();
private:
	SEVector gravity;
};

class SEPGravity3D : public SEPGravity
{
public:
    /**
     *  The constructor of SEPGravity3D
     *
     *  @param grav_strength The strength of the gravitational pull
     *  @param grav_location The location that this gravity is pulling towards
     */
	SEPGravity3D(SEVector grav_strength, SEVector grav_location);

	/**
     *  The deconstructor of SEPGravity3D
     */
	~SEPGravity3D();

	/**
     *  Gets the location of gravity
     *
     *  @return The location of the gravity
     */
	SEVector GetLocation();

    /**
     *  Gets the strength of the gravity
     *
     *  @return The strength of gravity
     */
	SEVector GetGravity();
private:
	SEVector pull_location;
};

#endif //define(__SEPGRAVITY__)
