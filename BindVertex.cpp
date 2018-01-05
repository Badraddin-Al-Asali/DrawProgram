#include "BindVertex.h"

BindVertex::BindVertex(){}

BindVertex::BindVertex(const float* vertices, const unsigned int& size, const unsigned int& bytes){
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, bytes * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, bytes * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
}

BindVertex::~BindVertex() {
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
}

const unsigned int& BindVertex::getVAO() const {
	return VAO;
}
const unsigned int& BindVertex::getVBO() const {
	return VBO;
}