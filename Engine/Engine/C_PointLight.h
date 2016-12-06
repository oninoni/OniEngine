#pragma once

#include "GameComponent.h"

class PointLight;

class C_PointLight : public GameComponent {
private:
    bool init;

    PointLight* pointLight;
    LightHandler* lightHandler;
public:
    C_PointLight(vec3 p, float r, vec3 v, float i);
    C_PointLight(vec3 p, float r, vec3 c, float i, float ac, float al, float as);

    void c_preRender(LightHandler* lightHandler, Shader* shader);
    void c_destroy();
};