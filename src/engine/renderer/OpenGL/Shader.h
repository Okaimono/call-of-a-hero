#pragma once

#include <glad/glad.h>
#include <string> 
#include <fstream>
#include <sstream>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:
    Shader(const char* vertexFile, const char* fragmentFile);

    GLuint getID() { return ID; }

    void Activate();
    void Delete();

    void setMat4(const glm::mat4& matrix);

    void compileErrors(unsigned int shader, const char* type);

private:
    GLuint ID;
    GLuint location = -1;
    
};