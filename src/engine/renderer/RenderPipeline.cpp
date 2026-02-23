#include "RenderPipeline.h"
#include "Renderer.h"
#include "ResourceManager.h"

void RenderPipeline::init(Renderer& r, ResourceManager& rm, Scene& s) {
    renderer = &r;
    resourceManager = &rm;
    scene = &s;
}

MeshHandle RenderPipeline::createMesh(const MeshData& data) {
    return renderer->createMesh(data);
}

void RenderPipeline::beginScene(const glm::mat4& viewProj) {
    renderer->clear();
    viewProjection = viewProj;
}

// Pre-multiply MVP here so the command queue stores final matrices,
// keeping the flush loop simple and batch-friendly.
void RenderPipeline::submit(ShaderID shader, TextureID texture, MeshHandle mesh, const glm::mat4& modelMatrix) {
    glm::mat4 mvp = viewProjection * modelMatrix;
    commandQueue.push_back({shader, texture, mesh, mvp});
}

void RenderPipeline::endScene(Renderer& renderer) {
    for (auto& cmd : commandQueue) {
        Shader& shader = resourceManager->getShader(cmd.shader);
        Texture& texture = resourceManager->getTexture(cmd.texture);
        renderer.draw(shader, texture, cmd.mesh, cmd.modelMatrix);
    }
    commandQueue.clear();
}