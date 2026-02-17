#include "WorldRenderer.h"

WorldRenderer::WorldRenderer() {}

void WorldRenderer::init(RenderPipeline& renderPipeline) 
{
    MeshData meshData;
    meshData.vertices = {
        { glm::vec3(-0.5f, -0.5f, 0.0f) },
        { glm::vec3( 0.5f, -0.5f, 0.0f) },
        { glm::vec3( 0.0f,  0.5f, 0.0f) }
    };

    meshData.indices = { 0, 1, 2 };

    chunk = renderPipeline.createMesh(meshData);
}

void WorldRenderer::render(RenderPipeline& renderPipeline) {
    renderPipeline.submit(chunk, glm::mat4(1.0f));
}