#include "scop.h"
#include "fcntl.h"
#include <unistd.h>

GLuint loadBMP_custom(const char * imagepath)
{
	// Data read from the header of the BMP file
	unsigned char header[54]; // Each BMP file begins by a 54-bytes header
	unsigned int dataPos;     // Position in the file where the actual data begins
	unsigned int width, height;
	unsigned int imageSize;   // = width*height*3
	// Actual RGB data
	//unsigned char * data;

	int fd = open(imagepath, O_RDONLY);
	if (fd == -1)
	{
		printf("Error with fd number\n");
		return(-1);
	}
	if (read(fd, header, 54) != 54)
	{
		printf("Not a correct BMP file\n");
		return(-1);
	}
	if (header[0] != 'B' || header[1] != 'M')
	{
		printf("Not a correct BMP file");
		return(-1);
	}

	// Read ints from the byte array
	dataPos    = *(int*)&(header[0x0A]);
	imageSize  = *(int*)&(header[0x22]);
	width      = *(int*)&(header[0x12]);
	height     = *(int*)&(header[0x16]);

	if (imageSize==0)
		imageSize=width*height*3;
	if (dataPos==0)
		dataPos=54;
	unsigned char data[imageSize]; //this is the data buffer
	read(fd, data, imageSize);
	close(fd);


	//we create OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);

	// "Bind" the newly created texture : all future texture functions will modify this texture
	glBindTexture(GL_TEXTURE_2D, textureID);

	// Give the image to OpenGL
	glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);



	printf("dataPos %i\n", dataPos);
	printf("imageSize %i\n", imageSize);
	printf("width %i\n", width);
	printf("height %i\n", height);

	return(0);
}
