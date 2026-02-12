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

Renderer::~Renderer() {     
    glDeleteProgram(shaderProgram);
}

void Renderer::clear() {
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const Mesh& mesh, const glm::mat4& matrix) {
    glUseProgram(shaderProgram);

    glUniformMatrix4fv(
        mvpLocation,
        1,
        GL_FALSE,
        glm::value_ptr(matrix)
    );

    glBindVertexArray(mesh.getVAO());
    glDrawArrays(GL_TRIANGLES, 0, mesh.getVertexCount());
}