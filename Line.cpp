#include "Line.h"
Line::Line() {}
Line::Line(const int& startX, const int& startY, const int& stopX, const int& stopY): startX(startX), startY(startY), stopX(stopX), stopY(stopY){}

Line::~Line()
{
}

void Line::render(Pixels* pictureBox) {
	float dX(abs(stopX - startX));
	float dY(abs(stopY - startY));
	float err;
	int x = startX;
	int y = startY;
	int step_X(1);
	int step_Y(1);

	if (startX > stopX) {
		step_X = -1;
	}
	if (startY > stopY) {
		step_Y = -1;
	}
	if (dX > dY) {
		err = dX / 2.0;
		while (x != stopX) {
			pictureBox->setPixelColour(x, y, 0x000000);
			err = err - dY;
			if (err < 0.0) {
				y += step_Y;
				err += dX;
			}
			x += step_X;
		}
	}
	else {
		err = dY / 2.0;
		while (y != stopY) {
			pictureBox->setPixelColour(x, y, 0x000000);
			err = err - dX;
			if (err < 0.0) {
				x += step_X;
				err += dY;
			}
			y += step_Y;
		}
	}
	pictureBox->setPixelColour(x, y, 0x000000);
	float radius(10.0f);
	float pr = 1.125; // pr is the aspected pixel ratio which is almost equal to 2
	for (int i = -radius; i <= radius; ++i) // loop for horizontal movement
	{
		for (int j = -radius; j <= radius; ++j) // loop for vertical movement
		{
			float d = ((i*pr) / radius)*((i*pr) / radius) + (j / radius)*(j / radius); //multiplying the i variable with pr to equalize pixel-width with the height
			if (d > 0.95 && d < 1.08) // approximation
			{
				pictureBox->setPixelColour(startX + i, startY + j, 0xff0000);
				pictureBox->setPixelColour(stopX + i, stopY + j, 0x0000ff);
			}
		}
	}
}

void Line::unRender(Pixels* pictureBox) {
	float dX(abs(stopX - startX));
	float dY(abs(stopY - startY));
	float err;
	int x = startX;
	int y = startY;
	int step_X(1);
	int step_Y(1);

	if (startX > stopX) {
		step_X = -1;
	}
	if (startY > stopY) {
		step_Y = -1;
	}
	if (dX > dY) {
		err = dX / 2.0;
		while (x != stopX) {
			pictureBox->setPixelColour(x, y, 0xffffff);
			err -= dY;
			if (err < 0.0) {
				y += step_Y;
				err += dX;
			}
			x += step_X;
		}
	}
	else {
		err = dY / 2.0;
		while (y != stopY) {
			pictureBox->setPixelColour(x, y, 0xffffff);
			err -= dX;
			if (err < 0.0) {
				x += step_X;
				err += dY;
			}
			y += step_Y;
		}
	}
	pictureBox->setPixelColour(x, y, 0xffffff);
	float radius(10.0f);
	float pr = 1.125; // pr is the aspected pixel ratio which is almost equal to 2
	for (int i = -radius; i <= radius; ++i) // loop for horizontal movement
	{
		for (int j = -radius; j <= radius; ++j) // loop for vertical movement
		{
			float d = ((i*pr) / radius)*((i*pr) / radius) + (j / radius)*(j / radius); //multiplying the i variable with pr to equalize pixel-width with the height
			if (d > 0.95 && d < 1.08) // approximation
			{
				pictureBox->setPixelColour(startX + i, startY + j, 0xffffff);
				pictureBox->setPixelColour(stopX + i, stopY + j, 0xffffff);
			}
		}
	}
}


void Line::editVector_Start(const int& x, const int& y) {
	stopX = x;
	stopY = y;
}
void Line::editVector_End(const int& x, const int& y) {
	startX = x;
	startY = y;
}
bool Line::onVector_Start(const int& x, const int& y) {
	int diameter(20);
	return ((x < stopX + diameter && x > stopX - diameter) && (y < stopY + diameter && y > stopY - diameter));
}
bool Line::onVector_End(const int& x, const int& y) {
	int diameter(20);
	return ((x < startX + diameter && x > startX - diameter) && (y < startY + diameter && y > startY - diameter));
}