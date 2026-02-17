#include "game.h"
#include "glm/glm.hpp"
#include "engine/renderer/RenderPipeline.h"
#include "engine/Scene.h"
#include "engine/InputManager.h"
#include "engine/renderer/Camera.h"

void Game::onInit(RenderPipeline& renderPipeline) {
    worldRenderer.init(renderPipeline);
    world.init();
}

void Game::onUpdate(float dt, InputManager& inputManager) {
    playerController.update(inputManager, player.playerCamera);
}

void Game::onRender(RenderPipeline& renderPipeline, Scene& scene) {
    scene.submitCameraData(player.playerCamera);
    worldRenderer.render(renderPipeline);
}