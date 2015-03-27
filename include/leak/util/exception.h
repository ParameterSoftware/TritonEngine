#ifndef _LUS_EXCEPTION_H_
#define _LUS_EXCEPTION_H_

namespace Leak
{
	namespace Util
	{
		/**
		 *  @addtogroup lus_exception
		 *  @{
		 */

		/// The basic Exception
		class Exception: public std::exception
		{
		protected:
			String msg; ///<
		public:
			/** The constructor for @ref Exception
			 *
			 *  @param msg The message to be stored
			 */
			Exception(String msg): msg("Exception: "+msg+"\n") {}

			virtual String		what() { return msg; } ///< Returns the @ref String of this exception based on @ref msg
		};

		/// An error based off @ref Exception for better clarification
		class Error: public Exception
		{
		public:
			/** The constructor for @ref Error
			 *
			 *  @param errorCode The error code to be applied to this exception
			 *  @param error The error message of @ref Error
			 */
			Error(int errorCode, String error): msg("Error Code: "+errorCode+"\nError Exception: "+error) {}

			int 			getErrorCode(); ///< Returns the error's code via stringstreams
			String		getError(); ///< Returns the error's readable statement
		};
		/** @} */
	}
}

#endif 