#ifndef _LUS_ANGLE_H_
#define _LUS_ANGLE_H_

namespace Tri
{
	namespace Util
	{
		/**
		 *  @addtogroup lus_angle
		 *  @{
		 */
		struct Angle;
		struct Degree;
		struct Radian;

		/// @brief A simple Angle object (practically an interface)
		///
		/// Suggestion: Don't use unless angle type will not matter
		struct Angle
		{
			enum AngleType
			{
				ANGLE,
				DEGREE,
				RADIAN
			};
		
			float ang;
			
			virtual RotationType GetRotationType() { return ANGLE; }
		};

		/// @brief A simplistic Degree object
		///
		/// Based on @ref Angle
		struct Degree: public Angle
		{
			Degree(float ang): ang(ang) {}
			Degree(const Radian& rad);

			Degree& 		operator=(const Radian& rad);
			operator 		Radian();

			Radian			ToRadian();
			
			RotationType	GetRotationType() { return DEGREE; }
		};

		/// @brief A simplistic Radian object
		///
		/// Based on @ref Angle
		struct Radian: public Angle
		{
			Radian(float ang): ang(ang) {}
			Radian(const Degree& deg);

			Degree& 		operator=(const Radian& rad);
			operator 		Radian();

			Degree			ToDegree();
			
			RotationType GetRotationType() { return RADIAN; }
		};
		/**
		 *  @}
		 */
	}
}

#endif