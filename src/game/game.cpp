#include "game.h"
#include "glm/glm.hpp"
#include "engine/renderer/RenderPipeline.h"
#include "engine/Scene.h"
#include "engine/InputManager.h"

void Game::onInit() {
    triangle.init();
}

void Game::onUpdate(float dt, InputManager& inputManager) {

    CameraPose& playerCamera = player.playerCamera;
    if (inputManager.isKeyDown(GLFW_KEY_W)) {
        playerCamera.position += playerCamera.orientation * 0.01f;
    }
    if (inputManager.isKeyDown(GLFW_KEY_S)) {
        playerCamera.position += playerCamera.orientation * -0.01f;
    }
    if (inputManager.isKeyDown(GLFW_KEY_A)) {
        glm::vec3 dirLeft = glm::normalize(glm::cross(playerCamera.up, playerCamera.orientation));
        playerCamera.position += dirLeft * 0.01f;
    }
    if (inputManager.isKeyDown(GLFW_KEY_D)) {
        glm::vec3 dirRight = glm::normalize(glm::cross(playerCamera.orientation, playerCamera.up));
        playerCamera.position += dirRight * 0.01f;
    }
}

void Game::onRender(RenderPipeline& renderPipeline, Scene& scene) {
    scene.submitCameraData(player.playerCamera);
    renderPipeline.submit(triangle, glm::mat4(1.0f));
}
 