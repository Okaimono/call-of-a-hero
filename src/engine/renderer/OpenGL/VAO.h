#pragma once
#include "VBO.h"

#include<glad/glad.h>

class VAO {
public:
    VAO();
    ~VAO();
    void LinkAttrib(VBO& VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);

    void Bind();
    void Unbind();

private:
    GLuint ID;

};