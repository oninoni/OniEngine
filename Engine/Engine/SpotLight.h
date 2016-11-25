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
    SpotLight(vec3 d, float cO, vec3 p, float r, vec3 c, float i);
    SpotLight(vec3 d, float cO, vec3 p, float r, vec3 c, float i, float ac, float al, float as);

    void setUniformSpotLight(LightHandler * lightHandler);

    vec3 getDirection();
    void setDirection(vec3 d);

    float getCutoff();
    void setCutoff(float c);

    void forceUpdate();
};