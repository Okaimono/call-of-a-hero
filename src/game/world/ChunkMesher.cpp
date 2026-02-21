#include "ChunkMesher.h"

const glm::vec3 faceVertices[6][4] = {
    // TOP
    {{0,1,0}, {1,1,0}, {1,1,1}, {0,1,1}},
    // BOTTOM
    {{0,0,1}, {1,0,1}, {1,0,0}, {0,0,0}},
    // NORTH (+Z)
    {{0,0,1}, {1,0,1}, {1,1,1}, {0,1,1}},
    // SOUTH (-Z)
    {{1,0,0}, {0,0,0}, {0,1,0}, {1,1,0}},
    // EAST (+X)
    {{1,0,1}, {1,0,0}, {1,1,0}, {1,1,1}},
    // WEST (-X)
    {{0,0,0}, {0,0,1}, {0,1,1}, {0,1,0}},
};

void ChunkMesher::mesh(Chunk& chunk, MeshData& mesh) {
    mesh.vertices.clear();
    mesh.indices.clear();

    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 256; y++) {
            for (int z = 0; z < 16; z++) {
                if (chunk.getBlock(x, y, z) == BlockID::AIR) {continue; }
                addFace(Face::TOP, mesh, glm::vec3((float)x, (float)y, (float)z));
                addFace(Face::BOTTOM, mesh, glm::vec3((float)x, (float)y, (float)z));
                addFace(Face::NORTH, mesh, glm::vec3((float)x, (float)y, (float)z));
                addFace(Face::EAST, mesh, glm::vec3((float)x, (float)y, (float)z));
                addFace(Face::SOUTH, mesh, glm::vec3((float)x, (float)y, (float)z));
                addFace(Face::WEST, mesh, glm::vec3((float)x, (float)y, (float)z));
            }
        }
    }
}

void ChunkMesher::addFace(Face face, MeshData& mesh, glm::vec3 position) {
    int f = (int)face;
    int baseIndex = mesh.vertices.size();

    float s = 16.0f / 512.0f; // 0.03125 - one tile size
    float uMin = 0.0f;
    float uMax = s;
    float vMin = 1.0f - (4 * s);  // flipped for OpenGL
    float vMax = 1.0f - (3 * s);

    glm::vec2 uvCoords[4] = {
        {uMin, vMin},  // bottom left
        {uMax, vMin},  // bottom right
        {uMax, vMax},  // top right
        {uMin, vMax},  // top left
    };

    for (int i = 0; i < 4; i++) {
        Vertex v;
        v.position = position + faceVertices[f][i];
        v.texCoord = uvCoords[i];
        mesh.vertices.push_back(v);
    }

    mesh.indices.insert(mesh.indices.end(), {
        (GLuint)baseIndex+0, (GLuint)baseIndex+1, (GLuint)baseIndex+2,
        (GLuint)baseIndex+2, (GLuint)baseIndex+3, (GLuint)baseIndex+0
    });
}