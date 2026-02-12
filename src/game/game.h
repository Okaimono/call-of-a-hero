#pragma once
#include "engine/Application.h"
#include "engine/renderer/Mesh.h"
#include "Player.h"

class Game : public Application {
public:
    void onInit() override;
    void onUpdate(float dt, InputManager& inputManager) override;
    void onRender(RenderPipeline& renderPipeline, Scene& scene) override;

    Mesh triangle;
    Player player;
};