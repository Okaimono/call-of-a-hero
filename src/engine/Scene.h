#pragma once
#include "engine/CameraPose.h"

class Scene {
public:
    CameraPose activeCamera;
    
    void submitCameraData(CameraPose cameraPose);
    
};