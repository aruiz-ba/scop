#include "scop.h"

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path)
{
	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);	

	//read Vertex shader
//	const char *vertexShaderSource = "#version 330 core\n"
//    		"layout (location = 0) in vec3 aPos;\n\n"
//    		"layout(location = 1) in vec3 vertexColor;\n\n"
//    		"out vec3 fragmentColor;\n\n"
//    		"void main()\n"
//    		"{\n"
//    		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//    		"   fragmentColor = vertexColor;\n" "}\0";
	//read fragment shader
//	const char *fragmentShaderSource = "#version 330 core\n"
//		"in vec3 fragmentColor;\n"
//		"out vec3 color;\n"
//		"void main()\n"
//		"{\n"
//	   	"	color = fragmentColor;\n"
//		"}\n\0";
	const char *vertexShaderSource = "#version 330 core\n"
    		//"layout(location = 0) in vec3 vertexPosition_modelspace;\n\n"
    		"layout (location = 0) in vec3 aPos;\n\n"
    		"layout(location = 1) in vec2 vertexUV;\n\n"
    		"out vec2 UV;\n\n"
    		"uniform mat4 MVP;\n\n"
    		"void main()\n"
    		"{\n"
    		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
//    		"   gl_Position = MVP * vec4(vertexPosition_modelspace,1);\n"
    		"   UV = vertexUV;\n" 
		"}\n\0";

	const char *fragmentShaderSource = "#version 330 core\n"
		"in vec2 UV;\n"
		"out vec3 color;\n"
		"uniform sampler2D myTextureSampler;\n"
		"void main()\n"
		"{\n"
	   	"	color = texture( myTextureSampler, UV ).rgb;\n"
		"}\n\0";

	//Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	glShaderSource(VertexShaderID, 1, &vertexShaderSource, NULL);
	glCompileShader(VertexShaderID);
	
	//Check Vertex Shader
	int  success;
	char infoLog[512];
	int InfoLogLength;
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &success);
	glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
	if( InfoLogLength > 0 )
	{
		glGetShaderInfoLog(VertexShaderID, 512, NULL, infoLog);
		printf("Error in shader compilation: %s\n", infoLog);
	}

	//Compile Fragment Shader
	printf("Compiling shader : %s\n", fragment_file_path);
	glShaderSource(FragmentShaderID, 1, &fragmentShaderSource , NULL);
	glCompileShader(FragmentShaderID);

	//Check Fragment Shader
	glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &success);
	if(!success)
	{
	    glGetShaderInfoLog(FragmentShaderID, 512, NULL, infoLog);
	    printf("Error in fragment shader compilation: %s\n", infoLog);
	}
	// Link the program
	printf("Linking program\n");
	GLuint ProgramID = glCreateProgram();
	glAttachShader(ProgramID, VertexShaderID);
	glAttachShader(ProgramID, FragmentShaderID);
	glLinkProgram(ProgramID);


	// Check the program
	glGetProgramiv(ProgramID, GL_LINK_STATUS, &success);
	if(!success) {
	    glGetProgramInfoLog(ProgramID, 512, NULL, infoLog);
	    printf("Error with linking shader: %s\n", infoLog);
	}

	glDetachShader(ProgramID, VertexShaderID);
	glDetachShader(ProgramID, FragmentShaderID);
	
	glDeleteShader(VertexShaderID);
	glDeleteShader(FragmentShaderID);
	return ProgramID;
}
