#Makefile for scop

CC = gcc
CFLAGS = -Wall -Wextra -Werror
GLFLAGS = -lGL -lglut -lGLEW
OBJFILES = main.o window.o loadShader.o transformation.o
TARGET = scop

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(GLFLAGS)
test:
	$(CC) -g main.c window.c loadShader.c transformation.c -lGL -lglut -lGLEW -o $(OBJ)
	gdb $(OBJ)
exec:
	./$(OBJ)
clean:
	rm -f $(OBJFILES) $(TARGET)
