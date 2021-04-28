#include "scop.h"

void init_glew()
{
	GLenum err = glewInit();
	if (err != GLEW_OK)
	  exit(1); // or handle the error in a nicer way
	if (!GLEW_VERSION_2_1)  // check that the machine supports the 2.1 API.
	  exit(1); // or handle the error in a nicer way
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv)
{
	//Create and compile our GLSL program from the shaders
	glutInit(&argc, argv);
	init_glut();
	init_glew();
	GLuint programID = LoadShaders( "VertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS); 

	//Create VAO or Vertex Array Object
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	float	vertex_buffer[36][3] = {
		{-1.0f,-1.0f,-1.0f}, // triangle 1 : begin}
		{-1.0f,-1.0f, 1.0f},
		{-1.0f, 1.0f, 1.0f}, // triangle 1 : end
		{1.0f, 1.0f,-1.0f}, // triangle 2 : begin
		{-1.0f,-1.0f,-1.0f},
		{-1.0f, 1.0f,-1.0f}, // triangle 2 : end
		{1.0f,-1.0f, 1.0f},
		{-1.0f,-1.0f,-1.0f},
		{1.0f,-1.0f,-1.0f},
		{1.0f, 1.0f,-1.0f},
		{1.0f,-1.0f,-1.0f},
		{-1.0f,-1.0f,-1.0f},
		{-1.0f,-1.0f,-1.0f},
		{-1.0f, 1.0f, 1.0f},
		{-1.0f, 1.0f,-1.0f},
		{1.0f,-1.0f, 1.0f},
		{-1.0f,-1.0f, 1.0f},
		{-1.0f,-1.0f,-1.0f},
		{-1.0f, 1.0f, 1.0f},
		{-1.0f,-1.0f, 1.0f},
		{1.0f,-1.0f, 1.0f},
		{1.0f, 1.0f, 1.0f},
		{1.0f,-1.0f,-1.0f},
		{1.0f, 1.0f,-1.0f},
		{1.0f,-1.0f,-1.0f},
		{1.0f, 1.0f, 1.0f},
		{1.0f,-1.0f, 1.0f},
		{1.0f, 1.0f, 1.0f},
		{1.0f, 1.0f,-1.0f},
		{-1.0f, 1.0f,-1.0f},
		{1.0f, 1.0f, 1.0f},
		{-1.0f, 1.0f,-1.0f},
		{-1.0f, 1.0f, 1.0f},
		{1.0f, 1.0f, 1.0f},
		{-1.0f, 1.0f, 1.0f},
		{1.0f,-1.0f, 1.0f}
	};
	scale(vertex_buffer, 0.5f);
	printf("tras escalar: %f\n" , vertex_buffer[0][0]);
	//rotation_x(vertex_buffer, 0.2f);
	//printf("transformao en x: %f\n" , vertex_buffer[0][0]);
	rotation_y(vertex_buffer, 10);
	//printf("transformao en y: %f\n" , vertex_buffer[0][0]);
	//printf("Does It change?: %f\n", vertex_buffer[0][2]);
	//printf("Does It change?: %f\n", vertex_buffer[0][2]);
	//static const GLfloat g_vertex_buffer_data[36][3];
	static const GLfloat g_color_buffer_data[] = {
	    0.583f,  0.771f,  0.014f,
	    0.609f,  0.115f,  0.436f,
	    0.327f,  0.483f,  0.844f,
	    0.822f,  0.569f,  0.201f,
	    0.435f,  0.602f,  0.223f,
	    0.310f,  0.747f,  0.185f,
	    0.597f,  0.770f,  0.761f,
	    0.559f,  0.436f,  0.730f,
	    0.359f,  0.583f,  0.152f,
	    0.483f,  0.596f,  0.789f,
	    0.559f,  0.861f,  0.639f,
	    0.195f,  0.548f,  0.859f,
	    0.014f,  0.184f,  0.576f,
	    0.771f,  0.328f,  0.970f,
	    0.406f,  0.615f,  0.116f,
	    0.676f,  0.977f,  0.133f,
	    0.971f,  0.572f,  0.833f,
	    0.140f,  0.616f,  0.489f,
	    0.997f,  0.513f,  0.064f,
	    0.945f,  0.719f,  0.592f,
	    0.543f,  0.021f,  0.978f,
	    0.279f,  0.317f,  0.505f,
	    0.167f,  0.620f,  0.077f,
	    0.347f,  0.857f,  0.137f,
	    0.055f,  0.953f,  0.042f,
	    0.714f,  0.505f,  0.345f,
	    0.783f,  0.290f,  0.734f,
	    0.722f,  0.645f,  0.174f,
	    0.302f,  0.455f,  0.848f,
	    0.225f,  0.587f,  0.040f,
	    0.517f,  0.713f,  0.338f,
	    0.053f,  0.959f,  0.120f,
	    0.393f,  0.621f,  0.362f,
	    0.673f,  0.211f,  0.457f,
	    0.820f,  0.883f,  0.371f,
	    0.982f,  0.099f,  0.879f
	};

	//translation(g_vertex_buffer_data);	

	// This will identify our vertex buffer
	GLuint vertexbuffer;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
	//glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);	
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertex_buffer), vertex_buffer, GL_STATIC_DRAW);	


	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	//Now here we do the same but for colours
	GLuint colorbuffer;
	glGenBuffers(1, &colorbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		3,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);

	glutDisplayFunc(display);
	glUseProgram(programID);

	//Draw the triangle
	glDrawArrays(GL_TRIANGLES, 0, 12*3);
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glFlush();
	glutMainLoop();
}
