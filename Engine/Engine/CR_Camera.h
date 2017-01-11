#pragma once

#include "GameComponent.h"

class Camera;
class Input;
class ShaderHandler;

class CR_Camera : public GameComponent {
private:
    Camera* camera;
public:
    CR_Camera(Camera* camera);

    string GetDafaultName();

    void updateFreeCam(const double & delta, InputManager* input);

    void c_update(const double & delta, InputManager* input);
    void c_preRender(ShaderHandler* shaderHandler, LightHandler* lightHandler, bool shadowRender = false);
};