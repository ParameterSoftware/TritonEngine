#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <string>

#ifndef __Exception__
#define __Exception__

template<typedef T>

class Exception: public std::exception
{
public:
    /**
     *  The constructor of Exception
     *
     *  @param msg The message the Exception is returning
     */
	virtual Exception(const std::string msg);

	/**
     *  The deconstructor of Exception
     */
	virtual ~Excpetion();

	/**
     *  Gets the message the Exception is holding
     *
     *  @return The message the exception is holding
     */
	virtual string what() const;

	/**
     *  Gets the message the Exception is holding
     *
     *  @return The message the exception is holding
     */
	virtual string getMessage() const;
	string operator <<(T& all);
	string << operator(T& all);
private:
	string msg_;
};

#endif /* define(__Exception__) */
