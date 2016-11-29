#pragma once

class LightHandler;
class GameComponent;

class BaseLight abstract{
protected:
    vec3 color;
    bool colorChanged;
    float intensity;
    bool intensityChanged;

    GameComponent* component;

    BaseLight(GameComponent* component, vec3 color, float intensity);
public:
    vec3 getColor();
    void setColor(vec3 color);

    float getIntensity();
    void setIntensity(float intensity);

    void forceUpdate();

    mat4 getTransformationMatrix(bool inverted);
};