#pragma once
#include "engine/CameraPose.h"

#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(int sw, int sh, float fov, float np, float fp);

    glm::mat4 matrix(CameraPose& transform);
    //void processInputs(const InputManager& input, float dt);

    float FOVdeg;
    float nearPlane, farPlane;

    int screenWidth, screenHeight;
};