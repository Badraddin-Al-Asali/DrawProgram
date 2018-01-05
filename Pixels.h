#pragma once
#include <iostream>
#include <vector>
#include "OpenGLHeader.h"
class Pixels
{
public:
	Pixels();
	~Pixels();
	void setPixelColour(const int& x, const int& y, const int& colour);
	
	unsigned char* getPixels();
	unsigned int& getTexture();
	GLuint getFrameBuffer();
private:
	unsigned int texture;
	GLuint frameBuffer;
	std::vector<unsigned char> pixels;
};