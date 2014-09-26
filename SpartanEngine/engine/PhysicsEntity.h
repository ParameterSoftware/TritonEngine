#include <iostream>
#include "Vector.h"

#ifndef __SEPENTITY__
#define __SEPENTITY__

namespace sep
{
	class PhysicsProperties
	{
	public:
		/**
		 *	[Short Description]
		 *
		 *	[Long Description]
		 *	[Long Description]
		 *
		 *	@param paramamter
		 *	@param paramater2
		 *	
		 *	@return returns doc
		 **/
		PhysicsProperties(bool gravity = true, bool collision = true, bool rigidBody = true, bool otherPhysics = true);
		~PhysicsProperties();
		bool ToggleGravity();
		bool ToggleCollision();
		bool ToggleRigidBody();
		bool TogglePhysics();
		bool ToggleAlternatePhysics();
		bool HasGravity();
		bool HasCollision();
		bool HasRigidBody();
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
		PhysicsState(seu::Vector position, seu::Vector rotation, seu::Vector velocity, seu::Vector acceleration);

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

		seu::Vector position; ///< The States' current position
		seu::Vector rotation; ///< The States' current rotation
		seu::Vector velocity; ///< The States' current velocity
		seu::Vector acceleration; ///< The States' current acceleration
	private:
		bool hasPhysics; ///< The physics flag
		bool useGravity; ///< The gravity flag
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
