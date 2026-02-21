#include "WorldRenderer.h"
#include "game/assets.h"

WorldRenderer::WorldRenderer() {}

void WorldRenderer::init(RenderPipeline& renderPipeline) 
{
    chunk.init();

    MeshData meshData;
    ChunkMesher::mesh(chunk, meshData);
    handle = renderPipeline.createMesh(meshData);
}

void WorldRenderer::render(RenderPipeline& renderPipeline) {
    renderPipeline.submit(Assets::Shaders::DEFAULT, Assets::Textures::GAME_ATLAS, handle, glm::mat4(1.0f));
}