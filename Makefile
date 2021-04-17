#Makefile for scop

CC = gcc
CFLAGS = -Wall -Wextra -Werror
OBJ = scop

all:
	$(CC) main.c window.c loadShader.c -lGL -lglut -lGLEW -o $(OBJ)
test:
	$(CC) -g main.c window.c loadShader.c -lGL -lglut -lGLEW -o $(OBJ)
	gdb $(OBJ)
lol:
	$(CC) main.c window.c loadShader.c -lGL -lglut -lGLEW -o $(OBJ)
	./$(OBJ)
exec:
	./$(OBJ)
clean:
	rm $(OBJ)
