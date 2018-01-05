#include "Pixels.h"
//800 x 600 = 480,000 x 3 = 1440000
//set colours to white 255
Pixels::Pixels(): pixels(1440000, 255){
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	// set the texture wrapping/filtering options (on the currently bound texture object)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, &pixels[0]);
	//glGenerateMipmap(GL_TEXTURE_2D);
}
Pixels::~Pixels(){}
unsigned char* Pixels::getPixels() {
	return &pixels[0];
}
unsigned int& Pixels::getTexture() {
	return texture;
}
void Pixels::setPixelColour(const int& x, const int& y, const int& colour) {
	//sets x and y in the array
	//2400 = 800(width) * 3(channels)
	pixels[(2400 * y) + (3 * x)] = (colour & 0xff0000) >> 16;
	pixels[(2400 * y) + (3 * x) + 1] = (colour & 0x00ff00) >> 8;
	pixels[(2400 * y) + (3 * x) + 2] = (colour & 0x0000ff);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 800, 600, 0, GL_RGB, GL_UNSIGNED_BYTE, &pixels[0]);
}