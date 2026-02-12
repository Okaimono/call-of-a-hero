#include "InputManager.h"

void InputManager::init(GLFWwindow* win) {
    window = win;
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void InputManager::update() {
    for (int i = 0; i < GLFW_KEY_LAST; i++) {
        keysPrevious[i] = keysDown[i];
        keysDown[i] = glfwGetKey(window, i) == GLFW_PRESS;
    }

    double xpos, ypos;
    glfwGetCursorPos(window, &xpos, &ypos);

    if (firstMouse) {
        lastMousePos = {xpos, ypos};
        firstMouse = false;
    }

    mouseDelta = {xpos - lastMousePos.x, lastMousePos.y - ypos};
    lastMousePos = {xpos, ypos};
}

bool InputManager::isKeyDown(int key) const {
    return keysDown[key];
}   

bool InputManager::wasKeyPressed(int key) const {
    return keysDown[key] && !keysPrevious[key];
}

glm::vec2 InputManager::getMouseDelta() const {
    return mouseDelta;
}