#pragma once

class RenderPipeline;

class Application {
public:
    virtual ~Application() = default;
    virtual void onInit() = 0;
    virtual void onUpdate(float dt) = 0;
    virtual void onRender(RenderPipeline& renderPipeline) = 0;
};