#include "FragmentShader.h"

Fragment::Fragment() : err("ERROR::SHADER_COMPILATION_ERROR of type: Fragment\n") {}
Fragment::Fragment(const char* file, const CreateShaderID createShader) : err("ERROR::SHADER_COMPILATION_ERROR of type: Fragment\n")
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
	fragment = createShader.genrateFragmentShader();
	const char* vCode(code.c_str());
	glShaderSource(fragment, 1, &vCode, NULL);
	glCompileShader(fragment);
	checkCompileErrors(fragment, this);
}

Fragment::~Fragment(){}

const unsigned int& Fragment::getFragment() const {
	return fragment;
}
const std::string&  Fragment::getErr() const {
	return err;
}
const std::string&  Fragment::getCode() const {
	return code;
}