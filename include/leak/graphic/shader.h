#ifndef _LGS_SHADER_H_
#define _LGS_SHADER_H_

#include <leak/util/util.h>

namespace Leak
{
	namespace Graphic
	{
		class ShaderProgram;

		class Uniform
		{
			friend class ShaderProgram;
			
			LUS::String	mName;
			unsigned int	mId;
			
			Uniform(Util::String name, unsigned int programId);
		public:
			Util::String 	GetName();
			unsigned int 	GetId();
		};

		class Shader
		{
			unsigned int mId;
			ShaderType mType;
		public:
			enum ShaderType
			{
				VERTEX = 0,
				GEOMETRY,
				FRAGMENT,
				SHADER_TYPES_LENGTH
			};
		
			Shader(Util::String src, ShaderType type = VERTEX);

			unsigned int 	GetId();
			ShaderType 	GetType();
		};

		class ShaderProgram
		{
			unsigned int 					mId;
			Shader	 						shaders[SHADER_TYPES_LENGTH];
			Util::DList<Uniform> 		uniforms;

			bool 				IsValid();
		public:
			ShaderProgram();
			
			bool 				AssignShader(Shader* shader);
			void 				LoadUniform(Util::String name);
			unsigned int 	GetId();
			
			~ShaderProgram();
		};
	}
}

#endif