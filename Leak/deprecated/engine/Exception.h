#include <iostream>
#include <exception>
#include <stdexcept>
#include <sstream>
#include <string>

#ifndef __EXCEPTION__
#define __EXCEPTION__

using namespace std;

namespace seu
{
	class Exception: public exception
	{
	public:
		/**
		 *  The constructor of Exception
		 *
		 *  @param msg The message the Exception is returning
		 */
		Exception(const string msg);

		/**
		 *  The deconstructor of Exception
		 */
		~Exception();

		/**
		 *  Gets the message the Exception is holding
		 *
		 *  @return The message the exception is holding
		 */
		virtual const char* what() const;

		/**
		 *  Gets the message the Exception is holding
		 *
		 *  @return The message the exception is holding
		 */
		virtual string getMessage() const;
		string operator <<(string all);
		string operator <<(const char* all);
	private:
		string msg_;
	};
}

#endif /* define(__EXCEPTION__) */
