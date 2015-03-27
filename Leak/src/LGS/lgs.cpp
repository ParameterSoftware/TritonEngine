#include <leak/graphic/
#include "vbo.h"

using namespace Leak;
using namespace Graphic;

Resource::Image::Image(unsigned int width, unsigned int height, const LUS::ubyte* data)
{
	glGenTextures(1, &mTextureId);
	glBindTexture(GL_TEXTURE_2D, mTextureId);
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glGenerateMipmap(GL_TEXTURE_2D);
}

Resource::Image::Image(unsigned int textureId): mTextureId(textureId) {}

unsigned int Resource::Image::GetTextureId()
{
	return mTextureId;
}

Image Resource::Image::GetBmp(LUS::String filepath)
{
	const int headerSize = 54;

	FILE * file = fopen(filepath.c_str(),"rb");
	if (!file)
	{
		throw GraphicalException("BMP Load failed, check BMP "+filepath+" exists");
	}

	unsigned char header[headerSize];

	if ( fread(header, 1, 54, file)!=54 ){ // If not 54 bytes read : problem
		throw GraphicalException(filepath+" is not a BMP file");
	}

	if ( header[0]!='B' || header[1]!='M' ){
		throw GraphicalException(filepath+" is BMP but not formatted correctly.");
	}

	unsigned int dataPos    	= *(int*)&(header[0x0A]);
	unsigned int imageSize  = *(int*)&(header[0x22]);
	unsigned int width      	= *(int*)&(header[0x12]);
	unsigned int height     	= *(int*)&(header[0x16]);

	if (imageSize==0)    imageSize=width*height*3; // 3 : one byte for each Red, Green and Blue component
	if (dataPos==0)      dataPos=54;

	LUS::ubyte* data = new LUS::ubyte[imageSize];

	// Read the actual data from the file into the buffer
	fread(data,1,imageSize,file);

	//Everything is in memory now, the file can be closed
	fclose(file);

	return Resource::Image::Image(width, height, data);
}

Image Resource::Image::GetDds(LUS::String filepath)
{
	unsigned char header[124];

    FILE *fp;
 
    /* try to open the file */
    fp = fopen(imagepath, "rb");
    if (fp == NULL)
        return 0;
 
    /* verify the mType of file */
    char filecode[4];
    fread(filecode, 1, 4, fp);
    if (strncmp(filecode, "DDS ", 4) != 0) {
        fclose(fp);
        return 0;
    }
 
    /* get the surface desc */
    fread(&header, 124, 1, fp); 
 
    unsigned int height      = *(unsigned int*)&(header[8 ]);
    unsigned int width         = *(unsigned int*)&(header[12]);
    unsigned int linearSize     = *(unsigned int*)&(header[16]);
    unsigned int mipMapCount = *(unsigned int*)&(header[24]);
    unsigned int fourCC      = *(unsigned int*)&(header[80]);
	
	unsigned char * buffer;
    unsigned int bufsize;
    /* how big is it going to be including all mipmaps? */
    bufsize = mipMapCount > 1 ? linearSize * 2 : linearSize;
    buffer = (unsigned char*)malloc(bufsize * sizeof(unsigned char));
    fread(buffer, 1, bufsize, fp);
    /* close the file pointer */
    fclose(fp);
	
	unsigned int components  = (fourCC == FOURCC_DXT1) ? 3 : 4;
    unsigned int format;
    switch(fourCC)
    {
    case FOURCC_DXT1:
        format = GL_COMPRESSED_RGBA_S3TC_DXT1_EXT;
        break;
    case FOURCC_DXT3:
        format = GL_COMPRESSED_RGBA_S3TC_DXT3_EXT;
        break;
    case FOURCC_DXT5:
        format = GL_COMPRESSED_RGBA_S3TC_DXT5_EXT;
        break;
    default:
        free(buffer);
        throw GraphicalException("DDS with unknown format.");
    }
	
	GLuint textureID;
    glGenTextures(1, &textureID);
 
    // "Bind" the newly created texture : all future texture functions will modify this texture
    glBindTexture(GL_TEXTURE_2D, textureID);
	glPixelStorei(GL_UNPACK_ALIGNMENT,1);  
	
	unsigned int blockSize = (format == GL_COMPRESSED_RGBA_S3TC_DXT1_EXT) ? 8 : 16;
    unsigned int offset = 0;
 
    /* load the mipmaps */
    for (unsigned int level = 0; level < mipMapCount && (width || height); ++level)
    {
        unsigned int size = ((width+3)/4)*((height+3)/4)*blockSize;
        glCompressedTexImage2D(GL_TEXTURE_2D, level, format, width, height, 0, size, buffer + offset);
 
        offset += size;
        width  /= 2;
        height /= 2;
		
		if(width < 1) width = 1;
		if(height < 1) height = 1;
    }
    free(buffer); 
 
    return Resource::Image(textureID);
}

Resource::Model::Model(LUS::DList<LUS::Vec3> vertices, LUS::DList<LUS::Vec2> uvs, LUS::DList<LUS::Vec3> normals): mVertexList(vertices), mUvList(uvs), mNormalList(normals){}

LUS::Vec3* Resource::Model::GetVertex(int index)
{
	return mVertexList[index];
}

LUS::Vec2* Resource::Model::GetUV(int index)
{
	return mUvList[index];
}
LUS::Vec3* Resource::Model::GetNormal(int index)
{
	return mNormalList[index];
}

Resource::Model Resource::Model::GetObj(LUS::filepath, bool invertUv)
{
	FILE * file = fopen(filepath.c_str(), "r");
    if( file == NULL ){
		throw GraphicalException(filepath+" OBJ load failed, are you sure it exists");
	}
	
	LUS::DList<glm::vec3> temp_vertices;
	LUS::DList<glm::vec2> temp_uvs;
	LUS::DList<glm::vec3> temp_normals;
	
	LUS::DList<unsigned int> vertexIndices;
	LUS::DList<unsigned int> uvIndices;
	LUS::DList<unsigned int> normalIndices;

	while( 1 )
	{
		char lineHeader[128];
		// read the first word of the line
		int res = fscanf(file, "%s", lineHeader);
		if (res == EOF)
			break; // EOF = End Of File. Quit the loop.
		// else : parse lineHeader
		if ( strcmp( lineHeader, "v" ) == 0 )
		{
			glm::vec3 vertex;
			fscanf(file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
			temp_vertices.push_back(vertex);
		}
		else if ( strcmp( lineHeader, "vt" ) == 0 )
		{
			glm::vec2 uv;
			fscanf(file, "%f %f\n", &uv.x, &uv.y );
			uv.y = invertUV?-uv.y:uv.y; // Invert V coordinate since we will only use DDS texture, which are inverted. Remove if you want to use TGA or BMP loaders.
			temp_uvs.push_back(uv);
		}
		else if ( strcmp( lineHeader, "vn" ) == 0 )
		{
			glm::vec3 normal;
			fscanf(file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
			temp_normals.push_back(normal);
		}
		else if ( strcmp( lineHeader, "f" ) == 0 )
		{
			std::string vertex1, vertex2, vertex3;
			unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
			int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n", &vertexIndex[0], &uvIndex[0], &normalIndex[0], &vertexIndex[1], &uvIndex[1], &normalIndex[1], &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
			if (matches != 9)
			{
				throw GraphicalException("OBJ Loader Failed, try different OBJ Options, this can not read this yet");
			}
			vertexIndices.push_back(vertexIndex[0]);
			vertexIndices.push_back(vertexIndex[1]);
			vertexIndices.push_back(vertexIndex[2]);
			uvIndices.push_back(uvIndex[0]);
			uvIndices.push_back(uvIndex[1]);
			uvIndices.push_back(uvIndex[2]);
			normalIndices.push_back(normalIndex[0]);
			normalIndices.push_back(normalIndex[1]);
			normalIndices.push_back(normalIndex[2]);
		}
		else
		{
			// Probably a comment, eat up the rest of the line
			char stupidBuffer[1000];
			fgets(stupidBuffer, 1000, file);
		}
	}
	
	LUS::DList<glm::vec3> out_vertices;
	LUS::DList<glm::vec2> out_uvs;
	LUS::DList<glm::vec3> out_normals;
	
	for( unsigned int i=0; i<vertexIndices.size(); i++ )
	{
		out_vertices.push_back(temp_vertices[ vertexIndices[i]-1 ];); // Gets vertex index, then gets the vertex from the index, then puts it in the out
		out_uvs.push_back(temp_uvs[ uvIndices[i]-1 ]); // Gets uv index, then gets the uv from the index, then puts it in the out
		out_normals.push_back( temp_normals[ normalIndices[i]-1 ]); // Gets normal index, then gets the normal from the index, then puts it in the out
	}
	
	return Resource::Model(out_vertices, out_uvs, out_normals);
}

void Resource::Image::Draw()
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, GetId());
}

void Resource::Model::Render(Resource::Image img, Shader::Uniform textureUniform)
{
	img.Draw();
	glTexture1i(textureUniform.GetId(), 0);
}

Shader::Uniform(LUS::String name, unsigned int programId): mId(glGetUniformLocation(programId, name.c_str())), mName(name) {}

LUS::String Shader::Uniform::GetName()
{
	return mName;
}

unsigned int Shader::Uniform::GetId()
{
	return mId;
}

Shader::Shader::Shader(LUS::String src, Shader::ShaderType type = VERTEX): mType(type)
{
	GLenum shaderType;
	switch(mType)
	{
	case VERTEX:
		shaderType = GL_VERTEX_SHADER;
		break;
	case GEOMETRY:
		shaderType = GL_GEOMETRY_SHADER;
		break;
	case FRAGMENT:
		shaderType = GL_FRAGMENT_SHADER;
		break;
	default:
		shaderType = -1;
	}

	mId = glCreateShader(shaderType);
	const char* srcPtr = src.c_str();
	glShaderSource(mId, 1, &srcPtr, NULL);
	glCompileShader(mId);

	GLint Result = GL_FALSE;
	int InfoLogLength;

	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if ( InfoLogLength > 0 ){
		std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
		glGetShaderInfoLog(mId, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
		throw Exception(LUS::String(&VertexShaderErrorMessage[0]));
	}
}

unsigned int Shader::Shader::GetId()
{
	return mId;
}

Shader::ShaderType Shader::Shader::GetType()
{
	return mType;
}

Shader::ShaderProgram::ShaderProgram(): mId(glCreateProgram()) 
{
	if(!IsValid()) throw GraphicalException("Shader Creation Failed, ");
}

Shader::ShaderProgram::~ShaderProgram()
{
	glDeleteProgram(mId);
}

bool Shader::ShaderProgram::IsValid()
{
	return mId;
}

bool Shader::ShaderProgram::AssignShader(Shader::Shader* shader)
{
	if(!IsValid()) return false;

	if((shaders[shader->GetType()] = shader) == shader)
	{
		return true;
	}

	return false;
}

void Shader::ShaderProgram::LoadUniform(LUS::String name)
{
	if(!IsValid()) return;
	uniforms.push_back(Uniform(GetId(), name));
}

unsigned int Shader::ShaderProgram::GetId()
{
	return mId;
}

Render::Camera::Camera(LUS::Vec3<double> pos, LUS::Vec3<LUS::Radian> rotation, float fov): position(pos), rotation(rotation), fov(fov) {}

virtual void Render::Camera::Update(int tick) {}

Mat4 Render::Camera::GetViewMatrix()
{
	return glm::lookAt(glm::vec3(position.x, position.y, position.z), glm::vec3(rotation.x.toDegree().ang, rotation.y.toDegree().ang, rotation.z.toDegree().ang), glm::vec3(0, upsideDown?-1:1,0));
}

void Render::Camera::Rotate(LUS::Vec2<Angle> rotations);
{
	onRotate(rotations);
	rotation = rotations;
}

void Render::Camera::moveTo(LUS::Vec2<double> pos)
{
	onMove(pos);
	position = pos;
}

LUS::Vec3<double> Render::Camera::GetPosition()
{
	return position;
}

LUS::Vec3<LUS::Radian> Render::Camera::GetRotation()
{
	return rotation;
}

Shader::ShaderProgram Render::IDraw::GetShader()
{
	return mShaderProgam;
}

bool Render::Draw2D::assignTexture(Resource::Image texture)
{
	this->texture = texture;
}

void Render::Draw2D::rotate(LUS::Vec2<Angle> rotations)
{
	onRotate(rotations);
	rotation = rotations;
}

void Render::Draw2D::moveTo(LUS::Vec2<double> pos)
{
	onMove(pos);
	position = pos;
}

void Render::Draw2D::rescale(LUS::Vec2<float> scale)
{
	onRescale(scale);
	this->scale = scale;
}

void Render::Draw2D::setZLevel(double z)
{
	onZLevel(z);
	zLevel = z;
}

LUS::Vec2<double> Render::Draw2D::GetPosition()
{
	return position;
}

LUS::Vec2<LUS::Radian> Render::Draw2D::GetRotation()
{
	return rotation;
}

LUS::Vec2<float> Render::Draw2D::GetScale()
{
	return scale;
}

double Render::Draw2D::GetZLevel()
{
	return zLevel;
}

Mat4 Render::Draw2D::GetModelMatrix()
{
	Mat4 modelMatrix = Mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(GetPosition().x, GetPosition().y, GetZLevel()));
	modelMatrix = glm::rotate(modelMatrix, 1, glm::vec3(GetRotation().x.toDegree().ang, GetRotation().y.toDegree().ang, 0));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(GetScale().x, GetScale().y, 0));
	return modelMatrix;
}

void Render:Draw2D::Update(int tickUpdate) {}

void Render::Draw2D::Render()
{
	
}

bool Render::Draw3D::assignTexture(Resource::Image texture)
{
	this->texture = texture;
}

bool Render::Draw3D::assignModel(Resource::Model model)
{
	this->model = model;
}

void Render::Draw3D::rotate(LUS::Vec3<Angle> rotations)
{
	onRotate(rotations);
	rotation = rotations;
}

void Render::Draw3D::moveTo(LUS::Vec3<double> pos)
{
	onMove(pos);
	position = pos;
}

void Render::Draw3D::rescale(LUS::Vec3<float> scale)
{
	onRescale(scale);
	this->scale = scale;
}

LUS::Vec3<double> Render::Draw3D::GetPosition()
{
	return position;
}

LUS::Vec3<LUS::Radian> Render::Draw3D::GetRotation()
{
	return rotation;
}

LUS::Vec3<float> Render::Draw3D::GetScale()
{
	return scale;
}

Mat4 Render::Draw3D::GetModelMatrix()
{
	modelMatrix = Mat4(1.0f);
	modelMatrix = glm::translate(modelMatrix, glm::vec3(GetPosition().x, GetPosition().y, GetPosition().z));
	modelMatrix = glm::rotate(modelMatrix, 1, glm::vec3(GetRotation().x.toDegree().ang, GetRotation().y.toDegree().ang, GetRotation().z.toDegree().ang));
	modelMatrix = glm::scale(modelMatrix, glm::vec3(GetScale().x, GetScale().y, GetScale().z));
	return modelMatrix;
}

OpenGLManager::OpenGLManager(float aspectRatio)
{
	settings->useVBO = false;
	settings->shaderProg = NULL;
	settings->mainCamera = Camera(LUS::Vec3<double>(0,0,0), LUS::Vec3<LUS::Radian>(0,0,0));
	settings->aspectRatio = aspectRatio;
	settings->displayRange = LUS::Vec2(0.1f,100.0f);
}

OpenGLManager::~OpenGLManager() 
{
	delete settings; 
	for(LUS::DList<Render::DrawObject*>::iterator it = mpObjectsList.begin(); it != mpObjectsList.end(); ++it) if (!(*it)->keepUp) delete *it;
}

Render::DrawObject* OpenGLManager::addDrawable(Render::DrawObject* draw)
{
	mpObjectsList.push_back(draw);
}

OpenGLManager::glsettings_t* OpenGLManager::GetSettings()
{ 
	return settings; 
}

Mat4 OpenGLManager::GetProjectionMatrix()
{
	return glm::perspective(settings->mainCamera.fov, settings->mainCamera.aspectRatio, settings->displayRange.x, settings->displayRange.y);
}

Mat4 OpenGLManager::GetMVPFor(Render::IDraw draw)
{
	return draw.GetModelMatrix() * GetProjectionMatrix() * settings->mainCamera.GetViewMatrix();
}

void OpenGLManager::Render()
{
	Shader::ShaderProgram mainShader = settings->shaderProg;
	for(LUS::DList<Render::DrawObject*>::iterator it = mpObjectsList.begin(); it != mpObjectsList.end(); ++it)
	{
		Render:DrawObject* obj = *it;
		obj->Update(tickUpdate);
		obj->Render();
	}
}