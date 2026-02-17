#pragma once
#include "RenderTypes.h"

#include <vector>
#include <glm/glm.hpp>

class Renderer;

class RenderPipeline {
public:
    void init(Renderer& renderer);

    MeshHandle createMesh(const MeshData& data);
    void updateMesh(MeshHandle handle, const MeshData& data);
    void destroyMesh(MeshHandle handle);

    void beginScene(const glm::mat4& viewProj);
    void submit(MeshHandle handle, const glm::mat4& modelMatrix);
    void endScene(Renderer& renderer);
    
private:
    Renderer* renderer = nullptr;

    struct RenderCommand {
        MeshHandle mesh;
        glm::mat4 modelMatrix;
    };

    std::vector<RenderCommand> commandQueue;
    glm::mat4 viewProjection;
};