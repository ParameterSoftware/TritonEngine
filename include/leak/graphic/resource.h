#ifndef _LGS_RESOURCE_H_
#define _LGS_RESOURCE_H_

#include <leak/util/util.h>
#include <leak/util/vector.h>

namespace Leak
{
	namespace Graphic
	{
		//TODO: intergrate DevIL and AssImp

		class Image
		{
			unsigned int mTexureId;
		public:
			Image(unsigned int width, unsigned int height, const LUS::ubyte* data);
			Image(unsigned int texureId);

			unsigned int 		GetTextureId();
			
			void					Draw();

			static Image 		GetBmp(Util::String filepath);
			static Image		GetDds(Util::String filepath);
		};

		class Model
		{
			Util::DList<Util::Vec3<double>> 	mVertexList;
			Util::DList<Util::Vec2<float>> 	mUvList;
			Util::DList<Util::Vec3<double>> 	mNormalList;
		public:
			Model(Util::DList<Util::Vec3> vertices, Util::DList<Util::Vec2> uvs, Util::DList<Util::Vec3> normals);

			Util::Vec3 			GetVertex(int index);
			Util::Vec2 			GetUV(int index);
			Util::Vec3 			GetNormal(int index);
			
			void 						Render(Image image);

			static Model 			GetObj(Util::String filepath, bool invertUv = false);
		};
	}
}
#endif