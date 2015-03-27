#ifndef __SEPGRAVITY__
#define __SEPGRAVITY__

#include <iostream>
#include "Vector.h"

namespace sep
{
	class Gravity
	{
	public:
		/**
		 *  The constructor of Gravity
		 *
		 *  @param gravity The 3D gravity strength in certains direction that effects all gravity enabled objects
		 */
		Gravity(seu::Vector gravity);

		/**
		 *  The deconstructor of Gravity
		 */
		~Gravity();

		/**
		 *  Gets the current gravity
		 *
		 *  @return The objects current gravity strength
		 */
		virtual seu::Vector GetGravity();
	private:
		seu::Vector gravity;
	};

	class Gravity3D
	{
	public:
		/**
		 *  The constructor of Gravity3D
		 *
		 *  @param grav_strength The strength of the gravitational pull
		 *  @param grav_location The location that this gravity is pulling towards
		 */
		Gravity3D(seu::Vector grav_location);

		/**
		 *  The deconstructor of Gravity3D
		 */
		~Gravity3D();

		/**
		 *  Gets the location of gravity
		 *
		 *  @return The location of the gravity
		 */
		seu::Vector GetLocation();

		/**
		 *  Gets the strength of the gravity
		 *
		 *  @return The strength of gravity
		 */
		seu::Vector GetGravity();
	private:
		seu::Vector grav_location;
	};
}

#endif //define(__SEPGRAVITY__)
