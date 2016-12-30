#pragma once

#include "GameComponent.h"

class PointLight;

class C_PointLight : public GameComponent {
private:
    bool init;

    PointLight* pointLight;
    LightHandler* lightHandler;
public:
    C_PointLight(vec3 color, float range, bool shadowMapEnabled = false);
    C_PointLight(vec3 color, float range, bool shadowMapEnabled, float ac, float al, float as);

    void setColor(vec3 color);
    vec3 getColor();

    void setIntensity(float intensity);
    float getIntensity();

    void setColor(vec3 color);
    vec3 getColor();

    void c_update(const double & delta, InputManager* input);
    void c_preRender(LightHandler* lightHandler, Shader* shader);
    void c_destroy();
};