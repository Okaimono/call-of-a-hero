#pragma once

#include <glad/glad.h>

class VBO {
public:
    VBO();
    ~VBO();

    void Bind();
    void Unbind();

    void Upload(const void* data, GLsizeiptr size);

private:
    GLuint ID;
};