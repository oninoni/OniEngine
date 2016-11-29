#pragma once

class LightHandler;

#include "BaseLight.h"

class DirectionalLight : public BaseLight {
private:
    vec3 direction;
    bool directionChanged;
public:
    DirectionalLight(GameComponent* component, vec3 color, float intensity, vec3 direction);
    ~DirectionalLight();

    void setUniformDirectionalLight(LightHandler* lightHandler);

    vec3 getDirection();
    void setDirection(vec3 direction);

    void forceUpdate();
};