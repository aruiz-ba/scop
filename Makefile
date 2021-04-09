#Makefile for scop

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = scop

all:
	$(CC) -g main.c window.c -lGL -lglut -lGLEW -o $(OBJ)
lol:
	$(CC) -g main.c window.c -lGL -lglut -lGLEW -o $(OBJ)
	./$(OBJ)
exec:
	./$(OBJ)
clean:
	rm $(OBJ)
