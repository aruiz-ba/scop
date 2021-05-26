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
	set_draw();
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS); 
}

void inputhandler(unsigned char key, int x, int y)
{
	if (key == 033)
		exit(0);
		
	printf("Keypress:%i\n", key);
	printf("coords:%i, %i\n", x, y);
}

int main(int argc, char **argv)
{
	//Create and compile our GLSL program from the shaders
	glutInit(&argc, argv);
	init_glut();
	init_glew();

	glutDisplayFunc(display);
	glutSwapBuffers();
	glutKeyboardFunc(inputhandler);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	loadBMP_custom("./textures/texture.bmp");
	glutMainLoop();
}
