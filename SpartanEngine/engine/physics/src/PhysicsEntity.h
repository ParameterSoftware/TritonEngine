#ifndef __SEPENTITY__
#define __SEPENTITY__

#include <iostream>
#include "../../utilities/src/Vector.h"

/**
 *  The physic holder for entities
 *
 **/
class PhysicsState
{
public:
    /**
     *  The constructor of PhysicsState
     *
     *  @param position The position this state holds for its object
     *  @param rotation The rotation(recommended in degrees) this state holds for its object
     *  @param velocity The velocity this state holds for its object (increases the position according to its states)
     *  @param acceleration The acceleration this state holds for it object (increases the velocity according to it state)
     */
	PhysicsState(Vector position, Vector rotation, Vector velocity, Vector acceleration);

	/**
     *  The constructor of PhysicsState
     *
     *  @param position The position this state holds for its object
     *  @param rotation The rotation(recommended in degrees) this state holds for its object
     */
	PhysicsState(SEVector position, SEVector rotation);

	/**
     *  The constructor of PhysicsState
     */
	PhysicsState();

	/**
     *  The deconstructor of PhysicsState
     */
	~PhysicsState();

	/**
     *  Toggles Gravity
     */
	void ToggleGravity();

	/**
     *  The constructor of PhysicsState
     *
     *  @param toggleGravity Determines whether it also toggles gravity(default: true);
     */
	void TogglePhysics(bool toggleGravity = true);

	/**
     *  Checks whether gravity is enabled
     *
     *  @return true if it has gravity, false otherwise
     */
	bool UsesGravity();

	/**
     *  Checks whether physics are enabled (besides gravity)
     *
     *  @return true if it has physics, false otherwise
     */
	bool HasPhysics();

	Vector position; ///< The States' current position
	Vector rotation; ///< The States' current rotation
	Vector velocity; ///< The States' current velocity
	Vector acceleration; ///< The States' current acceleration
private:
	bool hasPhysics; ///< The physics flag
	bool useGravity; ///< The gravity flag
};

class PhysicsEntity
{
public:
    /**
     *  The constructor of SEPEntity
     *
     *  @param state The PhysicsState that represents this entity
     */
	PhysicsEntity(PhysicsState state);

	/**
     *  The deconstructor of SEPEntity
     */
	~PhysicsEntity();

	/**
     *  The function that updates the this SEPEntity
     */
	void Update();
	PhysicsState pState; ///< The PhysicsState that represents this entity
};

#endif /* defined(__SEPENTITY__) */
