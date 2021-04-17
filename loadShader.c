#include "scop.h"

GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path)
{
	// Create the shaders
	GLuint VertexShaderID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentShaderID = glCreateShader(GL_FRAGMENT_SHADER);	

	//read Vertex shader
	const char *vertexShaderSource = "#version 330 core\n"
    		"layout (location = 0) in vec3 aPos;\n\n"
    		"void main()\n"
    		"{\n"
    		"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    		"}\0";
	//read fragment shader
	const char *fragmentShaderSource = "#version 330 core\n"
		"out vec3 FragColor;\n"
		"void main()\n"
		"{\n"
	   	"	FragColor = vec3(1, 0, 0);\n"
		"}\n\0";

	//Compile Vertex Shader
	printf("Compiling shader : %s\n", vertex_file_path);
	glShaderSource(VertexShaderID, 1, &vertexShaderSource, NULL);
	glCompileShader(VertexShaderID);
	
	//Check Vertex Shader
	int  success;
	char infoLog[512];
	glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &success);
	if(!success)
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
