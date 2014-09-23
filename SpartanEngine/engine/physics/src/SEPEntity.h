#ifndef __SEPENTITY__
#define __SEPENTITY__

#include <iostream>
#include "../../utilities/src/SEVector.h"

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
	PhysicsState(SEVector position, SEVector rotation, SEVector velocity, SEVector acceleration);

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

	SEVector position; ///< The States' current position
	SEVector rotation; ///< The States' current rotation
	SEVector velocity; ///< The States' current velocity
	SEVector acceleration; ///< The States' current acceleration
private:
	bool hasPhysics; ///< The physics flag
	bool useGravity; ///< The gravity flag
};

class SEPEntity
{
public:
    /**
     *  The constructor of SEPEntity
     *
     *  @param state The PhysicsState that represents this entity
     */
	SEPEntity(PhysicsState state);

	/**
     *  The deconstructor of SEPEntity
     */
	~SEPEntity();

	/**
     *  The function that updates the this SEPEntity
     */
	void Update();
	PhysicsState pState; ///< The PhysicsState that represents this entity
};

#endif /* defined(__SEPENTITY__) */
