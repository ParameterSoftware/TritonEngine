#ifndef _LUS_STRING_H_
#define _LUS_STRING_H_

#include <string>

namespace Leak
{
	namespace Util
	{
		class CString
		{
			char* 	m_str;
			size_t	m_size;
		public:
			void														SetString(char* str);
			void														SetString(const char* str);
			void														SetString(std::string str);
			void														SetString(CString str);
			void														SetString(std::string* str);
			void														SetString(CString* str);
			void														SetString(char str);
																		CString(): m_str(NULL), m_size(0) {}
			template<typename strT>						CString (strT str): { SetString(str); }
			template<typename strT>						CString (strT* str): { SetString(str); }
			const char* 											c_str() const;
			const size_t											size() const;
			template<typename charT>CString& 		operator= (charT* s);
			template<typename charT>CString& 		operator= (charT s);
			char& 													operator[] (size_t pos);
			char& 													operator[] (size_t pos) const;
			char& 													at (size_t pos);
			char& 													at (size_t pos) const;
			void 														clear();
			bool 														empty();
			
			friend std::istream& operator>> (std::istream&, const CString&);
			friend std::ostream& operator<< (std::ostream&, CString&);
		};
	}
}

#endif