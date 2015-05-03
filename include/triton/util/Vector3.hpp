#ifndef TRITON_VEC3_HPP
#define TRITON_VEC3_HPP

#include <Trioton/Util/Vector2.hpp>

namespace Triton
{
namespace Util
{	

////////////////////////////////////////////////////////////
/// \brief Utility template class to store and manipulate 
///		2-dimensional vector positions
///
////////////////////////////////////////////////////////////
template <typename T>
class Vector3: public Vector2
{
public:

	////////////////////////////////////////////////////////////
	/// \brief Construct the vector from its coordinates, also 
	/// 	treated as default constructor
	///
	/// \param X X coordinate
	/// \param Y Y coordinate
	/// \param Z Z coordinate
	///
	////////////////////////////////////////////////////////////
	Vector3(T X = 0, T Y = 0, T Z = 0);
	
	////////////////////////////////////////////////////////////
	/// \brief Construct the vector from another type of vector
	///
	/// This constructor doesn't replace the copy constructor,
	/// it's called only when U != T.
	///
	///	\exception ExceptionCastFail thrown when U can't be casted to T
	///
	/// \param vector Vector to convert
	///
	////////////////////////////////////////////////////////////
	template <typename U>
	explicit Vector3(const Vector3<U>& vector);
	
	////////////////////////////////////////////////////////////
	/// \brief Construct the vector from a \ref Vector2 and a Z 
	/// 	coordinate
	///
	///	\exception ExceptionCastFail thrown when U can't be casted to T
	///
	/// \param vector Vector to convert
	/// \param Z the new Z coordinate
	///
	////////////////////////////////////////////////////////////
	template<typename U>
	Vector3(const Vector2<U>& vec, T Z = 0);
	
	////////////////////////////////////////////////////////////
	/// \brief Construct the vector from a \ref Vector1, a Y 
	/// 	coordinate, and Z coordinate
	///
	///	\exception ExceptionCastFail thrown when U can't be casted to T
	///
	/// \param vector Vector to convert
	/// \param Y the new Y coordinate
	/// \param Z the new Z coordinate
	///
	////////////////////////////////////////////////////////////
	template<typename U>
	Vector3(const Vector1<U>& vec, T Y = 0, T Z = 0);
	
	////////////////////////////////////////////////////////////
	/// \brief An operator for evaluating \ref Vector1 to a 
	/// 	\ref Vector3 using Y and Z coordinate parameters
	///
	///	\exception ExceptionCastFail thrown when U can't be casted to T
	///
	/// \param vector Vector to convert
	/// \param Y the new Y coordinate
	/// \param Z the new Z coordinate
	///
	////////////////////////////////////////////////////////////
	template<typename U>
	Vector3<T>& operator=(const Vector1<U>& vector, T Y = 0, T Z = 0);
	
	////////////////////////////////////////////////////////////
	/// \brief An operator for evaluating \ref Vector1 to a 
	/// 	\ref Vector3 using a Z coordinate parameter
	///
	///	\exception ExceptionCastFail thrown when U can't be casted to T
	///
	/// \param vector Vector to convert
	/// \param Z the new Z coordinate
	///
	////////////////////////////////////////////////////////////
	template<typename U>
	Vector3<T>& operator=(const Vector2<U>& vector, T Z = 0);
	
	////////////////////////////////////////////////////////////
	/// \brief Returns a vector that holds the distance between
	/// 	this and vector
	///
	///	\note The distance is an absolute value
	///
	///	\exception ExceptionCastFail thrown when U can't be casted to T
	///
	/// \param vector Vector to other vector
	///
	////////////////////////////////////////////////////////////
	template<typename U>
	Vector3<T> distance(Vector3<U> vector);
	
	////////////////////////////////////////////////////////////
	/// \brief Constructs a vector with an absolute value of 
	/// 	this vector
	///
	////////////////////////////////////////////////////////////
	Vector3<T> absV3();
	
	////////////////////////////////////////////////////////////
	/// \brief A safe and cross-object way of calling the 
	///		variables
	///
	////////////////////////////////////////////////////////////
	virtual T operator[](int index);
	
	////////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////////
	T m_ZPosition; ///< Z coordinate of the vector
};
////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of unary operator -
///
/// \param left Vector to negate
///
/// \return Memberwise opposite of the vector
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T> operator -(const Vector3<T>& left);
////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator +=
///
/// This operator performs a memberwise addition of both vectors,
/// and assigns the result to \a left.
///
/// \param left Left operand (a vector)
/// \param right Right operand (a vector)
///
/// \return Reference to \a left
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T>& operator +=(Vector3<T>& left, const Vector3<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator -=
///
/// This operator performs a memberwise subtraction of both vectors,
/// and assigns the result to \a left.
///
/// \param left Left operand (a vector)
/// \param right Right operand (a vector)
///
/// \return Reference to \a left
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T>& operator -=(Vector3<T>& left, const Vector3<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator +
///
/// \param left Left operand (a vector)
/// \param right Right operand (a vector)
///
/// \return Memberwise addition of both vectors
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T> operator +(const Vector3<T>& left, const Vector3<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator -
///
/// \param left Left operand (a vector)
/// \param right Right operand (a vector)
///
/// \return Memberwise subtraction of both vectors
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T> operator -(const Vector3<T>& left, const Vector3<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator *
///
/// \param left Left operand (a vector)
/// \param right Right operand (a scalar value)
///
/// \return Memberwise multiplication by \a right
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T> operator *(const Vector3<T>& left, T right);
////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator *
///
/// \param left Left operand (a scalar value)
/// \param right Right operand (a vector)
///
/// \return Memberwise multiplication by \a left
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T> operator *(T left, const Vector3<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator *=
///
/// This operator performs a memberwise multiplication by \a right,
/// and assigns the result to \a left.
///
/// \param left Left operand (a vector)
/// \param right Right operand (a scalar value)
///
/// \return Reference to \a left
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T>& operator *=(Vector3<T>& left, T right);
////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator /
///
/// \param left Left operand (a vector)
/// \param right Right operand (a scalar value)
///
/// \return Memberwise division by \a right
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T> operator /(const Vector3<T>& left, T right);
////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator /=
///
/// This operator performs a memberwise division by \a right,
/// and assigns the result to \a left.
///
/// \param left Left operand (a vector)
/// \param right Right operand (a scalar value)
///
/// \return Reference to \a left
///
////////////////////////////////////////////////////////////
template <typename T>
Vector3<T>& operator /=(Vector3<T>& left, T right);
////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator ==
///
/// This operator compares strict equality between two vectors.
///
/// \param left Left operand (a vector)
/// \param right Right operand (a vector)
///
/// \return True if \a left is equal to \a right
///
////////////////////////////////////////////////////////////
template <typename T>
bool operator ==(const Vector3<T>& left, const Vector3<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector3
/// \brief Overload of binary operator !=
///
/// This operator compares strict difference between two vectors.
///
/// \param left Left operand (a vector)
/// \param right Right operand (a vector)
///
/// \return True if \a left is not equal to \a right
///
////////////////////////////////////////////////////////////
template <typename T>
bool operator !=(const Vector3<T>& left, const Vector3<T>& right);

}
}
#endif
