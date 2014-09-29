#include <iostream>
#include "Vector.h"

#ifndef __GOBJ__
#define __GOBJ__

namespace seg
{
	class Object
	{
	public:
		Object(seu::Vector position);
		virtual bool Start();
		virtual void Update();
		virtual void Stop();
		void SetPosition(seu::Vector pos);
		seu::Vector GetPosition();
	private:
		seu::Vector position;
		virtual void UpdateGraphics();
	};

	class FlatObject ///Simple Billborad Object
	{
	public:
		FlatObject(seu::DDVector position, float scale = 1.0);
		virtual bool Start();
		virtual void Update();
		virtual void Stop();
		void SetPosition(seu::DDVector pos);
		seu::DDVector GetPosition();
		void SetScale(float scale = 1.0);
		float GetScale();
	private:
		seu::DDVector position;
		float scale;
		virtual void UpdateGraphics();
	}
}

#endif /* define(__GOBJ__) */
