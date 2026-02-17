#pragma once
#include "engine/Application.h"
#include "Player.h"
#include "PlayerController.h"
#include "world/World.h"
#include "world/WorldRenderer.h"
#include "engine/renderer/RenderTypes.h"

class Game : public Application {
public:
    void onInit(RenderPipeline& renderPipeline) override;
    void onUpdate(float dt, InputManager& inputManager) override;
    void onRender(RenderPipeline& renderPipeline, Scene& scene) override;

    World world;
    PlayerController playerController;
    Player player;
    WorldRenderer worldRenderer;
};