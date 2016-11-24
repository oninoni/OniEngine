#pragma once

#include "GameComponent.h"

class DirectionalLight;

class C_DirectionalLight : public GameComponent {
private:
    bool init;

    DirectionalLight* directionalLight;

    Shader* activeShader;
public:
    C_DirectionalLight(vec3 color, float intensity, vec3 direction);

    void c_preRender(Shader* shader);
    void c_destroy();
};