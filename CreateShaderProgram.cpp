#include"CreateShaderProgram.h"
CreateShaderProgram::CreateShaderProgram(const Fragment& fragement, const Vertix& vertix) : err("ERROR::PROGRAM_LINKING_ERROR of type : PROGRAM\n")
{
	ID = glCreateProgram();
	glAttachShader(ID, vertix.getVertex());
	glAttachShader(ID, fragement.getFragment());
	glLinkProgram(ID);
	checkCompileErrors(ID, this);
	glDeleteShader(vertix.getVertex());
	glDeleteShader(fragement.getFragment());
}
// activate the shader
void CreateShaderProgram::use() const
{
	glUseProgram(ID);
}
// utility uniform functions
void CreateShaderProgram::setBool(const std::string &name, const bool& value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
}
void CreateShaderProgram::setInt(const std::string &name, const int& value) const
{
	glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}
void CreateShaderProgram::setFloat(const std::string &name, const float& value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}
void CreateShaderProgram::setFloat3(const std::string &name, float* value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), *value);
}
void CreateShaderProgram::setFloat4(const std::string &name, float* value) const
{
	glUniform1f(glGetUniformLocation(ID, name.c_str()), *value);
}
void CreateShaderProgram::setMat2(const std::string &name, const glm::mat2 &mat) const
{
	glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void CreateShaderProgram::setMat3(const std::string &name, const glm::mat3 &mat) const
{
	glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void CreateShaderProgram::setMat4(const std::string &name, const glm::mat4 &mat) const
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
}
void CreateShaderProgram::setVec2(const std::string &name, const glm::vec2 &vec) const
{
	glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &vec[0]);
}
void CreateShaderProgram::setVec3(const std::string &name, const glm::vec3 &vec) const
{
	glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &vec[0]);
}
void CreateShaderProgram::setVec4(const std::string &name, const glm::vec4 &vec) const
{
	glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &vec[0]);
}
const std::string& CreateShaderProgram::getErr() const {
	return err;
}