#pragma once

#include "GameComponent.h"

class Camera;
class Input;

class C_Camera : public GameComponent {
private:
    Camera* camera;
public:
    C_Camera(Camera* camera);

    string GetDafaultName();

    void updateFreeCam(const double & delta, InputManager* input);

    void c_update(const double & delta, InputManager* input);
};