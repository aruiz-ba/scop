#include "scop.h"

void	scale(float input[12][3], float scale)
{
	float	out[12][3];
	int	y;

	y = 0;
	while (*input[y])
	{
		out[y][0] = input[y][0] * scale;
		out[y][1] = input[y][1] * scale;
		out[y][2] = input[y][2] * scale;
		y++;	
	}
	printf("TestOutput: %f", out[0][1]);
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
