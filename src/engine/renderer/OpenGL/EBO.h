#pragma once

#include <glad/glad.h>

class EBO {
public: 
    EBO();
    ~EBO();

    void Bind();
    void Unbind();

    void Upload(const void* data, GLsizeiptr size);
    
private:
    GLuint ID;
};