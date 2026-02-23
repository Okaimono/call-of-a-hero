#pragma once
#define GLM_ENABLE_EXPERIMENTAL
#include "Engine/InputManager.h"
#include "engine/CameraPose.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

class PlayerController {
public:
    void update(InputManager& input, CameraPose& cam);
    void handleMovement(InputManager& input, CameraPose& cam);
    void handleLook(InputManager& input, CameraPose& cam);
};