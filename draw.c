#include "scop.h"

void	set_draw(t_key *key)
{
	//Create VAO or Vertex Array Object
	GLuint programID = LoadShaders( "VertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );
	GLuint VertexArrayID;
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

//	float	vertex_buffer[36][3] = {
//		{-1.0f,-1.0f,-1.0f}, // triangle 1 : begin}
//		{-1.0f,-1.0f, 1.0f},
//		{-1.0f, 1.0f, 1.0f}, // triangle 1 : end
//		{1.0f, 1.0f,-1.0f}, // triangle 2 : begin
//		{-1.0f,-1.0f,-1.0f},
//		{-1.0f, 1.0f,-1.0f}, // triangle 2 : end
//		{1.0f,-1.0f, 1.0f},
//		{-1.0f,-1.0f,-1.0f},
//		{1.0f,-1.0f,-1.0f},
//		{1.0f, 1.0f,-1.0f},
//		{1.0f,-1.0f,-1.0f},
//		{-1.0f,-1.0f,-1.0f},
//		{-1.0f,-1.0f,-1.0f},
//		{-1.0f, 1.0f, 1.0f},
//		{-1.0f, 1.0f,-1.0f},
//		{1.0f,-1.0f, 1.0f},
//		{-1.0f,-1.0f, 1.0f},
//		{-1.0f,-1.0f,-1.0f},
//		{-1.0f, 1.0f, 1.0f},
//		{-1.0f,-1.0f, 1.0f},
//		{1.0f,-1.0f, 1.0f},
//		{1.0f, 1.0f, 1.0f},
//		{1.0f,-1.0f,-1.0f},
//		{1.0f, 1.0f,-1.0f},
//		{1.0f,-1.0f,-1.0f},
//		{1.0f, 1.0f, 1.0f},
//		{1.0f,-1.0f, 1.0f},
//		{1.0f, 1.0f, 1.0f},
//		{1.0f, 1.0f,-1.0f},
//		{-1.0f, 1.0f,-1.0f},
//		{1.0f, 1.0f, 1.0f},
//		{-1.0f, 1.0f,-1.0f},
//		{-1.0f, 1.0f, 1.0f},
//		{1.0f, 1.0f, 1.0f},
//		{-1.0f, 1.0f, 1.0f},
//		{1.0f,-1.0f, 1.0f}
//	};
	//float	vertex_buffer[42][3] = {
	float	output[42][3] = {
		{0.232406f, -1.216630f, 1.133818f},
		{0.232406f, -0.745504f, 2.843098f},
		{-0.227475f, -0.745504f, 2.843098f},
		{-0.227475f, -1.216630f, 1.133818f},
		{0.232407f, 1.119982f, 1.133819f},
		{0.232406f, 1.119982f, 1.602814f},
		{-0.227475f, 1.119982f, 1.602813f},
		{-0.227475f, 1.119982f, 1.133818f},
		{0.232406f, -0.340316f, 2.843098f},
		{-0.227475f, -0.340316f, 2.843098f},
		{0.232407f, -0.305193f, 1.133819f},
		{0.232407f, -0.294496f, 2.297937f},
		{-0.227475f, -0.305193f, 1.133818f},
		{-0.227475f, -0.294496f, 2.297937f},
		{0.232406f, -1.222569f, 1.497195f},
		{0.232406f, -0.745504f, 1.477731f},
		{-0.227475f, -0.745504f, 1.477731f},
		{-0.227475f, -1.222569f, 1.497194f},
		{-0.227403f, -0.731178f, 0.901477f},
		{-0.227403f, -0.731178f, -0.037620f},
		{0.223704f, -0.731178f, -0.037620f},
		{0.223704f, -0.731178f, 0.901477f},
		{-0.227403f, 1.119377f, 0.901477f},
		{-0.227403f, 1.119377f, -0.037620f},
		{0.223704f, 1.119377f, -0.037620f},
		{0.223704f, 1.119377f, 0.901477f},
		{-0.227403f, -0.129772f, 0.901477f},
		{-0.227403f, 0.551492f, 0.384487f},
		{-0.227403f, 1.104268f, 0.408501f},
		{-0.227403f, 0.507336f, 0.901477f},
		{0.223704f, 0.507336f, 0.901477f},
		{0.223704f, 1.104269f, 0.408501f},
		{0.223704f, 0.551492f, 0.384487f},
		{0.223704f, -0.129772f, 0.901477f},
		{-0.227403f, 0.634134f, -0.037620f},
		{-0.227403f, -0.066768f, 0.398575f},
		{-0.227403f, -0.684649f, 0.389681f},
		{-0.227403f, -0.075523f, -0.037620f},
		{0.223704f, 0.634134f, -0.037620f},
		{0.223704f, -0.066768f, 0.398575f},
		{0.223704f, -0.684649f, 0.389681f},
		{0.223704f, -0.075523f, -0.037620f}
	};
	int faces[47][4] = {
		{16,2,3,17},
		{5,8,7,6},
		{2,9,10,3},
		{5,12,14,8},
		{12,11,13,14},
		{1,15,18,4},
		{15,16,17,18},
		{38,42,21,20},
		{33,39,25,32},
		{34,27,19,22},
		{19,20,21,22},
		{26,25,24,23},
		{26,23,30,31},
		{31,30,29,32},
		{32,29,28,33},
		{33,28,27,34},
		{24,25,39,35},
		{35,39,40,36},
		{36,40,41,37},
		{37,41,42,38},
		{26,31,32,-1},
		{37,38,20,-1},
		{21,42,41,-1},
		{12,5,6,-1},
		{25,26,32,-1},
		{22,21,41,-1},
		{8,14,7,-1},
		{28,36,27,-1},
		{10,14,17,3},
		{33,40,39,-1},
		{40,33,34,-1},
		{11,16,15,1},
		{14,10,7,-1},
		{2,16,12,9},
		{11,12,16,-1},
		{40,34,22,41},
		{12,6,9,-1},
		{18,17,13,4},
		{36,28,35,-1},
		{37,20,19,-1},
		{29,23,24,-1},
		{19,27,36,37},
		{24,35,28,29}
	};
	//float output[200][3];
	//print(vertex_buffer, faces, output);
	float vertex_buffer[278][3];
	print(output, faces, vertex_buffer);
	scale(vertex_buffer, key->zoom);
	//rotation_x(vertex_buffer, 0.10f);
	rotation_y(vertex_buffer, key);
	// Two UV coordinatesfor each vertex. They were created with Blender. You'll learn shortly how to do this yourself.
	static const GLfloat g_uv_buffer_data[] = {
	    0.000059f, 1.0f, -0.000004f,
	    0.000103f, 1.0f, -0.336048f,
	    0.335973f, 1.0f, -0.335903f,
	    1.000023f, 1.0f, -0.000013f,
	    0.667979f, 1.0f, -0.335851f,
	    0.999958f, 1.0f, -0.336064f,
	    0.667979f, 1.0f, -0.335851f,
	    0.336024f, 1.0f, -0.671877f,
	    0.667969f, 1.0f, -0.671889f,
	    1.000023f, 1.0f, -0.000013f,
	    0.668104f, 1.0f, -0.000013f,
	    0.667979f, 1.0f, -0.335851f,
	    0.000059f, 1.0f, -0.000004f,
	    0.335973f, 1.0f, -0.335903f,
	    0.336098f, 1.0f, -0.000071f,
	    0.667979f, 1.0f, -0.335851f,
	    0.335973f, 1.0f, -0.335903f,
	    0.336024f, 1.0f, -0.671877f,
	    1.000004f, 1.0f, -0.671847f,
	    0.999958f, 1.0f, -0.336064f,
	    0.667979f, 1.0f, -0.335851f,
	    0.668104f, 1.0f, -0.000013f,
	    0.335973f, 1.0f, -0.335903f,
	    0.667979f, 1.0f, -0.335851f,
	    0.335973f, 1.0f, -0.335903f,
	    0.668104f, 1.0f, -0.000013f,
	    0.336098f, 1.0f, -0.000071f,
	    0.000103f, 1.0f, -0.336048f,
	    0.000004f, 1.0f, -0.671870f,
	    0.336024f, 1.0f, -0.671877f,
	    0.000103f, 1.0f, -0.336048f,
	    0.336024f, 1.0f, -0.671877f,
	    0.335973f, 1.0f, -0.335903f,
	    0.667969f, 1.0f, -0.671889f,
	    1.000004f, 1.0f, -0.671847f,
	    0.667979f, 1.0f, -0.335851f
	};

//	//static const GLfloat g_vertex_buffer_data[36][3];
//	static const GLfloat g_color_buffer_data[] = {
//	    0.583f,  0.771f,  0.014f,
//	    0.609f,  0.115f,  0.436f,
//	    0.327f,  0.483f,  0.844f,
//	    0.822f,  0.569f,  0.201f,
//	    0.435f,  0.602f,  0.223f,
//	    0.310f,  0.747f,  0.185f,
//	    0.597f,  0.770f,  0.761f,
//	    0.559f,  0.436f,  0.730f,
//	    0.359f,  0.583f,  0.152f,
//	    0.483f,  0.596f,  0.789f,
//	    0.559f,  0.861f,  0.639f,
//	    0.195f,  0.548f,  0.859f,
//	    0.014f,  0.184f,  0.576f,
//	    0.771f,  0.328f,  0.970f,
//	    0.406f,  0.615f,  0.116f,
//	    0.676f,  0.977f,  0.133f,
//	    0.971f,  0.572f,  0.833f,
//	    0.140f,  0.616f,  0.489f,
//	    0.997f,  0.513f,  0.064f,
//	    0.945f,  0.719f,  0.592f,
//	    0.543f,  0.021f,  0.978f,
//	    0.278f,  0.317f,  0.505f,
//	    0.167f,  0.620f,  0.077f,
//	    0.347f,  0.857f,  0.137f,
//	    0.055f,  0.953f,  0.042f,
//	    0.714f,  0.505f,  0.345f,
//	    0.783f,  0.290f,  0.734f,
//	    0.722f,  0.645f,  0.174f,
//	    0.302f,  0.455f,  0.848f,
//	    0.225f,  0.587f,  0.040f,
//	    0.517f,  0.713f,  0.338f,
//	    0.053f,  0.959f,  0.120f,
//	    0.393f,  0.621f,  0.362f,
//	    0.673f,  0.211f,  0.457f,
//	    0.820f,  0.883f,  0.371f,
//	    0.982f,  0.099f,  0.879f
//	};

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
	//glBufferData(GL_ARRAY_BUFFER, sizeof(g_color_buffer_data), g_color_buffer_data, GL_STATIC_DRAW);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, colorbuffer);
	glVertexAttribPointer(
		1,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		2,                  // size
		GL_FLOAT,           // type
		GL_FALSE,           // normalized?
		0,                  // stride
		(void*)0            // array buffer offset
	);
	glUseProgram(programID);

	//Draw the triangle
	//glDrawArrays(GL_TRIANGLES, 0, 42);
	//glDrawArrays(GL_TRIANGLE_FAN, 0, 38);
	glDrawArrays(GL_TRIANGLES, 0, (3 * 2 * 42)- 16 * 3);
	glFlush();
}
