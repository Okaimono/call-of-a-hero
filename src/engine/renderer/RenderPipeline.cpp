#include "RenderPipeline.h"

#include "Renderer.h"

void RenderPipeline::init(Renderer& r) {
    renderer = &r;
}

MeshHandle RenderPipeline::createMesh(const MeshData& data) {
    return renderer->createMesh(data);
}

void RenderPipeline::beginScene(const glm::mat4& viewProj) {
    viewProjection = viewProj;
}

void RenderPipeline::submit(MeshHandle mesh, const glm::mat4& modelMatrix) {
    glm::mat4 mvp = viewProjection * modelMatrix;
    commandQueue.push_back({mesh, mvp});
}

void RenderPipeline::endScene(Renderer& renderer) {
    for (auto& cmd : commandQueue) {
        renderer.draw(cmd.mesh, cmd.modelMatrix);
    }
    commandQueue.clear();
}