#ifndef TRITON_VEC2_HPP
#define TRITON_VEC2_HPP

#include <Tritonoton/Util/Vector1.hpp>

namespace Triton
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
	
	////////////////////////////////////////////////////////////
	/// \brief Construct the vector from a 
	/// 	\ref Triton::Util::Vector1 and a Z coordinate
	///
	///	\exception ExceptionCastFail thrown when U can't be 
	/// 	casted to T
	///
	/// \param vector Vector to convert
	/// \param Y the new Y coordinate
	///
	////////////////////////////////////////////////////////////
	template<typename U>
	Vector2(const Vector1<U>& vector, T Y = 0);
	
	////////////////////////////////////////////////////////////
	/// \brief An operator for evaluating 
	/// 	\ref Triton::Util::Vector1 to a 
	/// 	\ref Triton::Util::Vector2 using a Y coordinate 
	/// 	parameter
	///
	///	\exception ExceptionCastFail thrown when U can't be 
	/// 	casted to T
	///
	/// \param vector Vector to convert
	/// \param Y the new Y coordinate
	///
	////////////////////////////////////////////////////////////
	template<typename U>
	Vector2<T>& operator=(const Vector1<U>& vector, T Y = 0);
	
	////////////////////////////////////////////////////////////
	/// \brief Returns a vector that holds the distance between
	/// 	this and vector
	///
	///	\note The distance is an absolute value
	///
	///	\exception ExceptionCastFail thrown when U can't be 
	/// 	casted to T
	///
	/// \param vector Vector to other vector
	///
	////////////////////////////////////////////////////////////
	template<typename U>
	Vector2<T> distance(Vector2<U> vector);
	
	////////////////////////////////////////////////////////////
	/// \brief Constructs a \ref Triton::Util::Vector2 with an 
	///		absolute value of this vector
	///
	////////////////////////////////////////////////////////////
	Vector2<T> absV2();

	////////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////////
	T m_YPosition; ///< Y coordinate of the vector
	
};

////////////////////////////////////////////////////////////
/// \relates Vector2
/// \brief Overload of unary operator -
///
/// \param left Vector to negate
///
/// \return Memberwise opposite of the vector
///
////////////////////////////////////////////////////////////
template <typename T>
Vector2<T> operator -(const Vector2<T>& left);
////////////////////////////////////////////////////////////
/// \relates Vector2
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
Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector2
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
Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector2
/// \brief Overload of binary operator +
///
/// \param left Left operand (a vector)
/// \param right Right operand (a vector)
///
/// \return Memberwise addition of both vectors
///
////////////////////////////////////////////////////////////
template <typename T>
Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector2
/// \brief Overload of binary operator -
///
/// \param left Left operand (a vector)
/// \param right Right operand (a vector)
///
/// \return Memberwise subtraction of both vectors
///
////////////////////////////////////////////////////////////
template <typename T>
Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector2
/// \brief Overload of binary operator *
///
/// \param left Left operand (a vector)
/// \param right Right operand (a scalar value)
///
/// \return Memberwise multiplication by \a right
///
////////////////////////////////////////////////////////////
template <typename T>
Vector2<T> operator *(const Vector2<T>& left, T right);
////////////////////////////////////////////////////////////
/// \relates Vector2
/// \brief Overload of binary operator *
///
/// \param left Left operand (a scalar value)
/// \param right Right operand (a vector)
///
/// \return Memberwise multiplication by \a left
///
////////////////////////////////////////////////////////////
template <typename T>
Vector2<T> operator *(T left, const Vector2<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector2
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
Vector2<T>& operator *=(Vector2<T>& left, T right);
////////////////////////////////////////////////////////////
/// \relates Vector2
/// \brief Overload of binary operator /
///
/// \param left Left operand (a vector)
/// \param right Right operand (a scalar value)
///
/// \return Memberwise division by \a right
///
////////////////////////////////////////////////////////////
template <typename T>
Vector2<T> operator /(const Vector2<T>& left, T right);
////////////////////////////////////////////////////////////
/// \relates Vector2
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
Vector2<T>& operator /=(Vector2<T>& left, T right);
////////////////////////////////////////////////////////////
/// \relates Vector2
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
bool operator ==(const Vector2<T>& left, const Vector2<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector2
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
bool operator !=(const Vector2<T>& left, const Vector2<T>& right);

}
}

#endif