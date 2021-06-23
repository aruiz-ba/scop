#include "scop.h"

#include<stdio.h>
#include "fcntl.h"
#include "./Libft/libft.h"

void	print(float obj[42][3], int faces[47][4], float output[278][3]) {
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
	while (f < 41)
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
		
				output[i + 3][b] = obj[faces[f][0]-1][b]; //a
				output[i + 4][b] = obj[faces[f][2]-1][b]; //c
				output[i + 5][b] = obj[faces[f][3]-1][b]; //d
				printf("%f %f %f\n", output[i][b], output[i + 1][b],output[i + 2][b]);
				printf("faceval: %i %i %i --> %i %i %i\n", faces[f][0] - 1, faces[f][1] - 1, faces[f][2] -1, faces[f][1] - 1, faces[f][2] - 1, faces[f][3] -1);
				printf("bval: %i\n", b);
				printf("FVAL: %i\n\n", f);
				b++;
			}
			i += 6;
			printf("Complete triangle 1: P1: %f %f %f\n", output[0][0], output[0][1],output[0][2]);
			printf("Complete triangle 1: P2: %f %f %f\n", output[1][0], output[1][1],output[1][2]);
			printf("Complete triangle 1: P3: %f %f %f\n\n", output[2][0], output[2][1],output[2][2]);

			printf("Complete triangle 2: P1: %f %f %f\n", output[3][0], output[3][1],output[3][2]);
			printf("Complete triangle 2: P2: %f %f %f\n", output[4][0], output[4][1],output[4][2]);
			printf("Complete triangle 2: P3: %f %f %f\n", output[5][0], output[5][1],output[5][2]);
			printf("loops\n");
		}
		b = 0;
		f++;
	}
}

int parse_obj (char *args, t_obj *obj)
{
	int	i;
	int	v;
	char	*str;
	char	*out;
	char	**split;

	int fd = open(args, O_RDONLY);
	v = 0;

	if (fd == -1)
	{
		printf("Obj file could not be opened\n");
		exit(-1);
	}
	i = get_next_line(fd, &str);
	//poner esto en un loop que loopee hasta el final del archivo
	while(i != 0)
	{
		while((out = ft_strstr(str, "v")) == NULL && i != 0) 
		{
			i = get_next_line(fd, &str);
		}
		v++;
		i = get_next_line(fd, &str);
	}
	if (!(obj->v = malloc(sizeof(float *) * v)))
		return (0);
	int e = -1;
	while (++e < v)
	{
		if (!(obj->v[e] = malloc(sizeof(float) * 3)))
			return (0);
	}
	obj->v_size = v;

	fd = open(args, O_RDONLY);
	v = 0;

	if (fd == -1)
	{
		printf("Obj file could not be opened\n");
		exit(-1);
	}
	i = get_next_line(fd, &str);
	//poner esto en un loop que loopee hasta el final del archivo
	while(i != 0)
	{
		while((out = ft_strstr(str, "v ")) == NULL && i != 0) 
		{
			i = get_next_line(fd, &str);
		}
		if (i != 0)
		{
			split = ft_strsplit(out, ' ');
			obj->v[v][0] = atof(split[1]); //are we allowed to use atof????
			obj->v[v][1] = atof(split[2]);
			obj->v[v][2] = atof(split[3]);
		}
		v++;
		i = get_next_line(fd, &str);
	}
	return(0);
}

int parse_texture (char *args)
{
	int	i;
	int	v;
	char	*str;
	char	*out;
	char	**split;
	float	**obj;

	int fd = open(args, O_RDONLY);
	v = 0;

	if (fd == -1)
	{
		printf("Image could not be opened\n");
		exit(-1);
	}
	i = get_next_line(fd, &str);
	//poner esto en un loop que loopee hasta el final del archivo
	while(i != 0)
	{
		while((out = ft_strstr(str, "v")) == NULL && i != 0) 
		{
			i = get_next_line(fd, &str);
		}
		v++;
		i = get_next_line(fd, &str);
	}
	if (!(obj = malloc(sizeof(float *) * v)))
		return (0);
	int e = -1;
	while (++e < v)
	{
		if (!(obj[e] = malloc(sizeof(float) * 3)))
			return (0);
	}

	fd = open(args, O_RDONLY);
	v = 0;

	if (fd == -1)
	{
		printf("Image could not be opened\n");
		exit(-1);
	}
	i = get_next_line(fd, &str);
	//poner esto en un loop que loopee hasta el final del archivo
	while(i != 0)
	{
		while((out = ft_strstr(str, "v ")) == NULL && i != 0) 
		{
			i = get_next_line(fd, &str);
		}
		if (i != 0)
		{
			split = ft_strsplit(out, ' ');
			obj[v][0] = atof(split[1]); //are we allowed to use atof????
			obj[v][1] = atof(split[2]);
			obj[v][2] = atof(split[3]);

			//printf("test:%s\n", split[2]);
		}
		v++;
		i = get_next_line(fd, &str);
	}
	printf("test:%f\n", obj[0][0]);
	return(0);
}

