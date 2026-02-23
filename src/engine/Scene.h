#pragma once
#include "engine/CameraPose.h"

// Shared scene state that the game writes to and the engine reads from.
// The game submits camera data each frame; the engine uses it to build
// the view-projection matrix. This avoids the game needing to know
// about Camera or matrix math directly.

class Scene {
public:
    CameraPose activeCamera;
    
    void submitCameraData(CameraPose cameraPose);
    
};