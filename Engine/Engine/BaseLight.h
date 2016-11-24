#pragma once

class BaseLight {
protected:
    vec3 color;
    float intensity;

    BaseLight(vec3 c, float i);
public:

    vec3 getColor();
    void setColor(vec3 c);

    float getIntensity();
    void setIntensity(float i);
};