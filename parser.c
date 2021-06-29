#include "scop.h"
#include <stdio.h>
#include "fcntl.h"
#include "./Libft/libft.h"

int	malloc_triangle_vertices(t_obj *obj)
{
	int num_vertices;
	int e;
	
	num_vertices = obj->t_n * 3;
	e = -1;

	if (!(obj->t_v = malloc(sizeof(float *) * num_vertices)))
		return (-1);
	while (++e < num_vertices)
	{
		if (!(obj->t_v[e] = malloc(sizeof(float) * 3)))
			return (-1);
	}
	return(0);
}

void	print(t_obj *obj) {
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
	malloc_triangle_vertices(obj);
	while (f < obj->f_size)
	{
		if (obj->f[f][3] == -1)
		{
			while (b < 3)
			{
				obj->t_v[i][b] = obj->v[obj->f[f][0]-1][b];	//a
				obj->t_v[i + 1][b] = obj->v[obj->f[f][1]-1][b]; //b
				obj->t_v[i + 2][b] = obj->v[obj->f[f][2]-1][b]; //c
				printf("%f %f %f\n", obj->t_v[i][b], obj->t_v[i + 1][b],obj->t_v[i + 2][b]);
				//printf("faceval: %i %i %i\n", obj->f[f][0] - 1, obj->f[f][1] - 1, obj->f[f][2] -1);
				printf("faceval: %i %i %i\n", obj->f[f][0] - 1, obj->f[f][1] - 1, obj->f[f][2] -1);
				printf("bval: %i\n", b);
				b++;
			}
			i +=3;
		}
		else
		{
			while (b < 3)
			{
				obj->t_v[i][b] = obj->v[obj->f[f][0]-1][b];	//a
				obj->t_v[i + 1][b] = obj->v[obj->f[f][1]-1][b]; //b
				obj->t_v[i + 2][b] = obj->v[obj->f[f][2]-1][b]; //c
		
				obj->t_v[i + 3][b] = obj->v[obj->f[f][0]-1][b]; //a
				obj->t_v[i + 4][b] = obj->v[obj->f[f][2]-1][b]; //c
				obj->t_v[i + 5][b] = obj->v[obj->f[f][3]-1][b]; //d
				printf("%f %f %f\n", obj->t_v[i][b], obj->t_v[i + 1][b],obj->t_v[i + 2][b]);
				b++;
			}
			i += 6;
		}
		b = 0;
		f++;
	}
}

int parse_obj_f(char *args, t_obj *obj)
{
	int	i;
	int	f;
	char	*str;
	char	*out;
	char	**split;

	int fd = open(args, O_RDONLY);
	f = 0;
	obj->t_n = 0;

	if (fd == -1)
	{
		printf("Obj file could not be opened\n");
		exit(-1);
	}
	i = get_next_line(fd, &str);
	//poner esto en un loop que loopee hasta el final del archivo
	while(i != 0)
	{
		while((out = ft_strstr(str, "f ")) == NULL && i != 0) 
		{
			i = get_next_line(fd, &str);
		}
		f++;
		i = get_next_line(fd, &str);
	}
	if (!(obj->f = malloc(sizeof(float *) * f)))
		return (0);
	int e = -1;
	while (++e < f)
	{
		if (!(obj->f[e] = malloc(sizeof(float) * 4)))
			return (0);
	}
	obj->f_size = f; 

	fd = open(args, O_RDONLY);
	f = 0;

	if (fd == -1)
	{
		printf("Obj file could not be opened\n");
		exit(-1);
	}
	i = get_next_line(fd, &str);
	//poner esto en un loop que loopee hasta el final del archivo
	while(i != 0)
	{
		while((out = ft_strstr(str, "f ")) == NULL && i != 0) 
		{
			i = get_next_line(fd, &str);
		}
		if (i != 0)
		{
			split = ft_strsplit(out, ' ');
			obj->f[f][0] = ft_atoi(split[1]);
			obj->f[f][1] = ft_atoi(split[2]);
			obj->f[f][2] = ft_atoi(split[3]);
			if (split[4])
			{
				obj->f[f][3] = ft_atoi(split[4]);
				obj->t_n += 2;
			}
			else
			{
				obj->f[f][3] = -1; //if its a triangle
				obj->t_n++;
			}
		}
		f++;
		i = get_next_line(fd, &str);
	}
	return(0);
}

int parse_obj_v (char *args, t_obj *obj)
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
		while((out = ft_strstr(str, "v ")) == NULL && i != 0) 
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
	obj->v_size = v - 1;

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

