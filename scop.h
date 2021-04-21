#include "GL/glew.h"
#include "GL/gl.h"
#include "GL/glut.h"

#include <stdio.h> //BORRAME

void init_glut();
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
void	translation(const GLfloat g_vertex_buffer_data[]);
void	scale(float input[12][3], float scale);
