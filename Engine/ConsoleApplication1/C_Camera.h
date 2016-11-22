#pragma once

#include "GameComponent.h"

class Camera;

class C_Camera : public GameComponent {
private:
    Camera* camera;
public:
    C_Camera(Camera* camera);
    ~C_Camera();
};

