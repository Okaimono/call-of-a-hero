#include "Engine.h"

Engine::Engine(int width, int height, const char* title, Application& app) 
    : window(width, height, title), 
    camera(width, height, 100.0f, 0.1f, 50.0f), 
    application(app)
{}

void Engine::run() {
    inputManager.init(window.getHandle());
    renderPipeline.init(renderer, resourceManager, scene);
    application.onInit(renderPipeline, resourceManager);

    while (!window.shouldClose()) {
        window.pollEvents();

        inputManager.update();
        application.onUpdate(1.0f / 60.0f, inputManager, scene);

        renderPipeline.beginScene(camera.matrix(scene.activeCamera));
        application.onRender(renderPipeline);
        renderPipeline.endScene(renderer);

        window.swapBuffers();
    } 
}