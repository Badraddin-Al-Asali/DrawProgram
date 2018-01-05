#pragma once
#include "OpenGLHeader.h"
class CreateShaderID {
public:
	CreateShaderID();
	~CreateShaderID();
	const unsigned int&& genrateVertexShader() const;
	const unsigned int&& genrateFragmentShader() const;
};