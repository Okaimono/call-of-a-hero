#include "VBO.h"

VBO::VBO() {
    glGenBuffers(1, &ID);
}

VBO::~VBO() {
    glDeleteBuffers(1, &ID);
}

void VBO::Bind() {
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO::Upload(const void* data, GLsizeiptr size)
{
	Bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
}
