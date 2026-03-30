#include "WorldRenderer.h"
#include "game/assets.h"

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

WorldRenderer::WorldRenderer() {}

void WorldRenderer::init(RenderPipeline& renderPipeline, World& world) {
    auto getChunk = [&](ChunkCoord c) -> Chunk* {
        auto it = world.chunks.find(c);
        return it != world.chunks.end() ? it->second.get() : nullptr;
    };

    for (auto& entry : world.chunks) {
        ChunkCoord coord = entry.first;
        ChunkNeighbors neighbors = {
            getChunk(coord + ChunkCoord{0,  1}),
            getChunk(coord + ChunkCoord{0, -1}),
            getChunk(coord + ChunkCoord{1,  0}),
            getChunk(coord + ChunkCoord{-1, 0}),
        };

        MeshData data;
        Chunk& chunk = *entry.second;
        ChunkMesher::mesh(chunk, data, neighbors);

        MeshHandle handle = renderPipeline.createMesh(data);
        entries.push_back({handle, coord});
    }
}

void WorldRenderer::render(RenderPipeline& renderPipeline) {
    for (auto& entry : entries) {
        glm::mat4 model = glm::translate(glm::mat4(1.0f), 
            glm::vec3(entry.coord.x * 16.0f, 0.0f, entry.coord.z * 16.0f));
        renderPipeline.submit(Assets::Shaders::DEFAULT, Assets::Textures::GAME_ATLAS, entry.handle, model);
    }
}