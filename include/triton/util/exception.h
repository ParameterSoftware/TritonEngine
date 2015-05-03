#ifndef _LUS_EXCEPTION_H_
#define _LUS_EXCEPTION_H_

namespace Tri
{
	namespace Util
	{
	
		/** An Exception-Safe Basic String
		 *  
		 *  Please use only (and only use) ExceptionBasicString for exception handling
		 */
		template<class charT>
		class ExceptionBasicString
		{
			charT* 	m_str;
			size_t	m_size
		public:
			ExceptionBasicString (const charT* str);
			
			void	SetString(const charT* str)
			{
				m_size = strlen(str);
				m_str = str;
			}
		};
		
		typedef ExceptionBasicString<char> ExceptionString;
	
		/**
		 *  @addtogroup lus_exception
		 *  @{
		 */

		/// The basic Exception
		class Exception: public std::exception
		{
		protected:
			ExceptionString m_Msg; ///< The @ref ExceptionString Message this @ref Exception gives
		public:
			/** The constructor for @ref Exception
			 *
			 *  @param msg The message to be stored
			 */
			Exception(ExceptionString msg): m_Msg("Exception: "+msg+"\n") {}

			virtual ExceptionString what() { return m_Msg; } ///< Returns the @ref ExceptionString of this exception based on @ref msg
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
			Error(int errorCode, ExceptionString error): m_Msg("Error Code: "+errorCode+"\nError Message: "+error) {}

			int 						GetErrorCode(); 				///< Returns the error's code via stringstreams
			ExceptionString		GetErrorMessage(); 			///< Returns the error's readable statement
		};
		/** @} */
	}
}

#endif 