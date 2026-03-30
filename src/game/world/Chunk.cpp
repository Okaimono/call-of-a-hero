#include "Chunk.h"

Chunk::Chunk() {
    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 256; y++) {
            for (int z = 0; z < 16; z++) {
                blocks[x][y][z] = BlockID::AIR;
            }
        }
    }

    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 4; y++) {
            for (int z = 0; z < 16; z++) {
                blocks[x][y][z] = BlockID::GRASS;
            }
        }
    }
}