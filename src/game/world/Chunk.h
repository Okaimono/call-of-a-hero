#pragma once
#include "engine/renderer/Mesh.h"
#include "glm/glm.hpp"

enum class BlockID {
    AIR = 0, GRASS = 1
};

struct Renderable {
    Mesh& mesh;
    glm::vec3& position;
};

class Chunk {
public:
    void init();
    Renderable getRenderable();
private:
    Mesh mesh;
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    BlockID blocks[16][256][16];
};