#include "Engine.h"

Engine::Engine(int width, int height, const char* title, Application& app) 
    : window(width, height, title), 
    camera(width, height, 100.0f, 0.1f, 50.0f), 
    application(app)
{}

void Engine::run() {
    application.onInit();
    inputManager.init(window.getHandle());
    CameraTransform transform;

    transform.position = glm::vec3(0.0f, 0.0f, -1.0f);
    transform.orientation = glm::normalize(glm::vec3(-0.1f, 0.0f, 0.9f));
    transform.up = glm::vec3(0.0f, 1.0f, 0.0f);

    while (!window.shouldClose()) {
        renderer.clear();

        renderPipeline.beginScene(camera.matrix(transform));
        application.onRender(renderPipeline);
        renderPipeline.endScene(renderer);

        window.swapBuffers();
        window.pollEvents();
    } 
}