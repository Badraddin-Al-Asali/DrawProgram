#pragma once
#include <string>
#include <iostream>

#include "OpenGLHeader.h"

template<class T>
class Compile
{
public:
	Compile() {}
	~Compile() {}

	static void Compile::checkCompileErrors(unsigned int shader, T* type)
	{
		int success;
		char infoLog[1024];

		glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << type->getErr() << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
			system("pause");
		}
	}
};