#pragma once

#include "GameComponent.h"

class DirectionalLight;

class C_DirectionalLight : public GameComponent {
private:
    bool init;

    DirectionalLight* directionalLight;
    LightHandler* lightHandler;
public:
    C_DirectionalLight(vec3 color, float intensity, vec3 direction);

    void c_preRender(LightHandler* lightHandler, Shader* shader);
    void c_destroy();
};