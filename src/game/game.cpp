#include "game.h"
#include "glm/glm.hpp"
#include "engine/renderer/RenderPipeline.h"
#include "engine/renderer/ResourceManager.h"
#include "engine/Scene.h"
#include "engine/InputManager.h"
#include "engine/renderer/Camera.h"

#include "assets.h"

void Game::onInit(RenderPipeline& renderPipeline, ResourceManager& resourceManager) {
    worldRenderer.init(renderPipeline);
    world.init();

    initShaders(resourceManager);
    initTextures(resourceManager);

    Shader& def = resourceManager.getShader(Assets::Shaders::DEFAULT);
    Texture& gameAtlas = resourceManager.getTexture(Assets::Textures::GAME_ATLAS);

    def.Activate();
    gameAtlas.Bind();
}

void Game::onUpdate(float dt, InputManager& inputManager, Scene& scene) {
    playerController.update(inputManager, player.playerCamera);
    scene.submitCameraData(player.playerCamera);
}

void Game::onRender(RenderPipeline& renderPipeline) {
    worldRenderer.render(renderPipeline);
}

void Game::initShaders(ResourceManager& resourceManager) {
    resourceManager.createShader(Assets::CHUNK_VERT_PATH, Assets::CHUNK_FRAG_PATH);
}

void Game::initTextures(ResourceManager& resourceManager) {
    resourceManager.createTexture(Assets::GAME_ATLAS_PATH, GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    resourceManager.texUnit((int)Assets::Textures::GAME_ATLAS, (int)Assets::Shaders::DEFAULT, "tex0", 0);
}