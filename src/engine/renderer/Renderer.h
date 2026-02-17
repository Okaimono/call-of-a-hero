#pragma once
#include "RenderTypes.h"

#include <unordered_map>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Renderer {
public:
    Renderer();
    //~Renderer();

    MeshHandle createMesh(const MeshData& data);
    void updateMesh(MeshHandle handle, const MeshData& data);
    void destroyMesh(MeshHandle handle);

    void clear();
    void draw(MeshHandle handle, const glm::mat4& mvp);

private:
    void uploadMesh(GPUMesh& gpu, const MeshData& data);

    std::unordered_map<MeshHandle, GPUMesh> meshes;
    MeshHandle nextHandle = 1;

    unsigned int shaderProgram;
    int mvpLocation;
};