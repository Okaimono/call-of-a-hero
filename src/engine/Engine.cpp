#include "Engine.h"

Engine::Engine(int width, int height, const char* title, Application& app) 
    : window(width, height, title), 
    camera(width, height, 100.0f, 0.1f, 50.0f), 
    application(app)
{}

void Engine::run() {
    application.onInit();
    inputManager.init(window.getHandle());

    while (!window.shouldClose()) {
        renderer.clear();

        inputManager.update();

        application.onUpdate(1.0f / 60.0f, inputManager);

        renderPipeline.beginScene(camera.matrix(scene.activeCamera));
        application.onRender(renderPipeline, scene);
        renderPipeline.endScene(renderer);

        window.swapBuffers();
        window.pollEvents();
    } 
}