#ifndef __SEPGRAVITY__
#define __SEPGRAVITY__

#include <iostream>
#include "../../utilities/src/Vector.h"

class Gravity
{
public:
    /**
     *  The constructor of SEPGravity
     *
     *  @param gravity The 2D gravity strength in certains direction that effects all gravity enabled objects
     */
	Gravity(Vector gravity);

	/**
     *  The deconstructor of SEPGravity
     */
	~Gravity();

	/**
     *  Gets the current gravity
     *
     *  @return The objects current gravity strength
     */
	virtual Vector GetGravity();
private:
	SEVector gravity;
};

class Gravity3D : public Gravity
{
public:
    /**
     *  The constructor of SEPGravity3D
     *
     *  @param grav_strength The strength of the gravitational pull
     *  @param grav_location The location that this gravity is pulling towards
     */
	Gravity3D(Vector grav_strength, Vector grav_location);

	/**
     *  The deconstructor of SEPGravity3D
     */
	~Gravity3D();

	/**
     *  Gets the location of gravity
     *
     *  @return The location of the gravity
     */
	Vector GetLocation();

    /**
     *  Gets the strength of the gravity
     *
     *  @return The strength of gravity
     */
	Vector GetGravity();
private:
	Vector pull_location;
};

#endif //define(__SEPGRAVITY__)
