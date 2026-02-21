#pragma once
#include "BlockID.h"

#include <glm/glm.hpp>

enum class Face {
    TOP, BOTTOM, NORTH, SOUTH, EAST, WEST
};

class Chunk {
public:
    void init();
    BlockID getBlock(int x, int y, int z) const { return blocks[x][y][z]; }
private:
    glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
    BlockID blocks[16][256][16];
};