#pragma once

#include "GameComponent.h"

class DirectionalLight;

class C_DirectionalLight : public GameComponent {
private:
    bool init;

    DirectionalLight* directionalLight;
    LightHandler* lightHandler;
public:
    C_DirectionalLight(vec3 color, bool shadowMapEnabled = false);

    void setShadowMapID(int shadowMapID);
    int getShadowMapID();

    void setColor(vec3 color);
    vec3 getColor();

    void setIntensity(float intensity);
    float getIntensity();

    void c_update(const double & delta, InputManager* input);
    void c_preRender(LightHandler* lightHandler, Shader* shader);
    void c_destroy();
};