#pragma once

class RenderPipeline;
class InputManager;
class Scene;
class ResourceManager;

// TODO: Take all the references and place them into a struct for init and update

// Game implements this. Engine calls into it. Game never knows about engine internals like
// window. Engine never knows about game internals. Game interacts with engine with provided
// engine interfaces such as renderPipeline, inputManager, scene and resourceManager. 

class Application {
public:
    virtual ~Application() = default;
    virtual void onInit(RenderPipeline& renderPipeline, ResourceManager& resourceManager) = 0;
    virtual void onUpdate(float dt, InputManager& inputManager, Scene& scene) = 0;
    virtual void onRender(RenderPipeline& renderPipeline) = 0;
};