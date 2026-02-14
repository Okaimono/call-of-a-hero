#include "Chunk.h"

void Chunk::init() {
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 256; y++) {
            for (int z = 0; z < 16; z++) {
                blocks[x][y][z] = BlockID::GRASS;
            }
        }
    }
}

Renderable Chunk::getRenderable() {
    return {mesh, position};
}