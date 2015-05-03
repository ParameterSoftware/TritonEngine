#ifndef _LUS_LOCAL_H_
#define _LUS_LOCAL_H_

#include "util.h"

namespace Tri
{
	namespace Util
	{
		/**
		 *  @addtogroup lus_local
		 *  @{
		 */
		
		class Language;
	
		/// The manager for localization
		class LocalManager
		{
			Language	mLanguageCache; ///< Last Accessed Language Object from File
		
			String		mDirectoryName;
		
			LocalManager(String directory);
		public:

			void 				SetDirectory(String directory);
			
			Language		GetLanguage(String name = "");
		};

		/// The language object
		class Language
		{
			friend class LocalManager;

			String 				mName;
			DList<String> 	mTranslations;
			
			void				OpenLanguageFile(String directory);
			
			Language(String name);
		public:
			String	GetName();
			String	GetLocal(String unlocalizeName);
		};
		/**
		 *  @}
		 */
	}
}

#endif