#pragma once
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

#include "Compile.h"
#include "FragmentShader.h"
#include "VertexShader.h"
class CreateShaderProgram : public Compile<CreateShaderProgram>
{
public:
	// constructor generates the shader on the fly
	CreateShaderProgram(const Fragment& fragement, const Vertix& vertix);
	// activate the shader
	void use() const;
	// utility uniform functions
	void setBool(const std::string &name, const bool& value) const;
	void setInt(const std::string &name, const int& value) const;
	void setFloat(const std::string &name, const float& value) const;
	void setFloat3(const std::string &name, float* value) const;
	void setFloat4(const std::string &name, float* value) const;
	void setMat2(const std::string &name, const glm::mat2 &mat) const;
	void setMat3(const std::string &name, const glm::mat3 &mat) const;
	void setMat4(const std::string &name, const glm::mat4 &mat) const;
	void setVec2(const std::string &name, const glm::vec2 &vec) const;
	void setVec3(const std::string &name, const glm::vec3 &vec) const;
	void setVec4(const std::string &name, const glm::vec4 &vec) const;

	const std::string& getErr() const;
private:
	unsigned int ID;
	std::string err;
};