#pragma once

#include "BaseLight.h"
#include "Attenuation.h"

class LightHandler;

class PointLight : public BaseLight, public Attenuation{
protected:
    vec3 position;
    bool positionChanged;
    float range;
    bool rangeChanged;
public:
    PointLight(vec3 p, float r, vec3 v, float i);
    PointLight(vec3 p, float r, vec3 c, float i, float ac, float al, float as);

    void setUniformPointLight(LightHandler * lightHandler);

    vec3 getPosition();
    void setPosition(vec3 p);

    float getRange();
    void setRange(float r);

    void forceUpdate();
};

