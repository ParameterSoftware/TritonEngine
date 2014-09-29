#include <iostream>
#include <vector>
#include "Vector.h"

#ifndef __VBO__
#define __VBO__
namespace seg
{
	struct Vertex
	{
		seu::Vector vertex;
		seu::Vector normal;
		float s0, t0;
	};

	struct Triangle
	{
		Vertex a;
		Vertex b;
		Vertex c;
		unsigned short index[3];
	};

	struct TriangleVector
	{
		std::vector<Triangle> triangles;
	};

	class VBO
	{
	public:
		VBO(TriangleVector holder);
		~VBO();
		void Render(TriangleVector holder);
	private:
		unsigned int vaoID[1];
		unsigned int vboID[1];
	};
}

#endif /* define(__VBO__) */
