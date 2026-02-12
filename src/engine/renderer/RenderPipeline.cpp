#include "RenderPipeline.h"

#include "Renderer.h"
#include "Mesh.h"

void RenderPipeline::beginScene(const glm::mat4& viewProj) {
    viewProjection = viewProj;
}

void RenderPipeline::submit(const Mesh& mesh, const glm::mat4& modelMatrix) {
    glm::mat4 mvp = viewProjection * modelMatrix;
    commandQueue.push_back({&mesh, mvp});
}

void RenderPipeline::endScene(Renderer& renderer) {
    for (auto& cmd : commandQueue) {
        renderer.draw(*cmd.mesh, cmd.mvp);
    }
    commandQueue.clear();
}