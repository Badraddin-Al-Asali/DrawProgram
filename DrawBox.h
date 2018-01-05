#pragma once
class DrawBox
{
public:
	DrawBox();
	~DrawBox();

	const float* getBoxCoor() const;
	const int& getBoxSize() const;
	const int& getBoxByte() const;

private:
	const float Box[36] = {
		//tringle 1
		-1.0f, 1.0f, 0.0f,		0.0f, 1.0f,
		 1.0f, 1.0f, 0.0f,		1.0f, 1.0f,
		 1.0f, -1.0f, 0.0f,		1.0f, 0.0f,
		 //tringle 2
		 -1.0f, -1.0f, 0.0f,	0.0f, 0.0f,
		 -1.0f, 1.0f, 0.0f,		0.0f, 1.0f,
		 1.0f, -1.0f, 0.0f,		1.0f, 0.0f,
	};
};