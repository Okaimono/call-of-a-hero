#pragma once
#include "engine/renderer/RenderTypes.h"
#include "Chunk.h"

class ChunkMesher {
public:
    static void mesh(Chunk& chunk, MeshData& mesh);

private:
    static bool isSolid(Face face, Chunk& chunk, const glm::ivec3& position);
    static void addFace(BlockID block, Face face, MeshData& mesh, const glm::vec3& position);
};