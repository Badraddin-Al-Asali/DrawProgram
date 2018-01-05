#include "DrawBox.h"
DrawBox::DrawBox()
{
}

DrawBox::~DrawBox()
{
}

const float* DrawBox::getBoxCoor() const {
	return Box;
}
const int& DrawBox::getBoxSize() const {
	return sizeof(Box);
}
const int& DrawBox::getBoxByte() const {
	return 5;
}