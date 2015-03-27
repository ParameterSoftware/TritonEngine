#ifndef _LGS_RENDER_H_
#define _LGS_RENDER_H_

#include <leak/util/util.h>
#include <leak/util/angle.h>
#include <leak/util/vector.h>

namespace Leak
{
	namespace Graphic
	{
		class Camera
		{
		protected:
			Util::Vec3<double> 				mPosition;
			Util::Vec3<Util::Radian> 		mRotation;
			Util::Degree							mFov;
			bool 										mIsUpsideDown = false;

			virtual void onRotate(Util::Vec2<Angle>& rRotation) {}
			virtual void onMove(Util::Vec2<double>& rPosition) {}
		public:
			Camera(
				Util::Vec3<double> 			position, 
				Util::Vec3<Util::Radian> 	rotation,
				Util::Degree						fov = Util::Degree(60)
			);

			virtual void 							Update(int tick) {}

			Mat4 									GetViewMatrix();

			void 										Rotate(Util::Vec2<Angle> rotation);
			void 										MoveTo(Util::Vec2<double> position);
			void										SetFov(Util::Degree fov);
			void										SetIsUpsideDown(bool faceUp);

			Util::Vec3<double> 				GetPosition();
			Util::Vec3<Util::Radian> 		GetRotation();
			float										GetFov();
			bool										IsUpsideDown();
		};

		class IDraw
		{
		protected:
			unsigned long 					mId;
			Shader::ShaderProgram 	mShaderProgram;
		public:
			bool 									mKeepUp = false; ///< Boolean to determine whether to keep the object up after closing the Graphic Engine

			/// @brief The logical update function for @ref IDraw
			///
			///Use for positional changes
			virtual void 					Update(int tick) = 0; 
			
			/// @brief The graphical function for @ref IDraw
			///
			///Use for Graphical Manipulations
			virtual void 					Render() = 0;
			Shader::ShaderProgram GetShader();
			virtual Mat4 					GetModelMatrix() = 0;
		};

		class Draw2D: public IDraw
		{
			Util::Vec2<double> 			mPosition;
			double 								mZLevel;
			Util::Vec2<Util::Radian> 	mRotation;
			Util::Vec2<float> 				mScale;
			Resource::Image 				mTexture;
		protected:
			virtual void OnRotate(Util::Vec2<Angle>& rRotation) {}
			virtual void OnMove(Util::Vec2<double>& rPosition) {}
			virtual void OnRescale(Util::Vec2<float>& rScale) {}
			virtual void OnZLevelChange(double& rZLevel) {}
		public:
			Draw2D(Resource::Image texture): texture(texture) {}

			bool 										AssignTexture(Resource::Image texture);

			void 										Rotate(Util::Vec2<Angle> rotation);
			void 										MoveTo(Util::Vec2<double> position);
			void 										Rescale(Util::Vec2<float> scale);
			void 										SetZLevel(double z);

			Util::Vec2<double> 				GetPosition();
			Util::Vec2<Util::Radian> 		GetRotation();
			Util::Vec2<float> 					GetScale();
			double 									GetZLevel();
			Mat4 									GetModelMatrix();
		};

		class Draw3D: public IDraw
		{
			Util::Vec3<double> 				mPosition;
			Util::Vec3<Util::Radian> 		mRotation;
			Util::Vec3<float> 					mScale;
			Resource::Image 					mTexture;
			Resource::Model 					mModel;
		protected:
			virtual void onRotate(Util::Vec3<Angle>& rRotations) {}
			virtual void onMove(Util::Vec3<double>& rPosition) {}
			virtual void onRescale(Util::Vec3<float>& rScale) {}
		public:
			Draw3D(
				Resource::Image texture, 
				Resource::Model model): texture(texture), model(model) {}

			bool 									AssignTexture(Resource::Image texture);
			bool 									AssignModel(Resource::Model model);

			void 									Rotate(Util::Vec3<Angle> rotation);
			void 									MoveTo(Util::Vec3<double> position);
			void 									Rescale(Util::Vec3<float> scale);

			Util::Vec3<double> 			GetPosition();
			Util::Vec3<Util::Radian> 	GetRotation();
			Util::Vec3<float> 				GetScale();

			Mat4 								GetModelMatrix();
		};

		/// @breif A small class for rendering text from @ref Util::String and a @ref Resource::Image font
		///
		/// All input is updated on-the-fly
		///
		/// Example of use:
		/// @code
		/// Leak::Graphic::Render::Text txt(fontImage, "Foo");
		/// txt.text = "Bar" // txt now displays Bar instead of Foo
		/// @endcode
		class Text: public Draw2D
		{
		public:
			Util::String	text;
			Text(Resource::Image texture): Draw2D(texture), text("") {}
			Text( const Util::String& s, Resource::Image texture) : Draw2D(texture), text( s ) { }
			Text( const Util::String& s, std::size_t n, Resource::Image texture) : Draw2D(texture), text( s,n ) { }
			Text( const char *s, std::size_t n, Resource::Image texture ) : Draw2D(texture), text( s,n ) { }
			Text( const char *s, Resource::Image texture ) : Draw2D(texture), text( s ) { }
			Text( std::size_t n, char c, Resource::Image texture ) : Draw2D(texture), text(n,c ) { }
			template <class InputIterator>
			Text( InputIterator first, InputIterator last, Resource::Image texture ) : Draw2D(texture), text( first,last ) { }
		};

		//Warning: Careful with this, only call LEAK_USE_2D if you never plan on 3D Graphics
		#ifdef LEAK_USE_2D
			typedef Draw2D DrawObject;
		#else
			typedef Draw3D DrawObject;
		#endif
	}
}

#endif