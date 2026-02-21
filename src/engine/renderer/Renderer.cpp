#include "Renderer.h"

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

Renderer::Renderer() {
    
}

void Renderer::clear() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

MeshHandle Renderer::createMesh(const MeshData& data) {
    MeshHandle handle = nextHandle++;

    auto [it, inserted] = meshes.try_emplace(handle);
    GPUMesh& gpu = it->second;
    uploadMesh(gpu, data);

    return handle;
}

void Renderer::uploadMesh(GPUMesh& gpu, const MeshData& data) {
    gpu.vao.Bind();
    gpu.vbo.Bind();
    gpu.ebo.Bind();

    gpu.vbo.Upload(
        data.vertices.data(), 
        data.vertices.size() * sizeof(Vertex)
    );
    
    gpu.ebo.Upload(
        data.indices.data(),
        data.indices.size() * sizeof(GLuint)
    );

    gpu.vao.LinkAttrib(
        gpu.vbo, 
        0,
        3,
        GL_FLOAT,
        sizeof(Vertex),
        (void*)offsetof(Vertex, position)
    );

    gpu.vao.LinkAttrib(
        gpu.vbo,
        1, 2, GL_FLOAT,
        sizeof(Vertex),
        (void*)offsetof(Vertex, texCoord)
    );

    gpu.indexCount = static_cast<uint32_t>(data.indices.size());
}

void Renderer::draw(Shader& shader, Texture& texture, MeshHandle handle, const glm::mat4& mvp) {
    auto it = meshes.find(handle);
    if (it == meshes.end()) return;

    GPUMesh& gpu = it->second;

    texture.Bind();
    shader.Activate();
    shader.setMat4(mvp);
    

    gpu.vao.Bind();
    glEnable(GL_DEPTH_TEST);
    glDrawElements(GL_TRIANGLES,
                static_cast<GLsizei>(gpu.indexCount),
                GL_UNSIGNED_INT,
                nullptr);
}