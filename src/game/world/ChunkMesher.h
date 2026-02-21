#pragma once
#include "engine/renderer/RenderTypes.h"
#include "Chunk.h"

class ChunkMesher {
public:
    static void mesh(Chunk& chunk, MeshData& mesh);
private:
    static void addFace(Face face, MeshData& mesh, glm::vec3 position);
};