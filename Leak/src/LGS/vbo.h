#ifndef _LGS_VBO_H
#define _LGS_VBO_H

#include <vector>
#include <glm/glm.hpp>

namespace VBOLib
{

	typedef std::vector<unsigned short> inds
	typedef std::vector<glm::vec3> verts;
	typedef std::vector<glm::vec2> us;
	typedef std::vector<glm::vec3> norms;

	struct Vbo
	{
		inds indices;
		verts vertices;
		us uvs;
		norms normals;
		
		Vbo(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals);
		
		inds GetIndices();
		verts GetVertices();
		us GetUvs();
		norms GetNormals();
	};

}

#endif