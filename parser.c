#include<stdio.h>
#include "fcntl.h"
#include "./Libft/libft.h"

void	print(float obj[42][3], int faces[6][4], float output[200][3])
{
	int i;
	int b;
	int f;
/*	a b c d
	
	abc
	bcd
*/
	i = 0;	
	b = 0;	
	f = 0;	
	//while (faces[i])
	while (f < 6)
	{
		if (faces[f][3] == -1)
		{
			while (b < 3)
			{
				output[i][b] = obj[faces[f][0]-1][b];	//a
				output[i + 1][b] = obj[faces[f][1]-1][b]; //b
				output[i + 2][b] = obj[faces[f][2]-1][b]; //c
				printf("%f %f %f\n", output[i][b], output[i + 1][b],output[i + 2][b]);
				//printf("faceval: %i %i %i\n", faces[f][0] - 1, faces[f][1] - 1, faces[f][2] -1);
				printf("faceval: %i %i %i\n", faces[f][0] - 1, faces[f][1] - 1, faces[f][2] -1);
				printf("bval: %i\n", b);
				b++;
			}
			i +=3;
		}
		else
		{
			while (b < 3)
			{
				output[i][b] = obj[faces[f][0]-1][b];	//a
				output[i + 1][b] = obj[faces[f][1]-1][b]; //b
				output[i + 2][b] = obj[faces[f][2]-1][b]; //c
		
				output[i + 3][b] = obj[faces[f][1]-1][b]; //b
				output[i + 4][b] = obj[faces[f][2]-1][b]; //c
				output[i + 5][b] = obj[faces[f][3]-1][b]; //d
				printf("%f %f %f\n", output[i][b], output[i + 1][b],output[i + 2][b]);
				printf("faceval: %i %i %i --> %i %i %i\n", faces[f][0] - 1, faces[f][1] - 1, faces[f][2] -1, faces[f][1] - 1, faces[f][2] - 1, faces[f][3] -1);
				printf("bval: %i\n", b);
				printf("FVAL: %i\n\n", f);
				b++;
			}
			i += 6;
		}
		b = 0;
		//while (i < 2)
		//{

			/*
			while(b < 3)
			{
				if (faces[f][3] == -1)
				{
					output[i][b] = obj[faces[f][0]-1][b];	//a
					output[i + 1][b] = obj[faces[f][1]-1][b]; //b
					output[i + 2][b] = obj[faces[f][2]-1][b]; //c

					printf("%f %f %f\n", output[i][b], output[i + 1][b],output[i + 2][b]);
					printf("faceval: %i %i %i\n", faces[f][0] - 1, faces[f][1] - 1, faces[f][2] -1);
					printf("bval: %i\n", b);
					printf("QUE COJONES PASA AQUI: %f\n", obj[0][3]);

					i += 3;
				}
				else
				{
					output[i][b] = obj[faces[f][0]-1][b];	//a
					output[i + 1][b] = obj[faces[f][1]-1][b]; //b
					output[i + 2][b] = obj[faces[f][2]-1][b]; //c
					printf("%f %f %f\n", output[i][b], output[i + 1][b],output[i + 2][b]);
					printf("faceval: %i %i %i\n", faces[f][0] - 1, faces[f][1] - 1, faces[f][2] -1);
					printf("bval: %i\n", b);

					output[i + 3][b] = obj[faces[f][1]-1][b]; //b
					output[i + 4][b] = obj[faces[f][2]-1][b]; //c
					output[i + 5][b] = obj[faces[f][3]-1][b]; //d

					i += 6;
				}
				b++;
			}
			b = 0;
		//}*/
		f++;
	}
}

//int parse (int argc, char **args)
//{
//	int	i;
//	int	v;
//	char	*str;
//	char	*out;
//	char	**split;
//	float	**obj;
//
//	int fd = open(args[1], O_RDONLY);
//	v = 0;
//
//	if (fd == -1)
//	{
//		printf("Image could not be opened\n");
//		exit(-1);
//	}
//	i = get_next_line(fd, &str);
//	//poner esto en un loop que loopee hasta el final del archivo
//	while(i != 0)
//	{
//		while((out = ft_strstr(str, "v")) == NULL && i != 0) 
//		{
//			i = get_next_line(fd, &str);
//		}
//		v++;
//		i = get_next_line(fd, &str);
//	}
//	if (!(obj = malloc(sizeof(float *) * v)))
//		return (0);
//	int e = -1;
//	while (++e < v)
//	{
//		if (!(obj[e] = malloc(sizeof(float) * 3)))
//			return (0);
//	}
//
//	fd = open(args[1], O_RDONLY);
//	v = 0;
//
//	if (fd == -1)
//	{
//		printf("Image could not be opened\n");
//		exit(-1);
//	}
//	i = get_next_line(fd, &str);
//	//poner esto en un loop que loopee hasta el final del archivo
//	while(i != 0)
//	{
//		while((out = ft_strstr(str, "v ")) == NULL && i != 0) 
//		{
//			i = get_next_line(fd, &str);
//		}
//		if (i != 0)
//		{
//			split = ft_strsplit(out, ' ');
//			obj[v][0] = atof(split[1]); //are we allowed to use atof????
//			obj[v][1] = atof(split[2]);
//			obj[v][2] = atof(split[3]);
//
//			//printf("test:%s\n", split[2]);
//		}
//		v++;
//		i = get_next_line(fd, &str);
//	}
//	printf("test:%f\n", obj[0][0]);
//}

