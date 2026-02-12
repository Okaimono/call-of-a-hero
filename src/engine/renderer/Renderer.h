#pragma once
#include "Mesh.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Renderer {
public:
    Renderer();
    ~Renderer();

    void clear();
    void draw(const Mesh& mesh, const glm::mat4& matrix);

private:
    unsigned int shaderProgram;
    int mvpLocation;
};