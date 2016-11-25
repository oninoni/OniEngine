#pragma once

class LightHandler;

struct BaseLightData{
};

class BaseLight {
protected:
    vec3 color;
    bool colorChanged;
    float intensity;
    bool intensityChanged;

    BaseLight(vec3 c, float i);
public:
    vec3 getColor();
    void setColor(vec3 c);

    float getIntensity();
    void setIntensity(float i);

    void forceUpdate();
};