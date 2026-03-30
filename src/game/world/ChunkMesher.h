#pragma once
#include "engine/renderer/RenderTypes.h"
#include "Chunk.h"

struct ChunkNeighbors {
    Chunk* north = nullptr;
    Chunk* south = nullptr;
    Chunk* east  = nullptr;
    Chunk* west  = nullptr;
};

class ChunkMesher {
public:
    static void mesh(Chunk& chunk, MeshData& mesh, ChunkNeighbors neighbors);

private:
    static bool isSolid(Face face, Chunk& chunk, const glm::ivec3& position);
    static bool isBorder(Face face, Chunk& chunk, const ChunkNeighbors& neighbors, const glm::ivec3& position);
    static void addFace(BlockID block, Face face, MeshData& mesh, const glm::vec3& position);
};