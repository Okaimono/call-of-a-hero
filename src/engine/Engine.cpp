#include "Engine.h"

Engine::Engine(int width, int height, const char* title, Application& app) 
    : window(width, height, title), 
    camera(width, height, 100.0f, 0.1f, 50.0f), 
    application(app)
{}

void Engine::run() {
    // Initializes subsystems before main loop begins
    inputManager.init(window.getHandle());
    renderPipeline.init(renderer, resourceManager, scene);
    application.onInit(renderPipeline, resourceManager);

    // Main loop
    while (!window.shouldClose()) {
        window.pollEvents();

        inputManager.update();
        // TODO: make dt actually do something
        application.onUpdate(1.0f / 60.0f, inputManager, scene);

        // Render pipeline through scene now applies the VP matrix on all draw commands.
        // Probably get rid of scene, instead batch VP matrix on 
        // the draw commands and move scene to game side. 
        renderPipeline.beginScene(camera.matrix(scene.activeCamera));
        application.onRender(renderPipeline);
        renderPipeline.endScene(renderer);

        window.swapBuffers();
    } 
}