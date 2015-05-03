#ifndef _LGS_UTIl_H_
#define _LGS_UTIl_H_

#include <leak/util/exception.h>
#include <leak/graphic/render.h>

namespace Tri
{
	namespace Graphic
	{
		typedef glm::mat3 Mat3;
		typedef glm::mat4 Mat4;

		class GraphicalException: public Tri::Util::Exception
		{
		public:
			GraphicalException(LUS::String msg): msg("GraphicalException: "+msg+"\n") {}
		};
		
		class GraphicManager
		{
			unsigned int 									mTickUpdate = 0;

			/// @breif the Current settings for OpenGL to use
			///
			/// All Settings are loaded dynamically
			struct glsettings_t
			{
				bool 						mUseVBO;					///< Determines whether to use VBO
				ShaderProgram 	mShaderProgram;			///< Determines the current Shaders to load based on program
				Camera 				mMainCamera;				///< The current used camera to display to client
				float 						mAspectRatio;				///< The current aspect of resolution ratio
				LUS::Vec2<float> 	mDisplayRange;			///< The range of distance of sight for the current camera
			}*													mSettings;

			/// @brief Load Storage for current Input Objects
			///
			/// Name Reason: mP suffix instead of mp because Objects are pointers, not the List
			LUS::DList<Render::DrawObject*> 	mPObjectsList;
		public:
			OpenGLManager();
			~OpenGLManager();

			/// @brief Simple addition of drawable objects
			///
			/// @param pDraw A pointer to a drawable object defined by LEAK_USE_2D, 2D only if stated, 3D otherwsie
			Render::DrawObject* AddDrawable(Render::DrawObject* pDraw);

			glsettings_t* 	GetSettings();///< Retrieves the current (mutable) settings 
			Mat4 			GetProjectionMatrix();
			Mat4 			GetMVPFor(Render::IDraw draw);
			unsigned int	GetTickUpdate();

			void				Render();
			
			bool 				Is3DEnabled()
			{
				#ifdef LEAK_USE_2D
					return false
				#else
					return true;
				#endif
			}
		} gManager;
	}
}

#endif