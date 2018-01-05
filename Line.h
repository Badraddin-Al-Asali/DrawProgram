#pragma once
#include "Pixels.h"
class Line
{
public:
	Line();
	Line(const int& startX, const int& startY, const int& stopX, const int& stopY);
	~Line();

	void render(Pixels* pictureBox);
	void unRender(Pixels* pictureBox);
	void editVector_Start(const int& x, const int& y);
	void editVector_End(const int& x, const int& y);

	bool onVector_Start(const int& x, const int& y);
	bool onVector_End(const int& x, const int& y);
private:
	int startX, startY, stopX, stopY;
};