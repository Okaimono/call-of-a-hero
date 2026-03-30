#include "World.h"

World::World() {
    for (int x = 0; x < 5; x++) {
        for (int z = 0; z < 5; z++) {
            ChunkCoord coord = {x, z};
            chunks.emplace(coord, std::make_unique<Chunk>());
        }
    }
}