#include <iostream>
#include <vector>
#include "../../utilities/src/Vector.h"

#ifndef __VBO__
#define __VBO__

struct Vertex
{
	Vector vertex;
	Vector normal;
	float s0, t0;
};

struct Triangle
{
	Vertex a;
	Vertex b;
	Vertex c;
	unsigned short indices[3];
};

struct TriangleVector
{
	std::vector<SEGTriangle> triangles;
};

class VBO
{
public:
	VBO(TriangleVector holder);
	~VBO();
private:
	unsigned int vaoID[1];
	unsigned int vboID[1];
};

#endif /* define(__VBO__) */
