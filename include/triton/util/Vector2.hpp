#ifndef TRITON_VEC2_HPP
#define TRITON_VEC2_HPP

#include <Trioton/Util/Vector1.hpp>

namespace Tri
{
namespace Util
{

////////////////////////////////////////////////////////////
/// \brief Utility template class to store and manipulate 
///		2-dimensional vector positions
///
////////////////////////////////////////////////////////////
template<typename T = int>
class Vector2: public Vector1<T>
{
public:
	
	////////////////////////////////////////////////////////////
	/// \brief Construct the vector from its coordinates
	///
	/// \param X X coordinate
	/// \param Y Y coordinate
	///
	////////////////////////////////////////////////////////////
	Vector2(T X = 0, T Y = 0);
	
	template<typename U>
	explicit Vector2(const Vector2<U>& vector);
	
	explicit Vector2<T>& operator=(const Vector1<T>& vec, T y = 0);
	
	explicit operator Vector1<T>();
	
	template<typename U>
	Vector2<T> distance(Vector2<U> v);
	
	Vector2<T> absV2();
	
	virtual T operator[](int index);

	T m_YPosition;
	
};
	
}
}

#endif