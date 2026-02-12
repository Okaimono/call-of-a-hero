#pragma once
//#include "InputManager.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

struct CameraTransform {
    glm::vec3 position;
    glm::vec3 orientation;
    glm::vec3 up;
};

class Camera {
public:
    Camera(int sw, int sh, float fov, float np, float fp);

    glm::mat4 matrix(CameraTransform& transform);
    //void processInputs(const InputManager& input, float dt);

    float FOVdeg;
    float nearPlane, farPlane;

    int screenWidth, screenHeight;
private:
    glm::vec3 position = {0.0f, 0.0f, 1.0f};
    glm::vec3 orientation = {0.0f, 0.0f, -1.0f};
    glm::vec3 up = {0.0f, 1.0f, 0.0f};
};