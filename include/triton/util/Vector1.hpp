#ifndef _LUS_VECTOR_H_
#define _LUS_VECTOR_H_

namespace Triton
{
namespace Util
{

////////////////////////////////////////////////////////////
/// \brief Utility template class to store and manipulate 
///		1-dimensional vector positions
///
////////////////////////////////////////////////////////////
template<typename T = int>
class Vector1
{
public:

	////////////////////////////////////////////////////////////
	/// \brief Construct the vector from its coordinates
	///
	/// \param X X coordinate
	///
	////////////////////////////////////////////////////////////
	Vector1(T X = 0);
	
	////////////////////////////////////////////////////////////
	/// \brief Construct the vector from another type of vector
	///
	/// This constructor doesn't replace the copy constructor,
	/// it's called only when U != T.
	///
	///	\exception ExceptionCastFail thrown when U can't be 
	/// 	casted to T
	///
	/// \param vector Vector to convert
	///
	////////////////////////////////////////////////////////////
	template<typename U>
	explicit Vector1(const Vector1<U>& vector);

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
	Vector1<T> distance(Vector1<U> vector);
	
	////////////////////////////////////////////////////////////
	/// \brief Constructs a \ref Triton::Util::Vector1 with an 
	///		absolute value of this vector
	///
	////////////////////////////////////////////////////////////
	Vector1<T> absV();
	
	////////////////////////////////////////////////////////////
	/// \brief A safe and cross-object way of calling the 
	///		member variables
	///
	////////////////////////////////////////////////////////////
	virtual T operator[](int index);
	
	////////////////////////////////////////////////////////////
	// Member data
	////////////////////////////////////////////////////////////
	T m_XPosition; ///< Y coordinate of the vector
	
};

////////////////////////////////////////////////////////////
/// \relates Vector1
/// \brief Overload of unary operator -
///
/// \param left Vector to negate
///
/// \return Memberwise opposite of the vector
///
////////////////////////////////////////////////////////////
template <typename T>
Vector1<T> operator -(const Vector1<T>& left);
////////////////////////////////////////////////////////////
/// \relates Vector1
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
Vector1<T>& operator +=(Vector1<T>& left, const Vector1<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector1
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
Vector1<T>& operator -=(Vector1<T>& left, const Vector1<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector1
/// \brief Overload of binary operator +
///
/// \param left Left operand (a vector)
/// \param right Right operand (a vector)
///
/// \return Memberwise addition of both vectors
///
////////////////////////////////////////////////////////////
template <typename T>
Vector1<T> operator +(const Vector1<T>& left, const Vector1<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector1
/// \brief Overload of binary operator -
///
/// \param left Left operand (a vector)
/// \param right Right operand (a vector)
///
/// \return Memberwise subtraction of both vectors
///
////////////////////////////////////////////////////////////
template <typename T>
Vector1<T> operator -(const Vector1<T>& left, const Vector1<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector1
/// \brief Overload of binary operator *
///
/// \param left Left operand (a vector)
/// \param right Right operand (a scalar value)
///
/// \return Memberwise multiplication by \a right
///
////////////////////////////////////////////////////////////
template <typename T>
Vector1<T> operator *(const Vector1<T>& left, T right);
////////////////////////////////////////////////////////////
/// \relates Vector1
/// \brief Overload of binary operator *
///
/// \param left Left operand (a scalar value)
/// \param right Right operand (a vector)
///
/// \return Memberwise multiplication by \a left
///
////////////////////////////////////////////////////////////
template <typename T>
Vector1<T> operator *(T left, const Vector1<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector1
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
Vector1<T>& operator *=(Vector1<T>& left, T right);
////////////////////////////////////////////////////////////
/// \relates Vector1
/// \brief Overload of binary operator /
///
/// \param left Left operand (a vector)
/// \param right Right operand (a scalar value)
///
/// \return Memberwise division by \a right
///
////////////////////////////////////////////////////////////
template <typename T>
Vector1<T> operator /(const Vector1<T>& left, T right);
////////////////////////////////////////////////////////////
/// \relates Vector1
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
Vector1<T>& operator /=(Vector1<T>& left, T right);
////////////////////////////////////////////////////////////
/// \relates Vector1
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
bool operator ==(const Vector1<T>& left, const Vector1<T>& right);
////////////////////////////////////////////////////////////
/// \relates Vector1
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
bool operator !=(const Vector1<T>& left, const Vector1<T>& right);

}
}

#endif 