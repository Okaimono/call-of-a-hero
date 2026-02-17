#pragma once
#include "OpenGL/VAO.h"
#include "OpenGL/EBO.h"

#include <cstdint>
#include <cstddef>
#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>

using MeshHandle = uint32_t;

struct Vertex {
    glm::vec3 position;
};

struct MeshData {
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
};

struct GPUMesh {
    VAO vao;
    VBO vbo;
    EBO ebo;
    uint32_t indexCount;
};
