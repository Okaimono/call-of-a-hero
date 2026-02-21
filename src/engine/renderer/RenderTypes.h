#pragma once
#include "OpenGL/VAO.h"
#include "OpenGL/EBO.h"

#include <cstdint>
#include <cstddef>
#include <vector>

#include <glad/glad.h>
#include <glm/glm.hpp>


/*
This right here is truly where I understood the power of why C++
is not just C with classes, but it provides incredible abstraction
with the power of C.

Not just random OOP object design, but abstraction that enables deep
manipulation and usability to scale architecture and enable DOP
design to truly shine.

It simply helps enable DOP to shine, and providing humans to make DOP 
extremely effective.

This was by far the hardest thing to come to a deep understanding
of in my journey

- Understanding why namespaces, templates, everything works so well.
We can powerfully define a namespace here to define what MeshData might mean, what 
MeshHandle, or ShaderID, or TextureID can indicate using abstraction.
This becomes insanely powerful, because now game can configure the engine.
From this, we can create extremely powerful DOP inside, making it safe,
manipulatable, and cleanly structured.

Now our code provides necessary abstrarction, not uselessly abstract code,
but abstraction that provides insane long term scalability,
which is what true OOP is.
*/

using MeshHandle = uint32_t;
using ShaderID = uint32_t;
using TextureID = uint32_t;

struct Vertex {
    glm::vec3 position;
    glm::vec2 texCoord;
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