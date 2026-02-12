#pragma once

#include <glad/glad.h>

class Mesh {
public:
    Mesh();
    ~Mesh();
    void init();

    unsigned int getVAO() const { return VAO; }
    int getVertexCount() const { return 3; };

private:
    unsigned int VAO, VBO;
};