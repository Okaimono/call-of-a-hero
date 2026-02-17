#include "EBO.h"

EBO::EBO() {
    glGenBuffers(1, &ID);
}

EBO::~EBO() {
    glDeleteBuffers(1, &ID);
}

void EBO::Bind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Upload(const void* data, GLsizeiptr size)
{
	Bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
}
