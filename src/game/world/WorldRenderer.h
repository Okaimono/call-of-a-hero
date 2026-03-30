#pragma once
#include "engine/renderer/RenderPipeline.h"
#include "ChunkMesher.h"
#include "World.h"

#include <glm/gtc/matrix_transform.hpp>
#include <unordered_map>

class WorldRenderer {
public:
    WorldRenderer();
    
    void init(RenderPipeline& renderPipeline, World& world);
    void render(RenderPipeline& renderPipeline);

private:
    struct ChunkRenderEntry {
        MeshHandle handle;
        ChunkCoord coord;
    };

    std::vector<ChunkRenderEntry> entries;
};