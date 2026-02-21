#pragma once

class RenderPipeline;
class InputManager;
class Scene;
class ResourceManager;

class Application {
public:
    virtual ~Application() = default;
    virtual void onInit(RenderPipeline& renderPipeline, ResourceManager& resourceManager) = 0;
    virtual void onUpdate(float dt, InputManager& inputManager, Scene& scene) = 0;
    virtual void onRender(RenderPipeline& renderPipeline) = 0;
};