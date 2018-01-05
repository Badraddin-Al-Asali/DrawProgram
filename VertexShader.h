#pragma once
#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
#include "Compile.h"
#include "CreateShaderID.h"
class Vertix : public Compile<Vertix>
{
public:
	Vertix(const char* file, const CreateShaderID createShader);
	~Vertix();

	const unsigned int& getVertex() const;
	const std::string& getErr() const;
	const std::string& getCode() const;

private:
	Vertix();

	unsigned int vertex;
	std::string err;
	std::string code;
};