#pragma once
#include "engine/Application.h"
#include "Player.h"
#include "PlayerController.h"
#include "world/World.h"
#include "world/WorldRenderer.h"
#include "engine/renderer/RenderTypes.h"

class Game : public Application {
public:
    void onInit(RenderPipeline& renderPipeline, ResourceManager& resourceManager) override;
    void onUpdate(float dt, InputManager& inputManager, Scene& scene) override;
    void onRender(RenderPipeline& renderPipeline) override;

    void initShaders(ResourceManager& resourceManager);
    void initTextures(ResourceManager& resourceManager);

    World world;
    PlayerController playerController;
    Player player;
    WorldRenderer worldRenderer;
};