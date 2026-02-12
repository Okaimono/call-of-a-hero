#pragma once
#include "Window.h"
#include "InputManager.h"
#include "renderer/Renderer.h"
#include "renderer/RenderPipeline.h"
#include "renderer/Mesh.h"
#include "renderer/Camera.h"
#include "Application.h"

class Engine {
public:
    Engine(int width, int height, const char* title, Application& app);
    void run();

private:
    Application& application;
    Window window;
    InputManager inputManager;
    Camera camera;
    RenderPipeline renderPipeline;
    Renderer renderer;
};