#pragma once

#include "PointLight.h"

class LightHandler;

class SpotLight : public PointLight {
protected:
    vec3 direction;
    bool directionChanged;

    float cutoff;
    bool cutoffChanged;
public:
    SpotLight(GameComponent* component, vec3 direction, float cutoff, vec3 position, float radius, vec3 color);
    SpotLight(GameComponent* component, vec3 direction, float cutoff, vec3 position, float radius, vec3 color, float constant, float linear, float square);

    void setUniformSpotLight(LightHandler * lightHandler);

    vec3 getDirection();
    void setDirection(vec3 direction);

    float getCutoff();
    void setCutoff(float c);

    void forceUpdate();
};