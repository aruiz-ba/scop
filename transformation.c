#include "scop.h"
#include <math.h>

void rotation_y(t_obj *obj, t_key *key)
{
	int i;
	int y;
	float anglex = key->rot_x;
	float angley = key->rot_y;
	//angley = 34;
	float anglez = 0.0f;
	int	total_vertices;

	float rotate_x[4][4] = {
		{cos(anglez) * cos(angley), (cos(anglez) * sin(angley) * sin(anglex)) - (sin(anglez) * cos(anglex)), (cos(anglez) * sin(angley) *cos(anglex)) + (sin(anglez) * sin(anglex))},
		{sin(anglez) * cos(angley), (sin(anglez) * sin(angley) * sin(anglex)) + (cos(anglez) * cos(anglex)), (sin(anglez) * sin(angley) * cos(anglex)) - (cos(anglez) * sin(anglex))},
		{-sin(angley), cos(angley) * sin(anglex), cos(angley) * cos(anglex)},
	};

	i = 0;
	y = 0;
	total_vertices = obj->t_n * 3;
	while (y < total_vertices)
	{
		//input[y][0] =  input[y][0];
		//input[y][1] =  (cos(angle) * input[y][1]) - (sin(angle) * input[y][2]);
		//input[y][2] =  (sin(angle) * input[y][1]) - (sin(angle) * input[y][2]);

		while (i < 3)
		{
			obj->t_v[y][i] = ((rotate_x[i][0] * obj->t_v[y][0]) 
				+ (rotate_x[i][1] * obj->t_v[y][1])
				+ (rotate_x[i][2] * obj->t_v[y][2]));
			i++;
		}
		i = 0;
		y++;
	}
}

void rotation_x(float input[278][3], float angle)
{
//	int i;
	int y;

//	float rotate_x[4][4] = {
//		{1.0f, 0.0f, 0.0f},
//		{0.0f, cos(angle), -sin(angle)},
//		{0.0f, sin(angle), cos(angle)},
//	};
///
//	i = 0;
	y = 0;
	printf("Print of sen %f\n", sin(0.2f));
	while (y < 278)
	{
		input[y][0] =  (cos(angle) * input[y][0]) - (sin(angle) * input[y][1]);
		input[y][1] =  (sin(angle) * input[y][0]) + (cos(angle) * input[y][1]);
		input[y][2] =  input[y][1];
		//input[y][0] = glRotatef(angle, input[y][0], input[y][1], input[y][2]);
	//	input[y][0] =  (cos(angle) * input[y][0]) + (sin(angle) * input[y][2]);
	//	input[y][1] =  input[y][1];
	//	input[y][2] =  (-sin(angle) * input[y][0]) + (cos(angle) * input[y][2]);
//		while (i < 3)
//		{
//			input[y][i] = ((rotate_x[i][0] * input[y][0]) 
//				+ (rotate_x[i][1] * input[y][1])
//				+ (rotate_x[i][2] * input[y][2]));
//			i++;
//		}
//		i = 0;
		y++;
	}
}

void scale(t_obj *obj, float scale)
{
	int	y;
	int	total_vertices;

	y = 0;
	total_vertices = obj->t_n * 3;
	while (y < total_vertices)
	{
		obj->t_v[y][0] *= scale;
		obj->t_v[y][1] *= scale;
		obj->t_v[y][2] *= scale;
		y++;	
	}
}

//void	translation(const GLfloat g_vertex_buffer_dat[])
//{
//	//printf("g_vertex_shit%f", g_vertex_buffer_dat[0]);
//	int	x_move = 10;
//	int	y_move = 1;
//	int	z_move = 3;
//	float out[4];
//	int i;
//	int translation[4][4] = {
//		{1, 0, 0, x_move},
//		{0, 1, 0, y_move},
//		{0, 0, 1, z_move},
//		{0, 0, 0, 1}
//	};
//	float vertex[4] = {-1.0f, -1.0f, 0.0f, 1};
//
//	i = 0;
//	while (i < 4)
//	{
//		out[i] = ((translation[i][0] * vertex[0]) 
//			+ (translation[i][1] * vertex[1])
//			+ (translation[i][2] * vertex[2])
//			+ (translation[i][3] * vertex[3]));
//		i++;
//	}
//	//printf("testesito1: %f \n", out[0]);
//	//printf("testesito2: %f \n", out[1]);
//	//printf("testesito3: %f \n", out[2]);
//	//printf("testesito4: %f \n", out[3]);
//}
