#include "CreateShaderID.h"
CreateShaderID::CreateShaderID() {

}
CreateShaderID::~CreateShaderID() {

}
const unsigned int&& CreateShaderID::genrateVertexShader() const {
	return glCreateShader(GL_VERTEX_SHADER);
}
const unsigned int&& CreateShaderID::genrateFragmentShader() const {
	return glCreateShader(GL_FRAGMENT_SHADER);
}