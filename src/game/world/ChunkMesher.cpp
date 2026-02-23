#include "ChunkMesher.h"
#include "BlockData.h"

/*
ORDER: 
1. Face Cull
2. Greedy Mesh
3. Terrain Generation
4. Multithread
5. Render Distance
6. Frustrum Cull

*/

static const glm::vec3 faceVertices[6][4] = {
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

static const glm::ivec3 adjacentSide[(int)Face::COUNT] = {
    {0, 1, 0},
    {0, -1, 0},
    {0, 0, 1},
    {0, 0, -1},
    {1, 0, 0},
    {-1, 0, 0}
};

// Optimized face cull. Just change it so that, in future, where I might add
// all the render distance system and stuff, make it so that those bordering chunks are 
// brought here to cull required faces.

void ChunkMesher::mesh(Chunk& chunk, MeshData& mesh) {
    mesh.vertices.clear();
    mesh.indices.clear();

    for (int x = 0; x < 16; x++) {
        for (int y = 0; y < 256; y++) {
            for (int z = 0; z < 16; z++) {
                BlockID block = chunk.getBlock(x, y, z);
                if (block == BlockID::AIR) { continue; }

                glm::ivec3 pos(x, y, z);
                for (int f = 0; f < (int)Face::COUNT; f++) {
                    Face face = (Face)f;
                    if (!isSolid(face, chunk, pos))
                        addFace(block, face, mesh, glm::vec3(pos));
                }
            }
        }
    }
}

bool ChunkMesher::isSolid(Face face, Chunk& chunk, const glm::ivec3& position) {
    glm::ivec3 n = position + adjacentSide[(int)face];

    if (n.x < 0 || n.x >= 16 ||
        n.y < 0 || n.y >= 256 ||
        n.z < 0 || n.z >= 16)
        return false;

    return chunk.getBlock(n.x, n.y, n.z) != BlockID::AIR;
}

void ChunkMesher::addFace(BlockID block, Face face, MeshData& mesh, const glm::vec3& position) {
    int f = (int)face;
    int baseIndex = mesh.vertices.size();

    BlockData::UVCoord uv = BlockData::blockUVs[(int)block][(int)face];

    glm::vec2 uvCoords[4] = {
        {uv.uMin, uv.vMax},  // bottom left
        {uv.uMax, uv.vMax},  // bottom right
        {uv.uMax, uv.vMin},  // top right
        {uv.uMin, uv.vMin},  // top left
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