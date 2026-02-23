#pragma once
#include "Window.h"
#include "InputManager.h"
#include "renderer/Renderer.h"
#include "renderer/RenderPipeline.h"
#include "renderer/ResourceManager.h"
#include "Scene.h"
#include "renderer/Camera.h"
#include "Application.h"


// Core engine. Owns every subsystem, orchestrates the main loop.
// This knows nothing about underlying game systems, 
// abstract applicaton interface is the only interaction.

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