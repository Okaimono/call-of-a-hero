#pragma once
#include "RenderTypes.h"

#include <vector>
#include <glm/glm.hpp>

class Renderer;
class ResourceManager;
class Scene;

class RenderPipeline {
public:
    void init(Renderer& renderer, ResourceManager& resourceManager, Scene& scene);

    MeshHandle createMesh(const MeshData& data);
    
    void updateMesh(MeshHandle handle, const MeshData& data);
    void destroyMesh(MeshHandle handle);

    void beginScene(const glm::mat4& viewProj);
    void submit(ShaderID shader, TextureID texture, MeshHandle mesh, const glm::mat4& modelMatrix);
    void endScene(Renderer& renderer);

private:
    Renderer* renderer = nullptr;
    ResourceManager* resourceManager = nullptr;
    Scene* scene = nullptr;

    struct RenderCommand {
        ShaderID shader;
        TextureID texture;
        MeshHandle mesh;
        glm::mat4 modelMatrix;
    };

    std::vector<RenderCommand> commandQueue;
    glm::mat4 viewProjection;
};