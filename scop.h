#include "GL/glew.h"
#include "GL/gl.h"
#include "GL/glut.h"
#include "./Libft/libft.h"

#include <stdio.h> //BORRAME

typedef	struct		s_key
{
	float				rot_x;
	float				rot_y;
	float				rot_z;
	float				zoom;
}					t_key;

typedef	struct		s_obj
{
	float	**v;
	int	**f;
	int	v_size;
	int	f_size;
	float	**t_v; //total triangles vertices
	int	t_n; //total triangle number
}					t_obj;

void init_glut();
GLuint LoadShaders(const char * vertex_file_path,const char * fragment_file_path);
void	translation(const GLfloat g_vertex_buffer_data[]);
void	scale(t_obj *obj, float scale);
void	rotation_x(float input[278][3], float angle);
void	rotation_y(t_obj *obj, t_key *key);
void	set_draw(t_key *key, t_obj *obj);
GLuint loadBMP_custom(const char * imagepath);
void	key_to_transform(t_key *key, int keyStates[256]);
void	print(t_obj *obj);
int	parse_texture(char *args);
int	parse_obj_v(char *args, t_obj *obj);
int	parse_obj_f(char *args, t_obj *obj);
