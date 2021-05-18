#Makefile for scop

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -lm
GLFLAGS = -lGL -lglut -lGLEW
OBJFILES = main.o window.o loadShader.o transformation.o draw.o
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
