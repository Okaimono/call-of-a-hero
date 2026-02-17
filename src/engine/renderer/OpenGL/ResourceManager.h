#pragma once
#include "OpenGL/VAO.h"
#include "RenderTypes.h"

#include <vector>

class ResourceManager {
public:
    MeshHandle createMesh(const MeshData& data);
    void updateMesh(MeshHandle handle, const MeshData& data);
    void destroyMesh(MeshHandle handle);

private:

};