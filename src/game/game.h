#pragma once
#include "engine/Application.h"
#include "engine/renderer/Mesh.h"

class Game : public Application {
public:
    void onInit() override;
    void onUpdate(float dt) override;
    void onRender(RenderPipeline& renderPipeline) override;

    Mesh triangle;
};