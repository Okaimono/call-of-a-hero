#pragma once

#include <vector>
#include <glm/glm.hpp>

class Renderer;
class Mesh;

class RenderPipeline {
public:
    void beginScene(const glm::mat4& viewProj);
    void submit(const Mesh& mesh, const glm::mat4& modelMatrix);
    void endScene(Renderer& renderer);
    
private:
    struct RenderCommand {
        const Mesh* mesh;
        glm::mat4 mvp;
    };

    std::vector<RenderCommand> commandQueue;
    glm::mat4 viewProjection;
};