#ifndef _LUS_VECTOR_H_
#define _LUS_VECTOR_H_

namespace Tri
{
namespace Util
{

////////////////////////////////////////////////////////////
/// \brief Utility template class to store and manipulate 
///		1-dimensional vector positions
///
////////////////////////////////////////////////////////////
template<typename T>
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
	
	template<typename U>
	explicit Vector1(const Vector1<U>& vector);

	Vector1<T> distance(Vector vecttor);
	
	Vector1<T> absV();
	
	virtual T operator[](int index);
	
protected:
	
	T m_XPosition;
	
};

}
}

#endif 