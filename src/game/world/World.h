#pragma once
#include "Chunk.h"
#include <unordered_map>
#include <memory>

struct ChunkCoord {
    int x;
    int z;

    bool operator==(const ChunkCoord& other) const {
        return x == other.x && z == other.z;
    }
    ChunkCoord operator+(const ChunkCoord& other) const {
        return {x + other.x, z + other.z};
    }
};

struct ChunkCoordHash {
    size_t operator()(const ChunkCoord& c) const {
        return std::hash<int>()(c.x) ^ (std::hash<int>()(c.z) * 2654435761ULL);
    }
};

class World {
public:
    World();
    std::unordered_map<ChunkCoord, std::unique_ptr<Chunk>, ChunkCoordHash> chunks;

private:
};