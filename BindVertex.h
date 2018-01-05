#pragma once
#include "OpenGLHeader.h"

class BindVertex {
public:
	BindVertex(const float* vertices, const unsigned int& size, const unsigned int& bytes);
	~BindVertex();
	const unsigned int& getVAO() const;
	const unsigned int& getVBO() const;
private:
	unsigned int VAO, VBO;
	BindVertex();
};