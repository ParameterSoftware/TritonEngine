#include "VBO.h"
#include <GLFW\glfw3.h>
#include <GL\glew.h>

#pragma comment(lib, "glfw3")
#pragma comment(lib, "glfw3dll")
#pragma comment(lib, "glew32")
#pragma comment(lib, "glew32s")

using namespace seg;

VBO::VBO(TriangleVector holder)
{
	glGenVertexArrays(1, &vaoID[0]);
	glBindVertexArray(vaoID[0]);
	glGenBuffers(1, vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID[0]);
	float *vertices = new float[holder.triangles.size()*3];
	for(int i = 0; i < holder.triangles.size(), i++)
	{
		vertices[i] = holder.triangles.at(i).a.vertex.x;
		vertices[i+1] = holder.triangles.at(i).a.vertex.y;
		vertices[i+2] = holder.triangles.at(i).a.vertex.z;
		i+=3;
	}
	glBufferData(GL_ARRAY_BUFFER, holder.triangles.size()*3 * sizeof(GLfloat), vertices, GL_STATIC_DRAW);
	glVertexAttribPointer((GLuint)0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
	this->Render(holder);
}

void VBO::Render(TriangleVector holder)
{
	glBindVertexArray(vaoID[0]);
	glDrawArrays(GL_TRIANGLES, 0, );
	glBindVertexArray(0);
}

VBO::~VBO()
{}
