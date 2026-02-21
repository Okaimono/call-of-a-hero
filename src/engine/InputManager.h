#pragma once
#include "Window.h"

#include <glm/glm.hpp>

class InputManager {
public:
    void init(GLFWwindow* win);
    void update();

    bool isKeyDown(int key) const;
    bool wasKeyPressed(int key) const;
    glm::vec2 getMouseDelta() const;

private:
    GLFWwindow* window;
    bool keysDown[GLFW_KEY_LAST] = {};
    bool keysPrevious[GLFW_KEY_LAST] = {};
    glm::vec2 mouseDelta = {0, 0};
    glm::vec2 lastMousePos = {0, 0};
    bool firstMouse = true;
};