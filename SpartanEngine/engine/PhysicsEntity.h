#include <iostream>
#include "Vector.h"

#ifndef __SEPENTITY__
#define __SEPENTITY__

namespace sep
{

	/**
	 *	The active Physics Properties that an object can have
	 */
	class PhysicsProperties
	{
	public:
		/**
		 *	The constructor for PhysicsProperties
		 *
		 *	@param gravity		Whether gravity is enabled for this object Default: true
		 *	@param collision	Whether collisions are active in this object Default: true
		 *	@param rigidBody	Whether an object has rigid body transformations (like rotating down a hill as a sphere) Default: true
		 *	@param otherPhysics	Whether an alternate act of physics is taken into account Deafult: true
		 **/
		PhysicsProperties(bool gravity = true, bool collision = true, bool rigidBody = true, bool otherPhysics = true);
		
		/**
		 *	The destructor for PhysicProperties
		 **/
		~PhysicsProperties();

		/**
		 *	Toggles whether gravity is active or not
		 *
		 *	@return Whether gravity is currently enabled
		 **/
		bool ToggleGravity();

		/**
		 *	Toggles whether collision detection is active 
		 *	
		 *	@return Whether collisions are currently active
		 **/
		bool ToggleCollision();

		/**
		 *	Toggles whether Rigid Body transformations are possible
		 *	
		 *	@return Whether rigid bodies for this object are active
		 **/
		bool ToggleRigidBody();

		/**
		 *	Toggles whether physics are possible for this object
		 *	
		 *	@return Whether physics for this object are active
		 **/
		bool TogglePhysics();

		/**
		 *	Toggles whether alternate nondescribe physics are possible
		 *	
		 *	@return Whether alternate nondescribe physics for this object are active
		 **/
		bool ToggleAlternatePhysics();

		/**
		 *	Returns whether gravity is enabled or not
		 *	
		 *	@return If gravity is active for this object
		 **/
		bool HasGravity();

		/**
		 *	Returns whether collisions are enabled or not
		 *	
		 *	@return If collisions are active for this object
		 **/
		bool HasCollision();

		/**
		 *	Returns whether rigid body transformations are enabled or not
		 *	
		 *	@return If rigid body transformations are active for this object
		 **/
		bool HasRigidBody();

		/**
		 *	Returns whether alternate nondescribe physics are enabled or not
		 *	
		 *	@return If alternate nondescribe physics are active for this object
		 **/
		bool UsesAlternatePhysics();
	private:
		bool gravity;
		bool collision;
		bool rigidBody;
		bool otherPhysics;
	};

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
		PhysicsState(seu::Vector position = seu::Vector(), seu::Vector rotation = seu::Vector(), seu::Vector velocity = seu::Vector(), seu::Vector acceleration = seu::Vector(), PhysicsProperties pProps = PhysicsProperties());

		/**
		 *  The deconstructor of PhysicsState
		 */
		~PhysicsState();

		/**
		 *  Gets the current PhysicsProperties for this PhysicState
		 *
		 *  @return PhysicsProperties of this object
		 */
		PhysicsProperties GetPhysicsProperties();

		seu::Vector position; ///< The States' current position
		seu::Vector rotation; ///< The States' current rotation
		seu::Vector velocity; ///< The States' current velocity
		seu::Vector acceleration; ///< The States' current acceleration
	private:
		PhysicsProperties physicsProps ///< The properties for this physics state
	};

	class PhysicsEntity
	{
	public:
		/**
		 *  The constructor of PhysicsEntity
		 *
		 *  @param state The PhysicsState that represents this entity
		 */
		PhysicsEntity(PhysicsState state);

		/**
		 *  The deconstructor of PhysicsEntity
		 */
		~PhysicsEntity();

		/**
		 *  The function that updates the this PhysicsEntity
		 */
		void Update();
		PhysicsState pState; ///< The PhysicsState that represents this entity
	};
}

#endif /* defined(__SEPENTITY__) */
