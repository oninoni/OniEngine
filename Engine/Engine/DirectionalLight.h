#pragma once

class LightHandler;

#include "BaseLight.h"

class DirectionalLight : public BaseLight {
private:
    vec3 direction;
    bool directionChanged;
public:
    DirectionalLight(vec3 c, float i, vec3 d);
    ~DirectionalLight();

    void setUniformDirectionalLight(LightHandler* lightHandler);

    vec3 getDirection();
    void setDirection(vec3 direction);

    void forceUpdate();
};