#include <iostream>
#include <vector>

#ifndef __SEGVBO__
#define __SEGVBO__

struct SEGVertex
{
	SEVector vertex;
	SEVector normal;
	float s0, t0;
};

struct SEGTriangle
{
	SEGVertex a;
	SEGVertex b;
	SEGVertex c;
	ushort indices[3];
};

struct SEGVertexHolder
{
	std::vector<SEGTriangle> triangles;
};

class SEGVbo
{
public:
	SEGVbo(SEGVertexHolder holder);
	~SEGVbo();
private:
	unsigned int vaoID[1];
	unsigned int vboID[1];
	SEGVertexHolder holder;
};

#endif /* define(__SEGVBO__) */
