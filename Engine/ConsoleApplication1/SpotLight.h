#pragma once

#include "stdafx.h"

#include "PointLight.h"

class SpotLight : public PointLight {
protected:
    vec3 direction;
    float cutoff;
    float cutoffBlend;
public:
    SpotLight(vec3 d, float cO, float cOB, vec3 p, float r, vec3 c, float i);
    SpotLight(vec3 d, float cO, float cOB, vec3 p, float r, vec3 c, float i, float ac, float al, float as);

    vec3 getDirection();
    void setDirection(vec3 d);

    float getCutoff();
    void setCutoff(float c);

    float getCutoffBlend();
    void setCutoffBlend(float cOB);
};

