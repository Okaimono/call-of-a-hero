#pragma once
#include "Window.h"
#include "InputManager.h"
#include "renderer/Renderer.h"
#include "renderer/RenderPipeline.h"
#include "renderer/ResourceManager.h"
#include "Scene.h"
#include "renderer/Camera.h"
#include "Application.h"


class Engine {
public:
    Engine(int width, int height, const char* title, Application& app);
    void run();

private:
    Application& application;
    ResourceManager resourceManager;
    Window window;
    InputManager inputManager;
    Camera camera;
    RenderPipeline renderPipeline;
    Scene scene;
    Renderer renderer;
};