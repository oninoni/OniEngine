#pragma once

#include "PointLight.h"

class SpotLight : public PointLight {
protected:
    vec3 direction;
    float cutoff;
public:
    SpotLight(vec3 d, float cO, vec3 p, float r, vec3 c, float i, float ac, float al, float as);

    vec3 getDirection();
    void setDirection(vec3 d);

    float getCutoff();
    void setCutoff(float c);
};
