#include "ResourceManager.h" 

#include <filesystem>
#include <string>

namespace fs = std::filesystem;

void ResourceManager::createShader(const char* vertexFile, const char* fragmentFile) {
    shaders.emplace_back(vertexFile, fragmentFile);
}

void ResourceManager::createTexture(const char* image, GLenum texType, GLenum slot, GLenum format, GLenum pixelType) {
    std::string fullPath = fs::current_path().string() + "/" + image;
    textures.emplace_back(fullPath.c_str(), texType, slot, format, pixelType);
}

void ResourceManager::texUnit(TextureID textureID, ShaderID shaderID, const char* uniform, GLuint unit) {
    Texture& texture = textures[textureID];
    Shader& shader = shaders[shaderID];
    texture.texUnit(shader, uniform, unit);
}