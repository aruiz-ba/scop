#Makefile for scop

CC = gcc -g
CFLAGS = -Wall -Wextra -Werror -lm
GLFLAGS = -lGL -lglut -lGLEW
LIBFT = Libft/libft.a
OBJFILES = main.o window.o loadShader.o transformation.o draw.o load_textures.o events.o parser.o
TARGET = scop

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(GLFLAGS) $(LIBFT)
test:
	$(CC) -g main.c window.c loadShader.c transformation.c -lGL -lglut -lGLEW -o $(OBJ)
	gdb $(OBJ)
exec:
	./$(OBJ)
clean:
	rm -f $(OBJFILES) $(TARGET)
