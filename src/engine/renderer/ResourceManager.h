#pragma once
#include "RenderTypes.h"
#include "OpenGL/Texture.h"
#include "OpenGL/Shader.h"

#include <vector>

// 
//
//

class ResourceManager {
public:
    void createShader(const char* vertexFile, const char* fragmentFile);

    void createTexture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType);
    void texUnit(TextureID texture, ShaderID shader, const char* uniform, GLuint unit);

    MeshHandle createMesh(const MeshData& data);

    void updateMesh(MeshHandle handle, const MeshData& data);
    void destroyMesh(MeshHandle handle);

    Shader& getShader(ShaderID shader) {
        return shaders[shader];
    }

    Texture& getTexture(TextureID texture) {
        return textures[texture];
    }

private:
    std::vector<Shader> shaders;
    std::vector<Texture> textures;

};