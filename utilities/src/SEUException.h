#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <string>

#ifndef __SEUEXCEPTION__
#define __SEUEXCEPTION__

template<typedef T>

class SEUException: public std::exception
{
public:
	virtual SEUException(const std::string& msg);
	virtual ~SEUExcpetion();
	virtual string what() const;
	virtual string getMessage() const;
	string operator <<(T& all);
private:
	string msg_;
};

#endif /* define(__SEUEXCEPTION__) */
