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
    SpotLight(GameProperty* property, vec3 color, float radius, float cutoff);
    SpotLight(GameProperty* property, vec3 color, float radius, float cutoff, float constant, float linear, float square);

    void setUniformSpotLight(LightHandler * lightHandler);

    vec3 getDirection();
    void setDirection(vec3 direction);

    float getCutoff();
    void setCutoff(float c);

    void forceUpdate();
};