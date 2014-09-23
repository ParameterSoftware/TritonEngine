#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <string>

#ifndef __SEException__
#define __SEException__

template<typedef T>

class SEException: public std::exception
{
public:
    /**
     *  The constructor of SEException
     *
     *  @param msg The message the SEException is returning
     */
	virtual SEException(const std::string msg);

	/**
     *  The deconstructor of SEException
     */
	virtual ~SEUExcpetion();

	/**
     *  Gets the message the SEException is holding
     *
     *  @return The message the exception is holding
     */
	virtual string what() const;

	/**
     *  Gets the message the SEException is holding
     *
     *  @return The message the exception is holding
     */
	virtual string getMessage() const;
	string operator <<(T& all);
private:
	string msg_;
};

#endif /* define(__SEException__) */
