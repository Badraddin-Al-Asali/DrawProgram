#include "VertexShader.h"

Vertix::Vertix() : err("ERROR::SHADER_COMPILATION_ERROR of type: Vertix\n") {}
Vertix::Vertix(const char* file, const CreateShaderID createShader) : err("ERROR::SHADER_COMPILATION_ERROR of type: Vertix\n")
{
	std::ifstream vShaderFile;
	std::stringstream vShaderStream;
	//open File
	vShaderFile.open(file);
	// read file's buffer contents into streams
	vShaderStream << vShaderFile.rdbuf();
	// close file handlers
	vShaderFile.close();
	// convert stream into string
	code = vShaderStream.str();
	vertex = createShader.genrateVertexShader();
	const char* vCode(code.c_str());
	glShaderSource(vertex, 1, &vCode, NULL);
	glCompileShader(vertex);
	checkCompileErrors(vertex, this);
}

Vertix::~Vertix(){}

const unsigned int& Vertix::getVertex() const {
	return vertex;
}
const std::string&  Vertix::getErr() const {
	return err;
}
const std::string&  Vertix::getCode() const {
	return code;
}