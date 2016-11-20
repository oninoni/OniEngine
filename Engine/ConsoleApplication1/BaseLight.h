#pragma once

#include "m_vector.h"

class BaseLight {
protected:
    vec3 color;
    float intensity;
public:
    BaseLight(vec3 color, float intensity);
    ~BaseLight();

    vec3 getColor();
    void setColor(vec3 c);

    float getIntensity();
    void setIntensity(float i);
};

