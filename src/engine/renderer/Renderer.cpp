#include "Renderer.h"

Renderer::Renderer() {
    const char* vertexSource = R"(
        #version 330 core
        layout (location = 0) in vec3 aPos;

        uniform mat4 u_MVP;
        
        void main() {
            gl_Position = u_MVP * vec4(aPos, 1.0);
        }
    )";
    const char* fragmentSource = R"(
        #version 330 core
        out vec4 FragColor;
        
        void main() {
            FragColor = vec4(0.3f, 0.8f, 0.3f, 1.0f);
        }
    )";

    unsigned int vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertexSource, nullptr);
    glCompileShader(vertex);

    unsigned int fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fragmentSource, nullptr);
    glCompileShader(fragment);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertex);
    glAttachShader(shaderProgram, fragment);
    glLinkProgram(shaderProgram);

    mvpLocation = glGetUniformLocation(shaderProgram, "u_MVP");

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

void Renderer::clear() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
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

    gpu.indexCount = static_cast<uint32_t>(data.indices.size());
}

void Renderer::draw(MeshHandle handle, const glm::mat4& mvp) {
    auto it = meshes.find(handle);
    if (it == meshes.end()) return;

    GPUMesh& gpu = it->second;

    glUseProgram(shaderProgram);
    glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));

    gpu.vao.Bind();
    glDrawElements(GL_TRIANGLES,
                static_cast<GLsizei>(gpu.indexCount),
                GL_UNSIGNED_INT,
                nullptr);
}