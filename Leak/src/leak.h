#include "utils.h"

#ifndef __leakengine__
#define __leakengine__

namespace Leak 
{
	typedef unsigned int* ImageData;
	
	class KeyBind
	{
		KeyInput input;
		bool ignoreMods;
	public:
		KeyBind(KeyInput input, bool ignoreMods = true);
		
		void 		setInput(KeyInput input, int mods = -1);
		void		setIgnoreMods(bool ignore);
		
		KeyInput	getKeyInput();
	};
	
	namespace Asset
	{
		struct AssetObject {
			AssetObject();
		};
		
		struct Model: public AssetObject
		{
			aiScene* model;
			Model(aiScene* model);
		};
		
		struct Image: public AssetObject
		{
			ImageData image;
			Image(ImageData image);
		};
		
		struct Audio: public AssetObject
		{
			Audio();
		};
	}
	
	namespace File
	{		
		class Resource
		{
			Utility::String location;
		public:
			Resource(Utility::String location);
			
			virtual Asset::AssetObject 	getAsset() = 0;
		};
		
		struct ModelResource: public Resource
		{
			ModelResource(Utility::String location);
		};
		
		struct ImageResource: public Resoure
		{
			ImageResource(Utility::String location);
		};
		
		struct AudioResource: public Resource
		{
			AudioResource(Utility::String location);
		};
	}
	
	namespace Visual
	{
		class VisualObject
		{
		protected:
			Utility::Vec3L 	position;
			Utility::Vec3F 	rotation;
			
			int				existTicks;
		public:
			VisualObject(Utility::Vec3L pos = Utility::Vec3L(), Utility::Vec3F rot = Utility::Vec3F());
			
			void 			setPosition(long x, long y, long z);
			void			setRotation(float yaw, float pitch, float roll);
			
			Utility::Vec3L	getPosition();
			Utility::Vec3F	getRotation();
			
			virtual void	onUpdate();
		};
		
		class LightObject : public VisualObject
		{
		protected:
			long focus;
			bool spotlight;
		public:
			LightObject(Utility::Vec3L pos = Utility::Vec3L(), Utility::Vec3F rot = Utility::Vec3L(), long foc = 0);

			void			setFocus(long focus);
			void 			setSpotlight(bool spot);
			
			long			getFocus();
			
			bool			isSpotlight();
			
			virtual void	onLightUpdate();
		};
		
		class LightRound : public LightObject
		{
		protected:
			long radius;
		public:
			LightRound(Utility::Vec3L pos = Utility::Vec3L(), Utility::Vec3F rot = Utility::Vec3L(), long foc = 0, long rad = 0);

			void			setRadius(long radius);
			
			long			getRadius();
		};
		
		class LightRect : public LightObject
		{
		protected:
			Utility::Vec3F horizontal;
			Utility::Vec3F vertical;
		public:
			LightRect(
				Utility::Vec3L pos = Utility::Vec3L(),
				Utility::Vec3F rot = Utility::Vec3L(),
				long foc = 0,
				Utility::Vec3F hor = Utility::Vec3F(),
				Utility::Vec3F ver = Utility::Vec3F()
			);
			
			void			setVertical(Utility::Vec3F vert);
			void			setHorizontal(Utility::Vec3F horz);
			
			Utility::Vec3F	getVertical();
			Utility::Vec3F	getHorizontal();
		};
		
		class GraphicObject: public VisualObject
		{
		protected:
			File::ModelResource* model;
			File::ImageResource* texture;
		public:
			float lightReflectStrength;
		
			GraphicObject(Utility::Vec3L pos = Utility::Vec3L(), Utility::Vec3F rot = Utility::Vec3F());
			
			void			setModelLocation(Utility::String loc);
			void 			setImageLocation(Utility::String loc);
			
			virtual void	onRender(LightObject light);
		};
	}

	namespace Engine
	{
		class InputEngine
		{
			Engine* engine;
		
			std::vector<KeyBind*> binds;
			
			Utility::Vec2 mousePosition;
		public:
			InputEngine(Engine* engine);
			
			void			addBind(KeyBind* bind);
			
			KeyBind			getBindFor(KeyValue value);
			int				getActionFromBind(KeyValue value);
			Utility::Vec2 	getMousePosition();
			
			void			onUpdate();
		};
		
		class GraphicEngine
		{
			Engine* engine;
		
			std::vector<VisualObject*> objects;
		public:
			GraphicEngine(Engine* engine);
			
			void					onUpdate();
			
			void					addObject(VisualObject* vo);
			
			Visual::VisualObject* 	getObject(int id);
		};
		
		class Engine
		{
			Engine* 		instance;
			GraphicEngine* 	gEngine;
			InputEngine*	iEngine;
			Window*			window;
		public:
			Engine(Window* window);
			Engine(Utility::String winTitle, int winWidth, int winHeight);
			
			GraphicEngine* 	getGraphicEngine();
			InputEngine*	getInputEngine();
			Window*			getWindow();
		};
	}
}

#endif