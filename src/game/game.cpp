#include "game.h"
#include "glm/glm.hpp"
#include "engine/renderer/RenderPipeline.h"

void Game::onInit() {
    triangle.init();
}

void Game::onUpdate(float dt) {

}

void Game::onRender(RenderPipeline& renderPipeline) {
    renderPipeline.submit(triangle, glm::mat4(1.0f));
}
