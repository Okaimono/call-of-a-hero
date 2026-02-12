#pragma once
#include <glm/glm.hpp>

struct CameraPose {
    glm::vec3 position{0, 0, 1};
    glm::vec3 orientation{0, 0, -1};
    glm::vec3 up{0, 1, 0};
};