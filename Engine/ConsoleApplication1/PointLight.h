#pragma once

#include "BaseLight.h"
#include "Attenuation.h"

class PointLight : public BaseLight, public Attenuation{
protected:
    vec3 position;
    float range;
public:
    PointLight(vec3 p, float r, vec3 v, float i);
    PointLight(vec3 p, float r, vec3 c, float i, float ac, float al, float as);

    vec3 getPosition();
    void setPosition(vec3 p);

    float getRange();
    void setRange(float r);
};

