#include "Camera.h"

Camera::Camera(int sw, int sh, float fov, float np, float fp) 
    : screenWidth(sw), screenHeight(sh), FOVdeg(fov), nearPlane(np), farPlane(fp)
{}

glm::mat4 Camera::matrix(CameraPose& cameraPose) {
    glm::mat4 view = glm::mat4(1.0f);
    glm::mat4 projection = glm::mat4(1.0f);

    view = glm::lookAt(cameraPose.position, cameraPose.position + cameraPose.orientation, cameraPose.up);
    projection = glm::perspective(glm::radians(FOVdeg), (float)screenWidth / screenHeight, nearPlane, farPlane);
    
    return projection * view;
}