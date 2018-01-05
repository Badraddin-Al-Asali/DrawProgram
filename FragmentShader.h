#pragma once
#include <fstream>
#include <sstream>
#include "Compile.h"
#include "CreateShaderID.h"
#include <iostream>
class Fragment : public Compile<Fragment>
{
public:
	Fragment(const char* file, const CreateShaderID createShader);
	~Fragment();

	const unsigned int& getFragment() const;
	const std::string& getErr() const;
	const std::string& getCode() const;
private:
	Fragment();

	unsigned int fragment;
	std::string err;
	std::string code;
};