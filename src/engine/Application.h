#pragma once

class RenderPipeline;
class InputManager;
class Scene;

class Application {
public:
    virtual ~Application() = default;
    virtual void onInit() = 0;
    virtual void onUpdate(float dt, InputManager& inputManager) = 0;
    virtual void onRender(RenderPipeline& renderPipeline, Scene& scene) = 0;
};