#include "scop.h"

void display()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	init_glut();

	glutDisplayFunc(display);
	glutMainLoop();
}
