#pragma once
#include "engine/renderer/RenderPipeline.h"

class WorldRenderer {
public:
    WorldRenderer();
    
    void init(RenderPipeline& renderPipeline);
    void render(RenderPipeline& renderPipeline);

private:
    MeshHandle chunk;
};