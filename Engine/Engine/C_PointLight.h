#pragma once

#include "GameComponent.h"

class PointLight;

class C_PointLight : public GameComponent {
private:
    bool init;

    PointLight* pointLight;
    LightHandler* lightHandler;
public:
    C_PointLight(float r, vec3 c, bool shadowMapEnabled = false);
    C_PointLight(float r, vec3 c, bool shadowMapEnabled, float ac, float al, float as);

    void c_update(const double & delta, InputManager* input);
    void c_preRender(LightHandler* lightHandler, Shader* shader);
    void c_destroy();
};