#ifndef _LUS_EXCEPTSTR_HPP
#define _LUS_EXCEPTSTR_HPP

#include <string>

namespace Triton
{
namespace Util
{

////////////////////////////////////////////////////////////
/// \brief Utility string class which is made to use in 
///		exceptions
///
/// \note Every method will never throw an exception to keep 
/// 	it exception-safe
///
////////////////////////////////////////////////////////////
class EString
{
public:
	
	////////////////////////////////////////////////////////////
	///	\brief The template constructor that works with all 
	/// 	standard strings, can be used as default 
	/// 	constructor
	///
	///	\sa Triton::Util::EString#SetString
	///
	/// \tparam str_t a string type or chararcter type
	///
	///	\param string the string or character to input into this object
	///
	////////////////////////////////////////////////////////////
	template<typename str_t>
	EString(str_t string = '');
	
	////////////////////////////////////////////////////////////
	///	\brief Returns the cstring pointer, based on 
	/// 	std::string::c_str()
	///
	////////////////////////////////////////////////////////////
	const char* c_str() const;
	
	////////////////////////////////////////////////////////////
	///	\brief Returns the length, based on 
	/// 	std::string::c_str()
	///
	////////////////////////////////////////////////////////////
	size_t size();
	
	////////////////////////////////////////////////////////////
	///	\brief Returns the length, based on 
	/// 	std::string::c_str()
	///
	////////////////////////////////////////////////////////////
	size_t length();
	
	////////////////////////////////////////////////////////////
	///	\brief Clears the string, based on 
	/// 	std::string::c_str()
	///
	////////////////////////////////////////////////////////////
	void clear();
	
	////////////////////////////////////////////////////////////
	///	\brief Returns whether this string is empty, based on 
	/// 	std::string::c_str()
	///
	////////////////////////////////////////////////////////////
	bool empty() const;
	
	////////////////////////////////////////////////////////////
	///	\brief The bracket operator that returns the character 
	/// 	reference at index, based on std::string::c_str()
	///
	/// \param index the index to retrieve
	///
	////////////////////////////////////////////////////////////
	char& operator[](int index);
	
	////////////////////////////////////////////////////////////
	///	\brief The bracket operator that returns the constant 
	///		character reference at index, based on 
	///		std::string::c_str()
	///
	/// \param index the index to retrieve
	///
	////////////////////////////////////////////////////////////
	const char& operator[](int index) const;
	
	////////////////////////////////////////////////////////////
	///	\brief Returns the character reference at index, based 
	///		on std::string::c_str()
	///
	/// \param index the index to retrieve
	///
	////////////////////////////////////////////////////////////
	char& at(int index);
	
	////////////////////////////////////////////////////////////
	///	\brief Returns the constant character reference at 
	/// 	index, based on std::string::c_str()
	///
	/// \param index the index to retrieve
	///
	////////////////////////////////////////////////////////////
	const char& at(int index) const;
	
	////////////////////////////////////////////////////////////
	///	\brief The equal operator that returns the modified 
	/// 	\ref Triton::Util::EString reference, based on 
	/// 	std::string::c_str()
	///
	/// \sa EString#SetString
	///
	/// \tparam str_t the string type
	///
	/// \param str the string that modifies this string
	///
	////////////////////////////////////////////////////////////
	template<typename str_t>
	EString& operator= (str_t str);
	
	////////////////////////////////////////////////////////////
	///	\brief The plus-equal operator that returns the modified 
	/// 	\ref Triton::Util::EString reference, based on 
	/// 	std::string::c_str()
	///
	///	\sa EString#AddToString
	///
	/// \tparam str_t the string type
	///
	/// \param str the string that modifies this string
	///
	////////////////////////////////////////////////////////////
	template<typename str_t>
	EString& operator+= (str_t str);
	
protected:

	////////////////////////////////////////////////////////////
	///	\brief Sets this string as string
	///
	/// \param string the string to set this string as
	///
	////////////////////////////////////////////////////////////
	void SetString(const char string);
	
	////////////////////////////////////////////////////////////
	///	\brief Sets this string as string
	///
	/// \param string the string to set this string as
	///
	////////////////////////////////////////////////////////////
	void SetString(const char* string);
	
	////////////////////////////////////////////////////////////
	///	\brief Sets this string as string
	///
	/// \param string the string to set this string as
	///
	////////////////////////////////////////////////////////////
	void SetString(const char& string);
	
	////////////////////////////////////////////////////////////
	///	\brief Sets this string as string
	///
	/// \param string the string to set this string as
	///
	////////////////////////////////////////////////////////////
	void SetString(const std::string string);
	
	////////////////////////////////////////////////////////////
	///	\brief Sets this string as string
	///
	/// \param string the string to set this string as
	///
	////////////////////////////////////////////////////////////
	void SetString(const std::string* string);
	
	////////////////////////////////////////////////////////////
	///	\brief Sets this string as string
	///
	/// \param string the string to set this string as
	///
	////////////////////////////////////////////////////////////
	void SetString(const std::string& string);
	
	////////////////////////////////////////////////////////////
	///	\brief Sets this string as string
	///
	/// \param string the string to set this string as
	///
	////////////////////////////////////////////////////////////
	void SetString(const wchar_t string);
	
	////////////////////////////////////////////////////////////
	///	\brief Sets this string as string
	///
	/// \param string the string to set this string as
	///
	////////////////////////////////////////////////////////////
	void SetString(const wchar_t* string);
	
	////////////////////////////////////////////////////////////
	///	\brief Sets this string as string
	///
	/// \param string the string to set this string as
	///
	////////////////////////////////////////////////////////////
	void SetString(const wchar_t& string);
	
	////////////////////////////////////////////////////////////
	///	\brief Sets this string as string
	///
	/// \param string the string to set this string as
	///
	////////////////////////////////////////////////////////////
	void SetString(const EString string);
	
	////////////////////////////////////////////////////////////
	///	\brief Sets this string as string
	///
	/// \param string the string to set this string as
	///
	////////////////////////////////////////////////////////////
	void SetString(const EString* string);
	
	////////////////////////////////////////////////////////////
	///	\brief Sets this string as string
	///
	/// \param string the string to set this string as
	///
	////////////////////////////////////////////////////////////
	void SetString(const EString& string);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds to this string using string
	///
	/// \param string the string to append
	///
	////////////////////////////////////////////////////////////
	void AddToString(const char string);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds to this string using string
	///
	/// \param string the string to append
	///
	////////////////////////////////////////////////////////////
	void AddToString(const char* string);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds to this string using string
	///
	/// \param string the string to append
	///
	////////////////////////////////////////////////////////////
	void AddToString(const char& string);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds to this string using string
	///
	/// \param string the string to append
	///
	////////////////////////////////////////////////////////////
	void AddToString(const std::string string);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds to this string using string
	///
	/// \param string the string to append
	///
	////////////////////////////////////////////////////////////
	void AddToString(const std::string* string);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds to this string using string
	///
	/// \param string the string to append
	///
	////////////////////////////////////////////////////////////
	void AddToString(const std::string& string);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds to this string using string
	///
	/// \param string the string to append
	///
	////////////////////////////////////////////////////////////
	void AddToString(const wchar_t string);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds to this string using string
	///
	/// \param string the string to append
	///
	////////////////////////////////////////////////////////////
	void AddToString(const wchar_t* string);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds to this string using string
	///
	/// \param string the string to append
	///
	////////////////////////////////////////////////////////////
	void AddToString(const wchar_t& string);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds to this string using string
	///
	/// \param string the string to append
	///
	////////////////////////////////////////////////////////////
	void AddToString(const EString string);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds to this string using string
	///
	/// \param string the string to append
	///
	////////////////////////////////////////////////////////////
	void AddToString(const EString* string);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds to this string using string
	///
	/// \param string the string to append
	///
	////////////////////////////////////////////////////////////
	void AddToString(const EString* string);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds an \ref Triton::Util::EString and an 
	/// 	object of str_t together
	///
	///	\sa EString#AddToString
	///
	/// \tparam str_t the string object to add to EString
	///
	/// \param lhs the left string
	/// \param rhs the right string
	///
	////////////////////////////////////////////////////////////
	template<typename str_t>
	friend EString operator+(const EString& lhs, const str_t rhs);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds an \ref Triton::Util::EString pointer and 
	/// 	an object of str_t together
	///
	///	\sa EString#AddToString
	///
	/// \tparam str_t the string object to add to EString
	///
	/// \param lhs the left string
	/// \param rhs the right string
	///
	////////////////////////////////////////////////////////////
	template<typename str_t>
	friend EString operator+(const EString* lhs, const str_t rhs);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds an \ref Triton::Util::EString and an 
	/// 	object of str_t together
	///
	///	\sa EString#AddToString
	///
	/// \tparam str_t the string object to add to EString
	///
	/// \param lhs the left string
	/// \param rhs the right string
	///
	////////////////////////////////////////////////////////////
	template<typename str_t>
	friend EString operator+(const str_t lhs, const EString& rhs);
	
	////////////////////////////////////////////////////////////
	///	\brief Adds an \ref Triton::Util::EString pointer and 
	/// 	an object of str_t together
	///
	///	\sa EString#AddToString
	///
	/// \tparam str_t the string object to add to EString
	///
	/// \param lhs the left string
	/// \param rhs the right string
	///
	////////////////////////////////////////////////////////////
	template<typename str_t>
	friend EString operator+(const str_t rhs, const EString* rhs);

private:

	char* m_String;
	size_t m_Size;
};

ostream& operator<<(ostream& os, const EString& str);

istream& operator>>(istream& is, const EString& str);

}
}

#endif