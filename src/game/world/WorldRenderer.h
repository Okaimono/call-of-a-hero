#pragma once
#include "engine/renderer/RenderPipeline.h"
#include "ChunkMesher.h"

#include <glm/gtc/matrix_transform.hpp>

class WorldRenderer {
public:
    WorldRenderer();
    
    void init(RenderPipeline& renderPipeline);
    void render(RenderPipeline& renderPipeline);

private:
    MeshHandle handle;
    Chunk chunk;
};