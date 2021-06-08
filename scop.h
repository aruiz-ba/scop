#include "GL/glew.h"
#include "GL/gl.h"
#include "GL/glut.h"

#include <stdio.h> //BORRAME

typedef	struct		s_key
{
	float				rot_x;
	float				rot_y;
	float				rot_z;
	float				zoom;
}					t_key;

void init_glut();
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
void	translation(const GLfloat g_vertex_buffer_data[]);
void	scale(float input[42][3], float scale);
void	rotation_x(float input[42][3], float angle);
void	rotation_y(float input[42][3], t_key *key);
void	set_draw(t_key *key);
GLuint loadBMP_custom(const char * imagepath);
void	key_to_transform(t_key *key, int keyStates[256]);

void	print(float obj[42][3], int faces[6][4], float output[200][3]);
