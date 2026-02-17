#include "PlayerController.h"

void PlayerController::update(InputManager& input, CameraPose& cam) {
    handleMovement(input, cam);
    handleLook(input, cam);
}

void PlayerController::handleMovement(InputManager& input, CameraPose& cam) {
    if (input.isKeyDown(GLFW_KEY_W)) {
        cam.position += cam.orientation * 0.01f;
    }
    if (input.isKeyDown(GLFW_KEY_S)) {
        cam.position += cam.orientation * -0.01f;
    }
    if (input.isKeyDown(GLFW_KEY_A)) {
        glm::vec3 dirLeft = glm::normalize(glm::cross(cam.up, cam.orientation));
        cam.position += dirLeft * 0.01f;
    }
    if (input.isKeyDown(GLFW_KEY_D)) {
        glm::vec3 dirRight = glm::normalize(glm::cross(cam.orientation, cam.up));
        cam.position += dirRight * 0.01f;
    }
}

void PlayerController::handleLook(InputManager& input, CameraPose& cam) {
    glm::vec2 mouseDelta = input.getMouseDelta();

    float rotX = glm::radians(mouseDelta.x);
    float rotY = glm::radians(mouseDelta.y);

    glm::vec3 newOrientation = glm::rotate(cam.orientation, -rotX, cam.up);
    newOrientation = glm::rotate(newOrientation, rotY, glm::normalize(glm::cross(newOrientation, cam.up)));
    cam.orientation = newOrientation;
}