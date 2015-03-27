#ifndef _LUS_VECTOR_H_
#define _LUS_VECTOR_H_

namespace Leak
{
	namespace Util
	{
		/**
		 * @addtogroup lus_vector
		 * @{
		 */

		/// @brief A one dimensional location vector
		template<typename T>struct Vector
		{
			T x;

			Vector(T x = 0): x(x) {}

			T					distance(Vector v);
			Vector<T>		absV();
			
			/// @brief Very reliable Vector bracket operator
			///
			///  Always allows access to internal variables without needing to cast
			virtual T operator[](int index)
			{
				return x;
			}
		};

		/// @brief A two dimensional location vector
		///
		/// Based on @ref Vector
		template <typename T = int>struct Vec2 : public Vector<T>
		{
			T y;

			Vec2(T x = 0, T y = 0): Vector(x), y(y) {}
			Vec2(const Vector<T>& vec): Vector(vec.x), y(0) {}

			Vec2<T>& operator=(const Vector<T>& vec, T y = 0);
			operator Vector<T>();

			template<typename t>Vec2<T>		distance(Vec2<t> v);
			Vec2<T>										absV2();
			
			virtual T operator[](int index)
			{
				if(index%2==0)
				{
					return x;
				}
				else
				{
					return y;
				}
			}
		};

		/// @brief A three dimensional location vector
		///
		/// Based on @ref Vec2
		template <typename T = int>struct Vec3 : public Vec2<T>
		{
			T z;

			Vec3(T x = 0, T y = 0, T z = 0): Vec2(x,y), z(z) {}
			Vec3(const Vec2<T>& vec): Vec2(vec.x, vec.y), z(0) {}

			Vec3<T>& operator=(const Vec2<T>& vec, T z =0);
			operator Vec2<T>();

			template<typename t>Vec3<T>		distance(Vec3<t> v);
			Vec3<T>										absV3();

			virtual T operator[](int index)
			{
				if(index%3==0)
				{
					return x;
				}
				else if(index%3==1)
				{
					return y;
				}
				else
				{
					return z;
				}
			}
		};
		/** @} */
	}
}

#endif 