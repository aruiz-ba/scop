#include "scop.h"

void init_glew()
{
	GLenum err = glewInit();
	if (err != GLEW_OK)
	  exit(1); // or handle the error in a nicer way
	if (!GLEW_VERSION_2_1)  // check that the machine supports the 2.1 API.
	  exit(1); // or handle the error in a nicer way
}

int	keyStates[256];
t_key	key;
t_obj	obj;

void display()
{
	key_to_transform(&key, keyStates);	
	if (keyStates[119] == 1)
		key.rot_x += 0.1f;
	//printf("test %f\n", key.rot_x);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	set_draw(&key, &obj);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS); 
}

void key_down(unsigned char key, int x, int y)
{
	if (key == 033)
		exit(0);

//	if (key == 119)
//		printf("w is pressed\n");
//	if (key == 97)
//		printf("a is pressed\n");
//	if (key == 100)
//		printf("d is pressed\n");
//	if (key == 115)
//		printf("s is pressed\n");
		
	keyStates[key] = 1;
//	printf("Keypress:%i\n", key);
	printf("coords:%i, %i\n", x, y);
	glutPostRedisplay();
}

void key_up (unsigned char key, int x, int y)
{  
//	if (key == 119)
//		printf("w is up\n");
//	if (key == 97)
//		printf("a is up\n");
//	if (key == 100)
//		printf("d is up\n");
//	if (key == 115)
//			printf("s is up\n");
	keyStates[key] = 0;
	printf("coords:%i, %i\n", x, y);
	glutPostRedisplay();
} 

int main(int argc, char **argv)
{

	//Create and compile our GLSL program from the shaders
	key.rot_x = 0.0f;
	key.rot_y = 0.0f;
	key.zoom = 0.5f;
	glutInit(&argc, argv);
	init_glut();
	init_glew();

	glutDisplayFunc(display);
	glutSwapBuffers();

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	//parse texture
	//parse_texture(argv[1]);

	parse_obj_v(argv[1], &obj);
	parse_obj_f(argv[1], &obj);
	printf("Number of triangles: %i\n", obj.t_n);

	//loadBMP_custom("./textures/texture.bmp");
	loadBMP_custom("./textures/dirt.bmp");
	// When MAGnifying the image (no bigger mipmap available), use LINEAR filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// When MINifying the image, use a LINEAR blend of two mipmaps, each filtered LINEARLY too
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	// Generate mipmaps, by the way.
	glGenerateMipmap(GL_TEXTURE_2D);
	//loadBMP_custom("./textures/test2.bmp");

	glutKeyboardFunc(key_down);
	glutKeyboardUpFunc(key_up);

	glutMainLoop();
}
